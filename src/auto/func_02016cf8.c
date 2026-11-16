/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200ebac(M2C_UNK *);                       /* extern */
s32 func_0200ed00(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_0200ee24(M2C_UNK *, M2C_UNK *);            /* extern */
s32 func_0200f144(M2C_UNK *);                       /* extern */
M2C_UNK func_02016e8c();                            /* extern */
M2C_UNK func_02017b34();                            /* extern */
extern void *data_020c6274;
extern M2C_UNK data_020c62c0;
extern M2C_UNK data_020c63c0;
extern M2C_UNK func_02016978;
extern M2C_UNK func_02016c40;
extern M2C_UNK func_02016fa8;
extern M2C_UNK func_02017b00;

void func_02016cf8(void *arg0) {
    u32 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(data_020c6274, s32 *, 0) = 4;
        return;
    }
    temp_r0 = M2C_FIELD(data_020c6274, s32 *, 4) - 0xD;
    switch (temp_r0) {
        case 0:
        case 2:
            func_02017b34();
            return;
        case 1:
            if (func_0200ebac(&func_02017b00) != 0) {
                M2C_FIELD(data_020c6274, s32 *, 0) = 4;
                return;
            }
            func_02016e8c();
            if (func_0200ee24(&func_02016fa8, &data_020c62c0) == 2) {
                M2C_FIELD(data_020c6274, s32 *, 0) = 6;
                return;
            }
            M2C_FIELD(data_020c6274, s32 *, 4) = 1;
            M2C_FIELD(data_020c6274, s32 *, 0) = 5;
            if (func_0200f144(&func_02016c40) != 2) {
                M2C_FIELD(data_020c6274, s32 *, 0) = 4;
            }
            return;
        case 3:
            if (func_0200ebac(&func_02017b00) != 0) {
                M2C_FIELD(data_020c6274, s32 *, 0) = 4;
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
            return;
        default:
            return;
    }
}
