/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK *data_02111f68;
extern M2C_UNK func_02019c34;

void func_0205ddac(void) {
    s32 temp_r0_2;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = func_020197fc();
    if (M2C_FIELD(temp_r4, u16 *, 0x4E) == 0) {
        if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
            M2C_FIELD(temp_r0, s8 *, 0x32)  = (s8) M2C_FIELD(temp_r4, s32 *, 0x40);
            M2C_FIELD(temp_r0, s16 *, 0x34) = 2;
            func_02019818(0);
        } else {
            temp_r0_2 = M2C_FIELD(temp_r4, s32 *, 0x40);
            if (temp_r0_2 == 5) {
                func_02019818(0);
            } else if (temp_r0_2 >= 4) {
                func_02019818(1);
            } else {
                func_02019818(2);
            }
        }
    }
    M2C_FIELD(temp_r4, u16 *, 0x4E) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x4E) + 1);
    if (func_02019808() == 3) {
        data_02111f68                   = &func_02019c34;
        M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
    }
}
