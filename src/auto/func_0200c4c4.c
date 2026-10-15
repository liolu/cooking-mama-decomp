/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);
M2C_UNK func_0200c60c(void);

extern M2C_UNK data_020c4c78;

s32 func_0200c4c4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;

    temp_r0 = func_02006194();
    if (M2C_FIELD(&data_020c4c78, s32 *, 0) != 0) {
        func_020061a8(temp_r0);
        return 1;
    }
    M2C_FIELD(&data_020c4c78, s32 *, 0) = 1;
    func_020061a8(temp_r0);
    M2C_FIELD(&data_020c4c78, s32 *, 0x14) = 1;
    M2C_FIELD(&data_020c4c78, s32 *, 0x18) = 0;
    M2C_FIELD(&data_020c4c78, s32 *, 8)    = arg0;
    M2C_FIELD(&data_020c4c78, s32 *, 4)    = arg1;
    M2C_FIELD(&data_020c4c78, s32 *, 0x10) = arg2;
    if (func_0200c60c() != 0) {
        return 0;
    }
    return 3;
}
