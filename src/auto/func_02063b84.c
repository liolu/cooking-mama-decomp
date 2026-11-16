/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b1a0(void *);                      /* extern */
void *func_0202f368();                              /* extern */

void func_02063b84(void) {
    s32 temp_r3;
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x24) + 1);
    temp_r3                         = M2C_FIELD(temp_r0, s32 *, 0x24) * 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x1C), s16 *, 0x1A) =
        (s16) (0x1F - ((s32) (temp_r3 + ((u32) (temp_r3 >> 4) >> 0x1B)) >> 5));
    if (M2C_FIELD(temp_r0, s32 *, 0x24) != 0x20) {
        return;
    }
    func_0202b1a0(temp_r0 + 0x1C);
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
