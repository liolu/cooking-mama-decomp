#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020380f0(M2C_UNK);                     /* extern */
M2C_UNK func_02052390();                            /* extern */
M2C_UNK func_02052428();                            /* extern */
M2C_UNK func_0206df1c(M2C_UNK *);                   /* extern */
extern void *data_02110b70;
extern M2C_UNK data_02110c04;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_02038100;
extern M2C_UNK func_020522fc;
extern M2C_UNK func_020524b0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_020524ec(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02052428();
    func_02052390();
    temp_r0       = func_020197fc();
    data_02110b70 = temp_r0;
    if (M2C_FIELD(temp_r0, volatile s16 *, 0x16) != 4) {
        M2C_FIELD(temp_r0, volatile s8 *, 0x31) = 3;
    } else {
        M2C_FIELD(temp_r0, volatile s8 *, 0x31) = 4;
    }
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0206df1c(&data_02110c04);
    func_020380f0(0);
    func_0202f564(&func_020522fc, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_02038100;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_020524b0;
    func_0202c1a0(1);
}
