/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0201e140();                                /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_0206de68(M2C_UNK, M2C_UNK, s32, M2C_UNK); /* extern */
extern M2C_UNK func_0205899c;

void func_02058a78(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0201e140() != 0) {
        return;
    }
    func_02038384(1);
    func_0206de68(0x80, 0x60, M2C_FIELD(temp_r4, s32 *, 0x84) + 4, -1);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0205899c;
}
