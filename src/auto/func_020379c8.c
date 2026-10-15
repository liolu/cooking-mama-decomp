#include "m2c.h"

M2C_UNK func_0200472c(s32, M2C_UNK *, s32);         /* extern */
s32 func_02053788(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK data_020b5df4;
extern M2C_UNK data_020b5df8;
extern M2C_UNK data_020b5e00;
extern M2C_UNK data_020b5e0c;
extern M2C_UNK data_020b5e10;
extern M2C_UNK data_020b5e18;
extern M2C_UNK data_020b5e24;
extern M2C_UNK data_020b5e28;
extern M2C_UNK data_020b5e30;
extern M2C_UNK data_020b5e3c;
extern M2C_UNK data_020b5e40;
extern M2C_UNK data_020b5e48;
extern M2C_UNK data_020b5e54;
extern M2C_UNK data_020b5e58;
extern M2C_UNK data_020b5e60;

void func_020379c8(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 var_r5;

    var_r5 = arg1;
    if (arg2 < 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, volatile s32 *, 8);
    if (arg2 < 0xA) {
        var_r5 += 1;
    }
    if (temp_r0 != 0) {
        if (func_02053788(temp_r0, &data_020b5df4) == 0) {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 8) + var_r5, &data_020b5df8, arg2);
        } else {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 8) + var_r5, &data_020b5e00, arg2);
        }
    }
    temp_r0_2 = M2C_FIELD(arg0, volatile s32 *, 4);
    if (temp_r0_2 != 0) {
        if (func_02053788(temp_r0_2, &data_020b5e0c) == 0) {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 4) + var_r5, &data_020b5e10, arg2);
        } else {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 4) + var_r5, &data_020b5e18, arg2);
        }
    }
    temp_r0_3 = M2C_FIELD(arg0, volatile s32 *, 0xC);
    if (temp_r0_3 != 0) {
        if (func_02053788(temp_r0_3, &data_020b5e24) == 0) {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0xC) + var_r5, &data_020b5e28, arg2);
        } else {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0xC) + var_r5, &data_020b5e30, arg2);
        }
    }
    temp_r0_4 = M2C_FIELD(arg0, volatile s32 *, 0x10);
    if (temp_r0_4 != 0) {
        if (func_02053788(temp_r0_4, &data_020b5e3c) == 0) {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0x10) + var_r5, &data_020b5e40, arg2);
        } else {
            func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0x10) + var_r5, &data_020b5e48, arg2);
        }
    }
    temp_r0_5 = M2C_FIELD(arg0, volatile s32 *, 0x14);
    if (temp_r0_5 == 0) {
        return;
    }
    if (func_02053788(temp_r0_5, &data_020b5e54) == 0) {
        func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0x14) + var_r5, &data_020b5e58, arg2);
        return;
    }
    func_0200472c(M2C_FIELD(arg0, volatile s32 *, 0x14) + var_r5, &data_020b5e60, arg2);
}
