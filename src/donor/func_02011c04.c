/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02018c70 from projets/code-lyoko/src/donor/func_02018c70.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
extern const u16(*ctrdgi_fl_maxtime);
extern u16 func_02011c04(const u16 *buf, int length);
u16 func_02011c04(const u16 *buf, int length) {
    u32 sum;
    int nwords = length >> 1;

    for (sum = 0; nwords > 0; nwords--) {
        sum += *buf++;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (u16) (sum ^ 0xffff);
}
