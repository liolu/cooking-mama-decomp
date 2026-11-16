/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0203773c(M2C_UNK);                     /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
extern void *data_0210ceb0;
extern M2C_UNK func_0203a474;

void func_0203a4ac(void) {
    M2C_UNK var_r0;
    s16 temp_ip;
    void *temp_r0;

    temp_r0 = func_0202f368();
    temp_ip = M2C_FIELD(temp_r0, s16 *, 0x30);
    if ((s32) temp_ip >= (s32) M2C_FIELD(temp_r0, s16 *, 0x2E)) {
        var_r0 = 0;
    } else if ((s32) temp_ip > 1) {
        var_r0 = 1;
    } else {
        var_r0 = 2;
    }
    if (M2C_FIELD(data_0210ceb0, s16 *, 0x16) == 4) {
        M2C_FIELD(data_0210ceb0, s8 *, 0x32)  = (s8) temp_ip;
        M2C_FIELD(data_0210ceb0, s16 *, 0x34) = 1;
    }
    func_0203773c(var_r0);
    func_02038384(0);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203a474;
}
