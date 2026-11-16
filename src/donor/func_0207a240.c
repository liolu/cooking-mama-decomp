/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068c78 from projets/children-of-mana/src/auto/func_02068c78.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef signed long s32;
typedef signed long long int s64;
typedef s32 fx32;
typedef s64 fx64;
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
        fx32 _20, _21;
    };
    fx32 m[3][2];
    fx32 a[6];
} MtxFx32;
extern void func_0207a240(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab);
void func_0207a240(const MtxFx32 *a, const MtxFx32 *b, MtxFx32 *ab) {
    MtxFx32 temp;
    MtxFx32 *m;

    ((void) 0);
    ((void) 0);
    ((void) 0);

    if (ab == b) {
        m = &temp;
    } else {
        m = ab;
    }

    m->_00 = (fx32) (((fx64) a->_00 * b->_00 + (fx64) a->_01 * b->_10) >> 12);
    m->_01 = (fx32) (((fx64) a->_00 * b->_01 + (fx64) a->_01 * b->_11) >> 12);

    m->_10 = (fx32) (((fx64) a->_10 * b->_00 + (fx64) a->_11 * b->_10) >> 12);
    m->_11 = (fx32) (((fx64) a->_10 * b->_01 + (fx64) a->_11 * b->_11) >> 12);

    m->_20 = (fx32) (((fx64) a->_20 * b->_00 + (fx64) a->_21 * b->_10) >> 12) + b->_20;
    m->_21 = (fx32) (((fx64) a->_20 * b->_01 + (fx64) a->_21 * b->_11) >> 12) + b->_21;

    if (m == &temp) {
        *ab = temp;
    }
}
