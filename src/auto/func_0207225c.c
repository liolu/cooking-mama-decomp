/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202b024(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_020383b0();                                /* extern */

void func_0207225c(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                      = func_0202f368();
    temp_r0                      = func_0202b024(4, func_020383b0(), 0, 2, 0);
    M2C_FIELD(temp_r0, s16 *, 6) = (s16) ((M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s32 *, 0x48) * 0x28) + 0x20);
    M2C_FIELD(temp_r0, s16 *, 8) = 0xC0;
    func_0202ec14(0xA);
}
