//
// menucgi.c
//
// menus for the CGI-BIN version..
//

#include "common.h"
#include "statedata.h"

//
// In the CURSES version, the main menus are in gamelogic00.c.
//
// In the CGI-BIN version, because I am not using the main game
// interface functions for the main menus, I do them differently,
// so these are away from the gamelogic listings.
//
// gamelogic00.c is removed in the CGI-BIN version of the program.
//

// storage of the file load structure..
extern  struct	futils_filebuff         gstruct_FileBuffOut;

// this is the debug output flag
extern  char    gszVersionStamp[20];

// this is the debug output flag
extern  char    gcDebugFlag;


//
// Function to output the full selection menu.
//
// Assumes that the gstruct_FileBuffOut is setup and partially loaded with HTTP and HTML header information.
// Also assumes that the CWD has been set to where the user data files are.
//
// 0 = main menu config.
// 1 = about menu config.
// 2 = load menu config.
// 3 = credits menu config.
// 10 = end game menu config.
//
void menucgi_outputFullMenu (int iRestrict)
{
    int iRet;
    struct stat statFile;

    // About BMPS, menu.

    if (iRestrict != 1)
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

        if ((iRet == 0) && (gcDebugFlag != 0))
            iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"About BMPS\" /> for information about this game, such as what it is about.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the About menu link", 801);
        }
    }

    if (iRestrict != 10)
    {
        // Start a new BMPS game, menu.

        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

        if ((iRet == 0) && (gcDebugFlag != 0))
            iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Start a new BMPS game\" /> to start a new game.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the start menu link", 802);
        }

        // Resume last BMPS autosave, menu.

        // this entry is always there..

        iRet = stat ("BMPS.autosave.txt", &statFile);

        if (iRet == 0)
        {
            iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

            if (iRet == 0)
                iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

            if ((iRet == 0) && (gcDebugFlag != 0))
                iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

            if (iRet == 0)
                iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Resume last BMPS autosave\" /> to pickup where you last left off.<br/>\n</form>\n", &gstruct_FileBuffOut);

            if (iRet != 0)
            {
                httpcgi_errorOutput ("Could not buffer the autosave load menu link", 803);
            }
        }

        // Load a previously saved BMPS game, menu.

        if (iRestrict != 2)
        {

            // Ok, rather simple, stat every single file name combo..

            iRet = stat ("BMPS.save1.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save2.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save3.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save4.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save5.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save6.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save7.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save8.txt", &statFile);

            if (iRet != 0)
                iRet = stat ("BMPS.save9.txt", &statFile);

            // if none of the save files exist, then don't render the menu entry.

            if (iRet == 0)
            {
                iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

                if ((iRet == 0) && (gcDebugFlag != 0))
                    iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

                if (iRet == 0)
                    iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Load a previously saved BMPS game\" /> to load a game save you put aside.<br/>\n</form>\n", &gstruct_FileBuffOut);

                if (iRet != 0)
                {
                    httpcgi_errorOutput ("Could not buffer the save load menu link", 804);
                }
            }
        }
    }

    // BMPS credits, menu.

    if (iRestrict != 3)
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

        if ((iRet == 0) && (gcDebugFlag != 0))
            iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"BMPS credits\" /> for people involved.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the credits menu link", 805);
        }
    }

    // BMPS main menu, menu.

    if (iRestrict != 0)
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

        if ((iRet == 0) && (gcDebugFlag != 0))
            iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"BMPS main menu\" /> to go back to the main menu.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the main menu link", 806);
        }
    }
    else // Back to the list of games, menu.
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"main.cgi\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Back to the list of games\" /> to back to the main list.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the game menu link", 807);
        }
    }
}


//
// Function to output the main menu.
//
// Assumes that the gstruct_FileBuffOut is setup and partially loaded with HTTP and HTML header information.
// Also assumes that the CWD has been set to where the user data files are.
//
void menucgi_outputMainMenu ()
{
    int iRet;

    iRet = futils_addStringToFileBufferEnd ("Bunny, Mayoress, Prostitute &amp; Succubus (BMPS). Version ", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

    if ((iRet == 0) && (gcDebugFlag != 0))
        iRet = futils_addStringToFileBufferEnd (" #CHEAT-MODE-ON", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<br/><br/>\nLicense: <a href=\"http://creativecommons.org/licenses/by/4.0/legalcode\">CC BY 4.0</a><br/><br/>\nThis text game has heavy adult and sexual content and is not meant for minors. At bare minimum, you should be above the &quot;age of consent&quot; to play this game. If you don&apos;t know what &quot;age of consent&quot; is, then close the web browser now.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game main text", 810);
    }

    menucgi_outputFullMenu (0);
}


//
// Function to output the about menu.
//

void menucgi_outputAboutMenu ()
{
    int iRet;

    iRet = futils_addStringToFileBufferEnd ("BMPS is a very simple &apos;interactive-fiction-like&apos; text novel game. This is also a piece of adult fiction, and has some heavy sexual references.<br/><br/>\nStoryline subjects/themes:<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Tags, according to <a href=\"http://pastebin.com/Su7gb2iq\">http://pastebin.com/Su7gb2iq</a><br/>\n[Brg]= Breast growth/shrink (multi-event)<br/>\n[Drg]= Drugs (multi-event)<br/>\n[Fdo]= Femdom (recurring)<br/>\n[Lct]= Lactation (single event)<br/>\n[Mtc]= Mental change (recurring)<br/>\n[Mdc]= Mind Control/Hypnosis (recurring)<br/>\n[Msr]= Monsters (PC)<br/>\n[Rpe]= Rape (recurring)<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("There is also Masturbation (recurring), Leather clothing (single event), Sex toys (dildos and vibrators, separate single events), Piss Drinking (single event), and Foul Language (recurring).<br/><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Game play notes:<br/><br/>\nYou guide the PC (Bunny) around the various places/locations in the village (Belchwood). At each location there may be a number of NPCs (villagers) that Bunny interacts with.<br/><br/>\nThe PC is a succubus, who is slowly entrancing the other villagers, as she has sex with them. The other villages are all men. There are 64 NPCs (including the mayor). The difference between a good end and a bad end is the number of villagers who trust the PC, before the second villager becomes openly obedient. The number is determined by the difficulty level that you select when you start the game.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Also, as the PC comes to know the NPCs, she will know where they are in the village (the &apos;give me a hint&apos; menu selection shows this).<br/><br/>\nThe aim is, to get to know as many NPCs as possible, earn their trust, before breaking anyone other than the mayor completely. The story starts with the mayor fully obedient/broken.<br/><br/>\nSome of the NPCs are locked. They will abstain from having sex with the PC until there is a specific event condition satisfied. It is not possible to complete the game with the difficulty set to hard, unless you unlock all of the locked NPCs.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("The NPCs (being human men) are only good for an encounter with the PC, then need time to rest. Their &apos;energy&apos; is a contributing factor if they will have sex with the PC during the next encounter.<br/><br/>\nYou (the player) chose where the PC is to go, and she has sex with 1-5 of the most energetic ones at that location.<br/><br/>\nThe NPCs follow a schedule, as to where they are going to be, and what they are going to be doing, at specific times of the day. For some NPCs, the schedule is going to be boring. However, other NPCs have a set of random locations where they can be.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("If a NPC is fast asleep, they will not consciously have sex with the PC (but that does not stop the PC from sucking them dry while they are unconscious).<br/><br/>\nSome NPCs can disappear into the forest, not be found by the PC, at specific times.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game about text", 812);
    }

    menucgi_outputFullMenu (1);
}


//
// Function to output the credits menu.
//

void menucgi_outputCreditsMenu ()
{
    int iRet;

    iRet = futils_addStringToFileBufferEnd ("Bunny, Mayoress, Prostitute &amp; Succubus (BMPS) is licensed under the Creative Commons Attribution 4.0 International license (CC BY 4.0).<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<a href=\"http://creativecommons.org/licenses/by/4.0/\">http://creativecommons.org/licenses/by/4.0/</a><br/>..and..<br/><a href=\"http://creativecommons.org/licenses/by/4.0/legalcode\">http://creativecommons.org/licenses/by/4.0/legalcode</a><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("As a project, development commenced on Saturday 24th September 2016.<br/>First release (CURSES version) was on Wednesday 19th October 2016.<br/><br/>\nIf you take this game and/or story, modify it (or translate it into another language), you need to leave everything on this credit page alone and add your own details to it (of course).<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Concept, dialog and code was originally by M100.<br/><br/>\nThanks to the participants on the #/d/evs rizon.net IRC channel for guidance, as well as putting up with occasional ranting while making this.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game credits text", 814);
    }

    menucgi_outputFullMenu (3);
}


//
// Function to output the save slot menu.
//

void menucgi_outputSaveMenu ()
{
    int iRet;
    int iSaveRet;
    int iCount;
    char szDateCounter[30];
    char szSavePath[30];

    iRet = futils_addStringToFileBufferEnd ("<script language=\"javascript\">\nfunction convdt(dt) {\nvar cnvDate = new Date(0);\ncnvDate.setUTCSeconds(dt);\ndocument.write(cnvDate.toLocaleString());\n}\n</script>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Pick a slot to save your game in:<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
    {
        for (iCount = 0; iCount < 9; iCount++)
        {
            iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);
            if (iRet != 0) break;

            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);
            if (iRet != 0) break;

            if (gcDebugFlag != 0)
            {
                iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }

            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Save to slot ", &gstruct_FileBuffOut);
            if (iRet != 0) break;

            sprintf (szSavePath, "%d", iCount + 1);

            iRet = futils_addStringToFileBufferEnd (szSavePath, &gstruct_FileBuffOut);
            if (iRet != 0) break;

            iRet = futils_addStringToFileBufferEnd ("\" />", &gstruct_FileBuffOut);
            if (iRet != 0) break;

            sprintf (szSavePath, "BMPS.save%d.txt", iCount + 1);

            iSaveRet = statefile_parseSaveFile (szSavePath, szDateCounter);

            if (iSaveRet == 2)
            {
                iRet = futils_addStringToFileBufferEnd (" is currently empty.<br/>\n</form>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
            else if (iSaveRet == 1)
            {
                iRet = futils_addStringToFileBufferEnd (" is invalid (\n<script language=\"javascript\">\nconvdt(", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (szDateCounter, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (");\n</script>\n).<br/>\n</form>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
            else // iSaveRet == 0
            {
                iRet = futils_addStringToFileBufferEnd (" was saved \n<script language=\"javascript\">\nconvdt(", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (szDateCounter, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (");\n</script>\n.<br/>\n</form>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
        }
    }

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game save text", 816);
    }

    menucgi_outputFullMenu (2);
}


//
// Function to output the load slot menu.
//

void menucgi_outputLoadMenu ()
{
    int iRet;
    int iSaveRet;
    int iCount;
    char szDateCounter[30];
    char szSavePath[30];

    iRet = futils_addStringToFileBufferEnd ("<script language=\"javascript\">\nfunction convdt(dt) {\nvar cnvDate = new Date(0);\ncnvDate.setUTCSeconds(dt);\ndocument.write(cnvDate.toLocaleString());\n}\n</script>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Pick a slot to load from:<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
    {
        for (iCount = 0; iCount < 9; iCount++)
        {
            sprintf (szSavePath, "BMPS.save%d.txt", iCount + 1);

            iSaveRet = statefile_parseSaveFile (szSavePath, szDateCounter);

            sprintf (szSavePath, "%d", iCount + 1);

            if (iSaveRet == 2)
            {
                iRet = futils_addStringToFileBufferEnd ("<hr/>\nSlot ", &gstruct_FileBuffOut);

                iRet = futils_addStringToFileBufferEnd (szSavePath, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (" is currently empty.<br/>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
            else if (iSaveRet == 1)
            {
                iRet = futils_addStringToFileBufferEnd ("<hr/>\nSlot ", &gstruct_FileBuffOut);

                iRet = futils_addStringToFileBufferEnd (szSavePath, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (" is invalid (\n<script language=\"javascript\">\nconvdt(", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (szDateCounter, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (");\n</script>\n).<br/>\n</form>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
            else // iSaveRet == 0
            {
                iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                if (gcDebugFlag != 0)
                {
                    iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);
                    if (iRet != 0) break;
                }

                iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Slot ", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                sprintf (szSavePath, "%d", iCount + 1);

                iRet = futils_addStringToFileBufferEnd (szSavePath, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd ("\" /> was saved \n<script language=\"javascript\">\nconvdt(", &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (szDateCounter, &gstruct_FileBuffOut);
                if (iRet != 0) break;

                iRet = futils_addStringToFileBufferEnd (");\n</script>\n.<br/>\n</form>\n", &gstruct_FileBuffOut);
                if (iRet != 0) break;
            }
        }
    }

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game load text", 818);
    }

    menucgi_outputFullMenu (2);
}


