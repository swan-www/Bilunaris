#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Resources/ResourceLoader/Interfaces/IResourceLoader.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IResourceLoader_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif

const ztf_ResourceState ztf_gVertexBufferState = (ztf_ResourceState)(ZTF_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER | ZTF_RESOURCE_STATE_SHADER_RESOURCE);
const ztf_ResourceState ztf_gIndexBufferState = (ztf_ResourceState)(ZTF_RESOURCE_STATE_INDEX_BUFFER | ZTF_RESOURCE_STATE_SHADER_RESOURCE);
const char ZTF_GEOMETRY_FILE_MAGIC_STR[10] = {'G', 'e', 'o', 'm', 'e', 't', 'r', 'y', 'T', 'F'};

ZTF_C_RENDERER_API ztf_ResourceLoaderDesc* ztf_getDefaultResourceLoaderDesc()
{
    return (ztf_ResourceLoaderDesc*)&gDefaultResourceLoaderDesc;
}

// MARK: - Resource Loader Functions

ZTF_C_RENDERER_API void ztf_initResourceLoaderInterface(ztf_Renderer* pRenderer, ztf_ResourceLoaderDesc* pDesc)
{
    initResourceLoaderInterface((Renderer*) pRenderer, (ResourceLoaderDesc*) pDesc);
}

ZTF_C_RENDERER_API void ztf_exitResourceLoaderInterface(ztf_Renderer* pRenderer)
{
    exitResourceLoaderInterface((Renderer*) pRenderer);
}

/// Multiple Renderer (unlinked GPU) variants. The Resource Loader must be shared between Renderers.
ZTF_C_RENDERER_API void ztf_initResourceLoaderInterface2(ztf_Renderer** ppRenderers, uint32_t rendererCount, ztf_ResourceLoaderDesc* pDesc)
{
    initResourceLoaderInterface((Renderer**)ppRenderers, rendererCount, (ResourceLoaderDesc*) pDesc);
}
ZTF_C_RENDERER_API void ztf_exitResourceLoaderInterface2(ztf_Renderer** ppRenderers, uint32_t rendererCount)
{
    exitResourceLoaderInterface((Renderer**)ppRenderers, rendererCount);
}

// MARK: App Material Management
#ifdef ENABLE_FORGE_MATERIALS

// Will load a material and all related shaders/textures (if they are not already loaded, Material shaders/textures are shared across all
// Materials)
ZTF_C_RENDERER_API uint32_t ztf_addMaterial(const char* pMaterialFileName, ztf_Material** pMaterial, ztf_SyncToken* pSyncToken)
{
    return addMaterial(pMaterialFileName, (Material**)pMaterial, (SyncToken*) pSyncToken);
}
// Will unload all the related shaders/textures (if they are not still used by some other Material)
ZTF_C_RENDERER_API void     ztf_removeMaterial(ztf_Material* pMaterial)
{
    removeMaterial((Material*) pMaterial);
}

// TODO: Functions below are a simple interface to get resources from materials, as we develop materials further this interface will
// probably change.
ZTF_C_RENDERER_API uint32_t ztf_getMaterialSetIndex(ztf_Material* pMaterial, const char* name)
{
    return getMaterialSetIndex((Material*) pMaterial, name);
}
ZTF_C_RENDERER_API void     ztf_getMaterialShader(ztf_Material* pMaterial, uint32_t materialSetIndex, ztf_Shader** ppOutShader)
{
    getMaterialShader((Material*) pMaterial, materialSetIndex, (Shader**)ppOutShader);
}
ZTF_C_RENDERER_API void     ztf_getMaterialTextures(ztf_Material* pMaterial, uint32_t materialSetIndex, const char** ppOutTextureBindingNames,
                                                ztf_Texture** ppOutTextures, uint32_t outTexturesSize)
{
    getMaterialTextures((Material*) pMaterial, materialSetIndex, ppOutTextureBindingNames, (Texture**)ppOutTextures, outTexturesSize);
}

#endif // ENABLE_FORGE_MATERIALS

// MARK: addResource and updateResource

ZTF_C_RENDERER_API void ztf_getResourceSizeAlign(const ztf_BufferLoadDesc* pDesc, ztf_ResourceSizeAlign* pOut)
{
    getResourceSizeAlign((const BufferLoadDesc*) pDesc, (ResourceSizeAlign*) pOut);
}
ZTF_C_RENDERER_API void ztf_getResourceSizeAlign2(const ztf_TextureLoadDesc* pDesc, ztf_ResourceSizeAlign* pOut)
{
    getResourceSizeAlign((const TextureLoadDesc*) pDesc, (ResourceSizeAlign*) pOut);
}

/// Adding and updating resources can be done using a addResource or
/// beginUpdateResource/endUpdateResource pair.
/// if addResource(BufferLoadDesc) is called with a data size larger than the ResourceLoader's staging buffer, the ResourceLoader
/// will perform multiple copies/flushes rather than failing the copy.

/// If token is NULL, the resource will be available when allResourceLoadsCompleted() returns true.
/// If token is non NULL, the resource will be available after isTokenCompleted(token) returns true.
ZTF_C_RENDERER_API void ztf_addResource(ztf_BufferLoadDesc* pBufferDesc, ztf_SyncToken* token)
{
    addResource((BufferLoadDesc*) pBufferDesc, (SyncToken*) token);
}
ZTF_C_RENDERER_API void ztf_addResource2(ztf_TextureLoadDesc* pTextureDesc, ztf_SyncToken* token)
{
    addResource((TextureLoadDesc*)pTextureDesc, (SyncToken*)token);
}
ZTF_C_RENDERER_API void ztf_addResource3(ztf_GeometryLoadDesc* pGeomDesc, ztf_SyncToken* token)
{
    addResource((GeometryLoadDesc*) pGeomDesc, (SyncToken*) token);
}
ZTF_C_RENDERER_API void ztf_addGeometryBuffer(ztf_GeometryBufferLoadDesc* pDesc)
{
    addGeometryBuffer((GeometryBufferLoadDesc*) pDesc);
}

ZTF_C_RENDERER_API void ztf_beginUpdateResource(ztf_BufferUpdateDesc* pBufferDesc)
{
    beginUpdateResource((BufferUpdateDesc*) pBufferDesc);
}
ZTF_C_RENDERER_API void ztf_beginUpdateResource2(ztf_TextureUpdateDesc* pTextureDesc)
{
    beginUpdateResource((TextureUpdateDesc*) pTextureDesc);
}
ZTF_C_RENDERER_API void ztf_endUpdateResource(ztf_BufferUpdateDesc* pBuffer)
{
    endUpdateResource((BufferUpdateDesc*) pBuffer);
}
ZTF_C_RENDERER_API void ztf_endUpdateResource2(ztf_TextureUpdateDesc* pTexture)
{
    endUpdateResource((TextureUpdateDesc*) pTexture);
}

/// This function is used to acquire geometry buffer location.
/// It can be used on index or vertex buffer
/// When there are no continious chunk with enough size, output chunk contains 0 size.
/// Use releaseGeometryBufferPart to release chunk.
/// Make sure all chunks are released before removeGeometryBuffer.
ZTF_C_RENDERER_API void ztf_addGeometryBufferPart(ztf_BufferChunkAllocator* buffer, uint32_t size, uint32_t alignment, ztf_BufferChunk* pOut,
                                              ztf_BufferChunk* pPreferredChunk)
{
    addGeometryBufferPart((BufferChunkAllocator*) buffer, size, alignment, (BufferChunk*) pOut, (BufferChunk*) pPreferredChunk);
}

/// Release previously claimed chunk to buffer.
/// Buffer must be the one passed to claimGeometryBufferPart for this chunk.
ZTF_C_RENDERER_API void ztf_removeGeometryBufferPart(ztf_BufferChunkAllocator* buffer, ztf_BufferChunk* chunk)
{
    removeGeometryBufferPart((BufferChunkAllocator*) buffer, (BufferChunk*) chunk);
}

ZTF_C_RENDERER_API void ztf_flushResourceUpdates(ztf_FlushResourceUpdateDesc* pDesc)
{
    flushResourceUpdates((FlushResourceUpdateDesc*) pDesc);
}

/// Copies data from GPU to the CPU, typically for transferring it to another GPU in unlinked mode.
/// For optimal use, the amount of data to transfer should be minimized as much as possible and applications should
/// provide additional graphics/compute work that the GPU can execute alongside the copy.
FORGE_RENDERER_API void ztf_copyResource(ztf_TextureCopyDesc* pTextureDesc, ztf_SyncToken* token)
{
    copyResource((TextureCopyDesc*) pTextureDesc, (SyncToken*) token);
}

// MARK: removeResource

ZTF_C_RENDERER_API void ztf_removeResource(ztf_Buffer* pBuffer)
{
    removeResource((Buffer*) pBuffer);
}
ZTF_C_RENDERER_API void ztf_removeResource2(ztf_Texture* pTexture)
{
    removeResource((Texture*) pTexture);
}
ZTF_C_RENDERER_API void ztf_removeResource3(ztf_Geometry* pGeom)
{
    removeResource((Geometry*) pGeom);
}
ZTF_C_RENDERER_API void ztf_removeResource4(ztf_GeometryData* pGeom)
{
    removeResource((GeometryData*) pGeom);
}
ZTF_C_RENDERER_API void ztf_removeGeometryBuffer(ztf_GeometryBuffer* pGeomBuffer)
{
    removeGeometryBuffer((GeometryBuffer*) pGeomBuffer);
}
// Frees pGeom->pShadow in case it was requested with GEOMETRY_LOAD_FLAG_SHADOWED and you are already done with it
ZTF_C_RENDERER_API void ztf_removeGeometryShadowData(ztf_GeometryData* pGeom)
{
    removeGeometryShadowData((GeometryData*) pGeom);
}

// MARK: Waiting for Loads

/// Returns whether all submitted resource loads and updates have been completed.
ZTF_C_RENDERER_API bool ztf_allResourceLoadsCompleted()
{
    return allResourceLoadsCompleted();
}

/// Blocks the calling thread until allResourceLoadsCompleted() returns true.
/// Note that if more resource loads or updates are submitted from a different thread while
/// while the calling thread is blocked, those loads or updates are not guaranteed to have
/// completed when this function returns.
ZTF_C_RENDERER_API void ztf_waitForAllResourceLoads()
{
    return waitForAllResourceLoads();
}

/// Wait for the copy queue to finish all work
ZTF_C_RENDERER_API void ztf_waitCopyQueueIdle()
{
    waitCopyQueueIdle();
}

/// Returns wheter the resourceloader is single threaded or not
ZTF_C_RENDERER_API bool ztf_isResourceLoaderSingleThreaded()
{
    return isResourceLoaderSingleThreaded();
}

/// A SyncToken is an array of monotonically increasing integers.
/// getLastTokenCompleted() returns the last value for which
/// isTokenCompleted(token) is guaranteed to return true.
ZTF_C_RENDERER_API ztf_SyncToken ztf_getLastTokenCompleted()
{
    SyncToken token = getLastTokenCompleted();
    ztf_SyncToken ztf_token = *(ztf_SyncToken*)&token;
    return ztf_token;
}
ZTF_C_RENDERER_API bool      ztf_isTokenCompleted(const ztf_SyncToken* token)
{
    return isTokenCompleted((const SyncToken*) token);
}
ZTF_C_RENDERER_API void      ztf_waitForToken(const ztf_SyncToken* token)
{
    waitForToken((const SyncToken*) token);
}

/// Allows clients to synchronize with the submission of copy commands (as opposed to their completion).
/// This can reduce the wait time for clients but requires using the Semaphore from getLastSemaphoreCompleted() in a wait
/// operation in a submit that uses the textures just updated.
ZTF_C_RENDERER_API ztf_SyncToken ztf_getLastTokenSubmitted()
{
    SyncToken token = getLastTokenSubmitted();
    ztf_SyncToken ztf_token = *(ztf_SyncToken*)&token;
    return ztf_token;
}
ZTF_C_RENDERER_API bool      ztf_isTokenSubmitted(const ztf_SyncToken* token)
{
    return isTokenSubmitted((const SyncToken*) token);
}
ZTF_C_RENDERER_API void      ztf_waitForTokenSubmitted(const ztf_SyncToken* token)
{
    waitForTokenSubmitted((const SyncToken*) token);
}

/// Return the semaphore for the last copy operation of a specific GPU.
/// Could be NULL if no operations have been executed.
ZTF_C_RENDERER_API ztf_Semaphore* ztf_getLastSemaphoreSubmitted(uint32_t nodeIndex)
{
    return (ztf_Semaphore*)getLastSemaphoreSubmitted(nodeIndex);
}

/// Either loads the cached shader bytecode or compiles the shader to create new bytecode depending on whether source is newer than binary
ZTF_C_RENDERER_API void ztf_addShader(ztf_Renderer* pRenderer, const ztf_ShaderLoadDesc* pDesc, ztf_Shader** pShader)
{
    addShader((Renderer*) pRenderer, (const ShaderLoadDesc*) pDesc, (Shader**)pShader);
}

/// Save/Load pipeline cache from disk
ZTF_C_RENDERER_API void ztf_loadPipelineCache(ztf_Renderer* pRenderer, const ztf_PipelineCacheLoadDesc* pDesc, ztf_PipelineCache** ppPipelineCache)
{
    loadPipelineCache((Renderer*) pRenderer, (const PipelineCacheLoadDesc*) pDesc, (PipelineCache**)ppPipelineCache);
}
ZTF_C_RENDERER_API void ztf_savePipelineCache(ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache, ztf_PipelineCacheSaveDesc* pDesc)
{
    savePipelineCache((Renderer*) pRenderer, (PipelineCache*) pPipelineCache, (PipelineCacheSaveDesc*) pDesc);
}

/// Determines whether we are using Uniform Memory Architecture or not.
/// Do not assume this variable will be the same, if code was compiled with multiple APIs result of this function might change per API.
ZTF_C_RENDERER_API bool ztf_isUma()
{
    return isUma();
}

#ifdef __cplusplus
} // extern "C"
#endif