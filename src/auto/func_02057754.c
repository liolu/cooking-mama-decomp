/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02111844;

void func_02057754(void) {
    M2C_UNK var_r2;
    s16 temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    switch (temp_r0) {                              /* irregular */
        case 0:
            var_r2 = 2;
            break;
        case 1:
        case 2:
            var_r2 = 0x12;
            break;
        default:
            var_r2 = 0x1C;
            break;
    }
    M2C_FIELD(temp_r4, void **, 0x1C)                         = func_0202b024(1, &data_02111844, var_r2, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA)  = 0xA;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0x1A) = 0;
    M2C_FIELD(temp_r4, void **, 0x20)                         = func_0202b024(1, &data_02111844, 9, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)    = 0x28;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)    = 0xA8;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA)  = 0xB;
}
