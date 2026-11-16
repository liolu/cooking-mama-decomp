/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02014820 from projets/code-lyoko/src/donor/func_02014820.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;
extern void func_0200c540(void);
extern int func_0200c480(RTCTime *time);
extern u32 data_02084ea4;
u16 func_0200e5d4(void) {
    enum {
        TGID_DEFAULT = (1 << 16)
    };

    if (data_02084ea4 == (u32) TGID_DEFAULT) {
        RTCTime rt[1];
        func_0200c540();
        if (func_0200c480(rt) == 0) {
            data_02084ea4 = (u16) (rt->second + (rt->minute << 8));
        }
    }

    data_02084ea4 = (u16) (data_02084ea4 + 1);
    return (u16) data_02084ea4;
}
