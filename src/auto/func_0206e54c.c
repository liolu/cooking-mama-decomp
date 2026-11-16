/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s8 *func_0200af20();                                /* extern */
extern s8 data_02113960;
extern s32 data_02113968;

void func_0206e54c(void) {
    s8 *temp_r0;

    if ((s32) data_02113968 < 0x1E) {
        data_02113968 += 1;
        data_02113960 = 0;
        return;
    }
    temp_r0 = func_0200af20();
    if (temp_r0 == NULL) {
        data_02113960 = 0;
        return;
    }
    data_02113960 = *temp_r0;
}
