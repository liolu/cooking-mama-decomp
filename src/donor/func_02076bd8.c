/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02064c74 from projets/children-of-mana/src/auto/func_02064c74.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct NNSG2dAnimFrameData {
    void *pContent;
    u16 frames;
    u16 pad16;
} NNSG2dAnimFrameData;
typedef enum NNSG2dAnimationPlayMode {
    NNS_G2D_ANIMATIONPLAYMODE_INVALID = 0x0,
    NNS_G2D_ANIMATIONPLAYMODE_FORWARD,
    NNS_G2D_ANIMATIONPLAYMODE_FORWARD_LOOP,
    NNS_G2D_ANIMATIONPLAYMODE_REVERSE,
    NNS_G2D_ANIMATIONPLAYMODE_REVERSE_LOOP,
    NNS_G2D_ANIMATIONPLAYMODE_MAX
} NNSG2dAnimationPlayMode;
typedef struct NNSG2dAnimSequenceData {
    u16 numFrames;
    u16 loopStartFrameIdx;
    u32 animType;
    NNSG2dAnimationPlayMode playMode;
    NNSG2dAnimFrameData *pAnmFrameArray;
} NNSG2dAnimSequenceData;
typedef struct NNSG2dAnimBankData {
    u16 numSequences;
    u16 numTotalFrames;
    NNSG2dAnimSequenceData *pSequenceArrayHead;
    NNSG2dAnimFrameData *pFrameArrayHead;
    void *pAnimContents;
    void *pStringBank;
    void *pExtendedData;
} NNSG2dAnimBankData;
typedef struct NNSG2dUserExDataBlock {
    u32 blkTypeID;
    u32 blkSize;
} NNSG2dUserExDataBlock;
typedef struct NNSG2dUserExAnimFrameAttr {
    u32 *pAttr;
} NNSG2dUserExAnimFrameAttr;
typedef struct NNSG2dUserExAnimSequenceAttr {
    u16 numFrames;
    u16 pad16;
    u32 *pAttr;
    NNSG2dUserExAnimFrameAttr *pAnmFrmAttrArray;
} NNSG2dUserExAnimSequenceAttr;
typedef struct NNSG2dUserExAnimAttrBank {
    u16 numSequences;
    u16 numAttribute;
    NNSG2dUserExAnimSequenceAttr *pAnmSeqAttrArray;
} NNSG2dUserExAnimAttrBank;
void func_02076bd8(NNSG2dAnimBankData *pData) {
    u16 i, j;

    pData->pSequenceArrayHead = (pData->pSequenceArrayHead) = (void *) ((u32) (pData->pSequenceArrayHead) + (u32) pData);
    pData->pFrameArrayHead = (pData->pFrameArrayHead) = (void *) ((u32) (pData->pFrameArrayHead) + (u32) pData);
    pData->pAnimContents = (pData->pAnimContents) = (void *) ((u32) (pData->pAnimContents) + (u32) pData);

    {
        NNSG2dAnimSequenceData *pSeq    = pData->pSequenceArrayHead;
        NNSG2dAnimFrameData *pFrameBase = pData->pFrameArrayHead;
        void *pContentsBase             = pData->pAnimContents;

        for (i = 0; i < pData->numSequences; i++) {
            pSeq[i].pAnmFrameArray = (pSeq[i].pAnmFrameArray) = (void *) ((u32) (pSeq[i].pAnmFrameArray) + (u32) pFrameBase);

            for (j = 0; j < pSeq[i].numFrames; j++) {
                pSeq[i].pAnmFrameArray[j].pContent = (pSeq[i].pAnmFrameArray[j].pContent) =
                    (void *) ((u32) (pSeq[i].pAnmFrameArray[j].pContent) + (u32) pContentsBase);
            }
        }
    }

    if (pData->pExtendedData != ((void *) 0)) {
        pData->pExtendedData = (pData->pExtendedData) = (void *) ((u32) (pData->pExtendedData) + (u32) pData);
        {
            u32 i = 0;
            u32 j = 0;

            NNSG2dUserExDataBlock *pExBlk            = (NNSG2dUserExDataBlock *) pData->pExtendedData;
            NNSG2dUserExAnimAttrBank *pAnmExAttrBank = (NNSG2dUserExAnimAttrBank *) (pExBlk + 1);
            pAnmExAttrBank->pAnmSeqAttrArray         = (pAnmExAttrBank->pAnmSeqAttrArray) =
                (void *) ((u32) (pAnmExAttrBank->pAnmSeqAttrArray) + (u32) pAnmExAttrBank);

            for (i = 0; i < pAnmExAttrBank->numSequences; i++) {
                NNSG2dUserExAnimSequenceAttr *pSeqAttr = &pAnmExAttrBank->pAnmSeqAttrArray[i];

                pSeqAttr->pAttr = (pSeqAttr->pAttr) = (void *) ((u32) (pSeqAttr->pAttr) + (u32) pAnmExAttrBank);
                pSeqAttr->pAnmFrmAttrArray          = (pSeqAttr->pAnmFrmAttrArray) =
                    (void *) ((u32) (pSeqAttr->pAnmFrmAttrArray) + (u32) pAnmExAttrBank);
                for (j = 0; j < pSeqAttr->numFrames; j++) {
                    NNSG2dUserExAnimFrameAttr *pFrm = &pSeqAttr->pAnmFrmAttrArray[j];
                    pFrm->pAttr = (pFrm->pAttr) = (void *) ((u32) (pFrm->pAttr) + (u32) pAnmExAttrBank);
                }
            }
        }
    }
}
