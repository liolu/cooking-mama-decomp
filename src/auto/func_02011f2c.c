#include "m2c.h"

extern M2C_UNK data_020c6090;

void func_02011f2c(void) {
    M2C_FIELD(M2C_FIELD(&data_020c6090, void **, 4), s16 *, 0x4B0) = 1;
    M2C_FIELD(&data_020c6090, u8 *, 0xE) = (u8) M2C_FIELD(M2C_FIELD(&data_020c6090, void **, 4), u8 *, 0x4B4);
    M2C_FIELD(&data_020c6090, s8 *, 0xC) = 5;
}
