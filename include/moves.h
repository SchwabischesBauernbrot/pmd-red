#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "constants/move.h"
#include "constants/move_id.h"

void LoadWazaParameters(void);
u8 sub_809287C(struct Move *move);
void InitPokemonMove(struct Move *move, u16 moveID);
void sub_8092AA8(struct Move *move, u16 moveID);
void InitZeroedPPPokemonMove(struct Move *move, u16 moveID);
s16 GetMoveTargetAndRange(struct Move *move, u32 isAI);
u8 GetMoveType(struct Move *move);
u8 GetMoveAIWeight(struct Move *move);
u32 GetMoveNumberOfChainedHits(struct Move *move);
s32 GetMoveBasePower(struct Move *move);
s32 GetMoveAccuracyOrAIChance(struct Move *move, u32 accuracyType);
u32 GetMoveBasePP(struct Move *move);
u32 GetMoveMaxUpgradeLevel(struct Move *move);
u8 GetMoveCritChance(struct Move *move);
bool8 MoveCannotHitFrozen(struct Move *move);
bool8 MovesIgnoresTaunted(struct Move *move);
u32 GetMoveRangeID(struct Move *move);
void sub_8092C84(u8 *buffer, u16 moveID);
u8 *GetMoveUseText(u16 moveID);
bool8 IsReflectedByMagicCoat(u16 moveID);
bool8 CanBeSnatched(u16 moveID);
bool8 FailsWhileMuzzled(u16 moveID);
bool8 IsSoundMove(struct Move *move);
bool8 DoesMoveCharge(u16 move);

#endif // GUARD_MOVES_H
