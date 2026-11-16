/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200ed00(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_0200f144(M2C_UNK *);                       /* extern */
extern void *data_020c6274;
extern M2C_UNK data_020c63c0;
extern M2C_UNK func_02016978;
extern M2C_UNK func_02016c40;

void func_02016898(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(data_020c6274, s32 *, 4) = 1;
        M2C_FIELD(data_020c6274, s32 *, 0) = 5;
        if (func_0200f144(&func_02016c40) != 2) {
            M2C_FIELD(data_020c6274, s32 *, 0) = 4;
        }
        return;
    }
    if (M2C_FIELD(data_020c6274, s32 *, 4) != 0xE) {
        return;
    }
    if (func_0200ed00(&func_02016978, &data_020c63c0, 0, 1, 0) == 2) {
        return;
    }
    M2C_FIELD(data_020c6274, s32 *, 4) = 1;
    M2C_FIELD(data_020c6274, s32 *, 0) = 5;
    if (func_0200f144(&func_02016c40) != 2) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
    }
}
