/* compiler: 2.0/sp1p5  */
/* func_0211723c from projets/resident-evil-deadly-silence/src/auto/func_0211723c.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_020158f8(void) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #0x1
    cmphs r3, r1, lsl #0x1
    bhs L_0210e758
    bx lr
L_0210e758:
    orr r3, r0, r1
    movs r3, r3, lsl #0x1
    cmpeq r0, r0
    bxeq lr
    orrs r2, r0, r1
    bmi L_0210e778
    cmp r0, r1
    bx lr
L_0210e778:
    cmp r1, r0
    bx lr
}
// clang-format on
