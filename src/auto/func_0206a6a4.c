/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_021132ac;

void func_0206a6a4(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    temp_r0                                                  = func_0202b024(1, &data_021132ac, 7, -1, 0);
    M2C_FIELD(temp_r0, s16 *, 6)                             = 0x80;
    M2C_FIELD(temp_r0, s16 *, 8)                             = 0x60;
    M2C_FIELD(temp_r0, s16 *, 0xA)                           = 0xA;
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_021132ac, 1, -1, 1);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0x28;
    M2C_FIELD(temp_r4, void **, 0x20)                        = func_0202b024(1, &data_021132ac, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)   = -0x20;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0x1E;
    M2C_FIELD(temp_r4, void **, 0x24)                        = func_0202b024(1, &data_021132ac, 5, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 8)   = -0x30;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 0xA) = 0x23;
}
