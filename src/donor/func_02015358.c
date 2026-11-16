/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02001d2c from projets/children-of-mana/src/donor/func_02001d2c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_02015358(void *dest, const void *src, u32 count);
void *func_02015358(void *dest, const void *src, u32 count) {
    u8 *d       = dest;
    const u8 *s = src;

    while (count != 0) {
        *d++ = *s++;
        count--;
    }
    return dest;
}
