/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020056cc();                   /* extern */
M2C_UNK func_0200573c();                   /* extern */
M2C_UNK func_02073d70();                      /* extern */
M2C_UNK func_02075b84();                      /* extern */
extern s32 data_02114aa8;
extern M2C_UNK data_02114f80;

void func_02075bf0(void *arg0) {
    func_0200573c(&data_02114f80);
    if (data_02114aa8 != 0) {
        func_0200573c(data_02114aa8 + 0x4C8);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1E) >> 0x1F) != 0) {
        func_02073d70(arg0);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(arg0, M2C_UNK(**)(void *), 0x16C)(arg0);
    }
    func_02075b84(arg0);
    func_020056cc(&data_02114f80);
    if (data_02114aa8 == 0) {
        return;
    }
    func_020056cc(data_02114aa8 + 0x4C8);
}
