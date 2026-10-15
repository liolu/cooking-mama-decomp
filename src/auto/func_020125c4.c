#include "m2c.h"

extern void *data_020c6138;

s32 func_020125c4(void) {
    if (M2C_FIELD(data_020c6138, u8 *, 0x50D) == 1) {
        return 1;
    }
    return 0;
}
