#include "m2c.h"

void *func_020197fc();                              /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK func_0201e490;
extern M2C_UNK func_020225ac;
extern M2C_UNK func_0202b910;
extern M2C_UNK func_0202b95c;
extern M2C_UNK func_0202b9b0;
extern M2C_UNK func_0202ba04;
extern M2C_UNK func_0202c890;
extern M2C_UNK func_0202eac0;
extern M2C_UNK func_0202eae0;
extern M2C_UNK func_0202eb00;
extern M2C_UNK func_0202eb14;
extern M2C_UNK func_0202eb28;
extern M2C_UNK func_0202eb34;

void func_0202f224(s32 arg0) {
    func_0202f564(&func_0202eb14, 0x50);
    func_0202f564(&func_0202ba04, 0x51);
    func_0202f564(&func_0202eae0, 0x52);
    func_0202f564(&func_0202eb00, 0x5A);
    func_0202f564(&func_0202b9b0, 0x5B);
    func_0202f564(&func_0202eac0, 0x5C);
    func_0202f564(&func_0202eb34, 0x60);
    func_0202f564(&func_0202b95c, 0x61);
    func_0202f564(&func_0202eb28, 0x62);
    func_0202f564(&func_0202b910, 0x70);
    func_0202f564(&func_0202c890, 0x70);
    if (arg0 == 0) {
        return;
    }
    if (M2C_FIELD(func_020197fc(), s16 *, 0x1A) != 1) {
        return;
    }
    func_0202f564(&func_020225ac, 0x40);
    func_0202f564(&func_0201e490, 0x40);
}
