/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201a054 from projets/code-lyoko/src/donor/func_0201a054.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern const u16(*ctrdgi_fl_maxtime);
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
extern void func_020121cc(u32 ggid, u16 tgid, u8 attribute);
typedef enum MbBeaconState {
    MB_BEACON_STATE_STOP = 0,
    MB_BEACON_STATE_READY,
    MB_BEACON_STATE_FIXED_START,
    MB_BEACON_STATE_FIXED,
    MB_BEACON_STATE_VOLAT_START,
    MB_BEACON_STATE_VOLAT,
    MB_BEACON_STATE_NEXT_GAME
} MbBeaconState;
typedef struct MbBeaconSendStatus {
    MBGameInfo *gameInfoListTop;
    MBGameInfo *nowGameInfop;
    u8 *srcp;
    u8 state;
    u8 seqNoFixed;
    u8 seqNoVolat;
    u8 flagmentNo;
    u8 flagmentMaxNum;
    u8 beaconNo;
    u8 pad[2];
} MbBeaconSendStatus;
extern BOOL func_02012120(void);
extern void func_020120d4(void);
extern void func_02011f5c(u32 ggid, u16 tgid, u8 attribute);
extern void func_02011f2c(void);
extern void func_02011c88(u32 ggid, u16 tgid, u8 attribute);
extern MbBeaconSendStatus data_020c6090;
void func_020121cc(u32 ggid, u16 tgid, u8 attribute) {
    while (1) {
        switch (data_020c6090.state) {
            case MB_BEACON_STATE_STOP:
            case MB_BEACON_STATE_READY:
                if (!func_02012120()) {
                    return;
                }
                break;
            case MB_BEACON_STATE_FIXED_START:
                func_020120d4();
                break;
            case MB_BEACON_STATE_FIXED:
                func_02011f5c(ggid, tgid, attribute);
                return;
            case MB_BEACON_STATE_VOLAT_START:
                func_02011f2c();
                break;
            case MB_BEACON_STATE_VOLAT:
                func_02011c88(ggid, tgid, attribute);
                return;
            case MB_BEACON_STATE_NEXT_GAME:
                break;
        }
    }
}
extern BOOL func_02012120(void);
extern void func_020120d4(void);
extern void func_02011f5c(u32 ggid, u16 tgid, u8 attribute);
extern void func_02011f2c(void);
extern void func_02011c88(u32 ggid, u16 tgid, u8 attribute);
