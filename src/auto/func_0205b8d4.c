#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0205b6cc();                            /* extern */
M2C_UNK func_0205b7b8();                            /* extern */
extern M2C_UNK data_020bc244;
extern M2C_UNK data_020bc3f8;
extern M2C_UNK data_020bc45c;
extern s32 data_02111ce8;
extern s32 data_02111cec;
extern s32 data_02111cf0;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0205b630;
extern M2C_UNK func_0205b87c;
extern M2C_UNK func_0205b898;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_0205b8d4(void) {
    s16 temp_r1;
    void *temp_r0;
    void *temp_r4;

    temp_r4                         = func_0202f368();
    temp_r0                         = func_020197fc();
    data_02111ce8                   = 0;
    M2C_FIELD(temp_r0, s16 *, 0x1C) = 1;
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 4) {
        M2C_FIELD(temp_r0, s8 *, 0x31) = 5;
        data_02111cec                  = *((M2C_UNK *) ((s8 *) &data_020bc244 + (M2C_FIELD(temp_r0, u8 *, 0x30) * 4)));
        data_02111cf0                  = (M2C_FIELD(temp_r0, u8 *, 0x30) * 0x14) + (s32) &data_020bc3f8;
    } else {
        temp_r1       = M2C_FIELD(temp_r0, s16 *, 0x14);
        data_02111cec = (s32) temp_r1;
        if ((s32) temp_r1 >= 0x13) {
            data_02111cec = 0;
        }
        data_02111cf0 = (data_02111cec * 0x14) + (s32) &data_020bc45c;
    }
    func_0205b7b8();
    func_0205b6cc();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_0205b630, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0205b898;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0205b87c;
    func_0202c1a0(1);
}
