/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020015e8(M2C_UNK);
void func_0200660c(M2C_UNK);

extern s32 data_02084e84;
extern s32 data_020c2b7c;

void func_02002b08(void) {
    if (data_02084e84 != -1) {
        func_0200660c(data_02084e84);
    }
    func_020015e8(data_020c2b7c);
    data_020c2b7c = 0;
}
