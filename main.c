//
// main.c
//
// main listing of the program..
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"


extern struct  mutils_commandlist  *gstruct_CommandList;
extern int     giCommandListUsed;

extern char    *gpszDialogBuffer;
extern int     giDialogBufferUsed;
extern char    *gpszArchiveBuffer;
extern int     giArchiveBufferUsed;

// storage of the file load structure..
struct futils_filebuff          gstruct_FileBuffGen;
struct futils_filebuff          gstruct_FileBuffOut;
struct futils_filebuff          gstruct_FileBuffHdr;

// storage for the session tracking id.
char     gszSessionTrackingId[50];

char     gszVersionStamp[20];

// this is the debug output flag
char     gcDebugFlag = 0;
// this is referenced in a lot of the scene files to turn on logging in most places where flags are set and used
// unfortunately, this messes up the dialog display.
// this is turned on by the -D command line switch (CURSES version).


// this is the actual scene list..
struct  main_scenelist gstructSceneList[] =
{
    { 1001, gamelogic01_scene1001 },
    { 1002, gamelogic01_scene1002 },
    { 1021, gamelogic02_scene1021 },
    { 1022, gamelogic02_scene1022 },
    { 1023, gamelogic02_scene1023 },
    { 1024, gamelogic02_scene1024 },
    { 1025, gamelogic02_scene1025 },
    { 1026, gamelogic02_scene1026 },
    { 1027, gamelogic02_scene1027 },
    { 1028, gamelogic02_scene1028 },
    { 1029, gamelogic02_scene1029 },
    { 1030, gamelogic02_scene1030 },
    { 1031, gamelogic02_scene1031 },
    { 1032, gamelogic02_scene1032 },
    { 1033, gamelogic02_scene1033 },
    { 1034, gamelogic02_scene1034 },
    { 1035, gamelogic02_scene1035 },
    { 1036, gamelogic02_scene1036 },
    { 1037, gamelogic02_scene1037 },
    { 1038, gamelogic02_scene1038 },
    { 1039, gamelogic02_scene1039 },
    { 1040, gamelogic02_scene1040 },
    { 1041, gamelogic02_scene1041 },
    { 1042, gamelogic02_scene1042 },
    { 1061, gamelogic03_scene1061 },
    {   -1, NULL                  }
};

// definition for the list of files
struct	main_fileList
{
            // name of the file
    char    szFileName[140];
            // start offset
    int     iStartPos;
            // size of the file
    int     iFileSize;
            // this entry is active
    char    cActive;
};

//
// Main entry point of the program.
//
int main (int argc, char **argv)
{
    char *szDataFileName = "BMPSfiles.dat";
    int iDataFileHandle;
    off_t offsetDataFileSize;
    char szBuffer[1024];
    int iDataFileCatalogSize;
    signed int siBytes;
    int iOffset1;
    struct main_fileList *pstruct_FileCatalog = NULL;
    int iFileCatalogSize = 0;
    int iListenSocket;
    int iClientSocket;
    int iRet;
    struct sockaddr_in structServerAddr;
    struct sockaddr_in structClientAddr;
    socklen_t addr_size;
    char szBuffer1[1024];
    char szURL[204];
    char szIPAddress[30];
    int iPort;
    char szClientIPAddress[INET_ADDRSTRLEN + 1];
#ifndef WIN32
    int iValue;
#endif // WIN32
//    struct timeval structTimeout;
    int iInputOffset;
    char *pszRequestBuf = NULL;
    char *pszPostBuf = NULL;
    int iRequestAlloc = 0;
    int iRequestSize = 0;
    int iRequestLeft;
    int iPostSize = 0;
    int iCount;
    char *pszPointer1;
    char *pszPointer2;
    short sFinished;
    char cPostData;
    char cFileLock = 0;
    pid_t pidMe;
    time_t tTime;

#ifdef WIN32
    char cAutoStartWebBrowser = 1;
    WSADATA wsaData;
    int wsaerr;
#endif // WIN32

    szIPAddress[0] = 0;
    iPort = 0;

#ifndef WIN32
    pidMe = getpid ();
#else // WIN32
    pidMe = (pid_t) GetCurrentProcessId();
#endif // WIN32

    //
    // Process the command line arguments.
    //
    iCount = 0;
    while (--argc)
    {
        iCount++;
        pszPointer1 = argv [iCount];
        if (*pszPointer1 == '-')
        {
            pszPointer1++;

            switch (*pszPointer1)
            {
            // -D turns on the debug outputs in the dialog
            case 'D':
                gcDebugFlag = 1;
                break;
#ifdef WIN32
            // -W turns off the automatic startup of the web browser
            case 'W':
                cAutoStartWebBrowser = 0;
                break;
#endif //WIN32
            }
        }
        else if (iPort == 0)
        {
            iPort = (int) atoi (pszPointer1);
        }
        else if (szIPAddress[0] == 0)
        {
            strncpy (szIPAddress, pszPointer1, 28);
            szIPAddress[28] = 0;
        }
    }

    // put in the blocks on signals
#ifndef WIN32
    signal(SIGHUP, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);
#endif //WIN32

    // load in the version number
    strcpy (gszVersionStamp, "0.82");

    if (gcDebugFlag != 0)
        printf("BMPS Version %s, with debugging turned on, is starting.\n", gszVersionStamp);
    else
        printf("BMPS Version %s is starting.\n", gszVersionStamp);

    gstruct_FileBuffGen.bMemFlag = FALSE;
    gstruct_FileBuffOut.bMemFlag = FALSE;
    gstruct_FileBuffHdr.bMemFlag = FALSE;

    // pre-allocate some working buffers..
    iRet = futils_preAllocateBuffer ((unsigned long)1024, &gstruct_FileBuffHdr);
    if (iRet != 0)
    {
        printf("Memory allocation error (Buffer Header)!\n");
        return 1;
    }

    iRet = futils_preAllocateBuffer ((unsigned long)32768, &gstruct_FileBuffOut);
    if (iRet != 0)
    {
        printf("Memory allocation error (Buffer Output)!\n");
        return 1;
    }

    iRet = futils_preAllocateBuffer ((unsigned long)122880, &gstruct_FileBuffGen);
    if (iRet != 0)
    {
        printf("Memory allocation error (Buffer Generic)!\n");
        return 1;
    }

    //
    // Load in the catalog for the file store..
    //

    // open the file
    iDataFileHandle = _open (szDataFileName, _O_RDONLY | _O_BINARY);

    if (iDataFileHandle == -1)
    {
        printf ("%s: Could not open !\n", szDataFileName);
        return 1;
    }

    // figure out the size of the datafile..
    offsetDataFileSize = _lseek (iDataFileHandle, 0, SEEK_END);

    // shift the offset to where the catalog size is
    _lseek (iDataFileHandle, offsetDataFileSize - (off_t)10, SEEK_SET);

    siBytes = _read (iDataFileHandle, szBuffer,
#ifdef WIN32
                     (unsigned int)10);
#else // WIN32
                     (size_t)10);
#endif // WIN32

    if (siBytes != (signed int)10)
    {
        printf ("%s: Could not read catalog start !\n", szDataFileName);
        return 1;
    }

    szBuffer[10] = 0;
    iDataFileCatalogSize = atoi (szBuffer);

    printf ("%s Catalog = %d bytes\n", szDataFileName, iDataFileCatalogSize);

    // shift the offset to where the catalog data is
    _lseek (iDataFileHandle, offsetDataFileSize - (off_t)(10 + iDataFileCatalogSize), SEEK_SET);

    // load the file fragment into memory as if it is a single file.
    iRet = futils_loadOpenedFileIntoMemory (iDataFileHandle, iDataFileCatalogSize, &gstruct_FileBuffGen);

    if (iRet != 0)
    {
        printf ("%s: Could not load the catalog !\n", szDataFileName);
        return 1;
    }

    while (1)
    {
        iRet = futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szBuffer, 1000);

        if (iRet == 4)
        {
            break;
        }

        if (iRet != 0)
        {
            printf ("%s: Error counting the catalog !\n", szDataFileName);
            return 1;
        }

        iFileCatalogSize++;
    }

    printf ("%s CatalogEntries = %d\n", szDataFileName, iFileCatalogSize);

    // allocate the memory buffer to hold the file catalog
    pstruct_FileCatalog = (struct main_fileList *)malloc ((size_t)sizeof (struct main_fileList) * (size_t)((size_t)iFileCatalogSize + (size_t)1));

    if (pstruct_FileCatalog == NULL)
    {
        printf ("%s: Could not allocate the catalog !\n", szDataFileName);
        return 1;
    }

    // zero out the buffer
    for (iOffset1 = 0; iOffset1 < (iFileCatalogSize + 1); iOffset1++)
    {
        pstruct_FileCatalog[iOffset1].cActive = 0;
        pstruct_FileCatalog[iOffset1].szFileName[0] = 0;
        pstruct_FileCatalog[iOffset1].iFileSize = 0;
        pstruct_FileCatalog[iOffset1].iStartPos = 0;
    }

    // reset our current position in the data that we are reading
    gstruct_FileBuffGen.ulBufferPos = 0;

    // now to read in the contents of the file data
    for (iOffset1 = 0; iOffset1 < iFileCatalogSize; iOffset1++)
    {
        int iOffset2 = 0;
        char *pszSize;
        char *pszOffset;

        iRet = futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szBuffer, 1000);
        szBuffer[1000] = 0;

        if (iRet != 0)
        {
            printf ("%s: Error reading the catalog !\n", szDataFileName);
            return 1;
        }

        while (1)
        {
            if (szBuffer[iOffset2] == 0)
            {
                printf ("%s: Catalog format problem #01 !\n", szDataFileName);
                return 1;
            }

            if (szBuffer[iOffset2] == ' ')
                break;

            iOffset2++;
        }

        szBuffer[iOffset2] = 0;
        iOffset2++;
        pszSize = szBuffer + iOffset2;

        while (1)
        {
            if (szBuffer[iOffset2] == 0)
            {
                printf ("%s: Catalog format problem #02 !\n", szDataFileName);
                return 1;
            }

            if (szBuffer[iOffset2] == ' ')
                break;

            iOffset2++;
        }

        szBuffer[iOffset2] = 0;
        iOffset2++;
        pszOffset = szBuffer + iOffset2;

        while (1)
        {
            if (szBuffer[iOffset2] == ' ')
            {
                printf ("%s: Catalog format problem #03 !\n", szDataFileName);
                return 1;
            }

            if (szBuffer[iOffset2] == 0)
                break;

            iOffset2++;
        }

        strncpy (pstruct_FileCatalog[iOffset1].szFileName, szBuffer, 138);
        pstruct_FileCatalog[iOffset1].szFileName[138] = 0;
        pstruct_FileCatalog[iOffset1].iFileSize = (int) atoi (pszSize);
        pstruct_FileCatalog[iOffset1].iStartPos = (int) atoi (pszOffset);
        pstruct_FileCatalog[iOffset1].cActive = 1;

        // should not have a 0 length file.
        if (pstruct_FileCatalog[iOffset1].iFileSize == 0)
        {
            printf ("%s: Catalog format problem #04 !\n", szDataFileName);
            return 1;
        }
    }

    // now that we have our file data loaded in, it is time for a quick
    //  sanity check.
    for (iOffset1 = 0; iOffset1 < iFileCatalogSize; iOffset1++)
    {
        _lseek (iDataFileHandle, (off_t)(pstruct_FileCatalog[iOffset1].iStartPos + pstruct_FileCatalog[iOffset1].iFileSize), SEEK_SET);

        siBytes = _read (iDataFileHandle, szBuffer,
#ifdef WIN32
                         (unsigned int)2);
#else // WIN32
                         (size_t)2);
#endif // WIN32

        if (siBytes != (signed int)2)
        {
            printf ("%s: Could not read trailing nullspace for %s !\n", szDataFileName, pstruct_FileCatalog[iOffset1].szFileName);
            return 1;
        }

        if ((szBuffer[0] != 0) || (szBuffer[1] != 0))
        {
            printf ("%s: Nullspace check failed for %s !\n", szDataFileName, pstruct_FileCatalog[iOffset1].szFileName);
            return 1;
        }
    }

    printf ("%s checks out ok.\n", szDataFileName);

    //
    // now load up the game specific information..
    //

    // load up the skin settings
    htmlskin_loadStart ();

    // init the randum number generator
    srand ((unsigned) time (&tTime));

    // I set the main command list to be big enough to never expand for this game
    //   (it still can, it is just there is no need).
    iRet = mutils_initAndClearCommandList ();

    if (iRet != 0)
    {
        printf ("Could not allocate the command list !\n");
        return 1;
    }

    // I init the dialog buffer last, which inits the fixed archive buffer first.
    //  The dialog buffer is the most likely to grow (and be realloced).
    // setting the order this way reduces the likelihood of memory fragmentation.
    iRet = mutils_initAndClearDialogBuffer ();

    if (iRet != 0)
    {
        printf ("Could not allocate the dialog buffers !\n");
        return 1;
    }

    // initialize the dynamic part of the search/replace system..
    mdialog_initDynamicList ();

    // Alloc and Init the state data.
    iRet = statedata_allocAndInit ();

    if (iRet != 0)
        return 1;

    //
    // now continue with the starting the server..
    //

#ifdef WIN32
    // Windows requires a call to startup the WS_32 library.
    if ((wsaerr = WSAStartup(0x202, &wsaData)) != 0)
    {
        printf ("WS_32: WSAStartup() failed with error %d\n", wsaerr);
        WSACleanup();
        return -1;
    }
    else
        printf("WS_32: WSAStartup() is OK.\n");
#endif // WIN32

    // allocate the memory buffer for the post processing buffer
    pszPostBuf = (char *)malloc ((size_t)2080);

    if (pszPostBuf == NULL)
    {
        printf("Memory allocation error (post buffer)!\n");
        return 1;
    }

    // allocate the memory buffer for the request buffer
    iRequestAlloc = 5119;
    pszRequestBuf = (char *)malloc ((size_t)(iRequestAlloc + 1));

    // this is to force an init of the memory buffer.
    iRequestSize = 5118;

    if (pszRequestBuf == NULL)
    {
        printf("Memory allocation error!\n");
        return 1;
    }

    // set the defaults
    if (szIPAddress[0] == 0)
        strcpy (szIPAddress, "127.0.0.1");
    if (iPort == 0)
        iPort = 6081;

    // create the listener socket
    iListenSocket = socket (PF_INET, SOCK_STREAM, 0);

    if (iListenSocket == -1)
    {
        printf("Socket creation error!\n");
        return 1;
    }

    // set SO_REUSEADDR
#ifndef WIN32
    // I turn this off to the Win32 platform.
    iValue = 1;
    if (setsockopt (iListenSocket, SOL_SOCKET, SO_REUSEADDR, &iValue, sizeof(iValue)) < 0)
    {
        printf("Unable to set REUSEADDR!\n");
		return 0;
    }
#endif // WIN32

    // config the bind details
    structServerAddr.sin_family = AF_INET;
    structServerAddr.sin_port = htons (iPort);
    structServerAddr.sin_addr.s_addr = inet_addr (szIPAddress);
    memset (structServerAddr.sin_zero, '\0', sizeof (structServerAddr.sin_zero));

    // bind to the socket
    iRet = bind (iListenSocket, (struct sockaddr *) &structServerAddr, sizeof (structServerAddr));

    if (iRet != 0)
    {
        printf("Unable to bind the address/port (%s %d) !\n", szIPAddress, iPort);
        printf("It is possible that it is in use by something else.\n");
        return 1;
    }

    // listen on the socket
    iRet = listen (iListenSocket, 40);

    if (iRet != 0)
    {
        printf("Unable to listen the port!\n");
        return 1;
    }

    printf("bound & listening.");
#ifdef WIN32
    if (cAutoStartWebBrowser == 1)
    {
        printf(" Auto-starting the default web browser.\nStarting the web browser using this command:\n");
        sprintf (szBuffer, "cmd /c start http://%s:%d/", szIPAddress, iPort);
        printf ("%s\n", szBuffer);
        system (szBuffer);
        printf("Web browser should be running.\n");
    }
    else
    {
        printf(" Not auto-starting the web browser.\nConnect with a web browser to this URL:\n");
        printf("http://%s:%d/\n", szIPAddress, iPort);
    }
#else
    printf("\nConnect with a web browser to this URL:\n");
    printf("http://%s:%d/\n", szIPAddress, iPort);
#endif // WIN32
    printf("Use Ctrl-C to stop the program.\n");

    //
    // main while loop
    //
    while (1)
    {
        cFileLock = 0;
        pszPostBuf[0] = 0;

        addr_size = sizeof (structClientAddr);

        // accept the socket connection
        iClientSocket = accept (iListenSocket, (struct sockaddr *) &structClientAddr, &addr_size);

        if (iClientSocket == -1)
        {
            printf("Error with the accept operation.\n");
            return 1;
        }

        // ok, here is a weird thing. Multiple web browsers (seen this with both IE and Firefox) go as
        //  far as starting to establish a TCP/IP connection to servers when they are evaluating if they
        //  need to get an object from server, however, they identify that they already have the object
        //  in cache, leaving the connection hanging. Now, if the server times out the connection then
        //  there is the REAL risk that the client is going to try and reuse the TCP/IP connection that
        //  is already in the middle of being closed down, which is already triggering a 500 status
        //  return. So, I need to DISABLE the server timeout, and just let the client timeout, which is
        //  really weird, and could probably result in the program locking up if the client should crash.
        // Let's hope that the end user isn't brave enough to run this across a small network
        //  (even if it is virtual).
        //structTimeout.tv_sec = 300;
        //structTimeout.tv_usec = 0;

        // apply the timeout to this socket
        //if (setsockopt (iClientSocket, SOL_SOCKET, SO_RCVTIMEO, (char*)&structTimeout, sizeof (structTimeout)) < 0)
        //{
        //    printf("Unable to set the timeout value.\n");
        //    return 1;
        //}

#ifndef WIN32
        inet_ntop (AF_INET, &(structClientAddr.sin_addr), szClientIPAddress, INET_ADDRSTRLEN);
#else // WIN32
        // Windows is missing the thread-safe inet_ntop function, so I use inet_ntoa instead and copy aside the results.
        {
            char *pszAddr;
            u_long iMode = 0;

            pszAddr = inet_ntoa (structClientAddr.sin_addr);

            strncpy (szClientIPAddress, pszAddr, INET_ADDRSTRLEN - 1);
            szClientIPAddress[INET_ADDRSTRLEN - 1] = 0;

            // while I am at it, I am setting Blocking mode on the socket (which is not the default).
            iRet = ioctlsocket (iClientSocket, FIONBIO, &iMode);
            if (iRet != NO_ERROR)
            {
                printf("Failure %d with the ioctlsocket call.\n", iRet);
                return 1;
            }
        }
#endif // WIN32

        printf ("client %s %d: ", szClientIPAddress, (int)structClientAddr.sin_port);

        // first, I zero out the entire input buffer (what was used earlier).
        for (iCount = 0; iCount < (iRequestSize + 1); iCount++)
            pszRequestBuf[iCount] = 0;

        iRequestSize = 0;
        iCount = 0;
        sFinished = 0;

        // while loop to read
        while (1)
        {
            // workout the size left
            iRequestLeft = iRequestAlloc - iRequestSize;

            // read data from the client socket
#ifdef WIN32
            iRet = (int)recv (iClientSocket, (char *)&pszRequestBuf[iRequestSize], (int)iRequestLeft, 0);
#else // WIN32
            iRet = (int)read (iClientSocket, (void *)&pszRequestBuf[iRequestSize], (size_t)iRequestLeft);
#endif // WIN32

            if (iRet == -1)
            {
#ifdef WIN32
                int nError = WSAGetLastError ();

                if (nError == WSAEWOULDBLOCK)
                {
                    futils_sleep (1);
                    continue;
                }
#endif // WIN32

                printf("Read Error.. ");
                sFinished = 500;
                break;
            }

            // if there is no more data.. erm.. how is this going to work ??
            // the reason why this is bad, is because the HTTP header was not detected on an earlier pass.
            if (iRet == 0)
            {
                printf("Invalid HTTP structure.. ");
                sFinished = 500;
                break;
            }

            iRequestSize += iRet;

            pszPointer1 = strstr (pszRequestBuf, "\r\n\r\n");

            // we found the end of marker for the HTTP header, but I have no idea if it is intact.
            if (pszPointer1 != NULL)
                break;

            iCount++;

            if (iCount > 10)
            {
                printf("Missing end of HTTP header.. ");
                sFinished = 500;
                break;
            }
            printf("# ");
        }

        // try and workout if this is a get or POST operation.
        if (sFinished == 0)
        {
            if (strncmp (pszRequestBuf, "GET ", 4) == 0)
            {
                printf ("GET ");
                cPostData = 0;
            }
            else if (strncmp (pszRequestBuf, "POST ", 5) == 0)
            {
                printf ("POST ");
                cPostData = 1;
            }
            else
            {
                printf ("unknown operation ");
                sFinished = 501;
            }
        }

        // now to figure out the URL
        if (sFinished == 0)
        {
            pszPointer1 = pszRequestBuf;

            // find the end of the line.
            pszPointer2 = strstr (pszRequestBuf, "\n");

            if (pszPointer2 != NULL)
                // we found the end of the string.
                iInputOffset = pszPointer2 - pszPointer1;
            else
                // if we did not find the end of the string..
                //  set this to 0, and let the operation below fail.
                iInputOffset = 0;

            // if this looks invalid, bail out.
            if ((iInputOffset < 6) || (iInputOffset > 200))
            {
                printf ("URL overrun ");
                sFinished = 500;
            }
            else
            {
                // copy aside the input string.
                strncpy (szBuffer1, pszRequestBuf, iInputOffset);
                szBuffer1[iInputOffset] = 0;

                if (cPostData == 0) // set the offset for the GET
                {
                    pszPointer1 = szBuffer1 + 4;
                    iInputOffset = 4;
                }
                else // (cPostData == 1) // set the offset for the POST
                {
                    pszPointer1 = szBuffer1 + 5;
                    iInputOffset = 5;
                }

                // go and find the end of the URL
                while (1)
                {
                    if (szBuffer1[iInputOffset] == 0)
                        break;

                    if (szBuffer1[iInputOffset] == ' ')
                        break;

                    iInputOffset++;
                }

                // check to see if this is premature.
                if (szBuffer1[iInputOffset] == 0)
                {
                    printf ("Invalid header ");
                    sFinished = 500;
                }

                // I don't care about the version number, as long as I have a valid URL.
                szBuffer1[iInputOffset] = 0;
                strcpy (szURL, pszPointer1);

                printf ("%s, ", szURL);

                // The only URL to accept post operations is the / URL
                if ((strcmp (pszPointer1, "/") != 0) && (cPostData == 1))
                {
                    sFinished = 404;
                }
                // if this is a get, and not the root, search the catalog
                else if ((cPostData == 0) && (strcmp (pszPointer1, "/") != 0))
                {
                    for (iOffset1 = 0; iOffset1 < iFileCatalogSize; iOffset1++)
                    {
                        if (strcmp (pszPointer1, pstruct_FileCatalog[iOffset1].szFileName) == 0)
                        {
                            cFileLock = 1;
                            break;
                        }
                    }

                    if (cFileLock == 0)
                    {
                        sFinished = 404;
                    }
                }
            }
        }

        // now to start the necessary processing for the post data (decode the content-length header value).
        if ((sFinished == 0) && (cPostData == 1))
        {
            // is the content-length header in the request payload.
            pszPointer1 = strstr (pszRequestBuf, "Content-Length: ");

            if (pszPointer1 == NULL)
            {
                printf ("Missing Content-Length ");
                sFinished = 500;
            }
            else
            {
                // make sure it is terminated with a newline
                pszPointer2 = strstr (pszPointer1, "\n");

                if (pszPointer2 != NULL)
                    // we found the end of the string.
                    iInputOffset = pszPointer2 - pszPointer1;
                else
                    // if we did not find the end of the string..
                    //  set this to 0, and let the operation below fail.
                    iInputOffset = 0;

                // if this looks invalid, bail out.
                if ((iInputOffset < 15) || (iInputOffset > 200))
                {
                    printf ("Corrupt Content-Length ");
                    sFinished = 500;
                }
                else
                {
                    // copy over the header.
                    strncpy (szBuffer1, pszPointer1, iInputOffset);
                    szBuffer1[iInputOffset] = 0;

                    // we know that this field should start with "Content-Length: ",
                    //  which is 16 chars long.
                    iInputOffset = 15;

                    // let's make the assumption that there might be more than one space character.
                    while (1)
                    {
                        if (szBuffer1[iInputOffset] == ' ')
                        {
                            iInputOffset++;
                            continue;
                        }

                        break;
                    }

                    if (szBuffer1[iInputOffset] == 0)
                    {
                        printf ("Null Content-Length ");
                        sFinished = 500;
                    }
                    else
                    {
                        pszPointer2 = szBuffer1 + iInputOffset;

                        while (1)
                        {
                            if (szBuffer1[iInputOffset] == 0)
                                break;

                            // this character should not have been copied across, but I am checking for it anyway.
                            if (szBuffer1[iInputOffset] == '\n')
                                break;

                            // this character should not have been copied across, but I am checking for it anyway.
                            if (szBuffer1[iInputOffset] == '\r')
                                break;

                            iInputOffset++;
                        }

                        szBuffer1[iInputOffset] = 0;
                        iPostSize = atoi (pszPointer2);

                        if (iPostSize < 1)
                        {
                            printf ("Invalid Content-Length ");
                            sFinished = 500;
                        }
                        else if (iPostSize > 1024)
                        {
                            printf ("Overrun Content-Length ");
                            sFinished = 500;
                        }
                        else
                            printf ("%d posted bytes, ", iPostSize);
                    }
                }
            }
        }

        // continue the necessary processing for the post data
        if ((sFinished == 0) && (cPostData == 1))
        {
            // iPostSize should now contain the amount of post data that follows the header.
            // we know how much input we have, so we need to calculate how large the header is
            // in the input. Once that is done, we can determine if we have anymore data to
            // read from the input.

            pszPointer1 = strstr (pszRequestBuf, "\r\n\r\n");

            // it should be impossible for pszPointer1 to be NULL, because that was checked up top.
            //  if it is, then this next calculation is going to fail anyway.

            iInputOffset = pszPointer1 - pszRequestBuf;

            if ((iInputOffset < 0) || (iInputOffset > 4096) || (iInputOffset > iRequestSize))
            {
                printf ("Header Overrun ");
                sFinished = 500;
            }
            else
            {
                iInputOffset += 4;
                iCount = 0;

                // continue reading till we get the data we want
                while ((iInputOffset + iPostSize) > iRequestSize)
                {
                    // workout the size left
                    iRequestLeft = iRequestAlloc - iRequestSize;

                    // read data from the client socket
                    iRet += (int)read (iClientSocket, (void *)&pszRequestBuf[iRequestSize], (size_t)iRequestLeft);

                    if (iRet == -1)
                    {
                        printf("Read POST Error.. ");
                        sFinished = 500;
                        break;
                    }

                    // if there is no more data.. erm.. how is this going to work ??
                    if (iRet == 0)
                    {
                        printf("Invalid POST structure.. ");
                        sFinished = 500;
                        break;
                    }

                    iRequestSize += iRet;
                    pszRequestBuf[iRequestSize] = 0;

                    iCount++;

                    if (iCount > 10)
                    {
                        printf("Missing POST data.. ");
                        sFinished = 500;
                        break;
                    }
                }

                if (sFinished == 0)
                {
                    httppost_urlConvertList (&pszRequestBuf[iInputOffset], pszPostBuf, iPostSize);
                    // we now have our converted post data.
                }
            }
        }

        if ((sFinished == 0) && (cFileLock == 0))
        {
            int iPos;
            char cLock = 0;
            int iSceneId = 0;
            int iSubSceneId = 0;
            char szTrackingId[50];
            char szSceneId[24];
            char szMenuValue[40];
            int iSaveFile = 0;
            char cCompleteOutput = 0;

            int iMainAction = 0;
            // 0 = main menu (default).
            // 1 = about menu.
            // 2 = credits menu.
            // 3 = load menu.
            // 4 = save menu.
            // 5 = change skin.
            // 6 = spoiler menu.
            // 7 = load action (iSaveFile means something).
            // 8 = save action (iSaveFile means something).
            // 10 = game action.
            // 11 = restore last autosave.
            // 12 = start new.

            //
            // this is where the dynamic content is produced.
            //

            futils_wipeFileBuffer (&gstruct_FileBuffHdr);
            futils_wipeFileBuffer (&gstruct_FileBuffOut);

            printf ("S ");
            futils_addStringToFileBufferEnd ("HTTP/1.0 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\nConnection: close\r\nPragma: No-cache\r\nCache-Control: no-cache\r\n", &gstruct_FileBuffHdr);

            iRet = futils_addStringToFileBufferEnd ("<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"icon\" type=\"image/x-icon\" href=\"BMPS.ico\" />\n<title>Bunny, Mayoress, Prostitute & Succubus (BMPS) v", &gstruct_FileBuffOut);

            if (iRet == 0)
                iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

            if (iRet == 0)
                iRet = futils_addStringToFileBufferEnd ("</title>\n<style type=\"text/css\">\n", &gstruct_FileBuffOut);

            if (iRet != 0)
            {
                printf ("\nCannot start output initial\n");
                sFinished = 500;
            }

            // figure out what we are doing.. (cPostData == 1 is a POST operation, 0 is a GET).
            if ((cPostData == 1) && (sFinished == 0))
            {
                iRet = httppost_extractEntry (pszPostBuf, "menu=", szMenuValue, 38);

                if (iRet != 0)
                {
                    iRet = httppost_extractEntry (pszPostBuf, "game=", szMenuValue, 38);

                    if (iRet == 0)
                    {
                        if (strcmp (szMenuValue, "Submit") == 0)
                        {
                            iRet = httppost_extractEntry (pszPostBuf, "track=", szTrackingId, 48);

                            if (iRet == 0)
                            {
                                iRet = httppost_extractEntry (pszPostBuf, "sc=", szSceneId, 22);

                                if (iRet == 0)
                                {
                                    if ((szSceneId[4] == '.') && ((int)strlen (szSceneId) > 5))
                                    {
                                        szSceneId[4] = 0;

                                        iSceneId = atoi (szSceneId);
                                        iSubSceneId = atoi (&szSceneId[5]);
                                        iCount = 0;

                                        while (1)
                                        {
                                            if (gstructSceneList[iCount].iSceneId == -1)
                                                break;

                                            if (gstructSceneList[iCount].iSceneId == iSceneId)
                                            {
                                                iMainAction = 10;
                                                break;
                                            }

                                            iCount++;
                                        }

                                        if (iMainAction != 10)
                                        {
                                            printf ("\nInvalid scene id %d\n", iSceneId);
                                            sFinished = 500;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (strncmp (szMenuValue, "Start ", 6) == 0)
                    {
                        iMainAction = 12; // start a new game
                    }
                    else if (strncmp (szMenuValue, "Save S", 6) == 0)
                    {
                        iMainAction = 4; // save screen
                    }
                    else if (strncmp (szMenuValue, "Resume", 6) == 0)
                    {
                        iMainAction = 11; // restore last autosave
                    }
                    else if (strncmp (szMenuValue, "Load a", 6) == 0)
                    {
                        iMainAction = 3; // load screen
                    }
                    else if (strncmp (szMenuValue, "About ", 6) == 0)
                    {
                        iMainAction = 1; // about screen
                    }
                    else if (strncmp (szMenuValue, "BMPS s", 6) == 0)
                    {
                        iMainAction = 6; // Spoiler menu
                    }
                    else if (strncmp (szMenuValue, "Skin c", 6) == 0)
                    {
                        iMainAction = 5; // Skin change function
                    }
                    else if (strncmp (szMenuValue, "BMPS c", 6) == 0)
                    {
                        iMainAction = 2; // credits screen
                    }
                    else if (strncmp (szMenuValue, "Slot ", 5) == 0)
                    {
                        if (strncmp (szMenuValue, "Slot 1", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 1; // save file 1
                        }
                        else if (strncmp (szMenuValue, "Slot 2", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 2; // save file 2
                        }
                        else if (strncmp (szMenuValue, "Slot 3", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 3; // save file 3
                        }
                        else if (strncmp (szMenuValue, "Slot 4", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 4; // save file 4
                        }
                        else if (strncmp (szMenuValue, "Slot 5", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 5; // save file 5
                        }
                        else if (strncmp (szMenuValue, "Slot 6", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 6; // save file 6
                        }
                        else if (strncmp (szMenuValue, "Slot 7", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 7; // save file 7
                        }
                        else if (strncmp (szMenuValue, "Slot 8", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 8; // save file 8
                        }
                        else if (strncmp (szMenuValue, "Slot 9", 6) == 0)
                        {
                            iMainAction = 7; // load action
                            iSaveFile = 9; // save file 9
                        }
                    }
                    else if (strncmp (szMenuValue, "Save t", 6) == 0)
                    {
                        if (strncmp (szMenuValue, "Save to slot 1", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 1; // save file 1
                        }
                        else if (strncmp (szMenuValue, "Save to slot 2", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 2; // save file 2
                        }
                        else if (strncmp (szMenuValue, "Save to slot 3", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 3; // save file 3
                        }
                        else if (strncmp (szMenuValue, "Save to slot 4", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 4; // save file 4
                        }
                        else if (strncmp (szMenuValue, "Save to slot 5", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 5; // save file 5
                        }
                        else if (strncmp (szMenuValue, "Save to slot 6", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 6; // save file 6
                        }
                        else if (strncmp (szMenuValue, "Save to slot 7", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 7; // save file 7
                        }
                        else if (strncmp (szMenuValue, "Save to slot 8", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 8; // save file 8
                        }
                        else if (strncmp (szMenuValue, "Save to slot 9", 14) == 0)
                        {
                            iMainAction = 8; // save action
                            iSaveFile = 9; // save file 9
                        }
                    }
                }
            }

            // if this is the Skin change function..
            if ((cCompleteOutput == 0) && (iMainAction == 5) && (sFinished == 0))
            {
                szSceneId[0] = 0;

                httppost_extractEntry (pszPostBuf, "skin=", szSceneId, 8);

                htmlskin_setSkin (szSceneId);

                // set to the default of the menu, and leave it at that.
                iMainAction = 0;
            }

            // now we can output the stylesheet information.
            if (sFinished == 0)
            {
                iRet = htmlskin_includeCurrentSkin (&gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd ("</style>\n</head>\n<body>\n", &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    printf ("\nCannot start output style sheet information\n");
                    sFinished = 500;
                }
            }

            // if this is the About menu..
            if ((cCompleteOutput == 0) && (iMainAction == 1) && (sFinished == 0))
            {
                iRet = menuraw_outputAboutMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            // if this is the Credits menu..
            if ((cCompleteOutput == 0) && (iMainAction == 2) && (sFinished == 0))
            {
                iRet = menuraw_outputCreditsMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            // if this is the Load menu..
            if ((cCompleteOutput == 0) && (iMainAction == 3) && (sFinished == 0))
            {
                iRet = menuraw_outputLoadMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            // if this is the Save menu..
            if ((cCompleteOutput == 0) && (iMainAction == 4) && (sFinished == 0))
            {
                iRet = menuraw_outputSaveMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            // if this is the Spoilers menu..
            if ((cCompleteOutput == 0) && (iMainAction == 6) && (sFinished == 0))
            {
                iRet = menuraw_outputSpoilersMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            // this is the load action
            if ((cCompleteOutput == 0) && (iMainAction == 7) && (sFinished == 0))
            {
#ifdef WIN32
                sprintf (szBuffer, "copy BMPS.save%d.txt BMPS.autosave.txt /y", iSaveFile);
#else // WIN32
                sprintf (szBuffer, "cp BMPS.save%d.txt BMPS.autosave.txt", iSaveFile);
#endif // WIN32
                iRet = system (szBuffer);

                if (iRet != 0)
                {
                    printf ("\nCould not rename save file to the autosave file.\n");
                    sFinished = 500;
                }

                // now that is complete, perform main action 11, which restores the game from the autosave.
                iMainAction = 11;
            }

            // this is the save action
            if ((cCompleteOutput == 0) && (iMainAction == 8) && (sFinished == 0))
            {
#ifdef WIN32
                sprintf (szBuffer, "copy BMPS.autosave.txt BMPS.save%d.txt /y", iSaveFile);
#else // WIN32
                sprintf (szBuffer, "cp BMPS.autosave.txt BMPS.save%d.txt", iSaveFile);
#endif // WIN32

                iRet = system (szBuffer);

                if (iRet != 0)
                {
                    printf ("\nCould not rename autosave file to the save file.\n");
                    sFinished = 500;
                }

                // now that is complete, perform main action 11, which restores the game from the autosave.
                iMainAction = 11;
            }

            // if we are restoring the game from the last save, load the last save.
            if (((iMainAction == 10) || (iMainAction == 11)) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                iRet = statefile_loadSaveFile ("BMPS.autosave.txt");

                if (iRet != 0)
                {
                    iRet = futils_addStringToFileBufferEnd ("Error: Loading autosave file.<br/>(going back to main)<br/><br/>\n", &gstruct_FileBuffOut);
                    if (iRet != 0)
                    {
                        printf ("\nCould not buffer autosave warning.\n");
                        sFinished = 500;
                    }

                    iMainAction = 0;
                }
            }

            // if we are acting upon a game continuation action, check it.
            if ((iMainAction == 10) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                if (strcmp (szTrackingId, gszSessionTrackingId) != 0)
                {
                    // if the tracking id is inconsistent, send the player back to the main menu with a warning.
                    iRet = futils_addStringToFileBufferEnd ("Error: Tracking Id mismatch.<br/>(going back to main)<br/><br/>\n", &gstruct_FileBuffOut);
                    if (iRet != 0)
                    {
                        printf ("\nCould not buffer trackingid warning.\n");
                        sFinished = 500;
                    }

                    iMainAction = 0;
                }
                else
                {
                    cLock = 0;
                    iPos = 0;

                    for (iPos = 0; iPos < giCommandListUsed; iPos++)
                    {
                        if (gstruct_CommandList[iPos].cUseFlag == 0)
                            continue;

                        if (gstruct_CommandList[iPos].iSceneId != iSceneId)
                            continue;

                        if (gstruct_CommandList[iPos].iSubSceneId != iSubSceneId)
                            continue;

                        cLock = 1;
                        break;
                    }

                    if (cLock == 0)
                    {
                        // if the tracking id is inconsistent, send the player back to the main menu with a warning.
                        iRet = futils_addStringToFileBufferEnd ("Error: Scene/Sub-Scene Id mismatch.<br/>(going back to main)<br/><br/>\n", &gstruct_FileBuffOut);
                        if (iRet != 0)
                        {
                            printf ("\nCould not buffer sceneid warning.\n");
                            sFinished = 500;
                        }

                        iMainAction = 0;
                    }
                }
            }

            // if this is a start a new game.. start things off.
            if ((iMainAction == 12) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                mutils_addToDialogBuffer ("<br/>\n");

                iSubSceneId = 0;
                iSceneId = 1001; // this is the start of the game.
                iCount = 0;

                while (1)
                {
                    if (gstructSceneList[iCount].iSceneId == -1)
                        break;

                    if (gstructSceneList[iCount].iSceneId == 1001)
                    {
                        iMainAction = 10; // merge into the game continue action
                        break;
                    }

                    iCount++;
                }

                if (iMainAction != 10)
                {
                    printf ("\nCould not find start scene id 1001.0.\n");
                    sFinished = 500;
                }
            }

            // merge in game start and continue here.
            if ((iMainAction == 10) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                // Note: iCount should still set from earlier.
                if (iCount == -1)
                {
                    printf ("\nScene offset is missing.\n");
                    sFinished = 500;
                }
            }

            if ((iMainAction == 10) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                // To make it here means that we have a valid action to continue what we are doing.
                mutils_initAndClearCommandList ();
                mutils_addDialogToArchive (0);

                // this is where the actual referenced function is called.
                iRet = gstructSceneList[iCount].vFunc (iSubSceneId, 0);

                if (iRet != 0)
                {
                    printf ("\nReturn %d from Scene function %d.%d.\n", iRet, iSceneId, iSubSceneId);
                    sFinished = 500;
                }

                iMainAction = 11; // merge into the restore last save action
            }

            // Here we work with the data that we have restored..
            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                pidMe++;

                if (pidMe > 64000)
                    pidMe = 10;

                time (&tTime);

                // rebuild the tracking id.
                sprintf (gszSessionTrackingId, "%ld.%d", tTime, pidMe);

                // rewrite the autosave file.
                iRet = statefile_writeSaveFile ("BMPS.autosave.txt");

                if (iRet != 0)
                {
                    printf ("\nCould not write the autosave file.\n");
                    sFinished = 500;
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                // now start shoving the updated dialog across into the HTTP output buffer.

                iRet = futils_addStringToFileBufferEnd ("<div id=\"past\">\n", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd (gpszArchiveBuffer, &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd ("</div>\n<div id=\"current\"/>\n", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd (gpszDialogBuffer, &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    printf ("\nCould not buffer the dialog text.\n");
                    sFinished = 500;
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                // if there are no commands, write out the main menu command buttons, and leave it at that.
                if (giCommandListUsed == 0)
                {
                    iRet = menuraw_outputFullMenu (10);
                    if (iRet != 0)
                        sFinished = 500;

                    cCompleteOutput = 1;
                }
            }

            // if we are still working with start/continue/restored data, and we have actual command entries to work with.
            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                iRet = futils_addStringToFileBufferEnd ("<hr>\n<script type=\"text/javascript\">\nfunction enableSubmit() {\n document.forms[\"nav\"][\"submit\"].disabled=false;\n}\n", &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    printf ("\nCould not buffer the start of the javascript.\n");
                    sFinished = 500;
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                for (iPos = 0; iPos < giCommandListUsed; iPos++)
                {
                    // ergh.. Microsoft IE 11 has a "wonderful" bug, where it cannot find radio button elements that are in the form array,
                    //  so it is necessary to change the code so it looks up the radio button by the element id. Funnily enough it can
                    //  still work the right way, when there are multiple "submit" buttons involved (go figure).
//                    sprintf (szBuffer, "function sel%d%c%d() {\n document.forms[\"nav\"][\"%d%c%d\"].checked=true;\n document.forms[\"nav\"][\"submit\"].disabled=false;\n}\n",
//                            (int)gstruct_CommandList[iPos].iSceneId, 'w', (int)gstruct_CommandList[iPos].iSubSceneId,
//                            (int)gstruct_CommandList[iPos].iSceneId, '.', (int)gstruct_CommandList[iPos].iSubSceneId);

                    sprintf (szBuffer, "function sel%d%c%d() {\n document.getElementById(\'%d%c%d\').checked=true;\n document.forms[\"nav\"][\"submit\"].disabled=false;\n}\n",
                            (int)gstruct_CommandList[iPos].iSceneId, 'w', (int)gstruct_CommandList[iPos].iSubSceneId,
                            (int)gstruct_CommandList[iPos].iSceneId, '.', (int)gstruct_CommandList[iPos].iSubSceneId);

                    iRet = futils_addStringToFileBufferEnd (szBuffer, &gstruct_FileBuffOut);

                    if (iRet != 0)
                    {
                        printf ("\nCould not buffer menu entry into the javascript section.\n");
                        sFinished = 500;

                        break;
                    }
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                iRet = futils_addStringToFileBufferEnd ("</script>\n<form id=\"nav\" action=\"/#current\" method=\"POST\">\n <input type=\"hidden\" name=\"track\" value=\"", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd (gszSessionTrackingId, &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd ("\" />\n", &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    printf ("\nCould not buffer the start of the form section.\n");
                    sFinished = 500;
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                for (iPos = 0; iPos < giCommandListUsed; iPos++)
                {
                    sprintf (szBuffer, " <input type=\"radio\" id=\"%d%c%d\" name=\"sc\" onchange=\"enableSubmit()\" value=\"%d%c%d\"><a href=\"javascript:void(0);\" onclick=\"sel%d%c%d()\" />%s</a><br>\n",
                            (int)gstruct_CommandList[iPos].iSceneId, '.', (int)gstruct_CommandList[iPos].iSubSceneId,
                            (int)gstruct_CommandList[iPos].iSceneId, '.', (int)gstruct_CommandList[iPos].iSubSceneId,
                            (int)gstruct_CommandList[iPos].iSceneId, 'w', (int)gstruct_CommandList[iPos].iSubSceneId,
                            gstruct_CommandList[iPos].pszCommand);

                    iRet = futils_addStringToFileBufferEnd (szBuffer, &gstruct_FileBuffOut);

                    if (iRet != 0)
                    {
                        printf ("\nCould not buffer menu entry into the form section.\n");
                        sFinished = 500;
                        break;
                    }
                }
            }

            if ((iMainAction == 11) && (cCompleteOutput == 0) && (sFinished == 0))
            {
                iRet = futils_addStringToFileBufferEnd (" <input type=\"submit\" id=\"submit\" name=\"game\" value=\"Submit\" disabled>\n</form>\n", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd ("<hr>\n<center>\n<form action=\"/#current\" method=\"POST\">\n <input type=\"submit\" name=\"menu\" value=\"Save Screen\" />\n <input type=\"submit\" name=\"menu\" value=\"Main Menu\" />\n</form>\n</center>\n", &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    printf ("\nCould not buffer the end mini-menu.\n");
                    sFinished = 500;
                }

                cCompleteOutput = 1;
            }

            // default is to dump out the main menu.
            if ((cCompleteOutput == 0) && (sFinished == 0))
            {
                iRet = menuraw_outputMainMenu ();
                if (iRet != 0)
                    sFinished = 500;
                cCompleteOutput = 1;
            }

            if ((cCompleteOutput == 0) && (sFinished == 0))
            {
                // cap the end of the HTML document.
                iRet = futils_addStringToFileBufferEnd ("</body>\n</html>\n", &gstruct_FileBuffOut);
                if (iRet != 0)
                {
                    printf ("\nCould not buffer the end of the document.\n");
                    sFinished = 500;
                }
            }

            if (sFinished == 0)
            {
                printf ("200 ");
                sprintf (szBuffer1, "Content-Length: %d\r\n\r\n", (int)gstruct_FileBuffOut.ulBufferPos);

                futils_addStringToFileBufferEnd (szBuffer1, &gstruct_FileBuffHdr);

                send (iClientSocket, (void *)gstruct_FileBuffHdr.pcData, (size_t)gstruct_FileBuffHdr.ulBufferPos, 0);
                send (iClientSocket, (void *)gstruct_FileBuffOut.pcData, (size_t)gstruct_FileBuffOut.ulBufferPos, 0);

                futils_wipeFileBuffer (&gstruct_FileBuffHdr);
                futils_wipeFileBuffer (&gstruct_FileBuffOut);
            }
        }
        else if (cFileLock != 0)
        {
            //
            // This is where we work with the datastore to pull out the static file and shove it out the HTTP connection.
            //

            futils_wipeFileBuffer (&gstruct_FileBuffHdr);
            futils_wipeFileBuffer (&gstruct_FileBuffOut);

            printf ("File ");

            // go to the file position in the datafile.
            _lseek (iDataFileHandle, (off_t)(pstruct_FileCatalog[iOffset1].iStartPos), SEEK_SET);

            // load that file into memory
            iRet = futils_loadOpenedFileIntoMemory (iDataFileHandle, pstruct_FileCatalog[iOffset1].iFileSize, &gstruct_FileBuffOut);

            if (iRet == 0)
            {
                int iExtPos = (int)(strlen (pstruct_FileCatalog[iOffset1].szFileName)) - 4;

                if (strcmp (&pstruct_FileCatalog[iOffset1].szFileName[iExtPos], ".ico") == 0)
                {
                    printf ("ico ");
                    futils_addStringToFileBufferEnd ("HTTP/1.0 200 OK\r\nContent-Type: image/ico\r\n", &gstruct_FileBuffHdr);
                }
                else if (strcmp (&pstruct_FileCatalog[iOffset1].szFileName[iExtPos], ".png") == 0)
                {
                    printf ("png ");
                    futils_addStringToFileBufferEnd ("HTTP/1.0 200 OK\r\nContent-Type: image/png\r\n", &gstruct_FileBuffHdr);
                }
                else
                {
                    printf ("jpg ");
                    futils_addStringToFileBufferEnd ("HTTP/1.0 200 OK\r\nContent-Type: image/jpg\r\n", &gstruct_FileBuffHdr);
                }

                sprintf (szBuffer1, "Cache-Control: private, max-age=600\r\nConnection: close\r\nContent-Length: %d\r\n\r\n", (int)pstruct_FileCatalog[iOffset1].iFileSize);

                futils_addStringToFileBufferEnd (szBuffer1, &gstruct_FileBuffHdr);

                send (iClientSocket, (void *)gstruct_FileBuffHdr.pcData, (size_t)gstruct_FileBuffHdr.ulBufferPos, 0);
                send (iClientSocket, (void *)gstruct_FileBuffOut.pcData, (size_t)pstruct_FileCatalog[iOffset1].iFileSize, 0);

                futils_wipeFileBuffer (&gstruct_FileBuffHdr);
                futils_wipeFileBuffer (&gstruct_FileBuffOut);
            }
            else
            {
                printf ("(error) ");
                sFinished = 500;
            }
        }

        if (sFinished != 0)
        {
            futils_wipeFileBuffer (&gstruct_FileBuffHdr);
            futils_wipeFileBuffer (&gstruct_FileBuffOut);

            if (sFinished == 404)
            {
                printf ("404 ");
                futils_addStringToFileBufferEnd ("HTTP/1.0 404 Not Found\r\nContent-Type: text/html; charset=UTF-8\r\nConnection: close\r\nPragma: No-cache\r\nCache-Control: no-cache\r\n", &gstruct_FileBuffHdr);
                futils_addStringToFileBufferEnd ("<!DOCTYPE html>\n<html>\n<body>\n404 Not Found\n</body>\n</html>\n", &gstruct_FileBuffOut);
                sprintf (szBuffer1, "Content-Length: %d\r\n\r\n", (int)gstruct_FileBuffOut.ulBufferPos);
                futils_addStringToFileBufferEnd (szBuffer1, &gstruct_FileBuffHdr);
            }
            else if (sFinished == 501)
            {
                printf ("501 ");
                futils_addStringToFileBufferEnd ("HTTP/1.0 501 Not Implemented\r\nContent-Type: text/html; charset=UTF-8\r\nConnection: close\r\nPragma: No-cache\r\nCache-Control: no-cache\r\n", &gstruct_FileBuffHdr);
                futils_addStringToFileBufferEnd ("<!DOCTYPE html>\n<html>\n<body>\n501 Not Found\n</body>\n</html>\n", &gstruct_FileBuffOut);
                sprintf (szBuffer1, "Content-Length: %d\r\n\r\n", (int)gstruct_FileBuffOut.ulBufferPos);
                futils_addStringToFileBufferEnd (szBuffer1, &gstruct_FileBuffHdr);
            }
            else // (sFinished == 500)
            {
                printf ("500 ");
                futils_addStringToFileBufferEnd ("HTTP/1.0 500 Internal Server Error\r\nContent-Type: text/html; charset=UTF-8\r\nConnection: close\r\nPragma: No-cache\r\nCache-Control: no-cache\r\n", &gstruct_FileBuffHdr);
                futils_addStringToFileBufferEnd ("<!DOCTYPE html>\n<html>\n<body>\n500 Internal Server Error\n</body>\n</html>\n", &gstruct_FileBuffOut);
                sprintf (szBuffer1, "Content-Length: %d\r\n\r\n", (int)gstruct_FileBuffOut.ulBufferPos);
                futils_addStringToFileBufferEnd (szBuffer1, &gstruct_FileBuffHdr);
            }

            send (iClientSocket, (void *)gstruct_FileBuffHdr.pcData, (size_t)gstruct_FileBuffHdr.ulBufferPos, 0);
            send (iClientSocket, (void *)gstruct_FileBuffOut.pcData, (size_t)gstruct_FileBuffOut.ulBufferPos, 0);

            futils_wipeFileBuffer (&gstruct_FileBuffHdr);
            futils_wipeFileBuffer (&gstruct_FileBuffOut);
        }

        close (iClientSocket);

        printf ("done.\n");
    }

    printf("Exiting (how?)\n");
    return 0;
}

