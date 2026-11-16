/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206a214 from projets/children-of-mana/src/auto/func_0206a214.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
typedef volatile u32 vu32;
typedef vu32 REGType32v;
typedef int BOOL;
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
    GX_MTXMODE_PROJECTION      = 0,
    GX_MTXMODE_POSITION        = 1,
    GX_MTXMODE_POSITION_VECTOR = 2,
    GX_MTXMODE_TEXTURE         = 3
} GXMtxMode;
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
extern void G3_MtxMode(GXMtxMode mode);
extern void G3_PushMtx(void);
extern void G3_Translate(fx32 x, fx32 y, fx32 z);
static inline void G3_MtxMode(GXMtxMode mode) {
    ((void) 0);
    (*(REGType32v *) (0x04000000 + 0x440)) = ((u32) ((mode) << 0));
}
static inline void G3_PushMtx() {
    (*(REGType32v *) (0x04000000 + 0x444)) = 0;
}
static inline void G3_Translate(fx32 x, fx32 y, fx32 z) {
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) x;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) y;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) z;
}
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
extern void func_0207b7cc(NNSG2dRndCoreInstance *pRnd);
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
extern u32 func_020788a0(const NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type);
extern BOOL func_02078888(const NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type);
extern u32 func_02078850(const NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type);
extern BOOL func_02078834(const NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type);
extern NNSG2dRndCoreInstance *data_021174f0;
static inline int GetShiftToConvByteTo2DChar_(GXOBJVRamModeChar mappingType) {
    int shift = (0x00700000 & mappingType) >> 20;
    return shift;
}
static inline u32 GetNum2DCharacter_(u32 sizeByte, GXOBJVRamModeChar mappingType) {
    const int shiftBit = 5 + GetShiftToConvByteTo2DChar_(mappingType);
    u32 numChar        = sizeByte >> shiftBit;

    ((void) 0);

    return numChar;
}
static inline u32 GetTexBaseAddr3D_(const NNSG2dImageProxy *pImgProxy) {
    ((void) 0);
    if (func_02078888(pImgProxy, NNS_G2D_VRAM_TYPE_3DMAIN)) {
        return func_020788a0(pImgProxy, NNS_G2D_VRAM_TYPE_3DMAIN);
    } else {
        return 0;
    }
}
static inline u32 GetPltBaseAddr3D_(const NNSG2dImagePaletteProxy *pPltProxy) {
    ((void) 0);
    if (func_02078834(pPltProxy, NNS_G2D_VRAM_TYPE_3DMAIN)) {
        return func_02078850(pPltProxy, NNS_G2D_VRAM_TYPE_3DMAIN);
    } else {
        return 0;
    }
}
static inline NNS_G2D_VRAM_TYPE SurfaceTypeToVramType_(NNSG2dSurfaceType surfaceType) {
    return (NNS_G2D_VRAM_TYPE) surfaceType;
}
static inline u32 GetCharacterBase2D_(const NNSG2dImageProxy *pImgProxy, NNSG2dSurfaceType type) {

    ((void) 0);
    ((void) 0);

    {
        const NNS_G2D_VRAM_TYPE vramType = SurfaceTypeToVramType_(type);

        if (func_02078888(pImgProxy, vramType)) {
            u32 baseAddr = func_020788a0(pImgProxy, vramType);
            return GetNum2DCharacter_(baseAddr, pImgProxy->attr.mappingType);
        } else {
            return 0;
        }
    }
}
void func_0207b7cc(NNSG2dRndCoreInstance *pRnd) {
    ((void) 0);
    ((void) 0);
    ((void) 0);

    data_021174f0 = pRnd;

    if (pRnd->pCurrentTargetSurface->type == NNS_G2D_SURFACETYPE_MAIN3D) {

        G3_MtxMode(GX_MTXMODE_PROJECTION);
        G3_PushMtx();
        G3_Translate(-pRnd->pCurrentTargetSurface->viewRect.posTopLeft.x, -pRnd->pCurrentTargetSurface->viewRect.posTopLeft.y,
                     0);
        G3_MtxMode(GX_MTXMODE_POSITION);

        pRnd->baseTexAddr3D = GetTexBaseAddr3D_(data_021174f0->pImgProxy);
        pRnd->basePltAddr3D = GetPltBaseAddr3D_(data_021174f0->pPltProxy);

    } else {
        data_021174f0->base2DCharOffset =
            GetCharacterBase2D_(data_021174f0->pImgProxy, data_021174f0->pCurrentTargetSurface->type);
    }
}
