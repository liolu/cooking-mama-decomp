#include "m2c.h"

s32 func_0202d308(s32, s16, s16, s16, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_0202d948(s32, s32);                    /* extern */
M2C_UNK func_0202de6c(s32, s32, M2C_UNK);           /* extern */

s32 func_0202d4f8(void *arg0, s32 arg1) {
    s32 temp_r4;

    temp_r4 = func_0202d308(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s16 *, 4), M2C_FIELD(arg0, s16 *, 6),
                            M2C_FIELD(arg0, s16 *, 8), arg1, M2C_FIELD(arg0, s32 *, 0x18), (s32) M2C_FIELD(arg0, s16 *, 0xA),
                            (s32) M2C_FIELD(arg0, s16 *, 0xC), M2C_FIELD(arg0, s32 *, 0x10));
    if (M2C_FIELD(arg0, s32 *, 0x14) == 1) {
        func_0202d948(M2C_FIELD(arg0, s32 *, 0), temp_r4);
    }
    func_0202de6c(M2C_FIELD(arg0, s32 *, 0), temp_r4, 0x800);
    return temp_r4;
}
