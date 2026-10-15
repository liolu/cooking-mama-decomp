#include "m2c.h"

M2C_UNK func_0202cc9c(void *);                      /* extern */
M2C_UNK func_0206eaec();                            /* extern */

void func_0202e5e0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        func_0202cc9c(arg0 + 4);
    }
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        func_0202cc9c(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        func_0202cc9c(arg0 + 8);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
        func_0202cc9c(arg0 + 0xC);
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        func_0202cc9c(arg0 + 0x10);
    }
    if (M2C_FIELD(arg0, s32 *, 0x64) != 0) {
        func_0206eaec();
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x60) == 0) {
        return;
    }
    func_0206eaec();
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}
