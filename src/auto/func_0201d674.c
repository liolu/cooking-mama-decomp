/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_02019684(s32, s32);                        /* extern */
void *func_020197fc();                              /* extern */
void *func_0201f4a0(M2C_UNK);                       /* extern */
M2C_UNK func_0201f4ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_0202dd68(M2C_UNK);                     /* extern */
M2C_UNK func_020537ac(s32, s32);                    /* extern */
extern M2C_UNK data_020d3a7c;

void func_0201d674(void) {
    void *temp_r4;
    void *temp_r5;

    temp_r5 = func_020197fc();
    func_0202dd68(4);
    if (M2C_FIELD(temp_r5, s16 *, 0x16) == 3) {
        temp_r4 = func_0201f4a0(0x18);
        func_020537ac(M2C_FIELD(temp_r4, s32 *, 0x18),
                      func_02019684(M2C_FIELD(temp_r5, s32 *, 4), M2C_FIELD(temp_r5, s32 *, 8)));
        func_0201f4ec(0x18, &data_020d3a7c);
        return;
    }
    M2C_FIELD(func_0201f4a0(0x17), s32 *, 0x18) = (s32) (M2C_FIELD(M2C_FIELD(temp_r5, void **, 0x24), s32 *, 4) + 1);
    func_0201f4ec(0x17, &data_020d3a7c);
}
