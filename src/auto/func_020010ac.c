/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* GX_Init from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;
extern void func_02006440(void);
extern u32 func_02003aa0(void);
extern u32 data_02084e84;
extern u16 data_020c2b40;
extern void func_02001230(void);
extern void func_02006914(u32 dmaNo, void *dest, u32 data, u32 size);
extern void func_020069d8(u32 data, void *dest, u32 size);
extern u32 data_02084e84;
extern u16 data_020c2b40;
void func_020010ac(void) {
    (*(vu16 *) 0x04000304) |= 0x8000;
    (*(vu16 *) 0x04000304) = ((*(vu16 *) 0x04000304) & ~0x20e) | 0x20e;
    (*(vu16 *) 0x04000304) |= 1;
    func_02001230();

    while (data_020c2b40 == 0) {
        s32 lockId = func_02003aa0();
        if (lockId == -3) {
            func_02006440();
        }
        data_020c2b40 = lockId;
    }

    (*(vu16 *) 0x04000004)          = 0;
    (*(u32 *) ((0x04000000) | 0x0)) = 0;

    if (data_02084e84 != -1) {
        func_02006914(data_02084e84, (void *) &(*(vu16 *) ((0x04000000) | 0x8)), 0, 0x60);
        (*(u16 *) ((0x04000000) | 0x6c)) = 0;
        func_02006914(data_02084e84, (void *) &(*(u32 *) ((0x04001000) | 0x0)), 0, 0x70);
    } else {
        func_020069d8(0, (void *) &(*(vu16 *) ((0x04000000) | 0x8)), 0x60);
        (*(u16 *) ((0x04000000) | 0x6c)) = 0;
        func_020069d8(0, (void *) &(*(u32 *) ((0x04001000) | 0x0)), 0x70);
    }

    (*(u16 *) ((0x04000000) | 0x20)) = 0x100;
    (*(u16 *) ((0x04000000) | 0x26)) = 0x100;
    (*(u16 *) ((0x04000000) | 0x30)) = 0x100;
    (*(u16 *) ((0x04000000) | 0x36)) = 0x100;
    (*(u16 *) ((0x04001000) | 0x20)) = 0x100;
    (*(u16 *) ((0x04001000) | 0x26)) = 0x100;
    (*(u16 *) ((0x04001000) | 0x30)) = 0x100;
    (*(u16 *) ((0x04001000) | 0x36)) = 0x100;
}
