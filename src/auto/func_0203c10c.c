#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
s32 func_0202bdf4(s32);                             /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0203be8c(s32);                         /* extern */
extern M2C_UNK data_0210d364;
extern M2C_UNK data_0210d36c;
extern M2C_UNK data_0210d370;
extern M2C_UNK func_0203c058;

void func_0203c10c(void) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0202bdf4(M2C_FIELD(&data_0210d364, s32 *, 8)) == 0) {
        return;
    }
    M2C_FIELD(temp_r4, s32 *, 0x28) = 0;
    func_0202b1a0(&data_0210d36c);
    func_0202b1a0(&data_0210d370);
    temp_r0 = M2C_FIELD(temp_r4, s32 *, 0x24) & 2;
    if (temp_r0 == 0) {
        M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0203c058;
        return;
    }
    func_0203be8c(temp_r0);
}
