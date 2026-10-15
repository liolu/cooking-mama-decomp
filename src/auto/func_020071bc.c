/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020061f8(M2C_UNK);                     /* extern */
s32 func_020070e8();                                /* extern */
s32 func_02008148(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_02008170(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK func_02007228;

void func_020071bc(void) {
    func_02008170(7, &func_02007228);
    if (func_020070e8() == 0) {
        return;
    }
    if (func_02008148(7, 1) != 0) {
        return;
    }
    do {
        func_020061f8(0x64);
    } while (func_02008148(7, 1) == 0);
}
