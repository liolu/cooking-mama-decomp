/* compiler: 2.0/sp1p5  */
/* func_021178c4 from projets/resident-evil-deadly-silence/src/auto/func_021178c4.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015f80(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_0210ede8
    cmn ip, r3, lsl #0x1
    bhs L_0210ee04
L_0210ede0:
    mov r0, #0x0
    bx lr
L_0210ede8:
    movne r0, #0x1
    bxne lr
    cmp r0, #0x0
    movhi r0, #0x1
    bxhi lr
    cmn ip, r3, lsl #0x1
    blo L_0210ede0
L_0210ee04:
    movne r0, #0x1
    bxne lr
    cmp r2, #0x0
    movhi r0, #0x1
    bxhi lr
    b L_0210ede0
}
// clang-format on
