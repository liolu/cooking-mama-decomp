/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b33c(void *);                      /* extern */
M2C_UNK func_0202b3d0(void *);                      /* extern */
M2C_UNK func_020537c4(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 data_020d5290;

void func_0202b1a0(void **arg0) {
    void *temp_r0;
    void *temp_r1;
    void *temp_r1_2;

    temp_r0 = *arg0;
    if (temp_r0 == NULL) {
        return;
    }
    if ((u32) (M2C_FIELD(temp_r0, s32 *, 0) - 3) <= 1U) {
        data_020d5290 -= 1;
    }
    temp_r1 = *arg0;
    if (M2C_FIELD(temp_r1, s32 *, 0x28) != 0) {
        func_0202b33c(temp_r1 + 0x28);
    }
    temp_r1_2 = *arg0;
    if (M2C_FIELD(temp_r1_2, s32 *, 0x24) != 0) {
        func_0202b3d0(temp_r1_2 + 0x24);
    }
    func_020537c4(*arg0, 0, 0x2C);
    *arg0 = NULL;
}
