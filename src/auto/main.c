/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02006204();                            /* extern */
M2C_UNK func_0200b468(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_02018f1c();                            /* extern */
M2C_UNK func_0202eb84();                            /* extern */
M2C_UNK func_0202f07c();                            /* extern */
s32 func_0202f0c4();                                /* extern */
M2C_UNK func_0202f430();                            /* extern */
M2C_UNK func_0202f564(M2C_UNK *, s32);              /* extern */
M2C_UNK func_0202f74c(M2C_UNK *, M2C_UNK *);        /* extern */
s32 func_0202f770();                                /* extern */
M2C_UNK func_0202f8b4();                            /* extern */
M2C_UNK func_0203048c();                            /* extern */
extern M2C_UNK data_0210aca0;
extern M2C_UNK data_0210adb0;
extern M2C_UNK func_02018dc0;
extern M2C_UNK func_02027d70;

void main(void) {
    func_0202f07c();
    func_0202f8b4();
    if (func_0202f0c4() != 0) {
        func_0202f564(&func_02018dc0, 0xFF02);
    } else {
        if (func_0202f770() == 0) {
            func_02018f1c();
        }
        func_0202f74c(&data_0210adb0, &data_0210aca0);
        func_0202f564(&func_02027d70, 0xFF02);
    }
loop_5:
    if (((s32) (*(u16 *) 0x027FFFA8 & 0x8000) >> 0xF) == 1) {
        func_0203048c();
        func_0200b468(0xC, 0, 0);
        goto loop_5;
    }
    func_0202eb84();
    func_0202f430();
    *(s32 *) 0x04000540 = 1;
    func_02006204();
    goto loop_5;
}
