#include "engine.h"
#include "m2c.h"

M2C_UNK func_020193f4(void);
M2C_UNK func_0202f7e0(void);

s32 func_0201943c(void) {
    s32 temp_r4;
    s32 var_r0;
    s32 var_r2;
    s32 var_r3;
    u8 temp_r1;

    temp_r4 = func_020193f4();
    var_r0  = func_0202f7e0();
    var_r2  = 0;
    var_r3  = 0;
    if (temp_r4 > 0) {
        do {
            temp_r1 = M2C_FIELD(var_r0, u8 *, 0xAE);
            var_r3 += 1;
            var_r0 += 3;
            if ((s32) temp_r1 > var_r2) {
                var_r2 = (s32) temp_r1;
            }
        } while (var_r3 < temp_r4);
    }
    return var_r2;
}
