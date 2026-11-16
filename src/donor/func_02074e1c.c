/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02075e24 from projets/children-of-mana/src/auto/func_02075e24.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 irq_flag);
extern void *func_02074458(void *arc);
extern void *func_0207411c(u32 fileId);
extern void func_02074100(u32 fileId, void *mem);
extern void func_02074e1c(void *mem, void *arc, u32 fileId);
void func_02074e1c(void *mem, void *arc, u32 fileId) {
    void *prev;
    int irq;

    if (arc == 0) {
        return;
    }

    irq  = func_02006194();
    prev = func_02074458(arc);
    if (mem == func_0207411c(fileId)) {
        func_02074100(fileId, 0);
    }
    func_02074458(prev);
    func_020061a8(irq);
}
