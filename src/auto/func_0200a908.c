/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02007f64();                            /* extern */
s32 func_02008148(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_02008170(M2C_UNK, M2C_UNK *);          /* extern */
extern u16 data_020c4bb0;
extern M2C_UNK data_020c4bb4;
extern M2C_UNK func_0200a998;

void func_0200a908(void) {
    if (data_020c4bb0 != 0) {
        return;
    }
    data_020c4bb0 = 1;
    func_02007f64();
    M2C_FIELD(&data_020c4bb4, s16 *, 0x32) = 0;
    M2C_FIELD(&data_020c4bb4, s16 *, 0x36) = 0;
    M2C_FIELD(&data_020c4bb4, s16 *, 0xC)  = 0;
    M2C_FIELD(&data_020c4bb4, s32 *, 0)    = 0;
    M2C_FIELD(&data_020c4bb4, s32 *, 0x10) = 0;
    M2C_FIELD(&data_020c4bb4, s16 *, 0x30) = 0;
    M2C_FIELD(&data_020c4bb4, s16 *, 0x34) = 0;
    do {

    } while (func_02008148(6, 1) == 0);
    func_02008170(6, &func_0200a998);
}
