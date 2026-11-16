/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_02113104;

void func_020692b4(void) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x54) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x54) + 1);
    temp_r0_2                       = M2C_FIELD(temp_r0, s32 *, 0x54);
    if (temp_r0_2 < 0x10) {
        return;
    }
    if (temp_r0_2 != 0x10) {
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x54) = 0;
    if (data_02113104 == 2) {
        func_0202c03c(M2C_FIELD(temp_r0, void **, 0x20), 2);
    }
    temp_r0_3 = M2C_FIELD(temp_r0, s32 *, 0x40);
    if (temp_r0_3 >= 0xF) {
        func_0202c03c(M2C_FIELD(temp_r0, void **, 0x24), 0x12);
        if (data_02113104 == 1) {
            func_0202c03c(M2C_FIELD(temp_r0, void **, 0x20), 0x15);
        }
    } else if (temp_r0_3 >= 0xA) {
        func_0202c03c(M2C_FIELD(temp_r0, void **, 0x24), 0x11);
    } else if (temp_r0_3 >= 5) {
        func_0202c03c(M2C_FIELD(temp_r0, void **, 0x24), 0x10);
    } else {
        func_0202c03c(M2C_FIELD(temp_r0, void **, 0x24), 0xF);
    }
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x24), s16 *, 0x1A) = 0x1F;
    if (data_02113104 == 1) {
        M2C_FIELD(temp_r0, s32 *, 0x48) = 3;
        return;
    }
    if (data_02113104 != 2) {
        M2C_FIELD(temp_r0, s32 *, 0x48) = 2;
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 0x48)                           = 4;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x2C), s16 *, 6)    = 0x40;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x2C), s16 *, 8)    = 0x68;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x2C), s16 *, 0x1A) = 0x1F;
}
