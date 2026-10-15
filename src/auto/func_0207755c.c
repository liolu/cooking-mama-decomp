/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02077650();                            /* extern */

void func_0207755c(void *arg0) {
    s32 var_r2;
    void *temp_r2;
    void *temp_r2_2;

    if ((s32) M2C_FIELD(arg0, s32 *, 0x10) > 0) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    if ((var_r2 ^ M2C_FIELD(arg0, s32 *, 4)) != 0) {
        temp_r2                   = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(temp_r2, s32 *, 0xC) + (M2C_FIELD(temp_r2, u16 *, 2) * 8));
    } else {
        temp_r2_2                 = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(arg0, s32 *, 0) = (s32) ((M2C_FIELD(temp_r2_2, s32 *, 0xC) + (M2C_FIELD(temp_r2_2, u16 *, 0) * 8)) - 8);
    }
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    func_02077650();
}
