/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*CB)(u32);
void func_02000b44(s32);
void func_02006440(void);
void func_0200c7d4(void);
u32 func_02006194(void);
void func_020061a8(u32);
void func_02004b98(void *);
void func_02004b18(void *);
void func_02004ae4(void *);
void func_0200ca98(s32);
void func_0200d82c(void *, s32, s32);
extern u8 data_020c4d00[];
extern u8 data_020c2c14[];

s32 func_0200cc94(s32 type) {
    u8 *c = data_020c4d00;
    u32 irq;
    CB cb;
    u32 arg;
    func_02000b44(0x2000b70);
    if (type == 0) {
        func_02006440();
    }
    func_0200c7d4();
    irq = func_02006194();
    while (*(u32 *) (c + 0x114) & 4) {
        func_02004b98(c + 0x10c);
    }
    *(u32 *) (c + 0x114) |= 4;
    *(u32 *) (c + 0x38) = 0;
    *(u32 *) (c + 0x3c) = 0;
    func_020061a8(irq);
    func_0200ca98(type);
    *(u32 *) (data_020c4d00 + 0x104) = *(u32 *) (data_020c2c14 + 4);
    func_0200d82c(c, 2, 1);
    *(u32 *) (*(u8 **) c + 0xc)  = 0;
    *(u8 **) (*(u8 **) c + 0x10) = c + 0x120;
    *(u32 *) (*(u8 **) c + 0x14) = 1;
    func_0200d82c(c, 6, 1);
    cb  = *(CB *) (c + 0x38);
    arg = *(u32 *) (c + 0x3c);
    irq = func_02006194();
    *(u32 *) (c + 0x114) &= ~0x4c;
    func_02004b18(c + 0x10c);
    if (*(u32 *) (c + 0x114) & 0x10) {
        func_02004ae4(c + 0x44);
    }
    func_020061a8(irq);
    if (cb != NULL) {
        cb(arg);
    }
    return **(s32 **) c == 0;
}
