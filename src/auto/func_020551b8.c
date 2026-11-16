/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02111484;
extern M2C_UNK func_02019c34;

void func_020551b8(void) {
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x60) == 0) {
        temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x5C);
        if (temp_r0_2 >= 0x30) {
            func_02019818(0);
        } else if (temp_r0_2 >= 0x26) {
            func_02019818(1);
        } else {
            func_02019818(2);
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x60) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x60) + 1);
    if (func_02019808() == 3) {
        data_02111484                   = &func_02019c34;
        M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
    }
}
