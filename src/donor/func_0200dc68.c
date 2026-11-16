/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207c904 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_system.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
extern void func_02006440(void);
extern void func_02005818(void *ptr, u32 size);
extern void func_02005834(void *ptr, u32 size);
extern void func_02006ae4(const void *src, void *dest, u32 size);
extern void func_020069bc(const void *src, void *dest, u32 size);
extern void func_02006a50(void *dest, u8 value, u32 size);
extern void func_020069a4(u16 value, void *dest, u32 size);
typedef void (*UnkWmCallbackFunc)(void *arg);
typedef struct UnkWmStatus {
    u16 state;
    u8 unk_002[0xa];
    u32 unk_00c;
    u8 unk_010[0x2c];
    u16 unk_03c;
    u16 unk_03e;
    u8 unk_040[0x32];
    u16 unk_072;
    u8 unk_074[0x8];
    u32 unk_07c;
    u8 unk_080[0x6];
    u16 unk_086;
    u8 unk_088[0x14];
    u16 unk_09c;
    u8 unk_09e[0x1e];
    u16 unk_0bc;
    u8 unk_0be[0x8];
    u16 unk_0c6;
    u8 unk_0c8[0x30];
    u16 unk_0f8;
    u8 unk_0fa[0x88];
    u16 unk_182;
    u8 unk_184[0x4];
    u16 unk_188;
} UnkWmStatus;
typedef struct UnkWmArm9Buf {
    void *unk_000;
    UnkWmStatus *status;
    void *unk_008;
    void *unk_00c;
    void *unk_010;
    u16 dmaNo;
    u16 unk_016;
    UnkWmCallbackFunc callbackTable[0x2c];
    UnkWmCallbackFunc indCallback;
    UnkWmCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;
} UnkWmArm9Buf;
typedef struct UnkWmCallback {
    u16 apiid;
    u16 errcode;
} UnkWmCallback;
typedef struct UnkWmPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    u16 *recvBuf;
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
    u16 rssi;
    u16 maxSendDataSize;
    u16 maxRecvDataSize;
} UnkWmPortRecvCallback;
typedef struct UnkWmStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 unk_06;
    u16 *recvBuf;
} UnkWmStartMPCallback;
typedef struct UnkWmUnknownCallback {
    u16 apiid;
    u16 errcode;
    u8 unk_04[0x18];
    UnkWmCallbackFunc callback;
} UnkWmUnknownCallback;
typedef struct UnkWmStartParentCallback {
    u16 apiid;
    u16 errcode;
    u8 unk_04[4];
    u16 state;
    u8 macAddress[6];
    u16 aid;
    u16 reason;
    u8 ssid[24];
    u16 parentSize;
    u16 childSize;
} UnkWmStartParentCallback;
typedef struct UnkWmStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u8 unk_04[4];
    u16 state;
    u16 aid;
    u16 reason;
    u8 unk_0e[2];
    u8 macAddress[6];
    u16 parentSize;
    u16 childSize;
} UnkWmStartConnectCallback;
extern u32 func_0200e338(void);
extern void func_0200dc68(u32 tag, u32 data, BOOL err);
extern void func_0200dc4c(void);
extern u16 data_020c5568;
extern UnkWmArm9Buf *data_020c556c;
extern UnkWmPortRecvCallback data_020c55b8;
u32 func_0200e338(void);
void func_0200dc68(u32 tag, u32 data, BOOL err) {
    UnkWmArm9Buf *p   = data_020c556c;
    UnkWmCallback *cb = (UnkWmCallback *) data;

    if (err) {
        return;
    }

    func_02005818(p->unk_010, 0x100);
    if (p->unk_016 == 0) {
        func_02005818(p->status, 0x800);
    }
    if ((void *) cb != p->unk_010) {
        func_02005818(cb, 0x100);
    }

    if (cb->apiid >= 0x2c) {
        if (cb->apiid == 0x80) {
            if (cb->errcode == 0x13) {
                func_02006440();
            }
            if (p->indCallback) {
                p->indCallback(cb);
            }
        } else if (cb->apiid == 0x82) {
            UnkWmPortRecvCallback *cbPort = (UnkWmPortRecvCallback *) cb;
            if (p->portCallbackTable[cbPort->port]) {
                cbPort->arg                = p->portCallbackArgument[cbPort->port];
                cbPort->connectedAidBitmap = (u16) p->connectedAidBitmap;
                func_02005818(cbPort->recvBuf, p->status->unk_072);
                p->portCallbackTable[cbPort->port](cb);
            }
        } else if (cb->apiid == 0x81) {
            UnkWmUnknownCallback *cbUnknown = (UnkWmUnknownCallback *) cb;
            cb->apiid                       = 0xf;
            if (cbUnknown->callback) {
                cbUnknown->callback(cb);
            }
        }
    } else {
        if (cb->apiid == 0xe) {
            UnkWmStartMPCallback *cbStartMP = (UnkWmStartMPCallback *) cb;
            if ((cbStartMP->state == 11 || cbStartMP->state == 12) && cb->errcode == 0) {
                func_02005818(cbStartMP->recvBuf, p->status->unk_072);
            }
        }

        if (cb->apiid == 2 && cb->errcode == 0) {
            UnkWmCallbackFunc callback = p->callbackTable[cb->apiid];
            func_0200e338();
            if (callback) {
                callback(cb);
            }
            return;
        }

        if (p->callbackTable[cb->apiid]) {
            p->callbackTable[cb->apiid](cb);
            if (!data_020c5568) {
                return;
            }
        }

        if (cb->apiid == 8 || cb->apiid == 0xc) {
            u16 state;
            u16 aid;
            u16 myAid;
            u16 reason;
            u8 *macAddress;
            u8 *ssid;
            u16 parentSize;
            u16 childSize;

            if (cb->apiid == 8) {
                UnkWmStartParentCallback *cbParent = (UnkWmStartParentCallback *) cb;
                macAddress                         = cbParent->macAddress;
                state                              = cbParent->state;
                aid                                = cbParent->aid;
                reason                             = cbParent->reason;
                ssid                               = cbParent->ssid;
                myAid                              = 0;
                parentSize                         = cbParent->parentSize;
                childSize                          = cbParent->childSize;
            } else if (cb->apiid == 0xc) {
                UnkWmStartConnectCallback *cbConnect = (UnkWmStartConnectCallback *) cb;
                state                                = cbConnect->state;
                myAid                                = cbConnect->aid;
                reason                               = cbConnect->reason;
                aid                                  = 0;
                ssid                                 = 0;
                macAddress                           = cbConnect->macAddress;
                parentSize                           = cbConnect->parentSize;
                childSize                            = cbConnect->childSize;
            }

            if (state == 7 || state == 9 || state == 0x1a) {
                u16 i;

                if (state == 7) {
                    p->connectedAidBitmap |= (1 << aid);
                } else {
                    p->connectedAidBitmap &= ~(1 << aid);
                }
                p->myAid = myAid;

                func_02006a50(&data_020c55b8, 0, sizeof(UnkWmPortRecvCallback));
                data_020c55b8.apiid              = 0x82;
                data_020c55b8.errcode            = 0;
                data_020c55b8.state              = state;
                data_020c55b8.recvBuf            = 0;
                data_020c55b8.data               = 0;
                data_020c55b8.length             = 0;
                data_020c55b8.aid                = aid;
                data_020c55b8.myAid              = myAid;
                data_020c55b8.connectedAidBitmap = (u16) p->connectedAidBitmap;
                data_020c55b8.seqNo              = 0xffff;
                data_020c55b8.reason             = reason;
                func_02006ae4(macAddress, data_020c55b8.macAddress, 6);
                if (ssid) {
                    func_020069bc(ssid, data_020c55b8.ssid, 24);
                } else {
                    func_020069a4(0, data_020c55b8.ssid, 24);
                }
                data_020c55b8.maxSendDataSize = (myAid == 0) ? parentSize : childSize;
                data_020c55b8.maxRecvDataSize = (myAid == 0) ? childSize : parentSize;

                for (i = 0; i < 16; i++) {
                    data_020c55b8.port = i;
                    if (p->portCallbackTable[i]) {
                        data_020c55b8.arg = p->portCallbackArgument[i];
                        p->portCallbackTable[i](&data_020c55b8);
                    }
                }
            }
        }
    }

    func_02005818(p->unk_010, 0x100);
    func_0200dc4c();
    if ((void *) cb != p->unk_010) {
        cb->apiid |= 0x8000;
        func_02005834(cb, 0x100);
    }
}
void func_0200dc4c(void);
