/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020a0f38 from https://github.com/cntrl-alt-lenny/gx-spirit-caller src/main/func_020a0f38.legacy.c (license: MIT),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern unsigned char *data_020c613c;
extern u8 data_02084ea8;
extern void func_02006a50(void *, int, unsigned int);
extern void func_02006ae4(const void *, void *, unsigned int);
extern void *func_02014bc0(void *, void *);
extern int func_02011c4c(int a, int b, int c);
int func_0200ff24(int unused0) {
    s8 chosen = -1;
    u16 mask  = 0;
    struct {
        u8 type;
        u16 id;
        u16 value;
    } command;
    u8 counts[16];
    u16 i;
    u8 n;
    u8 current;
    unsigned char *base;
    void *dest;
    func_02006a50(counts, 0, 16);
    base = data_020c613c;
    for (i = 1; i <= 15; i++) {
        if (*(int *) (base + 0x14e8 + (i - 1) * 4) == 5) {
            counts[*(s8 *) (base + 0x1526 + (i - 1))]++;
        }
    }
    current = data_02084ea8;
    for (n = 0; n < 16; n++) {
        current = (current + 1) % 16;
        if (*(u8 *) (base + current * 0x5d4 + 0x1d52) != 0) {
            if (counts[current] != 0) {
                chosen = current;
                break;
            }
        }
    }
    if (chosen == -1) {
        return 21;
    }
    data_02084ea8 = chosen;
    for (i = 1; i <= 15; i++) {
        if (*(int *) (base + 0x14e8 + (i - 1) * 4) == 5) {
            if (chosen == *(s8 *) (base + 0x1526 + (i - 1))) {
                mask |= 1 << i;
            }
        }
    }
    command.type = 3;
    command.id   = chosen;
    dest         = func_02014bc0(&command, base);
    if (dest != 0) {
        func_02006ae4(data_020c613c + 0x1788 + chosen * 0x5d4, dest, 0xe4);
    }
    return func_02011c4c(0xea, mask, (int) data_020c613c);
}
