#pragma once

#include <stdint.h>
#include <assert.h>

#include "ztf_bind_common.h"

#include "IGraphics_c.h"
#include "Config_c.h"
#include "GraphicsConfig_c.h"
#include "MathTypes_glue.h"

#ifdef __cplusplus
extern "C"
{
#endif

    ZTF_C_RENDERER_API extern const ztf_ResourceState ztf_gVertexBufferState;
    ZTF_C_RENDERER_API extern const ztf_ResourceState ztf_gIndexBufferState;

    typedef struct ztf_MappedMemoryRange
    {
        uint8_t* pData;
        ztf_Buffer* pBuffer;
        uint64_t mOffset;
        uint64_t mSize;
        uint32_t mFlags;
    } ztf_MappedMemoryRange;

    typedef enum ztf_TextureContainerType
    {
        /// Use whatever container is designed for that platform
        /// Windows, macOS, Linux - TEXTURE_CONTAINER_DDS
        /// iOS, Android          - TEXTURE_CONTAINER_KTX
        ZTF_TEXTURE_CONTAINER_DEFAULT = 0,
        /// Explicit container types
        /// .dds
        ZTF_TEXTURE_CONTAINER_DDS,
        /// .ktx
        ZTF_TEXTURE_CONTAINER_KTX,
        /// .gnf
        ZTF_TEXTURE_CONTAINER_GNF,
    } ztf_TextureContainerType;

    typedef enum ztf_RegisterMaterialResult
    {

        ZTF_REGISTER_MATERIAL_SUCCESS = 0x0000,
        ZTF_REGISTER_MATERIAL_BADFILE = 0x0001,

    } ztf_RegisterMaterialResult;

    // MARK: - Resource Loading

    typedef struct ztf_BufferLoadDesc
    {
        ztf_Buffer** ppBuffer;
        // This must stay valid until the buffer load is not completed
        // Use waitForToken (if a token was passed to addResource) or waitForAllResourceLoads before freeing pData
        const void* pData;
        ztf_BufferDesc  mDesc;
        /// MemZero buffer
        bool        mForceReset;

        // Optional (if user provides staging buffer memory)
        ztf_Buffer* pSrcBuffer;
        uint64_t mSrcOffset;
    } ztf_BufferLoadDesc;

    typedef struct ztf_TextureLoadDesc
    {
        ztf_Texture** ppTexture;
        union
        {
            /// Load empty texture
            struct
            {
                ztf_TextureDesc* pDesc;
                /// MemZero texture
                bool         mForceReset;
            };
            /// Ycbcr sampler to use when loading ycbcr texture from file
            ztf_Sampler* pYcbcrSampler;
        };
        /// Filename without extension. Extension will be determined based on mContainer
        const char* pFileName;
        /// The index of the GPU in SLI/Cross-Fire that owns this texture, or the Renderer index in unlinked mode.
        uint32_t             mNodeIndex;
        /// Following is ignored if pDesc != NULL.  pDesc->mFlags will be considered instead.
        ztf_TextureCreationFlags mCreationFlag;
        /// The texture file format (dds/ktx/...)
        ztf_TextureContainerType mContainer;
    } ztf_TextureLoadDesc;

    typedef struct ztf_BufferChunk
    {
        uint32_t mOffset;
        uint32_t mSize;
    } ztf_BufferChunk;

    // Structure used to sub-allocate chunks on a buffer, keeps track of free memory to handle new requests.
    // Interface to add/remove this allocator is currently private, could be made public if needed.
    typedef struct ztf_BufferChunkAllocator
    {
        ztf_Buffer* pBuffer;
        uint32_t     mUsedChunkCount;
        uint32_t     mSize;
        ztf_BufferChunk* mUnusedChunks;
    } ztf_BufferChunkAllocator;

    // Stores huge buffers that are then used to sub-allocate memory for each of the loaded meshes.
    // GeometryBuffer can be provided to GeometryLoadDesc::pGeometryBuffer when loading a mesh, sub-chunks will be allocated
    // by mIndex and mVertex allocators and return the BufferChunk(s) that where used in Geometry::mIndexBufferChunk and
    // Geometry::mVertexBufferChunks
    typedef struct ztf_GeometryBuffer
    {
        ztf_BufferChunkAllocator mIndex;
        ztf_BufferChunkAllocator mVertex[ZTF_MAX_VERTEX_BINDINGS];
    } ztf_GeometryBuffer;

    extern const char ZTF_GEOMETRY_FILE_MAGIC_STR[10];

    typedef struct ztf_Meshlet
    {
        /// Offsets within meshlet_vertices and meshlet_triangles arrays with meshlet data
        uint vertexOffset;
        uint triangleOffset;

        /// Number of vertices and triangles used in the meshlet; data is stored in consecutive range defined by offset and count
        uint vertexCount;
        uint triangleCount;
    } ztf_Meshlet;

    typedef struct ztf_MeshletData
    {
        ztf_Float3 center;
        float  radius;

        /// Normal cone, useful for backface culling
        ztf_Float3 coneApex;
        ztf_Float3 coneAxis;
        float  coneCutoff; // = cos(angle/2)
    } ztf_MeshletData;

    typedef struct ztf_GeometryMeshlets
    {
        uint64_t     mMeshletCount;
        ztf_Meshlet* mMeshlets;
        ztf_MeshletData* mMeshletsData;

        uint64_t  mVertexCount;
        uint32_t* mVertices;

        uint64_t mTriangleCount;
        uint8_t* mTriangles;
    } ztf_GeometryMeshlets;

    typedef struct ztf_Geometry
    {
        union
        {
            struct
            {
                /// Index buffer to bind when drawing this geometry
                ztf_Buffer* pIndexBuffer;
                /// The array of vertex buffers to bind when drawing this geometry
                ztf_Buffer* pVertexBuffers[ZTF_MAX_VERTEX_BINDINGS];
            };
            struct
            {
                /// Used when Geometry is loaded to unified GeometryBuffer object (when GeometryLoadDesc::pGeometryBuffer is valid)
                ztf_BufferChunk mIndexBufferChunk;
                ztf_BufferChunk mVertexBufferChunks[ZTF_MAX_VERTEX_BINDINGS];
            };
        };

        /// The array of traditional draw arguments to draw each subset in this geometry
        ztf_IndirectDrawIndexArguments* pDrawArgs;

        /// The array of vertex buffer strides to bind when drawing this geometry
        uint32_t mVertexStrides[ZTF_MAX_VERTEX_BINDINGS];

        /// Number of vertex buffers in this geometry
        uint32_t mVertexBufferCount : 8;
        /// Index type (32 or 16 bit)
        uint32_t mIndexType : 2;
        /// Number of draw args in the geometry
        uint32_t mDrawArgCount : 22;
        /// Number of indices in the geometry
        uint32_t mIndexCount;
        /// Number of vertices in the geometry
        uint32_t mVertexCount;

        // If present, data is stored in pGeometryBuffer
        ztf_GeometryBuffer* pGeometryBuffer;

        ztf_GeometryMeshlets meshlets;

        uint32_t mPad[20];
    } ztf_Geometry;

    _Static_assert(sizeof(ztf_Geometry) == 352, "If Geometry size changes we need to rebuild all custom binary meshes");
    _Static_assert(sizeof(ztf_Geometry) % 16 == 0, "Geometry size must be a multiple of 16");

    typedef struct ztf_Hair
    {
        uint32_t mVertexCountPerStrand;
        uint32_t mGuideCountPerStrand;
    } ztf_Hair;

    typedef struct ztf_ShadowData
    {
        void* pIndices;
        void* pAttributes[ZTF_MAX_SEMANTICS];

        // Strides for the data in pAttributes, this might not match Geometry::mVertexStrides since those are generated based on
        // GeometryLoadDesc::pVertexLayout, e.g. if the normals are packed on the GPU as half2 then:
        //         - Geometry::mVertexStrides will be sizeof(half2)
        //         - ShadowData::mVertexStrides might be sizeof(float3) = 12 (or maybe sizeof(float4) = 16)
        // If the data readed from the file in pAttributes is already packed then ShadowData::mVertexStrides[i] ==
        // Geometry::mVertexStrides[i]
        uint32_t mVertexStrides[ZTF_MAX_SEMANTICS];

        // We might have a different number of attributes than mVertexCount.
        // This happens for example for Hair
        uint32_t mAttributeCount[ZTF_MAX_SEMANTICS];

        // TODO: Consider if we want to store here mIndexStride to access ShadowData::pIndices,
        //       right now it depends on the number of vertexes in the mesh (uint16_t if mVertexCount < 64k otherwise uint32_t)
    } ztf_ShadowData;

    // Outputs data that's only needed in the CPU side, OTOH the Geometry object holds GPU related information and buffers
    typedef struct ztf_GeometryData
    {
        /// Shadow copy of the geometry vertex and index data if requested through the load flags
        ztf_ShadowData* pShadow;

        /// The array of joint inverse bind-pose matrices ( object-space )
        ztf_Matrix4* pInverseBindPoses;
        /// The array of data to remap skin batch local joint ids to global joint ids
        uint32_t* pJointRemaps;

        /// Number of joints in the skinned geometry
        uint32_t mJointCount;

        /// Hair data
        ztf_Hair mHair;

        uint32_t mPad0[1];

        ztf_MeshletData* meshlets;

        // Custom data imported by the user in custom AssetPipelines, this can be data that was exported from a custom tool/plugin
        // specific to the engine/game. See AssetPipeline: callbacks in ProcessGLTFParams for more information.
        void* pUserData;
        uint32_t mUserDataSize;

        uint32_t mPad1[5];
    } ztf_GeometryData;

    _Static_assert(sizeof(ztf_GeometryData) % 16 == 0, "GeometryData size must be a multiple of 16");

    typedef enum ztf_GeometryLoadFlags
    {
        ZTF_GEOMETRY_LOAD_FLAG_NONE = 0x0,
        /// Keep shadow copy of indices and vertices for CPU
        ZTF_GEOMETRY_LOAD_FLAG_SHADOWED = 0x1,
        /// Use structured buffers instead of raw buffers
        ZTF_GEOMETRY_LOAD_FLAG_STRUCTURED_BUFFERS = 0x2,
        /// Geometry buffers can be used as input for ray tracing
        ZTF_GEOMETRY_LOAD_FLAG_RAYTRACING_INPUT = 0x4,
    } ztf_GeometryLoadFlags;

    typedef struct ztf_GeometryBufferLoadDesc
    {
        ztf_ResourceState mStartState;

        const char* pNameIndexBuffer;
        const char* pNamesVertexBuffers[ZTF_MAX_VERTEX_BINDINGS];

        uint32_t mIndicesSize;
        uint32_t mVerticesSizes[ZTF_MAX_VERTEX_BINDINGS];

        ztf_ResourcePlacement* pIndicesPlacement;
        ztf_ResourcePlacement* pVerticesPlacements[ZTF_MAX_VERTEX_BINDINGS];

        ztf_GeometryBuffer** pOutGeometryBuffer;
    } ztf_GeometryBufferLoadDesc;

    typedef struct ztf_GeometryBufferLayoutDesc
    {
        ztf_IndexType mIndexType;
        uint32_t  mVerticesStrides[ZTF_MAX_VERTEX_BINDINGS];
        // Vertex buffer/binding idx for each semantic.
        // Used to locate attributes inside specific buffers for loaded Geometry.
        uint32_t  mSemanticBindings[ZTF_SEMANTIC_TEXCOORD9 + 1];
    } ztf_GeometryBufferLayoutDesc;

    typedef struct ztf_GeometryLoadDesc
    {
        /// Output geometry
        ztf_Geometry** ppGeometry;
        ztf_GeometryData** ppGeometryData;

        /// Filename of geometry container
        const char* pFileName;
        /// Loading flags
        ztf_GeometryLoadFlags   mFlags;
        /// Linked gpu node / Unlinked Renderer index
        uint32_t            mNodeIndex;
        /// Specifies how to arrange the vertex data loaded from the file into GPU memory
        const ztf_VertexLayout* pVertexLayout;

        /// Optional preallocated unified buffer for geometry.
        /// When this parameter is specified, Geometry::pDrawArgs values are going
        /// to be shifted according to index/vertex location within BufferChunkAllocator.
        ztf_GeometryBuffer* pGeometryBuffer;

        /// Used to convert data to desired state inside GeometryBuffer.
        ztf_GeometryBufferLayoutDesc* pGeometryBufferLayoutDesc;
    } ztf_GeometryLoadDesc;

    typedef struct ztf_BufferUpdateDesc
    {
        ztf_Buffer* pBuffer;
        uint64_t mDstOffset;
        uint64_t mSize;

        /// To be filled by the caller between beginUpdateResource and endUpdateResource calls
        /// Example:
        /// BufferUpdateDesc update = { pBuffer, bufferDstOffset };
        /// beginUpdateResource(&update);
        /// ParticleVertex* vertices = (ParticleVertex*)update.pMappedData;
        ///   for (uint32_t i = 0; i < particleCount; ++i)
        ///	    vertices[i] = { rand() };
        /// endUpdateResource(&update, &token);
        void* pMappedData;

        // Optional (if user provides staging buffer memory)
        ztf_Buffer* pSrcBuffer;
        uint64_t      mSrcOffset;
        ztf_ResourceState mCurrentState;

        /// Internal
        struct
        {
            ztf_MappedMemoryRange mMappedRange;
        } mInternal;
    } ztf_BufferUpdateDesc;

    typedef struct ztf_TextureSubresourceUpdate
    {
        /// Filled by ResourceLaoder in beginUpdateResource
        /// Size of each row in destination including padding - Needs to be respected otherwise texture data will be corrupted if dst row stride
        /// is not the same as src row stride
        uint32_t mDstRowStride;
        /// Number of rows in this slice of the texture
        uint32_t mRowCount;
        /// Src row stride for convenience (mRowCount * width * texture format size)
        uint32_t mSrcRowStride;
        /// Size of each slice in destination including padding - Use for offsetting dst data updating 3D textures
        uint32_t mDstSliceStride;
        /// Size of each slice in src - Use for offsetting src data when updating 3D textures
        uint32_t mSrcSliceStride;
        /// To be filled by the caller
        /// Example:
        /// BufferUpdateDesc update = { pTexture, 2, 1 };
        /// beginUpdateResource(&update);
        /// Row by row copy is required if mDstRowStride > mSrcRowStride. Single memcpy will work if mDstRowStride == mSrcRowStride
        /// 2D
        /// for (uint32_t r = 0; r < update.mRowCount; ++r)
        ///     memcpy(update.pMappedData + r * update.mDstRowStride, srcPixels + r * update.mSrcRowStride, update.mSrcRowStride);
        /// 3D
        /// for (uint32_t z = 0; z < depth; ++z)
        /// {
        ///     uint8_t* dstData = update.pMappedData + update.mDstSliceStride * z;
        ///     uint8_t* srcData = srcPixels + update.mSrcSliceStride * z;
        ///     for (uint32_t r = 0; r < update.mRowCount; ++r)
        ///         memcpy(dstData + r * update.mDstRowStride, srcData + r * update.mSrcRowStride, update.mSrcRowStride);
        /// }
        /// endUpdateResource(&update, &token);
        uint8_t* pMappedData;
    } ztf_TextureSubresourceUpdate;

    /// #NOTE: Only use for procedural textures which are created on CPU (noise textures, font texture, ...)
    typedef struct ztf_TextureUpdateDesc
    {
        ztf_Texture* pTexture;
        uint32_t      mBaseMipLevel;
        uint32_t      mMipLevels;
        uint32_t      mBaseArrayLayer;
        uint32_t      mLayerCount;
        ztf_ResourceState mCurrentState;
        // Optional - If we want to run the update on user specified command buffer instead
        ztf_Cmd* pCmd;

        /// Internal
        struct
        {
            ztf_MappedMemoryRange mMappedRange;
            uint32_t          mDstSliceStride;
            bool              mSkipBarrier;
        } mInternal;
    } ztf_TextureUpdateDesc;

    ZTF_C_RENDERER_API ztf_TextureSubresourceUpdate getSubresourceUpdateDesc(ztf_TextureUpdateDesc* self, uint32_t mip, uint32_t layer);

    typedef struct ztf_TextureCopyDesc
    {
        ztf_Texture* pTexture;
        ztf_Buffer* pBuffer;
        /// Semaphore to synchronize graphics/compute operations that write to the texture with the texture -> buffer copy.
        ztf_Semaphore* pWaitSemaphore;
        uint32_t      mTextureMipLevel;
        uint32_t      mTextureArrayLayer;
        /// Current texture state.
        ztf_ResourceState mTextureState;
        /// Queue the texture is copied from.
        ztf_QueueType     mQueueType;
        uint64_t      mBufferOffset;
    } ztf_TextureCopyDesc;

    typedef struct ztf_ShaderStageLoadDesc
    { //-V802 : Very user-facing struct, and order is highly important to convenience
        const char* pFileName;
        const char* pEntryPointName;
    } ztf_ShaderStageLoadDesc;

    typedef struct ztf_ShaderLoadDesc
    {
        ztf_ShaderStageLoadDesc   mStages[ZTF_SHADER_STAGE_COUNT];
        const ztf_ShaderConstant* pConstants;
        uint32_t              mConstantCount;
    } ztf_ShaderLoadDesc;

    typedef struct ztf_PipelineCacheLoadDesc
    {
        const char* pFileName;
        ztf_PipelineCacheFlags mFlags;
    } ztf_PipelineCacheLoadDesc;

    typedef struct ztf_PipelineCacheSaveDesc
    {
        const char* pFileName;
    } ztf_PipelineCacheSaveDesc;

    typedef uint64_t ztf_SyncToken;

    typedef struct ztf_Material ztf_Material;

    typedef struct ztf_ResourceLoaderDesc
    {
        uint64_t mBufferSize;
        uint32_t mBufferCount;
        bool     mSingleThreaded;
#ifdef ENABLE_FORGE_MATERIALS
        bool mUseMaterials;
#endif
    } ztf_ResourceLoaderDesc;

    ZTF_C_RENDERER_API ztf_ResourceLoaderDesc* ztf_getDefaultResourceLoaderDesc();

    // MARK: - Resource Loader Functions

    ZTF_C_RENDERER_API void ztf_initResourceLoaderInterface(ztf_Renderer* pRenderer, ztf_ResourceLoaderDesc* pDesc);
    ZTF_C_RENDERER_API void ztf_exitResourceLoaderInterface(ztf_Renderer* pRenderer);

    /// Multiple Renderer (unlinked GPU) variants. The Resource Loader must be shared between Renderers.
    ZTF_C_RENDERER_API void ztf_initResourceLoaderInterface2(ztf_Renderer** ppRenderers, uint32_t rendererCount, ztf_ResourceLoaderDesc* pDesc);
    ZTF_C_RENDERER_API void ztf_exitResourceLoaderInterface2(ztf_Renderer** ppRenderers, uint32_t rendererCount);

    // MARK: App Material Management
#ifdef ENABLE_FORGE_MATERIALS

// Will load a material and all related shaders/textures (if they are not already loaded, Material shaders/textures are shared across all
// Materials)
    ZTF_C_RENDERER_API uint32_t ztf_addMaterial(const char* pMaterialFileName, ztf_Material** pMaterial, ztf_SyncToken* pSyncToken);
    // Will unload all the related shaders/textures (if they are not still used by some other Material)
    ZTF_C_RENDERER_API void     ztf_removeMaterial(ztf_Material* pMaterial);

    // TODO: Functions below are a simple interface to get resources from materials, as we develop materials further this interface will
    // probably change.
    ZTF_C_RENDERER_API uint32_t ztf_getMaterialSetIndex(ztf_Material* pMaterial, const char* name);
    ZTF_C_RENDERER_API void     ztf_getMaterialShader(ztf_Material* pMaterial, uint32_t materialSetIndex, ztf_Shader** ppOutShader);
    ZTF_C_RENDERER_API void     ztf_getMaterialTextures(ztf_Material* pMaterial, uint32_t materialSetIndex, const char** ppOutTextureBindingNames,
                                                    ztf_Texture** ppOutTextures, uint32_t outTexturesSize);

#endif // ENABLE_FORGE_MATERIALS

    // MARK: addResource and updateResource

    ZTF_C_RENDERER_API void ztf_getResourceSizeAlign(const ztf_BufferLoadDesc* pDesc, ztf_ResourceSizeAlign* pOut);
    ZTF_C_RENDERER_API void ztf_getResourceSizeAlign2(const ztf_TextureLoadDesc* pDesc, ztf_ResourceSizeAlign* pOut);

    /// Adding and updating resources can be done using a addResource or
    /// beginUpdateResource/endUpdateResource pair.
    /// if addResource(BufferLoadDesc) is called with a data size larger than the ResourceLoader's staging buffer, the ResourceLoader
    /// will perform multiple copies/flushes rather than failing the copy.

    /// If token is NULL, the resource will be available when allResourceLoadsCompleted() returns true.
    /// If token is non NULL, the resource will be available after isTokenCompleted(token) returns true.
    ZTF_C_RENDERER_API void ztf_addResource(ztf_BufferLoadDesc* pBufferDesc, ztf_SyncToken* token);
    ZTF_C_RENDERER_API void ztf_addResource2(ztf_TextureLoadDesc* pTextureDesc, ztf_SyncToken* token);
    ZTF_C_RENDERER_API void ztf_addResource3(ztf_GeometryLoadDesc* pGeomDesc, ztf_SyncToken* token);
    ZTF_C_RENDERER_API void ztf_addGeometryBuffer(ztf_GeometryBufferLoadDesc* pDesc);

    ZTF_C_RENDERER_API void ztf_beginUpdateResource(ztf_BufferUpdateDesc* pBufferDesc);
    ZTF_C_RENDERER_API void ztf_beginUpdateResource2(ztf_TextureUpdateDesc* pTextureDesc);
    ZTF_C_RENDERER_API void ztf_endUpdateResource(ztf_BufferUpdateDesc* pBuffer);
    ZTF_C_RENDERER_API void ztf_endUpdateResource2(ztf_TextureUpdateDesc* pTexture);

    /// This function is used to acquire geometry buffer location.
    /// It can be used on index or vertex buffer
    /// When there are no continious chunk with enough size, output chunk contains 0 size.
    /// Use releaseGeometryBufferPart to release chunk.
    /// Make sure all chunks are released before removeGeometryBuffer.
    ZTF_C_RENDERER_API void ztf_addGeometryBufferPart(ztf_BufferChunkAllocator* buffer, uint32_t size, uint32_t alignment, ztf_BufferChunk* pOut,
                                                  ztf_BufferChunk* pPreferredChunk);

    /// Release previously claimed chunk to buffer.
    /// Buffer must be the one passed to claimGeometryBufferPart for this chunk.
    ZTF_C_RENDERER_API void ztf_removeGeometryBufferPart(ztf_BufferChunkAllocator* buffer, ztf_BufferChunk* chunk);

    typedef struct ztf_FlushResourceUpdateDesc
    {
        uint32_t    mNodeIndex;
        uint32_t    mWaitSemaphoreCount;
        ztf_Semaphore** ppWaitSemaphores;
        ztf_Fence* pOutFence;
        ztf_Semaphore* pOutSubmittedSemaphore;
    } ztf_FlushResourceUpdateDesc;
    ZTF_C_RENDERER_API void ztf_flushResourceUpdates(ztf_FlushResourceUpdateDesc* pDesc);

    /// Copies data from GPU to the CPU, typically for transferring it to another GPU in unlinked mode.
    /// For optimal use, the amount of data to transfer should be minimized as much as possible and applications should
    /// provide additional graphics/compute work that the GPU can execute alongside the copy.
    ZTF_C_RENDERER_API void ztf_copyResource(ztf_TextureCopyDesc* pTextureDesc, ztf_SyncToken* token);

    // MARK: removeResource

    ZTF_C_RENDERER_API void ztf_removeResource(ztf_Buffer* pBuffer);
    ZTF_C_RENDERER_API void ztf_removeResource2(ztf_Texture* pTexture);
    ZTF_C_RENDERER_API void ztf_removeResource3(ztf_Geometry* pGeom);
    ZTF_C_RENDERER_API void ztf_removeResource4(ztf_GeometryData* pGeom);
    ZTF_C_RENDERER_API void ztf_removeGeometryBuffer(ztf_GeometryBuffer* pGeomBuffer);
    // Frees pGeom->pShadow in case it was requested with GEOMETRY_LOAD_FLAG_SHADOWED and you are already done with it
    ZTF_C_RENDERER_API void ztf_removeGeometryShadowData(ztf_GeometryData* pGeom);

    // MARK: Waiting for Loads

    /// Returns whether all submitted resource loads and updates have been completed.
    ZTF_C_RENDERER_API bool ztf_allResourceLoadsCompleted();

    /// Blocks the calling thread until allResourceLoadsCompleted() returns true.
    /// Note that if more resource loads or updates are submitted from a different thread while
    /// while the calling thread is blocked, those loads or updates are not guaranteed to have
    /// completed when this function returns.
    ZTF_C_RENDERER_API void ztf_waitForAllResourceLoads();

    /// Wait for the copy queue to finish all work
    ZTF_C_RENDERER_API void ztf_waitCopyQueueIdle();

    /// Returns wheter the resourceloader is single threaded or not
    ZTF_C_RENDERER_API bool ztf_isResourceLoaderSingleThreaded();

    /// A SyncToken is an array of monotonically increasing integers.
    /// getLastTokenCompleted() returns the last value for which
    /// isTokenCompleted(token) is guaranteed to return true.
    ZTF_C_RENDERER_API ztf_SyncToken ztf_getLastTokenCompleted();
    ZTF_C_RENDERER_API bool      ztf_isTokenCompleted(const ztf_SyncToken* token);
    ZTF_C_RENDERER_API void      ztf_waitForToken(const ztf_SyncToken* token);

    /// Allows clients to synchronize with the submission of copy commands (as opposed to their completion).
    /// This can reduce the wait time for clients but requires using the Semaphore from getLastSemaphoreCompleted() in a wait
    /// operation in a submit that uses the textures just updated.
    ZTF_C_RENDERER_API ztf_SyncToken ztf_getLastTokenSubmitted();
    ZTF_C_RENDERER_API bool      ztf_isTokenSubmitted(const ztf_SyncToken* token);
    ZTF_C_RENDERER_API void      ztf_waitForTokenSubmitted(const ztf_SyncToken* token);

    /// Return the semaphore for the last copy operation of a specific GPU.
    /// Could be NULL if no operations have been executed.
    ZTF_C_RENDERER_API ztf_Semaphore* ztf_getLastSemaphoreSubmitted(uint32_t nodeIndex);

    /// Either loads the cached shader bytecode or compiles the shader to create new bytecode depending on whether source is newer than binary
    ZTF_C_RENDERER_API void ztf_addShader(ztf_Renderer* pRenderer, const ztf_ShaderLoadDesc* pDesc, ztf_Shader** pShader);

    /// Save/Load pipeline cache from disk
    ZTF_C_RENDERER_API void ztf_loadPipelineCache(ztf_Renderer* pRenderer, const ztf_PipelineCacheLoadDesc* pDesc, ztf_PipelineCache** ppPipelineCache);
    ZTF_C_RENDERER_API void ztf_savePipelineCache(ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache, ztf_PipelineCacheSaveDesc* pDesc);

    /// Determines whether we are using Uniform Memory Architecture or not.
    /// Do not assume this variable will be the same, if code was compiled with multiple APIs result of this function might change per API.
    ZTF_C_RENDERER_API bool ztf_isUma();

#ifdef __cplusplus
} // extern "C"
#endif