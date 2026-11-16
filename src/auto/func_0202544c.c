/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0202ac30(void *, s32);                     /* extern */
M2C_UNK func_0202b014(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_0202b1a0(void *);                      /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_020d4580;
extern s32 data_020d4588;
extern s32 data_020d458c;
extern s32 data_020d4594;
extern s32 data_020d4598;
extern s32 data_020d459c;
extern M2C_UNK data_020d471c;

void func_0202544c(void) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_6;
    s32 temp_r2_2;
    s32 var_r2;
    void *temp_r0;
    void *temp_r0_5;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r1_4;
    void *temp_r1_5;
    void *temp_r1_6;
    void *temp_r1_7;
    void *temp_r1_8;
    void *temp_r1_9;
    void *temp_r2;
    void *temp_r3;

    temp_r0   = func_0202f368();
    temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x20);
    switch (temp_r0_2) {                            /* irregular */
        case 0x0:
            M2C_FIELD(temp_r0, void **, 0x28) = func_0202b024(1, &data_020d471c, -1, M2C_FIELD(temp_r0, s32 *, 0x24) + 0xA, 1);
            if (M2C_FIELD(temp_r0, s32 *, 0x24) == 0) {
                func_0202b014(M2C_FIELD(temp_r0, void **, 0x28), 0xE, 0x7E, 9);
            } else {
                func_0202b014(M2C_FIELD(temp_r0, void **, 0x28), 0xF2, 0x7E, 9);
            }
            M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), u16 *, 0xE) = 0U;
            temp_r1                                                  = M2C_FIELD(temp_r0, void **, 0x28);
            M2C_FIELD(temp_r1, u16 *, 0xC)                           = (u16) M2C_FIELD(temp_r1, u16 *, 0xE);
            M2C_FIELD(temp_r0, s32 *, 0x20)                          = (s32) (M2C_FIELD(temp_r0, s32 *, 0x20) + 1);
            return;
        case 0x1:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) + 1);
            temp_r0_3                       = M2C_FIELD(temp_r0, s32 *, 0x1C);
            if (temp_r0_3 <= 9) {
                temp_r1_2                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_2, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_2, u16 *, 0xC) + 0x200);
                temp_r1_3                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_3, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_3, u16 *, 0xC);
                return;
            }
            if (temp_r0_3 <= 0xB) {
                temp_r1_4                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_4, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_4, u16 *, 0xC) - 0x100);
                temp_r1_5                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_5, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_5, u16 *, 0xC);
                return;
            }
            M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), u16 *, 0xE) = 0x1000U;
            temp_r3                                                  = M2C_FIELD(temp_r0, void **, 0x28);
            M2C_FIELD(temp_r3, u16 *, 0xC)                           = (u16) M2C_FIELD(temp_r3, u16 *, 0xE);
            M2C_FIELD(temp_r0, s32 *, 0x1C)                          = 0;
            M2C_FIELD(temp_r0, s32 *, 0x20)                          = 3;
            return;
        case 0x2:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) + 1);
            temp_r0_4                       = M2C_FIELD(temp_r0, s32 *, 0x1C);
            if (temp_r0_4 <= 2) {
                temp_r1_6                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_6, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_6, u16 *, 0xC) + 0x100);
                temp_r1_7                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_7, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_7, u16 *, 0xC);
                return;
            }
            if (temp_r0_4 <= 9) {
                temp_r1_8                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_8, u16 *, 0xC) = (u16) (M2C_FIELD(temp_r1_8, u16 *, 0xC) - 0x200);
                temp_r1_9                        = M2C_FIELD(temp_r0, void **, 0x28);
                M2C_FIELD(temp_r1_9, u16 *, 0xE) = (u16) M2C_FIELD(temp_r1_9, u16 *, 0xC);
                return;
            }
            M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x28), u16 *, 0xE) = 0U;
            temp_r2                                                  = M2C_FIELD(temp_r0, void **, 0x28);
            M2C_FIELD(temp_r2, u16 *, 0xC)                           = (u16) M2C_FIELD(temp_r2, u16 *, 0xE);
            if (data_020d4594 == 0) {
                data_020d4594 = 1;
            }
            M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r0, s32 *, 0x20) = 0x63;
            data_020d4588                   = 0;
            return;
        case 0x3:
            temp_r0_5 = M2C_FIELD(temp_r0, void **, 0x28);
            if (M2C_FIELD(temp_r0_5, u16 *, 0xC) == 0) {
                var_r2 = 1;
            } else {
                var_r2 = 0;
            }
            if ((func_0202ac30(temp_r0_5, var_r2 | data_020d4580) == 0) && (data_020d4594 != 1) && (data_020d4598 == 0)) {
                return;
            }
            if (func_0202ac30(M2C_FIELD(temp_r0, void **, 0x28), data_020d4580) != 0) {
                if (M2C_FIELD(temp_r0, s32 *, 0x24) == 0) {
                    temp_r0_6     = data_020d458c - 1;
                    data_020d458c = temp_r0_6;
                    if (temp_r0_6 < 0) {
                        data_020d458c = data_020d459c - 1;
                    }
                } else {
                    temp_r2_2     = data_020d458c + 1;
                    data_020d458c = temp_r2_2;
                    if (temp_r2_2 > (s32) (data_020d459c - 1)) {
                        data_020d458c = 0;
                    }
                }
                func_0202ec14(7);
                data_020d4588 = 1;
            }
            M2C_FIELD(temp_r0, s32 *, 0x20) = 2;
            return;
        case 0x63:
            func_0202b1a0(temp_r0 + 0x28);
            M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
            return;
    }
}
