/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern void *data_02110b70;
extern M2C_UNK func_020515d4;

void func_02051618(void) {
    M2C_UNK var_r0;
    s32 temp_ip;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_ip = M2C_FIELD(temp_r0, s32 *, 0x2C);
    if ((temp_ip >= 3) && !(M2C_FIELD(temp_r0, s32 *, 0x24) & 0x40)) {
        var_r0 = 0;
    } else if (temp_ip >= 1) {
        var_r0 = 1;
    } else {
        var_r0 = 2;
    }
    if (M2C_FIELD(data_02110b70, s16 *, 0x16) == 4) {
        M2C_FIELD(data_02110b70, s8 *, 0x32)  = (s8) temp_ip;
        M2C_FIELD(data_02110b70, s16 *, 0x34) = 1;
    }
    func_0203773c(var_r0);
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020515d4;
}
