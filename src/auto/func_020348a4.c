#include "m2c.h"

M2C_UNK func_0202bfe4(void *, M2C_UNK);             /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210bcb4;

void func_020348a4(void) {
    s32 temp_r3;
    void *temp_r4;

    temp_r4 = func_0202f368();
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) + 4);
    temp_r3 = M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 8) - 0xA;
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) < temp_r3) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) = (s16) temp_r3;
    func_0202bfe4(M2C_FIELD(&data_0210bcb4, void **, 0x10C), 0);
    M2C_FIELD(temp_r4, s32 *, 0x10) = 1;
}
