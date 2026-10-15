#include "m2c.h"

M2C_UNK func_02018f0c();                            /* extern */
void *func_02019758();                              /* extern */
M2C_UNK func_020197fc();                            /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
M2C_UNK func_0201f4ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_0202dd68(M2C_UNK);                     /* extern */
M2C_UNK func_020537ac(s32, s32);                    /* extern */
extern M2C_UNK data_020d4ac4;

void func_02023dac(void) {
    void *temp_r4;

    func_020197fc();
    func_0202dd68(3);
    func_0201f4a0(0x35);
    func_0201f4ec(0x35, &data_020d4ac4);
    func_0201f4a0(0x37);
    func_0201f4ec(0x37, &data_020d4ac4);
    temp_r4 = func_0201f4a0(0x36);
    func_02018f0c();
    func_020537ac(M2C_FIELD(temp_r4, s32 *, 0x18), M2C_FIELD(func_02019758(), s32 *, 4));
    func_0201f4ec(0x36, &data_020d4ac4);
}
