#include "m2c.h"

M2C_UNK func_0202b1a0(s32);                         /* extern */
extern M2C_UNK data_02113844;

void func_0206da44(void *arg0) {
    func_0202b1a0(arg0 + 0x20);
    *((M2C_UNK *) ((s8 *) &data_02113844 + (M2C_FIELD(arg0, s32 *, 0x2C) * 4))) = 0;
}
