#include "m2c.h"

s32 func_02019808();                                /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_020380f0(M2C_UNK *);                   /* extern */
M2C_UNK func_0206e764();                            /* extern */
extern M2C_UNK func_02019c34;

void func_02045644(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_0206e764();
    if (func_02019808() != 3) {
        return;
    }
    func_020380f0(&func_02019c34);
    M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
}
