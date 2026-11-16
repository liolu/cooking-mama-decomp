/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202bfe4(s32, s32);                    /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_02111cec;

void func_0205a6c0(void) {
    s32 temp_r2;
    s32 var_r1;
    void *temp_r0;

    temp_r0 = func_0202f368();
    var_r1  = 0;
    if (M2C_FIELD(temp_r0, s32 *, 0x30) == 1) {
        if (data_02111cec == 0x11) {
            return;
        }
        var_r1 = 3;
        goto block_4;
    }
block_4:
    temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x34);
    if (temp_r2 >= 8) {
        if (temp_r2 < 0x10) {
            var_r1 += 1;
        } else {
            var_r1 += 2;
        }
    }
    func_0202bfe4(M2C_FIELD(temp_r0, s32 *, 0x1C), var_r1);
}
