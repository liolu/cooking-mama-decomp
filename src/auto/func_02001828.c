#include "m2c.h"

M2C_UNK func_02002130();                            /* extern */
extern u16 data_020c2b48;

void func_02001828(s32 arg0) {
    data_020c2b48 |= arg0;
    func_02002130(arg0);
}
