/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206a544 from projets/children-of-mana/src/auto/func_0206a544.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
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
extern void func_02002204(const MtxFx43 *m);
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
typedef enum NNSG2dRendererFlip {
    NNS_G2D_RENDERERFLIP_NONE = 0x00,
    NNS_G2D_RENDERERFLIP_H    = 0x01,
    NNS_G2D_RENDERERFLIP_V    = 0x02
} NNSG2dRendererFlip;
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
extern BOOL func_0207b950(const NNSG2dRndCoreInstance *pRnd);
extern BOOL func_0207b93c(const NNSG2dRndCoreInstance *pRnd);
extern BOOL NNSi_G2dGetOamFlipH(const GXOamAttr *oamAttr);
extern BOOL NNSi_G2dGetOamFlipV(const GXOamAttr *oamAttr);
inline BOOL NNSi_G2dGetOamFlipH(const GXOamAttr *oamAttr) {
    return (BOOL) (oamAttr->flipH);
}
inline BOOL NNSi_G2dGetOamFlipV(const GXOamAttr *oamAttr) {
    return (BOOL) (oamAttr->flipV);
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
extern void func_0207a3a8(s16 posX, s16 posY, s16 posZ, const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr,
                          u32 texBaseAddr, u32 pltBaseAddr);
extern NNSG2dRndCoreInstance *data_021174f0;
static inline u16 GetFlipedOBJPosX_(GXOamAttr *pOam, const GXOamShape shape) {
    return func_0207b950(data_021174f0) ? (u16) (-NNS_G2dRepeatXinCellSpace((s16) pOam->x) - NNS_G2dGetOamSizeX(&shape))
                                        : (u16) NNS_G2dRepeatXinCellSpace((s16) pOam->x);
}
static inline u16 GetFlipedOBJPosY_(GXOamAttr *pOam, const GXOamShape shape) {
    return func_0207b93c(data_021174f0) ? (u16) (-NNS_G2dRepeatYinCellSpace((s16) pOam->y) - NNS_G2dGetOamSizeY(&shape))
                                        : (u16) NNS_G2dRepeatYinCellSpace((s16) pOam->y);
}
static inline void OverwriteOamFlipFlag_(GXOamAttr *pOam) {
    ((void) 0);
    {

        const BOOL bFlipH = func_0207b950(data_021174f0) ^ NNSi_G2dGetOamFlipH(pOam);
        const BOOL bFlipV = func_0207b93c(data_021174f0) ^ NNSi_G2dGetOamFlipV(pOam);

        pOam->attr01 &= ~0x10000000;
        pOam->attr01 |= bFlipH << 28;

        pOam->attr01 &= ~0x20000000;
        pOam->attr01 |= bFlipV << 29;
    }
}
void func_0207bb28(GXOamAttr *pOam) {
    func_02002204(&data_021174f0->mtxFor3DGE);

    if (data_021174f0->flipFlag != NNS_G2D_RENDERERFLIP_NONE) {
        const GXOamShape shape = NNS_G2dGetOAMSize(pOam);

        const s16 posX = (s16) GetFlipedOBJPosX_(pOam, shape);
        const s16 posY = (s16) GetFlipedOBJPosY_(pOam, shape);
        const s16 posZ = -1;

        OverwriteOamFlipFlag_(pOam);

        func_0207a3a8(posX, posY, posZ, pOam, &data_021174f0->pImgProxy->attr, data_021174f0->baseTexAddr3D,
                      data_021174f0->basePltAddr3D);
    } else {
        const s16 posX = (s16) NNS_G2dRepeatXinCellSpace((s16) pOam->x);
        const s16 posY = (s16) NNS_G2dRepeatYinCellSpace((s16) pOam->y);
        const s16 posZ = -1;

        func_0207a3a8(posX, posY, posZ, pOam, &data_021174f0->pImgProxy->attr, data_021174f0->baseTexAddr3D,
                      data_021174f0->basePltAddr3D);
    }
}
extern BOOL func_0207b950(const NNSG2dRndCoreInstance *pRnd);
extern BOOL func_0207b93c(const NNSG2dRndCoreInstance *pRnd);
