/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MBi_SendFixedBeacon from https://github.com/Project-Holon/aletheia src/matched/ov_sdk/ov107_func_021F4140.c (license: none
 * (MIT = tooling only)), reused by tools/donor_match.py */
typedef struct {
    unsigned short sum;
    unsigned char fragmentNo;
    unsigned char fragmentMaxNum;
    unsigned char size;
    unsigned char rsv;
    unsigned short data[0x31];
} MbBeaconFixed;
typedef struct {
    unsigned long ggid;
    unsigned char dataAttr : 2;
    unsigned char fileNo : 6;
    unsigned char seqNoFixed;
    unsigned char seqNoVolat;
    unsigned char beaconNo;
    union {
        MbBeaconFixed fixed;
        unsigned short raw[0x34];
    } data;
} MbBeacon;
typedef struct {
    void *top;
    unsigned char *nowGInfop;
    unsigned char *nowFixedp;
    unsigned char state;
    unsigned char pad1;
    unsigned char seqNoVolat;
    unsigned char fragmentNo;
    unsigned char fragmentMaxNum;
    unsigned char beaconNo;
} MbSendStatus;
extern void *sSendVolatCallback;
extern void *sSendVolatCallbackTiming;
extern void *mbrsp;
extern void *brecvBuffp;
extern void (*sLockFunc)(void);
extern void (*sUnlockFunc)(void);
extern MbSendStatus data_020c6090;
extern MbBeacon data_020c60c0 __attribute__((aligned(32)));
extern void func_020069a4(unsigned short data, void *destp, unsigned long size);
extern void func_020069bc(const void *srcp, void *destp, unsigned long size);
extern unsigned short func_02011c04(unsigned short *buf, int length);
extern int func_0200f89c(void *callback, unsigned short *userGameInfo, unsigned short size, unsigned long ggid,
                         unsigned short tgid, unsigned char attr);
static inline void MI_CpuClear16(void *dest, unsigned long size) {
    func_020069a4(0, dest, size);
}
static inline void MI_CpuCopy16(const void *src, void *dest, unsigned long size) {
    func_020069bc(src, dest, size);
}
void func_02011f5c(unsigned long ggid, unsigned short tgid, unsigned char attribute) {
    unsigned long lastAddr = (unsigned long) data_020c6090.nowGInfop + 0x358;

    if ((unsigned long) data_020c6090.nowFixedp + 0x62 <= lastAddr) {
        data_020c60c0.data.fixed.size = 0x62;
    } else {
        data_020c60c0.data.fixed.size = (unsigned char) (lastAddr - (unsigned long) data_020c6090.nowFixedp);
        MI_CpuClear16((void *) ((unsigned char *) data_020c60c0.data.fixed.data + data_020c60c0.data.fixed.size),
                      (unsigned long) (0x62 - data_020c60c0.data.fixed.size));
    }
    MI_CpuCopy16(data_020c6090.nowFixedp, data_020c60c0.data.fixed.data, data_020c60c0.data.fixed.size);
    data_020c60c0.data.fixed.fragmentNo     = data_020c6090.fragmentNo;
    data_020c60c0.data.fixed.fragmentMaxNum = data_020c6090.fragmentMaxNum;
    data_020c60c0.dataAttr                  = data_020c6090.nowGInfop[0x4B2];
    data_020c60c0.seqNoFixed                = data_020c6090.nowGInfop[0x4B3];
    data_020c60c0.seqNoVolat                = data_020c6090.seqNoVolat;
    data_020c60c0.ggid                      = *(unsigned long *) (data_020c6090.nowGInfop + 0x4B8);
    data_020c60c0.fileNo                    = data_020c6090.nowGInfop[0x4B5];
    data_020c60c0.beaconNo                  = data_020c6090.beaconNo++;
    data_020c60c0.data.fixed.sum            = 0;
    data_020c60c0.data.fixed.sum = func_02011c04((unsigned short *) &data_020c60c0.data, sizeof(data_020c60c0.data));
    data_020c6090.fragmentNo++;
    if (data_020c6090.fragmentNo < data_020c6090.fragmentMaxNum) {
        data_020c6090.nowFixedp += 0x62;
    } else {
        data_020c6090.state = 4;
    }
    func_0200f89c(0, (unsigned short *) &data_020c60c0, 0x70, ggid, tgid, (unsigned char) (attribute | 3));
}
