/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, s32, s32); /* extern */
void *func_0202f368();                              /* extern */
void *func_0206eab8();                              /* extern */
extern s32 data_021115c0;
extern M2C_UNK data_021115c8;
extern M2C_UNK func_0205588c;

void func_020558bc(void) {
    s32 var_r5;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (data_021115c0 == 1) {
        var_r5 = 0;
    } else {
        var_r5 = 3;
    }
    temp_r0 = func_0206eab8();
    M2C_FIELD(temp_r0, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
    M2C_FIELD(temp_r4, void **, 0x1C) = func_0202b024(
        1, &data_021115c8, 0, var_r5 + (u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * 3) >> 0x10), 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = (s16) M2C_FIELD(temp_r4, s16 *, 0x20);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = (s16) M2C_FIELD(temp_r4, s16 *, 0x22);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0x1C;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_0205588c;
}
