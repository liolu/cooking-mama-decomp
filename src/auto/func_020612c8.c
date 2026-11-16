/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
extern M2C_UNK func_020612bc;

void func_020612c8(void) {
    s32 temp_lr;
    void *temp_ip;
    void *temp_r0;
    void *temp_r2;

    temp_r0                                                = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x3C)                        = (s32) (M2C_FIELD(temp_r0, s32 *, 0x3C) + 1);
    temp_ip                                                = M2C_FIELD(temp_r0, void **, 0x1C);
    M2C_FIELD(temp_ip, s16 *, 8)                           = (s16) (M2C_FIELD(temp_ip, s16 *, 8) - 4);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s16 *, 8) = (s16) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8);
    temp_lr                                                = M2C_FIELD(temp_r0, s32 *, 0x3C) * 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0x1A) =
        (s16) (0x1F - ((s32) (temp_lr + ((u32) (temp_lr >> 3) >> 0x1C)) >> 4));
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s16 *, 0x1A) = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0x3C) != 0x10) {
        return;
    }
    temp_r2 = M2C_FIELD(temp_r0, void **, 0x24);
    if (M2C_FIELD(temp_r2, s32 *, 0x48) == 2) {
        M2C_FIELD(temp_r2, s32 *, 0x40)                           = (s32) (M2C_FIELD(temp_r2, s32 *, 0x40) - 1);
        M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x24), s32 *, 0x48) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020612bc;
}
