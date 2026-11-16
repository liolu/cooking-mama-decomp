/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02111e2c;
extern M2C_UNK func_02019c34;

void func_0205ca88(void) {
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x64) == 0) {
        temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x4C);
        if (temp_r0_2 == 0xA) {
            func_02019818(0);
        } else if (temp_r0_2 >= 8) {
            func_02019818(1);
        } else {
            func_02019818(2);
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x64) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x64) + 1);
    if (func_02019808() == 3) {
        data_02111e2c                   = &func_02019c34;
        M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
    }
}
