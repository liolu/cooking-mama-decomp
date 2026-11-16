/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0205cdec from projets/children-of-mana/src/auto/func_0205cdec.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 state);
typedef void (*PxiCallback)(u32 tag, u32 data, BOOL err);
extern void func_02008170(u32 tag, PxiCallback callback);
typedef struct UnkPxiSystemWork {
    u8 unk_000[0x388];
    u32 unk_388[2];
} UnkPxiSystemWork;
extern PxiCallback data_020c4aa8[32];
static inline UnkPxiSystemWork *GetPxiSystemWork(void) {
    return (UnkPxiSystemWork *) 0x027ffc00;
}
void func_02008170(u32 tag, PxiCallback callback) {
    u32 enabled = func_02006194();

    data_020c4aa8[tag] = callback;
    if (callback) {
        GetPxiSystemWork()->unk_388[0] |= (1 << tag);
    } else {
        GetPxiSystemWork()->unk_388[0] &= ~(1 << tag);
    }
    func_020061a8(enabled);
}
