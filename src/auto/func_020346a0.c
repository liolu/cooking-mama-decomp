#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern s32 data_0210bc84;
extern M2C_UNK data_0210bcb4;
extern M2C_UNK data_0210bdcc;

void func_020346a0(void) {
    s16 temp_r0_2;
    s32 *temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s16 *, 0x28) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) + 5);
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) < 0x3C) {
            return;
        }
        func_0202c03c(M2C_FIELD(&data_0210bcb4, void **, 0x118), 5);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 0xA) = 5;
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE) = 0U;
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) =
            (u16) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE);
        M2C_FIELD(temp_r0, s16 *, 0x28) = 1;
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) =
        (u16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) + 0xC8);
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE) =
        (u16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE) + 0xC8);
    temp_r0_2 = M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8);
    if ((s32) temp_r0_2 > 0x46) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) = (s16) (temp_r0_2 - 1);
    }
    if ((u32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) < 0x1000U) {
        return;
    }
    func_0202b1a0(&data_0210bdcc);
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 6) = 0x81;
    if (data_0210bc84 != 8) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 4), s16 *, 6) = 0x81;
    }
    func_0202ec14(0x26);
    temp_r2 = M2C_FIELD(temp_r0, s32 **, 0x24);
    *temp_r2 |= 4;
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
