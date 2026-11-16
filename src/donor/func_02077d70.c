/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02065b3c from projets/children-of-mana/src/auto/func_02065b3c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
typedef int BOOL;
typedef s32 fx32;
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
extern const u16(*ctrdgi_fl_maxtime);
typedef enum NNSG2dOamType {
    NNS_G2D_OAMTYPE_MAIN = 0,
    NNS_G2D_OAMTYPE_SUB,
    NNS_G2D_OAMTYPE_SOFTWAREEMULATION,
    NNS_G2D_OAMTYPE_INVALID,
    NNS_G2D_OAMTYPE_MAX
} NNSG2dOamType;
typedef struct NNSG2dOAMManageArea {
    u16 fromIdx;
    u16 toIdx;
    u16 currentIdx;
} NNSG2dOAMManageArea;
typedef struct NNSG2dOamManagerInstance {
    NNSG2dOamType type;
    NNSG2dOAMManageArea managedAttrArea;
    NNSG2dOAMManageArea managedAffineArea;
    u16 GUID;
    u16 pad16_;
    BOOL bFastTransferEnable;
    fx32 spriteZoffsetStep;
} NNSG2dOamManagerInstance;
extern BOOL func_02077d70(NNSG2dOamManagerInstance *pMan, const GXOamAttr *pOam, u16 affineIdx);
typedef struct OamAttributeCache {
    u16 reservationTable[128];
    GXOamAttr oamBuffer[128];
} OamAttributeCache;
typedef struct OamAffineCache {
    u16 reservationTable[32];
} OamAffineCache;
typedef struct OamCache {
    OamAttributeCache attributeCache;
    OamAffineCache affineCache;
} OamCache;
extern OamCache data_02115580[3];
static inline BOOL IsManageAreaValid_(const NNSG2dOAMManageArea *pArea) {
    ((void) 0);

    return (BOOL) ((pArea->currentIdx <= pArea->toIdx + 1) && (pArea->fromIdx <= pArea->toIdx));
}
static inline OamCache *GetOamCachePtr_(NNSG2dOamType type) {
    ((void) 0);
    return &data_02115580[type];
}
static inline GXOamAttr *GetOamBufferPtr_(NNSG2dOamType type, u16 index) {
    ((void) 0);
    {
        OamCache *pOamCache = GetOamCachePtr_(type);
        ((void) 0);

        return pOamCache->attributeCache.oamBuffer + index;
    }
}
static inline u16 GetCapacity_(const NNSG2dOAMManageArea *pArea) {
    ((void) 0);

    if (IsManageAreaValid_(pArea)) {
        return (u16) ((int) pArea->toIdx - pArea->currentIdx + 1);
    } else {
        return 0;
    }
}
static inline BOOL HasEnoughCapacity_(const NNSG2dOAMManageArea *pArea, u16 num) {
    ((void) 0);
    ((void) 0);

    return (BOOL) (GetCapacity_(pArea) >= num);
}
static inline GXOamAttr *GetOamCurrentPtr_(NNSG2dOamManagerInstance *pMan) {
    ((void) 0);
    ((void) 0);
    ((void) 0);
    {

        GXOamAttr *pret = GetOamBufferPtr_(pMan->type, pMan->managedAttrArea.currentIdx);

        ((void) 0);

        return pret;
    }
}
BOOL func_02077d70(NNSG2dOamManagerInstance *pMan, const GXOamAttr *pOam, u16 affineIdx) {
    ((void) 0);
    ((void) 0);

    if (HasEnoughCapacity_(&pMan->managedAttrArea, 1)) {
        GXOamAttr *pOamAttr = GetOamCurrentPtr_(pMan);

        pOamAttr->attr0 = pOam->attr0;
        pOamAttr->attr1 = pOam->attr1;
        pOamAttr->attr2 = pOam->attr2;

        if (0xFFFE != affineIdx) {
            {
                if (pOamAttr->rsMode & 0x1) {
                    pOamAttr->rsParam = affineIdx;
                }
            }
        }

        pMan->managedAttrArea.currentIdx++;
        return 1;
    } else {
        ((void) 0);
        return 0;
    }
}
