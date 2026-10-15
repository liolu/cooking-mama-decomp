#include "m2c.h"

extern M2C_UNK data_020c4bb4;

s32 func_0200a0a0(s32 arg0) {
    return M2C_FIELD(&data_020c4bb4, u16 *, 0x34) & arg0;
}
