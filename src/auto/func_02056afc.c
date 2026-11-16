/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0201e140();                                /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_0206de68(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK func_02056568;

void func_02056afc(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_02038384(1);
    func_0206de68(0xC0, 0x60, 2, -1);
    *temp_r4 = &func_02056568;
}
