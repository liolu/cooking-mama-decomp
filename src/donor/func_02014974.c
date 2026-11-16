/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201e4d0 from projets/code-lyoko/src/donor/func_0201e4d0.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    u32 data_buf[15][((29) + 1) / sizeof(u32) + 1];
    u32 data_bmp[15];
} MbRequestPieceBuf;
extern BOOL func_02014974(u16 child);
extern struct {
    int size;
    int num;
    int bufSize;
} data_020c6168;
extern MbRequestPieceBuf *data_020c6164;
BOOL func_02014974(u16 child) {
    u16 i;

    for (i = 0; i < data_020c6168.num; i++) {
        if ((data_020c6164->data_bmp[child - 1] & (1 << i)) == 0) {
            return 0;
        }
    }

    return 1;
}
