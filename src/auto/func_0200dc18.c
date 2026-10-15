/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

extern void *data_020c556c;

s32 func_0200dc18(void) {
    s32 temp_r0;
    u16 var_r4;

    temp_r0 = func_02006194();
    if (data_020c556c != NULL) {
        var_r4 = M2C_FIELD(data_020c556c, u16 *, 0x150);
    } else {
        var_r4 = 0;
    }
    func_020061a8(temp_r0);
    return (s32) var_r4;
}
