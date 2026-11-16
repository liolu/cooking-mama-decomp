/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

void *func_0202f35c();                              /* extern */
M2C_UNK func_0202f3a8();                            /* extern */
extern void *data_02100c98;

void func_0202f430(void) {
    void *var_r5;

    var_r5 = func_0202f35c();
loop_1:
    var_r5 = M2C_FIELD(var_r5, void **, 8);
    if (var_r5 != NULL) {
        data_02100c98 = var_r5;
        if (M2C_FIELD(var_r5, u16 *, 0x1A) == 0) {
            M2C_FIELD(var_r5, M2C_UNK(**)(), 0)();
        }
        goto loop_1;
    }
    data_02100c98 = func_0202f35c();
    func_0202f3a8();
}
