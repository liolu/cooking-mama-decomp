/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206aebc from projets/children-of-mana/src/auto/func_0206aebc.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;
typedef enum NNSG2dBGSelect {
    NNS_G2D_BGSELECT_MAIN0,
    NNS_G2D_BGSELECT_MAIN1,
    NNS_G2D_BGSELECT_MAIN2,
    NNS_G2D_BGSELECT_MAIN3,
    NNS_G2D_BGSELECT_SUB0,
    NNS_G2D_BGSELECT_SUB1,
    NNS_G2D_BGSELECT_SUB2,
    NNS_G2D_BGSELECT_SUB3
} NNSG2dBGSelect;
extern volatile u16 *const data_02084e5c[];
static inline int GetBGNo(NNSG2dBGSelect bg) {
    return bg & 3;
}
static inline volatile u16 *GetBGnCNT(NNSG2dBGSelect bg) {
    return data_02084e5c[bg];
}
static inline BOOL IsMainBG(NNSG2dBGSelect bg) {
    return bg <= NNS_G2D_BGSELECT_MAIN3;
}
static inline int GetBGModeMain(void) {
    return (int) (*(volatile u32 *) 0x04000000 & 7);
}
static inline int GetBGModeSub(void) {
    return (int) (*(volatile u32 *) 0x04001000 & 7);
}
void func_0207c4a0(int *pWidth, int *pHeight, NNSG2dBGSelect bg) {
    const int bgNo     = GetBGNo(bg);
    const int scnSize  = (*GetBGnCNT(bg) & 0xc000) >> 14;
    const int bgMode   = IsMainBG(bg) ? GetBGModeMain() : GetBGModeSub();
    const BOOL bAffine = (((bgNo == 2) && ((bgMode == 2) || (bgMode >= 4))) || ((bgNo == 3) && (bgMode >= 1)));

    if (bAffine) {
        const int size = (16 << scnSize);
        *pWidth        = size;
        *pHeight       = size;
    } else {
        *pWidth  = (scnSize & 1) ? 64 : 32;
        *pHeight = (scnSize & 2) ? 64 : 32;
    }
}
