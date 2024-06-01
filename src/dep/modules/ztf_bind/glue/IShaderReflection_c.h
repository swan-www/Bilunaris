#pragma once

//Only to be incldued via IGraphics_c.h

#ifdef __cplusplus
extern "C"
{
#endif

    static const uint32_t ZTF_MAX_SHADER_STAGE_COUNT = 5;

    typedef enum ztf_TextureDimension
    {
        ZTF_TEXTURE_DIM_1D,
        ZTF_TEXTURE_DIM_2D,
        ZTF_TEXTURE_DIM_2DMS,
        ZTF_TEXTURE_DIM_3D,
        ZTF_TEXTURE_DIM_CUBE,
        ZTF_TEXTURE_DIM_1D_ARRAY,
        ZTF_TEXTURE_DIM_2D_ARRAY,
        ZTF_TEXTURE_DIM_2DMS_ARRAY,
        ZTF_TEXTURE_DIM_CUBE_ARRAY,
        ZTF_TEXTURE_DIM_COUNT,
        ZTF_TEXTURE_DIM_UNDEFINED,
    } ztf_TextureDimension;

    typedef struct ztf_VertexInput
    {
        // resource name
        const char* name;

        // The size of the attribute
        uint32_t size;

        // name size
        uint32_t name_size;
    } ztf_VertexInput;

#if defined(METAL)
    typedef struct ztf_ArgumentDescriptor
    {
        MTLDataType     mDataType;
        uint32_t        mBufferIndex;
        uint32_t        mArgumentIndex;
        uint32_t        mArrayLength;
        MTL_ACCESS_TYPE mAccessType;
        MTLTextureType  mTextureType;
        size_t          mAlignment;
    } ztf_ArgumentDescriptor;
#endif

    typedef struct ztf_ShaderResource
    {
        // resource Type
        ztf_DescriptorType type;

        // The resource set for binding frequency
        uint32_t set;

        // The resource binding location
        uint32_t reg;

        // The size of the resource. This will be the DescriptorInfo array size for textures
        uint32_t size;

        // what stages use this resource
        ztf_ShaderStage used_stages;

        // resource name
        const char* name;

        // name size
        uint32_t name_size;

        // 1D / 2D / Array / MSAA / ...
        ztf_TextureDimension dim;

#if defined(METAL)
        uint32_t           alignment;
        bool               mIsArgumentBufferField;
        ArgumentDescriptor mArgumentDescriptor;
#endif
    } ztf_ShaderResource;

    typedef struct ztf_ShaderVariable
    {
        // Variable name
        const char* name;

        // parents resource index
        uint32_t parent_index;

        // The offset of the Variable.
        uint32_t offset;

        // The size of the Variable.
        uint32_t size;

        // name size
        uint32_t name_size;

#if defined(GLES)
        GLenum type; // Needed to use the right glUniform(i) function to upload the data
#endif
    } ztf_ShaderVariable;

    typedef struct ztf_ShaderReflection
    {
        // single large allocation for names to reduce number of allocations
        char* pNamePool;
        ztf_VertexInput* pVertexInputs;
        ztf_ShaderResource* pShaderResources;
        ztf_ShaderVariable* pVariables;

#if defined(VULKAN)
        char* pEntryPoint;
#endif

        ztf_ShaderStage mShaderStage;

        uint32_t mNamePoolSize;
        uint32_t mVertexInputsCount;
        uint32_t mShaderResourceCount;
        uint32_t mVariableCount;

        // Thread group size for compute shader
        uint32_t mNumThreadsPerGroup[3];

        uint32_t mOutputRenderTargetTypesMask;

        // number of tessellation control point
        uint32_t mNumControlPoint;
    } ztf_ShaderReflection;

    typedef struct ztf_PipelineReflection
    {
        ztf_ShaderStage      mShaderStages;
        // the individual stages reflection data.
        ztf_ShaderReflection mStageReflections[ZTF_MAX_SHADER_STAGE_COUNT];
        uint32_t         mStageReflectionCount;

        uint32_t mVertexStageIndex;
        uint32_t mHullStageIndex;
        uint32_t mDomainStageIndex;
        uint32_t mGeometryStageIndex;
        uint32_t mPixelStageIndex;

        ztf_ShaderResource* pShaderResources;
        uint32_t        mShaderResourceCount;

        ztf_ShaderVariable* pVariables;
        uint32_t        mVariableCount;
    } ztf_PipelineReflection;

    ZTF_C_RENDERER_API void ztf_destroyShaderReflection(ztf_ShaderReflection* pReflection);

    ZTF_C_RENDERER_API void ztf_createPipelineReflection(ztf_ShaderReflection* pReflection, uint32_t stageCount, ztf_PipelineReflection* pOutReflection);
    ZTF_C_RENDERER_API void ztf_destroyPipelineReflection(ztf_PipelineReflection* pReflection);

    ZTF_C_RENDERER_API bool ztf_isDescriptorRootConstant(const char* resourceName);
    ZTF_C_RENDERER_API bool ztf_isDescriptorRootCbv(const char* resourceName);

#ifdef __cplusplus
}
#endif