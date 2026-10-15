/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02007f64();                            /* extern */
s32 func_02008148(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_02008170(M2C_UNK, M2C_UNK *);          /* extern */
extern u16 data_020c2f28;
extern M2C_UNK func_0200622c;

void func_02006270(void) {
    if (data_020c2f28 != 0) {
        return;
    }
    data_020c2f28 = 1;
    func_02007f64();
    do {

    } while (func_02008148(0xC, 1) == 0);
    func_02008170(0xC, &func_0200622c);
}
