/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02017e64 from projets/code-lyoko/src/donor/func_02017e64.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;
typedef enum MbSegmentType {
    MB_SEG_ARM9STATIC = 0,
    MB_SEG_ARM7STATIC,
    MB_SEG_ROMHEADER
} MbSegmentType;
extern const MbSegmentType data_02080aa8[(3)];
extern BOOL func_02010f0c(u8 segment_no, u32 address, u32 size);
extern const MbSegmentType data_02080aa8[(3)];
extern BOOL func_02010df8(u8 segment_no, u32 address, u32 size);
extern BOOL func_02010f0c(u8 segment_no, u32 address, u32 size);
BOOL func_02010df8(u8 segment_no, u32 address, u32 size) {
    MbSegmentType seg_type;

    ((void) 0);

    seg_type = data_02080aa8[segment_no];

    switch (seg_type) {
        case MB_SEG_ROMHEADER:
        case MB_SEG_ARM9STATIC:
            return func_02010f0c(segment_no, address, size);
        case MB_SEG_ARM7STATIC:
            if (address >= (0x02000000) && address < (0x02000000 + 0x003fe800)) {
                u32 end_adr = address + size;

                if ((0x02000000 + 0x00300000) > address && (0x02000000 + 0x00300000) < end_adr) {
                    return 0;
                } else if (end_adr <= ((0x02000000 + 0x002c0000) + ((0x02000000 + 0x00300000) - (0x02000000 + 0x002c0000)))) {
                    return 1;
                } else if (end_adr < (0x02000000 + 0x003fe800) &&
                           size <= ((0x02000000 + 0x00300000) - (0x02000000 + 0x002c0000))) {
                    return 1;
                } else {
                    return 0;
                }
            } else if (address >= 0x037f8000 && address < 0x037f8000 + (0x18000 - 0x1000)) {
                u32 end_adr = address + size;
                if (end_adr <= (0x037f8000 + (0x18000 - 0x1000))) {
                    return 1;
                } else {
                    return 0;
                }
            }
            break;
        default:
            return 0;
    }

    return 0;
}
