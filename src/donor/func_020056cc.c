/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02009b8c from projets/code-lyoko/src/donor/func_02009b8c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 irq_flag);
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc;
    char unk_40[0x20];
} OSContext;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef void (*OSThreadSwitchCallback)(OSThread *oldThread, OSThread *newThread);
typedef void (*OSThreadDestructor)(void *);
typedef struct OSThreadLinkedList {
    OSThread *prev;
    OSThread *next;
} OSThreadLinkedList;
typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
typedef struct OSMutexLinkedList {
    OSMutex *next;
    OSMutex *prev;
} OSMutexLinkedList;
typedef struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;
typedef struct OSThreadInfo {
    u16 isSchedulerWaiting;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    OSThreadSwitchCallback callback;
} OSThreadInfo;
typedef struct OSThread {
    OSContext context;
    s32 state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLinkedList list;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackOffset;
    OSThreadQueue joinQueue;
    void *unk_A4[3];
    void *unk_B0;
    OSThreadDestructor destructor;
    void *userParam;
    s32 error;
} OSThread;
extern OSThreadInfo data_020c2c14;
extern void func_02004b18(OSThreadQueue *queue);
static inline OSThreadInfo *OS_GetThreadInfo(void) {
    return &data_020c2c14;
}
static inline OSThread *OS_GetCurrentThread(void) {
    return OS_GetThreadInfo()->current;
}
typedef struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLinkedList list;
} OSMutex;
extern void func_020056cc(OSMutex *mutex);
extern void func_0200563c(OSThread *thread, OSMutex *mutex);
void func_020056cc(OSMutex *mutex) {
    u32 prevIRQState = func_02006194();

    OSThread *currentThread = OS_GetCurrentThread();

    if (mutex->thread == currentThread) {
        if (--mutex->count == 0) {
            func_0200563c(currentThread, mutex);
            mutex->thread = 0;
            func_02004b18(&mutex->queue);
        }
    }

    func_020061a8(prevIRQState);
}
extern void func_0200563c(OSThread *thread, OSMutex *mutex);
