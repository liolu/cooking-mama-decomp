/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200ef24(M2C_UNK *);                       /* extern */
s32 func_0200f144(M2C_UNK *);                       /* extern */
extern void *data_020c6274;
extern M2C_UNK func_02016c40;
extern M2C_UNK func_02017434;

void func_02017360(void *arg0) {
    s32 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(data_020c6274, s32 *, 4) = 1;
        M2C_FIELD(data_020c6274, s32 *, 0) = 5;
        if (func_0200f144(&func_02016c40) != 2) {
            M2C_FIELD(data_020c6274, s32 *, 0) = 4;
        }
        return;
    }
    temp_r0 = M2C_FIELD(data_020c6274, s32 *, 4);
    if ((temp_r0 != 0xD) && (temp_r0 != 0xF)) {
        return;
    }
    if (func_0200ef24(&func_02017434) == 2) {
        return;
    }
    M2C_FIELD(data_020c6274, s32 *, 4) = 1;
    M2C_FIELD(data_020c6274, s32 *, 0) = 5;
    if (func_0200f144(&func_02016c40) != 2) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
    }
}
