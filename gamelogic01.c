//
// gamelogic01.c
//
// This is group 1 of scene ids.
//
// Essentially, this is the all of the main story dialog of the game.
//
// I also put all of the "special scenes" (map atomic elements) in here as well.
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"

// external linkage to the game variables.
extern  char    gcDebugFlag;

// external linkage to the game variables.
extern struct  statedata_NPCData *gpstructNPC_Base;
extern struct  statedata_GlobalData gpstructPC_Global;


//
// Game Start function.
//
int gamelogic01_scene1001 (int iSubSceneId, char cSubFlag)
{
    int iRet;
    short sOffset1;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    // init the global vars.
    gpstructPC_Global.cLocationId = 0;
    gpstructPC_Global.cAreaId = 0;
    gpstructPC_Global.cClothesValue = 0;
    gpstructPC_Global.cDildoValue = 0;
    gpstructPC_Global.cBreastsValue = 0;
    gpstructPC_Global.cClitorisValue = 0;
    gpstructPC_Global.iDayCount = 0;
    gpstructPC_Global.cTimeValue = 0;
    gpstructPC_Global.cDifficultyLevel = 0;
    gpstructPC_Global.cHintCountDown = 0;

    // init the entire memory space.
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        gpstructNPC_Base[sOffset1].cLocationId = 0;
        gpstructNPC_Base[sOffset1].cAreaId = 0;
        gpstructNPC_Base[sOffset1].cActionId = 0;
        gpstructNPC_Base[sOffset1].cNameToFaceFlag = 0;
        gpstructNPC_Base[sOffset1].cInteractionLockFlag = 0;
        gpstructNPC_Base[sOffset1].iKnownValue = 0;
        gpstructNPC_Base[sOffset1].iTrustValue = 0;
        gpstructNPC_Base[sOffset1].iObedienceValue = 0;
        gpstructNPC_Base[sOffset1].iEnergyValue = 0;
    }

    iRet = mdialog_addToDialogWithSrchRep (">Start new game\n\n:: select the difficulty ::\n\nEasy = get 33 of 64 villagers to fully trust you.\nMedium = get 54 of 64 villagers to fully trust you.\nHard = get all of the 64 villagers to fully trust you.\n\nThe bad ending occurs if any of the villagers, not including the previous mayor (#!01#), start being openly obedient to you, BEFORE you reach the required level of trust from the required number of villagers.\n\n");
    if (iRet != 0) return iRet;

    iRet = mutils_addToCommandList ("Easy", 1002, 1);
    if (iRet != 0) return iRet;
    iRet = mutils_addToCommandList ("Medium", 1002, 2);
    if (iRet != 0) return iRet;
    iRet = mutils_addToCommandList ("Hard", 1002, 3);
    if (iRet != 0) return iRet;

    return 0;
}

//
// Difficulty level select.
//
int gamelogic01_scene1002 (int iSubSceneId, char cSubFlag)
{
    int iRet;
    short sOffset1;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 1:
        if (cSubFlag == 0)
        {
            iRet = mdialog_addToDialogWithSrchRep (">Easy\n\n");
            if (iRet != 0) return iRet;
        }

        gpstructPC_Global.cDifficultyLevel = 1;

        break;

    case 2:
        if (cSubFlag == 0)
        {
            iRet = mdialog_addToDialogWithSrchRep (">Medium\n\n");
            if (iRet != 0) return iRet;
        }

        gpstructPC_Global.cDifficultyLevel = 2;

        break;

    default:
        if (cSubFlag == 0)
        {
            iRet = mdialog_addToDialogWithSrchRep (">Hard\n\n");
            if (iRet != 0) return iRet;
        }

        gpstructPC_Global.cDifficultyLevel = 3;

        break;

    }

    // init the global vars.
    gpstructPC_Global.cLocationId = 2; // inside the mayor's house
    gpstructPC_Global.cAreaId = 1; // mayor's house
    gpstructPC_Global.cClothesValue = 0; // default
    gpstructPC_Global.cDildoValue = 0; // default
    gpstructPC_Global.cBreastsValue = 0; // default
    gpstructPC_Global.cClitorisValue = 0; // default
    gpstructPC_Global.iDayCount = 1; // day 1.
    gpstructPC_Global.cTimeValue = 10; // 06:45.
    gpstructPC_Global.cHintCountDown = 0; // reset

    // set the mayor manually.
    gpstructNPC_Base[0].cLocationId = 0;
    gpstructNPC_Base[0].cAreaId = 0;
    gpstructNPC_Base[0].cActionId = 0;
    gpstructNPC_Base[0].cNameToFaceFlag = 1;
    gpstructNPC_Base[0].cInteractionLockFlag = 0;
    gpstructNPC_Base[0].iKnownValue = STATEDATA_KNOWNMAX;
    gpstructNPC_Base[0].iTrustValue = STATEDATA_TRUSTMAX;
    gpstructNPC_Base[0].iObedienceValue = STATEDATA_OBEDIENCEMAX;
    gpstructNPC_Base[0].iEnergyValue = 5;

    // init the entire memory space.
    for (sOffset1 = 1; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // I am going to 0 these values for now..
        gpstructNPC_Base[sOffset1].cLocationId = 0;
        gpstructNPC_Base[sOffset1].cAreaId = 0;
        gpstructNPC_Base[sOffset1].cActionId = 0;

        // these are the initial values for MOST NPCs..
        gpstructNPC_Base[sOffset1].cNameToFaceFlag = 0;
        gpstructNPC_Base[sOffset1].cInteractionLockFlag = 0;
        gpstructNPC_Base[sOffset1].iKnownValue = 0;
        gpstructNPC_Base[sOffset1].iTrustValue = 0;
        gpstructNPC_Base[sOffset1].iObedienceValue = 0;
        gpstructNPC_Base[sOffset1].iEnergyValue = STATEDATA_ENERGYMAX;
    }

    // set interaction locks on specific NPCs.
    gpstructNPC_Base[7].cInteractionLockFlag = 1; // 8 - 1 = Redinald
    gpstructNPC_Base[26].cInteractionLockFlag = 1; // 27 - 1 = Viktor
    gpstructNPC_Base[46].cInteractionLockFlag = 1; // 47 - 1 = Melvin
    gpstructNPC_Base[47].cInteractionLockFlag = 1; // 48 - 1 = Gary
    gpstructNPC_Base[56].cInteractionLockFlag = 1; // 57 - 1 = Marcel
    gpstructNPC_Base[59].cInteractionLockFlag = 1; // 60 - 1 = Fabian

    iRet = gamelogic01_scene1003 (0, cSubFlag + 1);
    return iRet;
}

//
// Story Start.
//
int gamelogic01_scene1003 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    iRet = mdialog_addToDialogWithSrchRep ("\n[First evening...]\n\nThere is a gathering at the #!65# tavern. While tavern hall is barely large enough for 40 men, 60 are crammed in there. Even the two beggars turned up.\n\nThere is a small podium at the front of the hall, but no one is standing at it. The two stars of the town meeting haven\'t appeared yet.\n\nOne of the farmers turns to the #!65# constable, and asks \"Is it true... that old cunt #!01#... is fuckin\' the new cumdump already?\"\n\nThe constable responds \"That\'s mayor #!01# for you. He arranged for the new whore to come here, so he gets to screw the little slut first\".\n\nThere are a series of complaints from the crowd.\n\nThe constable addresses the crowd \"Settle down. Settle THE FUCK down. Remember... BEST behavior\".\n\nJust as the constable uttered his last word, the door next the podium swung open. A young woman, in a bunny suit, struts into the room \"Hiii... My name is #!00#\".\n\nAs the young woman starts waving and blowing kisses at the crowd, loud noise of cheering and wolf-whistles drown out the occasional shouts of \"show us your tits\" and \"suck my cock, bitch\". The volume only increases as #!00# starts sensuously sucking on her index finger, and reaches a fever pitch when she starts massaging her own breasts and nipples through the fabric of her bunny suit.\n\nThe excitement continues as #!00# then saunters back over to the small door next to the podium, reaches through the door and grabs the end of a chain. #!00# strides back past the podium, while still holding the chain.\n\n");
    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-Start1-by-Inkeranon.jpg\" /></center><br/>\n");
    if (iRet != 0) return iRet;
#endif

    iRet = mdialog_addToDialogWithSrchRep ("Then, through the door, a man wearing a leather full-body fetish outfit staggers into the room. The other end of the chain is attached to a spiked collar around his neck. His mouth is held open with a mouth spreader. His eyes are covered by a leather blindfold. His penis is exposed, and he is fully erect. Pre-cum is drooling from the tip of his penis.\n\nWithin seconds of the man in the fetish outfit entering the room, the crowd goes almost dead silent. There there are a couple of \"what the fuck\" statements.\n\n#!00# speaks \"Sorry... I sort of went too far and broke the mayor... #!01# is now MY slave\".\n\nThere is a minor hubbub from the audience, being a combination of \'what-gasps\', #!01#\'s name, and more \"what the fuck\" statements.\n\nWhen the chatter dies down, #!00# addresses the crowd \"So, Hiii... My name is #!00#. I am the new #!65# whore... and... I am also your new mayoress. It is going to be a pleasure, I am sure\".\n\n\n[The next morning...]\n\n#!00# is at her new residence. As the village whore, she would normally just have a room at the tavern to operate out of. As the mayoress, she has a house instead. She did check out the room at the tavern, but it isn\'t as roomy enough for both her and her new manservant to stay in. So she decided to go back to #!01#\'s house. There is a room in the mayor\'s house that allow her to stretch her wings in private.\n\n");
    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-Start2-by-Inkeranon.jpg\" /></center><br/>\n");
    if (iRet != 0) return iRet;
#endif

    iRet = mdialog_addToDialogWithSrchRep ("#!01# is rather useful. Last night, he told everyone that #!00# is the new mayoress, and that he has officially stepped down as the mayor. This morning #!01# told #!00# about everyone in the village. She knows the names of everyone now. #!00# hasn\'t associated their names to their cocks yet, but that won't take long. It was a good idea to turn #!01# into her loyal \'sperm bag\' first.\n\n#!00# has every intention to make everyone else in #!65# into her \'sperm bags\'. They don\'t know it yet, but being one of #!00#\'s obedient \'sperm bags\' is the greatest wonder that she can bestow. #!00# licks her lips. She then conceals her wings, horns and tail. With the non-human-looking stuff hidden away, #!00# puts her bunny girl outfit back on.\n\nWhile #!01# was kind enough to provide dinner, #!00# is starting to hunger for breakfast. With 64 human men, and #!00# being the only woman in village, it should not be too hard for her to find a decent meal.\n\n");
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Good ending.
//
int gamelogic01_scene1004 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    iRet = mdialog_addToDialogWithSrchRep ("\n[One week later, late in the evening...]\n\n#!00# is considering renaming #!65# to \'Bunnyville\'. She is the mayoress after all.\n\nAs #!00# strides into the hall of the #!65# tavern, her loyal \'sperm bags\' greet her. They stand there, lightly stroking their own erect cocks so that they are ready for her.\n\n#!00# kneels down as they gather around her. She starts licking the hood of the nearest cock, while her left and right hands immediately start groping the shafts of another two nearby penises. #!01# approaches #!00# from behind and starts massaging her udders \"Ah, that\'s the spot... yes\". #!00# goes back to sucking the dick in her mouth.\n\nIt does not take long for the cock in her mouth to ejaculate. Entree is served.\n\n");
    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-GoodEnd1-by-Inkeranon.jpg\" /></center><br/>\n");
    if (iRet != 0) return iRet;
#endif

    iRet = mdialog_addToDialogWithSrchRep ("#!00# decides that she can relax. She is safe here inside the tavern hall, so she lets her horns, wings and tail out. No one is surprised. She showed them all what she is a couple of days ago. Everyone are her obedient servants anyway, so they are not scared.\n\n");
    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-GoodEnd2-by-Inkeranon.jpg\" /></center><br/>\n");
    if (iRet != 0) return iRet;
#endif

    iRet = mdialog_addToDialogWithSrchRep ("#!00# the continues to alternate suck between the two cocks she started playing with earlier. They ejaculate at the same time, one down her throat, and the other on her face. Not enough for a main meal. #!00# needs another three servings. Then there is desert, that is essential.\n\n\nAs naked entranced men silently shuffle around inside the tavern. #!00# continues to feed.\n\nGOOD END.\n\n");

#ifdef INTERFACE_CURSES
    if (iRet != 0) return iRet;

    iRet = mutils_addToCommandList ("Credits", 3, 0);
    if (iRet != 0) return iRet;
    iRet = mutils_addToCommandList ("Main Menu", 0, 0);
#endif // INTERFACE_CURSES
    return iRet;
}

//
// Bad ending.
//
int gamelogic01_scene1005 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    iRet = mdialog_addToDialogWithSrchRep ("\n[Four days later, late in the evening...]\n\n#!00# is on the run. She had to leave #!01# and her other \'sperm bags\' behind.\n\nEarlier in the morning, a bunch of assholes showed up, and started harassing her \'sperm bags\'. Some of #!00#'s \'sperm bags\' fought back, but the assholes had swords. During the fight, #!00# escaped into the forest. When #!00# looked back, she could see that most of the buildings of #!65# were burning.\n\n");
    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-BadEnd1-by-Inkeranon.jpg\" /></center><br/>\n");
    if (iRet != 0) return iRet;
#endif

    iRet = mdialog_addToDialogWithSrchRep ("Someone wondered away from #!65# and told someone else about #!00# being in the village. This seemed to attract the assholes in the dark robes and armor. It might have been #^00#.\n\n\nIt is a shame, because #!65# was ideal for #!00#. Oh well. There has to be another collection of \'sperm bags\' for her to feed on... out there... somewhere.\n\nBAD END.\n\n");

#ifdef INTERFACE_CURSES
    if (iRet != 0) return iRet;

    iRet = mutils_addToCommandList ("Credits", 3, 0);
    if (iRet != 0) return iRet;
    iRet = mutils_addToCommandList ("Main Menu", 0, 0);
#endif // INTERFACE_CURSES
    return iRet;
}


