/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_0207a390(s32);                           /* extern */
M2C_UNK func_0207ba54(void *, M2C_UNK);             /* extern */
M2C_UNK func_0207bd88(void *, M2C_UNK);             /* extern */
extern void *data_021174f0;

void func_0207b59c(M2C_UNK arg0, s32 arg1) {
    M2C_UNK (*temp_r2)(void *, M2C_UNK);
    M2C_UNK (*temp_r3)(void *, M2C_UNK);
    u32 temp_r0_2;
    u32 temp_r4;
    void *temp_r0;
    void *temp_r5;

    temp_r5 = M2C_FIELD(data_021174f0, void **, 0);
    if (M2C_FIELD(temp_r5, volatile s32 *, 0x10) == 0) {
        return;
    }
    M2C_FIELD(data_021174f0, volatile s32 *, 0x30) = 1;
    temp_r3                                        = M2C_FIELD(temp_r5, M2C_UNK(**)(void *, M2C_UNK), 0x18);
    if (temp_r3 != NULL) {
        temp_r3(data_021174f0, arg0);
    }
    if (M2C_FIELD(data_021174f0, volatile s32 *, 0x30) != 0) {
        if (arg1 != -1) {
            temp_r4 = M2C_FIELD(temp_r5, volatile u32 *, 0x14);
            temp_r0 = func_0207a390(arg1);
            M2C_FIELD(temp_r0, volatile s32 *, 0x20) =
                (s32) ((M2C_FIELD(temp_r0, volatile s32 *, 0x20) & ~(1 << temp_r4)) | (1 << temp_r4));
        }
        temp_r0_2 = M2C_FIELD(temp_r5, volatile u32 *, 0x14);
        switch (temp_r0_2) {
            case 3:
                break;
            default:
                break;
            case 0:
                func_0207ba54(temp_r5, arg0);
                break;
            case 1:
            case 2:
                func_0207bd88(temp_r5, arg0);
                break;
        }
    }
    temp_r2 = M2C_FIELD(temp_r5, M2C_UNK(**)(void *, M2C_UNK), 0x1C);
    if (temp_r2 == NULL) {
        return;
    }
    temp_r2(data_021174f0, arg0);
}
