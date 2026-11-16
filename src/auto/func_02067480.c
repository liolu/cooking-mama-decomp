/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02112d4c;
extern M2C_UNK data_02112db4;
extern M2C_UNK data_02112e1c;

void func_02067480(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                                                   = func_0202f368();
    M2C_FIELD(temp_r4, void **, 0x1C)                         = func_0202b024(1, &data_02112d4c, 0, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)    = 0x40;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)    = 0x68;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA)  = 0x1E;
    M2C_FIELD(temp_r4, void **, 0x20)                         = func_0202b024(1, &data_02112db4, 3, -1, 2);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)    = 0x40;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)    = 0x62;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA)  = 0x17;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0x1A) = 0;
    temp_r0                                                   = func_0202b024(1, &data_02112e1c, 0, -1, 0);
    M2C_FIELD(temp_r0, s16 *, 6)                              = 0xB8;
    M2C_FIELD(temp_r0, s16 *, 8)                              = 0x60;
    M2C_FIELD(temp_r0, s16 *, 0xA)                            = 0x28;
}
