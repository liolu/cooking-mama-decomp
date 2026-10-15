/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02006898(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020069ec(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02084e84;

void func_020030b4(s32 arg0, s32 arg1, s32 arg2) {
    if ((data_02084e84 != -1) && ((u32) arg2 > 0x30U)) {
        func_02006898(data_02084e84, arg0, arg1 + 0x07000400, arg2);
        return;
    }
    func_020069ec(arg0, arg1 + 0x07000400, arg2);
}
