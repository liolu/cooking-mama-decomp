/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Sound_FlushCommand from https://github.com/RonyxDumb/mkds src/arm9/020211e4_Sound_FlushCommand.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed long s32;
typedef int BOOL;
struct SNDCommand {
    struct SNDCommand *llNext;
    s32 id;
    u32 arg[4];
};
extern const struct SNDCommand *func_020076c0(u32 flags);
extern BOOL func_0200741c(u32 flags);
typedef enum {
    OS_INTRMODE_DISABLE_IRQ = 0x80,
    OS_INTRMODE_DISABLE_FIQ = 0x40,
    OS_INTRMODE_ENABLE      = 0
} OSIntrMode;
extern OSIntrMode func_02006194(void);
extern OSIntrMode func_020061a8(OSIntrMode state);
extern void func_020061f8(u32 cycles);
extern void func_02005850(register const void *startAddr, register u32 nBytes);
extern s32 func_02008094(s32 fifotag, u32 data, BOOL err);
extern struct SNDCommand data_020c3240[256];
extern struct SNDCommand *data_020c2f88[8 + 1];
extern struct SNDCommand *data_020c2f6c;
extern struct SNDCommand *data_020c2f70;
extern s32 data_020c2f7c;
extern s32 data_020c2f80;
extern u32 data_020c2f84;
extern void func_02007188(void);
const struct SNDCommand *func_020076c0(u32 flags);
BOOL func_0200741c(u32 flags) {
    OSIntrMode oldirq = func_02006194();

    if (data_020c2f6c == ((void *) 0)) {
        (void) func_020061a8(oldirq);
        return 1;
    }

    if (data_020c2f80 >= 8) {
        if ((flags & 0x1) == 0) {
            (void) func_020061a8(oldirq);
            return 0;
        }

        do {
            (void) func_020076c0(0x1);
        } while (data_020c2f80 >= 8);
    }

    func_02005850(data_020c3240, sizeof(data_020c3240));

    s32 result = func_02008094(7, (u32) data_020c2f6c, 0);
    if (result < 0) {
        if ((flags & 0x1) == 0) {
            (void) func_020061a8(oldirq);
            return 0;
        }

        result = func_02008094(7, (u32) data_020c2f6c, 0);
        while (result < 0) {
            (void) func_020061a8(oldirq);
            func_020061f8(100);
            oldirq = func_02006194();
            result = func_02008094(7, (u32) data_020c2f6c, 0);
        }
    }

    if ((flags & 0x2) != 0) {
        func_02007188();
    }

    data_020c2f88[data_020c2f7c] = data_020c2f6c;

    if (++data_020c2f7c > 8) {
        data_020c2f7c = 0;
    }

    data_020c2f6c = ((void *) 0);
    data_020c2f70 = ((void *) 0);
    data_020c2f80++;
    data_020c2f84++;

    (void) func_020061a8(oldirq);
    return 1;
}
void func_02007188(void);
