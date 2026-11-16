/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MBi_TaskThread from https://github.com/Project-Holon/aletheia src/game/ov107/mb_task.c (license: none (MIT = tooling only)),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef int BOOL;
typedef struct Task {
    struct Task *next;
    u32 flags;
    void (*task)(struct Task *);
    void (*callback)(struct Task *);
    u32 param[4];
} Task;
typedef struct MBiTaskInfo {
    struct MBiTaskInfo *next;
    unsigned active : 1;
    unsigned priority : 31;
    void (*volatile task)(struct MBiTaskInfo *);
    void (*callback)(struct MBiTaskInfo *);
    u32 param[4];
} MBiTaskInfo;
typedef struct MBiTaskWork {
    char _0[0xC0];
    union {
        Task *volatile list;
        struct MBiTaskInfo *volatile head;
    } tasks;
    union {
        Task end;
        struct MBiTaskInfo info;
    } last;
} MBiTaskWork;
typedef struct _OSThread OSThread;
typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;
typedef u32 OSIntrMode;
typedef u64 OSTick;
typedef struct CPContext {
    u8 opaque[0x1C];
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
typedef struct OSMutex OSMutex;
typedef struct OSiAlarm OSAlarm;
typedef enum OSThreadState {
    OS_THREAD_STATE_WAITING    = 0,
    OS_THREAD_STATE_READY      = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;
typedef struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
} OSThreadLink;
typedef struct _OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
typedef struct _OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
} OSMutexLink;
typedef void (*OSAlarmHandler)(void *arg);
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
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
};
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
    void (*destructor)(void *);
    void *userParameter;
    int systemErrno;
};
extern OSIntrMode func_02006194(void);
extern OSIntrMode func_020061a8(OSIntrMode state);
extern void func_02004d00(void);
extern void func_02004b98(OSThreadQueue *queue);
extern BOOL func_02004918(OSThread *thread, u32 prio);
extern u32 func_02004910(const OSThread *thread);
extern void func_0201485c(void *arg);
void func_0201485c(void *arg) {
    MBiTaskWork *p;
    Task *trg;

    p = (MBiTaskWork *) arg;
    while (1) {
        {
            u32 bak_cpsr;

            bak_cpsr = func_02006194();
            while (p->tasks.list == 0) {
                func_02004918((OSThread *) p, 0);
                func_02004b98(0);
            }
            trg           = p->tasks.list;
            p->tasks.list = p->tasks.list->next;
            func_02004918((OSThread *) p, trg->flags >> 1);
            func_020061a8(bak_cpsr);
        }
        if (trg->task) {
            trg->task(trg);
        }
        {
            u32 bak_cpsr;
            void (*callback)(Task *);

            bak_cpsr = func_02006194();
            callback = trg->callback;
            {
                u32 cur_priority;
                u32 new_priority;

                cur_priority = func_02004910((void *) p);
                if (p->tasks.list == 0) {
                    new_priority = 0;
                } else {
                    new_priority = cur_priority < (p->tasks.list->flags >> 1) ? (p->tasks.list->flags >> 1) : cur_priority;
                }
                if (new_priority != cur_priority) {
                    func_02004918((OSThread *) p, new_priority);
                }
            }
            trg->next = 0;
            trg->flags &= ~1;
            if (callback) {
                callback(trg);
            }
            if (trg == &p->last.end) {
                break;
            }
            func_020061a8(bak_cpsr);
        }
    }
    func_02004d00();
}
