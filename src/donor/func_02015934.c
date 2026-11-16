/* compiler: 2.0/sp1p5  */
/* func_02117278 from projets/resident-evil-deadly-silence/src/auto/func_02117278.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015934(void) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #0x1
    movlo r0, #0x1
    bxlo lr
    cmp r3, r1, lsl #0x1
    movlo r0, #0x1
    bxlo lr
    mov r0, #0x0
    bx lr
}
// clang-format on
