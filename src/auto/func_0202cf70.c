/* compiler: 1.2/sp2p3  */
#include "m2c.h"

u8 func_0202cf70(u8 *arg0) {
    u8 temp_r0;

    temp_r0 = *arg0;
    if (((u32) temp_r0 >= 0x20U) && ((u32) temp_r0 <= 0x7FU)) {
        return (u8) (temp_r0 - 0x20);
    }
    if (((u32) temp_r0 >= 0xBFU) && ((u32) temp_r0 <= 0xFCU)) {
        return (u8) ((u8) (temp_r0 - 0xBF) + 0x60);
    }
    return 0x60U;
}
