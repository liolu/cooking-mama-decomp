/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200f234(M2C_UNK *);                       /* extern */
extern void *data_020c6274;
extern M2C_UNK func_02016cf8;

void func_02016f28(void *arg0) {
    u32 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
        return;
    }
    temp_r0 = M2C_FIELD(data_020c6274, s32 *, 4) - 0xD;
    switch (temp_r0) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (func_0200f234(&func_02016cf8) != 2) {
                M2C_FIELD(data_020c6274, s32 *, 0) = 4;
            }
            return;
        default:
            return;
    }
}
