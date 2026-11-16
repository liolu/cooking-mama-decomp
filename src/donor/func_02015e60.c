/* compiler: 2.0/sp1p5  */
/* func_021177a4 from projets/resident-evil-deadly-silence/src/auto/func_021177a4.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015e60(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_0210ed00
    cmn ip, r3, lsl #0x1
    bhs L_0210ed1c
L_0210ecc0:
    orrs ip, r3, r1
    bmi L_0210ecdc
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #0x1
    movlo r0, #0x0
    bx lr
L_0210ecdc:
    orr ip, r0, ip, lsl #0x1
    orrs ip, ip, r2
    moveq r0, #0x1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #0x1
    movlo r0, #0x0
    bx lr
L_0210ed00:
    movne r0, #0x0
    bxne lr
    cmp r0, #0x0
    movhi r0, #0x0
    bxhi lr
    cmn ip, r3, lsl #0x1
    blo L_0210ecc0
L_0210ed1c:
    movne r0, #0x0
    bxne lr
    cmp r2, #0x0
    movhi r0, #0x0
    bxhi lr
    b L_0210ecc0
}
// clang-format on
