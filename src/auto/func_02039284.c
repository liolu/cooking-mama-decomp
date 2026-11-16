/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f368();                              /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
void *func_0206e764();                              /* extern */
extern void *data_0210cc20;
extern s32 *data_0210cc24;
extern M2C_UNK func_020390ac;

void func_02039284(void) {
    s32 temp_r1;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    temp_r0 = func_0206e764();
    temp_r1 = M2C_FIELD(temp_r4, s32 *, 0x30);
    if (((s32) M2C_FIELD(temp_r4, s32 *, 0x28) <
         (s32) (*data_0210cc24 * M2C_FIELD((data_0210cc20 + (temp_r1 * 2)), s16 *, 0xC))) ||
        ((s32) (M2C_FIELD(data_0210cc20, s16 *, 2) - 1) <= temp_r1)) {
        M2C_FIELD(temp_r4, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x2C) + 1);
        if ((M2C_FIELD(temp_r4, s32 *, 0x2C) != 0x64) && (M2C_FIELD(temp_r0, u16 *, 4) != 1)) {
            return;
        }
        M2C_FIELD(temp_r4, s32 *, 0x2C) = 0;
        func_02038384(1);
        M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_020390ac;
        return;
    }
    func_02038384(1);
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_020390ac;
}
