#include "m2c.h"

M2C_UNK func_0202bfe4(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210bcb4;

void func_020347c0(void) {
    s16 temp_r0_2;
    s32 *temp_r2;
    u16 temp_r0_3;
    void *temp_r0;

    temp_r0   = func_0202f368();
    temp_r0_2 = M2C_FIELD(temp_r0, s16 *, 0x28);
    if (temp_r0_2 == 0) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) + 5);
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) < 0x3C) {
            return;
        }
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
            (s16) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8);
        func_0202bfe4(M2C_FIELD(&data_0210bcb4, void **, 0x118), 0);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0x1A) = 0U;
        func_0202ec14(0x29);
        temp_r2 = M2C_FIELD(temp_r0, s32 **, 0x24);
        *temp_r2 |= 0x4000;
        M2C_FIELD(temp_r0, s16 *, 0x28) = 1;
        return;
    }
    if ((s32) temp_r0_2 < 0x19) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0x1A) =
            (u16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0x1A) + 1);
    } else if ((s32) temp_r0_2 >= 0x64) {
        temp_r0_3 = M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0x1A);
        if (temp_r0_3 != 0) {
            M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0x1A) = (u16) (temp_r0_3 - 1);
        } else {
            M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
        }
    }
    M2C_FIELD(temp_r0, s16 *, 0x28) = (s16) (M2C_FIELD(temp_r0, s16 *, 0x28) + 1);
}
