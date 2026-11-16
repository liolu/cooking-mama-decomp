/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02017df0();                            /* extern */
extern s32 *data_020c6274;

void func_02016ee0(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        *data_020c6274 = 4;
        return;
    }
    *data_020c6274 = 1;
    func_02017df0();
}
