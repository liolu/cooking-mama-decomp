/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02069c38 from projets/children-of-mana/src/auto/func_02069c38.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int BOOL;
typedef volatile u16 REGType16v;
typedef enum {
    GX_VRAM_A   = 0x0001,
    GX_VRAM_B   = 0x0002,
    GX_VRAM_C   = 0x0004,
    GX_VRAM_D   = 0x0008,
    GX_VRAM_E   = 0x0010,
    GX_VRAM_F   = 0x0020,
    GX_VRAM_G   = 0x0040,
    GX_VRAM_H   = 0x0080,
    GX_VRAM_I   = 0x0100,
    GX_VRAM_ALL = 0x01ff
} GXVRam;
typedef enum {
    GX_VRAM_BGEXTPLTT_NONE    = 0x0000,
    GX_VRAM_BGEXTPLTT_01_F    = GX_VRAM_F,
    GX_VRAM_BGEXTPLTT_23_G    = GX_VRAM_G,
    GX_VRAM_BGEXTPLTT_0123_E  = GX_VRAM_E,
    GX_VRAM_BGEXTPLTT_0123_FG = GX_VRAM_F | GX_VRAM_G
} GXVRamBGExtPltt;
extern GXVRamBGExtPltt func_020012b0(void);
typedef enum {
    GX_BG_SCRSIZE_TEXT_256x256 = 0,
    GX_BG_SCRSIZE_TEXT_512x256 = 1,
    GX_BG_SCRSIZE_TEXT_256x512 = 2,
    GX_BG_SCRSIZE_TEXT_512x512 = 3
} GXBGScrSizeText;
typedef enum {
    GX_BG_COLORMODE_16  = 0,
    GX_BG_COLORMODE_256 = 1
} GXBGColorMode;
typedef enum {
    GX_BG_CHARBASE_0x00000 = 0,
    GX_BG_CHARBASE_0x04000 = 1,
    GX_BG_CHARBASE_0x08000 = 2,
    GX_BG_CHARBASE_0x0c000 = 3,
    GX_BG_CHARBASE_0x10000 = 4,
    GX_BG_CHARBASE_0x14000 = 5,
    GX_BG_CHARBASE_0x18000 = 6,
    GX_BG_CHARBASE_0x1c000 = 7,
    GX_BG_CHARBASE_0x20000 = 8,
    GX_BG_CHARBASE_0x24000 = 9,
    GX_BG_CHARBASE_0x28000 = 10,
    GX_BG_CHARBASE_0x2c000 = 11,
    GX_BG_CHARBASE_0x30000 = 12,
    GX_BG_CHARBASE_0x34000 = 13,
    GX_BG_CHARBASE_0x38000 = 14,
    GX_BG_CHARBASE_0x3c000 = 15
} GXBGCharBase;
typedef enum {
    GX_BG_SCRBASE_0x0000 = 0,
    GX_BG_SCRBASE_0x0800 = 1,
    GX_BG_SCRBASE_0x1000 = 2,
    GX_BG_SCRBASE_0x1800 = 3,
    GX_BG_SCRBASE_0x2000 = 4,
    GX_BG_SCRBASE_0x2800 = 5,
    GX_BG_SCRBASE_0x3000 = 6,
    GX_BG_SCRBASE_0x3800 = 7,
    GX_BG_SCRBASE_0x4000 = 8,
    GX_BG_SCRBASE_0x4800 = 9,
    GX_BG_SCRBASE_0x5000 = 10,
    GX_BG_SCRBASE_0x5800 = 11,
    GX_BG_SCRBASE_0x6000 = 12,
    GX_BG_SCRBASE_0x6800 = 13,
    GX_BG_SCRBASE_0x7000 = 14,
    GX_BG_SCRBASE_0x7800 = 15,
    GX_BG_SCRBASE_0x8000 = 16,
    GX_BG_SCRBASE_0x8800 = 17,
    GX_BG_SCRBASE_0x9000 = 18,
    GX_BG_SCRBASE_0x9800 = 19,
    GX_BG_SCRBASE_0xa000 = 20,
    GX_BG_SCRBASE_0xa800 = 21,
    GX_BG_SCRBASE_0xb000 = 22,
    GX_BG_SCRBASE_0xb800 = 23,
    GX_BG_SCRBASE_0xc000 = 24,
    GX_BG_SCRBASE_0xc800 = 25,
    GX_BG_SCRBASE_0xd000 = 26,
    GX_BG_SCRBASE_0xd800 = 27,
    GX_BG_SCRBASE_0xe000 = 28,
    GX_BG_SCRBASE_0xe800 = 29,
    GX_BG_SCRBASE_0xf000 = 30,
    GX_BG_SCRBASE_0xf800 = 31
} GXBGScrBase;
typedef enum {
    GX_BG_EXTPLTT_01 = 0,
    GX_BG_EXTPLTT_23 = 1
} GXBGExtPltt;
typedef enum NNSG2dBGSelect {
    NNS_G2D_BGSELECT_MAIN0,
    NNS_G2D_BGSELECT_MAIN1,
    NNS_G2D_BGSELECT_MAIN2,
    NNS_G2D_BGSELECT_MAIN3,
    NNS_G2D_BGSELECT_SUB0,
    NNS_G2D_BGSELECT_SUB1,
    NNS_G2D_BGSELECT_SUB2,
    NNS_G2D_BGSELECT_SUB3,
    NNS_G2D_BGSELECT_NUM
} NNSG2dBGSelect;
inline int GetBGNo(NNSG2dBGSelect n) {
    return n & 3;
}
inline REGType16v *GetBGnCNT(NNSG2dBGSelect n) {
    extern REGType16v *const data_02084e5c[];
    return data_02084e5c[n];
}
inline BOOL IsMainBG(NNSG2dBGSelect bg) {
    return (bg <= NNS_G2D_BGSELECT_MAIN3);
}
inline BOOL IsMainBGExtPltt01Available(void) {
    GXVRamBGExtPltt pltt = func_020012b0();
    return (pltt == GX_VRAM_BGEXTPLTT_01_F) || (pltt == GX_VRAM_BGEXTPLTT_0123_E) || (pltt == GX_VRAM_BGEXTPLTT_0123_FG);
}
inline u16 MakeBGnCNTValText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                             GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    return (u16) ((screenSize << 14) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13) | (colorMode << 7));
}
inline void SetBGnControlText(NNSG2dBGSelect n, GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                              GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    *GetBGnCNT(n) = (u16) ((*GetBGnCNT(n) & (0x0003 | 0x0040)) |
                           MakeBGnCNTValText(screenSize, colorMode, screenBase, charBase, bgExtPltt));
}
extern const u8 data_02084e24[4][8];
extern void func_0207b500(const u8 modeTable[]);
extern void func_0207b4d8(const u8 modeTable[]);
void func_0207b1f0(NNSG2dBGSelect n, GXBGScrSizeText size, GXBGColorMode cmode, GXBGScrBase scnBase, GXBGCharBase chrBase) {
    const int bgNo      = GetBGNo(n);
    GXBGExtPltt extPltt = GX_BG_EXTPLTT_01;
    if (IsMainBG(n)) {
        if (!IsMainBGExtPltt01Available()) {
            extPltt = GX_BG_EXTPLTT_23;
        }
        func_0207b500(data_02084e24[bgNo]);
    } else {
        func_0207b4d8(data_02084e24[bgNo]);
    }
    SetBGnControlText(n, size, cmode, scnBase, chrBase, extPltt);
}
