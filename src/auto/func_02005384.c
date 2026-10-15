/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200527c();                                /* extern */
s32 func_020052b0();                                /* extern */
s32 func_020053fc();                                /* extern */
extern s32 data_02084e98;

s32 func_02005384(void) {
    s32 temp_r4;
    s32 var_r2;

    if (data_02084e98 == -1) {
        temp_r4 = func_020052b0();
        if (func_020053fc() != 0) {
            var_r2 = temp_r4 | 0x10000000;
        } else if (func_0200527c() != 0) {
            var_r2 = temp_r4 | 0x40000000;
        } else if (temp_r4 & 0x01000000) {
            var_r2 = temp_r4 | 0x20000000;
        } else {
            var_r2 = temp_r4 | 0x80000000;
        }
        data_02084e98 = var_r2 | *(u16 *) 0x027FFFFA;
    }
    return data_02084e98;
}
