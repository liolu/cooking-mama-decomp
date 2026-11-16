/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206957c from projets/children-of-mana/src/auto/func_0206957c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef u8 GXScrFmtAffine;
typedef struct NNSG2dScreenData {
    u16 screenWidth;
    u16 screenHeight;
    u16 colorMode;
    u16 screenFormat;
    u32 szByte;
    u32 rawData[1];
} NNSG2dScreenData;
extern void func_02006ae4(const void *src, void *dest, u32 size);
void func_0207ab34(void *pScreenDst, const NNSG2dScreenData *pScnData, int srcX, int srcY, int dstX, int dstY, int dstW,
                   int width, int height) {

    {
        const int src_y_end        = srcY + height;
        const int srcW             = pScnData->screenWidth / 8;
        const u32 szLine           = sizeof(GXScrFmtAffine) * width;
        const GXScrFmtAffine *pSrc = (const GXScrFmtAffine *) pScnData->rawData;
        GXScrFmtAffine *pDst       = (GXScrFmtAffine *) pScreenDst;
        int y;

        pSrc += srcY * srcW + srcX;
        pDst += dstY * dstW + dstX;

        for (y = srcY; y < src_y_end; y++) {
            func_02006ae4(pSrc, pDst, szLine);
            pSrc += srcW;
            pDst += dstW;
        }
    }
}
