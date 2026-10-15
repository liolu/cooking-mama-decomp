/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200ac58();                            /* extern */
s32 func_0200af74(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_020c4bf0;
extern M2C_UNK func_0200ac70;

s32 func_0200af30(void) {
    s32 temp_r0;

    temp_r0                               = func_0200af74(&func_0200ac70, 0);
    M2C_FIELD(&data_020c4bf0, s32 *, 0xC) = temp_r0;
    if (temp_r0 == 0) {
        func_0200ac58();
    }
    return M2C_FIELD(&data_020c4bf0, s32 *, 0xC);
}
