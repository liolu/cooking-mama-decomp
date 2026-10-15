#include "m2c.h"

M2C_UNK func_02012ab0();                            /* extern */
extern void *data_020c613c;

void func_02012a8c(s32 arg0) {
    M2C_FIELD(data_020c613c, s32 *, 0x1320) = 1;
    func_02012ab0(arg0);
}
