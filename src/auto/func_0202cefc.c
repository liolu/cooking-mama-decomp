#include "m2c.h"

s32 func_0202cd5c(s32);                             /* extern */
s32 func_0202cdc0();                                /* extern */

s32 func_0202cefc(void) {
    s32 temp_r0;

    temp_r0 = func_0202cdc0();
    if (temp_r0 == 0) {
        return 0;
    }
    do {

    } while (func_0202cd5c(temp_r0) == 0);
    return temp_r0;
}
