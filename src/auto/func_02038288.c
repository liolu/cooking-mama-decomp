/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK **func_0202f368();                          /* extern */
extern s16 data_0210c8e8;
extern s32 data_0210c8fc;
extern M2C_UNK data_0210c900;
extern M2C_UNK data_0210c9e8;
extern M2C_UNK func_0203813c;

void func_02038288(void) {
    M2C_UNK **temp_r4;
    s32 temp_r0;

    temp_r4                             = func_0202f368();
    temp_r0                             = func_0202b024(4, &data_0210c9e8, 1, -1, 3);
    M2C_FIELD(&data_0210c900, s32 *, 4) = temp_r0;
    func_0202b014(temp_r0, 0x48, 0x48, 0);
    data_0210c8fc |= 1;
    data_0210c8e8 = 0;
    *temp_r4      = &func_0203813c;
}
