/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020057c8(M2C_UNK *);                   /* extern */
M2C_UNK func_020077f4();                            /* extern */
M2C_UNK func_0200798c();                            /* extern */
extern s32 data_020c2f48;
extern M2C_UNK data_020c2f4c;

void func_0200709c(void) {
    if (data_020c2f48 != 0) {
        return;
    }
    data_020c2f48 = 1;
    func_020057c8(&data_020c2f4c);
    func_020077f4();
    func_0200798c();
}
