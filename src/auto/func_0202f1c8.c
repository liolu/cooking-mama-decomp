/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

u16 func_02003aa0();                                /* extern */
M2C_UNK func_0200c6f4(u16);                         /* extern */
M2C_UNK func_0200c704(u16);                         /* extern */
M2C_UNK func_0200cc94(s32);                         /* extern */
extern u16 data_02100c94;

void func_0202f1c8(void) {
    data_02100c94 = func_02003aa0();
    func_0200c704(data_02100c94);
    func_0200cc94(0x901);
    func_0200c6f4(data_02100c94);
}
