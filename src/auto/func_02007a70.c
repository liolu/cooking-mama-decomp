/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02005818(void *, M2C_UNK);             /* extern */
extern void *data_020c4aa0;

s32 func_02007a70(void) {
    func_02005818(data_020c4aa0 + 4, 4);
    return M2C_FIELD(data_020c4aa0, s32 *, 4);
}
