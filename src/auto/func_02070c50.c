/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02113b60;
extern s32 data_02113b64;
extern s32 data_02113b68;
extern M2C_UNK func_02019c34;

void func_02070c50(void) {
    s16 temp_r1;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x3C) == 0) {
        if (M2C_FIELD(temp_r0, s16 *, 0x5A) == (data_02113b68 + data_02113b64)) {
            temp_r1 = M2C_FIELD(temp_r0, s16 *, 0x40);
            if (temp_r1 == 0x1E) {
                func_02019818(0);
            } else if ((temp_r1 + M2C_FIELD(temp_r0, s16 *, 0x42)) == 0x1E) {
                func_02019818(1);
            } else {
                func_02019818(2);
            }
        } else {
            func_02019818(2);
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x3C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x3C) + 1);
    if (func_02019808() == 3) {
        data_02113b60                   = &func_02019c34;
        M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
    }
}
