/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02074a7c();                            /* extern */
M2C_UNK func_02075f10(s32, void *);                 /* extern */
extern M2C_UNK data_021144e4;

void func_0207329c(void *arg0) {
    void *temp_r1;

    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        return;
    }
    func_02074a7c();
    temp_r1 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, s32 *, 8) = 0;
        return;
    }
    func_02075f10((M2C_FIELD(arg0, s32 *, 0x10) * 0x24) + (s32) &data_021144e4 + 0xC, arg0);
}
