/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02006820(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020069bc(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02084e84;

void func_02003178(s32 arg0, s32 arg1, s32 arg2) {
    if ((data_02084e84 != -1) && ((u32) arg2 > 0x1CU)) {
        func_02006820(data_02084e84, arg0, arg1 + 0x05000600, arg2);
        return;
    }
    func_020069bc(arg0, arg1 + 0x05000600, arg2);
}
