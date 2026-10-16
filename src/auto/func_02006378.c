/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 state);
extern u32 data_020c2f30;
extern u16 data_020c2f34[9];
u32 func_02006370(register u32 value);

/* func_02079f00 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_vramexclusive.c (license: none),
 * reused by tools/donor_match.py */
void func_02006378(u32 bank, u16 lockID) {
    u32 mask;
    u32 enabled = func_02006194();

    mask = bank & data_020c2f30 & 0x1ff;

    while (1) {
        s32 i = 31 - func_02006370(mask);
        if (i < 0) {
            break;
        }
        mask &= ~(1 << i);
        if (data_020c2f34[i] == lockID) {
            data_020c2f34[i] = 0;
            data_020c2f30 &= ~(1 << i);
        }
    }
    func_020061a8(enabled);
}
