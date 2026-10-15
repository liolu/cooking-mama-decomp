#include "m2c.h"

s32 func_02019684(s32, s32);                        /* extern */
M2C_UNK func_020197fc();                            /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
M2C_UNK func_0201f4ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_0202dd68(M2C_UNK);                     /* extern */
M2C_UNK func_020537ac(s32, M2C_UNK *);              /* extern */
M2C_UNK func_020537b8(s32, s32);                    /* extern */
extern M2C_UNK data_020aed70;
extern s32 data_020d457c;
extern s32 data_020d45a4;
extern M2C_UNK data_020d4ac4;

void func_02023e1c(void) {
    void *temp_r0;

    func_020197fc();
    func_0202dd68(3);
    temp_r0 = func_0201f4a0(0x23);
    func_020537ac(M2C_FIELD(temp_r0, s32 *, 0x18), &data_020aed70);
    func_020537b8(M2C_FIELD(temp_r0, s32 *, 0x18), func_02019684(data_020d457c, data_020d45a4));
    func_0201f4ec(0x23, &data_020d4ac4);
}
