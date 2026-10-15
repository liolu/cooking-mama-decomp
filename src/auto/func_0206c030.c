#include "engine.h"
#include "m2c.h"

void func_0202c03c(M2C_UNK, M2C_UNK);
void func_0202ec14(M2C_UNK);
M2C_UNK func_0202f368(void);
M2C_UNK func_0206e764(void);

void func_0206c030(void) {
    s32 temp_r4;

    temp_r4 = func_0202f368();
    func_0206e764();
    if (M2C_FIELD(temp_r4, volatile u16 *, 0x56) == 0) {
        M2C_FIELD(temp_r4, volatile s32 *, 0x48)                  = 2;
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x38), s16 *, 6)    = 0xE0;
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x38), s16 *, 8)    = 0x90;
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x3C), s16 *, 6)    = 0xA0;
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x3C), s16 *, 8)    = 0x90;
        M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x3C), u16 *, 0x1A) = 0x1FU;
        M2C_FIELD(temp_r4, volatile u16 *, 0x56)                  = 1U;
    }
    if (M2C_FIELD(temp_r4, volatile s32 *, 0x4C) == 0) {
        return;
    }
    func_0202ec14(0xB);
    if (M2C_FIELD(temp_r4, volatile s32 *, 0x4C) == 2) {
        func_0202c03c(M2C_FIELD(temp_r4, volatile s32 *, 0x34), 4);
    } else {
        func_0202c03c(M2C_FIELD(temp_r4, volatile s32 *, 0x34), 1);
    }
    M2C_FIELD(M2C_FIELD(temp_r4, volatile s32 *, 0x34), s16 *, 0x1A) = 0x1F;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x3C), u16 *, 0x1A)        = 0U;
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x38), u16 *, 0x1A) =
        (u16) M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x3C), u16 *, 0x1A);
    M2C_FIELD(temp_r4, volatile u16 *, 0x56)                  = 0U;
    M2C_FIELD(temp_r4, volatile s32 *, 0x4C)                  = 0;
    M2C_FIELD(temp_r4, volatile s32 *, 0x48)                  = (s32) M2C_FIELD(temp_r4, volatile s32 *, 0x4C);
    M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x1C), s32 *, 0x20) = 4;
    M2C_FIELD(temp_r4, volatile s32 *, 0x44)                  = (s32) (M2C_FIELD(temp_r4, volatile s32 *, 0x44) + 1);
}
