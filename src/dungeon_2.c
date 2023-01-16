#include "global.h"
#include "dungeon.h"
#include "code_800D090.h"
#include "pokemon.h"
#include "code_8092334.h"
#include "constants/dungeon.h"

extern const char gUnknown_8108F10[];
extern const char gUnknown_8108F18[];
extern const char gUnknown_8108F2C[];
extern u8 gDungeonFloorCount[];
extern u8 gUnknown_81077E8[];

void sub_80901D8(struct DungeonLocation *param_1,struct DungeonLocation *param_2)
{ 
  if ((u8)(param_2->id - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE) {
    param_1->id = DUNGEON_NORMAL_MAZE;
    param_1->floor = (param_2->id - DUNGEON_NORMAL_MAZE_2) * 3 + param_2->floor;
  }
  else {
    *param_1 = *param_2;
  }
}

void PrintYellowDungeonNametoBuffer(u8 *buffer, struct DungeonLocation *dungeonLocation)
{
    sprintfStatic(buffer, gUnknown_8108F10, gDungeonNames[dungeonLocation->id].name1); // {COLOR_2 YELLOW_4}%s{END_COLOR_TEXT_2} (normal floor print (no B)
}

void PrintDungeonLocationtoBuffer(u8 *buffer, struct DungeonLocation *dungeonLocation)
{
    if(gDungeons[dungeonLocation->id].stairDirection != 0){
        sprintfStatic(buffer, gUnknown_8108F18, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); //_F
    }
    else
    {
        sprintfStatic(buffer, gUnknown_8108F2C, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); // B _F
    }
}

void CopyDungeonName1toBuffer(u8 *buffer, struct DungeonLocation *dungeonLocation)
{
    strncpy(buffer, gDungeonNames[dungeonLocation->id].name1, 0x50);
}

s32 GetDungeonFloorCount(u8 dungeon)
{
    if ((u8)(dungeon - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE)
        return 4;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 1;
    else
        return gDungeonFloorCount[dungeon];
}

u8 sub_80902C8(u8 dungeon)
{
    if ((u8)(dungeon - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE)
        return 0;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 0;
    else
        return gUnknown_81077E8[dungeon];
}

void SaveDungeonLocation(struct unkStruct_8094924* r0, struct DungeonLocation* r1)
{
    SaveIntegerBits(r0, &r1->id, 0x7);
    SaveIntegerBits(r0, &r1->floor, 0x7);
}

void RestoreDungeonLocation(struct unkStruct_8094924* r0, struct DungeonLocation* r1)
{
    r1->id = 0;
    r1->floor = 0;
    RestoreIntegerBits(r0, &r1->id, 0x7);
    RestoreIntegerBits(r0, &r1->floor, 0x7);
}

u8 GetDungeonUnk1(u8 dungeon)
{
    return gDungeons[dungeon].unk1;
}