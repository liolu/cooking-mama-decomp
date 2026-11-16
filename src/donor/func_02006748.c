/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02059b80 from projets/children-of-mana/src/auto/func_02059b80.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef volatile u32 vu32;
extern void func_0200660c(u32 dmaNo);
typedef void (*UnkDmaCallback)(void *arg);
extern void func_01ff8214(u32 dmaNo, volatile const void *src, void *dest, u32 ctrl);
extern void func_020039a0(u32 dmaNo, UnkDmaCallback callback, void *arg);
static inline void UnkCallCallback(UnkDmaCallback callback, void *arg) {
    if (callback) {
        callback(arg);
    }
}
static inline void UnkDmaFillAsync(u32 dmaNo, void *dest, u32 data, u32 ctrl) {
    u32 e                            = func_02006194();
    (((vu32 *) 0x040000e0)[(dmaNo)]) = data;
    func_01ff8214(dmaNo, &(((vu32 *) 0x040000e0)[(dmaNo)]), dest, ctrl);
    func_020061a8(e);
}
void func_02006748(u32 dmaNo, void *dest, u32 data, u32 size, UnkDmaCallback callback, void *arg) {
    if (size == 0) {
        UnkCallCallback(callback, arg);
        return;
    }
    func_0200660c(dmaNo);
    if (callback) {
        func_020039a0(dmaNo, callback, arg);
        {
            u32 e      = func_02006194();
            u32 ctrl   = 0xc5000000 | (size >> 2);
            vu32 *fill = &(((vu32 *) 0x040000e0)[(dmaNo)]);
            *fill      = data;
            func_01ff8214(dmaNo, fill, dest, ctrl);
            func_020061a8(e);
        }
    } else {
        UnkDmaFillAsync(dmaNo, dest, data, 0x85000000 | (size >> 2));
    }
}
extern void func_0200660c(u32 dmaNo);
