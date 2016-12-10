//
// gamelogic02.c
//
// This is group 2 of scene ids.
//
// Essentially, this is the all of the navigation actions of the game.
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"

// external linkage to the game variables.
extern  char    gcDebugFlag;

// external linkage to the game variables.
extern struct  statedata_Locations gstructLocationList[];
extern struct  statedata_NPCData *gpstructNPC_Base;
extern struct  statedata_GlobalData gpstructPC_Global;
extern struct  statedata_NPCPriorityList *gpstructNPC_Priority;
extern short   gsNPC_PriorityUsed;


//
// Random dialog for if the PC cannot find anyone at the immediate location.
//
int gamelogic02_noNPCDialog ()
{
    char cRand1;
    int iRet;

    cRand1 = (char)(rand() % 4);

    switch (cRand1)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (" #!00# is bored, because there are no cocks to play with.");
        break;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (" #!00# is unhappy that the penises are hiding.");
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (" #!00# wants to go elsewhere, as it this is rather boring.");
        break;

    default:
        iRet = mdialog_addToDialogWithSrchRep (" #!00# looks around, lamenting the lack of dicks.");
        break;
    }
    if (iRet != 0) return iRet;

    return 0;
}


//
// Random dialog for if the PC has found someone new at the immediate location.
//
int gamelogic02_newNPCDialog ()
{
    char cRand1;
    int iRet;

    cRand1 = (char)(rand() % 4);

    switch (cRand1)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (", to get to know the her new friends.\n\n");
        break;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (", to meet the new penises in her life.\n\n");
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (", as it is good to greet a new cock every now and then.\n\n");
        break;

    default:
        iRet = mdialog_addToDialogWithSrchRep (", as it would be plain rude for her to not say hello to a new dick or two.\n\n");
        break;
    }
    if (iRet != 0) return iRet;

    return 0;
}


//
// Code to process the encounter with the NPCs.
//
int gamelogic02_encounterProcess ()
{
    char cRand1;
    int iRet;
    short sCutoff = 0;

    // prioritize the NPC interaction with the PC.
    statedata_prioritizeNPCs (gpstructPC_Global.cLocationId, gpstructPC_Global.cAreaId);
    // this loads up the sort list, and also populates a variable.
    // yeah, I cheated and used a global variable and global array for this.

    // if there are no NPCs engaging with the PC, that MIGHT mean that she is by herself.
    if (gsNPC_PriorityUsed == 0)
    {
        short sRet;

        // is the PC alone at the location?
        iRet = statedata_isPCAlone (gpstructPC_Global.cLocationId, &sRet);
        // sound asleep NPCs do not count.. these PCs have to be awake.

        // if there is a single NPC.
        if (iRet == 6)
        {
            mdialog_setDynamicEntry (0, sRet + 1);

            iRet = mdialog_addToDialogWithSrchRep ("While #^00# is here, he does not seem to be interested. #!00# decides to ");
            if (iRet != 0) return iRet;

            cRand1 = (char)(rand() % 3);

            switch (cRand1)
            {
            case 0:
                iRet = mdialog_addToDialogWithSrchRep ("ask #^00# if her awesome sexual services are to everyone\'s satisfaction.");
                break;

            case 1:
                iRet = mdialog_addToDialogWithSrchRep ("suggest to #^00# the health benefits of ejaculating inside of her everyday.");
                break;

            default:
                iRet = mdialog_addToDialogWithSrchRep ("talk to #^00# about #!65#\'s need for more whores to suck everyone\'s cocks.");
                break;
            }
            if (iRet != 0) return iRet;

            iRet = mdialog_addToDialogWithSrchRep ("\n\n\n[A while later...]\n\n");
            if (iRet != 0) return iRet;

            return 0;
        }

        // if there are awake NPCs.
        if (iRet == 0)
        {
            iRet = mdialog_addToDialogWithSrchRep ("While there are villagers here, #!00# notices that they aren't enthusiastic. #!00# decides to keep them entertained by ");
            if (iRet != 0) return iRet;

            cRand1 = (char)(rand() % 3);

            switch (cRand1)
            {
            case 0:
                if (gpstructPC_Global.cDildoValue == 0)
                    iRet = mdialog_addToDialogWithSrchRep ("fingering herself then massaging her breasts and nipples.");
                else if (gpstructPC_Global.cDildoValue == 1)
                    iRet = mdialog_addToDialogWithSrchRep ("playing with the dildos in her ass and pussy.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("playing with the vibrators in her pussy and ass.");
                break;

            case 1:
                if (gpstructPC_Global.cClitorisValue < 2)
                    iRet = mdialog_addToDialogWithSrchRep ("chatting to them about important matters about running #!65#, such as gangbang sessions at the tavern.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("inquiring if they would prefer their sluts with or without enlarged clitorises.");
                break;

            default:
                if (gpstructPC_Global.cBreastsValue < 2)
                    iRet = mdialog_addToDialogWithSrchRep ("inquiring about their sexual alignment and preferences.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("asking if they like smaller breasts, or bigger ones.");
                break;
            }
            if (iRet != 0) return iRet;

            iRet = mdialog_addToDialogWithSrchRep ("\n\n\n[A while later...]\n\n");
            if (iRet != 0) return iRet;

            return 0;
        }

        // look for if there is a sleeping NPC at the current location.
        sRet = statedata_isThereASleepingNPC (gpstructPC_Global.cLocationId);

        // if there isn't then the PC is just going to have to entertain herself.
        if (sRet == -1)
        {
            cRand1 = (char)(rand() % 3);

            switch (cRand1)
            {
            case 0:
                iRet = mdialog_addToDialogWithSrchRep ("With the absence of any penises to play with");
                break;

            case 1:
                iRet = mdialog_addToDialogWithSrchRep ("With the lack of energetic cocks being present");
                break;

            default:
                iRet = mdialog_addToDialogWithSrchRep ("With no dicks in plain sight");
                break;
            }
            if (iRet != 0) return iRet;

            iRet = mdialog_addToDialogWithSrchRep (", #!00# ");
            if (iRet != 0) return iRet;

            cRand1 = (char)(rand() % 4);

            switch (cRand1)
            {
            case 0:
                if (gpstructPC_Global.cClothesValue < 2)
                    iRet = mdialog_addToDialogWithSrchRep ("is forced to jill herself off in private.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("pleasures herself, while considering further alterations to her wardrobe.");
                break;

            case 1:
                if (gpstructPC_Global.cDildoValue == 0)
                    iRet = mdialog_addToDialogWithSrchRep ("has to pleasure herself.");
                else if (gpstructPC_Global.cDildoValue == 1)
                    iRet = mdialog_addToDialogWithSrchRep ("plays with the dildos she received from #!60#.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("plays with the vibrators she received from #!27#.");
                break;

            case 2:
                if (gpstructPC_Global.cBreastsValue < 2)
                    iRet = mdialog_addToDialogWithSrchRep ("keeps herself occupied with her own fingers.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("massages her breasts and nipples.");
                break;

            default:
                if (gpstructPC_Global.cClitorisValue < 2)
                    iRet = mdialog_addToDialogWithSrchRep ("resorts to slicking herself off.");
                else
                    iRet = mdialog_addToDialogWithSrchRep ("plays around with the size of her clitoris.");
                break;
            }
            if (iRet != 0) return iRet;

            iRet = mdialog_addToDialogWithSrchRep ("\n\n\n[A while later...]\n\n");
            if (iRet != 0) return iRet;

            return 0;
        }

        mdialog_setDynamicEntry (0, sRet + 1);

        if (gpstructNPC_Base[sRet].cNameToFaceFlag == 0)
        {
            gpstructNPC_Base[sRet].cNameToFaceFlag = 1;
            iRet = mdialog_addToDialogWithSrchRep ("#!00# satisfies herself by sucking on an unfamiliar cock. While it\'s owner is unconscious and sleeping soundly, the penis is certainly lively. She had not met this one before now, but she is guesses that this is #^00#.");
        }
        else
        {
            if (gpstructNPC_Base[sRet].iEnergyValue < STATEDATA_ENERGYAVAIL)
                iRet = mdialog_addToDialogWithSrchRep ("#^00# is here, but is sound asleep. #!00# decides that while #^00# isn\'t exactly energetic, she is not going to complain. Besides, it is her duty as #!65#\'s mayoress to suck him dry.");
            else
                iRet = mdialog_addToDialogWithSrchRep ("#^00# is here, but is sound asleep. #!00# sates herself by sucking on #^00#\'s penis while he sleeps.");
        }
        if (iRet != 0) return iRet;

        // reset this NPC energy to 0.
        gpstructNPC_Base[sRet].iEnergyValue = 0;

        iRet = mdialog_addToDialogWithSrchRep ("\n\n\n[A little while later...]\n\n");
        if (iRet != 0) return iRet;

        return 0;
    }

    // list out all of the NPCs who showed up (and potentially introduced themselves) to the PC.
    iRet = statedata_nameShowupNPCs (gpstructPC_Global.cLocationId);
    if (iRet != 0) return iRet;

    // Note: gsNPC_PriorityUsed cannot = 0, as that was covered by the code above.

    switch (gsNPC_PriorityUsed)
    {
    case 1: // 2p interaction
        sCutoff = 1;
        mdialog_setDynamicEntry (0, gpstructNPC_Priority[0].sOffset + 1);

        break;

    case 2: // 3p interaction
        sCutoff = 2;
        mdialog_setDynamicEntry (0, gpstructNPC_Priority[0].sOffset + 1);
        mdialog_setDynamicEntry (1, gpstructNPC_Priority[1].sOffset + 1);

        break;

    case 3: // 4p interaction
        sCutoff = 3;
        mdialog_setDynamicEntry (0, gpstructNPC_Priority[0].sOffset + 1);
        mdialog_setDynamicEntry (1, gpstructNPC_Priority[1].sOffset + 1);
        mdialog_setDynamicEntry (2, gpstructNPC_Priority[2].sOffset + 1);

        break;

    case 4: // 5p interaction
        sCutoff = 4;
        mdialog_setDynamicEntry (0, gpstructNPC_Priority[0].sOffset + 1);
        mdialog_setDynamicEntry (1, gpstructNPC_Priority[1].sOffset + 1);
        mdialog_setDynamicEntry (2, gpstructNPC_Priority[2].sOffset + 1);
        mdialog_setDynamicEntry (3, gpstructNPC_Priority[3].sOffset + 1);

        break;

    default: // 6p interaction (there is no 7 and above)
        sCutoff = 5;
        mdialog_setDynamicEntry (0, gpstructNPC_Priority[0].sOffset + 1);
        mdialog_setDynamicEntry (1, gpstructNPC_Priority[1].sOffset + 1);
        mdialog_setDynamicEntry (2, gpstructNPC_Priority[2].sOffset + 1);
        mdialog_setDynamicEntry (3, gpstructNPC_Priority[3].sOffset + 1);
        mdialog_setDynamicEntry (4, gpstructNPC_Priority[4].sOffset + 1);

        break;
    }
    // the primary purpose is to set the cutoff (used below), and the
    //  linkages for the mdialog dynamic entries.

    // this function lists out all of the observers
    iRet = statedata_namePresentNPCs (gpstructPC_Global.cLocationId, sCutoff);
    if (iRet != 0) return iRet;

    switch (gsNPC_PriorityUsed)
    {
    case 1: // 2p interaction
        cRand1 = (char)(rand() % 11);

        switch (cRand1)
        {
        case 0:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# starts fucking #!00#\'s pussy in the missionary position. #!00# takes the initiative by leg locking #^00#.\n\n");
            break;

        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# lays down in the missionary position and her anus is fucked by #^00#\'s cock.\n\n");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# crouches down on all fours, allowing #^00#\'s penis to slam into her vagina with a single thrust.\n\n");
            break;

        case 3:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# fucks #!00#\'s ass, doggy-style.\n\n");
            break;

        case 4:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# lays down, so that #!00# can straddle his crotch. #^00# gropes #!00#\'s breasts, as she slips his penis into her pussy and starts humping away.\n\n");
            break;

        case 5:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# lays down, allowing #!00# to stuff #^00#\'s cock inside her pussy, while riding him in a reverse cowgirl position.\n\n");
            break;

        case 6:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# has #^00# lay on his back, then lowers her butt onto #^00#\'s crotch, allowing his erect penis to penetrate her butt. #!00# then starting piston on #^00#\'s cock, while looking at him.\n\n");
            break;

        case 7:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# lays flat on his back, and #!00# forces his penis into her anus. #!00# then gyrates her hips in a reverse cowgirl position.\n\n");
            break;

        case 8:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# gives #^00# a tit-fuck. #!00# looks at #^00# directly in the eyes. #^00# just watches as his cock disappears into #!00#\'s cleavage.\n\n");
            break;

        case 9:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# starts by vacuum sucking #^00#\'s cock. #^00# responds by grabbing #!00#\'s head and thrusting his penis in and out of #!00#\'s mouth.\n\n");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# gives #^00# a tit-fuck fellatio combination, alternating between using her breasts, then her mouth, then a combination of both her breasts and her mouth at the same time.\n\n");
            break;
        }
        if (iRet != 0) return iRet;

        break;

    case 2: // 3p interaction
        cRand1 = (char)(rand() % 6);

        switch (cRand1)
        {
        case 0:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# lays down, allowing #!00# to straddle his crotch and slide #^00#\'s penis into her pussy. Then #^01# wonders behind #!00#, and slams his cock into #!00#\'s anus. #^00# and #^01# then start piston fucking #!00#.\n\n");
            break;

        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# and #^01# talk to #!00#, suggesting double-penetration. #!00# agrees and straddles #^00#\'s crotch, taking his penis into her pussy, then allows #^01# to slide his penis into her anus.\n\n");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("#^01# walks up to #!00# and tells her to bend over and suck his dick. #!00# notices that #^00# is standing behind her, and decides to go along with the game. #!00# bends over and starts to suck on #^01#\'s penis, leaving her ass exposed. #^00# walks up behind #!00#, and slams his cock into #!00#\'s wet snatch. #^00# and #^01# start thrusting away in unison.\n\n");
            break;

        case 3:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# walks up behind #!00# and starts fondling her breasts. #!00# then notices that #^01# is standing in front of her and also in the mood, so she grabs #^00#\'s cock, slides it into her moist slit, then bends over and gropes for #^01#\'s crotch. #^01# responds by grabbing #!00#\'s head and slamming his penis down her throat, as #^00# also starts fucking #!00#\'s pussy with vigor.\n\n");
            break;

        case 4:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# walks behind #!00#, making a comment about how juicy her butt looks. #!00# responds that it would a lot better with his cock in it, so she bends over allowing #^00# easy access to her butthole. #^00# proceeds to slide his erect penis into #!00#\'s anus, while #^01# walks up to #!00#\'s face and offers his own penis to her. #!00# starts licking and sucking on #^01#\'s penis, so both #^01# and #^00# start fucking #!00# from both ends.\n\n");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# eyes both #^00# and #^01#, noticing that both of them are in the mood. #!00# walks over to #^01#, bends over and starts sucking and licking his erect cock. #!00# notices that #^00# has moved behind her butt, grabbed her hips, and slammed his cock into her anus. #^00# starts forcing his own penis down #!00#\'s throat, and both #^01# and #^00# start thrusting away.\n\n");
            break;
        }
        if (iRet != 0) return iRet;

        break;

    case 3: // 4p interaction
        cRand1 = (char)(rand() % 4);

        switch (cRand1)
        {
        case 0:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# looks at #^00#, #^01# and #^02#, who appear to be in the mood. #!00# suggests that #^00# lay down so she can impale her pussy on his cock. #!00# then suggests that #^01# fucks her ass, while she sucks #^02# off. #^00#, #^01# and #^02# just look at each other and nod their heads in agreement.\n\n");
            break;

        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("#^01# grabs #!00# from behind and slams his cock into #!00#\'s butthole. #!00# smiles, looks at #^00# and #^02#, and asks if they want to join in. #^00# smiles, then lays down, allowing #!00# and #^01# to stagger over to his crotch so that #!00# could lower her pussy onto #^00#\'s penis. #^02# then grabs #!00#\'s head with both of his hands and thrusts his penis down her throat.\n\n");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("#^00#, #^01# and #^02# descend on #!00# like a pack of rabid animals, and start teasing #!00#\'s nipples and genitals. #!00# has no problems with it, and suggests that someone had better fill both of her lower mouthes. #^00# slams his cock into #!00#\'s pussy, while #^01# impales #!00#\'s anus with his own penis. #^02# offers his penis to #!00#\'s mouth as both her pussy and anus are repeatedly violated. Not satisfied with #!00#\'s oral skills, #^02#'s starts thrusting his dick down #!00#\'s throat.\n\n");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("#^00# and #^01# take the initiative, and make their move on #!00#. #^00# distracts #!00# by fondling her breasts, while #^01# grabs #!00# from behind and slams his cock into her anus. #^00# then thrusts his penis into #!00#\'s pussy. Meanwhile, #^02# is standing around. #!00# decides that she can do #^02# as well, and asks all 3 men to help her out. #^02# helps #!00#, #^00# and #^01# change positions, so that #^00# is on his back, and #!00# is still being double-penetrated. #!00# then rewards #^02# for his assistance by sucking on his cock.\n\n");
            break;
        }
        if (iRet != 0) return iRet;

        break;

    case 4: // 5p interaction
        cRand1 = (char)(rand() % 4);

        switch (cRand1)
        {
        case 0:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# looks at #^00#, #^01#, #^02# and #^03#, licks her lips, proclaims \"you four will do\", then leaps on #^00#. #^01#, #^02# and #^03# help #^00# lay down while #!00# is clinging to him and stuffing his penis into her pussy. After the trio successfully help #^00# lay down. #^01# kneels down behind #!00#, and starts fucking her butt as well. #^02# and #^03# flank #!00# on either side, so #!00# starts alternate fondling and sucking their cocks while #^00# and #^01# continue humping away at both of her lower orifices.\n\n");
            break;

        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("#^01#, #^02# and #^03# start fondling #!00#\'s breasts and genitals, while #^00# lays down underneath #!00#. #!00# takes the initiative and jumps on #^00#\'s crotch, shoving his cock into her pussy. #^01# then impales #!00#\'s ass with his dick, while #!00# starts to alternate between sucking #^02# and #^03#\'s cocks. #^00# and #^01# continue double-penetration fucking #!00#.\n\n");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("#^03#, #^00#, #^02# and #^01# decide to move on #!00#, at the same time. #!00# proclaims \"rather feisty aren\'t you... okay, I will fuck all four or you\". #!00# accepts #^01#\'s erect penis into her butthole, and lets #^02# and #^03# lift her up and impale her onto #^00#\'s erect cock. #!00# starts playing with #^02# and #^03#'s cocks.\n\n");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# leaps on #^00#, and starts impaling her pussy on his cock while he is still standing. #^02#, #^03# and #^01# help #^00# lay down while #!00# is still being fucked by #^00#. After #^00# is on the ground, #!00# starts toying with #^02# and #^03#\'s cocks, taking turns in sucking on each of them. #^01# takes the opportunity to start fucking #!00#\'s anus, and starts thrusting in unison with #^00#.\n\n");
            break;
        }
        if (iRet != 0) return iRet;

        break;

    default: // 6p interaction (there is no 7 and above)
        cRand1 = (char)(rand() % 4);

        switch (cRand1)
        {
        case 0:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# looks at #^00#, #^01#, #^02#, #^03# and #^04#, and decides that can can do all five of them. #!00# is about to make suggestions, when #^00# lays down. #^03# and #^04# escorts #!00# over to #^00#. As #!00# slides #^00#\'s cock into her pussy, #^01# kneels down behind #!00# and buries his penis in her anus. #^02# then stands in front of #!00#, while #^03# and #^04# flank #!00#. #^00# and #^01# start fucking #!00#\'s pussy and anus, so #!00# starts sucking #^02#\'s penis, while also fondling #^03# and #^04#\'s cocks with her hands.\n\n");
            break;

        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("#^01# approaches #!00# from behind and suddenly starts groping #!00#\'s breasts. #^03# and #^04# join in the petting and fondling of #!00# as #^00# lays down, and #^02# suggests that they \"carry the slut\" onto #^00#\'s cock. #^01#, #^03# and #^04# pick up #!00#, and impales her pussy onto #^00#\'s erect member, before #^01# shoves his own cock into #!00#\'s asshole. #!00# starts sucking on #^02#\'s cock and fondles the penises of #^03# and #^04#, as #^00# and #^01# start thrusting away.\n\n");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# walks over to #^02#, and decides that she is going to suck him off first. #^01# decides to grab #!00# from behind, and starts fucking her butt. #!00# responds by saying that she would rather have #^00#\'s penis inside her pussy. #^00# lays down, while #^02#, #^03# and #^04# help position #!00# and #^02#, so that #!00# can sit on #^00#\'s erect cock. After #^00# slams his penis inside of #!00#, she starts eagerly sucking #^02#'s dick, and groping for #^03# and #^04#'s penises with her free hands.\n\n");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("#!00# looks at #^00#, #^01#, #^02#, #^03# and #^04#, and asks \"are you boys ready\". #^00# smiles and claims that #!00#'s pussy is his. #!00# replies \"then you had better be on the bottom then\". #^00# lays down. #!00# eagerly straddles #^00#\'s crotch and just as she sticks his erect dick into her sopping wet snatch, #^01# kneels down behind #^00# and slides his erect penis into #!00#\'s anus. #^02# approaches #!00#\'s face, so she starts licking and sucking his penis. #!00# then reaches out for the erect cocks of #^03# and #^04# with her hands.\n\n");
            break;
        }
        if (iRet != 0) return iRet;

        break;
    }

    // this is how the values are increased for the stored parameters
    statedata_incrementPrioritizedNPCs (sCutoff, 150);

    iRet = mdialog_addToDialogWithSrchRep ("\n[A while later...]\n\n");
    if (iRet != 0) return iRet;

    // this function highlights if there are many/any changes with the participating NPCs.
    iRet = statedata_showNPCChanges (sCutoff);
    if (iRet != 0) return iRet;

    return 0;
}


//
// Setup/Continue the navigation.
//
int gamelogic02_scene1020 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    if (iSubSceneId == 0)
    {
        // check to see if we have reached the end-game condition.
        iRet = statedata_hasGameEndTriggered ();

        if (iRet != 0)
        {
            if (iRet == 1)
            {
                // call across to the good end.
                iRet = gamelogic01_scene1004 (0, cSubFlag + 1);
                return iRet;
            }
            else if (iRet == 2)
            {
                // Before calling across to the bad end, I need to identify the NPC most likely to have ratted out the PC.
                short sOffset1 = -1;
                short sOffset2;

                // find the NPC with the least amount of trust or known stats.
                for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
                {
                    if (sOffset1 == -1)
                    {
                        sOffset1 = sOffset2;
                        continue;
                    }

                    if (gpstructNPC_Base[sOffset2].iKnownValue < gpstructNPC_Base[sOffset1].iKnownValue)
                    {
                        sOffset1 = sOffset2;
                        continue;
                    }

                    if (gpstructNPC_Base[sOffset2].iTrustValue < gpstructNPC_Base[sOffset1].iTrustValue)
                    {
                        sOffset1 = sOffset2;
                        continue;
                    }
                }

                // set this NPC in the dynamic S/R list before passing control across to the bad end dialog.
                mdialog_setDynamicEntry (0, sOffset1 + 1);

                // call across to the bad end.
                iRet = gamelogic01_scene1005 (0, cSubFlag + 1);
                return iRet;
            }
        }

        statedata_incrementDateTimeAndUpdate ();

        iRet = mdialog_addToDialogWithSrchRep ("It is currently ");
        if (iRet != 0) return iRet;

        switch (gpstructPC_Global.cTimeValue)
        {
        case 1:
            iRet = mdialog_addToDialogWithSrchRep ("00:00");
            break;

        case 2:
            iRet = mdialog_addToDialogWithSrchRep ("00:45");
            break;

        case 3:
            iRet = mdialog_addToDialogWithSrchRep ("01:30");
            break;

        case 4:
            iRet = mdialog_addToDialogWithSrchRep ("02:15");
            break;

        case 5:
            iRet = mdialog_addToDialogWithSrchRep ("03:00");
            break;

        case 6:
            iRet = mdialog_addToDialogWithSrchRep ("03:45");
            break;

        case 7:
            iRet = mdialog_addToDialogWithSrchRep ("04:30");
            break;

        case 8:
            iRet = mdialog_addToDialogWithSrchRep ("05:15");
            break;

        case 9:
            iRet = mdialog_addToDialogWithSrchRep ("06:00");
            break;

        case 10:
            iRet = mdialog_addToDialogWithSrchRep ("06:45");
            break;

        case 11:
            iRet = mdialog_addToDialogWithSrchRep ("07:30");
            break;

        case 12:
            iRet = mdialog_addToDialogWithSrchRep ("08:15");
            break;

        case 13:
            iRet = mdialog_addToDialogWithSrchRep ("09:00");
            break;

        case 14:
            iRet = mdialog_addToDialogWithSrchRep ("09:45");
            break;

        case 15:
            iRet = mdialog_addToDialogWithSrchRep ("10:30");
            break;

        case 16:
            iRet = mdialog_addToDialogWithSrchRep ("11:15");
            break;

        case 17:
            iRet = mdialog_addToDialogWithSrchRep ("12:00");
            break;

        case 18:
            iRet = mdialog_addToDialogWithSrchRep ("12:45");
            break;

        case 19:
            iRet = mdialog_addToDialogWithSrchRep ("13:30");
            break;

        case 20:
            iRet = mdialog_addToDialogWithSrchRep ("14:15");
            break;

        case 21:
            iRet = mdialog_addToDialogWithSrchRep ("15:00");
            break;

        case 22:
            iRet = mdialog_addToDialogWithSrchRep ("15:45");
            break;

        case 23:
            iRet = mdialog_addToDialogWithSrchRep ("16:30");
            break;

        case 24:
            iRet = mdialog_addToDialogWithSrchRep ("17:15");
            break;

        case 25:
            iRet = mdialog_addToDialogWithSrchRep ("18:00");
            break;

        case 26:
            iRet = mdialog_addToDialogWithSrchRep ("18:45");
            break;

        case 27:
            iRet = mdialog_addToDialogWithSrchRep ("19:30");
            break;

        case 28:
            iRet = mdialog_addToDialogWithSrchRep ("20:15");
            break;

        case 29:
            iRet = mdialog_addToDialogWithSrchRep ("21:00");
            break;

        case 30:
            iRet = mdialog_addToDialogWithSrchRep ("21:45");
            break;

        case 31:
            iRet = mdialog_addToDialogWithSrchRep ("22:30");
            break;

        default:
            iRet = mdialog_addToDialogWithSrchRep ("23:15");
            break;
        }
        if (iRet != 0) return iRet;

        {
            char szWorking[24];

            sprintf (szWorking, ", day %d. #!00# is ", gpstructPC_Global.iDayCount);

            iRet = mdialog_addToDialogWithSrchRep (szWorking);
        }
        if (iRet != 0) return iRet;

        if ((gpstructPC_Global.cLocationId > 0) && (gpstructPC_Global.cLocationId < 67))
        {
            iRet = mdialog_addToDialogWithSrchRep (gstructLocationList[gpstructPC_Global.cLocationId - 1].pszDesc);
            if (iRet != 0) return iRet;
        }

        iRet = mdialog_addToDialogWithSrchRep (". Where should #!00# go next?\n\n");
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 1)
    {
        iRet = mutils_addToCommandList ("Mayor\'s house", 1021, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 2)
    {
        iRet = mutils_addToCommandList ("Constable's residence", 1022, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 3)
    {
        iRet = mutils_addToCommandList ("Guard barracks", 1023, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 4)
    {
        iRet = mutils_addToCommandList ("Moneylender\'s house", 1024, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 5)
    {
        iRet = mutils_addToCommandList ("Merchant\'s house", 1025, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 6)
    {
        iRet = mutils_addToCommandList ("Physician\'s residence", 1026, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 7)
    {
        iRet = mutils_addToCommandList ("Warehouse", 1027, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 8)
    {
        iRet = mutils_addToCommandList ("Brewery", 1028, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 9)
    {
        iRet = mutils_addToCommandList ("Tavern", 1029, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 10)
    {
        iRet = mutils_addToCommandList ("Kitchen", 1030, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 11)
    {
        iRet = mutils_addToCommandList ("Workshop", 1031, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 12)
    {
        iRet = mutils_addToCommandList ("Goat corral", 1032, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 13)
    {
        iRet = mutils_addToCommandList ("Lumber mill", 1033, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 14)
    {
        iRet = mutils_addToCommandList ("Forest edge", 1034, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 15)
    {
        iRet = mutils_addToCommandList ("Target range", 1035, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 16)
    {
        iRet = mutils_addToCommandList ("Lake edge", 1036, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 17)
    {
        iRet = mutils_addToCommandList ("Northern farm", 1037, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 18)
    {
        iRet = mutils_addToCommandList ("Eastern farm", 1038, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 19)
    {
        iRet = mutils_addToCommandList ("Southern farm", 1039, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 20)
    {
        iRet = mutils_addToCommandList ("Western farm", 1040, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 21)
    {
        iRet = mutils_addToCommandList ("Procurer\'s shack", 1041, 0);
        if (iRet != 0) return iRet;
    }

    if (gpstructPC_Global.cAreaId != 22)
    {
        iRet = mutils_addToCommandList ("Smuggler\'s shack", 1042, 0);
        if (iRet != 0) return iRet;
    }

    if (iSubSceneId == 0)
    {
        // this is the countdown for unlocking the "Give me a hint" menu.

        if (gpstructPC_Global.cHintCountDown > 0)
            gpstructPC_Global.cHintCountDown--;
    }

    if ((iSubSceneId == 0) && (gpstructPC_Global.cHintCountDown == 0))
    {
        iRet = mutils_addToCommandList ("Give me a hint", 1061, 0);
        if (iRet != 0) return iRet;
    }

    return 0;
}

//
// Mayor's house
//
int gamelogic02_scene1021 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Mayor\'s house\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the mayor\'s house.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 1;
        gpstructPC_Global.cLocationId = 1;

        iRet = statedata_nameLocalNPCs (1);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the mayor\'s house");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the mayor\'s house", 1021, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the mayor\'s house", 1021, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the gardener\'s shack next to the mayor\'s house", 1021, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the mayor\'s house\n\n");
        if (iRet != 0) return iRet;
        break;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is hangs around outside the mayor\'s house.\n\n");
        if (iRet != 0) return iRet;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the mayor\'s house\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 2;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside of the mayor\'s house.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (2);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the gardener\'s shack next to the mayor\'s house\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 3;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside gardener\'s shack next to the mayor\'s house.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (3);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Constable's residence
//
int gamelogic02_scene1022 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Constable\'s residence\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the constable\'s residence.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 2;
        gpstructPC_Global.cLocationId = 4;

        iRet = statedata_nameLocalNPCs (4);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the constable\'s residence");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the constable\'s residence", 1022, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the constable\'s residence", 1022, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the constable\'s residence\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the constable\'s residence\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 5;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside of the constable\'s residence.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (5);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Guard barracks
//
int gamelogic02_scene1023 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Guard barracks\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the guard barracks.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 3;
        gpstructPC_Global.cLocationId = 6;

        iRet = statedata_nameLocalNPCs (6);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the guard barracks");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the guard barracks", 1023, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the guard barracks", 1023, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the guard barracks\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the guard barracks\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 7;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the guard barracks.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (7);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Moneylender's house
//
int gamelogic02_scene1024 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Moneylender\'s house\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the moneylender\'s house.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 4;
        gpstructPC_Global.cLocationId = 8;

        iRet = statedata_nameLocalNPCs (8);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the moneylender\'s house");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the moneylender\'s house", 1024, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the moneylender\'s house", 1024, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the gardener\'s shack next to the moneylender\'s house", 1024, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the moneylender\'s house\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the moneylender\'s house\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the hallway of the moneylender\'s house.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 9;

        iRet = statedata_nameLocalNPCs (9);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around in the hallway of the moneylender\'s house");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around in the hallway of the moneylender\'s house", 1024, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the moneylender\'s room", 1024, 12);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the bodyguards room", 1024, 13);
        if (iRet != 0) return iRet;
        return 0;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the gardener\'s shack next to the moneylender\'s house\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 12;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the gardener\'s shack, next to the moneylender\'s house");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (12);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around in the hallway of the moneylender\'s house\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the moneylender\'s room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 10;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the moneylender\'s room, at his house.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 10(A): %d, %d\n", (int)gpstructNPC_Base[7].cInteractionLockFlag, (int)gpstructNPC_Base[7].cNameToFaceFlag);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        // this situation is only evaluated, for this location, if Redinald is locked.
        if ((gpstructNPC_Base[7].cInteractionLockFlag != 0) && (gpstructNPC_Base[7].cNameToFaceFlag != 0))
        {
            // unlock Redinald (this could be permanent)
            gpstructNPC_Base[7].cInteractionLockFlag = 0; // 8 - 1 = Redinald

            // the hack here, is to unlock Redinald, create the priority list, and see if it is only
            //  Redinald on the list. If we do not pass the entry requirements, Redinald is locked
            //  again, before executing the normal evaluation code..

            // prioritize the NPC interaction with the PC.
            statedata_prioritizeNPCs (gpstructPC_Global.cLocationId, gpstructPC_Global.cAreaId);
            // this loads up the sort list, and also populates a variable.

#ifdef BMPS_LVL2_DEBUG
            if (gcDebugFlag != 0)
            {
                char szWorking[400];

                sprintf (szWorking, "(debug) Loc 10(B): %d, %d", (int)gsNPC_PriorityUsed, (int)gpstructNPC_Priority[0].sOffset);
                iRet = mdialog_addToDialogWithSrchRep (szWorking);
                if (iRet != 0) return iRet;
            }
#endif // BMPS_LVL2_DEBUG

            // if we have a populated priority list. 8 - 1 = Redinald
            if ((gsNPC_PriorityUsed == 1) && (gpstructNPC_Priority[0].sOffset == 7))
            {
                // I don't have to unlock Redinald again, it is permanent.

                iRet = mdialog_addToDialogWithSrchRep ("\n\nAs #!00# enters #!08#\'s room, #!00# notices that #!08# seems to be checking to see if anyone else followed her. #!00# glances at the open door to #!08#\'s room, then looks at #!08#, and says \"I think... it is just me\".\n\n#!08# glances at #!00#, stands up, walks over to the door of the room, closes the door, and then locks it. Without looking at #!00#, #!08# utters \"Good\".\n\n#!00# then watches #!08#, as he walks over to a table, picks up a small empty glass and approaches #!00#. #!08# holds out the glass and says \"Could I trouble you to... pee... into this\".\n\n#!00# is not surprised. She already heard from #!01# about #!08#\'s little fetish. #!00# asks \"Wouldn\'t it be better... to just drink straight... from the source?\"\n\n#!08#'s eyes widen, as he exclaims \"Heaven should forbid it. The amount of rancid filth that must have accumulated down there... before you joined us... is considerable\".\n\n#!00# decides that while she could have fun arguing the point with #!08#, she can just teach him another way. #!00# takes the empty glass from #!08#, and asks \"I suppose you want to watch\".\n\n#!08# responds \"Of course\".\n\n#!00# grins.\n\n\n[10 minutes later...]\n\n#!08# is sitting on the edge of his bed, without his pants on. #!08# looks at #!00#, and asks \"Are you sure this is the best way for you to... make more?\"\n\n#!00# crouches down between #!08#\'s legs, looks up at him, and says \"I am sure\". #!00# then starts eagerly licking and sucking #!08#'s penis before his \'clean freak streak\' kicks in again.\n\n#!00# then skillfully manipulates #!08#\'s arousal so he reaches close to a climax, then holds him there.\n\n\n[15 minutes later...]\n\n#!08# is laying flat on his back, on his bed, in a dazed state. #!00#, is crouching near #!08#, and says \"I am ready now\".\n\n#!08# sleepily responds \"Yes... from the source... germs are on the glass... Yes... from the source... germs are on the glass\".\n\n#!00# lightly smiles, and considers that humans are so easy to manipulate at times. #!00# then straddles #!08# face. #!08# starts licking #!00#\'s pussy.\n\n#!00# says \"that\'s it... keep doing that... and you will get your drink\".\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (1, 150);

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (1);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }

            // re-lock Redinald.
            gpstructNPC_Base[7].cInteractionLockFlag = 1; // 8 - 1 = Redinald
        }

        iRet = statedata_nameLocalNPCs (10);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 13:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the bodyguards room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 11;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the bodyguard's room, at the moneylender\'s house.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (11);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Merchant's house
//
int gamelogic02_scene1025 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Merchant\'s house\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the merchant\'s house.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 5;
        gpstructPC_Global.cLocationId = 13;

        iRet = statedata_nameLocalNPCs (13);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the merchant\'s house");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the merchant\'s house", 1025, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the merchant\'s house", 1025, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the gardener\'s shack next to the merchant\'s house", 1025, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the merchant\'s house\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the merchant\'s house\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the hallway of the merchant\'s house.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 14;

        iRet = statedata_nameLocalNPCs (14);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay in the hallway of the merchant\'s house");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around in the hallway of the merchant\'s house", 1025, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the merchant\'s room", 1025, 12);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the security guards room", 1025, 13);
        if (iRet != 0) return iRet;
        return 0;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the gardener\'s shack next to the merchant\'s house\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 17;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the gardener\'s shack, next to the merchant\'s house");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (17);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around in the hallway of the merchant\'s house\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the merchant\'s room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 15;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the merchant\'s room, at his house.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (15);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 13:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the security guards room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 16;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the security guards room, at the merchant\'s house.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (16);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Physician's residence
//
int gamelogic02_scene1026 (int iSubSceneId, char cSubFlag)
{
    int iRet;
    char cEval1;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Physician\'s residence\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the physician\'s residence.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 6;
        gpstructPC_Global.cLocationId = 18;

        iRet = statedata_nameLocalNPCs (18);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the physician\'s residence");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the physician\'s residence", 1026, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the physician\'s residence", 1026, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the physician\'s residence\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the physician\'s residence\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 19;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the physician\'s residence.");
        if (iRet != 0) return iRet;

        // the evaluation of where we are at in the storyline, is based upon the combination of the breast and clitoris modifications.
        cEval1 = gpstructPC_Global.cBreastsValue + gpstructPC_Global.cClitorisValue;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 19(A): %d, %d, %d\n", (int)gpstructPC_Global.cClothesValue, (int)cEval1, (int)gpstructNPC_Base[13].iKnownValue);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        // start the check for the "Philippe - Mad scientist" storyline,
        //  if Bunny isn't wearing her original clothes, we have not
        //  reached the conclusion of the storyline yet, and Philippe has to be known.
        if ((gpstructPC_Global.cClothesValue != 0) && (cEval1 < 5) && (gpstructNPC_Base[13].iKnownValue >= STATEDATA_KNOWNMAX))
        // 14 - 1 = Philippe
        {
            // prioritize the NPC interaction with the PC.
            statedata_prioritizeNPCs (gpstructPC_Global.cLocationId, gpstructPC_Global.cAreaId);
            // this loads up the sort list, and also populates a variable.

#ifdef BMPS_LVL2_DEBUG
            if (gcDebugFlag != 0)
            {
                char szWorking[400];

                sprintf (szWorking, "\n(debug) Loc 19(B): %d, %d\n", (int)gsNPC_PriorityUsed, (int)gpstructNPC_Priority[0].sOffset);
                iRet = mdialog_addToDialogWithSrchRep (szWorking);
                if (iRet != 0) return iRet;
            }
#endif // BMPS_LVL2_DEBUG

            // if we have a populated priority list. 14 - 1 = Philippe
            //  the idea is that only Philippe that is present, to trigger the storyline progression.
            if ((gsNPC_PriorityUsed == 1) && (gpstructNPC_Priority[0].sOffset == 13))
            {
                char cAction; // 0 = breasts, 1 = clitoris

                // figure out what Philippe is going to be doing to Bunny.
                if (gpstructPC_Global.cBreastsValue >= 3)
                    // if breasts are already maxed out, only do clitoris.
                    cAction = 1;
                else if (gpstructPC_Global.cClitorisValue >= 2)
                    // if clitoris are already maxed out, only do breasts.
                    cAction = 0;
                else
                    // otherwise, use the RNG to decide.
                    cAction = (char)(rand() % 2);

                // first part dialog
                switch (cEval1)
                {
                case 0:
                    iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters #!14#\'s room. #!14# is here, but isn\'t paying immediate attention to #!00#. #!14# is currently focusing on something else. #!00# looks around the small room, that is both an examination room, and the place where #!14# sleeps.\n\nFinally, #!14# stands up from his chair and looks at #!00#, and says \"Time for your examination. Sit down, here\". #!14# points at another empty chair next to the one he was sitting on.\n\n#!00# decides to play along, so she saunters over to the second chair and sits on it. While sitting on the chair, #!00# notices what #!14# was working on. There are a collection of syringes lined up on the table. Once seated, #!00# asks #!14# \"So, how are we going to do this?... Do you want to stay standing, and I suck you cock... or\"...\n\n#!14# interjects \"No.. Quite frankly\", then #!14# picks up one of the syringes and carefully inspects the needle, and continues \"I am concerned about something... So I need to be thorough\".\n\n#!00# responds with a simple \"Oh\". #!01# had already told her about #!14#\'s fetish. Despite the fact that #!14# is attempting to act professionally, his boner is painfully straining against the fabric of his pants.\n\n#!14# looks at #!00# and says \"Now, this is going to sting, but... it is going to be worth it\".\n\n");
                    break;

                case 1:
                    iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters #!14#\'s room. #!14#, who was working on something again, looks at #!00#, glances around the room, then looks back at his work. #!14# then talks to #!00# without looking at her \"Sit down, I must... continue your examination\".\n\n#!00# mutters \"Okay\", then strides over to the chair next to #!14# and sits on it. #!00# does not have to even look at #!14#\'s crotch to know that he is aroused.\n\n#!14# starts talking to #!00#, without looking at her \"I am surprised... that you voluntarily came back\".\n\n#!00# asks \"Why are you surprised?\"\n\n#!14# finishes what he is working on, looks at #!00# and says \"Most others avoided returning... because of something about... pain\".\n\n#!00# considers the fact that she naturally can handle pain better than most humans. #!01# had told #!00# that every single woman that #!14# injected in the past had to be forcibly dragged back here, by the other villagers, so that #!14# could continue \'treating\' them.\n\n#!14# states \"Clearly, your condition is... worse than... than I feared.\". #!14# stands up, holds up another syringe, looks over it carefully, and then continues talking \"I must proceed further... for medical science\".\n\n#!00# does her best to not roll her eyes, ignores the fact that she can smell #!14#\'s arousal, and plays along with #!14#\'s little game.\n\n");
                    break;

                case 2:
                    iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters #!14#\'s room, and notices that she wasn\'t followed by anyone else. As #!14# glances at #!00#, then around the room, #!00# quietly considers the fact that she is going to have to continue playing the \'mad scientist game\' with #!14#.\n\n#!14# looks back at what he is working on, and says \"Sit down\". #!00# saunters over to the chair next to #!14#, and sits on it. After #!00# sits down, #!14# continues talking \"Your condition... is proving to be problematic. However, I have a solution\".\n\nAs #!14# holds up a syringe and inspects it again, #!00# stops herself from sighing.\n\n");
                    break;

                case 3:
                    iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters #!14#\'s room again, and notices that nobody else followed her. #!14# is working at his table, doing \'whatever it is he is doing with those syringes\'.\n\n#!14# glances at #!00#, then around the room, then resumes concentrating on what he is working on. #!14# says \"Sit down\". #!00# strides over to the chair next to #!14#, and sits on it. After #!00# sits down, #!14# continues talking \"Your condition... is still... problematic... Yes\".\n\n#!14# holds up a syringe and inspects it again. #!00# sighs, as #!14# is in his own little world right now.\n\n");
                    break;

                default: // case 4:
                    iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters #!14#\'s room again, and realizes that she wasn\'t followed. #!00# considers the fact that this would be so much easier if she wasn\'t here with just #!14#. #!00# glances down at her breasts and crotch. Making her nipples and clitoris grow after #!14# injected them certainly covered up the fact that what he was doing wasn\'t really having any effect on her, but it did not seem to deter #!14# from continuing.\n\n#!00# starts to wonder over to the chair next to #!14#, when #!14# says \"Sit down\". #!00# continues, and sits on the chair next to #!14#.\n\n#!14# holds up a syringe and inspects it again, while muttering \"still... problematic\". #!00# can smell the pre-cum from #!14#'s crotch.\n\n");
                    break;
                }
                if (iRet != 0) return iRet;

                // action dialog
                if (cAction == 0) // breasts
                {
                    switch (gpstructPC_Global.cBreastsValue)
                    {
                    case 0:
                        iRet = mdialog_addToDialogWithSrchRep ("\n[2 minutes later...]\n\n#!14# had finished injecting both of #!00#\'s nipples, and is currently stroking both of them with his fingers.\n\n");
                        break;

                    case 1:
                        iRet = mdialog_addToDialogWithSrchRep ("\n[2 minutes later...]\n\n#!14# had finished injecting both of #!00#\'s nipples again, and is currently stroking both of them with his fingers.\n\n");
                        break;

                    default:
                        iRet = mdialog_addToDialogWithSrchRep ("\n[5 minutes later...]\n\n#!14# had finished injecting both of #!00#\'s nipples again, and then #!14# continued with more injections into #!00#\'s breasts. #!14# is currently stroking both of #!00#\'s nipples with his fingers. This time #!00# is letting droplets of milk form around her erect nipples. #!14# grins when he sees the breast milk.\n\n");
                        break;
                    }

                    gpstructPC_Global.cBreastsValue++;
                }
                else // clitoris
                {
                    if (gpstructPC_Global.cClitorisValue == 0)
                        iRet = mdialog_addToDialogWithSrchRep ("\n[2 minutes later...]\n\n#!14# had finished injecting #!00#\'s clitoris, and is currently stroking it with his fingers.\n\n");
                    else
                        iRet = mdialog_addToDialogWithSrchRep ("\n[2 minutes later...]\n\n#!14# had finished injecting #!00#\'s clitoris again, and is currently stroking it with his fingers.\n\n");

                    gpstructPC_Global.cClitorisValue++;
                }
                if (iRet != 0) return iRet;

                // last part dialog
                switch (cEval1)
                {
                case 0:
                    iRet = mdialog_addToDialogWithSrchRep ("#!00# notices the spot of wetness on #!14#\'s pants where the tip of his penis is pressing against and is obviously leaking pre-cum. #!00# starts to ask \"How is\".\n\n#!14# finishes stroking #!00#, and interjects again \"Now, as your physician, it is necessary for you to return to continue your treatment\".\n\n#!00# cocks her head, and asks \"Treatment?\"\n\n#!14# continues \"Yes, this is necessary, for I am a physician. Now, I must continue to provide you with medical care\". #!14# then stands up, undoes his pants and reveals his erect cock.\n\n#!00# glances at #!14#\'s cock, licks her lips, then looks at his face, and asks \"Okay, so how\".\n\n#!14# interjects again \"I must confirm your progression, therefore, we must engage in energetic physical activities\".\n\n#!00# decides that she has had enough listening to #!14#, so she starts to suck and lick his cock.\n\n#!14# continues \"Yes, like that\".");
                    break;

                case 1:
                    iRet = mdialog_addToDialogWithSrchRep ("#!00# starts to ask \"Is that\".\n\n#!14# finishes stroking #!00#, and interjects again \"It is necessary to verify your progress\". #!14# stands up and undoes his pants. #!14# starts talking again \"This is all for\".\n\n#!00# decides to interrupt #!14# this time, and proceeds to suck and lick his erect penis.\n\n#!14# tries to continue talking \"Yes... medical... science\".");
                    break;

                case 2:
                    iRet = mdialog_addToDialogWithSrchRep ("While #!14# continues pawing #!00#, #!00# considers the fact that #!14# does not like to be interrupted. #!14# should stop by himself.\n\n#!14# finishes stroking #!00#, and talks at her again \"There... Now, to verify your progress\". #!14# stands up and undoes his pants.\n\nThis time #!00# decides to start by grabbing #!14#'s penis with her right hand, and and starts massaging the swollen tip with her right index finger and right thumb.\n\n#!14#\'s facial expression cannot hide his pleasure. But, there is a slight amount of anger shown on #!14#\'s face as well. Manages to #!14# utter the word \"mouth\", as #!00# keeps #!14# on the verge of climaxing with just her fingers alone.\n\n#!00# smiles, leans forward, kisses the tip of #!14#\'s cock, opens her mouth, then catches his ejaculation in her mouth as she makes him climax with her right fingers alone.\n\nExhausted, #!14# collapses back in his chair. #!00# licks her lips and then starts sucking #!14#\'s cock again.\n\nNow it is #!00#\'s turn.");
                    break;

                case 3:
                    iRet = mdialog_addToDialogWithSrchRep ("#!00# patiently waits for #!14# to stop touching her. At least #!14# is predictable.\n\n#!14# finishes stroking #!00#, and talks at her again \"Now, to verify... progress\". #!14# stands up and undoes his pants. #!00# is about to grab #!14#'s cock with her hand, when #!14# utters the word \"mouth\".\n\n#!00# grins, and replies \"Very well\". #!00# then swallows #!14#'s cock with her mouth, while also working his balls with her fingers.");
                    break;

                default: // case 4:
                    iRet = mdialog_addToDialogWithSrchRep ("#!14# stops petting #!00#, stands up, undoes his pants, and mutters \"verify\".\n\n#!00# glances at the pre-cum dribbling from the tip of #!14#\'s cock, and comes to the conclusion that #!14# has pretty much lost it. As #!00# swallows #!14#\'s penis and immediately backs off stimulating him, to not make #!14# cum his brains out, #!00# decides to fuck some sense into #!14#.\n\nAfter all, #!14# is now #!00#\'s patient.");
                    break;
                }
                if (iRet != 0) return iRet;

                iRet = mdialog_addToDialogWithSrchRep ("\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (1, 80);
                // Note: I reduced the increment value so that people playing on hard mode will have a chance.

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (1);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }
        }

        iRet = statedata_nameLocalNPCs (19);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;
    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Warehouse
//
int gamelogic02_scene1027 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Warehouse\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the warehouse.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 7;
        gpstructPC_Global.cLocationId = 20;

        iRet = statedata_nameLocalNPCs (20);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the warehouse");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the warehouse", 1027, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the warehouse", 1027, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the warehouse\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the warehouse\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the warehouse.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 21;

        iRet = statedata_nameLocalNPCs (21);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around inside the warehouse");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the warehouse storage area", 1027, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the breakroom in the warehouse", 1027, 12);
        if (iRet != 0) return iRet;
        return 0;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the warehouse storage area\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the breakroom in the warehouse\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 22;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the breakroom, at the warehouse.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (22);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Brewery
//
int gamelogic02_scene1028 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Brewery\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the brewery.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 8;
        gpstructPC_Global.cLocationId = 23;

        iRet = statedata_nameLocalNPCs (23);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the brewery");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the brewery", 1028, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the brewery", 1028, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the brewery\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the brewery\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the brewery.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 24;

        iRet = statedata_nameLocalNPCs (24);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around inside the brewery");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the inside the brewery", 1028, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the bunk room in the brewery", 1028, 12);
        if (iRet != 0) return iRet;
        return 0;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the inside the brewery\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the bunk room in the brewery\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 25;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the bunk room, at the brewery.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (25);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Tavern
//
int gamelogic02_scene1029 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Tavern\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the tavern.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 9;
        gpstructPC_Global.cLocationId = 26;

        iRet = statedata_nameLocalNPCs (26);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the tavern");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the tavern", 1029, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the tavern", 1029, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the tavern\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the tavern\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the main hall of the tavern.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 27;

        iRet = statedata_nameLocalNPCsx2 (27, 28);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay in the main hall of the tavern");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the tavern main hall", 1029, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go behind the bar in the tavern", 1029, 12);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the tavern keeper\'s room", 1029, 13);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the whore\'s room", 1029, 14);
        if (iRet != 0) return iRet;
        return 0;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the tavern main hall\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Go behind the bar in the tavern\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 28;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is behind the bar, at the tavern.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 28(A): %d, %d, %d\n", (int)gpstructNPC_Base[20].cLocationId, (int)gpstructPC_Global.cClothesValue, (int)gpstructNPC_Base[20].cNameToFaceFlag);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        // I wrote the below event before writing any sub-functions to check to see if a NPC is the only NPC at a location.
        //  It did not make sense to use such a function for this event, because the scheduler values are set, says that
        //  only one NPC is going ever be behind the bar (not via code, but by configuration).

        // let's start by checking to see if Izaiah is behind the bar, and if Bunny is still wearing her normal clothing.
        if ((gpstructNPC_Base[20].cLocationId == 28) && (gpstructPC_Global.cClothesValue == 0) && (gpstructNPC_Base[20].cNameToFaceFlag != 0))
        {
            // prioritize the NPC interaction with the PC.
            statedata_prioritizeNPCs (gpstructPC_Global.cLocationId, gpstructPC_Global.cAreaId);
            // this loads up the sort list, and also populates a variable.

#ifdef BMPS_LVL2_DEBUG
            if (gcDebugFlag != 0)
            {
                char szWorking[400];

                sprintf (szWorking, "(debug) Loc 28(B): %d, %d\n", (int)gsNPC_PriorityUsed, (int)gpstructNPC_Priority[0].sOffset);
                iRet = mdialog_addToDialogWithSrchRep (szWorking);
                if (iRet != 0) return iRet;
            }
#endif // BMPS_LVL2_DEBUG

            // if we have a populated priority list.
            if (gsNPC_PriorityUsed > 0)
            {
                // and (21 - 1 = 20) Izaiah is at the top of the list
                if (gpstructNPC_Priority[0].sOffset == 20)
                {
                    iRet = mdialog_addToDialogWithSrchRep ("\n\nThe hubbub in the tavern suddenly trails off. #!00# wonders what is going on.\n\nThen, #!21# turns to look at #!00#, and says \"What are you doing here?\"\n\n#!00# finds the question rather strange. Before #!00# can respond, #!21# reaches out and quickly rips the bunny suit off of #!00#.\n\nBefore #!00# realizes what had just happened, #!21# looks at the crowd in the tavern, while still holding the #!00#\'s shredded garment in his right hand, and proclaims \"Yeah... YEAH... THIS is how we roll!\"\n\n");
                    if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
                    iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-Tavern1-by-Inkeranon.jpg\" /></center><br/>\n");
                    if (iRet != 0) return iRet;
#endif

                    iRet = mdialog_addToDialogWithSrchRep ("The other occupants of the tavern start cheering. #!00# briefly looks at the destroyed bunny suit and contemplates that it is a shame, as she looked good in that. #!00# then focuses on #!21#\'s obvious erection straining against his pants.\n\n#!21# turns to look at #!00#, to find... that she isn't there. He is briefly perplexed before hearing a tearing sound from below his waist, as #!00# rips off #!21#\'s pants to get at his cock.\n\n#!21# looks down and exclaims \"What the FUCK...\", just as #!00# starts giving him a blowjob underneath the tavern counter. #!21# tries to maintain his composure as #!00# skillfully works his dick.\n\n#!21# takes a deep breath, looks at the crowd and proclaims \"This round... is on... the FUCKING house\". #!00# continues to lick and suck #!21#'s cock, as the crowd cheers, and #!21# serves more ales.\n\n\n[A while later...]\n\n");
                    if (iRet != 0) return iRet;

                    // change the clothes value..
                    gpstructPC_Global.cClothesValue = 1;
                    // some other events are going to trigger off of this being non-zero.

                    // this is how the values are increased for the stored parameters (also resets the energy value).
                    statedata_incrementPrioritizedNPCs (1, 150);

                    // this function highlights if there are many/any changes with the participating NPCs.
                    iRet = statedata_showNPCChanges (1);
                    if (iRet != 0) return iRet;

                    // call across to the navigation setup
                    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                    return iRet;
                }
            }
        }

        iRet = statedata_nameLocalNPCsx2 (27, 28);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 13:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the tavern keeper\'s room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 29;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside of the tavern keeper\'s room, at the tavern.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (29);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 14:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the whore\'s room\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 30;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside of the whore\'s room, at the tavern.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (30);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Kitchen
//
int gamelogic02_scene1030 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Kitchen\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the kitchen.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 10;
        gpstructPC_Global.cLocationId = 31;

        iRet = statedata_nameLocalNPCs (31);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside the kitchen");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the kitchen", 1030, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the kitchen", 1030, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the beggar\'s shanty next to the kitchen", 1030, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the kitchen\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the kitchen\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the kitchen.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 32;

        iRet = statedata_nameLocalNPCs (32);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around inside the kitchen");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around inside the kitchen", 1030, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the apartment above the kitchen", 1030, 12);
        if (iRet != 0) return iRet;
        return 0;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the beggar\'s shanty next to the kitchen\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 34;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside of the beggar\'s shanty, near the kitchen.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (34);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around inside the kitchen\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the apartment above the kitchen\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 33;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the apartment above the kitchen.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (33);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Workshop
//
int gamelogic02_scene1031 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Workshop\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the workshop.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 11;
        gpstructPC_Global.cLocationId = 35;

        iRet = statedata_nameLocalNPCs (35);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the workshop");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the workshop", 1031, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the workshop", 1031, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the workshop\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the workshop\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the workshop.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 36;

        iRet = statedata_nameLocalNPCs (36);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around the workshop");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around inside the workshop", 1031, 11);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the apartment above the workshop", 1031, 12);
        if (iRet != 0) return iRet;
        return 0;

    case 11:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around inside the workshop\n\n");
        if (iRet != 0) return iRet;
        break;

    case 12:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the apartment above the workshop\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 37;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the apartment above the workshop.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 37(A): %d, %d\n", (int)gpstructPC_Global.cDildoValue, (int)gpstructNPC_Base[26].cNameToFaceFlag);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        if ((gpstructPC_Global.cDildoValue == 1) && (gpstructNPC_Base[26].cNameToFaceFlag != 0))
        {
            iRet = statedata_specificNPCOnlyNPCAtLocation (27, 37);
            if (iRet == 1)
            {
                // unlock Viktor.
                gpstructNPC_Base[26].cInteractionLockFlag = 0; // 27 - 1 = Viktor

                // I am going to hard code the priority list.
                statedata_manualNPCPriority (27);
                // this means I can reuse the code to increment the NPC values, and take care of showing the changes.

                iRet = mdialog_addToDialogWithSrchRep ("\n\n#!27# looks at #!00#\'s crotch, and just keeps staring at it. #!00# notices that #!27# is concentrating only on her pussy, and asks \"Do you see something that you like?\"\n\n#!27# replies, without looking at #!00#\'s face, \"I see poo... crap... shit\". Finally, #!27# looks at #!00#\'s face, and continues \"A polished turd\".\n\n#!00# does her best to not roll her eyes, and asks #!27# \"Should I, come back... some other time?\"\n\n#!27# sighs, then says \"Sorry... I didn't mean you... I meant those... things\".\n\n#!00# glances down and realizes that #!27# was referring to the dildos.\n\n#!27# continues \"#!60#... has awful ideas, I mean... they are... static... he could not grasp the very CONCEPT\".\n\n#!00# inquires \"Static?... Concept?\"\n\n#!27# exclaims \"Yes... stationary... motionless... USELESS\".\n\n#!00# laments that when #!01# told her that #!27# was slightly insane, she should have asked for more detail.\n\n#!27# then grins, and states \"I can... do better\".\n\n#!00# looks at #!27#\'s smile, and utters \"Okay\".\n\n\n[10 minutes later...]\n\n#!00# considers that when #!27# said that he could \'do better\', he wasn't kidding. #!00# looks at #!27# and states \"I must admit, I am impressed... and you call... these?\"\n\n#!27# interjects \"Vibrators... because, you know... they vibrate\".\n\n#!00# glances down at the new vibrating dildos that #!27# gave her, and makes a mental note that she needs to remember to call them \'vibrators\' whenever around #!27#. #!00# then remembers something, and asks #!27# \"Do I need to give you something in return for these... vibrators?\"\n\n#!27# looks away from #!00#, with a slightly perplexed expression on his face, and says \"something in return... fuck... I hadn\'t thought of that\".\n\n#!00# smiles, because she is amused and not because of the pleasure she is feeling, and calls out to #!27# \"Hey, how about I give you a nice blowjob\".\n\n#!27# thinks about it \"A blowjob?... I don\'t know\".\n\n#!00# continues \"I will use my tits as well\".\n\n#!27# smiles, looks at #!00# and exclaims \"Like a fleshlight... hell yeah\".\n\n#!00# smiles and struts over to #!27#\'s, putting aside that she has no idea what a \'fleshlight\' is, but she can find that out later. Right now she just needs to wring some sperm out of #!27#\'s cock.\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // change the dildo value..
                gpstructPC_Global.cDildoValue = 2;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (1, 120);

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (1);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }
        }

        iRet = statedata_nameLocalNPCs (37);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Goat corral
//
int gamelogic02_scene1032 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Goat corral\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the goat corral.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 12;
        gpstructPC_Global.cLocationId = 38;

        iRet = statedata_nameLocalNPCsx2 (38, 39);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the goat corral");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the goat corral", 1032, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Jump the fence into the goat corral", 1032, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the goat corral", 1032, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the goat corral\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Jump the fence into the goat corral\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 39;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the goat corral.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCsx2 (38, 39);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the goat corral\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 40;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the goat corral.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (40);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Lumber mill
//
int gamelogic02_scene1033 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Lumber mill\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is next the lumber mill.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 13;
        gpstructPC_Global.cLocationId = 41;

        iRet = statedata_nameLocalNPCs (41);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the lumber mill");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the lumber mill", 1033, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the lumber mill", 1033, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the lumber mill\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the lumber mill\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 42;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the lumber mill.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (42);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Forest edge
//
int gamelogic02_scene1034 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Forest edge\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is near the edge of the forest.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 14;
        gpstructPC_Global.cLocationId = 43;

        iRet = statedata_nameLocalNPCs (43);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay at the edge of the forest");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the edge of the forest", 1034, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Venture into the forest", 1034, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the edge of the forest", 1034, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the edge of the forest\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Venture into the forest\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 45;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the forest.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (45);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the edge of the forest\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 44;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack near the edge of the forest.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (44);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Target range
//
int gamelogic02_scene1035 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Target range\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the target range.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 15;
        gpstructPC_Global.cLocationId = 46;

        iRet = statedata_nameLocalNPCsx2 (46, 47);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the target range");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around outside the target range", 1035, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Jump the fence into the target range", 1035, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the target range", 1035, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around outside the target range\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Jump the fence into the target range\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 47;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the target range.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCsx2 (46, 47);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the target range\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 48;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the target range.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (48);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Lake edge
//
int gamelogic02_scene1036 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Lake edge\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is near the edge of the lake.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 16;
        gpstructPC_Global.cLocationId = 49;

        iRet = statedata_nameLocalNPCs (49);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay near the edge of the lake");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the lake edge", 1036, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the edge of the lake", 1036, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the lake edge\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the edge of the lake\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 50;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the lake.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (50);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Northern farm
//
int gamelogic02_scene1037 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Northern farm\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is at the edge of the northern farm.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 17;
        gpstructPC_Global.cLocationId = 51;

        iRet = statedata_nameLocalNPCs (51);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay at the edge of the northern farm");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the northern farm", 1037, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the northern farm", 1037, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the northern farm\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the northern farm\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 52;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the northern farm.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 52(A): %d, %d, %d, %d, %d\n", (int)gpstructNPC_Base[46].cInteractionLockFlag, (int)gpstructNPC_Base[47].cInteractionLockFlag, (int)gpstructPC_Global.cBreastsValue, (int)gpstructNPC_Base[46].cNameToFaceFlag, (int)gpstructNPC_Base[47].cNameToFaceFlag);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        // this situation is only evaluated, for this location, if the two farmers are locked, and the PC's breasts are max size/modified.
        if ((gpstructNPC_Base[46].cInteractionLockFlag != 0) &&
                (gpstructNPC_Base[47].cInteractionLockFlag != 0) &&
                (gpstructPC_Global.cBreastsValue >= 3) &&
                (gpstructNPC_Base[46].cNameToFaceFlag != 0) &&
                (gpstructNPC_Base[47].cNameToFaceFlag != 0))
        {
            // unlock the two farmers (this could be permanent)
            gpstructNPC_Base[46].cInteractionLockFlag = 0; // 47 - 1 = Melvin
            gpstructNPC_Base[47].cInteractionLockFlag = 0; // 48 - 1 = Gary

            // the hack here, is to unlock the 2 farmers, create the priority list, and see if it is only
            //  2 farmers on the list. If we do not pass the entry requirements, the 2 farmers are locked
            //  again, before executing the normal evaluation code..

            // prioritize the NPC interaction with the PC.
            statedata_prioritizeNPCs (gpstructPC_Global.cLocationId, gpstructPC_Global.cAreaId);
            // this loads up the sort list, and also populates a variable.

#ifdef BMPS_LVL2_DEBUG
            if (gcDebugFlag != 0)
            {
                char szWorking[400];

                sprintf (szWorking, "(debug) Loc 52(B): %d, %d, %d\n", (int)gsNPC_PriorityUsed, (int)gpstructNPC_Priority[0].sOffset, (int)gpstructNPC_Priority[1].sOffset);
                iRet = mdialog_addToDialogWithSrchRep (szWorking);
                if (iRet != 0) return iRet;
            }
#endif // BMPS_LVL2_DEBUG

            // if we have a populated priority list. 47 - 1 = Melvin. 48 - 1 = Gary
            if ((gsNPC_PriorityUsed == 2) &&
                    ((gpstructNPC_Priority[0].sOffset == 46) || (gpstructNPC_Priority[0].sOffset == 47)) &&
                    ((gpstructNPC_Priority[1].sOffset == 46) || (gpstructNPC_Priority[1].sOffset == 47)))
            {
                // I don't have to unlock the 2 farmers again, this change is permanent.

                iRet = mdialog_addToDialogWithSrchRep ("\n\n#!00# enters the shack, and looks around. Both #!48# and #!47# are there. #!48# and #!47# look at each other, then at #!00#. #!47# talks to #!00# \"Nice pair of udders you have there missy\".\n\n#!00# is perplexed, then she looks down and remembers that she made her breasts larger, to convince #!14# that the stuff that he was injecting her with had some effect.\n\n#!00# glances at #!47#, then looks at #!48#. #!48# talks next \"I reckon we have ourselves a new cow\".\n\n#!47# nods in agreement, and says \"Mmm Hmm... looks like milkin\' time\".\n\n#!48# replies with a simple \"Yup\".\n\n#!00# smiles, as she remembered that #!01# mentioned something about these two having some weird \'dairy farmer\' fetish. #!00# asks \"Okay, so... how do we go about this?\"\n\n\n[5 minutes later...]\n\n#!47# is to #!00#\'s right, sucking on #!00#\'s right breast, while #!00# is stroking his cock with her right hand. #!48# is #!00#\'s left, doing the same to #!00#\'s left breast, while #!00#\'s left hand is working #!47#\'s penis.\n\n#!00# smiles as she lets out some breast milk, while the two men eagerly lap it up and ejaculate almost simultaneously. #!00# notices that most of the semen was wasted, so she will have to change things around a bit.\n\n#!00# decides that she is going to have to train her two new \'sperm cows\' to do this properly.\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (2, 200);

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (2);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }

            // re-lock the two farmers
            gpstructNPC_Base[46].cInteractionLockFlag = 1; // 47 - 1 = Melvin
            gpstructNPC_Base[47].cInteractionLockFlag = 1; // 48 - 1 = Gary
        }

        iRet = statedata_nameLocalNPCs (52);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Eastern farm
//
int gamelogic02_scene1038 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Eastern farm\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is at the edge of the eastern farm.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 18;
        gpstructPC_Global.cLocationId = 53;

        iRet = statedata_nameLocalNPCs (53);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay at the edge of the eastern farm");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the eastern farm", 1038, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the eastern farm", 1038, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the eastern farm\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the eastern farm\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 54;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the eastern farm.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (54);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Southern farm
//
int gamelogic02_scene1039 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Southern farm\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is at the edge of the southern farm.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 19;
        gpstructPC_Global.cLocationId = 55;

        iRet = statedata_nameLocalNPCs (55);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay at the edge of the southern farm");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the southern farm", 1039, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the southern farm", 1039, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the southern farm\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the southern farm\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 56;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the southern farm.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (56);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Western farm
//
int gamelogic02_scene1040 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Western farm\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is at the edge of the western farm.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 20;
        gpstructPC_Global.cLocationId = 57;

        iRet = statedata_nameLocalNPCs (57);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay at the edge of the western farm");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Hang around the western farm", 1040, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the shack next to the western farm", 1040, 2);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Hang around the western farm\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the shack next to the western farm\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 58;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the shack next to the western farm.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (58);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Procurer's shack
//
int gamelogic02_scene1041 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Procurer\'s shack\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the procurer\'s shack.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 21;
        gpstructPC_Global.cLocationId = 59;

        iRet = statedata_nameLocalNPCs (59);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to hang around outside of the procurer\'s shack");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the procurer\'s shack", 1041, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the procurer\'s shack", 1041, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the thug\'s shanty next to the procurer\'s shack", 1041, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the procurer\'s shack\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the procurer\'s shack\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 60;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the procurer\'s shack.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 60(A): %d, %d\n", (int)gpstructPC_Global.cClothesValue, (int)gpstructNPC_Base[56].cNameToFaceFlag);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        if ((gpstructPC_Global.cClothesValue == 1) && (gpstructNPC_Base[56].cNameToFaceFlag != 0))
        {
            iRet = statedata_specificNPCOnlyNPCAtLocation (57, 60);
            if (iRet == 1)
            {
                // unlock Marcel.
                gpstructNPC_Base[56].cInteractionLockFlag = 0; // 57 - 1 = Marcel

                // I am going to hard code the priority list.
                statedata_manualNPCPriority (57);
                // this means I can reuse the code to increment the NPC values, and take care of showing the changes.

                iRet = mdialog_addToDialogWithSrchRep ("\n\nAs #!00# enters the shack, #!57# takes just one look at #!00#, then says \"So, there was truth to that... information\".\n\n#!00# looks at #!57#, unsure how to respond. #!00# then notices that #!57# is staring at her naked body. #!00# glances down at her exposed breasts, then looks at #!57# again.\n\n#!57#, without taking his eyes off of #!00#, talks again \"Well... Miss... Mayoress... I think I have something for you\".\n\n\n[5 minutes later...]\n\n#!00# is now wearing an black leather open cup bustier. #!00# isn\'t surprised that #!57# has something like this, considering she was told by #!01# that #!57# took care of dressing up all of the previous women that #!65# had \'chewed up and spat out\' in the past.\n\nWhile #!00# considers the fact that the leather garment isn\'t going to get in the way of her wings, #!57# talks to #!00# again \"Now... for the not so minor matter... of payment\".\n\n");
                if (iRet != 0) return iRet;

#ifndef INTERFACE_CURSES
                iRet = mutils_addToDialogBuffer ("<center><img src=\"images/BMPS-Bustier1-by-Inkeranon.jpg\" /></center><br/>\n");
                if (iRet != 0) return iRet;
#endif

                iRet = mdialog_addToDialogWithSrchRep ("#!00# looks at #!57#, cocks her head, and inquires \"Payment?\"\n\n#!57# undoes his pants, lets them drop to the floor, revealing his erect cock. Then #!57# continues talking \"I can\'t get it up unless there is leather involved\".\n\n#!00# smiles, and responds \"Sure\".\n\n#!00# strides over to #!57#, squats down and immediately starts giving him a blowjob.\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // change the clothes value..
                gpstructPC_Global.cClothesValue = 2;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (1, 150);

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (1);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }
        }

        iRet = statedata_nameLocalNPCs (60);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the thug\'s shanty next to the procurer\'s shack\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 61;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the thug\'s shanty, next to procurer\'s shack.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (61);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

//
// Smuggler's shack
//
int gamelogic02_scene1042 (int iSubSceneId, char cSubFlag)
{
    int iRet;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    switch (iSubSceneId)
    {
    case 0:
        iRet = mdialog_addToDialogWithSrchRep (">Smuggler\'s shack\n\n");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is outside of the smuggler\'s shack.");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cAreaId = 22;
        gpstructPC_Global.cLocationId = 62;

        iRet = statedata_nameLocalNPCs (62);
        if (iRet == 1) return 1;
        if (iRet == 10)
        {
            iRet = mdialog_addToDialogWithSrchRep (" #!00# decides to stay outside of the smuggler\'s shack");
            if (iRet != 0) return iRet;
            iRet = gamelogic02_newNPCDialog ();
            if (iRet != 0) return iRet;

            break;
        }
        else
        {
            if (iRet == 6)
            {
                iRet = gamelogic02_noNPCDialog ();
                if (iRet != 0) return iRet;
            }
            iRet = mdialog_addToDialogWithSrchRep (" What should #!00# do?\n\n");
            if (iRet != 0) return iRet;
        }

        iRet = mutils_addToCommandList ("Stay outside the smuggler\'s shack", 1042, 1);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Go inside the smuggler\'s shack", 1042, 2);
        if (iRet != 0) return iRet;
        iRet = mutils_addToCommandList ("Visit the bandit\'s shanty next to the smuggler\'s shack", 1042, 3);
        if (iRet != 0) return iRet;
        return 0;

    case 1:
        iRet = mdialog_addToDialogWithSrchRep (">Stay outside the smuggler\'s shack\n\n");
        if (iRet != 0) return iRet;
        break;

    case 2:
        iRet = mdialog_addToDialogWithSrchRep (">Go inside the smuggler\'s shack\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 63;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the smuggler\'s shack.");
        if (iRet != 0) return iRet;

#ifdef BMPS_LVL2_DEBUG
        if (gcDebugFlag != 0)
        {
            char szWorking[400];

            sprintf (szWorking, "\n(debug) Loc 63(A): %d, %d, %d\n", (int)gpstructPC_Global.cClothesValue, (int)gpstructNPC_Base[59].cNameToFaceFlag, (int)gpstructPC_Global.cDildoValue);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
#endif // BMPS_LVL2_DEBUG

        if ((gpstructPC_Global.cClothesValue != 0) && (gpstructNPC_Base[59].cNameToFaceFlag != 0) && (gpstructPC_Global.cDildoValue == 0))
        {
            iRet = statedata_specificNPCOnlyNPCAtLocation (60, 63);
            if (iRet == 1)
            {
                // unlock Fabian.
                gpstructNPC_Base[59].cInteractionLockFlag = 0; // 60 - 1 = Fabian

                // I am going to hard code the priority list.
                statedata_manualNPCPriority (60);
                // this means I can reuse the code to increment the NPC values, and take care of showing the changes.

                iRet = mdialog_addToDialogWithSrchRep ("\n\nAs #!00# enters the shack, #!60# looks at #!00#. More specifically, #!60# is staring at #!00#\'s exposed pussy.\n\n#!00# looks down, then at #!60#, and talks to #!60# while fingering herself \"Do you see something that you like?... Does this make you hard?\"\n\n#!60# glances at #!00#\'s face, smirks, then says \"Maybe, but I want my dick to be as hard as diamonds\".\n\n#!00# replies \"Oh... So, tell me... What turns you on?\", and grins, as she already heard about #!60# from #!01#.\n\n\n[2 minutes later...]\n\n#!00# has a dildo stuffed in her pussy, and another in her anus. She received both of them from #!60#. #!00# is still fingering herself, to showoff to #!60#. #!00# then looks at #!60# and asks \"So, I am to keep these?\"\n\n#!60# looks at #!00#, nods with approval, and says \"Yeah, always use them... that is what I am talkin\' about.\". #!60# then undoes his pants, and continues \"Now, get over here and suck my cock, bitch\".\n\n#!00# grins, and replies \"Very well\", then takes the 2 steps towards #!60#, crouches down, and proceeds to vacuum suck #!60#'s cock.\n\n#!60# grabs #!00#\'s head, starts thrusting away, and proclaims \"Yeah, that\'s it\". Meanwhile, #!00# considers that #!01#\'s penis is usually harder than this, but who cares if she gets to feed on #!60#\'s sperm.\n\n\n[A while later...]\n\n");
                if (iRet != 0) return iRet;

                // change the dildo value..
                gpstructPC_Global.cDildoValue = 1;

                // this is how the values are increased for the stored parameters (also resets the energy value).
                statedata_incrementPrioritizedNPCs (1, 150);

                // this function highlights if there are many/any changes with the participating NPCs.
                iRet = statedata_showNPCChanges (1);
                if (iRet != 0) return iRet;

                // call across to the navigation setup
                iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
                return iRet;
            }
        }

        iRet = statedata_nameLocalNPCs (63);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    case 3:
        iRet = mdialog_addToDialogWithSrchRep (">Visit the bandit\'s shanty next to the smuggler\'s shack\n\n");
        if (iRet != 0) return iRet;

        gpstructPC_Global.cLocationId = 64;

        iRet = mdialog_addToDialogWithSrchRep ("#!00# is inside the bandit\'s shanty, next to smuggler\'s shack.");
        if (iRet != 0) return iRet;

        iRet = statedata_nameLocalNPCs (64);
        if (iRet == 1) return 1;
        iRet = mdialog_addToDialogWithSrchRep ("\n\n");
        if (iRet != 0) return iRet;

        break;

    }

    // if we reach here, we are processing this encounter.
    iRet = gamelogic02_encounterProcess ();
    if (iRet != 0) return iRet;

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (0, cSubFlag + 1);
    return iRet;
}

