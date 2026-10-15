/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200ebac(M2C_UNK *);                       /* extern */
s32 func_0200f7c0(M2C_UNK *, u16, u16, u16, s32);   /* extern */
M2C_UNK func_0201256c(M2C_UNK, s32);                /* extern */
extern u16 data_02084eb4;
extern u16 data_02084eb8;
extern u16 data_02084ebc;
extern u16 data_02084ec0;
extern M2C_UNK func_02013aac;

void func_02014324(void) {
    func_0201256c(0x80, func_0200ebac(&func_02013aac));
    func_0201256c(0x1D, func_0200f7c0(&func_02013aac, data_02084ec0, data_02084eb8, data_02084eb4, (s32) data_02084ebc));
}
