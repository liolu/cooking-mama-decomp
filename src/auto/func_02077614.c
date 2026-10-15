#include "m2c.h"

u32 func_02077614(void *arg0) {
    return (u32) ((M2C_FIELD(arg0, s32 *, 0) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), s32 *, 0xC)) << 0xD) >> 0x10;
}
