/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK WaitByLoop(M2C_UNK);                        /* extern */
s32 func_02008094(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

void func_02014cf0(M2C_UNK arg0) {
    if (func_02008094(0xD, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(1);
    } while (func_02008094(0xD, arg0, 0) != 0);
}
