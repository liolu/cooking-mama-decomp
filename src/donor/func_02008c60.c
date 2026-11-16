/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Fs_File_DefaultOperation_SeekDirectory from https://github.com/ai-tdd-labs/mkds-decomp ai/scratch/agent_0200399c.c (license:
 * none (MIT = tooling only)), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct FsArchive {
    u8 pad_00[0x34];
    void *fnt;
} FsArchive;
typedef struct FsDirPos {
    u32 pos;
    u16 index;
    u16 f6;
    u32 f8;
} FsDirPos;
typedef struct FsFile {
    u8 pad_00[8];
    FsArchive *archive;
    u8 pad_0c[0x14];
    FsDirPos current;
    u32 parent;
    FsDirPos pos;
} FsFile;
typedef struct FsDirEntry {
    u32 start;
    u16 id;
    u16 top;
} FsDirEntry;
typedef struct FsSyncReader {
    FsArchive *archive;
    void *position;
} FsSyncReader;
extern void func_02008d9c(FsSyncReader *reader, FsDirEntry *entry, u32 size);
int func_02008c60(FsFile *file) {
    FsDirEntry entry;
    FsSyncReader reader;
    FsArchive *arch = file->archive;
    FsDirPos *pos   = &file->pos;

    reader.archive  = arch;
    reader.position = (u8 *) arch->fnt + (pos->index << 3);
    func_02008d9c(&reader, &entry, 8);

    file->current = *pos;

    if (pos->f6 == 0 && pos->f8 == 0) {
        file->current.f6 = entry.id;
        file->current.f8 = (u32) arch->fnt + entry.start;
    }
    file->parent = entry.top & 0xfff;
    return 0;
}
