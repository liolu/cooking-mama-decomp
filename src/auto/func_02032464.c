/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202ebc4(M2C_UNK);                     /* extern */
void *func_0202f368();                              /* extern */

void func_02032464(void) {
    s16 temp_r0;

    temp_r0 = M2C_FIELD(func_0202f368(), s16 *, 0x32);
    if (temp_r0 == 0) {
        func_0202ebc4(0x2C);
        return;
    }
    if (temp_r0 == 1) {
        func_0202ebc4(0x2D);
        return;
    }
    func_0202ebc4(0x2E);
}
