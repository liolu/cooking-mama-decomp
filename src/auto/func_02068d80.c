/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02113170;

void func_02068d80(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                         = func_0202f368();
    temp_r0                         = func_0202b024(1, &data_02113170, 0, -1, 0x1000);
    M2C_FIELD(temp_r0, u16 *, 6)    = (u16) M2C_FIELD(temp_r4, u16 *, 0x34);
    M2C_FIELD(temp_r0, u16 *, 8)    = (u16) M2C_FIELD(temp_r4, u16 *, 0x36);
    M2C_FIELD(temp_r0, s16 *, 0xA)  = 0xA;
    M2C_FIELD(temp_r4, s32 *, 0x3C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x3C) + 1);
}
