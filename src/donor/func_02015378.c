/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02001d4c from projets/children-of-mana/src/donor/func_02001d4c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
extern void func_02015378(void *dst, int val, unsigned int n);
void func_02015378(void *dst, int val, unsigned int n) {
    unsigned int v = (unsigned char) val;
    unsigned int i;

    if (n >= 32) {
        i = (-(unsigned int) dst) & 3;

        if (i) {
            n -= i;
            do {
                *(((unsigned char *) dst))++ = v;
            } while (--i);
        }

        if (v) {
            v |= v << 24 | v << 16 | v << 8;
        }

        i = n >> 5;

        if (i) {
            do {
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
                *(((unsigned int *) dst))++ = v;
            } while (--i);
        }

        i = (n & 31) >> 2;

        if (i) {
            do {
                *(((unsigned int *) dst))++ = v;
            } while (--i);
        }

        n &= 3;
    }

    if (n) {
        do {
            *(((unsigned char *) dst))++ = v;
        } while (--n);
    }
}
