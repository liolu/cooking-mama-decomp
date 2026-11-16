/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0202bdf4(void *);                          /* extern */
void *func_0202f368();                              /* extern */
extern M2C_UNK data_0210b8ac;

void func_020327f8(void) {
    void *temp_r0;

    temp_r0                         = func_0202f368();
    M2C_FIELD(temp_r0, s16 *, 0x1C) = (s16) (M2C_FIELD(temp_r0, s16 *, 0x1C) + 1);
    if (M2C_FIELD(temp_r0, s16 *, 0x1C) == 0x30) {
        M2C_FIELD(M2C_FIELD(&data_0210b8ac, void **, 0xE0), s16 *, 0xA) = 0x26;
    }
    if (func_0202bdf4(M2C_FIELD(&data_0210b8ac, void **, 0xE0)) == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0210b8ac, void **, 0xE0), s16 *, 0xA) = 0x22;
    M2C_FIELD(temp_r0, s32 *, 0x10)                                 = 1;
}
