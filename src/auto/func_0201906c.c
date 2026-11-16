/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020195ac(s32);                           /* extern */
void *func_020197fc();                              /* extern */
extern s32 data_02089748;

s32 func_0201906c(s32 arg0, s32 arg1) {
    s32 var_r4;
    s32 var_r5;
    void *temp_r0;
    void *var_r0;

    var_r4  = 1;
    temp_r0 = func_020197fc();
    var_r0  = func_020195ac(M2C_FIELD((M2C_FIELD(temp_r0, s32 *, 0x24) + (arg0 * 4)), s32 *, 0x18));
    if (arg1 == 0) {
        if (M2C_FIELD((M2C_FIELD(temp_r0, s32 *, 0x24) + ((arg0 + 1) * 4)), s32 *, 0x18) != 0) {
            return 1;
        }
        goto block_4;
    }
    var_r0 = func_020195ac(arg1);
block_4:
    var_r5 = 0;
    if (data_02089748 != -1) {
    loop_6:
        if (M2C_FIELD(var_r0, s32 *, 4) == (&data_02089748)[var_r5]) {
            var_r4 = 0;
        } else {
            var_r5 += 1;
            if ((&data_02089748)[var_r5] != -1) {
                goto loop_6;
            }
        }
    }
    return var_r4;
}
