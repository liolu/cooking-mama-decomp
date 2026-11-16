/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0206e764();                            /* extern */
extern M2C_UNK data_0210fad8;
extern M2C_UNK func_02049e3c;

void func_0204a1a0(void) {
    M2C_UNK **temp_r4;
    s16 temp_r1;
    s16 temp_r2;

    temp_r4 = func_0202f368();
    func_0206e764();
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0xD0), s16 *, 8);
    if ((s32) temp_r1 > 0x29) {
        M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0xD0), s16 *, 8) = (s16) (temp_r1 - 5);
        M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 4), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 4), s16 *, 8) - 5);
    }
    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8);
    if ((s32) temp_r2 > -0x1E) {
        M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8) = (s16) (temp_r2 - 0xA);
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8) > -0x1E) {
            return;
        }
        func_0202ec14(0x24);
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8)   = -0x64;
    M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 0xA) = 0;
    *temp_r4                                                     = &func_02049e3c;
}
