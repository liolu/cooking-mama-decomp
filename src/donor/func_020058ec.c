/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020be52c from projets/eyeshield-21/src/auto/func_020be52c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *func_02005bcc(u32 id);
extern void *func_02005bb8(u32 id);
extern void func_02005974(u32 id, void *lo);
extern void *func_02005bcc(u32 id);
extern void *func_02005bb8(u32 id);
extern void func_02005974(u32 id, void *lo);
void *func_020058ec(u32 id, u32 size, u32 align) {
    void *ptr = func_02005bb8(id);
    u32 newLo;

    if (!ptr) {
        return 0;
    }

    ptr   = (void *) (((u32) ptr + align - 1) & ~(align - 1));
    newLo = (u32) ((u8 *) ptr + size + align - 1) & ~(align - 1);

    if (newLo > (u32) func_02005bcc(id)) {
        return 0;
    }
    func_02005974(id, (void *) newLo);
    return ptr;
}
