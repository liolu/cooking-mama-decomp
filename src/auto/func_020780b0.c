/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* NNS_G2dGetPaletteTableValue from https://github.com/ntrtwl/NitroSystem libraries/g2d/src/g2d_PaletteTable.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned short int u16;
extern const u16(*ctrdgi_fl_maxtime);
typedef struct NNSG2dPaletteSwapTable {
    u16 paletteIndex[16];
} NNSG2dPaletteSwapTable;
extern u16 func_020780b0(const NNSG2dPaletteSwapTable *pPlttTbl, u16 beforeIdx);
u16 func_020780b0(const NNSG2dPaletteSwapTable *pPlttTbl, u16 beforeIdx) {
    ((void) 0);
    ((void) 0);

    {
        const u16 afterIdx = pPlttTbl->paletteIndex[beforeIdx];
        ((void) 0);
        return afterIdx;
    }
}
