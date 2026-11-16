/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_02019758(s32);                           /* extern */
M2C_UNK func_0201c9a8();                            /* extern */
M2C_UNK func_0201cfa4(M2C_UNK *);                   /* extern */
M2C_UNK func_02025f18();                            /* extern */
M2C_UNK func_02025f2c();                            /* extern */
M2C_UNK func_0202b014(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202b1a0(void *);                      /* extern */
M2C_UNK func_0202bc4c(void *, s32);                 /* extern */
M2C_UNK func_0202dd68(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_020d4590;
extern s32 data_020d4594;
extern s32 data_020d45a4;
extern M2C_UNK data_020d464c;
extern M2C_UNK data_020d49f4;

void func_02024f6c(void) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r2;

    temp_r0   = func_0202f368();
    temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x20);
    switch (temp_r0_2) {                            /* irregular */
        case 0x0:
            func_02025f2c();
            if (M2C_FIELD(func_02019758(data_020d45a4), s8 *, 0x14) != 5) {
                func_0201cfa4(&data_020d49f4);
            }
            M2C_FIELD(temp_r0, void **, 0x28) = func_0202b024(1, &data_020d464c, 0, -1, 0);
            func_0202b014(M2C_FIELD(temp_r0, void **, 0x28), 0x80, 0x60, 0x32);
            M2C_FIELD(temp_r0, void **, 0x2C) = func_0202b024(1, &data_020d464c, 1, -1, 0);
            func_0202b014(M2C_FIELD(temp_r0, void **, 0x2C), 0x80, 0x60, 0x33);
            M2C_FIELD(temp_r0, void **, 0x30) = func_0202b024(1, &data_020d464c, 2, -1, 0);
            func_0202b014(M2C_FIELD(temp_r0, void **, 0x30), 0x80, 0x60, 0x34);
            func_0202bc4c(M2C_FIELD(temp_r0, void **, 0x30), 0xF);
            M2C_FIELD(temp_r0, s32 *, 0x20) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x20) + 1);
            M2C_FIELD(temp_r0, s32 *, 0x20) = 3;
            return;
        case 0x1:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) + 2);
            func_0202bc4c(M2C_FIELD(temp_r0, void **, 0x28), M2C_FIELD(temp_r0, s32 *, 0x1C));
            if ((s32) M2C_FIELD(temp_r0, s32 *, 0x1C) < 0x1F) {
                return;
            }
            func_0202bc4c(M2C_FIELD(temp_r0, void **, 0x28), 0x1F);
            func_0202bc4c(M2C_FIELD(temp_r0, void **, 0x2C), 0x1F);
            M2C_FIELD(temp_r0, s32 *, 0x20) = 3;
            return;
        case 0x2:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) + 1);
            temp_r0_3                       = M2C_FIELD(temp_r0, s32 *, 0x1C);
            if (temp_r0_3 <= 2) {
                temp_r1                          = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1, u16 *, 0xC)   = (u16) (M2C_FIELD(temp_r1, u16 *, 0xC) + 0x100);
                temp_r1_2                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_2, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_2, u16 *, 0xC);
                return;
            }
            if (temp_r0_3 <= 9) {
                temp_r1_3                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_3, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_3, u16 *, 0xC) - 0x200);
                temp_r1_4                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_4, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_4, u16 *, 0xC);
                if (M2C_FIELD(temp_r0, s32 *, 0x1C) != 4) {
                    return;
                }
                func_0202dd68(3);
                return;
            }
            M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), u16 *, 0xE) = 0U;
            temp_r2                                                  = M2C_FIELD(temp_r0, void **, 0x28);
            M2C_FIELD(temp_r2, u16 *, 0xC)                           = (u16) M2C_FIELD(temp_r2, u16 *, 0xE);
            M2C_FIELD(temp_r0, s32 *, 0x1C)                          = 0;
            M2C_FIELD(temp_r0, s32 *, 0x20)                          = 0x63;
            return;
        case 0x3:
            if (data_020d4594 == 1) {
                M2C_FIELD(temp_r0, s32 *, 0x20) = 0x63;
            }
            return;
        case 0x63:
            if (data_020d4590 != 5) {
                return;
            }
            func_0202b1a0(temp_r0 + 0x28);
            func_0202b1a0(temp_r0 + 0x2C);
            func_0202b1a0(temp_r0 + 0x30);
            func_0201c9a8();
            func_02025f18();
            M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
            return;
    }
}
