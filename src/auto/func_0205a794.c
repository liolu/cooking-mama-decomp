/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0205a2c4();                            /* extern */
M2C_UNK func_0205a37c();                            /* extern */
M2C_UNK func_0205a448();                            /* extern */
M2C_UNK func_0205a54c();                            /* extern */
M2C_UNK func_0205a618();                            /* extern */
extern s32 data_02111cec;
extern M2C_UNK data_02111d5c;
extern M2C_UNK func_0205a720;

void func_0205a794(void) {
    M2C_UNK var_r2;
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if ((M2C_FIELD(temp_r0, s32 *, 0x30) == 1) && (data_02111cec == 0x11)) {
        var_r2 = 4;
    } else {
        temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x34);
        if (temp_r0_2 < 8) {
            var_r2 = 1;
        } else if (temp_r0_2 < 0x10) {
            var_r2 = 2;
        } else {
            var_r2 = 3;
        }
    }
    M2C_FIELD(temp_r0, void **, 0x1C)                        = func_0202b024(1, &data_02111d5c, var_r2, -1, 1);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 6)   = (s16) M2C_FIELD(temp_r0, s16 *, 0x24);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8)   = (s16) M2C_FIELD(temp_r0, s16 *, 0x26);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0xA) = (s16) (0x3C - M2C_FIELD(temp_r0, s32 *, 0x30));
    switch ((s32) data_02111cec) {                  /* irregular */
        case 2:
            func_0205a618();
            break;
        case 15:
            func_0205a54c();
            break;
        case 5:
            func_0205a448();
            break;
        case 7:
            func_0205a37c();
            break;
        case 18:
            func_0205a2c4();
            break;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0205a720;
}
