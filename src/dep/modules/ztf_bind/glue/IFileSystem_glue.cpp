// auto generated by c2z

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Utilities/Interfaces/IFilesystem.h"

// extern "C" const void* _1_pSystemFileIO_ = (void*)&::pSystemFileIO;

extern "C" IFileSystem* _1_getSystemFileIO() { return ::pSystemFileIO; }
extern "C" bool         _1_fsIoOpenStreamFromPath_(IFileSystem* pIO, const ResourceDirectory rd, const char* fileName, FileMode mode,
                                                   FileStream* pOut)
{
    return ::fsIoOpenStreamFromPath(pIO, rd, fileName, mode, pOut);
}
extern "C" bool   _1_fsCloseStream_(FileStream* fs) { return ::fsCloseStream(fs); }
extern "C" size_t _1_fsReadFromStream_(FileStream* fs, void* pOutputBuffer, size_t bufferSizeInBytes)
{
    return ::fsReadFromStream(fs, pOutputBuffer, bufferSizeInBytes);
}
extern "C" size_t _1_fsWriteToStream_(FileStream* fs, const void* pSourceBuffer, size_t byteCount)
{
    return ::fsWriteToStream(fs, pSourceBuffer, byteCount);
}
extern "C" bool _1_fsSeekStream_(FileStream* fs, SeekBaseOffset baseOffset, ssize_t seekOffset)
{
    return ::fsSeekStream(fs, baseOffset, seekOffset);
}
extern "C" ssize_t     _1_fsGetStreamSeekPosition_(FileStream* fs) { return ::fsGetStreamSeekPosition(fs); }
extern "C" ssize_t     _1_fsGetStreamFileSize_(FileStream* fs) { return ::fsGetStreamFileSize(fs); }
extern "C" bool        _1_fsFlushStream_(FileStream* fs) { return ::fsFlushStream(fs); }
extern "C" bool        _1_fsStreamAtEnd_(FileStream* fs) { return ::fsStreamAtEnd(fs); }
extern "C" const void* _1_BUNYAR_MAGIC_ = (void*)&::BUNYAR_MAGIC;
