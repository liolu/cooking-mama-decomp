/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
M2C_UNK func_0200db00();                            /* extern */
extern s32 data_020c5560;
extern s32 (*data_020c5564)();

void func_0200db40(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        var_r0        = 1;
        data_020c5560 = 1;
        if (data_020c5564 != NULL) {
            var_r0 = data_020c5564();
        }
        if (var_r0 == 0) {
            return;
        }
        func_0200db00();
        return;
    }
    func_02006440();
}
