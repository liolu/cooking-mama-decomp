#include "m2c.h"

extern s32 *data_020c6274;

void func_0201678c(s32 arg0) {
    if (data_020c6274 != NULL) {
        *data_020c6274 = arg0;
    }
}
