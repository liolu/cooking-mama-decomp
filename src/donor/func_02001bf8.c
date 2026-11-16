/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205717c from projets/children-of-mana/src/auto/func_0205717c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef volatile u8 vu8;
typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clearImage;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 subBg;
    u16 subObj;
    u16 subBgExtPltt;
    u16 subObjExtPltt;
} UnkGxVramState;
extern UnkGxVramState data_020c2b48;
extern UnkGxVramState data_020c2b48;
extern void func_02002130(u32 lcdc);
void func_02001bf8(s32 bgExtPltt) {
    data_020c2b48.lcdc      = ~bgExtPltt & (data_020c2b48.lcdc | data_020c2b48.bgExtPltt);
    data_020c2b48.bgExtPltt = bgExtPltt;

    switch (bgExtPltt) {
        case 0x10:
            (*(u32 *) ((0x04000000) | 0x0)) |= 0x40000000;
            (*(vu8 *) 0x04000244) = 0x84;
            break;
        case 0x40:
            (*(u32 *) ((0x04000000) | 0x0)) |= 0x40000000;
            (*(vu8 *) 0x04000246) = 0x8c;
            break;
        case 0x60:
            (*(vu8 *) 0x04000246) = 0x8c;
        case 0x20:
            (*(vu8 *) 0x04000245) = 0x84;
            (*(u32 *) ((0x04000000) | 0x0)) |= 0x40000000;
            break;
        case 0x00:
            (*(u32 *) ((0x04000000) | 0x0)) &= ~0x40000000;
            break;
        default:
            break;
    }
    func_02002130(data_020c2b48.lcdc);
}
