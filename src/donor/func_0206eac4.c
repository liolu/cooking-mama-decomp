/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* BL_RandomSetSeed from https://github.com/gamemasterplc/bltouch2 include/src_common/random.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
extern void func_0206eac4(u32 value);
extern struct {
    u32 seed;
    u32 mul;
    u32 add;

} data_021139dc;
void func_0206eac4(u32 value) {
    data_021139dc.seed = value;
    data_021139dc.mul  = 0x5d588b65;
    data_021139dc.add  = 0x269ec3;
}
