/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02075810 from projets/children-of-mana/src/auto/func_02075810.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
typedef struct {
    void *prevObject;
    void *nextObject;
} NNSFndLink;
typedef struct {
    void *headObject;
    void *tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
extern void func_02075f10(NNSFndList *list, void *object);
extern void *func_02075ee4(NNSFndList *list, void *object);
typedef struct NNSiFndHeapHead NNSiFndHeapHead;
struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void *heapStart;
    void *heapEnd;
    u32 attribute;
};
typedef NNSiFndHeapHead *NNSFndHeapHandle;
extern BOOL func_020768d0(NNSFndHeapHandle heap, u32 tagName);
extern BOOL func_02076874(NNSFndHeapHandle heap, u32 tagName);
typedef void (*NNSSndHeapDisposeCallback)(void *mem, u32 size, u32 data1, u32 data2);
typedef struct NNSSndHeap *NNSSndHeapHandle;
extern void func_020749bc(NNSSndHeapHandle heap);
extern void func_02074808(NNSSndHeapHandle heap, int level);
typedef struct NNSSndHeap {
    NNSFndHeapHandle handle;
    NNSFndList sectionList;
} NNSSndHeap;
typedef struct NNSSndHeapBlock {
    NNSFndLink link;
    u32 size;
    NNSSndHeapDisposeCallback callback;
    u32 data1;
    u32 data2;
    u8 padding[0x20 - ((sizeof(NNSFndLink) + sizeof(NNSSndHeapDisposeCallback) + sizeof(u32) * 3) & 0x1f)];
    u32 buffer[0];
} NNSSndHeapBlock;
typedef struct NNSSndHeapSection {
    NNSFndList blockList;
    NNSFndLink link;
} NNSSndHeapSection;
extern BOOL func_02074738(NNSSndHeap *heap);
extern void func_02074714(void);
extern void func_020749bc(NNSSndHeapHandle heap);
void func_02074808(NNSSndHeapHandle heap, int level) {
    NNSSndHeapSection *section;
    void *object = ((void *) 0);
    BOOL result;
    BOOL doCallback = 0;

    ((void) 0);
    ((void) 0);

    if (level == 0) {
        func_020749bc(heap);
        return;
    }

    while (level < heap->sectionList.numObjects) {
        section = (NNSSndHeapSection *) func_02075ee4(&heap->sectionList, ((void *) 0));

        while ((object = func_02075ee4(&section->blockList, object)) != ((void *) 0)) {
            NNSSndHeapBlock *block = (NNSSndHeapBlock *) object;
            if (block->callback != ((void *) 0)) {
                block->callback(block->buffer, block->size, block->data1, block->data2);
                doCallback = 1;
            }
        }

        func_02075f10(&heap->sectionList, section);
    }

    result = func_02076874(heap->handle, (u32) level);
    ((void) 0);

    if (doCallback) {
        func_02074714();
    }

    result = func_020768d0(heap->handle, heap->sectionList.numObjects);
    ((void) 0);

    result = func_02074738(heap);
    ((void) 0);
}
extern BOOL func_02074738(NNSSndHeap *heap);
extern void func_02074714(void);
