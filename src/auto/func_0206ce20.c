#include "m2c.h"

void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_0206cd90();                            /* extern */
extern void *data_0211372c;
extern M2C_UNK func_0206cd50;
extern M2C_UNK func_0206cdf8;

void func_0206ce20(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_r0;

    func_0206cd90();
    temp_r0                                    = func_0202f564(&func_0206cd50, 0x10);
    data_0211372c                              = temp_r0;
    M2C_FIELD(temp_r0, s32 *, 0x28)            = arg0;
    M2C_FIELD(data_0211372c, s32 *, 0x30)      = arg1;
    M2C_FIELD(data_0211372c, s32 *, 0x34)      = arg2;
    M2C_FIELD(data_0211372c, M2C_UNK **, 0x14) = &func_0206cdf8;
}
