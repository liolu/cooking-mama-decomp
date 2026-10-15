/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02075ac8();           /* extern */
M2C_UNK func_02075b3c();                            /* extern */
M2C_UNK func_02075c94();                      /* extern */
extern s32 data_02114aa8;
extern M2C_UNK data_02114f98;

void func_02075b84(void *arg0) {
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1F) >> 0x1F) == 0) {
        return;
    }
    func_02075b3c(arg0);
    M2C_FIELD(arg0, M2C_UNK(**)(void *), 0x164)(arg0);
    func_02075ac8(&data_02114f98, arg0);
    if (data_02114aa8 != 0) {
        func_02075ac8(data_02114aa8 + 0x4E0, arg0);
    }
    func_02075c94(arg0);
}
