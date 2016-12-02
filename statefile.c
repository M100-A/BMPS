//
// statefile.c
//
// save/load functions for save files.
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"

// linkage to the file load structure..
extern  struct	futils_filebuff         gstruct_FileBuffGen;

// linkage to the mutils data.
extern  struct  mutils_commandlist  *gstruct_CommandList;
extern  int     giCommandListUsed;
extern  char    *gpszDialogBuffer;
extern  int     giDialogBufferUsed;
extern  int     giDialogBufferSize;
extern  char    *gpszArchiveBuffer;
extern  int     giArchiveBufferUsed;

// external linkage to the game variables.
extern struct  statedata_NPCData *gpstructNPC_Base;
extern struct  statedata_GlobalData gpstructPC_Global;

#ifndef INTERFACE_CURSES
extern char     gszSessionTrackingId[50];
#endif //INTERFACE_CURSES

//
// function to load in a save file and to partially parse it, verifying if it is usable.
//
// Note: this function does not actually load the save file, as it is meant to extract
//   and check only some detail from the file for the purposes of showing the file in a
//   list of save/load slots.
//
// returns 2 if non-existent (not enough data to indicate that it is there).
// returns 1 if invalid (could at least retrieve the date/time).
// returns 0 if it appears to be a valid save.
//
int statefile_parseSaveFile (char *pszFileName, char *pszDateTime)
{
    char    szInputString[900];
    char    szWorkString[40];
    int     iOffset;
    short   sOffset2;
    int     iValue;
    int     iYear;
    int     iMonth;
#ifdef INTERFACE_CURSES
    char    *pszMonth;
#endif // INTERFACE_CURSES
    int     iDay;
    int     iHour;
    int     iMin;
    int     iSec;
    int     iRet;

    // load the entire save file into the memory buffer
    iRet = futils_loadFileIntoMemory (pszFileName, &gstruct_FileBuffGen);

    if (iRet != 0)
        return 2;

    // start with the version line..
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 898) != 0)
    {
        return 2;
    }
    szInputString[898] = 0;

#ifdef INTERFACE_CURSES
    // check to see if it starts with what we want
    if (szInputString[0] != '!')
        return 2;
#else
    // check to see if it starts with what we want
    if (szInputString[0] != '*')
        return 2;
#endif //INTERFACE_CURSES

    // otherwise I don't care what it says

    //
    // Global values section
    //

    // next the global values section (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 2;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##BMPSGlobal") != 0)
        return 2;

    // next the global values section (size line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 2;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "=11") != 0)
        return 2;

    // next the date/time field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 20) != 0)
        return 2;
    szInputString[20] = 0;

    // Check the date/time field (and format it).

    // 00000000001111111111
    // 01234567890123456789
    // YYYY-MM-DD-hh-mm-ss

    if ((szInputString[4] != '-') || (szInputString[7] != '-') || (szInputString[10] != '-') || (szInputString[13] != '-') || (szInputString[16] != '-') || (szInputString[19] != 0))
    {
        return 2;
    }

    szInputString[4] = 0;
    szInputString[7] = 0;
    szInputString[10] = 0;
    szInputString[13] = 0;
    szInputString[16] = 0;

    iYear = atoi (szInputString);
    iMonth = atoi (&szInputString[5]);
    iDay = atoi (&szInputString[8]);
    iHour = atoi (&szInputString[11]);
    iMin = atoi (&szInputString[14]);
    iSec = atoi (&szInputString[17]);

    if ((iYear < 1) || (iMonth < 1) || (iDay < 1) || (iHour < 0) || (iMin < 0) || (iSec < 0) || (iMonth > 12) || (iDay > 31) || (iHour > 23) || (iMin > 59) || (iSec > 59))
    {
        return 2;
    }

#ifdef INTERFACE_CURSES
    switch (iMonth)
    {
    case 1:
        pszMonth = "Jan";
        break;
    case 2:
        pszMonth = "Feb";
        break;
    case 3:
        pszMonth = "Mar";
        break;
    case 4:
        pszMonth = "Apr";
        break;
    case 5:
        pszMonth = "May";
        break;
    case 6:
        pszMonth = "Jun";
        break;
    case 7:
        pszMonth = "Jul";
        break;
    case 8:
        pszMonth = "Aug";
        break;
    case 9:
        pszMonth = "Sep";
        break;
    case 10:
        pszMonth = "Oct";
        break;
    case 11:
        pszMonth = "Nov";
        break;
    case 12:
        pszMonth = "Dec";
        break;
    default:
        pszMonth = "Unk";
        break;
    }

    sprintf (pszDateTime, "%04d-%s-%02d %02d:%02d:%02d",
            iYear,
            pszMonth,
            iDay,
            iHour,
            iMin,
            iSec);
#else

    {
        struct tm tmDateTime;
        time_t tTimeNow;

        tmDateTime.tm_year = iYear - 1900;
        tmDateTime.tm_mon = iMonth - 1;
        tmDateTime.tm_mday = iDay;
        tmDateTime.tm_hour = iHour;
        tmDateTime.tm_min = iMin;
        tmDateTime.tm_sec = iSec;
        tmDateTime.tm_isdst = -1;

        tTimeNow = mktime (&tmDateTime);

        sprintf (pszDateTime, "%ld", tTimeNow);
    }

#endif //INTERFACE_CURSES

    // the following 10 fields are not checked, but skipped.
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;

    //
    // Per NPC values sections
    //

    for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
    {
        // next the global values section (first line)
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;

        sprintf (szWorkString, "##NPC-%02d", (int)(sOffset2 + 1));

        // if it isn't what we are expecting.. ignore this file.
        if (strcmp (szInputString, szWorkString) != 0)
            return 1;

        // next the global values section (size line)
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;

        // if it isn't what we are expecting.. ignore this file.
        if (strcmp (szInputString, "=9") != 0)
            return 1;

        // the following 9 fields are not checked, but skipped.
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
    }

    //
    // Command List section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##CommandList") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '=')
        return 1;

    iValue = atoi (&szInputString[1]);

    // just verify that we can load the data.
    for (iOffset = 0; iValue > iOffset; iOffset++)
    {
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 148) != 0)
            return 1;
    }

    //
    // Archive Buffer section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##ArchiveBuf") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '-')
        return 1;

    iValue = atoi (&szInputString[1]);

    // make the buffer reader jump ahead by the value we have defined.
    gstruct_FileBuffGen.ulBufferPos += (unsigned long)iValue;

    //
    // Dialog Buffer section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##DialogBuf") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '-')
        return 1;

    iValue = atoi (&szInputString[1]);

    // make the buffer reader jump ahead by the value we have defined.
    gstruct_FileBuffGen.ulBufferPos += (unsigned long)iValue;

    //
    // Trailer line
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##End##") != 0)
        return 1;

    return 0;
}


//
// function to load in a single command element.
//
int statefile_loadCommandElement ()
{
    char    szInputString[150];
    int     iOffset1;
    int     iOffset2;
    int     iSceneId;
    int     iSubSceneId;

    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 148) != 0)
        return 1;
    szInputString[148] = 0;
    szInputString[149] = 0;

    if ((szInputString[0] == '#') || (szInputString[0] == '=') || (szInputString[0] == '!'))
        return 1;

    iOffset1 = 0;

    while (1)
    {
        if (szInputString[iOffset1] == 0)
            return 1;

        if (szInputString[iOffset1] == ' ')
            break;

        iOffset1++;
    }

    szInputString[iOffset1] = 0;
    iOffset1++;

    iOffset2 = iOffset1;

    while (1)
    {
        if (szInputString[iOffset2] == 0)
            return 1;

        if (szInputString[iOffset2] == ' ')
            break;

        iOffset2++;
    }

    szInputString[iOffset2] = 0;
    iOffset2++;

    iSceneId = (int)atoi (szInputString);
    iSubSceneId = (int)atoi (&szInputString[iOffset1]);

    if (mutils_addToCommandList (&szInputString[iOffset2], iSceneId, iSubSceneId))
        return 1;

    return 0;
}


//
// Sub function to check if this line is what it should be.
//
int statefile_checkLineNonString (char *pszLine)
{
    if ((pszLine[0] == '#') || (pszLine[0] == '=') || (pszLine[0] == '!'))
        return 1;

    return 0;
}


//
// function to load in a save file to activate it for real.
//
// returns 1 if there was a problem.
// returns 0 if the save was loaded.
//
int statefile_loadSaveFile (char *pszFileName)
{
    char    szInputString[900];
    char    szWorkString[20];
    int     iOffset;
    short   sOffset2;
    int     iValue;
    int     iRet;

#ifdef INTERFACE_CURSES
    sprintf (szInputString, "Loading %s", pszFileName);

    clear ();
    attron(A_DIM);
    mvaddstr (2, 1, szInputString);
    attroff(A_DIM);
    refresh ();
#endif

    // load the entire save file into the memory buffer
    iRet = futils_loadFileIntoMemory (pszFileName, &gstruct_FileBuffGen);

    if (iRet != 0)
        return 1;

    // start with the version line..
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 898) != 0)
    {
        return 1;
    }
    szInputString[898] = 0;

#ifdef INTERFACE_CURSES
    // check to see if it starts with what we want
    if (szInputString[0] != '!')
        return 2;
    // otherwise I don't care what it says
#else
    // check to see if it starts with what we want
    if (szInputString[0] != '*')
        return 2;

    // copy aside the tracking id.
    strncpy (gszSessionTrackingId, &szInputString[1], 48);
    gszSessionTrackingId[48] = 0;
#endif //INTERFACE_CURSES

    //
    // Global values section
    //

    // next the global values section (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##BMPSGlobal") != 0)
        return 1;

    // next the global values section (size line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "=11") != 0)
        return 1;

    // next the date/time field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 20) != 0)
        return 1;
    szInputString[20] = 0;

    // Check the date/time field.

    // 00000000001111111111
    // 01234567890123456789
    // YYYY-MM-DD-hh-mm-ss

    if ((szInputString[4] != '-') || (szInputString[7] != '-') || (szInputString[10] != '-') || (szInputString[13] != '-') || (szInputString[16] != '-') || (szInputString[19] != 0))
    {
        return 1;
    }

    // we are not doing anything with the date/time other than verifying it's format.

    // the LocationId field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cLocationId = (char)atoi (szInputString);

    // the AreaId field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cAreaId = (char)atoi (szInputString);

    // the ClothesValue field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cClothesValue = (char)atoi (szInputString);

    // the DildoValue field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cDildoValue = (char)atoi (szInputString);

    // the BreastsValue field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cBreastsValue = (char)atoi (szInputString);

    // the ClitorisValue field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cClitorisValue = (char)atoi (szInputString);

    // the DayCount field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.iDayCount = (int)atoi (szInputString);

    // the TimeValue field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cTimeValue = (char)atoi (szInputString);

    // the DifficultyLevel field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cDifficultyLevel = (char)atoi (szInputString);

    // the HintCountDown field
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;
    iRet = statefile_checkLineNonString (szInputString);
    if (iRet != 0) return 1;

    gpstructPC_Global.cHintCountDown = (char)atoi (szInputString);

#ifdef INTERFACE_CURSES
    attron(A_DIM);
    mvaddstr (3, 1, "Global vars loaded");
    attroff(A_DIM);
    refresh ();
#endif

    //
    // Per NPC values sections
    //

    for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
    {
        // next the global values section (first line)
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;

        sprintf (szWorkString, "##NPC-%02d", (int)(sOffset2 + 1));

        // if it isn't what we are expecting.. ignore this file.
        if (strcmp (szInputString, szWorkString) != 0)
            return 1;

        // next the global values section (size line)
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;

        // if it isn't what we are expecting.. ignore this file.
        if (strcmp (szInputString, "=9") != 0)
            return 1;

        // the LocationId field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].cLocationId = (char)atoi (szInputString);

        // the AreaId field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].cAreaId = (char)atoi (szInputString);

        // the ActionId field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].cActionId = (char)atoi (szInputString);

        // the NameToFaceFlag field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].cNameToFaceFlag = (char)atoi (szInputString);

        // the InteractionLockFlag field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].cInteractionLockFlag = (char)atoi (szInputString);

        // the KnownValue field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].iKnownValue = (int)atoi (szInputString);

        // the TrustValue field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].iTrustValue = (int)atoi (szInputString);

        // the ObedienceValue field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].iObedienceValue = (int)atoi (szInputString);

        // the EnergyValue field
        if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
            return 1;
        szInputString[18] = 0;
        iRet = statefile_checkLineNonString (szInputString);
        if (iRet != 0) return 1;

        gpstructNPC_Base[sOffset2].iEnergyValue = (int)atoi (szInputString);
    }

#ifdef INTERFACE_CURSES
    attron(A_DIM);
    mvaddstr (4, 1, "NPC Stats Loaded");
    attroff(A_DIM);
    refresh ();
#endif

    //
    // Command List section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##CommandList") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '=')
        return 1;

    iValue = atoi (&szInputString[1]);

    // wipe the existing command list
    mutils_initAndClearCommandList ();

    // just verify that we can load the data.
    for (iOffset = 0; iValue > iOffset; iOffset++)
    {
        iRet = statefile_loadCommandElement ();
        if (iRet != 0)
            return 1;
    }

#ifdef INTERFACE_CURSES
    attron(A_DIM);
    mvaddstr (5, 1, "Command list loaded");
    attroff(A_DIM);
    refresh ();
#endif

    //
    // Archive Buffer section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##ArchiveBuf") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '-')
        return 1;

    iValue = atoi (&szInputString[1]);

#ifdef INTERFACE_CGI
    if (iValue > 16383)
        return 1;
#else
    if (iValue > 65535)
        return 1;
#endif // INTERFACE_CGI

    // copy the archive data straight over
    strncpy (gpszArchiveBuffer, &gstruct_FileBuffGen.pcData[gstruct_FileBuffGen.ulBufferPos], iValue);
    gpszArchiveBuffer[iValue] = 0;
    giArchiveBufferUsed = iValue;

    // make the buffer reader jump ahead by the value we have defined.
    gstruct_FileBuffGen.ulBufferPos += (unsigned long)iValue;

    //
    // Dialog Buffer section
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##DialogBuf") != 0)
        return 1;

    // following line count (second line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    if (szInputString[0] != '-')
        return 1;

    iValue = atoi (&szInputString[1]);

    // if the data is larger than what we have allocated for buffer.
    if (iValue > giDialogBufferSize)
    {
        // .. then it is time to increase the memory buffer allocation.
        int iNewSize = iValue + 100;
        char *pcMemData;

        // round up..
        while (iNewSize % 8192)
            iNewSize++;

        // decrement by 2 (it is added in by the realloc)..
        iNewSize -= 2;

        // now for the realloc..
        pcMemData = (char *)realloc ((VOID *)gpszDialogBuffer, (size_t)(iNewSize + 2));

        if (pcMemData == NULL)
            return 1;

        // I don't care if realloc is going to keep it all, I am about to overwrite it..

        // Now to save aside the references..
        gpszDialogBuffer = pcMemData;
        giDialogBufferSize = iNewSize;
    }

    // copy the archive data straight over
    strncpy (gpszDialogBuffer, &gstruct_FileBuffGen.pcData[gstruct_FileBuffGen.ulBufferPos], iValue);
    gpszDialogBuffer[iValue] = 0;
    giDialogBufferUsed = iValue;

    // make the buffer reader jump ahead by the value we have defined.
    gstruct_FileBuffGen.ulBufferPos += (unsigned long)iValue;

    //
    // Trailer line
    //

    // section identifier (first line)
    if (futils_readLineFromMemoryNoEndLineCombo (&gstruct_FileBuffGen, szInputString, 18) != 0)
        return 1;
    szInputString[18] = 0;

    // if it isn't what we are expecting.. ignore this file.
    if (strcmp (szInputString, "##End##") != 0)
        return 1;

#ifdef INTERFACE_CURSES
    attron(A_DIM);
    mvaddstr (6, 1, "Dialog loaded");
    attroff(A_DIM);
#endif

    return 0;
}


//
// function to write out the variables to a save file.
//
int statefile_writeSaveFile (char *pszFileName)
{
    char    szInputString[900];
    int     iOffset;
    short   sOffset2;
    int     iRet;

    // wipe the file buffer
    iRet = futils_wipeFileBuffer (&gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    //
    // Start with the global variables.
    //

    {
        struct tm *ptmDateTime;
        time_t tTimeNow;

        time (&tTimeNow);
        ptmDateTime = localtime (&tTimeNow);

        sprintf (szInputString, "##BMPSGlobal\n=11\n%04d-%02d-%02d-%02d-%02d-%02d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                (int)ptmDateTime->tm_year + 1900,
                (int)ptmDateTime->tm_mon + 1,
                (int)ptmDateTime->tm_mday,
                (int)ptmDateTime->tm_hour,
                (int)ptmDateTime->tm_min,
                (int)ptmDateTime->tm_sec,
                (int)gpstructPC_Global.cLocationId,
                (int)gpstructPC_Global.cAreaId,
                (int)gpstructPC_Global.cClothesValue,
                (int)gpstructPC_Global.cDildoValue,
                (int)gpstructPC_Global.cBreastsValue,
                (int)gpstructPC_Global.cClitorisValue,
                (int)gpstructPC_Global.iDayCount,
                (int)gpstructPC_Global.cTimeValue,
                (int)gpstructPC_Global.cDifficultyLevel,
                (int)gpstructPC_Global.cHintCountDown);
    }

    iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    //
    // Now for the NPC combinations.
    //

    for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
    {
        sprintf (szInputString, "##NPC-%02d\n=9\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                (int)(sOffset2 + 1),
                (int)gpstructNPC_Base[sOffset2].cLocationId,
                (int)gpstructNPC_Base[sOffset2].cAreaId,
                (int)gpstructNPC_Base[sOffset2].cActionId,
                (int)gpstructNPC_Base[sOffset2].cNameToFaceFlag,
                (int)gpstructNPC_Base[sOffset2].cInteractionLockFlag,
                (int)gpstructNPC_Base[sOffset2].iKnownValue,
                (int)gpstructNPC_Base[sOffset2].iTrustValue,
                (int)gpstructNPC_Base[sOffset2].iObedienceValue,
                (int)gpstructNPC_Base[sOffset2].iEnergyValue);

        iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);
        if (iRet != 0)
            return 1;
    }

    //
    // Now for the selection command data.
    //

    sprintf (szInputString, "##CommandList\n=%d\n", (int)giCommandListUsed);

    iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    for (iOffset = 0; (int)giCommandListUsed > iOffset; iOffset++)
    {
        sprintf (szInputString, "%d %d %s\n",
                (int)gstruct_CommandList[iOffset].iSceneId,
                (int)gstruct_CommandList[iOffset].iSubSceneId,
                gstruct_CommandList[iOffset].pszCommand);

        iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);

        if (iRet != 0)
            return 1;
    }

    //
    // Now for the archive data.
    //

    sprintf (szInputString, "##ArchiveBuf\n-%d\n", (int)strlen (gpszArchiveBuffer));

    iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    iRet = futils_addStringToFileBufferEnd (gpszArchiveBuffer, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    //
    // Now for the dailog data.
    //

    sprintf (szInputString, "##DialogBuf\n-%d\n", (int)strlen (gpszDialogBuffer));

    iRet = futils_addStringToFileBufferEnd (szInputString, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    iRet = futils_addStringToFileBufferEnd (gpszDialogBuffer, &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    //
    // trailer line.
    //

    iRet = futils_addStringToFileBufferEnd ("##End##\n\n", &gstruct_FileBuffGen);
    if (iRet != 0)
        return 1;

    //
    // Write the file.
    //

    unlink (pszFileName);

#ifdef INTERFACE_CURSES
    futils_writeFileHeaderAndData (pszFileName, "!Version 0.01\n", gstruct_FileBuffGen.pcData);
#else
    sprintf (szInputString, "*%s\n", gszSessionTrackingId);

    futils_writeFileHeaderAndData (pszFileName, szInputString, gstruct_FileBuffGen.pcData);
#endif //INTERFACE_CURSES

    return 0;
}


