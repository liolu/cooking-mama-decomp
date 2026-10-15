/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020049cc();                            /* extern */
M2C_UNK func_020050f8(s32, void *);                 /* extern */
s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
extern void **data_020c2c0c;

void func_02004b98(s32 arg0) {
    s32 temp_r5;
    void *temp_r4;

    temp_r5 = func_02006194();
    temp_r4 = *data_020c2c0c;
    if (arg0 != 0) {
        M2C_FIELD(temp_r4, s32 *, 0x78) = arg0;
        func_020050f8(arg0, temp_r4);
    }
    M2C_FIELD(temp_r4, s32 *, 0x64) = 0;
    func_020049cc();
    func_020061a8(temp_r5);
}
