#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02059e98();                            /* extern */
extern M2C_UNK data_020bc168;
extern M2C_UNK data_02111c80;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02059e0c;

void func_0205a034(void) {
    s16 var_r1;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02111c80);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x12C);
    var_r1 = M2C_FIELD(func_020197fc(), s16 *, 0x14);
    if ((s32) var_r1 > 6) {
        var_r1 = 0;
    }
    M2C_FIELD(temp_r4, s32 *, 0x5C) = (s32) * ((M2C_UNK *) ((s8 *) &data_020bc168 + (var_r1 * 4)));
    func_02059e98();
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_02059e0c;
}
