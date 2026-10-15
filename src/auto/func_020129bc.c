/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02006194();                                /* extern */
M2C_UNK func_020061a8(s32);                         /* extern */
s32 func_02012a50();                                /* extern */
M2C_UNK func_020145a8(M2C_UNK *);                   /* extern */
s32 func_020147b8();                                /* extern */
extern void *data_020c6138;
extern M2C_UNK func_02012a44;

s32 func_020129bc(void) {
    s32 temp_r4;
    s32 var_r5;

    var_r5  = 1;
    temp_r4 = func_02006194();
    if (M2C_FIELD(data_020c6138, u16 *, 0x526) == 0) {
        M2C_FIELD(data_020c6138, s32 *, 0x5E4) = 0;
        M2C_FIELD(data_020c6138, u16 *, 0x526) = 1U;
        if (func_020147b8() != 0) {
            func_020145a8(&func_02012a44);
            var_r5 = 0;
        } else {
            var_r5 = func_02012a50();
        }
    }
    func_020061a8(temp_r4);
    return var_r5;
}
