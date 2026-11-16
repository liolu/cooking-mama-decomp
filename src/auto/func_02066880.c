/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02112c10;
extern M2C_UNK func_02066854;

void func_02066880(void) {
    void *temp_r4;

    temp_r4                                                  = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                        = func_0202b024(1, &data_02112c10, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = (s16) ((M2C_FIELD(temp_r4, s32 *, 0x20) * 2) + 0xC0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = 0x30;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = (s16) (M2C_FIELD(temp_r4, s32 *, 0x20) + 0x1E);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                        = &func_02066854;
}
