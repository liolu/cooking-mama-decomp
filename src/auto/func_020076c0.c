/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 state);
extern void func_020061f8(u32 count);
typedef struct UnkSndCommand {
    struct UnkSndCommand *next;
    s32 id;
    u32 arg[4];
} UnkSndCommand;
extern UnkSndCommand *func_020076c0(u32 flags);
extern u32 func_02007a3c(void);
extern u32 data_020c2f68;
extern UnkSndCommand *data_020c2f74;
extern UnkSndCommand *data_020c2f64;
extern s32 data_020c2f78;
extern s32 data_020c2f80;
extern UnkSndCommand *data_020c2f88[9];

/* func_0207a818 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_command.c (license: none), reused
 * by tools/donor_match.py */
UnkSndCommand *func_020076c0(u32 flags) {
    u32 enabled = func_02006194();
    UnkSndCommand *head;
    UnkSndCommand *tail;

    if (flags & 1) {
        while (data_020c2f68 == func_02007a3c()) {
            func_020061a8(enabled);
            func_020061f8(100);
            enabled = func_02006194();
        }
    } else if (data_020c2f68 == func_02007a3c()) {
        func_020061a8(enabled);
        return 0;
    }

    head = data_020c2f88[data_020c2f78];
    data_020c2f78++;
    if (data_020c2f78 > 8) {
        data_020c2f78 = 0;
    }

    tail = head;
    while (tail->next != 0) {
        tail = tail->next;
    }

    if (data_020c2f74 != 0) {
        data_020c2f74->next = head;
    } else {
        data_020c2f64 = head;
    }
    data_020c2f74 = tail;
    data_020c2f80--;
    data_020c2f68++;

    func_020061a8(enabled);
    return head;
}
