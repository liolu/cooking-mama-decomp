/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02075c0c from projets/children-of-mana/src/auto/func_02075c0c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
extern void func_02005834(void *ptr, u32 size);
extern u32 func_02007b9c(void *waveArc);
extern void *func_02007b1c(void *waveArc, u32 index);
extern void func_02007b64(void *waveArc, u32 index, void *wave);
typedef struct UnkSndWaveArc UnkSndWaveArc;
typedef struct UnkSndWaveArcLink {
    UnkSndWaveArc *waveArc;
    struct UnkSndWaveArcLink *next;
} UnkSndWaveArcLink;
struct UnkSndWaveArc {
    u8 unk_00[8];
    u32 fileSize;
    u8 unk_0c[4];
    u8 blockHeader[8];
    UnkSndWaveArcLink *topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 waveOffset[0];
};
typedef void (*UnkSndHeapCallback)(void *mem, u32 size, void *data1, u32 data2);
extern s32 func_02074144(u32 fileId, void *dst, u32 size, u32 offset);
extern void *func_0207494c(void *heap, u32 size, UnkSndHeapCallback callback, void *data1, u32 data2);
extern void func_02074cf8(void *mem, u32 size, void *data1, u32 data2);
extern BOOL func_02074c04(UnkSndWaveArc *waveArc, u32 index, u32 fileId, void *heap);
extern void func_02074cf8(void *mem, u32 size, void *data1, u32 data2);
BOOL func_02074c04(UnkSndWaveArc *waveArc, u32 index, u32 fileId, void *heap) {
    u32 size;
    u32 offset;
    u32 end;

    if (func_02007b1c(waveArc, index) != 0) {
        return 1;
    }

    {
        u32 count = func_02007b9c(waveArc);
        u32 i     = waveArc->waveCount + index;
        offset    = waveArc->waveOffset[i];
        end       = index < count - 1 ? *(waveArc->waveOffset + i + 1) : waveArc->fileSize;
    }
    size = end - offset;

    if (heap == 0) {
        return 0;
    }

    heap = func_0207494c(heap, size + 0x20, func_02074cf8, waveArc, index);
    if (heap == 0) {
        return 0;
    }

    if (size != func_02074144(fileId, heap, size, offset)) {
        return 0;
    }

    func_02005834(heap, size);
    func_02007b64(waveArc, index, heap);
    return 1;
}
