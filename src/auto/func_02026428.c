/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020197fc();                            /* extern */
M2C_UNK func_0202b014(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0202b024(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0202b1a0(void *);                      /* extern */
M2C_UNK func_0202bc4c(s32, s32);                    /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_020d4c68;
extern s32 data_020d4c70;
extern M2C_UNK data_020d4c78;

void func_02026428(void) {
    s32 temp_r0_2;
    void *temp_r0;

    func_020197fc();
    temp_r0   = func_0202f368();
    temp_r0_2 = M2C_FIELD(temp_r0, s32 *, 0x20);
    switch (temp_r0_2) {                            /* irregular */
        case 0x0:
            M2C_FIELD(temp_r0, s32 *, 0x38) = func_0202b024(1, &data_020d4c78, 1, -1, 0);
            func_0202b014(M2C_FIELD(temp_r0, s32 *, 0x38), 0x80, 0x60, 0x1F);
            func_0202bc4c(M2C_FIELD(temp_r0, s32 *, 0x38), 0);
            M2C_FIELD(temp_r0, s32 *, 0x20) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x20) + 1);
            return;
        case 0x1:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) + 1);
            func_0202bc4c(M2C_FIELD(temp_r0, s32 *, 0x38), M2C_FIELD(temp_r0, s32 *, 0x1C));
            if ((s32) M2C_FIELD(temp_r0, s32 *, 0x1C) <= 0x20) {
                return;
            }
            func_0202bc4c(M2C_FIELD(temp_r0, s32 *, 0x38), 0x1F);
            M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r0, s32 *, 0x20) = 3;
            return;
        case 0x2:
            M2C_FIELD(temp_r0, s32 *, 0x1C) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1C) - 1);
            func_0202bc4c(M2C_FIELD(temp_r0, s32 *, 0x38), M2C_FIELD(temp_r0, s32 *, 0x1C) * 2);
            if ((s32) M2C_FIELD(temp_r0, s32 *, 0x1C) <= 0x20) {
                return;
            }
            func_0202bc4c(M2C_FIELD(temp_r0, s32 *, 0x38), 0);
            M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r0, s32 *, 0x20) = 0x63;
            return;
        case 0x3:
            if (data_020d4c70 == 1) {
                M2C_FIELD(temp_r0, s32 *, 0x20) = 0x63;
            }
            return;
        case 0x63:
            func_0202b1a0(temp_r0 + 0x38);
            func_0202b1a0(temp_r0 + 0x3C);
            data_020d4c68                   = M2C_FIELD(temp_r0, s32 *, 0x24);
            M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
            return;
    }
}
