/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_02113ddc;
extern M2C_UNK *data_02113de0;
extern M2C_UNK func_02019c34;

void func_02072848(void) {
    s32 temp_r2;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = func_020197fc();
    if (M2C_FIELD(temp_r4, s32 *, 0x50) == 0) {
        if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
            M2C_FIELD(temp_r0, u8 *, 0x32) = (u8) M2C_FIELD(temp_r0, u8 *, 0x30);
            if (M2C_FIELD(temp_r4, s32 *, 0x44) == data_02113ddc) {
                if (M2C_FIELD(temp_r0, u8 *, 0x30) == (M2C_FIELD(temp_r0, u8 *, 0x31) - 1)) {
                    M2C_FIELD(temp_r0, s16 *, 0x34) = 2;
                }
                func_02019818(0);
            } else {
                M2C_FIELD(temp_r0, s16 *, 0x34) = 1;
                func_02019818(2);
            }
        } else {
            temp_r2 = M2C_FIELD(temp_r4, s32 *, 0x44);
            if ((temp_r2 == data_02113ddc) && (M2C_FIELD(temp_r4, s32 *, 0x48) == 0)) {
                func_02019818(0);
            } else if (temp_r2 == data_02113ddc) {
                func_02019818(1);
            } else {
                func_02019818(2);
            }
        }
    }
    M2C_FIELD(temp_r4, s32 *, 0x50) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x50) + 1);
    if (func_02019808() == 3) {
        data_02113de0                   = &func_02019c34;
        M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
    }
}
