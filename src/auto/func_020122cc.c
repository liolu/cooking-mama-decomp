#include "m2c.h"

extern void *data_020c6090;

void func_020122cc(void *arg0) {
    void *var_r1;
    void *var_r2;

    var_r2 = data_020c6090;
    if (var_r2 == NULL) {
        data_020c6090 = arg0;
    } else {
        var_r1 = M2C_FIELD(var_r2, void **, 0x4BC);
        if (var_r1 != NULL) {
            do {
                var_r2 = var_r1;
                var_r1 = M2C_FIELD(var_r1, void **, 0x4BC);
            } while (var_r1 != NULL);
        }
        M2C_FIELD(var_r2, void **, 0x4BC) = arg0;
    }
    M2C_FIELD(arg0, s32 *, 0x4BC) = 0;
}
