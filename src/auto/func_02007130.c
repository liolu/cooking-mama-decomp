/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
extern u32 func_02006194(void);
extern u32 func_020061a8(u32 state);
typedef struct UnkSndCommand {
    struct UnkSndCommand *next;
    s32 id;
    u32 arg[4];
} UnkSndCommand;
extern UnkSndCommand *func_02007130(void);
extern UnkSndCommand *data_020c2f74;
extern UnkSndCommand *data_020c2f64;

/* func_0207adcc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_command.c (license: none), reused
 * by tools/donor_match.py */
UnkSndCommand *func_02007130(void) {
    UnkSndCommand *cmd;
    u32 enabled = func_02006194();

    cmd = data_020c2f64;
    if (cmd == 0) {
        func_020061a8(enabled);
        return 0;
    }
    data_020c2f64 = cmd->next;
    if (data_020c2f64 == 0) {
        data_020c2f74 = 0;
    }
    func_020061a8(enabled);
    return cmd;
}
