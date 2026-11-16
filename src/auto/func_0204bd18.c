/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern M2C_UNK func_0204bd50;

void func_0204bd18(void) {
    M2C_UNK var_r0;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s32 *, 0x24) & 0x80) {
        var_r0 = 0;
    } else {
        var_r0 = 2;
    }
    func_0203773c(var_r0);
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0204bd50;
}
