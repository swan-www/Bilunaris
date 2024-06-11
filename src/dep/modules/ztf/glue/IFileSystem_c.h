#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "ztf_bind_common.h"

#include "Config_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum ztf_ResourceMount
{
    /// Installed game directory / bundle resource directory
    ZTF_RM_CONTENT = 0,
    /// For storing debug data such as log files. To be used only during development
    ZTF_RM_DEBUG,
    /// Documents directory
    ZTF_RM_DOCUMENTS,
#if defined(ANDROID)
    // System level files (/proc/ or equivalent if available)
    ZTF_RM_SYSTEM,
#endif
    /// Save game data mount 0
    ZTF_RM_SAVE_0,
#ifdef ENABLE_FS_EMPTY_MOUNT
    /// Empty mount for absolute paths
    ZTF_RM_EMPTY,
#endif
    ZTF_RM_COUNT,
} ztf_ResourceMount;

typedef enum ztf_ResourceDirectory
{
    /// The main application's shader binaries directory
    ZTF_RD_SHADER_BINARIES = 0,

    ZTF_RD_PIPELINE_CACHE,
    /// The main application's texture source directory (TODO processed texture folder)
    ZTF_RD_TEXTURES,
    ZTF_RD_COMPILED_MATERIALS,
    ZTF_RD_MESHES,
    ZTF_RD_FONTS,
    ZTF_RD_ANIMATIONS,
    ZTF_RD_AUDIO,
    ZTF_RD_GPU_CONFIG,
    ZTF_RD_LOG,
    ZTF_RD_SCRIPTS,
    ZTF_RD_SCREENSHOTS,
    ZTF_RD_DEBUG,
#if defined(ANDROID)
    // #TODO: Add for others if necessary
    ZTF_RD_SYSTEM,
#endif
    ZTF_RD_OTHER_FILES,

    // Libraries can have their own directories.
    // Up to 100 libraries are supported.
    ZTF_____rd_lib_counter_begin = ZTF_RD_OTHER_FILES + 1,

    // Add libraries here
    ZTF_RD_MIDDLEWARE_0 = ZTF_____rd_lib_counter_begin,
    ZTF_RD_MIDDLEWARE_1,
    ZTF_RD_MIDDLEWARE_2,
    ZTF_RD_MIDDLEWARE_3,
    ZTF_RD_MIDDLEWARE_4,
    ZTF_RD_MIDDLEWARE_5,
    ZTF_RD_MIDDLEWARE_6,
    ZTF_RD_MIDDLEWARE_7,
    ZTF_RD_MIDDLEWARE_8,
    ZTF_RD_MIDDLEWARE_9,
    ZTF_RD_MIDDLEWARE_10,
    ZTF_RD_MIDDLEWARE_11,
    ZTF_RD_MIDDLEWARE_12,
    ZTF_RD_MIDDLEWARE_13,
    ZTF_RD_MIDDLEWARE_14,
    ZTF_RD_MIDDLEWARE_15,

    ZTF_____rd_lib_counter_end = ZTF_____rd_lib_counter_begin + 99 * 2,
    ZTF_RD_COUNT
} ztf_ResourceDirectory;

typedef enum ztf_SeekBaseOffset
{
    ZTF_SBO_START_OF_FILE = 0,
    ZTF_SBO_CURRENT_POSITION,
    ZTF_SBO_END_OF_FILE,
} ztf_SeekBaseOffset;

typedef enum ztf_FileMode
{
    // Get read access for file. Error if file not exist.
    ZTF_FM_READ = 1 << 0,

    // Get write access for file. File is created if not exist.
    ZTF_FM_WRITE = 1 << 1,

    // Set initial seek position to the end of file.
    ZTF_FM_APPEND = 1 << 2,

    // Read access for other processes.
    // Note: flag is required for Windows&Xbox.
    //       On other platforms read access is always available.
    ZTF_FM_ALLOW_READ = 1 << 4,

    // RW mode
    ZTF_FM_READ_WRITE = ZTF_FM_READ | ZTF_FM_WRITE,

    // W mode and set position to the end
    ZTF_FM_WRITE_APPEND = ZTF_FM_WRITE | ZTF_FM_APPEND,

    // R mode and set position to the end
    ZTF_FM_READ_APPEND = ZTF_FM_READ | ZTF_FM_APPEND,

    // RW mode and set position to the end
    ZTF_FM_READ_WRITE_APPEND = ZTF_FM_READ | ZTF_FM_APPEND,

    // -- mode and -- and also read access for other processes.
    ZTF_FM_WRITE_ALLOW_READ = ZTF_FM_WRITE | ZTF_FM_ALLOW_READ,
    ZTF_FM_READ_WRITE_ALLOW_READ = ZTF_FM_READ_WRITE | ZTF_FM_ALLOW_READ,
    ZTF_FM_WRITE_APPEND_ALLOW_READ = ZTF_FM_WRITE_APPEND | ZTF_FM_ALLOW_READ,
    ZTF_FM_READ_WRITE_APPEND_ALLOW_READ = ZTF_FM_READ_WRITE_APPEND | ZTF_FM_ALLOW_READ,
} ztf_FileMode;

typedef struct ztf_IFileSystem ztf_IFileSystem;

typedef struct ztf_FileStreamUserData
{
    uintptr_t data[6];
}ztf_FileStreamUserData;

/// After stream is opened, only FileStream::pIO must be used for this stream.
/// Example:
///   io->Open(&stream); // stream is opened
///   io->Read(&stream, ...); // bug, potentially uses wrong io on wrong stream.
///   stream.pIO->Read(&stream, ...); // correct
/// The reason for this is that IFileSystem::Open can open stream using another
/// IFileSystem handle.
///
/// It is best to use IFileSystem IO shortcuts "fsReadFromStream(&stream,...)"
typedef struct ztf_FileStream
{
    ztf_IFileSystem* pIO;
    ztf_FileMode                mMode;
    ztf_ResourceMount           mMount;
    struct ztf_FileStreamUserData mUser; // access to this field is IO exclusive
} ztf_FileStream;

typedef struct ztf_FileSystemInitDesc
{
    const char* pAppName;
    void* pPlatformData;
    const char* pResourceMounts[ZTF_RM_COUNT];
} ztf_FileSystemInitDesc;

struct ztf_IFileSystem
{
    bool (*Open)(ztf_IFileSystem* pIO, const ztf_ResourceDirectory resourceDir, const char* fileName, ztf_FileMode mode, ztf_FileStream* pOut);

    /// Closes and invalidates the file stream.
    bool (*Close)(ztf_FileStream* pFile);

    /// Returns the number of bytes read.
    size_t(*Read)(ztf_FileStream* pFile, void* outputBuffer, size_t bufferSizeInBytes);

    /// Reads at most `bufferSizeInBytes` bytes from sourceBuffer and writes them into the file.
    /// Returns the number of bytes written.
    size_t(*Write)(ztf_FileStream* pFile, const void* sourceBuffer, size_t byteCount);

    /// Seeks to the specified position in the file, using `baseOffset` as the reference offset.
    bool (*Seek)(ztf_FileStream* pFile, ztf_SeekBaseOffset baseOffset, ssize_t seekOffset);

    /// Gets the current seek position in the file.
    ssize_t(*GetSeekPosition)(ztf_FileStream* pFile);

    /// Gets the current size of the file. Returns -1 if the size is unknown or unavailable.
    ssize_t(*GetFileSize)(ztf_FileStream* pFile);

    /// Flushes all writes to the file stream to the underlying subsystem.
    bool (*Flush)(ztf_FileStream* pFile);

    /// Returns whether the current seek position is at the end of the file stream.
    bool (*IsAtEnd)(ztf_FileStream* pFile);

    const char* (*GetResourceMount)(ztf_ResourceMount mount);

    // Acquire unique file identifier.
    // Only Archive FS supports it currently.
    bool (*GetFileUid)(ztf_IFileSystem* pIO, ztf_ResourceDirectory rd, const char* name, uint64_t* outUid);

    // Open file using unique identifier. Use GetFileUid to get uid.
    bool (*OpenByUid)(ztf_IFileSystem* pIO, uint64_t uid, ztf_FileMode fm, ztf_FileStream* pOut);

    // Creates virtual address space of file.
    // When memory mapping is done, file can be accessed just like an array.
    // This is more efficient than using "FILE" stream.
    // Not all platforms are supported.
    // Use fsStreamWrapMemoryMap for strong cross-platform compatibility.
    // This function does read-only memory map.
    bool (*MemoryMap)(ztf_FileStream* fs, size_t* outSize, void const** outData);

    void* pUser;
};

/// Default file system using C File IO or Bundled File IO (Android) based on the ResourceDirectory
ZTF_C_API ztf_IFileSystem* ztf_getSystemFileIO();
/************************************************************************/
// MARK: - Initialization
/************************************************************************/
/// Initializes the FileSystem API
ZTF_C_API bool ztf_initFileSystem(ztf_FileSystemInitDesc* pDesc);

/// Frees resources associated with the FileSystem API
ZTF_C_API void ztf_exitFileSystem(void);

/// 'desc' can be NULL
ZTF_C_API bool ztf_fsArchiveOpen(ztf_ResourceDirectory rd, const char* fileName, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out);

/// This function is useful to use arbitrary stream source as an archive stream.
/// Only (*Seek) and (*Read) functions are required.
///
/// 'desc' can be NULL
/// 'stream' is owned by user, must be valid until fsArchiveClose
///          do not use stream while archive is opened
ZTF_C_API bool ztf_fsArchiveOpenFromStream(ztf_FileStream* stream, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out);

/// Archive can be opened on "read from memory" mode.
/// Benifits:
/// - no need for ArchiveOpenDesc::protectStreamCriticalSection
/// - no filesystem overhead
/// - less buffering during decompression
///
/// Recommended for mmap-ed memory.
///
/// 'desc' can be NULL
/// 'm' is owned by user, must be valid until fsArchiveClose
ZTF_C_API bool ztf_fsArchiveOpenFromMemory(uint64_t msize, const void* m, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out);

ZTF_C_API bool ztf_fsArchiveClose(ztf_IFileSystem* pArchive);

/************************************************************************/
// MARK: - File IO
/************************************************************************/

/// Opens the file at `filePath` using the mode `mode`, returning a new FileStream that can be used
/// to read from or modify the file. May return NULL if the file could not be opened.
ZTF_C_API bool ztf_fsOpenStreamFromPath(ztf_ResourceDirectory resourceDir, const char* fileName, ztf_FileMode mode, ztf_FileStream* pOut);

/// Opens a memory buffer as a FileStream, returning a stream that must be closed with `fsCloseStream`.
/// Use 'fsStreamMemoryMap' to do the opposite.
ZTF_C_API bool ztf_fsOpenStreamFromMemory(const void* buffer, size_t bufferSize, ztf_FileMode mode, bool owner, ztf_FileStream* pOut);

ZTF_C_API bool ztf_fsFindStream(ztf_FileStream* fs, const void* pFind, size_t findSize, ssize_t maxSeek, ssize_t* pPosition);
ZTF_C_API bool ztf_fsFindReverseStream(ztf_FileStream* fs, const void* pFind, size_t findSize, ssize_t maxSeek, ssize_t* pPosition);

/// Checks if stream is a standard system stream
ZTF_C_API bool ztf_fsIsSystemFileStream(ztf_FileStream* fs);
/// Checks if stream is a memory stream
ZTF_C_API bool ztf_fsIsMemoryStream(ztf_FileStream* fs);

/// symbolsCount can be SIZE_MAX, then reads until the end of file
/// appends '\0' to the end of string
ZTF_C_API size_t ztf_fsReadBstringFromStream(ztf_FileStream* stream, struct bstring* pStr, size_t symbolsCount);

/// Wraps stream into new memory stream using fsStreamMemoryMap
/// returns true: old stream is wrapped by new one with new IO.
/// returns false: stream is unaffected.
/// In both cases stream stays in valid state.
/// fsCloseStream(FileStream*) takes care of cleaning wrapped stream.
/// So checking return value is optional.
ZTF_C_API bool ztf_fsStreamWrapMemoryMap(ztf_FileStream* fs);

ZTF_C_API bool ztf_fsIoOpenStreamFromPath(ztf_IFileSystem* pIO, const ztf_ResourceDirectory rd, const char* fileName, ztf_FileMode mode,
                                              ztf_FileStream* pOut);

/// Closes and invalidates the file stream.
ZTF_C_API bool ztf_fsCloseStream(ztf_FileStream* fs);

/// Returns the number of bytes read.
ZTF_C_API size_t ztf_fsReadFromStream(ztf_FileStream* fs, void* pOutputBuffer, size_t bufferSizeInBytes);

/// Reads at most `bufferSizeInBytes` bytes from sourceBuffer and writes them into the file.
/// Returns the number of bytes written.
ZTF_C_API size_t ztf_fsWriteToStream(ztf_FileStream* fs, const void* pSourceBuffer, size_t byteCount);

/// Seeks to the specified position in the file, using `baseOffset` as the reference offset.
ZTF_C_API bool ztf_fsSeekStream(ztf_FileStream* fs, ztf_SeekBaseOffset baseOffset, ssize_t seekOffset);

/// Gets the current seek position in the file.
ZTF_C_API ssize_t ztf_fsGetStreamSeekPosition(ztf_FileStream* fs);

/// Gets the current size of the file. Returns -1 if the size is unknown or unavailable.
ZTF_C_API ssize_t ztf_fsGetStreamFileSize(ztf_FileStream* fs);

/// Flushes all writes to the file stream to the underlying subsystem.
ZTF_C_API bool ztf_fsFlushStream(ztf_FileStream* fs);

/// Returns whether the current seek position is at the end of the file stream.
ZTF_C_API bool ztf_fsStreamAtEnd(ztf_FileStream* fs);
ZTF_C_API const char* ztf_fsIoGetResourceMount(ztf_IFileSystem* pIO, ztf_ResourceMount mount);
ZTF_C_API bool ztf_fsIoGetFileUid(ztf_IFileSystem* pIO, ztf_ResourceDirectory rd, const char* fileName, uint64_t* outUid);
ZTF_C_API bool ztf_fsIoOpenByUid(ztf_IFileSystem* pIO, uint64_t index, ztf_FileMode mode, ztf_FileStream* pOutStream);
ZTF_C_API bool ztf_fsStreamMemoryMap(ztf_FileStream* fs, size_t* outSize, void const** outData);

/************************************************************************/
    // MARK: - Directory queries
    /************************************************************************/
    /// Returns location set for resource directory in fsSetPathForResourceDir.
ZTF_C_API const char* ztf_fsGetResourceDirectory(ztf_ResourceDirectory resourceDir);
/// Returns Resource Mount point for resource directory
ZTF_C_API ztf_ResourceMount ztf_fsGetResourceDirectoryMount(ztf_ResourceDirectory resourceDir);

/// Sets the relative path for `resourceDir` from `mount` to `bundledFolder`.
/// The `resourceDir` will making use of the given IFileSystem `pIO` file functions.
/// When `mount` is set to `RM_CONTENT` for a `resourceDir`, this directory is marked as a bundled resource folder.
/// Bundled resource folders should only be used for Read operations.
/// NOTE: A `resourceDir` can only be set once.
ZTF_C_API void ztf_fsSetPathForResourceDir(ztf_IFileSystem* pIO, ztf_ResourceMount mount, ztf_ResourceDirectory resourceDir, const char* bundledFolder);

/************************************************************************/
// MARK: - File Queries
/************************************************************************/

/// Gets the time of last modification for the file at `fileName`, within 'resourceDir'.
ZTF_C_API time_t ztf_fsGetLastModifiedTime(ztf_ResourceDirectory resourceDir, const char* fileName);

/************************************************************************/
// MARK: - Platform-dependent function definitions
/************************************************************************/

ZTF_C_API bool ztf_fsCreateResourceDirectory(ztf_ResourceDirectory resourceDir);

/************************************************************************/
   // MARK: - Buny Archive format definitions
   /************************************************************************/

   // Buny Archive File structure description:
   // First bytes are BunyArHeader with magic values and metadata location pointers
   // Metadata consist of following units:
   //    archive nodes (file entries)
   //    block of utf8 strings, referenced by nodes
   //    precomputed hash table (optional)
   //
   // Archive node contains file location within archive and other details
   //
   // Archive supports several compression formats.

typedef enum ztf_BunyArFileFormat
{
    ZTF_BUNYAR_FILE_FORMAT_RAW = 0,

    // File is splitted to N X-size blocks.
    // Leading data in a "blocks" format is represented by
    // BunyArBlockFormatHeader and BunyArBlockPointer table.
    // Table allows to seek through file quickly, while block size
    // is large enough for compression to be effective.
    ZTF_BUNYAR_FILE_FORMAT_LZ4_BLOCKS = 3,
    ZTF_BUNYAR_FILE_FORMAT_ZSTD_BLOCKS = 5,
}ztf_BunyArFileFormat;

// Artificial limit, to follow FS_MAX_PATH.
// Avoid using FS_MAX_PATH here because it varies, usually it is equal to 512
// FileSystem can not open file if name length is beyond limit.
// = 512 with trailing 0 at the end of str
#define ZTF_BUNYAR_FILE_NAME_LENGTH_MAX 511

    // points to location within archive
typedef struct ztf_BunyArPointer64
{
    uint64_t offset; // exact offset
    uint64_t size;   // exact size
}ztf_BunyArPointer64;

// points to relative location
typedef struct ztf_BunyArPointer32
{
    uint32_t offset; // relative offset
    uint32_t size;   // exact size
}ztf_BunyArPointer32;

// Reader can still use archive,
// if condition "compatible <= X <= actual" is met, where X is reader version.
typedef struct ztf_BunyArVersion
{
    uint32_t compatible; // backwards compatible version
    uint32_t actual;     // archive version
}ztf_BunyArVersion;

typedef struct BunyArHeader BunyArHeader;

typedef struct ztf_BunyArNode
{
    // BunyArFileFormat
    uint64_t format;

    // Original size of file compressed into an archive.
    // Also exact size of the file after reading from an archive
    uint64_t originalFileSize;

    // location of name relative to location of BunyArHeader::namesPointer
    // name is utf8 null-terminated string
    // size must not count trailing 0
    // size must be <= BUNYAR_FILE_NAME_LENGTH_MAX
    struct ztf_BunyArPointer32 namePointer;

    // location of compressed file
    struct ztf_BunyArPointer64 filePointer;
}ztf_BunyArNode;

typedef struct ztf_BunyArBlockFormatHeader
{
    // size of all uncompressed blocks except the last one
    uint64_t blockSize;

    // size of the last block. Strict rule: "blockSizeLast <= blockSize"
    uint64_t blockSizeLast;

    // number of BunyArBlockPointer
    uint64_t blockCount;

    // blocks are written after header
    // BunyArBlockPointer blockPointers[blockCount];
}ztf_BunyArBlockFormatHeader;

// Block pointer represents format, offset, and size of the block
// 1 + 40 + 23
// 1  bit   boolean set when block is compressed
// 40 bits  block offset, max offset is 1024GB-1B
// 23 bits  block size minus one, max size is 8MB
#define ZTF_BUNYAR_BLOCK_MAX_SIZE_MINUS_ONE (((uint32_t)1 << 23) - 1)
#define ZTF_BUNYAR_BLOCK_MAX_OFFSET         (((uint64_t)1 << 40) - 1)
typedef uint64_t ztf_BunyArBlockPointer;

typedef struct ztf_BunyArBlockInfo
{
    bool isCompressed;
    // size of compressed block in archive
    // uncompressed size is equal to blockSize or blockSizeLast
    uint32_t size;
    // block offset relative to the end of blockPointers
    uint64_t offset;
} ztf_BunyArBlockInfo;

ZTF_C_API struct ztf_BunyArBlockInfo ztf_bunyArDecodeBlockPointer(ztf_BunyArBlockPointer ptr);

ZTF_C_API bool ztf_bunyArEncodeBlockPointer(struct ztf_BunyArBlockInfo info, ztf_BunyArBlockPointer* dst);

// user must deallocate returned pointer using tf_free
ZTF_C_API struct ztf_BunyArHashTable* ztf_bunyArHashTableConstruct(uint64_t nodeCount, const struct ztf_BunyArNode* nodes, const char* nodeNames);

// In case value >= nodeCount is returned, node by that name is not found
ZTF_C_API uint64_t ztf_bunyArHashTableLookup(const struct ztf_BunyArHashTable* ht, const char* name, uint64_t nodeCount,
                                         const struct ztf_BunyArNode* nodes, const char* nodeNames);

ZTF_C_API uint64_t ztf_bunyArHashTableSize(const struct ztf_BunyArHashTable* ht);

ZTF_C_API const char* ztf_bunyArFormatName(enum ztf_BunyArFileFormat format);

ZTF_C_API void ztf_fsArchiveGetDescription(ztf_IFileSystem* pArchive, struct ztf_BunyArDescription* outInfo);

ZTF_C_API bool ztf_fsArchiveGetNodeDescription(ztf_IFileSystem* pArchive, uint64_t nodeId, struct ztf_BunyArNodeDescription* outInfo);

// Same as GetFileUid(), but without fileName postprocessing.
// Uses fileName directly without resolving through ResourceDirectory
// to search for file node.
ZTF_C_API bool ztf_fsArchiveGetNodeId(ztf_IFileSystem* fs, const char* fileName, uint64_t* outUid);

ZTF_C_API bool ztf_fsArchiveGetFileBlockMetadata(ztf_FileStream* pFile, struct ztf_BunyArBlockFormatHeader* outHeader,
                                             const ztf_BunyArBlockPointer** outBlockPtrs);

#ifdef __cplusplus
} // extern "C"
#endif