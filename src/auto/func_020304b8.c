/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

s32 func_020166bc();                                /* extern */
s32 func_02016734(M2C_UNK *);                       /* extern */
s32 func_02018074(M2C_UNK);                         /* extern */
M2C_UNK func_020180a0(s32, M2C_UNK);                /* extern */
M2C_UNK func_02018230();                            /* extern */
s32 func_020184b4(M2C_UNK);                         /* extern */
s32 func_020185bc();                                /* extern */
extern M2C_UNK data_02081b18;
extern s16 data_0210b198;
extern s32 data_0210b19c;

void func_020304b8(void) {
    s32 temp_r0;

    temp_r0 = func_020166bc();
    switch (temp_r0) {                              /* irregular */
        case 0:
            if (func_020184b4(1) == 1) {
                return;
            }
            data_0210b198 = 1;
            data_0210b19c = 0;
            return;
        case 1:
            if (func_02016734(&data_02081b18) != 0) {
                return;
            }
            func_02018230();
            return;
        case 9:
            data_0210b198 = 2;
            if (func_02018074(4) == 0) {
                return;
            }
            func_020180a0(func_020185bc(), 0);
            return;
    }
}
