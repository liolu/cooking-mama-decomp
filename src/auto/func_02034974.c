#include "m2c.h"

M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210bcb4;

void func_02034974(void) {
    s16 temp_r0_2;
    s32 *temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s16 *, 0x28) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) + 5);
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) <
            (s32) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8) - 0xB)) {
            return;
        }
        func_0202c03c(M2C_FIELD(&data_0210bcb4, void **, 0x118), 5);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8) - 0xB);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 0xA) = 0xF;
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE) = 0U;
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) =
            (u16) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE);
        temp_r2 = M2C_FIELD(temp_r0, s32 **, 0x24);
        *temp_r2 |= 0x4000;
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
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE) = 0x1000U;
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xC) =
        (u16) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), u16 *, 0xE);
    M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
}
