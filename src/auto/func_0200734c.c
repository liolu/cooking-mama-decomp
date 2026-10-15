/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

extern s32 data_020c2f68;
extern s32 data_020c2f6c;
extern s32 data_020c2f84;

s32 func_0200734c(void) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_02006194();
    if (data_020c2f6c == 0) {
        var_r4 = data_020c2f68;
    } else {
        var_r4 = data_020c2f84;
    }
    func_020061a8(temp_r0);
    return var_r4;
}
