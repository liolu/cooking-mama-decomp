#include "m2c.h"

extern M2C_UNK data_02113804;

void func_0206d76c(s32 arg0) {
    void *temp_r1;

    temp_r1 = *((M2C_UNK *) ((s8 *) &data_02113804 + (arg0 * 4)));
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 0x2C) = 0;
    }
}
