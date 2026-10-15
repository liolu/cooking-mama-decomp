/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200ebac(s32);                         /* extern */
s32 func_0200f184(s32, s32, u16);                   /* extern */
M2C_UNK func_020127c0(M2C_UNK);                     /* extern */
M2C_UNK func_02014324();                            /* extern */
extern u16 data_020c6130;
extern s32 data_020c6134;
extern void *data_020c6138;
extern void *data_020c613c;

s32 func_02012cc4(void) {
    s32 temp_r0;

    M2C_FIELD(data_020c6138, s16 *, 0x528) = 0;
    M2C_FIELD(data_020c6138, s16 *, 0x52A) = 0;
    M2C_FIELD(data_020c6138, s16 *, 0x526) = 0;
    M2C_FIELD(data_020c6138, s16 *, 0x548) = 0;
    func_020127c0(0xA);
    if (M2C_FIELD(data_020c613c, s32 *, 0x1320) == 0) {
        do {
            temp_r0 = func_0200f184(data_020c6134, M2C_FIELD(data_020c6138, s32 *, 0x508), data_020c6130);
        } while (temp_r0 == 4);
        if (temp_r0 != 2) {
            return 8;
        }
        func_0200ebac(M2C_FIELD(data_020c6138, s32 *, 0x508));
        M2C_FIELD(data_020c6138, s8 *, 0x50D) = 1;
        return 0;
    }
    func_0200ebac(M2C_FIELD(data_020c6138, s32 *, 0x508));
    M2C_FIELD(data_020c6138, s8 *, 0x50D) = 1;
    func_02014324();
    return 0;
}
