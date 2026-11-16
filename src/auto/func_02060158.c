/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
extern s32 data_02112250;
extern M2C_UNK func_0202f834;

void func_02060158(void) {
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (data_02112250 != 0) {
        M2C_FIELD(temp_r0, s32 *, 0x1C)   = (s32) data_02112250;
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0202f834;
        data_02112250                     = 0;
    }
}
