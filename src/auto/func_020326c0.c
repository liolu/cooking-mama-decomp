#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210b8ac;
extern M2C_UNK data_0210b9f0;

void func_020326c0(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    M2C_FIELD(M2C_FIELD(&data_0210b8ac, void **, 0x144), s16 *, 8) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0210b8ac, void **, 0x144), s16 *, 8) + 4);
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0210b8ac, void **, 0x144), s16 *, 8) < 0x3F) {
        return;
    }
    func_0202b1a0(&data_0210b9f0);
    M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
}
