#pragma once

#include <stdint.h>
#include <stdbool.h> 

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/tinyimageformat/tinyimageformat_base.h"

#include "Config_c.h"
#include "GraphicsConfig_c.h"

#include "IOperatingSystem_c.h"
#include "ILog_c.h"
//#include "IThread_c.h"

typedef struct Mutex Mutex;
typedef struct PipelineReflection PipelineReflection;

    //
    // default capability levels of the renderer
    //
#if !defined(RENDERER_CUSTOM_MAX)
    enum
    {
        ZTF_MAX_INSTANCE_EXTENSIONS = 64,
        ZTF_MAX_DEVICE_EXTENSIONS = 64,
        /// Max number of GPUs in SLI or Cross-Fire
        ZTF_MAX_LINKED_GPUS = 4,
        /// Max number of GPUs in unlinked mode
        ZTF_MAX_UNLINKED_GPUS = 4,
        /// Max number of GPus for either linked or unlinked mode. must update WindowsBase::setupPlatformUI accordingly
        ZTF_MAX_MULTIPLE_GPUS = 4,
        ZTF_MAX_RENDER_TARGET_ATTACHMENTS = 8,
        ZTF_MAX_VERTEX_BINDINGS = 15,
        ZTF_MAX_VERTEX_ATTRIBS = 15,
        ZTF_MAX_RESOURCE_NAME_LENGTH = 256,
        ZTF_MAX_SEMANTIC_NAME_LENGTH = 128,
        ZTF_MAX_DEBUG_NAME_LENGTH = 128,
        ZTF_MAX_MIP_LEVELS = 0xFFFFFFFF,
        ZTF_MAX_SWAPCHAIN_IMAGES = 3,
        ZTF_MAX_GPU_VENDOR_STRING_LENGTH = 256, // max size for GPUVendorPreset strings
        ZTF_MAX_SAMPLE_LOCATIONS = 16,
#if defined(VULKAN)
        ZTF_MAX_PLANE_COUNT = 3,
        ZTF_MAX_DESCRIPTOR_POOL_SIZE_ARRAY_COUNT = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT + 1,
#endif
    };
#endif

#ifdef DIRECT3D12
#ifndef D3D12MAAllocator
    // Forward declare opaque memory allocator structs
    typedef struct D3D12MAAllocator  D3D12MAAllocator;
    typedef struct D3D12MAAllocation D3D12MAAllocation;
#endif
    typedef int32_t DxDescriptorID;
#endif

#if defined(ORBIS)
#include "../../../PS4/Common_3/Graphics/Gnm/GnmStructs.h"
#endif
#if defined(PROSPERO)
#include "../../../Prospero/Common_3/Graphics/Agc/AgcStructs.h"
#endif
#if defined(Xbox)
#include "../../../Xbox/Common_3/Graphics/Direct3D12/Direct3D12X.h"
#endif

    typedef enum ztf_RendererApi
    {
#if defined(GLES)
        ZTF_RENDERER_API_GLES,
#endif
#if defined(DIRECT3D12)
        ZTF_RENDERER_API_D3D12,
#endif
#if defined(VULKAN)
        ZTF_RENDERER_API_VULKAN,
#endif
#if defined(DIRECT3D11)
        ZTF_RENDERER_API_D3D11,
#endif
#if defined(METAL)
        ZTF_RENDERER_API_METAL,
#endif
#if defined(ORBIS)
        ZTF_RENDERER_API_ORBIS,
#endif
#if defined(PROSPERO)
        ZTF_RENDERER_API_PROSPERO,
#endif
        ZTF_RENDERER_API_COUNT
    } ztf_RendererApi;

    typedef enum ztf_QueueType
    {
        ZTF_QUEUE_TYPE_GRAPHICS = 0,
        ZTF_QUEUE_TYPE_TRANSFER,
        ZTF_QUEUE_TYPE_COMPUTE,
        ZTF_MAX_QUEUE_TYPE
    } ztf_QueueType;

    typedef enum ztf_QueueFlag
    {
        ZTF_QUEUE_FLAG_NONE = 0x0,
        ZTF_QUEUE_FLAG_DISABLE_GPU_TIMEOUT = 0x1,
        ZTF_QUEUE_FLAG_INIT_MICROPROFILE = 0x2,
        ZTF_MAX_QUEUE_FLAG = 0xFFFFFFFF
    } ztf_QueueFlag;

    typedef enum ztf_QueuePriority
    {
        ZTF_QUEUE_PRIORITY_NORMAL,
        ZTF_QUEUE_PRIORITY_HIGH,
        ZTF_QUEUE_PRIORITY_GLOBAL_REALTIME,
        ZTF_MAX_QUEUE_PRIORITY
    } ztf_QueuePriority;

    typedef enum ztf_LoadActionType
    {
        ZTF_LOAD_ACTION_DONTCARE,
        ZTF_LOAD_ACTION_LOAD,
        ZTF_LOAD_ACTION_CLEAR,
        ZTF_MAX_LOAD_ACTION
    } ztf_LoadActionType;

    typedef enum ztf_StoreActionType
    {
        // Store is the most common use case so keep that as default
        ZTF_STORE_ACTION_STORE,
        ZTF_STORE_ACTION_DONTCARE,
        ZTF_STORE_ACTION_NONE,
#if defined(USE_MSAA_RESOLVE_ATTACHMENTS)
        // Resolve into pResolveAttachment and also store the MSAA attachment (rare - maybe used for debug)
        ZTF_STORE_ACTION_RESOLVE_STORE,
        // Resolve into pResolveAttachment and discard MSAA attachment (most common use case for resolve)
        ZTF_STORE_ACTION_RESOLVE_DONTCARE,
#endif
        ZTF_MAX_STORE_ACTION
    } ztf_StoreActionType;

    typedef void (*ztf_LogFn)(ztf_LogLevel, const char*, const char*);

    typedef enum ztf_ResourceState
    {
        ZTF_RESOURCE_STATE_UNDEFINED = 0,
        ZTF_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER = 0x1,
        ZTF_RESOURCE_STATE_INDEX_BUFFER = 0x2,
        ZTF_RESOURCE_STATE_RENDER_TARGET = 0x4,
        ZTF_RESOURCE_STATE_UNORDERED_ACCESS = 0x8,
        ZTF_RESOURCE_STATE_DEPTH_WRITE = 0x10,
        ZTF_RESOURCE_STATE_DEPTH_READ = 0x20,
        ZTF_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE = 0x40,
        ZTF_RESOURCE_STATE_PIXEL_SHADER_RESOURCE = 0x80,
        ZTF_RESOURCE_STATE_SHADER_RESOURCE = 0x40 | 0x80,
        ZTF_RESOURCE_STATE_STREAM_OUT = 0x100,
        ZTF_RESOURCE_STATE_INDIRECT_ARGUMENT = 0x200,
        ZTF_RESOURCE_STATE_COPY_DEST = 0x400,
        ZTF_RESOURCE_STATE_COPY_SOURCE = 0x800,
        ZTF_RESOURCE_STATE_GENERIC_READ = (((((0x1 | 0x2) | 0x40) | 0x80) | 0x200) | 0x800),
        ZTF_RESOURCE_STATE_PRESENT = 0x1000,
        ZTF_RESOURCE_STATE_COMMON = 0x2000,
        ZTF_RESOURCE_STATE_ACCELERATION_STRUCTURE_READ = 0x4000,
        ZTF_RESOURCE_STATE_ACCELERATION_STRUCTURE_WRITE = 0x8000,
#if defined(QUEST_VR)
        ZTF_RESOURCE_STATE_SHADING_RATE_SOURCE = 0x10000,
#endif
    } ztf_ResourceState;

    /// Choosing Memory Type
    typedef enum ztf_ResourceMemoryUsage
    {
        /// No intended memory usage specified.
        ZTF_RESOURCE_MEMORY_USAGE_UNKNOWN = 0,
        /// Memory will be used on device only, no need to be mapped on host.
        ZTF_RESOURCE_MEMORY_USAGE_GPU_ONLY = 1,
        /// Memory will be mapped on host. Could be used for transfer to device.
        ZTF_RESOURCE_MEMORY_USAGE_CPU_ONLY = 2,
        /// Memory will be used for frequent (dynamic) updates from host and reads on device.
        ZTF_RESOURCE_MEMORY_USAGE_CPU_TO_GPU = 3,
        /// Memory will be used for writing on device and readback on host.
        ZTF_RESOURCE_MEMORY_USAGE_GPU_TO_CPU = 4,
        ZTF_RESOURCE_MEMORY_USAGE_COUNT,
        ZTF_RESOURCE_MEMORY_USAGE_MAX_ENUM = 0x7FFFFFFF
    } ztf_ResourceMemoryUsage;

    typedef struct ztf_PlatformParameters
    {
        // RendererAPI
        ztf_RendererApi mSelectedRendererApi;
        // Available GPU capabilities
        char        ppAvailableGpuNames[ZTF_MAX_MULTIPLE_GPUS][ZTF_MAX_GPU_VENDOR_STRING_LENGTH];
        uint32_t    pAvailableGpuIds[ZTF_MAX_MULTIPLE_GPUS];
        uint32_t    mAvailableGpuCount;
        uint32_t    mSelectedGpuIndex;
        // Could add swap chain size, render target format, ...
        uint32_t    mPreferedGpuId;
    } ztf_PlatformParameters;

    // Forward declarations
    typedef struct ztf_RendererContext      ztf_RendererContext;
    typedef struct ztf_Renderer             ztf_Renderer;
    typedef struct ztf_Queue                ztf_Queue;
    typedef struct ztf_Pipeline             ztf_Pipeline;
    typedef struct ztf_Buffer               ztf_Buffer;
    typedef struct ztf_Texture              ztf_Texture;
    typedef struct ztf_RenderTarget         ztf_RenderTarget;
    typedef struct ztf_Shader               ztf_Shader;
    typedef struct ztf_RootSignature        ztf_RootSignature;
    typedef struct ztf_DescriptorSet        ztf_DescriptorSet;
    typedef struct ztf_DescriptorIndexMap   ztf_DescriptorIndexMap;
    typedef struct ztf_PipelineCache        ztf_PipelineCache;

    // Raytracing
    typedef struct ztf_Raytracing            ztf_Raytracing;
    typedef struct ztf_RaytracingHitGroup    ztf_RaytracingHitGroup;
    typedef struct ztf_AccelerationStructure ztf_AccelerationStructure;

    typedef struct ztf_EsramManager ztf_EsramManager;

    typedef struct ztf_IndirectDrawArguments
    {
        uint32_t mVertexCount;
        uint32_t mInstanceCount;
        uint32_t mStartVertex;
        uint32_t mStartInstance;
    } ztf_IndirectDrawArguments;

    typedef struct ztf_IndirectDrawIndexArguments
    {
        uint32_t mIndexCount;
        uint32_t mInstanceCount;
        uint32_t mStartIndex;
        uint32_t mVertexOffset;
        uint32_t mStartInstance;
    } ztf_IndirectDrawIndexArguments;

    typedef struct ztf_IndirectDispatchArguments
    {
        uint32_t mGroupCountX;
        uint32_t mGroupCountY;
        uint32_t mGroupCountZ;
    } ztf_IndirectDispatchArguments;

#define ZTF_INDIRECT_DRAW_ELEM_INDEX(m)       (offsetof(ztf_IndirectDrawArguments, m) / sizeof(uint32_t))
#define ZTF_INDIRECT_DRAW_INDEX_ELEM_INDEX(m) (offsetof(ztf_IndirectDrawIndexArguments, m) / sizeof(uint32_t))
#define ZTF_INDIRECT_DISPATCH_ELEM_INDEX(m)   (offsetof(ztf_IndirectDispatchArguments, m) / sizeof(uint32_t))

    typedef enum ztf_IndirectArgumentType
    {
        ZTF_INDIRECT_ARG_INVALID,
        ZTF_INDIRECT_DRAW,
        ZTF_INDIRECT_DRAW_INDEX,
        ZTF_INDIRECT_DISPATCH,
        ZTF_INDIRECT_VERTEX_BUFFER,
        ZTF_INDIRECT_INDEX_BUFFER,
        ZTF_INDIRECT_CONSTANT,
        ZTF_INDIRECT_CONSTANT_BUFFER_VIEW,   // only for dx
        ZTF_INDIRECT_SHADER_RESOURCE_VIEW,   // only for dx
        ZTF_INDIRECT_UNORDERED_ACCESS_VIEW,  // only for dx
        ZTF_INDIRECT_COMMAND_BUFFER,         // metal ICB
        ZTF_INDIRECT_COMMAND_BUFFER_RESET,   // metal ICB reset
        ZTF_INDIRECT_COMMAND_BUFFER_OPTIMIZE // metal ICB optimization
    } ztf_IndirectArgumentType;
    /************************************************/

    typedef enum ztf_DescriptorType
    {
        ZTF_DESCRIPTOR_TYPE_UNDEFINED = 0,
        ZTF_DESCRIPTOR_TYPE_SAMPLER = 0x01,
        // SRV Read only texture
        ZTF_DESCRIPTOR_TYPE_TEXTURE = (ZTF_DESCRIPTOR_TYPE_SAMPLER << 1),
        /// UAV Texture
        ZTF_DESCRIPTOR_TYPE_RW_TEXTURE = (ZTF_DESCRIPTOR_TYPE_TEXTURE << 1),
        // SRV Read only buffer
        ZTF_DESCRIPTOR_TYPE_BUFFER = (ZTF_DESCRIPTOR_TYPE_RW_TEXTURE << 1),
        ZTF_DESCRIPTOR_TYPE_BUFFER_RAW = (ZTF_DESCRIPTOR_TYPE_BUFFER | (ZTF_DESCRIPTOR_TYPE_BUFFER << 1)),
        /// UAV Buffer
        ZTF_DESCRIPTOR_TYPE_RW_BUFFER = (ZTF_DESCRIPTOR_TYPE_BUFFER << 2),
        ZTF_DESCRIPTOR_TYPE_RW_BUFFER_RAW = (ZTF_DESCRIPTOR_TYPE_RW_BUFFER | (ZTF_DESCRIPTOR_TYPE_RW_BUFFER << 1)),
        /// Uniform buffer
        ZTF_DESCRIPTOR_TYPE_UNIFORM_BUFFER = (ZTF_DESCRIPTOR_TYPE_RW_BUFFER << 2),
        /// Push constant / Root constant
        ZTF_DESCRIPTOR_TYPE_ROOT_CONSTANT = (ZTF_DESCRIPTOR_TYPE_UNIFORM_BUFFER << 1),
        /// IA
        ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER = (ZTF_DESCRIPTOR_TYPE_ROOT_CONSTANT << 1),
        ZTF_DESCRIPTOR_TYPE_INDEX_BUFFER = (ZTF_DESCRIPTOR_TYPE_VERTEX_BUFFER << 1),
        ZTF_DESCRIPTOR_TYPE_INDIRECT_BUFFER = (ZTF_DESCRIPTOR_TYPE_INDEX_BUFFER << 1),
        /// Cubemap SRV
        ZTF_DESCRIPTOR_TYPE_TEXTURE_CUBE = (ZTF_DESCRIPTOR_TYPE_TEXTURE | (ZTF_DESCRIPTOR_TYPE_INDIRECT_BUFFER << 1)),
        /// RTV / DSV per mip slice
        ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_MIP_SLICES = (ZTF_DESCRIPTOR_TYPE_INDIRECT_BUFFER << 2),
        /// RTV / DSV per array slice
        ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_ARRAY_SLICES = (ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_MIP_SLICES << 1),
        /// RTV / DSV per depth slice
        ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_DEPTH_SLICES = (ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_ARRAY_SLICES << 1),
        ZTF_DESCRIPTOR_TYPE_INDIRECT_COMMAND_BUFFER = (ZTF_DESCRIPTOR_TYPE_RENDER_TARGET_DEPTH_SLICES << 1),
        /// Raytracing acceleration structure
        ZTF_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE = (ZTF_DESCRIPTOR_TYPE_INDIRECT_COMMAND_BUFFER << 1),
#if defined(VULKAN)
        /// Subpass input (descriptor type only available in Vulkan)
        ZTF_DESCRIPTOR_TYPE_INPUT_ATTACHMENT = (ZTF_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE << 1),
        ZTF_DESCRIPTOR_TYPE_TEXEL_BUFFER = (ZTF_DESCRIPTOR_TYPE_INPUT_ATTACHMENT << 1),
        ZTF_DESCRIPTOR_TYPE_RW_TEXEL_BUFFER = (ZTF_DESCRIPTOR_TYPE_TEXEL_BUFFER << 1),
        ZTF_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = (ZTF_DESCRIPTOR_TYPE_RW_TEXEL_BUFFER << 1),
#endif
    } ztf_DescriptorType;

    typedef enum ztf_SampleCount
    {
        ZTF_SAMPLE_COUNT_1 = 1,
        ZTF_SAMPLE_COUNT_2 = 2,
        ZTF_SAMPLE_COUNT_4 = 4,
        ZTF_SAMPLE_COUNT_8 = 8,
        ZTF_SAMPLE_COUNT_16 = 16,
        ZTF_SAMPLE_COUNT_COUNT = 5,
    } ztf_SampleCount;

#ifdef METAL
    typedef enum ztf_ShaderStage
    {
        ZTF_SHADER_STAGE_NONE = 0,
        ZTF_SHADER_STAGE_VERT = 0X00000001,
        ZTF_SHADER_STAGE_FRAG = 0X00000002,
        ZTF_SHADER_STAGE_COMP = 0X00000004,
        ZTF_SHADER_STAGE_ALL_GRAPHICS = ((uint32_t)ZTF_SHADER_STAGE_VERT | (uint32_t)ZTF_SHADER_STAGE_FRAG),
        ZTF_SHADER_STAGE_COUNT = 3,
    } ztf_ShaderStage;

    typedef enum ztf_ShaderStageIndex
    {
        ZTF_SHADER_STAGE_INDEX_VERT = 0,
        ZTF_SHADER_STAGE_INDEX_FRAG,
        ZTF_SHADER_STAGE_INDEX_COMP,
    } ztf_ShaderStageIndex;
#else
    typedef enum ztf_ShaderStage
    {
        ZTF_SHADER_STAGE_NONE = 0,
        ZTF_SHADER_STAGE_VERT = 0X00000001,
        ZTF_SHADER_STAGE_TESC = 0X00000002,
        ZTF_SHADER_STAGE_TESE = 0X00000004,
        ZTF_SHADER_STAGE_GEOM = 0X00000008,
        ZTF_SHADER_STAGE_FRAG = 0X00000010,
        ZTF_SHADER_STAGE_COMP = 0X00000020,
        ZTF_SHADER_STAGE_ALL_GRAPHICS = ((uint32_t)ZTF_SHADER_STAGE_VERT | (uint32_t)ZTF_SHADER_STAGE_TESC | (uint32_t)ZTF_SHADER_STAGE_TESE |
        (uint32_t)ZTF_SHADER_STAGE_GEOM | (uint32_t)ZTF_SHADER_STAGE_FRAG),
        ZTF_SHADER_STAGE_HULL = ZTF_SHADER_STAGE_TESC,
        ZTF_SHADER_STAGE_DOMN = ZTF_SHADER_STAGE_TESE,
        ZTF_SHADER_STAGE_COUNT = 6,
    } ztf_ShaderStage;

    typedef enum ztf_ShaderStageIndex
    {
        ZTF_SHADER_STAGE_INDEX_VERT = 0,
        ZTF_SHADER_STAGE_INDEX_TESC,
        ZTF_SHADER_STAGE_INDEX_TESE,
        ZTF_SHADER_STAGE_INDEX_GEOM,
        ZTF_SHADER_STAGE_INDEX_FRAG,
        ZTF_SHADER_STAGE_INDEX_COMP,
        ZTF_SHADER_STAGE_INDEX_HULL = ZTF_SHADER_STAGE_INDEX_TESC,
        ZTF_SHADER_STAGE_INDEX_DOMN = ZTF_SHADER_STAGE_INDEX_TESE,
    } ztf_ShaderStageIndex;
#endif

    // This include is placed here because it uses data types defined previously in this file
    // and forward enums are not allowed for some compilers (Xcode).
#include "IShaderReflection_c.h"

    typedef enum ztf_PrimitiveTopology
    {
        ZTF_PRIMITIVE_TOPO_POINT_LIST = 0,
        ZTF_PRIMITIVE_TOPO_LINE_LIST,
        ZTF_PRIMITIVE_TOPO_LINE_STRIP,
        ZTF_PRIMITIVE_TOPO_TRI_LIST,
        ZTF_PRIMITIVE_TOPO_TRI_STRIP,
        ZTF_PRIMITIVE_TOPO_PATCH_LIST,
        ZTF_PRIMITIVE_TOPO_COUNT,
    } ztf_PrimitiveTopology;

    typedef enum ztf_IndexType
    {
        ZTF_INDEX_TYPE_UINT32 = 0,
        ZTF_INDEX_TYPE_UINT16,
    } ztf_IndexType;

    typedef enum ztf_ShaderSemantic
    {
        ZTF_SEMANTIC_UNDEFINED = 0,
        ZTF_SEMANTIC_POSITION,
        ZTF_SEMANTIC_NORMAL,
        ZTF_SEMANTIC_COLOR,
        ZTF_SEMANTIC_TANGENT,
        ZTF_SEMANTIC_BITANGENT,
        ZTF_SEMANTIC_JOINTS,
        ZTF_SEMANTIC_WEIGHTS,
        ZTF_SEMANTIC_CUSTOM,
        ZTF_SEMANTIC_TEXCOORD0,
        ZTF_SEMANTIC_TEXCOORD1,
        ZTF_SEMANTIC_TEXCOORD2,
        ZTF_SEMANTIC_TEXCOORD3,
        ZTF_SEMANTIC_TEXCOORD4,
        ZTF_SEMANTIC_TEXCOORD5,
        ZTF_SEMANTIC_TEXCOORD6,
        ZTF_SEMANTIC_TEXCOORD7,
        ZTF_SEMANTIC_TEXCOORD8,
        ZTF_SEMANTIC_TEXCOORD9,
        ZTF_MAX_SEMANTICS
    } ztf_ShaderSemantic;

    typedef enum ztf_BlendConstant
    {
        ZTF_BC_ZERO = 0,
        ZTF_BC_ONE,
        ZTF_BC_SRC_COLOR,
        ZTF_BC_ONE_MINUS_SRC_COLOR,
        ZTF_BC_DST_COLOR,
        ZTF_BC_ONE_MINUS_DST_COLOR,
        ZTF_BC_SRC_ALPHA,
        ZTF_BC_ONE_MINUS_SRC_ALPHA,
        ZTF_BC_DST_ALPHA,
        ZTF_BC_ONE_MINUS_DST_ALPHA,
        ZTF_BC_SRC_ALPHA_SATURATE,
        ZTF_BC_BLEND_FACTOR,
        ZTF_BC_ONE_MINUS_BLEND_FACTOR,
        ZTF_MAX_BLEND_CONSTANTS
    } ztf_BlendConstant;

    typedef enum ztf_BlendMode
    {
        ZTF_BM_ADD,
        ZTF_BM_SUBTRACT,
        ZTF_BM_REVERSE_SUBTRACT,
        ZTF_BM_MIN,
        ZTF_BM_MAX,
        ZTF_MAX_BLEND_MODES,
    } ztf_BlendMode;

    typedef enum ztf_CompareMode
    {
        ZTF_CMP_NEVER,
        ZTF_CMP_LESS,
        ZTF_CMP_EQUAL,
        ZTF_CMP_LEQUAL,
        ZTF_CMP_GREATER,
        ZTF_CMP_NOTEQUAL,
        ZTF_CMP_GEQUAL,
        ZTF_CMP_ALWAYS,
        ZTF_MAX_COMPARE_MODES,
    } ztf_CompareMode;

    typedef enum ztf_StencilOp
    {
        ZTF_STENCIL_OP_KEEP,
        ZTF_STENCIL_OP_SET_ZERO,
        ZTF_STENCIL_OP_REPLACE,
        ZTF_STENCIL_OP_INVERT,
        ZTF_STENCIL_OP_INCR,
        ZTF_STENCIL_OP_DECR,
        ZTF_STENCIL_OP_INCR_SAT,
        ZTF_STENCIL_OP_DECR_SAT,
        ZTF_MAX_STENCIL_OPS,
    } ztf_StencilOp;

    typedef enum ztf_ColorMask
    {
        ZTF_COLOR_MASK_NONE = 0x0,
        ZTF_COLOR_MASK_RED = 0x1,
        ZTF_COLOR_MASK_GREEN = 0x2,
        ZTF_COLOR_MASK_BLUE = 0x4,
        ZTF_COLOR_MASK_ALPHA = 0x8,
        ZTF_COLOR_MASK_ALL = (ZTF_COLOR_MASK_RED | ZTF_COLOR_MASK_GREEN | ZTF_COLOR_MASK_BLUE | ZTF_COLOR_MASK_ALPHA),
    } ztf_ColorMask;

    // Blend states are always attached to one of the eight or more render targets that
    // are in a MRT
    // Mask constants
    typedef enum ztf_BlendStateTargets
    {
        ZTF_BLEND_STATE_TARGET_0 = 0x1,
        ZTF_BLEND_STATE_TARGET_1 = 0x2,
        ZTF_BLEND_STATE_TARGET_2 = 0x4,
        ZTF_BLEND_STATE_TARGET_3 = 0x8,
        ZTF_BLEND_STATE_TARGET_4 = 0x10,
        ZTF_BLEND_STATE_TARGET_5 = 0x20,
        ZTF_BLEND_STATE_TARGET_6 = 0x40,
        ZTF_BLEND_STATE_TARGET_7 = 0x80,
        ZTF_BLEND_STATE_TARGET_ALL = 0xFF,
    } ztf_BlendStateTargets;

    typedef enum ztf_CullMode
    {
        ZTF_CULL_MODE_NONE = 0,
        ZTF_CULL_MODE_BACK,
        ZTF_CULL_MODE_FRONT,
        ZTF_CULL_MODE_BOTH,
        ZTF_MAX_CULL_MODES
    } ztf_CullMode;

    typedef enum ztf_FrontFace
    {
        ZTF_FRONT_FACE_CCW = 0,
        ZTF_FRONT_FACE_CW
    } ztf_FrontFace;

    typedef enum ztf_FillMode
    {
        ZTF_FILL_MODE_SOLID,
        ZTF_FILL_MODE_WIREFRAME,
        ZTF_MAX_FILL_MODES
    } ztf_FillMode;

    typedef enum ztf_PipelineType
    {
        ZTF_PIPELINE_TYPE_UNDEFINED = 0,
        ZTF_PIPELINE_TYPE_COMPUTE,
        ZTF_PIPELINE_TYPE_GRAPHICS,
        ZTF_PIPELINE_TYPE_COUNT,
    } ztf_PipelineType;

    typedef enum ztf_FilterType
    {
        ZTF_FILTER_NEAREST = 0,
        ZTF_FILTER_LINEAR,
    } ztf_FilterType;

    typedef enum ztf_AddressMode
    {
        ZTF_ADDRESS_MODE_MIRROR,
        ZTF_ADDRESS_MODE_REPEAT,
        ZTF_ADDRESS_MODE_CLAMP_TO_EDGE,
        ZTF_ADDRESS_MODE_CLAMP_TO_BORDER
    } ztf_AddressMode;

    typedef enum ztf_MipMapMode
    {
        ZTF_MIPMAP_MODE_NEAREST = 0,
        ZTF_MIPMAP_MODE_LINEAR
    } ztf_MipMapMode;

    typedef union ztf_ClearValue
    {
        struct
        {
            float r;
            float g;
            float b;
            float a;
        };
        struct
        {
            float    depth;
            uint32_t stencil;
        };
    } ztf_ClearValue;

    typedef enum ztf_BufferCreationFlags
    {
        /// Default flag (Buffer will use aliased memory, buffer will not be cpu accessible until mapBuffer is called)
        ZTF_BUFFER_CREATION_FLAG_NONE = 0x0,
        /// Buffer will allocate its own memory (COMMITTED resource)
        ZTF_BUFFER_CREATION_FLAG_OWN_MEMORY_BIT = 0x1,
        /// Buffer will be persistently mapped
        ZTF_BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT = 0x2,
        /// Use ESRAM to store this buffer
        ZTF_BUFFER_CREATION_FLAG_ESRAM = 0x4,
        /// Flag to specify not to allocate descriptors for the resource
        ZTF_BUFFER_CREATION_FLAG_NO_DESCRIPTOR_VIEW_CREATION = 0x8,

        ZTF_BUFFER_CREATION_FLAG_ACCELERATION_STRUCTURE_BUILD_INPUT = 0x10,
        ZTF_BUFFER_CREATION_FLAG_SHADER_DEVICE_ADDRESS = 0x20,
        ZTF_BUFFER_CREATION_FLAG_SHADER_BINDING_TABLE = 0x40,
        ZTF_BUFFER_CREATION_FLAG_MARKER = 0x80,
#ifdef VULKAN
        /* Memory Host Flags */
        ZTF_BUFFER_CREATION_FLAG_HOST_COHERENT = 0x100,
        ZTF_BUFFER_CREATION_FLAG_HOST_VISIBLE = 0x200,
#endif

    } ztf_BufferCreationFlags;

    typedef enum ztf_TextureCreationFlags
    {
        /// Default flag (Texture will use default allocation strategy decided by the api specific allocator)
        ZTF_TEXTURE_CREATION_FLAG_NONE = 0,
        /// Texture will allocate its own memory (COMMITTED resource)
        ZTF_TEXTURE_CREATION_FLAG_OWN_MEMORY_BIT = 0x01,
        /// Texture will be allocated in memory which can be shared among multiple processes
        ZTF_TEXTURE_CREATION_FLAG_EXPORT_BIT = 0x02,
        /// Texture will be allocated in memory which can be shared among multiple gpus
        ZTF_TEXTURE_CREATION_FLAG_EXPORT_ADAPTER_BIT = 0x04,
        /// Texture will be imported from a handle created in another process
        ZTF_TEXTURE_CREATION_FLAG_IMPORT_BIT = 0x08,
        /// Use ESRAM to store this texture
        ZTF_TEXTURE_CREATION_FLAG_ESRAM = 0x10,
        /// Use on-tile memory to store this texture
        ZTF_TEXTURE_CREATION_FLAG_ON_TILE = 0x20,
        /// Prevent compression meta data from generating (XBox)
        ZTF_TEXTURE_CREATION_FLAG_NO_COMPRESSION = 0x40,
        /// Force 2D instead of automatically determining dimension based on width, height, depth
        ZTF_TEXTURE_CREATION_FLAG_FORCE_2D = 0x80,
        /// Force 3D instead of automatically determining dimension based on width, height, depth
        ZTF_TEXTURE_CREATION_FLAG_FORCE_3D = 0x100,
        /// Display target
        ZTF_TEXTURE_CREATION_FLAG_ALLOW_DISPLAY_TARGET = 0x200,
        /// Create an sRGB texture.
        ZTF_TEXTURE_CREATION_FLAG_SRGB = 0x400,
        /// Create a normal map texture
        ZTF_TEXTURE_CREATION_FLAG_NORMAL_MAP = 0x800,
        /// Fast clear
        ZTF_TEXTURE_CREATION_FLAG_FAST_CLEAR = 0x1000,
        /// Fragment mask
        ZTF_TEXTURE_CREATION_FLAG_FRAG_MASK = 0x2000,
        /// Doubles the amount of array layers of the texture when rendering VR. Also forces the texture to be a 2D Array texture.
        ZTF_TEXTURE_CREATION_FLAG_VR_MULTIVIEW = 0x4000,
        /// Binds the FFR fragment density if this texture is used as a render target.
        ZTF_TEXTURE_CREATION_FLAG_VR_FOVEATED_RENDERING = 0x8000,
#if defined(USE_MSAA_RESOLVE_ATTACHMENTS)
        /// Creates resolve attachment for auto resolve (MSAA on tiled architecture - Resolve can be done on tile through render pass)
        ZTF_TEXTURE_CREATION_FLAG_CREATE_RESOLVE_ATTACHMENT = 0x10000,
#endif
    } ztf_TextureCreationFlags;

    // Used for swapchain
    typedef enum ztf_ColorSpace
    {
        ZTF_COLOR_SPACE_SDR_LINEAR = 0x0,
        ZTF_COLOR_SPACE_SDR_SRGB,
        ZTF_COLOR_SPACE_P2020,         // BT2020 color space with PQ EOTF
        ZTF_COLOR_SPACE_EXTENDED_SRGB, // Extended sRGB with linear EOTF
    } ztf_ColorSpace;

    // Material Unit test use this enum to index a shader table
    COMPILE_ASSERT(ZTF_GPU_PRESET_COUNT == 7);

    typedef struct ztf_BufferBarrier
    {
        ztf_Buffer* pBuffer;
        ztf_ResourceState mCurrentState;
        ztf_ResourceState mNewState;
		uint8_t mBitfield;
    } ztf_BufferBarrier;

	ZTF_BITFIELD_SETGET_DECLARE(BufferBarrier, BeginOnly, uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(BufferBarrier, EndOnly, uint8_t);

    typedef struct ztf_TextureBarrier
    {
        ztf_Texture* pTexture;
        ztf_ResourceState mCurrentState;
        ztf_ResourceState mNewState;
        uint8_t       mBitfieldOne;
		uint8_t       mBitfieldTwo;
		uint8_t       mBitfieldThree;

        uint16_t      mArrayLayer;
    } ztf_TextureBarrier;

	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, BeginOnly, 			uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, EndOnly, 				uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, Acquire, 				uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, Release, 				uint8_t);

	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, QueueType, 			uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, SubresourceBarrier, 	uint8_t);

	ZTF_BITFIELD_SETGET_DECLARE(TextureBarrier, MipLevel, 			uint8_t);

    typedef struct ztf_RenderTargetBarrier
    {
        ztf_RenderTarget* pRenderTarget;
        ztf_ResourceState mCurrentState;
        ztf_ResourceState mNewState;
        uint8_t       mBitfieldOne;
		uint8_t       mBitfieldTwo;
		uint8_t       mBitfieldThree;
        uint16_t      mArrayLayer;
    } ztf_RenderTargetBarrier;

	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, BeginOnly, 			uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, EndOnly, 				uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, Acquire, 				uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, Release, 				uint8_t);

	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, QueueType, 			uint8_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, SubresourceBarrier, 	uint8_t);

	ZTF_BITFIELD_SETGET_DECLARE(RenderTargetBarrier, MipLevel, 			uint8_t);

    typedef struct ztf_ReadRange
    {
        uint64_t mOffset;
        uint64_t mSize;
    } ztf_ReadRange;

    typedef enum ztf_QueryType
    {
        ZTF_QUERY_TYPE_TIMESTAMP = 0,
        ZTF_QUERY_TYPE_OCCLUSION,
        ZTF_QUERY_TYPE_PIPELINE_STATISTICS,
        ZTF_QUERY_TYPE_COUNT,
    } ztf_QueryType;

    typedef struct ztf_QueryPoolDesc
    {
        const char* pName;
        ztf_QueryType   mType;
        uint32_t    mQueryCount;
        uint32_t    mNodeIndex;
    } ztf_QueryPoolDesc;

    typedef struct ztf_QueryDesc
    {
        uint32_t mIndex;
    } ztf_QueryDesc;

    typedef struct ztf_QueryPool
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12QueryHeap* pQueryHeap;
                ztf_Buffer* pReadbackBuffer;
                D3D12_QUERY_TYPE mType;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkQueryPool pQueryPool;
                VkQueryType mType;
                uint32_t    mNodeIndex;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                // Length: 'mCount'
                // Not dynamic. It is of length n, given when a queryPool is added, look at: mtl_addQueryPool()
                // Take a look into QuerySampleRange in MetalRenderer.mm..
                void* pQueries;
                // Sampling done only at encoder level..
                id<MTLCounterSampleBuffer> pSampleBuffer;
                // Offset from the start of their relative origin
                uint32_t                   mRenderSamplesOffset;  // Origin: 0.
                uint32_t                   mComputeSamplesOffset; // Origin: RenderSampleCount * mCount.
                uint32_t                   mType;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Query** ppQueries;
                D3D11_QUERY   mType;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                uint32_t* pQueries;
                uint32_t  mType;
            } mGLES;
#endif
#if defined(ORBIS)
            struct
            {
                OrbisQueryPool mStruct;
                uint32_t       mType;
            };
#endif
#if defined(PROSPERO)
            struct
            {
                ProsperoQueryPool mStruct;
                uint32_t          mType;
            };
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        uint32_t mCount;
        uint32_t mStride;
    } ztf_QueryPool;

    typedef struct ztf_PipelineStatisticsQueryData
    {
        uint64_t mIAVertices;
        uint64_t mIAPrimitives;
        uint64_t mVSInvocations;
        uint64_t mGSInvocations;
        uint64_t mGSPrimitives;
        uint64_t mCInvocations;
        uint64_t mCPrimitives;
        uint64_t mPSInvocations;
        uint64_t mHSInvocations;
        uint64_t mDSInvocations;
        uint64_t mCSInvocations;
    } ztf_PipelineStatisticsQueryData;

    typedef struct ztf_QueryData
    {
        union
        {
            struct
            {
                ztf_PipelineStatisticsQueryData mPipelineStats;
            };
            struct
            {
                uint64_t mBeginTimestamp;
                uint64_t mEndTimestamp;
            };
            uint64_t mOcclusionCounts;
        };
        bool mValid;
    } ztf_QueryData;

#if defined(VULKAN)
    typedef enum ztf_SamplerRange
    {
        ZTF_SAMPLER_RANGE_FULL = 0,
        ZTF_SAMPLER_RANGE_NARROW = 1,
    } ztf_SamplerRange;

    typedef enum ztf_SamplerModelConversion
    {
        ZTF_SAMPLER_MODEL_CONVERSION_RGB_IDENTITY = 0,
        ZTF_SAMPLER_MODEL_CONVERSION_YCBCR_IDENTITY = 1,
        ZTF_SAMPLER_MODEL_CONVERSION_YCBCR_709 = 2,
        ZTF_SAMPLER_MODEL_CONVERSION_YCBCR_601 = 3,
        ZTF_SAMPLER_MODEL_CONVERSION_YCBCR_2020 = 4,
    } ztf_SamplerModelConversion;

    typedef enum ztf_SampleLocation
    {
        ZTF_SAMPLE_LOCATION_COSITED = 0,
        ZTF_SAMPLE_LOCATION_MIDPOINT = 1,
    } ztf_SampleLocation;
#endif

    typedef enum ztf_ResourceHeapCreationFlags
    {
        ZTF_RESOURCE_HEAP_FLAG_NONE = 0,
        ZTF_RESOURCE_HEAP_FLAG_SHARED = 0x1,
        ZTF_RESOURCE_HEAP_FLAG_DENY_BUFFERS = 0x2,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_DISPLAY = 0x4,
        ZTF_RESOURCE_HEAP_FLAG_SHARED_CROSS_ADAPTER = 0x8,
        ZTF_RESOURCE_HEAP_FLAG_DENY_RT_DS_TEXTURES = 0x10,
        ZTF_RESOURCE_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES = 0x20,
        ZTF_RESOURCE_HEAP_FLAG_HARDWARE_PROTECTED = 0x40,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_WRITE_WATCH = 0x80,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_SHADER_ATOMICS = 0x100,

        // These are convenience aliases to manage resource heap tier restrictions. They cannot be bitwise OR'ed together cleanly.
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES = 0x200,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_ONLY_BUFFERS = ZTF_RESOURCE_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES | ZTF_RESOURCE_HEAP_FLAG_DENY_RT_DS_TEXTURES,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES = ZTF_RESOURCE_HEAP_FLAG_DENY_BUFFERS | ZTF_RESOURCE_HEAP_FLAG_DENY_RT_DS_TEXTURES,
        ZTF_RESOURCE_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES = ZTF_RESOURCE_HEAP_FLAG_DENY_BUFFERS | ZTF_RESOURCE_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES,
    } ztf_ResourceHeapCreationFlags;

    typedef struct ztf_ResourceHeapDesc
    {
        uint64_t mSize;
        uint64_t mAlignment;

        ztf_ResourceMemoryUsage       mMemoryUsage;
        ztf_DescriptorType            mDescriptors;
        ztf_ResourceHeapCreationFlags mFlags;

        uint32_t    mNodeIndex;
        uint32_t    mSharedNodeIndexCount;
        uint32_t* pSharedNodeIndices;
        const char* pName;
    } ztf_ResourceHeapDesc;

    typedef struct DEFINE_ALIGNED(ztf_ResourceHeap, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12Heap* pHeap;

#if defined(XBOX)
                D3D12_GPU_VIRTUAL_ADDRESS mPtr;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                struct VmaAllocation_T* pAllocation;
                VkDeviceMemory          pMemory;
                void* pCpuMappedAddress;
                uint64_t                mOffset;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                struct VmaAllocation_T* pAllocation;
                NOREFS id<MTLHeap> pHeap;
            };
#endif
#if defined(ORBIS)
            OrbisResourceHeap mStruct;
#endif
#if defined(PROSPERO)
            ProsperoResourceHeap mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

        uint64_t mSize;
    } ztf_ResourceHeap;

    typedef struct ztf_ResourceSizeAlign
    {
        uint64_t mSize;
        uint64_t mAlignment;
    } ztf_ResourceSizeAlign;

    typedef struct ztf_ResourcePlacement
    {
        ztf_ResourceHeap* pHeap;
        uint64_t      mOffset;

#if defined(ORBIS)
        OrbisResourcePlacement mStruct;
#endif
#if defined(PROSPERO)
        ProsperoResourcePlacement mStruct;
#endif
    } ztf_ResourcePlacement;

    /// Data structure holding necessary info to create a Buffer
    typedef struct ztf_BufferDesc
    {
        /// Optional placement (addBuffer will place/bind buffer in this memory instead of allocating space)
        ztf_ResourcePlacement* pPlacement;
        /// Size of the buffer (in bytes)
        uint64_t             mSize;
        /// Set this to specify a counter buffer for this buffer (applicable to BUFFER_USAGE_STORAGE_SRV, BUFFER_USAGE_STORAGE_UAV)
        struct Buffer* pCounterBuffer;
        /// Index of the first element accessible by the SRV/UAV (applicable to BUFFER_USAGE_STORAGE_SRV, BUFFER_USAGE_STORAGE_UAV)
        uint32_t             mFirstElement;
        /// Number of elements in the buffer (applicable to BUFFER_USAGE_STORAGE_SRV, BUFFER_USAGE_STORAGE_UAV)
        uint32_t             mElementCount;
        /// Size of each element (in bytes) in the buffer (applicable to BUFFER_USAGE_STORAGE_SRV, BUFFER_USAGE_STORAGE_UAV)
        uint32_t             mStructStride;
        /// Alignment
        uint32_t             mAlignment;
        /// Debug name used in gpu profile
        const char* pName;
        uint32_t* pSharedNodeIndices;
        /// Decides which memory heap buffer will use (default, upload, readback)
        ztf_ResourceMemoryUsage  mMemoryUsage;
        /// Creation flags of the buffer
        ztf_BufferCreationFlags  mFlags;
        /// What type of queue the buffer is owned by
        ztf_QueueType            mQueueType;
        /// What state will the buffer get created in
        ztf_ResourceState        mStartState;
        /// ICB draw type
        ztf_IndirectArgumentType mICBDrawType;
        /// ICB max commands in indirect command buffer
        uint32_t                mICBMaxCommandCount;
        /// Format of the buffer (applicable to typed storage buffers (Buffer<T>)
        TinyImageFormat      mFormat;
        /// Flags specifying the suitable usage of this buffer (Uniform buffer, Vertex Buffer, Index Buffer,...)
        ztf_DescriptorType       mDescriptors;
        /// The index of the GPU in SLI/Cross-Fire that owns this buffer, or the Renderer index in unlinked mode.
        uint32_t             mNodeIndex;
        uint32_t             mSharedNodeIndexCount;
    } ztf_BufferDesc;

    typedef struct DEFINE_ALIGNED(ztf_Buffer, 64)
    {
        /// CPU address of the mapped buffer (applicable to buffers created in CPU accessible heaps (CPU, CPU_TO_GPU, GPU_TO_CPU)
        void* pCpuMappedAddress;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                /// GPU Address - Cache to avoid calls to ID3D12Resource::GetGpuVirtualAddress
                D3D12_GPU_VIRTUAL_ADDRESS mGpuAddress;
                /// Descriptor handle of the CBV in a CPU visible descriptor heap (applicable to BUFFER_USAGE_UNIFORM)
                DxDescriptorID            mDescriptors;
                /// Offset from mDescriptors for srv descriptor handle
                uint8_t                   mSrvDescriptorOffset;
                /// Offset from mDescriptors for uav descriptor handle
                uint8_t                   mUavDescriptorOffset;
#if !defined(XBOX)
                uint8_t mMarkerBuffer;
#endif
                /// Native handle of the underlying resource
                ID3D12Resource* pResource;
                union
                {
                    ID3D12Heap* pMarkerBufferHeap;
                    /// Contains resource allocation info such as parent heap, offset in heap
                    D3D12MAAllocation* pAllocation;
                };
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                /// Native handle of the underlying resource
                VkBuffer                pBuffer;
                /// Buffer view
                VkBufferView            pStorageTexelView;
                VkBufferView            pUniformTexelView;
                /// Contains resource allocation info such as parent heap, offset in heap
                struct VmaAllocation_T* pAllocation;
                uint64_t                mOffset;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                struct VmaAllocation_T* pAllocation;
                id<MTLBuffer>                pBuffer;
                id<MTLIndirectCommandBuffer> pIndirectCommandBuffer;
                uint64_t                     mOffset;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Buffer* pResource;
                ID3D11ShaderResourceView* pSrvHandle;
                ID3D11UnorderedAccessView* pUavHandle;
                uint64_t                   mFlags;
                uint64_t                   mPadA;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLuint mBuffer;
                GLenum mTarget;
                void* pGLCpuMappedAddress;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisBuffer mStruct;
#endif
#if defined(PROSPERO)
            ProsperoBuffer mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
		uint64_t mBitfield;
    } ztf_Buffer;
    // One cache line
    COMPILE_ASSERT(sizeof(ztf_Buffer) == 8 * sizeof(uint64_t));

	ZTF_BITFIELD_SETGET_DECLARE(Buffer, mSize, 			uint64_t);
	ZTF_BITFIELD_SETGET_DECLARE(Buffer, mDescriptors, 	uint64_t);
	ZTF_BITFIELD_SETGET_DECLARE(Buffer, mMemoryUsage, 	uint64_t);
	ZTF_BITFIELD_SETGET_DECLARE(Buffer, mNodeIndex, 	uint64_t);

    /// Data structure holding necessary info to create a Texture
    typedef struct ztf_TextureDesc
    {
        /// Optional placement (addTexture will place/bind buffer in this memory instead of allocating space)
        ztf_ResourcePlacement* pPlacement;
        /// Optimized clear value (recommended to use this same value when clearing the rendertarget)
        ztf_ClearValue         mClearValue;
        /// Pointer to native texture handle if the texture does not own underlying resource
        const void* pNativeHandle;
        /// Debug name used in gpu profile
        const char* pName;
        /// GPU indices to share this texture
        uint32_t* pSharedNodeIndices;
#if defined(VULKAN)
        VkSamplerYcbcrConversionInfo* pSamplerYcbcrConversionInfo;
#endif
        /// Texture creation flags (decides memory allocation strategy, sharing access,...)
        ztf_TextureCreationFlags mFlags;
        /// Width
        uint32_t             mWidth;
        /// Height
        uint32_t             mHeight;
        /// Depth (Should be 1 if not a mType is not TEXTURE_TYPE_3D)
        uint32_t             mDepth;
        /// Texture array size (Should be 1 if texture is not a texture array or cubemap)
        uint32_t             mArraySize;
        /// Number of mip levels
        uint32_t             mMipLevels;
        /// Number of multisamples per pixel (currently Textures created with mUsage TEXTURE_USAGE_SAMPLED_IMAGE only support SAMPLE_COUNT_1)
        ztf_SampleCount          mSampleCount;
        /// The image quality level. The higher the quality, the lower the performance. The valid range is between zero and the value
        /// appropriate for mSampleCount
        uint32_t             mSampleQuality;
        ///  image format
        TinyImageFormat      mFormat;
        /// What state will the texture get created in
        ztf_ResourceState        mStartState;
        /// Descriptor creation
        ztf_DescriptorType       mDescriptors;
        /// Number of GPUs to share this texture
        uint32_t             mSharedNodeIndexCount;
        /// GPU which will own this texture
        uint32_t             mNodeIndex;
    } ztf_TextureDesc;

    typedef struct DEFINE_ALIGNED(ztf_Texture, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                /// Descriptor handle of the SRV in a CPU visible descriptor heap (applicable to TEXTURE_USAGE_SAMPLED_IMAGE)
                DxDescriptorID     mDescriptors;
                /// Native handle of the underlying resource
                ID3D12Resource* pResource;
                /// Contains resource allocation info such as parent heap, offset in heap
                D3D12MAAllocation* pAllocation;
                uint32_t           mHandleCount;
                uint32_t           mUavStartIndex;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                /// Opaque handle used by shaders for doing read/write operations on the texture
                VkImageView  pSRVDescriptor;
                /// Opaque handle used by shaders for doing read/write operations on the texture
                VkImageView* pUAVDescriptors;
                /// Opaque handle used by shaders for doing read/write operations on the texture
                VkImageView  pSRVStencilDescriptor;
                /// Native handle of the underlying resource
                VkImage      pImage;
                union
                {
                    /// Contains resource allocation info such as parent heap, offset in heap
                    struct VmaAllocation_T* pAllocation;
                    VkDeviceMemory          pDeviceMemory;
                };
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                struct VmaAllocation_T* pAllocation;
                /// Native handle of the underlying resource
                id<MTLTexture>          pTexture;
                union
                {
                    id<MTLTexture> __strong* pUAVDescriptors;
                    id<MTLTexture>           pStencilTexture;
                };
                id       mpsTextureAllocator;
                uint32_t pPixelFormat;
                uint32_t mRT : 1;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Resource* pResource;
                ID3D11ShaderResourceView* pSRVDescriptor;
                ID3D11UnorderedAccessView** pUAVDescriptors;
                uint64_t                    mPadA;
                uint64_t                    mPadB;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLuint mTexture;
                GLenum mTarget;
                GLenum mGlFormat;
                GLenum mInternalFormat;
                GLenum mType;
                bool   mStateModified;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisTexture mStruct;
            /// Contains resource allocation info such as parent heap, offset in heap
#endif
#if defined(PROSPERO)
            ProsperoTexture mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        /// Current state of the buffer
		uint32_t mBitfieldOne;
		uint32_t mBitfieldTwo;
		uint32_t mBitfieldThree;
    } ztf_Texture;
    // One cache line
    COMPILE_ASSERT(sizeof(ztf_Texture) == 8 * sizeof(uint64_t));

	ZTF_BITFIELD_SETGET_DECLARE(Texture, mWidth, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mHeight, 				uint32_t);

	ZTF_BITFIELD_SETGET_DECLARE(Texture, mDepth, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mMipLevels, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mArraySizeMinusOne, 	uint32_t);

	ZTF_BITFIELD_SETGET_DECLARE(Texture, mFormat, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mAspectMask, 		uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mNodeIndex, 		uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mSampleCount, 		uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mUav, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mOwnsImage, 		uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Texture, mLazilyAllocated, 	uint32_t);

    typedef struct ztf_RenderTargetDesc
    {
        /// Optional placement (addRenderTarget will place/bind buffer in this memory instead of allocating space)
        ztf_ResourcePlacement* pPlacement;
        /// Texture creation flags (decides memory allocation strategy, sharing access,...)
        ztf_TextureCreationFlags mFlags;
        /// Width
        uint32_t             mWidth;
        /// Height
        uint32_t             mHeight;
        /// Depth (Should be 1 if not a mType is not TEXTURE_TYPE_3D)
        uint32_t             mDepth;
        /// Texture array size (Should be 1 if texture is not a texture array or cubemap)
        uint32_t             mArraySize;
        /// Number of mip levels
        uint32_t             mMipLevels;
        /// MSAA
        ztf_SampleCount          mSampleCount;
        /// Internal image format
        TinyImageFormat      mFormat;
        /// What state will the texture get created in
        ztf_ResourceState        mStartState;
        /// Optimized clear value (recommended to use this same value when clearing the rendertarget)
        ztf_ClearValue           mClearValue;
        /// The image quality level. The higher the quality, the lower the performance. The valid range is between zero and the value
        /// appropriate for mSampleCount
        uint32_t             mSampleQuality;
        /// Descriptor creation
        ztf_DescriptorType       mDescriptors;
        const void* pNativeHandle;
        /// Debug name used in gpu profile
        const char* pName;
        /// GPU indices to share this texture
        uint32_t* pSharedNodeIndices;
        /// Number of GPUs to share this texture
        uint32_t             mSharedNodeIndexCount;
        /// GPU which will own this texture
        uint32_t             mNodeIndex;
    } ztf_RenderTargetDesc;

    typedef struct DEFINE_ALIGNED(ztf_RenderTarget, 64)
    {
        ztf_Texture* pTexture;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                DxDescriptorID mDescriptors;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkImageView  pDescriptor;
                VkImageView* pSliceDescriptors;
                uint32_t     mId;
            } mVk;
#endif
#if defined(DIRECT3D11)
            struct
            {
                union
                {
                    /// Resources
                    ID3D11RenderTargetView* pRtvDescriptor;
                    ID3D11DepthStencilView* pDsvDescriptor;
                };
                union
                {
                    /// Resources
                    ID3D11RenderTargetView** pRtvSliceDescriptors;
                    ID3D11DepthStencilView** pDsvSliceDescriptors;
                };
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLuint mType;
                GLuint mFramebuffer;
                GLuint mDepthTarget;
                GLuint mStencilTarget;
            } mGLES;
#endif
#if defined(ORBIS)
            struct
            {
                OrbisRenderTarget mStruct;
                ztf_Texture* pFragMask;
            };
#endif
#if defined(PROSPERO)
            struct
            {
                ProsperoRenderTarget mStruct;
                ztf_Texture* pFragMask;
            };
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
#if defined(USE_MSAA_RESOLVE_ATTACHMENTS)
        RenderTarget* pResolveAttachment;
#endif
        ztf_ClearValue      mClearValue;
		uint32_t 		mBitfieldOne;
		uint32_t 		mBitfieldTwo;
		uint32_t 		mBitfieldThree;
		uint32_t 		mBitfieldFour;
        TinyImageFormat mFormat;
        ztf_SampleCount     mSampleCount;
        bool            mVRMultiview;
        bool            mVRFoveatedRendering;
    } ztf_RenderTarget;
    COMPILE_ASSERT(sizeof(ztf_RenderTarget) <= 32 * sizeof(uint64_t));

	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mArraySize, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mDepth, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mWidth, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mHeight, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mDescriptors, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mMipLevels, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RenderTarget, mSampleQuality, uint32_t);

    typedef struct ztf_SampleLocations
    {
        int8_t mX;
        int8_t mY;
    } ztf_SampleLocations;

    typedef struct ztf_SamplerDesc
    {
        ztf_FilterType  mMinFilter;
        ztf_FilterType  mMagFilter;
        ztf_MipMapMode  mMipMapMode;
        ztf_AddressMode mAddressU;
        ztf_AddressMode mAddressV;
        ztf_AddressMode mAddressW;
        float       mMipLodBias;
        bool        mSetLodRange;
        float       mMinLod;
        float       mMaxLod;
        float       mMaxAnisotropy;
        ztf_CompareMode mCompareFunc;

#if defined(VULKAN)
        struct
        {
            TinyImageFormat        mFormat;
            ztf_SamplerModelConversion mModel;
            ztf_SamplerRange           mRange;
            ztf_SampleLocation         mChromaOffsetX;
            ztf_SampleLocation         mChromaOffsetY;
            ztf_FilterType             mChromaFilter;
            bool                   mForceExplicitReconstruction;
        } mSamplerConversionDesc;
#endif
    } ztf_SamplerDesc;

    typedef struct DEFINE_ALIGNED(ztf_Sampler, 16)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                /// Description for creating the Sampler descriptor for this sampler
                D3D12_SAMPLER_DESC mDesc;
                /// Descriptor handle of the Sampler in a CPU visible descriptor heap
                DxDescriptorID     mDescriptor;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                /// Native handle of the underlying resource
                VkSampler                    pSampler;
                VkSamplerYcbcrConversion     pSamplerYcbcrConversion;
                VkSamplerYcbcrConversionInfo mSamplerYcbcrConversionInfo;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                /// Native handle of the underlying resource
                id<MTLSamplerState> pSamplerState;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                /// Native handle of the underlying resource
                ID3D11SamplerState* pSamplerState;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLenum mMinFilter;
                GLenum mMagFilter;
                GLenum mMipMapMode;
                GLenum mAddressS;
                GLenum mAddressT;
                GLenum mCompareFunc;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisSampler mStruct;
#endif
#if defined(PROSPERO)
            ProsperoSampler mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
    } ztf_Sampler;
#if defined(DIRECT3D12)
    COMPILE_ASSERT(sizeof(ztf_Sampler) == 8 * sizeof(uint64_t));
#elif defined(VULKAN)
    COMPILE_ASSERT(sizeof(ztf_Sampler) <= 8 * sizeof(uint64_t));
#elif defined(GLES)
    COMPILE_ASSERT(sizeof(ztf_Sampler) == 4 * sizeof(uint64_t));
#else
    COMPILE_ASSERT(sizeof(ztf_Sampler) == 2 * sizeof(uint64_t));
#endif

    typedef enum ztf_DescriptorUpdateFrequency
    {
        ZTF_DESCRIPTOR_UPDATE_FREQ_NONE = 0,
        ZTF_DESCRIPTOR_UPDATE_FREQ_PER_FRAME,
        ZTF_DESCRIPTOR_UPDATE_FREQ_PER_BATCH,
        ZTF_DESCRIPTOR_UPDATE_FREQ_PER_DRAW,
        ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT,
    } ztf_DescriptorUpdateFrequency;

    /// Data structure holding the layout for a descriptor
    typedef struct DEFINE_ALIGNED(ztf_DescriptorInfo, 16)
    {
        const char* pName;
#if defined(ORBIS)
        OrbisDescriptorInfo mStruct;
#elif defined(PROSPERO)
        ProsperoDescriptorInfo mStruct;
#else
        uint32_t mType;
		uint32_t mBitfield;
        uint32_t mSize;
        uint32_t mHandleIndex;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                uint64_t mPadA;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                uint32_t mType;
				uint32_t mBitfieldVk;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLSamplerState> pStaticSampler;
                uint32_t            mUsedStages : 6;
                uint32_t            mReg : 10;
                uint32_t            mIsArgumentBufferField : 1;
                MTLResourceUsage    mUsage;
                uint64_t            mPadB[2];
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
				uint32_t mBitfieldDx11;
                uint32_t mPadA;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                union
                {
                    uint32_t mGlType;
                    uint32_t mUBOSize;
                    uint32_t mVariableStart;
                };
            } mGLES;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
#endif
    } ztf_DescriptorInfo;
#if defined(METAL)
    COMPILE_ASSERT(sizeof(ztf_DescriptorInfo) == 8 * sizeof(uint64_t));
#elif defined(ORBIS) || defined(PROSPERO)
    COMPILE_ASSERT(sizeof(ztf_DescriptorInfo) == 2 * sizeof(uint64_t));
#else
    COMPILE_ASSERT(sizeof(ztf_DescriptorInfo) == 4 * sizeof(uint64_t));
#endif

	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mVkReg, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mStages, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mUsedStages, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mDx11Reg, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mDim, 			 uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mRootDescriptor,  uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mStaticSampler,  uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(DescriptorInfo, mUpdateFrequency, uint32_t);

    typedef enum ztf_RootSignatureFlags
    {
        /// Default flag
        ZTF_ROOT_SIGNATURE_FLAG_NONE = 0,
    } ztf_RootSignatureFlags;

    typedef struct ztf_RootSignatureDesc
    {
        ztf_Shader** ppShaders;
        uint32_t           mShaderCount;
        uint32_t           mMaxBindlessTextures;
        const char** ppStaticSamplerNames;
        ztf_Sampler** ppStaticSamplers;
        uint32_t           mStaticSamplerCount;
        ztf_RootSignatureFlags mFlags;
    } ztf_RootSignatureDesc;

    typedef struct DEFINE_ALIGNED(ztf_RootSignature, 64)
    {
        /// Number of descriptors declared in the root signature layout
        uint32_t            mDescriptorCount;
        /// Graphics or Compute
        ztf_PipelineType        mPipelineType;
        /// Array of all descriptors declared in the root signature layout
        ztf_DescriptorInfo* pDescriptors;
        /// Translates hash of descriptor name to descriptor index in pDescriptors array
        ztf_DescriptorIndexMap* pDescriptorNameToIndexMap;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12RootSignature* pRootSignature;
                uint8_t              mViewDescriptorTableRootIndices[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t              mSamplerDescriptorTableRootIndices[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint32_t             mCumulativeViewDescriptorCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint32_t             mCumulativeSamplerDescriptorCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint16_t             mViewDescriptorCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint16_t             mSamplerDescriptorCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
#if defined(_WINDOWS) && defined(D3D12_RAYTRACING_AVAILABLE) && defined(FORGE_DEBUG)
                bool mHasRayQueryAccelerationStructure;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkPipelineLayout      pPipelineLayout;
                VkDescriptorSetLayout mDescriptorSetLayouts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t               mDynamicDescriptorCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                VkDescriptorPoolSize  mPoolSizes[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT][ZTF_MAX_DESCRIPTOR_POOL_SIZE_ARRAY_COUNT];
                uint8_t               mPoolSizeCount[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                VkDescriptorPool      pEmptyDescriptorPool[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                VkDescriptorSet       pEmptyDescriptorSet[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                NSMutableArray<MTLArgumentDescriptor*>* mArgumentDescriptors[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t                                 mRootTextureCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t                                 mRootBufferCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t                                 mRootSamplerCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11SamplerState** ppStaticSamplers;
                uint32_t* pStaticSamplerSlots;
                ztf_ShaderStage* pStaticSamplerStages;
                uint32_t             mStaticSamplerCount;
                uint8_t              mSrvCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t              mUavCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t              mCbvCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t              mSamplerCounts[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint8_t              mDynamicCbvCount[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];

            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                uint32_t           mProgramCount : 6;
                uint32_t           mVariableCount : 10;
                uint32_t* pProgramTargets;
                int32_t* pDescriptorGlLocations;
                struct GlVariable* pVariables;
                ztf_Sampler* pSampler;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisRootSignature mStruct;
#endif
#if defined(PROSPERO)
            ProsperoRootSignature mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

    } ztf_RootSignature;
#if defined(VULKAN)
    COMPILE_ASSERT(sizeof(ztf_RootSignature) <= 72 * sizeof(uint64_t));
#elif defined(ORBIS) || defined(PROSPERO) || defined(DIRECT3D12) || defined(ENABLE_DEPENDENCY_TRACKER)
    // 2 cache lines
    COMPILE_ASSERT(sizeof(ztf_RootSignature) <= 16 * sizeof(uint64_t));
#else
    // 1 cache line
    COMPILE_ASSERT(sizeof(ztf_RootSignature) == 16 * sizeof(uint64_t));
#endif

    typedef struct ztf_DescriptorDataRange
    {
        uint32_t mOffset;
        uint32_t mSize;
        // Specify different structured buffer stride (ignored for raw buffer - ByteAddressBuffer)
        uint32_t mStructStride;
    } ztf_DescriptorDataRange;

    typedef struct ztf_DescriptorData
    {
        /// User can either set name of descriptor or index (index in pRootSignature->pDescriptors array)
        /// Name of descriptor
        const char* pName;
        /// Number of array entries to update (array size of ppTextures/ppBuffers/...)
        uint32_t    mCount : 31;
        /// Dst offset into the array descriptor (useful for updating few entries in a large array)
        // Example: to update 6th entry in a bindless texture descriptor, mArrayOffset will be 6 and mCount will be 1)
        uint32_t    mArrayOffset : 20;
        // Index in pRootSignature->pDescriptors array - Cache index using getDescriptorIndexFromName to avoid using string checks at runtime
        uint32_t    mIndex : 10;
        uint32_t    mBindByIndex : 1;

        // Range to bind (buffer offset, size)
        ztf_DescriptorDataRange* pRanges;

        // Binds stencil only descriptor instead of color/depth
        bool mBindStencilResource : 1;

        union
        {
            struct
            {
                // When binding UAV, control the mip slice to to bind for UAV (example - generating mipmaps in a compute shader)
                uint16_t mUAVMipSlice;
                // Binds entire mip chain as array of UAV
                bool     mBindMipChain;
            };
            struct
            {
                // Bind MTLIndirectCommandBuffer along with the MTLBuffer
                const char* pICBName;
                uint32_t    mICBIndex;
                bool        mBindICB;
            };
        };
        /// Array of resources containing descriptor handles or constant to be used in ring buffer memory - DescriptorRange can hold only one
        /// resource type array
        union
        {
            /// Array of texture descriptors (srv and uav textures)
            ztf_Texture** ppTextures;
            /// Array of sampler descriptors
            ztf_Sampler** ppSamplers;
            /// Array of buffer descriptors (srv, uav and cbv buffers)
            ztf_Buffer** ppBuffers;
            /// Custom binding (raytracing acceleration structure ...)
            ztf_AccelerationStructure** ppAccelerationStructures;
        };
    } ztf_DescriptorData;

    typedef struct DEFINE_ALIGNED(ztf_DescriptorSet, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                /// Start handle to cbv srv uav descriptor table
                DxDescriptorID       mCbvSrvUavHandle;
                /// Start handle to sampler descriptor table
                DxDescriptorID       mSamplerHandle;
                /// Stride of the cbv srv uav descriptor table (number of descriptors * descriptor size)
                uint32_t             mCbvSrvUavStride;
                /// Stride of the sampler descriptor table (number of descriptors * descriptor size)
                uint32_t             mSamplerStride;
                const ztf_RootSignature* pRootSignature;
                uint32_t             mMaxSets : 16;
                uint32_t             mUpdateFrequency : 3;
                uint32_t             mNodeIndex : 4;
                uint32_t             mCbvSrvUavRootIndex : 4;
                uint32_t             mSamplerRootIndex : 4;
                uint32_t             mPipelineType : 3;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkDescriptorSet* pHandles;
                const ztf_RootSignature* pRootSignature;
                struct ztf_DynamicUniformData* pDynamicUniformData;
                VkDescriptorPool           pDescriptorPool;
                uint32_t                   mMaxSets;
                uint8_t                    mDynamicOffsetCount;
                uint8_t                    mUpdateFrequency;
                uint8_t                    mNodeIndex;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLArgumentEncoder>         mArgumentEncoder;
                ztf_Buffer* mArgumentBuffer;
                struct UntrackedResourceData** ppUntrackedData;
                const ztf_RootSignature* pRootSignature;
                /// Descriptors that are bound without argument buffers
                /// This is necessary since there are argument buffers bugs in some iOS Metal drivers which causes shader compiler crashes or
                /// incorrect shader generation. This makes it necessary to keep fallback descriptor binding path alive
                struct ztf_RootDescriptorData* pRootDescriptorData;
                uint32_t                       mStride;
                uint32_t                       mMaxSets;
                uint32_t                       mRootBufferCount : 10;
                uint32_t                       mRootTextureCount : 10;
                uint32_t                       mRootSamplerCount : 10;
                uint8_t                        mUpdateFrequency;
                uint8_t                        mNodeIndex;
                uint8_t                        mStages;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                struct ztf_DescriptorDataArray* pHandles;
                const ztf_RootSignature* pRootSignature;
                uint16_t                    mMaxSets;
                uint32_t                    mUpdateFrequency : 3;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                struct ztf_DescriptorDataArray* pHandles;
                uint8_t                     mUpdateFrequency;
                const ztf_RootSignature* pRootSignature;
                uint16_t                    mMaxSets;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisDescriptorSet mStruct;
#endif
#if defined(PROSPERO)
            ProsperoDescriptorSet mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
    } ztf_DescriptorSet;

    typedef struct ztf_CmdPoolDesc
    {
        ztf_Queue* pQueue;
        bool   mTransient;
    } ztf_CmdPoolDesc;

    typedef struct ztf_CmdPool
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            ID3D12CommandAllocator* pCmdAlloc;
#endif
#if defined(VULKAN)
            VkCommandPool pCmdPool;
#endif
#if defined(GLES)
            struct CmdCache* pCmdCache;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

        ztf_Queue* pQueue;
    } ztf_CmdPool;

    typedef struct ztf_CmdDesc
    {
        ztf_CmdPool* pPool;
#if defined(ORBIS) || defined(PROSPERO)
        uint32_t mMaxSize;
#endif
        bool mSecondary;
#ifdef ENABLE_GRAPHICS_DEBUG
        const char* pName;
#endif // ENABLE_GRAPHICS_DEBUG
    } ztf_CmdDesc;

    typedef enum ztf_MarkerFlags
    {
        /// Default flag
        ZTF_MARKER_FLAG_NONE = 0,
        ZTF_MARKER_FLAG_WAIT_FOR_WRITE = 0x1,
    } ztf_MarkerFlags;

    typedef struct ztf_MarkerDesc
    {
        ztf_Buffer* pBuffer;
        uint32_t    mOffset;
        uint32_t    mValue;
        ztf_MarkerFlags mFlags;
    } ztf_MarkerDesc;

#if !defined(PROSPERO) && !defined(XBOX)
#define GPU_MARKER_SIZE                        sizeof(uint32_t)
#define GPU_MARKER_VALUE(markerBuffer, offset) (*((uint32_t*)markerBuffer->pCpuMappedAddress) + ((offset) / GPU_MARKER_SIZE))
#endif

    typedef struct DEFINE_ALIGNED(ztf_Cmd, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
#if defined(XBOX)
                DmaCmd mDma;
#endif
                ID3D12GraphicsCommandList1* pCmdList;
#if defined(ENABLE_GRAPHICS_DEBUG) && defined(_WINDOWS)
                // For resource state validation
                ID3D12DebugCommandList* pDebugCmdList;
#endif
                // Cached in beginCmd to avoid fetching them during rendering
                struct DescriptorHeap* pBoundHeaps[2];
                D3D12_GPU_DESCRIPTOR_HANDLE mBoundHeapStartHandles[2];

                // Command buffer state
                const ztf_RootSignature* pBoundRootSignature;
                ztf_DescriptorSet* pBoundDescriptorSets[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint16_t             mBoundDescriptorSetIndices[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint32_t             mNodeIndex : 4;
                uint32_t             mType : 3;
#if defined(XBOX)
                // Required for setting occlusion query control
                uint32_t mSampleCount : 5;
#endif
                ztf_CmdPool* pCmdPool;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkCommandBuffer  pCmdBuf;
                VkRenderPass     pActiveRenderPass;
                VkPipelineLayout pBoundPipelineLayout;
                ztf_CmdPool* pCmdPool;
                uint32_t         mNodeIndex : 4;
                uint32_t         mType : 3;
                uint32_t         mIsRendering : 1;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLCommandBuffer>         pCommandBuffer;
                id<MTLRenderCommandEncoder>  pRenderEncoder;
                id<MTLComputeCommandEncoder> pComputeEncoder;
                id<MTLBlitCommandEncoder>    pBlitEncoder;
#if defined(MTL_RAYTRACING_AVAILABLE)
                id<MTLAccelerationStructureCommandEncoder> pASEncoder IOS17_API;
#endif
                // Stored in cmdBindPipeline. Used in
                // - cmdDraw functions to check for tessellation and patch control point count
                // - cmdDispatch functions to check for num threads per group (Metal needs to specify numThreadsPerThreadGroup explicitly)
                ztf_Pipeline* pBoundPipeline;
                ztf_QueryPool* pCurrentQueryPool;
                int32_t    mCurrentQueryIndex;
                // Stored in cmdBindIndexBuffer and used in cmdDrawIndexed functions (no bindIndexBuffer in Metal)
                NOREFS id<MTLBuffer> mBoundIndexBuffer;
                // Stored in cmdBindIndexBuffer and used in cmdDrawIndexed functions (no bindIndexBuffer in Metal)
                uint32_t             mBoundIndexBufferOffset;
                // Stored in cmdBindIndexBuffer and used in cmdDrawIndexed functions (no bindIndexBuffer in Metal)
                uint32_t             mIndexType : 2;
                // Stored in cmdBindIndexBuffer and used in cmdDrawIndexed functions (no bindIndexBuffer in Metal)
                uint32_t             mIndexStride : 3;
                // Stored in cmdBindPipeline and used in all draw functions (primitive type does not go in PSO but specified in the draw call)
                uint32_t             mSelectedPrimitiveType : 4;
                uint32_t             mPipelineType : 3;
                // To store sample locations provided by cmdSetSampleLocations and used in cmdBindRenderTargets
                uint32_t             mSampleLocationsCount : 5;
                uint32_t             mShouldRebindDescriptorSets : ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT;
                uint32_t             mShouldRebindPipeline : 1;
                MTLSamplePosition    mSamplePositions[MAX_SAMPLE_LOCATIONS];
                const ztf_RootSignature* pUsedRootSignature;
                ztf_DescriptorSet* mBoundDescriptorSets[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
                uint32_t             mBoundDescriptorSetIndices[ZTF_DESCRIPTOR_UPDATE_FREQ_COUNT];
#ifdef ENABLE_DRAW_INDEX_BASE_VERTEX_FALLBACK
                // When first vertex is not supported for indexed draw, we have to offset the
                // vertex buffer manually using setVertexBufferOffset
                // mOffsets, mStrides stored in cmdBindVertexBuffer and used in cmdDrawIndexed functions
                uint32_t mOffsets[ZTF_MAX_VERTEX_BINDINGS];
                uint32_t mStrides[ZTF_MAX_VERTEX_BINDINGS];
                uint32_t mFirstVertex;
#endif
#ifdef ENABLE_GRAPHICS_DEBUG
                char mDebugMarker[MAX_DEBUG_NAME_LENGTH];
#endif
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Buffer* pRootConstantBuffer;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                ztf_CmdPool* pCmdPool;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisCmd mStruct;
#endif
#if defined(PROSPERO)
            ProsperoCmd mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        ztf_Renderer* pRenderer;
        ztf_Queue* pQueue;
    } ztf_Cmd;
    COMPILE_ASSERT(sizeof(ztf_Cmd) <= 64 * sizeof(uint64_t));

    typedef enum ztf_FenceStatus
    {
        ZTF_FENCE_STATUS_COMPLETE = 0,
        ZTF_FENCE_STATUS_INCOMPLETE,
        ZTF_FENCE_STATUS_NOTSUBMITTED,
    } ztf_FenceStatus;

    typedef struct ztf_Fence
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12Fence* pFence;
                HANDLE       pWaitIdleFenceEvent;
                uint64_t     mFenceValue;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkFence pFence;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                dispatch_semaphore_t pSemaphore;
                uint32_t             mSubmitted : 1;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Query* pDX11Query;
                uint32_t     mSubmitted : 1;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                uint32_t mSubmitted : 1;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisFence mStruct;
#endif
#if defined(PROSPERO)
            ProsperoFence mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
    } ztf_Fence;

    typedef struct ztf_Semaphore
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            // DirectX12 does not have a concept of semaphores
            // All synchronization is done using fences
            // Simlate semaphore signal and wait using DirectX12 fences

            // Semaphores used in DirectX12 only in queueSubmit
            // queueSubmit -> How the semaphores work in DirectX12

            // pp_wait_semaphores -> queue->Wait is manually called on each fence in this
            // array before calling ExecuteCommandLists to make the fence work like a wait semaphore

            // pp_signal_semaphores -> Manually call queue->Signal on each fence in this array after
            // calling ExecuteCommandLists and increment the underlying fence value

            // queuePresent does not use the wait semaphore since the swapchain Present function
            // already does the synchronization in this case
            struct
            {
                ID3D12Fence* pFence;
                HANDLE       pWaitIdleFenceEvent;
                uint64_t     mFenceValue;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkSemaphore pSemaphore;
                uint32_t    mCurrentNodeIndex : 5;
                uint32_t    mSignaled : 1;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLEvent> pSemaphore;
                uint64_t     mValue : 63;
                uint64_t     mSignaled : 1;
            };
#endif
#if defined(GLES)
            struct
            {
                uint32_t mSignaled : 1;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisSemaphore mStruct;
#endif
#if defined(PROSPERO)
            ProsperoSemaphore mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
    } ztf_Semaphore;

    typedef struct ztf_QueueDesc
    {
        ztf_QueueType     mType;
        ztf_QueueFlag     mFlag;
        ztf_QueuePriority mPriority;
        uint32_t      mNodeIndex;
        const char* pName;
    } ztf_QueueDesc;

    typedef struct ztf_Queue
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12CommandQueue* pQueue;
                ztf_Fence* pFence;
#if defined(_WINDOWS) && defined(FORGE_DEBUG)
                // To silence mismatching command list on Windows 11 multi GPU
                ztf_Renderer* pRenderer;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkQueue   pQueue;
                ztf_Renderer* pRenderer;
                Mutex* pSubmitMutex;
                float     mTimestampPeriod;
                uint32_t  mQueueFamilyIndex : 5;
                uint32_t  mQueueIndex : 5;
                uint32_t  mGpuMode : 3;
            } mVk;
#endif
#if defined(GLES)
            struct
            {
                struct CmdCache* pCmdCache;
            } mGLES;
#endif
#if defined(METAL)
            struct
            {
                id<MTLCommandQueue> pCommandQueue;
                id<MTLFence>        pQueueFence;
                uint32_t            mBarrierFlags;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Device* pDevice;
                ID3D11DeviceContext* pContext;
                ztf_Fence* pFence;
            } mDx11;
#endif
#if defined(ORBIS)
            OrbisQueue mStruct;
#endif
#if defined(PROSPERO)
            ProsperoQueue mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        uint32_t mType : 3;
        uint32_t mNodeIndex : 4;
    } ztf_Queue;

    /// ShaderConstant only supported by Vulkan and Metal APIs
    typedef struct ztf_ShaderConstant
    {
        const void* pValue;
        uint32_t    mIndex;
        uint32_t    mSize;
    } ztf_ShaderConstant;

    typedef struct ztf_BinaryShaderStageDesc
    {
        const char* pName;
#if defined(PROSPERO)
        ProsperoBinaryShaderStageDesc mStruct;
#else
        /// Byte code array
        void* pByteCode;
        uint32_t    mByteCodeSize;
        const char* pEntryPoint;
#if defined(METAL)
        uint32_t    mNumThreadsPerGroup[3];
        uint32_t    mOutputRenderTargetTypesMask;
#endif
#if defined(GLES)
        GLuint      mShader;
#endif
#endif
    } ztf_BinaryShaderStageDesc;

    typedef struct ztf_BinaryShaderDesc
    {
        ztf_ShaderStage           mStages;
        /// Specify whether shader will own byte code memory
        uint32_t              mOwnByteCode : 1;
        ztf_BinaryShaderStageDesc mVert;
        ztf_BinaryShaderStageDesc mFrag;
        ztf_BinaryShaderStageDesc mGeom;
        ztf_BinaryShaderStageDesc mHull;
        ztf_BinaryShaderStageDesc mDomain;
        ztf_BinaryShaderStageDesc mComp;
        const ztf_ShaderConstant* pConstants;
        uint32_t              mConstantCount;
#if defined(QUEST_VR)
        bool mIsMultiviewVR : 1;
#endif
    } ztf_BinaryShaderDesc;

    typedef struct ztf_Shader
    {
        ztf_ShaderStage mStages : 31;
        bool        mIsMultiviewVR : 1;
        uint32_t    mNumThreadsPerGroup[3];
        uint32_t    mOutputRenderTargetTypesMask;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                IDxcBlobEncoding** pShaderBlobs;
                LPCWSTR* pEntryNames;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkShaderModule* pShaderModules;
                char** pEntryNames;
                VkSpecializationInfo* pSpecializationInfo;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLFunction> pVertexShader;
                id<MTLFunction> pFragmentShader;
                id<MTLFunction> pComputeShader;
                uint32_t        mTessellation : 1;
                uint32_t        mICB : 1;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                union
                {
                    struct
                    {
                        ID3D11VertexShader* pVertexShader;
                        ID3D11PixelShader* pPixelShader;
                        ID3D11GeometryShader* pGeometryShader;
                        ID3D11DomainShader* pDomainShader;
                        ID3D11HullShader* pHullShader;
                    };
                    ID3D11ComputeShader* pComputeShader;
                };
                ID3DBlob* pInputSignature;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLuint mProgram;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisShader mStruct;
#endif
#if defined(PROSPERO)
            ProsperoShader mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        PipelineReflection* pReflection;

    } ztf_Shader;

    typedef struct ztf_BlendStateDesc
    {
        /// Source blend factor per render target.
        ztf_BlendConstant     mSrcFactors[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Destination blend factor per render target.
        ztf_BlendConstant     mDstFactors[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Source alpha blend factor per render target.
        ztf_BlendConstant     mSrcAlphaFactors[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Destination alpha blend factor per render target.
        ztf_BlendConstant     mDstAlphaFactors[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Blend mode per render target.
        ztf_BlendMode         mBlendModes[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Alpha blend mode per render target.
        ztf_BlendMode         mBlendAlphaModes[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Write mask per render target.
        ztf_ColorMask         mColorWriteMasks[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        /// Mask that identifies the render targets affected by the blend state.
        ztf_BlendStateTargets mRenderTargetMask;
        /// Set whether alpha to coverage should be enabled.
        bool              mAlphaToCoverage;
        /// Set whether each render target has an unique blend function. When false the blend function in slot 0 will be used for all render
        /// targets.
        bool              mIndependentBlend;
    } ztf_BlendStateDesc;

    typedef struct ztf_DepthStateDesc
    {
        bool        mDepthTest;
        bool        mDepthWrite;
        ztf_CompareMode mDepthFunc;
        bool        mStencilTest;
        uint8_t     mStencilReadMask;
        uint8_t     mStencilWriteMask;
        ztf_CompareMode mStencilFrontFunc;
        ztf_StencilOp   mStencilFrontFail;
        ztf_StencilOp   mDepthFrontFail;
        ztf_StencilOp   mStencilFrontPass;
        ztf_CompareMode mStencilBackFunc;
        ztf_StencilOp   mStencilBackFail;
        ztf_StencilOp   mDepthBackFail;
        ztf_StencilOp   mStencilBackPass;
    } ztf_DepthStateDesc;

    typedef struct ztf_RasterizerStateDesc
    {
        ztf_CullMode  mCullMode;
        int32_t   mDepthBias;
        float     mSlopeScaledDepthBias;
        ztf_FillMode  mFillMode;
        ztf_FrontFace mFrontFace;
        bool      mMultiSample;
        bool      mScissor;
        bool      mDepthClampEnable;
    } ztf_RasterizerStateDesc;

    typedef enum ztf_VertexBindingRate
    {
        ZTF_VERTEX_BINDING_RATE_VERTEX = 0,
        ZTF_VERTEX_BINDING_RATE_INSTANCE = 1,
        ZTF_VERTEX_BINDING_RATE_COUNT,
    } ztf_VertexBindingRate;

    typedef struct ztf_VertexBinding
    {
        uint32_t          mStride;
        ztf_VertexBindingRate mRate;
    } ztf_VertexBinding;

    typedef struct ztf_VertexAttrib
    {
        ztf_ShaderSemantic  mSemantic;
        uint32_t        mSemanticNameLength;
        char            mSemanticName[ZTF_MAX_SEMANTIC_NAME_LENGTH];
        TinyImageFormat mFormat;
        uint32_t        mBinding;
        uint32_t        mLocation;
        uint32_t        mOffset;
    } ztf_VertexAttrib;

    typedef struct ztf_VertexLayout
    {
        ztf_VertexBinding mBindings[ZTF_MAX_VERTEX_BINDINGS];
        ztf_VertexAttrib  mAttribs[ZTF_MAX_VERTEX_ATTRIBS];
        uint32_t      mBindingCount;
        uint32_t      mAttribCount;
    } ztf_VertexLayout;

    typedef struct ztf_GraphicsPipelineDesc
    {
        ztf_Shader* pShaderProgram;
        ztf_RootSignature* pRootSignature;
        ztf_VertexLayout* pVertexLayout;
        ztf_BlendStateDesc* pBlendState;
        ztf_DepthStateDesc* pDepthState;
        ztf_RasterizerStateDesc* pRasterizerState;
        TinyImageFormat* pColorFormats;
#if defined(USE_MSAA_RESOLVE_ATTACHMENTS)
        /// Used to specify resolve attachment for render pass
        StoreActionType* pColorResolveActions;
#endif
        uint32_t          mRenderTargetCount;
        ztf_SampleCount       mSampleCount;
        uint32_t          mSampleQuality;
        TinyImageFormat   mDepthStencilFormat;
        ztf_PrimitiveTopology mPrimitiveTopo;
        bool              mSupportIndirectCommandBuffer;
        bool              mVRFoveatedRendering;
        bool              mUseCustomSampleLocations;
    } ztf_GraphicsPipelineDesc;

    typedef struct ztf_ComputePipelineDesc
    {
        ztf_Shader* pShaderProgram;
        ztf_RootSignature* pRootSignature;
    } ztf_ComputePipelineDesc;

    typedef struct ztf_PipelineDesc
    {
        union
        {
            ztf_ComputePipelineDesc  mComputeDesc;
            ztf_GraphicsPipelineDesc mGraphicsDesc;
        };
        ztf_PipelineCache* pCache;
        void* pPipelineExtensions;
        const char* pName;
        ztf_PipelineType   mType;
        uint32_t       mExtensionCount;
    } ztf_PipelineDesc;

    typedef struct DEFINE_ALIGNED(ztf_Pipeline, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12PipelineState* pPipelineState;
                const ztf_RootSignature* pRootSignature;
                ztf_PipelineType           mType;
                D3D_PRIMITIVE_TOPOLOGY mPrimitiveTopology;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkPipeline   pPipeline;
                ztf_PipelineType mType;
#if defined(SHADER_STATS_AVAILABLE)
                ztf_ShaderStage mShaderStages;
#endif
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLRenderPipelineState>  pRenderPipelineState;
                id<MTLComputePipelineState> pComputePipelineState;
                id<MTLDepthStencilState>    pDepthStencilState;
                union
                {
                    // Graphics
                    struct
                    {
                        uint32_t mCullMode : 3;
                        uint32_t mFillMode : 3;
                        uint32_t mWinding : 3;
                        uint32_t mDepthClipMode : 1;
                        uint32_t mPrimitiveType : 4;
                        // Between 0-32
                        uint32_t mPatchControlPointCount : 6;
                        uint32_t mTessellation : 1;
                        float    mDepthBias;
                        float    mSlopeScale;
                    };
                    // Compute
                    struct
                    {
                        MTLSize mNumThreadsPerGroup;
                    };
                };
                ztf_PipelineType mType;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11VertexShader* pVertexShader;
                ID3D11PixelShader* pPixelShader;
                ID3D11GeometryShader* pGeometryShader;
                ID3D11DomainShader* pDomainShader;
                ID3D11HullShader* pHullShader;
                ID3D11ComputeShader* pComputeShader;
                ID3D11InputLayout* pInputLayout;
                ID3D11BlendState* pBlendState;
                ID3D11DepthStencilState* pDepthState;
                ID3D11RasterizerState* pRasterizerState;
                ztf_PipelineType             mType;
                D3D_PRIMITIVE_TOPOLOGY   mPrimitiveTopology;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                uint16_t                    mVertexLayoutSize;
                uint16_t                    mRootSignatureIndex;
                uint16_t                    mVAOStateCount;
                uint16_t                    mVAOStateLoop;
                struct GLVAOState* pVAOState;
                struct GlVertexAttrib* pVertexLayout;
                struct GLRasterizerState* pRasterizerState;
                struct GLDepthStencilState* pDepthStencilState;
                struct GLBlendState* pBlendState;
                ztf_RootSignature* pRootSignature;
                uint32_t                    mType;
                GLenum                      mGlPrimitiveTopology;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisPipeline mStruct;
#endif
#if defined(PROSPERO)
            ProsperoPipeline mStruct;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

    } ztf_Pipeline;
#if defined(DIRECT3D11) || defined(ORBIS)
    // Requires more cache lines due to no concept of an encapsulated pipeline state object
    COMPILE_ASSERT(sizeof(ztf_Pipeline) <= 64 * sizeof(uint64_t));
#elif defined(PROSPERO)
    COMPILE_ASSERT(sizeof(ztf_Pipeline) == 16 * sizeof(uint64_t));
#elif defined(ENABLE_DEPENDENCY_TRACKER)
    // Two cache lines
    COMPILE_ASSERT(sizeof(ztf_Pipeline) <= 16 * sizeof(uint64_t));
#else
    // One cache line
    COMPILE_ASSERT(sizeof(ztf_Pipeline) == 8 * sizeof(uint64_t));
#endif

    typedef enum ztf_PipelineCacheFlags
    {
        ZTF_PIPELINE_CACHE_FLAG_NONE = 0x0,
        ZTF_PIPELINE_CACHE_FLAG_EXTERNALLY_SYNCHRONIZED = 0x1,
    } ztf_PipelineCacheFlags;

    typedef struct ztf_PipelineCacheDesc
    {
        /// Initial pipeline cache data (can be NULL which means empty pipeline cache)
        void* pData;
        /// Initial pipeline cache size
        size_t             mSize;
        ztf_PipelineCacheFlags mFlags;
    } ztf_PipelineCacheDesc;

    typedef struct ztf_PipelineCache
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                ID3D12PipelineLibrary* pLibrary;
                void* pData;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkPipelineCache pCache;
            } mVk;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
    } ztf_PipelineCache;

#if defined(SHADER_STATS_AVAILABLE)
    typedef struct ztf_ShaderStats
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(VULKAN)
            struct
            {
                void* pDisassemblyAMD;
                uint32_t mDisassemblySize;
            } mVk;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        uint32_t mUsedVgprs;
        uint32_t mUsedSgprs;
        uint32_t mLdsSizePerLocalWorkGroup;
        uint32_t mLdsUsageSizeInBytes;
        uint32_t mScratchMemUsageInBytes;
        uint32_t mPhysicalVgprs;
        uint32_t mPhysicalSgprs;
        uint32_t mAvailableVgprs;
        uint32_t mAvailableSgprs;
        uint32_t mComputeWorkGroupSize[3];
        bool     mValid;
    } ztf_ShaderStats;

    typedef struct ztf_PipelineStats
    {
        ztf_ShaderStats mStats[ZTF_SHADER_STAGE_COUNT];
    } ztf_PipelineStats;
#endif

    typedef enum ztf_SwapChainCreationFlags
    {
        ZTF_SWAP_CHAIN_CREATION_FLAG_NONE = 0x0,
        ZTF_SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR = 0x1,
    } ztf_SwapChainCreationFlags;

    typedef struct ztf_SwapChainDesc
    {
        /// Window handle
        ztf_WindowHandle        mWindowHandle;
        /// Queues which should be allowed to present
        ztf_Queue** ppPresentQueues;
        /// Number of present queues
        uint32_t               mPresentQueueCount;
        /// Number of backbuffers in this swapchain
        uint32_t               mImageCount;
        /// Width of the swapchain
        uint32_t               mWidth;
        /// Height of the swapchain
        uint32_t               mHeight;
        /// Color format of the swapchain
        TinyImageFormat        mColorFormat;
        /// Clear value
        ztf_ClearValue             mColorClearValue;
        /// Swapchain creation flags
        ztf_SwapChainCreationFlags mFlags;
        /// Set whether swap chain will be presented using vsync
        bool                   mEnableVsync;
        /// We can toggle to using FLIP model if app desires.
        bool                   mUseFlipSwapEffect;
        /// Optional colorspace for HDR
        ztf_ColorSpace             mColorSpace;
    } ztf_SwapChainDesc;

    typedef struct ztf_SwapChain
    {
        /// Render targets created from the swapchain back buffers
        ztf_RenderTarget** ppRenderTargets;
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
#if defined(XBOX)
                uint64_t mFramePipelineToken;
                /// Sync interval to specify how interval for vsync
                uint32_t mSyncInterval : 3;
                uint32_t mFlags : 10;
                uint32_t mIndex;
                void* pWindow;
                ztf_Queue* pPresentQueue;
#else
                /// Use IDXGISwapChain3 for now since IDXGISwapChain4
                /// isn't supported by older devices.
                IDXGISwapChain3* pSwapChain;
                /// Sync interval to specify how interval for vsync
                uint32_t                                 mSyncInterval : 3;
                uint32_t                                 mFlags : 10;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                /// Present queue if one exists (queuePresent will use this queue if the hardware has a dedicated present queue)
                VkQueue        pPresentQueue;
                VkSwapchainKHR pSwapChain;
                VkSurfaceKHR   pSurface;
                ztf_SwapChainDesc* pDesc;
                uint32_t       mPresentQueueFamilyIndex : 5;
            } mVk;
#endif
#if defined(METAL)
            struct
            {
#if defined(TARGET_IOS)
                UIView* pForgeView;
#else
                NSView* pForgeView;
#endif
                id<CAMetalDrawable>  mMTKDrawable;
                id<MTLCommandBuffer> presentCommandBuffer;
                uint32_t             mIndex;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                /// Use IDXGISwapChain3 for now since IDXGISwapChain4
                /// isn't supported by older devices.
                IDXGISwapChain* pSwapChain;
                /// Sync interval to specify how interval for vsync
                uint32_t         mSyncInterval : 3;
                uint32_t         mFlags : 10;
                uint32_t         mImageIndex : 3;
                DXGI_SWAP_EFFECT mSwapEffect;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLSurface pSurface;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisSwapChain mStruct;
#endif
#if defined(PROSPERO)
            ProsperoSwapChain mStruct;
#endif
#if defined(QUEST_VR)
            struct
            {
                struct ovrTextureSwapChain* pSwapChain;
                VkExtent2D* pFragmentDensityTextureSizes;
                ztf_RenderTarget** ppFragmentDensityMasks;
            } mVR;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        uint32_t        mImageCount : 8;
        uint32_t        mEnableVsync : 1;
        ztf_ColorSpace      mColorSpace : 4;
        TinyImageFormat mFormat : 8;
    } ztf_SwapChain;

    typedef enum ztf_ShaderTarget
    {
        // We only need SM 5.0 for supporting D3D11 fallback
#if defined(DIRECT3D11)
        ZTF_SHADER_TARGET_5_0,
#endif
        // 5.1 is supported on all DX12 hardware
        ZTF_SHADER_TARGET_5_1,
        ZTF_SHADER_TARGET_6_0,
        ZTF_SHADER_TARGET_6_1,
        ZTF_SHADER_TARGET_6_2,
        ZTF_SHADER_TARGET_6_3, // required for Raytracing
        ZTF_SHADER_TARGET_6_4, // required for VRS
    } ztf_ShaderTarget;

    typedef enum ztf_GpuMode
    {
        ZTF_GPU_MODE_SINGLE = 0,
        ZTF_GPU_MODE_LINKED,
        ZTF_GPU_MODE_UNLINKED,
    } ztf_GpuMode;

    typedef struct ztf_RendererDesc
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                D3D_FEATURE_LEVEL mFeatureLevel;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                const char** ppInstanceLayers;
                const char** ppInstanceExtensions;
                const char** ppDeviceExtensions;
                uint32_t     mInstanceLayerCount;
                uint32_t     mInstanceExtensionCount;
                uint32_t     mDeviceExtensionCount;
                /// Flag to specify whether to request all queues from the gpu or just one of each type
                /// This will affect memory usage - Around 200 MB more used if all queues are requested
                bool         mRequestAllAvailableQueues;
            } mVk;
#endif
#if defined(DIRECT3D11)
            struct
            {
                /// Set whether to force feature level 10 for compatibility
                bool mUseDx10;
                /// Set whether to pick the first valid GPU or use our GpuConfig
                bool mUseDefaultGpu;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                const char** ppDeviceExtensions;
                uint32_t     mDeviceExtensionCount;
            } mGLES;
#endif
#if defined(ORBIS)
            OrbisExtendedDesc mExt;
#endif
#if defined(PROSPERO)
            ProsperoExtendedDesc mExt;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

        ztf_ShaderTarget mShaderTarget;
        ztf_GpuMode      mGpuMode;

        /// Apps may want to query additional state for their applications. That information is transferred through here.
        ztf_ExtendedSettings* pExtendedSettings;

        /// Required when creating unlinked multiple renderers. Optional otherwise, can be used for explicit GPU selection.
        ztf_RendererContext* pContext;
        uint32_t         mGpuIndex;

        /// This results in new validation not possible during API calls on the CPU, by creating patched shaders that have validation added
        /// directly to the shader. However, it can slow things down a lot, especially for applications with numerous PSOs. Time to see the
        /// first render frame may take several minutes
        bool mEnableGpuBasedValidation;
#if defined(SHADER_STATS_AVAILABLE)
        bool mEnableShaderStats;
#endif

        bool mD3D11Supported;
        bool mGLESSupported;
#if defined(VULKAN) && defined(ANDROID)
        bool mPreferVulkan;
#endif
    } ztf_RendererDesc;

    typedef struct ztf_GPUVendorPreset
    {
        uint32_t       mVendorId;
        uint32_t       mModelId;
        uint32_t       mRevisionId; // Optional as not all gpu's have that. Default is : 0x00
        ztf_GPUPresetLevel mPresetLevel;
        char           mVendorName[ZTF_MAX_GPU_VENDOR_STRING_LENGTH];
        char           mGpuName[ZTF_MAX_GPU_VENDOR_STRING_LENGTH]; // If GPU Name is missing then value will be empty string
        char           mGpuDriverVersion[ZTF_MAX_GPU_VENDOR_STRING_LENGTH];
        char           mGpuDriverDate[ZTF_MAX_GPU_VENDOR_STRING_LENGTH];
        uint32_t       mRTCoresCount;
    } ztf_GPUVendorPreset;

    typedef enum ztf_FormatCapability
    {
        ZTF_FORMAT_CAP_NONE = 0,
        ZTF_FORMAT_CAP_LINEAR_FILTER = 0x1,
        ZTF_FORMAT_CAP_READ = 0x2,
        ZTF_FORMAT_CAP_WRITE = 0x4,
        ZTF_FORMAT_CAP_READ_WRITE = 0x8,
        ZTF_FORMAT_CAP_RENDER_TARGET = 0x10,
    } ztf_FormatCapability;

    typedef struct ztf_GPUCapBits
    {
        ztf_FormatCapability mFormatCaps[TinyImageFormat_Count];
    } ztf_GPUCapBits;

    typedef enum ztf_DefaultResourceAlignment
    {
        ZTF_RESOURCE_BUFFER_ALIGNMENT = 4U,
    } ztf_DefaultResourceAlignment;

    typedef enum ztf_WaveOpsSupportFlags
    {
        ZTF_WAVE_OPS_SUPPORT_FLAG_NONE = 0x0,
        ZTF_WAVE_OPS_SUPPORT_FLAG_BASIC_BIT = 0x00000001,
        ZTF_WAVE_OPS_SUPPORT_FLAG_VOTE_BIT = 0x00000002,
        ZTF_WAVE_OPS_SUPPORT_FLAG_ARITHMETIC_BIT = 0x00000004,
        ZTF_WAVE_OPS_SUPPORT_FLAG_BALLOT_BIT = 0x00000008,
        ZTF_WAVE_OPS_SUPPORT_FLAG_SHUFFLE_BIT = 0x00000010,
        ZTF_WAVE_OPS_SUPPORT_FLAG_SHUFFLE_RELATIVE_BIT = 0x00000020,
        ZTF_WAVE_OPS_SUPPORT_FLAG_CLUSTERED_BIT = 0x00000040,
        ZTF_WAVE_OPS_SUPPORT_FLAG_QUAD_BIT = 0x00000080,
        ZTF_WAVE_OPS_SUPPORT_FLAG_PARTITIONED_BIT_NV = 0x00000100,
        ZTF_WAVE_OPS_SUPPORT_FLAG_ALL = 0x7FFFFFFF
    } ztf_WaveOpsSupportFlags;

    // update availableGpuProperties in GraphicsConfig.cpp if you made changes to this list
    typedef struct ztf_GPUSettings
    {
        uint64_t mVRAM; // set to 0 on OpenGLES platform
        uint32_t mUniformBufferAlignment;
        uint32_t mUploadBufferTextureAlignment;
        uint32_t mUploadBufferTextureRowAlignment;
        uint32_t mMaxVertexInputBindings;
#if defined(DIRECT3D12)
        uint32_t mMaxRootSignatureDWORDS;
#endif
        uint32_t            mWaveLaneCount;
        ztf_WaveOpsSupportFlags mWaveOpsSupportFlags;
        ztf_GPUVendorPreset     mGpuVendorPreset;
        ztf_ShaderStage         mWaveOpsSupportedStageFlags;

        uint32_t mMaxTotalComputeThreads;
        uint32_t mMaxComputeThreads[3];

		uint32_t mBitfieldOne;
#if defined(DIRECT3D11) || defined(DIRECT3D12)
        D3D_FEATURE_LEVEL mFeatureLevel;
#endif
#if defined(VULKAN)
		uint32_t mBitfieldVk;
#endif
        uint32_t mMaxBoundTextures;
		uint32_t mBitfieldTwo;
#if defined(METAL)
        uint32_t mHeaps : 1;
        uint32_t mPlacementHeaps : 1;
        uint32_t mTessellationIndirectDrawSupported : 1;
        uint32_t mDrawIndexVertexOffsetSupported : 1;
        uint32_t mCubeMapTextureArraySupported : 1;
#if !defined(TARGET_IOS)
        uint32_t mIsHeadLess : 1; // indicates whether a GPU device does not have a connection to a display.
#endif
#endif
        uint32_t mAmdAsicFamily;
    } ztf_GPUSettings;

	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mMultiDrawIndirect, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mIndirectRootConstant, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mBuiltinDrawID, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mIndirectCommandBuffer, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mROVsSupported, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mTessellationSupported, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mGeometryShaderSupported, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mGpuMarkers, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mTimestampQueries, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mOcclusionQueries, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mPipelineStatsQueries, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mAllowBufferTextureInSameHeap, 	uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mRaytracingSupported, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mRayPipelineSupported, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mRayQuerySupported, 				uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mSoftwareVRSSupported, 			uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mPrimitiveIdSupported, 			uint32_t);

#if defined(VULKAN)	
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mDynamicRenderingSupported, 		uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mXclipseTransferQueueWorkaround, 	uint32_t);
#endif	

	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mSamplerAnisotropySupported, 	uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GPUSettings, mGraphicsQueueSupported, 		uint32_t);

    typedef struct DEFINE_ALIGNED(ztf_Renderer, 64)
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                // API specific descriptor heap and memory allocator
                struct DescriptorHeap** pCPUDescriptorHeaps;
                struct DescriptorHeap** pCbvSrvUavHeaps;
                struct DescriptorHeap** pSamplerHeaps;
                D3D12MAAllocator* pResourceAllocator;
#if defined(XBOX)
                ID3D12Device* pDevice;
                ztf_EsramManager* pESRAMManager;
#elif defined(DIRECT3D12)
                ID3D12Device* pDevice;
#endif
#if defined(_WINDOWS) && defined(FORGE_DEBUG)
                ID3D12InfoQueue* pDebugValidation;
                bool             mSuppressMismatchingCommandListDuringPresent;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkDevice               pDevice;
                uint32_t** pAvailableQueueCount;
                uint32_t** pUsedQueueCount;
                VkDescriptorPool       pEmptyDescriptorPool;
                VkDescriptorSetLayout  pEmptyDescriptorSetLayout;
                VkDescriptorSet        pEmptyDescriptorSet;
                struct VmaAllocator_T* pVmaAllocator;
                union
                {
                    struct
                    {
                        uint8_t mGraphicsQueueFamilyIndex;
                        uint8_t mTransferQueueFamilyIndex;
                        uint8_t mComputeQueueFamilyIndex;
                    };
                    uint8_t mQueueFamilyIndices[3];
                };
            } mVk;
#endif
#if defined(METAL)
            struct
            {
                id<MTLDevice>               pDevice;
                struct VmaAllocator_T* pVmaAllocator;
                id<MTLComputePipelineState> pFillBufferPipeline;
                NOREFS id<MTLHeap>* pHeaps;
                uint32_t            mHeapCount;
                uint32_t            mHeapCapacity;
                // To synchronize resource allocation done through automatic heaps
                Mutex* pHeapMutex;
            };
#endif
#if defined(DIRECT3D11)
            struct
            {
                ID3D11Device* pDevice;
                ID3D11DeviceContext* pContext;
                ID3D11DeviceContext1* pContext1;
                ID3D11BlendState* pDefaultBlendState;
                ID3D11DepthStencilState* pDefaultDepthState;
                ID3D11RasterizerState* pDefaultRasterizerState;
                ID3DUserDefinedAnnotation* pUserDefinedAnnotation;
            } mDx11;
#endif
#if defined(GLES)
            struct
            {
                GLContext pContext;
                GLConfig  pConfig;
            } mGLES;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif

#if defined(ENABLE_NSIGHT_AFTERMATH)
        // GPU crash dump tracker using Nsight Aftermath instrumentation
        AftermathTracker mAftermathTracker;
#endif
        struct NullDescriptors* pNullDescriptors;
        struct ztf_RendererContext* pContext;
        const struct ztf_GpuInfo* pGpu;
        const char* pName;
        ztf_RendererApi         mRendererApi;
		uint32_t				mBitfield;
    } ztf_Renderer;
    // 3 cache lines
    COMPILE_ASSERT(sizeof(ztf_Renderer) <= 24 * sizeof(uint64_t));

	ZTF_BITFIELD_SETGET_DECLARE(Renderer, mLinkedNodeCount, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Renderer, mUnlinkedRendererIndex, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Renderer, mGpuMode, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Renderer, mShaderTarget, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(Renderer, mOwnsContext, uint32_t);


    typedef struct ztf_RendererContextDesc
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
                D3D_FEATURE_LEVEL mFeatureLevel;
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                const char** ppInstanceLayers;
                const char** ppInstanceExtensions;
                const char** ppDeviceExtensions;
                uint32_t     mInstanceLayerCount;
                uint32_t     mInstanceExtensionCount;
                uint32_t     mDeviceExtensionCount;
                /// Flag to specify whether to request all queues from the gpu or just one of each type
                /// This will affect memory usage - Around 200 MB more used if all queues are requested
                bool         mRequestAllAvailableQueues;
            } mVk;
#endif
#if defined(DIRECT3D11)
            struct
            {
                /// Set whether to force feature level 10 for compatibility
                bool mUseDx10;
                /// Set whether to pick the first valid GPU or use our GpuConfig
                bool mUseDefaultGpu;
            } mDx11;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
        bool mEnableGpuBasedValidation;
#if defined(SHADER_STATS_AVAILABLE)
        bool mEnableShaderStats;
#endif
        bool mD3D11Supported;
        bool mGLESSupported;
#if defined(VULKAN) && defined(ANDROID)
        bool mPreferVulkan;
#endif
    } ztf_RendererContextDesc;

    typedef struct ztf_GpuInfo
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
#if defined(XBOX)
                IDXGIAdapter* pGpu;
                ID3D12Device* pDevice;
#elif defined(DIRECT3D12)
                IDXGIAdapter4* pGpu;
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkPhysicalDevice            pGpu;
                VkPhysicalDeviceProperties2 mGpuProperties;
				uint32_t 					mBitfieldVkOne;
				uint32_t 					mBitfieldVkTwo;
            } mVk;
#endif
#if defined(DIRECT3D11)
            struct
            {
                IDXGIAdapter1* pGpu;
                uint32_t       mBitfieldDx11;
            } mDx11;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
#if defined(METAL)
        id<MTLDevice>     pGPU;
        id<MTLCounterSet> pCounterSetTimestamp;
        uint32_t          mCounterTimestampEnabled : 1;
#endif
        ztf_GPUSettings mSettings;
        ztf_GPUCapBits  mCapBits;
    } ztf_GpuInfo;

	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mYCbCrExtension, 									uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mFillModeNonSolid, 									uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mKHRRayQueryExtension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDGCNShaderExtension, 							uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDDrawIndirectCountExtension, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDShaderInfoExtension, 							uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDescriptorIndexingExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDynamicRenderingExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mShaderSampledImageArrayDynamicIndexingSupported, 	uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mBufferDeviceAddressSupported, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDrawIndirectCountExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDedicatedAllocationExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDebugMarkerExtension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mMemoryReq2Extension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mFragmentShaderInterlockExtension, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mBufferDeviceAddressExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAccelerationStructureExtension, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mRayTracingPipelineExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mRayQueryExtension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mBufferDeviceAddressFeature, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mShaderFloatControlsExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mSpirv14Extension, 									uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDeferredHostOperationsExtension, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDeviceFaultExtension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDeviceFaultSupported, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mASTCDecodeModeExtension, 							uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mDeviceMemoryReportExtension, 						uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDBufferMarkerExtension, 							uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDDeviceCoherentMemoryExtension, 					uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAMDDeviceCoherentMemorySupported, 					uint32_t);

#if defined(VK_USE_PLATFORM_WIN32_KHR)
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mExternalMemoryExtension, 								uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mExternalMemoryWin32Extension, 						uint32_t);
	#endif
#if defined(QUEST_VR)
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mMultiviewExtension, uint32_t);
#endif
#if defined(ENABLE_NSIGHT_AFTERMATH)
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mNVDeviceDiagnosticsCheckpointExtension, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mNVDeviceDiagnosticsConfigExtension, uint32_t );
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mAftermathSupport, uint32_t 					);
#endif
#if defined(DIRECT3D11)
	ZTF_BITFIELD_SETGET_DECLARE(GpuInfo, mPartialUpdateConstantBufferSupported, uint32_t);	
#endif

    typedef struct ztf_RendererContext
    {
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        union
        {
#endif
#if defined(DIRECT3D12)
            struct
            {
#if defined(XBOX)
                IDXGIFactory2* pDXGIFactory;
#elif defined(DIRECT3D12)
                IDXGIFactory6* pDXGIFactory;
                ID3D12Debug* pDebug;
#if defined(_WINDOWS) && defined(DRED)
                ID3D12DeviceRemovedExtendedDataSettings* pDredSettings;
#endif
#endif
            } mDx;
#endif
#if defined(VULKAN)
            struct
            {
                VkInstance               pInstance;
                VkDebugUtilsMessengerEXT pDebugUtilsMessenger;
                VkDebugReportCallbackEXT pDebugReport;
				uint32_t 				 mVkBitfield;
            } mVk;
#endif
#if defined(DIRECT3D11)
            struct
            {
                IDXGIFactory1* pDXGIFactory;
            } mDx11;
#endif
#if defined(ZTF_USE_MULTIPLE_RENDER_APIS)
        };
#endif
#if defined(METAL)
        struct
        {
            uint32_t mExtendedEncoderDebugReport : 1;
        } mMtl;
#endif
        ztf_GpuInfo  mGpus[ZTF_MAX_MULTIPLE_GPUS];
        uint32_t mGpuCount;
    } ztf_RendererContext;

	ZTF_BITFIELD_SETGET_DECLARE(RendererContext, mDebugUtilsExtension, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RendererContext, mDebugReportExtension, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(RendererContext, mDeviceGroupCreationExtension, uint32_t);

    // Indirect command structure define
    typedef struct ztf_IndirectArgument
    {
        ztf_IndirectArgumentType mType;
        uint32_t             mOffset;
    } ztf_IndirectArgument;

    typedef struct ztf_IndirectArgumentDescriptor
    {
        ztf_IndirectArgumentType mType;
        uint32_t             mIndex;
        uint32_t             mByteSize;
    } ztf_IndirectArgumentDescriptor;

    typedef struct ztf_CommandSignatureDesc
    {
        ztf_RootSignature* pRootSignature;
        ztf_IndirectArgumentDescriptor* pArgDescs;
        uint32_t                    mIndirectArgCount;
        /// Set to true if indirect argument struct should not be aligned to 16 bytes
        bool                        mPacked;
    } ztf_CommandSignatureDesc;

    typedef struct ztf_CommandSignature
    {
#if defined(DIRECT3D12)
        ID3D12CommandSignature* pHandle;
#endif
        ztf_IndirectArgumentType mDrawType;
        uint32_t             mStride;
    } ztf_CommandSignature;

    typedef struct ztf_DescriptorSetDesc
    {
        ztf_RootSignature* pRootSignature;
        ztf_DescriptorUpdateFrequency mUpdateFrequency;
        uint32_t                  mMaxSets;
        uint32_t                  mNodeIndex;
    } ztf_DescriptorSetDesc;

    typedef struct ztf_QueueSubmitDesc
    {
        ztf_Cmd** ppCmds;
        ztf_Fence* pSignalFence;
        ztf_Semaphore** ppWaitSemaphores;
        ztf_Semaphore** ppSignalSemaphores;
        uint32_t    mCmdCount;
        uint32_t    mWaitSemaphoreCount;
        uint32_t    mSignalSemaphoreCount;
        bool        mSubmitDone;
    } ztf_QueueSubmitDesc;

    typedef struct ztf_QueuePresentDesc
    {
        ztf_SwapChain* pSwapChain;
        ztf_Semaphore** ppWaitSemaphores;
        uint32_t    mWaitSemaphoreCount;
        uint8_t     mIndex;
        bool        mSubmitDone;
    } ztf_QueuePresentDesc;

    typedef struct ztf_BindRenderTargetDesc
    {
        ztf_RenderTarget* pRenderTarget;
        ztf_LoadActionType  mLoadAction;
        ztf_StoreActionType mStoreAction;
        ztf_ClearValue      mClearValue;
        ztf_LoadActionType  mLoadActionStencil;
        ztf_StoreActionType mStoreActionStencil;
        uint32_t        mArraySlice;
		uint32_t        mBitfield;
    } ztf_BindRenderTargetDesc;

	ZTF_BITFIELD_SETGET_DECLARE(BindRenderTargetDesc, mMipSlice, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindRenderTargetDesc, mOverrideClearValue, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindRenderTargetDesc, mUseArraySlice, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindRenderTargetDesc, mUseMipSlice, uint32_t);

    typedef struct ztf_BindDepthTargetDesc
    {
        ztf_RenderTarget* pDepthStencil;
        ztf_LoadActionType  mLoadAction;
        ztf_LoadActionType  mLoadActionStencil;
        ztf_StoreActionType mStoreAction;
        ztf_StoreActionType mStoreActionStencil;
        ztf_ClearValue      mClearValue;
        uint32_t        mArraySlice;
		uint32_t        mBitfield;
    } ztf_BindDepthTargetDesc;

	ZTF_BITFIELD_SETGET_DECLARE(BindDepthTargetDesc, mMipSlice, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindDepthTargetDesc, mOverrideClearValue, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindDepthTargetDesc, mUseArraySlice, uint32_t);
	ZTF_BITFIELD_SETGET_DECLARE(BindDepthTargetDesc, mUseMipSlice, uint32_t);

    typedef struct ztf_BindRenderTargetsDesc
    {
        uint32_t             mRenderTargetCount;
        ztf_BindRenderTargetDesc mRenderTargets[ZTF_MAX_RENDER_TARGET_ATTACHMENTS];
        ztf_BindDepthTargetDesc  mDepthStencil;
        // Explicit viewport for empty render pass
        uint32_t             mExtent[2];
    } ztf_BindRenderTargetsDesc;

    // clang-format off
    // Utilities functions
    ZTF_C_RENDERER_API void ztf_setRendererInitializationError(const char* reason);
    ZTF_C_RENDERER_API bool ztf_hasRendererInitializationError(const char** outReason);

    // API functions

    // Multiple renderer API (optional)
    ZTF_C_RENDERER_API void ztf_initRendererContext(const char* appName, const ztf_RendererContextDesc* pSettings, ztf_RendererContext** ppContext);
    ZTF_C_RENDERER_API void ztf_exitRendererContext(ztf_RendererContext* pContext);

    // allocates memory and initializes the renderer -> returns pRenderer
    //
    ZTF_C_RENDERER_API void ztf_initRenderer(const char* appName, const ztf_RendererDesc* pSettings, ztf_Renderer** ppRenderer);
    ZTF_C_RENDERER_API void ztf_exitRenderer(ztf_Renderer* pRenderer);

    ZTF_C_RENDERER_API void ztf_addFence(ztf_Renderer* pRenderer, ztf_Fence** ppFence);
    ZTF_C_RENDERER_API void ztf_removeFence(ztf_Renderer* pRenderer, ztf_Fence* pFence);
                       
    ZTF_C_RENDERER_API void ztf_addSemaphore(ztf_Renderer* pRenderer, ztf_Semaphore** ppSemaphore);
    ZTF_C_RENDERER_API void ztf_removeSemaphore(ztf_Renderer* pRenderer, ztf_Semaphore* pSemaphore);
                       
    ZTF_C_RENDERER_API void ztf_addQueue(ztf_Renderer* pRenderer, ztf_QueueDesc* pQDesc, ztf_Queue** ppQueue);
    ZTF_C_RENDERER_API void ztf_removeQueue(ztf_Renderer* pRenderer, ztf_Queue* pQueue);
                       
    ZTF_C_RENDERER_API void ztf_addSwapChain(ztf_Renderer* pRenderer, const ztf_SwapChainDesc* pDesc, ztf_SwapChain** ppSwapChain);
    ZTF_C_RENDERER_API void ztf_removeSwapChain(ztf_Renderer* pRenderer, ztf_SwapChain* pSwapChain);
                       
    // memory function 
    ZTF_C_RENDERER_API void ztf_addResourceHeap(ztf_Renderer* pRenderer, const ztf_ResourceHeapDesc* pDesc, ztf_ResourceHeap** ppHeap);
    ZTF_C_RENDERER_API void ztf_removeResourceHeap(ztf_Renderer* pRenderer, ztf_ResourceHeap* pHeap);

    // command pool functions
    ZTF_C_RENDERER_API void ztf_addCmdPool( ztf_Renderer* pRenderer, const ztf_CmdPoolDesc* pDesc, ztf_CmdPool** ppCmdPool);
    ZTF_C_RENDERER_API void ztf_removeCmdPool( ztf_Renderer* pRenderer, ztf_CmdPool* pCmdPool);
    ZTF_C_RENDERER_API void ztf_addCmd( ztf_Renderer* pRenderer, const ztf_CmdDesc* pDesc, ztf_Cmd** ppCmd);
    ZTF_C_RENDERER_API void ztf_removeCmd( ztf_Renderer* pRenderer, ztf_Cmd* pCmd);
    ZTF_C_RENDERER_API void ztf_addCmd_n( ztf_Renderer* pRenderer, const ztf_CmdDesc* pDesc, uint32_t cmdCount, ztf_Cmd*** pppCmds);
    ZTF_C_RENDERER_API void ztf_removeCmd_n( ztf_Renderer* pRenderer, uint32_t cmdCount, ztf_Cmd** ppCmds);

    //
    // All buffer, texture loading handled by resource system -> IResourceLoader.*
    //

    ZTF_C_RENDERER_API void ztf_addRenderTarget( ztf_Renderer* pRenderer, const ztf_RenderTargetDesc* pDesc, ztf_RenderTarget** ppRenderTarget)                                                 ;
    ZTF_C_RENDERER_API void ztf_removeRenderTarget( ztf_Renderer* pRenderer, ztf_RenderTarget* pRenderTarget)                                                                                   ;
    ZTF_C_RENDERER_API void ztf_addSampler( ztf_Renderer* pRenderer, const ztf_SamplerDesc* pDesc, ztf_Sampler** ppSampler)                                                                     ;
    ZTF_C_RENDERER_API void ztf_removeSampler( ztf_Renderer* pRenderer, ztf_Sampler* pSampler)                                                                                                  ;
                                                                                                                                                                                            
    // shader function                                                                                                                                                                      
    ZTF_C_RENDERER_API void ztf_addShaderBinary( ztf_Renderer* pRenderer, const ztf_BinaryShaderDesc* pDesc, ztf_Shader** ppShaderProgram)                                                      ;
    ZTF_C_RENDERER_API void ztf_removeShader( ztf_Renderer* pRenderer, ztf_Shader* pShaderProgram)                                                                                              ;
                                                                                                                                                                                            
    ZTF_C_RENDERER_API void ztf_addRootSignature( ztf_Renderer* pRenderer, const ztf_RootSignatureDesc* pDesc, ztf_RootSignature** ppRootSignature)                                             ;
    ZTF_C_RENDERER_API void ztf_removeRootSignature( ztf_Renderer* pRenderer, ztf_RootSignature* pRootSignature)                                                                                ;
    ZTF_C_RENDERER_API uint32_t ztf_getDescriptorIndexFromName( const ztf_RootSignature* pRootSignature, const char* pName)                                                                     ;
                                                                                                                                                                                            
    // pipeline functions                                                                                                                                                                   
    ZTF_C_RENDERER_API void ztf_addPipeline( ztf_Renderer* pRenderer, const ztf_PipelineDesc* pPipelineSettings, ztf_Pipeline** ppPipeline)                                                     ;
    ZTF_C_RENDERER_API void ztf_removePipeline( ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline)                                                                                               ;
    ZTF_C_RENDERER_API void ztf_addPipelineCache( ztf_Renderer* pRenderer, const ztf_PipelineCacheDesc* pDesc, ztf_PipelineCache** ppPipelineCache)                                             ;
    ZTF_C_RENDERER_API void ztf_getPipelineCacheData( ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache, size_t* pSize, void* pData)                                                   ;
#if defined(SHADER_STATS_AVAILABLE)                                                                                                                                                         
    ZTF_C_RENDERER_API void ztf_addPipelineStats( ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline, bool generateDisassembly, ztf_PipelineStats* pOutStats);                                    ;
    ZTF_C_RENDERER_API void ztf_removePipelineStats( ztf_Renderer* pRenderer, ztf_PipelineStats* pStats);                                                                                       ;
#endif                                                                                                                                                                                      
    ZTF_C_RENDERER_API void ztf_removePipelineCache( ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache)                                                                                ;
                                                                                                                                                                                            
    // Descriptor Set functions                                                                                                                                                             
    ZTF_C_RENDERER_API void ztf_addDescriptorSet( ztf_Renderer* pRenderer, const ztf_DescriptorSetDesc* pDesc, ztf_DescriptorSet** ppDescriptorSet)                                             ;
    ZTF_C_RENDERER_API void ztf_removeDescriptorSet( ztf_Renderer* pRenderer, ztf_DescriptorSet* pDescriptorSet)                                                                                ;
    ZTF_C_RENDERER_API void ztf_updateDescriptorSet( ztf_Renderer* pRenderer, uint32_t index, ztf_DescriptorSet* pDescriptorSet, uint32_t count, const ztf_DescriptorData* pParams)             ;
                                                                                                                                                                                            
    // command buffer functions                                                                                                                                                             
    ZTF_C_RENDERER_API void ztf_resetCmdPool( ztf_Renderer* pRenderer, ztf_CmdPool* pCmdPool)                                                                                                   ;
    ZTF_C_RENDERER_API void ztf_beginCmd( ztf_Cmd* pCmd)                                                                                                                                        ;
    ZTF_C_RENDERER_API void ztf_endCmd( ztf_Cmd* pCmd)                                                                                                                                          ;
    ZTF_C_RENDERER_API void ztf_cmdBindRenderTargets( ztf_Cmd* pCmd, const ztf_BindRenderTargetsDesc* pDesc)                                                                                    ;
    ZTF_C_RENDERER_API void ztf_cmdSetSampleLocations( ztf_Cmd* pCmd, ztf_SampleCount samplesCount, uint32_t gridSizeX, uint32_t gridSizeY, ztf_SampleLocations* plocations);                   ;
    ZTF_C_RENDERER_API void ztf_cmdSetViewport( ztf_Cmd* pCmd, float x, float y, float width, float height, float minDepth, float maxDepth)                                                     ;
    ZTF_C_RENDERER_API void ztf_cmdSetScissor( ztf_Cmd* pCmd, uint32_t x, uint32_t y, uint32_t width, uint32_t height)                                                                          ;
    ZTF_C_RENDERER_API void ztf_cmdSetStencilReferenceValue( ztf_Cmd* pCmd, uint32_t val)                                                                                                       ;
    ZTF_C_RENDERER_API void ztf_cmdBindPipeline( ztf_Cmd* pCmd, ztf_Pipeline* pPipeline)                                                                                                        ;
    ZTF_C_RENDERER_API void ztf_cmdBindDescriptorSet( ztf_Cmd* pCmd, uint32_t index, ztf_DescriptorSet* pDescriptorSet)                                                                         ;
    ZTF_C_RENDERER_API void ztf_cmdBindPushConstants( ztf_Cmd* pCmd, ztf_RootSignature* pRootSignature, uint32_t paramIndex, const void* pConstants)                                            ;
    ZTF_C_RENDERER_API void ztf_cmdBindDescriptorSetWithRootCbvs( ztf_Cmd* pCmd, uint32_t index, ztf_DescriptorSet* pDescriptorSet, uint32_t count, const ztf_DescriptorData* pParams)          ;
    ZTF_C_RENDERER_API void ztf_cmdBindIndexBuffer( ztf_Cmd* pCmd, ztf_Buffer* pBuffer, uint32_t indexType, uint64_t offset)                                                                        ;
    ZTF_C_RENDERER_API void ztf_cmdBindVertexBuffer( ztf_Cmd* pCmd, uint32_t bufferCount, ztf_Buffer** ppBuffers, const uint32_t* pStrides, const uint64_t* pOffsets)                           ;
    ZTF_C_RENDERER_API void ztf_cmdDraw(ztf_Cmd* pCmd, uint32_t vertexCount, uint32_t firstVertex)                                                                                              ;
    ZTF_C_RENDERER_API void ztf_cmdDrawInstanced( ztf_Cmd* pCmd, uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount, uint32_t firstInstance)                                    ;
    ZTF_C_RENDERER_API void ztf_cmdDrawIndexed( ztf_Cmd* pCmd, uint32_t indexCount, uint32_t firstIndex, uint32_t firstVertex)                                                                  ;
    ZTF_C_RENDERER_API void ztf_cmdDrawIndexedInstanced( ztf_Cmd* pCmd, uint32_t indexCount, uint32_t firstIndex, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)         ;
    ZTF_C_RENDERER_API void ztf_cmdDispatch(ztf_Cmd* pCmd, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)                                                                    ;

    // Transition Commands
    ZTF_C_RENDERER_API void ztf_cmdResourceBarrier(ztf_Cmd* pCmd, uint32_t bufferBarrierCount, ztf_BufferBarrier* pBufferBarriers, uint32_t textureBarrierCount, ztf_TextureBarrier* pTextureBarriers, uint32_t rtBarrierCount, ztf_RenderTargetBarrier* pRtBarriers);

    // queue/fence/swapchain functions
    ZTF_C_RENDERER_API void ztf_acquireNextImage( ztf_Renderer* pRenderer, ztf_SwapChain* pSwapChain, ztf_Semaphore* pSignalSemaphore, ztf_Fence* pFence, uint32_t* pImageIndex)                ;
    ZTF_C_RENDERER_API void ztf_queueSubmit(ztf_Queue* pQueue, const ztf_QueueSubmitDesc* pDesc)                                                                                                ;
    ZTF_C_RENDERER_API void ztf_queuePresent(ztf_Queue* pQueue, const ztf_QueuePresentDesc* pDesc)                                                                                              ;
    ZTF_C_RENDERER_API void ztf_waitQueueIdle(ztf_Queue* pQueue)                                                                                                                                ;
    ZTF_C_RENDERER_API void ztf_getFenceStatus(ztf_Renderer* pRenderer, ztf_Fence* pFence, ztf_FenceStatus* pFenceStatus)                                                                       ;
    ZTF_C_RENDERER_API void ztf_waitForFences(ztf_Renderer* pRenderer, uint32_t fenceCount, ztf_Fence** ppFences)                                                                               ;
    ZTF_C_RENDERER_API void ztf_toggleVSync(ztf_Renderer* pRenderer, ztf_SwapChain** ppSwapchain)                                                                                               ;
                                                                                                                                                                                            
    //Returns the recommended format for the swapchain.                                                                                                                                     
    //If true is passed for the hintHDR parameter, it will return an HDR format IF the platform supports it                                                                                 
    //If false is passed or the platform does not support HDR a non HDR format is returned.                                                                                                 
    //If true is passed for the hintSrgb parameter, it will return format that is will do gamma correction automatically                                                                    
    //If false is passed for the hintSrgb parameter the gamma correction should be done as a postprocess step before submitting image to swapchain                                          
    ZTF_C_RENDERER_API TinyImageFormat ztf_getSupportedSwapchainFormat( ztf_Renderer* pRenderer, const ztf_SwapChainDesc* pDesc, ztf_ColorSpace colorSpace)                                     ;
    ZTF_C_RENDERER_API uint32_t ztf_getRecommendedSwapchainImageCount( ztf_Renderer* pRenderer, const ztf_WindowHandle* hwnd)                                                                   ;
                                                                                                                                                                                            
    //indirect Draw functions                                                                                                                                                              
    ZTF_C_RENDERER_API void ztf_addIndirectCommandSignature( ztf_Renderer* pRenderer, const ztf_CommandSignatureDesc* pDesc, ztf_CommandSignature** ppCommandSignature)                         ;
    ZTF_C_RENDERER_API void ztf_removeIndirectCommandSignature( ztf_Renderer* pRenderer, ztf_CommandSignature* pCommandSignature)                                                               ;
    ZTF_C_RENDERER_API void ztf_cmdExecuteIndirect( ztf_Cmd* pCmd, ztf_CommandSignature* pCommandSignature, unsigned int maxCommandCount, ztf_Buffer* pIndirectBuffer, uint64_t bufferOffset, ztf_Buffer* pCounterBuffer, uint64_t counterBufferOffset);

    /************************************************************************/
    // GPU Query Interface
    /************************************************************************/
    ZTF_C_RENDERER_API void ztf_getTimestampFrequency( ztf_Queue* pQueue, double* pFrequency)                                                                                                   ;
    ZTF_C_RENDERER_API void ztf_addQueryPool( ztf_Renderer* pRenderer, const ztf_QueryPoolDesc* pDesc, ztf_QueryPool** ppQueryPool)                                                             ;
    ZTF_C_RENDERER_API void ztf_removeQueryPool( ztf_Renderer* pRenderer, ztf_QueryPool* pQueryPool)                                                                                            ;
    ZTF_C_RENDERER_API void ztf_cmdBeginQuery( ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, ztf_QueryDesc* pQuery)                                                                                 ;
    ZTF_C_RENDERER_API void ztf_cmdEndQuery( ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, ztf_QueryDesc* pQuery)                                                                                   ;
    ZTF_C_RENDERER_API void ztf_cmdResolveQuery( ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, uint32_t startQuery, uint32_t queryCount)                                                            ;
    ZTF_C_RENDERER_API void ztf_cmdResetQuery( ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, uint32_t startQuery, uint32_t queryCount)                                                              ;
    ZTF_C_RENDERER_API void ztf_getQueryData( ztf_Renderer* pRenderer, ztf_QueryPool* pQueryPool, uint32_t queryIndex, ztf_QueryData* pOutData)                                                 ;
    /************************************************************************/                                                                                                              
    // Stats Info Interface                                                                                                                                                                 
    /************************************************************************/                                                                                                              
    ZTF_C_RENDERER_API void ztf_calculateMemoryStats( ztf_Renderer* pRenderer, char** ppStats)                                                                                                  ;
    ZTF_C_RENDERER_API void ztf_calculateMemoryUse( ztf_Renderer* pRenderer, uint64_t* usedBytes, uint64_t* totalAllocatedBytes)                                                                ;
    ZTF_C_RENDERER_API void ztf_freeMemoryStats( ztf_Renderer* pRenderer, char* pStats)                                                                                                         ;
    /************************************************************************/                                                                                                              
    // Debug Marker Interface                                                                                                                                                               
    /************************************************************************/                                                                                                              
    ZTF_C_RENDERER_API void ztf_cmdBeginDebugMarker( ztf_Cmd* pCmd, float r, float g, float b, const char* pName)                                                                               ;
    ZTF_C_RENDERER_API void ztf_cmdEndDebugMarker( ztf_Cmd* pCmd)                                                                                                                               ;
    ZTF_C_RENDERER_API void ztf_cmdAddDebugMarker( ztf_Cmd* pCmd, float r, float g, float b, const char* pName)                                                                                 ;
    ZTF_C_RENDERER_API void ztf_cmdWriteMarker( ztf_Cmd* pCmd, const ztf_MarkerDesc* pDesc);                                                                                                    ;
    /************************************************************************/                                                                                                              
    // Resource Debug Naming Interface                                                                                                                                                      
    /************************************************************************/                                                                                                              
    ZTF_C_RENDERER_API void ztf_setBufferName( ztf_Renderer* pRenderer, ztf_Buffer* pBuffer, const char* pName)                                                                                 ;
    ZTF_C_RENDERER_API void ztf_setTextureName( ztf_Renderer* pRenderer, ztf_Texture* pTexture, const char* pName)                                                                              ;
    ZTF_C_RENDERER_API void ztf_setRenderTargetName( ztf_Renderer* pRenderer, ztf_RenderTarget* pRenderTarget, const char* pName)                                                               ;
    ZTF_C_RENDERER_API void ztf_setPipelineName( ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline, const char* pName)                                                                           ;
    /************************************************************************/                                                                                                              
    /************************************************************************/                                                                                                              
    // clang-format on

#ifdef __cplusplus
}
#endif