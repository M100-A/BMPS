//
// statedata.c
//
// character status storage.
//

#include "common.h"
#include "gamelogic.h"
#include "statedata.h"

// external linkage to the game variables.
extern  char    gcDebugFlag;

extern  struct  mdialog_searchreplacelist gstructSrchRepList[];


//
// This is the list of locations.
//
struct  statedata_Locations gstructLocationList[] =
{
    {  1,  1, "outside the mayor\'s house" },
    {  2,  1, "inside the mayor\'s house" },
    {  3,  1, "inside gardener shack next to the mayor\'s house" },
    {  4,  2, "outside the constable\'s residence" },
    {  5,  2, "inside the constable\'s residence" },
    {  6,  3, "outside the guard barracks" },
    {  7,  3, "inside the guard barracks" },
    {  8,  4, "outside the moneylender\'s house" },
    {  9,  4, "in the hallway of moneylender\'s house" },
    { 10,  4, "inside the moneylender\'s main room, at his house" },
    { 11,  4, "inside the bodyguard room, at the moneylender\'s house" },
    { 12,  4, "inside gardener shack next to the moneylender\'s house" },
    { 13,  5, "outside the merchant\'s house" },
    { 14,  5, "in the hallway of the merchant\'s house" },
    { 15,  5, "inside the merchant\'s room, at his house" },
    { 16,  5, "inside the security guard room, at the merchant\'s house" },
    { 17,  5, "inside gardener shack next to the merchant\'s house" },
    { 18,  6, "outside the physician\'s residence" },
    { 19,  6, "inside the physician\'s residence" },
    { 20,  7, "outside the warehouse" },
    { 21,  7, "inside the warehouse" },
    { 22,  7, "inside the warehouse apartment" },
    { 23,  8, "outside the brewery" },
    { 24,  8, "inside the brewery" },
    { 25,  8, "inside the brewery apartment" },
    { 26,  9, "outside the tavern" },
    { 27,  9, "inside the tavern main hall" },
    { 28,  9, "behind the tavern bar" },
    { 29,  9, "inside tavern keeper\'s room, at the tavern" },
    { 30,  9, "inside prostitute\'s room, at the tavern" },
    { 31, 10, "outside the kitchen" },
    { 32, 10, "inside the kitchen" },
    { 33, 10, "inside the kitchen apartment" },
    { 34, 10, "inside the beggar shanty next to the kitchen" },
    { 35, 11, "outside the workshop" },
    { 36, 11, "inside the workshop" },
    { 37, 11, "inside the workshop apartment" },
    { 38, 12, "outside the goat corral" },
    { 39, 12, "inside the goat corral" },
    { 40, 12, "inside the shack next to the goat corral" },
    { 41, 13, "outside the lumber mill" },
    { 42, 13, "inside the shack next to the lumber mill" },
    { 43, 14, "at the edge of the forest" },
    { 44, 14, "inside the shack next to the forest" },
    { 45, 14, "inside the forest" },
    { 46, 15, "outside the target range" },
    { 47, 15, "inside the target range" },
    { 48, 15, "inside the shack next to the target range" },
    { 49, 16, "at the edge of the lake" },
    { 50, 16, "inside the shack next to the lake" },
    { 51, 17, "near the northern farm" },
    { 52, 17, "inside the shack next to the northern farm" },
    { 53, 18, "near the eastern farm" },
    { 54, 18, "inside the shack next to the eastern farm" },
    { 55, 19, "near the southern farm" },
    { 56, 19, "inside the shack next to the southern farm" },
    { 57, 20, "near the western farm" },
    { 58, 20, "inside the shack next to the western farm" },
    { 59, 21, "outside the procurer\'s shack" },
    { 60, 21, "inside the procurer\'s shack" },
    { 61, 21, "inside the thug\'s shanty, next to the procurer\'s shack" },
    { 62, 22, "outside the smugglers\'s shack" },
    { 63, 22, "inside the smugglers\'s shack" },
    { 64, 22, "inside the bandit\'s shanty, next to the smugglers\'s shack" },
    { -1, -1, NULL },
};

//
// NPC-01 = Mayor-Zeke
//

struct  statedata_NPCSchElement gstructNPCSE_01_Sleep[] =
{
    { STATEACTION_SLP_A,  2,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_Default[] =
{
    { STATEACTION_HNG_N,  2,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_09[] =
{
    { STATEACTION_EAT_N, 32,  2 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_10[] =
{
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_12[] =
{
    { STATEACTION_HNG_N, 18,  1 },
    { STATEACTION_HNG_N,  6,  1 },
    { STATEACTION_HNG_N, 31,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_14[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 35,  1 },
    { STATEACTION_HNG_N, 15,  1 },
    { STATEACTION_HNG_N, 20,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_16[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 10,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_17[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 30,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_19[] =
{
    { STATEACTION_HNG_N,  5,  1 },
    { STATEACTION_HNG_N,  7,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_21[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 55,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_23[] =
{
    { STATEACTION_HNG_N, 63,  1 },
    { STATEACTION_HNG_N, 53,  2 },
    { STATEACTION_HNG_N, 47,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_25[] =
{
    { STATEACTION_HNG_N, 21,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_27[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_01_28[] =
{
    { STATEACTION_HNG_N,  5,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-01 = Mayor-Zeke
struct  statedata_NPCSchBase gstructNPCSB_01[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_01_Sleep }, // 01
    {  0, gstructNPCSE_01_Sleep }, // 02
    {  0, gstructNPCSE_01_Sleep }, // 03
    {  0, gstructNPCSE_01_Sleep }, // 04
    {  0, gstructNPCSE_01_Sleep }, // 05
    {  0, gstructNPCSE_01_Sleep }, // 06
    {  0, gstructNPCSE_01_Sleep }, // 07
    {  0, gstructNPCSE_01_Sleep }, // 08
    {  0, gstructNPCSE_01_09 }, // 09
    {  0, gstructNPCSE_01_10 }, // 10
    {  0, gstructNPCSE_01_Default }, // 11
    {  0, gstructNPCSE_01_12 }, // 12
    {  0, gstructNPCSE_01_Default }, // 13
    {  0, gstructNPCSE_01_14 }, // 14
    {  0, gstructNPCSE_01_Default }, // 15
    {  0, gstructNPCSE_01_16 }, // 16
    {  0, gstructNPCSE_01_17 }, // 17
    {  0, gstructNPCSE_01_Default }, // 18
    {  0, gstructNPCSE_01_19 }, // 19
    {  0, gstructNPCSE_01_Default }, // 20
    {  0, gstructNPCSE_01_21 }, // 21
    {  0, gstructNPCSE_01_Default }, // 22
    {  0, gstructNPCSE_01_23 }, // 23
    {  0, gstructNPCSE_01_Default }, // 24
    {  0, gstructNPCSE_01_25 }, // 25
    {  0, gstructNPCSE_01_Default }, // 26
    {  0, gstructNPCSE_01_27 }, // 27
    {  0, gstructNPCSE_01_28 }, // 28
    {  0, gstructNPCSE_01_Sleep }, // 29
    {  0, gstructNPCSE_01_Sleep }, // 30
    {  0, gstructNPCSE_01_Sleep }, // 31
    {  0, gstructNPCSE_01_Sleep } // 32
};


//
// NPC-02 = Constable-Otto
//

struct  statedata_NPCSchElement gstructNPCSE_02_Sleep[] =
{
    { STATEACTION_SLP_A,  5,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_Default[] =
{
    { STATEACTION_RES_N,  5,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_09[] =
{
    { STATEACTION_HNG_N,  7,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_11[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_12[] =
{
    { STATEACTION_DRK_N, 24,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_14[] =
{
    { STATEACTION_HNG_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_15[] =
{
    { STATEACTION_HNG_N,  5,  2 },
    { STATEACTION_HNG_N,  7,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_17[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 18,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_18[] =
{
    { STATEACTION_HNG_N,  6,  2 },
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_20[] =
{
    { STATEACTION_HNG_N, 43,  2 },
    { STATEACTION_HNG_N, 13,  2 },
    { STATEACTION_HNG_N, 63,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_21[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_DRK_N, 26,  2 },
    { STATEACTION_HNG_N, 19,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_22[] =
{
    { STATEACTION_HNG_N,  6,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_23[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_25[] =
{
    { STATEACTION_DRK_N, 30,  1 },
    { STATEACTION_HNG_N,  6,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_02_26[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-02 = Constable-Otto
struct  statedata_NPCSchBase gstructNPCSB_02[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_02_Sleep }, // 01
    {  0, gstructNPCSE_02_Sleep }, // 02
    {  0, gstructNPCSE_02_Sleep }, // 03
    {  0, gstructNPCSE_02_Sleep }, // 04
    {  0, gstructNPCSE_02_Sleep }, // 05
    {  0, gstructNPCSE_02_Sleep }, // 06
    {  0, gstructNPCSE_02_Sleep }, // 07
    {  0, gstructNPCSE_02_Sleep }, // 08
    {  0, gstructNPCSE_02_09 }, // 09
    {  0, gstructNPCSE_02_Default }, // 10
    {  0, gstructNPCSE_02_11 }, // 11
    {  0, gstructNPCSE_02_12 }, // 12
    {  1, NULL }, // 13
    {  0, gstructNPCSE_02_14 }, // 14
    {  0, gstructNPCSE_02_15 }, // 15
    {  8, NULL }, // 16
    {  0, gstructNPCSE_02_17 }, // 17
    {  0, gstructNPCSE_02_18 }, // 18
    {  0, gstructNPCSE_02_Default }, // 19
    {  0, gstructNPCSE_02_20 }, // 20
    {  0, gstructNPCSE_02_21 }, // 21
    {  0, gstructNPCSE_02_22 }, // 22
    {  0, gstructNPCSE_02_23 }, // 23
    {  0, gstructNPCSE_02_Default }, // 24
    {  0, gstructNPCSE_02_25 }, // 25
    {  0, gstructNPCSE_02_26 }, // 26
    {  0, gstructNPCSE_02_Default }, // 27
    {  0, gstructNPCSE_02_Default }, // 28
    {  0, gstructNPCSE_02_Sleep }, // 29
    {  0, gstructNPCSE_02_Sleep }, // 30
    {  0, gstructNPCSE_02_Sleep }, // 31
    {  0, gstructNPCSE_02_Sleep } // 32
};

//
// NPCs 03-07, Guards (common)
//

struct  statedata_NPCSchElement gstructNPCSE_GD_Sleep[] =
{
    { STATEACTION_SLP_A,  7,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_DeadSleep[] =
{
    { STATEACTION_SLP_D,  7,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_Default[] =
{
    { STATEACTION_RES_N,  7,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_Patrol1[] =
{
    { STATEACTION_HNG_N, 20,  0 }, // warehouse
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_Patrol2[] =
{
    { STATEACTION_HNG_N, 26,  0 }, // tavern
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_Patrol3[] =
{
    { STATEACTION_HNG_N, 35,  0 }, // workshop
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_Patrol4[] =
{
    { STATEACTION_HNG_N, 18,  0 }, // physician
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_TavDrink[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_GD_TavDefault[] =
{
    { STATEACTION_DRK_N, 27,  2 },
    { STATEACTION_RES_N,  7,  1 },
    { -1, -1, -1 }
};


//
// NPC-03 = Guard-Lars
//

struct  statedata_NPCSchElement gstructNPCSE_03_10[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_03_24[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-03 = Guard-Lars
struct  statedata_NPCSchBase gstructNPCSB_03[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_GD_Sleep }, // 01
    {  0, gstructNPCSE_GD_Sleep }, // 02
    {  0, gstructNPCSE_GD_DeadSleep }, // 03
    {  0, gstructNPCSE_GD_Sleep }, // 04
    {  0, gstructNPCSE_GD_Sleep }, // 05
    {  0, gstructNPCSE_GD_Sleep }, // 06
    {  0, gstructNPCSE_GD_Sleep }, // 07
    {  0, gstructNPCSE_GD_Sleep }, // 08
    {  0, gstructNPCSE_GD_Default }, // 09
    {  0, gstructNPCSE_03_10 }, // 10
    {  0, gstructNPCSE_GD_Patrol1 }, // 11
    {  0, gstructNPCSE_GD_Patrol2 }, // 12
    {  0, gstructNPCSE_GD_Patrol3 }, // 13
    {  0, gstructNPCSE_GD_Patrol4 }, // 14
    {  0, gstructNPCSE_GD_Patrol1 }, // 15
    {  0, gstructNPCSE_GD_Patrol2 }, // 16
    {  0, gstructNPCSE_GD_Patrol3 }, // 17
    {  0, gstructNPCSE_GD_Patrol4 }, // 18
    {  0, gstructNPCSE_GD_Patrol1 }, // 19
    {  0, gstructNPCSE_GD_Patrol2 }, // 20
    {  0, gstructNPCSE_GD_Patrol3 }, // 21
    {  0, gstructNPCSE_GD_Patrol4 }, // 22
    {  0, gstructNPCSE_GD_Patrol1 }, // 23
    {  0, gstructNPCSE_03_24 }, // 24
    {  0, gstructNPCSE_GD_TavDrink }, // 25
    {  0, gstructNPCSE_GD_TavDefault }, // 26
    {  0, gstructNPCSE_GD_Default }, // 27
    {  0, gstructNPCSE_GD_Default }, // 28
    {  0, gstructNPCSE_GD_Sleep }, // 29
    {  0, gstructNPCSE_GD_Sleep }, // 30
    {  0, gstructNPCSE_GD_Sleep }, // 31
    {  0, gstructNPCSE_GD_Sleep } // 32
};


//
// NPC-04 = Guard-Nasir
//

struct  statedata_NPCSchElement gstructNPCSE_04_11[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_04_16[] =
{
    { STATEACTION_RES_N, 43,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_04_17[] =
{
    { STATEACTION_HNG_N,  8,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-04 = Guard-Nasir
struct  statedata_NPCSchBase gstructNPCSB_04[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_GD_Patrol3 }, // 01
    {  0, gstructNPCSE_GD_Patrol4 }, // 02
    {  0, gstructNPCSE_GD_Patrol1 }, // 03
    {  0, gstructNPCSE_GD_Patrol2 }, // 04
    {  0, gstructNPCSE_GD_Patrol3 }, // 05
    {  0, gstructNPCSE_GD_Patrol4 }, // 06
    {  0, gstructNPCSE_GD_Patrol1 }, // 07
    {  0, gstructNPCSE_GD_Patrol2 }, // 08
    {  0, gstructNPCSE_GD_Patrol3 }, // 09
    {  0, gstructNPCSE_GD_Patrol4 }, // 10
    {  0, gstructNPCSE_04_11 }, // 11
    {  0, gstructNPCSE_GD_Default }, // 12
    {  0, gstructNPCSE_GD_Default }, // 13
    {  0, gstructNPCSE_GD_TavDrink }, // 14
    {  0, gstructNPCSE_GD_TavDrink }, // 15
    {  0, gstructNPCSE_04_16 }, // 16
    {  0, gstructNPCSE_04_17 }, // 17
    {  0, gstructNPCSE_GD_Default }, // 18
    {  0, gstructNPCSE_GD_Default }, // 19
    {  0, gstructNPCSE_GD_Sleep }, // 20
    {  0, gstructNPCSE_GD_Sleep }, // 21
    {  0, gstructNPCSE_GD_Sleep }, // 22
    {  0, gstructNPCSE_GD_Sleep }, // 23
    {  0, gstructNPCSE_GD_Sleep }, // 24
    {  0, gstructNPCSE_GD_Sleep }, // 25
    {  0, gstructNPCSE_GD_Sleep }, // 26
    {  0, gstructNPCSE_GD_Sleep }, // 27
    {  0, gstructNPCSE_GD_DeadSleep }, // 28
    {  0, gstructNPCSE_GD_Sleep }, // 29
    {  0, gstructNPCSE_GD_Sleep }, // 30
    {  0, gstructNPCSE_GD_Sleep }, // 31
    {  0, gstructNPCSE_GD_Default } // 32
};


//
// NPC-05 = Guard-Gino
//

struct  statedata_NPCSchElement gstructNPCSE_05_01[] =
{
    { STATEACTION_HNG_N,  1,  1 },
    { STATEACTION_HNG_N,  8,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_02[] =
{
    { STATEACTION_HNG_N,  4,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_03[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_04[] =
{
    { STATEACTION_HNG_N, 46,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_05[] =
{
    { STATEACTION_HNG_N,  6,  1 },
    { STATEACTION_HNG_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_06[] =
{
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_07[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_08[] =
{
    { STATEACTION_HNG_N, 23,  1 },
    { STATEACTION_HNG_N, 13,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_09[] =
{
    { STATEACTION_HNG_N,  1,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { STATEACTION_HNG_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_10[] =
{
    { STATEACTION_HNG_N, 26,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_11[] =
{
    { STATEACTION_HNG_N,  6,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_12[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N,  6,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_14[] =
{
    { STATEACTION_HNG_N,  6,  2 },
    { STATEACTION_HNG_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_05_15[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-05 = Guard-Gino
struct  statedata_NPCSchBase gstructNPCSB_05[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_05_01 }, // 01
    {  0, gstructNPCSE_05_02 }, // 02
    {  0, gstructNPCSE_05_03 }, // 03
    {  0, gstructNPCSE_05_04 }, // 04
    {  0, gstructNPCSE_05_05 }, // 05
    {  0, gstructNPCSE_05_06 }, // 06
    {  0, gstructNPCSE_05_07 }, // 07
    {  0, gstructNPCSE_05_08 }, // 08
    {  0, gstructNPCSE_05_09 }, // 09
    {  0, gstructNPCSE_05_10 }, // 10
    {  0, gstructNPCSE_05_11 }, // 11
    {  0, gstructNPCSE_05_12 }, // 12
    {  0, gstructNPCSE_GD_TavDrink }, // 13
    {  0, gstructNPCSE_05_14 }, // 14
    {  0, gstructNPCSE_05_15 }, // 15
    {  0, gstructNPCSE_GD_Default }, // 16
    {  0, gstructNPCSE_GD_TavDrink }, // 17
    {  0, gstructNPCSE_GD_TavDefault }, // 18
    {  0, gstructNPCSE_GD_Default }, // 19
    {  0, gstructNPCSE_GD_Sleep }, // 20
    {  0, gstructNPCSE_GD_Sleep }, // 21
    {  0, gstructNPCSE_GD_Sleep }, // 22
    {  0, gstructNPCSE_GD_Sleep }, // 23
    {  0, gstructNPCSE_GD_DeadSleep }, // 24
    {  0, gstructNPCSE_GD_Sleep }, // 25
    {  0, gstructNPCSE_GD_Sleep }, // 26
    {  0, gstructNPCSE_GD_Sleep }, // 27
    {  0, gstructNPCSE_GD_Sleep }, // 28
    {  0, gstructNPCSE_GD_Sleep }, // 29
    {  0, gstructNPCSE_GD_Sleep }, // 30
    {  0, gstructNPCSE_GD_Sleep }, // 31
    {  0, gstructNPCSE_GD_Default } // 32
};


//
// NPC-06 = Guard-Terell
//

struct  statedata_NPCSchElement gstructNPCSE_06_15[] =
{
    { STATEACTION_HNG_N,  4,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_06_17[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_06_18[] =
{
    { STATEACTION_HNG_N,  1,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_06_23[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_06_29[] =
{
    { STATEACTION_HNG_N, 35,  2 },
    { STATEACTION_HNG_N, 63,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-06 = Guard-Terell
struct  statedata_NPCSchBase gstructNPCSB_06[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_GD_Default }, // 01
    {  0, gstructNPCSE_GD_Sleep }, // 02
    {  0, gstructNPCSE_GD_Sleep }, // 03
    {  0, gstructNPCSE_GD_Sleep }, // 04
    {  0, gstructNPCSE_GD_Sleep }, // 05
    {  0, gstructNPCSE_GD_Sleep }, // 06
    {  0, gstructNPCSE_GD_Sleep }, // 07
    {  0, gstructNPCSE_GD_Sleep }, // 08
    {  0, gstructNPCSE_GD_DeadSleep }, // 09
    {  0, gstructNPCSE_GD_Sleep }, // 10
    {  0, gstructNPCSE_GD_Sleep }, // 11
    {  0, gstructNPCSE_GD_Sleep }, // 12
    {  0, gstructNPCSE_GD_Sleep }, // 13
    {  0, gstructNPCSE_GD_Default }, // 14
    {  0, gstructNPCSE_06_15 }, // 15
    {  0, gstructNPCSE_GD_Default }, // 16
    {  0, gstructNPCSE_06_17 }, // 17
    {  0, gstructNPCSE_06_18 }, // 18
    {  0, gstructNPCSE_GD_TavDrink }, // 19
    {  0, gstructNPCSE_GD_TavDrink }, // 20
    {  0, gstructNPCSE_GD_TavDrink }, // 21
    {  0, gstructNPCSE_GD_Default }, // 22
    {  0, gstructNPCSE_06_23 }, // 23
    {  0, gstructNPCSE_GD_Patrol2 }, // 24
    {  0, gstructNPCSE_GD_Patrol3 }, // 25
    {  0, gstructNPCSE_GD_Patrol4 }, // 26
    {  0, gstructNPCSE_GD_Patrol1 }, // 27
    {  0, gstructNPCSE_GD_Patrol2 }, // 28
    {  0, gstructNPCSE_06_29 }, // 29
    {  0, gstructNPCSE_GD_Patrol4 }, // 30
    {  0, gstructNPCSE_GD_Patrol1 }, // 31
    {  0, gstructNPCSE_GD_Patrol2 } // 32
};


//
// NPC-07 = Guard-Cortez
//

struct  statedata_NPCSchElement gstructNPCSE_07_15[] =
{
    { STATEACTION_HNG_N, 59,  1 },
    { STATEACTION_HNG_N, 62,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_16[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_17[] =
{
    { STATEACTION_RES_N,  7,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_19[] =
{
    { STATEACTION_RES_N, 49,  1 },
    { STATEACTION_RES_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_20[] =
{
    { STATEACTION_HNG_N, 46,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_24[] =
{
    { STATEACTION_HNG_N,  4,  1 },
    { STATEACTION_HNG_N,  1,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_25[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_26[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N,  8,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_28[] =
{
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_29[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 13,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_30[] =
{
    { STATEACTION_HNG_N, 43,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_31[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_07_32[] =
{
    { STATEACTION_HNG_N,  1,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-07 = Guard-Cortez
struct  statedata_NPCSchBase gstructNPCSB_07[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_GD_Default }, // 01
    {  0, gstructNPCSE_GD_Sleep }, // 02
    {  0, gstructNPCSE_GD_Sleep }, // 03
    {  0, gstructNPCSE_GD_Sleep }, // 04
    {  0, gstructNPCSE_GD_Sleep }, // 05
    {  0, gstructNPCSE_GD_DeadSleep }, // 06
    {  0, gstructNPCSE_GD_Sleep }, // 07
    {  0, gstructNPCSE_GD_Sleep }, // 08
    {  0, gstructNPCSE_GD_Sleep }, // 09
    {  0, gstructNPCSE_GD_Sleep }, // 10
    {  0, gstructNPCSE_GD_Sleep }, // 11
    {  0, gstructNPCSE_GD_Sleep }, // 12
    {  0, gstructNPCSE_GD_Sleep }, // 13
    {  0, gstructNPCSE_GD_Default }, // 14
    {  0, gstructNPCSE_07_15 }, // 15
    {  0, gstructNPCSE_07_16 }, // 16
    {  0, gstructNPCSE_07_17 }, // 17
    {  0, gstructNPCSE_GD_Default }, // 18
    {  0, gstructNPCSE_07_19 }, // 19
    {  0, gstructNPCSE_07_20 }, // 20
    {  0, gstructNPCSE_GD_Default }, // 21
    {  0, gstructNPCSE_GD_Default }, // 22
    {  0, gstructNPCSE_GD_TavDrink }, // 23
    {  0, gstructNPCSE_07_24 }, // 24
    {  0, gstructNPCSE_07_25 }, // 25
    {  0, gstructNPCSE_07_26 }, // 26
    {  0, gstructNPCSE_GD_Patrol2 }, // 27
    {  0, gstructNPCSE_07_28 }, // 28
    {  0, gstructNPCSE_07_29 }, // 29
    {  0, gstructNPCSE_07_30 }, // 30
    {  0, gstructNPCSE_07_31 }, // 31
    {  0, gstructNPCSE_07_32 } // 32
};


//
// NPC-08 = Moneylender-Redinald
//

struct  statedata_NPCSchElement gstructNPCSE_08_Sleep[] =
{
    { STATEACTION_SLP_A, 10,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_DeadSleep[] =
{
    { STATEACTION_SLP_D, 10,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_Default[] =
{
    { STATEACTION_WRK_A, 10,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_15[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_17[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_18[] =
{
    { STATEACTION_HNG_N, 21,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 31,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { STATEACTION_HNG_N, 24,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_19[] =
{
    { STATEACTION_HNG_N, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_2122[] =
{
    { STATEACTION_HNG_N, 15,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_23[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_24[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_08_28[] =
{
    { STATEACTION_HNG_N,  5,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-08 = Moneylender-Redinald
struct  statedata_NPCSchBase gstructNPCSB_08[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_08_Default }, // 01
    {  0, gstructNPCSE_08_Sleep }, // 02
    {  0, gstructNPCSE_08_Sleep }, // 03
    {  0, gstructNPCSE_08_DeadSleep }, // 04
    {  0, gstructNPCSE_08_DeadSleep }, // 05
    {  0, gstructNPCSE_08_DeadSleep }, // 06
    {  0, gstructNPCSE_08_DeadSleep }, // 07
    {  0, gstructNPCSE_08_DeadSleep }, // 08
    {  0, gstructNPCSE_08_DeadSleep }, // 09
    {  0, gstructNPCSE_08_DeadSleep }, // 10
    {  0, gstructNPCSE_08_DeadSleep }, // 11
    {  0, gstructNPCSE_08_DeadSleep }, // 12
    {  0, gstructNPCSE_08_Sleep }, // 13
    {  0, gstructNPCSE_08_Default }, // 14
    {  0, gstructNPCSE_08_15 }, // 15
    {  0, gstructNPCSE_08_Default }, // 16
    {  0, gstructNPCSE_08_17 }, // 17
    {  0, gstructNPCSE_08_18 }, // 18
    {  0, gstructNPCSE_08_19 }, // 19
    {  0, gstructNPCSE_08_Default }, // 20
    {  0, gstructNPCSE_08_2122 }, // 21
    {  0, gstructNPCSE_08_2122 }, // 22
    {  0, gstructNPCSE_08_23 }, // 23
    {  0, gstructNPCSE_08_24 }, // 24
    {  0, gstructNPCSE_08_Default }, // 25
    {  0, gstructNPCSE_08_Default }, // 26
    {  0, gstructNPCSE_08_Default }, // 27
    {  0, gstructNPCSE_08_28 }, // 28
    {  0, gstructNPCSE_08_Default }, // 29
    {  0, gstructNPCSE_08_Default }, // 30
    {  0, gstructNPCSE_08_Default }, // 31
    {  0, gstructNPCSE_08_Default } // 32
};


//
// NPCs 09-10, Bodyguards (common)
//

struct  statedata_NPCSchElement gstructNPCSE_BG_Sleep[] =
{
    { STATEACTION_SLP_A, 11,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BG_Guard[] =
{
    { STATEACTION_HNG_N,  9,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BG_TavernDrink[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BG_TavernEat[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};


//
// NPC-09 = Bodyguard-Sigga
//

struct  statedata_NPCSchElement gstructNPCSE_09_13[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-09 = Bodyguard-Sigga
struct  statedata_NPCSchBase gstructNPCSB_09[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BG_Sleep }, // 01
    {  0, gstructNPCSE_BG_Sleep }, // 02
    {  0, gstructNPCSE_BG_Sleep }, // 03
    {  0, gstructNPCSE_BG_Sleep }, // 04
    {  0, gstructNPCSE_BG_Sleep }, // 05
    {  0, gstructNPCSE_BG_Sleep }, // 06
    {  0, gstructNPCSE_BG_Sleep }, // 07
    {  0, gstructNPCSE_BG_Sleep }, // 08
    {  0, gstructNPCSE_BG_Sleep }, // 09
    {  0, gstructNPCSE_BG_Sleep }, // 10
    {  0, gstructNPCSE_BG_Sleep }, // 11
    {  0, gstructNPCSE_BG_Sleep }, // 12
    {  0, gstructNPCSE_09_13 }, // 13
    {  8, NULL }, // 14
    {  8, NULL }, // 15
    {  8, NULL }, // 16
    {  8, NULL }, // 17
    {  0, gstructNPCSE_BG_TavernEat }, // 18
    {  0, gstructNPCSE_BG_TavernDrink }, // 19
    {  0, gstructNPCSE_BG_Guard }, // 20
    {  8, NULL }, // 21
    {  8, NULL }, // 22
    {  8, NULL }, // 23
    {  8, NULL }, // 24
    {  0, gstructNPCSE_BG_Guard }, // 25
    {  0, gstructNPCSE_BG_Guard }, // 26
    {  0, gstructNPCSE_BG_Guard }, // 27
    {  8, NULL }, // 28
    {  0, gstructNPCSE_BG_Guard }, // 29
    {  0, gstructNPCSE_BG_Guard }, // 30
    {  0, gstructNPCSE_BG_Guard }, // 31
    {  0, gstructNPCSE_BG_Guard } // 32
};


//
// NPC-10 = Bodyguard-Massimo
//

struct  statedata_NPCSchElement gstructNPCSE_10_32[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 63,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-10 = Bodyguard-Massimo
struct  statedata_NPCSchBase gstructNPCSB_10[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BG_Guard }, // 01
    {  0, gstructNPCSE_BG_Guard }, // 02
    {  0, gstructNPCSE_BG_Guard }, // 03
    {  0, gstructNPCSE_BG_Guard }, // 04
    {  0, gstructNPCSE_BG_Guard }, // 05
    {  0, gstructNPCSE_BG_Guard }, // 06
    {  0, gstructNPCSE_BG_Guard }, // 07
    {  0, gstructNPCSE_BG_Guard }, // 08
    {  0, gstructNPCSE_BG_Guard }, // 09
    {  0, gstructNPCSE_BG_Guard }, // 10
    {  0, gstructNPCSE_BG_Guard }, // 11
    {  0, gstructNPCSE_BG_Guard }, // 12
    {  0, gstructNPCSE_BG_Guard }, // 13
    {  0, gstructNPCSE_BG_TavernEat }, // 14
    {  0, gstructNPCSE_BG_TavernDrink }, // 15
    {  0, gstructNPCSE_BG_TavernEat }, // 16
    {  0, gstructNPCSE_BG_TavernDrink }, // 17
    {  8, NULL }, // 18
    {  8, NULL }, // 19
    {  0, gstructNPCSE_BG_Sleep }, // 20
    {  0, gstructNPCSE_BG_Sleep }, // 21
    {  0, gstructNPCSE_BG_Sleep }, // 22
    {  0, gstructNPCSE_BG_Sleep }, // 23
    {  0, gstructNPCSE_BG_Sleep }, // 24
    {  0, gstructNPCSE_BG_Sleep }, // 25
    {  0, gstructNPCSE_BG_Sleep }, // 26
    {  0, gstructNPCSE_BG_Sleep }, // 27
    {  0, gstructNPCSE_BG_Sleep }, // 28
    {  0, gstructNPCSE_BG_Sleep }, // 29
    {  0, gstructNPCSE_BG_Sleep }, // 30
    {  0, gstructNPCSE_BG_Sleep }, // 31
    {  0, gstructNPCSE_10_32 } // 32
};


//
// NPC-11 = Merchant-Salvator
//

struct  statedata_NPCSchElement gstructNPCSE_11_Sleep[] =
{
    { STATEACTION_SLP_A, 15,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_DeadSleep[] =
{
    { STATEACTION_SLP_D, 15,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_Default[] =
{
    { STATEACTION_WRK_A, 15,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_15[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_16[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_17[] =
{
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_18[] =
{
    { STATEACTION_HNG_N, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_19[] =
{
    { STATEACTION_HNG_N, 21,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_20[] =
{
    { STATEACTION_HNG_N, 24,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_28[] =
{
    { STATEACTION_RES_N, 30,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_11_30[] =
{
    { STATEACTION_RES_N, 15,  2 },
    { STATEACTION_HNG_N, 63,  1 },
    { STATEACTION_HNG_N, 60,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-11 = Merchant-Salvator
struct  statedata_NPCSchBase gstructNPCSB_11[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_11_Default }, // 01
    {  0, gstructNPCSE_11_Sleep }, // 02
    {  0, gstructNPCSE_11_Sleep }, // 03
    {  0, gstructNPCSE_11_DeadSleep }, // 04
    {  0, gstructNPCSE_11_DeadSleep }, // 05
    {  0, gstructNPCSE_11_DeadSleep }, // 06
    {  0, gstructNPCSE_11_DeadSleep }, // 07
    {  0, gstructNPCSE_11_DeadSleep }, // 08
    {  0, gstructNPCSE_11_DeadSleep }, // 09
    {  0, gstructNPCSE_11_DeadSleep }, // 10
    {  0, gstructNPCSE_11_DeadSleep }, // 11
    {  0, gstructNPCSE_11_DeadSleep }, // 12
    {  0, gstructNPCSE_11_Sleep }, // 13
    {  0, gstructNPCSE_11_Default }, // 14
    {  0, gstructNPCSE_11_15 }, // 15
    {  0, gstructNPCSE_11_16 }, // 16
    {  0, gstructNPCSE_11_17 }, // 17
    {  0, gstructNPCSE_11_18 }, // 18
    {  0, gstructNPCSE_11_19 }, // 19
    {  0, gstructNPCSE_11_20 }, // 20
    {  0, gstructNPCSE_11_Default }, // 21
    {  0, gstructNPCSE_11_Default }, // 22
    {  8, NULL }, // 23
    {  8, NULL }, // 24
    {  8, NULL }, // 25
    {  0, gstructNPCSE_11_Default }, // 26
    {  0, gstructNPCSE_11_Default }, // 27
    {  0, gstructNPCSE_11_28 }, // 28
    {  0, gstructNPCSE_11_Default }, // 29
    {  0, gstructNPCSE_11_30 }, // 30
    {  0, gstructNPCSE_11_Default }, // 31
    {  0, gstructNPCSE_11_Default } // 32
};


//
// NPCs 12-13, Security Guards (common)
//

struct  statedata_NPCSchElement gstructNPCSE_SG_Sleep[] =
{
    { STATEACTION_SLP_A, 16,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SG_Rest[] =
{
    { STATEACTION_RES_N, 16,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SG_Guard[] =
{
    { STATEACTION_HNG_N, 14,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SG_GuardRot[] =
{
    { STATEACTION_HNG_N, 13,  1 },
    { STATEACTION_HNG_N, 20,  1 },
    { STATEACTION_HNG_N, 23,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SG_TavernDrink[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SG_TavernEat[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};


//
// NPC-12 = Security-Khol
//

struct  statedata_NPCSchElement gstructNPCSE_12_13[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-12 = Security-Khol
struct  statedata_NPCSchBase gstructNPCSB_12[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_SG_Sleep }, // 01
    {  0, gstructNPCSE_SG_Sleep }, // 02
    {  0, gstructNPCSE_SG_Sleep }, // 03
    {  0, gstructNPCSE_SG_Sleep }, // 04
    {  0, gstructNPCSE_SG_Sleep }, // 05
    {  0, gstructNPCSE_SG_Sleep }, // 06
    {  0, gstructNPCSE_SG_Sleep }, // 07
    {  0, gstructNPCSE_SG_Sleep }, // 08
    {  0, gstructNPCSE_SG_Sleep }, // 09
    {  0, gstructNPCSE_SG_Sleep }, // 10
    {  0, gstructNPCSE_SG_Sleep }, // 11
    {  0, gstructNPCSE_SG_Sleep }, // 12
    {  0, gstructNPCSE_12_13 }, // 13
    {  0, gstructNPCSE_SG_Guard }, // 14
    {  0, gstructNPCSE_SG_TavernDrink }, // 15
    {  0, gstructNPCSE_SG_TavernEat }, // 16
    {  0, gstructNPCSE_SG_TavernDrink }, // 17
    { 11, NULL }, // 18
    { 11, NULL }, // 19
    { 11, NULL }, // 20
    {  0, gstructNPCSE_SG_GuardRot }, // 21
    {  0, gstructNPCSE_SG_GuardRot }, // 22
    {  0, gstructNPCSE_SG_GuardRot }, // 23
    {  0, gstructNPCSE_SG_GuardRot }, // 24
    {  0, gstructNPCSE_SG_GuardRot }, // 25
    {  0, gstructNPCSE_SG_GuardRot }, // 26
    {  0, gstructNPCSE_SG_GuardRot }, // 27
    {  0, gstructNPCSE_SG_GuardRot }, // 28
    {  0, gstructNPCSE_SG_GuardRot }, // 29
    {  0, gstructNPCSE_SG_GuardRot }, // 30
    {  0, gstructNPCSE_SG_GuardRot }, // 31
    {  0, gstructNPCSE_SG_GuardRot } // 32
};


//
// NPC-13 = Security-Hung
//

struct  statedata_NPCSchElement gstructNPCSE_13_20[] =
{
    { STATEACTION_RES_D, 27,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-13 = Security-Hung
struct  statedata_NPCSchBase gstructNPCSB_13[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_SG_GuardRot }, // 01
    {  0, gstructNPCSE_SG_GuardRot }, // 02
    {  0, gstructNPCSE_SG_GuardRot }, // 03
    {  0, gstructNPCSE_SG_GuardRot }, // 04
    {  0, gstructNPCSE_SG_GuardRot }, // 05
    {  0, gstructNPCSE_SG_GuardRot }, // 06
    {  0, gstructNPCSE_SG_GuardRot }, // 07
    {  0, gstructNPCSE_SG_GuardRot }, // 08
    {  0, gstructNPCSE_SG_GuardRot }, // 09
    {  0, gstructNPCSE_SG_GuardRot }, // 10
    {  0, gstructNPCSE_SG_GuardRot }, // 11
    {  0, gstructNPCSE_SG_GuardRot }, // 12
    {  0, gstructNPCSE_SG_Guard }, // 13
    {  0, gstructNPCSE_SG_Rest }, // 14
    { 11, NULL }, // 15
    { 11, NULL }, // 16
    { 11, NULL }, // 17
    {  0, gstructNPCSE_SG_TavernEat }, // 18
    {  0, gstructNPCSE_SG_TavernDrink }, // 19
    {  0, gstructNPCSE_13_20 }, // 20
    {  0, gstructNPCSE_SG_Sleep }, // 21
    {  0, gstructNPCSE_SG_Sleep }, // 22
    {  0, gstructNPCSE_SG_Sleep }, // 23
    {  0, gstructNPCSE_SG_Sleep }, // 24
    {  0, gstructNPCSE_SG_Sleep }, // 25
    {  0, gstructNPCSE_SG_Sleep }, // 26
    {  0, gstructNPCSE_SG_Sleep }, // 27
    {  0, gstructNPCSE_SG_Sleep }, // 28
    {  0, gstructNPCSE_SG_Sleep }, // 29
    {  0, gstructNPCSE_SG_Sleep }, // 30
    {  0, gstructNPCSE_SG_Sleep }, // 31
    {  0, gstructNPCSE_SG_Rest } // 32
};


//
// NPC-14 = Physician-Philippe
//

struct  statedata_NPCSchElement gstructNPCSE_14_Sleep[] =
{
    { STATEACTION_SLP_A, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_DeadSleep[] =
{
    { STATEACTION_SLP_D, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_Default[] =
{
    { STATEACTION_WRK_A, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_Rest[] =
{
    { STATEACTION_RES_N, 19,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_07[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 63,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_12[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_17[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_22[] =
{
    { STATEACTION_RES_N, 49,  1 },
    { STATEACTION_RES_N, 43,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_23[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_EAT_N, 27,  3 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_14_24[] =
{
    { STATEACTION_DRK_N, 27,  3 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-14 = Physician-Philippe
struct  statedata_NPCSchBase gstructNPCSB_14[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_14_DeadSleep }, // 01
    {  0, gstructNPCSE_14_DeadSleep }, // 02
    {  0, gstructNPCSE_14_DeadSleep }, // 03
    {  0, gstructNPCSE_14_DeadSleep }, // 04
    {  0, gstructNPCSE_14_DeadSleep }, // 05
    {  0, gstructNPCSE_14_Sleep }, // 06
    {  0, gstructNPCSE_14_07 }, // 07
    {  0, gstructNPCSE_14_Default }, // 08
    {  0, gstructNPCSE_14_Default }, // 09
    {  0, gstructNPCSE_14_Default }, // 10
    {  0, gstructNPCSE_14_Default }, // 11
    {  0, gstructNPCSE_14_12 }, // 12
    {  0, gstructNPCSE_14_Default }, // 13
    {  0, gstructNPCSE_14_Default }, // 14
    {  0, gstructNPCSE_14_Default }, // 15
    {  0, gstructNPCSE_14_Default }, // 16
    {  0, gstructNPCSE_14_17 }, // 17
    {  0, gstructNPCSE_14_Default }, // 18
    {  0, gstructNPCSE_14_Default }, // 19
    {  0, gstructNPCSE_14_Default }, // 20
    {  0, gstructNPCSE_14_Default }, // 21
    {  0, gstructNPCSE_14_22 }, // 22
    {  0, gstructNPCSE_14_23 }, // 23
    {  0, gstructNPCSE_14_24 }, // 24
    {  0, gstructNPCSE_14_Default }, // 25
    {  0, gstructNPCSE_14_Default }, // 26
    {  0, gstructNPCSE_14_Default }, // 27
    {  0, gstructNPCSE_14_Sleep }, // 28
    {  0, gstructNPCSE_14_Sleep }, // 29
    {  0, gstructNPCSE_14_DeadSleep }, // 30
    {  0, gstructNPCSE_14_DeadSleep }, // 31
    {  0, gstructNPCSE_14_DeadSleep } // 32
};


//
// NPCs 15-17, Stevedores (common)
//

struct  statedata_NPCSchElement gstructNPCSE_SD_Sleep[] =
{
    { STATEACTION_SLP_A, 22,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_DeadSleep[] =
{
    { STATEACTION_SLP_D, 22,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_Rest[] =
{
    { STATEACTION_RES_N, 22,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_WorkW[] =
{
    { STATEACTION_WRK_A, 21,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_WorkB[] =
{
    { STATEACTION_WRK_A, 24,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_TavernH[] =
{
    { STATEACTION_HNG_N, 27,  3 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_TavernE[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_TavernD[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_SD_TavRecover[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_D, 22,  2 },
    { -1, -1, -1 }
};


//
// NPC-15 = Stevedore-Quon
//

struct  statedata_NPCSchElement gstructNPCSE_15_12[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  2 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_15_18[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-15 = Stevedore-Quon
struct  statedata_NPCSchBase gstructNPCSB_15[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_SD_DeadSleep }, // 01
    {  0, gstructNPCSE_SD_DeadSleep }, // 02
    {  0, gstructNPCSE_SD_DeadSleep }, // 03
    {  0, gstructNPCSE_SD_DeadSleep }, // 04
    {  0, gstructNPCSE_SD_DeadSleep }, // 05
    {  0, gstructNPCSE_SD_DeadSleep }, // 06
    {  0, gstructNPCSE_SD_DeadSleep }, // 07
    {  0, gstructNPCSE_SD_DeadSleep }, // 08
    {  0, gstructNPCSE_SD_DeadSleep }, // 09
    {  0, gstructNPCSE_SD_Sleep }, // 10
    {  0, gstructNPCSE_SD_Sleep }, // 11
    {  0, gstructNPCSE_15_12 }, // 12
    {  0, gstructNPCSE_SD_WorkB }, // 13
    {  0, gstructNPCSE_SD_TavernH }, // 14
    {  0, gstructNPCSE_SD_WorkW }, // 15
    {  0, gstructNPCSE_SD_WorkW }, // 16
    {  0, gstructNPCSE_SD_WorkW }, // 17
    {  0, gstructNPCSE_15_18 }, // 18
    {  0, gstructNPCSE_SD_WorkW }, // 19
    {  0, gstructNPCSE_SD_WorkW }, // 20
    {  0, gstructNPCSE_SD_WorkW }, // 21
    {  0, gstructNPCSE_SD_WorkW }, // 22
    {  0, gstructNPCSE_SD_WorkW }, // 23
    {  0, gstructNPCSE_SD_WorkW }, // 24
    {  0, gstructNPCSE_SD_TavernE }, // 25
    {  0, gstructNPCSE_SD_TavernH }, // 26
    {  0, gstructNPCSE_SD_Rest }, // 27
    {  0, gstructNPCSE_SD_Rest }, // 28
    {  0, gstructNPCSE_SD_TavernD }, // 29
    {  0, gstructNPCSE_SD_TavernD }, // 30
    {  0, gstructNPCSE_SD_TavRecover }, // 31
    {  0, gstructNPCSE_SD_Sleep } // 32
};


//
// NPC-16 = Stevedore-Norris
//

struct  statedata_NPCSchElement gstructNPCSE_16_11[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-16 = Stevedore-Norris
struct  statedata_NPCSchBase gstructNPCSB_16[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_SD_DeadSleep }, // 01
    {  0, gstructNPCSE_SD_DeadSleep }, // 02
    {  0, gstructNPCSE_SD_DeadSleep }, // 03
    {  0, gstructNPCSE_SD_DeadSleep }, // 04
    {  0, gstructNPCSE_SD_DeadSleep }, // 05
    {  0, gstructNPCSE_SD_DeadSleep }, // 06
    {  0, gstructNPCSE_SD_DeadSleep }, // 07
    {  0, gstructNPCSE_SD_DeadSleep }, // 08
    {  0, gstructNPCSE_SD_Sleep }, // 09
    {  0, gstructNPCSE_SD_Sleep }, // 10
    {  0, gstructNPCSE_16_11 }, // 11
    {  0, gstructNPCSE_SD_WorkB }, // 12
    {  0, gstructNPCSE_SD_TavernH }, // 13
    {  0, gstructNPCSE_SD_WorkW }, // 14
    {  0, gstructNPCSE_SD_WorkW }, // 15
    {  0, gstructNPCSE_SD_WorkB }, // 16
    {  0, gstructNPCSE_SD_TavernE }, // 17
    {  0, gstructNPCSE_SD_WorkW }, // 18
    {  0, gstructNPCSE_SD_WorkB }, // 19
    {  0, gstructNPCSE_SD_TavernH }, // 20
    {  0, gstructNPCSE_SD_WorkW }, // 21
    {  0, gstructNPCSE_SD_WorkB }, // 22
    {  0, gstructNPCSE_SD_TavernH }, // 23
    {  0, gstructNPCSE_SD_TavernE }, // 24
    {  0, gstructNPCSE_SD_TavernD }, // 25
    {  0, gstructNPCSE_SD_Rest }, // 26
    {  0, gstructNPCSE_SD_Rest }, // 27
    {  0, gstructNPCSE_SD_TavernD }, // 28
    {  0, gstructNPCSE_SD_TavernD }, // 29
    {  0, gstructNPCSE_SD_TavRecover }, // 30
    {  0, gstructNPCSE_SD_Sleep }, // 31
    {  0, gstructNPCSE_SD_DeadSleep } // 32
};


//
// NPC-17 = Stevedore-Jamar
//

struct  statedata_NPCSchElement gstructNPCSE_17_10[] =
{
    { STATEACTION_EAT_N, 27,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_17_17[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_17_19[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_17_21[] =
{
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-17 = Stevedore-Jamar
struct  statedata_NPCSchBase gstructNPCSB_17[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_SD_DeadSleep }, // 01
    {  0, gstructNPCSE_SD_DeadSleep }, // 02
    {  0, gstructNPCSE_SD_DeadSleep }, // 03
    {  0, gstructNPCSE_SD_DeadSleep }, // 04
    {  0, gstructNPCSE_SD_DeadSleep }, // 05
    {  0, gstructNPCSE_SD_DeadSleep }, // 06
    {  0, gstructNPCSE_SD_DeadSleep }, // 07
    {  0, gstructNPCSE_SD_Sleep }, // 08
    {  0, gstructNPCSE_SD_Sleep }, // 09
    {  0, gstructNPCSE_17_10 }, // 10
    {  0, gstructNPCSE_SD_WorkW }, // 11
    {  0, gstructNPCSE_SD_WorkW }, // 12
    {  0, gstructNPCSE_SD_WorkW }, // 13
    {  0, gstructNPCSE_SD_WorkB }, // 14
    {  0, gstructNPCSE_SD_TavernE }, // 15
    {  0, gstructNPCSE_SD_WorkW }, // 16
    {  0, gstructNPCSE_17_17 }, // 17
    {  0, gstructNPCSE_SD_WorkW }, // 18
    {  0, gstructNPCSE_17_19 }, // 19
    {  0, gstructNPCSE_SD_WorkW }, // 20
    {  0, gstructNPCSE_17_21 }, // 21
    {  0, gstructNPCSE_SD_WorkW }, // 22
    {  0, gstructNPCSE_SD_TavernE }, // 23
    {  0, gstructNPCSE_SD_TavernD }, // 24
    {  0, gstructNPCSE_SD_Rest }, // 25
    {  0, gstructNPCSE_SD_Rest }, // 26
    {  0, gstructNPCSE_SD_TavernD }, // 27
    {  0, gstructNPCSE_SD_TavernD }, // 28
    {  0, gstructNPCSE_SD_TavRecover }, // 29
    {  0, gstructNPCSE_SD_Sleep }, // 30
    {  0, gstructNPCSE_SD_DeadSleep }, // 31
    {  0, gstructNPCSE_SD_DeadSleep } // 32
};


//
// NPCs 18-20, Brewery workers (common)
//

struct  statedata_NPCSchElement gstructNPCSE_BW_Sleep[] =
{
    { STATEACTION_SLP_A, 25,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_DeadSleep[] =
{
    { STATEACTION_SLP_D, 25,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_Rest[] =
{
    { STATEACTION_RES_N, 25,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_RestB[] =
{
    { STATEACTION_RES_N, 24,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_TavernR[] =
{
    { STATEACTION_RES_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_WorkB[] =
{
    { STATEACTION_WRK_A, 24,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_Workshop[] =
{
    { STATEACTION_HNG_N, 36,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_TavernE[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BW_TavernA[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_D, 25,  2 },
    { -1, -1, -1 }
};


//
// NPC-18 = Brewer-Tuan
//

struct  statedata_NPCSchElement gstructNPCSE_18_11[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_18_18[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_18_13[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-18 = Brewer-Tuan
struct  statedata_NPCSchBase gstructNPCSB_18[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BW_DeadSleep }, // 01
    {  0, gstructNPCSE_BW_DeadSleep }, // 02
    {  0, gstructNPCSE_BW_DeadSleep }, // 03
    {  0, gstructNPCSE_BW_DeadSleep }, // 04
    {  0, gstructNPCSE_BW_DeadSleep }, // 05
    {  0, gstructNPCSE_BW_DeadSleep }, // 06
    {  0, gstructNPCSE_BW_DeadSleep }, // 07
    {  0, gstructNPCSE_BW_Sleep }, // 08
    {  0, gstructNPCSE_BW_Sleep }, // 09
    {  0, gstructNPCSE_BW_WorkB }, // 10
    {  0, gstructNPCSE_18_11 }, // 11
    {  0, gstructNPCSE_BW_WorkB }, // 12
    {  0, gstructNPCSE_18_13 }, // 13
    {  0, gstructNPCSE_BW_WorkB }, // 14
    {  0, gstructNPCSE_BW_WorkB }, // 15
    {  0, gstructNPCSE_BW_Workshop }, // 16
    {  0, gstructNPCSE_BW_WorkB }, // 17
    {  0, gstructNPCSE_18_18 }, // 18
    {  0, gstructNPCSE_BW_RestB }, // 19
    {  0, gstructNPCSE_BW_WorkB }, // 20
    {  0, gstructNPCSE_BW_WorkB }, // 21
    {  0, gstructNPCSE_BW_RestB }, // 22
    {  0, gstructNPCSE_BW_WorkB }, // 23
    {  0, gstructNPCSE_BW_Rest }, // 24
    {  0, gstructNPCSE_BW_Rest }, // 25
    {  0, gstructNPCSE_BW_TavernE }, // 26
    {  0, gstructNPCSE_BW_TavernA }, // 27
    {  0, gstructNPCSE_BW_Rest }, // 28
    {  0, gstructNPCSE_BW_Sleep }, // 29
    {  0, gstructNPCSE_BW_DeadSleep }, // 30
    {  0, gstructNPCSE_BW_DeadSleep }, // 31
    {  0, gstructNPCSE_BW_DeadSleep } // 32
};


//
// NPC-19 = Vinter-Kadeem
//

struct  statedata_NPCSchElement gstructNPCSE_19_10[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_19_14[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-19 = Vinter-Kadeem
struct  statedata_NPCSchBase gstructNPCSB_19[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BW_DeadSleep }, // 01
    {  0, gstructNPCSE_BW_DeadSleep }, // 02
    {  0, gstructNPCSE_BW_DeadSleep }, // 03
    {  0, gstructNPCSE_BW_DeadSleep }, // 04
    {  0, gstructNPCSE_BW_DeadSleep }, // 05
    {  0, gstructNPCSE_BW_DeadSleep }, // 06
    {  0, gstructNPCSE_BW_DeadSleep }, // 07
    {  0, gstructNPCSE_BW_Sleep }, // 08
    {  0, gstructNPCSE_BW_Sleep }, // 09
    {  0, gstructNPCSE_19_10 }, // 10
    {  0, gstructNPCSE_BW_WorkB }, // 11
    {  0, gstructNPCSE_BW_WorkB }, // 12
    {  0, gstructNPCSE_BW_WorkB }, // 13
    {  0, gstructNPCSE_19_14 }, // 14
    {  0, gstructNPCSE_BW_WorkB }, // 15
    {  0, gstructNPCSE_BW_WorkB }, // 16
    {  0, gstructNPCSE_BW_TavernE }, // 17
    {  0, gstructNPCSE_BW_TavernR }, // 18
    {  0, gstructNPCSE_BW_WorkB }, // 19
    {  0, gstructNPCSE_BW_WorkB }, // 20
    {  0, gstructNPCSE_BW_RestB }, // 21
    {  0, gstructNPCSE_BW_Workshop }, // 22
    {  0, gstructNPCSE_BW_WorkB }, // 23
    {  0, gstructNPCSE_BW_WorkB }, // 24
    {  0, gstructNPCSE_BW_TavernE }, // 25
    {  0, gstructNPCSE_BW_TavernR }, // 26
    {  0, gstructNPCSE_BW_TavernR }, // 27
    {  0, gstructNPCSE_BW_Rest }, // 28
    {  0, gstructNPCSE_BW_Rest }, // 29
    {  0, gstructNPCSE_BW_Sleep }, // 30
    {  0, gstructNPCSE_BW_DeadSleep }, // 31
    {  0, gstructNPCSE_BW_DeadSleep } // 32
};


//
// NPC-20 = Cooper-Erick
//

struct  statedata_NPCSchElement gstructNPCSE_20_11[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_20_13[] =
{
    { STATEACTION_HNG_N, 41,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_20_21[] =
{
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_20_22[] =
{
    { STATEACTION_RES_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_20_2829[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_20_30[] =
{
    { STATEACTION_RES_D, 27,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-20 = Cooper-Erick
struct  statedata_NPCSchBase gstructNPCSB_20[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BW_DeadSleep }, // 01
    {  0, gstructNPCSE_BW_DeadSleep }, // 02
    {  0, gstructNPCSE_BW_DeadSleep }, // 03
    {  0, gstructNPCSE_BW_DeadSleep }, // 04
    {  0, gstructNPCSE_BW_DeadSleep }, // 05
    {  0, gstructNPCSE_BW_DeadSleep }, // 06
    {  0, gstructNPCSE_BW_DeadSleep }, // 07
    {  0, gstructNPCSE_BW_DeadSleep }, // 08
    {  0, gstructNPCSE_BW_Sleep }, // 09
    {  0, gstructNPCSE_BW_Sleep }, // 10
    {  0, gstructNPCSE_20_11 }, // 11
    {  0, gstructNPCSE_BW_WorkB }, // 12
    {  0, gstructNPCSE_20_13 }, // 13
    {  0, gstructNPCSE_BW_WorkB }, // 14
    {  0, gstructNPCSE_BW_Workshop }, // 15
    {  0, gstructNPCSE_BW_WorkB }, // 16
    {  0, gstructNPCSE_BW_TavernE }, // 17
    {  0, gstructNPCSE_BW_WorkB }, // 18
    {  0, gstructNPCSE_BW_RestB }, // 19
    {  0, gstructNPCSE_BW_WorkB }, // 20
    {  0, gstructNPCSE_20_21 }, // 21
    {  0, gstructNPCSE_20_22 }, // 22
    {  0, gstructNPCSE_BW_WorkB }, // 23
    {  0, gstructNPCSE_BW_WorkB }, // 24
    {  0, gstructNPCSE_BW_TavernE }, // 25
    {  0, gstructNPCSE_BW_TavernR }, // 26
    {  0, gstructNPCSE_BW_WorkB }, // 27
    {  0, gstructNPCSE_20_2829 }, // 28
    {  0, gstructNPCSE_20_2829 }, // 29
    {  0, gstructNPCSE_20_30 }, // 30
    {  0, gstructNPCSE_BW_Sleep }, // 31
    {  0, gstructNPCSE_BW_DeadSleep } // 32
};


//
// NPC-21 = Tavern Keeper-Izaiah
//

struct  statedata_NPCSchElement gstructNPCSE_21_Sleep[] =
{
    { STATEACTION_SLP_A, 29,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_21_DeadSleep[] =
{
    { STATEACTION_SLP_D, 29,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_21_Default[] =
{
    { STATEACTION_WRK_A, 28,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_21_Rest[] =
{
    { STATEACTION_RES_N, 29,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-21 = Tavern Keeper-Izaiah
struct  statedata_NPCSchBase gstructNPCSB_21[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_21_Sleep }, // 01
    {  0, gstructNPCSE_21_DeadSleep }, // 02
    {  0, gstructNPCSE_21_DeadSleep }, // 03
    {  0, gstructNPCSE_21_DeadSleep }, // 04
    {  0, gstructNPCSE_21_DeadSleep }, // 05
    {  0, gstructNPCSE_21_DeadSleep }, // 06
    {  0, gstructNPCSE_21_DeadSleep }, // 07
    {  0, gstructNPCSE_21_DeadSleep }, // 08
    {  0, gstructNPCSE_21_Sleep }, // 09
    {  0, gstructNPCSE_21_Default }, // 10
    {  0, gstructNPCSE_21_Default }, // 11
    {  0, gstructNPCSE_21_Default }, // 12
    {  0, gstructNPCSE_21_Default }, // 13
    {  0, gstructNPCSE_21_Default }, // 14
    {  0, gstructNPCSE_21_Default }, // 15
    {  0, gstructNPCSE_21_Default }, // 16
    {  0, gstructNPCSE_21_Default }, // 17
    {  0, gstructNPCSE_21_Default }, // 18
    {  0, gstructNPCSE_21_Default }, // 19
    {  0, gstructNPCSE_21_Rest }, // 20
    {  0, gstructNPCSE_21_Rest }, // 21
    {  0, gstructNPCSE_21_Rest }, // 22
    {  0, gstructNPCSE_21_Default }, // 23
    {  0, gstructNPCSE_21_Default }, // 24
    {  0, gstructNPCSE_21_Default }, // 25
    {  0, gstructNPCSE_21_Default }, // 26
    {  0, gstructNPCSE_21_Default }, // 27
    {  0, gstructNPCSE_21_Default }, // 28
    {  0, gstructNPCSE_21_Default }, // 29
    {  0, gstructNPCSE_21_Default }, // 30
    {  0, gstructNPCSE_21_Default }, // 31
    {  0, gstructNPCSE_21_Default } // 32
};


//
// NPCs 22-24, Kitchen workers (common)
//

struct  statedata_NPCSchElement gstructNPCSE_KW_Sleep[] =
{
    { STATEACTION_SLP_A, 33,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_KW_DeadSleep[] =
{
    { STATEACTION_SLP_D, 33,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_KW_Rest[] =
{
    { STATEACTION_RES_N, 33,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_KW_Working[] =
{
    { STATEACTION_WRK_A, 32,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_KW_TavernHelp[] =
{
    { STATEACTION_WRK_A, 28,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_KW_Tavern[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

//
// NPC-22 = Fishmonger-Mack
//

struct  statedata_NPCSchElement gstructNPCSE_22_13[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_22_18[] =
{
    { STATEACTION_RES_N, 33,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-22 = Fishmonger-Mack
struct  statedata_NPCSchBase gstructNPCSB_22[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_KW_DeadSleep }, // 01
    {  0, gstructNPCSE_KW_DeadSleep }, // 02
    {  0, gstructNPCSE_KW_DeadSleep }, // 03
    {  0, gstructNPCSE_KW_DeadSleep }, // 04
    {  0, gstructNPCSE_KW_DeadSleep }, // 05
    {  0, gstructNPCSE_KW_DeadSleep }, // 06
    {  0, gstructNPCSE_KW_DeadSleep }, // 07
    {  0, gstructNPCSE_KW_DeadSleep }, // 08
    {  0, gstructNPCSE_KW_Sleep }, // 09
    {  0, gstructNPCSE_KW_Working }, // 10
    {  0, gstructNPCSE_KW_Working }, // 11
    {  0, gstructNPCSE_KW_Working }, // 12
    {  0, gstructNPCSE_22_13 }, // 13
    {  0, gstructNPCSE_KW_Working }, // 14
    {  0, gstructNPCSE_KW_Working }, // 15
    {  0, gstructNPCSE_KW_Working }, // 16
    {  0, gstructNPCSE_KW_Tavern }, // 17
    {  0, gstructNPCSE_22_18 }, // 18
    {  0, gstructNPCSE_KW_Working }, // 19
    {  0, gstructNPCSE_KW_Working }, // 20
    {  0, gstructNPCSE_KW_Rest }, // 21
    {  0, gstructNPCSE_KW_TavernHelp }, // 22
    {  0, gstructNPCSE_KW_Rest }, // 23
    {  0, gstructNPCSE_KW_Working }, // 24
    {  0, gstructNPCSE_KW_Working }, // 25
    {  0, gstructNPCSE_KW_Rest }, // 26
    {  0, gstructNPCSE_KW_Rest }, // 27
    {  0, gstructNPCSE_KW_Tavern }, // 28
    {  0, gstructNPCSE_KW_Tavern }, // 29
    {  0, gstructNPCSE_KW_Sleep }, // 30
    {  0, gstructNPCSE_KW_DeadSleep }, // 31
    {  0, gstructNPCSE_KW_DeadSleep } // 32
};


//
// NPC-23 = Baker-Rishi
//

struct  statedata_NPCSchElement gstructNPCSE_23_17[] =
{
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-23 = Baker-Rishi
struct  statedata_NPCSchBase gstructNPCSB_23[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_KW_DeadSleep }, // 01
    {  0, gstructNPCSE_KW_DeadSleep }, // 02
    {  0, gstructNPCSE_KW_DeadSleep }, // 03
    {  0, gstructNPCSE_KW_DeadSleep }, // 04
    {  0, gstructNPCSE_KW_DeadSleep }, // 05
    {  0, gstructNPCSE_KW_DeadSleep }, // 06
    {  0, gstructNPCSE_KW_Sleep }, // 07
    {  0, gstructNPCSE_KW_Working }, // 08
    {  0, gstructNPCSE_KW_Working }, // 09
    {  0, gstructNPCSE_KW_Working }, // 10
    {  0, gstructNPCSE_KW_Rest }, // 11
    {  0, gstructNPCSE_KW_Rest }, // 12
    {  0, gstructNPCSE_KW_Working }, // 13
    {  0, gstructNPCSE_KW_Rest }, // 14
    {  0, gstructNPCSE_KW_Rest }, // 15
    {  0, gstructNPCSE_KW_Tavern }, // 16
    {  0, gstructNPCSE_23_17 }, // 17
    {  0, gstructNPCSE_KW_Working }, // 18
    {  0, gstructNPCSE_KW_Working }, // 19
    {  0, gstructNPCSE_KW_Working }, // 20
    {  0, gstructNPCSE_KW_TavernHelp }, // 21
    {  0, gstructNPCSE_KW_Working }, // 22
    {  0, gstructNPCSE_KW_Working }, // 23
    {  0, gstructNPCSE_KW_Tavern }, // 24
    {  0, gstructNPCSE_KW_Tavern }, // 25
    {  0, gstructNPCSE_KW_Rest }, // 26
    {  0, gstructNPCSE_KW_Rest }, // 27
    {  0, gstructNPCSE_KW_Sleep }, // 28
    {  0, gstructNPCSE_KW_DeadSleep }, // 29
    {  0, gstructNPCSE_KW_DeadSleep }, // 30
    {  0, gstructNPCSE_KW_DeadSleep }, // 31
    {  0, gstructNPCSE_KW_DeadSleep } // 32
};


//
// NPC-24 = Butcher-Jered
//

struct  statedata_NPCSchElement gstructNPCSE_24_10[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_24_18[] =
{
    { STATEACTION_HNG_N, 43,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-24 = Butcher-Jered
struct  statedata_NPCSchBase gstructNPCSB_24[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_KW_DeadSleep }, // 01
    {  0, gstructNPCSE_KW_DeadSleep }, // 02
    {  0, gstructNPCSE_KW_DeadSleep }, // 03
    {  0, gstructNPCSE_KW_DeadSleep }, // 04
    {  0, gstructNPCSE_KW_DeadSleep }, // 05
    {  0, gstructNPCSE_KW_DeadSleep }, // 06
    {  0, gstructNPCSE_KW_DeadSleep }, // 07
    {  0, gstructNPCSE_KW_Sleep }, // 08
    {  0, gstructNPCSE_KW_Rest }, // 09
    {  0, gstructNPCSE_24_10 }, // 10
    {  0, gstructNPCSE_KW_Working }, // 11
    {  0, gstructNPCSE_KW_Working }, // 12
    {  0, gstructNPCSE_KW_Working }, // 13
    {  0, gstructNPCSE_KW_Rest }, // 14
    {  0, gstructNPCSE_KW_Tavern }, // 15
    {  0, gstructNPCSE_KW_Working }, // 16
    {  0, gstructNPCSE_KW_Working }, // 17
    {  0, gstructNPCSE_24_18 }, // 18
    {  0, gstructNPCSE_KW_Working }, // 19
    {  0, gstructNPCSE_KW_TavernHelp }, // 20
    {  0, gstructNPCSE_KW_Working }, // 21
    {  0, gstructNPCSE_KW_Working }, // 22
    {  0, gstructNPCSE_KW_Working }, // 23
    {  0, gstructNPCSE_KW_Rest }, // 24
    {  0, gstructNPCSE_KW_Rest }, // 25
    {  0, gstructNPCSE_KW_Tavern }, // 26
    {  0, gstructNPCSE_KW_Tavern }, // 27
    {  0, gstructNPCSE_KW_Rest }, // 28
    {  0, gstructNPCSE_KW_Sleep }, // 29
    {  0, gstructNPCSE_KW_DeadSleep }, // 30
    {  0, gstructNPCSE_KW_DeadSleep }, // 31
    {  0, gstructNPCSE_KW_DeadSleep } // 32
};


//
// NPCs 25-27, Workshop workers (common)
//

struct  statedata_NPCSchElement gstructNPCSE_WW_Sleep[] =
{
    { STATEACTION_SLP_A, 37,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_WW_DeadSleep[] =
{
    { STATEACTION_SLP_D, 37,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_WW_Rest[] =
{
    { STATEACTION_RES_N, 37,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_WW_Working[] =
{
    { STATEACTION_WRK_A, 36,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_WW_Tavern[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};


//
// NPC-25 = Carpenter-Bryan
//

struct  statedata_NPCSchElement gstructNPCSE_25_11[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_25_16[] =
{
    { STATEACTION_HNG_N, 41,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_25_17[] =
{
    { STATEACTION_RES_N, 37,  1 },
    { STATEACTION_HNG_N,  6,  1 },
    { STATEACTION_HNG_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_25_21[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_25_27[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N,  4,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-25 = Carpenter-Bryan
struct  statedata_NPCSchBase gstructNPCSB_25[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_WW_DeadSleep }, // 01
    {  0, gstructNPCSE_WW_DeadSleep }, // 02
    {  0, gstructNPCSE_WW_DeadSleep }, // 03
    {  0, gstructNPCSE_WW_DeadSleep }, // 04
    {  0, gstructNPCSE_WW_DeadSleep }, // 05
    {  0, gstructNPCSE_WW_DeadSleep }, // 06
    {  0, gstructNPCSE_WW_DeadSleep }, // 07
    {  0, gstructNPCSE_WW_DeadSleep }, // 08
    {  0, gstructNPCSE_WW_DeadSleep }, // 09
    {  0, gstructNPCSE_WW_Sleep }, // 10
    {  0, gstructNPCSE_25_11 }, // 11
    {  0, gstructNPCSE_WW_Rest }, // 12
    {  0, gstructNPCSE_WW_Working }, // 13
    {  0, gstructNPCSE_WW_Working }, // 14
    {  0, gstructNPCSE_WW_Rest }, // 15
    {  0, gstructNPCSE_25_16 }, // 16
    {  0, gstructNPCSE_25_17 }, // 17
    {  0, gstructNPCSE_WW_Working }, // 18
    {  0, gstructNPCSE_WW_Working }, // 19
    {  0, gstructNPCSE_WW_Working }, // 20
    {  0, gstructNPCSE_25_21 }, // 21
    {  0, gstructNPCSE_WW_Tavern }, // 22
    {  0, gstructNPCSE_WW_Rest }, // 23
    {  0, gstructNPCSE_WW_Working }, // 24
    {  0, gstructNPCSE_WW_Rest }, // 25
    {  0, gstructNPCSE_WW_Rest }, // 26
    {  0, gstructNPCSE_25_27 }, // 27
    {  0, gstructNPCSE_WW_Rest }, // 28
    {  0, gstructNPCSE_WW_Rest }, // 29
    {  0, gstructNPCSE_WW_Rest }, // 30
    {  0, gstructNPCSE_WW_Sleep }, // 31
    {  0, gstructNPCSE_WW_DeadSleep } // 32
};


//
// NPC-26 = Blacksmith-Harvir
//

struct  statedata_NPCSchElement gstructNPCSE_26_10[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_26_11[] =
{
    { STATEACTION_HNG_N, 41,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_26_13[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 23,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_26_18[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_26_20[] =
{
    { STATEACTION_HNG_N, 55,  1 },
    { STATEACTION_HNG_N, 46,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_26_23[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-26 = Blacksmith-Harvir
struct  statedata_NPCSchBase gstructNPCSB_26[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_WW_DeadSleep }, // 01
    {  0, gstructNPCSE_WW_DeadSleep }, // 02
    {  0, gstructNPCSE_WW_DeadSleep }, // 03
    {  0, gstructNPCSE_WW_DeadSleep }, // 04
    {  0, gstructNPCSE_WW_DeadSleep }, // 05
    {  0, gstructNPCSE_WW_Sleep }, // 06
    {  0, gstructNPCSE_WW_DeadSleep }, // 07
    {  0, gstructNPCSE_WW_DeadSleep }, // 08
    {  0, gstructNPCSE_WW_Sleep }, // 09
    {  0, gstructNPCSE_26_10 }, // 10
    {  0, gstructNPCSE_26_11 }, // 11
    {  0, gstructNPCSE_WW_Working }, // 12
    {  0, gstructNPCSE_26_13 }, // 13
    {  0, gstructNPCSE_WW_Rest }, // 14
    {  0, gstructNPCSE_WW_Working }, // 15
    {  0, gstructNPCSE_WW_Working }, // 16
    {  0, gstructNPCSE_WW_Rest }, // 17
    {  0, gstructNPCSE_26_18 }, // 18
    {  0, gstructNPCSE_WW_Working }, // 19
    {  0, gstructNPCSE_26_20 }, // 20
    {  0, gstructNPCSE_WW_Rest }, // 21
    {  0, gstructNPCSE_WW_Tavern }, // 22
    {  0, gstructNPCSE_26_23 }, // 23
    {  0, gstructNPCSE_WW_Rest }, // 24
    {  0, gstructNPCSE_WW_Tavern }, // 25
    {  0, gstructNPCSE_WW_Rest }, // 26
    {  0, gstructNPCSE_WW_Rest }, // 27
    {  0, gstructNPCSE_WW_Tavern }, // 28
    {  0, gstructNPCSE_WW_Rest }, // 29
    {  0, gstructNPCSE_WW_Sleep }, // 30
    {  0, gstructNPCSE_WW_DeadSleep }, // 31
    {  0, gstructNPCSE_WW_DeadSleep } // 32
};


//
// NPC-27 = Tinker-Viktor
//

struct  statedata_NPCSchElement gstructNPCSE_27_09[] =
{
    { STATEACTION_RES_N, 37,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_27_13[] =
{
    { STATEACTION_HNG_N, 24,  1 },
    { STATEACTION_HNG_N, 21,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_27_14[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_27_19[] =
{
    { STATEACTION_HNG_N,  5,  1 },
    { STATEACTION_HNG_N,  6,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_27_24[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-27 = Tinker-Viktor
struct  statedata_NPCSchBase gstructNPCSB_27[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_WW_DeadSleep }, // 01
    {  0, gstructNPCSE_WW_DeadSleep }, // 02
    {  0, gstructNPCSE_WW_DeadSleep }, // 03
    {  0, gstructNPCSE_WW_DeadSleep }, // 04
    {  0, gstructNPCSE_WW_DeadSleep }, // 05
    {  0, gstructNPCSE_WW_DeadSleep }, // 06
    {  0, gstructNPCSE_WW_DeadSleep }, // 07
    {  0, gstructNPCSE_WW_Sleep }, // 08
    {  0, gstructNPCSE_27_09 }, // 09
    {  0, gstructNPCSE_WW_Rest }, // 10
    {  0, gstructNPCSE_WW_Working }, // 11
    {  0, gstructNPCSE_WW_Rest }, // 12
    {  0, gstructNPCSE_27_13 }, // 13
    {  0, gstructNPCSE_27_14 }, // 14
    {  0, gstructNPCSE_WW_Rest }, // 15
    {  0, gstructNPCSE_WW_Working }, // 16
    {  0, gstructNPCSE_WW_Working }, // 17
    {  0, gstructNPCSE_WW_Working }, // 18
    {  0, gstructNPCSE_27_19 }, // 19
    {  0, gstructNPCSE_WW_Rest }, // 20
    {  0, gstructNPCSE_WW_Working }, // 21
    {  0, gstructNPCSE_WW_Working }, // 22
    {  0, gstructNPCSE_WW_Working }, // 23
    {  0, gstructNPCSE_27_24 }, // 24
    {  0, gstructNPCSE_WW_Tavern }, // 25
    {  0, gstructNPCSE_WW_Working }, // 26
    {  0, gstructNPCSE_WW_Working }, // 27
    {  0, gstructNPCSE_WW_Rest }, // 28
    {  0, gstructNPCSE_WW_Sleep }, // 29
    {  0, gstructNPCSE_WW_DeadSleep }, // 30
    {  0, gstructNPCSE_WW_DeadSleep }, // 31
    {  0, gstructNPCSE_WW_DeadSleep } // 32
};


//
// NPCs 28-31, Herdsmen (common)
//

struct  statedata_NPCSchElement gstructNPCSE_HE_Sleep[] =
{
    { STATEACTION_SLP_A, 40,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HE_DeadSleep[] =
{
    { STATEACTION_SLP_D, 40,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HE_Rest[] =
{
    { STATEACTION_RES_N, 40,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HE_Working[] =
{
    { STATEACTION_WRK_A, 39,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HE_Tavern[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};


//
// NPC-28 = Herdsman-Cecil
//

struct  statedata_NPCSchElement gstructNPCSE_28_11[] =
{
    { STATEACTION_HNG_N, 43,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_28_13[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_28_14[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_28_16[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_28_23[] =
{
    { STATEACTION_EAT_N, 27,  2 },
    { STATEACTION_EAT_N, 26,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-28 = Herdsman-Cecil
struct  statedata_NPCSchBase gstructNPCSB_28[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HE_DeadSleep }, // 01
    {  0, gstructNPCSE_HE_DeadSleep }, // 02
    {  0, gstructNPCSE_HE_DeadSleep }, // 03
    {  0, gstructNPCSE_HE_DeadSleep }, // 04
    {  0, gstructNPCSE_HE_DeadSleep }, // 05
    {  0, gstructNPCSE_HE_Sleep }, // 06
    {  0, gstructNPCSE_HE_Sleep }, // 07
    {  0, gstructNPCSE_HE_Sleep }, // 08
    {  0, gstructNPCSE_HE_Sleep }, // 09
    {  0, gstructNPCSE_HE_Rest }, // 10
    {  0, gstructNPCSE_28_11 }, // 11
    {  0, gstructNPCSE_HE_Rest }, // 12
    {  0, gstructNPCSE_28_13 }, // 13
    {  0, gstructNPCSE_28_14 }, // 14
    {  0, gstructNPCSE_HE_Rest }, // 15
    {  0, gstructNPCSE_28_16 }, // 16
    {  0, gstructNPCSE_HE_Rest }, // 17
    {  0, gstructNPCSE_HE_Working }, // 18
    {  0, gstructNPCSE_HE_Rest }, // 19
    {  0, gstructNPCSE_HE_Working }, // 20
    {  0, gstructNPCSE_HE_Rest }, // 21
    {  0, gstructNPCSE_HE_Working }, // 22
    {  0, gstructNPCSE_28_23 }, // 23
    {  0, gstructNPCSE_HE_Working }, // 24
    {  0, gstructNPCSE_HE_Rest }, // 25
    {  0, gstructNPCSE_HE_Working }, // 26
    {  0, gstructNPCSE_HE_Rest }, // 27
    {  0, gstructNPCSE_HE_Tavern }, // 28
    {  0, gstructNPCSE_HE_Sleep }, // 29
    {  0, gstructNPCSE_HE_DeadSleep }, // 30
    {  0, gstructNPCSE_HE_DeadSleep }, // 31
    {  0, gstructNPCSE_HE_DeadSleep } // 32
};


//
// NPC-29 = Herdsman-Anders
//

struct  statedata_NPCSchElement gstructNPCSE_29_09[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_29_18[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_29_22[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_29_23[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-29 = Herdsman-Anders
struct  statedata_NPCSchBase gstructNPCSB_29[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HE_DeadSleep }, // 01
    {  0, gstructNPCSE_HE_DeadSleep }, // 02
    {  0, gstructNPCSE_HE_DeadSleep }, // 03
    {  0, gstructNPCSE_HE_DeadSleep }, // 04
    {  0, gstructNPCSE_HE_Sleep }, // 05
    {  0, gstructNPCSE_HE_Rest }, // 06
    {  0, gstructNPCSE_HE_Working }, // 07
    {  0, gstructNPCSE_HE_Rest }, // 08
    {  0, gstructNPCSE_29_09 }, // 09
    {  0, gstructNPCSE_HE_Working }, // 10
    {  0, gstructNPCSE_HE_Rest }, // 11
    {  0, gstructNPCSE_HE_Working }, // 12
    {  0, gstructNPCSE_HE_Rest }, // 13
    {  0, gstructNPCSE_HE_Working }, // 14
    {  0, gstructNPCSE_HE_Rest }, // 15
    {  0, gstructNPCSE_HE_Working }, // 16
    {  0, gstructNPCSE_HE_Rest }, // 17
    {  0, gstructNPCSE_29_18 }, // 18
    {  0, gstructNPCSE_HE_Rest }, // 19
    {  0, gstructNPCSE_HE_Tavern }, // 20
    {  0, gstructNPCSE_HE_Tavern }, // 21
    {  0, gstructNPCSE_29_22 }, // 22
    {  0, gstructNPCSE_29_23 }, // 23
    {  0, gstructNPCSE_HE_Rest }, // 24
    {  0, gstructNPCSE_HE_Rest }, // 25
    {  0, gstructNPCSE_HE_Sleep }, // 26
    {  0, gstructNPCSE_HE_DeadSleep }, // 27
    {  0, gstructNPCSE_HE_DeadSleep }, // 28
    {  0, gstructNPCSE_HE_DeadSleep }, // 29
    {  0, gstructNPCSE_HE_DeadSleep }, // 30
    {  0, gstructNPCSE_HE_DeadSleep }, // 31
    {  0, gstructNPCSE_HE_DeadSleep } // 32
};


//
// NPC-30 = Herdsman-Franco
//

struct  statedata_NPCSchElement gstructNPCSE_30_10[] =
{
    { STATEACTION_RES_N, 40,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_30_20[] =
{
    { STATEACTION_HNG_N, 49,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_30_24[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

// Schedule: NPC-30 = Herdsman-Franco
struct  statedata_NPCSchBase gstructNPCSB_30[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HE_DeadSleep }, // 01
    {  0, gstructNPCSE_HE_DeadSleep }, // 02
    {  0, gstructNPCSE_HE_DeadSleep }, // 03
    {  0, gstructNPCSE_HE_DeadSleep }, // 04
    {  0, gstructNPCSE_HE_Sleep }, // 05
    {  0, gstructNPCSE_HE_Sleep }, // 06
    {  0, gstructNPCSE_HE_Rest }, // 07
    {  0, gstructNPCSE_HE_Rest }, // 08
    {  0, gstructNPCSE_HE_Working }, // 09
    {  0, gstructNPCSE_30_10 }, // 10
    {  0, gstructNPCSE_HE_Working }, // 11
    {  0, gstructNPCSE_HE_Rest }, // 12
    {  0, gstructNPCSE_HE_Working }, // 13
    {  0, gstructNPCSE_HE_Rest }, // 14
    {  0, gstructNPCSE_HE_Working }, // 15
    {  0, gstructNPCSE_HE_Tavern }, // 16
    {  0, gstructNPCSE_HE_Working }, // 17
    {  0, gstructNPCSE_HE_Rest }, // 18
    {  0, gstructNPCSE_HE_Rest }, // 19
    {  0, gstructNPCSE_30_20 }, // 20
    {  0, gstructNPCSE_HE_Working }, // 21
    {  0, gstructNPCSE_HE_Tavern }, // 22
    {  0, gstructNPCSE_HE_Working }, // 23
    {  0, gstructNPCSE_30_24 }, // 24
    {  0, gstructNPCSE_HE_Working }, // 25
    {  0, gstructNPCSE_HE_Rest }, // 26
    {  0, gstructNPCSE_HE_Sleep }, // 27
    {  0, gstructNPCSE_HE_DeadSleep }, // 28
    {  0, gstructNPCSE_HE_DeadSleep }, // 29
    {  0, gstructNPCSE_HE_DeadSleep }, // 30
    {  0, gstructNPCSE_HE_DeadSleep }, // 31
    {  0, gstructNPCSE_HE_DeadSleep } // 32
};


//
// NPC-31 = Herdsman-Haydn
//

struct  statedata_NPCSchElement gstructNPCSE_31_10[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_31_13[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_31_22[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-31 = Herdsman-Haydn
struct  statedata_NPCSchBase gstructNPCSB_31[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HE_Sleep }, // 01
    {  0, gstructNPCSE_HE_Rest }, // 02
    {  0, gstructNPCSE_HE_Rest }, // 03
    {  0, gstructNPCSE_HE_Working }, // 04
    {  0, gstructNPCSE_HE_Rest }, // 05
    {  0, gstructNPCSE_HE_Working }, // 06
    {  0, gstructNPCSE_HE_Rest }, // 07
    {  0, gstructNPCSE_HE_Working }, // 08
    {  0, gstructNPCSE_HE_Rest }, // 09
    {  0, gstructNPCSE_31_10 }, // 10
    {  0, gstructNPCSE_HE_Rest }, // 11
    {  0, gstructNPCSE_HE_Rest }, // 12
    {  0, gstructNPCSE_31_13 }, // 13
    {  0, gstructNPCSE_HE_Rest }, // 14
    {  0, gstructNPCSE_HE_Rest }, // 15
    {  0, gstructNPCSE_HE_Working }, // 16
    {  0, gstructNPCSE_HE_Rest }, // 17
    {  0, gstructNPCSE_HE_Working }, // 18
    {  0, gstructNPCSE_HE_Rest }, // 19
    {  0, gstructNPCSE_HE_Tavern }, // 20
    {  0, gstructNPCSE_HE_Tavern }, // 21
    {  0, gstructNPCSE_31_22 }, // 22
    {  0, gstructNPCSE_HE_Rest }, // 23
    {  0, gstructNPCSE_HE_Rest }, // 24
    {  0, gstructNPCSE_HE_Sleep }, // 25
    {  0, gstructNPCSE_HE_DeadSleep }, // 26
    {  0, gstructNPCSE_HE_DeadSleep }, // 27
    {  0, gstructNPCSE_HE_DeadSleep }, // 28
    {  0, gstructNPCSE_HE_DeadSleep }, // 29
    {  0, gstructNPCSE_HE_DeadSleep }, // 30
    {  0, gstructNPCSE_HE_DeadSleep }, // 31
    {  0, gstructNPCSE_HE_DeadSleep } // 32
};


//
// NPCs 32-35, Lumberjack (common)
//

struct  statedata_NPCSchElement gstructNPCSE_LJ_Sleep[] =
{
    { STATEACTION_SLP_A, 42,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_DeadSleep[] =
{
    { STATEACTION_SLP_D, 42,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_Rest[] =
{
    { STATEACTION_RES_N, 42,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_Working[] =
{
    { STATEACTION_WRK_A, 41,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_Working2[] =
{
    { STATEACTION_WRK_H, 45,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_Working3[] =
{
    { STATEACTION_WRK_H, 45,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { STATEACTION_WRK_A, 45,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_Working3a[] =
{
    { STATEACTION_WRK_H, 45,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_TavernD[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_LJ_TavernE[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};


//
// NPC-32 = Lumberjack-Tarik
//

struct  statedata_NPCSchElement gstructNPCSE_32_09[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_32_14[] =
{
    { STATEACTION_WRK_H, 45,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { STATEACTION_WRK_A, 45,  1 },
    { STATEACTION_RES_N, 42,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_32_19[] =
{
    { STATEACTION_WRK_H, 45,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_32_23[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-32 = Lumberjack-Tarik
struct  statedata_NPCSchBase gstructNPCSB_32[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_LJ_DeadSleep }, // 01
    {  0, gstructNPCSE_LJ_DeadSleep }, // 02
    {  0, gstructNPCSE_LJ_DeadSleep }, // 03
    {  0, gstructNPCSE_LJ_DeadSleep }, // 04
    {  0, gstructNPCSE_LJ_DeadSleep }, // 05
    {  0, gstructNPCSE_LJ_DeadSleep }, // 06
    {  0, gstructNPCSE_LJ_DeadSleep }, // 07
    {  0, gstructNPCSE_LJ_Sleep }, // 08
    {  0, gstructNPCSE_32_09 }, // 09
    {  0, gstructNPCSE_LJ_TavernD }, // 10
    {  0, gstructNPCSE_LJ_Rest }, // 11
    {  0, gstructNPCSE_LJ_Working3 }, // 12
    {  0, gstructNPCSE_LJ_Working3 }, // 13
    {  0, gstructNPCSE_32_14 }, // 14
    {  0, gstructNPCSE_LJ_Working3 }, // 15
    {  0, gstructNPCSE_LJ_Rest }, // 16
    {  0, gstructNPCSE_LJ_TavernE }, // 17
    {  0, gstructNPCSE_LJ_Working }, // 18
    {  0, gstructNPCSE_32_19 }, // 19
    {  0, gstructNPCSE_LJ_Rest }, // 20
    {  0, gstructNPCSE_LJ_Working2 }, // 21
    {  0, gstructNPCSE_LJ_Working2 }, // 22
    {  0, gstructNPCSE_32_23 }, // 23
    {  0, gstructNPCSE_LJ_Working }, // 24
    {  0, gstructNPCSE_LJ_Rest }, // 25
    {  0, gstructNPCSE_LJ_Rest }, // 26
    {  0, gstructNPCSE_LJ_TavernD }, // 27
    {  0, gstructNPCSE_LJ_TavernD }, // 28
    {  0, gstructNPCSE_LJ_Sleep }, // 29
    {  0, gstructNPCSE_LJ_DeadSleep }, // 30
    {  0, gstructNPCSE_LJ_DeadSleep }, // 31
    {  0, gstructNPCSE_LJ_DeadSleep } // 32
};


//
// NPC-33 = Lumberjack-Arjan
//

struct  statedata_NPCSchElement gstructNPCSE_33_15[] =
{
    { STATEACTION_RES_N, 42,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_33_18[] =
{
    { STATEACTION_HNG_N, 43,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-33 = Lumberjack-Arjan
struct  statedata_NPCSchBase gstructNPCSB_33[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_LJ_DeadSleep }, // 01
    {  0, gstructNPCSE_LJ_DeadSleep }, // 02
    {  0, gstructNPCSE_LJ_DeadSleep }, // 03
    {  0, gstructNPCSE_LJ_DeadSleep }, // 04
    {  0, gstructNPCSE_LJ_DeadSleep }, // 05
    {  0, gstructNPCSE_LJ_DeadSleep }, // 06
    {  0, gstructNPCSE_LJ_DeadSleep }, // 07
    {  0, gstructNPCSE_LJ_Sleep }, // 08
    {  0, gstructNPCSE_LJ_Working }, // 09
    {  0, gstructNPCSE_LJ_TavernE }, // 10
    {  0, gstructNPCSE_LJ_Working3 }, // 11
    {  0, gstructNPCSE_LJ_Working2 }, // 12
    {  0, gstructNPCSE_LJ_Working3 }, // 13
    {  0, gstructNPCSE_LJ_Working3 }, // 14
    {  0, gstructNPCSE_33_15 }, // 15
    {  0, gstructNPCSE_LJ_TavernE }, // 16
    {  0, gstructNPCSE_LJ_Working }, // 17
    {  0, gstructNPCSE_33_18 }, // 18
    {  0, gstructNPCSE_LJ_Working3a }, // 19
    {  0, gstructNPCSE_LJ_Working2 }, // 20
    {  0, gstructNPCSE_LJ_Working }, // 21
    {  0, gstructNPCSE_LJ_Rest }, // 22
    {  0, gstructNPCSE_LJ_Working }, // 23
    {  0, gstructNPCSE_LJ_TavernE }, // 24
    {  0, gstructNPCSE_LJ_Working }, // 25
    {  0, gstructNPCSE_LJ_Rest }, // 26
    {  0, gstructNPCSE_LJ_TavernD }, // 27
    {  0, gstructNPCSE_LJ_TavernD }, // 28
    {  0, gstructNPCSE_LJ_Sleep }, // 29
    {  0, gstructNPCSE_LJ_Sleep }, // 30
    {  0, gstructNPCSE_LJ_Sleep }, // 31
    {  0, gstructNPCSE_LJ_Sleep } // 32
};


//
// NPC-34 = Lumberjack-Kang
//

struct  statedata_NPCSchElement gstructNPCSE_34_09[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_34_18[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_34_23[] =
{
    { STATEACTION_RES_N, 42,  1 },
    { STATEACTION_WRK_A, 41,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-34 = Lumberjack-Kang
struct  statedata_NPCSchBase gstructNPCSB_34[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_LJ_DeadSleep }, // 01
    {  0, gstructNPCSE_LJ_DeadSleep }, // 02
    {  0, gstructNPCSE_LJ_Sleep }, // 03
    {  0, gstructNPCSE_LJ_Sleep }, // 04
    {  0, gstructNPCSE_LJ_Sleep }, // 05
    {  0, gstructNPCSE_LJ_Sleep }, // 06
    {  0, gstructNPCSE_LJ_Rest }, // 07
    {  0, gstructNPCSE_LJ_Rest }, // 08
    {  0, gstructNPCSE_34_09 }, // 09
    {  0, gstructNPCSE_LJ_TavernE }, // 10
    {  0, gstructNPCSE_LJ_Working2 }, // 11
    {  0, gstructNPCSE_LJ_Working }, // 12
    {  0, gstructNPCSE_LJ_Rest }, // 13
    {  0, gstructNPCSE_LJ_Working3 }, // 14
    {  0, gstructNPCSE_LJ_Working3 }, // 15
    {  0, gstructNPCSE_LJ_Working }, // 16
    {  0, gstructNPCSE_LJ_Working }, // 17
    {  0, gstructNPCSE_34_18 }, // 18
    {  0, gstructNPCSE_LJ_Working3a }, // 19
    {  0, gstructNPCSE_LJ_Working2 }, // 20
    {  0, gstructNPCSE_LJ_TavernE }, // 21
    {  0, gstructNPCSE_LJ_Working }, // 22
    {  0, gstructNPCSE_34_23 }, // 23
    {  0, gstructNPCSE_LJ_TavernD }, // 24
    {  0, gstructNPCSE_LJ_Rest }, // 25
    {  0, gstructNPCSE_LJ_Sleep }, // 26
    {  0, gstructNPCSE_LJ_DeadSleep }, // 27
    {  0, gstructNPCSE_LJ_DeadSleep }, // 28
    {  0, gstructNPCSE_LJ_DeadSleep }, // 29
    {  0, gstructNPCSE_LJ_DeadSleep }, // 30
    {  0, gstructNPCSE_LJ_DeadSleep }, // 31
    {  0, gstructNPCSE_LJ_DeadSleep } // 32
};


//
// NPC-35 = Lumberjack-Edwin
//

struct  statedata_NPCSchElement gstructNPCSE_35_26[] =
{
    { STATEACTION_HNG_N, 36,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-35 = Lumberjack-Edwin
struct  statedata_NPCSchBase gstructNPCSB_35[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_LJ_DeadSleep }, // 01
    {  0, gstructNPCSE_LJ_DeadSleep }, // 02
    {  0, gstructNPCSE_LJ_DeadSleep }, // 03
    {  0, gstructNPCSE_LJ_DeadSleep }, // 04
    {  0, gstructNPCSE_LJ_DeadSleep }, // 05
    {  0, gstructNPCSE_LJ_DeadSleep }, // 06
    {  0, gstructNPCSE_LJ_DeadSleep }, // 07
    {  0, gstructNPCSE_LJ_DeadSleep }, // 08
    {  0, gstructNPCSE_LJ_Sleep }, // 09
    {  0, gstructNPCSE_LJ_TavernE }, // 10
    {  0, gstructNPCSE_LJ_Working3 }, // 11
    {  0, gstructNPCSE_LJ_Working3 }, // 12
    {  0, gstructNPCSE_LJ_Working3 }, // 13
    {  0, gstructNPCSE_LJ_Rest }, // 14
    {  0, gstructNPCSE_LJ_Working3 }, // 15
    {  0, gstructNPCSE_LJ_Rest }, // 16
    {  0, gstructNPCSE_LJ_Working }, // 17
    {  0, gstructNPCSE_LJ_Working }, // 18
    {  0, gstructNPCSE_LJ_TavernE }, // 19
    {  0, gstructNPCSE_LJ_Working2 }, // 20
    {  0, gstructNPCSE_LJ_Working2 }, // 21
    {  0, gstructNPCSE_LJ_TavernD }, // 22
    {  0, gstructNPCSE_LJ_TavernD }, // 23
    {  0, gstructNPCSE_LJ_Working }, // 24
    {  0, gstructNPCSE_LJ_Working }, // 25
    {  0, gstructNPCSE_35_26 }, // 26
    {  0, gstructNPCSE_LJ_TavernE }, // 27
    {  0, gstructNPCSE_LJ_Rest }, // 28
    {  0, gstructNPCSE_LJ_TavernD }, // 29
    {  0, gstructNPCSE_LJ_Sleep }, // 30
    {  0, gstructNPCSE_LJ_DeadSleep }, // 31
    {  0, gstructNPCSE_LJ_DeadSleep } // 32
};


// Note: Gardner's are all over the place, so there is no point in constructing a common group for them.

//
// NPC-36 = Gardener-Nate
//

struct  statedata_NPCSchElement gstructNPCSE_36_Sleep[] =
{
    { STATEACTION_SLP_A,  3,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_DeadSleep[] =
{
    { STATEACTION_SLP_D,  3,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_Rest[] =
{
    { STATEACTION_RES_N,  3,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_MayorHouse[] =
{
    { STATEACTION_WRK_A,  1,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_PhysicianHouse[] =
{
    { STATEACTION_WRK_A, 18,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_Eating[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_15[] =
{
    { STATEACTION_RES_N,  3,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_25[] =
{
    { STATEACTION_RES_N,  3,  1 },
    { STATEACTION_HNG_N, 57,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_30[] =
{
    { STATEACTION_RES_N,  3,  1 },
    { STATEACTION_DRK_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_31[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_36_32[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-36 = Gardener-Nate
struct  statedata_NPCSchBase gstructNPCSB_36[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_36_Sleep }, // 01
    {  0, gstructNPCSE_36_DeadSleep }, // 02
    {  0, gstructNPCSE_36_DeadSleep }, // 03
    {  0, gstructNPCSE_36_DeadSleep }, // 04
    {  0, gstructNPCSE_36_DeadSleep }, // 05
    {  0, gstructNPCSE_36_DeadSleep }, // 06
    {  0, gstructNPCSE_36_DeadSleep }, // 07
    {  0, gstructNPCSE_36_DeadSleep }, // 08
    {  0, gstructNPCSE_36_DeadSleep }, // 09
    {  0, gstructNPCSE_36_DeadSleep }, // 10
    {  0, gstructNPCSE_36_DeadSleep }, // 11
    {  0, gstructNPCSE_36_Sleep }, // 12
    {  0, gstructNPCSE_36_Eating }, // 13
    {  0, gstructNPCSE_36_MayorHouse }, // 14
    {  0, gstructNPCSE_36_15 }, // 15
    {  0, gstructNPCSE_36_MayorHouse }, // 16
    {  0, gstructNPCSE_36_PhysicianHouse }, // 17
    {  0, gstructNPCSE_36_Eating }, // 18
    {  0, gstructNPCSE_36_MayorHouse }, // 19
    {  0, gstructNPCSE_36_Rest }, // 20
    {  0, gstructNPCSE_36_MayorHouse }, // 21
    {  0, gstructNPCSE_36_PhysicianHouse }, // 22
    {  0, gstructNPCSE_36_PhysicianHouse }, // 23
    {  0, gstructNPCSE_36_Eating }, // 24
    {  0, gstructNPCSE_36_25 }, // 25
    {  0, gstructNPCSE_36_Rest }, // 26
    {  0, gstructNPCSE_36_Rest }, // 27
    {  0, gstructNPCSE_36_Rest }, // 28
    {  0, gstructNPCSE_36_Rest }, // 29
    {  0, gstructNPCSE_36_30 }, // 30
    {  0, gstructNPCSE_36_31 }, // 31
    {  0, gstructNPCSE_36_32 } // 32
};


//
// NPC-37 = Gardener-Dalton
//

struct  statedata_NPCSchElement gstructNPCSE_37_Sleep[] =
{
    { STATEACTION_SLP_A, 12,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_DeadSleep[] =
{
    { STATEACTION_SLP_D, 12,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_Rest[] =
{
    { STATEACTION_RES_N, 12,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_MoneylenderHouse[] =
{
    { STATEACTION_WRK_A,  8,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_ConstableResidence[] =
{
    { STATEACTION_WRK_A,  4,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_Eating[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_Tavern[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_15[] =
{
    { STATEACTION_HNG_N, 51,  1 },
    { STATEACTION_RES_N, 12,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_24[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_RES_N, 12,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_37_31[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 12,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-37 = Gardener-Dalton
struct  statedata_NPCSchBase gstructNPCSB_37[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_37_DeadSleep }, // 01
    {  0, gstructNPCSE_37_DeadSleep }, // 02
    {  0, gstructNPCSE_37_DeadSleep }, // 03
    {  0, gstructNPCSE_37_DeadSleep }, // 04
    {  0, gstructNPCSE_37_DeadSleep }, // 05
    {  0, gstructNPCSE_37_DeadSleep }, // 06
    {  0, gstructNPCSE_37_DeadSleep }, // 07
    {  0, gstructNPCSE_37_DeadSleep }, // 08
    {  0, gstructNPCSE_37_DeadSleep }, // 09
    {  0, gstructNPCSE_37_DeadSleep }, // 10
    {  0, gstructNPCSE_37_Sleep }, // 11
    {  0, gstructNPCSE_37_Eating }, // 12
    {  0, gstructNPCSE_37_ConstableResidence }, // 13
    {  0, gstructNPCSE_37_ConstableResidence }, // 14
    {  0, gstructNPCSE_37_15 }, // 15
    {  0, gstructNPCSE_37_Eating }, // 16
    {  0, gstructNPCSE_37_MoneylenderHouse }, // 17
    {  0, gstructNPCSE_37_MoneylenderHouse }, // 18
    {  0, gstructNPCSE_37_MoneylenderHouse }, // 19
    {  0, gstructNPCSE_37_Rest }, // 20
    {  0, gstructNPCSE_37_ConstableResidence }, // 21
    {  0, gstructNPCSE_37_MoneylenderHouse }, // 22
    {  0, gstructNPCSE_37_MoneylenderHouse }, // 23
    {  0, gstructNPCSE_37_24 }, // 24
    {  0, gstructNPCSE_37_Rest }, // 25
    {  0, gstructNPCSE_37_Rest }, // 26
    {  0, gstructNPCSE_37_Rest }, // 27
    {  0, gstructNPCSE_37_Rest }, // 28
    {  0, gstructNPCSE_37_Tavern }, // 29
    {  0, gstructNPCSE_37_Tavern }, // 30
    {  0, gstructNPCSE_37_31 }, // 31
    {  0, gstructNPCSE_37_Sleep } // 32
};


//
// NPC-38 = Gardener-Rylan
//

struct  statedata_NPCSchElement gstructNPCSE_38_Sleep[] =
{
    { STATEACTION_SLP_A, 17,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_DeadSleep[] =
{
    { STATEACTION_SLP_D, 17,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_Rest[] =
{
    { STATEACTION_RES_N, 17,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_MerchantHouse[] =
{
    { STATEACTION_WRK_A, 13,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_Brewery[] =
{
    { STATEACTION_WRK_A, 23,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_14[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_20[] =
{
    { STATEACTION_RES_N, 17,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_22[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 38,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_26[] =
{
    { STATEACTION_RES_N, 17,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_30[] =
{
    { STATEACTION_RES_N, 17,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_31[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_38_32[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 12,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-38 = Gardener-Rylan
struct  statedata_NPCSchBase gstructNPCSB_38[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_38_Sleep }, // 01
    {  0, gstructNPCSE_38_DeadSleep }, // 02
    {  0, gstructNPCSE_38_DeadSleep }, // 03
    {  0, gstructNPCSE_38_DeadSleep }, // 04
    {  0, gstructNPCSE_38_DeadSleep }, // 05
    {  0, gstructNPCSE_38_DeadSleep }, // 06
    {  0, gstructNPCSE_38_DeadSleep }, // 07
    {  0, gstructNPCSE_38_DeadSleep }, // 08
    {  0, gstructNPCSE_38_DeadSleep }, // 09
    {  0, gstructNPCSE_38_DeadSleep }, // 10
    {  0, gstructNPCSE_38_DeadSleep }, // 11
    {  0, gstructNPCSE_38_Sleep }, // 12
    {  0, gstructNPCSE_38_Rest }, // 13
    {  0, gstructNPCSE_38_14 }, // 14
    {  0, gstructNPCSE_38_Rest }, // 15
    {  0, gstructNPCSE_38_MerchantHouse }, // 16
    {  0, gstructNPCSE_38_MerchantHouse }, // 17
    {  0, gstructNPCSE_38_MerchantHouse }, // 18
    {  0, gstructNPCSE_38_Brewery }, // 19
    {  0, gstructNPCSE_38_20 }, // 20
    {  0, gstructNPCSE_38_Rest }, // 21
    {  0, gstructNPCSE_38_22 }, // 22
    {  0, gstructNPCSE_38_MerchantHouse }, // 23
    {  0, gstructNPCSE_38_MerchantHouse }, // 24
    {  0, gstructNPCSE_38_Brewery }, // 25
    {  0, gstructNPCSE_38_26 }, // 26
    {  0, gstructNPCSE_38_Rest }, // 27
    {  0, gstructNPCSE_38_Rest }, // 28
    {  0, gstructNPCSE_38_Rest }, // 29
    {  0, gstructNPCSE_38_30 }, // 30
    {  0, gstructNPCSE_38_31 }, // 31
    {  0, gstructNPCSE_38_32 } // 32
};


//
// NPCs 39-40, Hunters (Forest shack, common)
//

struct  statedata_NPCSchElement gstructNPCSE_HF_Sleep[] =
{
    { STATEACTION_SLP_A, 44,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HF_DeadSleep[] =
{
    { STATEACTION_SLP_D, 44,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HF_Rest[] =
{
    { STATEACTION_RES_N, 44,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HF_Working[] =
{
    { STATEACTION_WRK_H, 45,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HF_WorkingA[] =
{
    { STATEACTION_WRK_H, 45,  2 },
    { STATEACTION_WRK_A, 45,  1 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};


//
// NPC-39 = Hunter-Joban
//

struct  statedata_NPCSchElement gstructNPCSE_39_12[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_14[] =
{
    { STATEACTION_WRK_H, 45,  1 },
    { STATEACTION_RES_N, 44,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_16[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_17[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_23[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_24[] =
{
    { STATEACTION_HNG_N, 39,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_28[] =
{
    { STATEACTION_RES_N, 44,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_2930[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_39_31[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-39 = Hunter-Joban
struct  statedata_NPCSchBase gstructNPCSB_39[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HF_Sleep }, // 01
    {  0, gstructNPCSE_HF_DeadSleep }, // 02
    {  0, gstructNPCSE_HF_DeadSleep }, // 03
    {  0, gstructNPCSE_HF_DeadSleep }, // 04
    {  0, gstructNPCSE_HF_DeadSleep }, // 05
    {  0, gstructNPCSE_HF_DeadSleep }, // 06
    {  0, gstructNPCSE_HF_DeadSleep }, // 07
    {  0, gstructNPCSE_HF_DeadSleep }, // 08
    {  0, gstructNPCSE_HF_Sleep }, // 09
    {  0, gstructNPCSE_HF_Sleep }, // 10
    {  0, gstructNPCSE_HF_Sleep }, // 11
    {  0, gstructNPCSE_39_12 }, // 12
    {  0, gstructNPCSE_HF_Working }, // 13
    {  0, gstructNPCSE_39_14 }, // 14
    {  0, gstructNPCSE_HF_Rest }, // 15
    {  0, gstructNPCSE_39_16 }, // 16
    {  0, gstructNPCSE_39_17 }, // 17
    {  0, gstructNPCSE_HF_WorkingA }, // 18
    {  0, gstructNPCSE_HF_Rest }, // 19
    {  0, gstructNPCSE_HF_WorkingA }, // 20
    {  0, gstructNPCSE_HF_WorkingA }, // 21
    {  0, gstructNPCSE_HF_WorkingA }, // 22
    {  0, gstructNPCSE_39_23 }, // 23
    {  0, gstructNPCSE_39_24 }, // 24
    {  0, gstructNPCSE_HF_Rest }, // 25
    {  0, gstructNPCSE_HF_Rest }, // 26
    {  0, gstructNPCSE_HF_Rest }, // 27
    {  0, gstructNPCSE_39_28 }, // 28
    {  0, gstructNPCSE_39_2930 }, // 29
    {  0, gstructNPCSE_39_2930 }, // 30
    {  0, gstructNPCSE_39_31 }, // 31
    {  0, gstructNPCSE_HF_Sleep } // 32
};


//
// NPC-40 = Hunter-Dryden
//

struct  statedata_NPCSchElement gstructNPCSE_40_16[] =
{
    { STATEACTION_RES_N, 44,  1 },
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_17[] =
{
    { STATEACTION_HNG_N, 46,  2 },
    { STATEACTION_HNG_N, 47,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_18[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_24[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_27[] =
{
    { STATEACTION_RES_N, 44,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_2829[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_40_30[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 44,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-40 = Hunter-Dryden
struct  statedata_NPCSchBase gstructNPCSB_40[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HF_Sleep }, // 01
    {  0, gstructNPCSE_HF_Sleep }, // 02
    {  0, gstructNPCSE_HF_Sleep }, // 03
    {  0, gstructNPCSE_HF_DeadSleep }, // 04
    {  0, gstructNPCSE_HF_DeadSleep }, // 05
    {  0, gstructNPCSE_HF_DeadSleep }, // 06
    {  0, gstructNPCSE_HF_DeadSleep }, // 07
    {  0, gstructNPCSE_HF_DeadSleep }, // 08
    {  0, gstructNPCSE_HF_DeadSleep }, // 09
    {  0, gstructNPCSE_HF_Sleep }, // 10
    {  0, gstructNPCSE_HF_Rest }, // 11
    { 39, NULL }, // 12
    { 39, NULL }, // 13
    { 39, NULL }, // 14
    { 39, NULL }, // 15
    {  0, gstructNPCSE_40_16 }, // 16
    {  0, gstructNPCSE_40_17 }, // 17
    {  0, gstructNPCSE_40_18 }, // 18
    { 39, NULL }, // 19
    { 39, NULL }, // 20
    { 39, NULL }, // 21
    { 39, NULL }, // 22
    {  0, gstructNPCSE_HF_Rest }, // 23
    {  0, gstructNPCSE_40_24 }, // 24
    {  0, gstructNPCSE_HF_Rest }, // 25
    {  0, gstructNPCSE_HF_Rest }, // 26
    {  0, gstructNPCSE_40_27 }, // 27
    {  0, gstructNPCSE_40_2829 }, // 28
    {  0, gstructNPCSE_40_2829 }, // 29
    {  0, gstructNPCSE_40_30 }, // 30
    {  0, gstructNPCSE_HF_Sleep }, // 31
    {  0, gstructNPCSE_HF_Sleep } // 32
};


//
// NPCs 41-42, Hunter & Fletcher (Target range shack, common)
//

struct  statedata_NPCSchElement gstructNPCSE_HT_Sleep[] =
{
    { STATEACTION_SLP_A, 48,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HT_DeadSleep[] =
{
    { STATEACTION_SLP_D, 48,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HT_Rest[] =
{
    { STATEACTION_RES_N, 48,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_HT_Range[] =
{
    { STATEACTION_WRK_A, 47,  3 },
    { STATEACTION_HNG_N, 46,  1 },
    { -1, -1, -1 }
};


//
// NPC-41 = Hunter-Keyon
//

struct  statedata_NPCSchElement gstructNPCSE_41_WorkingA[] =
{
    { STATEACTION_WRK_H, 45,  2 },
    { STATEACTION_WRK_A, 45,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_WorkingB[] =
{
    { STATEACTION_WRK_A, 45,  3 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_16[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_20[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_25[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_29[] =
{
    { STATEACTION_RES_N, 48,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_30[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_41_31[] =
{
    { STATEACTION_EAT_N, 26,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-41 = Hunter-Keyon
struct  statedata_NPCSchBase gstructNPCSB_41[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_41_WorkingA }, // 01
    {  0, gstructNPCSE_41_WorkingA }, // 02
    {  0, gstructNPCSE_41_WorkingA }, // 03
    {  0, gstructNPCSE_HT_Sleep }, // 04
    {  0, gstructNPCSE_HT_DeadSleep }, // 05
    {  0, gstructNPCSE_HT_DeadSleep }, // 06
    {  0, gstructNPCSE_HT_DeadSleep }, // 07
    {  0, gstructNPCSE_HT_DeadSleep }, // 08
    {  0, gstructNPCSE_HT_DeadSleep }, // 09
    {  0, gstructNPCSE_HT_DeadSleep }, // 10
    {  0, gstructNPCSE_HT_DeadSleep }, // 11
    {  0, gstructNPCSE_HT_DeadSleep }, // 12
    {  0, gstructNPCSE_HT_DeadSleep }, // 13
    {  0, gstructNPCSE_HT_DeadSleep }, // 14
    {  0, gstructNPCSE_HT_Sleep }, // 15
    {  0, gstructNPCSE_41_16 }, // 16
    {  0, gstructNPCSE_HT_Range }, // 17
    {  0, gstructNPCSE_HT_Range }, // 18
    {  0, gstructNPCSE_HT_Range }, // 19
    {  0, gstructNPCSE_41_20 }, // 20
    {  0, gstructNPCSE_41_WorkingB }, // 21
    {  0, gstructNPCSE_41_WorkingB }, // 22
    {  0, gstructNPCSE_HT_Rest }, // 23
    {  0, gstructNPCSE_HT_Rest }, // 24
    {  0, gstructNPCSE_41_25 }, // 25
    {  0, gstructNPCSE_HT_Range }, // 26
    {  0, gstructNPCSE_HT_Rest }, // 27
    {  0, gstructNPCSE_HT_Rest }, // 28
    {  0, gstructNPCSE_41_29 }, // 29
    {  0, gstructNPCSE_41_30 }, // 30
    {  0, gstructNPCSE_41_31 }, // 31
    {  0, gstructNPCSE_41_WorkingA } // 32
};


//
// NPC-42 = Fletcher-Lester
//

struct  statedata_NPCSchElement gstructNPCSE_42_12[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_14[] =
{
    { STATEACTION_HNG_N, 60,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_15[] =
{
    { STATEACTION_HNG_N, 35,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_19[] =
{
    { STATEACTION_RES_N, 48,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_22[] =
{
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_25[] =
{
    { STATEACTION_RES_N, 48,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_28[] =
{
    { STATEACTION_RES_N, 48,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_29[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_30[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_42_31[] =
{
    { STATEACTION_RES_N, 48,  2 },
    { STATEACTION_HNG_N, 27,  1 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-42 = Fletcher-Lester
struct  statedata_NPCSchBase gstructNPCSB_42[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_HT_DeadSleep }, // 01
    {  0, gstructNPCSE_HT_DeadSleep }, // 02
    {  0, gstructNPCSE_HT_DeadSleep }, // 03
    {  0, gstructNPCSE_HT_DeadSleep }, // 04
    {  0, gstructNPCSE_HT_DeadSleep }, // 05
    {  0, gstructNPCSE_HT_DeadSleep }, // 06
    {  0, gstructNPCSE_HT_DeadSleep }, // 07
    {  0, gstructNPCSE_HT_DeadSleep }, // 08
    {  0, gstructNPCSE_HT_DeadSleep }, // 09
    {  0, gstructNPCSE_HT_DeadSleep }, // 10
    {  0, gstructNPCSE_HT_Sleep }, // 11
    {  0, gstructNPCSE_42_12 }, // 12
    {  0, gstructNPCSE_HT_Range }, // 13
    {  0, gstructNPCSE_42_14 }, // 14
    {  0, gstructNPCSE_42_15 }, // 15
    {  0, gstructNPCSE_HT_Rest }, // 16
    {  0, gstructNPCSE_HT_Range }, // 17
    {  0, gstructNPCSE_HT_Range }, // 18
    {  0, gstructNPCSE_42_19 }, // 19
    {  0, gstructNPCSE_HT_Range }, // 20
    {  0, gstructNPCSE_HT_Rest }, // 21
    {  0, gstructNPCSE_42_22 }, // 22
    {  0, gstructNPCSE_HT_Rest }, // 23
    {  0, gstructNPCSE_HT_Range }, // 24
    {  0, gstructNPCSE_42_25 }, // 25
    {  0, gstructNPCSE_HT_Rest }, // 26
    {  0, gstructNPCSE_HT_Rest }, // 27
    {  0, gstructNPCSE_42_28 }, // 28
    {  0, gstructNPCSE_42_29 }, // 29
    {  0, gstructNPCSE_42_30 }, // 30
    {  0, gstructNPCSE_42_31 }, // 31
    {  0, gstructNPCSE_HT_Sleep } // 32
};


//
// NPCs 43-46, Fishermen (common)
//

struct  statedata_NPCSchElement gstructNPCSE_FI_Sleep[] =
{
    { STATEACTION_SLP_A, 50,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_DeadSleep[] =
{
    { STATEACTION_SLP_D, 50,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Rest[] =
{
    { STATEACTION_RES_N, 50,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Tav1[] =
{
    { STATEACTION_RES_N, 50,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Tav2[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Tav3[] =
{
    { STATEACTION_DRK_N, 27,  2 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Tav4[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 50,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_Fishing[] =
{
    { STATEACTION_WRK_A, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FI_EatK[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};


//
// NPC-43 = Fisherman-Yousef
//

struct  statedata_NPCSchElement gstructNPCSE_43_14[] =
{
    { STATEACTION_HNG_N, 36,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_43_20[] =
{
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_43_26[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-43 = Fisherman-Yousef
struct  statedata_NPCSchBase gstructNPCSB_43[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FI_Sleep }, // 01
    {  0, gstructNPCSE_FI_DeadSleep }, // 02
    {  0, gstructNPCSE_FI_DeadSleep }, // 03
    {  0, gstructNPCSE_FI_DeadSleep }, // 04
    {  0, gstructNPCSE_FI_DeadSleep }, // 05
    {  0, gstructNPCSE_FI_DeadSleep }, // 06
    {  0, gstructNPCSE_FI_DeadSleep }, // 07
    {  0, gstructNPCSE_FI_DeadSleep }, // 08
    {  0, gstructNPCSE_FI_DeadSleep }, // 09
    {  0, gstructNPCSE_FI_DeadSleep }, // 10
    {  0, gstructNPCSE_FI_DeadSleep }, // 11
    {  0, gstructNPCSE_FI_Sleep }, // 12
    {  0, gstructNPCSE_FI_EatK }, // 13
    {  0, gstructNPCSE_43_14 }, // 14
    {  0, gstructNPCSE_FI_Fishing }, // 15
    {  0, gstructNPCSE_FI_Fishing }, // 16
    {  0, gstructNPCSE_FI_Fishing }, // 17
    {  0, gstructNPCSE_FI_Fishing }, // 18
    {  0, gstructNPCSE_FI_Rest }, // 19
    {  0, gstructNPCSE_43_20 }, // 20
    {  0, gstructNPCSE_FI_Fishing }, // 21
    {  0, gstructNPCSE_FI_Fishing }, // 22
    {  0, gstructNPCSE_FI_Fishing }, // 23
    {  0, gstructNPCSE_FI_EatK }, // 24
    {  0, gstructNPCSE_FI_Rest }, // 25
    {  0, gstructNPCSE_43_26 }, // 26
    {  0, gstructNPCSE_FI_Rest }, // 27
    {  0, gstructNPCSE_FI_Rest }, // 28
    {  0, gstructNPCSE_FI_Tav1 }, // 29
    {  0, gstructNPCSE_FI_Tav2 }, // 30
    {  0, gstructNPCSE_FI_Tav3 }, // 31
    {  0, gstructNPCSE_FI_Tav4 } // 32
};


//
// NPC-44 = Fisherman-Braden
//

struct  statedata_NPCSchElement gstructNPCSE_44_01[] =
{
    { STATEACTION_RES_D, 26,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_44_15[] =
{
    { STATEACTION_WRK_A, 49,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_44_18[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_44_21[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 57,  1 },
    { STATEACTION_HNG_N, 45,  1 },
    { STATEACTION_HNG_N, 35,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_44_25[] =
{
    { STATEACTION_RES_N, 50,  1 },
    { STATEACTION_RES_N, 49,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-44 = Fisherman-Braden
struct  statedata_NPCSchBase gstructNPCSB_44[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_44_01 }, // 01
    {  0, gstructNPCSE_FI_Sleep }, // 02
    {  0, gstructNPCSE_FI_DeadSleep }, // 03
    {  0, gstructNPCSE_FI_DeadSleep }, // 04
    {  0, gstructNPCSE_FI_DeadSleep }, // 05
    {  0, gstructNPCSE_FI_Sleep }, // 06
    {  0, gstructNPCSE_FI_DeadSleep }, // 07
    {  0, gstructNPCSE_FI_DeadSleep }, // 08
    {  0, gstructNPCSE_FI_DeadSleep }, // 09
    {  0, gstructNPCSE_FI_DeadSleep }, // 10
    {  0, gstructNPCSE_FI_DeadSleep }, // 11
    {  0, gstructNPCSE_FI_Sleep }, // 12
    {  0, gstructNPCSE_FI_Sleep }, // 13
    {  0, gstructNPCSE_FI_EatK }, // 14
    {  0, gstructNPCSE_44_15 }, // 15
    {  0, gstructNPCSE_FI_Fishing }, // 16
    {  0, gstructNPCSE_FI_Fishing }, // 17
    {  0, gstructNPCSE_44_18 }, // 18
    {  0, gstructNPCSE_FI_Rest }, // 19
    {  0, gstructNPCSE_FI_Fishing }, // 20
    {  0, gstructNPCSE_44_21 }, // 21
    {  0, gstructNPCSE_FI_Fishing }, // 22
    {  0, gstructNPCSE_FI_EatK }, // 23
    {  0, gstructNPCSE_FI_Rest }, // 24
    {  0, gstructNPCSE_44_25 }, // 25
    {  0, gstructNPCSE_FI_Fishing }, // 26
    {  0, gstructNPCSE_FI_Fishing }, // 27
    {  0, gstructNPCSE_FI_Rest }, // 28
    {  0, gstructNPCSE_FI_Rest }, // 29
    {  0, gstructNPCSE_FI_Tav1 }, // 30
    {  0, gstructNPCSE_FI_Tav2 }, // 31
    {  0, gstructNPCSE_FI_Tav3 } // 32
};


//
// NPC-45 = Fisherman-Deion
//

struct  statedata_NPCSchElement gstructNPCSE_45_14[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_45_16[] =
{
    { STATEACTION_HNG_N, 35,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_45_17[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-45 = Fisherman-Deion
struct  statedata_NPCSchBase gstructNPCSB_45[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FI_Rest }, // 01
    {  0, gstructNPCSE_FI_Sleep }, // 02
    {  0, gstructNPCSE_FI_DeadSleep }, // 03
    {  0, gstructNPCSE_FI_DeadSleep }, // 04
    {  0, gstructNPCSE_FI_DeadSleep }, // 05
    {  0, gstructNPCSE_FI_DeadSleep }, // 06
    {  0, gstructNPCSE_FI_DeadSleep }, // 07
    {  0, gstructNPCSE_FI_DeadSleep }, // 08
    {  0, gstructNPCSE_FI_DeadSleep }, // 09
    {  0, gstructNPCSE_FI_DeadSleep }, // 10
    {  0, gstructNPCSE_FI_DeadSleep }, // 11
    {  0, gstructNPCSE_FI_DeadSleep }, // 12
    {  0, gstructNPCSE_FI_Sleep }, // 13
    {  0, gstructNPCSE_45_14 }, // 14
    {  0, gstructNPCSE_FI_EatK }, // 15
    {  0, gstructNPCSE_45_16 }, // 16
    {  0, gstructNPCSE_45_17 }, // 17
    {  0, gstructNPCSE_FI_Fishing }, // 18
    {  0, gstructNPCSE_FI_Fishing }, // 19
    {  0, gstructNPCSE_FI_Fishing }, // 20
    {  0, gstructNPCSE_FI_EatK }, // 21
    {  0, gstructNPCSE_FI_Rest }, // 22
    {  0, gstructNPCSE_FI_Fishing }, // 23
    {  0, gstructNPCSE_FI_Fishing }, // 24
    {  0, gstructNPCSE_FI_EatK }, // 25
    {  0, gstructNPCSE_FI_Rest }, // 26
    {  0, gstructNPCSE_FI_Tav1 }, // 27
    {  0, gstructNPCSE_FI_Tav2 }, // 28
    {  0, gstructNPCSE_FI_Tav3 }, // 29
    {  0, gstructNPCSE_FI_Tav4 }, // 30
    {  0, gstructNPCSE_FI_Rest }, // 31
    {  0, gstructNPCSE_FI_Rest } // 32
};


//
// NPC-46 = Fisherman-Omari
//

struct  statedata_NPCSchElement gstructNPCSE_46_18[] =
{
    { STATEACTION_RES_N, 50,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_46_19[] =
{
    { STATEACTION_RES_N, 50,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_46_22[] =
{
    { STATEACTION_HNG_N, 53,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_46_23[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 51,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-46 = Fisherman-Omari
struct  statedata_NPCSchBase gstructNPCSB_46[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FI_Fishing }, // 01
    {  0, gstructNPCSE_FI_Fishing }, // 02
    {  0, gstructNPCSE_FI_Sleep }, // 03
    {  0, gstructNPCSE_FI_DeadSleep }, // 04
    {  0, gstructNPCSE_FI_DeadSleep }, // 05
    {  0, gstructNPCSE_FI_DeadSleep }, // 06
    {  0, gstructNPCSE_FI_DeadSleep }, // 07
    {  0, gstructNPCSE_FI_DeadSleep }, // 08
    {  0, gstructNPCSE_FI_DeadSleep }, // 09
    {  0, gstructNPCSE_FI_DeadSleep }, // 10
    {  0, gstructNPCSE_FI_DeadSleep }, // 11
    {  0, gstructNPCSE_FI_DeadSleep }, // 12
    {  0, gstructNPCSE_FI_DeadSleep }, // 13
    {  0, gstructNPCSE_FI_Sleep }, // 14
    {  0, gstructNPCSE_FI_Sleep }, // 15
    {  0, gstructNPCSE_FI_EatK }, // 16
    {  0, gstructNPCSE_FI_Rest }, // 17
    {  0, gstructNPCSE_46_18 }, // 18
    {  0, gstructNPCSE_46_19 }, // 19
    {  0, gstructNPCSE_FI_Rest }, // 20
    {  0, gstructNPCSE_FI_Rest }, // 21
    {  0, gstructNPCSE_46_22 }, // 22
    {  0, gstructNPCSE_46_23 }, // 23
    {  0, gstructNPCSE_FI_Fishing }, // 24
    {  0, gstructNPCSE_FI_Fishing }, // 25
    {  0, gstructNPCSE_FI_Fishing }, // 26
    {  0, gstructNPCSE_FI_Rest }, // 27
    {  0, gstructNPCSE_FI_Tav1 }, // 28
    {  0, gstructNPCSE_FI_Tav2 }, // 29
    {  0, gstructNPCSE_FI_Tav3 }, // 30
    {  0, gstructNPCSE_FI_Tav4 }, // 31
    {  0, gstructNPCSE_FI_Rest } // 32
};


//
// NPCs 47-48, Farmers-North (common)
//

struct  statedata_NPCSchElement gstructNPCSE_FN_Sleep[] =
{
    { STATEACTION_SLP_A, 52,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FN_DeadSleep[] =
{
    { STATEACTION_SLP_D, 52,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FN_Rest[] =
{
    { STATEACTION_RES_N, 52,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FN_Farming[] =
{
    { STATEACTION_WRK_A, 51,  0 },
    { -1, -1, -1 }
};


//
// NPC-47 = Farmer-Melvin (NorthernFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_47_10[] =
{
    { STATEACTION_EAT_N, 27,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_N, 52,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_11[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_DRK_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_12[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_13[] =
{
    { STATEACTION_RES_N, 52,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_D, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_18[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_20[] =
{
    { STATEACTION_WRK_A, 51,  1 },
    { STATEACTION_HNG_N, 39,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_47_27[] =
{
    { STATEACTION_RES_N, 49,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-47 = Farmer-Melvin (NorthernFarm)
struct  statedata_NPCSchBase gstructNPCSB_47[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FN_DeadSleep }, // 01
    {  0, gstructNPCSE_FN_DeadSleep }, // 02
    {  0, gstructNPCSE_FN_DeadSleep }, // 03
    {  0, gstructNPCSE_FN_DeadSleep }, // 04
    {  0, gstructNPCSE_FN_DeadSleep }, // 05
    {  0, gstructNPCSE_FN_DeadSleep }, // 06
    {  0, gstructNPCSE_FN_DeadSleep }, // 07
    {  0, gstructNPCSE_FN_DeadSleep }, // 08
    {  0, gstructNPCSE_FN_Sleep }, // 09
    {  0, gstructNPCSE_47_10 }, // 10
    {  0, gstructNPCSE_47_11 }, // 11
    {  0, gstructNPCSE_47_12 }, // 12
    {  0, gstructNPCSE_47_13 }, // 13
    {  0, gstructNPCSE_FN_Farming }, // 14
    {  0, gstructNPCSE_FN_Farming }, // 15
    {  0, gstructNPCSE_FN_Rest }, // 16
    {  0, gstructNPCSE_FN_Farming }, // 17
    {  0, gstructNPCSE_47_18 }, // 18
    {  0, gstructNPCSE_FN_Rest }, // 19
    {  0, gstructNPCSE_47_20 }, // 20
    {  0, gstructNPCSE_FN_Farming }, // 21
    {  0, gstructNPCSE_FN_Farming }, // 22
    {  0, gstructNPCSE_FN_Rest }, // 23
    {  0, gstructNPCSE_FN_Farming }, // 24
    {  0, gstructNPCSE_FN_Farming }, // 25
    {  0, gstructNPCSE_FN_Rest }, // 26
    {  0, gstructNPCSE_47_27 }, // 27
    {  0, gstructNPCSE_FN_Rest }, // 28
    {  0, gstructNPCSE_FN_Rest }, // 29
    {  0, gstructNPCSE_FN_Sleep }, // 30
    {  0, gstructNPCSE_FN_DeadSleep }, // 31
    {  0, gstructNPCSE_FN_DeadSleep } // 32
};


//
// NPC-48 = Farmer-Gary (NorthernFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_48_12[] =
{
    { STATEACTION_WRK_A, 51,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_14[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_N, 52,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_15[] =
{
    { STATEACTION_EAT_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_16[] =
{
    { STATEACTION_HNG_N, 27,  1 },
    { STATEACTION_DRK_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_17[] =
{
    { STATEACTION_RES_N, 52,  2 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_19[] =
{
    { STATEACTION_WRK_A, 51,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_21[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_48_22[] =
{
    { STATEACTION_WRK_A, 51,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-48 = Farmer-Gary (NorthernFarm)
struct  statedata_NPCSchBase gstructNPCSB_48[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FN_DeadSleep }, // 01
    {  0, gstructNPCSE_FN_DeadSleep }, // 02
    {  0, gstructNPCSE_FN_DeadSleep }, // 03
    {  0, gstructNPCSE_FN_DeadSleep }, // 04
    {  0, gstructNPCSE_FN_DeadSleep }, // 05
    {  0, gstructNPCSE_FN_DeadSleep }, // 06
    {  0, gstructNPCSE_FN_DeadSleep }, // 07
    {  0, gstructNPCSE_FN_Sleep }, // 08
    {  0, gstructNPCSE_FN_Sleep }, // 09
    {  0, gstructNPCSE_FN_Sleep }, // 10
    {  0, gstructNPCSE_FN_Rest }, // 11
    {  0, gstructNPCSE_48_12 }, // 12
    {  0, gstructNPCSE_FN_Farming }, // 13
    {  0, gstructNPCSE_48_14 }, // 14
    {  0, gstructNPCSE_48_15 }, // 15
    {  0, gstructNPCSE_48_16 }, // 16
    {  0, gstructNPCSE_48_17 }, // 17
    {  0, gstructNPCSE_FN_Rest }, // 18
    {  0, gstructNPCSE_48_19 }, // 19
    {  0, gstructNPCSE_FN_Farming }, // 20
    {  0, gstructNPCSE_48_21 }, // 21
    {  0, gstructNPCSE_48_22 }, // 22
    {  0, gstructNPCSE_FN_Farming }, // 23
    {  0, gstructNPCSE_FN_Farming }, // 24
    {  0, gstructNPCSE_FN_Rest }, // 25
    {  0, gstructNPCSE_FN_Farming }, // 26
    {  0, gstructNPCSE_FN_Farming }, // 27
    {  0, gstructNPCSE_FN_Rest }, // 28
    {  0, gstructNPCSE_FN_Rest }, // 29
    {  0, gstructNPCSE_FN_Rest }, // 30
    {  0, gstructNPCSE_FN_Sleep }, // 31
    {  0, gstructNPCSE_FN_DeadSleep } // 32
};


//
// NPCs 49-50, Farmers-East (common)
//

struct  statedata_NPCSchElement gstructNPCSE_FE_Sleep[] =
{
    { STATEACTION_SLP_A, 54,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FE_DeadSleep[] =
{
    { STATEACTION_SLP_D, 54,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FE_Rest[] =
{
    { STATEACTION_RES_N, 54,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FE_Farming[] =
{
    { STATEACTION_WRK_A, 53,  0 },
    { -1, -1, -1 }
};


//
// NPC-49 = Farmer-Jerry (EasternFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_49_11[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_RES_N, 54,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_12[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_DRK_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_13[] =
{
    { STATEACTION_DRK_N, 27,  2 },
    { STATEACTION_EAT_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_14[] =
{
    { STATEACTION_RES_N, 54,  2 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_18[] =
{
    { STATEACTION_EAT_N, 32,  1 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_24[] =
{
    { STATEACTION_HNG_N, 39,  1 },
    { STATEACTION_HNG_N, 43,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_49_26[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-49 = Farmer-Jerry (EasternFarm)
struct  statedata_NPCSchBase gstructNPCSB_49[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FE_DeadSleep }, // 01
    {  0, gstructNPCSE_FE_DeadSleep }, // 02
    {  0, gstructNPCSE_FE_DeadSleep }, // 03
    {  0, gstructNPCSE_FE_DeadSleep }, // 04
    {  0, gstructNPCSE_FE_DeadSleep }, // 05
    {  0, gstructNPCSE_FE_DeadSleep }, // 06
    {  0, gstructNPCSE_FE_DeadSleep }, // 07
    {  0, gstructNPCSE_FE_DeadSleep }, // 08
    {  0, gstructNPCSE_FE_Sleep }, // 09
    {  0, gstructNPCSE_FE_Rest }, // 10
    {  0, gstructNPCSE_49_11 }, // 11
    {  0, gstructNPCSE_49_12 }, // 12
    {  0, gstructNPCSE_49_13 }, // 13
    {  0, gstructNPCSE_49_14 }, // 14
    {  0, gstructNPCSE_FE_Farming }, // 15
    {  0, gstructNPCSE_FE_Farming }, // 16
    {  0, gstructNPCSE_FE_Rest }, // 17
    {  0, gstructNPCSE_49_18 }, // 18
    {  0, gstructNPCSE_FE_Farming }, // 19
    {  0, gstructNPCSE_FE_Farming }, // 20
    {  0, gstructNPCSE_FE_Rest }, // 21
    {  0, gstructNPCSE_FE_Farming }, // 22
    {  0, gstructNPCSE_FE_Farming }, // 23
    {  0, gstructNPCSE_49_24 }, // 24
    {  0, gstructNPCSE_FE_Rest }, // 25
    {  0, gstructNPCSE_49_26 }, // 26
    {  0, gstructNPCSE_FE_Rest }, // 27
    {  0, gstructNPCSE_FE_Rest }, // 28
    {  0, gstructNPCSE_FE_Sleep }, // 29
    {  0, gstructNPCSE_FE_Sleep }, // 30
    {  0, gstructNPCSE_FE_Sleep }, // 31
    {  0, gstructNPCSE_FE_DeadSleep } // 32
};


//
// NPC-50 = Farmer-Frank (EasternFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_50_14[] =
{
    { STATEACTION_HNG_N, 38,  1 },
    { STATEACTION_HNG_N, 49,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_16[] =
{
    { STATEACTION_HNG_N, 43,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 35,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_18[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_RES_N, 54,  2 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_19[] =
{
    { STATEACTION_DRK_N, 27,  2 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_20[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_DRK_N, 27,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_21[] =
{
    { STATEACTION_RES_N, 54,  2 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_26[] =
{
    { STATEACTION_WRK_A, 53,  1 },
    { STATEACTION_RES_N, 54,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_50_31[] =
{
    { STATEACTION_HNG_N, 60,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-50 = Farmer-Frank (EasternFarm)
struct  statedata_NPCSchBase gstructNPCSB_50[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FE_Sleep }, // 01
    {  0, gstructNPCSE_FE_Sleep }, // 02
    {  0, gstructNPCSE_FE_DeadSleep }, // 03
    {  0, gstructNPCSE_FE_DeadSleep }, // 04
    {  0, gstructNPCSE_FE_DeadSleep }, // 05
    {  0, gstructNPCSE_FE_DeadSleep }, // 06
    {  0, gstructNPCSE_FE_DeadSleep }, // 07
    {  0, gstructNPCSE_FE_DeadSleep }, // 08
    {  0, gstructNPCSE_FE_DeadSleep }, // 09
    {  0, gstructNPCSE_FE_DeadSleep }, // 10
    {  0, gstructNPCSE_FE_Sleep }, // 11
    {  0, gstructNPCSE_FE_Sleep }, // 12
    {  0, gstructNPCSE_FE_Rest }, // 13
    {  0, gstructNPCSE_50_14 }, // 14
    {  0, gstructNPCSE_FE_Rest }, // 15
    {  0, gstructNPCSE_50_16 }, // 16
    {  0, gstructNPCSE_FE_Farming }, // 17
    {  0, gstructNPCSE_50_18 }, // 18
    {  0, gstructNPCSE_50_19 }, // 19
    {  0, gstructNPCSE_50_20 }, // 20
    {  0, gstructNPCSE_50_21 }, // 21
    {  0, gstructNPCSE_FE_Farming }, // 22
    {  0, gstructNPCSE_FE_Farming }, // 23
    {  0, gstructNPCSE_FE_Farming }, // 24
    {  0, gstructNPCSE_FE_Farming }, // 25
    {  0, gstructNPCSE_50_26 }, // 26
    {  0, gstructNPCSE_FE_Rest }, // 27
    {  0, gstructNPCSE_FE_Rest }, // 28
    {  0, gstructNPCSE_FE_Rest }, // 29
    {  0, gstructNPCSE_FE_Rest }, // 30
    {  0, gstructNPCSE_50_31 }, // 31
    {  0, gstructNPCSE_FE_Rest } // 32
};


//
// NPCs 51-52, Farmers-South (common)
//

struct  statedata_NPCSchElement gstructNPCSE_FS_Sleep[] =
{
    { STATEACTION_SLP_A, 56,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FS_DeadSleep[] =
{
    { STATEACTION_SLP_D, 56,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FS_Rest[] =
{
    { STATEACTION_RES_N, 56,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FS_Farming[] =
{
    { STATEACTION_WRK_A, 55,  0 },
    { -1, -1, -1 }
};


//
// NPC-51 = Farmer-Pete (SouthernFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_51_12[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_RES_N, 56,  2 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_13[] =
{
    { STATEACTION_DRK_N, 27,  2 },
    { STATEACTION_EAT_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_14[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_15[] =
{
    { STATEACTION_RES_N, 56,  1 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_17[] =
{
    { STATEACTION_HNG_N, 39,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_22[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_23[] =
{
    { STATEACTION_HNG_N, 24,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_51_29[] =
{
    { STATEACTION_RES_N, 56,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-51 = Farmer-Pete (SouthernFarm)
struct  statedata_NPCSchBase gstructNPCSB_51[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FS_Sleep }, // 01
    {  0, gstructNPCSE_FS_DeadSleep }, // 02
    {  0, gstructNPCSE_FS_DeadSleep }, // 03
    {  0, gstructNPCSE_FS_DeadSleep }, // 04
    {  0, gstructNPCSE_FS_DeadSleep }, // 05
    {  0, gstructNPCSE_FS_DeadSleep }, // 06
    {  0, gstructNPCSE_FS_DeadSleep }, // 07
    {  0, gstructNPCSE_FS_DeadSleep }, // 08
    {  0, gstructNPCSE_FS_DeadSleep }, // 09
    {  0, gstructNPCSE_FS_Sleep }, // 10
    {  0, gstructNPCSE_FS_Sleep }, // 11
    {  0, gstructNPCSE_51_12 }, // 12
    {  0, gstructNPCSE_51_13 }, // 13
    {  0, gstructNPCSE_51_14 }, // 14
    {  0, gstructNPCSE_51_15 }, // 15
    {  0, gstructNPCSE_FS_Farming }, // 16
    {  0, gstructNPCSE_51_17 }, // 17
    {  0, gstructNPCSE_FS_Farming }, // 18
    {  0, gstructNPCSE_FS_Farming }, // 19
    {  0, gstructNPCSE_FS_Farming }, // 20
    {  0, gstructNPCSE_FS_Rest }, // 21
    {  0, gstructNPCSE_51_22 }, // 22
    {  0, gstructNPCSE_51_23 }, // 23
    {  0, gstructNPCSE_FS_Farming }, // 24
    {  0, gstructNPCSE_FS_Farming }, // 25
    {  0, gstructNPCSE_FS_Rest }, // 26
    {  0, gstructNPCSE_FS_Rest }, // 27
    {  0, gstructNPCSE_FS_Rest }, // 28
    {  0, gstructNPCSE_51_29 }, // 29
    {  0, gstructNPCSE_FS_Rest }, // 30
    {  0, gstructNPCSE_FS_Rest }, // 31
    {  0, gstructNPCSE_FS_Sleep } // 32
};


//
// NPC-52 = Farmer-Lloyd (SouthernFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_52_18[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_N, 56,  2 },
    { STATEACTION_EAT_N, 31,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_19[] =
{
    { STATEACTION_EAT_N, 27,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_20[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_21[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 56,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { STATEACTION_WRK_H, 45,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_25[] =
{
    { STATEACTION_EAT_N, 32,  2 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_26[] =
{
    { STATEACTION_HNG_N, 49,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_52_30[] =
{
    { STATEACTION_RES_N, 56,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-52 = Farmer-Lloyd (SouthernFarm)
struct  statedata_NPCSchBase gstructNPCSB_52[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FS_Sleep }, // 01
    {  0, gstructNPCSE_FS_Sleep }, // 02
    {  0, gstructNPCSE_FS_DeadSleep }, // 03
    {  0, gstructNPCSE_FS_DeadSleep }, // 04
    {  0, gstructNPCSE_FS_DeadSleep }, // 05
    {  0, gstructNPCSE_FS_DeadSleep }, // 06
    {  0, gstructNPCSE_FS_DeadSleep }, // 07
    {  0, gstructNPCSE_FS_DeadSleep }, // 08
    {  0, gstructNPCSE_FS_DeadSleep }, // 09
    {  0, gstructNPCSE_FS_DeadSleep }, // 10
    {  0, gstructNPCSE_FS_DeadSleep }, // 11
    {  0, gstructNPCSE_FS_Sleep }, // 12
    {  0, gstructNPCSE_FS_Rest }, // 13
    {  0, gstructNPCSE_FS_Farming }, // 14
    {  0, gstructNPCSE_FS_Farming }, // 15
    {  0, gstructNPCSE_FS_Rest }, // 16
    {  0, gstructNPCSE_FS_Farming }, // 17
    {  0, gstructNPCSE_52_18 }, // 18
    {  0, gstructNPCSE_52_19 }, // 19
    {  0, gstructNPCSE_52_20 }, // 20
    {  0, gstructNPCSE_52_21 }, // 21
    {  0, gstructNPCSE_FS_Farming }, // 22
    {  0, gstructNPCSE_FS_Farming }, // 23
    {  0, gstructNPCSE_FS_Rest }, // 24
    {  0, gstructNPCSE_52_25 }, // 25
    {  0, gstructNPCSE_52_26 }, // 26
    {  0, gstructNPCSE_FS_Rest }, // 27
    {  0, gstructNPCSE_FS_Rest }, // 28
    {  0, gstructNPCSE_FS_Rest }, // 29
    {  0, gstructNPCSE_52_30 }, // 30
    {  0, gstructNPCSE_FS_Rest }, // 31
    {  0, gstructNPCSE_FS_Rest } // 32
};


//
// NPCs 53-54, Farmers-West (common)
//

struct  statedata_NPCSchElement gstructNPCSE_FW_Sleep[] =
{
    { STATEACTION_SLP_A, 58,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FW_DeadSleep[] =
{
    { STATEACTION_SLP_D, 58,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FW_Rest[] =
{
    { STATEACTION_RES_N, 58,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_FW_Farming[] =
{
    { STATEACTION_WRK_A, 57,  0 },
    { -1, -1, -1 }
};


//
// NPC-53 = Farmer-Bob (WesternFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_53_01[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_15[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_16[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_N, 58,  1 },
    { STATEACTION_HNG_N, 36,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_1718[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_19[] =
{
    { STATEACTION_RES_D, 26,  1 },
    { STATEACTION_RES_N, 58,  1 },
    { STATEACTION_WRK_H, 45,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_24[] =
{
    { STATEACTION_EAT_N, 32,  2 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_27[] =
{
    { STATEACTION_HNG_N, 38,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_53_3132[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-53 = Farmer-Bob (WesternFarm)
struct  statedata_NPCSchBase gstructNPCSB_53[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_53_01 }, // 01
    {  0, gstructNPCSE_FW_Rest }, // 02
    {  0, gstructNPCSE_FW_Sleep }, // 03
    {  0, gstructNPCSE_FW_DeadSleep }, // 04
    {  0, gstructNPCSE_FW_DeadSleep }, // 05
    {  0, gstructNPCSE_FW_DeadSleep }, // 06
    {  0, gstructNPCSE_FW_DeadSleep }, // 07
    {  0, gstructNPCSE_FW_DeadSleep }, // 08
    {  0, gstructNPCSE_FW_DeadSleep }, // 09
    {  0, gstructNPCSE_FW_DeadSleep }, // 10
    {  0, gstructNPCSE_FW_DeadSleep }, // 11
    {  0, gstructNPCSE_FW_Sleep }, // 12
    {  0, gstructNPCSE_FW_Sleep }, // 13
    {  0, gstructNPCSE_FW_Sleep }, // 14
    {  0, gstructNPCSE_53_15 }, // 15
    {  0, gstructNPCSE_53_16 }, // 16
    {  0, gstructNPCSE_53_1718 }, // 17
    {  0, gstructNPCSE_53_1718 }, // 18
    {  0, gstructNPCSE_53_19 }, // 19
    {  0, gstructNPCSE_FW_Farming }, // 20
    {  0, gstructNPCSE_FW_Farming }, // 21
    {  0, gstructNPCSE_FW_Farming }, // 22
    {  0, gstructNPCSE_FW_Farming }, // 23
    {  0, gstructNPCSE_53_24 }, // 24
    {  0, gstructNPCSE_FW_Farming }, // 25
    {  0, gstructNPCSE_FW_Farming }, // 26
    {  0, gstructNPCSE_53_27 }, // 27
    {  0, gstructNPCSE_FW_Rest }, // 28
    {  0, gstructNPCSE_FW_Rest }, // 29
    {  0, gstructNPCSE_FW_Rest }, // 30
    {  0, gstructNPCSE_53_3132 }, // 31
    {  0, gstructNPCSE_53_3132 } // 32
};


//
// NPC-54 = Farmer-Jake (WesternFarm)
//

struct  statedata_NPCSchElement gstructNPCSE_54_12[] =
{
    { STATEACTION_EAT_N, 31,  2 },
    { STATEACTION_EAT_N, 32,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_20[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_21[] =
{
    { STATEACTION_HNG_N, 39,  1 },
    { STATEACTION_HNG_N, 41,  1 },
    { STATEACTION_HNG_N, 35,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_22[] =
{
    { STATEACTION_HNG_N, 23,  1 },
    { STATEACTION_HNG_N, 24,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_27[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_RES_N, 58,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_28[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_29[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_30[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_RES_D, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_54_31[] =
{
    { STATEACTION_RES_D, 26,  2 },
    { STATEACTION_RES_N, 58,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-54 = Farmer-Jake (WesternFarm)
struct  statedata_NPCSchBase gstructNPCSB_54[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_FW_DeadSleep }, // 01
    {  0, gstructNPCSE_FW_DeadSleep }, // 02
    {  0, gstructNPCSE_FW_DeadSleep }, // 03
    {  0, gstructNPCSE_FW_DeadSleep }, // 04
    {  0, gstructNPCSE_FW_DeadSleep }, // 05
    {  0, gstructNPCSE_FW_DeadSleep }, // 06
    {  0, gstructNPCSE_FW_DeadSleep }, // 07
    {  0, gstructNPCSE_FW_DeadSleep }, // 08
    {  0, gstructNPCSE_FW_Sleep }, // 09
    {  0, gstructNPCSE_FW_Sleep }, // 10
    {  0, gstructNPCSE_FW_Sleep }, // 11
    {  0, gstructNPCSE_54_12 }, // 12
    {  0, gstructNPCSE_FW_Farming }, // 13
    {  0, gstructNPCSE_FW_Farming }, // 14
    {  0, gstructNPCSE_FW_Farming }, // 15
    {  0, gstructNPCSE_FW_Rest }, // 16
    {  0, gstructNPCSE_FW_Farming }, // 17
    {  0, gstructNPCSE_FW_Farming }, // 18
    {  0, gstructNPCSE_FW_Rest }, // 19
    {  0, gstructNPCSE_54_20 }, // 20
    {  0, gstructNPCSE_54_21 }, // 21
    {  0, gstructNPCSE_54_22 }, // 22
    {  0, gstructNPCSE_FW_Farming }, // 23
    {  0, gstructNPCSE_FW_Farming }, // 24
    {  0, gstructNPCSE_FW_Rest }, // 25
    {  0, gstructNPCSE_FW_Rest }, // 26
    {  0, gstructNPCSE_54_27 }, // 27
    {  0, gstructNPCSE_54_28 }, // 28
    {  0, gstructNPCSE_54_29 }, // 29
    {  0, gstructNPCSE_54_30 }, // 30
    {  0, gstructNPCSE_54_31 }, // 31
    {  0, gstructNPCSE_FW_Sleep } // 32
};


//
// NPCs 55-56, Beggars (common)
//

struct  statedata_NPCSchElement gstructNPCSE_BE_Sleep[] =
{
    { STATEACTION_SLP_A, 34,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BE_DeadSleep[] =
{
    { STATEACTION_SLP_D, 34,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BE_Rest[] =
{
    { STATEACTION_RES_N, 34,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BE_Begging[] =
{
    { STATEACTION_RES_N, 31,  0 },
    { -1, -1, -1 }
};


//
// NPC-55 = Beggar-Olson
//

struct  statedata_NPCSchElement gstructNPCSE_55_10[] =
{
    { STATEACTION_RES_N, 34,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_55_11[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_55_12[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 34,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_55_27[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_55_29[] =
{
    { STATEACTION_SLP_A, 34,  1 },
    { STATEACTION_HNG_N, 55,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-55 = Beggar-Olson
struct  statedata_NPCSchBase gstructNPCSB_55[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BE_DeadSleep }, // 01
    {  0, gstructNPCSE_BE_DeadSleep }, // 02
    {  0, gstructNPCSE_BE_DeadSleep }, // 03
    {  0, gstructNPCSE_BE_DeadSleep }, // 04
    {  0, gstructNPCSE_BE_DeadSleep }, // 05
    {  0, gstructNPCSE_BE_Sleep }, // 06
    {  0, gstructNPCSE_BE_Sleep }, // 07
    {  0, gstructNPCSE_BE_Sleep }, // 08
    {  0, gstructNPCSE_BE_Rest }, // 09
    {  0, gstructNPCSE_55_10 }, // 10
    {  0, gstructNPCSE_55_11 }, // 11
    {  0, gstructNPCSE_55_12 }, // 12
    {  0, gstructNPCSE_BE_Rest }, // 13
    {  0, gstructNPCSE_BE_Rest }, // 14
    {  0, gstructNPCSE_BE_Begging }, // 15
    {  0, gstructNPCSE_BE_Begging }, // 16
    {  0, gstructNPCSE_BE_Begging }, // 17
    {  0, gstructNPCSE_BE_Begging }, // 18
    {  0, gstructNPCSE_BE_Begging }, // 19
    {  0, gstructNPCSE_BE_Rest }, // 20
    {  0, gstructNPCSE_BE_Rest }, // 21
    {  0, gstructNPCSE_BE_Rest }, // 22
    {  0, gstructNPCSE_BE_Rest }, // 23
    {  0, gstructNPCSE_BE_Rest }, // 24
    {  0, gstructNPCSE_BE_Rest }, // 25
    {  0, gstructNPCSE_BE_Rest }, // 26
    {  0, gstructNPCSE_55_27 }, // 27
    {  0, gstructNPCSE_BE_Rest }, // 28
    {  0, gstructNPCSE_55_29 }, // 29
    {  0, gstructNPCSE_BE_Sleep }, // 30
    {  0, gstructNPCSE_BE_Sleep }, // 31
    {  0, gstructNPCSE_BE_DeadSleep } // 32
};


//
// NPC-56 = Beggar-Perry
//

struct  statedata_NPCSchElement gstructNPCSE_56_08[] =
{
    { STATEACTION_SLP_A, 34,  1 },
    { STATEACTION_HNG_N, 53,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_56_12[] =
{
    { STATEACTION_RES_N, 34,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_56_13[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_56_14[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 34,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_56_28[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-56 = Beggar-Perry
struct  statedata_NPCSchBase gstructNPCSB_56[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BE_DeadSleep }, // 01
    {  0, gstructNPCSE_BE_DeadSleep }, // 02
    {  0, gstructNPCSE_BE_DeadSleep }, // 03
    {  0, gstructNPCSE_BE_DeadSleep }, // 04
    {  0, gstructNPCSE_BE_DeadSleep }, // 05
    {  0, gstructNPCSE_BE_Sleep }, // 06
    {  0, gstructNPCSE_BE_Sleep }, // 07
    {  0, gstructNPCSE_56_08 }, // 08
    {  0, gstructNPCSE_BE_Rest }, // 09
    {  0, gstructNPCSE_BE_Rest }, // 10
    {  0, gstructNPCSE_BE_Rest }, // 11
    {  0, gstructNPCSE_56_12 }, // 12
    {  0, gstructNPCSE_56_13 }, // 13
    {  0, gstructNPCSE_56_14 }, // 14
    {  0, gstructNPCSE_BE_Rest }, // 15
    {  0, gstructNPCSE_BE_Rest }, // 16
    {  0, gstructNPCSE_BE_Rest }, // 17
    {  0, gstructNPCSE_BE_Rest }, // 18
    {  0, gstructNPCSE_BE_Rest }, // 19
    {  0, gstructNPCSE_BE_Rest }, // 20
    {  0, gstructNPCSE_BE_Begging }, // 21
    {  0, gstructNPCSE_BE_Begging }, // 22
    {  0, gstructNPCSE_BE_Begging }, // 23
    {  0, gstructNPCSE_BE_Begging }, // 24
    {  0, gstructNPCSE_BE_Begging }, // 25
    {  0, gstructNPCSE_BE_Begging }, // 26
    {  0, gstructNPCSE_BE_Rest }, // 27
    {  0, gstructNPCSE_56_28 }, // 28
    {  0, gstructNPCSE_BE_Sleep }, // 29
    {  0, gstructNPCSE_BE_Sleep }, // 30
    {  0, gstructNPCSE_BE_DeadSleep }, // 31
    {  0, gstructNPCSE_BE_DeadSleep } // 32
};


//
// NPC-57 = Procurer-Marcel
//

struct  statedata_NPCSchElement gstructNPCSE_57_Sleep[] =
{
    { STATEACTION_SLP_A, 60,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_57_DeadSleep[] =
{
    { STATEACTION_SLP_D, 60,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_57_OwnShack[] =
{
    { STATEACTION_HNG_N, 60,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_57_0916[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_57_1011[] =
{
    { STATEACTION_DRK_N, 27,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_57_29[] =
{
    { STATEACTION_HNG_N, 63,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-57 = Procurer-Marcel
struct  statedata_NPCSchBase gstructNPCSB_57[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_57_Sleep }, // 01
    {  0, gstructNPCSE_57_DeadSleep }, // 02
    {  0, gstructNPCSE_57_DeadSleep }, // 03
    {  0, gstructNPCSE_57_DeadSleep }, // 04
    {  0, gstructNPCSE_57_DeadSleep }, // 05
    {  0, gstructNPCSE_57_Sleep }, // 06
    {  0, gstructNPCSE_57_OwnShack }, // 07
    {  0, gstructNPCSE_57_OwnShack }, // 08
    {  0, gstructNPCSE_57_0916 }, // 09
    {  0, gstructNPCSE_57_1011 }, // 10
    {  0, gstructNPCSE_57_1011 }, // 11
    {  0, gstructNPCSE_57_OwnShack }, // 12
    {  0, gstructNPCSE_57_OwnShack }, // 13
    {  0, gstructNPCSE_57_OwnShack }, // 14
    {  0, gstructNPCSE_57_OwnShack }, // 15
    {  0, gstructNPCSE_57_0916 }, // 16
    {  0, gstructNPCSE_57_OwnShack }, // 17
    {  0, gstructNPCSE_57_OwnShack }, // 18
    {  0, gstructNPCSE_57_OwnShack }, // 19
    {  0, gstructNPCSE_57_OwnShack }, // 20
    {  0, gstructNPCSE_57_OwnShack }, // 21
    {  0, gstructNPCSE_57_OwnShack }, // 22
    {  0, gstructNPCSE_57_Sleep }, // 23
    {  0, gstructNPCSE_57_DeadSleep }, // 24
    {  0, gstructNPCSE_57_DeadSleep }, // 25
    {  0, gstructNPCSE_57_DeadSleep }, // 26
    {  0, gstructNPCSE_57_DeadSleep }, // 27
    {  0, gstructNPCSE_57_Sleep }, // 28
    {  0, gstructNPCSE_57_29 }, // 29
    {  0, gstructNPCSE_57_OwnShack }, // 30
    {  0, gstructNPCSE_57_OwnShack }, // 31
    {  0, gstructNPCSE_57_OwnShack } // 32
};


//
// NPCs 58-59, Thugs (common)
//

struct  statedata_NPCSchElement gstructNPCSE_TH_Sleep[] =
{
    { STATEACTION_SLP_A, 61,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_TH_DeadSleep[] =
{
    { STATEACTION_SLP_D, 61,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_TH_OwnShack[] =
{
    { STATEACTION_HNG_N, 61,  0 },
    { -1, -1, -1 }
};


//
// NPC-58 = Thug-Rafael
//

struct  statedata_NPCSchElement gstructNPCSE_58_Forest[] =
{
    { STATEACTION_WRK_H, 45,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_58_12[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_58_18[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_58_23[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_58_26[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-58 = Thug-Rafael
struct  statedata_NPCSchBase gstructNPCSB_58[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_TH_DeadSleep }, // 01
    {  0, gstructNPCSE_TH_DeadSleep }, // 02
    {  0, gstructNPCSE_TH_Sleep }, // 03
    {  0, gstructNPCSE_TH_Sleep }, // 04
    {  0, gstructNPCSE_TH_Sleep }, // 05
    {  0, gstructNPCSE_TH_Sleep }, // 06
    {  0, gstructNPCSE_TH_OwnShack }, // 07
    {  0, gstructNPCSE_TH_OwnShack }, // 08
    {  0, gstructNPCSE_TH_OwnShack }, // 09
    {  0, gstructNPCSE_TH_OwnShack }, // 10
    {  0, gstructNPCSE_TH_OwnShack }, // 11
    {  0, gstructNPCSE_58_12 }, // 12
    { 63, NULL }, // 13
    {  0, gstructNPCSE_TH_OwnShack }, // 14
    {  0, gstructNPCSE_TH_OwnShack }, // 15
    {  0, gstructNPCSE_TH_OwnShack }, // 16
    {  0, gstructNPCSE_TH_OwnShack }, // 17
    {  0, gstructNPCSE_58_18 }, // 18
    {  0, gstructNPCSE_58_Forest }, // 19
    {  0, gstructNPCSE_58_Forest }, // 20
    {  0, gstructNPCSE_TH_OwnShack }, // 21
    {  0, gstructNPCSE_TH_OwnShack }, // 22
    {  0, gstructNPCSE_58_23 }, // 23
    {  0, gstructNPCSE_TH_OwnShack }, // 24
    {  0, gstructNPCSE_TH_OwnShack }, // 25
    {  0, gstructNPCSE_58_26 }, // 26
    {  0, gstructNPCSE_TH_OwnShack }, // 27
    {  0, gstructNPCSE_TH_Sleep }, // 28
    {  0, gstructNPCSE_TH_Sleep }, // 29
    {  0, gstructNPCSE_TH_Sleep }, // 30
    {  0, gstructNPCSE_TH_DeadSleep }, // 31
    {  0, gstructNPCSE_TH_DeadSleep } // 32
};


//
// NPC-59 = Thug-Judd
//

struct  statedata_NPCSchElement gstructNPCSE_59_10[] =
{
    { STATEACTION_HNG_N, 61,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_59_12[] =
{
    { STATEACTION_DRK_N, 26,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_59_13[] =
{
    { STATEACTION_DRK_N, 26,  3 },
    { STATEACTION_DRK_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_59_27[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_WRK_H, 45,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-59 = Thug-Judd
struct  statedata_NPCSchBase gstructNPCSB_59[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_TH_OwnShack }, // 01
    {  0, gstructNPCSE_TH_OwnShack }, // 02
    {  0, gstructNPCSE_TH_OwnShack }, // 03
    {  0, gstructNPCSE_TH_OwnShack }, // 04
    {  0, gstructNPCSE_TH_OwnShack }, // 05
    {  0, gstructNPCSE_TH_OwnShack }, // 06
    {  0, gstructNPCSE_TH_OwnShack }, // 07
    {  0, gstructNPCSE_TH_OwnShack }, // 08
    {  0, gstructNPCSE_TH_OwnShack }, // 09
    {  0, gstructNPCSE_59_10 }, // 10
    {  0, gstructNPCSE_TH_OwnShack }, // 11
    {  0, gstructNPCSE_59_12 }, // 12
    {  0, gstructNPCSE_59_13 }, // 13
    {  0, gstructNPCSE_TH_OwnShack }, // 14
    {  0, gstructNPCSE_TH_Sleep }, // 15
    {  0, gstructNPCSE_TH_Sleep }, // 16
    {  0, gstructNPCSE_TH_Sleep }, // 17
    {  0, gstructNPCSE_TH_DeadSleep }, // 18
    {  0, gstructNPCSE_TH_DeadSleep }, // 19
    {  0, gstructNPCSE_TH_DeadSleep }, // 20
    {  0, gstructNPCSE_TH_DeadSleep }, // 21
    {  0, gstructNPCSE_TH_DeadSleep }, // 22
    {  0, gstructNPCSE_TH_Sleep }, // 23
    {  0, gstructNPCSE_TH_Sleep }, // 24
    {  0, gstructNPCSE_TH_Sleep }, // 25
    {  0, gstructNPCSE_TH_Sleep }, // 26
    {  0, gstructNPCSE_59_27 }, // 27
    {  0, gstructNPCSE_TH_OwnShack }, // 28
    {  0, gstructNPCSE_TH_OwnShack }, // 29
    {  0, gstructNPCSE_TH_OwnShack }, // 30
    {  0, gstructNPCSE_TH_OwnShack }, // 31
    {  0, gstructNPCSE_TH_OwnShack } // 32
};


//
// NPC-60 = Smuggler-Fabian
//

struct  statedata_NPCSchElement gstructNPCSE_60_Sleep[] =
{
    { STATEACTION_SLP_A, 63,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_OwnShack[] =
{
    { STATEACTION_HNG_N, 63,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_10[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 63,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_11[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_EAT_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_12[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_DRK_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_13[] =
{
    { STATEACTION_RES_N, 63,  2 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_16[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_1718[] =
{
    { STATEACTION_WRK_H, 45,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_60_28[] =
{
    { STATEACTION_RES_N, 63,  0 },
    { -1, -1, -1 }
};

// Schedule: NPC-60 = Smuggler-Fabian
struct  statedata_NPCSchBase gstructNPCSB_60[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_60_Sleep }, // 01
    {  0, gstructNPCSE_60_Sleep }, // 02
    {  0, gstructNPCSE_60_Sleep }, // 03
    {  0, gstructNPCSE_60_Sleep }, // 04
    {  0, gstructNPCSE_60_Sleep }, // 05
    {  0, gstructNPCSE_60_Sleep }, // 06
    {  0, gstructNPCSE_60_OwnShack }, // 07
    {  0, gstructNPCSE_60_OwnShack }, // 08
    {  0, gstructNPCSE_60_OwnShack }, // 09
    {  0, gstructNPCSE_60_10 }, // 10
    {  0, gstructNPCSE_60_11 }, // 11
    {  0, gstructNPCSE_60_12 }, // 12
    {  0, gstructNPCSE_60_13 }, // 13
    {  0, gstructNPCSE_60_OwnShack }, // 14
    {  0, gstructNPCSE_60_OwnShack }, // 15
    {  0, gstructNPCSE_60_16 }, // 16
    {  0, gstructNPCSE_60_1718 }, // 17
    {  0, gstructNPCSE_60_1718 }, // 18
    {  0, gstructNPCSE_60_OwnShack }, // 19
    {  0, gstructNPCSE_60_OwnShack }, // 20
    {  0, gstructNPCSE_60_OwnShack }, // 21
    {  0, gstructNPCSE_60_OwnShack }, // 22
    {  0, gstructNPCSE_60_OwnShack }, // 23
    {  0, gstructNPCSE_60_OwnShack }, // 24
    {  0, gstructNPCSE_60_Sleep }, // 25
    {  0, gstructNPCSE_60_Sleep }, // 26
    {  0, gstructNPCSE_60_Sleep }, // 27
    {  0, gstructNPCSE_60_28 }, // 28
    {  0, gstructNPCSE_60_OwnShack }, // 29
    {  0, gstructNPCSE_60_OwnShack }, // 30
    {  0, gstructNPCSE_60_OwnShack }, // 31
    {  0, gstructNPCSE_60_OwnShack } // 32
};


//
// NPCs 61-64, Bandits (common)
//

struct  statedata_NPCSchElement gstructNPCSE_BA_Sleep[] =
{
    { STATEACTION_SLP_A, 64,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BA_DeadSleep[] =
{
    { STATEACTION_SLP_D, 64,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BA_Resting[] =
{
    { STATEACTION_RES_N, 64,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_BA_Hiding[] =
{
    { STATEACTION_WRK_H, 45,  0 },
    { -1, -1, -1 }
};


//
// NPC-61 = Bandit Boss-Aho
//

struct  statedata_NPCSchElement gstructNPCSE_61_11[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_12[] =
{
    { STATEACTION_EAT_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_13[] =
{
    { STATEACTION_DRK_N, 26,  2 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_14[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_23[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_24[] =
{
    { STATEACTION_EAT_N, 26,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_25[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_61_26[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { STATEACTION_HNG_N,  2,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-61 = Bandit Boss-Aho
struct  statedata_NPCSchBase gstructNPCSB_61[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BA_Sleep }, // 01
    {  0, gstructNPCSE_BA_Sleep }, // 02
    {  0, gstructNPCSE_BA_Sleep }, // 03
    {  0, gstructNPCSE_BA_Sleep }, // 04
    {  0, gstructNPCSE_BA_DeadSleep }, // 05
    {  0, gstructNPCSE_BA_DeadSleep }, // 06
    {  0, gstructNPCSE_BA_Sleep }, // 07
    {  0, gstructNPCSE_BA_Sleep }, // 08
    {  0, gstructNPCSE_BA_Sleep }, // 09
    {  0, gstructNPCSE_BA_Resting }, // 10
    {  0, gstructNPCSE_61_11 }, // 11
    {  0, gstructNPCSE_61_12 }, // 12
    {  0, gstructNPCSE_61_13 }, // 13
    {  0, gstructNPCSE_61_14 }, // 14
    {  0, gstructNPCSE_BA_Resting }, // 15
    {  0, gstructNPCSE_BA_Resting }, // 16
    {  0, gstructNPCSE_BA_Hiding }, // 17
    {  0, gstructNPCSE_BA_Hiding }, // 18
    {  0, gstructNPCSE_BA_Resting }, // 19
    {  0, gstructNPCSE_BA_Resting }, // 20
    {  0, gstructNPCSE_BA_Resting }, // 21
    {  0, gstructNPCSE_BA_Resting }, // 22
    {  0, gstructNPCSE_61_23 }, // 23
    {  0, gstructNPCSE_61_24 }, // 24
    {  0, gstructNPCSE_61_25 }, // 25
    {  0, gstructNPCSE_61_26 }, // 26
    {  0, gstructNPCSE_BA_Resting }, // 27
    {  0, gstructNPCSE_BA_Resting }, // 28
    {  0, gstructNPCSE_BA_Resting }, // 29
    {  0, gstructNPCSE_BA_Resting }, // 30
    {  0, gstructNPCSE_BA_Resting }, // 31
    {  0, gstructNPCSE_BA_Resting } // 32
};


//
// NPC-62 = Bandit-Benson
//

struct  statedata_NPCSchElement gstructNPCSE_62_10[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_62_14[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_DRK_N, 26,  3 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_62_15[] =
{
    { STATEACTION_DRK_N, 26,  2 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_62_21[] =
{
    { STATEACTION_EAT_N, 31,  1 },
    { STATEACTION_WRK_H, 45,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_62_26[] =
{
    { STATEACTION_HNG_N, 26,  2 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_62_27[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  3 },
    { -1, -1, -1 }
};

// Schedule: NPC-62 = Bandit-Benson
struct  statedata_NPCSchBase gstructNPCSB_62[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_BA_DeadSleep }, // 01
    {  0, gstructNPCSE_BA_Sleep }, // 02
    {  0, gstructNPCSE_BA_Sleep }, // 03
    {  0, gstructNPCSE_BA_Sleep }, // 04
    {  0, gstructNPCSE_BA_Resting }, // 05
    {  0, gstructNPCSE_BA_Resting }, // 06
    {  0, gstructNPCSE_BA_Resting }, // 07
    {  0, gstructNPCSE_BA_Resting }, // 08
    {  0, gstructNPCSE_BA_Resting }, // 09
    {  0, gstructNPCSE_62_10 }, // 10
    {  0, gstructNPCSE_BA_Resting }, // 11
    {  0, gstructNPCSE_BA_Resting }, // 12
    { 63, NULL }, // 13
    {  0, gstructNPCSE_62_14 }, // 14
    {  0, gstructNPCSE_62_15 }, // 15
    {  0, gstructNPCSE_BA_Resting }, // 16
    {  0, gstructNPCSE_BA_Resting }, // 17
    {  0, gstructNPCSE_BA_Resting }, // 18
    {  0, gstructNPCSE_BA_Resting }, // 19
    {  0, gstructNPCSE_BA_Resting }, // 20
    {  0, gstructNPCSE_62_21 }, // 21
    {  0, gstructNPCSE_BA_Resting }, // 22
    {  0, gstructNPCSE_BA_Resting }, // 23
    {  0, gstructNPCSE_BA_Resting }, // 24
    {  0, gstructNPCSE_BA_Resting }, // 25
    {  0, gstructNPCSE_62_26 }, // 26
    {  0, gstructNPCSE_62_27 }, // 27
    {  0, gstructNPCSE_BA_Sleep }, // 28
    {  0, gstructNPCSE_BA_Sleep }, // 29
    {  0, gstructNPCSE_BA_Sleep }, // 30
    {  0, gstructNPCSE_BA_Sleep }, // 31
    {  0, gstructNPCSE_BA_DeadSleep } // 32
};


//
// NPC-63 = Bandit-Shaw
//

struct  statedata_NPCSchElement gstructNPCSE_63_01[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_11[] =
{
    { STATEACTION_EAT_N, 31,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_13[] =
{
    { STATEACTION_HNG_N, 24,  1 },
    { STATEACTION_HNG_N, 21,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_15[] =
{
    { STATEACTION_RES_N, 64,  2 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_16[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_17[] =
{
    { STATEACTION_HNG_N, 26,  2 },
    { STATEACTION_DRK_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_20[] =
{
    { STATEACTION_RES_N, 64,  1 },
    { STATEACTION_EAT_N, 31,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_21[] =
{
    { STATEACTION_DRK_N, 26,  2 },
    { STATEACTION_HNG_N, 26,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_22[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_DRK_N, 26,  3 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_29[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_63_30[] =
{
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_HNG_N, 26,  4 },
    { -1, -1, -1 }
};

// Schedule: NPC-63 = Bandit-Shaw
struct  statedata_NPCSchBase gstructNPCSB_63[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_63_01 }, // 01
    {  0, gstructNPCSE_BA_Sleep }, // 02
    {  0, gstructNPCSE_BA_Sleep }, // 03
    {  0, gstructNPCSE_BA_Sleep }, // 04
    {  0, gstructNPCSE_BA_Sleep }, // 05
    {  0, gstructNPCSE_BA_DeadSleep }, // 06
    {  0, gstructNPCSE_BA_DeadSleep }, // 07
    {  0, gstructNPCSE_BA_Sleep }, // 08
    {  0, gstructNPCSE_BA_Sleep }, // 09
    {  0, gstructNPCSE_BA_Sleep }, // 10
    {  0, gstructNPCSE_63_11 }, // 11
    {  0, gstructNPCSE_BA_Resting }, // 12
    {  0, gstructNPCSE_63_13 }, // 13
    {  0, gstructNPCSE_BA_Resting }, // 14
    {  0, gstructNPCSE_63_15 }, // 15
    {  0, gstructNPCSE_63_16 }, // 16
    {  0, gstructNPCSE_63_17 }, // 17
    {  0, gstructNPCSE_BA_Resting }, // 18
    {  0, gstructNPCSE_BA_Resting }, // 19
    {  0, gstructNPCSE_63_20 }, // 20
    {  0, gstructNPCSE_63_21 }, // 21
    {  0, gstructNPCSE_63_22 }, // 22
    {  0, gstructNPCSE_BA_Resting }, // 23
    {  0, gstructNPCSE_BA_Resting }, // 24
    {  0, gstructNPCSE_BA_Resting }, // 25
    {  0, gstructNPCSE_BA_Resting }, // 26
    {  0, gstructNPCSE_BA_Resting }, // 27
    {  0, gstructNPCSE_BA_Resting }, // 28
    {  0, gstructNPCSE_63_29 }, // 29
    {  0, gstructNPCSE_63_30 }, // 30
    {  0, gstructNPCSE_BA_Resting }, // 31
    {  0, gstructNPCSE_BA_Resting } // 32
};


//
// NPC-64 = Bandit-Javier
//

struct  statedata_NPCSchElement gstructNPCSE_64_OwnShack[] =
{
    { STATEACTION_HNG_N, 64,  0 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_01[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_RES_N, 64,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_05[] =
{
    { STATEACTION_HNG_N, 45,  2 },
    { STATEACTION_HNG_N, 43,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_18[] =
{
    { STATEACTION_EAT_N, 27,  1 },
    { STATEACTION_EAT_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_19[] =
{
    { STATEACTION_HNG_N, 27,  1 },
    { STATEACTION_HNG_N, 26,  2 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_20[] =
{
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_DRK_N, 26,  1 },
    { STATEACTION_RES_N, 64,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_31[] =
{
    { STATEACTION_RES_N, 64,  2 },
    { STATEACTION_DRK_N, 27,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

struct  statedata_NPCSchElement gstructNPCSE_64_32[] =
{
    { STATEACTION_HNG_N, 26,  1 },
    { STATEACTION_HNG_N, 27,  1 },
    { -1, -1, -1 }
};

// Schedule: NPC-64 = Bandit-Javier
struct  statedata_NPCSchBase gstructNPCSB_64[STATEDATA_TIMESLOTS] =
{
    {  0, gstructNPCSE_64_01 }, // 01
    {  0, gstructNPCSE_BA_Resting }, // 02
    {  0, gstructNPCSE_BA_Resting }, // 03
    {  0, gstructNPCSE_BA_Resting }, // 04
    {  0, gstructNPCSE_64_05 }, // 05
    {  0, gstructNPCSE_BA_Hiding }, // 06
    {  0, gstructNPCSE_BA_Hiding }, // 07
    {  0, gstructNPCSE_BA_Resting }, // 08
    {  0, gstructNPCSE_BA_Resting }, // 09
    {  0, gstructNPCSE_BA_Resting }, // 10
    {  0, gstructNPCSE_64_OwnShack }, // 11
    {  0, gstructNPCSE_64_OwnShack }, // 12
    {  0, gstructNPCSE_64_OwnShack }, // 13
    {  0, gstructNPCSE_64_OwnShack }, // 14
    {  0, gstructNPCSE_BA_Resting }, // 15
    {  0, gstructNPCSE_BA_Resting }, // 16
    {  0, gstructNPCSE_BA_Resting }, // 17
    {  0, gstructNPCSE_64_18 }, // 18
    {  0, gstructNPCSE_64_19 }, // 19
    {  0, gstructNPCSE_64_20 }, // 20
    {  0, gstructNPCSE_BA_Sleep }, // 21
    {  0, gstructNPCSE_BA_Sleep }, // 22
    {  0, gstructNPCSE_BA_Sleep }, // 23
    {  0, gstructNPCSE_BA_Sleep }, // 24
    {  0, gstructNPCSE_BA_DeadSleep }, // 25
    {  0, gstructNPCSE_BA_DeadSleep }, // 26
    {  0, gstructNPCSE_BA_Sleep }, // 27
    {  0, gstructNPCSE_BA_Sleep }, // 28
    {  0, gstructNPCSE_BA_Sleep }, // 29
    {  0, gstructNPCSE_BA_Resting }, // 30
    {  0, gstructNPCSE_64_31 }, // 31
    {  0, gstructNPCSE_64_32 } // 32
};

//----------------------------------------------------------------------

struct  statedata_NPCData *gpstructNPC_Base = NULL;
struct  statedata_GlobalData gpstructPC_Global;

struct  statedata_NPCPriorityList *gpstructNPC_Priority = NULL;
short   gsNPC_PriorityUsed = 0;


//
// Function to init (and check) the NPC variable storage.
//
int statedata_allocAndInit ()
{
    short   sOffset1;
    short   sOffset2;
    short   sOffset3;
    int     iCount;
    short   sCalc;
    char    szWorkBuffer[200];
    int     iRet;

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

    // allocate the memory
    gpstructNPC_Priority = (struct statedata_NPCPriorityList *)malloc ((size_t)sizeof (struct statedata_NPCPriorityList) * (size_t)((size_t)STATEDATA_NPCS + (size_t)2));

    // if there was a problem with the malloc, return 1.
    if (gpstructNPC_Priority == NULL)
        return 1;
    // Note: this array isn't large, so I allocate to the maximum number of NPCs anyway.

    // allocate the memory
    gpstructNPC_Base = (struct statedata_NPCData *)malloc ((size_t)sizeof (struct statedata_NPCData) * (size_t)((size_t)STATEDATA_NPCS + (size_t)2));

    // if there was a problem with the malloc, return 1.
    if (gpstructNPC_Base == NULL)
        return 1;

    // check the location data
    for (sOffset1 = 0; sOffset1 < 64; sOffset1++)
    {
        if (gstructLocationList[sOffset1].cLocationId != (char)((char)sOffset1 + (char)1))
        {
            sprintf (szWorkBuffer, "Location: Invalid offset in list %d !\n", (int)sOffset1 + 1);
            iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
            if (iRet != 0) return iRet;
            return 6;
        }
    }
    // Note: 64 is the number of location data entries, which is sort of hardcoded here..
    //  I should have constructed a dynamic evaluation, but.. meh..

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
        gpstructNPC_Base[sOffset1].structNPCSched = NULL;
    }

    // link in the entries.
    gpstructNPC_Base[0].structNPCSched = gstructNPCSB_01;
    gpstructNPC_Base[1].structNPCSched = gstructNPCSB_02;
    gpstructNPC_Base[2].structNPCSched = gstructNPCSB_03;
    gpstructNPC_Base[3].structNPCSched = gstructNPCSB_04;
    gpstructNPC_Base[4].structNPCSched = gstructNPCSB_05;
    gpstructNPC_Base[5].structNPCSched = gstructNPCSB_06;
    gpstructNPC_Base[6].structNPCSched = gstructNPCSB_07;
    gpstructNPC_Base[7].structNPCSched = gstructNPCSB_08;
    gpstructNPC_Base[8].structNPCSched = gstructNPCSB_09;
    gpstructNPC_Base[9].structNPCSched = gstructNPCSB_10;
    gpstructNPC_Base[10].structNPCSched = gstructNPCSB_11;
    gpstructNPC_Base[11].structNPCSched = gstructNPCSB_12;
    gpstructNPC_Base[12].structNPCSched = gstructNPCSB_13;
    gpstructNPC_Base[13].structNPCSched = gstructNPCSB_14;
    gpstructNPC_Base[14].structNPCSched = gstructNPCSB_15;
    gpstructNPC_Base[15].structNPCSched = gstructNPCSB_16;
    gpstructNPC_Base[16].structNPCSched = gstructNPCSB_17;
    gpstructNPC_Base[17].structNPCSched = gstructNPCSB_18;
    gpstructNPC_Base[18].structNPCSched = gstructNPCSB_19;
    gpstructNPC_Base[19].structNPCSched = gstructNPCSB_20;
    gpstructNPC_Base[20].structNPCSched = gstructNPCSB_21;
    gpstructNPC_Base[21].structNPCSched = gstructNPCSB_22;
    gpstructNPC_Base[22].structNPCSched = gstructNPCSB_23;
    gpstructNPC_Base[23].structNPCSched = gstructNPCSB_24;
    gpstructNPC_Base[24].structNPCSched = gstructNPCSB_25;
    gpstructNPC_Base[25].structNPCSched = gstructNPCSB_26;
    gpstructNPC_Base[26].structNPCSched = gstructNPCSB_27;
    gpstructNPC_Base[27].structNPCSched = gstructNPCSB_28;
    gpstructNPC_Base[28].structNPCSched = gstructNPCSB_29;
    gpstructNPC_Base[29].structNPCSched = gstructNPCSB_30;
    gpstructNPC_Base[30].structNPCSched = gstructNPCSB_31;
    gpstructNPC_Base[31].structNPCSched = gstructNPCSB_32;
    gpstructNPC_Base[32].structNPCSched = gstructNPCSB_33;
    gpstructNPC_Base[33].structNPCSched = gstructNPCSB_34;
    gpstructNPC_Base[34].structNPCSched = gstructNPCSB_35;
    gpstructNPC_Base[35].structNPCSched = gstructNPCSB_36;
    gpstructNPC_Base[36].structNPCSched = gstructNPCSB_37;
    gpstructNPC_Base[37].structNPCSched = gstructNPCSB_38;
    gpstructNPC_Base[38].structNPCSched = gstructNPCSB_39;
    gpstructNPC_Base[39].structNPCSched = gstructNPCSB_40;
    gpstructNPC_Base[40].structNPCSched = gstructNPCSB_41;
    gpstructNPC_Base[41].structNPCSched = gstructNPCSB_42;
    gpstructNPC_Base[42].structNPCSched = gstructNPCSB_43;
    gpstructNPC_Base[43].structNPCSched = gstructNPCSB_44;
    gpstructNPC_Base[44].structNPCSched = gstructNPCSB_45;
    gpstructNPC_Base[45].structNPCSched = gstructNPCSB_46;
    gpstructNPC_Base[46].structNPCSched = gstructNPCSB_47;
    gpstructNPC_Base[47].structNPCSched = gstructNPCSB_48;
    gpstructNPC_Base[48].structNPCSched = gstructNPCSB_49;
    gpstructNPC_Base[49].structNPCSched = gstructNPCSB_50;
    gpstructNPC_Base[50].structNPCSched = gstructNPCSB_51;
    gpstructNPC_Base[51].structNPCSched = gstructNPCSB_52;
    gpstructNPC_Base[52].structNPCSched = gstructNPCSB_53;
    gpstructNPC_Base[53].structNPCSched = gstructNPCSB_54;
    gpstructNPC_Base[54].structNPCSched = gstructNPCSB_55;
    gpstructNPC_Base[55].structNPCSched = gstructNPCSB_56;
    gpstructNPC_Base[56].structNPCSched = gstructNPCSB_57;
    gpstructNPC_Base[57].structNPCSched = gstructNPCSB_58;
    gpstructNPC_Base[58].structNPCSched = gstructNPCSB_59;
    gpstructNPC_Base[59].structNPCSched = gstructNPCSB_60;
    gpstructNPC_Base[60].structNPCSched = gstructNPCSB_61;
    gpstructNPC_Base[61].structNPCSched = gstructNPCSB_62;
    gpstructNPC_Base[62].structNPCSched = gstructNPCSB_63;
    gpstructNPC_Base[63].structNPCSched = gstructNPCSB_64;

    //
    // Now to perform a sanity check of the schedule data.
    //

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        if (gpstructNPC_Base[sOffset1].structNPCSched == NULL)
        {
            sprintf (szWorkBuffer, "Schedule: NPC %d has no Schedule data !\n", (int)sOffset1 + 1);
#ifdef INTERFACE_CURSES
            iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
            if (iRet != 0) return iRet;
            return 6;
#else
            httpcgi_errorOutput (szWorkBuffer, 101);
#endif
        }

        for (sOffset2 = 0; sOffset2 < STATEDATA_TIMESLOTS; sOffset2++)
        {
            if ((gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId == 0) && (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList == NULL))
            {
                sprintf (szWorkBuffer, "Schedule: NPC %d-%d Missing Slot data !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                if (iRet != 0) return iRet;
                return 6;
#else
                httpcgi_errorOutput (szWorkBuffer, 102);
#endif
            }

            if ((gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId != 0) && (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList != NULL))
            {
                sprintf (szWorkBuffer, "Schedule: NPC %d-%d Cannot have Slot data AND a link reference !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                if (iRet != 0) return iRet;
                return 6;
#else
                httpcgi_errorOutput (szWorkBuffer, 103);
#endif
            }

            if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId != 0)
            {
                if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId > STATEDATA_NPCS)
                {
                    sprintf (szWorkBuffer, "Schedule: NPC %d-%d Link reference is out of bounds !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                    iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                    if (iRet != 0) return iRet;
                    return 6;
#else
                    httpcgi_errorOutput (szWorkBuffer, 104);
#endif
                }

                continue;
            }

            sOffset3 = 0;
            iCount = 0;
            sCalc = 0;

            while (1)
            {
                if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].cActionId == -1)
                    break;

                if (iCount > 20)
                {
                    sprintf (szWorkBuffer, "Schedule: NPC %d-%d Corrupt Slot data !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                    iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                    if (iRet != 0) return iRet;
                    return 6;
#else
                    httpcgi_errorOutput (szWorkBuffer, 105);
#endif
                }

                if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].sPercentValue == 0)
                {
                    if ((sOffset3) || (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3 + 1].cActionId != -1))
                    {
                        sprintf (szWorkBuffer, "Schedule: NPC %d-%d-%d Percent value invalid (zero) !\n", (int)sOffset1 + 1, (int)sOffset2 + 1, (int)sOffset3 + 1);
#ifdef INTERFACE_CURSES
                        iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                        if (iRet != 0) return iRet;
                        return 6;
#else
                        httpcgi_errorOutput (szWorkBuffer, 106);
#endif
                    }
                }

                iCount++;
                sCalc += gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].sPercentValue;
                sOffset3++;
            }

            if (sOffset3 == 0)
            {
                sprintf (szWorkBuffer, "Schedule: NPC %d-%d Invalid Slot data !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                if (iRet != 0) return iRet;
                return 6;
#else
                httpcgi_errorOutput (szWorkBuffer, 107);
#endif
            }

            if (sOffset3 == 1)
            {
                if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[0].sPercentValue != 0)
                {
                    sprintf (szWorkBuffer, "Schedule: NPC %d-%d-1 Percent value invalid (non-zero) !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                    iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                    if (iRet != 0) return iRet;
                    return 6;
#else
                    httpcgi_errorOutput (szWorkBuffer, 108);
#endif
                }
            }

            if (sCalc >= STATEDATA_ARRAYMAX)
            {
                sprintf (szWorkBuffer, "Schedule: NPC %d-%d Total percent value larger than max !\n", (int)sOffset1 + 1, (int)sOffset2 + 1);
#ifdef INTERFACE_CURSES
                iRet = mdialog_addToDialogWithSrchRep (szWorkBuffer);
                if (iRet != 0) return iRet;
                return 6;
#else
                httpcgi_errorOutput (szWorkBuffer, 109);
#endif
            }
        }
    }

#ifdef INTERFACE_CURSES
    iRet = mdialog_addToDialogWithSrchRep ("Schedule: 64 NPCs loaded and checked.\n");
    if (iRet != 0) return iRet;
#endif

    return 0;
}


//
// Function to increment the date/time, and update where all of the NPCs are according to the schedule.
//
int statedata_incrementDateTimeAndUpdate ()
{
    struct statedata_NPCSchArray structScheduleArray[STATEDATA_ARRAYMAX];
    short sOffset1;
    short sOffset2;
    short sOffset1a;
    short sOffset3;
    short sOffset4;
    short sValue1;
    short sCalc;
    int iCount;
    short sRand;

    //
    // first increment the time value, and adjust the day counter as well.
    //
    gpstructPC_Global.cTimeValue++;
    if (gpstructPC_Global.cTimeValue > 32)
    {
        gpstructPC_Global.cTimeValue = 1;
        gpstructPC_Global.iDayCount++;
    }

    // this gives us our offset slot offset.
    sOffset2 = (short)gpstructPC_Global.cTimeValue - 1;

    //
    // first pass to figure out the primary actions
    //
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // ignore entries that are linkages to other NPCs
        if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId != 0)
            continue;

        // if the percent value for the first entry is 0, then it is the only entry (no random selection).
        if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[0].sPercentValue == 0)
        {
            // the validity of this is verified during init.
            gpstructNPC_Base[sOffset1].cActionId = gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[0].cActionId;
            gpstructNPC_Base[sOffset1].cLocationId = gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[0].cLocationId;
        }
        else
        {
            sOffset3 = 0;
            iCount = 0;
            sCalc = 0;

            // while loop to construct the list to select from (build the selection array).
            while (1)
            {
                if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].cActionId == -1)
                    break;

                sValue1 = gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].sPercentValue;

                for (sOffset4 = 0; sOffset4 < sValue1; sOffset4++)
                {
                    structScheduleArray[sCalc + sOffset4].cActionId = gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].cActionId;
                    structScheduleArray[sCalc + sOffset4].cLocationId = gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].pstructList[sOffset3].cLocationId;
                }

                iCount++;
                sCalc += sValue1;
                sOffset3++;
            }

            // Rather than come up with a complex selection method, I populate an array with the possibilities first, then just use a RNG modulus to the size of the array.
            sRand = (short)((short)rand() % sCalc);

            // now that I have selected my entry out of the array, that is what is populated as the NPC location and action.
            gpstructNPC_Base[sOffset1].cActionId = structScheduleArray[sRand].cActionId;
            gpstructNPC_Base[sOffset1].cLocationId = structScheduleArray[sRand].cLocationId;
        }

        // Now to populate the area id for the location id.
        gpstructNPC_Base[sOffset1].cAreaId = gstructLocationList[gpstructNPC_Base[sOffset1].cLocationId - 1].cAreaId;
        // I am going to cheat here, and use the location as the offset to the list.
        // I put a check in the init above to make sure that the offsets match the locations.
    }

    //
    // Because of the way that linkages work, I need to scan the NPC list again
    //
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // ignore that aren't linkages to other NPCs
        if (gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId == 0)
            continue;

        sOffset1a = (short)gpstructNPC_Base[sOffset1].structNPCSched[sOffset2].cLinkId - 1;

        // copy the values from the source NPC across to this one.
        gpstructNPC_Base[sOffset1].cAreaId = gpstructNPC_Base[sOffset1a].cAreaId;
        gpstructNPC_Base[sOffset1].cActionId = gpstructNPC_Base[sOffset1a].cActionId;
        gpstructNPC_Base[sOffset1].cLocationId = gpstructNPC_Base[sOffset1a].cLocationId;

        // Note: at no point do I check here, or in the init code if there is a circular or multiple linkage happening.
    }

    //
    // Third scan of the NPCs is to bump up the iEnergyValue
    //
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // if at the maximum value, ignore this entry.
        if (gpstructNPC_Base[sOffset1].iEnergyValue == STATEDATA_ENERGYMAX)
            continue;

        // if above the maximum value, correct this entry.
        if (gpstructNPC_Base[sOffset1].iEnergyValue > STATEDATA_ENERGYMAX)
        {
            gpstructNPC_Base[sOffset1].iEnergyValue = STATEDATA_ENERGYMAX;
            continue;
        }

        // if at 0 (just had sex with the PC), increment a nominal amount.
        if (gpstructNPC_Base[sOffset1].iEnergyValue == 0)
        {
            gpstructNPC_Base[sOffset1].iEnergyValue = 5;
            continue;
        }

        // increment the energy value depending upon the action being performed.
        switch (gpstructNPC_Base[sOffset1].cActionId)
        {
        case STATEACTION_SLP_D:
            gpstructNPC_Base[sOffset1].iEnergyValue += STATEDATA_ENERGYINC_SLP_D;
            break;

        case STATEACTION_SLP_A:
            gpstructNPC_Base[sOffset1].iEnergyValue += STATEDATA_ENERGYINC_SLP_A;
            break;

        case STATEACTION_RES_N:
            gpstructNPC_Base[sOffset1].iEnergyValue += STATEDATA_ENERGYINC_RES_N;
            break;

        case STATEACTION_RES_D:
            gpstructNPC_Base[sOffset1].iEnergyValue += STATEDATA_ENERGYINC_RES_D;
            break;

        default:
            gpstructNPC_Base[sOffset1].iEnergyValue += STATEDATA_ENERGYINC;
            break;
        }
        // I pre-calculated the values, rather than relying upon float/int math at run time.

        // if above the maximum, correct it..
        if (gpstructNPC_Base[sOffset1].iEnergyValue > STATEDATA_ENERGYMAX)
        {
            gpstructNPC_Base[sOffset1].iEnergyValue = STATEDATA_ENERGYMAX;
        }
        // why am I doing this twice, well.. I just incremented it, so I should make sure that I cap it.
    }

    return 0;
}


//
// Function to return a list of NPC actions at the specified location.
//
void statedata_visibleNPCs (char cLocationId, char *pcActionArray)
{
    short sOffset1;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // ignore any NPCs who are hidden or deep asleep.
        if ((gpstructNPC_Base[sOffset1].cActionId == STATEACTION_WRK_H) || (gpstructNPC_Base[sOffset1].cActionId == STATEACTION_SLP_D))
        {
            pcActionArray[sOffset1] = 0;
            continue;
        }

        if (gpstructNPC_Base[sOffset1].cLocationId == cLocationId)
            pcActionArray[sOffset1] = gpstructNPC_Base[sOffset1].cActionId;
        else
            pcActionArray[sOffset1] = 0;
    }
}


//
// Function to return a list of deep-sleep NPCs at the specified location.
//
void statedata_sleepingNPCs (char cLocationId, char *pcActionArray)
{
    short sOffset1;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // ignore any NPCs who are not deep asleep.
        if (gpstructNPC_Base[sOffset1].cActionId != STATEACTION_SLP_D)
        {
            pcActionArray[sOffset1] = 0;
            continue;
        }

        if (gpstructNPC_Base[sOffset1].cLocationId == cLocationId)
            pcActionArray[sOffset1] = gpstructNPC_Base[sOffset1].cActionId;
        else
            pcActionArray[sOffset1] = 0;
    }
}


//
// Function to call out the NPCs in a given location.
//
// This function has to figure out who is known and unknown.
//  This also changes the status of a NPC so that they are known.
//
// returns 0 for only known NPCs at the location.
// returns 1 for memory errors.
// returns 6 for no NPCs at the location.
// returns 10 for some previously unknown NPCs at the location.
//
int statedata_nameLocalNPCs (char cLocationId)
{
    char cArray1[STATEDATA_NPCS + 1];
    char cArray2[STATEDATA_NPCS + 1];
    int iCount;
    int iKnownCount;
    int iUnknownCount;
    int iCountDown;
    short sOffset1;
    int iRet;

    statedata_visibleNPCs (cLocationId, cArray1);

    iCount = 0;
    iKnownCount = 0;
    iUnknownCount = 0;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        cArray2[sOffset1] = 0;

        if (cArray1[sOffset1] == 0)
            continue;

        if (gpstructNPC_Base[sOffset1].cNameToFaceFlag == 1)
        {
            cArray2[sOffset1] = 1; // known
            iKnownCount++;
        }
        else
        {
            cArray2[sOffset1] = 2; // unknown
            iUnknownCount++;
        }

        iCount++;
    }

    if (iCount == 0)
        return 6;

    //
    // Take care of the unknowns.
    //
    if (iUnknownCount != 0)
    {
        iCountDown = iUnknownCount;

        iRet = mdialog_addToDialogWithSrchRep (" ");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" meets ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] == 2)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                // change this NPC to being known.
                gpstructNPC_Base[sOffset1].cNameToFaceFlag = 1;

                if (iUnknownCount == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        iRet = mdialog_addToDialogWithSrchRep (" for the first time.");
        if (iRet != 0) return iRet;
    }

    if (iKnownCount != 0)
    {
        iCountDown = iKnownCount;

        iRet = mdialog_addToDialogWithSrchRep (" ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] == 1)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (iKnownCount == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iKnownCount == 1)
            iRet = mdialog_addToDialogWithSrchRep (" is here as well.");
        else
            iRet = mdialog_addToDialogWithSrchRep (" are here as well.");
    }

    if (iUnknownCount != 0)
        return 10;

    return 0;
}


//
// Function to call out the NPCs at 2 given locations.
//  The assumption is that the 2 locations are within the same area.
//
// This function has to figure out who is known and unknown.
//  This also changes the status of a NPC so that they are known.
//
// returns 0 for only known NPCs at the location.
// returns 1 for memory errors.
// returns 6 for no NPCs at the location.
// returns 10 for some previously unknown NPCs at the location.
//
// I created this variant of the above function because there are
//  some locations in the village where the PC can see not only
//  the current location, but a nearby one (such as a roped/fenced
//  off area). This is important as the PC can talk to people on
//  the otherside of the fence, and therefore be introduced to them.
//
// I decided to keep the function simple, and not bother with
//  sorting according to the location of the PC.
//
int statedata_nameLocalNPCsx2 (char cLocationId1, char cLocationId2)
{
    char cArray1[STATEDATA_NPCS + 1];
    char cArray1a[STATEDATA_NPCS + 1];
    char cArray2[STATEDATA_NPCS + 1];
    int iCount;
    int iKnownCount;
    int iUnknownCount;
    int iCountDown;
    short sOffset1;
    int iRet;

    statedata_visibleNPCs (cLocationId1, cArray1);
    statedata_visibleNPCs (cLocationId2, cArray1a);

    iCount = 0;
    iKnownCount = 0;
    iUnknownCount = 0;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        cArray2[sOffset1] = 0;

        if ((cArray1[sOffset1] == 0) && (cArray1a[sOffset1] == 0))
            continue;

        if (gpstructNPC_Base[sOffset1].cNameToFaceFlag == 1)
        {
            cArray2[sOffset1] = 1; // known
            iKnownCount++;
        }
        else
        {
            cArray2[sOffset1] = 2; // unknown
            iUnknownCount++;
        }

        iCount++;
    }

    if (iCount == 0)
        return 6;

    //
    // Take care of the unknowns.
    //
    if (iUnknownCount != 0)
    {
        iCountDown = iUnknownCount;

        iRet = mdialog_addToDialogWithSrchRep (" ");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" meets ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] == 2)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                // change this NPC to being known.
                gpstructNPC_Base[sOffset1].cNameToFaceFlag = 1;

                if (iUnknownCount == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        iRet = mdialog_addToDialogWithSrchRep (" for the first time.");
        if (iRet != 0) return iRet;
    }

    if (iKnownCount != 0)
    {
        iCountDown = iKnownCount;

        iRet = mdialog_addToDialogWithSrchRep (" ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] == 1)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (iKnownCount == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iKnownCount == 1)
            iRet = mdialog_addToDialogWithSrchRep (" is here as well.");
        else
            iRet = mdialog_addToDialogWithSrchRep (" are here as well.");
    }

    if (iUnknownCount != 0)
        return 10;

    return 0;
}


//
// Function to add a NPC into the sorted priority list
//
void statedata_addNPCPriority (short sOffset, int iValue, char cResult)
{
    int sListOffset;
    int sRevOffset;

    // don't do anything if we have already loaded the list up.
    if (gsNPC_PriorityUsed >= STATEDATA_NPCS)
        return;

    if (gsNPC_PriorityUsed == 0)
    {
        sListOffset = 0;
    }
    else
    {
        // now find if that entry is going to be before anything else in the list..
        for (sListOffset = 0; sListOffset < gsNPC_PriorityUsed; sListOffset++)
        {
            if (gpstructNPC_Priority[sListOffset].iSortValue < iValue)
            {
                break;
            }
        }

        // this is for inserting INTO the list..
        if (sListOffset < gsNPC_PriorityUsed)
        {
            // to have reached here, means that this new entry is being inserted either in the middle or at the start of the list.. so everything at
            //  the current offset needs to move down one..

            sRevOffset = gsNPC_PriorityUsed;

            // this while loop works from the bottom of the list, up to the matching offset.
            while (1)
            {
                if ((sRevOffset < sListOffset) || (sRevOffset < 0))
                    break;

                // move down everything to the new offset..
                gpstructNPC_Priority[sRevOffset + 1].iSortValue = gpstructNPC_Priority[sRevOffset].iSortValue;
                gpstructNPC_Priority[sRevOffset + 1].sOffset = gpstructNPC_Priority[sRevOffset].sOffset;
                gpstructNPC_Priority[sRevOffset + 1].cResult = gpstructNPC_Priority[sRevOffset].cResult;

                // decreemnt the counter to move along..
                sRevOffset--;
            }

        }
    }

    gpstructNPC_Priority[sListOffset].iSortValue = iValue;
    gpstructNPC_Priority[sListOffset].sOffset = sOffset;
    gpstructNPC_Priority[sListOffset].cResult = cResult;
    gsNPC_PriorityUsed++;
}


//
// Function to prioritize the NPCs at a given location.
//
void statedata_prioritizeNPCs (char cLocationId, char cAreaId)
{
    int iValue;
    short sOffset1;
    char cImmediateFlag;
    char cResult;
    short sRand;

    gsNPC_PriorityUsed = 0;

    //
    // For loop to scan through the NPCs.
    //
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        cImmediateFlag = 0;

        // ignore any NPCs who are not in the current area.
        if (gpstructNPC_Base[sOffset1].cAreaId != cAreaId)
            continue;

        // ignore any NPC who has an interaction lock running.
        if (gpstructNPC_Base[sOffset1].cInteractionLockFlag != 0)
            continue;

        // any NPCs who are sound asleep
        if (gpstructNPC_Base[sOffset1].cActionId == STATEACTION_SLP_D)
            continue;

        // any NPCs who are hidden
        if (gpstructNPC_Base[sOffset1].cActionId == STATEACTION_WRK_H)
            continue;

        // any NPCs who ware too tired
        if (gpstructNPC_Base[sOffset1].iEnergyValue < STATEDATA_ENERGYAVAIL)
            continue;

        // to have reached here, means that the NPC is either immediately available or nearby.

        if (gpstructNPC_Base[sOffset1].cLocationId == cLocationId)
        {
            cImmediateFlag = 1;
            iValue = gpstructNPC_Base[sOffset1].iEnergyValue + 500;
        }
        else
            iValue = gpstructNPC_Base[sOffset1].iEnergyValue;

        // if this NPC is not in the immediate area.. start doing checks to see if we are going to include them or not.
        if (cImmediateFlag == 0)
        {
            // Only certain actions knock out a NPC from participating.

            switch (gpstructNPC_Base[sOffset1].cActionId)
            {
            case STATEACTION_RES_D: // resting drunk, 1-of-4, upgrading to 2-of-4 with extra energy
                sRand = (short)((short)rand() % 4);

                // reduce the chances if the NPC does not have much energy
                if ((iValue - 100) < STATEDATA_ENERGYAVAIL)
                {
                    if (sRand == 1)
                        continue;
                }

                if (sRand > 1)
                    continue;

                break;

            case STATEACTION_SLP_A: // sleeping, 1-of-6, upgrading to 2-of-6 with extra energy
                sRand = (short)((short)rand() % 6);

                // reduce the chances if the NPC does not have much energy
                if ((iValue - 100) < STATEDATA_ENERGYAVAIL)
                {
                    if (sRand == 1)
                        continue;
                }

                if (sRand > 1)
                    continue;

            case STATEACTION_RES_N: // resting normal, 1-of-3, upgrading to 2-of-3 with extra energy
                sRand = (short)((short)rand() % 3);

                // reduce the chances if the NPC does not have much energy
                if ((iValue - 100) < STATEDATA_ENERGYAVAIL)
                {
                    if (sRand == 1)
                        continue;
                }

                if (sRand > 1)
                    continue;
            }

            // the default is that the NPC is going to be included..
        }

        // put in the adjustments according to the action id.
        switch (gpstructNPC_Base[sOffset1].cActionId)
        {
        case STATEACTION_HNG_N:
            iValue += 200;
            break;

        case STATEACTION_DRK_N:
            iValue += 150;
            break;

        case STATEACTION_EAT_N:
            iValue += 100;
            break;

        case STATEACTION_WRK_A:
            iValue += 80;
            break;

        case STATEACTION_RES_N:
            iValue += 70;
            break;

        case STATEACTION_RES_D:
            iValue -= 20;
            break;

        case STATEACTION_SLP_A:
            iValue -= 60;
            break;
        }

        iValue += (gpstructNPC_Base[sOffset1].iTrustValue / 2) + gpstructNPC_Base[sOffset1].iObedienceValue;

        // randomize things a little bit.
        sRand = (short)((short)rand() % 10);
        iValue += (int)sRand;

        // workout what the result value should be.
        if (gpstructNPC_Base[sOffset1].iKnownValue < STATEDATA_KNOWNMAX)
            cResult = 0;
        else if (gpstructNPC_Base[sOffset1].iTrustValue < STATEDATA_TRUSTMAX)
            cResult = 1;
        else if (gpstructNPC_Base[sOffset1].iObedienceValue < STATEDATA_OBEDIENCEMAX)
            cResult = 2;
        else
            cResult = 3;

        // now add this NPC..
        statedata_addNPCPriority (sOffset1, iValue, cResult);
    }
}


//
// Manually setup the priority list.
//
void statedata_manualNPCPriority (short sNPCVal1)
{
    short sOffset1;
    char cResult;

    gsNPC_PriorityUsed = 0;

    // some bounds checking..
    if ((sNPCVal1 < 1) || (sNPCVal1 > STATEDATA_NPCS))
        return;

    sOffset1 = sNPCVal1 - 1;

    if (gpstructNPC_Base[sOffset1].iKnownValue < STATEDATA_KNOWNMAX)
        cResult = 0;
    else if (gpstructNPC_Base[sOffset1].iTrustValue < STATEDATA_TRUSTMAX)
        cResult = 1;
    else if (gpstructNPC_Base[sOffset1].iObedienceValue < STATEDATA_OBEDIENCEMAX)
        cResult = 2;
    else
        cResult = 3;

    // add this NPC in the list.
    statedata_addNPCPriority (sOffset1, 0, cResult);
}


//
// Function to increment values for participating NPCs.
//
// The assumption is that statedata_prioritizeNPCs() had been used to setup the data first.
//
void statedata_incrementPrioritizedNPCs (short sCutoff, int iIncrement)
{
    int iValue;
    short sOffset1;
    short sOffset2;

    // this is how the values are increased for the stored parameters

    iValue = (int)iIncrement / (int)(sCutoff + 1);

    for (sOffset1 = 0; sOffset1 < sCutoff; sOffset1++)
    {
        sOffset2 = gpstructNPC_Priority[sOffset1].sOffset;

        // suck out all of the energy from this NPC.
        gpstructNPC_Base[sOffset2].iEnergyValue = 0;

        // then figure out which parameters are going to move.
        switch (gpstructNPC_Priority[sOffset1].cResult)
        {
        case 0:
            gpstructNPC_Base[sOffset2].iKnownValue += iValue;
            if (gpstructNPC_Base[sOffset2].iKnownValue >= STATEDATA_KNOWNMAX)
            {
                // these result changes work with statedata_showNPCChanges() below..
                gpstructNPC_Priority[sOffset1].cResult += 5;
                gpstructNPC_Base[sOffset2].iKnownValue = STATEDATA_KNOWNMAX;
            }
            break;

        case 1:
            gpstructNPC_Base[sOffset2].iTrustValue += iValue;
            if (gpstructNPC_Base[sOffset2].iTrustValue >= STATEDATA_TRUSTMAX)
            {
                gpstructNPC_Priority[sOffset1].cResult += 5;
                gpstructNPC_Base[sOffset2].iTrustValue = STATEDATA_TRUSTMAX;
            }
            break;

        case 2:
            gpstructNPC_Base[sOffset2].iObedienceValue += iValue;
            if (gpstructNPC_Base[sOffset2].iObedienceValue >= STATEDATA_OBEDIENCEMAX)
            {
                gpstructNPC_Priority[sOffset1].cResult += 5;
                gpstructNPC_Base[sOffset2].iObedienceValue = STATEDATA_OBEDIENCEMAX;
            }
            break;
        }
    }
}


//
// Function to find if there is a sleeping NPC at the location.
//  This function prioritizes unknown NPCs above known NPCs.
//
// returns -1 if there is no lock.
// returns the offset of the NPC if there is a NPC to lock onto.
//
short statedata_isThereASleepingNPC (char cLocationId)
{
    short sOffset1;
    short sOffset2 = -1;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // check the location id
        if (gpstructNPC_Base[sOffset1].cLocationId != cLocationId)
            continue;

        // we are only interested in the NPCs who are sound asleep
        if (gpstructNPC_Base[sOffset1].cActionId != STATEACTION_SLP_D)
            continue;

        // if this NPC is known, remember them.
        if (gpstructNPC_Base[sOffset1].cNameToFaceFlag == 1)
            sOffset2 = sOffset1;
        else
        {
            // if the NPC is unknown, return their offset immediately.
            return sOffset1;
        }
    }

    if (sOffset2 != -1)
        return sOffset2;

    return -1;
}


//
// Function to determine if the PC is alone at the location.
// Sound asleep and hidden NPCs do not count.
//
// returns 0 if multiple NPCs are present.
// returns 6 if there is only one person present.
// returns 10 if the PC is alone.
//
int statedata_isPCAlone (char cLocationId, short *psOffset)
{
    short sOffset1;
    short sOffset2;
    char cLock = 0;

    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // check the location id
        if (gpstructNPC_Base[sOffset1].cLocationId != cLocationId)
            continue;

        // any NPCs who are sound asleep
        if (gpstructNPC_Base[sOffset1].cActionId == STATEACTION_SLP_D)
            continue;

        // any NPCs who are hidden
        if (gpstructNPC_Base[sOffset1].cActionId == STATEACTION_WRK_H)
            continue;

        // we have a present NPC
        cLock++;
        sOffset2 = sOffset1;
    }

    // cannot find any NPCs
    if (cLock == 0)
        return 10;

    // if we have a single lock..
    if (cLock == 1)
    {
        psOffset[0] = sOffset2;
        return 6;
    }

    // multiple NPCs are present
    return 0;
}


//
// Function to call out the NPCs who have joined in.
//
// The assumption is that statedata_prioritizeNPCs() was used
//  first to populate the gpstructNPC_Priority table.
//
int statedata_nameShowupNPCs (char cLocationId1)
{
    char cArray1[STATEDATA_NPCS + 1];
    char cLocationId2 = -1;
    int iArrayCount1 = 0;
    int iArrayCount2 = 0;
    int iCountDown;
    short sOffset1;
    short sOffset2;
    int iRet;

    // construct a list of all of the visible NPCs
    statedata_visibleNPCs (cLocationId1, cArray1);

    // I could not be bothered getting the caller to feed this information
    //  across, so I coded it here..
    if (cLocationId1 == 27)
        cLocationId2 = 28;
    else if (cLocationId1 == 28)
        cLocationId2 = 27;
    else if (cLocationId1 == 38)
        cLocationId2 = 39;
    else if (cLocationId1 == 39)
        cLocationId2 = 38;
    else if (cLocationId1 == 46)
        cLocationId2 = 47;
    else if (cLocationId1 == 47)
        cLocationId2 = 46;

    // load and merge the array for the second location.
    if (cLocationId2 != -1)
    {
        char cArray2[STATEDATA_NPCS + 1];

        // construct a list of all of the visible NPCs
        statedata_visibleNPCs (cLocationId2, cArray2);

        // merge the array.
        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] != 0)
                cArray1[sOffset1] = cArray2[sOffset1];
        }
    }

    // now it is time to invert the array with the contents of the priority table
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        if (cArray1[sOffset1] != 0)
        {
            cArray1[sOffset1] = 0;
            continue;
        }

        for (sOffset2 = 0; sOffset2 < gsNPC_PriorityUsed; sOffset2++)
        {
            if (gpstructNPC_Priority[sOffset2].sOffset == sOffset1)
            {
                if (gpstructNPC_Base[sOffset1].cNameToFaceFlag == 0)
                {
                    cArray1[sOffset1] = 2;
                    gpstructNPC_Base[sOffset1].cNameToFaceFlag = 1;
                    // we know this NPC now..

                    iArrayCount2++;
                }
                else
                {
                    cArray1[sOffset1] = 1;
                    iArrayCount1++;
                }
            }
        }
    }

    // nothing to see here.. move along..
    if ((iArrayCount2 == 0) && (iArrayCount1 == 0))
        return 0;

    if (iArrayCount2 != 0)
    {
        iCountDown = iArrayCount2;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" is introduced to ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray1[sOffset1] == 2)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount2 == 1)
            iRet = mdialog_addToDialogWithSrchRep (" as he decided to see ");
        else
            iRet = mdialog_addToDialogWithSrchRep (" as they decided to visit ");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        if (iArrayCount1 != 0)
            iRet = mdialog_addToDialogWithSrchRep (". ");
        else
            iRet = mdialog_addToDialogWithSrchRep (".\n\n");
        if (iRet != 0) return iRet;
    }

    if (iArrayCount1 != 0)
    {
        iCountDown = iArrayCount1;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray1[sOffset1] == 1)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount2 != 0)
        {
            if (iArrayCount1 == 1)
                iRet = mdialog_addToDialogWithSrchRep (" also dropped by.\n\n");
            else
                iRet = mdialog_addToDialogWithSrchRep (" also tagged along.\n\n");
        }
        else
        {
            if (iArrayCount1 == 1)
            {
                iRet = mdialog_addToDialogWithSrchRep (" also came to see ");
                if (iRet != 0) return iRet;

                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
                if (iRet != 0) return iRet;

                iRet = mdialog_addToDialogWithSrchRep (".\n\n");
            }
            else
                iRet = mdialog_addToDialogWithSrchRep (" also showed up.\n\n");
        }
        if (iRet != 0) return iRet;
    }

    return 0;
}


//
// Function to call out the NPCs who are watching a sex act.
//
// The assumption is that statedata_prioritizeNPCs() was used
//  first to populate the gpstructNPC_Priority table.
//
int statedata_namePresentNPCs (char cLocationId1, short sCutOff)
{
    char cArray1[STATEDATA_NPCS + 1];
    char cArray2[STATEDATA_NPCS + 1];
    char cArray3[STATEDATA_NPCS + 1];
    char cLocationId2 = -1;
    int iArrayCount1 = 0;
    int iArrayCount2 = 0;
    int iArrayCount3 = 0;
    int iCountDown;
    short sOffset1;
    short sOffset2;
    int iRet;

    // construct a list of all of the visible NPCs
    statedata_visibleNPCs (cLocationId1, cArray1);

    // I could not be bothered getting the caller to feed this information
    //  across, so I coded it here..
    if (cLocationId1 == 27)
        cLocationId2 = 28;
    else if (cLocationId1 == 28)
        cLocationId2 = 27;
    else if (cLocationId1 == 38)
        cLocationId2 = 39;
    else if (cLocationId1 == 39)
        cLocationId2 = 38;
    else if (cLocationId1 == 46)
        cLocationId2 = 47;
    else if (cLocationId1 == 47)
        cLocationId2 = 46;

    // load and merge the array for the second location.
    if (cLocationId2 != -1)
    {
        // construct a list of all of the visible NPCs
        statedata_visibleNPCs (cLocationId2, cArray2);

        // merge the array.
        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] != 0)
                cArray1[sOffset1] = cArray2[sOffset1];
        }
    }

    // .. and the sleeping NPCs, who are nearby.
    statedata_sleepingNPCs (cLocationId1, cArray2);

    // first, include any NPCs that are below the line in the priority table,
    //  while also wiping out any NPCs that appear above the line in the priority table.
    //  and also counting what is in the two arrays (after correction).
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        cArray3[sOffset1] = 0;

        if (cArray1[sOffset1] != 0)
        {
            for (sOffset2 = 0; sOffset2 < sCutOff; sOffset2++)
            {
                if (gpstructNPC_Priority[sOffset2].sOffset == sOffset1)
                {
                    cArray1[sOffset1] = 0;
                    break;
                }
            }
        }
        else if (gsNPC_PriorityUsed > sCutOff)
        {
            for (sOffset2 = sCutOff; sOffset2 < gsNPC_PriorityUsed; sOffset2++)
            {
                if (gpstructNPC_Priority[sOffset2].sOffset == sOffset1)
                {
                    cArray1[sOffset1] = gpstructNPC_Base[sOffset1].cActionId;
                    break;
                }
            }
        }

        if (cArray1[sOffset1] != 0)
            iArrayCount1++;

        if (cArray2[sOffset1] != 0)
        {
            // array2 are the sleeping NPCs that the PC knows.
            if (gpstructNPC_Base[sOffset1].cNameToFaceFlag == 1)
                iArrayCount2++;
            else
            {
                // array3 are the sleeping NPCs that the PC does not know yet.
                iArrayCount3++;
                cArray3[sOffset1] = cArray2[sOffset1];
                cArray2[sOffset1] = 0;
                gpstructNPC_Base[sOffset1].cNameToFaceFlag = 1;
                // of course, after this the PC is going to know who they are.
            }
        }
    }
    // why go through the effort of populating the table from one place and
    //  correcting it from another.. well it has to do with the fact that
    //  I want the NPCs who were out of the selection for the priority list
    //  to show up in the list present. gpstructNPC_Priority does not include
    //  NPCs who are knocked out because the energy level isn't enough or
    //  cInteractionLockFlag is set.
    //
    // gpstructNPC_Priority does drag in nearby candidates for the encounter,
    //  who may also be observing, which is why this combines the two lists..

    // the freshly introduced (sleeping) NPCs are on their own line.
    if (iArrayCount3 != 0)
    {
        iCountDown = iArrayCount3;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" is introduced to ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray3[sOffset1] != 0)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (iArrayCount3 == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount3 == 1)
            iRet = mdialog_addToDialogWithSrchRep (", who is sleeping soundly nearby.\n\n");
        else
            iRet = mdialog_addToDialogWithSrchRep (", who are sleeping soundly nearby.\n\n");

        if (iRet != 0) return iRet;
    }

    if ((iArrayCount1 == 0) && (iArrayCount2 == 0))
        return 0;

    // this is the list of the sleeping NPCs (that the PC already knows).
    if (iArrayCount2 != 0)
    {
        iCountDown = iArrayCount2;

        iRet = mdialog_addToDialogWithSrchRep ("While ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray2[sOffset1] != 0)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (iArrayCount2 == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount2 == 1)
            iRet = mdialog_addToDialogWithSrchRep (" is sleeping soundly nearby, ");
        else
            iRet = mdialog_addToDialogWithSrchRep (" are sleeping soundly nearby, ");

        if (iRet != 0) return iRet;

        if (iArrayCount1 != 0)
        {
            iRet = mdialog_addToDialogWithSrchRep ("and ");
            if (iRet != 0) return iRet;
        }
    }

    // this is the list of the watching NPCs.
    if (iArrayCount1 != 0)
    {
        iCountDown = iArrayCount1;

        if (iArrayCount2 == 0)
        {
            iRet = mdialog_addToDialogWithSrchRep ("While ");
            if (iRet != 0) return iRet;
        }

        for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
        {
            if (cArray1[sOffset1] != 0)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[sOffset1 + 1].pszReplace);
                if (iRet != 0) return iRet;

                if (iArrayCount2 == 1)
                    break;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount1 == 1)
            iRet = mdialog_addToDialogWithSrchRep (" observes, ");
        else
            iRet = mdialog_addToDialogWithSrchRep (" watch, ");
    }

    return 0;
}


//
// Function to call out the NPCs who have had state changes.
//
// The assumption is that statedata_prioritizeNPCs() was used
//  first to populate the gpstructNPC_Priority table.
//
int statedata_showNPCChanges (short sCutOff)
{
    int iArrayCount1 = 0;
    int iArrayCount2 = 0;
    int iArrayCount3 = 0;
    int iCountDown;
    short sOffset1;
    int iRet;

    for (sOffset1 = 0; sOffset1 < sCutOff; sOffset1++)
    {
        if (gpstructNPC_Priority[sOffset1].cResult == 5)
            iArrayCount1++;

        if (gpstructNPC_Priority[sOffset1].cResult == 6)
            iArrayCount2++;

        if (gpstructNPC_Priority[sOffset1].cResult == 7)
            iArrayCount3++;
    }

    if (iArrayCount1 != 0)
    {
        iCountDown = iArrayCount1;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" knows ");
        if (iRet != 0) return iRet;

        for (sOffset1 = 0; sOffset1 < sCutOff; sOffset1++)
        {
            if (gpstructNPC_Priority[sOffset1].cResult == 5)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[gpstructNPC_Priority[sOffset1].sOffset + 1].pszReplace);
                if (iRet != 0) return iRet;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        iRet = mdialog_addToDialogWithSrchRep (" rather well now.\n\n");
        if (iRet != 0) return iRet;
    }

    if (iArrayCount2 != 0)
    {
        iCountDown = iArrayCount2;

        for (sOffset1 = 0; sOffset1 < sCutOff; sOffset1++)
        {
            if (gpstructNPC_Priority[sOffset1].cResult == 6)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[gpstructNPC_Priority[sOffset1].sOffset + 1].pszReplace);
                if (iRet != 0) return iRet;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount2 == 1)
            iRet = mdialog_addToDialogWithSrchRep (" trusts ");
        else
            iRet = mdialog_addToDialogWithSrchRep (" trust ");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (" now.\n\n");
        if (iRet != 0) return iRet;
    }

    if (iArrayCount3 != 0)
    {
        iCountDown = iArrayCount3;

        for (sOffset1 = 0; sOffset1 < sCutOff; sOffset1++)
        {
            if (gpstructNPC_Priority[sOffset1].cResult == 7)
            {
                iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[gpstructNPC_Priority[sOffset1].sOffset + 1].pszReplace);
                if (iRet != 0) return iRet;

                iCountDown--;

                if (iCountDown == 1)
                    iRet = mdialog_addToDialogWithSrchRep (" and ");
                else if (iCountDown != 0)
                    iRet = mdialog_addToDialogWithSrchRep (", ");

                if (iRet != 0) return iRet;
            }

            if (iCountDown == 0)
                break;
        }

        if (iArrayCount3 == 1)
            iRet = mdialog_addToDialogWithSrchRep (" has become ");
        else
            iRet = mdialog_addToDialogWithSrchRep (" have become ");
        if (iRet != 0) return iRet;

        iRet = mdialog_addToDialogWithSrchRep (gstructSrchRepList[0].pszReplace);
        if (iRet != 0) return iRet;

        if (iArrayCount3 == 1)
            iRet = mdialog_addToDialogWithSrchRep ("\'s loyal \'sperm bag\'.\n\n");
        else
            iRet = mdialog_addToDialogWithSrchRep ("\'s loyal \'sperm bags\'.\n\n");
        if (iRet != 0) return iRet;
    }

    return 0;
}


//
// Function to check to see if only a specific NPC is at a specific location.
//
// This function does not work by sucking in priority list data.
//  (as a result it is only used for specific events).
//
// Returns 0 if false.
// Returns 1 if true.
//
int statedata_specificNPCOnlyNPCAtLocation (short sNPCVal1, char cLocation1)
{
    short sOffset1;

    // some bounds checking..
    if ((sNPCVal1 < 1) || (sNPCVal1 > STATEDATA_NPCS))
        return 0;

    // first, check to see if the specific NPC is at the specific location.
    if (gpstructNPC_Base[sNPCVal1 - 1].cLocationId != cLocation1)
        return 0;

    // next, scan through the entire list of NPCs, checking to see if any of them are ALSO at the specific location.
    for (sOffset1 = 0; sOffset1 < STATEDATA_NPCS; sOffset1++)
    {
        // ignore this entry if it is the same NPC that we want at this location.
        if (sOffset1 == (short)(sNPCVal1 - 1))
            continue;

        // check to see if any of the other NPCs happen to be at this location.
        if (gpstructNPC_Base[sOffset1].cLocationId == cLocation1)
            return 0;
    }

    // to have made it here, means that the specific NPC is at the location, and the only NPC at the location.

    return 1;
}


//
// Function to check to see if the end game state has been achieved.
//
// returns 0 for no.
// returns 1 for good end.
// returns 2 for bad end.
//
int statedata_hasGameEndTriggered ()
{
    short sOffset2;
    int iObedientCount = 0;
    int iTrustCount = 0;

    // find the NPC with the least amount of trust or known stats.
    for (sOffset2 = 0; sOffset2 < STATEDATA_NPCS; sOffset2++)
    {
        if (gpstructNPC_Base[sOffset2].iTrustValue >= STATEDATA_TRUSTMAX)
        {
            iTrustCount++;

            if (gpstructNPC_Base[sOffset2].iObedienceValue >= STATEDATA_OBEDIENCEMAX)
            {
                iObedientCount++;
            }
        }
    }

    // if the obedience counter is not exceeding the threshold, then this is not the ending yet.
    if (iObedientCount <= 1)
        return 0;

    // if easy, the minimum number of trusts needs to be 33.
    if (gpstructPC_Global.cDifficultyLevel == 1)
    {
        if (iTrustCount >= 33)
            return 1;
    }
    // if medium, the minimum number of trusts needs to be 54.
    else if (gpstructPC_Global.cDifficultyLevel == 2)
    {
        if (iTrustCount >= 54)
            return 1;
    }
    // if hard, the minimum number of trusts needs to be 64.
    else
    {
        if (iTrustCount >= 64)
            return 1;
    }

    // otherwise, bad end.
    return 2;
}


