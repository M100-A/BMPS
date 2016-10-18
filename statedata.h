//
// statedata.h
//
// Header file for statedata structures and definitions for BMPS.
//

//----------------------------------------------------------------------
//
// structures for location list..
//

struct  statedata_Locations
{
    char    cLocationId;
    char    cAreaId;
    char    *pszDesc;
};

//----------------------------------------------------------------------
//
// structures for a NPC schedule stat data..
//

#define STATEACTION_WRK_H 1 // working, but hidden/not-available
#define STATEACTION_SLP_D 2 // sleeping, but not-available
#define STATEACTION_SLP_A 3 // sleeping, and available
#define STATEACTION_WRK_A 4 // working, and available
#define STATEACTION_RES_D 5 // resting, drunk
#define STATEACTION_RES_N 6 // resting, normal
#define STATEACTION_DRK_N 7 // drinking, normal
#define STATEACTION_EAT_N 8 // eating, normal
#define STATEACTION_HNG_N 9 // hanging around, normal

struct  statedata_NPCSchElement
{
    char    cActionId;
    char    cLocationId;
    short   sPercentValue;
};

struct  statedata_NPCSchBase
{
    char    cLinkId;
    struct  statedata_NPCSchElement *pstructList;
};

#define STATEDATA_TIMESLOTS 32

//----------------------------------------------------------------------
//
// structure for a NPC schedule array..
//

struct  statedata_NPCSchArray
{
    char    cActionId;
    char    cLocationId;
};

#define STATEDATA_ARRAYMAX 16

//----------------------------------------------------------------------
//
// structure for a NPC interaction priority array..
//

struct  statedata_NPCPriorityList
{
    short   sOffset;
    char    cResult;
    int     iSortValue;
};

#define STATEDATA_KNOWNMAX 30
#define STATEDATA_TRUSTMAX 100
#define STATEDATA_OBEDIENCEMAX 200


//----------------------------------------------------------------------
//
// structure for a NPC dynamic stat data..
//

#define STATEDATA_NPCS 64

struct  statedata_NPCData
{
    char    cLocationId;
    char    cAreaId;
    char    cActionId;
    char    cNameToFaceFlag;
    char    cInteractionLockFlag;
    int     iKnownValue;
    int     iTrustValue;
    int     iObedienceValue;
    int     iEnergyValue;
    struct  statedata_NPCSchBase *structNPCSched;
};

#define STATEDATA_ENERGYMAX 400
#define STATEDATA_ENERGYINC 40
#define STATEDATA_ENERGYINC_SLP_D 80 // *2
#define STATEDATA_ENERGYINC_SLP_A 68 // *1.7
#define STATEDATA_ENERGYINC_RES_N 52 // *1.3
#define STATEDATA_ENERGYINC_RES_D 48 // *1.2
#define STATEDATA_ENERGYAVAIL 200


//----------------------------------------------------------------------
//
// structure for a Global+PC dynamic stat data..
//

struct  statedata_GlobalData
{
    char    cLocationId;
    char    cAreaId;
    char    cClothesValue;
    char    cDildoValue;
    char    cBreastsValue;
    char    cClitorisValue;
    int     iDayCount;
    char    cTimeValue;
    char    cDifficultyLevel;
    char    cHintCountDown;
};


//
// These are the state data functions (statedata.c).
//

int statedata_allocAndInit ();

int statedata_incrementDateTimeAndUpdate ();

void statedata_visibleNPCs (char cLocationId, char *pcActionArray);

int statedata_nameLocalNPCs (char cLocationId);

int statedata_nameLocalNPCsx2 (char cLocationId1, char cLocationId2);

void statedata_prioritizeNPCs (char cLocationId, char cAreaId);

void statedata_manualNPCPriority (short sNPCVal1);

void statedata_incrementPrioritizedNPCs (short sCutoff, int iIncrement);

short statedata_isThereASleepingNPC (char cLocationId);

int statedata_isPCAlone (char cLocationId, short *psOffset);

int statedata_nameShowupNPCs (char cLocationId1);

int statedata_namePresentNPCs (char cLocationId1, short sCutOff);

int statedata_showNPCChanges (short sCutOff);

int statedata_specificNPCOnlyNPCAtLocation (short sNPCVal1, char cLocation1);

int statedata_hasGameEndTriggered ();


//
// These are the state data savefile functions (statefile.c).
//

int statefile_parseSaveFile (char *pszFileName, char *pszDateTime);

int statefile_loadSaveFile (char *pszFileName);

int statefile_writeSaveFile (char *pszFileName);



