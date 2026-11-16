/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

u32 func_02000d54(M2C_UNK, M2C_UNK);                /* extern */

u16 func_02065170(M2C_UNK arg0, M2C_UNK arg1) {
    u32 temp_r0;

    temp_r0 = func_02000d54(arg1, arg0);
    if (temp_r0 < 0x7800U) {
        return 0xF800U;
    }
    if (temp_r0 > 0x8800U) {
        return 0x800U;
    }
    return (u16) (temp_r0 + 0x8000);
}
