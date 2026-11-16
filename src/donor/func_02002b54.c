/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020585f0 from projets/children-of-mana/src/auto/func_020585f0.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
extern u32 data_02084e84;
extern void func_020069ec(const void *src, void *dest, u32 size);
extern void func_020066a0(u32 dmaNo, const void *src, void *dest, u32 size, void (*callback)(void *), void *arg);
static inline void UnkGxCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (dmaNo != -1) {
        func_020066a0(dmaNo, src, dest, size, 0, 0);
    } else {
        func_020069ec(src, dest, size);
    }
}
void func_02002b54(const void *src, u32 destSlotAddr, u32 size) {
    UnkGxCopy32Async(data_02084e84, src, (void *) (0x68a0000 + destSlotAddr), size);
}
