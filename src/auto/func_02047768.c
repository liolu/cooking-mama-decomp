#include "engine.h"
#include "m2c.h"

void func_0202b014(void *, s16, s16, s16);
M2C_UNK func_0202bfe4(M2C_UNK, M2C_UNK);
void func_0202c03c(M2C_UNK, M2C_UNK);
s32 func_0202f368(void);
void func_020474f0(void);
M2C_UNK *func_0206e770(void);
M2C_UNK *func_0206eab8(void);

extern M2C_UNK data_0210f358;

void func_02047768(void) {
    s16 temp_r1;
    s32 *temp_r0;
    s32 temp_r4;

    temp_r4 = func_0202f368();
    func_0206e770();
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 0x24), s16 *, 8);
    if ((s32) temp_r1 < 0x78) {
        M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 0x24), s16 *, 8) = (s16) (temp_r1 + 5);
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) - 6);
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) > 0x78) {
        return;
    }
    func_0202c03c(M2C_FIELD(&data_0210f358, volatile s32 *, 0), 6);
    M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 8), s16 *, 6)    = -0x32;
    M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 0x24), s16 *, 6) = -0x32;
    func_0202b014(M2C_FIELD(&data_0210f358, void **, 0x28), 0x78, 0x78, 3);
    temp_r0                               = func_0206eab8();
    M2C_FIELD(temp_r0, volatile s32 *, 0) = (M2C_FIELD(temp_r0, volatile s32 *, 4) * M2C_FIELD(temp_r0, volatile s32 *, 0)) +
                                            M2C_FIELD(temp_r0, volatile s32 *, 8);
    M2C_FIELD(temp_r4, volatile s16 *, 0x30) =
        (s16) ((u32) (((u32) M2C_FIELD(temp_r0, volatile s32 *, 0) >> 0x10) * 4) >> 0x10);
    func_0202bfe4((s32) M2C_FIELD(&data_0210f358, void **, 0x28), (s32) M2C_FIELD(temp_r4, volatile s16 *, 0x30));
    M2C_FIELD(temp_r4, volatile s16 *, 0x32) = 0;
    M2C_FIELD(temp_r4, void (**)(), 0)       = func_020474f0;
}
