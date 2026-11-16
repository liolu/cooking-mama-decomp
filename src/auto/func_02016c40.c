/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200f1ec(M2C_UNK *);                       /* extern */
extern void *data_020c6274;
extern M2C_UNK func_02016ca4;

void func_02016c40(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
        return;
    }
    M2C_FIELD(data_020c6274, s16 *, 8) = 0;
    if (func_0200f1ec(&func_02016ca4) != 2) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
    }
}
