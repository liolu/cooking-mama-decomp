/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02006194(void);
void func_020061a8(M2C_UNK);

extern void *data_020c613c;

void func_02010dcc(s32 arg0) {
    s32 temp_r0;

    temp_r0                                 = func_02006194();
    M2C_FIELD(data_020c613c, s32 *, 0x14E4) = arg0;
    func_020061a8(temp_r0);
}
