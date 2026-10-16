/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02006194();
M2C_UNK func_020061a8();
extern s32 data_020c2c00;

s32 func_02004858(void) {
    M2C_UNK m2c_irq;
    s32 var_r4;

    m2c_irq = func_02006194();
    var_r4  = 0;
    if (data_020c2c00 != 0) {
        var_r4 = data_020c2c00;
        data_020c2c00 -= 1;
    }
    func_020061a8(m2c_irq);
    return var_r4;
}
