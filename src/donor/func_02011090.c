/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02055364 from projets/zoo-keeper/src/donor/func_02055364.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;
typedef struct MBUserInfo {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;
typedef struct {
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
} MB_BlockInfoTable;
typedef struct MbSegmentInfo {
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target : 1;
} MbSegmentInfo;
typedef struct MbDownloadFileInfoHeader {
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 reserved;
} MbDownloadFileInfoHeader;
typedef struct MB_CommCommonWork {
    u32 sendbuf[256];
    u32 recvbuf[960];
    MBUserInfo user;
    u16 isMbInitialized;
    int block_size_max;
    int start_mp_busy;
    int is_started_ex;
} MB_CommCommonWork;
extern MB_CommCommonWork *data_020c613c;
extern BOOL func_02010df8(u8 segment_no, u32 address, u32 size);
extern BOOL func_02011090(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi);
BOOL func_02011090(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi) {
    u16 *seg_headB = table->seg_head_blockno;
    u32 *seg_src   = table->seg_src_offset;
    u8 i;
    u32 src_ofs = 0;

    if (!mdfi) {
        return 0;
    }

    for (i = 0; i < 3; ++i) {
        MbSegmentInfo *si = ((MbSegmentInfo *) ((char *) (mdfi) + 0xc + (i) * 16));
        seg_src[i]        = src_ofs;
        src_ofs += si->size;
    }

    seg_headB[0] = 0;

    for (i = 0; i < 3; ++i) {
        MbSegmentInfo *si   = ((MbSegmentInfo *) ((char *) (mdfi) + 0xc + (i) * 16));
        u16 next_block_head = (u16) (seg_headB[i] + (u16) ((si->size + (*(u32 *) ((u8 *) data_020c613c + 0x1318)) - 1) /
                                                           (*(u32 *) ((u8 *) data_020c613c + 0x1318))));

        if (!func_02010df8(i, si->load_addr, si->size)) {
            return 0;
        }

        if (i < 3 - 1) {
            seg_headB[i + 1] = next_block_head;
        } else {
            table->block_num = next_block_head;
        }
    }

    return 1;
}
extern int func_02010df8(u8 segment_no, u32 address, u32 size);
