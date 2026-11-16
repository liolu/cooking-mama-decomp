/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206746c from projets/children-of-mana/src/auto/func_0206746c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef signed long s32;
typedef int BOOL;
extern const u16(*ctrdgi_fl_maxtime);
extern void func_02078ed0();
extern s32 data_02116550;
extern u16 data_020c2b10;
extern BOOL NNSi_G2dIsStackEmpty(void);
extern void NNSi_G2dMtxPop(void);
extern void RestoreRndMtxStackStateNotSR_(void);
inline void RestoreRndMtxStackStateNotSR_(void) {
    data_020c2b10 = 0xFFFE;
}
inline BOOL NNSi_G2dIsStackEmpty(void) {
    return (BOOL) (data_02116550 <= 0);
}
inline void NNSi_G2dMtxPop(void) {
    if (!NNSi_G2dIsStackEmpty()) {
        data_02116550--;

        {
            if (data_020c2b10 > data_02116550) {
                ((void) 0);

                RestoreRndMtxStackStateNotSR_();
            }
        }
    } else {
        ((void) 0);
    }
}
void func_02078ed0() {
    ((void) 0);
    NNSi_G2dMtxPop();
}
