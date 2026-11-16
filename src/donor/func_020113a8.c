/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020a2418 from https://github.com/cntrl-alt-lenny/gx-spirit-caller src/main/func_020a2418.legacy.c (license: MIT),
 * reused by tools/donor_match.py */
typedef struct {
    unsigned char pad[0x1d1f];
    unsigned char tag;
    unsigned char pad20;
    unsigned char index;
    unsigned char pad22[0x1e];
    void *handle;
    void *file;
    unsigned char pad48[6];
    unsigned short status;
    unsigned char pad50[2];
    unsigned char active;
    unsigned char pad53;
    unsigned char *ptr;
    unsigned char *ptr2;
} View;
typedef struct {
    int f0;
    unsigned short *f4;
    void *f8, *fc, *f10;
    int f14;
    unsigned char f18;
} Input;
typedef struct node_020a333c {
    char _pad[0x4bc];
    struct node_020a333c *next;
} node_020a333c_t;
extern unsigned char *data_020c613c;
extern unsigned char data_020c6084;
extern int func_02006194(void);
extern void func_020061a8(int unused0);
extern int func_020125c4(void);
extern void func_02011324(void *, void *);
extern void func_02006ae4(const void *, void *, int);
extern int func_02011090(void *, void *);
extern void func_02012470(char *p, Input *in, void *extra);
extern void func_020122cc(node_020a333c_t *node);
extern int func_020147b8(void);
extern int func_020147a4();
extern void func_020147d4(char *a0, char *a1);
int func_020113a8(Input *in, unsigned char *file) {
    unsigned char *p;
    unsigned char index = 0xff;
    int saved;
    unsigned char i;
    int off;
    saved = func_02006194();
    if (!func_020125c4()) {
        func_020061a8(saved);
        return 0;
    }
    if (data_020c613c[0x1524] + 1 > 16) {
        func_020061a8(saved);
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (((View *) (data_020c613c + i * 0x5d4))->handle == in) {
            func_020061a8(saved);
            return 0;
        }
        if (((View *) (data_020c613c + i * 0x5d4))->active == 0) {
            index = i;
            break;
        }
    }
    if (i == 16) {
        func_020061a8(saved);
        return 0;
    }
    off                                        = index * 0x5d4;
    *(Input **) (data_020c613c + off + 0x1d40) = in;
    p                                          = data_020c613c + 0x1788 + off;
    func_02011324(p, file);
    func_02006ae4((unsigned char *) in + 0x1c, p + 0xc4, 0x20);
    if (!func_02011090(data_020c613c + 0x1d2c + off, p)) {
        func_020061a8(saved);
        return 0;
    }
    func_02012470((char *) data_020c613c + 0x186c + off, in, data_020c613c + 0x1300);
    ((View *) (data_020c613c + off))->index = index;
    func_020122cc((node_020a333c_t *) (data_020c613c + 0x186c + off));
    ((View *) (data_020c613c + off))->tag              = data_020c6084++;
    *(unsigned short *) (data_020c613c + off + 0x1d4e) = 1;
    *(unsigned char **) (data_020c613c + off + 0x1d44) = file;
    *(unsigned char **) (data_020c613c + off + 0x1d54) = file + 0x1e8;
    *(unsigned char **) (data_020c613c + off + 0x1d58) = file + 0x258;
    if (*(int *) (*(unsigned char **) (data_020c613c + off + 0x1d54) + 0x6c) != 0 && !func_020147b8()) {
        func_020147a4((int) (data_020c613c + 0x7ce0));
        func_020147d4((char *) data_020c613c + 0x74e0, (char *) 0x800);
    }
    ((View *) (data_020c613c + off))->active = 1;
    data_020c613c[0x1524]++;
    func_020061a8(saved);
    return 1;
}
