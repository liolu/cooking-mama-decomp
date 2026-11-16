/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202b004(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0202b4b8(void *);                      /* extern */
M2C_UNK func_0202bb50(void *, M2C_UNK);             /* extern */
M2C_UNK func_0202bc44(void *, u16);                 /* extern */
M2C_UNK func_0202bfe4(void *);                      /* extern */
M2C_UNK func_0202c03c(void *, M2C_UNK);             /* extern */

void func_0202c0ac(s32 arg0, void *arg1, s32 arg2, M2C_UNK arg3, s32 arg4, u16 arg5) {
    M2C_FIELD(arg1, s32 *, 0)    = arg0;
    M2C_FIELD(arg1, s32 *, 0x20) = arg2;
    if (M2C_FIELD(arg1, s32 *, 0) == 2) {
        func_0202b4b8(arg1);
    } else if (arg4 != -1) {
        func_0202bfe4(arg1);
    } else {
        func_0202c03c(arg1, arg3);
    }
    M2C_FIELD(arg1, u16 *, 0xE)  = 0x1000U;
    M2C_FIELD(arg1, u16 *, 0xC)  = (u16) M2C_FIELD(arg1, u16 *, 0xE);
    M2C_FIELD(arg1, s16 *, 0x1A) = 0x1F;
    func_0202b004(arg1, 0x1F, 0x1F, 0x1F);
    func_0202bc44(arg1, arg5);
    if (M2C_FIELD(func_020197fc(), s16 *, 0x1A) != 1) {
        return;
    }
    if (M2C_FIELD(arg1, s32 *, 0) != 4) {
        return;
    }
    func_0202bb50(arg1, 1);
}
