/* compiler: 2.0/sp1p5  */
/* func_02117914 from projets/resident-evil-deadly-silence/src/auto/func_02117914.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
// clang-format off
asm void func_02015fd0(void) {
    mov ip, #0x200000
    cmn ip, r1, lsl #0x1
    bhs L_0210ee38
    cmn ip, r3, lsl #0x1
    bhs L_0210ee54
L_0210ee30:
    mov r0, #0x1
    bx lr
L_0210ee38:
    movne r0, #0x0
    bxne lr
    cmp r0, #0x0
    movhi r0, #0x0
    bxhi lr
    cmn ip, r3, lsl #0x1
    blo L_0210ee30
L_0210ee54:
    movne r0, #0x0
    bxne lr
    cmp r2, #0x0
    movhi r0, #0x0
    bxhi lr
    b L_0210ee30
}
// clang-format on
