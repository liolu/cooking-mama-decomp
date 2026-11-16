/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020bcc3c from projets/eyeshield-21/src/donor/func_020bcc3c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long s32;
extern s32 func_02003e4c(s8 *buffer, s32 bufsz, const s8 *format, void *args);
typedef struct printfStr {
    s32 spaceLeft;
    s8 *stringEnd;
    s8 *stringStart;
} printfStr;
extern void func_02004824(struct printfStr *dest, s8 value);
extern void func_020047bc(struct printfStr *dest, s8 value, s32 count);
extern void func_0200475c(struct printfStr *dest, const s8 *src, s32 count);
extern void func_02004824(struct printfStr *dest, s8 value);
extern void func_020047bc(struct printfStr *dest, s8 value, s32 count);
extern void func_0200475c(struct printfStr *dest, const s8 *src, s32 count);
s32 func_02003e4c(s8 *buffer, s32 bufsz, const s8 *format, void *args) {
    s8 buf[24];
    s32 n_buf;
    s8 prefix[2];
    s32 n_prefix;

    const s8 *s = format;

    printfStr str;
    str.spaceLeft   = bufsz;
    str.stringStart = buffer;
    str.stringEnd   = buffer;

    while (*s) {

        if ((u32) (((u8) *s ^ 0x20) - 0xa1) < 0x3c) {
            func_02004824(&str, *s++);
            if (*s) {
                func_02004824(&str, *s++);
            }
        } else if (*s != '%') {
            func_02004824(&str, *s++);
        } else {
            enum {
                blank   = 000001,
                plus    = 000002,
                sharp   = 000004,
                minus   = 000010,
                zero    = 000020,
                l1      = 000040,
                h1      = 000100,
                l2      = 000200,
                h2      = 000400,
                usigned = 010000,
                end
            };
            s32 flag = 0, width = 0, precision = -1, radix = 10;
            s8 hex            = 'a' - 10;
            const s8 *p_start = s;
            for (;;) {
                switch (*++s) {
                    case '+':
                        if (s[-1] != ' ') {
                            break;
                        }
                        flag |= plus;
                        continue;
                    case ' ':
                        flag |= blank;
                        continue;
                    case '-':
                        flag |= minus;
                        continue;
                    case '0':
                        flag |= zero;
                        continue;
                }
                break;
            }
            if (*s == '*') {
                ++s, width = *(s32 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                if (width < 0) {
                    width = -width, flag |= minus;
                }
            } else {
                while ((*s >= '0') && (*s <= '9')) {
                    width = (width * 10) + *s++ - '0';
                }
            }

            if (*s == '.') {
                ++s, precision = 0;
                if (*s == '*') {
                    ++s, precision = *(s32 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                    if (precision < 0) {
                        precision = -1;
                    }
                } else {
                    while ((*s >= '0') && (*s <= '9')) {
                        precision = (precision * 10) + *s++ - '0';
                    }
                }
            }

            switch (*s) {
                case 'h':
                    if (*++s != 'h') {
                        flag |= h1;
                    } else {
                        ++s, flag |= h2;
                    }
                    break;
                case 'l':
                    if (*++s != 'l') {
                        flag |= l1;
                    } else {
                        ++s, flag |= l2;
                    }
                    break;
            }

            switch (*s) {
                case 'd':
                case 'i':
                    goto put_int;
                case 'o':
                    radix = 8;
                    flag |= usigned;
                    goto put_int;
                case 'u':
                    flag |= usigned;
                    goto put_int;
                case 'X':
                    hex = 'A' - 10;
                    goto put_hex;
                case 'x':
                    goto put_hex;
                case 'p':
                    flag |= sharp;
                    precision = 8;
                    goto put_hex;
                case 'c':
                    if (precision >= 0) {
                        goto put_invalid;
                    }
                    {
                        s32 v = *(s32 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        width -= 1;
                        if (flag & minus) {
                            func_02004824(&str, (s8) v);
                            func_020047bc(&str, ' ', width);
                        } else {
                            s8 pad = (s8) ((flag & zero) ? '0' : ' ');
                            func_020047bc(&str, pad, width);
                            func_02004824(&str, (s8) v);
                        }
                        ++s;
                    }
                    break;
                case 's': {
                    s32 n_bufs       = 0;
                    const s8 *p_bufs = *(const s8 **) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                    if (precision < 0) {
                        while (p_bufs[n_bufs]) {
                            ++n_bufs;
                        }
                    } else {
                        while (n_bufs < precision && p_bufs[n_bufs]) {
                            ++n_bufs;
                        }
                    }
                    width -= n_bufs;
                    if (flag & minus) {
                        func_0200475c(&str, p_bufs, n_bufs);
                        func_020047bc(&str, ' ', width);
                    } else {
                        s8 pad = (s8) ((flag & zero) ? '0' : ' ');
                        func_020047bc(&str, pad, width);
                        func_0200475c(&str, p_bufs, n_bufs);
                    }
                    ++s;
                } break;
                case 'n': {
                    s32 count = str.stringEnd - str.stringStart;
                    if (!(flag & h2)) {
                        if (flag & h1) {
                            **(s16 **) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1) = (s16) count;
                        } else if (flag & l2) {
                            **(u64 **) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1) = (u64) count;
                        } else {
                            **(s32 **) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1) = count;
                        }
                    }
                }
                    ++s;
                    break;
                case '%':
                    if (p_start + 1 != s) {
                        goto put_invalid;
                    }
                    func_02004824(&str, *s++);
                    break;

                default:
                    goto put_invalid;

                put_invalid:
                    func_0200475c(&str, p_start, s - p_start);
                    break;

                put_hex:
                    radix = 16;
                    flag |= usigned;
                put_int: {
                    u64 value = 0;
                    n_prefix  = 0;
                    if (flag & minus) {
                        flag &= ~zero;
                    }
                    if (precision < 0) {
                        precision = 1;
                    } else {
                        flag &= ~zero;
                    }
                    if (flag & usigned) {
                        if (flag & h2) {
                            value = *(u8 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        } else if (flag & h1) {
                            value = *(u16 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        } else if (flag & l2) {
                            value = *((u64 *) (args = (void *) ((u64 *) (args) + 1)) - 1);
                        } else {
                            value = *(u32 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        }
                        flag &= ~(plus | blank);
                        if (flag & sharp) {
                            if (radix == 16) {
                                if (value != 0) {
                                    prefix[0] = (s8) (hex + (10 + 'x' - 'a'));
                                    prefix[1] = '0';
                                    n_prefix  = 2;
                                }
                            } else if (radix == 8) {
                                prefix[0] = '0';
                                n_prefix  = 1;
                            }
                        }
                    } else {
                        if (flag & h2) {
                            value = *(s8 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        } else if (flag & h1) {
                            value = *(s16 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        } else if (flag & l2) {
                            value = *((u64 *) (args = (void *) ((u64 *) (args) + 1)) - 1);
                        } else {
                            value = *(s32 *) ((u32 *) (args = (void *) ((u32 *) (args) + 1)) - 1);
                        }

                        if ((value >> 32) & 0x80000000) {
                            value     = ~value + 1;
                            prefix[0] = '-';
                            n_prefix  = 1;
                        } else {
                            if (value || precision) {
                                if (flag & plus) {
                                    prefix[0] = '+';
                                    n_prefix  = 1;
                                } else if (flag & blank) {
                                    prefix[0] = ' ';
                                    n_prefix  = 1;
                                }
                            }
                        }
                    }
                    n_buf = 0;
                    switch (radix) {
                        case 8:
                            while (value != 0) {
                                s32 octDig = (s32) (value & 0x7);
                                value >>= 3;
                                buf[n_buf++] = (s8) (octDig + '0');
                            }
                            break;
                        case 10:
                            if ((value >> 32) == 0) {
                                u32 v = (u32) value;
                                while (v) {
                                    u32 div10    = v / 10;
                                    s32 dig      = (s32) (v - (div10 * 10));
                                    v            = div10;
                                    buf[n_buf++] = (s8) (dig + '0');
                                }
                            } else {
                                while (value) {
                                    u64 div10    = value / 10;
                                    s32 dig      = (s32) (value - (div10 * 10));
                                    value        = div10;
                                    buf[n_buf++] = (s8) (dig + '0');
                                }
                            }
                            break;
                        case 16:
                            while (value != 0) {
                                s32 hexDig = (s32) (value & 0xf);
                                value >>= 4;
                                buf[n_buf++] = (s8) ((hexDig < 10) ? (hexDig + '0') : (hexDig + hex));
                            }
                            break;
                    }
                    if (n_prefix > 0 && prefix[0] == '0') {
                        n_prefix     = 0;
                        buf[n_buf++] = '0';
                    }
                }
                    goto put_to_stream;

                put_to_stream: {
                    s32 n_pad = (s32) (precision - n_buf);
                    if (flag & zero) {
                        if (n_pad < width - n_buf - n_prefix) {
                            n_pad = (s32) (width - n_buf - n_prefix);
                        }
                    }
                    if (n_pad > 0) {
                        width -= n_pad;
                    }

                    width -= n_prefix + n_buf;
                    if (!(flag & minus)) {
                        func_020047bc(&str, ' ', width);
                    }
                    while (n_prefix > 0) {
                        func_02004824(&str, prefix[--n_prefix]);
                    }
                    func_020047bc(&str, '0', n_pad);
                    while (n_buf > 0) {
                        func_02004824(&str, buf[--n_buf]);
                    }
                    if (flag & minus) {
                        func_020047bc(&str, ' ', width);
                    }
                    ++s;
                } break;
            }
        }
    }

    if (str.spaceLeft != 0) {
        *str.stringEnd = '\0';
    } else if (bufsz != 0) {
        str.stringStart[bufsz - 1] = '\0';
    }
    return str.stringEnd - str.stringStart;
}
