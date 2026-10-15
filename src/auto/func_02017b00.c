#include "m2c.h"

extern void *data_020c6274;

void func_02017b00(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 2);
    switch (temp_r0) {                              /* irregular */
        case 0:
            return;
        case 8:
            M2C_FIELD(data_020c6274, s32 *, 4) = 4;
            M2C_FIELD(data_020c6274, s32 *, 0) = 4;
            return;
    }
}
