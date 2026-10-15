/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02007f64();                            /* extern */
M2C_UNK func_02008170(M2C_UNK, M2C_UNK *);          /* extern */
extern s32 data_020c5564;
extern M2C_UNK func_0200db40;

void func_0200dbac(void) {
    func_02007f64();
    func_02008170(0xE, &func_0200db40);
    data_020c5564 = 0;
}
