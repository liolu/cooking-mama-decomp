#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
s32 func_0202bdf4(s32);                             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210bcb4;
extern M2C_UNK data_0210bdcc;

void func_02034900(void) {
    s32 *temp_r2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_0202bdf4(M2C_FIELD(&data_0210bcb4, s32 *, 0x118)) == 0) {
        return;
    }
    func_0202ec14(0x29);
    func_0202b1a0(&data_0210bdcc);
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 6) = 0x81;
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 4), s16 *, 6) = 0x81;
    func_0202ec14(0x26);
    temp_r2 = M2C_FIELD(temp_r4, s32 **, 0x24);
    *temp_r2 |= 4;
    M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
}
