/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200438c from projets/children-of-mana/src/donor/func_0200438c.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
#pragma cplusplus off
#pragma cplusplus off
char *func_02015498(char *destination, const char *source) {
    unsigned char *output      = (unsigned char *) destination;
    const unsigned char *input = (const unsigned char *) source;

    while (*output++ != 0) {
    }
    output--;
    while ((*output++ = *input++) != 0) {
    }
    return destination;
}
