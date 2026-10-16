/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02006194();
M2C_UNK func_020061a8();
extern M2C_UNK data_020c2c14;

s32 func_020048dc(s32 arg0) {
    M2C_UNK m2c_irq;
    s32 temp_r4;

    m2c_irq                               = func_02006194();
    temp_r4                               = M2C_FIELD(&data_020c2c14, s32 *, 0xC);
    M2C_FIELD(&data_020c2c14, s32 *, 0xC) = arg0;
    func_020061a8(m2c_irq);
    return temp_r4;
}
