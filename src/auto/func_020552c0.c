/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, M2C_UNK *, s32, M2C_UNK, s32); /* extern */
void *func_0202f368();                              /* extern */
void *func_0206eab8();                              /* extern */
extern M2C_UNK data_02111488;
extern M2C_UNK func_020552b4;

void func_020552c0(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = func_0206eab8();
    M2C_FIELD(temp_r0, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
    M2C_FIELD(temp_r4, s32 *, 0x24)   = (s32) ((u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * 3) >> 0x10) * 5);
    M2C_FIELD(temp_r4, void **, 0x1C) = func_0202b024(1, &data_02111488, M2C_FIELD(temp_r4, s32 *, 0x24), -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 6)   = (s16) M2C_FIELD(temp_r4, s16 *, 0x2C);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 8)   = (s16) M2C_FIELD(temp_r4, s16 *, 0x2E);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0xA) = (s16) M2C_FIELD(temp_r4, s16 *, 0x30);
    M2C_FIELD(temp_r4, void **, 0x20) = func_0202b024(1, &data_02111488, M2C_FIELD(temp_r4, s32 *, 0x24) + 4, -1, 0);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 6)    = (s16) M2C_FIELD(temp_r4, s16 *, 0x2C);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 8)    = (s16) M2C_FIELD(temp_r4, s16 *, 0x2E);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0xA)  = 0x3E;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0x1A) = 0;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                         = &func_020552b4;
}
