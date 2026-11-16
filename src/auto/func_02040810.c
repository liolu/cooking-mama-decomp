/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, s16);  /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
s32 func_0202bdf4(s32);                             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210e0b4;
extern M2C_UNK data_0210e110;
extern M2C_UNK data_0210e26c;
extern M2C_UNK func_0204072c;

void func_02040810(void) {
    s32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (!(M2C_FIELD(temp_r0, s32 *, 0x24) & 2)) {
        if (func_0202bdf4(M2C_FIELD(&data_0210e0b4, s32 *, 0x5C)) == 0) {
            return;
        }
        temp_r0_2                              = func_0202b024(1, &data_0210e26c, -1, 0, 8);
        M2C_FIELD(&data_0210e0b4, s32 *, 0x2C) = temp_r0_2;
        func_0202b014(temp_r0_2, 0x59, 0x3B, (s16) (M2C_FIELD(M2C_FIELD(&data_0210e0b4, void **, 0x7C), s16 *, 0xA) - 1));
        func_0202ec14(0x29);
        M2C_FIELD(temp_r0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x24) | 2);
        return;
    }
    if (func_0202bdf4(M2C_FIELD(&data_0210e0b4, s32 *, 0x2C)) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210e0b4, void **, 0x68), s16 *, 0xA) = 3;
    func_0202b1a0(&data_0210e110);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_0204072c;
}
