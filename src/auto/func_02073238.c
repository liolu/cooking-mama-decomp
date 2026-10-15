/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02073440(void *);                      /* extern */
M2C_UNK func_020734a0(M2C_UNK *, void *);           /* extern */
M2C_UNK func_02075f10(M2C_UNK *, void *);           /* extern */
extern M2C_UNK data_02114098;

void func_02073238(void *arg0, s8 arg1) {
    M2C_UNK *temp_r4;

    temp_r4 = M2C_FIELD(arg0, M2C_UNK **, 4);
    if (temp_r4 != NULL) {
        func_02075f10(temp_r4, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 4) = NULL;
    }
    func_02075f10(&data_02114098, arg0);
    M2C_FIELD(arg0, s8 *, 0x3D) = arg1;
    if (temp_r4 != NULL) {
        func_020734a0(temp_r4, arg0);
    }
    func_02073440(arg0);
}
