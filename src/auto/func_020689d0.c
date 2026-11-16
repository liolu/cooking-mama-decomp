/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
extern M2C_UNK func_020689c4;

void func_020689d0(void) {
    s32 temp_lr;
    void *temp_ip;
    void *temp_r0;

    temp_r0                                                = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x38)                        = (s32) (M2C_FIELD(temp_r0, s32 *, 0x38) + 1);
    temp_ip                                                = M2C_FIELD(temp_r0, void **, 0x1C);
    M2C_FIELD(temp_ip, s16 *, 8)                           = (s16) (M2C_FIELD(temp_ip, s16 *, 8) - 4);
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s16 *, 8) = (s16) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 8);
    temp_lr                                                = M2C_FIELD(temp_r0, s32 *, 0x38) * 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0x1A) =
        (s16) (0x1F - ((s32) (temp_lr + ((u32) (temp_lr >> 3) >> 0x1C)) >> 4));
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x20), s16 *, 0x1A) = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0x38) == 0x10) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020689c4;
    }
}
