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
// 4 = spoiler menu config.
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

    // BMPS spoiler, menu.

    if (iRestrict != 4)
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"BMPSv", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

        if ((iRet == 0) && (gcDebugFlag != 0))
            iRet = futils_addStringToFileBufferEnd (".cheat", &gstruct_FileBuffOut);

        if (iRet == 0)
            iRet = futils_addStringToFileBufferEnd (".cgi#current\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"BMPS spoilers\" /> Hints, tips, spoilers and cheats.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the spoiler menu link", 806);
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
            httpcgi_errorOutput ("Could not buffer the main menu link", 807);
        }
    }
    else // Back to the list of games, menu.
    {
        iRet = futils_addStringToFileBufferEnd ("<hr/>\n<form action=\"main.cgi\" method=\"POST\">\n<input type=\"submit\" name=\"menu\" value=\"Back to the list of games\" /> to back to the main list.<br/>\n</form>\n", &gstruct_FileBuffOut);

        if (iRet != 0)
        {
            httpcgi_errorOutput ("Could not buffer the game menu link", 808);
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

    iRet = futils_addStringToFileBufferEnd ("<br/>Bunny, Mayoress, Prostitute &amp; Succubus (BMPS). Version ", &gstruct_FileBuffOut);

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

    iRet = futils_addStringToFileBufferEnd ("<br/>BMPS is a very simple &apos;interactive-fiction-like&apos; text novel game. This is also a piece of adult fiction, and has some heavy sexual references.<br/><br/><br/>\n<b>Storyline subjects/themes:</b><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Tags, according to <a href=\"http://pastebin.com/Su7gb2iq\">http://pastebin.com/Su7gb2iq</a><br/>\n[Brg]= Breast growth/shrink (multi-event)<br/>\n[Drg]= Drugs (multi-event)<br/>\n[Fdo]= Femdom (recurring)<br/>\n[Lct]= Lactation (single event)<br/>\n[Mtc]= Mental change (recurring)<br/>\n[Mdc]= Mind Control/Hypnosis (recurring)<br/>\n[Msr]= Monsters (PC)<br/>\n[Rpe]= Rape (recurring)<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("There is also Masturbation (recurring), Leather clothing (single event), Sex toys (dildos and vibrators, separate single events), Piss Drinking (single event), and Foul Language (recurring).<br/><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<b>Game play notes:</b><br/><br/>\nYou guide the PC (Bunny) around the various places/locations in the village (Belchwood). At each location there may be a number of NPCs (villagers) that Bunny interacts with.<br/><br/>\nThe PC is a succubus, who is slowly entrancing the other villagers, as she has sex with them. The other villages are all men. There are 64 NPCs (including the mayor). The difference between a good end and a bad end is the number of villagers who trust the PC, before the second villager becomes openly obedient. The number is determined by the difficulty level that you select when you start the game.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Also, as the PC comes to know the NPCs, she will know where they are in the village (the &apos;give me a hint&apos; menu selection shows this).<br/><br/>\nThe aim is, to get to know as many NPCs as possible, earn their trust, before breaking anyone other than the mayor completely. The story starts with the mayor fully obedient/broken.<br/><br/>\nSome of the NPCs are locked. They will abstain from having sex with the PC until there is a specific event condition satisfied. It is not possible to complete the game with the difficulty set to hard, unless you unlock all of the locked NPCs.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("The NPCs (being human men) are only good for an encounter with the PC, then need time to rest. Their &apos;energy&apos; is a contributing factor if they will have sex with the PC during the next encounter.<br/><br/>\nYou (the player) chose where the PC is to go, and she has sex with 1-5 of the most energetic ones at that location.<br/><br/>\nThe NPCs follow a schedule, as to where they are going to be, and what they are going to be doing, at specific times of the day. For some NPCs, the schedule is going to be boring. However, other NPCs have a set of random locations where they can be.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("If a NPC is fast asleep, they will not consciously have sex with the PC (but that does not stop the PC from sucking them dry while they are unconscious).<br/><br/>\nSome NPCs can disappear into the forest, not be found by the PC, at specific times.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<br/><b>ChangeLog:</b><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<b># Version 0.80 - Friday 2nd December 2016</b><br/>First standalone web server version, replacing the standalone CURSES version.<br/>Included the first batch of images from Inkeranon (the primary reason that the standalone web server version was created).<br/>Included a spoilers menu page.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<b># Version 0.70 - Friday 11th November 2016</b><br/>First web server version, which included some of dialog fixes.<br/><br/>\n", &gstruct_FileBuffOut);

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

    iRet = futils_addStringToFileBufferEnd ("<br/>Bunny, Mayoress, Prostitute &amp; Succubus (BMPS), the story and code, is licensed under the Creative Commons Attribution 4.0 International license (CC BY 4.0).<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<a href=\"http://creativecommons.org/licenses/by/4.0/\">http://creativecommons.org/licenses/by/4.0/</a><br/>..and..<br/><a href=\"http://creativecommons.org/licenses/by/4.0/legalcode\">http://creativecommons.org/licenses/by/4.0/legalcode</a><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("As a project, development commenced on Saturday 24th September 2016.<br/>First release (CURSES version) was on Wednesday 19th October 2016.<br/><br/>\nIf you take this game and/or story, modify it (or translate it into another language), you need to leave everything on this credit page alone and add your own details to it (of course).<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("Concept, dialog and code was originally by M100.<br/><br/>The artwork was commissioned from <a href=\"http://notreallybuttpants.tumblr.com/\">Notreallybuttpants/Inkeranon</a>. <I>The artwork belongs to </I><a href=\"http://notreallybuttpants.tumblr.com/\"><I>Inkeranon</I></a>.<br/><br/>\n<center>My only specifications to <a href=\"http://notreallybuttpants.tumblr.com/\">Inkeranon</a> was; Bunny is a succubus, about 25 years old, wearing a bunny-corset-suit, short brown hair, and short bunny ears on the top of her head.<br/><I>This</I> was the resultant concept art that he drew from that short overview.<br/><img src=\"images/BMPS-Concept1-by-Inkeranon.jpg\" /></center><br/><br/>\nThanks to the participants on the #/d/evs rizon.net IRC channel for guidance, as well as putting up with occasional ranting while making this.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game credits text", 814);
    }

    menucgi_outputFullMenu (3);
}


//
// Function to output the spoilers menu.
//

void menucgi_outputSpoilersMenu ()
{
    int iRet;

    iRet = futils_addStringToFileBufferEnd ("<br/><B>Spoiler alert... Spoiler alert...</B><br/><br/>\nThe purpose of this page is to provide some details about some of the hidden aspects of Bunny, Mayoress, Prostitute &amp; Succubus (BMPS). I once dumped some information into a 4chan/d /dgg/ thread about how to play the game, and this is an extension of that.<br/><br/>\nIf you don&apos;t want to ruin the experience for yourself, then exit from this page.<br/><br/>\nWhile there is a fair amount of information contained in the &quot;about page&quot;, such as; how to play the game and the overall strategy, the &quot;about page&quot; does not reveal is where all of the hidden events are. This page is necessary only because my games aren&apos;t popular enough for some anon to go through the effort of creating a wiki that has a walk-through or two.<br/><br/>\n<I>With Hedonism Quest, Wilda’s Ascension (HQWA), I was able to point out the source code data that contains the information about the trigger elements on the maps. BMPS is a completely different game underneath the hood, so I have to do this another way.</I><br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<br/><B>Cheat/Debug:</B><br/><br/>\nThe &quot;standalone local web server&quot; version of the program have the -D command line switch.<br/><br/>\nThe web server (this) version does the same thing by altering the URL.<br/><br/>In the address bar of the web browser is a path to the program. When not in &quot;cheat&quot; mode it will be &quot;BMPSv", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd (gszVersionStamp, &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd (".cgi&quot;. To activate the &quot;cheat&quot; mode, change the &quot;.cgi&quot; part of the address to &quot;.cheat.cgi&quot;. Doing so will take you back to the main menu, but you will see a notice at the end of the version number at the top of the main menu it will say &quot;#CHEAT-MODE-ON&quot;. The program will maintain the path to the &quot;.cheat.cgi&quot; until you exit &apos;back to the list of games&apos; menu, or you alter the address again.<br/><br/>\nCheat/Debug mode does only one thing for BMPS, it alters the &quot;Give me a hint&quot; menu item so that it is  always available... AND, it alters the &quot;Give me a hint&quot; menu so that it shows where all of the NPCs are (not just the ones that the PC knows), and it shows their progression values. It changes nothing else, but being able to see the progression of all of the NPCs turns out to be a useful thing (without it, you cannot make an assessment if a NPC is becoming too obedient).<br/><br/>\nThe known value fills up when it reaches 30. The trust value fills up when it reaches 100. The obedience value fills up when it reaches 200.<br/><br/>\nOf course, when the obedience value reaches 200 on any NPC other than the (former-)Mayor, the game ends, and the evaluation between a good and a bad ending happens.<br/><br/>\nRemember:<br/>\nEasy difficulty level, get 33 of 64 villagers to fully trust you.<br/>\nMedium difficulty level, get 54 of 64 villagers to fully trust you.<br/>\nHard difficulty level, get all of the 64 villagers to fully trust you.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<br/><B>Strategy:</B><br/><br/>\nAs already specified, the overall strategy is to get the NPCs to trust you (by having sex with them), then avoid them as much as possible when they trust you. The only exception is the (former-)Mayor, Zeke, who is already fully obedient, and therefore the one person that Bunny can have sex with at anytime, without bringing the game to a conclusion soooner. This is harder than it sounds considering that you might want to build up the trust of a NPC who is in a location of NPCs who already trust the PC. It is better to alternate between places like the tavern and the kitchen on the first couple of days, but after the PC knows everyone, you need to start intercepting the NPCs who don&apos;t trust her yet when they are away from the heavily populated locations.<br/><br/>\nOne useful thing to note is that the progression of the NPCs is faster when you have sex with less of them. Sexual encounters can be between 1 to 5 NPCs. If there are 6 NPCs available in a location, the game will prioritize order the NPCs (with a little bit of randomness thrown in), and those that &quot;don&apos;t make the cut&quot; are pure observers.<br/><br/>\nA NPC&apos;s willingness to have sex is dependant upon a number of factors, including what they are doing. If they are sound-asleep, then the PC cannot have sex with them.<br/><br/>\nOne important thing, the NPCs won&apos;t have sex with Bunny if she has worn them down first. Usually, whenever Bunny has sex with someone, their parameters shift. Except, when the NPC is asleep, and there is no-one else awake, then Bunny will suck them off, wearing them down, but not altering any of their other status (such as trust and obedience).<br/><br/>\nHowever, there are some NPCs who the PC has to have one-on-one sex with, to unlock them.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<br/><B>Locked NPCs and Events:</B><br/>(these are the spoilers)<br/><br/>\nThere are a collection of events built into the game, and a handful of NPCs who are going to remain locked until those events are triggered. If you are playing the game in hard mode, then it will be impossible to win without unlocking ALL of these NPCs (because the success criteria for hard mode is 100% of the village trusts you before you make your second NPC obedient).<br/><br/>\n<B>Redinald</B>. He is the Moneylender, and a influential person in the village. He also has a fetish for drinking urine out of a glass, which is a polar opposite of the fact that he is also a clean freak and has a has a fear of germs. Redinald is going to remain locked till Bunny meets him in alone in his room. The difficulty factor is if anyone else in at his house wants to fuck Bunny, Redinald will stand back and watch. In order to get  Redinald alone first, Bunny has to tire out anyone else who might also be in the house beforehand. Thankfully, I did not link Redinald&apos;s event to anyone else. The additional difficulty is elevating Redinald&apos;s trust afterwards, without also elevating the trust and obedience of the NPCs around him (and he ALWAYS has a bodyguard nearby).<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<B>Izaiah</B>. He is the Tavern-keeper, and he isn&apos;t locked. However, there is a key event involving Izaiah, that enables events involving Marcel, Fabian, Philippe, Viktor, Melvin &amp; Gary. Considering that this is necessary to unlock all but Philippe, it is a key event to trigger. Because Bunny wants to stop and fuck new cocks, whenever she encounters them, it is necessary to get to know as many NPCs as possible with repeated visits to the Tavern. Once Bunny is inside the Tavern hall, and not screwing anyone that she meets for the first time, she has the option of going behind the bar of the tavern. Izaiah has priority when she is in &quot;his-space&quot; (assuming she hasn&apos;t worn him down earlier), and just being behind the bar is what triggers the event. Izaiah tears off Bunny&apos;s bunny-suit, which is the direct unlock trigger for events involving Marcel &amp; Fabian, as well as a contributing event to starting a series of events with Philippe. However, it is a one-on-one event with Izaiah, and to get that far inside the tavern, Bunny would have had sex with him a number of times already.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<B>Marcel</B>. He is the Procurer of the village. If you need to get it, he knows how to find it. The village thugs hang out with Marcel. He also has a thing for leather. To unlock (and get to know) Marcel, Bunny needs to be naked (see Izaiah) and inside his shack, with him alone (if he has a visitor, the visitors fuck Bunny, he just watches and the event does not trigger). His &quot;guys&quot; will hang back, so Bunny does not need to worry about wearing them down first.<br/><br/>\n<B>Fabian</B>. He is the Smuggler of the village. The local bandits hang out with Fabian, and are kept around for the &quot;grand scheme of things&quot;. Similar to Marcel, Bunny just needs to meet Fabian (alone) in his shack, while either naked or wearing Marcel&apos;s leather outfit, while Fabian is alone. Fabian&apos;s fetishes involve stuffing dildos inside women, then ordering them around. The dildos are an important trigger to unlock Viktor.<br/><br/>\n<B>Viktor</B>. He is the Tinker of the village. Most of his time he stays in the workshop. Viktor has a few screws loose. He stays away from Bunny, until she gets his attention with Fabian&apos;s dildos. The thing is that Viktor only goes off the handle if Bunny can intercept him, while he is alone, inside the apartment above the workshop. Which happens to be only at one specific time of the day, 14:15. Bunny does not need to worry about the other NPCs if they are around the workshop, as they will stay away when Viktor starts yelling.<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet == 0)
        iRet = futils_addStringToFileBufferEnd ("<B>Philippe</B>. He is the Physician of the village. There is a series of 5 linked events with Philippe, that can only be triggered if Bunny and Philippe are alone, that Bunny&apos;s bunny-suit is gone (see Izaiah), and that Bunny knows Philippe. However, Philippe is not locked. If there is an NPC outside of Phillippe&apos;s house (or inside), then the event will not happen, but Phillipe is likely to have sex with Bunny anyway. The important thing about the events is that at some point of time Bunny is going to be lactating. Once Bunny starts lactating, she can unlock Melvin and Gary. The difficulty with  Phillippe, is that it is highly likely that he will fully trust Bunny before the conditions are met to unlock  Melvin and Gary.<br/><br/>\n<B>Melvin</B> and <B>Gary</B>. These two farmers reside in the northern farm of the village. They will not do anything with Bunny, until she visits them with enlarged and lactating breasts. This unlock is only triggered when they are inside their shack and awake, and there are a number of opportunities in the evening and morning where that is possible.<br/><br/>\nM100<br/><br/>\n", &gstruct_FileBuffOut);

    if (iRet != 0)
    {
        httpcgi_errorOutput ("Could not buffer the game spoiler text", 815);
    }

    menucgi_outputFullMenu (4);
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


