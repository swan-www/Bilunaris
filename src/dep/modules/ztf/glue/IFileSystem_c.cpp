#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IFileSystem.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IFileSystem_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif

/// Default file system using C File IO or Bundled File IO (Android) based on the ResourceDirectory
ZTF_C_API ztf_IFileSystem* ztf_getSystemFileIO()
{
    return (ztf_IFileSystem*)pSystemFileIO;
}

/************************************************************************/
// MARK: - Initialization
/************************************************************************/
/// Initializes the FileSystem API
ZTF_C_API bool ztf_initFileSystem(ztf_FileSystemInitDesc* pDesc)
{
    return initFileSystem((FileSystemInitDesc*) pDesc);
}

/// Frees resources associated with the FileSystem API
ZTF_C_API void ztf_exitFileSystem(void)
{
    exitFileSystem();
}

/// 'desc' can be NULL
ZTF_C_API bool ztf_fsArchiveOpen(ztf_ResourceDirectory rd, const char* fileName, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out)
{
    return fsArchiveOpen((ResourceDirectory) rd, fileName, (const struct ArchiveOpenDesc*) desc, (IFileSystem*) out);
}

/// This function is useful to use arbitrary stream source as an archive stream.
/// Only (*Seek) and (*Read) functions are required.
///
/// 'desc' can be NULL
/// 'stream' is owned by user, must be valid until fsArchiveClose
///          do not use stream while archive is opened
ZTF_C_API bool ztf_fsArchiveOpenFromStream(ztf_FileStream* stream, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out)
{
    return fsArchiveOpenFromStream((FileStream*) stream, (const struct ArchiveOpenDesc*) desc, (IFileSystem*) out);
}

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
ZTF_C_API bool ztf_fsArchiveOpenFromMemory(uint64_t msize, const void* m, const struct ztf_ArchiveOpenDesc* desc, ztf_IFileSystem* out)
{
    return fsArchiveOpenFromMemory(msize, m, (const struct ArchiveOpenDesc*) desc, (IFileSystem*) out);
}

ZTF_C_API bool ztf_fsArchiveClose(ztf_IFileSystem* pArchive)
{
    return fsArchiveClose((IFileSystem*) pArchive);
}

/************************************************************************/
// MARK: - File IO
/************************************************************************/

/// Opens the file at `filePath` using the mode `mode`, returning a new FileStream that can be used
/// to read from or modify the file. May return NULL if the file could not be opened.
ZTF_C_API bool ztf_fsOpenStreamFromPath(ztf_ResourceDirectory resourceDir, const char* fileName, ztf_FileMode mode, ztf_FileStream* pOut)
{
    return fsOpenStreamFromPath((ResourceDirectory) resourceDir, fileName, (FileMode) mode, (FileStream*) pOut);
}

/// Opens a memory buffer as a FileStream, returning a stream that must be closed with `fsCloseStream`.
/// Use 'fsStreamMemoryMap' to do the opposite.
ZTF_C_API bool ztf_fsOpenStreamFromMemory(const void* buffer, size_t bufferSize, ztf_FileMode mode, bool owner, ztf_FileStream* pOut)
{
    return fsOpenStreamFromMemory(buffer, bufferSize, (FileMode) mode, owner, (FileStream*) pOut);
}

ZTF_C_API bool ztf_fsFindStream(ztf_FileStream* fs, const void* pFind, size_t findSize, ssize_t maxSeek, ssize_t* pPosition)
{
    return fsFindStream((FileStream*) fs, pFind, findSize, maxSeek, pPosition);
}
ZTF_C_API bool ztf_fsFindReverseStream(ztf_FileStream* fs, const void* pFind, size_t findSize, ssize_t maxSeek, ssize_t* pPosition)
{
    return fsFindReverseStream((FileStream*) fs, pFind, findSize, maxSeek, pPosition);
}

/// Checks if stream is a standard system stream
ZTF_C_API bool ztf_fsIsSystemFileStream(ztf_FileStream* fs)
{
    return fsIsSystemFileStream((FileStream*) fs);
}
/// Checks if stream is a memory stream
ZTF_C_API bool ztf_fsIsMemoryStream(ztf_FileStream* fs)
{
    return fsIsMemoryStream((FileStream*) fs);
}

/// symbolsCount can be SIZE_MAX, then reads until the end of file
/// appends '\0' to the end of string
ZTF_C_API size_t ztf_fsReadBstringFromStream(ztf_FileStream* stream, struct bstring* pStr, size_t symbolsCount)
{
    return fsReadBstringFromStream((FileStream*) stream, pStr, symbolsCount);
}

/// Wraps stream into new memory stream using fsStreamMemoryMap
/// returns true: old stream is wrapped by new one with new IO.
/// returns false: stream is unaffected.
/// In both cases stream stays in valid state.
/// fsCloseStream(FileStream*) takes care of cleaning wrapped stream.
/// So checking return value is optional.
ZTF_C_API bool ztf_fsStreamWrapMemoryMap(ztf_FileStream* fs)
{
    return fsStreamWrapMemoryMap((FileStream*)fs);
}

ZTF_C_API bool ztf_fsIoOpenStreamFromPath(ztf_IFileSystem* pIO, const ztf_ResourceDirectory rd, const char* fileName, ztf_FileMode mode,
                                              ztf_FileStream* pOut)
{
    return fsIoOpenStreamFromPath((IFileSystem*) pIO, (ResourceDirectory)rd, fileName, (FileMode) mode, (FileStream*) pOut);
}

/// Closes and invalidates the file stream.
ZTF_C_API bool ztf_fsCloseStream(ztf_FileStream* fs)
{
    return fsCloseStream((FileStream*) fs);
}

/// Returns the number of bytes read.
ZTF_C_API size_t ztf_fsReadFromStream(ztf_FileStream* fs, void* pOutputBuffer, size_t bufferSizeInBytes)
{
    return fsReadFromStream((FileStream*) fs, pOutputBuffer, bufferSizeInBytes);
}

/// Reads at most `bufferSizeInBytes` bytes from sourceBuffer and writes them into the file.
/// Returns the number of bytes written.
ZTF_C_API size_t ztf_fsWriteToStream(ztf_FileStream* fs, const void* pSourceBuffer, size_t byteCount)
{
    return fsWriteToStream((FileStream*) fs, pSourceBuffer, byteCount);
}

/// Seeks to the specified position in the file, using `baseOffset` as the reference offset.
ZTF_C_API bool ztf_fsSeekStream(ztf_FileStream* fs, ztf_SeekBaseOffset baseOffset, ssize_t seekOffset)
{
    return fsSeekStream((FileStream*) fs, (SeekBaseOffset) baseOffset, seekOffset);
}

/// Gets the current seek position in the file.
ZTF_C_API ssize_t ztf_fsGetStreamSeekPosition(ztf_FileStream* fs)
{
    return fsGetStreamSeekPosition((FileStream*) fs);
}

/// Gets the current size of the file. Returns -1 if the size is unknown or unavailable.
ZTF_C_API ssize_t ztf_fsGetStreamFileSize(ztf_FileStream* fs)
{
    return fsGetStreamFileSize((FileStream*) fs);
}

/// Flushes all writes to the file stream to the underlying subsystem.
ZTF_C_API bool ztf_fsFlushStream(ztf_FileStream* fs)
{
    return fsFlushStream((FileStream*) fs);
}

/// Returns whether the current seek position is at the end of the file stream.
ZTF_C_API bool ztf_fsStreamAtEnd(ztf_FileStream* fs)
{
    return fsStreamAtEnd((FileStream*) fs);
}
ZTF_C_API const char* ztf_fsIoGetResourceMount(ztf_IFileSystem* pIO, ztf_ResourceMount mount)
{
    return fsIoGetResourceMount((IFileSystem*) pIO, (ResourceMount) mount);
}
ZTF_C_API bool ztf_fsIoGetFileUid(ztf_IFileSystem* pIO, ztf_ResourceDirectory rd, const char* fileName, uint64_t* outUid)
{
    return fsIoGetFileUid((IFileSystem*) pIO, (ResourceDirectory) rd, fileName, outUid);
}
ZTF_C_API bool ztf_fsIoOpenByUid(ztf_IFileSystem* pIO, uint64_t index, ztf_FileMode mode, ztf_FileStream* pOutStream)
{
    return fsIoOpenByUid((IFileSystem*) pIO, index, (FileMode) mode, (FileStream*) pOutStream);
}
ZTF_C_API bool ztf_fsStreamMemoryMap(ztf_FileStream* fs, size_t* outSize, void const** outData)
{
    return fsStreamMemoryMap((FileStream*) fs, outSize, outData);
}

/************************************************************************/
    // MARK: - Directory queries
    /************************************************************************/
    /// Returns location set for resource directory in fsSetPathForResourceDir.
ZTF_C_API const char* ztf_fsGetResourceDirectory(ztf_ResourceDirectory resourceDir)
{
    return fsGetResourceDirectory((ResourceDirectory) resourceDir);
}

/// Returns Resource Mount point for resource directory
ZTF_C_API ztf_ResourceMount ztf_fsGetResourceDirectoryMount(ztf_ResourceDirectory resourceDir)
{
    return (ztf_ResourceMount)fsGetResourceDirectoryMount((ResourceDirectory) resourceDir);
}

/// Sets the relative path for `resourceDir` from `mount` to `bundledFolder`.
/// The `resourceDir` will making use of the given IFileSystem `pIO` file functions.
/// When `mount` is set to `RM_CONTENT` for a `resourceDir`, this directory is marked as a bundled resource folder.
/// Bundled resource folders should only be used for Read operations.
/// NOTE: A `resourceDir` can only be set once.
ZTF_C_API void ztf_fsSetPathForResourceDir(ztf_IFileSystem* pIO, ztf_ResourceMount mount, ztf_ResourceDirectory resourceDir, const char* bundledFolder)
{
    fsSetPathForResourceDir((IFileSystem*) pIO, (ResourceMount) mount, (ResourceDirectory) resourceDir, bundledFolder);
}

/************************************************************************/
// MARK: - File Queries
/************************************************************************/

/// Gets the time of last modification for the file at `fileName`, within 'resourceDir'.
ZTF_C_API time_t ztf_fsGetLastModifiedTime(ztf_ResourceDirectory resourceDir, const char* fileName)
{
    return fsGetLastModifiedTime((ResourceDirectory) resourceDir, fileName);
}

/************************************************************************/
// MARK: - Platform-dependent function definitions
/************************************************************************/

ZTF_C_API bool ztf_fsCreateResourceDirectory(ztf_ResourceDirectory resourceDir)
{
    return fsCreateResourceDirectory((ResourceDirectory) resourceDir);
}

ZTF_C_API struct ztf_BunyArBlockInfo ztf_bunyArDecodeBlockPointer(ztf_BunyArBlockPointer ptr)
{
    BunyArBlockInfo babi = bunyArDecodeBlockPointer((BunyArBlockPointer) ptr);
    ztf_BunyArBlockInfo zbabi = *(ztf_BunyArBlockInfo*)&babi;
    return zbabi;
}

ZTF_C_API bool ztf_bunyArEncodeBlockPointer(struct ztf_BunyArBlockInfo info, ztf_BunyArBlockPointer* dst)
{
    BunyArBlockInfo babi = *(BunyArBlockInfo*)&info;
    return bunyArEncodeBlockPointer(babi, (BunyArBlockPointer*) dst);
}

// user must deallocate returned pointer using tf_free
ZTF_C_API struct ztf_BunyArHashTable* ztf_bunyArHashTableConstruct(uint64_t nodeCount, const struct ztf_BunyArNode* nodes, const char* nodeNames)
{
    return (ztf_BunyArHashTable*)bunyArHashTableConstruct(nodeCount, (const struct BunyArNode*) nodes, nodeNames);
}

// In case value >= nodeCount is returned, node by that name is not found
ZTF_C_API uint64_t ztf_bunyArHashTableLookup(const struct ztf_BunyArHashTable* ht, const char* name, uint64_t nodeCount,
                                         const struct ztf_BunyArNode* nodes, const char* nodeNames)
{
    return bunyArHashTableLookup((const BunyArHashTable*) ht, name, nodeCount, (const struct BunyArNode*) nodes, nodeNames);
}

ZTF_C_API uint64_t ztf_bunyArHashTableSize(const struct ztf_BunyArHashTable* ht)
{
    return bunyArHashTableSize((const struct BunyArHashTable*) ht);
}
ZTF_C_API const char* ztf_bunyArFormatName(enum ztf_BunyArFileFormat format)
{
    return bunyArFormatName((BunyArFileFormat) format);
}

ZTF_C_API void ztf_fsArchiveGetDescription(ztf_IFileSystem* pArchive, struct ztf_BunyArDescription* outInfo)
{
    fsArchiveGetDescription((IFileSystem*) pArchive, (struct BunyArDescription*) outInfo);
}

ZTF_C_API bool ztf_fsArchiveGetNodeDescription(ztf_IFileSystem* pArchive, uint64_t nodeId, struct ztf_BunyArNodeDescription* outInfo)
{
    return fsArchiveGetNodeDescription((IFileSystem*) pArchive, nodeId, (struct BunyArNodeDescription*) outInfo);
}

// Same as GetFileUid(), but without fileName postprocessing.
// Uses fileName directly without resolving through ResourceDirectory
// to search for file node.
ZTF_C_API bool ztf_fsArchiveGetNodeId(ztf_IFileSystem* fs, const char* fileName, uint64_t* outUid)
{
    return fsArchiveGetNodeId((IFileSystem*) fs, fileName, outUid);
}

ZTF_C_API bool ztf_fsArchiveGetFileBlockMetadata(ztf_FileStream* pFile, struct ztf_BunyArBlockFormatHeader* outHeader,
                                             const ztf_BunyArBlockPointer** outBlockPtrs)
{
    return fsArchiveGetFileBlockMetadata((FileStream*) pFile, (struct BunyArBlockFormatHeader*) outHeader, (const BunyArBlockPointer**)outBlockPtrs);
}

#ifdef __cplusplus
} // extern "C"
#endif