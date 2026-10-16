/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef signed char s8;
typedef struct CallbackNode {
    void (*func)(void);
    void *arg;
    struct CallbackNode *next;
} CallbackNode;
extern s8 data_0211405c;
extern u32 data_02114064;
extern u32 data_02114060;
extern CallbackNode data_02114074;
extern CallbackNode data_02114068;
extern void func_02073074(void);
extern void func_02073068(void);
extern void func_0200709c(void);
extern void func_0200b26c(CallbackNode *node);
extern void func_0200b254(CallbackNode *node);
extern void *func_02073198(void);
extern void func_020740bc(void);
extern void func_020738e4(void);

/* SoundSystem_Init from https://github.com/sturmds/advance-wars-dual-strike-decomp src/game/main/sound/sound_system_init.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
void func_020730f0(void) {
    if (data_02114064 != 0) {
        return;
    }
    data_02114064 = 1;
    func_0200709c();
    data_02114068.func = func_02073074;
    data_02114068.arg  = ((void *) 0);
    data_02114074.func = func_02073068;
    data_02114074.arg  = ((void *) 0);
    func_0200b26c(&data_02114068);
    func_0200b254(&data_02114074);
    func_02073198();
    func_020740bc();
    func_020738e4();
    data_0211405c = -1;
    data_02114060 = 1;
}
