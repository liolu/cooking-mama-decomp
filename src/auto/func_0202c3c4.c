/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_02000f58(M2C_UNK);                     /* extern */
M2C_UNK func_02000f74(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_02001700(M2C_UNK);                     /* extern */
M2C_UNK func_0200177c(M2C_UNK);                     /* extern */
M2C_UNK func_02001848(M2C_UNK);                     /* extern */
M2C_UNK func_0200193c(M2C_UNK);                     /* extern */
M2C_UNK func_02001d0c(M2C_UNK);                     /* extern */
M2C_UNK func_02001e78(M2C_UNK);                     /* extern */
M2C_UNK func_0202c240();                            /* extern */
M2C_UNK func_0206ed08(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_0202c3c4(void) {
    func_0200193c(1);
    func_02001e78(2);
    func_02001d0c(0x50);
    func_02001848(0x20);
    func_02000f74(1, 0, 1);
    *(volatile s32 *) 0x04000000 &= 0xFFCFFFEF;
    func_0200177c(4);
    func_02001700(8);
    func_02000f58(0);
    *(volatile s32 *) 0x04001000 &= 0xFFCFFFEF;
    func_0202c240();
    func_0206ed08(0, 0xB, 0x20000);
    func_0206ed08(1, 0xB, 0x4000);
    func_0206ed08(2, 7, 0x14000);
    func_0206ed08(3, 7, 0x20000);
}
