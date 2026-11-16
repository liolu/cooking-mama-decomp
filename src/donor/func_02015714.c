/* compiler: 2.0/sp1p5  */
/* func_02117058 from projets/resident-evil-deadly-silence/src/auto/func_02117058.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015714(void) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #0x1
    movlo r0, #0x1
    bxlo lr
    cmp r3, r1, lsl #0x1
    movlo r0, #0x1
    bxlo lr
    orr r3, r0, r1
    movs r3, r3, lsl #0x1
    moveq r0, #0x0
    bxeq lr
    cmp r0, r1
    movne r0, #0x1
    moveq r0, #0x0
    bx lr
}
// clang-format on
