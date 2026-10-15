#include "m2c.h"

extern s32 *data_020c6274;

s32 func_020166bc(void) {
    if (data_020c6274 == NULL) {
        return 0;
    }
    return *data_020c6274;
}
