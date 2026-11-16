/* compiler: 1.2/sp2p3  */
/* func_02075e90 from projets/children-of-mana/src/auto/func_02075e90.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef signed char s8;
typedef unsigned char u8;
typedef long s32;
typedef s32 M2C_UNK;
extern u8 *func_0207411c();
extern void func_02074100(s32, u8 *);
extern u8 *func_0207494c(s32, s32, M2C_UNK *, s32, s32);
extern void func_02005834(u8 *, s32);
extern void func_02006ae4(u8 *, u8 *, s32);
extern void func_02006a50(u8 *, s32, s32);
extern s32 func_02074144(s32, void *, s32, s32);
extern s32 func_02074448();
extern M2C_UNK func_02074d4c;
extern M2C_UNK data_02114a6c;
u8 *func_02074e88(s32 arg0, s32 arg1, s32 arg2) {
    u8 *var_r6;
    s32 temp_r5;
    s32 temp_r4;
    s32 var_r3;
    s32 rd;
    u8 *temp_r0;
    var_r6 = func_0207411c();
    if (var_r6 == ((void *) 0)) {
        if (func_02074144(arg0, &data_02114a6c, 0x3C, 0) != 0x3C) {
            return ((void *) 0);
        }
        temp_r4 = (*(s32 *) ((s8 *) (&data_02114a6c) + (0x38))) * 4;
        temp_r5 = (temp_r4 * 2) + 0x3C;
        if (arg1 == 0) {
            return ((void *) 0);
        }
        if (arg2 == 0) {
            var_r3 = 0;
        } else {
            var_r3 = func_02074448();
        }
        var_r6 = func_0207494c(arg1, temp_r5 + 0x20, &func_02074d4c, var_r3, arg0);
        if (var_r6 == ((void *) 0)) {
            return ((void *) 0);
        }
        rd = func_02074144(arg0, var_r6, temp_r4 + 0x3C, 0);
        if (rd != temp_r4 + 0x3C) {
            return ((void *) 0);
        }
        temp_r0 = var_r6 + 0x3C;
        func_02006ae4(temp_r0, temp_r0 + ((*(s32 *) ((s8 *) (var_r6) + (0x38))) * 4), temp_r4);
        func_02006a50(var_r6 + 0x3C, 0, temp_r4);
        func_02005834(var_r6, temp_r5);
        if (arg2 != 0) {
            func_02074100(arg0, var_r6);
        }
    }
    return var_r6;
}
