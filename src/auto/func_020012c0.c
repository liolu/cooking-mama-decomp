#include "m2c.h"

M2C_UNK func_0200140c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020c2b60;

void func_020012c0(void) {
    *(s32 *) 0x04001000 &= ~0x80000000;
    func_0200140c(&data_020c2b60);
}
