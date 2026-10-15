#include "m2c.h"

M2C_UNK func_0202b1a0(void *);                      /* extern */
M2C_UNK func_0202ebc4(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
void *func_0206e764();                              /* extern */
extern M2C_UNK data_0210d540;
extern M2C_UNK func_0203cae8;
extern M2C_UNK func_0203cf70;

void func_0203d760(void) {
    s32 var_r6;
    void *temp_r4;
    void *temp_r5;

    temp_r4 = func_0202f368();
    temp_r5 = func_0206e764();
    if (func_02038374() == 2) {
        M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0203cae8;
        return;
    }
    if (M2C_FIELD(temp_r5, u16 *, 4) != 1) {
        return;
    }
    var_r6 = 0;
    if ((s32) (M2C_FIELD(temp_r4, s16 *, 0x2A) * 4) > 0) {
        do {
            func_0202b1a0((M2C_UNK *) ((s8 *) &data_0210d540 + ((var_r6 + 0x30) * 4)));
            var_r6 += 1;
        } while (var_r6 < (s32) (M2C_FIELD(temp_r4, s16 *, 0x2A) * 4));
    }
    M2C_FIELD(M2C_FIELD(&data_0210d540, void **, 0x10C), s16 *, 8) = 0xC8;
    func_02038384(0);
    func_0202ebc4(0xE);
    func_0202ebc4(0xF);
    func_0202ebc4(0x10);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_0203cf70;
}
