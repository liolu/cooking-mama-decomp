/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02001568();                                /* extern */
extern s32 data_020c2b68;
extern s32 data_020c2b6c;

void func_02002d9c(void) {
    s32 temp_r0;

    temp_r0       = func_02001568();
    data_020c2b6c = temp_r0;
    switch (temp_r0) {                              /* irregular */
        case 0x0:
            return;
        case 0x40:
            data_020c2b68 = 0x06894000;
            return;
        case 0x20:
            data_020c2b68 = 0x06890000;
            return;
    }
}
