/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0211169c;
extern M2C_UNK data_02111704;
extern M2C_UNK data_0211176c;

void func_02056b40(void) {
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_0211169c, 2, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = 0x38;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = 0x78;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0xF;
    M2C_FIELD(temp_r4, void **, 0x20)                        = func_0202b024(1, &data_0211169c, 3, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)   = 0xC8;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)   = 0x78;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0xF;
    M2C_FIELD(temp_r4, void **, 0x24)                        = func_0202b024(1, &data_02111704, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 6)   = 0xE0;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s16 *, 0xA) = 0x14;
    M2C_FIELD(temp_r4, void **, 0x28)                        = func_0202b024(1, &data_0211176c, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x28), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x28), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x28), s16 *, 0xA) = 0x32;
}
