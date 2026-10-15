/* compiler: 1.2/sp2p3  */
#include "m2c.h"

u16 *func_0200e868(M2C_UNK, u16);                   /* extern */
M2C_UNK func_020101d0(u16 *, u16);                  /* extern */
extern s32 data_020c6080;
extern s32 data_020c613c;

void func_02010118(M2C_UNK arg0) {
    s32 temp_r5;
    u16 *temp_r0;
    u16 temp_r1;
    u16 var_r6;
    u16 var_r6_2;

    var_r6 = 0;
    do {
        temp_r5 = (var_r6 * 0x5D4) + data_020c613c;
        if (M2C_FIELD(temp_r5, u8 *, 0x1D52) != 0) {
            M2C_FIELD(temp_r5, s16 *, 0x1D4A) = 0;
        }
        var_r6 += 1;
    } while ((u32) var_r6 < 0x10U);
    data_020c6080 = 0;
    var_r6_2      = 1;
    do {
        temp_r0 = func_0200e868(arg0, var_r6_2);
        if (temp_r0 != NULL) {
            temp_r1 = *temp_r0;
            if ((temp_r1 != 0xFFFF) && (temp_r1 != 0)) {
                func_020101d0(temp_r0, var_r6_2);
            }
        }
        var_r6_2 += 1;
    } while ((u32) var_r6_2 <= 0xFU);
}
