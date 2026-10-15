/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);
M2C_UNK func_0200ac80(void);

extern M2C_UNK data_020c4bf0;

s32 func_0200af74(s32 arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = func_02006194();
    if (M2C_FIELD(&data_020c4bf0, s32 *, 0) != 0) {
        func_020061a8(temp_r0);
        return 1;
    }
    M2C_FIELD(&data_020c4bf0, s32 *, 0) = 1;
    func_020061a8(temp_r0);
    M2C_FIELD(&data_020c4bf0, s32 *, 4) = arg0;
    M2C_FIELD(&data_020c4bf0, s32 *, 8) = arg1;
    if (func_0200ac80() != 0) {
        return 0;
    }
    return 3;
}
