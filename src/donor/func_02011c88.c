/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020a2cf8 from https://github.com/cntrl-alt-lenny/gx-spirit-caller src/main/func_020a2cf8.legacy.c (license: MIT),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 pad[0x358];
    u8 field358;
    u8 pad359;
    u16 bits;
    u16 field35c;
    u8 entries[15][0x16];
    u8 pad4a8[8];
    u16 sent;
    u8 pad4b2;
    u8 kind;
    u8 version;
    u8 mode;
    u8 pad4b6[2];
    u32 value;
} Source;
typedef struct {
    u32 unk;
    Source *source;
    u8 *cursor;
    u8 state;
    u8 pad;
    u8 field_e;
    u8 index;
    u8 count;
    u8 serial;
} State;
typedef struct {
    u32 value;
    u8 flags : 2;
    u8 mode : 6;
    u8 kind;
    u8 field6;
    u8 serial;
    u16 checksum;
    u8 index;
    u8 padb;
    u16 fieldc;
    u16 fielde;
    u8 pad10[0x58];
    u8 tail[8];
} Packet;
extern State data_020c6090;
extern Packet data_020c60c0;
extern int data_020c6088;
extern void (*data_020c608c)(u32);
extern u8 data_020c60d0[];
extern u16 data_020c60c8[];
extern void func_020069a4(int, int, int);
extern void func_020069bc(int, int, int);
extern u16 func_02011c04(void *, int);
extern int func_0200f89c(int, void *, unsigned int, int, unsigned short, unsigned char);
extern void func_02011f2c(void);
void func_02011c88(int a, unsigned short b, unsigned char c) {
    int i;
    unsigned int count;
    u8 *dst;
    int offset;
    u32 changed;
    int mask;
    if (data_020c6090.field_e != data_020c6090.source->version) {
        func_02011f2c();
    }
    data_020c60c0.flags  = 2;
    data_020c60c0.kind   = data_020c6090.source->kind;
    data_020c60c0.field6 = data_020c6090.field_e;
    data_020c60c0.value  = data_020c6090.source->value;
    data_020c60c0.mode   = data_020c6090.source->mode;
    data_020c60c0.serial = data_020c6090.serial++;
    data_020c60c0.index  = data_020c6090.source->field358;
    data_020c60c0.fieldc = data_020c6090.source->bits;
    data_020c60c0.fielde = data_020c6090.source->field35c;
    if (data_020c6088 == 0 && data_020c608c) {
        data_020c608c(data_020c6090.source->value);
    }
    for (i = 0; i < 8; i++) {
        data_020c60c0.tail[i] = data_020c6090.source->pad4a8[i];
    }
    func_020069a4(0, (int) data_020c60d0, 0x58);
    count   = 0;
    dst     = data_020c60d0;
    changed = (u16) (data_020c6090.source->sent ^ data_020c6090.source->bits);
    for (i = 0, offset = 0; i < 15; i++, offset += 0x16) {
        mask = 2 << i;
        if (changed & mask) {
            func_020069bc((int) ((u8 *) data_020c6090.source->entries + offset), (int) dst, 0x16);
            dst += 0x16;
            count++;
            data_020c6090.source->sent |= mask;
            if (count == 4) {
                break;
            }
        }
    }
    if (count < 4) {
        data_020c60d0[count * 0x16] &= ~0xf0;
    }
    data_020c60c0.checksum = 0;
    data_020c60c0.checksum = func_02011c04(data_020c60c8, 0x68);
    if (data_020c6090.source->sent == data_020c6090.source->bits) {
        data_020c6090.state = 1;
    }
    func_0200f89c(0, &data_020c60c0, 0x70, a, b, c | 3);
    if (data_020c6088 == 1 && data_020c608c) {
        data_020c608c(data_020c6090.source->value);
    }
}
