#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
extern M2C_UNK func_020689d0;

void func_02068a54(void) {
    void *temp_ip;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_02038374() == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(temp_r4, void **, 0x24);
    if (M2C_FIELD(temp_r1, s32 *, 0x38) != 0) {
        return;
    }
    if (M2C_FIELD(temp_r1, s32 *, 0x5C) == 1) {
        func_0202ec14(0x1B);
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x5C) = 0;
    }
    temp_r1_2                                                = M2C_FIELD(temp_r4, void **, 0x24);
    M2C_FIELD(temp_r1_2, s32 *, 0x40)                        = (s32) (M2C_FIELD(temp_r1_2, s32 *, 0x40) + 1);
    temp_ip                                                  = M2C_FIELD(temp_r4, void **, 0x24);
    M2C_FIELD(temp_ip, s32 *, 0x44)                          = (s32) (M2C_FIELD(temp_ip, s32 *, 0x44) + 1);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0xF;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0x10;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_020689d0;
}
