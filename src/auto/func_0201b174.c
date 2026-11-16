/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019684(s32, s32);                        /* extern */
void *func_020197fc();                              /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
M2C_UNK func_0201f4ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_020537ac(s32, M2C_UNK *);              /* extern */
M2C_UNK func_020537b8(s32, s32);                    /* extern */
extern M2C_UNK data_020a9834;
extern M2C_UNK data_020d3734;

void func_0201b174(void) {
    void *temp_r0;
    void *temp_r0_2;

    temp_r0 = func_020197fc();
    if (M2C_FIELD(temp_r0, s16 *, 0x16) == 3) {
        temp_r0_2 = func_0201f4a0(7);
        func_020537ac(M2C_FIELD(temp_r0_2, s32 *, 0x18), &data_020a9834);
        func_020537b8(M2C_FIELD(temp_r0_2, s32 *, 0x18),
                      func_02019684(M2C_FIELD(temp_r0, s32 *, 4), M2C_FIELD(temp_r0, s32 *, 8)));
        func_0201f4ec(7, &data_020d3734);
        return;
    }
    M2C_FIELD(func_0201f4a0(4), s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x24), s32 *, 4);
    func_0201f4ec(4, &data_020d3734);
}
