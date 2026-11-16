/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Fs_File_DefaultOperation_OpenFileById from https://github.com/ai-tdd-labs/mkds-decomp ai/scratch/agent_02003234.c (license:
 * none (MIT = tooling only)), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct FsArchive {
    u8 pad_00[0x2c];
    void *fileAllocationTable;
    u32 fileCount;
} FsArchive;
typedef struct FsFile {
    u8 pad_00[8];
    FsArchive *archive;
    u8 pad_0c[0x24];
    u32 rangeStart;
    u32 fileId;
    u32 rangeFileId;
} FsFile;
typedef struct FsSyncReader {
    FsArchive *archive;
    void *position;
} FsSyncReader;
typedef struct FsFileRange {
    u32 start;
    u32 end;
} FsFileRange;
extern void func_02008d9c(FsSyncReader *reader, FsFileRange *range, u32 size);
extern int func_020082e8(FsFile *file, u32 operation);
int func_020084f8(FsFile *file) {
    FsFileRange range;
    FsSyncReader reader;
    u32 fileId = file->fileId;

    if ((fileId << 3) >= file->archive->fileCount) {
        return 1;
    }

    reader.archive  = file->archive;
    reader.position = (u8 *) reader.archive->fileAllocationTable + (fileId << 3);
    func_02008d9c(&reader, &range, 8);

    file->rangeStart  = range.start;
    file->fileId      = range.end;
    file->rangeFileId = fileId;
    return func_020082e8(file, 7);
}
