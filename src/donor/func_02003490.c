/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020595ac from projets/children-of-mana/src/auto/func_020595ac.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
extern void func_020069ec(register const void *srcp, register void *destp, register u32 size);
typedef void (*MIDmaCallback)(void *);
extern void func_02006898(u32 dmaNo, const void *src, void *dest, u32 size);
extern void func_020066a0(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void func_02003490(void *src, u32 offset, u32 size);
static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (dmaNo != -1 && size > 0x30) {
        func_02006898(dmaNo, src, dest, size);
    } else {
        func_020069ec(src, dest, size);
    }
}
static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    if (dmaNo != -1) {
        func_020066a0(dmaNo, src, dest, size, callback, arg);
    } else {
        func_020069ec(src, dest, size);
    }
}
extern u32 data_020c2b90;
extern u32 data_020c2b80;
extern u32 data_020c2b94;
extern u32 data_02084e84;
#pragma thumb off
void func_02003490(void *src, u32 offset, u32 size) {
    void *temp;
    if (!data_020c2b90) {
        temp = (void *) (data_020c2b80 + offset);
    } else {
        if ((offset + size) < data_020c2b94) {
            temp = (void *) (data_020c2b80 + offset);
        } else if (offset >= data_020c2b94) {
            temp = (void *) (data_020c2b90 + offset - data_020c2b94);
        } else {
            void *temp2 = (void *) data_020c2b90;
            u32 temp1   = data_020c2b94 - offset;
            temp        = (void *) (data_020c2b80 + offset);
            GXi_DmaCopy32(data_02084e84, src, temp, temp1);
            GXi_DmaCopy32Async(data_02084e84, (void *) ((u8 *) src + temp1), temp2, (size - temp1), ((void *) 0),
                               ((void *) 0));
            return;
        }
    }
    GXi_DmaCopy32Async(data_02084e84, src, temp, size, ((void *) 0), ((void *) 0));
}
