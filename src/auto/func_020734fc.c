/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02075e94(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_02075ec4(void *);                      /* extern */

void func_020734fc(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x2E)  = 0;
    M2C_FIELD(arg0, s8 *, 0x2D)  = 0;
    M2C_FIELD(arg0, s8 *, 0x2F)  = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x3E) = 0;
    M2C_FIELD(arg0, s8 *, 0x40)  = 0x7F;
    M2C_FIELD(arg0, s8 *, 0x41)  = 0x7F;
    func_02075ec4(arg0 + 0x1C);
    func_02075e94(arg0 + 0x1C, 0x7F00, 1);
}
