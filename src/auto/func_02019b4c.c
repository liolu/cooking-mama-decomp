/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
s32 func_0201f4ec(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_0202de6c(s32, s32, M2C_UNK);           /* extern */
extern s32 data_020d331c;

s32 func_02019b4c(M2C_UNK arg0) {
    s32 temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    temp_r0_2 = func_020197fc();
    if (M2C_FIELD(temp_r0_2, void **, 0x28) == NULL) {
        return -1;
    }
    data_020d331c                     = 0;
    temp_r0_3                         = func_0201f4a0(0xB);
    M2C_FIELD(temp_r0_3, s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(temp_r0_2, void **, 0x28), s32 *, 0x10);
    temp_r0                           = func_0201f4ec(0xB, arg0);
    func_0202de6c(M2C_FIELD(temp_r0_3, s32 *, 0), temp_r0, 0x800);
    return temp_r0;
}
