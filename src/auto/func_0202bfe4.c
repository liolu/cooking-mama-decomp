/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b33c(void *);                      /* extern */
s32 func_0202b364();                                /* extern */
M2C_UNK func_0202bf38(void *, M2C_UNK);             /* extern */
M2C_UNK func_020789d0(s32, s32, s32);               /* extern */

void func_0202bfe4(void *arg0, M2C_UNK arg1) {
    void *temp_r2;

    if (M2C_FIELD(arg0, s32 *, 0x28) != 0) {
        func_0202b33c(arg0 + 0x28);
    }
    M2C_FIELD(arg0, s32 *, 0x28) = func_0202b364();
    temp_r2                      = M2C_FIELD(arg0, void **, 0x20);
    func_020789d0(M2C_FIELD(arg0, s32 *, 0x28), M2C_FIELD(M2C_FIELD(temp_r2, void **, 0x24), s32 *, 4),
                  M2C_FIELD(temp_r2, s32 *, 0x20));
    func_0202bf38(arg0, arg1);
}
