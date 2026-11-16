/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202e680();                            /* extern */
extern s32 data_020c8184;

void func_0201803c(void) {
    if (data_020c8184 == 0) {
        return;
    }
    func_0202e680();
    data_020c8184 = 0;
}
