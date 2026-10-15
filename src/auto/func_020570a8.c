#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_0211183c;
extern M2C_UNK func_02019c34;
extern M2C_UNK func_02056f88;

void func_020570a8(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x30) == 0) {
        if (M2C_FIELD(temp_r0, s32 *, 0x2C) != 0) {
            func_02019818(0);
        } else {
            func_02019818(2);
        }
        M2C_FIELD(temp_r0, s32 *, 0x30) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x30) + 1);
    }
    if (func_02019808() != 3) {
        return;
    }
    data_0211183c                                 = &func_02019c34;
    M2C_FIELD(func_020197fc(), M2C_UNK **, 0x17C) = &func_02056f88;
    M2C_FIELD(temp_r0, s32 *, 0x10)               = 1;
}
