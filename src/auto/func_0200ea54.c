/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005818(void *, M2C_UNK);             /* extern */
s32 func_0200e04c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
void *func_0200e16c();                              /* extern */

s32 func_0200ea54(void) {
    void *temp_r1;
    void *temp_r4;

    temp_r4 = func_0200e16c();
    if (func_0200e04c(2, 7, 8) != 0) {
        return 0;
    }
    func_02005818(M2C_FIELD(temp_r4, void **, 4) + 0xC, 4);
    temp_r1 = M2C_FIELD(temp_r4, void **, 4);
    if (M2C_FIELD(temp_r1, s32 *, 0xC) == 1) {
        return 0;
    }
    func_02005818(temp_r1 + 0x3C, 4);
    return (M2C_FIELD(M2C_FIELD(temp_r4, void **, 4), u16 *, 0x3C) + 0x1F) & ~0x1F;
}
