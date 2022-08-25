#include "common.h"
//AOF=326

//arg0 is a pointer to the string "mem err!\n"
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055BB0.s")

void func_80055BCC(s32 arg0) {
    __additional_scanline = arg0;
}

s32 func_80055BD8(void) {
    u32 y, z;
    y = __additional_scanline * 4 + 2;
    z = y + 1;
    y = y * z;
    return __additional_scanline = y / 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055C04.s")
// requires -O1 ??
// void func_80055C04(void) {
//     __osActiveQueue = 1;
//     D_800F6888 = -1;
//     D_800F6898 = -1;
//     D_800F688C = -1;
//     D_800F689C = -1;
//     D_800F6890 = -1;
//     D_800F68A0 = -1;
//     D_800F6894 = -1;
//     D_800F68A4 = -1;
// }

void func_80055C74(void) {
    __osActiveQueue = (OSThread*)0;
}

void func_80055C80(void) {
    __osActiveQueue = (OSThread*)1;
}

s32 func_80055C90(void) {
    return __osActiveQueue;
}

//https://decomp.me/scratch/5d7ug
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055C9C.s")

//https://decomp.me/scratch/c85I6
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055E5C.s")

void func_80055EEC(s32 arg0) {
    func_80055F10(0, arg0);
}

//https://decomp.me/scratch/Paab8
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055F10.s")

void func_80055FA4(void) {
    D_800F68C0 = - 1;
    D_800F68C4[0] = -1;
}

void func_80055FBC(s32 arg0) {
    D_800F68C0 = D_800F68C4[0];
    D_800F68C4[0] = arg0;
}

//https://decomp.me/scratch/R8dqR
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80055FD8.s")

//https://decomp.me/scratch/As37m
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056064.s")

//
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005609C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005625C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056CA0.s")

//https://decomp.me/scratch/cUHtJ
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056CDC.s")

void func_80056D14(unkStruct02* arg0, s32 arg1, unkStruct02* arg2, unkStruct02* arg3) {
    arg0->flags = arg1;
    arg0->unk_04 = arg2;
    arg0->unk_08 = arg3;
    if (arg3 != NULL) {
        arg3->unk_04 = (void*)arg0;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056D30.s")

void func_80056DF4(unkStruct02* arg0, unkStruct02* arg1) {
    unkStruct02* temp_v0;

    arg0->flags += (arg1->flags & ~1) + 0x80;
    temp_v0 = arg1->unk_08;
    arg0->unk_08 = temp_v0;
    if (temp_v0 != 0) {
        temp_v0->unk_04 = arg0;
    }
}

// Seems incorrectly named
// s32 leoDrive_reset(void);
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/leoDrive_reset.s")

void func_80056EB4(void) {
    func_80056CDC(D_801191A0, (D_801FFB78 - D_801191A0));
}

void* func_80056EE4(s32 arg0) {
    void* temp_v0 = func_80056D30(arg0);
    
    if (temp_v0 == NULL) {
        func_80055BB0(D_8010CA10);
    }
    return temp_v0;
}

s32 func_80056F24(void) {
    leoDrive_reset();
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80056F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80057010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80057334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800573BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005747C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80057A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80058044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80058748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80058BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80059254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800598C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80059F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005A7CC.s")

void func_8005AFA4(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    //why are there arguments if none of them are used????
    func_800573BC();
}

//text?
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005AFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005B874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005C04C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005C454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005C6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005C9B8.s")

void func_8005CA38(void) {
    D_800FDFA0 = 0;
}

//jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005CA44.s")
//jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8005F408.s")

void func_800610A8(void) {
    D_800FE000 = 1;
}

void func_800610B8(void) {
    D_800FE000 = 0;
    func_800573BC();
    func_8007E5E8();
}

void func_800610E4(f32 arg0, f32 arg1) {
    D_800FDFE0 = (s8) (u32) arg0;
    D_800FDFE4 = (s8) (u32) arg1;
}

void func_800611F8(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_800FE004 = arg0;
    D_800FE008 = arg1;
    D_800FE00C = arg2;
    D_800FE010 = arg3;
}

void func_8006122C(f32 arg0, f32 arg1) {
    D_800FDFF4 = arg0;
    D_800FDFF8 = arg1;
}

void func_80061240(void) {
    D_800FDFF4 = 0.0f;
    D_800FDFF8 = 0.0f;
}

void func_80061258(f32 arg0) {
    D_800FDFFC = arg0;
}

void func_80061264(f32 arg0) {
    D_800FDFFC = arg0;
}

void func_80061270(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_800FDFD0 = arg0;
    D_800FDFD4 = arg1;
    D_800FDFD8 = arg2;
    D_800FDFDC = arg3;
}

void func_800612A4(s8 arg0, s8 arg1, s8 arg2, s8 arg3) {
    D_800FDFD0 = arg0;
    D_800FDFD4 = arg1;
    D_800FDFD8 = arg2;
    D_800FDFDC = arg3;
}

void func_800612D8(f32 arg0) {
    D_800FDFF0 = arg0;
}

void func_800612E4(f32 arg0) {
    D_800FDFF0 = arg0;
}

void func_800612F0(s32 arg0) {
    D_800FDFE8 = arg0;
}

void func_800612FC(void) {
    D_800FDFEC = 0.0f;
}

void func_80061308(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF) {
    D_80176850[4] = arg4;
    D_80176850[5] = arg5;
    D_80176850[0] = arg0;
    D_80176850[1] = arg1;
    D_80176850[2] = arg2;
    D_80176850[3] = arg3;
    D_80176850[6] = arg6;
    D_80176850[7] = arg7;
    D_80176850[8] = arg8;
    D_80176850[9] = arg9;
    D_80176850[0xA] = argA;
    D_80176850[0xB] = argB;
    D_80176850[0xC] = argC;
    D_80176850[0xD] = argD;
    D_80176850[0xE] = argE;
    D_80176850[0xF] = argF;
}

void func_80061394(void) {
    D_800FDFC0[0] = 0;
    D_800FDFC0[1] = 0;
    D_800FDFC8[0] = 0;
    D_800FDFC8[1] = 0;
    func_800573BC();
}

void func_800613D0(arb* arg0) {
    arg0->unk4 = 0;
    arg0->unk3C = 0;
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    arg0->unkC = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800613EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80061514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800615A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800615D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80061640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800619F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80061D10.s")

void func_8006202C(void) {
    D_800FE160 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80062038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800620C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80062588.s")

void func_8006266C(argd8006266c* arg0) {
    d8006266c* temp_v0;
    
    temp_v0 = arg0->unk38;
    temp_v0->unk4 = 1;
    temp_v0->unkC = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80062684.s")

void func_800629C4(void) {
    D_800FE164 = 1;
}

void func_800629D4(void) {
    D_800FE164 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800629E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80062D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80062E18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80063160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800634D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800635DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800638AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80063B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800647B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80064BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80064D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80064F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006526C.s")
/*
aa1* func_8006526C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 arg9) {
    aa1* temp_v0;
    aa2* temp_v1;

    temp_v0 = func_800613EC(0, 24, &func_80065088);
    if (temp_v0 == NULL) {
        return temp_v0;
    }
    temp_v1 = temp_v0->unk38;
    temp_v1->unk0 = arg6;
    temp_v1->unk4 = arg7;
    temp_v1->unk8 = (s32) D_800FE18C;
    temp_v1->unkC = (s32) D_800FE190;
    temp_v1->unk10 = (s32) D_800FE194;
    temp_v1->unk14 = (s32) D_800FE198;
    temp_v0->unk10 = arg0;
    temp_v0->unk14 = arg1;
    temp_v0->unk18 = arg2;
    temp_v0->unk1C = arg3;
    temp_v0->unk20 = arg4;
    temp_v0->unk24 = arg5;
    temp_v0->unk0 = arg9;
    temp_v0->unk30 = (f32) arg8;
    temp_v0->unkC = 0.0f;
    return temp_v0;
}*/

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800654B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006578C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80065F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80066020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800661A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006623C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800662D4.s")

//https://decomp.me/scratch/GHZZV
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80066374.s")

//https://decomp.me/scratch/xl76w
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800664E8.s")

//https://decomp.me/scratch/Jy8t4
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800665F0.s")

void func_800667A8(void) {
    D_800FE19C = 0;
}

void func_800667B4(aaaaa* arg0) {
    arg0->unk1C = 1.0f;
}

void func_800667C4(s8 arg0[5], s32 arg1) {
    arg0[5] = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800667CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800674B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800675D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800678EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800679DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80067CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80067DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006854C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006863C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80068DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80069734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80069858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800698A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80069918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006A134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006A69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006A74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006A7B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006A824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006AA3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006AD34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006B96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006B9D0.s")

void func_8006BA14(void) {
    D_800FE4DC = 1;
}

void func_8006BA24(void) {
    D_800FE4DC = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006BA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006BD58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006BE4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006C0D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006C368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006C410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006C7F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006C8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CBA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CCB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006CEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006D844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006DAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006DB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006DCC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006DDCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006DE58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006E0A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006E16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006E3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006E888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006E9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006EBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006EC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006EF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006F100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006F230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006F43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006F8D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006F9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006FC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006FD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8006FE7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800703C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800704A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800705C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070D0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80070F5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007101C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007120C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80071420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800714C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80071968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80071A48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80071A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80072310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800723B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007294C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800729E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80072B1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80072D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80072D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80073090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800730E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007320C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800735A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800735F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80073C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80073FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007402C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800743BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800745F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800747E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80074908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80074C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800755DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800759CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80075F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800762C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007633C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80076548.s")

void func_80076884(s32 arg0) {
    func_80076548(arg0, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800768A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007691C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80076EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800771DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800772E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80077688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80077A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80077CAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80077F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800781A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800786D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80078F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80079150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007924C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007941C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800794F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80079820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80079930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80079F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80079FC4.s")

void func_8007A25C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    unk_8007A25C* temp_v0;

    temp_v0 = func_800613EC(0, 0, &func_80079FC4);
    if (temp_v0 != NULL) {
        temp_v0->unk10 = arg0;
        temp_v0->unk14 = arg1;
        temp_v0->unk18 = arg2;
        temp_v0->unk1C = arg3;
        temp_v0->unkC = 0.0f;
        temp_v0->unk30 = (f32) (1.0f / arg4);
    }
}

//jumptable
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007A2D8.s")

s32 func_8007ABDC(s32 arg0) {
    return arg0;
}

void func_8007ABE4(void) {
    D_800FEA30 = 0;
    D_800FEA34 = 0;
}

void func_8007ABF8(bf8* arg0) {
    if ((D_800FEA30 > 0) && (D_800FEA30 < 3)) {
        arg0->unk0 = 0;
        arg0->unk2 = 0;
        arg0->unk4 = 0;
        arg0->unk6 = 0;
        arg0->unk8 = 0;
    }
}

void func_8007AC2C(s32* arg0) {
    if ((D_800FEA30 > 0) && (D_800FEA30 < 3)) {
        D_80168E5C = 1;
        *arg0 += 10;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007AC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007ADDC.s")

void func_8007AF30(void) {
    func_8007ADDC(0);
    func_80057010(207);
}

void func_8007AF58(void) {
    func_80057334(207);
    func_8007ADDC(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007AF80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B4CC.s")

void func_8007B518(f32 arg0) {
    D_800FE060 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007B524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007BCE0.s")

void func_8007C494(void) {
    D_800FEA4C = 0;
    D_800FEB90 = 0;
    D_800FEB94 = 0;
    D_800FEB98 = 1;
    D_800FEB9C = -1;
}

void func_8007C4C8(void) {
    D_800FEA4C = 5;
    D_800FEB90 = 0;
    D_800FEB94 = 0;
    D_800FEB98 = 1;
    D_800FEB9C = -1;
}

s32 func_8007C500(void) {
    if (D_800FEA4C == 1) {
        return 1;
    }
    else if (D_800FEA4C >= 2) {
        return 2;
    }
    else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007C538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007C7FC.s")

void func_8007CDBC() {
    D_80174880.unk4 = 0;
    D_80174880.unk8 = 0;
    func_8008BD98(23);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007CDEC.s")

void func_8007DFDC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007DFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007E5E8.s")

void func_8007E684(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    D_800FEBD4.unk0 = arg0;
    D_800FEBD4.unk4 = arg1;
    D_800FEBD4.unk8 = arg2;
    D_800FEBD4.unkC = arg3;
    D_80176F50 = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007E6BC.s")

void func_8007E714(f32 arg0) {
    D_800FEBD0 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007E720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007EBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007F0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007F974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8007FB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80080318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800803F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80080430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80080864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80080C28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80080F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_8008265C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80082714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_800836FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80083B28.s")

void func_80083F08(void) {
}

void func_80083F10(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80083F18.s")

//https://decomp.me/scratch/s5GL7
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80084788.s")

//https://decomp.me/scratch/tLaoO
#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80084884.s")

s32 func_800849D4(s32 arg0) {
    return arg0;
}

void func_800849DC(s32 arg0) {
    func_80056F48();
    D_800F6880 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/30FB0/func_80084A04.s")
