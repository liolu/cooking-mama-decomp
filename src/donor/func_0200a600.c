/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020109dc from projets/code-lyoko/src/donor/func_020109dc.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
typedef volatile u16 vu16;
typedef int BOOL;
typedef u32 OSIntrMode;
extern OSIntrMode func_02006194(void);
extern OSIntrMode func_020061a8(OSIntrMode state);
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
extern int func_02008094(int fifotag, u32 data, BOOL err);
typedef enum {
    TP_REQUEST_COMMAND_SAMPLING      = 0x0,
    TP_REQUEST_COMMAND_AUTO_ON       = 0x1,
    TP_REQUEST_COMMAND_AUTO_OFF      = 0x2,
    TP_REQUEST_COMMAND_SET_STABILITY = 0x3,
    TP_REQUEST_COMMAND_AUTO_SAMPLING = 0x10
} TPRequestCommand;
typedef enum {
    TP_REQUEST_COMMAND_FLAG_SAMPLING      = 1 << TP_REQUEST_COMMAND_SAMPLING,
    TP_REQUEST_COMMAND_FLAG_AUTO_ON       = 1 << TP_REQUEST_COMMAND_AUTO_ON,
    TP_REQUEST_COMMAND_FLAG_AUTO_OFF      = 1 << TP_REQUEST_COMMAND_AUTO_OFF,
    TP_REQUEST_COMMAND_FLAG_SET_STABILITY = 1 << TP_REQUEST_COMMAND_SET_STABILITY
} TPRequestCommandFlag;
typedef enum {
    TP_RESULT_SUCCESS = 0,
    TP_RESULT_INVALID_PARAMETER,
    TP_RESULT_ILLEGAL_STATUS,
    TP_RESULT_EXCLUSIVE,
    TP_RESULT_PXI_BUSY
} TPRequestResult;
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;
typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);
extern void func_0200a600(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize);
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    s32 x0;
    s32 xDotSize;
    s32 xDotSizeInv;
    s32 y0;
    s32 yDotSize;
    s32 yDotSizeInv;
} TPiCalibrateParam;
extern struct {
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    u16 frequence;
    TPData *samplingBufs;
    u16 bufSize;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    vu16 state;
    vu16 err_flg;
    vu16 command_flg;
} data_020c4bb4;
static inline BOOL TPi_AutoSamplingOn(u16 vCount, u8 frequency) {
    if (0 > func_02008094(PXI_FIFO_TAG_TOUCHPANEL, 0x02000000 | (0 << 16) | (0x0001 << 8) | (u32) frequency, 0)) {
        return 0;
    }

    if (0 > func_02008094(PXI_FIFO_TAG_TOUCHPANEL, 0x01000000 | (1 << 16) | (u32) vCount, 0)) {
        return 0;
    }

    return 1;
}
static inline void TPi_ErrorAtPxi(TPRequestCommand command) {
    data_020c4bb4.err_flg |= (1 << command);

    if (data_020c4bb4.callback) {
        (data_020c4bb4.callback)(command, TP_RESULT_PXI_BUSY, 0);
    }
}
void func_0200a600(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize) {
    u32 i;
    OSIntrMode enabled;

    ((void) 0);
    ((void) 0);
    ((void) 0);
    ((void) 0);
    ((void) 0);
    ((void) 0);

    data_020c4bb4.samplingBufs = samplingBufs;
    data_020c4bb4.index        = 0;
    data_020c4bb4.frequence    = frequence;
    data_020c4bb4.bufSize      = bufSize;

    for (i = 0; i < bufSize; i++) {
        data_020c4bb4.samplingBufs[i].touch = 0;
    }

    enabled = func_02006194();

    if ((u8) TPi_AutoSamplingOn(vcount, (u8) frequence) == 0) {
        (void) func_020061a8(enabled);
        TPi_ErrorAtPxi(TP_REQUEST_COMMAND_AUTO_ON);
        return;
    }

    data_020c4bb4.command_flg |= TP_REQUEST_COMMAND_FLAG_AUTO_ON;
    data_020c4bb4.err_flg &= ~TP_REQUEST_COMMAND_FLAG_AUTO_ON;

    (void) func_020061a8(enabled);
}
