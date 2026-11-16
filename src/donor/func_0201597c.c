/* compiler: 2.0/sp1p5  */
/* func_021172c0 from projets/resident-evil-deadly-silence/src/auto/func_021172c0.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_0201597c(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_0210e824
    cmn ip, r3, lsl #0x1
    bhs L_0210e840
L_0210e7dc:
    orrs ip, r3, r1
    bmi L_0210e7fc
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0x0
    movlo r0, #0x1
    movhi r0, #0x2
    bx lr
L_0210e7fc:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0x0
    movlo r0, #0x1
    movhi r0, #0x2
    bx lr
L_0210e824:
    movne r0, #0x3
    bxne lr
    cmp r0, #0x0
    movhi r0, #0x3
    bxhi lr
    cmn ip, r3, lsl #0x1
    blo L_0210e7dc
L_0210e840:
    movne r0, #0x3
    bxne lr
    cmp r2, #0x0
    movhi r0, #0x3
    bxhi lr
    b L_0210e7dc
}
// clang-format on
