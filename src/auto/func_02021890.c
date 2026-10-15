#include "m2c.h"

M2C_UNK func_020216cc();                            /* extern */
M2C_UNK func_02021744();                            /* extern */
M2C_UNK func_020217c0();                            /* extern */
M2C_UNK func_0202c1a0(M2C_UNK);                     /* extern */
M2C_UNK func_0202f224(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
extern s32 data_020d436c;
extern M2C_UNK func_02021540;
extern M2C_UNK func_0202181c;
extern M2C_UNK func_0202185c;
extern M2C_UNK func_0202caf0;
extern M2C_UNK func_0206e494;
extern M2C_UNK func_0206e77c;

void func_02021890(void) {
    void *temp_r4;

    temp_r4       = func_0202f368();
    data_020d436c = 0;
    func_020217c0();
    func_02021744();
    func_020216cc();
    func_0202f564(&func_0202caf0, 0xFF01);
    func_0202f564(&func_0206e77c, 5);
    func_0202f564(&func_0206e494, 5);
    func_0202f224(1);
    func_0202f564(&func_02021540, 0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0)    = &func_0202185c;
    M2C_FIELD(temp_r4, M2C_UNK **, 0x14) = &func_0202181c;
    func_0202c1a0(1);
}
