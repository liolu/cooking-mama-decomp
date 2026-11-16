/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02074284 from projets/children-of-mana/src/auto/func_02074284.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct NNSFndLink {
    void *previous;
    void *next;
} NNSFndLink;
typedef struct NNSFndList {
    void *head;
    void *tail;
    u16 count;
    u16 offset;
} NNSFndList;
typedef struct NNSFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList children;
    u8 *start;
    u8 *end;
    u32 attributes;
} NNSFndHeapHead;
extern void *func_02075ef8(NNSFndList *list, void *object);
typedef struct NNSiSndFader {
    int origin;
    int target;
    int position;
    int duration;
} NNSiSndFader;
typedef struct NNSiSndSeqPlayer NNSiSndSeqPlayer;
typedef struct NNSiSndPlayer NNSiSndPlayer;
typedef struct NNSiSndSeqHeap NNSiSndSeqHeap;
typedef struct NNSSndHeap NNSSndHeap;
struct NNSSndHeap {
    NNSFndHeapHead *frame;
    NNSFndList sections;
};
typedef struct NNSSndHandle {
    NNSiSndSeqPlayer *player;
} NNSSndHandle;
struct NNSiSndPlayer {
    NNSFndList sequences;
    NNSFndList heaps;
    u32 max_sequences;
    u32 channel_mask;
    u8 volume;
    u8 padding21[3];
};
struct NNSiSndSeqHeap {
    NNSFndLink link;
    NNSSndHeap *heap;
    NNSiSndSeqPlayer *player;
    int player_index;
};
struct NNSiSndSeqPlayer {
    NNSSndHandle *handle;
    NNSiSndPlayer *owner;
    NNSiSndSeqHeap *heap;
    NNSFndLink player_link;
    NNSFndLink global_link;
    NNSiSndFader fader;
    u8 state;
    u8 started;
    u8 paused;
    u8 start_pending;
    u32 command;
    u16 sequence_kind;
    u16 unknown36;
    u16 archive_or_sequence;
    u16 archive_sequence;
    u8 index;
    u8 priority;
    s16 volume_db;
    u8 initial_volume;
    u8 external_volume;
    u8 padding42[2];
};
extern int func_02075e58(NNSiSndFader *fader);
extern void func_02075e40(NNSiSndFader *fader);
extern int func_02075e28(NNSiSndFader *fader);
extern void func_020732f8(NNSiSndSeqPlayer *sequence);
extern void func_02073404(NNSiSndSeqPlayer *sequence);
extern void func_02073770(void);
extern NNSFndList data_02114098;
extern const s16 data_020806b0[128];
extern void func_02006f8c(u32 sequence, int volume);
extern int func_020072f8(u32 command);
extern u32 func_02007a70(void);
extern void func_02006fe8(u32 sequence);
void func_02073770(void) {
    u32 active_mask            = func_02007a70();
    NNSiSndSeqPlayer *sequence = func_02075ef8(&data_02114098, 0);
    while (sequence) {
        NNSiSndSeqPlayer *next = func_02075ef8(&data_02114098, sequence);
        if (!sequence->started && func_020072f8(sequence->command)) {
            sequence->started = 1;
        }
        if (sequence->started && !(active_mask & (1 << sequence->index))) {
            func_020732f8(sequence);
        } else {
            int external_volume;
            int initial_volume;
            int player_volume;
            int volume;
            int fade;
            func_02075e40(&sequence->fader);
            external_volume = data_020806b0[sequence->external_volume];
            initial_volume  = data_020806b0[sequence->initial_volume];
            player_volume   = data_020806b0[sequence->owner->volume];
            fade            = data_020806b0[func_02075e58(&sequence->fader) >> 8];
            volume          = (player_volume + (initial_volume + external_volume)) + fade;
            if (volume < -723) {
                volume = -723;
            } else if (volume > 0) {
                volume = 0;
            }
            if (volume != sequence->volume_db) {
                func_02006f8c(sequence->index, volume);
                sequence->volume_db = volume;
            }
            if (sequence->state == 2 && func_02075e28(&sequence->fader)) {
                func_02073404(sequence);
            }
            if (sequence->start_pending) {
                func_02006fe8(sequence->index);
                sequence->start_pending = 0;
            }
        }
        sequence = next;
    }
}
extern void func_02073404(NNSiSndSeqPlayer *sequence);
extern void func_020732f8(NNSiSndSeqPlayer *sequence);
