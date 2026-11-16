/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0202e6ac(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02073a90(M2C_UNK *);                   /* extern */
M2C_UNK func_0207468c(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK func_020748f4(s32);                         /* extern */
s32 func_02074a98(s32, M2C_UNK);                    /* extern */
M2C_UNK func_020756fc(M2C_UNK, s32);                /* extern */
M2C_UNK func_020759e8(s32);                         /* extern */
extern s16 data_020afab4;
extern s32 data_020afab8;
extern M2C_UNK data_02100ba4;
extern s32 data_02100ba8;
extern M2C_UNK data_02100bac;
extern s32 data_02100bb0;
extern M2C_UNK data_02100c04;

void func_0202ee70(void) {
    s32 temp_r0;
    s32 temp_r0_2;

    data_020afab4 = 0x3E7;
    temp_r0       = func_0202e6ac(0x20000, 0, -0x10);
    data_02100bb0 = temp_r0;
    temp_r0_2     = func_02074a98(temp_r0, 0x20000);
    data_02100ba8 = temp_r0_2;
    func_0207468c(&data_02100c04, data_020afab8, temp_r0_2, 0);
    func_020759e8(data_02100ba8);
    func_020756fc(9, data_02100ba8);
    func_020748f4(data_02100ba8);
    func_02073a90(&data_02100bac);
    func_02073a90(&data_02100ba4);
}
