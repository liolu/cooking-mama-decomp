/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
M2C_UNK func_02076060(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_02114aac;

void func_02075a90(M2C_UNK arg0) {
    s32 temp_r4;

    temp_r4 = func_02006194();
    func_02076060(&data_02114aac, arg0);
    func_020061a8(temp_r4);
}
