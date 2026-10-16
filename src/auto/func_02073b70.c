/* compiler: 1.2/sp2p3 */
#include "engine.h"
#include "m2c.h"

void func_0207329c(void *);
void *func_0207494c(s32 *, s32, s32, s32, s32);
u32 func_02074a98(s32, s32);
M2C_UNK func_02076060(s32, void *);
extern M2C_UNK data_021144e4;

s32 func_02073b70(s32 arg0, s32 *arg1, s32 arg2) {
    u32 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0207494c(arg1, arg2 + 0x14, (s32) func_0207329c, 0, 0);
    if (temp_r0 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r0, s32 *, 0xC)  = 0;
    M2C_FIELD(temp_r0, s32 *, 0x10) = arg0;
    M2C_FIELD(temp_r0, u32 *, 8)    = 0U;
    temp_r0_2                       = func_02074a98((s32) (temp_r0 + 0x14), arg2);
    if (temp_r0_2 == 0) {
        return 0;
    }
    M2C_FIELD(temp_r0, u32 *, 8) = temp_r0_2;
    func_02076060((arg0 * 0x24) + (s32) &data_021144e4 + 0xC, temp_r0);
    return 1;
}
