/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201e5e0 from projets/code-lyoko/src/donor/func_0201e5e0.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern void func_02006ae4(const void *src, void *dest, u32 size);
extern const u16(*ctrdgi_fl_maxtime);
typedef enum MBCommType {
    MB_COMM_TYPE_DUMMY = 0,
    MB_COMM_TYPE_PARENT_SENDSTART,
    MB_COMM_TYPE_PARENT_KICKREQ,
    MB_COMM_TYPE_PARENT_DL_FILEINFO,
    MB_COMM_TYPE_PARENT_DATA,
    MB_COMM_TYPE_PARENT_BOOTREQ,
    MB_COMM_TYPE_PARENT_MEMBER_FULL,
    MB_COMM_TYPE_CHILD_FILEREQ,
    MB_COMM_TYPE_CHILD_ACCEPT_FILEINFO,
    MB_COMM_TYPE_CHILD_CONTINUE,
    MB_COMM_TYPE_CHILD_STOPREQ,
    MB_COMM_TYPE_CHILD_BOOTREQ_ACCEPTED
} MBCommType;
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
extern u8 *func_02014a84(const u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id);
extern u8 *func_020149d4(const MBCommChildBlockHeader *hdr, u16 child);
extern BOOL func_02014974(u16 child);
extern struct {
    int size;
    int num;
    int bufSize;
} data_020c6168;
extern MbRequestPieceBuf *data_020c6164;
u8 *func_02014a84(const u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id) {
    u8 *ptr   = (u8 *) recvbuf;
    hdr->type = *ptr++;

    switch (hdr->type) {
        case MB_COMM_TYPE_CHILD_FILEREQ:
            if (func_02014974(child_id)) {
                return (u8 *) data_020c6164->data_buf[child_id - 1];
            }

            hdr->req_data.piece = *ptr++;

            if (hdr->req_data.piece > data_020c6168.num) {
                return 0;
            }

            func_02006ae4(ptr, hdr->req_data.data, (u32) data_020c6168.size);
            ptr = func_020149d4(hdr, child_id);
            break;
        case MB_COMM_TYPE_CHILD_ACCEPT_FILEINFO:
            hdr->data.req = (u16) (0x00ff & (*ptr++));
            hdr->data.req |= (((u16) (*ptr++) << 8) & 0xff00);
            break;
        case MB_COMM_TYPE_CHILD_CONTINUE:
            hdr->data.req = (u16) (0x00ff & (*ptr++));
            hdr->data.req |= (((u16) (*ptr++) << 8) & 0xff00);
            func_02006ae4(ptr, hdr->data.reserved, (u32) data_020c6168.size);
            ptr += data_020c6168.size;
            break;
        default:
            return 0;
    }

    return ptr;
}
extern u8 *func_020149d4(const MBCommChildBlockHeader *hdr, u16 child);
extern BOOL func_02014974(u16 child);
