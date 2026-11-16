/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020690d0 from projets/children-of-mana/src/auto/func_020690d0.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed long s32;
typedef s32 fx32;
typedef int BOOL;
typedef enum {
    GX_OAM_SHAPE_8x8 = 0
} GXOamShape;
typedef enum GXOBJVRamModeChar {
    GX_OBJVRAMMODE_CHAR_2D      = 0x00000000,
    GX_OBJVRAMMODE_CHAR_1D_32K  = 0x00000010,
    GX_OBJVRAMMODE_CHAR_1D_64K  = 0x00100010,
    GX_OBJVRAMMODE_CHAR_1D_128K = 0x00200010,
    GX_OBJVRAMMODE_CHAR_1D_256K = 0x00300010
} GXOBJVRamModeChar;
typedef enum GXTexFmt {
    GX_TEXFMT_NONE    = 0,
    GX_TEXFMT_A3I5    = 1,
    GX_TEXFMT_PLTT4   = 2,
    GX_TEXFMT_PLTT16  = 3,
    GX_TEXFMT_PLTT256 = 4,
    GX_TEXFMT_COMP4x4 = 5,
    GX_TEXFMT_A5I3    = 6,
    GX_TEXFMT_DIRECT  = 7
} GXTexFmt;
typedef enum GXTexSizeS {
    GX_TEXSIZE_S8 = 0,
    GX_TEXSIZE_S16,
    GX_TEXSIZE_S32,
    GX_TEXSIZE_S64,
    GX_TEXSIZE_S128,
    GX_TEXSIZE_S256,
    GX_TEXSIZE_S512,
    GX_TEXSIZE_S1024
} GXTexSizeS;
typedef enum GXTexSizeT {
    GX_TEXSIZE_T8 = 0,
    GX_TEXSIZE_T16,
    GX_TEXSIZE_T32,
    GX_TEXSIZE_T64,
    GX_TEXSIZE_T128,
    GX_TEXSIZE_T256,
    GX_TEXSIZE_T512,
    GX_TEXSIZE_T1024
} GXTexSizeT;
typedef enum GXTexPlttColor0 {
    GX_TEXPLTTCOLOR0_USE  = 0,
    GX_TEXPLTTCOLOR0_TRNS = 1
} GXTexPlttColor0;
typedef union GXOamAttr {
    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 attr3;
    };
    struct {
        u32 attr01;
        u32 attr23;
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
        u32 charNo : 10;
        u32 priority : 2;
        u32 cParam : 4;
        u32 _3 : 16;
    };
    struct {
        u32 _0 : 28;
        u32 flipH : 1;
        u32 flipV : 1;
        u32 _1 : 2;
        u32 _2 : 2;
        u32 _4 : 16;
    };
} GXOamAttr;
typedef struct NNSG2dImageAttr {
    GXTexSizeS sizeS;
    GXTexSizeT sizeT;
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    GXTexPlttColor0 plttUse;
    GXOBJVRamModeChar mappingType;
} NNSG2dImageAttr;
typedef struct SpriteParams {
    fx32 u0;
    fx32 v0;
    fx32 u1;
    fx32 v1;
    int sx;
    int sy;
} SpriteParams;
typedef void (*UVFlipCorrectFunc)(fx32 *pU0, fx32 *pV0, fx32 *pU1, fx32 *pV1, BOOL bFlipH, BOOL bFlipV);
struct UVFlipState {
    UVFlipCorrectFunc pFunc;
    fx32 zOffset;
    u32 zOffsetEnabled;
};
extern void func_0207a688(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr,
                          SpriteParams *pResult);
extern struct UVFlipState data_021174e4;
extern const u16 data_02084d0c[3][4];
extern const u16 data_02084cf4[3][4];
extern const u32 data_02084d2c[8];
extern const GXTexSizeS data_02084d4c[3][4];
extern const GXTexSizeT data_02084d7c[3][4];
extern const GXTexFmt data_02084d24[2];
static inline void G3_TexPlttBase(u32 addr, GXTexFmt texfmt) {
    (*(volatile u32 *) 0x040004AC) = (u32) ((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4)));
}
static inline GXOamShape NNS_G2dGetOAMSize(const GXOamAttr *oamAttr) {
    const GXOamShape result = (GXOamShape) ((0x0000c000 | 0xc0000000) & oamAttr->attr01);
    return result;
}
static inline int NNS_G2dGetOamSizeX(const GXOamShape *oamShape) {
    return data_02084d0c[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline int NNS_G2dGetOamSizeY(const GXOamShape *oamShape) {
    return data_02084cf4[(*oamShape & 0x0000c000) >> 14][(*oamShape & 0xc0000000) >> 30];
}
static inline BOOL NNSi_G2dGetOamFlipH(const GXOamAttr *oamAttr) {
    return (BOOL) (oamAttr->flipH);
}
static inline BOOL NNSi_G2dGetOamFlipV(const GXOamAttr *oamAttr) {
    return (BOOL) (oamAttr->flipV);
}
static inline u32 GetNumTexChar_(GXTexSizeS texSize) {
    return data_02084d2c[texSize];
}
static inline void DoFlip_(BOOL bFlipH, BOOL bFlipV, fx32 *pRetU0, fx32 *pRetU1, fx32 *pRetV0, fx32 *pRetV1) {
    {
        fx32 temp;
        if (bFlipH) {
            temp    = *pRetU0;
            *pRetU0 = *pRetU1;
            *pRetU1 = temp;
        }

        if (bFlipV) {
            temp    = *pRetV0;
            *pRetV0 = *pRetV1;
            *pRetV1 = temp;
        }

        if (data_021174e4.pFunc) {
            (*data_021174e4.pFunc)(pRetU0, pRetV0, pRetU1, pRetV1, bFlipH, bFlipV);
        }
    }
}
static inline void CalcUVFor3DDirect2DMap_(const NNSG2dImageAttr *pTexImageAttr, u16 charName, fx32 *pRetU0, fx32 *pRetV0) {
    if (pTexImageAttr->fmt == GX_TEXFMT_PLTT256) {
        charName >>= 1;
    }

    {
        {
            const u32 numCharPerOneLine = GetNumTexChar_(pTexImageAttr->sizeS);

            *pRetU0 = (fx32) (((charName & (numCharPerOneLine - 1)) << 3) << 12);
            *pRetV0 = ((charName >> pTexImageAttr->sizeS) << 3) << 12;
        }
    }
}
static inline void CalcUVFor3DDirect1DMap_(fx32 *pRetU0, fx32 *pRetV0) {
    {
        *pRetU0 = 0;
        *pRetV0 = 0;
    }
}
static inline u32 GetOffsetByteSizeOfPlt_(GXTexFmt pltFmt, BOOL bExtendedPlt, u16 pltNo) {
    if (bExtendedPlt) {
        return (u32) (pltNo << 9);
    } else {
        if (pltFmt == GX_TEXFMT_PLTT256) {
            return 0;
        } else {
            return (u32) (pltNo << 5);
        }
    }
}
static inline int GetCharacterNameShiftBit_(GXOBJVRamModeChar objMappingMode) {
    return (objMappingMode & 0x00700000) >> 20;
}
static inline void SetTextureParamsFor3DDirect1DMap_(const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, GXOamShape shape,
                                                     u16 charName) {
    {
        const u16 shapeBit = (u16) ((shape & 0x0000c000) >> 14);
        const u16 sizeBit  = (u16) ((shape & 0xc0000000) >> 30);
        const int shiftBit = (5 + GetCharacterNameShiftBit_(pTexImageAttr->mappingType));

        (*(volatile u32 *) 0x040004A8) =
            ((u32) (((texBaseAddr + (charName << shiftBit)) >> 3) | ((pTexImageAttr->fmt) << 26) | ((1) << 30) |
                    ((data_02084d4c[shapeBit][sizeBit]) << 20) | ((data_02084d7c[shapeBit][sizeBit]) << 23) | ((0) << 16) |
                    ((0) << 18) | ((pTexImageAttr->plttUse) << 29)))

            ;
    }
}
static inline void SetTextureParamsFor3DDirect2DMap_(const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr) {
    {
        (*(volatile u32 *) 0x040004A8) =
            ((u32) (((texBaseAddr) >> 3) | ((pTexImageAttr->fmt) << 26) | ((1) << 30) | ((pTexImageAttr->sizeS) << 20) |
                    ((pTexImageAttr->sizeT) << 23) | ((0) << 16) | ((0) << 18) | ((pTexImageAttr->plttUse) << 29)))

            ;
    }
}
static inline void SetPaletteParamsFor3DDirect_(const NNSG2dImageAttr *pTexImageAttr, u32 pltBaseAddr, const GXOamAttr *pOam) {
    {
        const GXTexFmt pltFmt = data_02084d24[pOam->colorMode];

        const u32 pltOffs = GetOffsetByteSizeOfPlt_(pltFmt, pTexImageAttr->bExtendedPlt, (u16) pOam->cParam);

        G3_TexPlttBase(pltBaseAddr + pltOffs, pltFmt);
    }
}
void func_0207a688(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr,
                   SpriteParams *pResult) {
    const GXOamShape shapeOam = NNS_G2dGetOAMSize(pOam);
    const u16 charName        = (u16) pOam->charNo;

    pResult->sx = NNS_G2dGetOamSizeX(&shapeOam);
    pResult->sy = NNS_G2dGetOamSizeY(&shapeOam);

    if (pTexImageAttr->mappingType == GX_OBJVRAMMODE_CHAR_2D) {
        SetTextureParamsFor3DDirect2DMap_(pTexImageAttr, texBaseAddr);
        CalcUVFor3DDirect2DMap_(pTexImageAttr, charName, &pResult->u0, &pResult->v0);
    } else {
        SetTextureParamsFor3DDirect1DMap_(pTexImageAttr, texBaseAddr, shapeOam, charName);
        CalcUVFor3DDirect1DMap_(&pResult->u0, &pResult->v0);
    }

    pResult->u1 = pResult->u0 + (pResult->sx << 12);
    pResult->v1 = pResult->v0 + (pResult->sy << 12);

    DoFlip_(NNSi_G2dGetOamFlipH(pOam), NNSi_G2dGetOamFlipV(pOam), &pResult->u0, &pResult->u1, &pResult->v0, &pResult->v1);

    SetPaletteParamsFor3DDirect_(pTexImageAttr, pltBaseAddr, pOam);
}
