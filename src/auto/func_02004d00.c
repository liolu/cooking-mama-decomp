/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02004c90(s32, M2C_UNK);                /* extern */
M2C_UNK func_02006194();                            /* extern */
extern M2C_UNK data_020c2c14;

void func_02004d00(void) {
    func_02006194();
    func_02004c90(M2C_FIELD(&data_020c2c14, s32 *, 4), 0);
}
