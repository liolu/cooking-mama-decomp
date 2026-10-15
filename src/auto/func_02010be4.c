/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200f988();                                /* extern */
M2C_UNK func_02010ba8(s32, s32, M2C_UNK);           /* extern */
extern s32 data_020c613c;

void func_02010be4(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (func_0200f988() != 0) {
        M2C_FIELD((data_020c613c + ((arg0 - 1) * 4)), s32 *, 0x14E8) = arg1;
    }
    func_02010ba8(arg0, arg1, arg2);
}
