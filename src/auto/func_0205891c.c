/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02111914;
extern M2C_UNK func_02019c34;

void func_0205891c(void) {
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x80) == 0) {
        temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x68);
        if (temp_r0_2 == 0xA) {
            func_02019818(0);
        } else if (temp_r0_2 >= 8) {
            func_02019818(1);
        } else {
            func_02019818(2);
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x80) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x80) + 1);
    if (func_02019808() == 3) {
        data_02111914                   = &func_02019c34;
        M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
    }
}
