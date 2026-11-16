/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205a470 from projets/children-of-mana/src/auto/func_0205a470.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef volatile u32 vu32;
extern void func_020064d4(u32 dmaNo, s32 timing);
extern void func_02006464(u32 dmaNo, const void *src, u32 size, u32 mode);
extern void func_01ff82c0(u32 dmaNo, const void *src, void *dest, u32 ctrl);
void func_02006c1c(u32 dmaNo, const void *src, void *dest, u32 size) {
    vu32 *reg;

    func_020064d4(dmaNo, -1);
    func_02006464(dmaNo, src, size, 0x1000000);
    if (size == 0) {
        return;
    }
    reg = (vu32 *) 0x040000b0 + (dmaNo * 3 + 2);
    while (*reg & 0x80000000) {
    }
    func_01ff82c0(dmaNo, src, dest, 0xaf000001);
}
