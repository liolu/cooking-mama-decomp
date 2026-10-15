/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern u8 data_02113998;
extern M2C_UNK data_0211399c;

void func_0206e6a4(void) {
    data_02113998 = 0;
    if (M2C_FIELD(&data_0211399c, u16 *, 4) == 0) {
        return;
    }
    if (M2C_FIELD(&data_0211399c, u16 *, 0xC) == 0) {
        return;
    }
    if (M2C_FIELD(&data_0211399c, u16 *, 6) != 0) {
        return;
    }
    if (M2C_FIELD(&data_0211399c, u16 *, 0xE) != 0) {
        return;
    }
    if ((s32) M2C_FIELD(&data_0211399c, u16 *, 0) > (s32) (M2C_FIELD(&data_0211399c, u16 *, 8) + 1)) {
        data_02113998 |= 8;
    } else if ((s32) M2C_FIELD(&data_0211399c, u16 *, 0) < (s32) (M2C_FIELD(&data_0211399c, u16 *, 8) - 1)) {
        data_02113998 |= 4;
    }
    if ((s32) M2C_FIELD(&data_0211399c, u16 *, 2) > (s32) (M2C_FIELD(&data_0211399c, u16 *, 0xA) + 1)) {
        data_02113998 |= 2;
        return;
    }
    if ((s32) M2C_FIELD(&data_0211399c, u16 *, 2) < (s32) (M2C_FIELD(&data_0211399c, u16 *, 0xA) - 1)) {
        data_02113998 |= 1;
    }
}
