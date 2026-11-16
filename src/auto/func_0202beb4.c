/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0206eab8();                              /* extern */
M2C_UNK func_02077650(void *, s32);                 /* extern */

void func_0202beb4(void *arg0) {
    u16 temp_r4;
    u16 var_r1;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = M2C_FIELD(arg0, void **, 0x28);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r4   = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x18), void **, 0xC), u16 *, 4);
    temp_r0_2 = func_0206eab8();
    M2C_FIELD(temp_r0_2, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0_2, s32 *, 4) * M2C_FIELD(temp_r0_2, u32 *, 0)) + M2C_FIELD(temp_r0_2, s32 *, 8));
    if (temp_r4 == 0) {
        var_r1 = (u16) ((u32) M2C_FIELD(temp_r0_2, u32 *, 0) >> 0x10);
    } else {
        var_r1 = (u16) ((u32) (((u32) M2C_FIELD(temp_r0_2, u32 *, 0) >> 0x10) * temp_r4) >> 0x10);
    }
    func_02077650(M2C_FIELD(arg0, void **, 0x28), var_r1 << 0xC);
}
