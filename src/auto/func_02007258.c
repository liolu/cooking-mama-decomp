/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02007278();                                /* extern */
s32 func_020072b8();                                /* extern */

s32 func_02007258(void) {
    s32 temp_r4;

    temp_r4 = func_020072b8();
    return (0x100 - temp_r4) - func_02007278();
}
