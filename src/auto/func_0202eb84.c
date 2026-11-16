/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_020537c4(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020730bc();                            /* extern */
extern s32 data_02100bb0;
extern M2C_UNK data_02100bb4;

void func_0202eb84(void) {
    if (data_02100bb0 == 0) {
        return;
    }
    func_020730bc();
    func_020537c4(&data_02100bb4, 0, 0x50);
}
