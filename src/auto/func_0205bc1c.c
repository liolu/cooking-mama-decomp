/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02111e98;

void func_0205bc1c(M2C_UNK arg0) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                      = func_0202f368();
    temp_r0                      = func_0202b024(1, &data_02111e98, 0, arg0, 0x40);
    M2C_FIELD(temp_r0, s16 *, 6) = (s16) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x48), void **, 0x1C), s16 *, 6);
    M2C_FIELD(temp_r0, s16 *, 8) = (s16) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x48), void **, 0x1C), s16 *, 8);
}
