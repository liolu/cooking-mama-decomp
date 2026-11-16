/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0206e390();                            /* extern */
extern M2C_UNK data_02113940;

void func_0206e494(void) {
    M2C_FIELD(&data_02113940, s16 *, 0) = (s16) (((*(volatile u16 *) 0x04000130 | *(u16 *) 0x027FFFA8) ^ 0x2FFF) & 0x2FFF);
    func_0206e390();
    M2C_FIELD(&data_02113940, u16 *, 6) = (u16) (M2C_FIELD(&data_02113940, u16 *, 4) & 0xF0);
    M2C_FIELD(&data_02113940, u16 *, 6) =
        (u16) (M2C_FIELD(&data_02113940, u16 *, 6) | (u16) (M2C_FIELD(&data_02113940, u16 *, 2) & 0x2F0F));
}
