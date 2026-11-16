/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020099b0 from projets/code-lyoko/src/donor/func_020099b0.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
extern int func_02006194(void);
extern void func_020061a8(int state);
extern void func_02004b98(void *queue);
extern void func_02004b18(void *queue);
extern long long func_02016228(int a, int b);
int func_02005564(char *q, void *msg, int flags) {
    int enabled = func_02006194();
    while (*(int *) (q + 0x14) <= *(int *) (q + 0x1c)) {
        if ((flags & 1) == 0) {
            func_020061a8(enabled);
            return 0;
        }
        func_02004b98(q);
    }
    (*(void ***) (q + 0x10))[(int) (func_02016228(*(int *) (q + 0x18) + *(int *) (q + 0x1c), *(int *) (q + 0x14)) >> 32)] =
        msg;
    *(int *) (q + 0x1c) = *(int *) (q + 0x1c) + 1;
    func_02004b18(q + 8);
    func_020061a8(enabled);
    return 1;
}
