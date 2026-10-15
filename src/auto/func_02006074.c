/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038e8(M2C_UNK);                     /* extern */
M2C_UNK func_020039ec(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_02005fd0(M2C_UNK);                     /* extern */
extern u16 data_020c2f04;
extern s32 data_020c2f08;
extern M2C_UNK data_020c2f0c;
extern M2C_UNK func_02005fec;

void func_02006074(void) {
    if (data_020c2f04 != 0) {
        return;
    }
    data_020c2f04 = 1;
    func_02005fd0(0);
    M2C_FIELD(&data_020c2f0c, s32 *, 0) = 0;
    M2C_FIELD(&data_020c2f0c, s32 *, 4) = 0;
    *(s16 *) 0x04000102                 = 0;
    *(s16 *) 0x04000100                 = 0;
    *(s16 *) 0x04000102                 = 0xC1;
    func_020039ec(8, &func_02005fec);
    func_020038e8(8);
    data_020c2f08 = 0;
}
