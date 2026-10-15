/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02004ae4();                      /* extern */
M2C_UNK func_02004d2c(); /* extern */
s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8();                         /* extern */
M2C_UNK func_020147a4();                         /* extern */
extern void *data_020c6160;
extern M2C_UNK func_0201485c;

void func_020147d4(void *arg0, s32 arg1) {
    s32 temp_ip;
    s32 temp_r4;

    temp_r4 = func_02006194();
    if (data_020c6160 == NULL) {
        data_020c6160 = arg0;
        func_020147a4(arg0 + 0xC4);
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        temp_ip                      = (arg1 - 0xE4) & ~3;
        func_02004d2c(arg0, &func_0201485c, arg0, arg0 + 0xE4 + temp_ip, temp_ip, 0);
        func_02004ae4(arg0);
    }
    func_020061a8(temp_r4);
}
