/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
M2C_UNK func_0202dcb0(M2C_UNK);                     /* extern */
extern M2C_UNK data_0210bc6c;
extern s32 data_0210bc70;

void func_02034174(void) {
    if (data_0210bc70 != -1) {
        func_0202dcb0(3);
        data_0210bc70 = -1;
    }
    func_0202b1a0(&data_0210bc6c);
}
