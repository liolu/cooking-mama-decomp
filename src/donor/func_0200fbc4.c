/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MBi_CommParentSendBlock from https://github.com/Project-Holon/aletheia src/game/ov107/mb_parent.c (license: none (MIT =
 * tooling only)), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef int BOOL;
typedef u32 uptr;
typedef struct MBUserInfo {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;
typedef struct {
    u32 child_address;
    u32 size;
    u32 offset;
    u8 segment_no;
    u8 pad[3];
} MB_BlockInfo;
typedef struct {
    u32 seg_src_offset[3];
    u16 seg_head_blockno[3];
    u16 block_num;
} MB_BlockInfoTable;
typedef struct {
    u32 src;
    u32 len;
    void *ptr;
    u32 state;
} MBiCacheInfo;
typedef struct MBiCacheList {
    u32 lifetime;
    u32 recent;
    MBiCacheInfo *p_list;
    u32 size;
    char arc_name[4];
    u32 arc_name_len;
    void *arc_pointer;
    u8 reserved[20];
    MBiCacheInfo list[4];
} MBiCacheList;
typedef struct MBiTaskInfo {
    struct MBiTaskInfo *next;
    unsigned active : 1;
    unsigned priority : 31;
    void (*volatile task)(struct MBiTaskInfo *);
    void (*callback)(struct MBiTaskInfo *);
    u32 param[4];
} MBiTaskInfo;
typedef struct MBGameInfo {
    u8 pad0[0x14];
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad19[0x4DC - 0x19];
} MBGameInfo;
typedef struct MbDownloadFileInfoHeader {
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 reserved;
} MbDownloadFileInfoHeader;
typedef struct MBiParentFileInfo {
    union {
        MbDownloadFileInfoHeader header;
        u8 dl_fileinfo[0xE4];
    };
    union {
        MBGameInfo game_info;
        struct {
            u8 pad0E4[0x5A4 - 0xE4];
            MB_BlockInfoTable blockinfo_table;
            MBGameInfo *game_info_ptr;
            u32 pad5BC;
        };
    };
    u16 currentb;
    u16 nextb;
    u16 pollbmp;
    u16 gameinfo_child_bmp;
    u16 gameinfo_changed_bmp;
    u8 active;
    u8 update;
    MBiCacheList *cache_list;
    u32 *card_mapping;
} MBiParentFileInfo;
typedef struct MB_CommCommonWork {
    u32 sendbuf[256];
    u32 recvbuf[960];
    MBUserInfo user;
    u16 isMbInitialized;
    int block_size_max;
    int start_mp_busy;
    int is_started_ex;
} MB_CommCommonWork;
typedef struct MBCommParentBlockHeader {
    u8 type;
    u8 pad1;
    u16 fid;
    u16 seqno;
} MBCommParentBlockHeader;
typedef void (*MBCommPStateCallback)(u16 child_aid, u32 status, void *arg);
typedef struct MBCommPWork {
    MB_CommCommonWork common;
    u8 pad1324[0x1340 - sizeof(MB_CommCommonWork)];
    MBUserInfo childUser[15];
    u16 childversion[15];
    u32 childggid[15];
    MBCommPStateCallback parent_callback;
    int p_comm_state[15];
    u8 file_num;
    u8 cur_fileid;
    s8 fileid_of_child[15];
    u8 child_num;
    u16 child_entry_bmp;
    u8 pad1538[0x1754 - 0x1538];
    u16 req2child[15];
    MBUserInfo childUserCopy;
    MBiParentFileInfo fileinfo[16];
    u8 pad74C8[0x7CE0 - 0x74C8];
    MBiTaskInfo cur_task;
} MBCommPWork;
extern MB_CommCommonWork *data_020c613c;
extern void func_0200fe88(MBiTaskInfo *p_task);
extern int func_0200fbc4(void);
extern void func_0200f9b4(u8 file_id);
extern u8 *func_02014bc0(const MBCommParentBlockHeader *hdr, u8 *sendbuf);
extern int func_02011c4c(int body_len, u16 pollbmp, u32 *sendbuf);
extern void func_0200f9b4(u8 file_id);
extern BOOL func_02010fbc(MB_BlockInfo *bi, MB_BlockInfoTable *table, u32 block, MbDownloadFileInfoHeader *mdfi);
extern int func_0201447c(MBiCacheList *pl, u32 src, void *dst, u32 len);
extern int func_0201478c(MBiTaskInfo *pt);
extern void func_020145fc(struct MBiTaskInfo *pt, void (*task)(struct MBiTaskInfo *), void (*callback)(struct MBiTaskInfo *),
                          u32 priority);
extern void func_02006440(void);
extern void func_0200fe88(MBiTaskInfo *p_task);
extern int func_0200fbc4(void);
void func_0200fe88(MBiTaskInfo *p_task);
int func_0200fbc4(void) {
    MBCommParentBlockHeader hd;
    u8 *databuf;
    u8 i;
    MB_BlockInfo bi;

    if (((MBCommPWork *) data_020c613c)->file_num == 0) {
        return 0x15;
    }

    for (i = 0; i < 16; i++) {
        ((MBCommPWork *) data_020c613c)->cur_fileid = (u8) ((((MBCommPWork *) data_020c613c)->cur_fileid + 1) % 16);
        if (((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].active &&
            ((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].pollbmp) {
            break;
        }
    }
    if (i == 16) {
        return 0x15;
    }

    func_0200f9b4(((MBCommPWork *) data_020c613c)->cur_fileid);

    if (!func_02010fbc(&bi,
                       &((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].blockinfo_table,
                       ((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].currentb,
                       &((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].header)) {
        return 0x15;
    }

    hd.type  = 4;
    hd.fid   = ((MBCommPWork *) data_020c613c)->cur_fileid;
    hd.seqno = ((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].currentb;
    databuf  = func_02014bc0(&hd, (u8 *) ((MBCommPWork *) data_020c613c)->common.sendbuf);

    {
        u32 card_addr = (u32) (bi.offset -
                               ((MBCommPWork *) data_020c613c)
                                   ->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid]
                                   .blockinfo_table.seg_src_offset[bi.segment_no] +
                               ((MBCommPWork *) data_020c613c)
                                   ->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid]
                                   .card_mapping[bi.segment_no]);
        MBiCacheList *const pl =
            ((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].cache_list;
        if (!func_0201447c(pl, card_addr, databuf, bi.size)) {
            MBiTaskInfo *const p_task = &((MBCommPWork *) data_020c613c)->cur_task;
            if (!func_0201478c(p_task)) {
                if (pl->lifetime) {
                    --pl->lifetime;
                } else {
                    MBiCacheInfo *pi  = pl->list;
                    MBiCacheInfo *trg = 0;
                    int i;
                    for (i = 0; i < 4; ++i) {
                        if (pi[i].state == 2) {
                            if (!trg || (trg->src > pi[i].src)) {
                                trg = &pi[i];
                            }
                        }
                    }
                    if (!trg) {
                        func_02006440();
                    }
                    pl->lifetime     = 2;
                    trg->state       = 1;
                    trg->src         = (card_addr & ~31);
                    p_task->param[0] = (uptr) trg;
                    p_task->param[1] = (uptr) pl;
                    func_020145fc((struct MBiTaskInfo *) p_task, func_0200fe88, 0, 4);
                }
            }
            return 0x15;
        }
    }
    return func_02011c4c((int) (bi.size + sizeof(MBCommParentBlockHeader)),
                         ((MBCommPWork *) data_020c613c)->fileinfo[((MBCommPWork *) data_020c613c)->cur_fileid].pollbmp,
                         ((MBCommPWork *) data_020c613c)->common.sendbuf);
}
void func_0200f9b4(u8 file_id);
