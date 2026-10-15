#include "m2c.h"

M2C_UNK func_0200140c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020c2b58;

void func_0200139c(void) {
    *(s32 *) 0x04000000 &= ~0x80000000;
    func_0200140c(&data_020c2b58);
}
