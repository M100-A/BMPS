//
// common.h
//
// Common header file, where I dump system wide configuration things, such as include files, and my own generic definitions and functions.
//

//
// Given that I tend to write "semi-portable" code, there is a lot of ifdef WIN32 stuff in here..
//
// Unless I test for the platform, there is no guarantee that it will work..
//

// this is the raw HTTP version of the program, so the curses and CGI-BIN interfaces are knocked out.
//#define INTERFACE_CURSES 1
//#define INTERFACE_CGI 1
#define INTERFACE_RAW_HTTP 1

// This version needs to be able to cross compile, so there are conditional WIN32 statements in here.

#ifdef WIN32

#include    <windows.h>
#include    <winsock2.h>
#include    <ws2tcpip.h>

#include    <stdio.h>       // for sprintf
#include    <stdarg.h>
#include    <stdlib.h>
#include    <fcntl.h>
#include    <io.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
#include    <ctype.h>
#include    <string.h>      // for strlen
#include    <memory.h>      // for malloc
#include    <time.h>        // for localtime
#include    <ctype.h>       // for islower, isupper
#include    <signal.h>      // for signal stuff

#define PERM_FILE (_S_IREAD | _S_IWRITE)

#define VOID void
#define BOOL int
#define HANDLE int

#define TRUE 1
#define FALSE 0
#define unlink _unlink

#else

#ifdef HAVE_CONFIG_H
#include    <config.h>
#endif

#ifdef INTERFACE_CURSES
#include    <ncurses.h>     // for the *NIX curses library
#endif // INTERFACE_CURSES
#include    <stdio.h>
#include    <stdarg.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>
#include    <ctype.h>
#include    <string.h>      // for strlen
#include    <memory.h>      // for malloc
#include    <time.h>        // for localtime
#ifdef INTERFACE_RAW_HTTP
#include    <signal.h>      // for signal stuff
#include    <sys/socket.h>
#include    <arpa/inet.h>
#include    <netinet/in.h>
#endif // INTERFACE_RAW_HTTP
#include    <poll.h>        // for poll (used to simulate sleep()).
#include    <dirent.h>

//----------------------------------------------------------------------
//
// *nix port over stuff.
//

#define VOID void
#define BOOL int
#define HANDLE int
#define _open open
#define _close close
#define _O_RDONLY O_RDONLY
#define _O_WRONLY O_WRONLY
#define _O_CREAT O_CREAT
#define _O_APPEND O_APPEND
#define _O_TRUNC O_TRUNC
#define _O_EXCL O_EXCL
#define _O_BINARY 0
#define _O_RSYNC O_RSYNC
#define _fstat fstat
#define _stat stat
#define _read read
#define _lseek lseek
#define _write write
#define _unlink unlink
#define _getpid getpid
#define stricmp strcasecmp
#define TRUE 1
#define FALSE 0

#define PERM_FILE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

#endif



//----------------------------------------------------------------------
//
// defines for file utils..
//

// definition for buffered file I/O structure
struct	futils_filebuff
{
                    // pointer to the buffer
    char            *pcData;
                    // size of allocated buffer
    unsigned long   ulBufferSize;
                    // position in the buffer
    unsigned long   ulBufferPos;
                    // amount of data currently in buffer
    unsigned long   ulBufferMax;

    unsigned long   ulFileTotSpc;
                    // set if there is a memory buffer allocated !
    BOOL            bMemFlag;
};

// replacement for strnicmp
int futils_strnicmp (char *pszStr1, char *pszStr2, size_t iLength);

// generic sleep function
void futils_sleep (int iTimeout);

// preallocate the memory image
int futils_preAllocateBuffer (unsigned long ulBufferSize, struct futils_filebuff *pstructFullFile);

// load text file into memory image
int futils_loadFileIntoMemory (char *pszFileName, struct futils_filebuff *pstructFullFile);

#ifdef INTERFACE_RAW_HTTP
// load part of an already opened file into memory
int futils_loadOpenedFileIntoMemory (int iFileHandle, int iSizeLoad, struct futils_filebuff *pstructFullFile);
#endif // INTERFACE_RAW_HTTP

// read a single line from a file
int futils_readLineFromMemoryNoEndLineCombo (struct futils_filebuff *pstructFullFile, char *pszBuf, unsigned long ulMaxlen);

// wipe the memory buffer for output buffering
int futils_wipeFileBuffer (struct futils_filebuff *pstructFullFile);

// append a string to the memory output buffer
int futils_addStringToFileBufferEnd (char *pszBuf, struct futils_filebuff *pstructFullFile);

// appends a log entry to a file
void futils_writeFileHeaderAndData (char *pszFileName, char *pszHeader, char *pszData);


//----------------------------------------------------------------------
//
// defines for memory utils..
//

// definition for the temporary command struct
struct  mutils_commandlist
{
    char    cUseFlag;       // in use flag
    char    *pszCommand;    // command string
    int     iCommandSize;   // size of the command string
    int     iSceneId;       // scene id this entry corresponds to
    int     iSubSceneId;    // sub-scene id for this entry
};

// initialize the command list storage
int mutils_initAndClearCommandList ();

// add a command to the list storage
int mutils_addToCommandList (char *pszCommand, int iSceneId, int iSubSceneId);

// initialize and clear the dialog buffer storage
int mutils_initAndClearDialogBuffer ();

// suffix dialog into the dialog buffer
int mutils_addToDialogBuffer (char *pszString);

// suffix dialog into the dialog buffer (length specific)
int mutils_addToDialogBufferLenSpec (char *pszString, int iStrLen);

// migrate dialog to archive, and clear the dialog buffer
void mutils_addDialogToArchive (int iEndSubtract);

// calculate the row start offset based upon the archive data
int mutils_calcRowStartOffset (int iScrWidth);

// calculate the number of rows of the dialog buffer
int mutils_calcDialogRows (int iScrWidth);

//----------------------------------------------------------------------
//
// defines for mdialog..
//

// definition for the temporary command struct
struct  mdialog_searchreplacelist
{
    char    *pszSearch;
    char    *pszReplace;
};

struct  mdialog_dynamicreplacelist
{
    char    szSearch[4];
    short   sLink;
};

#define MDIALOG_DYNAMIC_MAX 9

// init the dynamic list
void mdialog_initDynamicList ();

// set a dynamic list entry
void mdialog_setDynamicEntry (short sOffset, short sEntry);

// suffix dialog into the dialog buffer (with search/replace)
int mdialog_addToDialogWithSrchRep (char *pszString);


#ifdef INTERFACE_CURSES
//----------------------------------------------------------------------
//
// defines for savescreen functions..
//

// initialize the savescreen command list storage
int savescreen_initAndClearCommandList ();

// add a command to the savescreen list storage
int savescreen_addToCommandList (char *pszCommand, int iSceneId, int iSubSceneId);

// initialize and clear the savescreen dialog buffer storage
int savescreen_initAndClearDialogBuffer ();

// suffix dialog into the savescreen dialog buffer
int savescreen_addToDialogBuffer (char *pszString);

// calculate the number of rows of the savescreen dialog buffer
int savescreen_calcDialogRows (int iScrWidth);

// create and display the save screen
int savescreen_playerInteract ();

// function to parse a save file (for display on the load or save dialog screens)
int savescreen_parseSaveFile (int iSaveId, char *pszDateTime);

// function to load a save file
int savescreen_loadSaveFile (int iSaveId);

#endif // INTERFACE_CURSES


#ifndef INTERFACE_CURSES
//----------------------------------------------------------------------
//
// defines for HTTP post functions..
//

// function to pre-convert the input data into a list.
void httppost_urlConvertList (char *pPostData, char *pOutput, int iLen);

// function to look for an entry in the input data.
int httppost_extractEntry (char *pPostData, char *pszLock, char *pszOutput, int iMax);

#endif // INTERFACE_CURSES


#ifdef INTERFACE_CGI

//----------------------------------------------------------------------
//
// defines for Menu CGI-BIN functions..
//

void menucgi_outputFullMenu (int iRestrict);

void menucgi_outputMainMenu ();

void menucgi_outputAboutMenu ();

void menucgi_outputCreditsMenu ();

void menucgi_outputSaveMenu ();

void menucgi_outputLoadMenu ();

// generic error output.
void menucgi_errorOutput (char *szErrorResult, int iErrorCode);

#endif // INTERFACE_CGI


#ifdef INTERFACE_RAW_HTTP

//----------------------------------------------------------------------
//
// defines for Menu raw functions..
//

int menuraw_outputFullMenu (int iRestrict);

int menuraw_outputMainMenu ();

int menuraw_outputAboutMenu ();

int menuraw_outputCreditsMenu ();

int menuraw_outputSpoilersMenu ();

int menuraw_outputSaveMenu ();

int menuraw_outputLoadMenu ();


//----------------------------------------------------------------------
//
// defines for html skin functions..
//

void htmlskin_loadStart ();

int htmlskin_includeCurrentSkin (struct futils_filebuff *pstructFullFile);

void htmlskin_setSkin (char *szValue);

#endif // INTERFACE_RAW_HTTP

