/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_021125dc;
extern M2C_UNK data_021126ac;

void func_02061dd4(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    temp_r0                                                  = func_0202b024(1, &data_021125dc, 2, -1, 0);
    M2C_FIELD(temp_r0, s16 *, 6)                             = 0x80;
    M2C_FIELD(temp_r0, s16 *, 8)                             = 0x60;
    M2C_FIELD(temp_r0, s16 *, 0xA)                           = 0x1E;
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_021126ac, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = 0x48;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0x1D;
    M2C_FIELD(temp_r4, void **, 0x20)                        = func_0202b024(1, &data_021125dc, 0x22, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)   = 0x5A;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)   = 0x95;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0x1D;
}
