/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Fs_File_DefaultOperation_ReadDirectory from https://github.com/ai-tdd-labs/mkds-decomp ai/scratch/agent_0200388c.c (license:
 * none (MIT = tooling only)), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct FsArchive FsArchive;
typedef struct FsDirectoryPosition {
    FsArchive *archive;
    u16 ownId;
    u16 index;
    u32 position;
} FsDirectoryPosition;
typedef struct FsDirectoryEntry {
    FsArchive *archive;
    union {
        u32 fileId;
        struct {
            u16 ownId;
            u16 index;
        } directory;
    } id;
    u32 position;
    u32 isDirectory;
    u32 nameLength;
    char name[128];
} FsDirectoryEntry;
typedef struct FsFile {
    u8 pad_00[8];
    FsArchive *archive;
    u8 pad_0c[0x14];
    FsDirectoryPosition current;
    u32 parent;
    union {
        struct {
            FsDirectoryEntry *entry;
            u32 skipName;
        } readDirectory;
        u8 raw[0x18];
    } argument;
} FsFile;
typedef struct FsSyncReader {
    FsArchive *archive;
    void *position;
} FsSyncReader;
extern void func_02008d9c(FsSyncReader *reader, void *destination, u32 size);
int func_02008b50(FsFile *file) {
    FsDirectoryEntry *entry = file->argument.readDirectory.entry;
    FsSyncReader reader;

    reader.archive  = file->archive;
    reader.position = (void *) file->current.position;

    {
        u8 descriptor;

        func_02008d9c(&reader, &descriptor, sizeof(descriptor));
        entry->nameLength  = (u32) (descriptor & 0x7f);
        entry->isDirectory = (u32) ((descriptor >> 7) & 1);
    }

    if (entry->nameLength == 0) {
        return 1;
    }

    if (!file->argument.readDirectory.skipName) {
        func_02008d9c(&reader, entry->name, entry->nameLength);
        entry->name[entry->nameLength] = '\0';
    } else {
        reader.position = (u8 *) reader.position + entry->nameLength;
    }

    if (entry->isDirectory) {
        u16 id;

        func_02008d9c(&reader, &id, sizeof(id));
        entry->archive            = file->archive;
        entry->id.directory.ownId = (u16) (id & 0xfff);
        entry->id.directory.index = 0;
        entry->position           = 0;
    } else {
        entry->archive   = file->archive;
        entry->id.fileId = file->current.index;
        ++file->current.index;
    }

    file->current.position = (u32) reader.position;
    return 0;
}
