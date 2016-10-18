//
// gamelogic03.c
//
// This is group 3 of scene ids.
//
// Essentially, this is the all of the inventory management of the game
// (which is rather limited).
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"

// external linkage to the game variables.
extern  char    gcDebugFlag;
extern struct  statedata_Locations gstructLocationList[];
extern struct  statedata_NPCData *gpstructNPC_Base;
extern struct  statedata_GlobalData gpstructPC_Global;
extern  struct  mdialog_searchreplacelist gstructSrchRepList[];


//
// Access the hint screen.
//
int gamelogic03_scene1061 (int iSubSceneId, char cSubFlag)
{
    int iRet;
    char szWorking[400];
    short sOffset1;
    short sOffset2;
    int iUnknownCount;
    int iPartialKnownCount;
    int iCount;
    int iKnownCount;
    int iTrustCount;
    int iObedientCount;
    int iCountDown;

    if (cSubFlag > MAXGAMESCENENESTS)
        return 101;

    if (cSubFlag == 0)
    {
        iRet = mutils_addToDialogBuffer (">Give me a hint\n\n");
        if (iRet != 0) return iRet;
    }

    if (gcDebugFlag != 0)
    {
        iRet = mutils_addToDialogBuffer ("-- NPCs with a * after their names are sleeping. NPCs with a # are low on energy. NPCs with $ are locked.\n\n");
        if (iRet != 0) return iRet;
    }

    // for loop to go through each area group.
    for (sOffset1 = 0; sOffset1 < 22; sOffset1++)
    {
        iCount = 0;
        iKnownCount = 0;
        iTrustCount = 0;
        iObedientCount = 0;

        if (gcDebugFlag == 0)
        {
            // ignore the current area.
            if ((char)(sOffset1 + 1) == gpstructPC_Global.cAreaId)
                continue;
        }
        else
        {
            iUnknownCount = 0;
            iPartialKnownCount = 0;
        }

        // first pass is to count the number of NPCs at a given location.
        for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
        {
            // ignore NPCs who are not in the area we are scanning.
            if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                continue;

            // if this NPC is hidden, then don't include them.
            if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                continue;
            // if the NPC is hidden, then the PC cannot interact with them anyway..

            // only ignore these conditions if we are NOT in debug mode.
            if (gcDebugFlag == 0)
            {
                // ignore NPCs who we haven't been introduced to yet.
                if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                    continue;

                // ignore NPCs who we don't fully know yet.
                if (gpstructNPC_Base[sOffset2].iKnownValue < STATEDATA_KNOWNMAX)
                    continue;
            }

            // we count/enable this area.
            iCount++;

            // count these conditions if we are in debug mode.
            if (gcDebugFlag != 0)
            {
                if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                {
                    iUnknownCount++;
                    continue;
                }

                if (gpstructNPC_Base[sOffset2].iKnownValue < STATEDATA_KNOWNMAX)
                {
                    iPartialKnownCount++;
                    continue;
                }
            }

            if (gpstructNPC_Base[sOffset2].iObedienceValue >= STATEDATA_OBEDIENCEMAX)
                iObedientCount++;
            else if (gpstructNPC_Base[sOffset2].iTrustValue >= STATEDATA_TRUSTMAX)
                iTrustCount++;
            else
                iKnownCount++;
        }

        if (iCount == 0)
            continue;

        if (gcDebugFlag != 0)
        {
            if ((char)(sOffset1 + 1) == gpstructPC_Global.cAreaId)
            {
                iRet = mutils_addToDialogBuffer ("(blocked) ");
                if (iRet != 0) return iRet;
            }
        }

        switch (sOffset1)
        {
        case 0:
            iRet = mutils_addToDialogBuffer ("At the mayor\'s house, ");
            break;

        case 1:
            iRet = mutils_addToDialogBuffer ("At the constable\'s residence, ");
            break;

        case 2:
            iRet = mutils_addToDialogBuffer ("At the guard barracks, ");
            break;

        case 3:
            iRet = mutils_addToDialogBuffer ("At the moneylender\'s house, ");
            break;

        case 4:
            iRet = mutils_addToDialogBuffer ("At the merchant\'s house, ");
            break;

        case 5:
            iRet = mutils_addToDialogBuffer ("At the physician\'s residence, ");
            break;

        case 6:
            iRet = mutils_addToDialogBuffer ("At the warehouse, ");
            break;

        case 7:
            iRet = mutils_addToDialogBuffer ("At the brewery, ");
            break;

        case 8:
            iRet = mutils_addToDialogBuffer ("At the tavern, ");
            break;

        case 9:
            iRet = mutils_addToDialogBuffer ("At the kitchen, ");
            break;

        case 10:
            iRet = mutils_addToDialogBuffer ("At the workshop, ");
            break;

        case 11:
            iRet = mutils_addToDialogBuffer ("At the goat corral, ");
            break;

        case 12:
            iRet = mutils_addToDialogBuffer ("At the lumber mill, ");
            break;

        case 13:
            iRet = mutils_addToDialogBuffer ("At the forest, ");
            break;

        case 14:
            iRet = mutils_addToDialogBuffer ("At the target range, ");
            break;

        case 15:
            iRet = mutils_addToDialogBuffer ("At the lake, ");
            break;

        case 16:
            iRet = mutils_addToDialogBuffer ("At the northern farm, ");
            break;

        case 17:
            iRet = mutils_addToDialogBuffer ("At the eastern farm, ");
            break;

        case 18:
            iRet = mutils_addToDialogBuffer ("At the southern farm, ");
            break;

        case 19:
            iRet = mutils_addToDialogBuffer ("At the western farm, ");
            break;

        case 20:
            iRet = mutils_addToDialogBuffer ("At the procurer\'s shack, ");
            break;

        default:
            iRet = mutils_addToDialogBuffer ("At the smuggler\'s shack, ");
            break;
        }
        if (iRet != 0) return iRet;

        if (gcDebugFlag != 0)
        {
            if (iUnknownCount != 0)
            {
                iCountDown = iUnknownCount;

                for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
                {
                    // ignore NPCs who are not in the area we are scanning.
                    if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                        continue;

                    // if this NPC is hidden, then don't include them.
                    if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                        continue;

                    // ignore NPCs who we do know (by name).
                    if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 0)
                        continue;

                    iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset2 + 1].pszReplace);
                    if (iRet != 0) return iRet;

                    if (gcDebugFlag != 0)
                    {
                        if (gpstructNPC_Base[sOffset2].iEnergyValue < STATEDATA_ENERGYAVAIL)
                        {
                            iRet = mutils_addToDialogBuffer ("#");
                            if (iRet != 0) return iRet;
                        }
                        if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_SLP_D)
                        {
                            iRet = mutils_addToDialogBuffer ("*");
                            if (iRet != 0) return iRet;
                        }
                        if (gpstructNPC_Base[sOffset2].cInteractionLockFlag != 0)
                        {
                            iRet = mutils_addToDialogBuffer ("$");
                            if (iRet != 0) return iRet;
                        }
                    }

                    iCountDown--;

                    if (iCountDown == 1)
                        iRet = mutils_addToDialogBuffer (" and ");
                    else if (iCountDown != 0)
                        iRet = mutils_addToDialogBuffer (", ");
                    if (iRet != 0) return iRet;

                    if (iCountDown == 0)
                        break;
                }

                if (iUnknownCount == 1)
                    iRet = mutils_addToDialogBuffer (" is unknown");
                else
                    iRet = mutils_addToDialogBuffer (" are unknown");
                if (iRet != 0) return iRet;

                if ((iObedientCount == 0) && (iTrustCount == 0) && (iPartialKnownCount == 0) && (iKnownCount == 0))
                    iRet = mutils_addToDialogBuffer (".\n\n");
                else
                    iRet = mutils_addToDialogBuffer (", ");
                if (iRet != 0) return iRet;
            }

            if (iPartialKnownCount != 0)
            {
                iCountDown = iPartialKnownCount;

                for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
                {
                    // ignore NPCs who are not in the area we are scanning.
                    if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                        continue;

                    // if this NPC is hidden, then don't include them.
                    if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                        continue;

                    // ignore NPCs who we don't know yet.
                    if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                        continue;

                    // ignore NPCs who we fully know.
                    if (gpstructNPC_Base[sOffset2].iKnownValue >= STATEDATA_KNOWNMAX)
                        continue;

                    if (gcDebugFlag != 0)
                    {
                        sprintf (szWorking, "(%d/30)", gpstructNPC_Base[sOffset2].iKnownValue);
                        iRet = mutils_addToDialogBuffer (szWorking);
                        if (iRet != 0) return iRet;
                    }

                    iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset2 + 1].pszReplace);
                    if (iRet != 0) return iRet;

                    if (gcDebugFlag != 0)
                    {
                        if (gpstructNPC_Base[sOffset2].iEnergyValue < STATEDATA_ENERGYAVAIL)
                        {
                            iRet = mutils_addToDialogBuffer ("#");
                            if (iRet != 0) return iRet;
                        }
                        if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_SLP_D)
                        {
                            iRet = mutils_addToDialogBuffer ("*");
                            if (iRet != 0) return iRet;
                        }
                        if (gpstructNPC_Base[sOffset2].cInteractionLockFlag != 0)
                        {
                            iRet = mutils_addToDialogBuffer ("$");
                            if (iRet != 0) return iRet;
                        }
                    }

                    iCountDown--;

                    if (iCountDown == 1)
                        iRet = mutils_addToDialogBuffer (" and ");
                    else if (iCountDown != 0)
                        iRet = mutils_addToDialogBuffer (", ");
                    if (iRet != 0) return iRet;

                    if (iCountDown == 0)
                        break;
                }

                if (iPartialKnownCount == 1)
                    iRet = mutils_addToDialogBuffer (" is partially known");
                else
                    iRet = mutils_addToDialogBuffer (" are partially known");
                if (iRet != 0) return iRet;

                if ((iObedientCount == 0) && (iTrustCount == 0) && (iKnownCount == 0))
                    iRet = mutils_addToDialogBuffer (".\n\n");
                else
                    iRet = mutils_addToDialogBuffer (", ");
                if (iRet != 0) return iRet;
            }
        }

        if (iKnownCount != 0)
        {
            iCountDown = iKnownCount;

            for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
            {
                // ignore NPCs who are not in the area we are scanning.
                if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                    continue;

                // if this NPC is hidden, then don't include them.
                if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                    continue;

                // ignore NPCs who we don't know yet.
                if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                    continue;

                // ignore the NPCs that we don't know enough.
                if (gpstructNPC_Base[sOffset2].iKnownValue < STATEDATA_KNOWNMAX)
                    continue;

                // ignore the NPCs that we have maxed out the trust for.
                if (gpstructNPC_Base[sOffset2].iTrustValue >= STATEDATA_TRUSTMAX)
                    continue;

                if (gcDebugFlag != 0)
                {
                    sprintf (szWorking, "(%d/100)", gpstructNPC_Base[sOffset2].iTrustValue);
                    iRet = mutils_addToDialogBuffer (szWorking);
                    if (iRet != 0) return iRet;
                }

                iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset2 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (gcDebugFlag != 0)
                {
                    if (gpstructNPC_Base[sOffset2].iEnergyValue < STATEDATA_ENERGYAVAIL)
                    {
                        iRet = mutils_addToDialogBuffer ("#");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_SLP_D)
                    {
                        iRet = mutils_addToDialogBuffer ("*");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cInteractionLockFlag != 0)
                    {
                        iRet = mutils_addToDialogBuffer ("$");
                        if (iRet != 0) return iRet;
                    }
                }

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mutils_addToDialogBuffer (" and ");
                else if (iCountDown != 0)
                    iRet = mutils_addToDialogBuffer (", ");
                if (iRet != 0) return iRet;

                if (iCountDown == 0)
                    break;
            }

            if (iKnownCount == 1)
                iRet = mutils_addToDialogBuffer (" is known to ");
            else
                iRet = mutils_addToDialogBuffer (" are known to ");
            if (iRet != 0) return iRet;

            iRet = mutils_addToDialogBuffer (gstructSrchRepList[0].pszReplace);
            if (iRet != 0) return iRet;

            if ((iObedientCount == 0) && (iTrustCount == 0))
                iRet = mutils_addToDialogBuffer (".\n\n");
            else
                iRet = mutils_addToDialogBuffer (", while ");
            if (iRet != 0) return iRet;
        }

        if (iTrustCount != 0)
        {
            iCountDown = iTrustCount;

            for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
            {
                // ignore NPCs who are not in the area we are scanning.
                if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                    continue;

                // if this NPC is hidden, then don't include them.
                if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                    continue;

                // ignore NPCs who we don't know yet.
                if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                    continue;

                // ignore the NPCs that we haven't maxed out the trust for.
                if (gpstructNPC_Base[sOffset2].iTrustValue < STATEDATA_TRUSTMAX)
                    continue;

                // ignore the NPCs that we have maxed out the obedience for.
                if (gpstructNPC_Base[sOffset2].iObedienceValue >= STATEDATA_OBEDIENCEMAX)
                    continue;

                if (gcDebugFlag != 0)
                {
                    sprintf (szWorking, "(%d/200)", gpstructNPC_Base[sOffset2].iObedienceValue);
                    iRet = mutils_addToDialogBuffer (szWorking);
                    if (iRet != 0) return iRet;
                }

                iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset2 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (gcDebugFlag != 0)
                {
                    if (gpstructNPC_Base[sOffset2].iEnergyValue < STATEDATA_ENERGYAVAIL)
                    {
                        iRet = mutils_addToDialogBuffer ("#");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_SLP_D)
                    {
                        iRet = mutils_addToDialogBuffer ("*");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cInteractionLockFlag != 0)
                    {
                        iRet = mutils_addToDialogBuffer ("$");
                        if (iRet != 0) return iRet;
                    }
                }

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mutils_addToDialogBuffer (" and ");
                else if (iCountDown != 0)
                    iRet = mutils_addToDialogBuffer (", ");
                if (iRet != 0) return iRet;

                if (iCountDown == 0)
                    break;
            }

            if (iTrustCount == 1)
                iRet = mutils_addToDialogBuffer (" trusts ");
            else
                iRet = mutils_addToDialogBuffer (" trust ");
            if (iRet != 0) return iRet;

            iRet = mutils_addToDialogBuffer (gstructSrchRepList[0].pszReplace);
            if (iRet != 0) return iRet;

            if (iObedientCount == 0)
                iRet = mutils_addToDialogBuffer (".\n\n");
            else if (iKnownCount != 0)
                iRet = mutils_addToDialogBuffer (", and ");
            else
                iRet = mutils_addToDialogBuffer (", while ");
            if (iRet != 0) return iRet;
        }

        if (iObedientCount != 0)
        {
            iCountDown = iObedientCount;

            for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
            {
                // ignore NPCs who are not in the area we are scanning.
                if (gpstructNPC_Base[sOffset2].cAreaId != (char)(sOffset1 + 1))
                    continue;

                // if this NPC is hidden, then don't include them.
                if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_WRK_H)
                    continue;

                // ignore NPCs who we don't know yet.
                if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
                    continue;

                // ignore the NPCs that we haven't maxed out the obedience for.
                if (gpstructNPC_Base[sOffset2].iObedienceValue < STATEDATA_OBEDIENCEMAX)
                    continue;

                iRet = mutils_addToDialogBuffer (gstructSrchRepList[sOffset2 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (gcDebugFlag != 0)
                {
                    if (gpstructNPC_Base[sOffset2].iEnergyValue < STATEDATA_ENERGYAVAIL)
                    {
                        iRet = mutils_addToDialogBuffer ("#");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cActionId == STATEACTION_SLP_D)
                    {
                        iRet = mutils_addToDialogBuffer ("*");
                        if (iRet != 0) return iRet;
                    }
                    if (gpstructNPC_Base[sOffset2].cInteractionLockFlag != 0)
                    {
                        iRet = mutils_addToDialogBuffer ("$");
                        if (iRet != 0) return iRet;
                    }
                }

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mutils_addToDialogBuffer (" and ");
                else if (iCountDown != 0)
                    iRet = mutils_addToDialogBuffer (", ");
                if (iRet != 0) return iRet;

                if (iCountDown == 0)
                    break;
            }

            if ((iKnownCount != 0) && (iTrustCount != 0))
            {
                if (iObedientCount == 1)
                    iRet = mutils_addToDialogBuffer (" is obedient.\n\n");
                else
                    iRet = mutils_addToDialogBuffer (" are obedient.\n\n");
                if (iRet != 0) return iRet;
            }
            else
            {
                if (iObedientCount == 1)
                    iRet = mutils_addToDialogBuffer (" obeys ");
                else
                    iRet = mutils_addToDialogBuffer (" are obedient to ");
                if (iRet != 0) return iRet;

                iRet = mutils_addToDialogBuffer (gstructSrchRepList[0].pszReplace);
                if (iRet != 0) return iRet;

                iRet = mutils_addToDialogBuffer (".\n\n");
                if (iRet != 0) return iRet;
            }
        }
    }

    if (gcDebugFlag == 0)
    {
        iUnknownCount = 0;
        iPartialKnownCount = 0;

        // pass to count the unknown and partial-known NPCs.
        for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
        {
            // count NPCs who we haven't been introduced to yet.
            if (gpstructNPC_Base[sOffset2].cNameToFaceFlag != 1)
            {
                iUnknownCount++;
                continue;
            }

            // count NPCs who we don't fully know yet.
            if (gpstructNPC_Base[sOffset2].iKnownValue < STATEDATA_KNOWNMAX)
                iPartialKnownCount++;
        }

        if ((iUnknownCount != 0) && (iPartialKnownCount != 0))
        {
            sprintf (szWorking, "There are %d unknown and another %d partially known villagers in #!65#.\n\n", iUnknownCount, iPartialKnownCount);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
        else if (iUnknownCount != 0)
        {
            sprintf (szWorking, "There are %d unknown villagers in #!65#.\n\n", iUnknownCount);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }
        else if (iPartialKnownCount != 0)
        {
            sprintf (szWorking, "There are %d partially known villagers in #!65#.\n\n", iPartialKnownCount);
            iRet = mdialog_addToDialogWithSrchRep (szWorking);
            if (iRet != 0) return iRet;
        }

        // if easy.. at least 1/2 of the time for this function.
        if (gpstructPC_Global.cDifficultyLevel == 1)
            gpstructPC_Global.cHintCountDown = 2;
        // if medium.. at least 1/4 of the time for this function.
        else if (gpstructPC_Global.cDifficultyLevel == 2)
            gpstructPC_Global.cHintCountDown = 4;
        // if hard.. at least 1/6 of the time for this function.
        else
            gpstructPC_Global.cHintCountDown = 6;
    }

    // call across to the navigation setup
    iRet = gamelogic02_scene1020 (1, cSubFlag + 1);
    return iRet;
}

