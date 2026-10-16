/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
extern u32 func_02001554();
extern void func_020035f4();
extern u32 data_020c2b80;
extern u32 data_020c2b94;
extern u32 data_020c2b90;
extern s32 data_020c2b8c;
extern const struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} data_02080650[16];

/* func_0214c6a8 from https://github.com/RonyxDumb/mkds src/arm9/0214c6a8_func_0214c6a8.c (license: none), reused by
 * tools/donor_match.py */
void func_020035f4() {
    u32 temp      = func_02001554();
    data_020c2b8c = (s32) temp;
    data_020c2b80 = (u32) (data_02080650[temp].blk1 << 0xC);
    data_020c2b90 = (u32) (data_02080650[temp].blk2 << 0xC);
    data_020c2b94 = (u32) (data_02080650[temp].szBlk1 << 0xC);
}
