/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201a964 from projets/code-lyoko/src/donor/func_0201a964.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed long s32;
typedef int BOOL;
typedef u32 OSIntrMode;
extern OSIntrMode func_02006194(void);
extern OSIntrMode func_020061a8(OSIntrMode state);
typedef struct CPContext {
    u64 div_numer;
    u64 div_denom;
    u64 sqrt;
    u16 div_mode;
    u16 sqrt_mode;
} CPContext;
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;

    u32 sp_svc;

    CPContext cp_context;

} OSContext;
typedef struct _OSThread OSThread;
typedef struct _OSThreadQueue OSThreadQueue;
typedef struct _OSThreadLink OSThreadLink;
typedef struct _OSMutexQueue OSMutexQueue;
typedef struct _OSMutexLink OSMutexLink;
typedef struct OSMutex OSMutex;
typedef struct OSiAlarm OSAlarm;
struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
};
struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
};
struct _OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
};
struct _OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
};
typedef enum {
    OS_THREAD_STATE_WAITING    = 0,
    OS_THREAD_STATE_READY      = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;
typedef void (*OSThreadDestructor)(void *);
struct _OSThread {
    OSContext context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;

    OSThreadQueue *queue;
    OSThreadLink link;

    OSMutex *mutex;
    OSMutexQueue mutexQueue;

    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;

    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    OSThreadDestructor destructor;
    void *userParameter;
    int systemErrno;
};
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;

    OSMutexLink link;
};
typedef u64 OSTick;
typedef void (*OSAlarmHandler)(void *);
struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};
extern void func_020069a4(u16 data, void *destp, u32 size);
static inline void MI_CpuFill16(void *dest, u16 data, u32 size) {
    ((void) 0);
    ((void) 0);

    func_020069a4(data, dest, size);
}
static inline void MI_CpuClear16(void *dest, u32 size) {
    MI_CpuFill16(dest, 0, size);
}
extern void func_02006a50(void *dest, u8 data, u32 size);
static inline void MI_CpuClear8(void *dest, u32 size) {
    func_02006a50(dest, 0, size);
}
typedef struct WMMpRecvBuf {
    u16 rsv1[3];
    u16 length;
    u16 rsv2[1];
    u16 ackTimeStamp;
    u16 timeStamp;
    u16 rate_rssi;
    u16 rsv3[2];
    u16 rsv4[2];
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 rsv5[3];
    u16 seqCtrl;
    u16 txop;
    u16 bitmap;
    u16 wmHeader;
    u16 data[2];
} WMMpRecvBuf, WMmpRecvBuf;
typedef struct WMMpRecvData {
    u16 length;
    u16 rate_rssi;
    u16 aid;
    u16 noResponse;
    u16 wmHeader;
    u16 cdata[1];
} WMMpRecvData, WMmpRecvData;
typedef struct WMMpRecvHeader {
    u16 bitmap;

    u16 errBitmap;

    u16 count;
    u16 length;
    u16 txCount;
    WMMpRecvData data[1];
} WMMpRecvHeader, WMmpRecvHeader;
typedef struct WMParentParam {
    u16 *userGameInfo;
    u16 userGameInfoLength;
    u16 padding;
    u32 ggid;
    u16 tgid;
    u16 entryFlag;
    u16 maxEntry;
    u16 multiBootFlag;
    u16 KS_Flag;
    u16 CS_Flag;
    u16 beaconPeriod;
    u16 rsv1[8 / sizeof(u16)];
    u16 rsv2[16 / sizeof(u16)];
    u16 channel;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 rsv[4];
} WMParentParam, WMpparam;
typedef struct WMGameInfo {
    u16 magicNumber;
    u8 ver;
    u8 platform;
    u32 ggid;
    u16 tgid;
    u8 userGameInfoLength;
    union {
        u8 gameNameCount_attribute;
        u8 attribute;
    };
    u16 parentMaxSize;
    u16 childMaxSize;
    union {
        u16 userGameInfo[112 / sizeof(u16)];
        struct {
            u16 userName[8 / sizeof(u16)];
            u16 gameName[16 / sizeof(u16)];
            u16 padd1[44];
        } old_type;
    };
} WMGameInfo, WMgameInfo;
typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    struct {
        u16 basic;
        u16 support;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc, WMbssDesc;
typedef struct WMStartScanCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 channel;
    u16 linkLevel;
    u16 ssidLength;
    u16 ssid[32 / sizeof(u16)];
    u16 gameInfoLength;
    WMGameInfo gameInfo;
} WMStartScanCallback, WMstartScanCallback;
enum {
    FS_ARCHIVE_NAME_LEN_MAX = 3
};
typedef enum {
    FS_COMMAND_ASYNC_BEGIN = 0,
    FS_COMMAND_READFILE    = FS_COMMAND_ASYNC_BEGIN,
    FS_COMMAND_WRITEFILE,
    FS_COMMAND_ASYNC_END,
    FS_COMMAND_SYNC_BEGIN = FS_COMMAND_ASYNC_END,
    FS_COMMAND_SEEKDIR    = FS_COMMAND_SYNC_BEGIN,
    FS_COMMAND_READDIR,
    FS_COMMAND_FINDPATH,
    FS_COMMAND_GETPATH,
    FS_COMMAND_OPENFILEFAST,
    FS_COMMAND_OPENFILEDIRECT,
    FS_COMMAND_CLOSEFILE,
    FS_COMMAND_SYNC_END,
    FS_COMMAND_STATUS_BEGIN = FS_COMMAND_SYNC_END,
    FS_COMMAND_ACTIVATE     = FS_COMMAND_STATUS_BEGIN,
    FS_COMMAND_IDLE,
    FS_COMMAND_SUSPEND,
    FS_COMMAND_RESUME,
    FS_COMMAND_STATUS_END,
    FS_COMMAND_INVALID
} FSCommandType;
typedef enum {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_CANCELLED = FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_PROC_ASYNC,
    FS_RESULT_PROC_DEFAULT,
    FS_RESULT_PROC_UNKNOWN
} FSResult;
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(struct FSFile *, FSCommandType);
typedef FSResult (*FS_ARCHIVE_READ_FUNC)(struct FSArchive *p, void *dst, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive *p, const void *src, u32 pos, u32 size);
typedef struct FSFileLink {
    struct FSFile *prev;
    struct FSFile *next;
} FSFileLink;
typedef struct FSArchive {
    union {
        char ptr[FS_ARCHIVE_NAME_LEN_MAX + 1];
        u32 pack;
    } name;
    struct FSArchive *next;
    struct FSArchive *prev;
    OSThreadQueue sync_q;
    OSThreadQueue stat_q;
    u32 flag;
    FSFileLink list;
    u32 base;
    u32 fat;
    u32 fat_size;
    u32 fnt;
    u32 fnt_size;
    u32 fat_bak;
    u32 fnt_bak;
    void *load_mem;
    FS_ARCHIVE_READ_FUNC read_func;
    FS_ARCHIVE_WRITE_FUNC write_func;
    FS_ARCHIVE_READ_FUNC table_func;
    FS_ARCHIVE_PROC_FUNC proc;
    u32 proc_flag;
} FSArchive;
typedef struct {
    struct FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;
typedef struct {
    struct FSArchive *arc;
    u32 file_id;
} FSFileID;
typedef struct {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[127 + 1];
} FSDirEntry;
typedef struct {
    FSDirPos pos;
} FSSeekDirInfo;
typedef struct {
    FSDirEntry *p_entry;
    BOOL skip_string;
} FSReadDirInfo;
typedef struct {
    FSDirPos pos;
    const char *path;
    BOOL find_directory;
    union {
        FSFileID *file;
        FSDirPos *dir;
    } result;
} FSFindPathInfo;
typedef struct {
    u8 *buf;
    u32 buf_len;
    u16 total_len;
    u16 dir_id;
} FSGetPathInfo;
typedef struct {
    FSFileID id;
} FSOpenFileFastInfo;
typedef struct {
    u32 top;
    u32 bottom;
    u32 index;
} FSOpenFileDirectInfo;
typedef struct {
    u32 reserved;
} FSCloseFileInfo;
typedef struct {
    void *dst;
    u32 len_org;
    u32 len;
} FSReadFileInfo;
typedef struct {
    const void *src;
    u32 len_org;
    u32 len;
} FSWriteFileInfo;
typedef struct FSFile {
    FSFileLink link;
    struct FSArchive *arc;
    u32 stat;
    FSCommandType command;
    FSResult error;

    OSThreadQueue queue[1];

    union {
        struct {
            u32 own_id;
            u32 top;
            u32 bottom;
            u32 pos;
        } file;

        struct {
            FSDirPos pos;
            u32 parent;
        } dir;
    } prop;
    union {
        FSReadFileInfo readfile;
        FSWriteFileInfo writefile;
        FSSeekDirInfo seekdir;
        FSReadDirInfo readdir;
        FSFindPathInfo findpath;
        FSGetPathInfo getpath;
        FSOpenFileFastInfo openfilefast;
        FSOpenFileDirectInfo openfiledirect;
        FSCloseFileInfo closefile;
    } arg;

} FSFile;
typedef enum {
    MB_COMM_PSTATE_NONE,
    MB_COMM_PSTATE_INIT_COMPLETE,
    MB_COMM_PSTATE_CONNECTED,
    MB_COMM_PSTATE_DISCONNECTED,
    MB_COMM_PSTATE_KICKED,
    MB_COMM_PSTATE_REQ_ACCEPTED,
    MB_COMM_PSTATE_SEND_PROCEED,
    MB_COMM_PSTATE_SEND_COMPLETE,
    MB_COMM_PSTATE_BOOT_REQUEST,
    MB_COMM_PSTATE_BOOT_STARTABLE,
    MB_COMM_PSTATE_REQUESTED,
    MB_COMM_PSTATE_MEMBER_FULL,
    MB_COMM_PSTATE_END,
    MB_COMM_PSTATE_ERROR,
    MB_COMM_PSTATE_WAIT_TO_SEND,
    MB_COMM_PSTATE_WM_EVENT = 0x80000000
} MBCommPState;
typedef void (*MBCommPStateCallback)(u16 child_aid, u32 status, void *arg);
typedef struct {
    const char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    const char *iconCharPathp;
    const char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[0x20];
} MBGameRegistry;
typedef struct {
    u16 palette[16];
    u16 data[512 / 2];
} MBIconInfo;
typedef struct {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;
extern void func_02010dcc(MBCommPStateCallback callback);
typedef struct MBGameInfoFixed {
    MBIconInfo icon;
    MBUserInfo parent;
    u8 maxPlayerNum;
    u8 pad[1];
    u16 gameName[48];
    u16 gameIntroduction[96];
} MBGameInfoFixed, MbGameInfoFixed;
typedef struct MBGameInfoVolatile {
    u8 nowPlayerNum;
    u8 pad[1];
    u16 nowPlayerFlag;
    u16 changePlayerFlag;
    MBUserInfo member[15];
    u8 userVolatData[8];
} MBGameInfoVolatile, MbGameInfoVolatile;
typedef struct MBGameInfo {
    MBGameInfoFixed fixed;
    MBGameInfoVolatile volat;
    u16 broadcastedPlayerFlag;
    u8 dataAttr;
    u8 seqNoFixed;
    u8 seqNoVolat;
    u8 fileNo;
    u8 pad[2];
    u32 ggid;
    struct MBGameInfo *nextp;
} MBGameInfo, MbGameInfo;
typedef enum {
    PXI_PROC_ARM9 = 0,
    PXI_PROC_ARM7 = 1
} PXIProc;
typedef enum {
    PXI_FIFO_TAG_EX = 0,
    PXI_FIFO_TAG_USER_0,
    PXI_FIFO_TAG_USER_1,
    PXI_FIFO_TAG_SYSTEM,
    PXI_FIFO_TAG_NVRAM,
    PXI_FIFO_TAG_RTC,
    PXI_FIFO_TAG_TOUCHPANEL,
    PXI_FIFO_TAG_SOUND,
    PXI_FIFO_TAG_PM,
    PXI_FIFO_TAG_MIC,
    PXI_FIFO_TAG_WM,
    PXI_FIFO_TAG_FS,
    PXI_FIFO_TAG_OS,
    PXI_FIFO_TAG_CTRDG,
    PXI_FIFO_TAG_CARD,
    PXI_FIFO_TAG_WVR,
    PXI_FIFO_TAG_CTRDG_Ex,
    PXI_FIFO_TAG_CTRDG_PHI,
    PXI_MAX_FIFO_TAG = 32
} PXIFifoTag;
extern BOOL func_02008148(int fifotag, PXIProc proc);
extern const u16(*ctrdgi_fl_maxtime);
typedef struct ParentInfo {
    union {
        WMBssDesc parentInfo[1];
        u8 parentInfo_area[192] __attribute__((aligned(32)));
    };
    WMStartScanCallback scan_data;
    u8 reserved1[8];
} ParentInfo;
typedef void (*MBCallbackFunc)(u16 type, void *arg);
typedef struct {
    union {
        WMParentParam parentParam;
        u8 parentParam_area[64] __attribute__((aligned(32)));
    };
    u16 sendBuf[(0x400) / sizeof(u16)] __attribute__((aligned(32)));
    union {
        WMBssDesc parentInfoBuf;
        u8 parentInfoBuf_area[192] __attribute__((aligned(32)));
    };
    u16 p_sendlen;
    u16 p_recvlen;
    WMMpRecvBuf *recvBuf;
    void (*callback_ptr)(void *arg);
    u8 mpBusy;
    u8 mbIsStarted;
    u8 reserved0[10];
    u16 sendBufSize;
    u16 recvBufSize;
    MBCallbackFunc callback;
    const WMBssDesc *pInfo;
    u16 mode;
    u16 endReq;
    u16 mpStarted;
    u16 child_bitmap;
    u16 contSend;
    u8 reserved1[2];
    u8 uname[8] __attribute__((aligned(4)));
    u8 gname[16] __attribute__((aligned(4)));
    u16 currentTgid;
    u8 reserved2[22];
    u16 userGameInfo[((112 + 32) & ~(32 - 1)) / sizeof(u16)] __attribute__((aligned(32)));
    struct {
        u16 found_parent_count;
        u16 my_aid;
        BOOL scanning_flag;
        BOOL scan_channel_flag;
        int last_found_parent_no;
        u8 reserved8[16];
        ParentInfo parent_info[16];
    };
} MBiParam;
extern void func_020106e0(u16 type, void *arg);
typedef struct {
    u32 data_buf[15][((29) + 1) / sizeof(u32) + 1];
    u32 data_bmp[15];
} MbRequestPieceBuf;
extern void func_02014cb4(u16 childMaxSize);
extern void func_02014c94(MbRequestPieceBuf *buf);
extern void func_02012298(void);
typedef struct MbDownloadFileInfoHeader {
    u32 arm9EntryAddr;
    u32 arm7EntryAddr;
    u32 padding;
} MbDownloadFileInfoHeader;
typedef struct MbSegmentInfo {
    u32 recv_addr;
    u32 load_addr;
    u32 size;
    u32 target : 1;
    u32 rsv : 31;
} MbSegmentInfo;
typedef struct {
    MbDownloadFileInfoHeader header;
    MbSegmentInfo seg[(3)];
    u32 auth_code[(136) / sizeof(u32)];
    u32 reserved[32 / sizeof(u32)];
} MBDownloadFileInfo;
typedef struct {
    u32 seg_src_offset[(3)];
    u16 seg_head_blockno[(3)];
    u16 block_num;
} MB_BlockInfoTable;
typedef struct {
    u32 src;
    u32 len;
    u8 *ptr;
    u32 state;
} MBiCacheInfo;
typedef struct {
    u32 lifetime;
    u32 recent;
    MBiCacheInfo *p_list;
    u32 size;
    char arc_name[FS_ARCHIVE_NAME_LEN_MAX + 1];
    u32 arc_name_len;
    FSArchive *arc_pointer;
    u8 reserved[32 - FS_ARCHIVE_NAME_LEN_MAX - 1 - sizeof(u32) - sizeof(FSArchive *)];
    MBiCacheInfo list[4];
} MBiCacheList;
typedef void (*MB_TASK_FUNC)(struct MBiTaskInfo_tag *);
typedef struct MBiTaskInfo_tag {
    struct MBiTaskInfo_tag *next;
    u32 busy : 1;
    u32 priority : 31;
    MB_TASK_FUNC task;
    MB_TASK_FUNC callback;
    u32 param[4];
} MBiTaskInfo;
typedef struct MB_CommCommonWork {
    u32 sendbuf[(0x400) / sizeof(u32)] __attribute__((aligned(32)));
    u32 recvbuf[(0x80) * 15 * 2 / sizeof(u32)] __attribute__((aligned(32)));
    MBUserInfo user;
    u16 isMbInitialized;
    int block_size_max;
    BOOL start_mp_busy;
    BOOL is_started_ex;
    u8 padding[28];
} MB_CommCommonWork;
typedef struct MB_CommPWork {
    MB_CommCommonWork common;
    MBUserInfo childUser[15] __attribute__((aligned(4)));
    u16 childversion[15];
    u32 childggid[15];
    MBCommPStateCallback parent_callback;
    int p_comm_state[15];
    u8 file_num;
    u8 cur_fileid;
    s8 fileid_of_child[15];
    u8 child_num;
    u16 child_entry_bmp;
    MbRequestPieceBuf req_data_buf;
    u16 req2child[15];
    MBUserInfo childUserBuf;
    struct {
        MBDownloadFileInfo dl_fileinfo;
        MBGameInfo game_info;
        MB_BlockInfoTable blockinfo_table;
        MBGameRegistry *game_reg;
        void *src_adr;
        u16 currentb;
        u16 nextb;
        u16 pollbmp;
        u16 gameinfo_child_bmp;
        u16 gameinfo_changed_bmp;
        u8 active;
        u8 update;
        MBiCacheList *cache_list;
        u32 *card_mapping;
    } fileinfo[(16)];
    BOOL useWvrFlag;
    u8 padding2[20];
    u8 task_work[2 * 1024];
    MBiTaskInfo cur_task;
} MB_CommPWork;
extern MB_CommCommonWork *data_020c613c;
extern void func_02013aac(void *arg);
extern MBiParam *data_020c6138;
extern u8 *data_020c6134;
extern MB_CommCommonWork *data_020c613c;
extern void func_02013aac(void *arg);
extern int func_02012cc4(void);
int func_02012ab0(int channel) {
    int i, ret;
    MBCommPStateCallback cb_tmp;
    OSIntrMode enabled;

    enabled                            = func_02006194();
    data_020c6138->parentParam.channel = (u16) channel;
    data_020c6134                      = (u8 *) ((((u32) data_020c613c) + sizeof(MB_CommPWork) + 31) & ~31);
    cb_tmp                             = ((MB_CommPWork *) data_020c613c)->parent_callback;

    MI_CpuClear16((void *) ((u32) ((MB_CommPWork *) data_020c613c) + sizeof(MB_CommCommonWork)),
                  sizeof(MB_CommPWork) - sizeof(MB_CommCommonWork));
    func_02010dcc(cb_tmp);

    data_020c613c->block_size_max = ((data_020c6138->p_sendlen) - (6));

    func_02014cb4(data_020c6138->p_recvlen);
    func_02014c94(&((MB_CommPWork *) data_020c613c)->req_data_buf);

    for (i = 0; i < 15; i++) {
        ((MB_CommPWork *) data_020c613c)->p_comm_state[i]    = MB_COMM_PSTATE_NONE;
        ((MB_CommPWork *) data_020c613c)->fileid_of_child[i] = -1;
    }

    ((MB_CommPWork *) data_020c613c)->file_num = 0;

    MI_CpuClear16(&((MB_CommPWork *) data_020c613c)->fileinfo[0], sizeof(((MB_CommPWork *) data_020c613c)->fileinfo));
    MI_CpuClear8(&((MB_CommPWork *) data_020c613c)->req2child[0], sizeof(((MB_CommPWork *) data_020c613c)->req2child));

    data_020c6138->mode         = 1;
    data_020c6138->callback     = func_020106e0;
    data_020c6138->callback_ptr = func_02013aac;

    data_020c6138->parentParam.parentMaxSize = data_020c6138->p_sendlen;
    data_020c6138->sendBufSize               = (u16) ((
        ((((MBiParam *) (data_020c6138))->parentParam.parentMaxSize) + 4 + ((0) ? (2 * 16 + 4) + (2 + 4) : 0) + 31) & ~0x1f));

    data_020c6138->parentParam.childMaxSize = data_020c6138->p_recvlen;
    data_020c6138->recvBufSize =
        (u16) ((((sizeof(WMMpRecvHeader) - sizeof(WMMpRecvData) +
                  ((sizeof(WMMpRecvData) + (((MBiParam *) (data_020c6138))->parentParam.childMaxSize) + 2 - 2 + 2 +
                    ((0) ? 2 + (2 + 2) : 0)) *
                   (15)) +
                  31) &
                 ~0x1f) *
                2));

    ((void) 0);
    ((void) 0);
    ((void) 0);
    ((void) 0);

    func_02012298();
    ret = func_02012cc4();

    (void) func_020061a8(enabled);
    ((MB_CommPWork *) data_020c613c)->useWvrFlag = func_02008148(PXI_FIFO_TAG_WVR, PXI_PROC_ARM7);

    return ret;
}
