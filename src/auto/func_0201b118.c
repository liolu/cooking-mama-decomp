#include "m2c.h"

void *func_020197fc();                              /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
M2C_UNK func_0201f4ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_0202dd68(M2C_UNK);                     /* extern */
extern M2C_UNK data_020d3594;

void func_0201b118(void) {
    void *temp_r4;

    temp_r4 = func_020197fc();
    func_0202dd68(3);
    M2C_FIELD(func_0201f4a0(5), s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x28), s32 *, 0x10);
    func_0201f4ec(5, &data_020d3594);
    M2C_FIELD(func_0201f4a0(6), s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x28), s32 *, 0x14);
    func_0201f4ec(6, &data_020d3594);
}
