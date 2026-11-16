/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef s32 (*drv_fn)(void *, s32, s32, s32);

s32 func_02006194(void);
void func_020061a8(s32 s);
void func_02004b98(void *p);

void func_02008d9c(u8 *obj, s32 arg1, s32 arg2) {
    u8 *dev;
    s32 res;
    s32 irq;

    dev                   = *(u8 **) obj;
    *(u32 *) (dev + 0x1C) = *(u32 *) (dev + 0x1C) | 0x200;
    res                   = ((drv_fn) * (u32 *) (dev + 0x50))(dev, arg1, *(s32 *) (obj + 4), arg2);
    switch (res) {
        case 0:
        case 1:
            *(u32 *) (dev + 0x1C) = *(u32 *) (dev + 0x1C) & ~0x200;
            break;
        case 6:
            irq = func_02006194();
            while (*(u32 *) (dev + 0x1C) & 0x200) {
                func_02004b98(dev + 0xc);
            }
            func_020061a8(irq);
            break;
    }
    *(s32 *) (obj + 4) = *(s32 *) (obj + 4) + arg2;
}
