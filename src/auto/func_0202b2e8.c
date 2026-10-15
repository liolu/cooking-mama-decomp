#include "m2c.h"

M2C_UNK func_0202b3a4();                            /* extern */
M2C_UNK func_0202b438();                            /* extern */
extern s32 data_020d5290;
extern M2C_UNK *data_020d5294;
extern M2C_UNK *data_020d5298;
extern M2C_UNK *data_020d529c;
extern M2C_UNK data_020db2a0;
extern M2C_UNK data_020e0aa0;

void func_0202b2e8(void) {
    data_020d529c = &data_020db2a0;
    data_020d5298 = &data_020db2a0;
    data_020d5294 = &data_020e0aa0;
    data_020d5290 = 0;
    func_0202b3a4();
    func_0202b438();
}
