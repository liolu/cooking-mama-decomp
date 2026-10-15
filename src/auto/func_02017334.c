#include "m2c.h"

extern M2C_UNK data_020c63c0;

s32 func_02017334(void) {
    if (((u32) M2C_FIELD(&data_020c63c0, u16 *, 0x3C) >= 8U) && (M2C_FIELD(&data_020c63c0, s32 *, 0x44) == 0x218)) {
        return 1;
    }
    return 0;
}
