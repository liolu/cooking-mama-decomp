#include "m2c.h"

M2C_UNK func_0202ed98(M2C_UNK);                     /* extern */
M2C_UNK func_02073a10(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02074808(s32, M2C_UNK);                /* extern */
M2C_UNK func_020756c4(u32, s32);                    /* extern */
M2C_UNK func_02075994(M2C_UNK *, u32);              /* extern */
extern u16 data_020afab4;
extern s32 data_02100ba8;
extern M2C_UNK data_02100bac;

void func_0202edb0(u32 arg0) {
    if (data_020afab4 == arg0) {
        return;
    }
    if (arg0 >= 9U) {
        return;
    }
    func_02074808(data_02100ba8, 1);
    func_020756c4(arg0, data_02100ba8);
    func_02075994(&data_02100bac, arg0);
    func_02073a10(&data_02100bac, 0x7F);
    func_0202ed98(0x100);
    data_020afab4 = (u16) arg0;
}
