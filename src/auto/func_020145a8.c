/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
M2C_UNK func_020145fc(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_020147b8();                                /* extern */
extern s32 data_020c6160;

void func_020145a8(M2C_UNK arg0) {
    s32 temp_r4;

    temp_r4 = func_02006194();
    if (func_020147b8() != 0) {
        func_020145fc(data_020c6160 + 0xC4, 0, arg0, 0);
    }
    func_020061a8(temp_r4);
}
