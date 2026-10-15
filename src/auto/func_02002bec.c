/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02001674(M2C_UNK);
void func_0200660c(M2C_UNK);

extern s32 data_02084e84;
extern s32 data_020c2b64;

void func_02002bec(void) {
    if (data_02084e84 != -1) {
        func_0200660c(data_02084e84);
    }
    func_02001674(data_020c2b64);
    data_020c2b64 = 0;
}
