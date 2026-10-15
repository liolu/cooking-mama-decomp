/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);
void func_02006ae4(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0200f988(M2C_UNK);

extern s32 data_020c613c;

s32 func_02010d30(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_02006194();
    if ((data_020c613c != 0) && (func_0200f988(arg0) != 0)) {
        func_02006ae4(((arg0 - 1) * 0x16) + (data_020c613c + 0x1340), data_020c613c + 0x1772, 0x16);
        func_020061a8(temp_r4);
        return data_020c613c + 0x1772;
    }
    func_020061a8(temp_r4);
    return 0;
}
