/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201e530 from projets/code-lyoko/src/donor/func_0201e530.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern void func_02006ae4(const void *src, void *dest, u32 size);
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    u8 type;
    u8 pad1[1];
    union {
        struct {
            u16 req;
            u8 reserved[((16) - 2)];
        } data;
        struct {
            u8 piece;

            u8 data[((16) - 2)];
            u8 pad2[1];
        } req_data;
    };
} MBCommChildBlockHeader;
typedef struct {
    u32 data_buf[15][((29) + 1) / sizeof(u32) + 1];
    u32 data_bmp[15];
} MbRequestPieceBuf;
extern u8 *func_020149d4(const MBCommChildBlockHeader *hdr, u16 child);
extern BOOL func_02014974(u16 child);
extern struct {
    int size;
    int num;
    int bufSize;
} data_020c6168;
extern MbRequestPieceBuf *data_020c6164;
u8 *func_020149d4(const MBCommChildBlockHeader *hdr, u16 child) {
    u8 piece;
    u8 *ptr;

    if (data_020c6164 == 0) {
        return 0;
    }

    piece = hdr->req_data.piece;

    if (piece > data_020c6168.num) {
        return 0;
    }

    ptr = ((u8 *) data_020c6164->data_buf[child - 1]) + (piece * data_020c6168.size);

    func_02006ae4(&hdr->req_data.data[0], ptr, (u32) data_020c6168.size);
    data_020c6164->data_bmp[child - 1] |= (1 << piece);

    ((void) 0);

    if (func_02014974(child)) {
        return (u8 *) data_020c6164->data_buf[child - 1];
    }

    return 0;
}
extern BOOL func_02014974(u16 child);
