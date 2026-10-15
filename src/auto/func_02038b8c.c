#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(s16);                         /* extern */
M2C_UNK func_020389a0();                            /* extern */
M2C_UNK func_02038b48();                            /* extern */
extern M2C_UNK data_020b5eb2;
extern s32 data_0210ca50;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02038b5c;

void func_02038b8c(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x24) = 0;
    func_02038b48();
    func_020389a0();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394((s16) (*((s16 *) ((s8 *) &data_020b5eb2 + (data_0210ca50 * 8))) * 0x3C));
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02038b5c;
}
