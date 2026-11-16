/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02112598;
extern M2C_UNK func_02019c34;

void func_02061814(void) {
    s32 var_r0;
    s32 var_r3;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = func_020197fc();
    if (M2C_FIELD(temp_r4, s32 *, 0x34) == 0) {
        if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
            M2C_FIELD(temp_r0, u8 *, 0x32) = (u8) M2C_FIELD(temp_r0, u8 *, 0x30);
            var_r3                         = M2C_FIELD(temp_r4, s32 *, 0x38) - M2C_FIELD(temp_r4, s32 *, 0x3C);
            if (var_r3 < 0) {
                var_r3 = 0 - var_r3;
            }
            if (var_r3 <= 0x14) {
                if (M2C_FIELD(temp_r0, u8 *, 0x30) == (M2C_FIELD(temp_r0, u8 *, 0x31) - 1)) {
                    M2C_FIELD(temp_r0, s16 *, 0x34) = 2;
                }
                if (var_r3 == 0) {
                    func_02019818(0);
                } else {
                    func_02019818(1);
                }
            } else {
                M2C_FIELD(temp_r0, s16 *, 0x34) = 1;
                func_02019818(2);
            }
        } else {
            var_r0 = M2C_FIELD(temp_r4, s32 *, 0x38) - M2C_FIELD(temp_r4, s32 *, 0x3C);
            if (var_r0 < 0) {
                var_r0 = 0 - var_r0;
            }
            if (var_r0 == 0) {
                func_02019818(0);
            } else if (var_r0 <= 0x14) {
                func_02019818(1);
            } else {
                func_02019818(2);
            }
        }
    }
    M2C_FIELD(temp_r4, s32 *, 0x34) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x34) + 1);
    if (func_02019808() == 3) {
        data_02112598                   = &func_02019c34;
        M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
    }
}
