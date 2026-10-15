#include "m2c.h"

M2C_UNK func_020015b0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020c2b5e;

void func_02001518(void) {
    *(s32 *) 0x04001000 &= ~0x40000000;
    func_020015b0(&data_020c2b5e);
}
