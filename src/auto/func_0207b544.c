/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0207b544(void *arg0, s32 arg1, s32 arg2) {
    s32 var_lr;
    void *var_ip;

    var_ip = arg0;
    var_lr = 0;
loop_1:
    if ((arg1 <= (s32) M2C_FIELD(var_ip, u16 *, 0)) && (arg2 <= (s32) M2C_FIELD(var_ip, u16 *, 2))) {
        return (var_lr * 6) + (s32) arg0;
    }
    var_lr += 1;
    var_ip += 6;
    if (var_lr >= 4) {
        return (s32) (arg0 + 0x12);
    }
    goto loop_1;
}
