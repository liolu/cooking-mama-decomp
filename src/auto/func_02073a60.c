#include "m2c.h"

extern M2C_UNK data_021144ec;

u16 func_02073a60(s32 arg0) {
    return *((u16 *) ((s8 *) &data_021144ec + (arg0 * 0x24)));
}
