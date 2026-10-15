#include "m2c.h"

M2C_UNK func_02018004();                            /* extern */
M2C_UNK func_0201801c();                            /* extern */
extern M2C_UNK data_020c6294;

void func_0201665c(s32 arg0) {
    func_0201801c();
    *((u16 *) ((s8 *) &data_020c6294 + (arg0 * 2))) = 0;
    func_02018004();
}
