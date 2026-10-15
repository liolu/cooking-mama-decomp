#include "m2c.h"

M2C_UNK func_0200140c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020c2b5e;

void func_020012e8(void) {
    *(s32 *) 0x04001000 &= ~0x40000000;
    func_0200140c(&data_020c2b5e);
}
