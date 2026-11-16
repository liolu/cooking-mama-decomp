/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_021138d8;

void func_0206e0b4(void) {
    void *temp_r4;
    void *temp_r5;

    temp_r5                                                  = func_0202f368();
    temp_r4                                                  = func_020197fc();
    M2C_FIELD(temp_r5, void **, 0x1C)                        = func_0202b024(1, &data_021138d8, 0, -1, 1);
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x1C), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x1C), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x1C), s16 *, 0xC) = 0;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x1C), s16 *, 0xE) = 0;
    M2C_FIELD(temp_r5, void **, 0x20) =
        func_0202b024(1, &data_021138d8, (M2C_FIELD(temp_r4, u8 *, 0x31) + 2) - M2C_FIELD(temp_r4, u8 *, 0x30), -1, 1);
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x20), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x20), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x20), s16 *, 0xC) = 0;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x20), s16 *, 0xE) = 0;
    M2C_FIELD(temp_r5, void **, 0x24)                        = func_0202b024(1, &data_021138d8, 1, -1, 1);
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x24), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x24), s16 *, 8)   = 0x60;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x24), s16 *, 0xC) = 0;
    M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x24), s16 *, 0xE) = 0;
}
