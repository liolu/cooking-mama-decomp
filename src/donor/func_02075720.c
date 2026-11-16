/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020766f0 from projets/children-of-mana/src/auto/func_020766f0.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
typedef struct UnkSndSeqParam {
    u32 fileId;
    u16 bankNo;
    u8 volume;
    u8 channelPrio;
    u8 playerPrio;
    u8 playerNo;
} UnkSndSeqParam;
typedef struct UnkSndSeqData {
    u8 unk_00[0x18];
    u32 dataOffset;
} UnkSndSeqData;
extern int func_02075308(int bankNo, u32 flags, void *heap, BOOL addToArc, void **pData);
extern void *func_020736b4(void *handle, int playerNo, int prio);
extern void func_020736a8(void *seqPlayer);
extern void func_0207364c(void *seqPlayer, const void *seq, u32 offset, const void *bank);
extern void *func_02073548(int playerNo, void *seqPlayer);
extern void func_02073a40(void *handle, int volume);
extern void func_02073a10(void *handle, int prio);
extern void func_0207399c(void *handle, int seqArcNo, int index);
extern BOOL func_02075720(void *handle, int playerNo, int bankNo, int playerPrio, UnkSndSeqParam *param, UnkSndSeqData *seqArc,
                          int seqArcNo, int index);
BOOL func_02075720(void *handle, int playerNo, int bankNo, int playerPrio, UnkSndSeqParam *param, UnkSndSeqData *seqArc,
                   int seqArcNo, int index) {
    void *seqPlayer;
    void *heap;
    void *bank;

    seqPlayer = func_020736b4(handle, playerNo, playerPrio);
    if (seqPlayer == 0) {
        return 0;
    }

    heap = func_02073548(playerNo, seqPlayer);

    if (func_02075308(bankNo, 6, heap, 0, &bank) != 0) {
        func_020736a8(seqPlayer);
        return 0;
    }

    func_0207364c(seqPlayer, (u8 *) seqArc + seqArc->dataOffset, param->fileId, bank);
    func_02073a40(handle, param->volume);
    func_02073a10(handle, param->channelPrio);
    func_0207399c(handle, seqArcNo, index);
    return 1;
}
