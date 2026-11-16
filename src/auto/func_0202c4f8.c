/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02001338();                            /* extern */
M2C_UNK func_02001828(s32);                         /* extern */
M2C_UNK func_02006a04(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_0202c4f8(void) {
    func_02001828(0x1FF);
    func_02006a04(0, 0x06800000, 0xA4000);
    func_02001338();
    func_02006a04(0xC0, 0x07000000, 0x400);
    func_02006a04(0, 0x05000000, 0x400);
    func_02006a04(0xC0, 0x07000400, 0x400);
    func_02006a04(0, 0x05000400, 0x400);
}
