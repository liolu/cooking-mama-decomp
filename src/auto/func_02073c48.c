/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020731c4(s32);                         /* extern */
M2C_UNK func_02075f10(M2C_UNK *, void *);           /* extern */
extern M2C_UNK data_02114964;

void func_02073c48(void *arg0) {
    func_020731c4(M2C_FIELD(arg0, s32 *, 0x40));
    func_02075f10(&data_02114964, arg0);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~1);
}
