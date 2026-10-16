/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02006194();
M2C_UNK func_020061a8();
extern u32 data_020c2c00;

u32 func_02004890(void) {
    M2C_UNK m2c_irq;
    M2C_UNK saved_reg_r4;
    u32 var_r4;

    var_r4  = saved_reg_r4;
    m2c_irq = func_02006194();
    if ((u32) data_020c2c00 < -1U) {
        var_r4 = data_020c2c00;
        data_020c2c00 += 1;
    }
    func_020061a8(m2c_irq);
    return var_r4;
}
