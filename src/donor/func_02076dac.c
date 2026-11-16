/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02064e54 from projets/children-of-mana/src/auto/func_02064e54.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct NNSG2dCellVramTransferData {
    u32 srcDataOffset;
    u32 szByte;
} NNSG2dCellVramTransferData;
typedef struct NNSG2dVramTransferData {
    u32 szByteMax;
    NNSG2dCellVramTransferData *pCellTransferDataArray;
} NNSG2dVramTransferData;
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
typedef enum NNSG2dCharacterDataMappingType {
    NNS_G2D_CHARACTERMAPPING_1D_32,
    NNS_G2D_CHARACTERMAPPING_1D_64,
    NNS_G2D_CHARACTERMAPPING_1D_128,
    NNS_G2D_CHARACTERMAPPING_1D_256,
    NNS_G2D_CHARACTERMAPPING_2D,
    NNS_G2D_CHARACTERMAPPING_MAX
} NNSG2dCharacterDataMappingType;
typedef struct NNSG2dCellDataBank {
    u16 numCells;
    u16 cellBankAttr;
    NNSG2dCellData *pCellDataArrayHead;
    NNSG2dCharacterDataMappingType mappingMode;
    NNSG2dVramTransferData *pVramTransferData;
    void *pStringBank;
    void *pExtendedData;
} NNSG2dCellDataBank;
extern const NNSG2dCellData *func_02076e58(const NNSG2dCellDataBank *pCellData, u16 idx);
extern void *func_02076ee4(NNSG2dCellDataBank *pCellBank);
extern void func_02076ed4(void *pExData);
extern const NNSG2dCellData *func_02076e58(const NNSG2dCellDataBank *pCellData, u16 idx);
void func_02076dac(NNSG2dCellDataBank *pCellData) {
    {
        pCellData->pCellDataArrayHead = (pCellData->pCellDataArrayHead) =
            (void *) ((u32) (pCellData->pCellDataArrayHead) + (u32) pCellData);

        {
            void *pHeadOfOAMData = func_02076ee4(pCellData);

            u16 i;
            NNSG2dCellData *pCell = ((void *) 0);
            for (i = 0; i < pCellData->numCells; i++) {
                pCell                = (NNSG2dCellData *) (func_02076e58(pCellData, i));
                pCell->pOamAttrArray = (pCell->pOamAttrArray) = (void *) ((u32) (pCell->pOamAttrArray) + (u32) pHeadOfOAMData);
            }
        }

        if (pCellData->pVramTransferData != ((void *) 0)) {
            NNSG2dVramTransferData *pVramTsfmData = (pCellData->pVramTransferData) =
                (void *) ((u32) (pCellData->pVramTransferData) + (u32) pCellData);

            pVramTsfmData->pCellTransferDataArray = (pVramTsfmData->pCellTransferDataArray) =
                (void *) ((u32) (pVramTsfmData->pCellTransferDataArray) + (u32) pVramTsfmData);
            pCellData->pVramTransferData = pVramTsfmData;
        }

        if (pCellData->pExtendedData != ((void *) 0)) {
            pCellData->pExtendedData = (pCellData->pExtendedData) =
                (void *) ((u32) (pCellData->pExtendedData) + (u32) pCellData);
            func_02076ed4(pCellData->pExtendedData);
        }
    }
}
