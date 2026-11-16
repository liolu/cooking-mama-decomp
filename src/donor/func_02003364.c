/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020587c4 from projets/children-of-mana/src/auto/func_020587c4.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned long u32;
extern void func_020069ec(register const void *srcp, register void *destp, register u32 size);
typedef void (*MIDmaCallback)(void *);
extern void func_020066a0(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void func_02003364(void *src, u32 offset, u32 size);
static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    if (dmaNo != -1) {
        func_020066a0(dmaNo, src, dest, size, callback, arg);
    } else {
        func_020069ec(src, dest, size);
    }
}
extern u32 data_020c2b84;
extern u32 data_02084e84;
#pragma thumb off
void func_02003364(void *src, u32 offset, u32 size) {
    GXi_DmaCopy32Async(data_02084e84, src, (void *) (data_020c2b84 + offset), size, ((void *) 0), ((void *) 0));
}
