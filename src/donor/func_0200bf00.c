/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02011e3c from projets/code-lyoko/src/donor/func_02011e3c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
typedef int BOOL;
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
typedef struct OSThreadInfo {
    u16 isNeedRescheduling;

    u16 irqDepth;

    OSThread *current;
    OSThread *list;
    void *switchCallback;

} OSThreadInfo;
typedef volatile struct OSLockWord {
    u32 lockFlag;
    u16 ownerID;
    u16 extension;
} OSLockWord;
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
typedef struct {
    u8 bootCheckInfo[0x20];
    u32 resetParameter;
    u8 padding5[0x8];
    u32 romBaseOffset;
    u8 cartridgeModuleInfo[12];
    u32 vblankCount;
    u8 wmBootBuf[0x40];
    u8 nvramUserInfo[0x100];
    u8 isd_reserved1[0x20];
    u8 arenaInfo[0x48];
    u8 real_time_clock[8];
    u32 dmaClearBuf[4];
    u8 rom_header[0x160];
    u8 isd_reserved2[32];
    u32 pxiSignalParam[2];
    u32 pxiHandleChecker[2];
    u32 mic_last_address;
    u16 mic_sampling_data;
    u16 wm_callback_control;
    u16 wm_rssi_pool;
    u8 ctrdg_SetModuleInfoFlag;
    u8 ctrdg_IsExisting;
    u32 component_param;
    OSThreadInfo *threadinfo_mainp;
    OSThreadInfo *threadinfo_subp;
    u16 button_XY;
    u8 touch_panel[4];
    u16 autoloadSync;
    u32 lockIDFlag_mainp[2];
    u32 lockIDFlag_subp[2];
    struct OSLockWord lock_VRAM_C;
    struct OSLockWord lock_VRAM_D;
    struct OSLockWord lock_WRAM_BLOCK0;
    struct OSLockWord lock_WRAM_BLOCK1;
    struct OSLockWord lock_CARD;
    struct OSLockWord lock_CARTRIDGE;
    struct OSLockWord lock_INIT;
    u16 mmem_checker_mainp;
    u16 mmem_checker_subp;
    u8 padding4[2];
    u16 command_area;
} OSSystemWork;
typedef struct RTCRawDate {
    u32 year : 8;
    u32 month : 5;
    u32 dummy0 : 3;
    u32 day : 6;
    u32 dummy1 : 2;
    u32 week : 3;
    u32 dummy2 : 5;
} RTCRawDate;
typedef struct RTCRawTime {
    u32 hour : 6;
    u32 afternoon : 1;
    u32 dummy0 : 1;
    u32 minute : 7;
    u32 dummy1 : 1;
    u32 second : 7;
    u32 dummy2 : 9;
} RTCRawTime;
typedef struct RTCRawStatus1 {
    u16 reset : 1;
    u16 format : 1;
    u16 dummy0 : 2;
    u16 intr1 : 1;
    u16 intr2 : 1;
    u16 bld : 1;
    u16 poc : 1;
    u16 dummy1 : 8;
} RTCRawStatus1;
typedef struct RTCRawStatus2 {
    u16 intr_mode : 4;
    u16 dummy0 : 2;
    u16 intr2_mode : 1;
    u16 test : 1;
    u16 dummy1 : 8;
} RTCRawStatus2;
typedef struct RTCRawAlarm {
    u32 week : 3;
    u32 dummy0 : 4;
    u32 we : 1;
    u32 hour : 6;
    u32 afternoon : 1;
    u32 he : 1;
    u32 minute : 7;
    u32 me : 1;
    u32 dummy2 : 8;
} RTCRawAlarm;
typedef struct RTCRawPulse {
    u32 pulse : 5;
    u32 dummy : 27;
} RTCRawPulse;
typedef struct RTCRawAdjust {
    u32 adjust : 8;
    u32 dummy : 24;
} RTCRawAdjust;
typedef struct RTCRawFree {
    u32 free : 8;
    u32 dummy : 24;
} RTCRawFree;
typedef union RTCRawData {
    struct {
        RTCRawDate date;
        RTCRawTime time;
    } t;
    struct {
        RTCRawStatus1 status1;
        RTCRawStatus2 status2;
        union {
            RTCRawPulse pulse;
            RTCRawAlarm alarm;
            RTCRawAdjust adjust;
            RTCRawFree free;
        };
    } a;
    u32 words[2];
    u16 halfs[4];
    u8 bytes[8];
} RTCRawData;
typedef enum RTCPxiResult {
    RTC_PXI_RESULT_SUCCESS = 0,
    RTC_PXI_RESULT_INVALID_COMMAND,
    RTC_PXI_RESULT_ILLEGAL_STATUS,
    RTC_PXI_RESULT_BUSY,
    RTC_PXI_RESULT_FATAL_ERROR,
    RTC_PXI_RESULT_MAX
} RTCPxiResult;
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
typedef enum RTCWeek {
    RTC_WEEK_SUNDAY = 0,
    RTC_WEEK_MONDAY,
    RTC_WEEK_TUESDAY,
    RTC_WEEK_WEDNESDAY,
    RTC_WEEK_THURSDAY,
    RTC_WEEK_FRIDAY,
    RTC_WEEK_SATURDAY,
    RTC_WEEK_MAX
} RTCWeek;
typedef enum RTCAlarmStatus {
    RTC_ALARM_STATUS_OFF = 0,
    RTC_ALARM_STATUS_ON,
    RTC_ALARM_STATUS_MAX
} RTCAlarmStatus;
typedef enum RTCResult {
    RTC_RESULT_SUCCESS = 0,
    RTC_RESULT_BUSY,
    RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR,
    RTC_RESULT_INVALID_COMMAND,
    RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR,
    RTC_RESULT_MAX
} RTCResult;
typedef void (*RTCCallback)(RTCResult result, void *arg);
typedef void (*RTCInterrupt)(void);
typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    RTCWeek week;
} RTCDate;
typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;
typedef struct RTCAlarmParam {
    RTCWeek week;
    u32 hour;
    u32 minute;
    u32 enable;
} RTCAlarmParam;
extern BOOL func_0200c5fc(void);
extern RTCWeek func_0200c61c(RTCDate *date);
typedef enum RTCLock {
    RTC_LOCK_OFF = 0,
    RTC_LOCK_ON,
    RTC_LOCK_MAX
} RTCLock;
typedef enum RTCSequence {
    RTC_SEQ_GET_DATE = 0,
    RTC_SEQ_GET_TIME,
    RTC_SEQ_GET_DATETIME,
    RTC_SEQ_SET_DATE,
    RTC_SEQ_SET_TIME,
    RTC_SEQ_SET_DATETIME,
    RTC_SEQ_GET_ALARM1_STATUS,
    RTC_SEQ_GET_ALARM2_STATUS,
    RTC_SEQ_GET_ALARM_PARAM,
    RTC_SEQ_SET_ALARM1_STATUS,
    RTC_SEQ_SET_ALARM2_STATUS,
    RTC_SEQ_SET_ALARM1_PARAM,
    RTC_SEQ_SET_ALARM2_PARAM,
    RTC_SEQ_SET_HOUR_FORMAT,
    RTC_SEQ_SET_REG_STATUS2,
    RTC_SEQ_SET_REG_ADJUST,
    RTC_SEQ_MAX
} RTCSequence;
typedef struct RTCWork {
    u32 lock;
    RTCCallback callback;
    void *buffer[2];
    void *callbackArg;
    u32 sequence;
    u32 index;
    RTCInterrupt interrupt;
    RTCResult commonResult;
} RTCWork;
extern RTCWork data_020c4c78;
extern void func_0200bf00(PXIFifoTag tag, u32 data, BOOL err);
extern u32 func_0200be7c(u32 bcd);
void func_0200bf00(PXIFifoTag tag, u32 data, BOOL err) {

#pragma unused(tag)
#line 352
    RTCResult result;
    RTCPxiResult pxiresult;
    u8 command;
    RTCCallback cb;

    if (err) {
        if (data_020c4c78.index) {
            data_020c4c78.index = 0;
        }

        if (data_020c4c78.lock != RTC_LOCK_OFF) {
            data_020c4c78.lock = RTC_LOCK_OFF;
        }

        if (data_020c4c78.callback) {
            cb                     = data_020c4c78.callback;
            data_020c4c78.callback = ((void *) 0);
            cb(RTC_RESULT_FATAL_ERROR, data_020c4c78.callbackArg);
        }

        return;
    }

    command   = (u8) ((data & 0x00007f00) >> 8);
    pxiresult = (RTCPxiResult) ((data & 0x000000ff) >> 0);

    if (command == 0x30) {
        if (data_020c4c78.interrupt) {
            data_020c4c78.interrupt();
        }
        return;
    }

    if (pxiresult == RTC_PXI_RESULT_SUCCESS) {
        result = RTC_RESULT_SUCCESS;
        switch (data_020c4c78.sequence) {

            case RTC_SEQ_GET_DATE: {
                RTCDate *pDst    = (RTCDate *) (data_020c4c78.buffer[0]);
                RTCRawDate *pSrc = &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->t.date);

                pDst->year  = func_0200be7c(pSrc->year);
                pDst->month = func_0200be7c(pSrc->month);
                pDst->day   = func_0200be7c(pSrc->day);
                pDst->week  = func_0200c61c(pDst);
            } break;
            case RTC_SEQ_GET_TIME: {
                RTCTime *pDst    = (RTCTime *) (data_020c4c78.buffer[0]);
                RTCRawTime *pSrc = &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->t.time);

                pDst->hour   = func_0200be7c(pSrc->hour);
                pDst->minute = func_0200be7c(pSrc->minute);
                pDst->second = func_0200be7c(pSrc->second);
            } break;
            case RTC_SEQ_GET_DATETIME: {
                RTCDate *pDst    = (RTCDate *) (data_020c4c78.buffer[0]);
                RTCRawDate *pSrc = &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->t.date);

                pDst->year  = func_0200be7c(*(u32 *) pSrc & 0x000000ff);
                pDst->month = func_0200be7c(pSrc->month);
                pDst->day   = func_0200be7c(pSrc->day);
                pDst->week  = func_0200c61c(pDst);
            }
                {
                    RTCTime *pDst = (RTCTime *) (data_020c4c78.buffer[1]);
                    RTCRawTime *pSrc =
                        &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->t.time);

                    pDst->hour   = func_0200be7c(pSrc->hour);
                    pDst->minute = func_0200be7c(pSrc->minute);
                    pDst->second = func_0200be7c(pSrc->second);
                }
                break;

            case RTC_SEQ_SET_DATE:
            case RTC_SEQ_SET_TIME:
            case RTC_SEQ_SET_DATETIME:
                break;
            case RTC_SEQ_GET_ALARM1_STATUS: {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *) (data_020c4c78.buffer[0]);
                RTCRawStatus2 *pSrc =
                    &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->a.status2);

                switch (pSrc->intr_mode) {
                    case 0x4:
                        *pDst = RTC_ALARM_STATUS_ON;
                        break;
                    default:
                        *pDst = RTC_ALARM_STATUS_OFF;
                }
            } break;

            case RTC_SEQ_GET_ALARM2_STATUS: {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *) (data_020c4c78.buffer[0]);
                RTCRawStatus2 *pSrc =
                    &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->a.status2);

                if (pSrc->intr2_mode) {
                    *pDst = RTC_ALARM_STATUS_ON;
                } else {
                    *pDst = RTC_ALARM_STATUS_OFF;
                }
            } break;

            case RTC_SEQ_GET_ALARM_PARAM: {
                RTCAlarmParam *pDst = (RTCAlarmParam *) (data_020c4c78.buffer[0]);
                RTCRawAlarm *pSrc =
                    &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->a.alarm);

                pDst->week   = (RTCWeek) (pSrc->week);
                pDst->hour   = func_0200be7c(pSrc->hour);
                pDst->minute = func_0200be7c(pSrc->minute);
                pDst->enable = 0x0000;
                if (pSrc->we) {
                    pDst->enable += 0x0001;
                }
                if (pSrc->he) {
                    pDst->enable += 0x0002;
                }
                if (pSrc->me) {
                    pDst->enable += 0x0004;
                }
            } break;
            case RTC_SEQ_SET_ALARM1_STATUS:
                if (data_020c4c78.index == 0) {
                    RTCRawStatus2 *pSrc =
                        &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->a.status2);

                    if (*(RTCAlarmStatus *) (data_020c4c78.buffer[0]) == RTC_ALARM_STATUS_ON) {
                        if (pSrc->intr_mode != 0x4) {
                            data_020c4c78.index++;
                            pSrc->intr_mode = 0x4;
                            if (!func_0200c5fc()) {
                                data_020c4c78.index = 0;
                                result              = RTC_RESULT_SEND_ERROR;
                            }
                        }
                    } else {
                        if (pSrc->intr_mode != 0x0) {
                            data_020c4c78.index++;
                            pSrc->intr_mode = 0x0;
                            if (!func_0200c5fc()) {
                                data_020c4c78.index = 0;
                                result              = RTC_RESULT_SEND_ERROR;
                            }
                        }
                    }
                } else {
                    data_020c4c78.index = 0;
                }
                break;
            case RTC_SEQ_SET_ALARM2_STATUS:
                if (data_020c4c78.index == 0) {
                    RTCRawStatus2 *pSrc =
                        &(((RTCRawData *) (((OSSystemWork *) (0x02000000 + 0x007ffc00))->real_time_clock))->a.status2);

                    if (*(RTCAlarmStatus *) (data_020c4c78.buffer[0]) == RTC_ALARM_STATUS_ON) {
                        if (!pSrc->intr2_mode) {
                            data_020c4c78.index++;
                            pSrc->intr2_mode = 1;
                            if (!func_0200c5fc()) {
                                data_020c4c78.index = 0;
                                result              = RTC_RESULT_SEND_ERROR;
                            }
                        }
                    } else {

                        if (pSrc->intr2_mode) {

                            data_020c4c78.index++;
                            pSrc->intr2_mode = 0;
                            if (!func_0200c5fc()) {
                                data_020c4c78.index = 0;
                                result              = RTC_RESULT_SEND_ERROR;
                            }
                        }
                    }
                } else {
                    data_020c4c78.index = 0;
                }
                break;
            case RTC_SEQ_SET_ALARM1_PARAM:
            case RTC_SEQ_SET_ALARM2_PARAM:
            case RTC_SEQ_SET_HOUR_FORMAT:
            case RTC_SEQ_SET_REG_STATUS2:
            case RTC_SEQ_SET_REG_ADJUST:
                break;
            default:
                result              = RTC_RESULT_INVALID_COMMAND;
                data_020c4c78.index = 0;
        }
    } else {
        data_020c4c78.index = 0;

        switch (pxiresult) {
            case RTC_PXI_RESULT_INVALID_COMMAND:
                result = RTC_RESULT_INVALID_COMMAND;
                break;
            case RTC_PXI_RESULT_ILLEGAL_STATUS:
                result = RTC_RESULT_ILLEGAL_STATUS;
                break;
            case RTC_PXI_RESULT_BUSY:
                result = RTC_RESULT_BUSY;
                break;
            case RTC_PXI_RESULT_FATAL_ERROR:
            default:
                result = RTC_RESULT_FATAL_ERROR;
        }
    }

    if (data_020c4c78.index == 0) {
        if (data_020c4c78.lock != RTC_LOCK_OFF) {
            data_020c4c78.lock = RTC_LOCK_OFF;
        }

        if (data_020c4c78.callback) {
            cb                     = data_020c4c78.callback;
            data_020c4c78.callback = ((void *) 0);
            cb(result, data_020c4c78.callbackArg);
        }
    }
}
extern u32 func_0200be7c(u32 bcd);
