//
// mdialog.c
//
// some dialog utilities for the program.
//

#include "common.h"

//
// I put this listing aside from mutils.c, so that I am not altering mutils.
//
// A feature that I am adding into BMPS, is search/replace operations within the dialog.
// I did create a mutils.c function to support this (mutils_addToDialogBufferLenSpec).
//
// This ENTIRE listing is about managing search/replace actions.
//

//
// This is the static search/replace table.
//
// Offset 0 is the PC name
// Offsets 1-64 are the NPC names
// Offset 65 is the Village name
// Offset 66 is a default value (for the dynamic table)
//
struct  mdialog_searchreplacelist gstructSrchRepList[] =
{
    { "00", "Bunny" },
    { "01", "Zeke" },
    { "02", "Otto" },
    { "03", "Lars" },
    { "04", "Nasir" },
    { "05", "Gino" },
    { "06", "Terell" },
    { "07", "Cortez" },
    { "08", "Redinald" },
    { "09", "Sigga" },
    { "10", "Massimo" },
    { "11", "Salvator" },
    { "12", "Kohl" },
    { "13", "Hung" },
    { "14", "Philippe" },
    { "15", "Quon" },
    { "16", "Norris" },
    { "17", "Jamar" },
    { "18", "Tuan" },
    { "19", "Kadeem" },
    { "20", "Erick" },
    { "21", "Izaiah" },
    { "22", "Mack" },
    { "23", "Rishi" },
    { "24", "Jered" },
    { "25", "Bryan" },
    { "26", "Harvir" },
    { "27", "Viktor" },
    { "28", "Cecil" },
    { "29", "Anders" },
    { "30", "Franco" },
    { "31", "Haydn" },
    { "32", "Tarik" },
    { "33", "Arjan" },
    { "34", "Kang" },
    { "35", "Edwin" },
    { "36", "Nate" },
    { "37", "Dalton" },
    { "38", "Rylan" },
    { "39", "Joban" },
    { "40", "Dryden" },
    { "41", "Keyon" },
    { "42", "Lester" },
    { "43", "Yousef" },
    { "44", "Braden" },
    { "45", "Deion" },
    { "46", "Omari" },
    { "47", "Melvin" },
    { "48", "Gary" },
    { "49", "Jerry" },
    { "50", "Frank" },
    { "51", "Pete" },
    { "52", "Lloyd" },
    { "53", "Bob" },
    { "54", "Jake" },
    { "55", "Olson" },
    { "56", "Perry" },
    { "57", "Marcel" },
    { "58", "Rafael" },
    { "59", "Judd" },
    { "60", "Fabian" },
    { "61", "Aho" },
    { "62", "Benson" },
    { "63", "Shaw" },
    { "64", "Javier" },
    { "65", "Belchwood" },
    { "66", "<none>" },
    { NULL, NULL }
};

struct  mdialog_dynamicreplacelist gpstructDynamicReplaceList[MDIALOG_DYNAMIC_MAX + 1];
short   gsSrchRepListMax = 0;

//
// Small function to init the dynamic list.
//
void mdialog_initDynamicList ()
{
    short sOffset1;

    sOffset1 = 0;

    // find the end of the static list

    while (1)
    {
        if (gstructSrchRepList[sOffset1].pszReplace == NULL)
            break;

        sOffset1++;
    }

    gsSrchRepListMax = sOffset1;

    // reset the entire dynamic list
    for (sOffset1 = 0; sOffset1 < MDIALOG_DYNAMIC_MAX; sOffset1++)
    {
        gpstructDynamicReplaceList[sOffset1].sLink = (short)(gsSrchRepListMax - 1);
        sprintf (gpstructDynamicReplaceList[sOffset1].szSearch, "%02d", sOffset1);
    }
}

//
// Small function to setup the dynamic list entry.
//
void mdialog_setDynamicEntry (short sOffset, short sEntry)
{
    if (sOffset >= MDIALOG_DYNAMIC_MAX)
        return;

    if (sEntry >= gsSrchRepListMax)
        return;

    gpstructDynamicReplaceList[sOffset].sLink = sEntry;
}

//
// This is a front end to mutils_addToDialogBuffer & mutils_addToDialogBufferLenSpec,
// which takes care of looking for Search tags and inputting replacements.
//
// One of the grand assumptions is that the input string is null terminated.
//
// 0 if ok
// 1 if there was a memory allocation error
//
int mdialog_addToDialogWithSrchRep (char *pszString)
{
    int iRet;
    int iStart = 0;
    int iPos = 0;
    int iLen = (int)strlen (pszString);

    while (1)
    {
        if (iPos >= iLen)
            break;

        if (pszString[iPos] == '#')
        {
            int iCalc = iLen - iPos;

            // check that we have enough bytes to lock onto (so we are not potentially searching off the end of the string somewhere).
            if (iCalc > 4)
            {
                if (pszString[iPos + 4] == '#')
                {
                    short sOffset1;
                    char cLock = 0;

                    iCalc = iPos - iStart;

                    //
                    // This is the static search/replace trigger.
                    //
                    if (pszString[iPos + 1] == '!')
                    {
                        for (sOffset1 = 0; sOffset1 < gsSrchRepListMax; sOffset1++)
                        {
                            if (gstructSrchRepList[sOffset1].pszReplace == NULL)
                                break;

                            if (strncmp (gstructSrchRepList[sOffset1].pszSearch, &pszString[iPos + 2], 2) == 0)
                            {
                                cLock = 1;
                                break;
                            }
                        }

                        if (cLock != 0)
                        {
                            // first dump out the string that we have so far
                            iRet = mutils_addToDialogBufferLenSpec (&pszString[iStart], iCalc);
                            if (iRet != 0) return iRet;

                            // now set our position past the search/replace key.
                            iPos += 5;
                            iStart = iPos;

                            // now put in the search/replace value
                            iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset1].pszReplace);
                            if (iRet != 0) return iRet;

                            continue;
                        }
                    }

                    //
                    // This is the dynamic search/replace trigger (using what mdialog_setDynamicEntry maintains).
                    //
                    if (pszString[iPos + 1] == '^')
                    {
                        for (sOffset1 = 0; sOffset1 < MDIALOG_DYNAMIC_MAX; sOffset1++)
                        {
                            if (strncmp (gpstructDynamicReplaceList[sOffset1].szSearch, &pszString[iPos + 2], 2) == 0)
                            {
                                cLock = 1;
                                break;
                            }
                        }

                        if (cLock != 0)
                        {
                            // first dump out the string that we have so far
                            iRet = mutils_addToDialogBufferLenSpec (&pszString[iStart], iCalc);
                            if (iRet != 0) return iRet;

                            // now set our position past the search/replace key.
                            iPos += 5;
                            iStart = iPos;

                            // now put in the search/replace value
                            iRet = mutils_addToDialogBuffer (gstructSrchRepList[gpstructDynamicReplaceList[sOffset1].sLink].pszReplace);
                            if (iRet != 0) return iRet;

                            continue;
                        }
                    }
                }
            }
        }


        iPos++;
    }

    // finish off the string
    return (mutils_addToDialogBuffer (&pszString[iStart]));
}
//
// Why the logic complexity around search/replace?
//
// The "not much of an issue" that I wanted to avoid was allocating more memory. This is the primary
// reason for the added complexity.
//
// So the idea is to look for the start of the search combinations #! and #^
//
// #! prefixes static S/R tags (#!00#, etc).
// #^ prefixes the dynamic S/R tags (#^00#, etc).
//
// For example:
// 00000000001111111111222222222233333333334
// 01234567890123456789012345678901234567890
// This is a #!00# test of a string.
//
// When I identify that I have a valid S/R combo (complete with a match).
// Let's say for the sake of the demonstration (with the above example), that the code identifies
// this when it reaches offset 10. It checks to see if the remaining string is long enough (iCalc
// check) to be a S/R tag. It then verifies that the last character of the combo is there (trailing
// #, offset 14), then goes looking for if it is a static or dynamic type (because that changes the
// memory table we are looking in).
//
// Then I look in the memory tables by the 2 character string combinations (being the 2 numbers).
// Once a lock has been successfully made:
//  Dump out what was before the SR tag (mutils_addToDialogBufferLenSpec call).
//  Set the current and start positions past the end of the SR tag (which will become offset 15).
//  Dump out the referenced entry in the table lookup (mutils_addToDialogBuffer call).
//  Then resume checking.
//
// At the end of the function is a mutils_addToDialogBuffer call to dump out what is left from the
// updated start position.
//
// The above example is written out as (between the [] brackets).
// [This is a ] mutils_addToDialogBufferLenSpec call
// [Bunny] mutils_addToDialogBuffer call
// [ test of a string.] mutils_addToDialogBuffer call
//
// Any memory allocation is left to the lower level mutils_addToDialogBufferLenSpec and
// mutils_addToDialogBuffer function calls.
//
// It might seem a pain that only character names, and the town name are in the S/R tag combinations.
// However, in this case, the SR values are all defined here and don't change. As a result, if there
// is a need to include the PC, NPC or Town name anywhere, everything can be run through here.
//
// Meaning, if you don't like the names that I came up with for the PC, 64 NPCs or the town, just
// change them here, and the code will use those... as long as I stick to using the S/R tags in the
// first place.
//


