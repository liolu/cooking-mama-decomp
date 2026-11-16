/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020197fc();                            /* extern */
s32 func_02019808();                                /* extern */
M2C_UNK func_02019818(M2C_UNK);                     /* extern */
M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
s32 func_0201e140();                                /* extern */
M2C_UNK func_02020884();                            /* extern */
M2C_UNK func_020208a8(void *);                      /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038384(M2C_UNK);                     /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_0206e764();                            /* extern */
extern s32 data_020d414c;
extern s32 data_020d4150;
extern M2C_UNK *data_020d4154;
extern M2C_UNK data_020d42f8;
extern M2C_UNK func_02019c34;
extern M2C_UNK func_02038288;

void func_02020960(void) {
    M2C_UNK var_r0;
    u32 temp_r1;
    void *temp_r4;

    func_0206e764();
    temp_r4 = func_0202f368();
    func_020197fc();
    temp_r1 = M2C_FIELD(temp_r4, u32 *, 0x20);
    switch (temp_r1) {
        case 0:
            func_020208a8(temp_r4);
            func_02019b4c(&data_020d42f8);
            func_02020884();
            func_0202f564(&func_02038288, 0x15);
            func_02038394(0x384);
            M2C_FIELD(temp_r4, u32 *, 0x20) = (u32) (M2C_FIELD(temp_r4, u32 *, 0x20) + 1);
            return;
        case 1:
            if (func_0201e140() != 0) {
                return;
            }
            func_02038384(1);
            M2C_FIELD(temp_r4, u32 *, 0x20) = (u32) (M2C_FIELD(temp_r4, u32 *, 0x20) + 1);
            return;
        case 2:
            if (data_020d414c == 0) {
                M2C_FIELD(temp_r4, u32 *, 0x20) = (u32) (temp_r1 + 1);
            }
            return;
        case 3:
            func_02038384(0);
            var_r0 = 0;
            if ((s32) data_020d4150 < 2) {
                var_r0 = 2;
            } else if ((s32) data_020d4150 < 5) {
                var_r0 = 1;
            }
            func_02019818(var_r0);
            M2C_FIELD(temp_r4, u32 *, 0x20) = (u32) (M2C_FIELD(temp_r4, u32 *, 0x20) + 1);
            return;
        case 4:
            if (func_02019808() == 3) {
                data_020d4154                   = &func_02019c34;
                M2C_FIELD(temp_r4, u32 *, 0x20) = 0x63U;
            }
            return;
        default:
            return;
    }
}
