/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* CARDi_InitCommon from https://github.com/RushRE/SonicRushAdventure-Decomp lib/NitroSDK/src/card/card_common.c (license:
 * none), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long s32;
typedef unsigned long long int u64;
typedef signed long long int s64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef volatile f32 vf32;
typedef u8 REGType8;
typedef u16 REGType16;
typedef u32 REGType32;
typedef u64 REGType64;
typedef vu8 REGType8v;
typedef vu16 REGType16v;
typedef vu32 REGType32v;
typedef vu64 REGType64v;
typedef int BOOL;
extern void NitroMain(void);
extern void NitroStartUp(void);
extern void OSi_ReferSymbol(void *symbol);
typedef enum {
    OS_PROCMODE_USER  = 16,
    OS_PROCMODE_FIQ   = 17,
    OS_PROCMODE_IRQ   = 18,
    OS_PROCMODE_SVC   = 19,
    OS_PROCMODE_ABORT = 23,
    OS_PROCMODE_UNDEF = 27,
    OS_PROCMODE_SYS   = 31
} OSProcMode;
typedef enum {
    OS_INTRMODE_DISABLE_IRQ = 0x80,
    OS_INTRMODE_DISABLE_FIQ = 0x40,
    OS_INTRMODE_ENABLE      = 0
} OSIntrMode;
typedef enum {
    OS_INTRMODE_IRQ_DISABLE = 0x80,
    OS_INTRMODE_IRQ_ENABLE  = 0
} OSIntrMode_Irq;
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern void SDK_SECTION_ARENA_EX_START(void);
extern void OS_EnableITCM(void);
extern void OS_DisableITCM(void);
extern void OS_SetITCMParam(u32 param);
extern u32 OS_GetITCMParam(void);
extern void OS_EnableDTCM(void);
extern void OS_DisableDTCM(void);
extern void OS_SetDTCMParam(u32 param);
extern u32 OS_GetDTCMParam(void);
extern void OS_SetDTCMAddress(u32 address);
extern u32 OS_GetDTCMAddress(void);
static inline u32 OS_GetITCMAddress(void) {
    return (u32) 0x01FF8000;
}
extern void OS_Halt(void);
extern OSIntrMode OS_EnableInterrupts(void);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
extern OSIntrMode_Irq OS_GetCpsrIrq(void);
extern OSProcMode OS_GetProcMode(void);
extern void OS_SpinWait(u32 cycles);
extern void OS_WaitVBlankIntr(void);
typedef struct CPContext {
    u64 div_numer;
    u64 div_denom;
    u64 sqrt;
    u16 div_mode;
    u16 sqrt_mode;
} CPContext;
extern void CP_SaveContext(CPContext *context);
extern void CPi_RestoreContext(const CPContext *context);
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;

    u32 sp_svc;

    CPContext cp_context;

} OSContext;
extern void OS_InitContext(OSContext *context, u32 newpc, u32 newsp);
extern BOOL OS_SaveContext(OSContext *context);
extern void OS_LoadContext(OSContext *context);
typedef struct OSiAlarm OSAlarm;
typedef struct _OSThread OSThread;
typedef struct _OSThreadQueue OSThreadQueue;
typedef struct _OSThreadLink OSThreadLink;
typedef struct _OSMutexQueue OSMutexQueue;
typedef struct _OSMutexLink OSMutexLink;
typedef struct OSMutex OSMutex;
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
typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;
typedef enum {
    OS_THREAD_STATE_WAITING    = 0,
    OS_THREAD_STATE_READY      = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;
typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);
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

    u32 systemErrno;
};
extern OSThreadInfo OSi_ThreadInfo;
static inline OSThreadInfo *OS_GetThreadInfo(void) {
    return &OSi_ThreadInfo;
}
static inline BOOL OS_IsThreadRunnable(const OSThread *thread) {
    return thread->state == OS_THREAD_STATE_READY;
}
static inline void OS_InitThreadQueue(OSThreadQueue *queue) {
    queue->head = queue->tail = ((void *) 0);
}
static inline OSThread *OS_GetCurrentThread(void) {
    return OS_GetThreadInfo()->current;
}
static inline void OS_SetCurrentThread(OSThread *thread) {
    OS_GetThreadInfo()->current = thread;
}
typedef volatile struct OSLockWord {
    u32 lockFlag;
    u16 ownerID;
    u16 extension;
} OSLockWord;
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
    u8 padding3[2];
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
extern OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
extern void OS_InitThread(void);
extern BOOL OS_IsThreadAvailable(void);
extern void func_02004d2c(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_ExitThread(void);
extern void OS_DestroyThread(OSThread *thread);
extern void OS_JoinThread(OSThread *thread);
extern BOOL OS_IsThreadTerminated(const OSThread *thread);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void OS_WakeupThread(OSThreadQueue *queue);
extern void func_02004ae4(OSThread *thread);
extern OSThread *OS_SelectThread(void);
extern void OS_RescheduleThread(void);
extern void OS_YieldThread(void);
extern BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
extern u32 OS_GetThreadPriority(const OSThread *thread);
extern void OS_Sleep(u32 msec);
extern OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);
extern u32 OS_DisableScheduler(void);
extern u32 OS_EnableScheduler(void);
extern void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor);
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;

    OSMutexLink link;
};
extern void OS_InitMutex(OSMutex *mutex);
extern BOOL OS_TryLockMutex(OSMutex *mutex);
extern void OS_UnlockMutex(OSMutex *mutex);
extern void OSi_UnlockAllMutex(OSThread *thread);
extern void OS_LockMutex(OSMutex *mtx);
typedef u32 OSIrqMask;
typedef void (*OSIrqFunction)(void);
typedef struct {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;
extern OSIrqFunction OS_IRQTable[];
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[(7 + 1)];
static inline vu32 OS_GetVBlankCount(void) {
    return *(vu32 *) (0x02000000 + 0x007ffc3c);
}
static inline void OSi_SetVBlankCount(u32 count) {
    *(u32 *) (0x02000000 + 0x007ffc3c) = count;
}
static inline void OS_ClearIrqCheckFlag(OSIrqMask intr) {
    *(vu32 *) ((((u32) SDK_AUTOLOAD_DTCM_START) + 0x00003fc0) + 0x38) &= (u32) ~intr;
}
static inline u32 OS_GetIrqCheckFlag(void) {
    return *(vu32 *) ((((u32) SDK_AUTOLOAD_DTCM_START) + 0x00003fc0) + 0x38);
}
static inline void OS_SetIrqCheckFlag(OSIrqMask intr) {
    *(vu32 *) ((((u32) SDK_AUTOLOAD_DTCM_START) + 0x00003fc0) + 0x38) |= (u32) intr;
}
static inline BOOL OS_EnableIrq(void) {
    u16 prep                               = (*(REGType16v *) (0x04000000 + 0x208));
    (*(REGType16v *) (0x04000000 + 0x208)) = (1UL << 0);
    return (BOOL) prep;
}
static inline BOOL OS_DisableIrq(void) {
    u16 prep                               = (*(REGType16v *) (0x04000000 + 0x208));
    (*(REGType16v *) (0x04000000 + 0x208)) = (0UL << 0);
    return (BOOL) prep;
}
static inline BOOL OS_RestoreIrq(BOOL enable) {
    BOOL ime                               = (*(REGType16v *) (0x04000000 + 0x208));
    (*(REGType16v *) (0x04000000 + 0x208)) = enable;
    return ime;
}
static inline OSIrqMask OS_GetIrqMask(void) {
    return (*(REGType32v *) (0x04000000 + 0x210));
}
static inline OSIrqMask OS_GetRequestIrqMask(void) {
    return (*(REGType32v *) (0x04000000 + 0x214));
}
extern void OS_InitIrqTable(void);
extern void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function);
extern OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit);
extern void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *arg), void *arg);
extern void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
extern OSIrqMask OS_SetIrqMask(OSIrqMask mask);
extern OSIrqMask OS_EnableIrqMask(OSIrqMask mask);
extern OSIrqMask OS_DisableIrqMask(OSIrqMask mask);
extern OSIrqMask OS_ResetRequestIrqMask(OSIrqMask mask);
extern void OS_SetIrqStackChecker(void);
typedef s32 (*MIi_InitReadStreamCallback)(const u8 *devicep, void *ramp, const void *paramp);
typedef s32 (*MIi_TerminateReadStreamCallback)(const u8 *devicep);
typedef u8 (*MIi_ReadByteStreamCallback)(const u8 *devicep);
typedef u16 (*MIi_ReadShortStreamCallback)(const u8 *devicep);
typedef u32 (*MIi_ReadWordStreamCallback)(const u8 *devicep);
typedef struct {
    MIi_InitReadStreamCallback initStream;
    MIi_TerminateReadStreamCallback terminateStream;
    MIi_ReadByteStreamCallback readByteStream;
    MIi_ReadShortStreamCallback readShortStream;
    MIi_ReadWordStreamCallback readWordStream;
} MIReadStreamCallbacks;
extern MIReadStreamCallbacks *MI_GetReadStreamFromMemoryCallbacks(void);
typedef enum {
    MI_COMPRESSION_LZ      = 0x10,
    MI_COMPRESSION_HUFFMAN = 0x20,
    MI_COMPRESSION_RL      = 0x30,
    MI_COMPRESSION_DIFF    = 0x80,

    MI_COMPRESSION_TYPE_MASK    = 0xF0,
    MI_COMPRESSION_TYPE_EX_MASK = 0xFF
} MICompressionType;
typedef struct {
    u32 compParam : 4;
    u32 compType : 4;
    u32 destSize : 24;
} MICompressionHeader;
typedef struct {
    u16 srcNum;
    u16 srcBitNum : 8;
    u16 destBitNum : 8;
    u32 destOffset : 31;
    u32 destOffset0_on : 1;
} MIUnpackBitsParam;
extern void MI_UncompressLZ8(const void *srcp, void *destp);
extern void MI_UncompressLZ16(const void *srcp, void *destp);
extern void MI_UncompressHuffman(const void *srcp, void *destp);
extern void MI_UncompressRL8(const void *srcp, void *destp);
extern void MI_UncompressRL16(const void *srcp, void *destp);
extern void MI_UnfilterDiff8(const void *srcp, void *destp);
extern void MI_UnfilterDiff16(const void *srcp, void *destp);
extern void MIi_UncompressBackward(void *bottom);
static inline u32 MI_GetUncompressedSize(const void *srcp) {
    return (*(u32 *) srcp >> 8);
}
static inline MICompressionType MI_GetCompressionType(const void *srcp) {
    return (MICompressionType) (*(u32 *) srcp & MI_COMPRESSION_TYPE_MASK);
}
extern void SVC_WaitByLoop(s32 count);
extern void SVC_CpuSet(const void *srcp, void *destp, u32 dmaCntData);
extern void SVC_CpuSetFast(const void *srcp, void *destp, u32 dmaCntData);
extern void SVC_UnpackBits(const void *srcp, void *destp, const MIUnpackBitsParam *paramp);
extern void SVC_UncompressLZ8(const void *srcp, void *destp);
extern void SVC_UncompressRL8(const void *srcp, void *destp);
extern s32 SVC_UncompressLZ16FromDevice(const void *srcp, void *destp, const void *paramp,
                                        const MIReadStreamCallbacks *callbacks);
extern s32 SVC_UncompressRL16FromDevice(const void *srcp, void *destp, const void *paramp,
                                        const MIReadStreamCallbacks *callbacks);
extern s32 SVC_UncompressHuffmanFromDevice(const void *srcp, void *destp, u8 *tableBufp,
                                           const MIReadStreamCallbacks *callbacks);
extern u16 SVC_GetCRC16(u32 start, const void *datap, u32 size);
extern BOOL SVC_IsMmemExpanded(void);
extern s32 SVC_Div(s32 number, s32 denom);
extern s32 SVC_DivRem(s32 number, s32 denom);
extern u16 SVC_Sqrt(u32 src);
extern void SVC_Halt(void);
extern void OS_InitLock(void);
extern s32 OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
extern s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
extern s32 OS_UnlockCartridge(u16 lockID);
extern s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
extern s32 OS_LockCartridge(u16 lockID);
extern s32 OS_TryLockCartridge(u16 lockID);
extern s32 OS_LockCard(u16 lockID);
extern s32 OS_UnlockCard(u16 lockID);
extern s32 OS_TryLockCard(u16 lockID);
extern u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp);
extern s32 OS_GetLockID(void);
extern void OS_ReleaseLockID(register u16 lockID);
extern s32 OS_UnLockCartridge(u16 lockID);
typedef char *va_list;
typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned short wchar_t;
extern char *STD_CopyString(char *destp, const char *srcp);
extern int STD_CopyLStringZeroFill(char *destp, const char *srcp, int n);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);
extern char *STD_SearchString(const char *srcp, const char *str);
extern int STD_GetStringLength(const char *str);
extern char *STD_ConcatenateString(char *str1, const char *str2);
extern int STD_CompareString(const char *str1, const char *str2);
extern int STD_CompareNString(const char *str1, const char *str2, int len);
extern int STD_CompareLString(const char *str1, const char *str2);
extern int STD_TSScanf(const char *src, const char *fmt, ...);
extern int STD_TVSScanf(const char *src, const char *fmt, va_list vlist);
extern int STD_TSPrintf(char *dst, const char *fmt, ...);
extern int STD_TVSPrintf(char *dst, const char *fmt, va_list vlist);
extern int STD_TSNPrintf(char *dst, size_t len, const char *fmt, ...);
extern int STD_TVSNPrintf(char *dst, size_t len, const char *fmt, va_list vlist);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int OS_VSPrintf(char *dst, const char *fmt, va_list vlist);
extern int OS_SNPrintf(char *dst, size_t len, const char *fmt, ...);
extern int OS_VSNPrintf(char *dst, size_t len, const char *fmt, va_list vlist);
typedef enum {
    OS_ARENA_MAIN         = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX       = 2,
    OS_ARENA_ITCM         = 3,
    OS_ARENA_DTCM         = 4,
    OS_ARENA_SHARED       = 5,
    OS_ARENA_WRAM_MAIN    = 6,
    OS_ARENA_WRAM_SUB     = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX          = 9
} OSArenaId;
typedef struct {
    void *lo[OS_ARENA_MAX];
    void *hi[OS_ARENA_MAX];
    u16 initialized;
    u8 padding[2];
} OSArenaInfo;
extern void OS_InitArena(void);
extern void OS_InitArenaEx(void);
extern void *OS_GetArenaHi(OSArenaId id);
extern void *OS_GetArenaLo(OSArenaId id);
extern void *OS_GetInitArenaHi(OSArenaId id);
extern void *OS_GetInitArenaLo(OSArenaId id);
extern void OS_SetArenaHi(OSArenaId id, void *newHi);
extern void OS_SetArenaLo(OSArenaId id, void *newLo);
extern void *OS_AllocFromArenaLo(OSArenaId id, u32 size, u32 align);
extern void *OS_AllocFromArenaHi(OSArenaId id, u32 size, u32 align);
static inline void OS_InitArenaHi(OSArenaId id) {
    OS_SetArenaHi(id, OS_GetInitArenaHi(id));
}
static inline void OS_InitArenaLo(OSArenaId id) {
    OS_SetArenaLo(id, OS_GetInitArenaLo(id));
}
static inline void OS_InitArenaHiAndLo(OSArenaId id) {
    (void) OS_InitArenaHi(id);
    (void) OS_InitArenaLo(id);
}
typedef int OSHeapHandle;
typedef void (*OSAllocVisitor)(void *obj, u32 size);
extern void *OS_InitAlloc(OSArenaId id, void *arenaStart, void *arenaEnd, int maxHeaps);
extern void OS_ClearAlloc(OSArenaId id);
extern OSHeapHandle OS_CreateHeap(OSArenaId id, void *start, void *end);
extern void OS_DestroyHeap(OSArenaId id, OSHeapHandle heap);
extern void OS_AddToHeap(OSArenaId id, OSHeapHandle heap, void *start, void *end);
extern OSHeapHandle OS_SetCurrentHeap(OSArenaId id, OSHeapHandle heap);
extern void *OS_AllocFromHeap(OSArenaId id, OSHeapHandle heap, u32 size);
extern void *OS_AllocFixed(OSArenaId id, void **rstart, void **rend);
extern void OS_FreeToHeap(OSArenaId id, OSHeapHandle heap, void *ptr);
extern void OS_FreeAllToHeap(OSArenaId id, OSHeapHandle heap);
extern s32 OS_CheckHeap(OSArenaId id, OSHeapHandle heap);
extern void OS_DumpHeap(OSArenaId id, OSHeapHandle heap);
extern u32 OS_ReferentSize(OSArenaId id, void *ptr);
extern void OS_VisitAllocated(OSArenaId id, OSAllocVisitor visitor);
extern u32 OSi_GetTotalAllocSize(OSArenaId id, OSHeapHandle heap, BOOL isHeadInclude);
extern u32 OS_GetTotalFreeSize(OSArenaId id, OSHeapHandle heap);
extern u32 OS_GetMaxFreeSize(OSArenaId id, OSHeapHandle heap);
extern void OS_ClearHeap(OSArenaId id, OSHeapHandle heap, void *start, void *end);
static inline u32 OS_GetTotalAllocSize(OSArenaId id, OSHeapHandle heap) {
    return OSi_GetTotalAllocSize(id, heap, 0);
}
static inline u32 OS_GetTotalOccupiedSize(OSArenaId id, OSHeapHandle heap) {
    return OSi_GetTotalAllocSize(id, heap, 1);
}
static inline void *OS_AllocFromMain(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_MAIN, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToMain(void *ptr) {
    OS_FreeToHeap(OS_ARENA_MAIN, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToMain(void) {
    OS_FreeAllToHeap(OS_ARENA_MAIN, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromSubPriv(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_MAIN_SUBPRIV, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToSubPriv(void *ptr) {
    OS_FreeToHeap(OS_ARENA_MAIN_SUBPRIV, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToSubPriv(void) {
    OS_FreeAllToHeap(OS_ARENA_MAIN_SUBPRIV, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromMainEx(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_MAINEX, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToMainEx(void *ptr) {
    OS_FreeToHeap(OS_ARENA_MAINEX, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToMainEx(void) {
    OS_FreeAllToHeap(OS_ARENA_MAINEX, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromITCM(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_ITCM, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToITCM(void *ptr) {
    OS_FreeToHeap(OS_ARENA_ITCM, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToITCM(void) {
    OS_FreeAllToHeap(OS_ARENA_ITCM, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromDTCM(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_DTCM, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToDTCM(void *ptr) {
    OS_FreeToHeap(OS_ARENA_DTCM, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToDTCM(void) {
    OS_FreeAllToHeap(OS_ARENA_DTCM, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromShared(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_SHARED, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToShared(void *ptr) {
    OS_FreeToHeap(OS_ARENA_SHARED, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToShared(void) {
    OS_FreeAllToHeap(OS_ARENA_SHARED, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromWramMain(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_WRAM_MAIN, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToWramMain(void *ptr) {
    OS_FreeToHeap(OS_ARENA_WRAM_MAIN, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToWramMain(void) {
    OS_FreeAllToHeap(OS_ARENA_WRAM_MAIN, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromWramSub(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_WRAM_SUB, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToWramSub(void *ptr) {
    OS_FreeToHeap(OS_ARENA_WRAM_SUB, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToWramSub(void) {
    OS_FreeAllToHeap(OS_ARENA_WRAM_SUB, ((OSHeapHandle) -1));
}
static inline void *OS_AllocFromSubPrivWram(u32 size) {
    return OS_AllocFromHeap(OS_ARENA_WRAM_SUBPRIV, ((OSHeapHandle) -1), size);
}
static inline void OS_FreeToSubPrivWram(void *ptr) {
    OS_FreeToHeap(OS_ARENA_WRAM_SUBPRIV, ((OSHeapHandle) -1), ptr);
}
static inline void OS_FreeAllToSubPrivWram(void) {
    OS_FreeAllToHeap(OS_ARENA_WRAM_SUBPRIV, ((OSHeapHandle) -1));
}
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
typedef enum {
    PXI_FIFO_SUCCESS           = 0,
    PXI_FIFO_FAIL_SEND_ERR     = -1,
    PXI_FIFO_FAIL_SEND_FULL    = -2,
    PXI_FIFO_FAIL_RECV_ERR     = -3,
    PXI_FIFO_FAIL_RECV_EMPTY   = -4,
    PXI_FIFO_NO_CALLBACK_ENTRY = -5
} PXIFifoStatus;
typedef void (*PXIFifoCallback)(PXIFifoTag tag, u32 data, BOOL err);
typedef union {
    struct {
        u32 tag : 5;
        u32 err : 1;
        u32 data : 26;
    } e;
    u32 raw;
} PXIFifoMessage;
extern void PXI_InitFifo(void);
extern void func_02008170(int fifotag, PXIFifoCallback callback);
extern BOOL PXI_IsCallbackReady(int fifotag, PXIProc proc);
extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern void OS_InitReset(void);
extern BOOL OS_IsResetOccurred(void);
extern void MicCommonCallback(PXIFifoTag tag, u32 data, BOOL err);
extern void OSi_SendToPxi(u16 data);
extern void OS_ResetSystem(u32 parameter);
static inline u32 OS_GetResetParameter(void) {
    return *(u32 *) (0x02000000 + 0x007ffc20);
}
extern void OS_Terminate(void);
extern void OS_IrqDummy(void);
extern void OS_IrqHandler(void);
extern void OS_IrqHandler_ThreadSwitch(void);
typedef enum {
    OS_TIMER_PRESCALER_1    = (0UL << 0),
    OS_TIMER_PRESCALER_64   = (1UL << 0),
    OS_TIMER_PRESCALER_256  = (2UL << 0),
    OS_TIMER_PRESCALER_1024 = (3UL << 0)
} OSTimerPrescaler;
typedef enum {
    OS_TIMER_0 = 0,
    OS_TIMER_1 = 1,
    OS_TIMER_2 = 2,
    OS_TIMER_3 = 3
} OSTimer;
static inline void OS_SetTimerCount(OSTimer id, u16 count) {
    *((REGType16 *) ((u32) & (*(REGType16v *) (0x04000000 + 0x100)) + id * 4)) = count;
}
static inline void OS_SetTimerControl(OSTimer id, u16 control) {
    *((REGType16 *) ((u32) & (*(REGType16v *) (0x04000000 + 0x102)) + id * 4)) = control;
}
extern void OSi_SetTimerReserved(s32 timerNum);
typedef u64 OSTick;
extern vu64 OSi_TickCounter;
extern void OS_InitTick(void);
extern BOOL OS_IsTickAvailable(void);
extern OSTick OS_GetTick(void);
extern u16 OS_GetTickLo(void);
typedef void *OSMessage;
typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    OSMessage *msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
} OSMessageQueue;
extern void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
extern BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
extern BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
extern BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
extern BOOL OS_ReadMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
extern void OS_Init(void);
typedef void (*OSExceptionHandler)(u32, void *);
extern void OS_InitException(void);
typedef void (*OSVAlarmHandler)(void *);
typedef struct OSiVAlarm OSVAlarm;
struct OSiVAlarm {
    OSVAlarmHandler handler;
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
extern void OS_InitVAlarm(void);
extern BOOL OS_IsVAlarmAvailable(void);
extern void OS_CreateVAlarm(OSVAlarm *alarm);
extern void OS_SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg);
extern void OS_SetPeriodicVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg);
extern void OS_SetVAlarmTag(OSVAlarm *alarm, u32 tag);
extern void OS_CancelVAlarm(OSVAlarm *alarm);
extern void OS_CancelVAlarms(u32 tag);
extern BOOL OS_IsRunOnEmulator(void);
extern u32 OS_GetConsoleType(void);
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
extern void OS_InitAlarm(void);
extern BOOL OS_IsAlarmAvailable(void);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg);
extern void OS_SetPeriodicAlarm(OSAlarm *alarm, OSTick start, OSTick period, OSAlarmHandler handler, void *arg);
extern void OS_CancelAlarm(OSAlarm *alarm);
struct OSiAlarmQueue {
    OSAlarm *head;
    OSAlarm *tail;
};
extern struct OSiAlarmQueue *OSi_GetAlarmQueue(void);
extern void OSi_SetTimer(OSAlarm *alarm);
extern void OS_InitAlarm(void);
extern void OSi_InsertAlarm(OSAlarm *alarm, OSTick fire);
typedef struct NVRAMConfigDate {
    u8 month;
    u8 day;
} NVRAMConfigDate;
typedef struct NVRAMConfigNickname {
    u16 str[10];
    u8 length;
    u8 rsv;
} NVRAMConfigNickname;
typedef struct NVRAMConfigComment {
    u16 str[26];
    u8 length;
    u8 rsv;
} NVRAMConfigComment;
typedef struct NVRAMConfigOwnerInfo {
    u8 favoriteColor : 4;
    u8 rsv : 4;
    NVRAMConfigDate birthday;
    u8 pad;
    NVRAMConfigNickname nickname;
    NVRAMConfigComment comment;
} NVRAMConfigOwnerInfo;
typedef struct NVRAMConfigAlarm {
    u8 hour;
    u8 minute;
    u8 second;
    u8 pad;
    u16 enableWeek : 7;
    u16 alarmOn : 1;
    u16 rsv : 8;
} NVRAMConfigAlarm;
typedef struct NVRAMConfigTpCalibData {
    u16 raw_x1;
    u16 raw_y1;
    u8 dx1;
    u8 dy1;
    u16 raw_x2;
    u16 raw_y2;
    u8 dx2;
    u8 dy2;
} NVRAMConfigTpCalibData;
typedef struct NVRAMConfigOption {
    u16 language : 3;
    u16 agbLcd : 1;
    u16 detectPullOutCardFlag : 1;
    u16 detectPullOutCtrdgFlag : 1;
    u16 autoBootFlag : 1;
    u16 rsv : 4;
    u16 input_favouriteColour : 1;
    u16 input_tp : 1;
    u16 input_language : 1;
    u16 input_rtc : 1;
    u16 input_nickname : 1;
    u8 timeZone;
    u8 rtcClockAdjust;
    s64 rtcOffset;
} NVRAMConfigOption;
typedef struct NVRAMConfigData {
    u8 version;
    u8 pad;
    NVRAMConfigOwnerInfo owner;
    NVRAMConfigAlarm alarm;
    NVRAMConfigTpCalibData tp;
    NVRAMConfigOption option;
} NVRAMConfigData;
typedef struct NVRAMConfig {
    NVRAMConfigData ncd;
    u16 saveCount;
    u16 crc16;
} NVRAMConfig;
typedef enum OSLanguage_ {
    OS_LANGUAGE_JAPANESE = 0,
    OS_LANGUAGE_ENGLISH  = 1,
    OS_LANGUAGE_FRENCH   = 2,
    OS_LANGUAGE_GERMAN   = 3,
    OS_LANGUAGE_ITALIAN  = 4,
    OS_LANGUAGE_SPANISH  = 5,
    OS_LANGUAGE_CODE_MAX = 6
} OSLanguage;
typedef struct OSBirthday {
    u8 month;
    u8 day;
} OSBirthday;
typedef struct OSOwnerInfo {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[10];
    u16 nickNameLength;
    u16 comment[26];
    u16 commentLength;
} OSOwnerInfo;
extern void OS_GetMacAddress(u8 *macAddr);
extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern void OS_GetLowEntropyData(u32 buffer[32 / sizeof(u32)]);
extern void OS_WaitIrq(BOOL clear, OSIrqMask irqFlags);
extern void DC_InvalidateAll(void);
extern void DC_StoreAll(void);
extern void DC_FlushAll(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_StoreRange(const void *startAddr, u32 nBytes);
extern void func_02005850(const void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
extern void IC_InvalidateAll(void);
extern void IC_InvalidateRange(void *startAddr, u32 nBytes);
typedef enum {
    OSi_PR_BASE_MASK_4KB   = 0xfffff000,
    OSi_PR_BASE_MASK_8KB   = 0xffffe000,
    OSi_PR_BASE_MASK_16KB  = 0xffffc000,
    OSi_PR_BASE_MASK_32KB  = 0xffff8000,
    OSi_PR_BASE_MASK_64KB  = 0xffff0000,
    OSi_PR_BASE_MASK_128KB = 0xfffe0000,
    OSi_PR_BASE_MASK_256KB = 0xfffc0000,
    OSi_PR_BASE_MASK_512KB = 0xfff80000,
    OSi_PR_BASE_MASK_1MB   = 0xfff00000,
    OSi_PR_BASE_MASK_2MB   = 0xffe00000,
    OSi_PR_BASE_MASK_4MB   = 0xffc00000,
    OSi_PR_BASE_MASK_8MB   = 0xff800000,
    OSi_PR_BASE_MASK_16MB  = 0xff000000,
    OSi_PR_BASE_MASK_32MB  = 0xfe000000,
    OSi_PR_BASE_MASK_64MB  = 0xfc000000,
    OSi_PR_BASE_MASK_128MB = 0xf8000000,
    OSi_PR_BASE_MASK_256MB = 0xf0000000,
    OSi_PR_BASE_MASK_512MB = 0xe0000000,
    OSi_PR_BASE_MASK_1GB   = 0xc0000000,
    OSi_PR_BASE_MASK_2GB   = 0x80000000,
    OSi_PR_BASE_MASK_4GB   = 0x00000000
} OSiProtectionRegionBaseMask;
extern void OS_EnableICacheForProtectionRegion(register u32 flags);
extern void OS_DisableICacheForProtectionRegion(register u32 flags);
extern u32 OS_GetICacheEnableFlagsForProtectionRegion(void);
extern void OS_SetIPermissionsForProtectionRegion(u32 setMask, u32 flags);
extern u32 OS_GetIPermissionsForProtectionRegion(void);
extern void OS_EnableDCacheForProtectionRegion(u32 flags);
extern void OS_DisableDCacheForProtectionRegion(u32 flags);
extern u32 OS_GetDCacheEnableFlagsForProtectionRegion(u32 flags);
extern void OS_SetDPermissionsForProtectionRegion(u32 setMask, u32 flags);
extern u32 OS_GetDPermissionsForProtectionRegion(void);
extern void OS_EnableWriteBufferForProtectionRegion(u32 flags);
extern void OS_DisableWriteBufferForProtectionRegion(u32 flags);
extern u32 OS_GetWriteBufferEnableFlagsForProtectionRegion(u32 flags);
extern void OS_SetProtectionRegion0(u32 param);
extern void OS_SetProtectionRegion1(u32 param);
extern void OS_SetProtectionRegion2(u32 param);
extern void OS_SetProtectionRegion3(u32 param);
extern void OS_SetProtectionRegion4(u32 param);
extern void OS_SetProtectionRegion5(u32 param);
extern void OS_SetProtectionRegion6(u32 param);
extern void OS_SetProtectionRegion7(u32 param);
extern u32 OS_GetProtectionRegion0(void);
extern u32 OS_GetProtectionRegion1(void);
extern u32 OS_GetProtectionRegion2(void);
extern u32 OS_GetProtectionRegion3(void);
extern u32 OS_GetProtectionRegion4(void);
extern u32 OS_GetProtectionRegion5(void);
extern u32 OS_GetProtectionRegion6(void);
extern u32 OS_GetProtectionRegion7(void);
static inline u32 OSi_CalcPRParam(u32 address, u32 size, OSiProtectionRegionBaseMask mask) {
    return ((address & mask) | size);
}
extern void OS_DisableProtectionUnit(void);
extern void OS_EnableProtectionUnit(void);
extern u32 OsCountZeroBits(u32 bitmap);
extern void OSi_UnlockVram(u16 bank, u16 lockId);
extern void OSi_InitVramExclusive(void);
typedef enum {
    MI_WRAM_ARM9_ALL = 0 << 0,
    MI_WRAM_1616_1   = 1 << 0,
    MI_WRAM_1616_2   = 2 << 0,
    MI_WRAM_ARM7_ALL = 3 << 0
} MIWram;
extern void MI_SetWramBank(MIWram cnt);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
extern void MIi_CpuSend32(const void *srcp, volatile void *destp, u32 size);
extern void func_02006a04(u32 data, void *destp, u32 size);
extern void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
extern void MI_Copy32B(const void *pSrc, void *pDest);
extern void MI_Copy36B(const void *pSrc, void *pDest);
extern void MI_Copy48B(const void *pSrc, void *pDest);
extern void MI_Copy64B(const void *pSrc, void *pDest);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_02006ae4(const void *srcp, void *dstp, u32 size);
extern void MI_Zero36B(void *pDest);
static inline void MI_CpuClear8(void *dest, u32 size) {
    MI_CpuFill8(dest, 0, size);
}
static inline void MI_CpuCopy16(const void *src, void *dest, u32 size) {
    MIi_CpuCopy16(src, dest, size);
}
static inline void MI_CpuFill16(void *dest, u16 data, u32 size) {
    MIi_CpuClear16(data, dest, size);
}
static inline void MI_CpuClear16(void *dest, u32 size) {
    MI_CpuFill16(dest, 0, size);
}
static inline void MI_CpuCopy32(const void *src, void *dest, u32 size) {
    MIi_CpuCopy32(src, dest, size);
}
static inline void MI_CpuFill32(void *dest, u32 data, u32 size) {
    MIi_CpuClear32(data, dest, size);
}
static inline void MI_CpuClear32(void *dest, u32 size) {
    MI_CpuFill32(dest, 0, size);
}
static inline void MI_CpuSend32(const void *src, volatile void *dest, u32 size) {
    MIi_CpuSend32(src, dest, size);
}
static inline void MI_CpuCopyFast(const void *src, void *dest, u32 size) {
    MIi_CpuCopyFast(src, dest, size);
}
static inline void MI_CpuFillFast(void *dest, u32 data, u32 size) {
    func_02006a04(data, dest, size);
}
static inline void MI_CpuClearFast(void *dest, u32 size) {
    MI_CpuFillFast(dest, 0, size);
}
typedef enum {
    MI_PROCESSOR_ARM9 = 0,
    MI_PROCESSOR_ARM7 = 1
} MIProcessor;
typedef enum {
    MI_CTRDG_ROMCYCLE1_10 = 0,
    MI_CTRDG_ROMCYCLE1_8  = 1,
    MI_CTRDG_ROMCYCLE1_6  = 2,
    MI_CTRDG_ROMCYCLE1_18 = 3
} MICartridgeRomCycle1st;
typedef enum {
    MI_CTRDG_ROMCYCLE2_6 = 0,
    MI_CTRDG_ROMCYCLE2_4 = 1
} MICartridgeRomCycle2nd;
typedef enum {
    MI_CTRDG_RAMCYCLE_10 = 0,
    MI_CTRDG_RAMCYCLE_8  = 1,
    MI_CTRDG_RAMCYCLE_6  = 2,
    MI_CTRDG_RAMCYCLE_18 = 3
} MICartridgeRamCycle;
typedef enum {
    MIi_PHI_CLOCK_LOW   = 0,
    MIi_PHI_CLOCK_4MHZ  = 1,
    MIi_PHI_CLOCK_8MHZ  = 2,
    MIi_PHI_CLOCK_16MHZ = 3
} MIiPhiClock;
typedef enum {
    MI_WMWAIT0_1_9  = 0,
    MI_WMWAIT0_1_7  = 1,
    MI_WMWAIT0_1_5  = 2,
    MI_WMWAIT0_1_17 = 3
} MIWMWait0_1;
typedef enum {
    MI_WMWAIT0_2_5 = 0,
    MI_WMWAIT0_2_3 = 1
} MIWMWait0_2;
typedef enum {
    MI_WMWAIT1_1_9  = 0,
    MI_WMWAIT1_1_7  = 1,
    MI_WMWAIT1_1_5  = 2,
    MI_WMWAIT1_1_17 = 3
} MIWMWait1_1;
typedef enum {
    MI_WMWAIT1_2_9 = 0,
    MI_WMWAIT1_2_3 = 1
} MIWMWait1_2;
typedef enum {
    MI_PHI_CLOCK_CARTRIDGE = 0,
    MI_PHI_CLOCK_33MHZ     = 1
} MIPhiControl;
static inline MIProcessor MI_GetMainMemoryPriority(void) {
    return (MIProcessor) (((*(REGType16v *) (0x04000000 + 0x204)) & 0x8000) >> 15);
}
static inline MICartridgeRomCycle1st MI_GetCartridgeRomCycle1st(void) {
    return (MICartridgeRomCycle1st) (((*(REGType16v *) (0x04000000 + 0x204)) & 0xc) >> 2);
}
static inline MICartridgeRomCycle2nd MI_GetCartridgeRomCycle2nd(void) {
    return (MICartridgeRomCycle2nd) (((*(REGType16v *) (0x04000000 + 0x204)) & 0x10) >> 4);
}
static inline void MI_SetCartridgeRomCycle1st(MICartridgeRomCycle1st c1) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0xc) | (c1 << 2));
}
static inline void MI_SetCartridgeRomCycle2nd(MICartridgeRomCycle2nd c2) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0x10) | (c2 << 4));
}
static inline void MI_SetCartridgeRamCycle(MICartridgeRamCycle c) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~3) | (c << 0));
}
static inline MICartridgeRamCycle MI_GetCartridgeRamCycle(void) {
    return (MICartridgeRamCycle) (((*(REGType16v *) (0x04000000 + 0x204)) & 3) >> 0);
}
static inline MIProcessor MI_GetCartridgeProcessor(void) {
    return (MIProcessor) (((*(REGType16v *) (0x04000000 + 0x204)) & 0x0080) >> 7);
}
static inline void MIi_SetPhiClock(MIiPhiClock clock) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0x0060) | (clock << 5));
}
static inline MIiPhiClock MIi_GetPhiClock(void) {
    return (MIiPhiClock) (((*(REGType16v *) (0x04000000 + 0x204)) & 0x0060) >> 5);
}
static inline void MI_SetMainMemoryPriority(MIProcessor proc) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0x8000) | (proc << 15));
}
static inline void MIi_SetCardProcessor(MIProcessor proc) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0x0800) | (proc << 11));
}
static inline void MIi_SetCartridgeProcessor(MIProcessor proc) {
    (*(REGType16v *) (0x04000000 + 0x204)) = (u16) (((*(REGType16v *) (0x04000000 + 0x204)) & ~0x0080) | (proc << 7));
}
extern u32 MI_SwapWord(u32 setData, vu32 *destp);
typedef void (*MIDmaCallback)(void *);
extern void MI_HBlankDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
extern void MI_HBlankDmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
extern void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
extern void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
extern void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
typedef union {
    u32 b32;
    u16 b16;
} MIiDmaClearSrc;
extern void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size);
extern void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
extern void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
extern void MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg);
extern void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void MI_WaitDma(u32 dmaNo);
extern void MI_StopDma(u32 dmaNo);
extern void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
extern void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
extern void MIi_DmaSetParams(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
extern void MIi_DmaSetParams_wait(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
extern void MIi_DmaSetParams_noInt(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
extern void MIi_DmaSetParams_wait_noInt(u32 dmaNo, u32 src, u32 dest, u32 ctrl);
static inline void MIi_DmaSetParams_wait_src32(u32 dmaNo, u32 data, u32 dest, u32 ctrl) {
    OSIntrMode lastIntrMode = OS_DisableInterrupts();

    MIiDmaClearSrc *scrp = (MIiDmaClearSrc *) ((u32) (0x04000000 + 0x0e0) + dmaNo * 4);
    scrp->b32            = data;
    MIi_DmaSetParams_wait_noInt(dmaNo, (u32) scrp, dest, ctrl);

    (void) OS_RestoreInterrupts(lastIntrMode);
}
static inline void MIi_DmaSetParams_src32(u32 dmaNo, u32 data, u32 dest, u32 ctrl) {
    OSIntrMode lastIntrMode = OS_DisableInterrupts();

    MIiDmaClearSrc *srcp = (MIiDmaClearSrc *) ((u32) (0x04000000 + 0x0e0) + dmaNo * 4);
    srcp->b32            = data;
    MIi_DmaSetParams_noInt(dmaNo, (u32) srcp, dest, ctrl);

    (void) OS_RestoreInterrupts(lastIntrMode);
}
static inline void MIi_CallCallback(MIDmaCallback callback, void *arg) {
    if (callback) {
        callback(arg);
    }
}
static inline u8 MI_ReadByte(const void *address) {
    return *(u8 *) address;
}
static inline void MI_WriteByte(void *address, u8 value) {
    *(u8 *) address = value;
}
static inline u8 MI_LoadLE8(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u8) ((src[0] << 0UL));
}
static inline u16 MI_LoadLE16(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u16) ((src[0] << 0UL) | (src[1] << 8UL));
}
static inline u32 MI_LoadLE32(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u32) ((src[0] << 0UL) | (src[1] << 8UL) | (src[2] << 16UL) | (src[3] << 24UL));
}
static inline u8 MI_LoadBE8(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u8) ((src[0] << 0UL));
}
static inline u16 MI_LoadBE16(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u16) ((src[0] << 8UL) | (src[1] << 0UL));
}
static inline u32 MI_LoadBE32(const void *ptr) {
    const u8 *src = (const u8 *) ptr;
    return (u32) ((src[0] << 24UL) | (src[1] << 16UL) | (src[2] << 8UL) | (src[3] << 0UL));
}
static inline void MI_StoreLE8(void *ptr, u8 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 0UL);
}
static inline void MI_StoreLE16(void *ptr, u16 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 0UL);
    src[1]  = (u8) (val >> 8UL);
}
static inline void MI_StoreLE32(void *ptr, u32 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 0UL);
    src[1]  = (u8) (val >> 8UL);
    src[2]  = (u8) (val >> 16UL);
    src[3]  = (u8) (val >> 24UL);
}
static inline void MI_StoreBE8(void *ptr, u8 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 0UL);
}
static inline void MI_StoreBE16(void *ptr, u16 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 8UL);
    src[1]  = (u8) (val >> 0UL);
}
static inline void MI_StoreBE32(void *ptr, u32 val) {
    u8 *src = (u8 *) ptr;
    src[0]  = (u8) (val >> 24UL);
    src[1]  = (u8) (val >> 16UL);
    src[2]  = (u8) (val >> 8UL);
    src[3]  = (u8) (val >> 0UL);
}
extern void MI_Init(void);
extern void PXI_Init(void);
extern void SND_Init(void);
extern void SNDi_LockMutex(void);
extern void SNDi_UnlockMutex(void);
typedef void (*SNDAlarmHandler)(void *);
typedef struct SNDAlarm {
    u8 enable;
    u8 id;
    u16 padding;

    struct {
        OSTick tick;
        OSTick period;
    } setting;

    OSAlarm alarm;
} SNDAlarm;
extern void SND_AlarmInit(void);
extern void SNDi_IncAlarmId(int alarmNo);
extern u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);
extern void SNDi_CallAlarmHandler(int alarmNo);
typedef enum SNDCommandID {
    SND_COMMAND_START_SEQ,
    SND_COMMAND_STOP_SEQ,
    SND_COMMAND_PREPARE_SEQ,
    SND_COMMAND_START_PREPARED_SEQ,
    SND_COMMAND_PAUSE_SEQ,
    SND_COMMAND_SKIP_SEQ,
    SND_COMMAND_PLAYER_PARAM,
    SND_COMMAND_TRACK_PARAM,
    SND_COMMAND_MUTE_TRACK,
    SND_COMMAND_ALLOCATABLE_CHANNEL,
    SND_COMMAND_PLAYER_LOCAL_VAR,
    SND_COMMAND_PLAYER_GLOBAL_VAR,
    SND_COMMAND_START_TIMER,
    SND_COMMAND_STOP_TIMER,
    SND_COMMAND_SETUP_CHANNEL_PCM,
    SND_COMMAND_SETUP_CHANNEL_PSG,
    SND_COMMAND_SETUP_CHANNEL_NOISE,
    SND_COMMAND_SETUP_CAPTURE,
    SND_COMMAND_SETUP_ALARM,
    SND_COMMAND_CHANNEL_TIMER,
    SND_COMMAND_CHANNEL_VOLUME,
    SND_COMMAND_CHANNEL_PAN,
    SND_COMMAND_SURROUND_DECAY,
    SND_COMMAND_MASTER_VOLUME,
    SND_COMMAND_MASTER_PAN,
    SND_COMMAND_OUTPUT_SELECTOR,
    SND_COMMAND_LOCK_CHANNEL,
    SND_COMMAND_UNLOCK_CHANNEL,
    SND_COMMAND_STOP_UNLOCKED_CHANNEL,
    SND_COMMAND_SHARED_WORK,
    SND_COMMAND_INVALIDATE_SEQ,
    SND_COMMAND_INVALIDATE_BANK,
    SND_COMMAND_INVALIDATE_WAVE,
    SND_COMMAND_READ_DRIVER_INFO
} SNDCommandID;
typedef struct SNDCommand {
    struct SNDCommand *next;
    SNDCommandID id;
    u32 arg[4];
} SNDCommand;
extern void SND_CommandInit(void);
extern struct SNDCommand *SND_AllocCommand(u32 flags);
extern void SND_PushCommand(struct SNDCommand *command);
extern const SNDCommand *SND_RecvCommandReply(u32 flags);
extern BOOL SND_FlushCommand(u32 flags);
extern void SND_WaitForCommandProc(u32 tag);
extern void SND_WaitForFreeCommand(int count);
extern u32 SND_GetCurrentCommandTag(void);
extern BOOL SND_IsFinishedCommandTag(u32 tag);
extern int SND_CountFreeCommand(void);
extern int SND_CountReservedCommand(void);
extern int SND_CountWaitingCommand(void);
typedef enum SNDChannelOut {
    SND_CHANNEL_OUT_MIXER,
    SND_CHANNEL_OUT_BYPASS
} SNDChannelOut;
typedef enum SNDOutput {
    SND_OUTPUT_MIXER,
    SND_OUTPUT_CHANNEL1,
    SND_OUTPUT_CHANNEL3,
    SND_OUTPUT_CHANNEL1_3
} SNDOutput;
typedef enum {
    SND_CAPTURE_0,
    SND_CAPTURE_1
} SNDCapture;
typedef enum {
    SND_CAPTURE_FORMAT_PCM16,
    SND_CAPTURE_FORMAT_PCM8
} SNDCaptureFormat;
typedef enum {
    SND_CAPTURE_REPEAT_YES,
    SND_CAPTURE_REPEAT_NO
} SNDCaptureRepeat;
typedef enum {
    SND_CAPTURE_IN_MIXER,
    SND_CAPTURE_IN_CHANNEL,

    SND_CAPTURE_IN_MIXER_L  = SND_CAPTURE_IN_MIXER,
    SND_CAPTURE_IN_MIXER_R  = SND_CAPTURE_IN_MIXER,
    SND_CAPTURE_IN_CHANNEL0 = SND_CAPTURE_IN_CHANNEL,
    SND_CAPTURE_IN_CHANNEL2 = SND_CAPTURE_IN_CHANNEL
} SNDCaptureIn;
typedef enum {
    SND_CAPTURE_OUT_NORMAL,
    SND_CAPTURE_OUT_CHANNEL_MIX,

    SND_CAPTURE_OUT_CHANNEL0_MIX = SND_CAPTURE_OUT_CHANNEL_MIX,
    SND_CAPTURE_OUT_CHANNEL2_MIX = SND_CAPTURE_OUT_CHANNEL_MIX
} SNDCaptureOut;
typedef enum {
    SND_CHANNEL_0,
    SND_CHANNEL_1,
    SND_CHANNEL_2,
    SND_CHANNEL_3,
    SND_CHANNEL_4,
    SND_CHANNEL_5,
    SND_CHANNEL_6,
    SND_CHANNEL_7,
    SND_CHANNEL_8,
    SND_CHANNEL_9,
    SND_CHANNEL_10,
    SND_CHANNEL_11,
    SND_CHANNEL_12,
    SND_CHANNEL_13,
    SND_CHANNEL_14,
    SND_CHANNEL_15
} SNDChannelId;
typedef enum {
    SND_WAVE_FORMAT_PCM8,
    SND_WAVE_FORMAT_PCM16,
    SND_WAVE_FORMAT_ADPCM,
    SND_WAVE_FORMAT_PSG,
    SND_WAVE_FORMAT_NOISE = SND_WAVE_FORMAT_PSG
} SNDWaveFormat;
typedef enum {
    SND_CHANNEL_LOOP_MANUAL,
    SND_CHANNEL_LOOP_REPEAT,
    SND_CHANNEL_LOOP_1SHOT
} SNDChannelLoop;
typedef enum {
    SND_DUTY_1_8,
    SND_DUTY_2_8,
    SND_DUTY_3_8,
    SND_DUTY_4_8,
    SND_DUTY_5_8,
    SND_DUTY_6_8,
    SND_DUTY_7_8
} SNDDuty;
typedef enum {
    SND_CHANNEL_DATASHIFT_NONE,
    SND_CHANNEL_DATASHIFT_1BIT,
    SND_CHANNEL_DATASHIFT_2BIT,
    SND_CHANNEL_DATASHIFT_4BIT
} SNDChannelDataShift;
extern void SND_StartChannel(int chNo);
struct SNDExChannel;
typedef enum SNDExChannelType {
    SND_EX_CHANNEL_PCM,
    SND_EX_CHANNEL_PSG,
    SND_EX_CHANNEL_NOISE
} SNDExChannelType;
typedef enum SNDExChannelCallbackStatus {
    SND_EX_CHANNEL_CALLBACK_DROP,
    SND_EX_CHANNEL_CALLBACK_FINISH
} SNDExChannelCallbackStatus;
typedef enum SNDEnvStatus {
    SND_ENV_ATTACK,
    SND_ENV_DECAY,
    SND_ENV_SUSTAIN,
    SND_ENV_RELEASE
} SNDEnvStatus;
typedef enum SNDLfoTarget {
    SND_LFO_PITCH,
    SND_LFO_VOLUME,
    SND_LFO_PAN
} SNDLfoTarget;
typedef void (*SNDExChannelCallback)(struct SNDExChannel *ch_p, SNDExChannelCallbackStatus status, void *userData);
typedef struct SNDWaveParam {
    u8 format;
    u8 loopflag;
    u16 rate;
    u16 timer;
    u16 loopstart;
    u32 looplen;
} SNDWaveParam;
typedef struct SNDLfoParam {
    u8 target;
    u8 speed;
    u8 depth;
    u8 range;
    u16 delay;
} SNDLfoParam;
typedef struct SNDLfo {
    struct SNDLfoParam param;

    u16 delay_counter;
    u16 counter;
} SNDLfo;
typedef struct SNDExChannel {
    u8 myNo;
    u8 type;
    u8 env_status;
    u8 active_flag : 1;
    u8 start_flag : 1;
    u8 auto_sweep : 1;
    u8 sync_flag : 5;

    u8 pan_range;
    u8 original_key;
    s16 user_decay2;

    u8 key;
    u8 velocity;
    s8 init_pan;
    s8 user_pan;

    s16 user_decay;
    s16 user_pitch;

    s32 env_decay;

    s32 sweep_counter;
    s32 sweep_length;

    u8 attack;
    u8 sustain;
    u16 decay;
    u16 release;

    u8 prio;
    u8 pan;
    u16 volume;
    u16 timer;

    struct SNDLfo lfo;
    s16 sweep_pitch;

    s32 length;

    struct SNDWaveParam wave;
    union {
        const void *data;
        SNDDuty duty;
    };

    SNDExChannelCallback callback;
    void *callback_data;

    struct SNDExChannel *nextLink;
} SNDExChannel;
typedef enum {
    SND_SEQ_MUTE_OFF,
    SND_SEQ_MUTE_NO_STOP,
    SND_SEQ_MUTE_RELEASE,
    SND_SEQ_MUTE_STOP
} SNDSeqMute;
struct SNDBankData;
typedef struct SNDPlayer {
    u8 active_flag : 1;
    u8 prepared_flag : 1;
    u8 pause_flag : 1;
    u8 pad_ : 5;

    u8 myNo;
    u8 pad2_;
    u8 pad3_;

    u8 prio;
    u8 volume;
    s16 extFader;

    u8 tracks[16];

    u16 tempo;
    u16 tempo_ratio;
    u16 tempo_counter;
    u16 pad__;

    struct SNDBankData *bank;
} SNDPlayer;
typedef struct SNDTrack {
    u8 active_flag : 1;
    u8 note_wait : 1;
    u8 mute_flag : 1;
    u8 tie_flag : 1;
    u8 note_finish_wait : 1;
    u8 porta_flag : 1;
    u8 cmp_flag : 1;
    u8 channel_mask_flag : 1;

    u8 pan_range;

    u16 prgNo;

    u8 volume;
    u8 volume2;
    s8 pitch_bend;
    u8 bend_range;

    s8 pan;
    s8 ext_pan;
    s16 extFader;
    s16 ext_pitch;

    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;

    u8 prio;
    s8 transpose;
    u8 porta_key;
    u8 porta_time;
    s16 sweep_pitch;

    struct SNDLfoParam mod;
    u16 channel_mask;

    s32 wait;

    const u8 *base;
    const u8 *cur;

    const u8 *call_stack[3];
    u8 loop_count[3];
    u8 call_stack_depth;

    struct SNDExChannel *channel_list;
} SNDTrack;
struct SNDBankData;
struct SNDSharedWork;
struct SNDSpCallback;
struct SNDDriverInfo;
extern void SND_StartSeq(int playerNo, const void *base, u32 offset, const struct SNDBankData *bank);
extern void SND_PrepareSeq(int playerNo, const void *base, u32 offset, const struct SNDBankData *bank);
extern void SND_StartPreparedSeq(int playerNo);
extern void SND_StopSeq(int playerNo);
extern void SND_StopSeq(int playerNo);
extern void SND_PauseSeq(int playerNo, BOOL flag);
extern void SND_SetPlayerTempoRatio(int playerNo, int ratio);
extern void SND_SetPlayerVolume(int playerNo, int volume);
extern void SND_SetPlayerChannelPriority(int playerNo, int prio);
extern void SND_SetPlayerLocalVariable(int playerNo, int varNo, s16 var);
extern void SND_SetPlayerGlobalVariable(int varNo, s16 var);
extern void SND_SetTrackMute(int playerNo, u32 trackBitMask, BOOL flag);
extern void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, SNDSeqMute mute);
extern void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume);
extern void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch);
extern void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
extern void SND_SetTrackPanRange(int playerNo, u32 trackBitMask, int panRange);
extern void SND_SetTrackModDepth(int playerNo, u32 trackBitMask, int depth);
extern void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, int speed);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
extern void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
extern void SND_LockChannel(u32 chBitMask, u32 flags);
extern void SND_UnlockChannel(u32 chBitMask, u32 flags);
extern void SND_StopUnlockedChannel(u32 chBitMask, u32 flags);
extern void SND_SetupChannelPcm(int chNo, SNDWaveFormat format, const void *dataAddr, SNDChannelLoop loop, int loopStart,
                                int dataLen, int volume, SNDChannelDataShift shift, int timer, int pan);
extern void SND_SetupChannelPsg(int chNo, SNDDuty duty, int volume, SNDChannelDataShift shift, int timer, int pan);
extern void SND_SetupChannelNoise(int chNo, int volume, SNDChannelDataShift shift, int timer, int pan);
extern void SND_SetChannelVolume(u32 chBitMask, int volume, SNDChannelDataShift shift);
extern void SND_SetChannelTimer(u32 chBitMask, int timer);
extern void SND_SetChannelPan(u32 chBitMask, int pan);
extern void SND_SetupCapture(SNDCapture capture, SNDCaptureFormat format, void *buffer_p, u32 length, BOOL loopFlag,
                             SNDCaptureIn in, SNDCaptureOut out);
extern void SND_SetupAlarm(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);
extern void SND_SetMasterVolume(int volume);
extern void SND_SetOutputSelector(SNDOutput left, SNDOutput right, SNDChannelOut channel1, SNDChannelOut channel3);
extern void SND_SetMasterPan(int pan);
extern void SND_ResetMasterPan(void);
extern void SND_InvalidateSeqData(const void *start, const void *end);
extern void SND_InvalidateBankData(const void *start, const void *end);
extern void SND_InvalidateWaveData(const void *start, const void *end);
extern void SND_ReadDriverInfo(struct SNDDriverInfo *info);
extern void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size);
extern void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
extern void SNDi_SkipSeq(int playerNo, u32 tick);
extern void SNDi_SetSurroundDecay(int decay);
typedef struct SNDWork {
    SNDExChannel channel[16];
    SNDPlayer player[16];
    SNDTrack track[32];
    SNDAlarm alarm[8];
} SNDWork;
typedef struct SNDSharedWork {
    vu32 finishCommandTag;
    vu32 playerStatus;
    vu16 channelStatus;
    vu16 captureStatus;
    vu32 padding[5];
    struct {
        vs16 variable[16];
        vu32 tickCounter;
    } player[16];
    vs16 globalVariable[16];
} SNDSharedWork;
typedef struct SNDSpReg {
    u32 chCtrl[16];
} SNDSpReg;
typedef struct SNDDriverInfo {
    SNDWork work;
    u32 chCtrl[16];
    SNDWork *workAddress;
    u32 lockedChannels;
    u32 padding[6];
} SNDDriverInfo;
typedef struct SNDChannelInfo {
    BOOL activeFlag : 1;
    BOOL lockFlag : 1;

    u16 volume;
    u8 pan;
    u8 pad_;

    SNDEnvStatus envStatus;
} SNDChannelInfo;
typedef struct SNDPlayerInfo {
    BOOL activeFlag : 1;
    BOOL pauseFlag : 1;

    u16 trackBitMask;
    u16 tempo;
    u8 volume;
    u8 pad_;
    u16 pad2_;
} SNDPlayerInfo;
typedef struct SNDTrackInfo {
    u16 prgNo;
    u8 volume;
    u8 volume2;
    s8 pitchBend;
    u8 bendRange;
    u8 pan;
    s8 transpose;
    u8 pad_;
    u8 chCount;
    u8 channel[16];
} SNDTrackInfo;
extern SNDSharedWork *SNDi_SharedWork;
extern s16 SND_GetPlayerLocalVariable(int playerNo, int varNo);
extern s16 SND_GetPlayerGlobalVariable(int varNo);
extern u32 SND_GetPlayerTickCounter(int playerNo);
extern u32 SND_GetPlayerStatus(void);
extern u32 SND_GetChannelStatus(void);
extern u32 SND_GetCaptureStatus(void);
extern BOOL SND_ReadChannelInfo(const SNDDriverInfo *driverInfo, int chNo, SNDChannelInfo *chInfo);
extern BOOL SND_ReadPlayerInfo(const SNDDriverInfo *driverInfo, int playerNo, SNDPlayerInfo *playerInfo);
extern BOOL SND_ReadTrackInfo(const SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);
extern u32 SNDi_GetFinishedCommandTag(void);
extern void SNDi_InitSharedWork(SNDSharedWork *work);
typedef struct SNDBinaryFileHeader {
    char signature[4];
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} SNDBinaryFileHeader;
typedef struct SNDBinaryBlockHeader {
    u32 kind;
    u32 size;
} SNDBinaryBlockHeader;
struct SNDWaveArc;
struct SNDExChannel;
typedef enum SNDInstType {
    SND_INST_INVALID = 0,

    SND_INST_PCM = 0x01,
    SND_INST_PSG,
    SND_INST_NOISE,
    SND_INST_DIRECTPCM,
    SND_INST_NULL,

    SND_INST_DRUM_SET = 0x10,
    SND_INST_KEY_SPLIT
} SNDInstType;
typedef struct SNDWaveArcLink {
    struct SNDWaveArc *waveArc;
    struct SNDWaveArcLink *next;
} SNDWaveArcLink;
typedef struct SNDWaveArc {
    struct SNDBinaryFileHeader fileHeader;
    struct SNDBinaryBlockHeader blockHeader;

    struct SNDWaveArcLink *topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 waveOffset[0];
} SNDWaveArc;
typedef struct SNDWaveData {
    struct SNDWaveParam param;
    u8 samples[0];
} SNDWaveData;
typedef struct SNDBankData {
    struct SNDBinaryFileHeader fileHeader;
    struct SNDBinaryBlockHeader blockHeader;

    struct SNDWaveArcLink waveArcLink[4];
    u32 instCount;
    u32 instOffset[0];
} SNDBankData;
typedef struct SNDInstParam {
    u16 wave[2];
    u8 original_key;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 pan;
} SNDInstParam;
typedef struct SNDInstData {
    u8 type;
    u8 padding_;

    struct SNDInstParam param;
} SNDInstData;
typedef struct SNDKeySplit {
    u8 key[8];
    struct SNDInstData instOffset[0];
} SNDKeySplit;
typedef struct SNDDrumSet {
    u8 min;
    u8 max;
    struct SNDInstData instOffset[0];
} SNDDrumSet;
typedef struct SNDInstPos {
    u32 prgNo;
    u32 index;
} SNDInstPos;
extern void SND_AssignWaveArc(struct SNDBankData *bank, int index, struct SNDWaveArc *waveArc);
extern void SND_DestroyBank(struct SNDBankData *bank);
extern void SND_DestroyWaveArc(struct SNDWaveArc *waveArc);
extern BOOL SND_ReadInstData(const struct SNDBankData *bank, int prgNo, int key, struct SNDInstData *inst);
extern BOOL SND_WriteInstData(struct SNDBankData *bank, int prgNo, int key, const struct SNDInstData *inst);
extern struct SNDInstPos SND_GetFirstInstDataPos(const struct SNDBankData *bank);
extern BOOL SND_GetNextInstData(const struct SNDBankData *bank, struct SNDInstData *inst, struct SNDInstPos *pos);
extern u32 SND_GetWaveDataCount(const struct SNDWaveArc *waveArc);
extern void SND_SetWaveDataAddress(struct SNDWaveArc *waveArc, int index, const SNDWaveData *address);
extern const SNDWaveData *SND_GetWaveDataAddress(const struct SNDWaveArc *waveArc, int index);
struct SNDBankData;
typedef struct SNDMidiChannel {
    struct SNDExChannel *chp;
    u8 key;
    u8 pad1;
    u16 pad2;
} SNDMidiChannel;
typedef struct SNDMidiTrack {
    struct SNDMidiChannel channels[16];
    SNDLfoParam mod;

    s16 sweep_pitch;

    u16 prgNo;
    s8 pitchbend;

    u8 porta_time;
    u8 volume;
    s8 pan;
    u8 expression;
    s8 transpose;
    u8 prio;
    u8 bendrange;
    u8 porta_flag;
    u8 porta_key;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
} SNDMidiTrack;
typedef struct SNDMidiPlayer {
    const struct SNDBankData *bank;
    SNDMidiTrack track[16];

    u8 main_volume;
    u8 prio;
    u16 pad;
} SNDMidiPlayer;
extern const s16 SNDi_DecibelTable[128];
extern const s16 SNDi_DecibelSquareTable[128];
static inline s16 SND_CalcDecibel(int scale) {
    return SNDi_DecibelTable[scale];
}
static inline s16 SND_CalcDecibelSquare(int scale) {
    return SNDi_DecibelSquareTable[scale];
}
extern u16 SND_CalcTimer(int orgTimer, int pitch);
extern u16 SND_CalcChannelVolume(int dB);
static inline u16 PAD_Read(void) {
    return (u16) ((((*(REGType16v *) 0x4000130) | *(vu16 *) (0x02000000 + 0x007FFFA8)) ^
                   ((0x0010 | 0x0020 | 0x0040 | 0x0080) |
                    (0x0001 | 0x0002 | 0x0008 | 0x0004 | 0x0100 | 0x0200 | 0x0400 | 0x0800 | 0x2000))) &
                  ((0x0010 | 0x0020 | 0x0040 | 0x0080) |
                   (0x0001 | 0x0002 | 0x0008 | 0x0004 | 0x0100 | 0x0200 | 0x0400 | 0x0800 | 0x2000)));
}
static inline BOOL PAD_DetectFold(void) {
    return (BOOL) ((*(vu16 *) (0x02000000 + 0x007FFFA8) & 0x8000) >> 15);
}
typedef enum SPIDeviceType {
    SPI_DEVICE_TYPE_TP = 0,
    SPI_DEVICE_TYPE_NVRAM,
    SPI_DEVICE_TYPE_MIC,
    SPI_DEVICE_TYPE_PM,
    SPI_DEVICE_TYPE_ARM7,
    SPI_DEVICE_TYPE_MAX
} SPIDeviceType;
typedef enum SPITpTouch {
    SPI_TP_TOUCH_OFF = 0,
    SPI_TP_TOUCH_ON
} SPITpTouch;
typedef enum SPITpValidity {
    SPI_TP_VALIDITY_VALID = 0,
    SPI_TP_VALIDITY_INVALID_X,
    SPI_TP_VALIDITY_INVALID_Y,
    SPI_TP_VALIDITY_INVALID_XY
} SPITpValidity;
typedef union SPITpData {
    struct {
        u32 x : 12;
        u32 y : 12;
        u32 touch : 1;
        u32 validity : 2;
        u32 dummy : 5;

    } e;
    u32 raw;
    u8 bytes[4];
    u16 halfs[2];

} SPITpData;
typedef u32 PMWakeUpTrigger;
typedef u32 PMLogic;
enum {
    PM_UTIL_DUMMY = 0,
    PM_UTIL_LED_ON,
    PM_UTIL_LED_BLINK_HIGH_SPEED,
    PM_UTIL_LED_BLINK_LOW_SPEED,
    PM_UTIL_LCD1_BACKLIGHT_ON,
    PM_UTIL_LCD1_BACKLIGHT_OFF,
    PM_UTIL_LCD2_BACKLIGHT_ON,
    PM_UTIL_LCD2_BACKLIGHT_OFF,
    PM_UTIL_LCD12_BACKLIGHT_ON,
    PM_UTIL_LCD12_BACKLIGHT_OFF,
    PM_UTIL_SOUND_POWER_ON,
    PM_UTIL_SOUND_POWER_OFF,
    PM_UTIL_SOUND_VOL_CTRL_ON,
    PM_UTIL_SOUND_VOL_CTRL_OFF,
    PM_UTIL_FORCE_POWER_OFF,
    PM_UTIL_FORCE_POWER_ON
};
typedef enum {
    PM_LED_PATTERN_NONE       = 0,
    PM_LED_PATTERN_ON         = 1,
    PM_LED_PATTERN_BLINK_LOW  = 2,
    PM_LED_PATTERN_BLINK_HIGH = 3,
    PM_LED_PATTERN_BLINK1     = 4,
    PM_LED_PATTERN_BLINK2     = 5,
    PM_LED_PATTERN_BLINK3     = 6,
    PM_LED_PATTERN_BLINK4     = 7,
    PM_LED_PATTERN_BLINK5     = 8,
    PM_LED_PATTERN_BLINK6     = 9,
    PM_LED_PATTERN_BLINK8     = 10,
    PM_LED_PATTERN_BLINK10    = 11,
    PM_LED_PATTERN_PATTERN1   = 12,
    PM_LED_PATTERN_PATTERN2   = 13,
    PM_LED_PATTERN_PATTERN3   = 14,
    PM_LED_PATTERN_WIRELESS   = 15
} PMLEDPattern;
typedef enum {
    PM_LED_NONE       = 0,
    PM_LED_ON         = 1,
    PM_LED_BLINK_LOW  = 2,
    PM_LED_BLINK_HIGH = 3
} PMLEDStatus;
typedef enum MICResult {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR,
    MIC_RESULT_MAX
} MICResult;
typedef enum MICSamplingType {
    MIC_SAMPLING_TYPE_8BIT = 0,
    MIC_SAMPLING_TYPE_12BIT,
    MIC_SAMPLING_TYPE_SIGNED_8BIT,
    MIC_SAMPLING_TYPE_SIGNED_12BIT,
    MIC_SAMPLING_TYPE_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_MAX
} MICSamplingType;
typedef enum MICSamplingRate {
    MIC_SAMPLING_RATE_8K    = (33513982 / 8000),
    MIC_SAMPLING_RATE_11K   = (33513982 / 11025),
    MIC_SAMPLING_RATE_16K   = (33513982 / 16000),
    MIC_SAMPLING_RATE_22K   = (33513982 / 22050),
    MIC_SAMPLING_RATE_32K   = (33513982 / 32000),
    MIC_SAMPLING_RATE_LIMIT = 1024
} MICSamplingRate;
typedef void (*MICCallback)(MICResult result, void *arg);
typedef struct MICAutoParam {
    MICSamplingType type;
    void *buffer;
    u32 size;
    u32 rate;
    BOOL loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;
extern void MIC_Init(void);
extern void *MIC_GetLastSamplingAddress(void);
typedef void (*PMCallback)(u32 result, void *arg);
typedef void (*PMSleepCallback)(void *);
typedef enum {
    PM_LCD_TOP    = 0,
    PM_LCD_BOTTOM = 1,
    PM_LCD_ALL    = 2
} PMLCDTarget;
typedef enum {
    PM_BACKLIGHT_OFF = 0,
    PM_BACKLIGHT_ON  = 1
} PMBackLightSwitch;
typedef enum {
    PM_BATTERY_HIGH = 0,
    PM_BATTERY_LOW  = 1
} PMBattery;
typedef enum {
    PM_AMP_OFF = 0,
    PM_AMP_ON  = 1
} PMAmpSwitch;
typedef enum {
    PM_AMPGAIN_20      = 0,
    PM_AMPGAIN_40      = 1,
    PM_AMPGAIN_80      = 2,
    PM_AMPGAIN_160     = 3,
    PM_AMPGAIN_DEFAULT = PM_AMPGAIN_40
} PMAmpGain;
typedef enum {
    PM_LCD_POWER_OFF = 0,
    PM_LCD_POWER_ON  = 1
} PMLCDPower;
typedef enum {
    PM_SOUND_POWER_OFF = 0,
    PM_SOUND_POWER_ON  = 1
} PMSoundPowerSwitch;
typedef enum {
    PM_SOUND_VOLUME_OFF = 0,
    PM_SOUND_VOLUME_ON  = 1
} PMSoundVolumeSwitch;
typedef struct {
    u16 flag;
    u16 padding;
    u16 *buffer;
} PMData16;
typedef struct PMiSleepCallbackInfo PMSleepCallbackInfo;
struct PMiSleepCallbackInfo {
    PMSleepCallback callback;
    void *arg;
    PMSleepCallbackInfo *next;
};
extern void PM_Init(void);
extern u32 PM_SendUtilityCommandAsync(u32 number, PMCallback callback, void *arg);
extern u32 PM_SendUtilityCommand(u32 number);
extern u32 PM_SetBackLightAsync(PMLCDTarget target, PMBackLightSwitch sw, PMCallback callback, void *arg);
extern u32 PM_SetBackLight(PMLCDTarget target, PMBackLightSwitch status);
extern u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg);
extern u32 PM_ForceToPowerOff(void);
extern u32 PM_SetAmpAsync(PMAmpSwitch sw, PMCallback callback, void *arg);
extern u32 PM_SetAmp(PMAmpSwitch sw);
extern u32 PM_SetAmpGainAsync(PMAmpGain gain, PMCallback callback, void *arg);
extern u32 PM_SetAmpGain(PMAmpGain gain);
extern u32 PM_GetBattery(PMBattery *batteryBuf);
extern u32 PM_GetBackLight(PMBackLightSwitch *top, PMBackLightSwitch *bottom);
extern u32 PM_GetAmp(PMAmpSwitch *swBuf);
extern u32 PM_GetAmpGain(PMAmpGain *gainBuf);
extern void PM_GoSleepMode(PMWakeUpTrigger trigger, PMLogic logic, u16 keyPattern);
extern void PM_AppendPreSleepCallback(PMSleepCallbackInfo *info);
extern void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info);
extern void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info);
extern void PM_PrependPostSleepCallback(PMSleepCallbackInfo *info);
extern void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info);
extern void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info);
extern BOOL PM_SetLCDPower(PMLCDPower sw);
extern PMLCDPower PM_GetLCDPower(void);
extern u32 PMi_SendLEDPatternCommandAsync(PMLEDPattern pattern, PMCallback callback, void *arg);
extern u32 PMi_SendLEDPatternCommand(PMLEDPattern pattern);
extern u32 PM_GetLEDPatternAsync(PMLEDPattern *patternBuf, PMCallback callback, void *arg);
extern u32 PM_GetLEDPattern(PMLEDPattern *patternBuf);
extern BOOL PMi_SetLCDPower(PMLCDPower sw, PMLEDStatus led, BOOL skip, BOOL isSync);
extern u32 PMi_SetSoundPowerAsync(PMSoundPowerSwitch sw, PMCallback callback, void *arg);
extern u32 PMi_SetSoundPower(PMSoundPowerSwitch sw);
extern u32 PMi_SetSoundVolumeAsync(PMSoundVolumeSwitch sw, PMCallback callback, void *arg);
extern u32 PMi_SetSoundVolume(PMSoundVolumeSwitch sw);
extern u32 PMi_GetSoundPower(PMSoundPowerSwitch *swBuf);
extern u32 PMi_GetSoundVolume(PMSoundVolumeSwitch *swBuf);
extern void PMi_SendPxiData(u32 data);
extern void PMi_CommonCallback(PXIFifoTag tag, u32 data, BOOL err);
extern u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData);
extern u32 PMi_DisposeSleepEnd(void);
extern u32 PMi_ReadRegisterAsync(u16 registerAddr, u16 *buffer, PMCallback callback, void *arg);
extern u32 PMi_ReadRegister(u16 registerAddr, u16 *buffer);
extern u32 PMi_WriteRegisterAsync(u16 registerAddr, u16 data, PMCallback callback, void *arg);
extern u32 PMi_WriteRegister(u16 registerAddr, u16 data);
extern u32 PMi_SetLEDAsync(PMLEDStatus status, PMCallback callback, void *arg);
extern u32 PMi_SetLED(PMLEDStatus status);
extern u32 PMi_GetLCDOffCount(void);
static inline void PM_SetSleepCallbackInfo(PMSleepCallbackInfo *info, PMSleepCallback callback, void *arg) {
    info->callback = callback;
    info->arg      = arg;
}
static inline u32 PM_SetLEDPatternAsync(PMLEDPattern pattern, PMCallback callback, void *arg) {
    return PMi_SendLEDPatternCommandAsync(pattern, callback, arg);
}
static inline u32 PM_SetLEDPattern(PMLEDPattern pattern) {
    return PMi_SendLEDPatternCommand(pattern);
}
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
typedef enum {
    TP_STATE_READY = 0,
    TP_STATE_SAMPLING,
    TP_STATE_AUTO_SAMPLING,
    TP_STATE_AUTO_WAIT_END
} TPState;
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;
typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;
typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);
extern void TP_Init(void);
extern BOOL TP_GetUserInfo(TPCalibrateParam *calibrate);
extern void TP_SetCalibrateParam(const TPCalibrateParam *param);
extern void TP_SetCallback(TPRecvCallback callback);
extern void TP_RequestSamplingAsync(void);
extern u32 TP_WaitRawResult(TPData *result);
extern u32 TP_GetCalibratedResult(TPData *result);
extern u32 TP_WaitCalibratedResult(TPData *result);
extern void TP_RequestAutoSamplingStartAsync(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_RequestSetStabilityAsync(u8 retry, u16 range);
extern void TP_GetLatestRawPointInAuto(TPData *result);
extern void TP_GetLatestCalibratedPointInAuto(TPData *result);
extern u16 TP_GetLatestIndexInAuto(void);
extern u32 TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2,
                                 u16 dx2, u16 dy2);
extern void TP_GetCalibratedPoint(TPData *disp, const TPData *raw);
extern void TP_GetUnCalibratedPoint(u16 *raw_x, u16 *raw_y, u16 dx, u16 dy);
extern void TP_WaitBusy(TPRequestCommandFlag command_flgs);
extern void TP_WaitAllBusy(void);
extern u32 TP_CheckBusy(TPRequestCommandFlag command_flgs);
extern u32 TP_CheckError(TPRequestCommandFlag command_flgs);
static inline u32 TP_RequestSetStability(u8 retry, u16 range) {
    TP_RequestSetStabilityAsync(retry, range);
    TP_WaitBusy(TP_REQUEST_COMMAND_FLAG_SET_STABILITY);
    return TP_CheckError(TP_REQUEST_COMMAND_FLAG_SET_STABILITY);
}
static inline u32 TP_RequestAutoSamplingStart(u16 vcount, u16 frequence, TPData samplingBufs[], u16 bufSize) {
    TP_RequestAutoSamplingStartAsync(vcount, frequence, samplingBufs, bufSize);
    TP_WaitBusy(TP_REQUEST_COMMAND_FLAG_AUTO_ON);
    return TP_CheckError(TP_REQUEST_COMMAND_FLAG_AUTO_ON);
}
static inline u32 TP_RequestAutoSamplingStop(void) {
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(TP_REQUEST_COMMAND_FLAG_AUTO_OFF);
    return TP_CheckError(TP_REQUEST_COMMAND_FLAG_AUTO_OFF);
}
static inline u32 TP_RequestRawSampling(TPData *result) {
    TP_RequestSamplingAsync();
    return TP_WaitRawResult(result);
}
static inline u32 TP_RequestCalibratedSampling(TPData *result) {
    TP_RequestSamplingAsync();
    return TP_WaitCalibratedResult(result);
}
typedef enum {
    CARD_RESULT_SUCCESS = 0,
    CARD_RESULT_FAILURE,
    CARD_RESULT_INVALID_PARAM,
    CARD_RESULT_UNSUPPORTED,
    CARD_RESULT_TIMEOUT,
    CARD_RESULT_ERROR,
    CARD_RESULT_NO_RESPONSE,
    CARD_RESULT_CANCELED
} CARDResult;
typedef enum {
    CARD_BACKUP_TYPE_EEPROM_4KBITS   = (((1) << 0) | ((9) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_EEPROM_64KBITS  = (((1) << 0) | ((13) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_EEPROM_512KBITS = (((1) << 0) | ((16) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_FLASH_2MBITS    = (((2) << 0) | ((18) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_FLASH_4MBITS    = (((2) << 0) | ((19) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_FLASH_8MBITS    = (((2) << 0) | ((20) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_FRAM_256KBITS   = (((3) << 0) | ((15) << 8) | ((0) << 16)),
    CARD_BACKUP_TYPE_NOT_USE         = 0
} CARDBackupType;
typedef enum {
    CARD_REQ_INIT = 0,
    CARD_REQ_ACK,
    CARD_REQ_IDENTIFY,
    CARD_REQ_READ_ID,
    CARD_REQ_READ_ROM,
    CARD_REQ_WRITE_ROM,
    CARD_REQ_READ_BACKUP,
    CARD_REQ_WRITE_BACKUP,
    CARD_REQ_PROGRAM_BACKUP,
    CARD_REQ_VERIFY_BACKUP,
    CARD_REQ_ERASE_PAGE_BACKUP,
    CARD_REQ_ERASE_SECTOR_BACKUP,
    CARD_REQ_ERASE_CHIP_BACKUP,
    CARD_REQ_MAX
} CARDRequest;
typedef enum {
    CARD_REQUEST_MODE_RECV,
    CARD_REQUEST_MODE_SEND,
    CARD_REQUEST_MODE_SEND_VERIFY,
    CARD_REQUEST_MODE_SPECIAL
} CARDRequestMode;
extern void CARD_Init(void);
extern BOOL CARD_IsAvailable(void);
extern BOOL CARD_IsEnabled(void);
extern void CARD_CheckEnabled(void);
extern void func_0200c7c4(BOOL enable);
extern u32 CARD_GetThreadPriority(void);
extern u32 CARD_SetThreadPriority(u32 prior);
extern CARDResult CARD_GetResultCode(void);
extern const u8 *CARD_GetRomHeader(void);
extern void CARD_GetCacheFlushThreshold(u32 *icache, u32 *dcache);
extern void CARD_SetCacheFlushThreshold(u32 icache, u32 dcache);
extern BOOL CARD_IdentifyBackup(CARDBackupType type);
extern u32 CARD_GetBackupTotalSize(void);
extern u32 CARD_GetBackupSectorSize(void);
extern u32 CARD_GetBackupPageSize(void);
extern CARDBackupType CARD_GetCurrentBackupType(void);
extern void CARD_LockBackup(u16 lock_id);
extern void CARD_UnlockBackup(u16 lock_id);
extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARD_WaitBackupAsync(void);
extern void CARD_CancelBackupAsync(void);
extern BOOL CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async,
                                       CARDRequest req_type, int req_retry, CARDRequestMode req_mode);
extern BOOL CARDi_RequestWriteSectorCommand(u32 src, u32 dst, u32 len, BOOL verify, MIDmaCallback callback, void *arg,
                                            BOOL is_async);
static inline BOOL CARDi_ReadBackup(u32 src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_READ_BACKUP, 1,
                                      CARD_REQUEST_MODE_RECV);
}
static inline BOOL CARDi_ProgramBackup(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_PROGRAM_BACKUP, 10,
                                      CARD_REQUEST_MODE_SEND);
}
static inline BOOL CARDi_WriteBackup(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_WRITE_BACKUP, 10,
                                      CARD_REQUEST_MODE_SEND);
}
static inline BOOL CARDi_VerifyBackup(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_VERIFY_BACKUP, 1,
                                      CARD_REQUEST_MODE_SEND);
}
static inline BOOL CARDi_ProgramAndVerifyBackup(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg,
                                                BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_PROGRAM_BACKUP, 10,
                                      CARD_REQUEST_MODE_SEND_VERIFY);
}
static inline BOOL CARDi_WriteAndVerifyBackup(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg,
                                              BOOL is_async) {
    return CARDi_RequestStreamCommand((u32) src, (u32) dst, len, callback, arg, is_async, CARD_REQ_WRITE_BACKUP, 10,
                                      CARD_REQUEST_MODE_SEND_VERIFY);
}
static inline BOOL CARDi_EraseBackupSector(u32 dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand(0, (u32) dst, len, callback, arg, is_async, CARD_REQ_ERASE_SECTOR_BACKUP, 10,
                                      CARD_REQUEST_MODE_SPECIAL);
}
static inline BOOL CARDi_EraseBackupChip(MIDmaCallback callback, void *arg, BOOL is_async) {
    return CARDi_RequestStreamCommand(0, 0, 0, callback, arg, is_async, CARD_REQ_ERASE_CHIP_BACKUP, 1,
                                      CARD_REQUEST_MODE_SPECIAL);
}
static inline void CARD_ReadBackupAsync(u32 src, void *dst, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_ReadBackup(src, dst, len, callback, arg, 1);
}
static inline BOOL CARD_ReadBackup(u32 src, void *dst, u32 len) {
    return CARDi_ReadBackup(src, dst, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_ProgramBackupAsync(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_ProgramBackup(dst, src, len, callback, arg, 1);
}
static inline BOOL CARD_ProgramBackup(u32 dst, const void *src, u32 len) {
    return CARDi_ProgramBackup(dst, src, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_WriteBackupAsync(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_WriteBackup(dst, src, len, callback, arg, 1);
}
static inline BOOL CARD_WriteBackup(u32 dst, const void *src, u32 len) {
    return CARDi_WriteBackup(dst, src, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_VerifyBackupAsync(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_VerifyBackup(dst, src, len, callback, arg, 1);
}
static inline BOOL CARD_VerifyBackup(u32 dst, const void *src, u32 len) {
    return CARDi_VerifyBackup(dst, src, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_ProgramAndVerifyBackupAsync(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_ProgramAndVerifyBackup(dst, src, len, callback, arg, 1);
}
static inline BOOL CARD_ProgramAndVerifyBackup(u32 dst, const void *src, u32 len) {
    return CARDi_ProgramAndVerifyBackup(dst, src, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_WriteAndVerifyBackupAsync(u32 dst, const void *src, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_WriteAndVerifyBackup(dst, src, len, callback, arg, 1);
}
static inline BOOL CARD_WriteAndVerifyBackup(u32 dst, const void *src, u32 len) {
    return CARDi_WriteAndVerifyBackup(dst, src, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_EraseBackupSectorAsync(u32 dst, u32 len, MIDmaCallback callback, void *arg) {
    (void) CARDi_EraseBackupSector(dst, len, callback, arg, 1);
}
static inline BOOL CARD_EraseBackupSector(u32 dst, u32 len) {
    return CARDi_EraseBackupSector(dst, len, ((void *) 0), ((void *) 0), 0);
}
static inline void CARD_EraseBackupChipAsync(MIDmaCallback callback, void *arg) {
    (void) CARDi_EraseBackupChip(callback, arg, 1);
}
static inline BOOL CARD_EraseBackupChip(void) {
    return CARDi_EraseBackupChip(((void *) 0), ((void *) 0), 0);
}
typedef struct {
    u32 offset;
    u32 length;
} CARDRomRegion;
typedef struct {
    char game_name[12];
    u32 game_code;
    u16 maker_code;
    u8 product_id;
    u8 device_type;
    u8 device_size;
    u8 reserved_A[9];
    u8 game_version;
    u8 property;

    void *main_rom_offset;
    void *main_entry_address;
    void *main_ram_address;
    u32 main_size;
    void *sub_rom_offset;
    void *sub_entry_address;
    void *sub_ram_address;
    u32 sub_size;

    CARDRomRegion fnt;
    CARDRomRegion fat;

    CARDRomRegion main_ovt;
    CARDRomRegion sub_ovt;

    u8 rom_param_A[8];
    u32 banner_offset;
    u16 secure_crc;
    u8 rom_param_B[2];

    void *main_autoload_done;
    void *sub_autoload_done;

    u8 rom_param_C[8];
    u32 rom_size;
    u32 header_size;
    u8 reserved_B[0x38];

    u8 logo_data[0x9C];
    u16 logo_crc;
    u16 header_crc;

} CARDRomHeader;
extern void CARD_LockRom(u16 lock_id);
extern void CARD_UnlockRom(u16 lock_id);
extern void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async);
extern void CARD_WaitRomAsync(void);
extern BOOL CARD_TryWaitRomAsync(void);
extern u32 CARDi_ReadRomID(void);
static inline const CARDRomRegion *CARD_GetRomRegionFNT(void) {
    return (const CARDRomRegion *) ((const u8 *) (0x02000000 + 0x007ffe00) + 0x40);
}
static inline const CARDRomRegion *CARD_GetRomRegionFAT(void) {
    return (const CARDRomRegion *) ((const u8 *) (0x02000000 + 0x007ffe00) + 0x48);
}
static inline const CARDRomRegion *CARD_GetRomRegionOVT(MIProcessor target) {
    return (target == MI_PROCESSOR_ARM9) ? (const CARDRomRegion *) ((const u8 *) (0x02000000 + 0x007ffe00) + 0x50)
                                         : (const CARDRomRegion *) ((const u8 *) (0x02000000 + 0x007ffe00) + 0x58);
}
static inline void CARD_ReadRomAsync(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg) {
    CARDi_ReadRom(dma, src, dst, len, callback, arg, 1);
}
static inline void CARD_ReadRom(u32 dma, const void *src, void *dst, u32 len) {
    CARDi_ReadRom(dma, src, dst, len, ((void *) 0), ((void *) 0), 0);
}
typedef BOOL (*CARDPulledOutCallback)(void);
extern void CARD_InitPulledOutCallback(void);
extern void CARD_SetPulledOutCallback(CARDPulledOutCallback callback);
extern void CARD_TerminateForPulledOut(void);
extern void CARD_CheckPulledOut(void);
extern BOOL CARD_IsPulledOut(void);
struct FSFile;
struct FSArchive;
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
typedef FSResult (*FS_ARCHIVE_READ_FUNC)(struct FSArchive *p, void *dst, size_t pos, size_t size);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive *p, const void *src, size_t pos, size_t size);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(struct FSFile *, FSCommandType);
typedef struct {
    struct FSFile *prev;
    struct FSFile *next;
} FSFileLink;
typedef struct {
    u32 start;
    u16 index;
    u16 parent;
} FSArchiveFNT;
typedef struct {
    u32 top;
    u32 bottom;
} FSArchiveFAT;
typedef struct FSArchive {
    union {
        char ptr[4];
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
static inline BOOL FS_IsArchiveLoaded(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000002) ? 1 : 0;
}
static inline u32 FS_GetArchiveOffset(const FSArchive *p_arc, u32 pos) {
    return p_arc->base + pos;
}
static inline BOOL FSi_IsArchiveCanceling(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000020) != 0;
}
static inline BOOL FS_IsArchiveSuspended(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000008) ? 1 : 0;
}
static inline BOOL FSi_IsArchiveSuspending(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000040) != 0;
}
static inline BOOL FSi_IsArchiveRunning(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000010) != 0;
}
static inline BOOL FSi_IsArchiveUnloading(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000080) != 0;
}
static inline BOOL FSi_IsArchiveAsync(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000100) != 0;
}
static inline BOOL FSi_IsArchiveSync(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000200) != 0;
}
static inline BOOL FS_IsArchiveTableLoaded(volatile const FSArchive *p_arc) {
    return (p_arc->flag & 0x00000004) ? 1 : 0;
}
extern void FS_InitArchive(FSArchive *p_arc);
extern FSArchive *FS_FindArchive(const char *name, int name_len);
extern BOOL FS_RegisterArchiveName(FSArchive *p_arc, const char *name, u32 name_len);
extern void FS_ReleaseArchiveName(FSArchive *p_arc);
extern BOOL FS_LoadArchive(FSArchive *p_arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                           FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);
extern BOOL FS_UnloadArchive(FSArchive *p_arc);
extern u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size);
extern void *FS_UnloadArchiveTables(FSArchive *p_arc);
extern BOOL FS_SuspendArchive(FSArchive *p_arc);
extern BOOL FS_ResumeArchive(FSArchive *p_arc);
extern void FS_SetArchiveProc(struct FSArchive *p_arc, FS_ARCHIVE_PROC_FUNC proc, u32 flags);
extern void FS_NotifyArchiveAsyncEnd(FSArchive *p_arc, FSResult ret);
extern void FSi_EndArchive(void);
typedef enum FSSeekFileMode {
    FS_SEEK_SET = 0,
    FS_SEEK_CUR,
    FS_SEEK_END
} FSSeekFileMode;
struct FSFile;
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
extern void FS_Init(u32 default_dma_no);
extern BOOL FS_IsAvailable(void);
extern void FS_End(void);
extern u32 FS_GetDefaultDMA(void);
extern u32 FS_SetDefaultDMA(u32 dma_no);
extern u32 FS_TryLoadTable(void *p_mem, u32 size);
extern void FS_InitFile(FSFile *p_file);
extern BOOL FS_OpenFile(FSFile *p_file, const char *path);
extern BOOL FS_OpenFileFast(FSFile *p_file, FSFileID file_id);
extern BOOL FS_ConvertPathToFileID(FSFileID *p_file_id, const char *path);
extern BOOL FS_CloseFile(FSFile *p_file);
extern BOOL FS_GetPathName(FSFile *p_file, char *buf, u32 len);
extern s32 FS_GetPathLength(FSFile *p_file);
extern s32 FS_ReadFile(FSFile *p_file, void *dst, s32 len);
extern s32 FS_ReadFileAsync(FSFile *p_file, void *dst, s32 len);
extern s32 FS_WriteFile(FSFile *p_file, const void *src, s32 len);
extern s32 FS_WriteFileAsync(FSFile *p_file, const void *src, s32 len);
extern BOOL FS_WaitAsync(FSFile *p_file);
extern void FS_CancelFile(FSFile *p_file);
extern BOOL FS_SeekFile(FSFile *p_file, s32 offset, FSSeekFileMode origin);
extern BOOL FS_ChangeDir(const char *path);
extern BOOL FS_FindDir(FSFile *p_dir, const char *path);
extern BOOL FS_ReadDir(FSFile *p_dir, FSDirEntry *p_entry);
extern BOOL FS_TellDir(const FSFile *p_dir, FSDirPos *p_pos);
extern BOOL FS_SeekDir(FSFile *p_dir, const FSDirPos *p_pos);
extern BOOL FS_RewindDir(FSFile *p_dir);
extern BOOL FS_OpenFileDirect(FSFile *p_file, FSArchive *p_arc, u32 image_top, u32 image_bottom, u32 file_index);
extern BOOL FS_CreateFileFromRom(FSFile *p_file, u32 offset, u32 size);
extern BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size);
static inline u32 FS_GetTableSize(void) {
    return FS_TryLoadTable(((void *) 0), 0);
}
static inline BOOL FS_LoadTable(void *p_mem, u32 size) {
    return (FS_TryLoadTable(p_mem, size) <= size) ? 1 : 0;
}
static inline void *FS_UnloadTable(void) {
    FSArchive *const p_arc = FS_FindArchive("rom", 3);
    return FS_UnloadArchiveTables(p_arc);
}
static inline BOOL FS_IsBusy(volatile const FSFile *p_file) {
    return p_file->stat & 0x00000001 ? 1 : 0;
}
static inline BOOL FS_IsCanceling(volatile const FSFile *p_file) {
    return (p_file->stat & 0x00000002) ? 1 : 0;
}
static inline BOOL FS_IsSucceeded(volatile const FSFile *p_file) {
    return (p_file->error == FS_RESULT_SUCCESS) ? 1 : 0;
}
static inline BOOL FS_IsFile(volatile const FSFile *p_file) {
    return (p_file->stat & 0x00000010) ? 1 : 0;
}
static inline BOOL FS_IsDir(volatile const FSFile *p_file) {
    return (p_file->stat & 0x00000020) ? 1 : 0;
}
static inline BOOL FS_IsFileSyncMode(const volatile FSFile *p) {
    return (p->stat & 0x00000004) ? 1 : 0;
}
static inline FSResult FS_GetResultCode(volatile const FSFile *p_file) {
    return p_file->error;
}
static inline u32 FS_GetLength(const FSFile *p_file) {
    return p_file->prop.file.bottom - p_file->prop.file.top;
}
static inline u32 FS_GetPosition(const FSFile *p_file) {
    return p_file->prop.file.pos - p_file->prop.file.top;
}
static inline BOOL FS_SeekFileToBegin(FSFile *p_file) {
    return FS_SeekFile(p_file, 0, FS_SEEK_SET);
}
static inline BOOL FS_SeekFileToEnd(FSFile *p_file) {
    return FS_SeekFile(p_file, 0, FS_SEEK_END);
}
static inline FSArchive *FS_GetAttachedArchive(const FSFile *p_file) {
    return p_file->arc;
}
static inline u32 const FS_GetFileImageTop(const FSFile *p_file) {
    return p_file->prop.file.top;
}
static inline u32 FS_GetFileImageBottom(const FSFile *p_file) {
    return p_file->prop.file.bottom;
}
typedef u32 FSOverlayID;
typedef void (*FSOverlayInitFunc)(void);
typedef struct FSOverlayInfoHeader {
    u32 id;
    u8 *ram_address;
    u32 ram_size;
    u32 bss_size;
    FSOverlayInitFunc *sinit_init;
    FSOverlayInitFunc *sinit_init_end;
    u32 file_id;
    u32 compressed : 24;
    u32 flag : 8;
} FSOverlayInfoHeader;
typedef struct FSOverlayInfo {
    FSOverlayInfoHeader header;
    MIProcessor target;
    CARDRomRegion file_pos;
} FSOverlayInfo;
static inline u8 *const FS_GetOverlayAddress(FSOverlayInfo *p_ovi) {
    return p_ovi->header.ram_address;
}
static inline u32 const FS_GetOverlayImageSize(FSOverlayInfo *p_ovi) {
    return p_ovi->header.ram_size;
}
static inline u32 const FS_GetOverlayTotalSize(FSOverlayInfo *p_ovi) {
    return p_ovi->header.ram_size + p_ovi->header.bss_size;
}
extern void FS_ClearOverlayImage(FSOverlayInfo *p_ovi);
extern FSFileID FS_GetOverlayFileID(const FSOverlayInfo *p_ovi);
extern BOOL FSi_LoadOverlayInfoCore(FSOverlayInfo *p_ovi, MIProcessor target, FSOverlayID id, FSArchive *arc, u32 offset_arm9,
                                    u32 len_arm9, u32 offset_arm7, u32 len_arm7);
extern BOOL FS_LoadOverlayInfo(FSOverlayInfo *p_ovi, MIProcessor target, FSOverlayID id);
extern BOOL FS_LoadOverlayImageAsync(FSOverlayInfo *p_ovi, FSFile *p_file);
extern BOOL FS_LoadOverlayImage(FSOverlayInfo *p_ovi);
extern void FS_StartOverlay(FSOverlayInfo *p_ovi);
extern void FS_EndOverlay(FSOverlayInfo *p_ovi);
extern BOOL FS_UnloadOverlayImage(FSOverlayInfo *p_ovi);
extern BOOL FS_LoadOverlay(MIProcessor target, FSOverlayID id);
extern BOOL FS_UnloadOverlay(MIProcessor target, FSOverlayID id);
extern void FS_AttachOverlayTable(MIProcessor target, const void *ptr, u32 len);
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
typedef enum RTCAlarmChan {
    RTC_ALARM_CHAN_1 = 0,
    RTC_ALARM_CHAN_2,
    RTC_ALARM_CHAN_MAX
} RTCAlarmChan;
typedef enum RTCAlarmStatus {
    RTC_ALARM_STATUS_OFF = 0,
    RTC_ALARM_STATUS_ON,
    RTC_ALARM_STATUS_MAX
} RTCAlarmStatus;
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
typedef struct RTCTimeEx {
    s32 hour;
    s32 minute;
    s32 second;
    s32 millisecond;
} RTCTimeEx;
typedef struct RTCAlarmParam {
    RTCWeek week;
    u32 hour;
    u32 minute;
    u32 enable;
} RTCAlarmParam;
extern void RTC_Init(void);
extern RTCResult RTC_GetDate(RTCDate *date);
extern RTCResult RTC_GetTime(RTCTime *time);
extern RTCResult RTC_GetDateTime(RTCDate *date, RTCTime *time);
extern RTCResult RTC_GetDateTimeExByTick(RTCDate *date, RTCTimeEx *time);
extern RTCResult RTC_SetDate(const RTCDate *date);
extern RTCResult RTC_SetTime(const RTCTime *time);
extern RTCResult RTC_SetDateTime(const RTCDate *date, const RTCTime *time);
extern RTCResult RTC_GetAlarmStatus(RTCAlarmChan chan, RTCAlarmStatus *status);
extern RTCResult RTC_GetAlarmParam(RTCAlarmChan chan, RTCAlarmParam *param);
extern RTCResult RTC_SetAlarmStatus(RTCAlarmChan chan, const RTCAlarmStatus *status);
extern RTCResult RTC_SetAlarmParam(RTCAlarmChan chan, const RTCAlarmParam *param);
extern RTCResult RTC_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg);
extern RTCResult RTC_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg);
extern RTCResult RTC_GetDateTimeAsync(RTCDate *date, RTCTime *time, RTCCallback callback, void *arg);
extern RTCResult RTC_SetDateAsync(const RTCDate *date, RTCCallback callback, void *arg);
extern RTCResult RTC_SetTimeAsync(const RTCTime *time, RTCCallback callback, void *arg);
extern RTCResult RTC_SetDateTimeAsync(const RTCDate *date, const RTCTime *time, RTCCallback callback, void *arg);
extern RTCResult RTC_GetAlarmStatusAsync(RTCAlarmChan chan, RTCAlarmStatus *status, RTCCallback callback, void *arg);
extern RTCResult RTC_GetAlarmParamAsync(RTCAlarmChan chan, RTCAlarmParam *param, RTCCallback callback, void *arg);
extern void RTC_SetAlarmInterrupt(RTCInterrupt interrupt);
extern RTCResult RTC_SetAlarmStatusAsync(RTCAlarmChan chan, const RTCAlarmStatus *status, RTCCallback callback, void *arg);
extern RTCResult RTC_SetAlarmParamAsync(RTCAlarmChan chan, const RTCAlarmParam *param, RTCCallback callback, void *arg);
extern BOOL RTCi_ResetAsync(void);
extern BOOL RTCi_SetHourFormatAsync(void);
extern BOOL RTCi_ReadRawDateTimeAsync(void);
extern BOOL RTCi_WriteRawDateTimeAsync(void);
extern BOOL RTCi_ReadRawDateAsync(void);
extern BOOL RTCi_WriteRawDateAsync(void);
extern BOOL RTCi_ReadRawTimeAsync(void);
extern BOOL RTCi_WriteRawTimeAsync(void);
extern BOOL RTCi_ReadRawPulseAsync(void);
extern BOOL RTCi_WriteRawPulseAsync(void);
extern BOOL RTCi_ReadRawAlarm1Async(void);
extern BOOL RTCi_WriteRawAlarm1Async(void);
extern BOOL RTCi_ReadRawAlarm2Async(void);
extern BOOL RTCi_WriteRawAlarm2Async(void);
extern BOOL RTCi_ReadRawStatus1Async(void);
extern BOOL RTCi_WriteRawStatus1Async(void);
extern BOOL RTCi_ReadRawStatus2Async(void);
extern BOOL RTCi_WriteRawStatus2Async(void);
extern BOOL RTCi_ReadRawAdjustAsync(void);
extern BOOL RTCi_WriteRawAdjustAsync(void);
extern BOOL RTCi_ReadRawFreeAsync(void);
extern BOOL RTCi_WriteRawFreeAsync(void);
extern RTCResult RTCi_SetRegStatus2Async(const RTCRawStatus2 *status2, RTCCallback callback, void *arg);
extern RTCResult RTCi_SetRegAdjustAsync(const RTCRawAdjust *adjust, RTCCallback callback, void *arg);
extern RTCResult RTCi_SetRegAdjust(const RTCRawAdjust *Adjust);
extern RTCResult RTCi_SetRegStatus2(const RTCRawStatus2 *status2);
extern s32 RTC_ConvertDateToDay(const RTCDate *date);
extern s32 RTCi_ConvertTimeToSecond(const RTCTime *time);
extern s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
extern void RTC_ConvertDayToDate(RTCDate *date, s32 day);
extern void RTCi_ConvertSecondToTime(RTCTime *time, s32 sec);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern RTCWeek RTC_GetDayOfWeek(RTCDate *date);
typedef u16 GXRgb;
typedef u16 GXRgba;
typedef u32 VecFx10;
extern u32 GXi_DmaId;
extern void GX_SendFifo48B(register const void *pSrc, register void *pDest);
extern void GX_SendFifo64B(register const void *pSrc, register void *pDest);
extern void GX_SendFifo128B(register const void *pSrc, register void *pDest);
static inline void GX_SendFifo36B(register const void *pSrc, register void *pDest) {
    MI_Copy36B(pSrc, pDest);
}
typedef union {
    u32 raw;
    struct {
        u32 bgMode : 3;
        u32 bg0_2d3d : 1;
        u32 objMapChar : 1;
        u32 objMapBmp : 2;
        u32 blankScr : 1;
        u32 visiblePlane : 5;
        u32 visibleWnd : 3;
        u32 dispMode : 4;
        u32 extObjMapChar : 2;
        u32 extObjMapBmp : 1;
        u32 hBlankObjProc : 1;
        u32 bgCharOffset : 3;
        u32 bgScrOffset : 3;
        u32 bgExtPltt : 1;
        u32 objExtPltt : 1;
    };
} GXDispCnt;
typedef union {
    u32 raw;
    struct {
        u32 bgMode : 3;
        u32 _reserve1 : 1;
        u32 objMapChar : 1;
        u32 objMapBmp : 2;
        u32 blankScr : 1;
        u32 visiblePlane : 5;
        u32 visibleWnd : 3;
        u32 dispMode : 1;
        u32 _reserve2 : 3;
        u32 extObjMapChar : 2;
        u32 _reserve3 : 1;
        u32 hBlankObjProc : 1;
        u32 _reserve4 : 6;
        u32 bgExtPltt : 1;
        u32 objExtPltt : 1;
    };
} GXSDispCnt;
typedef enum {
    GX_DISPMODE_OFF      = 0x00,
    GX_DISPMODE_GRAPHICS = 0x01,
    GX_DISPMODE_VRAM_A   = 0x02,
    GX_DISPMODE_VRAM_B   = 0x06,
    GX_DISPMODE_VRAM_C   = 0x0a,
    GX_DISPMODE_VRAM_D   = 0x0e,
    GX_DISPMODE_MMEM     = 0x03
} GXDispMode;
typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;
typedef enum {
    GX_BG0_AS_2D = 0,
    GX_BG0_AS_3D = 1
} GXBG0As;
typedef enum {
    GX_BGSCROFFSET_0x00000 = 0x00,
    GX_BGSCROFFSET_0x10000 = 0x01,
    GX_BGSCROFFSET_0x20000 = 0x02,
    GX_BGSCROFFSET_0x30000 = 0x03,
    GX_BGSCROFFSET_0x40000 = 0x04,
    GX_BGSCROFFSET_0x50000 = 0x05,
    GX_BGSCROFFSET_0x60000 = 0x06,
    GX_BGSCROFFSET_0x70000 = 0x07
} GXBGScrOffset;
typedef enum {
    GX_BGCHAROFFSET_0x00000 = 0x00,
    GX_BGCHAROFFSET_0x10000 = 0x01,
    GX_BGCHAROFFSET_0x20000 = 0x02,
    GX_BGCHAROFFSET_0x30000 = 0x03,
    GX_BGCHAROFFSET_0x40000 = 0x04,
    GX_BGCHAROFFSET_0x50000 = 0x05,
    GX_BGCHAROFFSET_0x60000 = 0x06,
    GX_BGCHAROFFSET_0x70000 = 0x07
} GXBGCharOffset;
typedef enum {
    GX_OBJVRAMMODE_CHAR_2D      = (0 << 4) | (0 << 20),
    GX_OBJVRAMMODE_CHAR_1D_32K  = (1 << 4) | (0 << 20),
    GX_OBJVRAMMODE_CHAR_1D_64K  = (1 << 4) | (1 << 20),
    GX_OBJVRAMMODE_CHAR_1D_128K = (1 << 4) | (2 << 20),
    GX_OBJVRAMMODE_CHAR_1D_256K = (1 << 4) | (3 << 20)
} GXOBJVRamModeChar;
typedef enum {
    GX_OBJVRAMMODE_BMP_2D_W128 = (0 << (4 + 1)) | (0 << (20 + 2)),
    GX_OBJVRAMMODE_BMP_2D_W256 = (1 << (4 + 1)) | (0 << (20 + 2)),
    GX_OBJVRAMMODE_BMP_1D_128K = (2 << (4 + 1)) | (0 << (20 + 2)),
    GX_OBJVRAMMODE_BMP_1D_256K = (2 << (4 + 1)) | (1 << (20 + 2))
} GXOBJVRamModeBmp;
typedef enum {
    GX_POWER_OFF = 0,

    GX_POWER_2D_MAIN = 1 << 1,
    GX_POWER_2D_SUB  = 1 << 9,

    GX_POWER_RE = 1 << 2,
    GX_POWER_GE = 1 << 3,

    GX_POWER_2D = GX_POWER_2D_MAIN | GX_POWER_2D_SUB,
    GX_POWER_3D = GX_POWER_RE | GX_POWER_GE,

    GX_POWER_ALL = GX_POWER_2D | GX_POWER_3D
} GXPower;
typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;
typedef enum {
    GX_PLANEMASK_NONE = 0,

    GX_PLANEMASK_BG0 = (1 << 0),
    GX_PLANEMASK_BG1 = (1 << 1),
    GX_PLANEMASK_BG2 = (1 << 2),
    GX_PLANEMASK_BG3 = (1 << 3),
    GX_PLANEMASK_OBJ = (1 << 4),

    GX_PLANEMASK_ALL = GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ,
} GXPlaneMask;
typedef enum {
    GX_WNDMASK_NONE = 0x00,
    GX_WNDMASK_W0   = 0x01,
    GX_WNDMASK_W1   = 0x02,
    GX_WNDMASK_OW   = 0x04
} GXWndMask;
extern void GX_SetPower(int gxbit_power);
extern GXPower GX_GetPower(void);
extern void GX_Power2DMain(BOOL enable);
extern void GX_Power2DSub(BOOL enable);
extern void GX_PowerRender(BOOL enable);
extern void GX_PowerGeometry(BOOL enable);
extern void GXi_PowerLCD(BOOL enable);
extern void GX_Power2D(BOOL enable);
extern void GX_Power3D(BOOL enable);
extern void GX_SetDispSelect(GXDispSelect sel);
extern GXDispSelect GX_GetDispSelect(void);
extern s32 GX_IsHBlank(void);
extern s32 GX_HBlankIntr(BOOL enable);
extern s32 GX_IsVBlank(void);
extern s32 GX_VBlankIntr(BOOL enable);
extern s32 GX_IsVCountEq(void);
extern void GX_VCountEqIntr(BOOL enable);
extern void GX_SetVCountEqVal(s32 val);
extern s32 GX_GetVCountEqVal(void);
extern s32 GX_GetVCount(void);
extern void GX_SetVCount(s32 count);
extern void GX_Init(void);
extern void GX_InitEx(u32 dma_no);
extern u32 GX_SetDefaultDMA(u32 dma_no);
extern u32 GX_GetDefaultDMA(void);
extern void GX_SetGraphicsMode(GXDispMode dispMode, GXBGMode bgMode, GXBG0As bg0_2d3d);
extern void GX_DispOff(void);
extern void GX_DispOn(void);
extern BOOL GX_IsDispOn(void);
extern void GX_SetVisiblePlane(int plane);
extern void GX_SetVisibleWnd(int window);
extern void GX_BlankScr(BOOL blank);
extern GXBGScrOffset GX_GetBGScrOffset();
extern void GX_SetBGScrOffset(GXBGScrOffset offset);
extern GXBGCharOffset GX_GetBGCharOffset();
extern void GX_SetBGCharOffset(GXBGCharOffset offset);
extern void GX_SetOBJVRamModeChar(GXOBJVRamModeChar mode);
extern void GX_SetOBJVRamModeBmp(GXOBJVRamModeBmp mode);
extern void GX_HBlankOBJProc(BOOL proc);
extern void GX_SetMasterBrightness(int brightness);
extern void GXS_SetGraphicsMode(GXBGMode bgMode);
extern void GXS_DispOff(void);
extern void GXS_DispOn(void);
extern void GXS_SetVisiblePlane(int plane);
extern void GXS_SetVisibleWnd(int window);
extern void GXS_SetOBJVRamModeChar(GXOBJVRamModeChar mode);
extern void GXS_SetOBJVRamModeBmp(GXOBJVRamModeBmp mode);
extern void GXS_HBlankOBJProc(BOOL proc);
extern void GXS_SetMasterBrightness(int brightness);
extern void GXx_SetMasterBrightness_(vu16 *reg, int brightness);
extern int GXx_GetMasterBrightness_(vu16 *reg);
static inline GXDispCnt GX_GetDispCnt(void) {
    return *(volatile GXDispCnt *) (0x04000000 + 0x000);
}
static inline GXSDispCnt GXS_GetDispCnt(void) {
    return *(volatile GXSDispCnt *) (0x04000000 + 0x1000);
}
static inline GXBGScrOffset GX_GetBGScrOffset(void) {
    return (GXBGScrOffset) (((*(REGType32v *) (0x04000000 + 0x000)) & 0x38000000) >> 27);
}
static inline void GX_SetBGScrOffset(GXBGScrOffset offset) {
    (*(REGType32v *) (0x04000000 + 0x000)) = (u32) (((*(REGType32v *) (0x04000000 + 0x000)) & ~0x38000000) | (offset << 27));
}
static inline GXBGCharOffset GX_GetBGCharOffset(void) {
    return (GXBGCharOffset) (((*(REGType32v *) (0x04000000 + 0x000)) & 0x07000000) >> 24);
}
static inline void GX_SetBGCharOffset(GXBGCharOffset offset) {
    (*(REGType32v *) (0x04000000 + 0x000)) = (u32) (((*(REGType32v *) (0x04000000 + 0x000)) & ~0x07000000) | (offset << 24));
}
static inline void GX_SetVisiblePlane(int plane) {
    (*(REGType32v *) (0x04000000 + 0x000)) = (u32) (((*(REGType32v *) (0x04000000 + 0x000)) & ~0x00001f00) | (plane << 8));
}
static inline int GX_GetVisiblePlane(void) {
    return (int) (((*(REGType32v *) (0x04000000 + 0x000)) & 0x00001f00) >> 8);
}
static inline void GXS_SetVisiblePlane(int plane) {
    (*(REGType32v *) (0x04000000 + 0x1000)) = (u32) (((*(REGType32v *) (0x04000000 + 0x1000)) & ~0x00001f00) | (plane << 8));
}
static inline int GXS_GetVisiblePlane(void) {
    return (int) (((*(REGType32v *) (0x04000000 + 0x1000)) & 0x00001f00) >> 8);
}
static inline void GX_SetVisibleWnd(int window) {
    (*(REGType32v *) (0x04000000 + 0x000)) =
        (u32) (((*(REGType32v *) (0x04000000 + 0x000)) & ~(0x00002000 | 0x00004000 | 0x00008000)) | (window << 13));
}
static inline int GX_GetVisibleWnd(void) {
    return (int) (((*(REGType32v *) (0x04000000 + 0x000)) & (0x00002000 | 0x00004000 | 0x00008000)) >> 13);
}
static inline void GXS_SetVisibleWnd(int window) {
    (*(REGType32v *) (0x04000000 + 0x1000)) =
        (u32) (((*(REGType32v *) (0x04000000 + 0x1000)) & ~(0x00002000 | 0x00004000 | 0x00008000)) | (window << 13));
}
static inline int GXS_GetVisibleWnd(void) {
    return (int) (((*(REGType32v *) (0x04000000 + 0x1000)) & (0x00002000 | 0x00004000 | 0x00008000)) >> 13);
}
static inline void GX_SetOBJVRamModeChar(GXOBJVRamModeChar mode) {
    (*(REGType32v *) (0x04000000 + 0x000)) =
        (u32) ((*(REGType32v *) (0x04000000 + 0x000)) & ~(0x00300000 | 0x00000010) | mode);
}
static inline GXOBJVRamModeChar GX_GetOBJVRamModeChar(void) {
    return (GXOBJVRamModeChar) ((*(REGType32v *) (0x04000000 + 0x000)) & (0x00300000 | 0x00000010));
}
static inline void GXS_SetOBJVRamModeChar(GXOBJVRamModeChar mode) {
    (*(REGType32v *) (0x04000000 + 0x1000)) =
        (u32) ((*(REGType32v *) (0x04000000 + 0x1000)) & ~(0x00300000 | 0x00000010) | mode);
}
static inline GXOBJVRamModeChar GXS_GetOBJVRamModeChar(void) {
    return (GXOBJVRamModeChar) ((*(REGType32v *) (0x04000000 + 0x1000)) & (0x00300000 | 0x00000010));
}
static inline void GX_SetOBJVRamModeBmp(GXOBJVRamModeBmp mode) {
    (*(REGType32v *) (0x04000000 + 0x000)) =
        (u32) ((*(REGType32v *) (0x04000000 + 0x000)) & ~(0x00400000 | 0x00000060) | mode);
}
static inline GXOBJVRamModeBmp GX_GetOBJVRamModeBmp(void) {
    return (GXOBJVRamModeBmp) ((*(REGType32v *) (0x04000000 + 0x000)) & (0x00400000 | 0x00000060));
}
static inline void GXS_SetOBJVRamModeBmp(GXOBJVRamModeBmp mode) {
    (*(REGType32v *) (0x04000000 + 0x1000)) = (u32) ((*(REGType32v *) (0x04000000 + 0x1000)) & ~(0x00000060) | mode);
}
static inline GXOBJVRamModeBmp GXS_GetOBJVRamModeBmp(void) {
    return (GXOBJVRamModeBmp) ((*(REGType32v *) (0x04000000 + 0x1000)) & 0x00000060);
}
static inline void GX_BlankScr(BOOL blank) {
    if (blank) {
        (*(REGType32v *) (0x04000000 + 0x000)) |= 0x00000080;
    } else {
        (*(REGType32v *) (0x04000000 + 0x000)) &= ~0x00000080;
    }
}
static inline void GXS_DispOff(void) {
    (*(REGType32v *) (0x04000000 + 0x1000)) &= ~0x00010000;
}
static inline void GXS_DispOn(void) {
    (*(REGType32v *) (0x04000000 + 0x1000)) |= 0x00010000;
}
static inline void GX_HBlankOBJProc(BOOL proc) {
    if (proc) {
        (*(REGType32v *) (0x04000000 + 0x000)) |= 0x00800000;
    } else {
        (*(REGType32v *) (0x04000000 + 0x000)) &= ~0x00800000;
    }
}
static inline void GXS_HBlankOBJProc(BOOL proc) {
    if (proc) {
        (*(REGType32v *) (0x04000000 + 0x1000)) |= 0x00800000;
    } else {
        (*(REGType32v *) (0x04000000 + 0x1000)) &= ~0x00800000;
    }
}
static inline void GX_SetMasterBrightness(int brightness) {
    GXx_SetMasterBrightness_(&(*(REGType16v *) (0x04000000 + 0x06c)), brightness);
}
static inline int GX_GetMasterBrightness(void) {
    return GXx_GetMasterBrightness_(&(*(REGType16v *) (0x04000000 + 0x06c)));
}
static inline void GXS_SetMasterBrightness(int brightness) {
    GXx_SetMasterBrightness_(&(*(REGType16v *) (0x04000000 + 0x106c)), brightness);
}
static inline int GXS_GetMasterBrightness(void) {
    return GXx_GetMasterBrightness_(&(*(REGType16v *) (0x04000000 + 0x106c)));
}
static inline s32 GX_IsHBlank(void) {
    return ((*(REGType16v *) (0x04000000 + 0x004)) & 0x0002);
}
static inline s32 GX_IsVBlank(void) {
    return ((*(REGType16v *) (0x04000000 + 0x004)) & 0x0001);
}
static inline s32 GX_IsVCountEq(void) {
    return ((*(REGType16v *) (0x04000000 + 0x004)) & 0x0004);
}
static inline void GX_VCountEqIntr(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x004)) |= 0x0020;
    } else {
        (*(REGType16v *) (0x04000000 + 0x004)) &= ~0x0020;
    }
}
static inline s32 GX_GetVCount(void) {
    return (*(REGType16v *) (0x04000000 + 0x006));
}
static inline void GX_SetVCount(s32 count) {
    (*(REGType16v *) (0x04000000 + 0x006)) = (u16) count;
}
static inline s32 GX_GetVCountEqVal(void) {
    u16 val = (*(REGType16v *) (0x04000000 + 0x004));
    return ((val >> 8) & 0x00ff) | ((val << 1) & 0x0100);
}
static inline void GX_SetPower(int gxbit_power) {
    (*(REGType16v *) (0x04000000 + 0x304)) = (u16) (((*(REGType16v *) (0x04000000 + 0x304)) & ~GX_POWER_ALL) | gxbit_power);
}
static inline GXPower GX_GetPower(void) {
    return (GXPower) ((*(REGType16v *) (0x04000000 + 0x304)) & GX_POWER_ALL);
}
static inline void GXi_PowerLCD(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= 0x0001;
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~0x0001;
    }
}
static inline void GX_Power2D(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= (0x0002 | 0x0200);
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~(0x0002 | 0x0200);
    }
}
static inline void GX_Power2DMain(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= 0x0002;
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~0x0002;
    }
}
static inline void GX_Power2DSub(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= 0x0200;
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~0x0200;
    }
}
static inline void GX_PowerRender(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= 0x0004;
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~0x0004;
    }
}
static inline void GX_PowerGeometry(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= 0x0008;
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~0x0008;
    }
}
static inline void GX_Power3D(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x304)) |= (0x0008 | 0x0004);
    } else {
        (*(REGType16v *) (0x04000000 + 0x304)) &= ~(0x0008 | 0x0004);
    }
}
static inline void GX_SetDispSelect(GXDispSelect sel) {
    (*(REGType16v *) (0x04000000 + 0x304)) = (u16) (((*(REGType16v *) (0x04000000 + 0x304)) & ~0x8000) | (sel << 15));
}
static inline GXDispSelect GX_GetDispSelect(void) {
    return (GXDispSelect) (((*(REGType16v *) (0x04000000 + 0x304)) & 0x8000) >> 15);
}
static inline void GX_InitEx(u32 dma_no) {
    GXi_DmaId = dma_no;
    GX_Init();
}
static inline u32 GX_GetDefaultDMA(void) {
    return GXi_DmaId;
}
extern void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
extern void GXi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
extern void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void GXi_WaitDma(u32 dmaNo);
static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (dmaNo != ((u32) ~0) && size > 48) {
        MI_DmaCopy32(dmaNo, src, dest, size);
    } else {
        MI_CpuCopy32(src, dest, size);
    }
}
static inline void GXi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (dmaNo != ((u32) ~0) && size > 28) {
        MI_DmaCopy16(dmaNo, src, dest, size);
    } else {
        MI_CpuCopy16(src, dest, size);
    }
}
static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    if (dmaNo != ((u32) ~0)) {
        MI_DmaCopy32Async(dmaNo, src, dest, size, callback, arg);
    } else {
        MI_CpuCopy32(src, dest, size);
    }
}
static inline void GXi_WaitDma(u32 dmaNo) {
    if (dmaNo != ((u32) ~0)) {
        MI_WaitDma(dmaNo);
    }
}
typedef enum {
    GX_VRAM_A   = 0x0001,
    GX_VRAM_B   = 0x0002,
    GX_VRAM_C   = 0x0004,
    GX_VRAM_D   = 0x0008,
    GX_VRAM_E   = 0x0010,
    GX_VRAM_F   = 0x0020,
    GX_VRAM_G   = 0x0040,
    GX_VRAM_H   = 0x0080,
    GX_VRAM_I   = 0x0100,
    GX_VRAM_ALL = 0x01FF
} GXVRam;
typedef enum {
    GX_VRAM_LCDC_NONE = 0x0000,
    GX_VRAM_LCDC_A    = GX_VRAM_A,
    GX_VRAM_LCDC_B    = GX_VRAM_B,
    GX_VRAM_LCDC_C    = GX_VRAM_C,
    GX_VRAM_LCDC_D    = GX_VRAM_D,
    GX_VRAM_LCDC_E    = GX_VRAM_E,
    GX_VRAM_LCDC_F    = GX_VRAM_F,
    GX_VRAM_LCDC_G    = GX_VRAM_G,
    GX_VRAM_LCDC_H    = GX_VRAM_H,
    GX_VRAM_LCDC_I    = GX_VRAM_I,
    GX_VRAM_LCDC_ALL  = GX_VRAM_ALL
} GXVRamLCDC;
typedef enum {
    GX_VRAM_BG_NONE     = 0x0000,
    GX_VRAM_BG_16_F     = GX_VRAM_F,
    GX_VRAM_BG_16_G     = GX_VRAM_G,
    GX_VRAM_BG_32_FG    = GX_VRAM_F | GX_VRAM_G,
    GX_VRAM_BG_64_E     = GX_VRAM_E,
    GX_VRAM_BG_80_EF    = GX_VRAM_E | GX_VRAM_F,
    GX_VRAM_BG_96_EFG   = GX_VRAM_E | GX_VRAM_F | GX_VRAM_G,
    GX_VRAM_BG_128_A    = GX_VRAM_A,
    GX_VRAM_BG_128_B    = GX_VRAM_B,
    GX_VRAM_BG_128_C    = GX_VRAM_C,
    GX_VRAM_BG_128_D    = GX_VRAM_D,
    GX_VRAM_BG_256_AB   = GX_VRAM_A | GX_VRAM_B,
    GX_VRAM_BG_256_BC   = GX_VRAM_B | GX_VRAM_C,
    GX_VRAM_BG_256_CD   = GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_BG_384_ABC  = GX_VRAM_A | GX_VRAM_B | GX_VRAM_C,
    GX_VRAM_BG_384_BCD  = GX_VRAM_B | GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_BG_512_ABCD = GX_VRAM_A | GX_VRAM_B | GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_BG_80_EG    = GX_VRAM_E | GX_VRAM_G,
    GX_VRAM_BG_256_AC   = GX_VRAM_A | GX_VRAM_C,
    GX_VRAM_BG_256_AD   = GX_VRAM_A | GX_VRAM_D,
    GX_VRAM_BG_256_BD   = GX_VRAM_B | GX_VRAM_D,
    GX_VRAM_BG_384_ABD  = GX_VRAM_A | GX_VRAM_B | GX_VRAM_D,
    GX_VRAM_BG_384_ACD  = GX_VRAM_A | GX_VRAM_C | GX_VRAM_D
} GXVRamBG;
typedef enum {
    GX_VRAM_OBJ_NONE   = 0x0000,
    GX_VRAM_OBJ_16_F   = GX_VRAM_F,
    GX_VRAM_OBJ_16_G   = GX_VRAM_G,
    GX_VRAM_OBJ_32_FG  = GX_VRAM_F | GX_VRAM_G,
    GX_VRAM_OBJ_64_E   = GX_VRAM_E,
    GX_VRAM_OBJ_80_EF  = GX_VRAM_E | GX_VRAM_F,
    GX_VRAM_OBJ_80_EG  = GX_VRAM_E | GX_VRAM_G,
    GX_VRAM_OBJ_96_EFG = GX_VRAM_E | GX_VRAM_F | GX_VRAM_G,
    GX_VRAM_OBJ_128_A  = GX_VRAM_A,
    GX_VRAM_OBJ_128_B  = GX_VRAM_B,
    GX_VRAM_OBJ_256_AB = GX_VRAM_A | GX_VRAM_B
} GXVRamOBJ;
typedef enum {
    GX_VRAM_TEX_NONE      = 0x0000,
    GX_VRAM_TEX_0_A       = GX_VRAM_A,
    GX_VRAM_TEX_0_B       = GX_VRAM_B,
    GX_VRAM_TEX_0_C       = GX_VRAM_C,
    GX_VRAM_TEX_0_D       = GX_VRAM_D,
    GX_VRAM_TEX_01_AB     = GX_VRAM_A | GX_VRAM_B,
    GX_VRAM_TEX_01_BC     = GX_VRAM_B | GX_VRAM_C,
    GX_VRAM_TEX_01_CD     = GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_TEX_012_ABC   = GX_VRAM_A | GX_VRAM_B | GX_VRAM_C,
    GX_VRAM_TEX_012_BCD   = GX_VRAM_B | GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_TEX_0123_ABCD = GX_VRAM_A | GX_VRAM_B | GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_TEX_01_AC     = GX_VRAM_A | GX_VRAM_C,
    GX_VRAM_TEX_01_AD     = GX_VRAM_A | GX_VRAM_D,
    GX_VRAM_TEX_01_BD     = GX_VRAM_B | GX_VRAM_D,
    GX_VRAM_TEX_012_ABD   = GX_VRAM_A | GX_VRAM_B | GX_VRAM_D,
    GX_VRAM_TEX_012_ACD   = GX_VRAM_A | GX_VRAM_C | GX_VRAM_D
} GXVRamTex;
typedef enum {
    GX_VRAM_CLEARIMAGE_NONE   = 0x0000,
    GX_VRAM_CLEARIMAGE_256_AB = GX_VRAM_A | GX_VRAM_B,
    GX_VRAM_CLEARIMAGE_256_CD = GX_VRAM_C | GX_VRAM_D,
    GX_VRAM_CLEARDEPTH_128_A  = GX_VRAM_A,
    GX_VRAM_CLEARDEPTH_128_B  = GX_VRAM_B,
    GX_VRAM_CLEARDEPTH_128_C  = GX_VRAM_C,
    GX_VRAM_CLEARDEPTH_128_D  = GX_VRAM_D
} GXVRamClearImage;
typedef enum {
    GX_VRAM_TEXPLTT_NONE       = 0x0000,
    GX_VRAM_TEXPLTT_0_F        = GX_VRAM_F,
    GX_VRAM_TEXPLTT_0_G        = GX_VRAM_G,
    GX_VRAM_TEXPLTT_01_FG      = GX_VRAM_F | GX_VRAM_G,
    GX_VRAM_TEXPLTT_0123_E     = GX_VRAM_E,
    GX_VRAM_TEXPLTT_01234_EF   = GX_VRAM_E | GX_VRAM_F,
    GX_VRAM_TEXPLTT_012345_EFG = GX_VRAM_E | GX_VRAM_F | GX_VRAM_G
} GXVRamTexPltt;
typedef enum {
    GX_VRAM_BGEXTPLTT_NONE    = 0x0000,
    GX_VRAM_BGEXTPLTT_01_F    = GX_VRAM_F,
    GX_VRAM_BGEXTPLTT_23_G    = GX_VRAM_G,
    GX_VRAM_BGEXTPLTT_0123_E  = GX_VRAM_E,
    GX_VRAM_BGEXTPLTT_0123_FG = GX_VRAM_F | GX_VRAM_G
} GXVRamBGExtPltt;
typedef enum {
    GX_VRAM_OBJEXTPLTT_NONE = 0,
    GX_VRAM_OBJEXTPLTT_0_F  = GX_VRAM_F,
    GX_VRAM_OBJEXTPLTT_0_G  = GX_VRAM_G
} GXVRamOBJExtPltt;
typedef enum {
    GX_VRAM_SUB_BG_NONE  = 0x0000,
    GX_VRAM_SUB_BG_128_C = GX_VRAM_C,
    GX_VRAM_SUB_BG_32_H  = GX_VRAM_H,
    GX_VRAM_SUB_BG_48_HI = GX_VRAM_H | GX_VRAM_I
} GXVRamSubBG;
typedef enum {
    GX_VRAM_SUB_OBJ_NONE  = 0x0000,
    GX_VRAM_SUB_OBJ_128_D = GX_VRAM_D,
    GX_VRAM_SUB_OBJ_16_I  = GX_VRAM_I
} GXVRamSubOBJ;
typedef enum {
    GX_VRAM_SUB_BGEXTPLTT_NONE   = 0x0000,
    GX_VRAM_SUB_BGEXTPLTT_0123_H = GX_VRAM_H
} GXVRamSubBGExtPltt;
typedef enum {
    GX_VRAM_SUB_OBJEXTPLTT_NONE = 0x0000,
    GX_VRAM_SUB_OBJEXTPLTT_0_I  = GX_VRAM_I
} GXVRamSubOBJExtPltt;
typedef enum {
    GX_VRAM_ARM7_NONE   = 0x0000,
    GX_VRAM_ARM7_128_C  = GX_VRAM_C,
    GX_VRAM_ARM7_128_D  = GX_VRAM_D,
    GX_VRAM_ARM7_256_CD = GX_VRAM_C | GX_VRAM_D
} GXVRamARM7;
extern void GX_SetBankForBG(GXVRamBG bg);
extern BOOL GX_TrySetBankForBG(GXVRamBG bg);
extern void GX_SetBankForBGEx(GXVRamBG bg1, GXVRamBG bg2);
extern BOOL GX_TrySetBankForBGEx(GXVRamBG bg1, GXVRamBG bg2);
extern void GX_SetBankForOBJ(GXVRamOBJ obj);
extern BOOL GX_TrySetBankForOBJ(GXVRamOBJ obj);
extern void GX_SetBankForBGExtPltt(GXVRamBGExtPltt bgExtPltt);
extern BOOL GX_TrySetBankForBGExtPltt(GXVRamBGExtPltt bgExtPltt);
extern void GX_SetBankForOBJExtPltt(GXVRamOBJExtPltt objExtPltt);
extern BOOL GX_TrySetBankForOBJExtPltt(GXVRamOBJExtPltt objExtPltt);
extern void GX_SetBankForTex(GXVRamTex tex);
extern BOOL GX_TrySetBankForTex(GXVRamTex tex);
extern void GX_SetBankForTexPltt(GXVRamTexPltt texPltt);
extern BOOL GX_TrySetBankForTexPltt(GXVRamTexPltt texPltt);
extern void GX_SetBankForClearImage(GXVRamClearImage clrImg);
extern BOOL GX_TrySetBankForClearImage(GXVRamClearImage clrImg);
extern GXVRamBG GX_GetBankForBG(void);
extern GXVRamOBJ GX_GetBankForOBJ(void);
extern GXVRamBGExtPltt GX_GetBankForBGExtPltt(void);
extern GXVRamOBJExtPltt GX_GetBankForOBJExtPltt(void);
extern GXVRamTex GX_GetBankForTex(void);
extern GXVRamTexPltt GX_GetBankForTexPltt(void);
extern GXVRamClearImage GX_GetBankForClearImage(void);
extern GXVRamBG GX_ResetBankForBG(void);
extern GXVRamOBJ GX_ResetBankForOBJ(void);
extern GXVRamBGExtPltt GX_ResetBankForBGExtPltt(void);
extern GXVRamOBJExtPltt GX_ResetBankForOBJExtPltt(void);
extern GXVRamTex GX_ResetBankForTex(void);
extern GXVRamTexPltt GX_ResetBankForTexPltt(void);
extern GXVRamClearImage GX_ResetBankForClearImage(void);
extern GXVRamBG GX_DisableBankForBG(void);
extern GXVRamOBJ GX_DisableBankForOBJ(void);
extern GXVRamBGExtPltt GX_DisableBankForBGExtPltt(void);
extern GXVRamOBJExtPltt GX_DisableBankForOBJExtPltt(void);
extern GXVRamTex GX_DisableBankForTex(void);
extern GXVRamTexPltt GX_DisableBankForTexPltt(void);
extern GXVRamClearImage GX_DisableBankForClearImage(void);
extern u32 GX_GetSizeOfBG(void);
extern u32 GX_GetSizeOfOBJ(void);
extern u32 GX_GetSizeOfBGExtPltt(void);
extern u32 GX_GetSizeOfOBJExtPltt(void);
extern u32 GX_GetSizeOfTex(void);
extern u32 GX_GetSizeOfTexPltt(void);
extern u32 GX_GetSizeOfClearImage(void);
extern void GX_SetBankForSubBG(GXVRamSubBG sub_bg);
extern void GX_SetBankForSubOBJ(GXVRamSubOBJ sub_obj);
extern void GX_SetBankForSubBGExtPltt(GXVRamSubBGExtPltt sub_bgExtPltt);
extern void GX_SetBankForSubOBJExtPltt(GXVRamSubOBJExtPltt sub_objExtPltt);
extern GXVRamSubBG GX_GetBankForSubBG(void);
extern GXVRamSubOBJ GX_GetBankForSubOBJ(void);
extern GXVRamSubBGExtPltt GX_GetBankForSubBGExtPltt(void);
extern GXVRamSubOBJExtPltt GX_GetBankForSubOBJExtPltt(void);
extern GXVRamSubBG GX_ResetBankForSubBG(void);
extern GXVRamSubOBJ GX_ResetBankForSubOBJ(void);
extern GXVRamSubBGExtPltt GX_ResetBankForSubBGExtPltt(void);
extern GXVRamSubOBJExtPltt GX_ResetBankForSubOBJExtPltt(void);
extern GXVRamSubBG GX_DisableBankForSubBG(void);
extern GXVRamSubOBJ GX_DisableBankForSubOBJ(void);
extern GXVRamSubBGExtPltt GX_DisableBankForSubBGExtPltt(void);
extern GXVRamSubOBJExtPltt GX_DisableBankForSubOBJExtPltt(void);
extern u32 GX_GetSizeOfSubBG(void);
extern u32 GX_GetSizeOfSubOBJ(void);
extern u32 GX_GetSizeOfSubBGExtPltt(void);
extern u32 GX_GetSizeOfSubOBJExtPltt(void);
extern void GX_SetBankForARM7(GXVRamARM7 arm7);
extern void GX_SetBankForLCDC(int lcdc);
extern GXVRamARM7 GX_GetBankForARM7(void);
extern GXVRamLCDC GX_GetBankForLCDC(void);
extern GXVRamARM7 GX_ResetBankForARM7(void);
extern GXVRamARM7 GX_DisableBankForARM7(void);
extern GXVRamLCDC GX_DisableBankForLCDC(void);
extern u32 GX_GetSizeOfARM7(void);
typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;

    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt_;
typedef struct {
    GX_VRAMCnt_ vramCnt;
} GX_State;
extern GX_State gGXState;
extern void GX_InitGXState();
static inline void GX_StateCheck_VRAMCnt(void) {}
static inline void GX_RegionCheck_BG(u32 first, u32 last) {}
static inline void GX_RegionCheck_OBJ(u32 first, u32 last) {}
static inline void GX_RegionCheck_SubBG(u32 first, u32 last) {}
static inline void GX_RegionCheck_SubOBJ(u32 first, u32 last) {}
static inline void GX_RegionCheck_Tex(GXVRamTex tex, u32 first, u32 last) {}
static inline void GX_RegionCheck_TexPltt(GXVRamTexPltt texPltt, u32 first, u32 last) {}
extern void *G2_GetBG0ScrPtr(void);
extern void *G2S_GetBG0ScrPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2S_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2S_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void *G2S_GetBG3ScrPtr(void);
extern void *G2_GetBG0CharPtr(void);
extern void *G2S_GetBG0CharPtr(void);
extern void *G2_GetBG1CharPtr(void);
extern void *G2S_GetBG1CharPtr(void);
extern void *G2_GetBG2CharPtr(void);
extern void *G2S_GetBG2CharPtr(void);
extern void *G2_GetBG3CharPtr(void);
extern void *G2S_GetBG3CharPtr(void);
extern void *G2_GetOBJCharPtr(void);
extern void *G2S_GetOBJCharPtr(void);
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 charBase : 4;
        u16 mosaic : 1;
        u16 colorMode : 1;
        u16 screenBase : 5;
        u16 bgExtPltt : 1;
        u16 screenSize : 2;
    };
} GXBg01Control;
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 charBase : 4;
        u16 mosaic : 1;
        u16 colorMode : 1;
        u16 screenBase : 5;
        u16 _reserve : 1;
        u16 screenSize : 2;
    };
} GXBg23ControlText;
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 charBase : 4;
        u16 mosaic : 1;
        u16 _reserve : 1;
        u16 screenBase : 5;
        u16 areaOver : 1;
        u16 screenSize : 2;
    };
} GXBg23ControlAffine;
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 _reserve1 : 1;
        u16 charBase : 3;
        u16 mosaic : 1;
        u16 _reserve2 : 1;
        u16 screenBase : 5;
        u16 areaOver : 1;
        u16 screenSize : 2;
    };
} GXBg23Control256x16Pltt;
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 _reserve1 : 4;
        u16 mosaic : 1;
        u16 _reserve2 : 1;
        u16 screenBase : 5;
        u16 areaOver : 1;
        u16 screenSize : 2;
    };
} GXBg23Control256Bmp, GXBg23ControlDCBmp;
typedef union {
    u16 raw;
    struct {
        u16 priority : 2;
        u16 _reserve1 : 4;
        u16 mosaic : 1;
        u16 _reserve2 : 6;
        u16 areaOver : 1;
        u16 screenSize : 2;
    };
} GXBg2ControlLargeBmp;
typedef enum {
    GX_BG_SCRSIZE_TEXT_256x256 = 0,
    GX_BG_SCRSIZE_TEXT_512x256 = 1,
    GX_BG_SCRSIZE_TEXT_256x512 = 2,
    GX_BG_SCRSIZE_TEXT_512x512 = 3
} GXBGScrSizeText;
typedef enum {
    GX_BG_SCRSIZE_AFFINE_128x128   = 0,
    GX_BG_SCRSIZE_AFFINE_256x256   = 1,
    GX_BG_SCRSIZE_AFFINE_512x512   = 2,
    GX_BG_SCRSIZE_AFFINE_1024x1024 = 3
} GXBGScrSizeAffine;
typedef enum {
    GX_BG_SCRSIZE_256x16PLTT_128x128   = 0,
    GX_BG_SCRSIZE_256x16PLTT_256x256   = 1,
    GX_BG_SCRSIZE_256x16PLTT_512x512   = 2,
    GX_BG_SCRSIZE_256x16PLTT_1024x1024 = 3
} GXBGScrSize256x16Pltt;
typedef enum {
    GX_BG_SCRSIZE_256BMP_128x128 = 0,
    GX_BG_SCRSIZE_256BMP_256x256 = 1,
    GX_BG_SCRSIZE_256BMP_512x256 = 2,
    GX_BG_SCRSIZE_256BMP_512x512 = 3
} GXBGScrSize256Bmp;
typedef enum {
    GX_BG_SCRSIZE_DCBMP_128x128 = 0,
    GX_BG_SCRSIZE_DCBMP_256x256 = 1,
    GX_BG_SCRSIZE_DCBMP_512x256 = 2,
    GX_BG_SCRSIZE_DCBMP_512x512 = 3
} GXBGScrSizeDcBmp;
typedef enum {
    GX_BG_SCRSIZE_LARGEBMP_512x1024 = 0,
    GX_BG_SCRSIZE_LARGEBMP_1024x512 = 1
} GXBGScrSizeLargeBmp;
typedef enum {
    GX_BG_COLORMODE_16  = 0,
    GX_BG_COLORMODE_256 = 1
} GXBGColorMode;
typedef enum {
    GX_BG_AREAOVER_XLU    = 0,
    GX_BG_AREAOVER_REPEAT = 1
} GXBGAreaOver;
typedef enum {
    GX_BG_CHARBASE_0x00000 = 0,
    GX_BG_CHARBASE_0x04000 = 1,
    GX_BG_CHARBASE_0x08000 = 2,
    GX_BG_CHARBASE_0x0c000 = 3,
    GX_BG_CHARBASE_0x10000 = 4,
    GX_BG_CHARBASE_0x14000 = 5,
    GX_BG_CHARBASE_0x18000 = 6,
    GX_BG_CHARBASE_0x1c000 = 7,
    GX_BG_CHARBASE_0x20000 = 8,
    GX_BG_CHARBASE_0x24000 = 9,
    GX_BG_CHARBASE_0x28000 = 10,
    GX_BG_CHARBASE_0x2c000 = 11,
    GX_BG_CHARBASE_0x30000 = 12,
    GX_BG_CHARBASE_0x34000 = 13,
    GX_BG_CHARBASE_0x38000 = 14,
    GX_BG_CHARBASE_0x3c000 = 15
} GXBGCharBase;
typedef enum {
    GX_BG_SCRBASE_0x0000 = 0,
    GX_BG_SCRBASE_0x0800 = 1,
    GX_BG_SCRBASE_0x1000 = 2,
    GX_BG_SCRBASE_0x1800 = 3,
    GX_BG_SCRBASE_0x2000 = 4,
    GX_BG_SCRBASE_0x2800 = 5,
    GX_BG_SCRBASE_0x3000 = 6,
    GX_BG_SCRBASE_0x3800 = 7,
    GX_BG_SCRBASE_0x4000 = 8,
    GX_BG_SCRBASE_0x4800 = 9,
    GX_BG_SCRBASE_0x5000 = 10,
    GX_BG_SCRBASE_0x5800 = 11,
    GX_BG_SCRBASE_0x6000 = 12,
    GX_BG_SCRBASE_0x6800 = 13,
    GX_BG_SCRBASE_0x7000 = 14,
    GX_BG_SCRBASE_0x7800 = 15,
    GX_BG_SCRBASE_0x8000 = 16,
    GX_BG_SCRBASE_0x8800 = 17,
    GX_BG_SCRBASE_0x9000 = 18,
    GX_BG_SCRBASE_0x9800 = 19,
    GX_BG_SCRBASE_0xa000 = 20,
    GX_BG_SCRBASE_0xa800 = 21,
    GX_BG_SCRBASE_0xb000 = 22,
    GX_BG_SCRBASE_0xb800 = 23,
    GX_BG_SCRBASE_0xc000 = 24,
    GX_BG_SCRBASE_0xc800 = 25,
    GX_BG_SCRBASE_0xd000 = 26,
    GX_BG_SCRBASE_0xd800 = 27,
    GX_BG_SCRBASE_0xe000 = 28,
    GX_BG_SCRBASE_0xe800 = 29,
    GX_BG_SCRBASE_0xf000 = 30,
    GX_BG_SCRBASE_0xf800 = 31
} GXBGScrBase;
typedef enum {
    GX_BG_BMPSCRBASE_0x00000 = 0,
    GX_BG_BMPSCRBASE_0x04000 = 1,
    GX_BG_BMPSCRBASE_0x08000 = 2,
    GX_BG_BMPSCRBASE_0x0c000 = 3,
    GX_BG_BMPSCRBASE_0x10000 = 4,
    GX_BG_BMPSCRBASE_0x14000 = 5,
    GX_BG_BMPSCRBASE_0x18000 = 6,
    GX_BG_BMPSCRBASE_0x1c000 = 7,
    GX_BG_BMPSCRBASE_0x20000 = 8,
    GX_BG_BMPSCRBASE_0x24000 = 9,
    GX_BG_BMPSCRBASE_0x28000 = 10,
    GX_BG_BMPSCRBASE_0x2c000 = 11,
    GX_BG_BMPSCRBASE_0x30000 = 12,
    GX_BG_BMPSCRBASE_0x34000 = 13,
    GX_BG_BMPSCRBASE_0x38000 = 14,
    GX_BG_BMPSCRBASE_0x3c000 = 15,
    GX_BG_BMPSCRBASE_0x40000 = 16,
    GX_BG_BMPSCRBASE_0x44000 = 17,
    GX_BG_BMPSCRBASE_0x48000 = 18,
    GX_BG_BMPSCRBASE_0x4c000 = 19,
    GX_BG_BMPSCRBASE_0x50000 = 20,
    GX_BG_BMPSCRBASE_0x54000 = 21,
    GX_BG_BMPSCRBASE_0x58000 = 22,
    GX_BG_BMPSCRBASE_0x5c000 = 23,
    GX_BG_BMPSCRBASE_0x60000 = 24,
    GX_BG_BMPSCRBASE_0x64000 = 25,
    GX_BG_BMPSCRBASE_0x68000 = 26,
    GX_BG_BMPSCRBASE_0x6c000 = 27,
    GX_BG_BMPSCRBASE_0x70000 = 28,
    GX_BG_BMPSCRBASE_0x74000 = 29,
    GX_BG_BMPSCRBASE_0x78000 = 30,
    GX_BG_BMPSCRBASE_0x7c000 = 31
} GXBGBmpScrBase;
typedef enum {
    GX_BG_EXTPLTT_01 = 0,
    GX_BG_EXTPLTT_23 = 1
} GXBGExtPltt;
typedef enum {
    GX_BG_EXTMODE_256x16PLTT = (0 << 2) | (0 << 7),
    GX_BG_EXTMODE_256BITMAP  = (0 << 2) | (1 << 7),
    GX_BG_EXTMODE_DCBITMAP   = (1 << 2) | (1 << 7)
} GXBGExtMode;
static inline void G2_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                    GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    (*(REGType16v *) (0x04000000 + 0x008)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x008)) & (0x0003 | 0x0040)) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                     GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    (*(REGType16v *) (0x04000000 + 0x1008)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x1008)) & (0x0003 | 0x0040)) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                    GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    (*(REGType16v *) (0x04000000 + 0x00a)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00a)) & (0x0003 | 0x0040)) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                     GXBGCharBase charBase, GXBGExtPltt bgExtPltt) {
    (*(REGType16v *) (0x04000000 + 0x100a)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100a)) & (0x0003 | 0x0040)) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                        GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                         GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                          GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (screenBase << 8) |
               (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                           GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (screenBase << 8) |
               (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG2Control256x16Pltt(GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                              GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & (0x0003 | 0x0040)) | (screenSize << 14) | (charBase << 2) |
               GX_BG_EXTMODE_256x16PLTT | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG2Control256x16Pltt(GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                               GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & (0x0003 | 0x0040)) | (screenSize << 14) | (charBase << 2) |
               GX_BG_EXTMODE_256x16PLTT | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG2Control256Bmp(GXBGScrSize256Bmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_256BITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG2Control256Bmp(GXBGScrSize256Bmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_256BITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG2ControlDCBmp(GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_DCBITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG2ControlDCBmp(GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_DCBITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG2ControlLargeBmp(GXBGScrSizeLargeBmp screenSize, GXBGAreaOver areaOver) {
    (*(REGType16v *) (0x04000000 + 0x00c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & (0x0003 | 0x0040)) | (screenSize << 14) | (areaOver << 13));
}
static inline void G2S_SetBG2ControlLargeBmp(GXBGScrSizeLargeBmp screenSize, GXBGAreaOver areaOver) {
    (*(REGType16v *) (0x04000000 + 0x100c)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & (0x0003 | 0x0040)) | (screenSize << 14) | (areaOver << 13));
}
static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                        GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                         GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (colorMode << 7) |
               (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                          GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (screenBase << 8) |
               (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                           GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & ((0x0003 | 0x0040))) | (screenSize << 14) | (screenBase << 8) |
               (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG3Control256x16Pltt(GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                              GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & (0x0003 | 0x0040)) | (screenSize << 14) | (charBase << 2) |
               GX_BG_EXTMODE_256x16PLTT | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG3Control256x16Pltt(GXBGScrSize256x16Pltt screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase,
                                               GXBGCharBase charBase) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & (0x0003 | 0x0040)) | (screenSize << 14) | (charBase << 2) |
               GX_BG_EXTMODE_256x16PLTT | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG3Control256Bmp(GXBGScrSize256Bmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_256BITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG3Control256Bmp(GXBGScrSize256Bmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_256BITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG3ControlDCBmp(GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_DCBITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG3ControlDCBmp(GXBGScrSizeDcBmp screenSize, GXBGAreaOver areaOver, GXBGBmpScrBase screenBase) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & (0x0003 | 0x0040)) | (screenSize << 14) | GX_BG_EXTMODE_DCBITMAP |
               (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG3ControlLargeBmp(GXBGScrSizeLargeBmp screenSize, GXBGAreaOver areaOver) {
    (*(REGType16v *) (0x04000000 + 0x00e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & (0x0003 | 0x0040)) | (screenSize << 14) | (areaOver << 13));
}
static inline void G2S_SetBG3ControlLargeBmp(GXBGScrSizeLargeBmp screenSize, GXBGAreaOver areaOver) {
    (*(REGType16v *) (0x04000000 + 0x100e)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & (0x0003 | 0x0040)) | (screenSize << 14) | (areaOver << 13));
}
static inline void G2_BG0Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x008)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x008)) &= ~0x0040;
    }
}
static inline void G2S_BG0Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x1008)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x1008)) &= ~0x0040;
    }
}
static inline void G2_BG1Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x00a)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x00a)) &= ~0x0040;
    }
}
static inline void G2S_BG1Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x100a)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x100a)) &= ~0x0040;
    }
}
static inline void G2_BG2Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x00c)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x00c)) &= ~0x0040;
    }
}
static inline void G2S_BG2Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x100c)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x100c)) &= ~0x0040;
    }
}
static inline void G2_BG3Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x00e)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x00e)) &= ~0x0040;
    }
}
static inline void G2S_BG3Mosaic(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x100e)) |= 0x0040;
    } else {
        (*(REGType16v *) (0x04000000 + 0x100e)) &= ~0x0040;
    }
}
static inline void G2_SetBG0Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x008)) = (u16) (((*(REGType16v *) (0x04000000 + 0x008)) & ~0x0003) | (priority << 0));
}
static inline void G2S_SetBG0Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x1008)) = (u16) (((*(REGType16v *) (0x04000000 + 0x1008)) & ~0x0003) | (priority << 0));
}
static inline void G2_SetBG1Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x00a)) = (u16) (((*(REGType16v *) (0x04000000 + 0x00a)) & ~0x0003) | (priority << 0));
}
static inline void G2S_SetBG1Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x100a)) = (u16) (((*(REGType16v *) (0x04000000 + 0x100a)) & ~0x0003) | (priority << 0));
}
static inline void G2_SetBG2Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x00c)) = (u16) (((*(REGType16v *) (0x04000000 + 0x00c)) & ~0x0003) | (priority << 0));
}
static inline void G2S_SetBG2Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x100c)) = (u16) (((*(REGType16v *) (0x04000000 + 0x100c)) & ~0x0003) | (priority << 0));
}
static inline void G2_SetBG3Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x00e)) = (u16) (((*(REGType16v *) (0x04000000 + 0x00e)) & ~0x0003) | (priority << 0));
}
static inline void G2S_SetBG3Priority(int priority) {
    (*(REGType16v *) (0x04000000 + 0x100e)) = (u16) (((*(REGType16v *) (0x04000000 + 0x100e)) & ~0x0003) | (priority << 0));
}
static inline GXBg01Control G2_GetBG0Control(void) {
    return *(volatile GXBg01Control *) &(*(REGType16v *) (0x04000000 + 0x008));
}
static inline GXBg01Control G2S_GetBG0Control(void) {
    return *(volatile GXBg01Control *) &(*(REGType16v *) (0x04000000 + 0x1008));
}
static inline GXBg01Control G2_GetBG1Control(void) {
    return *(volatile GXBg01Control *) &(*(REGType16v *) (0x04000000 + 0x00a));
}
static inline GXBg01Control G2S_GetBG1Control(void) {
    return *(volatile GXBg01Control *) &(*(REGType16v *) (0x04000000 + 0x100a));
}
static inline GXBg23ControlText G2_GetBG2ControlText(void) {
    return *(volatile GXBg23ControlText *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg23ControlText G2S_GetBG2ControlText(void) {
    return *(volatile GXBg23ControlText *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg23ControlAffine G2_GetBG2ControlAffine(void) {
    return *(volatile GXBg23ControlAffine *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg23ControlAffine G2S_GetBG2ControlAffine(void) {
    return *(volatile GXBg23ControlAffine *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg23Control256x16Pltt G2_GetBG2Control256x16Pltt(void) {
    return *(volatile GXBg23Control256x16Pltt *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg23Control256x16Pltt G2S_GetBG2Control256x16Pltt(void) {
    return *(volatile GXBg23Control256x16Pltt *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg23Control256Bmp G2_GetBG2Control256Bmp(void) {
    return *(volatile GXBg23Control256Bmp *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg23Control256Bmp G2S_GetBG2Control256Bmp(void) {
    return *(volatile GXBg23Control256Bmp *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg23ControlDCBmp G2_GetBG2ControlDCBmp(void) {
    return *(volatile GXBg23ControlDCBmp *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg23ControlDCBmp G2S_GetBG2ControlDCBmp(void) {
    return *(volatile GXBg23ControlDCBmp *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg2ControlLargeBmp G2_GetBG2ControlLargeBmp(void) {
    return *(volatile GXBg2ControlLargeBmp *) &(*(REGType16v *) (0x04000000 + 0x00c));
}
static inline GXBg2ControlLargeBmp G2S_GetBG2ControlLargeBmp(void) {
    return *(volatile GXBg2ControlLargeBmp *) &(*(REGType16v *) (0x04000000 + 0x100c));
}
static inline GXBg23ControlText G2_GetBG3ControlText(void) {
    return *(volatile GXBg23ControlText *) &(*(REGType16v *) (0x04000000 + 0x00e));
}
static inline GXBg23ControlText G2S_GetBG3ControlText(void) {
    return *(volatile GXBg23ControlText *) &(*(REGType16v *) (0x04000000 + 0x100e));
}
static inline GXBg23ControlAffine G2_GetBG3ControlAffine(void) {
    return *(volatile GXBg23ControlAffine *) &(*(REGType16v *) (0x04000000 + 0x00e));
}
static inline GXBg23ControlAffine G2S_GetBG3ControlAffine(void) {
    return *(volatile GXBg23ControlAffine *) &(*(REGType16v *) (0x04000000 + 0x100e));
}
static inline GXBg23Control256x16Pltt G2_GetBG3Control256x16Pltt(void) {
    return *(volatile GXBg23Control256x16Pltt *) &(*(REGType16v *) (0x04000000 + 0x00e));
}
static inline GXBg23Control256x16Pltt G2S_GetBG3Control256x16Pltt(void) {
    return *(volatile GXBg23Control256x16Pltt *) &(*(REGType16v *) (0x04000000 + 0x100e));
}
static inline GXBg23Control256Bmp G2_GetBG3Control256Bmp(void) {
    return *(volatile GXBg23Control256Bmp *) &(*(REGType16v *) (0x04000000 + 0x00e));
}
static inline GXBg23Control256Bmp G2S_GetBG3Control256Bmp(void) {
    return *(volatile GXBg23Control256Bmp *) &(*(REGType16v *) (0x04000000 + 0x100e));
}
static inline GXBg23ControlDCBmp G2_GetBG3ControlDCBmp(void) {
    return *(volatile GXBg23ControlDCBmp *) &(*(REGType16v *) (0x04000000 + 0x00e));
}
static inline GXBg23ControlDCBmp G2S_GetBG3ControlDCBmp(void) {
    return *(volatile GXBg23ControlDCBmp *) &(*(REGType16v *) (0x04000000 + 0x100e));
}
static inline void *G2_GetOBJCharPtr(void) {
    return (void *) 0x06400000;
}
static inline void *G2S_GetOBJCharPtr(void) {
    return (void *) 0x06600000;
}
typedef enum {
    GX_CAPTURE_DEST_VRAM_A_0x00000 = 0,
    GX_CAPTURE_DEST_VRAM_B_0x00000 = 1,
    GX_CAPTURE_DEST_VRAM_C_0x00000 = 2,
    GX_CAPTURE_DEST_VRAM_D_0x00000 = 3,

    GX_CAPTURE_DEST_VRAM_A_0x08000 = 4,
    GX_CAPTURE_DEST_VRAM_B_0x08000 = 5,
    GX_CAPTURE_DEST_VRAM_C_0x08000 = 6,
    GX_CAPTURE_DEST_VRAM_D_0x08000 = 7,

    GX_CAPTURE_DEST_VRAM_A_0x10000 = 8,
    GX_CAPTURE_DEST_VRAM_B_0x10000 = 9,
    GX_CAPTURE_DEST_VRAM_C_0x10000 = 10,
    GX_CAPTURE_DEST_VRAM_D_0x10000 = 11,

    GX_CAPTURE_DEST_VRAM_A_0x18000 = 12,
    GX_CAPTURE_DEST_VRAM_B_0x18000 = 13,
    GX_CAPTURE_DEST_VRAM_C_0x18000 = 14,
    GX_CAPTURE_DEST_VRAM_D_0x18000 = 15
} GXCaptureDest;
typedef enum {
    GX_CAPTURE_SIZE_128x128 = 0,
    GX_CAPTURE_SIZE_256x64  = 1,
    GX_CAPTURE_SIZE_256x128 = 2,
    GX_CAPTURE_SIZE_256x192 = 3
} GXCaptureSize;
typedef enum {
    GX_CAPTURE_SRCA_2D3D = 0,
    GX_CAPTURE_SRCA_3D   = 1
} GXCaptureSrcA;
typedef enum {
    GX_CAPTURE_SRCB_VRAM_0x00000 = 0,
    GX_CAPTURE_SRCB_MRAM         = 1,
    GX_CAPTURE_SRCB_VRAM_0x08000 = 2,
    GX_CAPTURE_SRCB_VRAM_0x10000 = 4,
    GX_CAPTURE_SRCB_VRAM_0x18000 = 6
} GXCaptureSrcB;
typedef enum {
    GX_CAPTURE_MODE_A  = 0,
    GX_CAPTURE_MODE_B  = 1,
    GX_CAPTURE_MODE_AB = 2
} GXCaptureMode;
static inline void GX_SetCapture(GXCaptureSize sz, GXCaptureMode mode, GXCaptureSrcA a, GXCaptureSrcB b, GXCaptureDest dest,
                                 int eva, int evb) {
    (*(REGType32v *) (0x04000000 + 0x064)) =
        (0x80000000 | (mode << 29) | (b << 25) | (a << 24) | (sz << 20) | (dest << 16) | (evb << 8) | (eva << 0));
}
static inline void GX_ResetCapture(void) {
    (*(REGType32v *) (0x04000000 + 0x064)) &= ~0x80000000;
}
typedef s32 fx32;
typedef s64 fx64;
typedef s64 fx64c;
typedef s16 fx16;
typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;
typedef struct {
    fx16 x;
    fx16 y;
    fx16 z;
} VecFx16;
typedef union {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
        fx32 _30, _31, _32;
    };
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;
typedef union {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;
static inline s32 FX_Whole(fx32 v) {
    return v >> 12;
}
static inline fx32 FX_Floor(fx32 v) {
    return v & (0x7ffff000 | 0x80000000);
}
static inline fx32 FX32_CAST(s64 res) {
    return (fx32) res;
}
static inline fx32 FX_MulInline(fx32 v1, fx32 v2) {
    return ((s64) v1 * v2 + 0x800LL) >> 12;
}
extern fx32 FX_Mul32x64cFunc(fx32 v32, fx64c v64c);
static inline fx32 FX_Mul32x64cInline(fx32 v32, fx64c v64c) {
    fx64c tmp = v64c * v32 + 0x80000000LL;
    return FX32_CAST(tmp >> 32);
}
extern void FX_Init(void);
typedef struct {
    u8 planeMask : 5;
    u8 effect : 1;
    u8 _reserve : 2;
} GXWndPlane;
typedef enum GXBlendPlaneMask {
    GX_BLEND_PLANEMASK_NONE = 0x0000,
    GX_BLEND_PLANEMASK_BG0  = 0x0001,
    GX_BLEND_PLANEMASK_BG1  = 0x0002,
    GX_BLEND_PLANEMASK_BG2  = 0x0004,
    GX_BLEND_PLANEMASK_BG3  = 0x0008,
    GX_BLEND_PLANEMASK_OBJ  = 0x0010,
    GX_BLEND_PLANEMASK_BD   = 0x0020
} GXBlendPlaneMask;
typedef enum {
    GX_WND_PLANEMASK_NONE = 0x0000,
    GX_WND_PLANEMASK_BG0  = 0x0001,
    GX_WND_PLANEMASK_BG1  = 0x0002,
    GX_WND_PLANEMASK_BG2  = 0x0004,
    GX_WND_PLANEMASK_BG3  = 0x0008,
    GX_WND_PLANEMASK_OBJ  = 0x0010
} GXWndPlaneMask;
extern void G2x_SetBGyAffine_(u32 addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void G2x_SetBlendBrightnessExt_(u32 addr, int plane1, int plane2, int ev1, int ev2, int brightness);
extern void G2x_ChangeBlendBrightness_(u32 addr, int brightness);
static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect) {
    u32 tmp;

    tmp = (((*(REGType16v *) (0x04000000 + 0x04a)) & ~0x003f) | ((u32) wnd << 0));

    if (effect) {
        tmp |= (0x20 << 0);
    }

    (*(REGType16v *) (0x04000000 + 0x04a)) = (u16) tmp;
}
static inline void G2_SetBG0Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x010)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2_SetBG1Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x014)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2_SetBG2Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x018)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2_SetBG3Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x01c)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2S_SetBG0Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x1010)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2S_SetBG1Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x1014)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2S_SetBG2Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x1018)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2S_SetBG3Offset(int hOffset, int vOffset) {
    (*(REGType32v *) (0x04000000 + 0x101c)) = (u32) (((hOffset << 0) & 0x000001ff) | ((vOffset << 16) & 0x01ff0000));
}
static inline void G2_SetBG2Affine(const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1) {
    G2x_SetBGyAffine_((u32) & (*(REGType16v *) (0x04000000 + 0x020)), mtx, centerX, centerY, x1, y1);
}
static inline void G2_SetBG3Affine(const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1) {
    G2x_SetBGyAffine_((u32) & (*(REGType16v *) (0x04000000 + 0x030)), mtx, centerX, centerY, x1, y1);
}
static inline void G2S_SetBG2Affine(const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1) {
    G2x_SetBGyAffine_((u32) & (*(REGType16v *) (0x04000000 + 0x1020)), mtx, centerX, centerY, x1, y1);
}
static inline void G2S_SetBG3Affine(const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1) {
    G2x_SetBGyAffine_((u32) & (*(REGType16v *) (0x04000000 + 0x1030)), mtx, centerX, centerY, x1, y1);
}
static inline void G2_BlendNone(void) {
    (*(REGType16v *) (0x04000000 + 0x050)) = 0;
}
static inline void G2S_BlendNone(void) {
    (*(REGType16v *) (0x04000000 + 0x1050)) = 0;
}
static inline void G2_SetBlendBrightness(int plane, int brightness) {
    G2x_SetBlendBrightness_((u32) & (*(REGType16v *) (0x04000000 + 0x050)), plane, brightness);
}
static inline void G2S_SetBlendBrightness(int plane, int brightness) {
    G2x_SetBlendBrightness_((u32) & (*(REGType16v *) (0x04000000 + 0x1050)), plane, brightness);
}
static inline void G2_SetBlendBrightnessExt(int plane1, int plane2, int ev1, int ev2, int brightness) {
    G2x_SetBlendBrightnessExt_((u32) & (*(REGType16v *) (0x04000000 + 0x050)), plane1, plane2, ev1, ev2, brightness);
}
static inline void G2S_SetBlendBrightnessExt(int plane1, int plane2, int ev1, int ev2, int brightness) {
    G2x_SetBlendBrightnessExt_((u32) & (*(REGType16v *) (0x04000000 + 0x1050)), plane1, plane2, ev1, ev2, brightness);
}
static inline void G2_ChangeBlendBrightness(int brightness) {
    G2x_ChangeBlendBrightness_((u32) & (*(REGType16v *) (0x04000000 + 0x050)), brightness);
}
static inline void G2S_ChangeBlendBrightness(int brightness) {
    G2x_ChangeBlendBrightness_((u32) & (*(REGType16v *) (0x04000000 + 0x1050)), brightness);
}
typedef u32 GXSt;
typedef u32 GXTexPlttBaseParam;
typedef u32 VecVtx10;
typedef u32 VecVtxDiff;
typedef enum {
    GX_MTXMODE_PROJECTION      = 0,
    GX_MTXMODE_POSITION        = 1,
    GX_MTXMODE_POSITION_VECTOR = 2,
    GX_MTXMODE_TEXTURE         = 3
} GXMtxMode;
typedef enum {
    GX_BEGIN_TRIANGLES      = 0,
    GX_BEGIN_QUADS          = 1,
    GX_BEGIN_TRIANGLE_STRIP = 2,
    GX_BEGIN_QUAD_STRIP     = 3
} GXBegin;
typedef enum {
    GX_SORTMODE_AUTO   = 0,
    GX_SORTMODE_MANUAL = 1
} GXSortMode;
typedef enum {
    GX_BUFFERMODE_Z = 0,
    GX_BUFFERMODE_W = 1
} GXBufferMode;
typedef enum {
    GX_LIGHTMASK_NONE = 0,
    GX_LIGHTMASK_0    = 1,
    GX_LIGHTMASK_1    = 2,
    GX_LIGHTMASK_01   = 3,
    GX_LIGHTMASK_2    = 4,
    GX_LIGHTMASK_02   = 5,
    GX_LIGHTMASK_12   = 6,
    GX_LIGHTMASK_012  = 7,
    GX_LIGHTMASK_3    = 8,
    GX_LIGHTMASK_03   = 9,
    GX_LIGHTMASK_13   = 10,
    GX_LIGHTMASK_013  = 11,
    GX_LIGHTMASK_23   = 12,
    GX_LIGHTMASK_023  = 13,
    GX_LIGHTMASK_123  = 14,
    GX_LIGHTMASK_0123 = 15
} GXLightMask;
typedef enum {
    GX_POLYGONMODE_MODULATE = 0,
    GX_POLYGONMODE_DECAL    = 1,
    GX_POLYGONMODE_TOON     = 2,
    GX_POLYGONMODE_SHADOW   = 3
} GXPolygonMode;
typedef enum {
    GX_CULL_ALL   = 0,
    GX_CULL_FRONT = 1,
    GX_CULL_BACK  = 2,
    GX_CULL_NONE  = 3
} GXCull;
typedef enum {
    GX_POLYGON_ATTR_MISC_NONE             = 0,
    GX_POLYGON_ATTR_MISC_XLU_DEPTH_UPDATE = 1 << 11,
    GX_POLYGON_ATTR_MISC_FAR_CLIPPING     = 1 << 12,
    GX_POLYGON_ATTR_MISC_DISP_1DOT        = 1 << 13,
    GX_POLYGON_ATTR_MISC_DEPTHTEST_DECAL  = 1 << 14,
    GX_POLYGON_ATTR_MISC_FOG              = 1 << 15
} GXPolygonAttrMisc;
typedef enum {
    GX_TEXREPEAT_NONE = 0,
    GX_TEXREPEAT_S    = 1,
    GX_TEXREPEAT_T    = 2,
    GX_TEXREPEAT_ST   = 3
} GXTexRepeat;
typedef enum {
    GX_TEXFLIP_NONE = 0,
    GX_TEXFLIP_S    = 1,
    GX_TEXFLIP_T    = 2,
    GX_TEXFLIP_ST   = 3
} GXTexFlip;
typedef enum {
    GX_TEXSIZE_S8    = 0,
    GX_TEXSIZE_S16   = 1,
    GX_TEXSIZE_S32   = 2,
    GX_TEXSIZE_S64   = 3,
    GX_TEXSIZE_S128  = 4,
    GX_TEXSIZE_S256  = 5,
    GX_TEXSIZE_S512  = 6,
    GX_TEXSIZE_S1024 = 7
} GXTexSizeS;
typedef enum {
    GX_TEXSIZE_T8    = 0,
    GX_TEXSIZE_T16   = 1,
    GX_TEXSIZE_T32   = 2,
    GX_TEXSIZE_T64   = 3,
    GX_TEXSIZE_T128  = 4,
    GX_TEXSIZE_T256  = 5,
    GX_TEXSIZE_T512  = 6,
    GX_TEXSIZE_T1024 = 7
} GXTexSizeT;
typedef enum {
    GX_TEXFMT_NONE    = 0,
    GX_TEXFMT_A3I5    = 1,
    GX_TEXFMT_PLTT4   = 2,
    GX_TEXFMT_PLTT16  = 3,
    GX_TEXFMT_PLTT256 = 4,
    GX_TEXFMT_COMP4x4 = 5,
    GX_TEXFMT_A5I3    = 6,
    GX_TEXFMT_DIRECT  = 7
} GXTexFmt;
typedef enum {
    GX_TEXPLTTCOLOR0_USE  = 0,
    GX_TEXPLTTCOLOR0_TRNS = 1
} GXTexPlttColor0;
typedef enum {
    GX_TEXGEN_NONE     = 0,
    GX_TEXGEN_TEXCOORD = 1,
    GX_TEXGEN_NORMAL   = 2,
    GX_TEXGEN_VERTEX   = 3
} GXTexGen;
typedef enum {
    GX_LIGHTID_0 = 0,
    GX_LIGHTID_1 = 1,
    GX_LIGHTID_2 = 2,
    GX_LIGHTID_3 = 3
} GXLightId;
typedef union {
    u32 val[3];
    struct {
        fx16 x;
        fx16 y;
        fx16 z;
        fx16 width;
        fx16 height;
        fx16 depth;
    };
} GXBoxTestParam;
typedef struct {
    u8 *curr_cmd;
    u32 *curr_param;
    u32 *bottom;
    u32 length;
    BOOL param0_cmd_flg;
} GXDLInfo;
extern void G3_BeginMakeDL(GXDLInfo *info, void *ptr, u32 length);
extern u32 G3_EndMakeDL(GXDLInfo *info);
extern void *G3_GetDLStart(const GXDLInfo *info);
extern u32 G3_GetDLLength(const GXDLInfo *info);
extern u32 G3_GetDLSize(const GXDLInfo *info);
extern GXTexPlttBaseParam G3_MakeTexPlttBaseParam(u32 plttBaseAddr, GXTexFmt texfmt);
static inline void *G3_GetDLStart(const GXDLInfo *info) {
    return (void *) info->bottom;
}
static inline u32 G3_GetDLLength(const GXDLInfo *info) {
    return info->length;
}
static inline u32 G3_GetDLSize(const GXDLInfo *info) {
    if ((u32) info->curr_cmd & 3) {
        return (u32) ((u32) info->curr_param - (u32) info->bottom);
    } else {
        return (u32) ((u32) info->curr_cmd - (u32) info->bottom);
    }
}
static inline GXTexPlttBaseParam G3_MakeTexPlttBaseParam(u32 plttBaseAddr, GXTexFmt texfmt) {
    if (GX_TEXFMT_PLTT4 == texfmt) {
        return (GXTexPlttBaseParam) (plttBaseAddr >> 3);
    } else {
        return (GXTexPlttBaseParam) (plttBaseAddr >> 4);
    }
}
typedef enum {
    GX_SHADING_TOON      = 0,
    GX_SHADING_HIGHLIGHT = 1
} GXShading;
typedef enum {
    GX_FOGBLEND_COLOR_ALPHA = 0,
    GX_FOGBLEND_ALPHA       = 1
} GXFogBlend;
typedef enum {
    GX_FOGSLOPE_0x8000 = 0,
    GX_FOGSLOPE_0x4000 = 1,
    GX_FOGSLOPE_0x2000 = 2,
    GX_FOGSLOPE_0x1000 = 3,
    GX_FOGSLOPE_0x0800 = 4,
    GX_FOGSLOPE_0x0400 = 5,
    GX_FOGSLOPE_0x0200 = 6,
    GX_FOGSLOPE_0x0100 = 7,
    GX_FOGSLOPE_0x0080 = 8,
    GX_FOGSLOPE_0x0040 = 9,
    GX_FOGSLOPE_0x0020 = 10
} GXFogSlope;
typedef enum {
    GX_FIFOINTR_COND_DISABLE   = 0,
    GX_FIFOINTR_COND_UNDERHALF = 1,
    GX_FIFOINTR_COND_EMPTY     = 2
} GXFifoIntrCond;
typedef enum {
    GX_FIFOSTAT_EMPTY     = 6,
    GX_FIFOSTAT_UNDERHALF = 2,
    GX_FIFOSTAT_OVERHALF  = 0,
    GX_FIFOSTAT_FULL      = 1
} GXFifoStat;
extern void G3X_Init(void);
extern void G3X_InitMtxStack(void);
extern void G3X_ResetMtxStack(void);
extern void G3X_InitTable(void);
extern void G3X_Reset(void);
extern void G3X_SetShading(GXShading shading);
extern void G3X_AlphaTest(BOOL enable, int ref);
extern void G3X_AlphaBlend(BOOL enable);
extern void G3X_AntiAlias(BOOL enable);
extern void G3X_EdgeMarking(BOOL enable);
extern void G3X_SetFog(BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset);
extern int G3X_GetMtxStackLevelPV(s32 *level);
extern int G3X_GetMtxStackLevelPJ(s32 *level);
extern void G3X_SetFifoIntrCond(GXFifoIntrCond cond);
extern void G3X_SetDisp1DotDepth(fx32 w);
extern int G3X_GetBoxTestResult(s32 *in);
extern int G3X_GetPositionTestResult(VecFx32 *vec, fx32 *w);
extern int G3X_GetVectorTestResult(fx16 *vec);
extern int G3X_GetClipMtx(MtxFx44 *m);
extern int G3X_GetVectorMtx(MtxFx33 *m);
extern void G3X_SetHOffset(int hOffset);
extern void G3X_SetEdgeColorTable(const GXRgb *rgb_8);
extern void G3X_SetFogTable(const u32 *fogTable);
extern void G3X_SetToonTable(const GXRgb *rgb_32);
extern void G3X_SetClearColor(GXRgb rgb, int alpha, int depth, int polygonID, BOOL fog);
extern void G3X_SetClearImageOffset(int xOffset, int yOffset);
extern void G3X_SetFogColor(GXRgb rgb, int alpha);
extern s32 G3X_IsMtxStackOverflow(s32 *overflow);
extern s32 G3X_IsLineBufferUnderflow(void);
extern s32 G3X_IsListRamOverflow(void);
extern s32 G3X_IsGeometryBusy(void);
extern void G3X_ResetMtxStackOverflow(void);
extern void G3X_ResetLineBufferUnderflow(void);
extern void G3X_ResetListRamOverflow(void);
extern void G3X_ClearFifo(void);
extern s32 G3X_GetPolygonListRamCount(void);
extern s32 G3X_GetVtxListRamCount(void);
extern s32 G3X_GetRenderedLineCount(void);
extern s32 G3X_GetCommandFifoCount(void);
extern GXFifoStat G3X_GetCommandFifoStatus(void);
static inline void G3X_SetShading(GXShading shading) {
    (*(REGType16v *) (0x04000000 + 0x060)) =
        (u16) (((*(REGType16v *) (0x04000000 + 0x060)) & ~(0x0002 | 0x1000 | 0x2000)) | (shading << 1));
}
static inline void G3X_AlphaTest(BOOL enable, int ref) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x060)) = (u16) ((*(REGType16v *) (0x04000000 + 0x060)) & ~(0x1000 | 0x2000) | 0x0004);
        (*(REGType16v *) (0x04000000 + 0x340)) = (u16) ref;
    } else {
        (*(REGType16v *) (0x04000000 + 0x060)) &= (u16) ~(0x0004 | 0x1000 | 0x2000);
    }
}
static inline void G3X_AlphaBlend(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x060)) = (u16) ((*(REGType16v *) (0x04000000 + 0x060)) & ~(0x1000 | 0x2000) | 0x0008);
    } else {
        (*(REGType16v *) (0x04000000 + 0x060)) &= (u16) ~(0x0008 | 0x1000 | 0x2000);
    }
}
static inline void G3X_AntiAlias(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x060)) = (u16) ((*(REGType16v *) (0x04000000 + 0x060)) & ~(0x1000 | 0x2000) | 0x0010);
    } else {
        (*(REGType16v *) (0x04000000 + 0x060)) &= (u16) ~(0x0010 | 0x1000 | 0x2000);
    }
}
static inline void G3X_EdgeMarking(BOOL enable) {
    if (enable) {
        (*(REGType16v *) (0x04000000 + 0x060)) = (u16) ((*(REGType16v *) (0x04000000 + 0x060)) & ~(0x1000 | 0x2000) | 0x0020);
    } else {
        (*(REGType16v *) (0x04000000 + 0x060)) &= (u16) ~(0x0020 | 0x1000 | 0x2000);
    }
}
static inline void G3X_SetFifoIntrCond(GXFifoIntrCond cond) {
    (*(REGType32v *) (0x04000000 + 0x600)) = (((*(REGType32v *) (0x04000000 + 0x600)) & ~0xc0000000) | (cond << 30));
}
static inline void G3X_SetClearImageOffset(int xOffset, int yOffset) {
    (*(REGType16v *) (0x04000000 + 0x356)) = (u16) (((xOffset << 0) & 0x00ff) | ((yOffset << 8) & 0xff00));
}
static inline void G3X_SetFogColor(GXRgb rgb, int alpha) {
    (*(REGType32v *) (0x04000000 + 0x358)) = (u32) ((rgb << 0) | (alpha << 16));
}
static inline s32 G3X_IsMtxStackOverflow(s32 *overflow) {
    if ((*(REGType32v *) (0x04000000 + 0x600)) & 0x00004000) {
        return -1;
    }

    *overflow = (s32) ((*(REGType32v *) (0x04000000 + 0x600)) & 0x00008000);
    return 0;
}
static inline s32 G3X_IsLineBufferUnderflow(void) {
    return ((*(REGType16v *) (0x04000000 + 0x060)) & 0x1000);
}
static inline s32 G3X_IsListRamOverflow(void) {
    return ((*(REGType16v *) (0x04000000 + 0x060)) & 0x2000);
}
static inline s32 G3X_IsGeometryBusy(void) {
    return (s32) ((*(REGType32v *) (0x04000000 + 0x600)) & 0x08000000);
}
static inline void G3X_ResetMtxStackOverflow(void) {
    (*(REGType32v *) (0x04000000 + 0x600)) |= 0x00008000;
}
static inline void G3X_ResetLineBufferUnderflow(void) {
    (*(REGType16v *) (0x04000000 + 0x060)) |= 0x1000;
}
static inline void G3X_ResetListRamOverflow(void) {
    (*(REGType16v *) (0x04000000 + 0x060)) |= 0x2000;
}
static inline s32 G3X_GetPolygonListRamCount(void) {
    return (*(const REGType16v *) (0x04000000 + 0x604));
}
static inline s32 G3X_GetVtxListRamCount(void) {
    return (*(const REGType16v *) (0x04000000 + 0x606));
}
static inline s32 G3X_GetRenderedLineCount(void) {
    return (*(const REGType16v *) (0x04000000 + 0x320));
}
static inline s32 G3X_GetCommandFifoCount(void) {
    return (s32) (((*(REGType32v *) (0x04000000 + 0x600)) & 0x00ff0000) >> 16);
}
static inline GXFifoStat G3X_GetCommandFifoStatus(void) {
    return (GXFifoStat) (((*(REGType32v *) (0x04000000 + 0x600)) & (0x01000000 | 0x02000000 | 0x04000000)) >> 24);
}
extern void G3BS_Direct0(GXDLInfo *info, int op);
extern void G3BS_Direct1(GXDLInfo *info, int op, u32 param0);
extern void G3BS_Direct2(GXDLInfo *info, int op, u32 param0, u32 param1);
extern void G3BS_Direct3(GXDLInfo *info, int op, u32 param0, u32 param1, u32 param2);
extern void G3BS_DirectN(GXDLInfo *info, int op, int nParams, const u32 *params);
extern void G3BS_Nop(GXDLInfo *info);
extern void G3BS_MtxMode(GXDLInfo *info, GXMtxMode mode);
extern void G3BS_PushMtx(GXDLInfo *info);
extern void G3BS_PopMtx(GXDLInfo *info, int num);
extern void G3BS_StoreMtx(GXDLInfo *info, int num);
extern void G3BS_RestoreMtx(GXDLInfo *info, int num);
extern void G3BS_Identity(GXDLInfo *info);
extern void G3BS_LoadMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3BS_LoadMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3BS_MultMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3BS_MultMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3BS_MultMtx33(GXDLInfo *info, const MtxFx33 *m);
extern void G3BS_MultTransMtx33(GXDLInfo *info, const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3BS_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3BS_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3BS_Color(GXDLInfo *info, GXRgb rgb);
extern void G3BS_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3BS_TexCoord(GXDLInfo *info, fx32 s, fx32 t);
extern void G3BS_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3BS_Vtx10(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3BS_VtxXY(GXDLInfo *info, fx16 x, fx16 y);
extern void G3BS_VtxXZ(GXDLInfo *info, fx16 x, fx16 z);
extern void G3BS_VtxYZ(GXDLInfo *info, fx16 y, fx16 z);
extern void G3BS_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3BS_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha,
                             int misc);
extern void G3BS_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t,
                               GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr);
extern void G3BS_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt);
extern void G3BS_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
extern void G3BS_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess);
extern void G3BS_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z);
extern void G3BS_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb);
extern void G3BS_Shininess(GXDLInfo *info, const u32 *table);
extern void G3BS_Begin(GXDLInfo *info, GXBegin primitive);
extern void G3BS_End(GXDLInfo *info);
extern void G3BS_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw);
extern void G3BS_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2);
extern void G3BS_BoxTest(GXDLInfo *info, const GXBoxTestParam *box);
extern void G3BS_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3BS_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_UpdateGXDLInfo(GXDLInfo *info, int n);
extern void G3B_Direct0(GXDLInfo *info, int op);
extern void G3B_Direct1(GXDLInfo *info, int op, u32 param0);
extern void G3B_Direct2(GXDLInfo *info, int op, u32 param0, u32 param1);
extern void G3B_Direct3(GXDLInfo *info, int op, u32 param0, u32 param1, u32 param2);
extern void G3B_DirectN(GXDLInfo *info, int op, int nParams, const u32 *params);
extern void G3B_Nop(GXDLInfo *info);
extern void G3B_MtxMode(GXDLInfo *info, GXMtxMode mode);
extern void G3B_PushMtx(GXDLInfo *info);
extern void G3B_PopMtx(GXDLInfo *info, int num);
extern void G3B_StoreMtx(GXDLInfo *info, int num);
extern void G3B_RestoreMtx(GXDLInfo *info, int num);
extern void G3B_Identity(GXDLInfo *info);
extern void G3B_LoadMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3B_LoadMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3B_MultMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3B_MultMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3B_MultMtx33(GXDLInfo *info, const MtxFx33 *m);
extern void G3B_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3B_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3B_MultTransMtx33(GXDLInfo *info, const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3B_Color(GXDLInfo *info, GXRgb rgb);
extern void G3B_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_TexCoord(GXDLInfo *info, fx32 s, fx32 t);
extern void G3B_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_Vtx10(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_VtxXY(GXDLInfo *info, fx16 x, fx16 y);
extern void G3B_VtxXZ(GXDLInfo *info, fx16 x, fx16 z);
extern void G3B_VtxYZ(GXDLInfo *info, fx16 y, fx16 z);
extern void G3B_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha,
                            int misc);
extern void G3B_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat,
                              GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr);
extern void G3B_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt);
extern void G3B_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
extern void G3B_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess);
extern void G3B_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z);
extern void G3B_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb);
extern void G3B_Shininess(GXDLInfo *info, const u32 *table);
extern void G3B_Begin(GXDLInfo *info, GXBegin primitive);
extern void G3B_End(GXDLInfo *info);
extern void G3B_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw);
extern void G3B_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2);
extern void G3B_BoxTest(GXDLInfo *info, const GXBoxTestParam *box);
extern void G3B_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3B_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
static inline void G3BS_Direct0(GXDLInfo *info, int op) {
    *(u32 *) info->curr_cmd = (u32) op;
}
static inline void G3BS_Direct1(GXDLInfo *info, int op, u32 param0) {
    *(u32 *) info->curr_cmd = (u32) op;
    *info->curr_param       = param0;
}
static inline void G3BS_Direct2(GXDLInfo *info, int op, u32 param0, u32 param1) {
    *(u32 *) info->curr_cmd = (u32) op;
    *(info->curr_param + 0) = param0;
    *(info->curr_param + 1) = param1;
}
static inline void G3BS_Direct3(GXDLInfo *info, int op, u32 param0, u32 param1, u32 param2) {
    *(u32 *) info->curr_cmd = (u32) op;
    *(info->curr_param + 0) = param0;
    *(info->curr_param + 1) = param1;
    *(info->curr_param + 2) = param2;
}
static inline void G3BS_Nop(GXDLInfo *info) {
    G3BS_Direct0(info, 0x00);
}
static inline void G3BS_MtxMode(GXDLInfo *info, GXMtxMode mode) {
    G3BS_Direct1(info, 0x10, ((u32) ((mode) << 0)));
}
static inline void G3BS_PushMtx(GXDLInfo *info) {
    G3BS_Direct0(info, 0x11);
}
static inline void G3BS_PopMtx(GXDLInfo *info, int num) {
    G3BS_Direct1(info, 0x12, ((u32) (num)));
}
static inline void G3BS_StoreMtx(GXDLInfo *info, int num) {
    G3BS_Direct1(info, 0x13, ((u32) (num)));
}
static inline void G3BS_RestoreMtx(GXDLInfo *info, int num) {
    G3BS_Direct1(info, 0x14, ((u32) (num)));
}
static inline void G3BS_Identity(GXDLInfo *info) {
    G3BS_Direct0(info, 0x15);
}
static inline void G3BS_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z) {
    G3BS_Direct3(info, 0x1b, (u32) x, (u32) y, (u32) z);
}
static inline void G3BS_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z) {
    G3BS_Direct3(info, 0x1c, (u32) x, (u32) y, (u32) z);
}
static inline void G3BS_Color(GXDLInfo *info, GXRgb rgb) {
    G3BS_Direct1(info, 0x20, ((u32) (rgb)));
}
static inline void G3BS_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x21,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20)))));
}
static inline void G3BS_TexCoord(GXDLInfo *info, fx32 s, fx32 t) {
    G3BS_Direct1(info, 0x22, (((GXSt) ((u16) ((s16) (((s)) >> 8)) | ((u16) ((s16) (((t)) >> 8)) << 16)))));
}
static inline void G3BS_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct2(info, 0x23, ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16))), (u32) (u16) z);
}
static inline void G3BS_Vtx10(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x24,
                 ((u32) ((VecVtx10) ((((((x)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 0) |
                                     (((((y)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 10) |
                                     (((((z)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 20)))));
}
static inline void G3BS_VtxXY(GXDLInfo *info, fx16 x, fx16 y) {
    G3BS_Direct1(info, 0x25, (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((y)) << 16)))));
}
static inline void G3BS_VtxXZ(GXDLInfo *info, fx16 x, fx16 z) {
    G3BS_Direct1(info, 0x26, (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((z)) << 16)))));
}
static inline void G3BS_VtxYZ(GXDLInfo *info, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x27, (((u32) ((u32) (u16) ((y)) | ((u32) (u16) ((z)) << 16)))));
}
static inline void G3BS_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x28, (((VecVtxDiff) (((((x)) & 0x03ff) << 0) | ((((y)) & 0x03ff) << 10) | ((((z)) & 0x03ff) << 20)))));
}
static inline void G3BS_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID,
                                    int alpha, int misc) {
    G3BS_Direct1(
        info, 0x29,
        ((u32) (((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16))));
}
static inline void G3BS_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t,
                                      GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr) {
    G3BS_Direct1(info, 0x2a,
                 ((u32) (((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) |
                         ((flip) << 18) | ((pltt0) << 29))));
}
static inline void G3BS_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt) {
    u32 param = ((u32) ((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))));

    G3BS_Direct1(info, 0x2b, param);
}
static inline void G3BS_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor) {
    G3BS_Direct1(info, 0x30, ((u32) ((diffuse) | ((ambient) << 16) | ((IsSetVtxColor != 0) << 15))));
}
static inline void G3BS_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess) {
    G3BS_Direct1(info, 0x31, ((u32) ((specular) | ((emission) << 16) | ((IsShininess != 0) << 15))));
}
static inline void G3BS_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x32,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20))) |
                  ((u32) (lightID) << 30)));
}
static inline void G3BS_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb) {
    G3BS_Direct1(info, 0x33, ((u32) ((rgb) | ((u32) (lightID) << 30))));
}
static inline void G3BS_Shininess(GXDLInfo *info, const u32 *table) {
    G3BS_DirectN(info, 0x34, 32, table);
}
static inline void G3BS_Begin(GXDLInfo *info, GXBegin primitive) {
    G3BS_Direct1(info, 0x40, ((u32) ((primitive) << 0)));
}
static inline void G3BS_End(GXDLInfo *info) {
    G3BS_Direct0(info, 0x41);
}
static inline void G3BS_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw) {
    G3BS_Direct1(info, 0x50, ((u32) (((am) << 0) | ((zw) << 1))));
}
static inline void G3BS_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2) {
    G3BS_Direct1(info, 0x60, ((u32) ((x1) | ((y1) << 8) | ((x2) << 16) | ((y2) << 24))));
}
static inline void G3BS_BoxTest(GXDLInfo *info, const GXBoxTestParam *box) {
    G3BS_Direct3(info, 0x70, box->val[0], box->val[1], box->val[2]);
}
static inline void G3BS_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct2(info, 0x71, ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16))), (u32) (u16) z);
}
static inline void G3BS_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3BS_Direct1(info, 0x72,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20)))));
}
static inline void G3B_UpdateGXDLInfo(GXDLInfo *info, int n) {
    info->curr_cmd   = (u8 *) (info->curr_param + n);
    info->curr_param = (u32 *) (info->curr_cmd + 4);
}
extern void G3CS_Direct0(GXDLInfo *info, int op);
extern void G3CS_Direct1(GXDLInfo *info, int op, u32 param0);
extern void G3CS_Direct2(GXDLInfo *info, int op, u32 param0, u32 param1);
extern void G3CS_Direct3(GXDLInfo *info, int op, u32 param0, u32 param1, u32 param2);
extern void G3CS_DirectN(GXDLInfo *info, int op, int nParams, const u32 *params);
extern void G3CS_Nop(GXDLInfo *info);
extern void G3CS_MtxMode(GXDLInfo *info, GXMtxMode mode);
extern void G3CS_PushMtx(GXDLInfo *info);
extern void G3CS_PopMtx(GXDLInfo *info, int num);
extern void G3CS_StoreMtx(GXDLInfo *info, int num);
extern void G3CS_RestoreMtx(GXDLInfo *info, int num);
extern void G3CS_Identity(GXDLInfo *info);
extern void G3CS_LoadMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3CS_LoadMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3CS_MultMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3CS_MultMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3CS_MultMtx33(GXDLInfo *info, const MtxFx33 *m);
extern void G3CS_MultTransMtx33(GXDLInfo *info, const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3CS_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3CS_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3CS_Color(GXDLInfo *info, GXRgb rgb);
extern void G3CS_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3CS_TexCoord(GXDLInfo *info, fx32 s, fx32 t);
extern void G3CS_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3CS_Vtx10(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3CS_VtxXY(GXDLInfo *info, fx16 x, fx16 y);
extern void G3CS_VtxXZ(GXDLInfo *info, fx16 x, fx16 z);
extern void G3CS_VtxYZ(GXDLInfo *info, fx16 y, fx16 z);
extern void G3CS_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3CS_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha,
                             int misc);
extern void G3CS_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t,
                               GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr);
extern void G3CS_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt);
extern void G3CS_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
extern void G3CS_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess);
extern void G3CS_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z);
extern void G3CS_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb);
extern void G3CS_Shininess(GXDLInfo *info, const u32 *table);
extern void G3CS_Begin(GXDLInfo *info, GXBegin primitive);
extern void G3CS_End(GXDLInfo *info);
extern void G3CS_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw);
extern void G3CS_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2);
extern void G3CS_BoxTest(GXDLInfo *info, const GXBoxTestParam *box);
extern void G3CS_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3CS_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3C_UpdateGXDLInfo(GXDLInfo *info, int n);
extern void G3C_Direct0(GXDLInfo *info, int op);
extern void G3C_Direct1(GXDLInfo *info, int op, u32 param0);
extern void G3C_Direct2(GXDLInfo *info, int op, u32 param0, u32 param1);
extern void G3C_Direct3(GXDLInfo *info, int op, u32 param0, u32 param1, u32 param2);
extern void G3C_DirectN(GXDLInfo *info, int op, int nParams, const u32 *params);
extern void G3C_Nop(GXDLInfo *info);
extern void G3C_MtxMode(GXDLInfo *info, GXMtxMode mode);
extern void G3C_PushMtx(GXDLInfo *info);
extern void G3C_PopMtx(GXDLInfo *info, int num);
extern void G3C_StoreMtx(GXDLInfo *info, int num);
extern void G3C_RestoreMtx(GXDLInfo *info, int num);
extern void G3C_Identity(GXDLInfo *info);
extern void G3C_LoadMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3C_LoadMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3C_MultMtx44(GXDLInfo *info, const MtxFx44 *m);
extern void G3C_MultMtx43(GXDLInfo *info, const MtxFx43 *m);
extern void G3C_MultMtx33(GXDLInfo *info, const MtxFx33 *m);
extern void G3C_MultTransMtx33(GXDLInfo *info, const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3C_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3C_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z);
extern void G3C_Color(GXDLInfo *info, GXRgb rgb);
extern void G3C_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3C_TexCoord(GXDLInfo *info, fx32 s, fx32 t);
extern void G3C_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3C_Vtx10(GXDLInfo *info, fx16, fx16, fx16);
extern void G3C_VtxXY(GXDLInfo *info, fx16 x, fx16 y);
extern void G3C_VtxXZ(GXDLInfo *info, fx16 x, fx16 z);
extern void G3C_VtxYZ(GXDLInfo *info, fx16 y, fx16 z);
extern void G3C_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3C_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha,
                            int misc);
extern void G3C_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat,
                              GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr);
extern void G3C_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt);
extern void G3C_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
extern void G3C_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess);
extern void G3C_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z);
extern void G3C_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb);
extern void G3C_Shininess(GXDLInfo *info, const u32 *table);
extern void G3C_Begin(GXDLInfo *info, GXBegin primitive);
extern void G3C_End(GXDLInfo *info);
extern void G3C_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw);
extern void G3C_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2);
extern void G3C_BoxTest(GXDLInfo *info, const GXBoxTestParam *box);
extern void G3C_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
extern void G3C_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z);
static inline void G3CS_Nop(GXDLInfo *info) {
    G3CS_Direct0(info, 0x00);
}
static inline void G3CS_MtxMode(GXDLInfo *info, GXMtxMode mode) {
    G3CS_Direct1(info, 0x10, ((u32) ((mode) << 0)));
}
static inline void G3CS_PushMtx(GXDLInfo *info) {
    G3CS_Direct0(info, 0x11);
}
static inline void G3CS_PopMtx(GXDLInfo *info, int num) {
    G3CS_Direct1(info, 0x12, ((u32) (num)));
}
static inline void G3CS_StoreMtx(GXDLInfo *info, int num) {
    G3CS_Direct1(info, 0x13, ((u32) (num)));
}
static inline void G3CS_RestoreMtx(GXDLInfo *info, int num) {
    G3CS_Direct1(info, 0x14, ((u32) (num)));
}
static inline void G3CS_Identity(GXDLInfo *info) {
    G3CS_Direct0(info, 0x15);
}
static inline void G3CS_Scale(GXDLInfo *info, fx32 x, fx32 y, fx32 z) {
    G3CS_Direct3(info, 0x1b, (u32) x, (u32) y, (u32) z);
}
static inline void G3CS_Translate(GXDLInfo *info, fx32 x, fx32 y, fx32 z) {
    G3CS_Direct3(info, 0x1c, (u32) x, (u32) y, (u32) z);
}
static inline void G3CS_Color(GXDLInfo *info, GXRgb rgb) {
    G3CS_Direct1(info, 0x20, ((u32) (rgb)));
}
static inline void G3CS_Normal(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x21,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20)))));
}
static inline void G3CS_TexCoord(GXDLInfo *info, fx32 s, fx32 t) {
    G3CS_Direct1(info, 0x22, (((GXSt) ((u16) ((s16) (((s)) >> 8)) | ((u16) ((s16) (((t)) >> 8)) << 16)))));
}
static inline void G3CS_Vtx(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct2(info, 0x23, ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16))), (u32) (u16) z);
}
static inline void G3CS_Vtx10(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x24,
                 ((u32) ((VecVtx10) ((((((x)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 0) |
                                     (((((y)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 10) |
                                     (((((z)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 20)))));
}
static inline void G3CS_VtxXY(GXDLInfo *info, fx16 x, fx16 y) {
    G3CS_Direct1(info, 0x25, (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((y)) << 16)))));
}
static inline void G3CS_VtxXZ(GXDLInfo *info, fx16 x, fx16 z) {
    G3CS_Direct1(info, 0x26, (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((z)) << 16)))));
}
static inline void G3CS_VtxYZ(GXDLInfo *info, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x27, (((u32) ((u32) (u16) ((y)) | ((u32) (u16) ((z)) << 16)))));
}
static inline void G3CS_VtxDiff(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x28, (((VecVtxDiff) (((((x)) & 0x03ff) << 0) | ((((y)) & 0x03ff) << 10) | ((((z)) & 0x03ff) << 20)))));
}
static inline void G3CS_PolygonAttr(GXDLInfo *info, int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID,
                                    int alpha, int misc) {
    G3CS_Direct1(
        info, 0x29,
        ((u32) (((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16))));
}
static inline void G3CS_TexImageParam(GXDLInfo *info, GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t,
                                      GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr) {
    G3CS_Direct1(info, 0x2a,
                 ((u32) (((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) |
                         ((flip) << 18) | ((pltt0) << 29))));
}
static inline void G3CS_TexPlttBase(GXDLInfo *info, u32 addr, GXTexFmt texfmt) {
    u32 param = ((u32) ((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))));

    G3CS_Direct1(info, 0x2b, param);
}
static inline void G3CS_MaterialColorDiffAmb(GXDLInfo *info, GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor) {
    G3CS_Direct1(info, 0x30, ((u32) ((diffuse) | ((ambient) << 16) | ((IsSetVtxColor != 0) << 15))));
}
static inline void G3CS_MaterialColorSpecEmi(GXDLInfo *info, GXRgb specular, GXRgb emission, BOOL IsShininess) {
    G3CS_Direct1(info, 0x31, ((u32) ((specular) | ((emission) << 16) | ((IsShininess != 0) << 15))));
}
static inline void G3CS_LightVector(GXDLInfo *info, GXLightId lightID, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x32,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20))) |
                  ((u32) (lightID) << 30)));
}
static inline void G3CS_LightColor(GXDLInfo *info, GXLightId lightID, GXRgb rgb) {
    G3CS_Direct1(info, 0x33, ((u32) ((rgb) | ((u32) (lightID) << 30))));
}
static inline void G3CS_Shininess(GXDLInfo *info, const u32 *table) {
    G3CS_DirectN(info, 0x34, 32, table);
}
static inline void G3CS_Begin(GXDLInfo *info, GXBegin primitive) {
    G3CS_Direct1(info, 0x40, ((u32) ((primitive) << 0)));
}
static inline void G3CS_End(GXDLInfo *info) {
    G3CS_Direct0(info, 0x41);
}
static inline void G3CS_SwapBuffers(GXDLInfo *info, GXSortMode am, GXBufferMode zw) {
    G3CS_Direct1(info, 0x50, ((u32) (((am) << 0) | ((zw) << 1))));
}
static inline void G3CS_ViewPort(GXDLInfo *info, int x1, int y1, int x2, int y2) {
    G3CS_Direct1(info, 0x60, ((u32) ((x1) | ((y1) << 8) | ((x2) << 16) | ((y2) << 24))));
}
static inline void G3CS_BoxTest(GXDLInfo *info, const GXBoxTestParam *box) {
    G3CS_Direct3(info, 0x70, box->val[0], box->val[1], box->val[2]);
}
static inline void G3CS_PositionTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct2(info, 0x71, ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16))), (u32) (u16) z);
}
static inline void G3CS_VectorTest(GXDLInfo *info, fx16 x, fx16 y, fx16 z) {
    G3CS_Direct1(info, 0x72,
                 ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                    (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                    (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20)))));
}
extern void G3_Direct0(int op);
extern void G3_Direct1(int op, u32 param0);
extern void G3_Direct2(int op, u32 param0, u32 param1);
extern void G3_Direct3(int op, u32 param0, u32 param1, u32 param2);
extern void G3_MtxMode(GXMtxMode mode);
extern void G3_PushMtx(void);
extern void G3_PopMtx(int num);
extern void G3_StoreMtx(int num);
extern void G3_RestoreMtx(int num);
extern void G3_Identity(void);
extern void G3_LoadMtx44(const MtxFx44 *m);
extern void G3_LoadMtx43(const MtxFx43 *m);
extern void G3_MultMtx44(const MtxFx44 *m);
extern void G3_MultMtx43(const MtxFx43 *m);
extern void G3_MultMtx33(const MtxFx33 *m);
extern void G3_MultTransMtx33(const MtxFx33 *mtx, const VecFx32 *trans);
extern void G3_Scale(fx32 x, fx32 y, fx32 z);
extern void G3_Translate(fx32 x, fx32 y, fx32 z);
extern void G3_Color(GXRgb rgb);
extern void G3_Normal(fx16 x, fx16 y, fx16 z);
extern void G3_TexCoord(fx32 s, fx32 t);
extern void G3_Vtx(fx16 x, fx16 y, fx16 z);
extern void G3_Vtx10(fx16 x, fx16 y, fx16 z);
extern void G3_VtxXY(fx16 x, fx16 y);
extern void G3_VtxXZ(fx16 x, fx16 z);
extern void G3_VtxYZ(fx16 y, fx16 z);
extern void G3_VtxDiff(fx16 x, fx16 y, fx16 z);
extern void G3_PolygonAttr(int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc);
extern void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip,
                             GXTexPlttColor0 pltt0, u32 addr);
extern void G3_TexPlttBase(u32 addr, GXTexFmt texfmt);
extern void G3_MaterialColorDiffAmb(GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor);
extern void G3_MaterialColorSpecEmi(GXRgb specular, GXRgb emission, BOOL IsShininess);
extern void G3_LightVector(GXLightId lightID, fx16 x, fx16 y, fx16 z);
extern void G3_LightColor(GXLightId lightID, GXRgb rgb);
extern void G3_Shininess(const u32 *table);
extern void G3_Begin(GXBegin primitive);
extern void G3_End(void);
extern void G3_SwapBuffers(GXSortMode am, GXBufferMode zw);
extern void G3_ViewPort(int x1, int y1, int x2, int y2);
extern void G3_BoxTest(const GXBoxTestParam *box);
extern void G3_PositionTest(fx16 x, fx16 y, fx16 z);
extern void G3_VectorTest(fx16 x, fx16 y, fx16 z);
static inline void G3_Direct0(int op) {
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = 0;
}
static inline void G3_Direct1(int op, u32 param0) {
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param0;
}
static inline void G3_Direct2(int op, u32 param0, u32 param1) {
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param0;
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param1;
}
static inline void G3_Direct3(int op, u32 param0, u32 param1, u32 param2) {
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param0;
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param1;
    *(REGType32v *) ((0x04000000 + 0x440) + ((op - 0x10) * 4)) = param2;
}
static inline void G3_MtxMode(GXMtxMode mode) {
    (*(REGType32v *) (0x04000000 + 0x440)) = ((u32) ((mode) << 0));
}
static inline void G3_PushMtx() {
    (*(REGType32v *) (0x04000000 + 0x444)) = 0;
}
static inline void G3_PopMtx(int num) {
    (*(REGType32v *) (0x04000000 + 0x448)) = ((u32) (num));
}
static inline void G3_StoreMtx(int num) {
    (*(REGType32v *) (0x04000000 + 0x44c)) = ((u32) (num));
}
static inline void G3_RestoreMtx(int num) {
    (*(REGType32v *) (0x04000000 + 0x450)) = ((u32) (num));
}
static inline void G3_Identity() {
    (*(REGType32v *) (0x04000000 + 0x454)) = 0;
}
static inline void G3_Scale(fx32 x, fx32 y, fx32 z) {
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) x;
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) y;
    (*(REGType32v *) (0x04000000 + 0x46c)) = (u32) z;
}
static inline void G3_Translate(fx32 x, fx32 y, fx32 z) {
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) x;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) y;
    (*(REGType32v *) (0x04000000 + 0x470)) = (u32) z;
}
static inline void G3_Color(GXRgb rgb) {
    (*(REGType32v *) (0x04000000 + 0x480)) = ((u32) (rgb));
}
static inline void G3_Normal(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x484)) = ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                                                (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                                                (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20))));
}
static inline void G3_TexCoord(fx32 s, fx32 t) {
    (*(REGType32v *) (0x04000000 + 0x488)) = (((GXSt) ((u16) ((s16) (((s)) >> 8)) | ((u16) ((s16) (((t)) >> 8)) << 16))));
}
static inline void G3_Vtx(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x48c)) = ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16)));
    (*(REGType32v *) (0x04000000 + 0x48c)) = (u32) (u16) z;
}
static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x490)) = ((u32) ((VecVtx10) ((((((x)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 0) |
                                                                 (((((y)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 10) |
                                                                 (((((z)) >> (12 - 6)) & (0x01c0 | 0x003f | 0x0200)) << 20))));
}
static inline void G3_VtxXY(fx16 x, fx16 y) {
    (*(REGType32v *) (0x04000000 + 0x494)) = (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((y)) << 16))));
}
static inline void G3_VtxXZ(fx16 x, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x498)) = (((u32) ((u32) (u16) ((x)) | ((u32) (u16) ((z)) << 16))));
}
static inline void G3_VtxYZ(fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x49c)) = (((u32) ((u32) (u16) ((y)) | ((u32) (u16) ((z)) << 16))));
}
static inline void G3_VtxDiff(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x4a0)) =
        (((VecVtxDiff) (((((x)) & 0x03ff) << 0) | ((((y)) & 0x03ff) << 10) | ((((z)) & 0x03ff) << 20))));
}
static inline void G3_PolygonAttr(int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc) {
    (*(REGType32v *) (0x04000000 + 0x4a4)) =
        ((u32) (((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)));
}
static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat,
                                    GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr) {
    (*(REGType32v *) (0x04000000 + 0x4a8)) = ((u32) (((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) |
                                                     ((t) << 23) | ((repeat) << 16) | ((flip) << 18) | ((pltt0) << 29)));
}
static inline void G3_TexPlttBase(u32 addr, GXTexFmt texfmt) {
    u32 param = ((u32) ((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))));

    (*(REGType32v *) (0x04000000 + 0x4ac)) = param;
}
static inline void G3_MaterialColorDiffAmb(GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor) {
    (*(REGType32v *) (0x04000000 + 0x4c0)) = ((u32) ((diffuse) | ((ambient) << 16) | ((IsSetVtxColor != 0) << 15)));
}
static inline void G3_MaterialColorSpecEmi(GXRgb specular, GXRgb emission, BOOL IsShininess) {
    (*(REGType32v *) (0x04000000 + 0x4c4)) = ((u32) ((specular) | ((emission) << 16) | ((IsShininess != 0) << 15)));
}
static inline void G3_LightVector(GXLightId lightID, fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x4c8)) = ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                                                (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                                                (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20))) |
                                              ((u32) (lightID) << 30));
}
static inline void G3_LightColor(GXLightId lightID, GXRgb rgb) {
    (*(REGType32v *) (0x04000000 + 0x4cc)) = ((u32) ((rgb) | ((u32) (lightID) << 30)));
}
static inline void G3_Begin(GXBegin primitive) {
    (*(REGType32v *) (0x04000000 + 0x500)) = ((u32) ((primitive) << 0));
}
static inline void G3_End() {
    (*(REGType32v *) (0x04000000 + 0x504)) = 0;
}
static inline void G3_SwapBuffers(GXSortMode am, GXBufferMode zw) {
    (*(REGType32v *) (0x04000000 + 0x540)) = ((u32) (((am) << 0) | ((zw) << 1)));
}
static inline void G3_ViewPort(int x1, int y1, int x2, int y2) {
    (*(REGType32v *) (0x04000000 + 0x580)) = ((u32) ((x1) | ((y1) << 8) | ((x2) << 16) | ((y2) << 24)));
}
static inline void G3_BoxTest(const GXBoxTestParam *box) {
    (*(REGType32v *) (0x04000000 + 0x5c0)) = box->val[0];
    (*(REGType32v *) (0x04000000 + 0x5c0)) = box->val[1];
    (*(REGType32v *) (0x04000000 + 0x5c0)) = box->val[2];
}
static inline void G3_PositionTest(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x5c4)) = ((u32) ((u32) (u16) (x) | ((u32) (u16) (y) << 16)));
    (*(REGType32v *) (0x04000000 + 0x5c4)) = (u32) (u16) z;
}
static inline void G3_VectorTest(fx16 x, fx16 y, fx16 z) {
    (*(REGType32v *) (0x04000000 + 0x5c8)) = ((u32) ((VecFx10) ((((((x)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 0) |
                                                                (((((y)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 10) |
                                                                (((((z)) >> (12 - 9)) & (0x0000 | 0x01ff | 0x0200)) << 20))));
}
extern void GX_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte);
extern void GX_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte);
extern void GXS_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(const void *pSrc, u32 destSlotAddr, u32 szByte);
extern void GX_EndLoadTex(void);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
extern void GX_EndLoadTexPltt(void);
extern void G3i_FrustumW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
extern void G3i_PerspectiveW_(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
extern void G3i_OrthoW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, BOOL draw, MtxFx44 *mtx);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, BOOL draw, MtxFx43 *mtx);
static inline void G3_Frustum(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_FrustumW_(t, b, l, r, n, f, ((fx32) 0x0000000000001000L), 1, mtx);
}
static inline void G3_Perspective(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_PerspectiveW_(fovySin, fovyCos, aspect, n, f, ((fx32) 0x0000000000001000L), 1, mtx);
}
static inline void G3_Ortho(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_OrthoW_(t, b, l, r, n, f, ((fx32) 0x0000000000001000L), 1, mtx);
}
static inline void G3_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_FrustumW_(t, b, l, r, n, f, scaleW, 1, mtx);
}
static inline void G3_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_PerspectiveW_(fovySin, fovyCos, aspect, n, f, scaleW, 1, mtx);
}
static inline void G3_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_OrthoW_(t, b, l, r, n, f, scaleW, 1, mtx);
}
static inline void G3_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx) {
    G3i_LookAt_(camPos, camUp, target, 1, mtx);
}
typedef struct {
    union {
        u32 attr01;
        struct {
            u16 attr0;
            u16 attr1;
        };
        struct {
            u32 y : 8;
            u32 rsMode : 2;
            u32 objMode : 2;
            u32 mosaic : 1;
            u32 colorMode : 1;
            u32 shape : 2;

            u32 x : 9;
            u32 rsParam : 5;
            u32 size : 2;
        };
        struct {
            u32 _0 : 28;
            u32 flipH : 1;
            u32 flipV : 1;
            u32 _1 : 2;
        };
    };
    union {
        struct {
            u16 attr2;
            u16 _3;
        };
        u32 attr23;
        struct {
            u32 charNo : 10;
            u32 priority : 2;
            u32 cParam : 4;
            u32 _2 : 16;
        };
    };
} GXOamAttr;
typedef struct GXOamAffine_ {
    u16 _0;
    u16 _1;
    u16 _2;
    s16 PA;
    u16 _4;
    u16 _5;
    u16 _6;
    s16 PB;
    u16 _8;
    u16 _9;
    u16 _10;
    s16 PC;
    u16 _12;
    u16 _13;
    u16 _14;
    s16 PD;
} GXOamAffine;
typedef enum {
    GX_OAM_SHAPE_8x8   = (0 << 14) | (0 << 30),
    GX_OAM_SHAPE_16x16 = (0 << 14) | (1 << 30),
    GX_OAM_SHAPE_32x32 = (0 << 14) | (2 << 30),
    GX_OAM_SHAPE_64x64 = (0 << 14) | (3 << 30),
    GX_OAM_SHAPE_16x8  = (1 << 14) | (0 << 30),
    GX_OAM_SHAPE_32x8  = (1 << 14) | (1 << 30),
    GX_OAM_SHAPE_32x16 = (1 << 14) | (2 << 30),
    GX_OAM_SHAPE_64x32 = (1 << 14) | (3 << 30),
    GX_OAM_SHAPE_8x16  = (2 << 14) | (0 << 30),
    GX_OAM_SHAPE_8x32  = (2 << 14) | (1 << 30),
    GX_OAM_SHAPE_16x32 = (2 << 14) | (2 << 30),
    GX_OAM_SHAPE_32x64 = (2 << 14) | (3 << 30)
} GXOamShape;
typedef enum {
    GX_OAM_COLORMODE_16  = 0,
    GX_OAM_COLORMODE_256 = 1
} GXOamColorMode;
typedef enum {
    GX_OAM_EFFECT_NONE          = (0 << 8) | (0 << 28) | (0 << 29),
    GX_OAM_EFFECT_FLIP_H        = (0 << 8) | (1 << 28) | (0 << 29),
    GX_OAM_EFFECT_FLIP_V        = (0 << 8) | (0 << 28) | (1 << 29),
    GX_OAM_EFFECT_FLIP_HV       = (0 << 8) | (1 << 28) | (1 << 29),
    GX_OAM_EFFECT_AFFINE        = (1 << 8),
    GX_OAM_EFFECT_NODISPLAY     = (2 << 8),
    GX_OAM_EFFECT_AFFINE_DOUBLE = (3 << 8)
} GXOamEffect;
typedef enum {
    GX_OAM_MODE_NORMAL    = 0,
    GX_OAM_MODE_XLU       = 1,
    GX_OAM_MODE_OBJWND    = 2,
    GX_OAM_MODE_BITMAPOBJ = 3
} GXOamMode;
static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y) {
    oam->attr01 = ((oam->attr01 & ~(0x000000ff | 0x01ff0000)) | (y & 0x000000ff) | ((x & (0x01ff0000 >> 16)) << 16));
}
static inline void G2_GetOBJPosition(const GXOamAttr *oam, u32 *x, u32 *y) {
    *x = (oam->attr01 & 0x01ff0000) >> 16;
    *y = oam->attr01 & 0x000000ff;
}
static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority) {
    oam->attr2 = (u16) ((oam->attr2 & ~0x0c00) | (priority << 10));
}
static inline int G2_GetOBJPriority(const GXOamAttr *oam) {
    return (oam->attr2 & 0x0c00) >> 10;
}
static inline void G2_SetOBJMode(GXOamAttr *oam, GXOamMode mode, int cParam) {
    oam->attr01 = ((oam->attr01 & ~0x00000c00) | (mode << 10));

    oam->attr2 = (u16) ((oam->attr2 & ~0xf000) | (cParam << 12));
}
static inline GXOamMode G2_GetOBJMode(const GXOamAttr *oam) {
    return (GXOamMode) ((oam->attr01 & 0x00000c00) >> 10);
}
static inline int G2_GetOBJColorParam(const GXOamAttr *oam) {
    return (oam->attr2 & 0xf000) >> 12;
}
static inline void G2_SetOBJEffect(GXOamAttr *oam, GXOamEffect effect, int rsParam) {
    if (GX_OAM_EFFECT_AFFINE != effect && GX_OAM_EFFECT_AFFINE_DOUBLE != effect) {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) | effect);
    } else {
        oam->attr01 = ((oam->attr01 & ~(0x00000300 | 0x3e000000)) | effect | (rsParam << 25));
    }
}
static inline GXOamEffect G2_GetOBJEffect(const GXOamAttr *oam) {
    GXOamEffect effect;

    effect = (GXOamEffect) (oam->attr01 & 0x00000300);

    if (effect == GX_OAM_EFFECT_AFFINE || effect == GX_OAM_EFFECT_AFFINE_DOUBLE) {
        return effect;
    }

    return (GXOamEffect) (effect | (oam->attr01 & 0x30000000));
}
static inline void G2_SetOBJShape(GXOamAttr *oam, GXOamShape shape) {
    oam->attr01 = ((oam->attr01 & ~(0x0000c000 | 0xc0000000)) | shape);
}
static inline GXOamShape G2_GetOBJShape(const GXOamAttr *oam) {
    return (GXOamShape) (oam->attr01 & (0x0000c000 | 0xc0000000));
}
static inline void G2_SetOBJCharName(GXOamAttr *oam, int name) {
    oam->attr2 = (u16) ((oam->attr2 & ~0x03ff) | name);
}
static inline int G2_GetOBJCharName(const GXOamAttr *oam) {
    return oam->attr2 & 0x03ff;
}
static inline void G2_SetOBJColorMode(GXOamAttr *oam, GXOamColorMode color) {
    oam->attr01 = ((oam->attr01 & ~0x00002000) | (color << 13));
}
static inline GXOamColorMode G2_GetOBJColorMode(const GXOamAttr *oam) {
    return (GXOamColorMode) ((oam->attr01 & 0x00002000) >> 13);
}
static inline void G2_OBJMosaic(GXOamAttr *oam, BOOL enable) {
    if (enable) {
        oam->attr01 |= (1 << 12);
    } else {
        oam->attr01 &= ~(1 << 12);
    }
}
static inline void G2_SetOBJAffine(GXOamAffine *oam, const MtxFx22 *mtx) {
    oam->PA = (s16) (mtx->_00 >> 4);
    oam->PB = (s16) (mtx->_01 >> 4);
    oam->PC = (s16) (mtx->_10 >> 4);
    oam->PD = (s16) (mtx->_11 >> 4);
}
static inline void G2_GetOBJAffine(const GXOamAffine *oam, MtxFx22 *mtx) {

    mtx->_00 = (fx32) (oam->PA << 4);
    mtx->_01 = (fx32) (oam->PB << 4);
    mtx->_10 = (fx32) (oam->PC << 4);
    mtx->_11 = (fx32) (oam->PD << 4);
}
typedef u16 GXScrFmtText;
typedef u8 GXScrFmtAffine;
typedef u8 GXScrFmt256Bmp;
typedef union {
    u32 data32[8];
    u16 data16[16];
    u8 data8[32];
} GXCharFmt16;
typedef union {
    u32 data32[16];
    u16 data16[32];
    u8 data8[64];
} GXCharFmt256;
typedef union {
    u16 data16[16];
    u32 data32[8];
    GXRgb rgb[16];
} GXBGPltt16;
typedef GXBGPltt16 GXOBJPltt16;
typedef union {
    u16 data16[256];
    u32 data32[128];
    GXRgb rgb[256];
} GXBGPltt256;
typedef GXBGPltt256 GXOBJPltt256;
typedef union {
    u16 data16[32 * 32];
    u32 data32[32 * 32 / 2];
    GXScrFmtText scr[32][32];
} GXScrText32x32;
typedef union {
    u16 data16[64 * 32];
    u32 data32[64 * 32 / 2];
    GXScrFmtText scr[64][32];
} GXScrText64x32;
typedef union {
    u16 data16[32 * 64];
    u32 data32[32 * 64 / 2];
    GXScrFmtText scr[32][64];
} GXScrText32x64;
typedef union {
    u16 data16[64 * 64];
    u32 data32[64 * 64 / 2];
    GXScrFmtText scr[64][64];
} GXScrText64x64;
typedef union {
    u8 data8[16 * 16];
    u32 data32[16 * 16 / 4];
    GXScrFmtAffine scr[16][16];
} GXScrAffine16x16;
typedef union {
    u8 data8[32 * 32];
    u32 data32[32 * 32 / 4];
    GXScrFmtAffine scr[32][32];
} GXScrAffine32x32;
typedef union {
    u8 data8[64 * 64];
    u32 data32[64 * 64 / 4];
    GXScrFmtAffine scr[64][64];
} GXScrAffine64x64;
typedef union {
    u8 data8[128 * 128];
    u32 data32[128 * 128 / 4];
    GXScrFmtAffine scr[128][128];
} GXScrAffine128x128;
typedef union {
    u8 data8[128 * 128];
    u32 data32[128 * 128 / 4];
    GXScrFmt256Bmp scr[128][128];
} GXScr256Bmp128x128;
typedef union {
    u8 data8[256 * 256];
    u32 data32[256 * 256 / 4];
    GXScrFmt256Bmp scr[256][256];
} GXScr256Bmp256x256;
typedef union {
    u8 data8[512 * 256];
    u32 data32[512 * 256 / 4];
    GXScrFmt256Bmp scr[512][256];
} GXScr256Bmp512x256;
typedef union {
    u8 data8[512 * 512];
    u32 data32[512 * 512 / 4];
    GXScrFmt256Bmp scr[512][512];
} GXScr256Bmp512x512;
typedef union {
    u16 data16[128 * 128];
    u32 data32[128 * 128 / 2];
    GXRgba scr[128][128];
} GXScrDCBmp128x128;
typedef union {
    u16 data16[256 * 256];
    u32 data32[256 * 256 / 2];
    GXRgba scr[256][256];
} GXScrDCBmp256x256;
typedef union {
    u16 data16[512 * 256];
    u32 data32[512 * 256 / 2];
    GXRgba scr[512][256];
} GXScrDCBmp512x256;
typedef union {
    u16 data16[512 * 512];
    u32 data32[512 * 512 / 2];
    GXRgba scr[512][512];
} GXScrDCBmp512x512;
typedef struct {
    GXCharFmt16 ch[1024];
} GXCharBGText16;
typedef struct {
    GXCharFmt256 ch[1024];
} GXCharBGText256;
typedef struct {
    GXCharFmt256 ch[256];
} GXCharBGAffine256;
typedef union {
    GXBGPltt256 pltt256;
    GXBGPltt16 pltt16[16];
} GXBGStdPlttData;
typedef union {
    GXOBJPltt256 pltt256;
    GXOBJPltt16 pltt16[16];
} GXOBJStdPlttData;
typedef struct {
    GXBGStdPlttData bgPltt;
    GXOBJStdPlttData objPltt;
} GXStdPlttData;
typedef struct {
    GXBGPltt256 pltt256[16];
} GXBGExtPlttData;
typedef struct {
    GXOBJPltt256 pltt256[16];
} GXOBJExtPlttData;
typedef void (*WMcallbackFunc)(void *arg);
typedef void (*WMCallbackFunc)(void *arg);
typedef enum WMApiid {
    WM_APIID_INITIALIZE = 0,
    WM_APIID_RESET,
    WM_APIID_END,

    WM_APIID_ENABLE,
    WM_APIID_DISABLE,
    WM_APIID_POWER_ON,
    WM_APIID_POWER_OFF,

    WM_APIID_SET_P_PARAM,
    WM_APIID_START_PARENT,
    WM_APIID_END_PARENT,
    WM_APIID_START_SCAN,
    WM_APIID_END_SCAN,
    WM_APIID_START_CONNECT,
    WM_APIID_DISCONNECT,
    WM_APIID_START_MP,
    WM_APIID_SET_MP_DATA,
    WM_APIID_END_MP,
    WM_APIID_START_DCF,
    WM_APIID_SET_DCF_DATA,
    WM_APIID_END_DCF,
    WM_APIID_SET_WEPKEY,
    WM_APIID_START_KS,
    WM_APIID_END_KS,
    WM_APIID_GET_KEYSET,
    WM_APIID_SET_GAMEINFO,
    WM_APIID_SET_BEACON_IND,
    WM_APIID_START_TESTMODE,
    WM_APIID_STOP_TESTMODE,
    WM_APIID_VALARM_MP,
    WM_APIID_SET_LIFETIME,
    WM_APIID_MEASURE_CHANNEL,
    WM_APIID_INIT_W_COUNTER,
    WM_APIID_GET_W_COUNTER,
    WM_APIID_SET_ENTRY,
    WM_APIID_AUTO_DEAUTH,
    WM_APIID_SET_MP_PARAMETER,
    WM_APIID_SET_BEACON_PERIOD,
    WM_APIID_AUTO_DISCONNECT,
    WM_APIID_START_SCAN_EX,
    WM_APIID_SET_WEPKEY_EX,
    WM_APIID_SET_PS_MODE,
    WM_APIID_START_TESTRXMODE,
    WM_APIID_STOP_TESTRXMODE,

    WM_APIID_KICK_MP_PARENT,
    WM_APIID_KICK_MP_CHILD,
    WM_APIID_KICK_MP_RESUME,

    WM_APIID_ASYNC_KIND_MAX,

    WM_APIID_INDICATION = 128,
    WM_APIID_PORT_SEND,
    WM_APIID_PORT_RECV,
    WM_APIID_READ_STATUS,

    WM_APIID_UNKNOWN = 255
} WMApiid;
typedef enum WMPort {

    WM_PORT_RAWDATA    = 0,
    WM_PORT_BT         = 1,
    WM_PORT_RESERVE_02 = 2,
    WM_PORT_RESERVE_03 = 3,

    WM_PORT_RESERVE_10 = 8,
    WM_PORT_RESERVE_11 = 9,
    WM_PORT_RESERVE_12 = 10,
    WM_PORT_RESERVE_13 = 11
} WMPort;
typedef enum WMPriorityLevel {
    WM_PRIORITY_URGENT = 0,
    WM_PRIORITY_HIGH,
    WM_PRIORITY_NORMAL,
    WM_PRIORITY_LOW
} WMPriorityLevel;
typedef enum WMErrCode {
    WM_ERRCODE_SUCCESS            = 0,
    WM_ERRCODE_FAILED             = 1,
    WM_ERRCODE_OPERATING          = 2,
    WM_ERRCODE_ILLEGAL_STATE      = 3,
    WM_ERRCODE_WM_DISABLE         = 4,
    WM_ERRCODE_NO_KEYSET          = 5,
    WM_ERRCODE_NO_DATASET         = 5,
    WM_ERRCODE_INVALID_PARAM      = 6,
    WM_ERRCODE_NO_CHILD           = 7,
    WM_ERRCODE_FIFO_ERROR         = 8,
    WM_ERRCODE_TIMEOUT            = 9,
    WM_ERRCODE_SEND_QUEUE_FULL    = 10,
    WM_ERRCODE_NO_ENTRY           = 11,
    WM_ERRCODE_OVER_MAX_ENTRY     = 12,
    WM_ERRCODE_INVALID_POLLBITMAP = 13,
    WM_ERRCODE_NO_DATA            = 14,
    WM_ERRCODE_SEND_FAILED        = 15,

    WM_ERRCODE_DCF_TEST,
    WM_ERRCODE_WL_INVALID_PARAM,
    WM_ERRCODE_WL_LENGTH_ERR,

    WM_ERRCODE_FLASH_ERROR,
    WM_ERRCODE_MAX
} WMErrCode;
typedef enum WMStateCode {
    WM_STATECODE_PARENT_START = 0,
    WM_STATECODE_BEACON_SENT  = 2,

    WM_STATECODE_SCAN_START       = 3,
    WM_STATECODE_PARENT_NOT_FOUND = 4,
    WM_STATECODE_PARENT_FOUND     = 5,

    WM_STATECODE_CONNECT_START = 6,
    WM_STATECODE_BEACON_LOST   = 8,

    WM_STATECODE_CONNECTED                = 7,
    WM_STATECODE_CHILD_CONNECTED          = 7,
    WM_STATECODE_DISCONNECTED             = 9,
    WM_STATECODE_DISCONNECTED_FROM_MYSELF = 26,

    WM_STATECODE_MP_START  = 10,
    WM_STATECODE_MPEND_IND = 11,
    WM_STATECODE_MP_IND    = 12,
    WM_STATECODE_MPACK_IND = 13,

    WM_STATECODE_DCF_START = 14,
    WM_STATECODE_DCF_IND   = 15,

    WM_STATECODE_BEACON_RECV  = 16,
    WM_STATECODE_DISASSOCIATE = 17,
    WM_STATECODE_REASSOCIATE  = 18,
    WM_STATECODE_AUTHENTICATE = 19,

    WM_STATECODE_PORT_INIT = 25,
    WM_STATECODE_PORT_SEND = 20,
    WM_STATECODE_PORT_RECV = 21,

    WM_STATECODE_FIFO_ERROR  = 22,
    WM_STATECODE_INFORMATION = 23,
    WM_STATECODE_UNKNOWN     = 24,

    WM_STATECODE_MAX = 27
} WMStateCode;
typedef enum WMState {
    WM_STATE_READY = 0,
    WM_STATE_STOP,
    WM_STATE_IDLE,
    WM_STATE_CLASS1,
    WM_STATE_TESTMODE,
    WM_STATE_SCAN,
    WM_STATE_CONNECT,
    WM_STATE_PARENT,
    WM_STATE_CHILD,
    WM_STATE_MP_PARENT,
    WM_STATE_MP_CHILD,
    WM_STATE_DCF_CHILD,
    WM_STATE_TESTMODE_RX,
    WM_STATE_MAX
} WMState;
typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1,
    WM_LINK_LEVEL_2,
    WM_LINK_LEVEL_3,
    WM_LINK_LEVEL_MAX
} WMLinkLevel;
typedef enum WMDataSharingState {
    WM_DS_STATE_READY = 0,
    WM_DS_STATE_START,
    WM_DS_STATE_PAUSING,
    WM_DS_STATE_PAUSED,
    WM_DS_STATE_RETRY_SEND,
    WM_DS_STATE_ERROR
} WMDataSharingState;
typedef enum WMDisconnectReason {

    WM_DISCONNECT_REASON_RESERVED                    = 0,
    WM_DISCONNECT_REASON_UNSPECIFIED                 = 1,
    WM_DISCONNECT_REASON_PREV_AUTH_INVALID           = 2,
    WM_DISCONNECT_REASON_DEAUTH_LEAVING              = 3,
    WM_DISCONNECT_REASON_INACTIVE                    = 4,
    WM_DISCONNECT_REASON_UNABLE_HANDLE               = 5,
    WM_DISCONNECT_REASON_RX_CLASS2_FROM_NONAUTH_STA  = 6,
    WM_DISCONNECT_REASON_RX_CLASS3_FROM_NONASSOC_STA = 7,
    WM_DISCONNECT_REASON_DISASSOC_LEAVING            = 8,
    WM_DISCONNECT_REASON_ASSOC_STA_NOTAUTHED         = 9,

    WM_DISCONNECT_REASON_NO_ENTRY = 19,

    WM_DISCONNECT_REASON_MP_LIFETIME  = 0x8001,
    WM_DISCONNECT_REASON_TGID_CHANGED = 0x8002,
    WM_DISCONNECT_REASON_FATAL_ERROR  = 0x8003,

    WM_DISCONNECT_REASON_FROM_MYSELF = 0xf001
} WMDisconnectReason;
typedef enum WMInfoCode {
    WM_INFOCODE_NONE = 0,
    WM_INFOCODE_FATAL_ERROR
} WMInfoCode;
typedef struct WMDataSet {
    u16 aidBitmap;
    u16 receivedBitmap;
    u16 data[508 / sizeof(u16)];
} WMDataSet;
typedef struct WMDataSharingInfo {
    WMDataSet ds[4];
    u16 seqNum[4];
    u16 writeIndex;
    u16 sendIndex;
    u16 readIndex;
    u16 aidBitmap;
    u16 dataLength;
    u16 stationNumber;
    u16 dataSetLength;
    u16 port;
    u16 doubleMode;
    u16 currentSeqNum;
    u16 state;
    u16 reserved[1];
} WMDataSharingInfo;
typedef WMDataSharingInfo WMKeySetBuf, WMkeySetBuf;
typedef struct WMKeySet {
    u16 seqNum;
    u16 rsv;
    u16 key[16];
} WMKeySet, WMkeySet;
typedef struct {
    u16 next;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 sendingBitmap;
    u16 padding;
    u16 size;
    u16 seqNo;
    u16 retryCount;
    const u16 *data;
    WMCallbackFunc callback;
    void *arg;
} WMPortSendQueueData;
typedef struct {
    u16 head;
    u16 tail;
} WMPortSendQueue;
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
typedef struct WMDcfRecvBuf {
    u16 frameID;
    u16 rsv1[2];
    u16 length;

    u16 rsv2[3];
    u16 rate_rssi;
    u16 rsv3[4];
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 rsv4[4];

    u16 data[2];
} WMDcfRecvBuf, WMdcfRecvBuf;
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
typedef struct WMGameInfo_ {
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
typedef struct WMBssDesc_ {
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
typedef struct WMOtherElements_ {
    u8 count;
    u8 rsv[3];
    struct {
        u8 id;
        u8 length;
        u8 rsv[2];
        u8 *body;
    } element[16];
} WMOtherElements;
typedef struct WMScanParam_ {
    WMBssDesc *scanBuf;
    u16 channel;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 rsv[9];

} WMScanParam, WMscanParam;
typedef struct WMScanExParam_ {
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];

    u16 ssidMatchLength;
    u16 rsv2[7];

} WMScanExParam, WMscanExParam;
typedef struct WMMPParam_ {
    u32 mask;

    u16 minFrequency;
    u16 frequency;
    u16 maxFrequency;
    u16 parentSize;
    u16 childSize;
    u16 parentInterval;
    u16 childInterval;
    u16 parentVCount;
    u16 childVCount;
    u16 defaultRetryCount;
    u8 minPollBmpMode;
    u8 singlePacketMode;
    u8 ignoreFatalErrorMode;
    u8 ignoreSizePrecheckMode;
} WMMPParam;
typedef struct WMStatus_ {
    u16 state;
    u16 BusyApiid;

    BOOL apiBusy;
    BOOL scan_continue;
    BOOL mp_flag;
    BOOL dcf_flag;
    BOOL ks_flag;
    BOOL dcf_sendFlag;
    BOOL VSyncFlag;

    u8 wlVersion[8];
    u16 macVersion;
    u16 rfVersion;
    u16 bbpVersion[4 / sizeof(u16)];

    u16 mp_parentSize;
    u16 mp_childSize;
    u16 mp_parentMaxSize;
    u16 mp_childMaxSize;
    u16 mp_sendSize;
    u16 mp_recvSize;
    u16 mp_maxSendSize;
    u16 mp_maxRecvSize;
    u16 mp_parentVCount;
    u16 mp_childVCount;
    u16 mp_parentInterval;
    u16 mp_childInterval;

    OSTick mp_parentIntervalTick;
    OSTick mp_childIntervalTick;

    u16 mp_minFreq;
    u16 mp_freq;
    u16 mp_maxFreq;

    u16 mp_vsyncOrderedFlag;
    u16 mp_vsyncFlag;
    s16 mp_count;
    s16 mp_limitCount;
    u16 mp_resumeFlag;
    u16 mp_prevPollBitmap;
    u16 mp_prevWmHeader;
    u16 mp_prevTxop;
    u16 mp_prevDataLength;
    u16 mp_recvBufSel;
    u16 mp_recvBufSize;
    WMMpRecvBuf *mp_recvBuf[2];
    u32 *mp_sendBuf;
    u16 mp_sendBufSize;

    u16 mp_ackTime;
    u16 mp_waitAckFlag;

    u16 mp_readyBitmap;

    u16 mp_newFrameFlag;
    u16 mp_setDataFlag;
    u16 mp_sentDataFlag;
    u16 mp_bufferEmptyFlag;
    u16 mp_isPolledFlag;

    u16 mp_minPollBmpMode;
    u16 mp_singlePacketMode;
    u16 mp_fixFreqMode;
    u16 mp_defaultRetryCount;
    u16 mp_ignoreFatalErrorMode;
    u16 mp_ignoreSizePrecheckMode;

    u16 mp_pingFlag;
    u16 mp_pingCounter;

    u8 dcf_destAdr[6];
    u16 *dcf_sendData;
    u16 dcf_sendSize;
    u16 dcf_recvBufSel;
    WMDcfRecvBuf *dcf_recvBuf[2];
    u16 dcf_recvBufSize;

    u16 curr_tgid;

    u16 linkLevel;
    u16 minRssi;
    u16 rssiCounter;

    u16 beaconIndicateFlag;
    u16 wepKeyId;
    u16 pwrMgtMode;
    u8 reserved_d[4];

    u16 VSyncBitmap;
    u16 valarm_queuedFlag;

    u32 v_tsf;
    u32 v_tsf_bak;
    u32 v_remain;
    u16 valarm_counter;

    u8 reserved_e[2];

    u8 MacAddress[6];
    u16 mode;

    WMParentParam pparam;
    u8 childMacAddress[15][6];
    u16 child_bitmap;

    WMBssDesc *pInfoBuf;
    u16 aid;
    u8 parentMacAddress[6];
    u16 scan_channel;

    u8 reserved_f[4];

    u16 wepMode;
    BOOL wep_flag;
    u16 wepKey[80 / sizeof(u16)];

    u16 rate;
    u16 preamble;

    u16 tmptt;
    u16 retryLimit;

    u16 enableChannel;

    u16 allowedChannel;

    u16 portSeqNo[15 + 1][8];

    WMPortSendQueueData sendQueueData[32];
    WMPortSendQueue sendQueueFreeList;
    WMPortSendQueue sendQueue[4];
    WMPortSendQueue readyQueue[4];
    OSMutex sendQueueMutex;
    BOOL sendQueueInUse;

    OSTick mp_lastRecvTick[1 + 15];
    OSTick mp_lifeTimeTick;
} WMStatus, WMstatus;
typedef struct WMArm7Buf_ {
    WMStatus *status;

    u8 reserved_a[4];
    u32 *fifo7to9;

    u8 reserved_b[4];

    WMBssDesc connectPInfo;

    u32 requestBuf[512 / sizeof(u32)];
} WMArm7Buf, WMarm7Buf;
typedef struct WMArm9Buf_ {
    WMArm7Buf *WM7;
    WMStatus *status;
    u32 *indbuf;
    u32 *fifo9to7;
    u32 *fifo7to9;

    u16 dmaNo;
    u16 scanOnlyFlag;

    WMCallbackFunc CallbackTable[(WM_APIID_ASYNC_KIND_MAX - 2)];
    WMCallbackFunc indCallback;

    WMCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;

    u8 reserved1[512 - (20 + 4 + 4 * (WM_APIID_ASYNC_KIND_MAX - 2) + 4 + (4 + 4) * 16 + 6)];
} WMArm9Buf, WMarm9Buf;
typedef struct WMStartScanReq_ {
    u16 apiid;
    u16 channel;
    WMBssDesc *scanBuf;
    u16 maxChannelTime;
    u8 bssid[6];
} WMStartScanReq, WMstartScanReq;
typedef struct WMStartScanExReq_ {
    u16 apiid;
    u16 channelList;
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];

    u16 ssidMatchLength;
    u16 rsv[2];

} WMStartScanExReq, WMstartScanExReq;
typedef struct WMStartConnectReq_ {
    u16 apiid;
    u16 reserved;
    WMBssDesc *pInfo;
    u8 ssid[24];
    BOOL powerSave;
    u16 reserved2;
    u16 authMode;
} WMStartConnectReq, WMstartConnectReq;
typedef struct WMMeasureChannelReq_ {
    u16 apiid;
    u16 ccaMode;
    u16 edThreshold;
    u16 channel;
    u16 measureTime;
} WMMeasureChannelReq, WMmeasureChannelReq;
typedef struct WMSetMPParameterReq_ {
    u16 apiid;
    u16 reserved;

    WMMPParam param;
} WMSetMPParameterReq;
typedef struct WMStartMPReq_ {
    u16 apiid;
    u16 rsv1;
    u32 *recvBuf;
    u32 recvBufSize;
    u32 *sendBuf;
    u32 sendBufSize;

    WMMPParam param;
} WMStartMPReq;
typedef struct WMStartTestModeReq_ {
    u16 apiid;
    u16 control;
    u16 signal;
    u16 rate;
    u16 channel;
} WMStartTestModeReq, WMstartTestModeReq;
typedef struct WMStartTestRxModeReq_ {
    u16 apiid;
    u16 channel;
} WMStartTestRxModeReq, WMstartTestRxModeReq;
typedef struct WMCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;
typedef struct WMStartParentCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 aid;
    u16 reason;
    u8 ssid[24];
    u16 parentSize;
    u16 childSize;
} WMStartParentCallback, WMstartParentCallback;
typedef struct WMStartScanCallback_ {
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
typedef struct WMStartScanExCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
} WMStartScanExCallback, WMstartScanExCallback;
typedef struct WMStartConnectCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
    u16 reason;
    u16 wlStatus;
    u8 macAddress[6];
    u16 parentSize;
    u16 childSize;
} WMStartConnectCallback, WMstartConnectCallback;
typedef struct WMDisconnectCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 tryBitmap;
    u16 disconnectedBitmap;
} WMDisconnectCallback;
typedef struct WMSetMPParameterCallback_ {
    u16 apiid;
    u16 errcode;
    u32 mask;
    WMMPParam oldParam;
} WMSetMPParameterCallback;
typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    WMMpRecvBuf *recvBuf;

    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
    u16 reserved2;
} WMStartMPCallback, WMstartMPCallback;
typedef struct WMStartDCFCallback_ {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    WMDcfRecvBuf *recvBuf;

} WMStartDCFCallback, WMstartDCFCallback;
typedef struct WMMeasureChannelCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 channel;
    u16 ccaBusyRatio;
} WMMeasureChannelCallback, WMmeasureChannelCallback;
typedef struct WMGetWirelessCounterCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u32 TX_Success;
    u32 TX_Failed;
    u32 TX_Retry;
    u32 TX_AckError;
    u32 TX_Unicast;
    u32 TX_Multicast;
    u32 TX_WEP;
    u32 TX_Beacon;
    u32 RX_RTS;
    u32 RX_Fragment;
    u32 RX_Unicast;
    u32 RX_Multicast;
    u32 RX_WEP;
    u32 RX_Beacon;
    u32 RX_FCSError;
    u32 RX_DuplicateError;
    u32 RX_MPDuplicateError;
    u32 RX_ICVError;
    u32 RX_FrameCtrlError;
    u32 RX_LengthError;
    u32 RX_PLCPError;
    u32 RX_BufferOverflowError;
    u32 RX_PathError;
    u32 RX_RateError;
    u32 RX_FCSOK;
    u32 TX_MP;
    u32 TX_KeyData;
    u32 TX_NullKey;
    u32 RX_MP;
    u32 RX_MPACK;
    u32 MPKeyResponseError[15];
} WMGetWirelessCounterCallback, WMgetWirelessCounterCallback;
typedef struct WMIndCallback_ {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 reason;
} WMIndCallback, WMindCallback;
typedef struct WMPortSendCallback_ {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 rsv;
    const u16 *data;
    union {
        u16 size;
        u16 length;
    };
    u16 seqNo;
    WMCallbackFunc callback;
    void *arg;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortSendCallback;
typedef struct WMPortRecvCallback_ {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    WMMpRecvBuf *recvBuf;
    u16 *data;
    u16 length;
    u16 aid;
    u8 macAddress[6];
    u16 seqNo;
    void *arg;
    u16 myAid;
    u16 connectedAidBitmap;
    u8 ssid[24];
    u16 reason;
    u16 rsv;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} WMPortRecvCallback;
typedef struct WMBeaconRecvIndCallback_ {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 tgid;
    u16 wmstate;
    u16 gameInfoLength;
    WMGameInfo gameInfo;
} WMBeaconRecvIndCallback;
typedef struct WMStartTestModeCallback_ {
    u16 apiid;
    u16 errcode;
    u32 RFadr5;
    u32 RFadr6;
    u16 PllLockCheck;
    u16 RFMDflag;
} WMStartTestModeCallback;
typedef struct WMStopTestRxModeCallback_ {
    u16 apiid;
    u16 errcode;
    u32 fcsOk;
    u32 fcsErr;
} WMStopTestRxModeCallback;
extern WMErrCode WM_Init(void *wmSysBuf, u16 dmaNo);
extern WMErrCode WM_Finish(void);
extern WMErrCode WM_Enable(WMCallbackFunc callback);
extern WMErrCode WM_Disable(WMCallbackFunc callback);
extern WMErrCode WM_PowerOn(WMCallbackFunc callback);
extern WMErrCode WM_PowerOff(WMCallbackFunc callback);
extern WMErrCode WM_Initialize(void *wmSysBuf, WMCallbackFunc callback, u16 dmaNo);
extern WMErrCode WM_SetIndCallback(WMCallbackFunc callback);
extern WMErrCode WM_SetPortCallback(u16 port, WMCallbackFunc callback, void *arg);
extern WMErrCode WM_Reset(WMCallbackFunc callback);
extern WMErrCode WM_End(WMCallbackFunc callback);
extern WMErrCode WM_ReadStatus(WMStatus *statusBuf);
extern WMErrCode WM_SetParentParameter(WMCallbackFunc callback, const WMParentParam *pparaBuf);
extern WMErrCode WMi_StartParentEx(WMCallbackFunc callback, BOOL powerSave);
extern WMErrCode WM_StartParent(WMCallbackFunc callback);
extern WMErrCode WM_EndParent(WMCallbackFunc callback);
extern WMErrCode WM_StartScan(WMCallbackFunc callback, const WMScanParam *param);
extern WMErrCode WM_StartScanEx(WMCallbackFunc callback, const WMScanExParam *param);
extern WMErrCode WM_EndScan(WMCallbackFunc callback);
extern WMErrCode WM_StartConnectEx(WMCallbackFunc callback, const WMBssDesc *pInfo, const u8 *ssid, BOOL powerSave,
                                   u16 authMode);
extern WMErrCode WM_Disconnect(WMCallbackFunc callback, u16 aid);
extern WMErrCode WM_DisconnectChildren(WMCallbackFunc callback, u16 aidBitmap);
extern int WM_GetMPSendBufferSize(void);
extern int WM_GetMPReceiveBufferSize(void);
extern WMErrCode WM_StartMPEx(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize,
                              u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode,
                              BOOL ignoreFatalError);
extern WMErrCode WM_StartMP(WMCallbackFunc callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq);
extern WMErrCode WM_SetMPParameter(WMCallbackFunc callback, const WMMPParam *param);
extern WMErrCode WM_SetMPChildSize(WMCallbackFunc callback, u16 childSize);
extern WMErrCode WM_SetMPParentSize(WMCallbackFunc callback, u16 parentSize);
extern WMErrCode WM_SetMPFrequency(WMCallbackFunc callback, u16 mpFreq);
extern WMErrCode WM_SetMPInterval(WMCallbackFunc callback, u16 parentInterval, u16 childInterval);
extern WMErrCode WM_SetMPTiming(WMCallbackFunc callback, u16 parentVCount, u16 childVCount);
extern WMErrCode WM_SetMPDataToPortEx(WMCallbackFunc callback, void *arg, const u16 *sendData, u16 sendDataSize,
                                      u16 destBitmap, u16 port, u16 prio);
extern WMErrCode WM_EndMP(WMCallbackFunc callback);
extern WMErrCode WM_StartDCF(WMCallbackFunc callback, WMDcfRecvBuf *recvBuf, u16 recvBufSize);
extern WMErrCode WM_SetDCFData(WMCallbackFunc callback, const u8 *destAdr, const u16 *sendData, u16 sendDataSize);
extern WMErrCode WM_EndDCF(WMCallbackFunc callback);
extern WMErrCode WM_SetWEPKey(WMCallbackFunc callback, u16 wepmode, const u16 *wepkey);
extern WMErrCode WM_SetWEPKeyEx(WMCallbackFunc callback, u16 wepmode, u16 wepkeyid, const u8 *wepkey);
extern WMMpRecvData *WM_ReadMPData(const WMMpRecvHeader *header, u16 aid);
extern WMErrCode WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
extern WMErrCode WM_EndDataSharing(WMDataSharingInfo *dsInfo);
extern WMErrCode WM_StepDataSharing(WMDataSharingInfo *dsInfo, const u16 *sendData, WMDataSet *receiveData);
extern u16 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u16 aid);
extern WMErrCode WM_StartKeySharing(WMKeySetBuf *buf, u16 port);
extern WMErrCode WM_EndKeySharing(WMKeySetBuf *buf);
extern WMErrCode WM_GetKeySet(WMKeySetBuf *buf, WMKeySet *keySet);
extern WMErrCode WM_SetGameInfo(WMCallbackFunc callback, const u16 *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid,
                                u8 attr);
extern WMErrCode WM_SetBeaconIndication(WMCallbackFunc callback, u16 flag);
extern WMErrCode WM_SetLifeTime(WMCallbackFunc callback, u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern WMErrCode WM_MeasureChannel(WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
extern WMErrCode WM_InitWirelessCounter(WMCallbackFunc callback);
extern WMErrCode WM_GetWirelessCounter(WMCallbackFunc callback);
extern u16 WM_GetAllowedChannel(void);
extern WMErrCode WM_SetEntry(WMCallbackFunc callback, BOOL enabled);
extern WMLinkLevel WM_GetLinkLevel(void);
extern WMErrCode WMi_SetBeaconPeriod(WMCallbackFunc callback, u16 beaconPeriod);
extern u16 WM_GetDispersionBeaconPeriod(void);
extern u16 WM_GetDispersionScanPeriod(void);
extern WMOtherElements WM_GetOtherElements(WMBssDesc *bssDesc);
extern u16 WM_GetNextTgid(void);
extern WMErrCode WM_SetPowerSaveMode(WMCallbackFunc callback, BOOL powerSave);
extern BOOL WMi_IsMP(void);
extern u16 WM_GetAID(void);
extern u16 WM_GetConnectedAIDs(void);
extern u16 WMi_GetMPReadyAIDs(void);
static inline WMErrCode WM_SetMPDataToPort(WMCallbackFunc callback, const u16 *sendData, u16 sendDataSize, u16 destBitmap,
                                           u16 port, u16 prio) {
    return WM_SetMPDataToPortEx(callback, ((void *) 0), sendData, sendDataSize, destBitmap, port, prio);
}
static inline WMErrCode WM_SetMPData(WMCallbackFunc callback, const u16 *sendData, u16 sendDataSize, u16 tmptt, u16 pollbmp) {

#pragma unused(tmptt)
#line 126
    return WM_SetMPDataToPortEx(callback, ((void *) 0), sendData, sendDataSize, pollbmp, WM_PORT_RAWDATA, WM_PRIORITY_NORMAL);
}
static inline WMErrCode WM_StartConnect(WMCallbackFunc callback, const WMBssDesc *pInfo, const u8 *ssid) {
    return WM_StartConnectEx(callback, pInfo, ssid, 1, 0);
}
static inline void WM_ConvGgid32to16(u32 *src, u16 *dst) {
    dst[0] = (u16) (*src & 0x0000ffff);
    dst[1] = (u16) (*src >> 16);
}
static inline void WM_ConvGgid16to32(u16 *src, u32 *dst) {
    *dst = ((u32) src[1] << 16) | src[0];
}
static inline BOOL WM_IsBssidEqual(const u8 *idp1, const u8 *idp2) {
    return ((*idp1 == *idp2) && (*(idp1 + 1) == *(idp2 + 1)) && (*(idp1 + 2) == *(idp2 + 2)) && (*(idp1 + 3) == *(idp2 + 3)) &&
            (*(idp1 + 4) == *(idp2 + 4)) && (*(idp1 + 5) == *(idp2 + 5)));
}
static inline BOOL WM_IsBssidEqual16(const u8 *idp1, const u8 *idp2) {
    return ((*(u16 *) idp1 == *(u16 *) idp2) && (*(u16 *) (idp1 + 2) == *(u16 *) (idp2 + 2)) &&
            (*(u16 *) (idp1 + 4) == *(u16 *) (idp2 + 4)));
}
static inline void WM_CopyBssid(const u8 *src, u8 *dst) {
    *dst       = *src;
    *(dst + 1) = *(src + 1);
    *(dst + 2) = *(src + 2);
    *(dst + 3) = *(src + 3);
    *(dst + 4) = *(src + 4);
    *(dst + 5) = *(src + 5);
}
static inline void WM_CopyBssid16(const u8 *src, u8 *dst) {
    *(u16 *) dst       = *(u16 *) src;
    *(u16 *) (dst + 2) = *(u16 *) (src + 2);
    *(u16 *) (dst + 4) = *(u16 *) (src + 4);
}
static inline BOOL WM_IsValidGameInfo(const WMGameInfo *gameInfo, u16 gameInfoLength) {
    return (gameInfoLength >= 16 && gameInfo->magicNumber == 0x0001);
}
static inline BOOL WM_IsValidGameBeacon(const WMBssDesc *bssDesc) {
    return WM_IsValidGameInfo(&bssDesc->gameInfo, bssDesc->gameInfoLength);
}
static inline BOOL WMi_IsDisconnectReasonFromMyself(u16 reason) {
    return (reason >= WM_DISCONNECT_REASON_FROM_MYSELF);
}
typedef enum WVRResult {
    WVR_RESULT_SUCCESS = 0,
    WVR_RESULT_OPERATING,
    WVR_RESULT_DISABLE,
    WVR_RESULT_INVALID_PARAM,
    WVR_RESULT_FIFO_ERROR,
    WVR_RESULT_ILLEGAL_STATUS,
    WVR_RESULT_VRAM_LOCKED,
    WVR_RESULT_FATAL_ERROR,

    WVR_RESULT_MAX
} WVRResult;
typedef void (*WVRCallbackFunc)(void *arg, WVRResult result);
extern WVRResult WVR_StartUpAsync(GXVRamARM7 vram, WVRCallbackFunc callback, void *arg);
extern WVRResult WVR_TerminateAsync(WVRCallbackFunc callback, void *arg);
typedef enum {
    CTRDG_PHI_CLOCK_LOW   = MIi_PHI_CLOCK_LOW,
    CTRDG_PHI_CLOCK_4MHZ  = MIi_PHI_CLOCK_4MHZ,
    CTRDG_PHI_CLOCK_8MHZ  = MIi_PHI_CLOCK_8MHZ,
    CTRDG_PHI_CLOCK_16MHZ = MIi_PHI_CLOCK_16MHZ
} CTRDGPhiClock;
typedef struct {
    u32 startAddress;
    u8 nintendoLogo[0x9c];
    char titleName[12];
    u32 gameCode;
    u16 makerCode;
    u8 isRomCode;
    u8 machineCode;
    u8 deviceType;
    u8 exLsiID[3];
    u8 reserved_A[4];
    u8 softVersion;
    u8 complement;
    u16 moduleID;
} CTRDGHeader;
typedef struct {
    union {
        struct {
            u8 bitID;
            u8 numberID : 5;
            u8 : 2;
            u8 disableExLsiID : 1;
        };
        u16 raw;
    };
} CTRDGModuleID;
typedef struct {
    CTRDGModuleID moduleID;
    u8 exLsiID[3];
    u8 isAgbCartridge : 1;
    u8 detectPullOut : 1;
    u8 : 0;
    u16 makerCode;
    u32 gameCode;
} CTRDGModuleInfo;
typedef BOOL (*CTRDGPulledOutCallback)(void);
extern void CTRDG_Init(void);
extern BOOL CTRDG_IsPulledOut(void);
extern BOOL CTRDG_IsExisting(void);
extern BOOL CTRDG_IsBitID(u8 bitID);
extern BOOL CTRDG_IsNumberID(u8 numberID);
extern BOOL CTRDG_IsAgbCartridge(void);
extern BOOL CTRDG_IsOptionCartridge(void);
extern u32 CTRDG_GetAgbGameCode(void);
extern u16 CTRDG_GetAgbMakerCode(void);
extern BOOL CTRDG_IsAgbCartridgePulledOut(void);
extern BOOL CTRDG_IsOptionCartridgePulledOut(void);
extern void CTRDG_SetPulledOutCallback(CTRDGPulledOutCallback callback);
extern void CTRDG_TerminateForPulledOut(void);
extern void CTRDG_SendToARM7(void *arg);
extern BOOL CTRDG_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
extern BOOL CTRDG_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
extern BOOL CTRDG_CpuCopy8(const void *src, void *dest, u32 size);
extern BOOL CTRDG_CpuCopy16(const void *src, void *dest, u32 size);
extern BOOL CTRDG_CpuCopy32(const void *src, void *dest, u32 size);
extern BOOL CTRDG_Read8(const u8 *address, u8 *rdata);
extern BOOL CTRDG_Read16(const u16 *address, u16 *rdata);
extern BOOL CTRDG_Read32(const u32 *address, u32 *rdata);
extern BOOL CTRDG_Write8(u8 *address, u8 data);
extern BOOL CTRDG_Write16(u16 *address, u16 data);
extern BOOL CTRDG_Write32(u32 *address, u32 data);
extern BOOL CTRDG_IsEnabled(void);
extern void CTRDG_Enable(BOOL enable);
extern void CTRDG_CheckEnabled(void);
extern void CTRDG_CheckPulledOut(void);
extern void CTRDG_SetPhiClock(CTRDGPhiClock clock);
static inline CTRDGPhiClock CTRDG_GetPhiClock(void) {
    return (CTRDGPhiClock) MIi_GetPhiClock();
}
typedef struct CTRDGRomCycle {
    MICartridgeRomCycle1st c1;
    MICartridgeRomCycle2nd c2;
} CTRDGRomCycle;
typedef struct CTRDGLockByProc {
    BOOL locked;
    OSIntrMode irq;
} CTRDGLockByProc;
extern void CTRDGi_InitCommon(void);
extern void CTRDGi_InitModuleInfo(void);
extern void CTRDGi_SendtoPxi(u32 data);
extern void CTRDGi_LockByProcessor(u16 lockID, CTRDGLockByProc *info);
extern void CTRDGi_UnlockByProcessor(u16 lockID, CTRDGLockByProc *info);
extern void CTRDGi_ChangeLatestAccessCycle(CTRDGRomCycle *r);
extern void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r);
extern BOOL CTRDGi_IsBitIDAtInit(u8 bitID);
extern BOOL CTRDGi_IsNumberIDAtInit(u8 numberID);
extern BOOL CTRDGi_IsAgbCartridgeAtInit(void);
extern u32 CTRDGi_GetAgbGameCodeAtInit(void);
extern u16 CTRDGi_GetAgbMakerCodeAtInit(void);
extern BOOL CTRDGi_CopyCommon(u32 dmaNo, const void *src, void *dest, u32 size, u32 forwardType);
extern BOOL CTRDGi_AccessCommon(void *address, u32 data, void *rdata, u32 accessType);
struct CTRDGTaskInfo_tag;
typedef u32 (*CTRDG_TASK_FUNC)(struct CTRDGTaskInfo_tag *);
typedef struct CTRDGTaskInfo_tag {
    CTRDG_TASK_FUNC task;
    CTRDG_TASK_FUNC callback;
    u32 result;
    u8 *data;
    u8 *adr;
    u32 offset;
    u32 size;
    u8 *dst;
    u16 sec_num;
    u8 busy;
    u8 param[1];
} CTRDGTaskInfo;
typedef struct {
    OSThread th[1];
    CTRDGTaskInfo *volatile list;
    CTRDGTaskInfo end_task;
} CTRDGiTaskWork;
extern void CTRDGi_InitTaskThread(void *p_work);
extern BOOL CTRDGi_IsTaskAvailable(void);
extern void CTRDGi_InitTaskInfo(CTRDGTaskInfo *pt);
extern BOOL CTRDGi_IsTaskBusy(volatile const CTRDGTaskInfo *pt);
extern void CTRDGi_SetTask(CTRDGTaskInfo *pt, CTRDG_TASK_FUNC task, CTRDG_TASK_FUNC callback);
extern void CTRDGi_EndTaskThread(CTRDG_TASK_FUNC callback);
extern void CTRDG_SetTaskThreadPriority(u32 priority);
typedef struct CTRDGiFlashSectorTag {
    u32 size;
    u16 shift;
    u16 count;
    u16 top;
    u8 reserved[2];
} CTRDGiFlashSector;
typedef struct CTRDGFlashTypeTag {
    u32 romSize;
    CTRDGiFlashSector sector;
    MICartridgeRamCycle agbWait[2];
    u16 makerID;
    u16 deviceID;
} CTRDGFlashType;
extern const CTRDGFlashType *AgbFlash;
extern u16 ctrdg_flash_remainder;
extern void CTRDGi_SetFlashBankMx(u16 bank);
extern u16 CTRDGi_ReadFlashID(void);
extern void StartFlashTimer(u16 phase);
extern void CheckFlashTimer(void);
extern void CTRDGi_SetFlashBankMx(u16 bank);
extern u16 CTRDGi_PollingSR512kCOMMON(u16 phase, u8 *adr, u16 lastData);
extern u16 CTRDGi_PollingSR1MCOMMON(u16 phase, u8 *adr, u16 lastData);
extern void CTRDG_ReadAgbFlash(u16 sec_num, u32 offset, u8 *dst, u32 size);
extern void CTRDG_ReadAgbFlashAsync(u16 sec_num, u32 offset, u8 *dst, u32 size, CTRDG_TASK_FUNC callback);
extern u16 CTRDG_EraseAgbFlashChip(void);
extern void CTRDG_EraseAgbFlashChipAsync(CTRDG_TASK_FUNC callback);
extern u16 CTRDG_EraseAgbFlashSector(u16 sec_num);
extern void CTRDG_EraseAgbFlashSectorAsync(u16 sec_num, CTRDG_TASK_FUNC callback);
extern u16 CTRDG_WriteAgbFlashSector(u16 sec_num, u8 *src);
extern void CTRDG_WriteAgbFlashSectorAsync(u16 sec_num, u8 *src, CTRDG_TASK_FUNC callback);
extern u32 CTRDG_VerifyAgbFlash(u16 sec_num, u8 *src, u32 size);
extern void CTRDG_VerifyAgbFlashAsync(u16 sec_num, u8 *src, u32 size, CTRDG_TASK_FUNC callback);
extern u32 CTRDG_WriteAndVerifyAgbFlash(u16 sec_num, u8 *src, u32 verifysize);
extern void CTRDG_WriteAndVerifyAgbFlashAsync(u16 sec_num, u8 *src, u32 verifysize, CTRDG_TASK_FUNC callback);
extern void CTRDG_ReadAgbSram(u32 src, void *dst, u32 size);
extern void CTRDG_ReadAgbSramAsync(u32 src, void *dst, u32 size, CTRDG_TASK_FUNC callback);
extern void CTRDG_WriteAgbSram(u32 dst, const void *src, u32 size);
extern void CTRDG_WriteAgbSramAsync(u32 dst, const void *src, u32 size, CTRDG_TASK_FUNC callback);
extern u32 CTRDG_VerifyAgbSram(u32 tgt, const void *src, u32 size);
extern void CTRDG_VerifyAgbSramAsync(u32 tgt, const void *src, u32 size, CTRDG_TASK_FUNC callback);
extern u32 CTRDG_WriteAndVerifyAgbSram(u32 dst, const void *src, u32 size);
extern void CTRDG_WriteAndVerifyAgbSramAsync(u32 dst, const void *src, u32 size, CTRDG_TASK_FUNC callback);
typedef enum {
    CTRDG_BACKUP_TYPE_FLASH_512K,
    CTRDG_BACKUP_TYPE_FLASH_1M,
    CTRDG_BACKUP_TYPE_SRAM
} CTRDGBackupType;
typedef struct CTRDGiFlashTypePlusTag {
    u16 (*CTRDGi_WriteAgbFlashSector)(u16 secNo, u8 *src);
    u16 (*CTRDGi_EraseAgbFlashChip)(void);
    u16 (*CTRDGi_EraseAgbFlashSector)(u16 secNo);
    void (*CTRDGi_WriteAgbFlashSectorAsync)(u16 secNo, u8 *src, CTRDG_TASK_FUNC callback);
    void (*CTRDGi_EraseAgbFlashChipAsync)(CTRDG_TASK_FUNC callback);
    void (*CTRDGi_EraseAgbFlashSectorAsync)(u16 secNo, CTRDG_TASK_FUNC callback);
    u16 (*CTRDGi_PollingSR)(u16 phase, u8 *adr, u16 lastData);
    const u16(*maxtime);
    CTRDGFlashType type;
} CTRDGiFlashTypePlus;
extern u16 ctrdg_flash_remainder;
extern const u16(*ctrdgi_fl_maxtime);
extern u16 (*CTRDGi_PollingSR)(u16 phase, u8 *adr, u16 lastData);
extern const CTRDGFlashType *AgbFlash;
extern u16 (*CTRDGi_WriteAgbFlashSector)(u16 secNo, u8 *src);
extern u16 (*CTRDGi_EraseAgbFlashChip)(void);
extern u16 (*CTRDGi_EraseAgbFlashSector)(u16 secNo);
extern void (*CTRDGi_WriteAgbFlashSectorAsync)(u16 secNo, u8 *src, CTRDG_TASK_FUNC callback);
extern void (*CTRDGi_EraseAgbFlashChipAsync)(CTRDG_TASK_FUNC callback);
extern void (*CTRDGi_EraseAgbFlashSectorAsync)(u16 secNo, CTRDG_TASK_FUNC callback);
extern u16 (*pollingSR)(u16 phase, u8 *adr, u16 lastData);
extern u16 CTRDG_IdentifyAgbBackup(CTRDGBackupType type);
extern void CTRDG_Init(void);
extern u32 MATH_CountLeadingZerosFunc(u32 x);
// clang-format off
static inline u32 MATH_CountLeadingZerosInline(u32 x)
{
    asm
    {
    clz     x, x}
    return x;
}
// clang-format on
static inline int MATH_IAbs(int a) {
    return (a < 0) ? -a : a;
}
static inline int MATH_IMin(int a, int b) {
    return (a <= b) ? a : b;
}
static inline int MATH_IMax(int a, int b) {
    return (a >= b) ? a : b;
}
static inline int MATH_ILog2(u32 x) {
    return (int) (31 - MATH_CountLeadingZerosInline(x));
}
static inline u32 MATH_CountTrailingZeros(u32 x) {
    return (u32) (32 - MATH_CountLeadingZerosInline((u32) (~x & (x - 1))));
}
static inline u32 MATH_GetLeastSignificantBit(u32 x) {
    return (u32) (x & -(s32) x);
}
static inline u32 MATH_GetMostSignificantBit(u32 x) {
    return (u32) (x & ((s32) 0x80000000 >> MATH_CountLeadingZerosInline(x)));
}
extern u8 MATH_CountPopulation(u32 x);
typedef u8 MATHCRC8Context;
typedef u16 MATHCRC16Context;
typedef u32 MATHCRC32Context;
typedef struct MATHCRC8Table {
    u8 table[256];
} MATHCRC8Table;
typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;
typedef struct MATHCRC32Table {
    u32 table[256];
} MATHCRC32Table;
extern void MATHi_CRC8InitTable(MATHCRC8Table *table, u8 poly);
extern void MATHi_CRC8InitTableRev(MATHCRC8Table *table, u8 poly);
extern void MATHi_CRC8Update(const MATHCRC8Table *table, MATHCRC8Context *context, const void *input, u32 length);
extern void MATHi_CRC16InitTable(MATHCRC16Table *table, u16 poly);
extern void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly);
extern void MATHi_CRC16Update(const MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length);
extern void MATHi_CRC16UpdateRev(const MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length);
extern void MATHi_CRC32InitTable(MATHCRC32Table *table, u32 poly);
extern void MATHi_CRC32InitTableRev(MATHCRC32Table *table, u32 poly);
extern void MATHi_CRC32Update(const MATHCRC32Table *table, MATHCRC32Context *context, const void *input, u32 length);
extern void MATHi_CRC32UpdateRev(const MATHCRC32Table *table, MATHCRC32Context *context, const void *input, u32 length);
extern u8 MATH_CalcCRC8(const MATHCRC8Table *table, const void *data, u32 dataLength);
extern u16 MATH_CalcCRC16(const MATHCRC16Table *table, const void *data, u32 dataLength);
extern u16 MATH_CalcCRC16CCITT(const MATHCRC16Table *table, const void *data, u32 dataLength);
extern u32 MATH_CalcCRC32(const MATHCRC32Table *table, const void *data, u32 dataLength);
extern u32 MATH_CalcCRC32POSIX(const MATHCRC32Table *table, const void *data, u32 dataLength);
static inline void MATHi_CRC8Init(MATHCRC8Context *context, u8 init) {
    *context = init;
}
static inline void MATHi_CRC8UpdateRev(const MATHCRC8Table *table, MATHCRC8Context *context, const void *input, u32 length) {
    MATHi_CRC8Update(table, context, input, length);
}
static inline u8 MATHi_CRC8GetHash(MATHCRC8Context *context) {
    return (u8) *context;
}
static inline void MATH_CRC8InitTable(MATHCRC8Table *table) {
    MATHi_CRC8InitTable(table, 0x07);
}
static inline void MATH_CRC8Init(MATHCRC8Context *context) {
    MATHi_CRC8Init(context, 0);
}
static inline void MATH_CRC8Update(const MATHCRC8Table *table, MATHCRC8Context *context, const void *input, u32 length) {
    MATHi_CRC8Update(table, context, input, length);
}
static inline u8 MATH_CRC8GetHash(MATHCRC8Context *context) {
    return MATHi_CRC8GetHash(context);
}
static inline void MATHi_CRC16Init(MATHCRC16Context *context, u16 init) {
    *context = init;
}
static inline u16 MATHi_CRC16GetHash(MATHCRC16Context *context) {
    return (u16) *context;
}
static inline void MATH_CRC16CCITTInitTable(MATHCRC16Table *table) {
    MATHi_CRC16InitTable(table, 0x1021);
}
static inline void MATH_CRC16CCITTInit(MATHCRC16Context *context) {
    MATHi_CRC16Init(context, 0xffff);
}
static inline void MATH_CRC16CCITTUpdate(const MATHCRC16Table *table, MATHCRC16Context *context, const void *input,
                                         u32 length) {
    MATHi_CRC16Update(table, context, input, length);
}
static inline u16 MATH_CRC16CCITTGetHash(MATHCRC16Context *context) {
    return MATHi_CRC16GetHash(context);
}
static inline void MATH_CRC16InitTable(MATHCRC16Table *table) {
    MATHi_CRC16InitTableRev(table, 0xa001);
}
static inline void MATH_CRC16Init(MATHCRC16Context *context) {
    MATHi_CRC16Init(context, 0);
}
static inline void MATH_CRC16Update(const MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length) {
    MATHi_CRC16UpdateRev(table, context, input, length);
}
static inline u16 MATH_CRC16GetHash(MATHCRC16Context *context) {
    return MATHi_CRC16GetHash(context);
}
static inline void MATHi_CRC32Init(MATHCRC32Context *context, u32 init) {
    *context = init;
}
static inline u32 MATHi_CRC32GetHash(MATHCRC32Context *context) {
    return (u32) *context;
}
static inline void MATH_CRC32InitTable(MATHCRC32Table *table) {
    MATHi_CRC32InitTableRev(table, 0xedb88320);
}
static inline void MATH_CRC32Init(MATHCRC32Context *context) {
    MATHi_CRC32Init(context, 0xffffffff);
}
static inline void MATH_CRC32Update(const MATHCRC32Table *table, MATHCRC32Context *context, const void *input, u32 length) {
    MATHi_CRC32UpdateRev(table, context, input, length);
}
static inline u32 MATH_CRC32GetHash(MATHCRC32Context *context) {
    return (u32) (~MATHi_CRC32GetHash(context));
}
static inline void MATH_CRC32POSIXInitTable(MATHCRC32Table *table) {
    MATHi_CRC32InitTable(table, 0x04c11db7);
}
static inline void MATH_CRC32POSIXInit(MATHCRC32Context *context) {
    MATHi_CRC32Init(context, 0);
}
static inline void MATH_CRC32POSIXUpdate(const MATHCRC32Table *table, MATHCRC32Context *context, const void *input,
                                         u32 length) {
    MATHi_CRC32Update(table, context, input, length);
}
static inline u32 MATH_CRC32POSIXGetHash(MATHCRC32Context *context) {
    return (u32) (~MATHi_CRC32GetHash(context));
}
typedef struct DGTHash1Context {
    union {
        struct {
            unsigned long a, b, c, d;
        };
        unsigned long state[4];
    };
    unsigned long long length;
    union {
        unsigned long buffer32[16];
        unsigned char buffer8[64];
    };
} DGTHash1Context;
typedef struct DGTHash2Context {
    unsigned long Intermediate_Hash[5];
    unsigned long Length_Low;
    unsigned long Length_High;
    int Message_Block_Index;
    unsigned char Message_Block[64];
    int Computed;
    int Corrupted;
} DGTHash2Context;
extern void DGT_Hash1Reset(DGTHash1Context *ctx);
extern void DGT_Hash1SetSource(DGTHash1Context *ctx, unsigned char *, unsigned long);
extern void DGT_Hash1GetDigest_R(unsigned char digest[16], DGTHash1Context *);
extern void DGT_Hash2Reset(DGTHash2Context *ctx);
extern void DGT_Hash2SetSource(DGTHash2Context *ctx, unsigned char *, unsigned long);
extern void DGT_Hash2GetDigest(DGTHash2Context *ctx, unsigned char digest[20]);
extern void DGT_Hash1CalcHmac(void *digest, void *bin_ptr, int bin_len, void *key_ptr, int key_len);
extern void DGT_Hash2CalcHmac(void *digest, void *bin_ptr, int bin_len, void *key_ptr, int key_len);
extern void DGTi_hash2_arm4_small(void *result, void *a2, int a3);
typedef DGTHash1Context MATHMD5Context;
typedef DGTHash2Context MATHSHA1Context;
extern void MATH_CalcMD5(void *digest, const void *data, u32 dataLength);
extern void MATH_CalcSHA1(void *digest, const void *data, u32 dataLength);
static inline void MATH_MD5Init(MATHMD5Context *context) {
    DGT_Hash1Reset(context);
}
static inline void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length) {
    DGT_Hash1SetSource(context, (u8 *) input, length);
}
static inline void MATH_MD5GetHash(MATHMD5Context *context, void *digest) {
    DGT_Hash1GetDigest_R((u8 *) digest, context);
}
static inline void MATH_MD5GetDigest(MATHMD5Context *context, void *digest) {
    MATH_MD5GetHash(context, digest);
}
static inline void MATH_SHA1Init(MATHSHA1Context *context) {
    DGT_Hash2Reset(context);
}
static inline void MATH_SHA1Update(MATHSHA1Context *context, const void *input, u32 length) {
    DGT_Hash2SetSource(context, (u8 *) input, length);
}
static inline void MATH_SHA1GetHash(MATHSHA1Context *context, void *digest) {
    DGT_Hash2GetDigest(context, (u8 *) digest);
}
static inline void MATH_SHA1GetDigest(MATHSHA1Context *context, void *digest) {
    MATH_SHA1GetHash(context, digest);
}
static inline void MATH_CalcHMACMD5(void *digest, const void *data, u32 dataLength, const void *key, u32 keyLength) {
    DGT_Hash1CalcHmac(digest, (void *) data, (int) dataLength, (void *) key, (int) keyLength);
}
static inline void MATH_CalcHMACSHA1(void *digest, const void *data, u32 dataLength, const void *key, u32 keyLength) {
    DGT_Hash2CalcHmac(digest, (void *) data, (int) dataLength, (void *) key, (int) keyLength);
}
typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;
typedef struct {
    u32 x;
    u32 mul;
    u32 add;
} MATHRandContext16;
static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed) {
    context->x   = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->add = 2531011;
}
static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max) {
    context->x = context->mul * context->x + context->add;

    if (max == 0) {
        return (u32) (context->x >> 32);
    } else {
        return (u32) (((context->x >> 32) * max) >> 32);
    }
}
static inline void MATH_InitRand16(MATHRandContext16 *context, u32 seed) {
    context->x   = seed;
    context->mul = 1566083941LL;
    context->add = 2531011;
}
static inline u16 MATH_Rand16(MATHRandContext16 *context, u16 max) {
    context->x = context->mul * context->x + context->add;

    if (max == 0) {
        return (u16) (context->x >> 16);
    } else {
        return (u16) (((context->x >> 16) * max) >> 16);
    }
}
typedef enum STDResult {
    STD_RESULT_SUCCESS,
    STD_RESULT_ERROR,
    STD_RESULT_INVALID_PARAM,
    STD_RESULT_CONVERSION_FAILED
} STDResult;
typedef STDResult (*STDConvertUnicodeCallback)(u16 *dst, int *dst_len, const char *src, int *src_len);
typedef STDResult (*STDConvertSjisCallback)(char *dst, int *dst_len, const u16 *src, int *src_len);
extern STDResult STD_ConvertStringSjisToUnicode(u16 *dst, int *dst_len, const char *src, int *src_len,
                                                STDConvertUnicodeCallback callback);
extern STDResult STD_ConvertStringUnicodeToSjis(char *dst, int *dst_len, const u16 *src, int *src_len,
                                                STDConvertSjisCallback callback);
static inline BOOL STD_IsSjisLeadByte(int c) {
    return ((unsigned int) ((((u8) c) ^ 0x20) - 0xA1) < 0x3C);
}
static inline BOOL STD_IsSjisTrailByte(int c) {
    return (c != 0x7F) && ((u8) (c - 0x40) <= (0xFC - 0x40));
}
static inline BOOL STD_IsSjisCharacter(const char *s) {
    return STD_IsSjisLeadByte(s[0]) && STD_IsSjisTrailByte(s[1]);
}
static inline int STD_ConvertCharSjisToUnicode(u16 *dst, const char *src) {
    int src_len   = STD_IsSjisCharacter(src) ? 2 : 1;
    int dst_len   = 1;
    STDResult ret = STD_ConvertStringSjisToUnicode(dst, &dst_len, src, &src_len, ((void *) 0));
    return (ret == STD_RESULT_SUCCESS) ? dst_len : -1;
}
static inline int STD_ConvertCharUnicodeToSjis(char *dst, u16 src) {
    int src_len   = 1;
    int dst_len   = 2;
    STDResult ret = STD_ConvertStringUnicodeToSjis(dst, &dst_len, &src, &src_len, ((void *) 0));
    return (ret == STD_RESULT_SUCCESS) ? dst_len : -1;
}
extern fx16 FX_Atan(fx32 x);
extern fx16 FX_Atan2(fx32 y, fx32 x);
extern u16 FX_AtanIdx(fx32 x);
extern u16 FX_Atan2Idx(fx32 y, fx32 x);
extern const fx16 FX_SinCosTable_[];
static inline fx16 FX_SinIdx(int idx) {
    return FX_SinCosTable_[((idx >> 4) << 1)];
}
static inline fx16 FX_CosIdx(int idx) {
    return FX_SinCosTable_[((idx >> 4) << 1) + 1];
}
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern fx32 FX_Inv(fx32 denom);
extern fx64c FX_InvFx64c(fx32 denom);
extern fx32 FX_Sqrt(fx32 x);
extern fx64c FX_GetDivResultFx64c(void);
extern fx32 FX_GetDivResult(void);
extern void FX_InvAsync(fx32 denom);
extern fx32 FX_GetSqrtResult(void);
extern void FX_DivAsync(fx32 numer, fx32 denom);
extern s32 FX_DivS32(s32 a, s32 b);
extern s32 FX_ModS32(s32 a, s32 b);
static inline s32 CP_IsDivBusy(void) {
    return ((*(REGType16v *) (0x04000000 + 0x280)) & 0x8000);
}
static inline s32 CP_IsSqrtBusy(void) {
    return ((*(REGType16v *) (0x04000000 + 0x2B0)) & 0x8000);
}
static inline void CP_WaitDiv(void) {
    while (CP_IsDivBusy()) {
    }
}
static inline void CP_WaitSqrt(void) {
    while (CP_IsSqrtBusy()) {
    }
}
static inline s64 CP_GetDivResultImm64(void) {
    return (s64) (*(REGType64 *) (0x04000000 + 0x2A0));
}
static inline void CP_SetDivImm32_32_NS_(u32 numer, u32 denom) {
    *(REGType32 *) (0x04000000 + 0x290) = numer;
    *(REGType64 *) (0x04000000 + 0x298) = denom;
}
static inline void CP_SetDivImm64_32_NS_(u64 numer, u32 denom) {
    *(REGType64 *) (0x04000000 + 0x290) = numer;
    *(REGType64 *) (0x04000000 + 0x298) = denom;
}
static inline void CP_SetDivImm64_64_NS_(u64 numer, u64 denom) {
    *(REGType64 *) (0x04000000 + 0x290) = numer;
    *(REGType64 *) (0x04000000 + 0x298) = denom;
}
static inline void CP_SetDiv64_64(u64 numer, u64 denom) {
    (*(REGType16v *) (0x04000000 + 0x280)) = (2UL << 0);
    CP_SetDivImm64_64_NS_(numer, denom);
}
static inline void CP_SetDiv64_32(u64 numer, u32 denom) {
    (*(REGType16v *) (0x04000000 + 0x280)) = (1UL << 0);
    CP_SetDivImm64_32_NS_(numer, denom);
}
static inline void CP_SetDiv32_32(u32 numer, u32 denom) {
    (*(REGType16v *) (0x04000000 + 0x280)) = (0UL << 0);
    CP_SetDivImm32_32_NS_(numer, denom);
}
static inline s32 CP_GetDivResultImm32() {
    return (s32) (*(REGType32 *) (0x04000000 + 0x2A0));
}
static inline s32 CP_GetDivRemainderImm32() {
    return (s32) (*(REGType32 *) (0x04000000 + 0x2A8));
}
static inline void CP_SetDivImm64_32(u64 numer, u32 denom) {
    CP_SetDivImm64_32_NS_(numer, denom);
}
static inline void CP_SetSqrtImm64_NS_(u64 param) {
    *((REGType64 *) (0x04000000 + 0x2B8)) = param;
}
static inline u32 CP_GetSqrtResultImm32(void) {
    return (u32) (*((REGType32 *) (0x04000000 + 0x2B4)));
}
static inline s64 CP_GetDivResult64(void) {
    CP_WaitDiv();
    return CP_GetDivResultImm64();
}
static inline s32 CP_GetDivResult32(void) {
    CP_WaitDiv();
    return CP_GetDivResultImm32();
}
static inline s32 CP_GetDivRemainder32(void) {
    CP_WaitDiv();
    return CP_GetDivRemainderImm32();
}
static inline void CP_SetSqrt64(u64 param) {
    (*(REGType16v *) (0x04000000 + 0x2B0)) = (1UL << 0);
    CP_SetSqrtImm64_NS_(param);
}
static inline u32 CP_GetSqrtResult32(void) {
    CP_WaitSqrt();
    return CP_GetSqrtResultImm32();
}
static inline void FX_InvAsyncImm(fx32 denom) {
    CP_SetDivImm64_32((u64) ((fx32) 0x0000000000001000L) << 32, (u32) denom);
}
static inline fx64c FX_GetInvResultFx64c(void) {
    return FX_GetDivResultFx64c();
}
static inline fx32 FX_GetInvResult(void) {
    return FX_GetDivResult();
}
static inline void FX_DivAsyncImm(fx32 numer, fx32 denom) {
    CP_SetDivImm64_32((u64) numer << 32, (u32) denom);
}
static inline fx32 FX_Mod(fx32 numer, fx32 denom) {
    return (fx32) FX_ModS32(numer, denom);
}
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern fx32 VEC_DotProduct(const VecFx32 *a, const VecFx32 *b);
extern void VEC_CrossProduct(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb);
extern fx32 VEC_Mag(const VecFx32 *pSrc);
extern void VEC_Normalize(const VecFx32 *pSrc, VecFx32 *pDst);
extern void VEC_MultAdd(fx32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
extern fx32 VEC_Distance(const VecFx32 *v1, const VecFx32 *v2);
static inline void VEC_Set(VecFx32 *a, fx32 x, fx32 y, fx32 z) {
    a->x = x;
    a->y = y;
    a->z = z;
}
static inline void VEC_Fx16Set(VecFx16 *a, fx16 x, fx16 y, fx16 z) {
    a->x = x;
    a->y = y;
    a->z = z;
}
extern void MTX_Identity22_(register MtxFx22 *pDst);
extern void MTX_Scale22_(register MtxFx22 *pDst, register fx32 x, register fx32 y);
extern void MTX_Rot22_(register MtxFx22 *pDst, register fx32 sinVal, register fx32 cosVal);
extern void MTX_ScaleApply22(const MtxFx22 *pSrc, MtxFx22 *pDst, fx32 x, fx32 y);
extern void MTX_Concat22(const MtxFx22 *a, const MtxFx22 *b, MtxFx22 *ab);
static inline void MTX_Identity22(MtxFx22 *pDst) {
    MTX_Identity22_(pDst);
}
static inline void MTX_Scale22(MtxFx22 *pDst, fx32 x, fx32 y) {
    MTX_Scale22_(pDst, x, y);
}
static inline void MTX_Rot22(MtxFx22 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_Rot22_(pDst, sinVal, cosVal);
}
extern void MTX_Identity33_(register MtxFx33 *pDst);
extern void MTX_Copy33To43_(const register MtxFx33 *pSrc, register MtxFx43 *pDst);
extern void MTX_Transpose33_(const register MtxFx33 *pSrc, register MtxFx33 *pDst);
extern void MTX_Scale33_(register MtxFx33 *pDst, register fx32 x, register fx32 y, register fx32 z);
extern void MTX_ScaleApply33(const MtxFx33 *pSrc, MtxFx33 *pDst, fx32 x, fx32 y, fx32 z);
extern void MTX_RotX33_(register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal);
extern void MTX_RotY33_(register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal);
extern void MTX_RotZ33_(register MtxFx33 *pDst, register fx32 sinVal, register fx32 cosVal);
extern void MTX_RotAxis33(MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal);
extern void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
extern int MTX_Inverse33(const MtxFx33 *pSrc, MtxFx33 *pDst);
extern void MTX_MultVec33(const VecFx32 *vec, const MtxFx33 *m, VecFx32 *dst);
static inline void MTX_Identity33(MtxFx33 *pDst) {
    MTX_Identity33_(pDst);
}
static inline void MTX_Copy33(const MtxFx33 *pSrc, MtxFx33 *pDst) {
    MI_Copy36B(pSrc, pDst);
}
static inline void MTX_Copy33To43(const MtxFx33 *pSrc, MtxFx43 *pDst) {
    MTX_Copy33To43_(pSrc, pDst);
}
static inline void MTX_Transpose33(const MtxFx33 *pSrc, MtxFx33 *pDst) {
    MTX_Transpose33_(pSrc, pDst);
}
static inline void MTX_Scale33(MtxFx33 *pDst, fx32 x, fx32 y, fx32 z) {
    MTX_Scale33_(pDst, x, y, z);
}
static inline void MTX_RotX33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_RotX33_(pDst, sinVal, cosVal);
}
static inline void MTX_RotY33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_RotY33_(pDst, sinVal, cosVal);
}
static inline void MTX_RotZ33(MtxFx33 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_RotZ33_(pDst, sinVal, cosVal);
}
extern void MTX_Identity43_(register MtxFx43 *pDst);
extern void MTX_Copy43To44_(register const MtxFx43 *pSrc, register MtxFx44 *pDst);
extern void MTX_TransApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
extern void MTX_ScaleApply43(const MtxFx43 *pSrc, MtxFx43 *pDst, fx32 x, fx32 y, fx32 z);
extern void MTX_RotY43_(register MtxFx43 *pDst, register fx32 sinVal, register fx32 cosVal);
extern void MTX_RotZ43_(register MtxFx43 *pDst, register fx32 sinVal, register fx32 cosVal);
extern int MTX_Inverse43(const MtxFx43 *pSrc, MtxFx43 *pDst);
extern void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);
extern void MTX_MultVec43(const VecFx32 *vec, const MtxFx43 *m, VecFx32 *dst);
static inline void MTX_Identity43(MtxFx43 *pDst) {
    MTX_Identity43_(pDst);
}
static inline void MTX_Copy43(const MtxFx43 *pSrc, MtxFx43 *pDst) {
    MI_Copy48B(pSrc, pDst);
}
static inline void MTX_Copy43To33(const MtxFx43 *pSrc, MtxFx33 *pDst) {
    MI_Copy36B(pSrc, pDst);
}
static inline void MTX_Copy43To44(const MtxFx43 *pSrc, MtxFx44 *pDst) {
    MTX_Copy43To44_(pSrc, pDst);
}
static inline void MTX_RotY43(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_RotY43_(pDst, sinVal, cosVal);
}
static inline void MTX_RotZ43(MtxFx43 *pDst, fx32 sinVal, fx32 cosVal) {
    MTX_RotZ43_(pDst, sinVal, cosVal);
}
static inline void MTX_LookAt(const VecFx32 *camPos, const VecFx32 *camUp, const VecFx32 *target, MtxFx43 *mtx) {
    G3i_LookAt_(camPos, camUp, target, 0, mtx);
}
extern void MTX_Identity44_(register MtxFx44 *pDst);
extern void MTX_Copy44To43_(const register MtxFx44 *pSrc, register MtxFx43 *pDst);
extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
static inline void MTX_Identity44(MtxFx44 *pDst) {
    MTX_Identity44_(pDst);
}
static inline void MTX_Copy44(const MtxFx44 *pSrc, MtxFx44 *pDst) {
    MI_Copy64B(pSrc, pDst);
}
static inline void MTX_Copy44To43(const MtxFx44 *pSrc, MtxFx43 *pDst) {
    MTX_Copy44To43_(pSrc, pDst);
}
static inline void MTX_Frustum(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_FrustumW_(t, b, l, r, n, f, ((fx32) 0x0000000000001000L), 0, mtx);
}
static inline void MTX_Perspective(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_PerspectiveW_(fovySin, fovyCos, aspect, n, f, ((fx32) 0x0000000000001000L), 0, mtx);
}
static inline void MTX_Ortho(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, MtxFx44 *mtx) {
    G3i_OrthoW_(t, b, l, r, n, f, ((fx32) 0x0000000000001000L), 0, mtx);
}
static inline void MTX_FrustumW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_FrustumW_(t, b, l, r, n, f, scaleW, 0, mtx);
}
static inline void MTX_PerspectiveW(fx32 fovySin, fx32 fovyCos, fx32 aspect, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_PerspectiveW_(fovySin, fovyCos, aspect, n, f, scaleW, 0, mtx);
}
static inline void MTX_OrthoW(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f, fx32 scaleW, MtxFx44 *mtx) {
    G3i_OrthoW_(t, b, l, r, n, f, scaleW, 0, mtx);
}
typedef void (*MBCommPStateCallback)(u16 child_aid, u32 status, void *arg);
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

    MB_COMM_PSTATE_COUNT,

    MB_COMM_PSTATE_WM_EVENT = 0x80000000
} MBCommPState;
typedef enum {
    MB_COMM_RESPONSE_REQUEST_KICK,
    MB_COMM_RESPONSE_REQUEST_ACCEPT,
    MB_COMM_RESPONSE_REQUEST_DOWNLOAD,
    MB_COMM_RESPONSE_REQUEST_BOOT
} MBCommResponseRequestType;
typedef enum {
    MB_ERRCODE_SUCCESS = 0,

    MB_ERRCODE_INVALID_PARAM,
    MB_ERRCODE_INVALID_STATE,

    MB_ERRCODE_INVALID_DLFILEINFO,
    MB_ERRCODE_INVALID_BLOCK_NO,
    MB_ERRCODE_INVALID_BLOCK_NUM,
    MB_ERRCODE_INVALID_FILE,
    MB_ERRCODE_INVALID_RECV_ADDR,

    MB_ERRCODE_WM_FAILURE,

    MB_ERRCODE_FATAL,

    MB_ERRCODE_COUNT
} MBErrCode;
typedef struct {
    u16 errcode;
} MBErrorStatus;
typedef struct {
    const char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    const char *iconCharPathp;
    const char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[0x00000020];
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
typedef struct {
    u16 length;
    u16 rssi;
    u16 bssid[3];
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
} MBParentBssDesc;
typedef struct {
    u16 boot_type;
    MBParentBssDesc parent_bss_desc;
} MBParam;
typedef struct {
    u32 ggid;
    MBUserInfo userinfo;
    u16 version;
    u8 fileid;
    u8 pad[3];
} MBCommRequestData;
extern int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
extern int MB_GetParentSystemBufSize(void);
extern BOOL MB_SetParentCommSize(u16 sendSize);
extern BOOL MB_SetParentCommParam(u16 sendSize, u16 maxChildren);
extern u16 MB_GetTgid(void);
extern void MB_End(void);
extern void MB_EndToIdle(void);
extern void MB_DisconnectChild(u16 aid);
extern int MB_StartParent(int channel);
extern int MB_StartParentFromIdle(int channel);
extern u8 MB_CommGetChildrenNumber(void);
extern const MBUserInfo *MB_CommGetChildUser(u16 child_aid);
extern int MB_CommGetParentState(u16 child);
extern void MB_CommSetParentStateCallback(MBCommPStateCallback callback);
extern u32 MB_GetSegmentLength(FSFile *file);
extern BOOL MB_ReadSegment(FSFile *file, void *buf, u32 len);
extern BOOL MB_RegisterFile(const MBGameRegistry *game_reg, const void *buf);
extern BOOL MB_CommResponseRequest(u16 child_aid, MBCommResponseRequestType ack);
extern BOOL MB_CommIsBootable(u16 child_aid);
extern u16 MB_GetGameEntryBitmap(const MBGameRegistry *game_reg);
extern void MB_ReadMultiBootParentBssDesc(WMBssDesc *p_desc, u16 parent_max_size, u16 child_max_size, BOOL ks_flag,
                                          BOOL cs_flag);
extern void MB_SetLifeTime(u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern void MB_SetPowerSaveMode(BOOL enable);
static inline BOOL MB_CommStartSending(u16 child_aid) {
    return MB_CommResponseRequest(child_aid, MB_COMM_RESPONSE_REQUEST_DOWNLOAD);
}
static inline BOOL MB_CommStartSendingAll(void) {
    u8 child, num;

    for (num = 0, child = 1; child <= 15; child++) {
        if (1 == MB_CommStartSending(child)) {
            num++;
        }
    }

    if (num == 0) {
        return 0;
    }

    return 1;
}
static inline BOOL MB_CommBootRequest(u16 child_aid) {
    return MB_CommResponseRequest(child_aid, MB_COMM_RESPONSE_REQUEST_BOOT);
}
static inline BOOL MB_CommBootRequestAll(void) {
    u8 child, num;

    for (num = 0, child = 1; child <= 15; child++) {
        if (1 == MB_CommBootRequest(child)) {
            num++;
        }
    }

    if (num == 0) {
        return 0;
    }

    return 1;
}
static inline const MBParam *MB_GetMultiBootParam(void) {
    return (const MBParam *) (0x02000000 + 0x007ffc40);
}
static inline BOOL MB_IsMultiBootChild(void) {
    return MB_GetMultiBootParam()->boot_type == 2;
}
static inline const MBParentBssDesc *MB_GetMultiBootParentBssDesc(void) {
    return MB_IsMultiBootChild() ? &MB_GetMultiBootParam()->parent_bss_desc : ((void *) 0);
}
static inline const u8 *MB_GetMultiBootDownloadParameter(void) {
    return MB_IsMultiBootChild() ? (const u8 *) (0x02000000 + 0x007ffbe0) : ((void *) 0);
}
typedef void (*MBSendVolatCallbackFunc)(u32 ggid);
enum {
    MB_SEND_VOLAT_CALLBACK_TIMMING_BEFORE,
    MB_SEND_VOLAT_CALLBACK_TIMMING_AFTER
};
typedef enum MbBeaconDataAttr {
    MB_BEACON_DATA_ATTR_FIXED_NORMAL = 0,
    MB_BEACON_DATA_ATTR_FIXED_NO_ICON,
    MB_BEACON_DATA_ATTR_VOLAT
} MBBeaconDataAttr, MbBeaconDataAttr;
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
extern void MB_SetSendVolatCallback(MBSendVolatCallbackFunc callback, u32 timming);
extern void MB_SetUserVolatData(u32 ggid, const u8 *userData, u32 size);
extern void *MB_GetUserVolatData(const WMGameInfo *gameInfo);
typedef enum {
    MB_COMM_CSTATE_NONE,
    MB_COMM_CSTATE_INIT_COMPLETE,
    MB_COMM_CSTATE_CONNECT,
    MB_COMM_CSTATE_CONNECT_FAILED,
    MB_COMM_CSTATE_DISCONNECTED_BY_PARENT,
    MB_COMM_CSTATE_REQ_ENABLE,
    MB_COMM_CSTATE_REQ_REFUSED,
    MB_COMM_CSTATE_DLINFO_ACCEPTED,
    MB_COMM_CSTATE_RECV_PROCEED,
    MB_COMM_CSTATE_RECV_COMPLETE,
    MB_COMM_CSTATE_BOOTREQ_ACCEPTED,
    MB_COMM_CSTATE_BOOT_READY,
    MB_COMM_CSTATE_CANCELED,
    MB_COMM_CSTATE_CANCELLED = MB_COMM_CSTATE_CANCELED,
    MB_COMM_CSTATE_AUTHENTICATION_FAILED,
    MB_COMM_CSTATE_MEMBER_FULL,
    MB_COMM_CSTATE_GAMEINFO_VALIDATED,
    MB_COMM_CSTATE_GAMEINFO_INVALIDATED,
    MB_COMM_CSTATE_GAMEINFO_LOST,
    MB_COMM_CSTATE_GAMEINFO_LIST_FULL,
    MB_COMM_CSTATE_ERROR,

    MB_COMM_CSTATE_FAKE_END,

    MB_COMM_CSTATE_WM_EVENT = 0x80000000
} MBCommCState;
typedef void (*MBCommCStateCallbackFunc)(u32 status, void *arg);
typedef void (*MBFakeScanCallbackFunc)(u16 type, void *arg);
enum {
    MB_FAKESCAN_PARENT_FOUND,
    MB_FAKESCAN_PARENT_LOST,
    MB_FAKESCAN_API_ERROR,
    MB_FAKESCAN_END_SCAN,
    MB_FAKESCAN_PARENT_BEACON
};
typedef struct {
    u16 index;
    u16 padding;
    MBGameInfo *gameInfo;
    WMBssDesc *bssDesc;
} MBFakeScanCallback;
typedef struct {
    u16 apiid;
    u16 errcode;
} MBFakeScanErrorCallback;
extern void MB_FakeInit(void *buf, const MBUserInfo *user);
extern void MB_FakeEnd(void);
extern u32 MB_FakeGetWorkSize(void);
extern void MB_FakeSetCStateCallback(MBCommCStateCallbackFunc callback);
extern void MB_FakeStartScanParent(MBFakeScanCallbackFunc callback, u32 ggid);
extern void MB_FakeEndScan(void);
extern BOOL MB_FakeEntryToParent(u16 index);
extern BOOL MB_FakeGetParentGameInfo(u16 index, MBGameInfo *pGameInfo);
extern BOOL MB_FakeGetParentBssDesc(u16 index, WMBssDesc *pBssDesc);
extern BOOL MB_FakeReadParentBssDesc(u16 index, WMBssDesc *pBssDesc, u16 parent_max_size, u16 child_max_size, BOOL ks_flag,
                                     BOOL cs_flag);
typedef void (*WBTCallback)(void *);
typedef s16 WBTResult;
typedef u8 WBTPacketCommand;
typedef u8 WBTCommandCounter;
typedef u32 WBTBlockId;
typedef u16 WBTAidBitmap;
typedef s8 WBTPermission;
typedef s32 WBTBlockSeqNo;
typedef s16 WBTBlockNumEntry;
typedef s16 WBTPacketSize;
typedef s32 WBTBlockSize;
typedef enum {
    WBT_CMD_REQ_NONE = 0,
    WBT_CMD_REQ_WAIT,
    WBT_CMD_REQ_SYNC,
    WBT_CMD_RES_SYNC,
    WBT_CMD_REQ_GET_BLOCK,
    WBT_CMD_RES_GET_BLOCK,
    WBT_CMD_REQ_GET_BLOCKINFO,
    WBT_CMD_RES_GET_BLOCKINFO,
    WBT_CMD_REQ_GET_BLOCK_DONE,
    WBT_CMD_RES_GET_BLOCK_DONE,
    WBT_CMD_REQ_USER_DATA,
    WBT_CMD_RES_USER_DATA,
    WBT_CMD_SYSTEM_CALLBACK,
    WBT_CMD_PREPARE_SEND_DATA,
    WBT_CMD_REQ_ERROR,
    WBT_CMD_RES_ERROR,
    WBT_CMD_CANCEL
} WBTCommandType;
typedef struct {
    u32 id;
    s32 block_size;
    u8 user_id[32];
} WBTBlockInfo;
typedef struct WBTBlockInfoList {
    WBTBlockInfo data_info;
    struct WBTBlockInfoList *next;
    void *data_ptr;
    WBTAidBitmap permission_bmp;
    u16 block_type;
} WBTBlockInfoList;
typedef struct {
    WBTBlockInfo *block_info[((1 + 15 - 1) + 1)];
} WBTBlockInfoTable;
typedef struct {
    u32 *packet_bitmap[((1 + 15 - 1) + 1)];
} WBTPacketBitmapTable;
typedef struct {
    u8 *recv_buf[((1 + 15 - 1) + 1)];
} WBTRecvBufTable;
typedef struct {
    WBTBlockNumEntry num_of_list;
    s16 peer_packet_size;
    s16 my_packet_size;
    u16 pad1;
    u32 padd2[2];
} WBTRequestSyncCallback;
typedef struct {
    u32 block_id;
} WBTGetBlockDoneCallback;
typedef struct {
    u32 block_id;
    s32 block_seq_no;
    void *data_ptr;
    s16 own_packet_size;
    u16 padd;
} WBTPrepareSendDataCallback;
typedef struct {
    u8 data[9];
    u8 size;
    u8 padd[3];
} WBTRecvUserDataCallback;
typedef struct {
    u32 block_id;
    u32 recv_data_size;
    WBTRecvBufTable recv_buf_table;
    WBTPacketBitmapTable pkt_bmp_table;
} WBTGetBlockCallback;
typedef struct {
    WBTCommandType command;
    WBTCommandType event;
    u16 target_bmp;
    u16 peer_bmp;
    WBTCommandCounter my_cmd_counter;
    WBTCommandCounter peer_cmd_counter;
    WBTResult result;
    WBTCallback callback;
    union {
        WBTRequestSyncCallback sync;
        WBTGetBlockDoneCallback blockdone;
        WBTPrepareSendDataCallback prepare_send_data;
        WBTRecvUserDataCallback user_data;
        WBTGetBlockCallback get;
    };
} WBTCommand;
extern void WBT_InitParent(int send_packet_size, int recv_packet_size, WBTCallback callback);
extern void WBT_InitChild(WBTCallback callback);
extern void WBT_End(void);
extern int WBT_AidbitmapToAid(u16 abmp);
extern int WBT_GetOwnAid(void);
extern int WBT_CalcPacketbitmapSize(int block_size);
extern BOOL WBT_GetCurrentDownloadProgress(u32 block_id, int aid, int *current_count, int *total_count);
extern int WBT_NumOfRegisteredBlock(void);
extern BOOL WBT_RegisterBlock(WBTBlockInfoList *block_info_list, u32 block_id, const void *user_id, const void *data_ptr,
                              int data_size, u16 permission_bmp);
extern WBTBlockInfoList *WBT_UnregisterBlock(u32 block_id);
extern void WBT_PrintBTList(void);
extern BOOL WBT_SetPacketSize(int send_packet_size, int recv_packet_size);
extern int WBT_MpParentSendHook(void *sendbuf, int send_size);
extern void WBT_MpParentRecvHook(const void *recv_buf, int recv_size, int aid);
extern void WBT_SetOwnAid(int aid);
extern int WBT_MpChildSendHook(void *sendbuf, int send_size);
extern void WBT_MpChildRecvHook(const void *recv_buf, int recv_size);
extern BOOL WBT_RequestSync(u16 target, WBTCallback callback);
extern BOOL WBT_GetBlockInfo(u16 target, int index, WBTBlockInfoTable *block_info_table, WBTCallback callback);
extern BOOL WBT_GetBlock(u16 target, u32 block_id, WBTRecvBufTable *recv_buf_table, u32 recv_size,
                         WBTPacketBitmapTable *p_bmp_table, WBTCallback callback);
extern BOOL WBT_PutUserData(u16 target, const void *user_data, int size, WBTCallback callback);
extern BOOL WBT_CancelCurrentCommand(u16 target);
static inline u16 WBT_AidToAidbitmap(int aid) {
    return (u16) (1 << aid);
}
typedef void (*VIBCartridgePulloutCallback)(void);
typedef struct {
    u32 pulse_num;
    u32 rest_time;
    u32 on_time[6];
    u32 off_time[6];
    u32 repeat_num;
} VIBPulseState;
extern BOOL VIB_Init(void);
extern void VIB_End(void);
extern void VIB_StartPulse(const VIBPulseState *state);
extern void VIB_StopPulse(void);
extern BOOL VIB_IsExecuting(void);
extern void VIB_SetCartridgePulloutCallback(VIBCartridgePulloutCallback func);
extern BOOL VIB_IsCartridgeEnabled(void);
typedef s32 CARDiOwner;
enum {
    CARD_STAT_INIT     = (1 << 0),
    CARD_STAT_INIT_CMD = (1 << 1),
    CARD_STAT_BUSY     = (1 << 2),
    CARD_STAT_TASK     = (1 << 3),
    CARD_STAT_RECV     = (1 << 4),
    CARD_STAT_REQ      = (1 << 5),
    CARD_STAT_CANCEL   = (1 << 6)
};
typedef enum {
    CARD_TARGET_NONE,
    CARD_TARGET_ROM,
    CARD_TARGET_BACKUP
} CARDTargetMode;
typedef struct CARDiCommandArg {
    CARDResult result;
    CARDBackupType type;
    u32 id;
    u32 src;
    u32 dst;
    u32 len;

    struct {
        u32 total_size;
        u32 sect_size;
        u32 page_size;
        u32 addr_width;

        u32 program_page;
        u32 write_page;
        u32 write_page_total;
        u32 erase_chip;
        u32 erase_chip_total;
        u32 erase_sector;
        u32 erase_sector_total;
        u32 erase_page;

        u8 initial_status;
        u8 padding1[3];
        u32 caps;
        u8 padding2[16];
    } spec;

} CARDiCommandArg;
typedef struct CARDiCommon {
    CARDiCommandArg *cmd;
    int command;

    volatile CARDiOwner lock_owner;
    volatile int lock_ref;

    OSThreadQueue lock_queue[1];

    CARDTargetMode lock_target;
    u32 src;
    u32 dst;
    u32 len;
    u32 dma;
    CARDRequest req_type;
    int req_retry;
    CARDRequestMode req_mode;
    MIDmaCallback callback;
    void *callback_arg;
    void (*task_func)(struct CARDiCommon *);
    OSThread thread[1];
    OSThread *cur_th;
    u32 priority;

    OSThreadQueue busy_q[1];

    volatile u32 flag;

    u32 flush_threshold_ic;
    u32 flush_threshold_dc;

    u8 backup_cache_page_buf[256] __attribute__((aligned(32)));
} CARDiCommon;
extern CARDiCommon data_020c4d00;
extern void func_0200d9dc(PXIFifoTag tag, u32 data, BOOL err);
extern BOOL CARDi_WaitAsync(void);
extern BOOL CARDi_TryWaitAsync(void);
extern void CARDi_SetTask(void (*task)(CARDiCommon *));
extern void func_0200d980(void *arg);
extern void func_0200c810(void);
extern BOOL CARDi_Request(CARDiCommon *p, int req_type, int retry_max);
static inline void CARDi_SendPxi(u32 data) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_FS, data, 1) < 0)
        ;
}
static inline CARDTargetMode CARDi_GetTargetMode(void) {
    return data_020c4d00.lock_target;
}
static inline void CARDi_WaitTask(CARDiCommon *p, MIDmaCallback callback, void *callback_arg) {
    OSIntrMode bak_psr = OS_DisableInterrupts();
    while ((p->flag & CARD_STAT_BUSY) != 0) {
        OS_SleepThread(p->busy_q);
    }
    p->flag |= CARD_STAT_BUSY;
    p->callback     = callback;
    p->callback_arg = callback_arg;
    (void) OS_RestoreInterrupts(bak_psr);
}
static inline void CARDi_EndTask(CARDiCommon *p, BOOL is_own_task) {
    const MIDmaCallback func = p->callback;
    void *const arg          = p->callback_arg;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();

        p->flag &= ~(CARD_STAT_BUSY | CARD_STAT_TASK | CARD_STAT_CANCEL);
        OS_WakeupThread(p->busy_q);
        if ((p->flag & CARD_STAT_RECV) != 0) {
            func_02004ae4(p->thread);
        }
        (void) OS_RestoreInterrupts(bak_psr);
    }

    if (is_own_task && func) {
        (*func)(arg);
    }
}
extern void CARDi_InitStatusRegister(void);
extern void CARDi_IdentifyBackupCore(CARDBackupType type);
extern u8 CARDi_CommandReadStatus(void);
extern void CARDi_ReadBackupCore(u32 src, void *dst, u32 len);
extern void CARDi_ProgramBackupCore(u32 dst, const void *src, u32 len);
extern void CARDi_WriteBackupCore(u32 dst, const void *src, u32 len);
extern void CARDi_VerifyBackupCore(u32 dst, const void *src, u32 len);
extern void CARDi_EraseBackupSectorCore(u32 dst, u32 len);
extern void CARDi_EraseBackupSubSectorCore(u32 dst, u32 len);
extern void CARDi_EraseChipCore(void);
extern void CARDi_SetWriteProtectCore(u16 stat);
extern CARDiCommon data_020c4d00 __attribute__((aligned(32)));
extern CARDiCommandArg data_020c4ca0 __attribute__((aligned(32)));
extern u8 data_020c4f20[0x400] __attribute__((aligned(4)));
extern void CARDi_LockResource(CARDiOwner owner, CARDTargetMode target);
extern void CARDi_UnlockResource(CARDiOwner owner, CARDTargetMode target);
void CARDi_SetTask(void (*task)(CARDiCommon *));
void CARDi_LockResource(CARDiOwner owner, CARDTargetMode target);
void CARDi_UnlockResource(CARDiOwner owner, CARDTargetMode target);
void func_0200c810(void) {
    CARDiCommon *p = &data_020c4d00;

    p->lock_owner  = (-3);
    p->lock_ref    = 0;
    p->lock_target = CARD_TARGET_NONE;

    p->cmd = &data_020c4ca0;
    MI_CpuFillFast(&data_020c4ca0, 0x00, sizeof(data_020c4ca0));
    func_02005850(&data_020c4ca0, sizeof(data_020c4ca0));

    if (!MB_IsMultiBootChild()) {
        func_02006ae4((const void *) (0x02000000 + 0x007ffe00), (void *) (0x02000000 + 0x007ffa80), 0x00000160);
    }

    OS_InitThreadQueue(p->lock_queue);
    OS_InitThreadQueue(p->busy_q);
    p->priority = 4;
    func_02004d2c(p->thread, func_0200d980, ((void *) 0), data_020c4f20 + sizeof(data_020c4f20), sizeof(data_020c4f20),
                  p->priority);
    func_02004ae4(p->thread);

    func_02008170(PXI_FIFO_TAG_FS, func_0200d9dc);

    if (!MB_IsMultiBootChild()) {
        func_0200c7c4(1);
    }
}
extern BOOL CARDi_EnableFlag;
BOOL CARD_IsEnabled(void);
void CARD_CheckEnabled(void);
void func_0200c7c4(BOOL enable);
BOOL CARDi_WaitAsync(void);
BOOL CARDi_TryWaitAsync(void);
BOOL CARD_IsAvailable(void);
CARDResult CARD_GetResultCode(void);
u32 CARD_GetThreadPriority(void);
u32 CARD_SetThreadPriority(u32 prior);
void CARD_LockRom(u16 lock_id);
void CARD_UnlockRom(u16 lock_id);
void CARD_LockBackup(u16 lock_id);
void CARD_UnlockBackup(u16 lock_id);
const u8 *CARD_GetRomHeader(void);
