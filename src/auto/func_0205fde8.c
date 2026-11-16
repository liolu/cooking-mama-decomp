/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_0202f368();                                /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern s32 data_0211224c;
extern M2C_UNK data_02112254;
extern M2C_UNK func_0205f3fc;
extern M2C_UNK func_0205fa38;
extern M2C_UNK func_0205fd40;

void func_0205fde8(void) {
    s32 temp_r4;
    s32 var_r10;
    s32 var_r9;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;
    void *temp_r0_4;

    temp_r4                        = func_0202f368();
    temp_r0                        = func_0202b024(1, &data_02112254, 0, -1, 0);
    M2C_FIELD(temp_r0, s16 *, 6)   = 0x80;
    M2C_FIELD(temp_r0, s16 *, 8)   = 0x60;
    M2C_FIELD(temp_r0, s16 *, 0xA) = 0x14;
    if (data_0211224c == 1) {
        var_r10 = 2;
    } else {
        var_r10 = 4;
    }
    var_r9 = 0;
    do {
        if (var_r9 < var_r10) {
            temp_r0_2                         = func_0202f564(&func_0205fd40, 0x10);
            M2C_FIELD(temp_r0_2, s32 *, 0x1C) = temp_r4;
            M2C_FIELD(temp_r0_2, s32 *, 0x28) = var_r9;
            temp_r0_3                         = func_0202f564(&func_0205fa38, 0x10);
            M2C_FIELD(temp_r0_3, s32 *, 0x1C) = temp_r4;
            M2C_FIELD(temp_r0_3, s32 *, 0x28) = var_r9;
        }
        temp_r0_4                         = func_0202f564(&func_0205f3fc, 0x10);
        M2C_FIELD(temp_r0_4, s32 *, 0x1C) = temp_r4;
        M2C_FIELD(temp_r0_4, s32 *, 0x28) = var_r9;
        var_r9 += 1;
    } while (var_r9 < 4);
}
