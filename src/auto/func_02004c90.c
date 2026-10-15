/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02004c4c(s32);                         /* extern */
M2C_UNK func_02005188(void *, M2C_UNK (*)(s32));    /* extern */
M2C_UNK func_02005238(void *);                      /* extern */
extern s32 data_020c2bfc;

void func_02004c90(void *arg0, s32 arg1) {
    if (data_020c2bfc != 0) {
        func_02005188(arg0, func_02004c4c);
        M2C_FIELD(arg0, s32 *, 4)    = arg1;
        M2C_FIELD(arg0, s32 *, 0)    = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x80);
        M2C_FIELD(arg0, s32 *, 0x64) = 1;
        func_02005238(arg0);
        return;
    }
    func_02004c4c(arg1);
}
