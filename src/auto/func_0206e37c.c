#include "m2c.h"

extern M2C_UNK data_02113940;

u16 func_0206e37c(s32 arg0) {
    return *((u16 *) ((s8 *) &data_02113940 + (arg0 * 2)));
}
