/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02004858();                            /* extern */
M2C_UNK func_02004890();                            /* extern */
M2C_UNK func_020049cc();                            /* extern */
M2C_UNK func_02004b18(void *);                      /* extern */
M2C_UNK func_02004f90(void *);                      /* extern */
M2C_UNK func_02005070(s32, void *);                 /* extern */
M2C_UNK func_02005684(void *);                      /* extern */
M2C_UNK func_02006440();                            /* extern */
extern void **data_020c2c0c;

void func_02004bec(void) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = *data_020c2c0c;
    func_02004890();
    func_02005684(temp_r4);
    temp_r0 = M2C_FIELD(temp_r4, s32 *, 0x78);
    if (temp_r0 != 0) {
        func_02005070(temp_r0, temp_r4);
    }
    func_02004f90(temp_r4);
    M2C_FIELD(temp_r4, s32 *, 0x64) = 2;
    func_02004b18(temp_r4 + 0x9C);
    func_02004858();
    func_020049cc();
    func_02006440();
}
