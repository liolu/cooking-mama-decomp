/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02001bf8(M2C_UNK);
void func_0200660c(M2C_UNK);

extern s32 data_02084e84;
extern s32 data_020c2b70;
extern s32 data_020c2b74;
extern s32 data_020c2b78;

void func_02002e0c(void) {
    if (data_02084e84 != -1) {
        func_0200660c(data_02084e84);
    }
    func_02001bf8(data_020c2b78);
    data_020c2b78 = 0;
    data_020c2b74 = 0;
    data_020c2b70 = 0;
}
