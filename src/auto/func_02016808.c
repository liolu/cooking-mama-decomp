/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0206eab8();                              /* extern */
extern u16 data_020c626c;

u16 func_02016808(void) {
    s32 temp_r4;
    u16 temp_r1;
    u16 var_r1;
    void *temp_r0;

    if (data_020c626c == 0) {
        temp_r4 = *(s32 *) 0x027FFC3C;
        temp_r0 = func_0206eab8();
        M2C_FIELD(temp_r0, u32 *, 0) =
            (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
        temp_r1 = (u16) temp_r4;
        if (temp_r1 == 0) {
            var_r1 = (u16) ((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10);
        } else {
            var_r1 = (u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * temp_r1) >> 0x10);
        }
        data_020c626c = var_r1;
    }
    data_020c626c += 1;
    return data_020c626c;
}
