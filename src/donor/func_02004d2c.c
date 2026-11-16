/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020092d8 from projets/code-lyoko/src/donor/func_020092d8.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
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
extern void func_02005188(OSContext *context, u32 newpc, u32 newsp);
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
extern void func_02004d2c(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void func_02004d00(void);
static inline void OS_InitThreadQueue(OSThreadQueue *queue) {

    queue->head = queue->tail = ((void *) 0);
}
extern void func_02004850(OSThread *thread, OSThreadDestructor dtor);
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
extern void func_020069d8(u32 data, void *destp, u32 size);
static inline void MI_CpuFill32(void *dest, u32 data, u32 size) {
    ((void) 0);
    ((void) 0);

    func_020069d8(data, dest, size);
}
static inline void MI_CpuClear32(void *dest, u32 size) {
    MI_CpuFill32(dest, 0, size);
}
extern void func_02004fd8(OSThread *thread);
extern int func_02005170(void);
extern void func_02004fd8(OSThread *thread);
void func_02004d2c(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio) {

    OSIntrMode enable;
    int index;

    ((void) 0);
    ((void) 0);
    ((void) 0);
    ((void) 0);

    enable = func_02006194();
#line 401
    index = func_02005170();

    thread->priority = prio;
    thread->id       = (u32) index;
    thread->state    = OS_THREAD_STATE_WAITING;
    thread->profiler = ((void *) 0);

    func_02004fd8(thread);

    thread->stackBottom        = (u32) stack;
    thread->stackTop           = (u32) stack - stackSize;
    thread->stackWarningOffset = 0;

    *(u32 *) (thread->stackBottom - sizeof(u32)) = 0xfddb597dUL;
    *(u32 *) thread->stackTop                    = 0x7bf9dd5bUL;

    OS_InitThreadQueue(&thread->joinQueue);
    func_02005188(&thread->context, (u32) func, (u32) stack - sizeof(u32));

    thread->context.r[0] = (u32) arg;
    thread->context.lr   = (u32) func_02004d00;

    MI_CpuClear32((void *) ((u32) stack - stackSize + sizeof(u32)), stackSize - sizeof(u32) * 2);

    thread->mutex = ((void *) 0);

    thread->mutexQueue.head = ((void *) 0);
    thread->mutexQueue.tail = ((void *) 0);

    func_02004850(thread, ((void *) 0));

    thread->queue     = ((void *) 0);
    thread->link.prev = thread->link.next = ((void *) 0);
    MI_CpuClear32(&thread->specific[0], sizeof(void *) * 3);

    thread->alarmForSleep = ((void *) 0);
    (void) func_020061a8(enable);
}
extern void func_02004d00(void);
extern void func_02004850(OSThread *thread, OSThreadDestructor dtor);
