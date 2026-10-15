#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_0206d3c4(M2C_UNK);                     /* extern */
extern void *data_02113798;
extern M2C_UNK func_0206d384;
extern M2C_UNK func_0206d4c8;

void func_0206d4f0(M2C_UNK arg0, s32 arg1, s32 arg2) {
    void *temp_r0;

    if (arg1 > 0x14) {
        func_02006440();
    }
    func_0206d3c4(arg0);
    temp_r0                                    = func_0202f564(&func_0206d384, 0x10);
    data_02113798                              = temp_r0;
    M2C_FIELD(temp_r0, s32 *, 0x6C)            = arg1;
    M2C_FIELD(data_02113798, s32 *, 0x74)      = arg2;
    M2C_FIELD(data_02113798, M2C_UNK **, 0x14) = &func_0206d4c8;
}
