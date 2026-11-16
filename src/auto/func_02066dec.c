/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
s32 func_0202ac30(void *, M2C_UNK);                 /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
s32 func_02038374();                                /* extern */
M2C_UNK func_0206de68(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK func_02066de0;

void func_02066dec(void) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (func_02038374() == 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x28) != 0) {
        return;
    }
    if (func_0202ac30(M2C_FIELD(temp_r4, void **, 0x1C), 0) == 0) {
        return;
    }
    func_0202ec14(0xB);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), s32 *, 0x28) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x28) + 1);
    func_0206de68(0x40, 0x68, 4, -1);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x24), void **, 0x20), s16 *, 0x1A) = 0x1F;
    if (M2C_FIELD(func_020197fc(), s16 *, 0x16) == 4) {
        return;
    }
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s16 *, 0x1A) = 0;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x20), s16 *, 0x1A) = 0;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                         = &func_02066de0;
}
