#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202b0f0();                            /* extern */
M2C_UNK func_0202b220(M2C_UNK);                     /* extern */
M2C_UNK func_0202dd48();                            /* extern */
M2C_UNK func_0202e6ec(M2C_UNK *);                   /* extern */
M2C_UNK func_02056f88();                            /* extern */
M2C_UNK func_02057860();                            /* extern */
extern M2C_UNK data_02111840;

void func_0205799c(void) {
    void *temp_r4;

    temp_r4 = func_020197fc();
    func_0202e6ec(&data_02111840);
    func_0202dd48();
    if ((M2C_FIELD(temp_r4, s16 *, 0x16) == 1) && (M2C_FIELD(temp_r4, s16 *, 0x14) != 3)) {
        func_0202b220(0x2000);
    } else {
        func_0202b0f0();
        func_02056f88();
        M2C_FIELD(temp_r4, s32 *, 0x17C) = 0;
    }
    func_02057860();
}
