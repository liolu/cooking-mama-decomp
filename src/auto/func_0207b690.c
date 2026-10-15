/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0207ba54(void *, M2C_UNK);             /* extern */
M2C_UNK func_0207bd88(void *, M2C_UNK);             /* extern */
extern void *data_021174f0;

void func_0207b690(M2C_UNK arg0) {
    M2C_UNK (*temp_r2)(void *, M2C_UNK);
    M2C_UNK (*temp_r2_2)(void *, M2C_UNK);
    u32 temp_r0;
    void *temp_r4;

    temp_r4 = M2C_FIELD(data_021174f0, void **, 0);
    if (M2C_FIELD(temp_r4, s32 *, 0x10) == 0) {
        return;
    }
    M2C_FIELD(data_021174f0, s32 *, 0x30) = 1;
    temp_r2                               = M2C_FIELD(temp_r4, M2C_UNK(**)(void *, M2C_UNK), 0x18);
    if (temp_r2 != NULL) {
        temp_r2(data_021174f0, arg0);
    }
    if (M2C_FIELD(data_021174f0, s32 *, 0x30) != 0) {
        temp_r0 = M2C_FIELD(temp_r4, u32 *, 0x14);
        switch (temp_r0) {
            case 3:
                break;
            default:
                break;
            case 0:
                func_0207ba54(temp_r4, arg0);
                break;
            case 1:
            case 2:
                func_0207bd88(temp_r4, arg0);
                break;
        }
    }
    temp_r2_2 = M2C_FIELD(temp_r4, M2C_UNK(**)(void *, M2C_UNK), 0x1C);
    if (temp_r2_2 == NULL) {
        return;
    }
    temp_r2_2(data_021174f0, arg0);
}
