/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0200193c(M2C_UNK);
void func_0200660c(M2C_UNK);

extern s32 data_02084e84;
extern s32 data_020c2b80;
extern s32 data_020c2b8c;
extern s32 data_020c2b90;
extern s32 data_020c2b94;

void func_02003420(void) {
    if (data_02084e84 != -1) {
        func_0200660c(data_02084e84);
    }
    func_0200193c(data_020c2b8c);
    data_020c2b94 = 0;
    data_020c2b90 = 0;
    data_020c2b80 = 0;
    data_020c2b8c = 0;
}
