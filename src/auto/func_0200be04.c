/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

extern s32 data_020c4c24;

s32 func_0200be04(void) {
    s32 temp_r0;

    temp_r0 = func_02006194();
    if (data_020c4c24 != 0) {
        func_020061a8(temp_r0);
        return 0;
    }
    data_020c4c24 = 1;
    func_020061a8(temp_r0);
    return 1;
}
