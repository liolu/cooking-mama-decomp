/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202bfe4(void *);                      /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202ec14(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_02110b7c;
extern M2C_UNK func_020517bc;

s32 func_020519cc(u32 arg0) {
    void *temp_r4;

    temp_r4 = func_0202f368();
    if (arg0 >= 0xE10U) {
        M2C_FIELD(temp_r4, s32 *, 0x28) = 0;
        M2C_FIELD(temp_r4, s16 *, 0x30) = 0;
        func_0202c03c(M2C_FIELD(&data_02110b7c, void **, 0x10), 3);
        M2C_FIELD(temp_r4, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x24) & 0xFFFD);
        M2C_FIELD(temp_r4, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x24) & 0xFFFE);
        M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x14), s16 *, 6) =
            (s16) M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 6);
        M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x14), s16 *, 8) =
            (s16) M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x10), s16 *, 8);
        M2C_FIELD(M2C_FIELD(&data_02110b7c, void **, 0x14), s16 *, 0x1A) = 0x1F;
        func_0202ec14(0x5F);
        M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_020517bc;
        return 1;
    }
    if (arg0 >= 0x190U) {
        M2C_FIELD(temp_r4, s16 *, 0x30) = (s16) (M2C_FIELD(temp_r4, s16 *, 0x30) + 1);
        if ((s32) M2C_FIELD(temp_r4, s16 *, 0x30) >= 3) {
            M2C_FIELD(temp_r4, s16 *, 0x30) = 0;
            func_0202bfe4(M2C_FIELD(&data_02110b7c, void **, 0x10));
            M2C_FIELD(temp_r4, s32 *, 0x28) = 0;
            func_0202ec14(0x5E);
            M2C_FIELD(temp_r4, s32 *, 0x24) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x24) | 2);
        } else {
            func_0202ec14(0x5D);
            func_0202ec14(0x5D);
            func_0202ec14(0x5D);
        }
        return 1;
    }
    return 0;
}
