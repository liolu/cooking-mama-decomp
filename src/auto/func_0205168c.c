/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(void *, s16, s16, s16);       /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0206dc78(M2C_UNK);                     /* extern */
extern M2C_UNK data_02110b7c;
extern M2C_UNK data_02110b8c;
extern M2C_UNK data_02110b94;
extern M2C_UNK data_02110b9c;
extern M2C_UNK data_02110c04;
extern M2C_UNK func_02051e14;

void func_0205168c(void) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x28) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x28) + 1);
    if ((s32) M2C_FIELD(temp_r0, s32 *, 0x28) < 0x14) {
        return;
    }
    func_0206dc78(1);
    func_0202b1a0(&data_02110b8c);
    temp_r0_2                                = func_0202b024(1, &data_02110c04, 1, -1, 0);
    M2C_FIELD(&data_02110b7c, void **, 0x10) = temp_r0_2;
    func_0202b014(temp_r0_2, 0xC8, 0x3C, 3);
    func_0202b1a0(&data_02110b94);
    temp_r0_3                                = func_0202b024(1, &data_02110b9c, 4, -1, 0);
    M2C_FIELD(&data_02110b7c, void **, 0x18) = temp_r0_3;
    func_0202b014(temp_r0_3, M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 6),
                  M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 8),
                  (s16) (M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 0xA) - 1));
    func_0202b014(M2C_FIELD(&data_02110b7c, void **, 0x1C),
                  (s16) (M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 6) + 0x58),
                  (s16) (M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 8) + 0x60),
                  (s16) (M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0), s16 *, 0xA) - 1));
    M2C_FIELD(temp_r0, s32 *, 0x28)   = 0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_02051e14;
}
