/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02001540();                                /* extern */
extern M2C_UNK data_02080640;
extern s32 data_020c2b84;
extern s32 data_020c2b88;

void func_020033d8(void) {
    s32 temp_r0;

    temp_r0       = func_02001540();
    data_020c2b88 = temp_r0;
    data_020c2b84 = *((u16 *) ((s8 *) &data_02080640 + ((temp_r0 >> 4) * 2))) << 0xC;
}
