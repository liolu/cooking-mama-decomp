/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200e150();                                /* extern */

u16 func_0200e83c(void) {
    if (func_0200e150() != 0) {
        return 0x8000U;
    }
    return *(u16 *) 0x027FFCFA;
}
