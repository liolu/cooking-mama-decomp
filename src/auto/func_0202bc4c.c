#include "engine.h"
#include "m2c.h"

void func_0202ad64(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0202bc4c(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (u8) arg1;
    func_0202ad64(arg0 + 0x1A, 0, 0x1F);
}
