/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02073388(M2C_UNK);
void func_02073404(M2C_UNK);
void func_020734a0(M2C_UNK, M2C_UNK);
void func_02073a78(M2C_UNK);
M2C_UNK func_02075ef8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021144e4;

s32 func_020736b4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r6;

    temp_r6 = (arg1 * 0x24) + (s32) &data_021144e4;
    if (*(M2C_UNK *) arg0 != 0) {
        func_02073a78(arg0);
    }
    if ((u32) M2C_FIELD(temp_r6, u16 *, 8) >= (u32) M2C_FIELD(temp_r6, u32 *, 0x18)) {
        temp_r0_2 = func_02075ef8(temp_r6, 0);
        if (temp_r0_2 == 0) {
            return 0;
        }
        if (arg2 < (s32) M2C_FIELD(temp_r0_2, u8 *, 0x3D)) {
            return 0;
        }
        func_02073404(temp_r0_2);
        goto block_8;
    }
block_8:
    temp_r0 = func_02073388(arg2);
    if (temp_r0 == 0) {
        return 0;
    }
    func_020734a0(temp_r6, temp_r0);
    *(M2C_UNK *) temp_r0 = arg0;
    *(M2C_UNK *) arg0    = temp_r0;
    return temp_r0;
}
