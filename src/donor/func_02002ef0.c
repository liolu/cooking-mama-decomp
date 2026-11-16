/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205898c from projets/children-of-mana/src/auto/func_0205898c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned long u32;
typedef signed long s32;
extern u32 func_0200158c();
extern void func_02002ef0();
extern s32 data_020c2b78;
extern u32 data_020c2b74;
extern u32 data_020c2b70;
#pragma thumb off
void func_02002ef0() {
    data_020c2b78 = (s32) func_0200158c();
    switch (data_020c2b78) {
        case 0:
            break;
        case 0x10:
            data_020c2b74 = 0x06880000;
            data_020c2b70 = 0x0;
            break;
        case 0x40:
            data_020c2b74 = 0x06894000;
            data_020c2b70 = 0x4000;
            break;
        case 0x20:
        case 0x60:
            data_020c2b74 = 0x06890000;
            data_020c2b70 = 0x0;
            break;
    }
}
