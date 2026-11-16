/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
extern void *data_0210d518;
extern M2C_UNK func_0203cab4;

void func_0203cae8(void) {
    M2C_UNK var_r0;
    s16 temp_r1;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_r1 = M2C_FIELD(temp_r0, s16 *, 0x6A);
    if ((s32) temp_r1 >= (s32) M2C_FIELD(temp_r0, s16 *, 0x30)) {
        if ((s32) (M2C_FIELD(data_0210d518, u8 *, 0x31) - 1) <= (s32) M2C_FIELD(data_0210d518, u8 *, 0x30)) {
            M2C_FIELD(data_0210d518, s16 *, 0x34) = 2;
        }
        var_r0 = 0;
    } else if ((s32) temp_r1 >= 2) {
        var_r0                                = 1;
        M2C_FIELD(data_0210d518, s16 *, 0x34) = 1;
    } else {
        var_r0                                = 2;
        M2C_FIELD(data_0210d518, s16 *, 0x34) = 1;
    }
    func_0203773c(var_r0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203cab4;
}
