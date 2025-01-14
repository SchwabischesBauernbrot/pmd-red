#include "global.h"
#include "text.h"
#include "input.h"
#include "memory.h"
#include "item.h"
#include "pokemon.h"
#include "code_8094F88.h"
#include "constants/wonder_mail.h"

struct unkStruct_203B320
{
    // size: 0xC4
    u8 unk0[0x20];
    u32 wonderMailType;
    u32 unk24;
    u8 fill28[0x3C - 0x28];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u8 fill48[0x58 - 0x48];
    u32 unk58;
    struct UnkTextStruct2 *unk5C;
    struct UnkTextStruct2 unk60[4];
    u8 unkC0[4];
};
extern struct unkStruct_203B320 *gUnknown_203B320;
extern struct UnkTextStruct2 gUnknown_80E083C;
extern struct UnkTextStruct2 gUnknown_80E0854;
extern u8 *gUnknown_80E086C[];
extern struct unkStruct_203B480 *gUnknown_203B480;

struct unkStruct_802C39C
{
    /* 0x0 */ u32 unk0[2];
    /* 0x8 */ struct DungeonLocation *unk8;
    /* 0xC */ u8 *unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 fill15[0x1B];
    /* 0x34 */ u8 fill34[2];
    /* 0x36 */ u8 fill36[0x3C - 0x36];
    /* 0x3C */ u8 unk3C[0x10];
    /* 0x4C */ u32 unk4C;
    /* 0x50 */ u32 unk50[3];
};

extern bool8 HasNoWonderMailType(u32);
extern s32 sub_8030A74(void);
extern void sub_80308A0(void);
extern void sub_803092C(void);
extern void sub_8012D08(struct UnkTextStruct2 *, s32);
extern void sub_8013818(void *, u32, u32, u32);

extern u8 sub_80138B8(u32 *, u32);
extern void sub_8013660(u32 *);
extern s32 GetKeyPress(u32 *);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013984(u32 *);
extern void AddMenuCursorSprite(u32 *);
extern s32 sub_8013800(void *, u32);
extern void xxx_call_draw_string(u32, u32, const u8 *, u32, u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void CreateRescueTitle(void *);

u32 sub_80306A8(u32 wonderMailType, u32 r1, struct UnkTextStruct2_sub *r2, u32 r3)
{
    if(HasNoWonderMailType(wonderMailType))
        return 0;
    gUnknown_203B320 = MemoryAlloc(sizeof(struct unkStruct_203B320), 0x8);
    gUnknown_203B320->wonderMailType = wonderMailType;
    gUnknown_203B320->unk58 = r1;

    gUnknown_203B320->unk5C = &gUnknown_203B320->unk60[gUnknown_203B320->unk58];
    sub_8006518(gUnknown_203B320->unk60);

    gUnknown_203B320->unk60[gUnknown_203B320->unk58] = gUnknown_80E0854;
    gUnknown_203B320->unk5C->unk14 = gUnknown_203B320->unkC0;

    if(r2 != 0)
    {
        gUnknown_203B320->unk60[gUnknown_203B320->unk58].unk08 = *r2;
    }


    sub_8012D08(gUnknown_203B320->unk5C, r3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B320->unk60, 1, 1);
    sub_8013818(&gUnknown_203B320->unk24, sub_8030A74(), r3, r1);
    sub_80308A0();
    sub_803092C();
    return 1;
}

u32 sub_8030768(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B320->unk24);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B320->unk24))
    {
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if(sub_80138B8(&gUnknown_203B320->unk24, 1) != 0)
            {
                sub_80308A0();
                sub_803092C();
                return 1;
            }
            else
                return 0;
    }
}

u8 sub_80307EC(void)
{
    return gUnknown_203B320->unk0[(gUnknown_203B320->unk42 * gUnknown_203B320->unk40) + gUnknown_203B320->unk3C];
}

void sub_8030810(u8 r0)
{
    gUnknown_203B320->unk46 = sub_8030A74();
    sub_8013984(&gUnknown_203B320->unk24);

    sub_80308A0();
    sub_803092C();
    if(r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B320->unk24);
}

void sub_803084C()
{
    if(gUnknown_203B320 != NULL)
    {
        gUnknown_203B320->unk60[gUnknown_203B320->unk58] = gUnknown_80E083C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B320->unk60, 1, 1);
        MemoryFree(gUnknown_203B320);
        gUnknown_203B320 = NULL;
    }
}

u8 *sub_8030894()
{
    return gUnknown_203B320->unk0;
}

NAKED
void sub_80308A0(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _08030928\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x44\n"
	"\tldrh r1, [r1]\n"
	"\tadds r0, 0xC0\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x42\n"
	"\tldrh r1, [r1]\n"
	"\tadds r0, 0xC1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xC2\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xC3\n"
	"\tstrb r2, [r0]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x60\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x3E\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x58]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x6E\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x58]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x70\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x60\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08030928: .4byte gUnknown_203B320");
}

void sub_803092C(void)
{
  struct unkStruct_203B480 *mail;
  s32 r4;
  s32 r5;
  s32 r6;
  struct unkStruct_802C39C local;
  
  sub_8008C54(gUnknown_203B320->unk58);
  sub_80073B8(gUnknown_203B320->unk58);
  r4 = gUnknown_203B320->unk42 * 8;
  r5 = r4;
  r5 += 10;
  xxx_call_draw_string(r5,0,gUnknown_80E086C[gUnknown_203B320->wonderMailType],gUnknown_203B320->unk58,0);
  r4 += 4; 
  r5 = r4 + gUnknown_203B320->unkC0[2] * 8;
  sub_8012BC4(r5,0,gUnknown_203B320->unk42 + 1,1,7,gUnknown_203B320->unk58);

  r6 = 0;
  if (r6 < gUnknown_203B320->unk3E) {
    do {
      mail = sub_8095228(gUnknown_203B320->unk0[(gUnknown_203B320->unk42 * gUnknown_203B320->unk40) + r6]);
      local.unk0[0] = gUnknown_203B320->unk58;
      local.unk4C = sub_8013800(&gUnknown_203B320->unk24,r6);
      local.unk3C[8] = 7;
      local.unk3C[10] = 0;
      local.unk3C[12] = 0;

      local.unk8 = &mail->dungeon;
      local.unkC = mail->playerName;

      local.unk10 = (mail->clientSpecies);
      local.unk12 = (mail->clientSpecies);
      local.unk14 = 0;
      local.fill15[0x19] = 5;

      switch(mail->mailType)
      {
        case WONDER_MAIL_TYPE_AOK:
            local.unk3C[11] = 3;
            break;
        case WONDER_MAIL_TYPE_THANK_YOU:
            local.unk3C[11] = 4;
            break;
        case 1:
        case 2:
            local.unk3C[11]= 1;
            break;
        default:
            local.unk3C[11]= 0;
            break;
      }
      CreateRescueTitle(&local);
      r6++;
    } while (r6 < gUnknown_203B320->unk3E);
  }
  sub_80073E0(gUnknown_203B320->unk58);
}

s32 sub_8030A74(void)
{
  s32 index;
  s32 count = 0;
  switch(gUnknown_203B320->wonderMailType) {
    case WONDER_MAIL_TYPE_NONE:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType != WONDER_MAIL_TYPE_NONE) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_COMPLETED:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_COMPLETED) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case 1:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == 1) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case 2:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == 2) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_AOK:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_AOK) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case 3:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == 3) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
    case WONDER_MAIL_TYPE_THANK_YOU:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_THANK_YOU) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;

    case WONDER_MAIL_TYPE_OKD:
        for (index = 0; index < 0x20; index++)
        {
            struct unkStruct_203B480 *p = gUnknown_203B480 + index;
            if (p->mailType == WONDER_MAIL_TYPE_OKD) {
                gUnknown_203B320->unk0[count] = index;
                count++;
            }
        }
        break;
  }
  return count;
}

bool8 HasNoWonderMailType(u32 wonderMailType)
{
  s32 index;
  
  switch(wonderMailType) {
    case WONDER_MAIL_TYPE_NONE:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType != WONDER_MAIL_TYPE_NONE) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_COMPLETED:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_COMPLETED) {
                return FALSE;
            }
        }
        break;
    case 1:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == 1) {
                return FALSE;
            }
        }
        break;
    case 2:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == 2) {
                return FALSE;
            }
        }
        break;
    case WONDER_MAIL_TYPE_AOK:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_AOK) {
                return FALSE;
            }
        }
        break;
    case 3:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == 3) {
                return FALSE;
            }
        }
        break;

    case WONDER_MAIL_TYPE_THANK_YOU:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_THANK_YOU) {
                return FALSE;
            }
        }
        break;

    case WONDER_MAIL_TYPE_OKD:
        for (index = 0; index < 0x20; index++)
        {
            if (gUnknown_203B480[index].mailType == WONDER_MAIL_TYPE_OKD) {
                return FALSE;
            }
        }
        break;
  }
  return TRUE;
}
