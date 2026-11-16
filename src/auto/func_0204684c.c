/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern M2C_UNK func_02046818;

void func_0204684c(void) {
    M2C_UNK var_r0;
    s16 temp_r1;
    s16 temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_r2 = M2C_FIELD(temp_r0, s16 *, 0x26);
    if ((s32) temp_r2 >= 7) {
        var_r0 = 2;
    } else {
        temp_r1 = M2C_FIELD(temp_r0, s16 *, 0x24);
        if (((s32) temp_r2 <= (s32) (temp_r1 - 4)) || ((s32) (temp_r1 + 4) <= (s32) temp_r2)) {
            var_r0 = 2;
        } else if (((s32) temp_r2 <= (s32) (temp_r1 - 1)) || ((s32) (temp_r1 + 1) <= (s32) temp_r2)) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
    }
    func_0203773c(var_r0);
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02046818;
}
