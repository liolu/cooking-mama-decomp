/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206abd4 from projets/children-of-mana/src/auto/func_0206abd4.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef signed long long int s64;
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
    GX_OAM_SHAPE_8x8   = (0 << 14) | (0 << 30),
    GX_OAM_SHAPE_16x16 = (0 << 14) | (1 << 30),
    GX_OAM_SHAPE_32x32 = (0 << 14) | (2 << 30),
    GX_OAM_SHAPE_64x64 = (0 << 14) | (3 << 30),
    GX_OAM_SHAPE_16x8  = (1 << 14) | (0 << 30),
    GX_OAM_SHAPE_32x8  = (1 << 14) | (1 << 30),
    GX_OAM_SHAPE_32x16 = (1 << 14) | (2 << 30),
    GX_OAM_SHAPE_64x32 = (1 << 14) | (3 << 30),
    GX_OAM_SHAPE_8x16  = (2 << 14) | (0 << 30),
    GX_OAM_SHAPE_8x32  = (2 << 14) | (1 << 30),
    GX_OAM_SHAPE_16x32 = (2 << 14) | (2 << 30),
    GX_OAM_SHAPE_32x64 = (2 << 14) | (3 << 30)
} GXOamShape;
typedef enum {
    GX_OAM_EFFECT_NONE          = (0 << 8) | (0 << 28) | (0 << 29),
    GX_OAM_EFFECT_FLIP_H        = (0 << 8) | (1 << 28) | (0 << 29),
    GX_OAM_EFFECT_FLIP_V        = (0 << 8) | (0 << 28) | (1 << 29),
    GX_OAM_EFFECT_FLIP_HV       = (0 << 8) | (1 << 28) | (1 << 29),
    GX_OAM_EFFECT_AFFINE        = (1 << 8),
    GX_OAM_EFFECT_NODISPLAY     = (2 << 8),
    GX_OAM_EFFECT_AFFINE_DOUBLE = (3 << 8)
} GXOamEffect;
extern void G2_SetOBJPosition(GXOamAttr *oam, int x, int y);
extern void G2_SetOBJEffect(GXOamAttr *oam, GXOamEffect effect, int rsParam);
static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y) {
    oam->attr01 = ((oam->attr01 & ~(0x000000ff | 0x01ff0000)) | (y & 0x000000ff) | ((x & (0x01ff0000 >> 16)) << 16));
}
static inline void G2_SetOBJEffect(GXOamAttr *oam, GXOamEffect effect, int rsParam) {
    ((void) 0);
    ((void) 0);

    if (GX_OAM_EFFECT_AFFINE != effect && GX_OAM_EFFECT_AFFINE_DOUBLE != effect) {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) | effect);
    } else {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) | effect | (rsParam << 25));
    }
}
static inline GXOamEffect G2_GetOBJEffect(const GXOamAttr *oam) {
    GXOamEffect effect;

    ((void) 0);

    effect = (GXOamEffect) (oam->attr01 & 0x00000300);

    if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        return effect;
    }

    return (GXOamEffect) (effect | (oam->attr01 & 0x30000000));
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
extern const u16 data_02084cf4[3][4];
extern const u16 data_02084d0c[3][4];
inline GXOamShape NNS_G2dGetOAMSize(const GXOamAttr *oamAttr) {
    const GXOamShape result = (GXOamShape) ((0x0000c000 | 0xc0000000) & oamAttr->attr01);
    return result;
}
inline int NNS_G2dGetOamSizeX(const GXOamShape *oamShape) {

    return data_02084d0c[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
inline int NNS_G2dGetOamSizeY(const GXOamShape *oamShape) {

    return data_02084cf4[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
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
inline s16 NNS_G2dRepeatXinCellSpace(s16 srcX) {
    if (srcX > 255) {
        srcX |= 0xFF00;
    }
    return srcX;
}
inline s16 NNS_G2dRepeatYinCellSpace(s16 srcY) {
    if (srcY > 127) {
        srcY |= 0xFF00;
    }
    return srcY;
}
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
extern s16 NNSi_G2dGetOamX(const GXOamAttr *oamAttr);
extern s16 NNSi_G2dGetOamY(const GXOamAttr *oamAttr);
extern void NNSi_G2dAdjustDifferenceOfRotateOrientation(const GXOamAttr *pOam, const MtxFx22 *pM, NNSG2dFVec2 *pV,
                                                        BOOL adjustDoubleAffine);
inline s16 NNSi_G2dGetOamX(const GXOamAttr *oamAttr) {
    ((void) 0);
    {
        s16 val = (s16) ((0x01ff0000 & oamAttr->attr01) >> 16);
        return val;
    }
}
inline s16 NNSi_G2dGetOamY(const GXOamAttr *oamAttr) {
    ((void) 0);
    {
        s16 val = (s16) ((0x000000ff & oamAttr->attr01) >> 0);
        return val;
    }
}
inline void NNS_G2dGetOamTransFx32(const GXOamAttr *pOam, NNSG2dFVec2 *pRet) {
    ((void) 0);
    ((void) 0);

    pRet->x = (fx32) (NNS_G2dRepeatXinCellSpace(NNSi_G2dGetOamX(pOam)) * ((fx32) 0x0000000000001000L));
    pRet->y = (fx32) (NNS_G2dRepeatYinCellSpace(NNSi_G2dGetOamY(pOam)) * ((fx32) 0x0000000000001000L));
}
inline void NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(const GXOamAttr *pOam, NNSG2dFVec2 *pV) {
    ((void) 0);
    ((void) 0);

    if (G2_GetOBJEffect(pOam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {

        const GXOamShape oamShape = NNS_G2dGetOAMSize(pOam);
        const int halfW           = NNS_G2dGetOamSizeX(&oamShape) << (12 - 1);
        const int halfH           = NNS_G2dGetOamSizeY(&oamShape) << (12 - 1);

        pV->x += halfW;
        pV->y += halfH;
    }
}
inline void NNSi_G2dAdjustDifferenceOfRotateOrientation(const GXOamAttr *pOam, const MtxFx22 *pM, NNSG2dFVec2 *pV,
                                                        BOOL adjustDoubleAffine) {
    ((void) 0);
    ((void) 0);
    ((void) 0);
    {
        const GXOamShape oamShape = NNS_G2dGetOAMSize(pOam);
        const int halfW           = NNS_G2dGetOamSizeX(&oamShape) >> 1;
        const int halfH           = NNS_G2dGetOamSizeY(&oamShape) >> 1;

        pV->x += -(halfW << 12) + pM->_00 * halfW + pM->_10 * halfH;
        pV->y += -(halfH << 12) + pM->_01 * halfW + pM->_11 * halfH;

        if (adjustDoubleAffine) {
            pV->x -= halfW << 12;
            pV->y -= halfH << 12;
        }
    }
}
inline void MulMtx22(const MtxFx22 *m, const NNSG2dFVec2 *pSrc, NNSG2dFVec2 *pDst) {
    NNSG2dFVec2 temp;
    NNSG2dFVec2 *pV = pDst;
    if (pDst == pSrc) {
        pV = &temp;
    }

    pV->x = (fx32) ((((s64) (m->_00) * pSrc->x + 0x800LL) + ((s64) (m->_10) * pSrc->y + 0x800LL)) >> 12);
    pV->y = (fx32) ((((s64) (m->_01) * pSrc->x + 0x800LL) + ((s64) (m->_11) * pSrc->y + 0x800LL)) >> 12);

    if (pV == &temp) {
        *pDst = temp;
    }
}
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
extern NNSG2dRndCoreInstance *data_021174f0;
void func_0207c1b8(const MtxFx22 *pMtxSR, GXOamAttr *pOam, NNSG2dFVec2 *pBaseTrans) {
    NNSG2dFVec2 objTrans;
    GXOamEffect effectTypeAfter;

    NNS_G2dGetOamTransFx32(pOam, &objTrans);
    NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(pOam, &objTrans);
    MulMtx22(pMtxSR, &objTrans, &objTrans);

    if (data_021174f0->affineOverwriteMode != NNS_G2D_RND_AFFINE_OVERWRITE_NONE) {
        if (data_021174f0->affineOverwriteMode == NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE) {
            effectTypeAfter = GX_OAM_EFFECT_AFFINE_DOUBLE;
        } else {
            effectTypeAfter = GX_OAM_EFFECT_AFFINE;
        }

        G2_SetOBJEffect(pOam, effectTypeAfter, 0);
    }

    {

        const BOOL bShouldAdjust = G2_GetOBJEffect(pOam) == GX_OAM_EFFECT_AFFINE_DOUBLE;

        NNSi_G2dAdjustDifferenceOfRotateOrientation(pOam, pMtxSR, &objTrans, bShouldAdjust);
    }

    objTrans.x += pBaseTrans->x;
    objTrans.y += pBaseTrans->y;
    G2_SetOBJPosition(pOam, objTrans.x >> 12, objTrans.y >> 12);
}
