/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0207b760();                            /* extern */
extern s32 data_02116548;
extern void *data_0211654c;

void func_02079268(void) {
    s32 temp_r3;

    *(s32 *) 0x04000448 = 1;
    temp_r3             = M2C_FIELD(data_0211654c, s32 *, 0x7C);
    if (temp_r3 != 0) {
        if (temp_r3 & 1) {
            data_02116548 = 0;
        }
        if (temp_r3 & 2) {
            M2C_FIELD(data_0211654c, s32 *, 0x74) = 0;
            func_0207b760();
        }
        M2C_FIELD(data_0211654c, s32 *, 0x7C) = 0;
    }
    data_0211654c = NULL;
}
