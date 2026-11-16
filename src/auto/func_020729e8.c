/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern s32 *data_02113de8;
extern M2C_UNK data_02113dec;
extern M2C_UNK data_02113e54;

void func_020729e8(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (*data_02113de8 == 0xE) {
        M2C_FIELD(temp_r4, void **, 0x1C) = func_0202b024(1, &data_02113e54, 0xA, -1, 0);
    } else {
        M2C_FIELD(temp_r4, void **, 0x1C) = func_0202b024(1, &data_02113dec, 0, -1, 0);
    }
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = 0x88;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = 0x29;
    M2C_FIELD(temp_r4, void **, 0x20)                        = func_0202b024(1, &data_02113e54, 2, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)   = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)   = 0x88;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA) = 0x28;
}
