/* compiler: 1.2/sp2p3  */
/* OS_RescheduleThread from projets/rayman-rr/src/auto/OS_RescheduleThread.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef long s32;
typedef unsigned long u32;
typedef void (*RescheduleCb)(void *, void *);
extern u32 data_020c2c00;
extern void *data_020c2c0c;
extern RescheduleCb data_020c2c08;
extern u8 data_020c2c14[];
extern unsigned long func_020061ec(void);
extern s32 func_02004ab8(void);
extern s32 func_020051ec(void *ctx);
extern void func_02005238(void *ctx);
void func_020049cc(void) {
    u8 *info;
    u8 *cur;
    u8 *sel;

    info = data_020c2c14;
    if (data_020c2c00 != 0) {
        return;
    }
    if (*(u16 *) (info + 2) != 0 || func_020061ec() == 0x12) {
        *(u16 *) info = 1;
        return;
    }
    cur = *(u8 **) data_020c2c0c;
    sel = (u8 *) func_02004ab8();
    if (cur == sel) {
        return;
    }
    if (sel == 0) {
        return;
    }
    if (*(u32 *) (cur + 0x64) != 2) {
        if (func_020051ec(cur) != 0) {
            return;
        }
    }
    if (data_020c2c08 != 0) {
        data_020c2c08(cur, sel);
    }
    if (*(RescheduleCb *) (info + 0xc) != 0) {
        (*(RescheduleCb *) (info + 0xc))(cur, sel);
    }
    *(u8 **) (data_020c2c14 + 4) = sel;
    func_02005238(sel);
}
