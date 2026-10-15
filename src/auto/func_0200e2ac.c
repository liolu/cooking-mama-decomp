/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005404(M2C_UNK *, u16 *, M2C_UNK);   /* extern */
s32 func_020054b8(M2C_UNK *, u16 **, M2C_UNK);      /* extern */
M2C_UNK func_02005818(u16 *, M2C_UNK);              /* extern */
extern M2C_UNK data_020c5570;

u16 *func_0200e2ac(void) {
    u16 *sp0;

    if (func_020054b8(&data_020c5570, &sp0, 0) == 0) {
        return NULL;
    }
    func_02005818(sp0, 2);
    if (*sp0 & 0x8000) {
        return sp0;
    }
    func_02005404(&data_020c5570, sp0, 1);
    return NULL;
}
