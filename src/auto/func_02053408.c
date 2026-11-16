/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02053080();                            /* extern */
M2C_UNK func_020533b8();                            /* extern */
void *func_0206eab8();                              /* extern */
extern s16 data_02110da8;
extern M2C_UNK func_02038288;
extern M2C_UNK func_020533d8;

void func_02053408(void) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s32 *, 0x20) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x24) = 0;
    M2C_FIELD(temp_r0, s16 *, 0x28) = 0;
    if ((data_02110da8 == 0) || (data_02110da8 == 3)) {
        temp_r0_2 = func_0206eab8();
        M2C_FIELD(temp_r0_2, u32 *, 0) =
            (u32) ((M2C_FIELD(temp_r0_2, s32 *, 4) * M2C_FIELD(temp_r0_2, u32 *, 0)) + M2C_FIELD(temp_r0_2, s32 *, 8));
        M2C_FIELD(temp_r0, s16 *, 0x26) =
            (s16) ((u16) ((u32) (((u32) M2C_FIELD(temp_r0_2, u32 *, 0) >> 0x10) * 4) >> 0x10) + 7);
    } else {
        temp_r0_3 = func_0206eab8();
        M2C_FIELD(temp_r0_3, u32 *, 0) =
            (u32) ((M2C_FIELD(temp_r0_3, s32 *, 4) * M2C_FIELD(temp_r0_3, u32 *, 0)) + M2C_FIELD(temp_r0_3, s32 *, 8));
        M2C_FIELD(temp_r0, s16 *, 0x26) =
            (s16) ((u16) ((u32) (((u32) M2C_FIELD(temp_r0_3, u32 *, 0) >> 0x10) * 0xE) >> 0x10) + 0xA);
    }
    func_020533b8();
    func_02053080();
    func_0202f564(&func_02038288, 0x15);
    func_02038384(0);
    func_02038394(0x3E8);
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &func_020533d8;
}
