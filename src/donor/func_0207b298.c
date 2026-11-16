/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02069ce0 from projets/children-of-mana/src/auto/func_02069ce0.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef enum NNSG2dBGExtPlttSlot {
    NNS_G2D_BGEXTPLTTSLOT_MAIN0,
    NNS_G2D_BGEXTPLTTSLOT_MAIN1,
    NNS_G2D_BGEXTPLTTSLOT_MAIN2,
    NNS_G2D_BGEXTPLTTSLOT_MAIN3,
    NNS_G2D_BGEXTPLTTSLOT_SUB0,
    NNS_G2D_BGEXTPLTTSLOT_SUB1,
    NNS_G2D_BGEXTPLTTSLOT_SUB2,
    NNS_G2D_BGEXTPLTTSLOT_SUB3
} NNSG2dBGExtPlttSlot;
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
extern const u16 data_02084dbc[8];
NNSG2dBGExtPlttSlot func_0207b298(NNSG2dBGSelect bg) {
    u32 addr;
    NNSG2dBGExtPlttSlot slot = (NNSG2dBGExtPlttSlot) bg;

    addr = data_02084dbc[bg];

    if (addr != 0) {
        addr += 0x04000000;

        if ((*(u16 *) addr & 0x2000) != 0) {
            slot += 2;
        }
    }

    return slot;
}
