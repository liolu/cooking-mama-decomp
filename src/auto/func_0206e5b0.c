/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
s32 func_0200af30();                                /* extern */

void func_0206e5b0(void) {
    if (func_0200af30() == 0) {
        return;
    }
    func_02006440();
}
