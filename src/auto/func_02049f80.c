/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b014(void *, s16, s16, s16);       /* extern */
M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
s32 func_0202bdf4(void *);                          /* extern */
M2C_UNK func_0202bfe4(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210fad8;
extern M2C_UNK data_0210fbe0;

void func_02049f80(void) {
    s16 temp_r0_2;
    s32 *temp_r3;
    void *temp_r0;

    temp_r0 = func_0202f368();
    if (M2C_FIELD(temp_r0, s16 *, 0x28) == 0) {
        if (func_0202bdf4(M2C_FIELD(&data_0210fad8, void **, 0x108)) == 0) {
            return;
        }
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) < 0) {
            func_0202b014(M2C_FIELD(&data_0210fad8, void **, 0x100),
                          (s16) (M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x108), s16 *, 6) - 0x14),
                          M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x108), s16 *, 8),
                          (s16) (M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 0xA) - 1));
        }
        M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) + 4);
        if (*M2C_FIELD(temp_r0, s32 **, 0x24) & 4) {
            if ((s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) <
                (s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8)) {
                return;
            }
            func_0202c03c(M2C_FIELD(&data_0210fad8, void **, 0), 4);
            M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) = -0x32;
            M2C_FIELD(temp_r0, s32 *, 0x10)                                = 1;
            return;
        }
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) < 0x47) {
            return;
        }
        func_0202b1a0(&data_0210fbe0);
        if (M2C_FIELD(temp_r0, s16 *, 0x2C) == 0) {
            M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8) = 0x47;
            temp_r3                                                    = M2C_FIELD(temp_r0, s32 **, 0x24);
            *temp_r3 |= 0x800;
            M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) = -0x32;
            temp_r0_2                                                      = *M2C_FIELD(temp_r0, s16 **, 0x30);
            if (temp_r0_2 == 0) {
                func_0202ec14(0x26);
            } else if (temp_r0_2 == 1) {
                func_0202ec14(0x27);
            } else {
                func_0202ec14(0x28);
            }
            func_0202ec14(0x29);
            M2C_FIELD(temp_r0, s32 *, 0x10) = 1;
            return;
        }
        func_0202bfe4(M2C_FIELD(&data_0210fad8, void **, 0x100), 0);
        M2C_FIELD(temp_r0, s16 *, 0x28) = 1;
        return;
    }
    if (*M2C_FIELD(temp_r0, s32 **, 0x24) & 4) {
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) <
            (s32) M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0), s16 *, 8)) {
            return;
        }
        func_0202c03c(M2C_FIELD(&data_0210fad8, void **, 0), 4);
        M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) = -0x32;
        M2C_FIELD(temp_r0, s32 *, 0x10)                                = 1;
        return;
    }
    if (func_0202bdf4(M2C_FIELD(&data_0210fad8, void **, 0x100)) == 0) {
        return;
    }
    func_0202c03c(M2C_FIELD(&data_0210fad8, void **, 0), 4);
    M2C_FIELD(M2C_FIELD(&data_0210fad8, void **, 0x100), s16 *, 8) = -0x32;
    M2C_FIELD(temp_r0, s32 *, 0x10)                                = 1;
}
