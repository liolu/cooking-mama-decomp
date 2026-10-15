#include "m2c.h"

extern u16 data_020c5568;

s32 func_0200e150(void) {
    if (data_020c5568 != 0) {
        return 0;
    }
    return 3;
}
