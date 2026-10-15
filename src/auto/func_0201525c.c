/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02007f64();                            /* extern */
s32 func_02008148(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_02008170(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_02014f94();                            /* extern */
M2C_UNK func_02015090();                            /* extern */
extern s32 data_020c617c;
extern s32 data_020c6180;
extern M2C_UNK func_02014ff4;
extern M2C_UNK func_02015054;

void func_0201525c(void) {
    if (data_020c617c != 0) {
        return;
    }
    data_020c617c = 1;
    func_02014f94();
    func_02007f64();
    do {

    } while (func_02008148(0xD, 1) == 0);
    func_02008170(0xD, &func_02015054);
    func_02015090();
    func_02008170(0xD, NULL);
    func_02008170(0xD, &func_02014ff4);
    data_020c6180 = 0;
}
