/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020053fc(void);
M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

s32 func_020070e8(void) {
    s32 temp_r0;
    s32 temp_r4;

    if (func_020053fc() == 0) {
        return 1;
    }
    temp_r0             = func_02006194();
    *(s32 *) 0x04FFF200 = 0x10;
    temp_r4             = *(s32 *) 0x04FFF200;
    func_020061a8(temp_r0);
    if (temp_r4 != 0) {
        return 1;
    }
    return 0;
}
