/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_0206eaec(void *arg0) {
    void *temp_r1;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r3;

    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    temp_r2                      = M2C_FIELD(arg0, void **, 4);
    if ((temp_r2 != NULL) && (M2C_FIELD(temp_r2, s32 *, 0x10) == 0)) {
        M2C_FIELD(temp_r2, void **, 0) = NULL;
        M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, void **, 4)  = (void *) M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 4);
        temp_r1                      = M2C_FIELD(arg0, void **, 4);
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, void **, 0) = arg0;
        }
    }
    temp_r3 = M2C_FIELD(arg0, void **, 0);
    if (temp_r3 == NULL) {
        return;
    }
    if (M2C_FIELD(temp_r3, s32 *, 0x10) != 0) {
        return;
    }
    M2C_FIELD(temp_r3, s32 *, 0xC)                     = (s32) (M2C_FIELD(temp_r3, s32 *, 0xC) + M2C_FIELD(arg0, s32 *, 0xC));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 4) = (void *) M2C_FIELD(arg0, void **, 4);
    temp_r2_2                                          = M2C_FIELD(arg0, void **, 4);
    if (temp_r2_2 != NULL) {
        M2C_FIELD(temp_r2_2, void **, 0) = (void *) M2C_FIELD(arg0, void **, 0);
    }
    M2C_FIELD(arg0, void **, 0) = NULL;
}
