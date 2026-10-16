/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0214fefc from https://github.com/RonyxDumb/mkds src/arm9/0214fefc_func_0214fefc.c (license: none), reused by
 * tools/donor_match.py */
extern int func_0200be04(void);
extern void func_0200b6a8(int param);
extern void func_0200b378(int a, int b, int c, int d);
extern volatile int data_020c4c10;
extern int data_020c4c14;
int func_0200bb28(unsigned int a, unsigned int b) {
    volatile int *p;

    if (!func_0200be04()) {
        return 1;
    }
    data_020c4c10 = 0;
    func_0200b6a8(0x3006000);
    p = &data_020c4c10;
    while (!*p) {
    }
    *p            = 0;
    data_020c4c14 = 0;
    func_0200b378(0, 2, 0, 0);
    func_0200b6a8((a & 0xff) | 0x2006100);
    func_0200b6a8((b & 0xffff) | 0x1010000);
    return 0;
}
