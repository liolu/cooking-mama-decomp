/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed short int s16;
typedef signed long s32;
typedef int BOOL;
typedef void (*OSAlarmHandler)(void *);
typedef struct OSiVAlarm OSVAlarm;
struct OSiVAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    u32 frame;
    s16 fire;
    s16 delay;
    OSVAlarm *prev;
    OSVAlarm *next;
    BOOL period;
    BOOL finish;
    BOOL canceled;
};
extern void func_02006110(void);
typedef u32 OSIrqMask;
extern OSIrqMask func_020038a0(OSIrqMask mask);
extern struct OSiVAlarmQueue {
    OSVAlarm *head;
    OSVAlarm *tail;
} data_020c2f20;
extern u16 data_020c2f14;
extern s32 data_020c2f1c;
extern s32 data_020c2f18;

/* Os_InitializeVAlarm from https://github.com/RonyxDumb/mkds src/arm9/0200fc1c_Os_InitializeVAlarm.c (license: none), reused
 * by tools/donor_match.py */
void func_02006110(void) {
    if (!data_020c2f14) {
        data_020c2f14 = 1;

        data_020c2f20.head = ((void *) 0);
        data_020c2f20.tail = ((void *) 0);

        (void) func_020038a0((1UL << 2));

        data_020c2f1c = 0;
        data_020c2f18 = 0;
    }
}
