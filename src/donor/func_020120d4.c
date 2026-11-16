/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02019f5c from projets/code-lyoko/src/donor/func_02019f5c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
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
typedef enum MbBeaconDataAttr {
    MB_BEACON_DATA_ATTR_FIXED_NORMAL = 0,
    MB_BEACON_DATA_ATTR_FIXED_NO_ICON,
    MB_BEACON_DATA_ATTR_VOLAT
} MBBeaconDataAttr, MbBeaconDataAttr;
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
extern void func_020120d4(void);
extern MbBeaconSendStatus data_020c6090;
void func_020120d4(void) {
    if (data_020c6090.state != MB_BEACON_STATE_FIXED_START) {
        return;
    }

    if (data_020c6090.nowGameInfop->dataAttr == MB_BEACON_DATA_ATTR_FIXED_NORMAL) {
        data_020c6090.flagmentMaxNum =
            ((sizeof(MBGameInfoFixed) / ((112 - 8) - 6)) + (sizeof(MBGameInfoFixed) % ((112 - 8) - 6) ? 1 : 0));
        data_020c6090.srcp = (u8 *) &data_020c6090.nowGameInfop->fixed;
    } else {
        data_020c6090.flagmentMaxNum = (((sizeof(MBGameInfoFixed) - sizeof(MBIconInfo)) / ((112 - 8) - 6)) +
                                        ((sizeof(MBGameInfoFixed) - sizeof(MBIconInfo)) % ((112 - 8) - 6) ? 1 : 0));
        data_020c6090.srcp           = (u8 *) &data_020c6090.nowGameInfop->fixed.parent;
    }

    data_020c6090.state = MB_BEACON_STATE_FIXED;
}
