/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0202b1a0(M2C_UNK *);                   /* extern */
M2C_UNK func_0202dcb0(M2C_UNK, s32);                /* extern */
extern s32 data_0210c8ec;
extern void *data_0210c8f0;
extern s32 data_0210c8fc;
extern M2C_UNK data_0210c900;
extern M2C_UNK data_0210c904;
extern M2C_UNK data_0210c908;
extern M2C_UNK data_0210c90c;
extern M2C_UNK data_0210c910;
extern M2C_UNK data_0210c914;

void func_02037b8c(void) {
    if (data_0210c8fc & 1) {
        func_0202b1a0(&data_0210c904);
    }
    if (data_0210c8fc & 2) {
        func_0202b1a0(&data_0210c914);
        if (M2C_FIELD(data_0210c8f0, s16 *, 0x24) & 0x10) {
            func_0202dcb0(4, data_0210c8ec);
        }
    }
    func_0202b1a0(&data_0210c900);
    func_0202b1a0(&data_0210c908);
    func_0202b1a0(&data_0210c90c);
    func_0202b1a0(&data_0210c910);
}
