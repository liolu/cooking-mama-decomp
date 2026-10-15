/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020070e8();                                /* extern */
s32 func_02007130();                                /* extern */
M2C_UNK func_02007188();                            /* extern */
s32 func_02007258(s32);                             /* extern */
M2C_UNK func_0200741c(M2C_UNK);                     /* extern */
s32 func_020076c0(M2C_UNK);                         /* extern */

s32 func_02007624(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;

    if (func_020070e8() == 0) {
        return 0;
    }
    temp_r0_3 = func_02007130();
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_4 = arg0 & 1;
    if (temp_r0_4 == 0) {
        return 0;
    }
    if (func_02007258(temp_r0_4) > 0) {
        do {

        } while (func_020076c0(0) != 0);
        temp_r0_2 = func_02007130();
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        goto block_12;
    }
    func_0200741c(1);
block_12:
    func_02007188();
    do {
        func_020076c0(1);
        temp_r0 = func_02007130();
    } while (temp_r0 == 0);
    return temp_r0;
}
