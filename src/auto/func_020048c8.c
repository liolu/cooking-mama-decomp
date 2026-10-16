/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
extern u32 func_02006180(void);
extern void func_02006434(void);
extern void func_020048c8(void *arg);

/* func_02078bc4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_thread.c (license: none), reused by
 * tools/donor_match.py */
void func_020048c8(void *arg) {
    func_02006180();
    while (1) {
        func_02006434();
    }
}
