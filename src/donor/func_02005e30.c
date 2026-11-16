/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205c534 from projets/children-of-mana/src/auto/func_0205c534.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
extern void func_02005e44(void);
extern void func_02005ed4(void);
// clang-format off
asm void func_02005e30(void)
{
    stmdb sp!, {lr}
    bl func_02005e44
    bl func_02005ed4
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
