/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02069f48 from projets/children-of-mana/src/auto/func_02069f48.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;
typedef volatile u32 REGType32v;
typedef enum {
    GX_DISPMODE_GRAPHICS = 0x01,
    GX_DISPMODE_VRAM_A   = 0x02,
    GX_DISPMODE_VRAM_B   = 0x06,
    GX_DISPMODE_VRAM_C   = 0x0a,
    GX_DISPMODE_VRAM_D   = 0x0e,
    GX_DISPMODE_MMEM     = 0x03
} GXDispMode;
typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;
typedef enum {
    GX_BG0_AS_2D = 0,
    GX_BG0_AS_3D = 1
} GXBG0As;
extern void func_02000f74(GXDispMode dispMode, GXBGMode bgMode, GXBG0As bg0_2d3d);
inline BOOL IsBG03D(void) {
    return ((*(REGType32v *) (0x04000000 + 0x000)) & 0x00000008) != 0;
}
inline GXBGMode GetBGModeMain(void) {
    return (GXBGMode) (((*(REGType32v *) (0x04000000 + 0x000)) & 0x00000007) >> 0);
}
void func_0207b500(const u8 modeTable[]) {
    GXBGMode mode = (GXBGMode) modeTable[GetBGModeMain()];
    GXBG0As bg0as = IsBG03D() ? GX_BG0_AS_3D : GX_BG0_AS_2D;

    if (mode >= 8) {
        mode -= 8;
    }

    func_02000f74(GX_DISPMODE_GRAPHICS, mode, bg0as);
}
