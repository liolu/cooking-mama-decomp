#include "m2c.h"

extern M2C_UNK data_021008bc;

s32 func_0202df58(s32 arg0) {
    return *((M2C_UNK *) ((s8 *) &data_021008bc + (arg0 * 4)));
}
