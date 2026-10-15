#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_0203e768();                            /* extern */
M2C_UNK func_0203e904();                            /* extern */
M2C_UNK func_0206d550(M2C_UNK, s16);                /* extern */
extern M2C_UNK data_020b77b0;
extern s32 data_0210db50;
extern M2C_UNK func_02038288;
extern M2C_UNK func_0203e984;

void func_0203e9b4(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x2C) = (s16) (*((s16 *) ((s8 *) &data_020b77b0 + (data_0210db50 * 6))) * 4);
    M2C_FIELD(temp_r0, s16 *, 0x2E) = 0;
    func_0203e904();
    func_0203e768();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    if (*((s16 *) ((s8 *) &data_020b77b0 + (data_0210db50 * 6))) == 1) {
        func_02038394(0x384);
    } else {
        func_02038394(0x5DC);
    }
    func_0206d550(9, M2C_FIELD(temp_r0, s16 *, 0x2C));
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0203e984;
}
