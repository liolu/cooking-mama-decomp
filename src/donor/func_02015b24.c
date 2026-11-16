/* compiler: 2.0/sp1p5  */
/* _deq from projets/resident-evil-deadly-silence/src/auto/_deq.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_02015b24(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_0210e9c4
    cmn ip, r3, lsl #0x1
    bhs L_0210e9e0
L_0210e984:
    orrs ip, r3, r1
    bmi L_0210e9a0
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0x1
    movne r0, #0x0
    bx lr
L_0210e9a0:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0x1
    movne r0, #0x0
    bx lr
L_0210e9c4:
    movne r0, #0x0
    bxne lr
    cmp r0, #0x0
    movhi r0, #0x0
    bxhi lr
    cmn ip, r3, lsl #0x1
    blo L_0210e984
L_0210e9e0:
    movne r0, #0x0
    bxne lr
    cmp r2, #0x0
    movhi r0, #0x0
    bxhi lr
    b L_0210e984
}
// clang-format on
