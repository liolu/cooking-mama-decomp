/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02034650 from projets/code-lyoko/src/donor/func_02034650.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
typedef int BOOL;
extern void func_02006a04(u32 data, void *destp, u32 size);
static inline void MI_CpuFillFast(void *dest, u32 data, u32 size) {
    ((void) 0);
    ((void) 0);

    func_02006a04(data, dest, size);
}
static inline void MI_CpuClearFast(void *dest, u32 size) {
    MI_CpuFillFast(dest, 0, size);
}
typedef s32 fx32;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;
typedef enum {
    GX_TEXSIZE_S8    = 0,
    GX_TEXSIZE_S16   = 1,
    GX_TEXSIZE_S32   = 2,
    GX_TEXSIZE_S64   = 3,
    GX_TEXSIZE_S128  = 4,
    GX_TEXSIZE_S256  = 5,
    GX_TEXSIZE_S512  = 6,
    GX_TEXSIZE_S1024 = 7
} GXTexSizeS;
typedef enum {
    GX_TEXSIZE_T8    = 0,
    GX_TEXSIZE_T16   = 1,
    GX_TEXSIZE_T32   = 2,
    GX_TEXSIZE_T64   = 3,
    GX_TEXSIZE_T128  = 4,
    GX_TEXSIZE_T256  = 5,
    GX_TEXSIZE_T512  = 6,
    GX_TEXSIZE_T1024 = 7
} GXTexSizeT;
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
typedef enum {
    GX_TEXPLTTCOLOR0_USE  = 0,
    GX_TEXPLTTCOLOR0_TRNS = 1
} GXTexPlttColor0;
typedef enum {
    GX_OBJVRAMMODE_CHAR_2D      = (0 << 4) | (0 << 20),
    GX_OBJVRAMMODE_CHAR_1D_32K  = (1 << 4) | (0 << 20),
    GX_OBJVRAMMODE_CHAR_1D_64K  = (1 << 4) | (1 << 20),
    GX_OBJVRAMMODE_CHAR_1D_128K = (1 << 4) | (2 << 20),
    GX_OBJVRAMMODE_CHAR_1D_256K = (1 << 4) | (3 << 20)
} GXOBJVRamModeChar;
typedef struct {
    union {
        u32 attr01;
        struct {
            u16 attr0;
            u16 attr1;
        };
        struct {
            u32 y : 8;
            u32 rsMode : 2;
            u32 objMode : 2;
            u32 mosaic : 1;
            u32 colorMode : 1;
            u32 shape : 2;

            u32 x : 9;
            u32 rsParam : 5;
            u32 size : 2;
        };
        struct {
            u32 _0 : 28;
            u32 flipH : 1;
            u32 flipV : 1;
            u32 _1 : 2;
        };
    };
    union {
        struct {
            u16 attr2;
            u16 _3;
        };
        u32 attr23;
        struct {
            u32 charNo : 10;
            u32 priority : 2;
            u32 cParam : 4;
            u32 _2 : 16;
        };
    };
} GXOamAttr;
typedef enum {
    GX_OAM_MODE_NORMAL    = 0,
    GX_OAM_MODE_XLU       = 1,
    GX_OAM_MODE_OBJWND    = 2,
    GX_OAM_MODE_BITMAPOBJ = 3
} GXOamMode;
extern const u16(*ctrdgi_fl_maxtime);
typedef struct NNSG2dFVec2 {
    fx32 x;
    fx32 y;
} NNSG2dFVec2;
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
        fx32 _20, _21;
    };
    fx32 m[3][2];
    fx32 a[6];
} MtxFx32;
typedef enum NNS_G2D_VRAM_TYPE {
    NNS_G2D_VRAM_TYPE_3DMAIN = 0,
    NNS_G2D_VRAM_TYPE_2DMAIN = 1,
    NNS_G2D_VRAM_TYPE_2DSUB  = 2,
    NNS_G2D_VRAM_TYPE_2DBOTH = 3,
    NNS_G2D_VRAM_TYPE_MAX    = 3
} NNS_G2D_VRAM_TYPE;
typedef struct NNSG2dImageAttr {
    GXTexSizeS sizeS;
    GXTexSizeT sizeT;
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    GXTexPlttColor0 plttUse;
    GXOBJVRamModeChar mappingType;
} NNSG2dImageAttr;
typedef struct NNSG2dVRamLocation {
    u32 baseAddrOfVram[NNS_G2D_VRAM_TYPE_MAX];
} NNSG2dVRamLocation;
typedef struct NNSG2dImageProxy {
    NNSG2dVRamLocation vramLocation;
    NNSG2dImageAttr attr;
} NNSG2dImageProxy;
typedef struct NNSG2dImagePaletteProxy {
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    NNSG2dVRamLocation vramLocation;
} NNSG2dImagePaletteProxy;
typedef struct NNSG2dCellOAMAttrData {
    u16 attr0;
    u16 attr1;
    u16 attr2;
} NNSG2dCellOAMAttrData;
typedef struct NNSG2dCellData {
    u16 numOAMAttrs;
    u16 cellAttr;
    NNSG2dCellOAMAttrData *pOamAttrArray;
} NNSG2dCellData;
typedef struct NNSG2dPaletteSwapTable {
    u16 paletteIndex[16];
} NNSG2dPaletteSwapTable;
typedef enum NNSG2dRendererAffineTypeOverwiteMode {
    NNS_G2D_RND_AFFINE_OVERWRITE_NONE,
    NNS_G2D_RND_AFFINE_OVERWRITE_NORMAL,
    NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE
} NNSG2dRendererAffineTypeOverwiteMode;
typedef enum NNSG2dSurfaceType {
    NNS_G2D_SURFACETYPE_MAIN3D = 0x00,
    NNS_G2D_SURFACETYPE_MAIN2D = 0x01,
    NNS_G2D_SURFACETYPE_SUB2D  = 0x02,
    NNS_G2D_SURFACETYPE_MAX    = 0x03
} NNSG2dSurfaceType;
typedef struct NNSG2dRndCore2DMtxCache {
    MtxFx22 m22;
    u16 affineIndex[0x04][2];
} NNSG2dRndCore2DMtxCache;
typedef struct NNSG2dViewRect {
    NNSG2dFVec2 posTopLeft;
    NNSG2dFVec2 sizeView;
} NNSG2dViewRect;
typedef BOOL (*NNSG2dOamRegisterFunction)(const GXOamAttr *pOam, u16 affineIndex, BOOL bDoubleAffine);
typedef u16 (*NNSG2dAffineRegisterFunction)(const MtxFx22 *mtx);
typedef void (*NNSG2dRndCoreDrawCellCallBack)(struct NNSG2dRndCoreInstance *pRend, const NNSG2dCellData *pCell);
typedef void (*NNSG2dRndCoreDrawOamCallBack)(struct NNSG2dRndCoreInstance *pRend, const NNSG2dCellData *pCell, u16 oamIdx);
typedef struct NNSG2dRndCoreSurface {
    NNSG2dViewRect viewRect;
    BOOL bActive;
    NNSG2dSurfaceType type;
    NNSG2dRndCoreDrawCellCallBack pBeforeDrawCellBackFunc;
    NNSG2dRndCoreDrawCellCallBack pAfterDrawCellBackFunc;
    NNSG2dRndCoreDrawOamCallBack pBeforeDrawOamBackFunc;
    NNSG2dRndCoreDrawOamCallBack pAfterDrawOamBackFunc;
} NNSG2dRndCoreSurface;
typedef struct NNSG2dRndCoreInstance {
    NNSG2dRndCoreSurface *pCurrentTargetSurface;
    NNSG2dRendererAffineTypeOverwiteMode affineOverwriteMode;
    const struct NNSG2dImageProxy *pImgProxy;
    const struct NNSG2dImagePaletteProxy *pPltProxy;
    u32 base2DCharOffset;
    u32 baseTexAddr3D;
    u32 basePltAddr3D;
    NNSG2dOamRegisterFunction pFuncOamRegister;
    NNSG2dAffineRegisterFunction pFuncOamAffineRegister;
    u32 flipFlag;
    NNSG2dRndCore2DMtxCache *pCurrentMtxCacheFor2D;
    const MtxFx32 *pCurrentMxt;
    BOOL bDrawEnable;
    fx32 zFor3DSoftwareSprite;
    GXOamAttr currentOam;
    MtxFx43 mtxFor3DGE;
} NNSG2dRndCoreInstance;
extern void func_0207ba0c(NNSG2dRndCoreInstance *pRnd);
inline void NNS_G2dInitRndCore2DMtxCache(NNSG2dRndCore2DMtxCache *pMtxCache) {
    MI_CpuFillFast(pMtxCache->affineIndex, 0xFFFFFFFF, sizeof(pMtxCache->affineIndex));
}
typedef BOOL (*NNSG2dRndCellCullingFunction)(const NNSG2dCellData *pCell, const MtxFx32 *pMtx,
                                             const NNSG2dViewRect *pViewRect);
typedef void (*NNSG2dRndDrawCellCallBack)(struct NNSG2dRendererInstance *pRend, struct NNSG2dRenderSurface *pSurface,
                                          const NNSG2dCellData *pCell, const MtxFx32 *pMtx);
typedef void (*NNSG2dRndDrawOamCallBack)(struct NNSG2dRendererInstance *pRend, struct NNSG2dRenderSurface *pSurface,
                                         const NNSG2dCellData *pCell, u16 oamIdx, const MtxFx32 *pMtx);
typedef struct NNSG2dRenderSurface {
    union {
        NNSG2dRndCoreSurface coreSurface;
        struct {
            NNSG2dViewRect viewRect;
            BOOL bActive;
            NNSG2dSurfaceType type;
            NNSG2dRndCoreDrawCellCallBack pBeforeCoreDrawCellBack;
            NNSG2dRndCoreDrawCellCallBack pAfterCoreDrawCellBack;
            NNSG2dRndCoreDrawOamCallBack pBeforeCoreDrawOamBack;
            NNSG2dRndCoreDrawOamCallBack pAfterCoreDrawOamBack;
        };
    };

    NNSG2dOamRegisterFunction pFuncOamRegister;
    NNSG2dAffineRegisterFunction pFuncOamAffineRegister;
    void *pNextSurface;
    NNSG2dRndCellCullingFunction pFuncVisibilityCulling;
    NNSG2dRndDrawCellCallBack pBeforeDrawCellBackFunc;
    NNSG2dRndDrawCellCallBack pAfterDrawCellBackFunc;
    NNSG2dRndDrawOamCallBack pBeforeDrawOamBackFunc;
    NNSG2dRndDrawOamCallBack pAfterDrawOamBackFunc;
} NNSG2dRenderSurface;
typedef enum NNSG2dRendererOptimizeHint {
    NNS_G2D_RDR_OPZHINT_NONE        = 0x0,
    NNS_G2D_RDR_OPZHINT_NOT_SR      = 0x1,
    NNS_G2D_RDR_OPZHINT_LOCK_PARAMS = 0x2
} NNSG2dRendererOptimizeHint;
typedef enum NNSG2dRendererOverwriteParam {
    NNS_G2D_RND_OVERWRITE_NONE        = 0x0,
    NNS_G2D_RND_OVERWRITE_PRIORITY    = 0x1,
    NNS_G2D_RND_OVERWRITE_PLTTNO      = 0x2,
    NNS_G2D_RND_OVERWRITE_MOSAIC      = 0x4,
    NNS_G2D_RND_OVERWRITE_OBJMODE     = 0x8,
    NNS_G2D_RND_OVERWRITE_PLTTNO_OFFS = 0x10,
    NNS_G2D_RND_OVERWRITE_MAX
} NNSG2dRendererOverwriteParam;
typedef struct NNSG2dRendererInstance {
    NNSG2dRndCoreInstance rendererCore;
    NNSG2dRenderSurface *pTargetSurfaceList;
    NNSG2dRenderSurface *pCurrentSurface;
    const NNSG2dPaletteSwapTable *pPaletteSwapTbl;
    u32 opzHint;
    fx32 spriteZoffsetStep;
    u32 overwriteEnableFlag;
    u16 overwritePriority;
    u16 overwritePlttNo;
    GXOamMode overwriteObjMode;
    BOOL overwriteMosaicFlag;
    u16 overwritePlttNoOffset;
    u16 pad16_;
} NNSG2dRendererInstance;
extern void func_02079424(NNSG2dRendererInstance *pRend);
extern s32 data_02116550;
extern u16 data_020c2b10;
extern BOOL data_02116548;
extern void NNSi_G2dInitRndMtxStack(void);
extern void RestoreRndMtxStackStateNotSR_(void);
inline void RestoreRndMtxStackStateNotSR_(void) {
    data_020c2b10 = 0xFFFE;
}
inline void NNSi_G2dInitRndMtxStack(void) {
    data_02116550 = 0;
    RestoreRndMtxStackStateNotSR_();
}
inline void NNSi_G2dSetRndMtxStackSRTransformEnableFlag(BOOL bEnable) {
    data_02116548 = !bEnable;
}
extern NNSG2dRndCore2DMtxCache data_02116cd4[32];
extern u16 data_02116540;
inline void NNSi_RMCInitMtxCache(void) {
    int i;
    for (i = 0; i < 32; i++) {
        NNS_G2dInitRndCore2DMtxCache(&data_02116cd4[i]);
    }
    data_02116540 = 0;
}
typedef struct MCMMtxState {
    u16 mtxCacheIdx;
    u16 groupID;
    u16 stateType;
    u16 pad16;
} MCMMtxState;
extern MCMMtxState data_021165d4[32];
extern u16 data_02116544;
inline void InitGroupID_(void) {
    data_02116544 = 0;
}
inline void NNSi_G2dMCMInitMtxCache(void) {
    NNSi_G2dInitRndMtxStack();
    NNSi_RMCInitMtxCache();

    InitGroupID_();

    MI_CpuClearFast(data_021165d4, sizeof(data_021165d4));
}
void func_02079424(NNSG2dRendererInstance *pRend) {
    ((void) 0);

    func_0207ba0c(&pRend->rendererCore);

    pRend->pTargetSurfaceList = 0;
    pRend->pCurrentSurface    = 0;
    pRend->pPaletteSwapTbl    = 0;

    pRend->opzHint = NNS_G2D_RDR_OPZHINT_NONE;

    pRend->spriteZoffsetStep = 0;

    pRend->overwriteEnableFlag   = NNS_G2D_RND_OVERWRITE_NONE;
    pRend->overwritePriority     = 0;
    pRend->overwritePlttNo       = 0;
    pRend->overwriteObjMode      = GX_OAM_MODE_NORMAL;
    pRend->overwriteMosaicFlag   = 0;
    pRend->overwritePlttNoOffset = 0;

    NNSi_G2dMCMInitMtxCache();
    NNSi_G2dSetRndMtxStackSRTransformEnableFlag(1);
}
