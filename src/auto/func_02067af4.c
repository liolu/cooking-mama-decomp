/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_02112ef4;
extern M2C_UNK data_02112f60;
extern M2C_UNK func_02067940;

void func_02067af4(void) {
    s32 temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x24);
    if (M2C_FIELD((data_02112ef4 + (temp_r2 * 4)), u16 *, 6) == 2) {
        M2C_FIELD(temp_r0, void **, 0x1C)                        = func_0202b024(1, &data_02112f60, 0, 1, 0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 6)   = 0x80;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8)   = 0x48;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0xA) = 0x14;
    } else {
        M2C_FIELD(temp_r0, void **, 0x1C)                        = func_0202b024(1, &data_02112f60, temp_r2 + 2, -1, 0);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 6)   = 0x80;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8)   = -0x10;
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0xA) = 0x14;
        func_0202ec14(0x19);
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02067940;
}
