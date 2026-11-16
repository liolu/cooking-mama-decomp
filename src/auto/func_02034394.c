/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
void *func_0202f564(M2C_UNK *, M2C_UNK);            /* extern */
extern void *data_0210bc68;
extern void *data_0210bc6c;
extern s32 data_0210bc70;
extern M2C_UNK func_020341bc;

void func_02034394(M2C_UNK arg0, s32 arg1) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0       = func_0202b024(1, arg0, 7, -1, 1);
    data_0210bc6c = temp_r0;
    func_0202b014(temp_r0, 0x80, 0x60, 1);
    M2C_FIELD(data_0210bc6c, u16 *, 0xE)  = 0U;
    M2C_FIELD(data_0210bc6c, u16 *, 0xC)  = (u16) M2C_FIELD(data_0210bc6c, u16 *, 0xE);
    data_0210bc70                         = -1;
    temp_r0_2                             = func_0202f564(&func_020341bc, 0x15);
    data_0210bc68                         = temp_r0_2;
    M2C_FIELD(temp_r0_2, s32 *, 0x28)     = arg1;
    M2C_FIELD(data_0210bc68, s16 *, 0x30) = 2;
}
