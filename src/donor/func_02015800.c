/* compiler: 2.0/sp1p5  */
/* func_02117144 from projets/resident-evil-deadly-silence/src/auto/func_02117144.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015800(void) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #0x1
    cmphs r3, r1, lsl #0x1
    movlo r0, #0x0
    bxlo lr
    cmp r0, #0x0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0x0
    cmp r1, #0x0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0x0
    cmp r0, r1
    movle r0, #0x1
    movgt r0, #0x0
    bx lr
}
// clang-format on
