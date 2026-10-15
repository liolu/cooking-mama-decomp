#include "m2c.h"

M2C_UNK func_020015b0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020c2b58;

void func_02001568(void) {
    *(s32 *) 0x04000000 &= ~0x80000000;
    func_020015b0(&data_020c2b58);
}
