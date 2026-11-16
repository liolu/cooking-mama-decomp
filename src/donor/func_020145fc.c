/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* StructANN_SomeFn_from_thumb from https://github.com/ai-tdd-labs/mkds-decomp ai/scratch/agent_0200aeec.c (license: none (MIT
 * = tooling only)), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct OSThread {
    u8 padding[0xc0];
} OSThread;
typedef struct StructANN StructANN;
struct StructANN {
    StructANN *next;
    u32 active : 1;
    u32 priority : 31;
    void (*callback2)(StructANN *entry);
    void (*callback)(StructANN *entry);
    u32 value10;
    u32 value14;
    u32 value18;
    u32 value1c;
};
typedef struct GlobalANWork {
    OSThread thread;
    StructANN *volatile head;
    StructANN stopEntry;
} GlobalANWork;
extern int func_020147b8(void);
extern void func_02006440(void);
extern int func_02004910(OSThread *thread);
extern u32 func_02006194(void);
extern void func_02004ae4(OSThread *thread);
extern void func_020061a8(u32 irqState);
extern GlobalANWork *data_020c6160;
void func_020145fc(StructANN *entry, void (*callback2)(StructANN *entry), void (*callback)(StructANN *entry), u32 priority) {
    GlobalANWork *work = data_020c6160;
    u32 irqState;

    if (func_020147b8() == 0) {
        func_02006440();
    }
    if (entry->active != 0) {
        func_02006440();
    }

    if (priority > 31) {
        u32 threadPriority = func_02004910(&work->thread);

        if (priority == 32) {
            if (threadPriority != 0) {
                priority = threadPriority - 1;
            } else {
                priority = 0;
            }
        } else if (priority == 33) {
            if (threadPriority < 31) {
                priority = threadPriority + 1;
            } else {
                priority = 31;
            }
        } else if (priority == 34) {
            priority = threadPriority;
        } else {
            priority = 31;
        }
    }

    irqState         = func_02006194();
    entry->active    = 1;
    entry->priority  = priority;
    entry->callback2 = callback2;
    entry->callback  = callback;

    if (work->head == 0) {
        if (entry == &work->stopEntry) {
            data_020c6160 = 0;
        }
        work->head = entry;
        func_02004ae4(&work->thread);
    } else {
        StructANN *current = work->head;

        if (entry == &work->stopEntry) {
            while (current->next != 0) {
                current = current->next;
            }
            current->next = entry;
            data_020c6160 = 0;
        } else if (current->priority > priority) {
            work->head  = entry;
            entry->next = current;
        } else {
            while (current->next != 0 && current->next->priority <= priority) {
                current = current->next;
            }
            entry->next   = current->next;
            current->next = entry;
        }
    }

    func_020061a8(irqState);
}
