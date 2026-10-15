#include "m2c.h"

void func_02079414(void *arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x30) = (void *) M2C_FIELD(arg0, void **, 0x70);
    M2C_FIELD(arg0, void **, 0x70) = arg1;
}
