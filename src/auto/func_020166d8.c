/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200f144(M2C_UNK *);                       /* extern */
extern void *data_020c6274;
extern M2C_UNK func_02016c40;

void func_020166d8(void) {
    if (data_020c6274 == NULL) {
        return;
    }
    M2C_FIELD(data_020c6274, s32 *, 0) = 5;
    M2C_FIELD(data_020c6274, s32 *, 4) = 1;
    if (func_0200f144(&func_02016c40) != 2) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
    }
}
