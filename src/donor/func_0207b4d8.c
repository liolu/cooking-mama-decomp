/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02069f20 from projets/children-of-mana/src/auto/func_02069f20.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
typedef volatile u32 REGType32v;
typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;
extern void func_02000f58(GXBGMode bgMode);
inline GXBGMode GetBGModeSub(void) {
    return (GXBGMode) (((*(REGType32v *) (0x04000000 + 0x1000)) & 0x00000007) >> 0);
}
void func_0207b4d8(const u8 modeTable[]) {
    GXBGMode mode = (GXBGMode) modeTable[GetBGModeSub()];

    if (mode >= 8) {
        mode -= 8;
    }

    func_02000f58(mode);
}
