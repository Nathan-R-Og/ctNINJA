#include "common.h"
//AOF=301

const char padRodata[] = "\0\0\0\0\0\0\0";

// Sum of Two Squares: Elisiah
f32 func_8002D0E0(f32 arg0, f32 arg1) {
    return SUM_OF_SQUARES(arg0, arg1);
}

// Takes an angle in degrees and returns its normalised angle from 0
void normalizeDegrees(f32* theta_ptr) {
    while (1) {
        f32 theta = *theta_ptr;

        if (theta >= 360.0f) {
            *theta_ptr = theta - 360.0f;
            continue;
        } else if (theta < 0.0f) {
            *theta_ptr = theta + 360.0f;
            continue;
        } else {
            break;
        }
    }
}

// if a^2+b^2 > c^2 -> set a and b st. a^2+b^2=c^2 : Elisiah
// If point is outside circle (radius c), set norm st point is on the boundary
void func_8002D148(f32* a, f32* b, f32 c) {
    f32 norm;
    f32 aSquaredPlusBSquared;

    aSquaredPlusBSquared = SUM_OF_SQUARES(*a, *b);
    if (!(aSquaredPlusBSquared <= SQ(c))) {
        norm = sqrtf(aSquaredPlusBSquared);
        *a = (*a * c) / norm;
        *b = (*b * c) / norm;
    }
}

// Unknown Function: Elisiah 
f32 func_8002D1CC(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return func_800C8C14(arg2 - arg0, -(arg3 - arg1));
}

// Mirror the lower semicircle onto the top
f32 func_8002D214(f32 theta) {

    if (theta < 0.0f) {
        theta = -theta;
    }
    if (theta > 180.0f) {
        theta = 360.0f - theta;
    }
    return theta;
}

// 1 or 0 depending on unk func: Elisiah
s32 func_8002D258(f32 arg0, f32 arg1, f32 arg2) {   // Usually called as unk_90, arg1, unk_15C

    if (func_8002D214(arg0 - arg1) <= arg2) {
        return 1;
    }
    return 0;
}

// : Elisiah
s32 func_8002D2A0(f32 arg0, f32 arg1) {
    if (arg0 < 180.0f) {
        if ((arg0 < arg1) && (arg1 <= (arg0 + 180.0f))) {
            return 1;
        }
        return -1;
    }
    if (((arg0 - 180.0f) < arg1) && (arg1 <= arg0)) {
        return -1;
    }
    return 1;
}

// Unknown Angle Function: Elisiah
s32 func_8002D328(f32 theta, f32 phi) { // used to be void and still built
    f32* theta_ptr;

    theta_ptr = &theta;
    theta = theta - 90.0f;
    normalizeDegrees(theta_ptr);
    return func_8002D2A0(theta, phi);   // used to not return and still built
}

// Unkown Function: Elisiah
s32 func_8002D36C(f32* arg0, f32 arg1, f32 arg2) {
    s32 phi_v1;
    f32 phi_f0;
    s32 sp1C;

    phi_v1 = 0;
    if (*arg0 < arg1) {
        phi_f0 = -(*arg0 - arg1);
    } else {
        phi_f0 = *arg0 - arg1;
    }
    if (phi_f0 > 180.0f) {
        phi_f0 = 360.0f - phi_f0;
    }
    if (arg2 <= phi_f0) {
        sp1C = 0;
        *arg0 += arg2 * (f32) func_8002D2A0(*arg0, arg1);
    } else {
        *arg0 = arg1;
        phi_v1 = 1;
    }
    sp1C = phi_v1;
    normalizeDegrees(arg0);
    return sp1C;
}

void func_8002D434(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_f10;
    f32 a = *arg0 - arg2;
    f32 b = *arg1 - arg3;
    f32 c = sqrtf(SUM_OF_SQUARES(a, b));
    
    if (c != 0.0f) {
        temp_f10 = func_800C8C14(a, -b) + arg4;
        *arg0 = cosf(DEGREES_TO_RADIANS(temp_f10)) * c + arg2;
        *arg1 = arg3 + -(sinf(DEGREES_TO_RADIANS(temp_f10)) * c);
    }
}

//TODO: fake match (only here to match rodata)
void func_8002D550(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_f12;
    f32 *new_var;
    f32 temp_f2;
    f32 temp_f12_2 = func_8002D1CC(arg2, arg3, *arg0, *arg1);
    temp_f2 = (*arg0) - arg2;
    temp_f12 = (*arg1) - arg3;
    if (SUM_OF_SQUARES(temp_f2, temp_f12) < SQ(arg4)) {
        temp_f12_2 = DEGREES_TO_RADIANS(temp_f12_2);
        if (temp_f12) {

        }
        *arg0 = (cosf(temp_f12_2) * arg4) + arg2;
        *arg1 = ((-sinf(temp_f12_2)) * arg4) + arg3;
    }
}

void func_8002D644(s32 actorIndex, s32 actorID, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, f32 argF, f32 arg10, f32 arg11, f32 arg12, f32 arg13, s32 arg14, s32 arg15, s32 arg16, s32 arg17) {
    Actor* actorInstance;
    s32 i;

    actorInstance = &D_8016AC68[actorIndex];

    for (i = 0; i < 6;) {
        actorInstance->unk_10C[i] = 0;
        i++;
    }

    for (i = 0; i < 8; ) {
        actorInstance->unk_134[i] = 0;
        i++;
    }

    actorInstance->actorIndex = actorIndex;
    actorInstance->actorID = actorID;
    actorInstance->globalTimer = 0;
    actorInstance->posX = arg2;
    actorInstance->posY = arg3;
    actorInstance->posZ = arg4;
    actorInstance->unk_90 = arg5;

    for (i = 0; i < 3; i++) {
        actorInstance->unknownPositionThings[i].unk_08 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_04 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_00 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_10 = 0.0f;
        actorInstance->unknownPositionThings[i].unk_0C = 0.0f;
    }
    actorInstance->tScale = actorInstance->unknownPositionThings[0].unk_0C = D_8010A6D0[actorID].x;
    actorInstance->tYPos = actorInstance->unknownPositionThings[0].unk_10 = D_8010A6D0[actorID].y;
    actorInstance->tongueCollision = 1;

    actorInstance->unk_F4 = arg6;
    actorInstance->unk_F8 = arg7;
    actorInstance->unk_FC = arg8;
    actorInstance->unk_100 = arg9;
    actorInstance->unk_104 = argA;
    actorInstance->unk_108 = argB;
    actorInstance->position._f32.x = argC;
    actorInstance->position._f32.y = argD;
    actorInstance->unk_15C = argE;
    actorInstance->unk_160 = argF;
    actorInstance->unk_164 = arg10;
    actorInstance->unk_168 = arg11;
    actorInstance->unk_16C = arg12;
    actorInstance->unk_170 = arg13;
    actorInstance->unk_124 = arg14;
    actorInstance->unk_128 = arg15;
    actorInstance->unk_12C = arg16;
    actorInstance->unk_130 = arg17;
    actorInstance->actorState = 0;
    actorInstance->direction = 0.0f;
    actorInstance->yVelocity = 0.0f;
    actorInstance->unk_38 = 0.0f;
    actorInstance->tXOffset = 0.0f;
    actorInstance->tYOffset = 0.0f;
    actorInstance->tZOffset = 0.0f;
    actorInstance->unk_94 = 0.0f;
    actorInstance->posOnTongue = 0;
    actorInstance->touched = 0;
    actorInstance->hit = 0;
    actorInstance->tongueBumpSeg = 0;
    actorInstance->unk_98 = 0;
    actorInstance->unk_9C = 0;
    actorInstance->unk_B0 = 0.0f;
    
    actorInstance->unk_A0.unk_00 = D_8010AA28[actorID].unk_00;
    actorInstance->unk_A0.unk_04 = D_8010AA28[actorID].unk_04;
    actorInstance->unk_A0.unk_08 = D_8010AA28[actorID].unk_08;
    actorInstance->unk_A0.unk_0C = D_8010AA28[actorID].unk_0C;
    

    actorInstance->unk_C4 = 0;
    actorInstance->unk_C8 = 0;
    actorInstance->unk_C0 = 0.0f;

    actorInstance->unk_D0 = actorInstance->unk_CC = 1.0f;
    actorInstance->unk_EC = 0;
    actorInstance->unk_F0 = 0;
    actorInstance->unk_D4 = 0.0f;
    actorInstance->unk_D8 = 0.0f;
    actorInstance->unk_DC = 0.0f;
    actorInstance->unk_E0 = -1;
    actorInstance->unk_E4 = -1;

    switch (actorID) {
    case Red_Ant:
        func_80039368(actorInstance);
        return;
    case Green_Ant:
        func_8003A1B0(actorInstance);
        return;
    case Grey_Ant:
        func_80038510(actorInstance);
        return;
    case Bullet_Hell_Ant:
        func_80038AE0(actorInstance);
        return;
    case Ant_Trio:
        func_80038F70(actorInstance);
        return;
    case Yellow_Ant:
        func_800399A0(actorInstance);
        return;
    case Grey_Ant_Spawner:
        func_800383C0(actorInstance);
        return;
    case Bullet_Hell_Ant_Spawner:
        func_80038990(actorInstance);
        return;
    case Ant_Queen:
        func_8003A3F0(actorInstance);
        return;
    case Ant_Queen_Ant:
        func_8003B894(actorInstance);
        return;
    case White_Bomb_Snake:
        func_8003BA38(actorInstance);
        return;
    case Grenade:
        func_8003BC8C(actorInstance);
        return;
    case Missile_Spawner:
        func_8003BD98(actorInstance);
        return;
    case Missile:
        func_8003BEE8(actorInstance);
        return;
    case Cannon:
        func_8003C20C(actorInstance);
        return;
    case Cannonball:
        func_8003C4B8(actorInstance);
        return;
    case BL_Boss_Segment:
        func_8003C8AC(actorInstance);
        return;
    case Explosion:
        func_8003D574(actorInstance);
        return;
    case Black_Chameleon_Projectile_Spawner:
        func_8003D6A4(actorInstance);
        return;
    case Black_Chameleon_Projectile:
        func_8003D908(actorInstance);
        return;
    case Chomper:
        func_8003D998(actorInstance);
        return;
    case Sand_Crab:
        func_8003DE04(actorInstance);
        return;
    case Vulture:
        func_8003DFB4(actorInstance);
        return;
    case Arrows:
        func_8003E30C(actorInstance);
        return;
    case Boulder:
        func_8003E368(actorInstance);
        return;
    case Armadillo:
        func_8003E62C(actorInstance);
        return;
    case Pogo:
        func_8003FB04(actorInstance);
        return;
    case unk_23:
        func_8003FEB4(actorInstance);
        return;
    case Ice_Cream_Sandwich:
        func_8003FEC4(actorInstance);
        return;
    case Training_Room_Choco_Kid:
        func_80040068(actorInstance);
        return;
    case unk_1F:
        func_800401E8(actorInstance);
        return;
    case Popcorn:
        func_800404D8(actorInstance);
        return;
    case Cake_Boss:
        func_80041050(actorInstance);
        return;
    case Cake_Boss_Strawberry:
        func_800405F8(actorInstance);
        return;
    case unk_28:
        func_80040CDC(actorInstance);
        return;
    case Cake_Boss_Choco_Kid:
        func_80040CEC(actorInstance);
        return;
    case Bowling_Ball:
        func_80042AFC(actorInstance);
        return;
    case Bowling_Pins:
        func_80042FB4(actorInstance);
        return;
    case Cue_Ball:
        func_8004237C(actorInstance);
        return;
    case Billiards_Ball:
        func_8004259C(actorInstance);
        return;
    case unk_2E:
        func_800431E8(actorInstance);
        return;
    case unk_2F:
        func_800434F4(actorInstance);
        return;
    case Cup:
        func_80043998(actorInstance);
        return;
    case Saucer:
        func_800439D8(actorInstance);
        return;
    case Metal_Sheet:
        func_80043A18(actorInstance);
        return;
    case Scroll:
        func_80043A58(actorInstance);
        return;
    case RNG_Room_Spawner:
        func_80043A98(actorInstance);
        return;
    case Mirror:
        func_80043C80(actorInstance);
        return;
    case Barrel_Jump_Fire_Spawner:
        func_80043FE8(actorInstance);
        return;
    case Barrel_Jump_Fire:
        func_800440FC(actorInstance);
        return;
    case Fire_Spitter:
        func_800442E0(actorInstance);
        return;
    case Candles:
        func_80044504(actorInstance);
        return;
    case Fire_Spawner:
        func_80044544(actorInstance);
        return;
    case Fire:
        func_80044584(actorInstance);
        return;
    case Sandal:
        func_80044708(actorInstance);
        return;
    case Pile_of_Books:
        func_80044878(actorInstance);
        return;
    case Pile_of_Books_Arm_Segments:
        func_80046DDC(actorInstance);
        return;
    case Pile_of_Books_Arm_Spitter:
        func_80046FB0(actorInstance);
        return;
    case Pile_of_Books_Projectile:
        func_8004709C(actorInstance);
        return;
    case Spider_Spawner:
        func_8004718C(actorInstance);
        return;
    case Spider:
        func_80047350(actorInstance);
        return;
    case Spider_Trio:
        func_80047520(actorInstance);
        return;
    case Golem:
        func_800477C4(actorInstance);
        return;
    case Hedgehog:
        func_800479CC(actorInstance);
        return;
    case Fish:
        func_80047C04(actorInstance);
        return;
    case Lizard_Kong_Butterfly:
        func_800480EC(actorInstance);
        return;
    case Golem_Room_Spider_Spawner:
        func_8004769C(actorInstance);
        return;
    case Lizard_Kong_Butterfly_Spawner:
        func_800487D8(actorInstance);
        return;
    case Lizard_Kong_Boulder:
        func_800488C4(actorInstance);
        return;
    case Lizard_Kong:
        func_80048A68(actorInstance);
        return;
    case Popcorn_Bucket_Spawner:
        func_80049780(actorInstance);
        return;
    case Popcorn_Bucket:
        func_800498B4(actorInstance);
        return;
    case unk_4E:
        func_800498F4(actorInstance);
        return;
    case Choco_Kid_Spawner:
        func_80049934(actorInstance);
        return;
    case Choco_Kid:
        func_80049A24(actorInstance);
        return;
    case unk_51:
        func_80049A64(actorInstance);
        return;
    case unk_52:
        func_80049AA4(actorInstance);
        return;
    case Battle_Mode_Sand_Crab_Spawner:
        func_80049AE4(actorInstance);
        return;
    case Battle_Mode_Sand_Crab:
        func_80049C34(actorInstance);
        return;
    case unk_55:
        func_80049D0C(actorInstance);
        return;
    case Battle_Mode_Fire:
        func_80049F04(actorInstance);
        return;
    case Battle_Mode_Saucer_Spawner:
        func_80049F14(actorInstance);
        return;
    case Battle_Mode_Saucer:
        func_8004A0A0(actorInstance);
        return;
    case unk_59:
        func_8004A184(actorInstance);
        return;
    case unk_5A:
        func_8004A310(actorInstance);
        return;
    case Power_Up_Spawner:
        func_8004A39C(actorInstance);
        return;
    case Falling_Grey_Ant_Spawner:
        func_8004A544(actorInstance);
        return;
    case Falling_Grey_Ant:
        func_8004A658(actorInstance);
        return;
    case unk_5E:
        func_8004AB00(actorInstance);
    }
}

s32 func_8002DE30(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, f32 argF, f32 arg10, f32 arg11, f32 arg12, s32 arg13, s32 arg14, s32 arg15, s32 arg16) {
    s32 index;
    s32* pointer;

    pointer = &D_8016AC68->actorID;
    index = 0;
    while(1){
        if (*pointer == 0) {
            func_8002D644(index, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, argF, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
            D_80168DA4 += 1;
            return index;
        }
        index += 1;
        pointer += 0x5D;
        if (index == 0x40) {
            return -1;
        }
    }
}

//just annoying
//https://decomp.me/scratch/vLzb6
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002DF5C.s")


void func_8002E04C(s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    func_8002DE30(arg1, arg2, arg3, arg4, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0);
}

//BACKWARDS struct
//https://decomp.me/scratch/EqKdo
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002E0CC.s")

//big and intimidating
//https://decomp.me/scratch/rdS0x
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002E5DC.s")

//ditto
//https://decomp.me/scratch/x0ImW
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002E9F4.s")

//ditto
//https://decomp.me/scratch/gxIEG
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002ECCC.s")

void func_8002F3D4(void) {
    if (PlayerPointer->shootLeft != 0) {
        PlayerPointer->shootLeft--;
    }
    if (PlayerPointer->vaultFall != 0) {
        PlayerPointer->vaultFall--;
    }
    if (PlayerPointer->canJump == 0) {
        PlayerPointer->vaultFall = 0;
    }
    if (PlayerPointer->canJump == 0) {
        if (PlayerPointer->forwardVel == 0.0f) {
            PlayerPointer->groundMovement = 0;
            PlayerPointer->globalTimer = (PlayerPointer->globalTimer + D_8010B328);
            return;
        }
        if (PlayerPointer->forwardVel < (65.0f * PlayerPointer->forwardImpulse)) {
            PlayerPointer->groundMovement = 1;
            PlayerPointer->globalTimer = (PlayerPointer->globalTimer + (((2.0f + (((PlayerPointer->forwardVel / ((65.0f * PlayerPointer->forwardImpulse) / 10.0f)) * PlayerPointer->forwardImpulse) / D_8010B32C)) / 4.5f) / D_8010B330));
            return;
        }
        PlayerPointer->groundMovement = 2;
        PlayerPointer->globalTimer = PlayerPointer->globalTimer + 1.5f * PlayerPointer->forwardImpulse / D_8010B334;
    }
}


void func_8002F528(s32 arg0) {
    PlayerPointer->playerHURTSTATE = 3;
    PlayerPointer->playerHURTTIMER = 0;
}


void func_8002F54C(f32 arg0, playerActor* PlayerP, s32 arg2) {
    PlayerP->yVel = arg0;
    PlayerP->canJump = 1;
    PlayerP->hasTumbled = arg2;
    PlayerP->jumpReleasedInAir = 0;
    PlayerP->jumpAnimFrame = 0;
}



void func_8002F568(void) {
    PlayerPointer->xVel = PlayerPointer->xVaultlocity * 0.25f;
    PlayerPointer->zVel = PlayerPointer->zVaultlocity * 0.25f;
    if (TonguePointer->segments >= 4) {
        PlayerPointer->vaultFall = 0xC;
    }
}

//very close
//https://decomp.me/scratch/oO1ev
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002F5C4.s")

//unGODLY close
//https://decomp.me/scratch/QW2eP
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002F6DC.s")

void func_8002F7F0(void) {
    s32 aIM;

    aIM = TonguePointer->amountInMouth;
    if (aIM < 6) {
        PlayerPointer->forwardImpulse = (f32) (((24.0f - (f32) aIM) * D_8010B34C) / 24.0f);
    } else {
        PlayerPointer->forwardImpulse = (f32) D_8010B350;
    }
    if (PlayerPointer->power == 3) {
        PlayerPointer->forwardImpulse = (f32) (PlayerPointer->forwardImpulse * 0.5f);
    }
}

void func_8002F884(s32 arg0, s32 arg1) {
    if (((D_801749B0 == 0) || (PlayerPointer->playerID != 1)) && (D_80168D78[arg0] == 0)) {
        if (D_800FFEB4 == 7) {
            func_8007B314(arg0, ((arg1 * 100) / 6.0f), arg1);
        } else {
            func_8007B314(arg0, ((arg1 * 100) * 0.5f), arg1);
        }
    }
}

void func_8002F960(unk_8002F960* arg0) {
    func_8002F884(PlayerPointer->playerID, 2);
    func_80087ED0(0x10, 0, 0, 0, 0, 0x10);
    arg0->unk608 = 0xA;
}

void func_8002F9BC(s32 arg0) {
    PlayerPointer->power = 0;
    func_8002F7F0();
    PlayerPointer->tongueYOffset = 60.0f;
    PlayerPointer->tongueSeperation = 50.0f;
    PlayerPointer->hitboxSize = 30.0f;
    PlayerPointer->hitboxYStretch = 150.0f;
}

//this one is REALLY long holy shit
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8002FA34.s")

//less long than above but still nauseating
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80030DCC.s")

//yeah
//https://decomp.me/scratch/BeR2b
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80030F3C.s")


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800311C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800312B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800312FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800313BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800314E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80031518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800317A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80031898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80031DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80032074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800320EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800321F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80032720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80032A0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80033048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80033C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80034104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800343B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003449C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80034744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80034B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80034FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80035374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80035460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800360E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003624C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80036490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80036900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80036D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80036F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003749C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80037504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80037538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80037584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003760C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80037D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80037F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800382B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800382F4.s")

void func_800383A0(void) {
    func_800CEFC4();
}

// Grey Ant Spawner: Elisiah
void func_800383C0(Actor* greyAntSpawnerActor) {
    if (greyAntSpawnerActor->unk_12C != 0) {
        D_801748A0 = 0;
        greyAntSpawnerActor->unk_10C[1] = greyAntSpawnerActor->unk_12C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800383E4.s")

// Grey Ant Function: Rainchu and Elisiah
void func_80038510(Actor* actor) {
    actor->unk_94 = actor->unk_124;
    actor->unk_90 = func_8002D1CC(actor->posX, actor->posZ, actor->position._f32.x, actor->position._f32.y);
    actor->unk_10C[0] = 4;
    actor->unk_134[0] = actor->posY;
    actor->posY = actor->posY - actor->unknownPositionThings[0].unk_10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038574.s")

// Bullet-Hell Ant Spawner: Elisiah
void func_80038990(Actor* bulletHellAntSpawnerActor) {
    bulletHellAntSpawnerActor->unk_10C[1] = bulletHellAntSpawnerActor->unk_128;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003899C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038E64.s")

// Ant Trio Function: Elisiah
void func_80038F70(Actor* antTrioActor) {
    antTrioActor->unk_94 = (f32) antTrioActor->unk_124;
    antTrioActor->unk_90 = func_8002D1CC(antTrioActor->posX, antTrioActor->posZ, antTrioActor->position._f32.x, antTrioActor->position._f32.y);
    antTrioActor->unk_98 = 1;
    func_800382F4(antTrioActor); 
    antTrioActor->unk_F0 = func_800C8900(0, 0x100);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80038FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80039368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80039500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800397DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800399A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80039B0C.s")

// Green Ant Function: Rainchu and Elisiah
void func_8003A1B0(Actor* greenAntActor) {
    greenAntActor->unk_134[0] = 0.0f;
    greenAntActor->unk_10C[2] = greenAntActor->unk_15C / greenAntActor->position._f32.x;
    greenAntActor->unk_F0 = func_800C8900(0, 0x100/*, greenAntActor*/);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003A208.s")

// Ant Queen Function: Elisiah
void func_8003A3F0(Actor* antQueenActor) {
    antQueenActor->unk_120 = (s32) antQueenActor->unk_12C;
    antQueenActor->tongueCollision = 3;
    antQueenActor->unknownPositionThings[1].unk_0C = 150.0f;
    antQueenActor->unknownPositionThings[1].unk_10 = (f32) D_8010A6D0[Ant_Queen].y;
    antQueenActor->unknownPositionThings[2].unk_0C = 200.0f;
    antQueenActor->unknownPositionThings[2].unk_10 = (f32) D_8010A6D0[Ant_Queen].y;
    antQueenActor->unknownPositionThings[1].unk_04 = 150.0f;
    antQueenActor->unknownPositionThings[2].unk_04 = 300.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003A444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003AAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003B894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003B8D8.s")

// White Bomb Snake Function: Elisiah
void func_8003BA38(Actor* whiteBombSnakeActor) {
    s32 temp_f10;

    whiteBombSnakeActor->unk_10C[0] = 4;
    whiteBombSnakeActor->unk_134[0] = whiteBombSnakeActor->posX;
    whiteBombSnakeActor->unk_134[1] = whiteBombSnakeActor->posZ;
    whiteBombSnakeActor->unk_90 = func_8002D1CC(whiteBombSnakeActor->posX, whiteBombSnakeActor->posZ, whiteBombSnakeActor->position._f32.x, whiteBombSnakeActor->position._f32.y);
    temp_f10 = (s32) (180.0f / whiteBombSnakeActor->unk_160);
    whiteBombSnakeActor->unk_10C[3] = temp_f10;
    whiteBombSnakeActor->unk_160 = (f32) (0xB4 / temp_f10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003BADC.s")

// Grenade Function: Elisiah
void func_8003BC8C(Actor* grenadeActor) {
    grenadeActor->unk_94 = grenadeActor->position._f32.x;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003BC98.s")

// Missile Spawner: Auto-Decompile
void func_8003BD98(Actor* missileSpawnerActor) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003BDA0.s")

// Missile Function: Elisiah
void func_8003BEE8(Actor* missileActor) {
    missileActor->unk_134[0] = missileActor->posX;
    missileActor->unk_134[1] = missileActor->posY;
    missileActor->unk_134[2] = missileActor->posZ;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003BF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003C8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003CAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D574.s")

void func_8003D598(Actor* arg0) {               //Unsure if struct is actor
    if (arg0->unk_124 == arg0->globalTimer) {  //0x124 == 0x10
        func_80031518();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D5C8.s")

// Black Chameleon Projectile Spawner: Auto-Decompile
void func_8003D6A4(Actor* blackChameleonProjectileSpawnerActor){
    
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D6AC.s")


void func_8003D908(Actor* arg0) {
    arg0->unk_CC = 0.0f;
    func_800312B0(arg0->actorIndex);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003D9D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003DE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003DE4C.s")

// Vulture Function: Elisiah
void func_8003DFB4(Actor* vultureActor) {
    vultureActor->unk_134[0] = vultureActor->posX;
    vultureActor->unk_134[1] = vultureActor->posY;
    vultureActor->unk_134[2] = vultureActor->posZ;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003DFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E224.s")

// Arrows Function: Elisiah
void func_8003E30C(Actor* arrowsActor) {
    arrowsActor->unk_94 = arrowsActor->position._f32.x;
    arrowsActor->unk_10C[0] = (s32) (arrowsActor->position._f32.y / arrowsActor->position._f32.x);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E32C.s")
// Elisiah
void func_8003E32C(Actor* arg0) {                   // unsure if struct is actor
    if (arg0->globalTimer == arg0->unk_10C[0]) {
        func_80031518();
    }
    func_800382F4(arg0);
}

// boulder
void func_8003E368(Actor* boulderActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E48C.s")

// Armadillo Function: Elisiah
void func_8003E62C(Actor* armadilloActor) {
    armadilloActor->unk_134[0] = armadilloActor->position._f32.y / armadilloActor->position._f32.x;
    armadilloActor->posY = -400.0f;
    armadilloActor->unk_134[4] = 100.0f;
    armadilloActor->unk_10C[4] = armadilloActor->unk_130;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003E968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003EB38.s")

void func_8003FA38(Actor* arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_f8;

    temp_f0 = arg1 - arg0->posX;
    temp_f2 = arg3 - arg0->posZ;
    if (arg0->unk_10C[0] >= 3) {
        arg0->unk_94 = (f32) (arg0->unk_16C / 1.5f);
    } else {
        arg0->unk_94 = (f32) arg0->unk_16C;
    }
    temp_f8 = (s32) (sqrtf(SQ(temp_f0) + SQ(temp_f2)) / arg0->unk_94);
    arg0->unk_10C[1] = temp_f8;
    arg0->unk_134[3] = (f32) ((arg2 - arg0->posY) / (f32) temp_f8);
    arg0->unk_90 = func_800C8C14(temp_f0, -temp_f2);
}

// Pogo Function: Elisiah
void func_8003FB04(Actor* pogoActor) {
    pogoActor->unk_10C[0] = 1;
    pogoActor->unk_134[0] = pogoActor->posX;
    pogoActor->unk_134[1] = pogoActor->posY;
    pogoActor->unk_134[2] = pogoActor->posZ;
    
    func_8003FA38(pogoActor, pogoActor->position._f32.x, pogoActor->position._f32.y, pogoActor->unk_15C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003FB4C.s")

// 0x21
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003FC54.s")

// 0x22
void func_8003FEAC(s32 arg0) {
}

// unk_23
void func_8003FEB4(Actor* unk_23Actor){

}

void func_8003FEBC(s32 arg0) {

}

// Ice Cream Sandwich Function: Elisiah
void func_8003FEC4(Actor* iceCreamSandwichActor) {
    iceCreamSandwichActor->unk_134[0] = iceCreamSandwichActor->posY;
    iceCreamSandwichActor->posY = iceCreamSandwichActor->posY + 2000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8003FEE0.s")

// Training Room Choco Kid Function: Elisiah
void func_80040068(Actor* trainingRoomChocoKidActor) {
    trainingRoomChocoKidActor->unk_134[1] = trainingRoomChocoKidActor->posZ;
    trainingRoomChocoKidActor->unk_94 = trainingRoomChocoKidActor->position._f32.x;
    trainingRoomChocoKidActor->unk_134[0] = trainingRoomChocoKidActor->posX;
    func_8006E16C(trainingRoomChocoKidActor->posX, trainingRoomChocoKidActor->posY + 50.0f, trainingRoomChocoKidActor->posZ, 0x42F00000, 20.0f, 0xA);
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800400C8.s")

// unk_1F Function: Elisiah
void func_800401E8(Actor* unk_1FActor) {
    unk_1FActor->unk_134[0] = unk_1FActor->posY;
    unk_1FActor->unk_134[1] = unk_1FActor->posX;
    unk_1FActor->unk_134[2] = unk_1FActor->posZ;
    unk_1FActor->posY = unk_1FActor->posY + 1000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80040214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800404D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80040590.s")

// Cake Boss Strawberry Function: Elisiah
void func_800405F8(Actor* cakeBossStrawberryActor) {
    if (cakeBossStrawberryActor->unk_128 == 6) {
        cakeBossStrawberryActor->tScale *= 2.0f;
        cakeBossStrawberryActor->tYPos *= 2.0f;
        cakeBossStrawberryActor->unknownPositionThings[0].unk_0C = cakeBossStrawberryActor->tScale;
        cakeBossStrawberryActor->unknownPositionThings[0].unk_10 = cakeBossStrawberryActor->tYPos;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80040638.s")

// unk_28
void func_80040CDC(Actor* unk_28Actor){

}

void func_80040CE4(s32 arg0) {

}

// Cake Boss Choco Kid: Auto-Decompile
void func_80040CEC(Actor* cakeBossChocoKidActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80040CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80041050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800410B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800410EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80041C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80042174.s")

// Cue Ball Actor: Elisiah
void func_8004237C(Actor* cueBallActor) {
    cueBallActor->unk_134[0] = cueBallActor->posY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80042388.s")

// Billiards Ball
void func_8004259C(Actor* billiardsBallActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800425A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004263C.s")

// Bowling Ball Function: Elisiah
void func_80042AFC(Actor* bowlingBallActor) {
    func_8006A74C();
    func_8004263C();
    bowlingBallActor->unk_10C[0] = 0;
    bowlingBallActor->unk_134[0] = bowlingBallActor->posY;
    bowlingBallActor->unk_10C[3] = func_80055BD8() % 5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80042B4C.s")

// Bowling Pins Function: Elisiah
void func_80042FB4(Actor* bowlingPinsActor) {
    bowlingPinsActor->unk_90 = (f32) ((func_80055BD8() % 21) - 0x64);
    bowlingPinsActor->unk_10C[1] = (func_80055BD8() % 21) + 0x1E;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043010.s")

void func_800431E8(Actor* arg0) {
    arg0->unk_10C[0] = 0xA;
    arg0->unk_134[0] = arg0->posY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800431FC.s")

// unk_2F
void func_800434F4(Actor* unk_2FActor){

}

void func_800434FC(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043558.s")

// Cup Function: Elisiah
void func_80043998(Actor* cupActor) {
    func_80043504(cupActor);
}

void func_800439B8(void) {
    func_80043558();
}

// Saucer Function: Elisiah
void func_800439D8(Actor* saucerActor) {
    func_80043504(saucerActor);
}

void func_800439F8(void) {
    func_80043558();
}

// Metal Sheet Function: Elisiah
void func_80043A18(Actor* metalSheetActor) {
    func_80043504(metalSheetActor);
}

void func_80043A38(void) {
    func_80043558();
}

// Scroll Function: Elisiah
void func_80043A58(Actor* scrollActor) {
    func_80043504(scrollActor);
}

void func_80043A78(void) {
    func_80043558();
}

// RNG Room Spawner: Auto-Decompile
void func_80043A98(Actor* rngRoomSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043C80.s")
/* NEEDS PERMUTING
void func_80043C80(Actor* arg0) {
    if (arg0->unk_124 == ((s32) D_8017499C % (s32) arg0->unk_128)) {
        arg0->unk_10C[1] = 1;
        return;
    }
    arg0->unk_10C[1] = 0;
}*/


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043CDC.s")

// Barrel Jump Fire Spawner: Auto-Decompile
void func_80043FE8(Actor* barrelJumpFireSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80043FF0.s")

// Barrel Jump Fire Actor: Elisiah
void func_800440FC(Actor* barrelJumpFireActor) {
    barrelJumpFireActor->unk_134[0] = func_8002D1CC(barrelJumpFireActor->position._f32.x, barrelJumpFireActor->position._f32.y, barrelJumpFireActor->posX, barrelJumpFireActor->posZ);
    barrelJumpFireActor->unk_10C[0] = (s32) (360.0f / barrelJumpFireActor->unk_160) - 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044158.s")

// Fire Spitter Function: Elisiah
void func_800442E0(Actor* fireSpitterActor) {
    fireSpitterActor->unk_10C[0] = fireSpitterActor->unk_124 - 1;
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800442F0.s")

// Candles Function: Elisiah
void func_80044504(Actor* candlesActor) {
    func_800442E0(candlesActor);
}

void func_80044524(void) {
    func_800442F0();
}

// Fire Spawner: Elisiah
void func_80044544(Actor* fireSpawnerActor) {
    func_80044504(fireSpawnerActor);
}

void func_80044564(void) {
    func_80044524();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800445CC.s")

// Sandal Function: Elisiah
void func_80044708(Actor* sandalActor) {
    func_800431E8(sandalActor);
}


void func_80044728(void) {
    func_800431FC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044748.s")

// Pile of Books Function: Elisiah
void func_80044878(Actor* pileOfBooksActor) {
    pileOfBooksActor->unk_EC = 0;
    pileOfBooksActor->unk_10C[3] = pileOfBooksActor->unk_128 * 2;
    pileOfBooksActor->unk_134[1] = pileOfBooksActor->posZ + -800.0f;
    pileOfBooksActor->unk_134[2] = pileOfBooksActor->unk_90;
    func_80044748(pileOfBooksActor);    // Compiled as empty originally?
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800448C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80044EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004501C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80046DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80046E50.s")

void func_80046FB0(Actor* arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80046FB8.s")

void func_8004709C(Actor* arg0) {
    arg0->unk_94 = arg0->position._f32.x;
    func_800382F4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800470C0.s")

// Spider Spawner: Auto-Decompile
void func_8004718C(Actor* spiderSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047194.s")

// Spider Function: Elisiah
void func_80047350(Actor* spiderActor) {
    spiderActor->unk_98 = 1;
    spiderActor->yVelocity = spiderActor->unk_160;
    spiderActor->unk_94 = spiderActor->position._f32.x;
    func_800382F4(spiderActor);    // Sometimes calls with a arg0, sometimes calls empty?
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047568.s")

// Golem Room Spider Spawner: Auto-Decompile
void func_8004769C(Actor* golemRoomSpiderSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800476A4.s")

// Golem?: Auto-Decompile
void func_800477C4(Actor* golem) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800477CC.s")

// Hedgehog Function: Elisiah
void func_800479CC(Actor* hedgehogActor) {
    hedgehogActor->unk_134[0] = (f32) hedgehogActor->posX;
    hedgehogActor->unk_134[1] = (f32) hedgehogActor->posZ;
    hedgehogActor->unk_134[2] = (f32) hedgehogActor->unk_90;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800479E8.s")

// Fish Function: Elisiah
void func_80047C04(Actor* fishActor) {
    fishActor->unk_134[0] = fishActor->posX;
    fishActor->unk_134[1] = fishActor->posZ;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047C18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80047FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800480EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80048284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800486E0.s")

// Lizard Kong Butterfly Spawner: Auto-Decompile
void func_800487D8(Actor* lizardKongButterflySpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800487E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800488C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800488FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_800489B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80048A68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80048AFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80048B88.s")

// Popcorn Bucket Spawner: Auto-Decompile
void func_80049780(Actor* popcornBucketSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049788.s")

// Popcorn Bucket Function: Elisiah
void func_800498B4(Actor* popcornBucketActor) {
    func_800401E8(popcornBucketActor);
}

void func_800498D4(void) {
    func_80040214();
}


void func_800498F4(Actor* arg0) {
    func_800404D8(arg0);
}


void func_80049914(void) {
    func_80040590();
}


// Choco Kid Spawner: Auto-Decompile
void func_80049934(Actor* chocoKidSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004993C.s")

// Choco Kid Function: Elisiah
void func_80049A24(Actor* chocoKidActor) {
    func_80040068(chocoKidActor);
}

void func_80049A44(void) {
    func_800400C8();
}

// unk_51 Function: Elisiah
void func_80049A64(Actor* unk_51Actor) {
    func_800383C0(unk_51Actor);
}

void func_80049A84(void) {
    func_800383E4();
}

// unk_52 Function: Elisiah
void func_80049AA4(Actor* unk_52Actor) {
    func_80038510(unk_52Actor);
}

void func_80049AC4(void) {
    func_80038574();
}

// Battle Mode Sand Crab Spawner: Auto-Decompile
void func_80049AE4(Actor* battleModeSandCrabSpawnerActor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049AEC.s")

// Battle Mode Sand Crab Function: Elisiah
void func_80049C34(Actor* battleModeSandCrabActor) {
    battleModeSandCrabActor->unk_94 = battleModeSandCrabActor->position._f32.x;
    battleModeSandCrabActor->yVelocity = 32.0f;
    func_800382F4(battleModeSandCrabActor);
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049C64.s")

// unk_55
void func_80049D0C(Actor* unk_55Actor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049D14.s")


void func_80049F04(Actor* arg0) {

}

void func_80049F0C(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_80049F50.s")

// Battle Mode Saucer Function: Elisiah
void func_8004A0A0(Actor* battleModeSaucerActor) {
    battleModeSaucerActor->unk_134[0] = battleModeSaucerActor->posY;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A0AC.s")

// unk_59
void func_8004A184(Actor* unk_59Actor){

}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A18C.s")

// unk_5A Function: Elisiah
void func_8004A310(Actor* unk_5AActor) {
    unk_5AActor->unk_98 = 1;
}

// unk_5C
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A31C.s")

// Power Up Spawner: Auto-Decompile
void func_8004A39C(Actor* powerUpSpawnerActor){
    
}

// unk_5B
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A3A4.s")

// Falling Grey Ant Spawner Auto-Decompile
void func_8004A544(Actor* fallingGreyAntSpawnerActor){
    
}

// unk_5C
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A54C.s")

// Falling Grey Ant Function: Elisiah
void func_8004A658(Actor* fallingGreyAntActor) {
    fallingGreyAntActor->unk_94 = (f32) fallingGreyAntActor->unk_124;
    fallingGreyAntActor->unk_90 = func_8002D1CC(fallingGreyAntActor->posX, fallingGreyAntActor->posZ, fallingGreyAntActor->position._f32.x, fallingGreyAntActor->position._f32.y);
    fallingGreyAntActor->unk_98 = 1;
    func_800382F4(fallingGreyAntActor);
    fallingGreyAntActor->unk_F0 = func_800C8900(0, 0x100);
}

// unk_5D
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004A6C4.s")

// unk_??
void func_8004AB00(Actor* unk_5EActor){
}

// unk_5E
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004AB08.s")

// unk_60
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004AC20.s")

// unk_66 to unk_69 arent used
// unk_6A
#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004AC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004AD2C.s")

//iirc this is for the battle start
//thanks rain for fixing it
void func_8004BA5C(s32 arg0) {
    s32 i;
    PlayerPointer = &D_80168DA8;
    TonguePointer = &D_80169268;
    
    for (i = 0; i < arg0; i++) {
        func_8004AD2C();
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004BAC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004BC48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004BD7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004BE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004BF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004C110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004C1C8.s")

s32 func_8004C374(u16* arg0, u16* arg1, s32 arg2) {
    if ((*arg1 & arg2) == 0) {
        *arg0 |= arg2;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004C3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004C43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004C600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004CC6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004CCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004CD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/code/84E0/func_8004DDE0.s")
