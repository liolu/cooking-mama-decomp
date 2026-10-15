/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006e70(s32, M2C_UNK);                /* extern */
extern s32 data_02114088;

void func_02073200(s32 arg0) {
    if (arg0 == 0) {
        return;
    }
    func_02006e70(arg0, 0);
    data_02114088 &= ~arg0;
}
