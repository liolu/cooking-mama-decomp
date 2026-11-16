/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02065418 from projets/children-of-mana/src/auto/func_02065418.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
extern int func_02077810(void *p);
typedef struct {
    char _pad[0xc];
    int f_c;
} state_0207e910_t;
int func_02077630(state_0207e910_t *p) {
    int r = func_02077810(p);
    if (r != 0) {
        p->f_c = 0;
    }
    return r;
}
