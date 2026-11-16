/* compiler: 1.2/sp2p3 -nointerworking */
#include "m2c.h"

M2C_UNK func_0200107c(M2C_UNK, u16);                /* extern */
M2C_UNK func_02003920(M2C_UNK);                     /* extern */
M2C_UNK func_020039ec(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK func_0202f208;

void func_0202f000(void) {
    u16 temp_r1;

    func_020039ec(1, &func_0202f208);
    func_02003920(1);
    temp_r1                      = *(volatile u16 *) 0x04000208;
    *(volatile u16 *) 0x04000208 = 1;
    func_0200107c(1, temp_r1);
}
