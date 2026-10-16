/* compiler: 1.2/sp2p3 */
#include "engine.h"
#include "m2c.h"

void func_02004b98(s32);
s32 func_020093ec(void *);

s32 func_02009828(s32 arg0) {
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r5;
    u32 temp_r4;

    var_r5  = 0;
    temp_r4 = func_02006194();
    if (M2C_FIELD(arg0, volatile s32 *, 0xC) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        if (!(M2C_FIELD(arg0, volatile s32 *, 0xC) & 0x44)) {
            var_r5 = 1;
        } else {
            var_r5 = 0;
        }
        if (var_r5 != 0) {
            M2C_FIELD(arg0, volatile s32 *, 0xC) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0xC) | 4);
            do {
                func_02004b98(arg0 + 0x18);
            } while (!(M2C_FIELD(arg0, volatile s32 *, 0xC) & 0x40));
        } else {
            do {
                func_02004b98(arg0 + 0x18);
                if (M2C_FIELD(arg0, volatile s32 *, 0xC) & 1) {
                    var_r0_2 = 1;
                } else {
                    var_r0_2 = 0;
                }
            } while (var_r0_2 != 0);
        }
    }
    func_020061a8(temp_r4);
    if (var_r5 != 0) {
        return func_020093ec((void *) arg0);
    }
    if (M2C_FIELD(arg0, volatile s32 *, 0x14) == 0) {
        return 1;
    }
    return 0;
}
