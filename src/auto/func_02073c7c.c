/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006e9c(s32, M2C_UNK, s32, M2C_UNK);  /* extern */
s32 func_0200734c();                                /* extern */
M2C_UNK func_0200738c(s32);                         /* extern */
M2C_UNK func_0200741c(M2C_UNK);                     /* extern */
M2C_UNK func_0200b224(void *);                      /* extern */
M2C_UNK func_0200b23c(void *);                      /* extern */
M2C_UNK func_02073c48(void *);                      /* extern */

void func_02073c7c(void *arg0) {
    s32 temp_r5;

    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F) != 0) {
        func_02006e9c(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
        func_0200b23c(arg0 + 8);
        func_0200b224(arg0 + 0x14);
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~2);
        temp_r5                      = func_0200734c();
        func_0200741c(1);
        func_0200738c(temp_r5);
    }
    func_02073c48(arg0);
}
