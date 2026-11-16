/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02014440 from projets/code-lyoko/src/donor/func_02014440.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef signed long s32;
typedef int BOOL;
typedef u64 OSTick;
typedef struct CPContext {
    u64 div_numer;
    u64 div_denom;
    u64 sqrt;
    u16 div_mode;
    u16 sqrt_mode;
} CPContext;
typedef void *OSMessage;
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
typedef struct OSContext OSContext;
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
struct OSThread {
    u8 context[0x64];
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLink link;
    void *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
    void *specific[3];
    void *alarmForSleep;
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};
typedef struct OSMessageQueue OSMessageQueue;
struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
};
enum {
    WM_ERRCODE_SUCCESS            = 0,
    WM_ERRCODE_FAILED             = 1,
    WM_ERRCODE_OPERATING          = 2,
    WM_ERRCODE_ILLEGAL_STATE      = 3,
    WM_ERRCODE_WM_DISABLE         = 4,
    WM_ERRCODE_NO_KEYSET          = 5,
    WM_ERRCODE_INVALID_PARAM      = 6,
    WM_ERRCODE_NO_CHILD           = 7,
    WM_ERRCODE_FIFO_ERROR         = 8,
    WM_ERRCODE_TIMEOUT            = 9,
    WM_ERRCODE_SEND_QUEUE_FULL    = 10,
    WM_ERRCODE_NO_ENTRY           = 11,
    WM_ERRCODE_OVER_MAX_ENTRY     = 12,
    WM_ERRCODE_INVALID_POLLBITMAP = 13,
    WM_ERRCODE_NO_DATA            = 14,
    WM_ERRCODE_SEND_FAILED        = 15
};
typedef int WMErrCode;
typedef int WMApiid;
typedef char *va_list;
extern BOOL func_02005564(OSMessageQueue *queue, OSMessage msg, s32 flags);
extern void func_02005834(void *addr, u32 size);
extern s32 func_02008094(int tag, u32 data, BOOL err);
extern u32 *func_0200e2ac(void);
extern OSMessageQueue data_020c5570;
WMErrCode func_0200e1f4(WMApiid id, u16 paramNum, ...) {
    va_list vlist;
    s32 i;
    int result;
    u32 *tmpAddr;

    tmpAddr = func_0200e2ac();
    if (tmpAddr == ((void *) 0)) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    *(u16 *) tmpAddr = (u16) id;

    ((vlist) = (char *) (((int) &(paramNum) & ~3) + 4));
    for (i = 0; i < paramNum; i++) {
        tmpAddr[i + 1] = (*(u32 *) (((vlist) += 4) - 4));
    }
    ((void) 0);

    func_02005834(tmpAddr, 256);

    result = func_02008094(10, (u32) tmpAddr, 0);

    (void) func_02005564(&data_020c5570, tmpAddr, 1);

    if (result < 0) {
        return WM_ERRCODE_FIFO_ERROR;
    }

    return WM_ERRCODE_OPERATING;
}
