/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
M2C_UNK func_02014fd4();                            /* extern */
extern s32 (*data_020c6180)();

void func_02014ff4(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        var_r0 = 0;
        if (data_020c6180 != NULL) {
            var_r0 = data_020c6180();
        }
        if (var_r0 == 0) {
            return;
        }
        func_02014fd4();
        return;
    }
    func_02006440();
}
