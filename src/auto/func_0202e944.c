/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020793b4(void *);                      /* extern */
M2C_UNK func_02079414(M2C_UNK, void *);             /* extern */
M2C_UNK func_02079424(M2C_UNK);                     /* extern */
extern M2C_UNK func_0202ea34;

void func_0202e944(M2C_UNK arg0, void *arg1) {
    func_020793b4(arg1);
    M2C_FIELD(arg1, s32 *, 0)         = 0;
    M2C_FIELD(arg1, s32 *, 4)         = 0;
    M2C_FIELD(arg1, s32 *, 8)         = 0x100000;
    M2C_FIELD(arg1, s32 *, 0xC)       = 0xC0000;
    M2C_FIELD(arg1, s32 *, 0x28)      = 0;
    M2C_FIELD(arg1, s32 *, 0x2C)      = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x34) = &func_0202ea34;
    M2C_FIELD(arg1, s32 *, 0x14)      = 0;
    func_02079424(arg0);
    func_02079414(arg0, arg1);
}
