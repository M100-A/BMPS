//
// gamelogic.h
//

//
// define for the maximum number of sub-recursions..
//
#define MAXGAMESCENENESTS 20
// this is used in the scene functions to figure out if the program is stuck in a potentially infinite scene link loop, and to bail out.


// definition for the scene list array
struct  main_scenelist
{
    int     iSceneId;                               // scene id
    int     (*vFunc)(int iSubSceneId, char cSubFlag); // call function.
};

// definition for the scene list array
struct  gamelogic02_eventscenes
{
    char    cSpecialSceneId;            // scene id
    int     (*vFunc)(char cSubFlag);    // call function.
};


//
// These ALL of the scene id functions (gamelogicxx.c).
//
// These need to be defined so that they can be referenced by the lookup array, without dumping EVERY single function into the one sourcecode listing.
//

// 00.c, menu elements
int gamelogic00_scene0000 (int iSubSceneId, char cSubFlag);
int gamelogic00_scene0001 (int iSubSceneId, char cSubFlag);
int gamelogic00_scene0002 (int iSubSceneId, char cSubFlag);
int gamelogic00_scene0003 (int iSubSceneId, char cSubFlag);
int gamelogic00_scene0004 (int iSubSceneId, char cSubFlag);
int gamelogic00_scene0009 (int iSubSceneId, char cSubFlag);

// 01.c, main dialog (main scenes)
int gamelogic01_scene1001 (int iSubSceneId, char cSubFlag);
int gamelogic01_scene1002 (int iSubSceneId, char cSubFlag);
int gamelogic01_scene1003 (int iSubSceneId, char cSubFlag);
int gamelogic01_scene1004 (int iSubSceneId, char cSubFlag);
int gamelogic01_scene1005 (int iSubSceneId, char cSubFlag);

// 02.c, movement/navigation
int gamelogic02_scene1020 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1021 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1022 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1023 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1024 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1025 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1026 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1027 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1028 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1029 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1030 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1031 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1032 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1033 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1034 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1035 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1036 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1037 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1038 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1039 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1040 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1041 (int iSubSceneId, char cSubFlag);
int gamelogic02_scene1042 (int iSubSceneId, char cSubFlag);

// 03.c, status
int gamelogic03_scene1061 (int iSubSceneId, char cSubFlag);


