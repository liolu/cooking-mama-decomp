#include "engine.h"
#include "m2c.h"

void func_0202b014(void *, s16, s16, s16);
s32 func_0202bdf4(void *);
M2C_UNK func_0202bfe4(M2C_UNK, M2C_UNK);
s32 func_0202f368(void);
void func_0204729c(void);
void func_020474f0(void);
M2C_UNK *func_0206eab8(void);

extern M2C_UNK data_0210f358;

void func_02047404(void) {
    s32 *temp_r0;
    s32 temp_r4;

    temp_r4 = func_0202f368();
    if (func_0202bdf4(M2C_FIELD(&data_0210f358, void **, 0)) == 0) {
        return;
    }
    if ((s32) M2C_FIELD(temp_r4, volatile s16 *, 0x32) < 3) {
        func_0202b014(M2C_FIELD(&data_0210f358, void **, 0x28), 0x78, 0x78, 3);
        temp_r0 = func_0206eab8();
        M2C_FIELD(temp_r0, volatile s32 *, 0) =
            (M2C_FIELD(temp_r0, volatile s32 *, 4) * M2C_FIELD(temp_r0, volatile s32 *, 0)) +
            M2C_FIELD(temp_r0, volatile s32 *, 8);
        M2C_FIELD(temp_r4, volatile s16 *, 0x30) =
            (s16) ((u32) (((u32) M2C_FIELD(temp_r0, volatile s32 *, 0) >> 0x10) * 4) >> 0x10);
        func_0202bfe4((s32) M2C_FIELD(&data_0210f358, void **, 0x28), (s32) M2C_FIELD(temp_r4, volatile s16 *, 0x30));
        M2C_FIELD(temp_r4, void (**)(), 0) = func_020474f0;
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) + 5);
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0210f358, void **, 4), s16 *, 6) < 0xF0) {
        return;
    }
    func_0202b014(M2C_FIELD(&data_0210f358, void **, 0x28), 0x78, 0x78, 3);
    func_0202bfe4((s32) M2C_FIELD(&data_0210f358, void **, 0x28), 4);
    M2C_FIELD(temp_r4, void (**)(), 0) = func_0204729c;
}
