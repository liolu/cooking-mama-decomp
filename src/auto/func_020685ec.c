#include "m2c.h"

M2C_UNK func_02019b4c(M2C_UNK *);                   /* extern */
M2C_UNK **func_0202f368();                          /* extern */
M2C_UNK func_0202f564(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02034394(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_02038394(s32);                         /* extern */
M2C_UNK func_02068368();                            /* extern */
M2C_UNK func_0206df1c(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02112ef8;
extern M2C_UNK data_02112f60;
extern M2C_UNK data_02113030;
extern M2C_UNK data_02113098;
extern M2C_UNK func_02038288;
extern M2C_UNK func_020682a8;

void func_020685ec(void) {
    M2C_UNK **temp_r4;

    temp_r4 = func_0202f368();
    func_02019b4c(&data_02113030);
    func_02034394(&data_02112ef8, &data_02113098);
    func_0202f564(&func_02038288, 0x15);
    func_02038394(0x708);
    func_0206df1c(&data_02112f60);
    func_02068368();
    *temp_r4 = &func_020682a8;
}
