#include "m2c.h"

M2C_UNK func_0202b1a0(s32);                         /* extern */
M2C_UNK func_0202e5e0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02113844;
extern M2C_UNK data_0211386c;

void func_0206da04(void *arg0) {
    func_0202b1a0(arg0 + 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        func_0202e5e0(&data_0211386c);
    }
    *((M2C_UNK *) ((s8 *) &data_02113844 + (M2C_FIELD(arg0, s32 *, 0x2C) * 4))) = 0;
}
