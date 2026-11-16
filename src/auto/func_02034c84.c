/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0206e764();                            /* extern */
extern M2C_UNK data_0210bcb4;
extern M2C_UNK func_02034b08;

void func_02034c84(void) {
    s16 temp_r1;
    s16 temp_r2;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_0206e764();
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8);
    if ((s32) temp_r1 > 0x1F) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8) = (s16) (temp_r1 - 5);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 4), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 4), s16 *, 8) - 5);
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 8), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 8), s16 *, 8) - 5);
        if (M2C_FIELD(temp_r4, s32 *, 0x24) & 0x4000) {
            M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) =
                (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x118), s16 *, 8) - 5);
        }
    }
    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 8);
    if ((s32) temp_r2 > -0x1E) {
        M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 8) = (s16) (temp_r2 - 0xA);
        if (M2C_FIELD(temp_r4, s32 *, 0x24) & 0x800) {
            M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) =
                (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x10C), s16 *, 8) - 0xA);
        }
        if (M2C_FIELD(temp_r4, s32 *, 0x24) & 0x2000) {
            M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x114), s16 *, 8) =
                (s16) (M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0x114), s16 *, 8) - 0xF);
        }
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0xD8), s16 *, 8) > -0x1E) {
            return;
        }
        func_0202ec14(0x19);
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 8)   = -0x64;
    M2C_FIELD(M2C_FIELD(&data_0210bcb4, void **, 0), s16 *, 0xA) = 0;
    M2C_FIELD(temp_r4, M2C_UNK **, 0)                            = &func_02034b08;
}
