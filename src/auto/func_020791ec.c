/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02079674(M2C_UNK);
M2C_UNK func_0207a644(void);
void func_0207a654(M2C_UNK);
void func_0207a664(void);
void func_0207a678(M2C_UNK);

extern void *data_0211654c;

void func_020791ec(s32 arg0) {
    s32 temp_r4;

    if (M2C_FIELD(data_0211654c, s32 *, 0x80) != 0) {
        temp_r4 = func_0207a644();
        func_0207a678(1);
        func_0207a654(M2C_FIELD(data_0211654c, s32 *, 0x80));
        func_02079674(arg0);
        func_0207a678(0);
        func_0207a654(temp_r4);
        func_0207a664();
        return;
    }
    func_02079674(arg0);
}
