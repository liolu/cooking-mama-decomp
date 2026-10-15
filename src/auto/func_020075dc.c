/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

extern s32 data_020c2f6c;
extern s32 data_020c2f70;

void func_020075dc(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_02006194();
    if (data_020c2f70 == 0) {
        data_020c2f70 = arg0;
        data_020c2f6c = arg0;
    } else {
        *(M2C_UNK *) data_020c2f70 = arg0;
        data_020c2f70              = arg0;
    }
    *(M2C_UNK *) arg0 = 0;
    func_020061a8(temp_r0);
}
