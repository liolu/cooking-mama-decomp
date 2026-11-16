/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02011be0 from projets/code-lyoko/src/donor/func_02011be0.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
typedef volatile u32 vu32;
typedef int BOOL;
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
typedef void (*PXIFifoCallback)(PXIFifoTag tag, u32 data, BOOL err);
extern void func_02008170(int fifotag, PXIFifoCallback callback);
extern BOOL func_02008148(int fifotag, PXIProc proc);
typedef void (*PMCallback)(u32 result, void *arg);
typedef struct {
    u16 flag;
    u16 padding;
    u16 *buffer;
} PMData16;
extern void func_0200bccc(void);
extern void func_0200bbe0(PXIFifoTag tag, u32 data, BOOL err);
extern void func_02007f64(void);
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
static inline vu32 OS_GetVBlankCount(void) {
    return *(vu32 *) (0x02000000 + 0x007ffc3c);
}
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;

    OSMutexLink link;
};
extern void func_020057c8(OSMutex *mutex);
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
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    BOOL lock;
    PMCallback callback;
    void *callbackArg;
    void *work;
} PMiWork;
extern u16 data_020c4c0c;
extern PMiWork data_020c4c24;
extern PMData16 data_020c4c4c[5];
extern OSMutex data_020c4c34;
extern u32 data_020c4c1c;
void func_0200bccc(void) {
    int i;

    if (data_020c4c0c) {
        return;
    }

    data_020c4c0c          = 1;
    data_020c4c24.lock     = 0;
    data_020c4c24.callback = 0;

    func_02007f64();
    while (!func_02008148(PXI_FIFO_TAG_PM, PXI_PROC_ARM7)) {
    }

    func_02008170(PXI_FIFO_TAG_PM, func_0200bbe0);

    for (i = 0; i < 5; i++) {
        data_020c4c4c[i].flag = 0;
    }

    func_020057c8(&data_020c4c34);

    data_020c4c1c = OS_GetVBlankCount();
}
extern void func_0200bbe0(PXIFifoTag tag, u32 data, BOOL err);
