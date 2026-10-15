/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200be54();                            /* extern */
s32 func_0200c4c4(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK data_020c4c78;
extern M2C_UNK func_0200be6c;

s32 func_0200c480(M2C_UNK arg0) {
    s32 temp_r0;

    temp_r0                                = func_0200c4c4(arg0, &func_0200be6c, 0);
    M2C_FIELD(&data_020c4c78, s32 *, 0x20) = temp_r0;
    if (temp_r0 == 0) {
        func_0200be54();
    }
    return M2C_FIELD(&data_020c4c78, s32 *, 0x20);
}
