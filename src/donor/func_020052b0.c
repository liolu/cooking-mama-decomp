/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205b578 from projets/children-of-mana/src/auto/func_0205b578.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
extern int func_02003aa0(void);
extern unsigned int func_02006194(void);
extern int func_02003af8(unsigned short *p);
extern int func_02003b98(int x);
extern int func_02003bb8(int a);
extern void func_020061a8(unsigned int flags);
int func_020052b0(void) {
    int result;
    int done = 0;
    int x;
    int res;
    unsigned int irq;

    x      = (unsigned short) func_02003aa0();
    result = done;

    do {
        res = -1;
        irq = func_02006194();
        if ((func_02003af8((unsigned short *) 0x027fffe8) & 0x40) != 0 || (res = func_02003b98(x)) == 0) {
            if (*(unsigned int *) 0x8000000 == 0x544e494e && *(unsigned int *) 0x8000004 == 0x4f444e45) {
                result = 0x1000000;
            } else {
                result = 0x2000000;
            }
            if (res == 0) {
                func_02003bb8(x);
                done = 1;
            }
        }
        func_020061a8(irq);
    } while (done == 0);

    return result;
}
