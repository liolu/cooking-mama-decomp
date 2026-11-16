/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020664cc from projets/children-of-mana/src/auto/func_020664cc.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned long u32;
typedef int BOOL;
typedef enum {
    GX_TEXFMT_NONE    = 0,
    GX_TEXFMT_A3I5    = 1,
    GX_TEXFMT_PLTT4   = 2,
    GX_TEXFMT_PLTT16  = 3,
    GX_TEXFMT_PLTT256 = 4,
    GX_TEXFMT_COMP4x4 = 5,
    GX_TEXFMT_A5I3    = 6,
    GX_TEXFMT_DIRECT  = 7
} GXTexFmt;
typedef enum NNS_G2D_VRAM_TYPE {
    NNS_G2D_VRAM_TYPE_3DMAIN = 0,
    NNS_G2D_VRAM_TYPE_2DMAIN = 1,
    NNS_G2D_VRAM_TYPE_2DSUB  = 2,
    NNS_G2D_VRAM_TYPE_2DBOTH = 3,
    NNS_G2D_VRAM_TYPE_MAX    = 3
} NNS_G2D_VRAM_TYPE;
typedef struct NNSG2dVRamLocation {
    u32 baseAddrOfVram[NNS_G2D_VRAM_TYPE_MAX];
} NNSG2dVRamLocation;
typedef struct NNSG2dImagePaletteProxy {
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    NNSG2dVRamLocation vramLocation;
} NNSG2dImagePaletteProxy;
extern void InitializeVRamLocation_(NNSG2dVRamLocation *pVramLocation);
static inline void InitializeVRamLocation_(NNSG2dVRamLocation *pVramLocation) {
    int i;
    for (i = 0; i < NNS_G2D_VRAM_TYPE_MAX; i++) {
        pVramLocation->baseAddrOfVram[i] = 0xFFFFFFFF;
    }
}
void func_02078868(NNSG2dImagePaletteProxy *pImg) {
    InitializeVRamLocation_(&pImg->vramLocation);
}
