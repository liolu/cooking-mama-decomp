/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202c03c(s32, s32);                    /* extern */
void *func_0202f368();                              /* extern */

void func_0206add4(void) {
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 var_r2;
    u32 temp_r0_2;
    void *temp_r0;
    void *temp_r1;

    temp_r0 = func_0202f368();
    temp_r1 = M2C_FIELD(temp_r0, void **, 0x24);
    var_r2  = 0;
    if ((s32) M2C_FIELD(temp_r1, s32 *, 0x28) < 3) {
        return;
    }
    if (M2C_FIELD(temp_r1, s32 *, 0x38) == 0) {
        return;
    }
    temp_r0_2 = M2C_FIELD(temp_r1, u32 *, 0x2C);
    switch (temp_r0_2) {
        default:
            break;
        case 0:
            if (M2C_FIELD(temp_r0, s32 *, 0x28) == 0xA) {
                var_r2 = 1;
            }
            break;
        case 1:
            temp_r0_3 = M2C_FIELD(temp_r0, s32 *, 0x28);
            if ((temp_r0_3 == 9) || (temp_r0_3 == 3) || (temp_r0_3 == 0xB)) {
                var_r2 = 1;
            }
            break;
        case 2:
            temp_r0_4 = M2C_FIELD(temp_r0, s32 *, 0x28);
            if ((temp_r0_4 == 8) || (temp_r0_4 == 2) || (temp_r0_4 == 0) || (temp_r0_4 == 4)) {
                var_r2 = 1;
            }
            break;
        case 3:
            temp_r0_5 = M2C_FIELD(temp_r0, s32 *, 0x28);
            if ((temp_r0_5 == 7) || (temp_r0_5 == 1) || (temp_r0_5 == 5)) {
                var_r2 = 1;
            }
            break;
        case 4:
            if (M2C_FIELD(temp_r0, s32 *, 0x28) == 6) {
                var_r2 = 1;
            }
            break;
    }
    if (var_r2 == 0) {
        return;
    }
    func_0202c03c(M2C_FIELD(temp_r0, s32 *, 0x1C), (M2C_FIELD(temp_r1, s32 *, 0x30) * 3) + 6);
    func_0202c03c(M2C_FIELD(temp_r0, s32 *, 0x20), (M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x24), s32 *, 0x30) * 3) + 7);
    M2C_FIELD(temp_r0, void (**)(), 0) = func_0206add4;
}
