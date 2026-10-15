/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02002b08();                            /* extern */
M2C_UNK func_02002b54(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_02002bc8();                            /* extern */
M2C_UNK func_02002cd0();                            /* extern */
M2C_UNK func_02002d28(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_02002d9c();                            /* extern */
M2C_UNK func_02003178(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_020031e0(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_0200330c();                            /* extern */
M2C_UNK func_02003364(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_020033d8();                            /* extern */
M2C_UNK func_02005850(s32, s32);                    /* extern */
M2C_UNK func_0207885c(void *, s32, M2C_UNK);        /* extern */

void func_020780bc(void *arg0, M2C_UNK arg1, s32 arg2, void *arg3) {
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, volatile s32 *, 0xC);
    temp_r4 = M2C_FIELD(arg0, volatile s32 *, 8);
    func_02005850(temp_r5, temp_r4);
    switch (arg2) {                                 /* irregular */
        case 1:
            if (M2C_FIELD(arg0, volatile s32 *, 4) != 0) {
                func_02002d9c();
                func_02002d28(temp_r5, arg1, temp_r4);
                func_02002cd0();
            } else {
                func_020031e0(temp_r5, arg1, temp_r4);
            }
            break;
        case 2:
            if (M2C_FIELD(arg0, volatile s32 *, 4) != 0) {
                func_02002bc8();
                func_02002b54(temp_r5, arg1, temp_r4);
                func_02002b08();
            } else {
                func_02003178(temp_r5, arg1, temp_r4);
            }
            break;
        case 0:
            func_020033d8();
            func_02003364(temp_r5, arg1, temp_r4);
            func_0200330c();
            break;
    }
    M2C_FIELD(arg3, volatile s32 *, 0) = (s32) M2C_FIELD(arg0, volatile s32 *, 0);
    M2C_FIELD(arg3, volatile s32 *, 4) = (s32) M2C_FIELD(arg0, volatile s32 *, 4);
    func_0207885c(arg3, arg2, arg1);
}
