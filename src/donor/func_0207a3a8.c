/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068df0 from projets/children-of-mana/src/auto/func_02068df0.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef volatile u32 vu32;
typedef vu32 REGType32v;
typedef int BOOL;
typedef s32 fx32;
typedef s16 fx16;
typedef enum {
    GX_BEGIN_TRIANGLES      = 0,
    GX_BEGIN_QUADS          = 1,
    GX_BEGIN_TRIANGLE_STRIP = 2,
    GX_BEGIN_QUAD_STRIP     = 3
} GXBegin;
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
typedef u32 GXSt;
typedef u32 VecVtx10;
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
static inline GXOamEffect G2_GetOBJEffect(const GXOamAttr *oam) {
    GXOamEffect effect;

    ((void) 0);

    effect = (GXOamEffect) (oam->attr01 & 0x00000300);

    if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        return effect;
    }

    return (GXOamEffect) (effect | (oam->attr01 & 0x30000000));
}
extern void G3_Scale(fx32 x, fx32 y, fx32 z);
extern void G3_Translate(fx32 x, fx32 y, fx32 z);
extern void G3_TexCoord(fx32 s, fx32 t);
extern void G3_Vtx10(fx16 x, fx16 y, fx16 z);
extern void G3_Begin(GXBegin primitive);
extern void G3_End(void);
static inline void G3_Scale(fx32 x, fx32 y, fx32 z) {
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) x;
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) y;
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) z;
}
static inline void G3_Translate(fx32 x, fx32 y, fx32 z) {
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) x;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) y;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) z;
}
static inline void G3_TexCoord(fx32 s, fx32 t) {
    ((void) 0);
    ((void) 0);

    (*(REGType32v *) (0x04000000 + 0x488)) = (((GXSt) ((u16) ((s16) (((s)) >> 8)) | ((u16) ((s16) (((t)) >> 8)) << 16))));
}
static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x490)) = ((u32) ((VecVtx10) ((((((x)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 0) |
                                                                 (((((y)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 10) |
                                                                 (((((z)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 20))));
}
static inline void G3_Begin(GXBegin primitive) {
    ((void) 0);
    (*(REGType32v *) (0x04000000 + 0x500)) = ((u32) ((primitive) << 0));
}
static inline void G3_End(void) {
    (*(REGType32v *) (0x04000000 + 0x504)) = 0;
}
extern const u16(*ctrdgi_fl_maxtime);
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
typedef struct NNSG2dImageAttr {
    GXTexSizeS sizeS;
    GXTexSizeT sizeT;
    GXTexFmt fmt;
    BOOL bExtendedPlt;
    GXTexPlttColor0 plttUse;
    GXOBJVRamModeChar mappingType;
} NNSG2dImageAttr;
extern void func_0207a3a8(s16 posX, s16 posY, s16 posZ, const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr,
                          u32 texBaseAddr, u32 pltBaseAddr);
typedef struct SpriteParams {
    fx32 u0;
    fx32 v0;
    fx32 u1;
    fx32 v1;
    int sx;
    int sy;
} SpriteParams;
extern BOOL data_021174e0;
extern fx32 data_021174e8;
extern fx32 data_020c2b30;
static inline void IncreaseAutoZOffset_(void) {
    if (data_021174e0) {
        data_021174e8 += data_020c2b30;
    }
}
static inline fx32 GetFx32DepthValue_(int z) {
    if (data_021174e0) {
        return (z << 12) + data_021174e8;
    } else {
        return (z << 12);
    }
}
static inline void SetQuadTranslation_(const GXOamAttr *pOam, const int posX, const int posY, const int posZ) {

#pragma inline_max_size(20000)
#line 223
    if (G2_GetOBJEffect(pOam) == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        const GXOamShape oamShape = NNS_G2dGetOAMSize(pOam);
        const int halfW           = NNS_G2dGetOamSizeX(&oamShape) >> 1;
        const int halfH           = NNS_G2dGetOamSizeY(&oamShape) >> 1;

        G3_Translate((posX + halfW) << 12, (posY + halfH) << 12, GetFx32DepthValue_(posZ));
    } else {
        G3_Translate(posX << 12, posY << 12, GetFx32DepthValue_(posZ));
    }
}
extern void func_0207a688(const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr, u32 pltBaseAddr,
                          SpriteParams *pResult);
void func_0207a3a8(s16 posX, s16 posY, s16 posZ, const GXOamAttr *pOam, const NNSG2dImageAttr *pTexImageAttr, u32 texBaseAddr,
                   u32 pltBaseAddr) {
    ((void) 0);
    ((void) 0);

    {
        SpriteParams spriteParams;
        func_0207a688(pOam, pTexImageAttr, texBaseAddr, pltBaseAddr, &spriteParams);

        SetQuadTranslation_(pOam, posX, posY, posZ);

        G3_Scale(spriteParams.sx << 12, spriteParams.sy << 12, ((fx32) 0x0000000000001000L));

        {
            const fx32 size = ((fx32) 0x0000000000001000L);

            G3_Begin(GX_BEGIN_QUADS);

            G3_TexCoord(spriteParams.u0, spriteParams.v1);
            G3_Vtx10(0, size, 0);

            G3_TexCoord(spriteParams.u1, spriteParams.v1);
            G3_Vtx10(size, size, 0);

            G3_TexCoord(spriteParams.u1, spriteParams.v0);
            G3_Vtx10(size, 0, 0);

            G3_TexCoord(spriteParams.u0, spriteParams.v0);
            G3_Vtx10(0, 0, 0);

            G3_End();
        }

        IncreaseAutoZOffset_();
    }
}
