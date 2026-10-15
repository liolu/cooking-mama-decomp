/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020069a4(M2C_UNK, void *, M2C_UNK);    /* extern */
extern M2C_UNK func_02079b5c;
extern M2C_UNK func_02079c14;
extern M2C_UNK func_02079e24;
extern M2C_UNK func_02079ec4;

void func_020793b4(void *arg0) {
    func_020069a4(0, arg0, 0x48);
    M2C_FIELD(arg0, s32 *, 0x10)      = 1;
    M2C_FIELD(arg0, s32 *, 0x14)      = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &func_02079ec4;
    M2C_FIELD(arg0, M2C_UNK **, 0x1C) = &func_02079e24;
    M2C_FIELD(arg0, M2C_UNK **, 0x20) = &func_02079c14;
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &func_02079b5c;
}
