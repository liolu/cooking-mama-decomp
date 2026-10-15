/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_02075ef8();            /* extern */
M2C_UNK func_02075f7c();   /* extern */
extern M2C_UNK data_02114098;

void func_02073440(void *arg0) {
    void *var_r1;

    var_r1 = func_02075ef8(&data_02114098, 0);
    if (var_r1 != NULL) {
    loop_2:
        if ((u32) M2C_FIELD(arg0, u8 *, 0x3D) >= (u32) M2C_FIELD(var_r1, u8 *, 0x3D)) {
            var_r1 = func_02075ef8(&data_02114098);
            if (var_r1 != NULL) {
                goto loop_2;
            }
        }
    }
    func_02075f7c(&data_02114098, var_r1, arg0);
}
