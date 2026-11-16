/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02006440();                            /* extern */
s32 func_0200a0a0(M2C_UNK);                         /* extern */
M2C_UNK func_0200a0b4(M2C_UNK);                     /* extern */
M2C_UNK func_0200a600(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern s8 data_02113994;
extern M2C_UNK data_021139b4;

void func_0206e8b4(void) {
    func_0200a600(0, 4, &data_021139b4, 5);
    func_0200a0b4(2);
    if (func_0200a0a0(2) != 0) {
        func_02006440();
    }
    data_02113994 = 1;
}
