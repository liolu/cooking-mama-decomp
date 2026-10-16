/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_ReceiveMessage from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/os/calls/OS_ReceiveMessage.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
extern int func_02006194(void);
extern void func_020061a8(int state);
extern void func_02004b98(void *queue);
extern void func_02004b18(void *queue);
extern long long func_02016228(int a, int b);
int func_020054b8(char *q, void **out, int flags) {
    int enabled = func_02006194();
    while (*(int *) (q + 0x1c) == 0) {
        if ((flags & 1) == 0) {
            func_020061a8(enabled);
            return 0;
        }
        func_02004b98(q + 8);
    }
    if (out != 0) {
        *out = (*(void ***) (q + 0x10))[*(int *) (q + 0x18)];
    }
    *(int *) (q + 0x18) = (int) (func_02016228(*(int *) (q + 0x18) + 1, *(int *) (q + 0x14)) >> 32);
    *(int *) (q + 0x1c) = *(int *) (q + 0x1c) - 1;
    func_02004b18(q);
    func_020061a8(enabled);
    return 1;
}
