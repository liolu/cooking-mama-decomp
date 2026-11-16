/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0206d914(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02113380;
extern M2C_UNK func_0206abe4;

void func_0206ac34(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_0206d914(0, &data_02113380, 0xE0, 0x20, 4);
    *temp_r4 = &func_0206abe4;
}
