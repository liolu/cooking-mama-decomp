/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_0200f27c(M2C_UNK *);                       /* extern */
extern s32 *data_020c6274;
extern M2C_UNK func_02016ee0;

void func_02016ca4(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        *data_020c6274 = 4;
        return;
    }
    if (func_0200f27c(&func_02016ee0) != 2) {
        *data_020c6274 = 4;
    }
}
