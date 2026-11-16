/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
void *func_0202f368();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02038394(M2C_UNK);                     /* extern */
M2C_UNK func_02058ac0();                            /* extern */
M2C_UNK func_0206ce78(void *, M2C_UNK);             /* extern */
M2C_UNK func_0206df1c(M2C_UNK *);                   /* extern */
void *func_0206eab8();                              /* extern */
extern M2C_UNK data_02111980;
extern M2C_UNK data_02111a50;
extern M2C_UNK func_02038288;
extern M2C_UNK func_02058a78;

void func_02058d94(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02111a50);
    func_0206ce78(temp_r4 + 0x68, 0xA);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x384);
    func_0206df1c(&data_02111980);
    temp_r0 = func_0206eab8();
    M2C_FIELD(temp_r0, u32 *, 0) =
        (u32) ((M2C_FIELD(temp_r0, s32 *, 4) * M2C_FIELD(temp_r0, u32 *, 0)) + M2C_FIELD(temp_r0, s32 *, 8));
    M2C_FIELD(temp_r4, s32 *, 0x84) = (s32) (u16) ((u32) (((u32) M2C_FIELD(temp_r0, u32 *, 0) >> 0x10) * 3) >> 0x10);
    func_02058ac0();
    M2C_FIELD(temp_r4, M2C_UNK **, 0) = &func_02058a78;
}
