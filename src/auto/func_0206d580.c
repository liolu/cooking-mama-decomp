#include "m2c.h"

extern M2C_UNK data_02113804;

void func_0206d580(void *arg0) {
    *((M2C_UNK *) ((s8 *) &data_02113804 + (M2C_FIELD(arg0, s32 *, 0x20) * 4))) = 0;
}
