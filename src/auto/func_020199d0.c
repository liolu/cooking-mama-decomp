/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 *func_0201f4a0(M2C_UNK);                        /* extern */
M2C_UNK func_0202dcb0(s32, s32);                    /* extern */
extern M2C_UNK data_020d3320;

void func_020199d0(void) {
    func_0202dcb0(*func_0201f4a0(0xD), M2C_FIELD(&data_020d3320, s32 *, 0));
    func_0202dcb0(*func_0201f4a0(0xE), M2C_FIELD(&data_020d3320, s32 *, 4));
}
