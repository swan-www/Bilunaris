#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Graphics\Interfaces\IGraphics.h"

static_assert(::MAX_INSTANCE_EXTENSIONS == 64, "API_Verifier: '::MAX_INSTANCE_EXTENSIONS == 64' evaluated to false.");
static_assert(::MAX_DEVICE_EXTENSIONS == 64, "API_Verifier: '::MAX_DEVICE_EXTENSIONS == 64' evaluated to false.");
static_assert(::MAX_LINKED_GPUS == 4, "API_Verifier: '::MAX_LINKED_GPUS == 4' evaluated to false.");
static_assert(::MAX_UNLINKED_GPUS == 4, "API_Verifier: '::MAX_UNLINKED_GPUS == 4' evaluated to false.");
static_assert(::MAX_MULTIPLE_GPUS == 4, "API_Verifier: '::MAX_MULTIPLE_GPUS == 4' evaluated to false.");
static_assert(::MAX_RENDER_TARGET_ATTACHMENTS == 8, "API_Verifier: '::MAX_RENDER_TARGET_ATTACHMENTS == 8' evaluated to false.");
static_assert(::MAX_VERTEX_BINDINGS == 15, "API_Verifier: '::MAX_VERTEX_BINDINGS == 15' evaluated to false.");
static_assert(::MAX_VERTEX_ATTRIBS == 15, "API_Verifier: '::MAX_VERTEX_ATTRIBS == 15' evaluated to false.");
static_assert(::MAX_RESOURCE_NAME_LENGTH == 256, "API_Verifier: '::MAX_RESOURCE_NAME_LENGTH == 256' evaluated to false.");
static_assert(::MAX_SEMANTIC_NAME_LENGTH == 128, "API_Verifier: '::MAX_SEMANTIC_NAME_LENGTH == 128' evaluated to false.");
static_assert(::MAX_DEBUG_NAME_LENGTH == 128, "API_Verifier: '::MAX_DEBUG_NAME_LENGTH == 128' evaluated to false.");
static_assert(::MAX_MIP_LEVELS == -1, "API_Verifier: '::MAX_MIP_LEVELS == -1' evaluated to false.");
static_assert(::MAX_SWAPCHAIN_IMAGES == 3, "API_Verifier: '::MAX_SWAPCHAIN_IMAGES == 3' evaluated to false.");
static_assert(::MAX_GPU_VENDOR_STRING_LENGTH == 256, "API_Verifier: '::MAX_GPU_VENDOR_STRING_LENGTH == 256' evaluated to false.");
static_assert(::MAX_SAMPLE_LOCATIONS == 16, "API_Verifier: '::MAX_SAMPLE_LOCATIONS == 16' evaluated to false.");
static_assert(::MAX_PLANE_COUNT == 3, "API_Verifier: '::MAX_PLANE_COUNT == 3' evaluated to false.");
static_assert(::MAX_DESCRIPTOR_POOL_SIZE_ARRAY_COUNT == 11, "API_Verifier: '::MAX_DESCRIPTOR_POOL_SIZE_ARRAY_COUNT == 11' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<RendererApi>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<RendererApi>,int>' evaluated to false.");
static_assert(RendererApi::RENDERER_API_D3D12 == 0, "API_Verifier: 'RendererApi::RENDERER_API_D3D12 == 0' evaluated to false.");
static_assert(RendererApi::RENDERER_API_VULKAN == 1, "API_Verifier: 'RendererApi::RENDERER_API_VULKAN == 1' evaluated to false.");
static_assert(RendererApi::RENDERER_API_D3D11 == 2, "API_Verifier: 'RendererApi::RENDERER_API_D3D11 == 2' evaluated to false.");
static_assert(RendererApi::RENDERER_API_COUNT == 3, "API_Verifier: 'RendererApi::RENDERER_API_COUNT == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<QueueType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<QueueType>,int>' evaluated to false.");
static_assert(QueueType::QUEUE_TYPE_GRAPHICS == 0, "API_Verifier: 'QueueType::QUEUE_TYPE_GRAPHICS == 0' evaluated to false.");
static_assert(QueueType::QUEUE_TYPE_TRANSFER == 1, "API_Verifier: 'QueueType::QUEUE_TYPE_TRANSFER == 1' evaluated to false.");
static_assert(QueueType::QUEUE_TYPE_COMPUTE == 2, "API_Verifier: 'QueueType::QUEUE_TYPE_COMPUTE == 2' evaluated to false.");
static_assert(QueueType::MAX_QUEUE_TYPE == 3, "API_Verifier: 'QueueType::MAX_QUEUE_TYPE == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<QueueFlag>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<QueueFlag>,int>' evaluated to false.");
static_assert(QueueFlag::QUEUE_FLAG_NONE == 0, "API_Verifier: 'QueueFlag::QUEUE_FLAG_NONE == 0' evaluated to false.");
static_assert(QueueFlag::QUEUE_FLAG_DISABLE_GPU_TIMEOUT == 1, "API_Verifier: 'QueueFlag::QUEUE_FLAG_DISABLE_GPU_TIMEOUT == 1' evaluated to false.");
static_assert(QueueFlag::QUEUE_FLAG_INIT_MICROPROFILE == 2, "API_Verifier: 'QueueFlag::QUEUE_FLAG_INIT_MICROPROFILE == 2' evaluated to false.");
static_assert(QueueFlag::MAX_QUEUE_FLAG == -1, "API_Verifier: 'QueueFlag::MAX_QUEUE_FLAG == -1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<QueuePriority>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<QueuePriority>,int>' evaluated to false.");
static_assert(QueuePriority::QUEUE_PRIORITY_NORMAL == 0, "API_Verifier: 'QueuePriority::QUEUE_PRIORITY_NORMAL == 0' evaluated to false.");
static_assert(QueuePriority::QUEUE_PRIORITY_HIGH == 1, "API_Verifier: 'QueuePriority::QUEUE_PRIORITY_HIGH == 1' evaluated to false.");
static_assert(QueuePriority::QUEUE_PRIORITY_GLOBAL_REALTIME == 2, "API_Verifier: 'QueuePriority::QUEUE_PRIORITY_GLOBAL_REALTIME == 2' evaluated to false.");
static_assert(QueuePriority::MAX_QUEUE_PRIORITY == 3, "API_Verifier: 'QueuePriority::MAX_QUEUE_PRIORITY == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<LoadActionType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<LoadActionType>,int>' evaluated to false.");
static_assert(LoadActionType::LOAD_ACTION_DONTCARE == 0, "API_Verifier: 'LoadActionType::LOAD_ACTION_DONTCARE == 0' evaluated to false.");
static_assert(LoadActionType::LOAD_ACTION_LOAD == 1, "API_Verifier: 'LoadActionType::LOAD_ACTION_LOAD == 1' evaluated to false.");
static_assert(LoadActionType::LOAD_ACTION_CLEAR == 2, "API_Verifier: 'LoadActionType::LOAD_ACTION_CLEAR == 2' evaluated to false.");
static_assert(LoadActionType::MAX_LOAD_ACTION == 3, "API_Verifier: 'LoadActionType::MAX_LOAD_ACTION == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<StoreActionType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<StoreActionType>,int>' evaluated to false.");
static_assert(StoreActionType::STORE_ACTION_STORE == 0, "API_Verifier: 'StoreActionType::STORE_ACTION_STORE == 0' evaluated to false.");
static_assert(StoreActionType::STORE_ACTION_DONTCARE == 1, "API_Verifier: 'StoreActionType::STORE_ACTION_DONTCARE == 1' evaluated to false.");
static_assert(StoreActionType::STORE_ACTION_NONE == 2, "API_Verifier: 'StoreActionType::STORE_ACTION_NONE == 2' evaluated to false.");
static_assert(StoreActionType::MAX_STORE_ACTION == 3, "API_Verifier: 'StoreActionType::MAX_STORE_ACTION == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ResourceState>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ResourceState>,int>' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_UNDEFINED == 0, "API_Verifier: 'ResourceState::RESOURCE_STATE_UNDEFINED == 0' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER == 1, "API_Verifier: 'ResourceState::RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER == 1' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_INDEX_BUFFER == 2, "API_Verifier: 'ResourceState::RESOURCE_STATE_INDEX_BUFFER == 2' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_RENDER_TARGET == 4, "API_Verifier: 'ResourceState::RESOURCE_STATE_RENDER_TARGET == 4' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_UNORDERED_ACCESS == 8, "API_Verifier: 'ResourceState::RESOURCE_STATE_UNORDERED_ACCESS == 8' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_DEPTH_WRITE == 16, "API_Verifier: 'ResourceState::RESOURCE_STATE_DEPTH_WRITE == 16' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_DEPTH_READ == 32, "API_Verifier: 'ResourceState::RESOURCE_STATE_DEPTH_READ == 32' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE == 64, "API_Verifier: 'ResourceState::RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE == 64' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_PIXEL_SHADER_RESOURCE == 128, "API_Verifier: 'ResourceState::RESOURCE_STATE_PIXEL_SHADER_RESOURCE == 128' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_SHADER_RESOURCE == 192, "API_Verifier: 'ResourceState::RESOURCE_STATE_SHADER_RESOURCE == 192' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_STREAM_OUT == 256, "API_Verifier: 'ResourceState::RESOURCE_STATE_STREAM_OUT == 256' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_INDIRECT_ARGUMENT == 512, "API_Verifier: 'ResourceState::RESOURCE_STATE_INDIRECT_ARGUMENT == 512' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_COPY_DEST == 1024, "API_Verifier: 'ResourceState::RESOURCE_STATE_COPY_DEST == 1024' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_COPY_SOURCE == 2048, "API_Verifier: 'ResourceState::RESOURCE_STATE_COPY_SOURCE == 2048' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_GENERIC_READ == 2755, "API_Verifier: 'ResourceState::RESOURCE_STATE_GENERIC_READ == 2755' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_PRESENT == 4096, "API_Verifier: 'ResourceState::RESOURCE_STATE_PRESENT == 4096' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_COMMON == 8192, "API_Verifier: 'ResourceState::RESOURCE_STATE_COMMON == 8192' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_ACCELERATION_STRUCTURE_READ == 16384, "API_Verifier: 'ResourceState::RESOURCE_STATE_ACCELERATION_STRUCTURE_READ == 16384' evaluated to false.");
static_assert(ResourceState::RESOURCE_STATE_ACCELERATION_STRUCTURE_WRITE == 32768, "API_Verifier: 'ResourceState::RESOURCE_STATE_ACCELERATION_STRUCTURE_WRITE == 32768' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ResourceMemoryUsage>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ResourceMemoryUsage>,int>' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_UNKNOWN == 0, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_UNKNOWN == 0' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_GPU_ONLY == 1, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_GPU_ONLY == 1' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_CPU_ONLY == 2, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_CPU_ONLY == 2' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_CPU_TO_GPU == 3, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_CPU_TO_GPU == 3' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_GPU_TO_CPU == 4, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_GPU_TO_CPU == 4' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_COUNT == 5, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_COUNT == 5' evaluated to false.");
static_assert(ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_MAX_ENUM == 2147483647, "API_Verifier: 'ResourceMemoryUsage::RESOURCE_MEMORY_USAGE_MAX_ENUM == 2147483647' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<IndirectArgumentType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<IndirectArgumentType>,int>' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_ARG_INVALID == 0, "API_Verifier: 'IndirectArgumentType::INDIRECT_ARG_INVALID == 0' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_DRAW == 1, "API_Verifier: 'IndirectArgumentType::INDIRECT_DRAW == 1' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_DRAW_INDEX == 2, "API_Verifier: 'IndirectArgumentType::INDIRECT_DRAW_INDEX == 2' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_DISPATCH == 3, "API_Verifier: 'IndirectArgumentType::INDIRECT_DISPATCH == 3' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_VERTEX_BUFFER == 4, "API_Verifier: 'IndirectArgumentType::INDIRECT_VERTEX_BUFFER == 4' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_INDEX_BUFFER == 5, "API_Verifier: 'IndirectArgumentType::INDIRECT_INDEX_BUFFER == 5' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_CONSTANT == 6, "API_Verifier: 'IndirectArgumentType::INDIRECT_CONSTANT == 6' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_CONSTANT_BUFFER_VIEW == 7, "API_Verifier: 'IndirectArgumentType::INDIRECT_CONSTANT_BUFFER_VIEW == 7' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_SHADER_RESOURCE_VIEW == 8, "API_Verifier: 'IndirectArgumentType::INDIRECT_SHADER_RESOURCE_VIEW == 8' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_UNORDERED_ACCESS_VIEW == 9, "API_Verifier: 'IndirectArgumentType::INDIRECT_UNORDERED_ACCESS_VIEW == 9' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_COMMAND_BUFFER == 10, "API_Verifier: 'IndirectArgumentType::INDIRECT_COMMAND_BUFFER == 10' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_COMMAND_BUFFER_RESET == 11, "API_Verifier: 'IndirectArgumentType::INDIRECT_COMMAND_BUFFER_RESET == 11' evaluated to false.");
static_assert(IndirectArgumentType::INDIRECT_COMMAND_BUFFER_OPTIMIZE == 12, "API_Verifier: 'IndirectArgumentType::INDIRECT_COMMAND_BUFFER_OPTIMIZE == 12' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<DescriptorType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<DescriptorType>,int>' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_UNDEFINED == 0, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_UNDEFINED == 0' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_SAMPLER == 1, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_SAMPLER == 1' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_TEXTURE == 2, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_TEXTURE == 2' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RW_TEXTURE == 4, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RW_TEXTURE == 4' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_BUFFER == 8, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_BUFFER == 8' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_BUFFER_RAW == 24, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_BUFFER_RAW == 24' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RW_BUFFER == 32, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RW_BUFFER == 32' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RW_BUFFER_RAW == 96, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RW_BUFFER_RAW == 96' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_UNIFORM_BUFFER == 128, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_UNIFORM_BUFFER == 128' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_ROOT_CONSTANT == 256, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_ROOT_CONSTANT == 256' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_VERTEX_BUFFER == 512, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_VERTEX_BUFFER == 512' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_INDEX_BUFFER == 1024, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_INDEX_BUFFER == 1024' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_INDIRECT_BUFFER == 2048, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_INDIRECT_BUFFER == 2048' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_TEXTURE_CUBE == 4098, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_TEXTURE_CUBE == 4098' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_MIP_SLICES == 8192, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_MIP_SLICES == 8192' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_ARRAY_SLICES == 16384, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_ARRAY_SLICES == 16384' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_DEPTH_SLICES == 32768, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RENDER_TARGET_DEPTH_SLICES == 32768' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_INDIRECT_COMMAND_BUFFER == 65536, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_INDIRECT_COMMAND_BUFFER == 65536' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE == 131072, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE == 131072' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_INPUT_ATTACHMENT == 262144, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_INPUT_ATTACHMENT == 262144' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_TEXEL_BUFFER == 524288, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_TEXEL_BUFFER == 524288' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_RW_TEXEL_BUFFER == 1048576, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_RW_TEXEL_BUFFER == 1048576' evaluated to false.");
static_assert(DescriptorType::DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER == 2097152, "API_Verifier: 'DescriptorType::DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER == 2097152' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<SampleCount>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<SampleCount>,int>' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_1 == 1, "API_Verifier: 'SampleCount::SAMPLE_COUNT_1 == 1' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_2 == 2, "API_Verifier: 'SampleCount::SAMPLE_COUNT_2 == 2' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_4 == 4, "API_Verifier: 'SampleCount::SAMPLE_COUNT_4 == 4' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_8 == 8, "API_Verifier: 'SampleCount::SAMPLE_COUNT_8 == 8' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_16 == 16, "API_Verifier: 'SampleCount::SAMPLE_COUNT_16 == 16' evaluated to false.");
static_assert(SampleCount::SAMPLE_COUNT_COUNT == 5, "API_Verifier: 'SampleCount::SAMPLE_COUNT_COUNT == 5' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ShaderStage>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ShaderStage>,int>' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_NONE == 0, "API_Verifier: 'ShaderStage::SHADER_STAGE_NONE == 0' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_VERT == 1, "API_Verifier: 'ShaderStage::SHADER_STAGE_VERT == 1' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_TESC == 2, "API_Verifier: 'ShaderStage::SHADER_STAGE_TESC == 2' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_TESE == 4, "API_Verifier: 'ShaderStage::SHADER_STAGE_TESE == 4' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_GEOM == 8, "API_Verifier: 'ShaderStage::SHADER_STAGE_GEOM == 8' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_FRAG == 16, "API_Verifier: 'ShaderStage::SHADER_STAGE_FRAG == 16' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_COMP == 32, "API_Verifier: 'ShaderStage::SHADER_STAGE_COMP == 32' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_ALL_GRAPHICS == 31, "API_Verifier: 'ShaderStage::SHADER_STAGE_ALL_GRAPHICS == 31' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_HULL == 2, "API_Verifier: 'ShaderStage::SHADER_STAGE_HULL == 2' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_DOMN == 4, "API_Verifier: 'ShaderStage::SHADER_STAGE_DOMN == 4' evaluated to false.");
static_assert(ShaderStage::SHADER_STAGE_COUNT == 6, "API_Verifier: 'ShaderStage::SHADER_STAGE_COUNT == 6' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ShaderStageIndex>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ShaderStageIndex>,int>' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_VERT == 0, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_VERT == 0' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_TESC == 1, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_TESC == 1' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_TESE == 2, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_TESE == 2' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_GEOM == 3, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_GEOM == 3' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_FRAG == 4, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_FRAG == 4' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_COMP == 5, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_COMP == 5' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_HULL == 1, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_HULL == 1' evaluated to false.");
static_assert(ShaderStageIndex::SHADER_STAGE_INDEX_DOMN == 2, "API_Verifier: 'ShaderStageIndex::SHADER_STAGE_INDEX_DOMN == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<PrimitiveTopology>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<PrimitiveTopology>,int>' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_POINT_LIST == 0, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_POINT_LIST == 0' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_LINE_LIST == 1, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_LINE_LIST == 1' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_LINE_STRIP == 2, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_LINE_STRIP == 2' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_TRI_LIST == 3, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_TRI_LIST == 3' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_TRI_STRIP == 4, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_TRI_STRIP == 4' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_PATCH_LIST == 5, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_PATCH_LIST == 5' evaluated to false.");
static_assert(PrimitiveTopology::PRIMITIVE_TOPO_COUNT == 6, "API_Verifier: 'PrimitiveTopology::PRIMITIVE_TOPO_COUNT == 6' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<IndexType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<IndexType>,int>' evaluated to false.");
static_assert(IndexType::INDEX_TYPE_UINT32 == 0, "API_Verifier: 'IndexType::INDEX_TYPE_UINT32 == 0' evaluated to false.");
static_assert(IndexType::INDEX_TYPE_UINT16 == 1, "API_Verifier: 'IndexType::INDEX_TYPE_UINT16 == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ShaderSemantic>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ShaderSemantic>,int>' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_UNDEFINED == 0, "API_Verifier: 'ShaderSemantic::SEMANTIC_UNDEFINED == 0' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_POSITION == 1, "API_Verifier: 'ShaderSemantic::SEMANTIC_POSITION == 1' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_NORMAL == 2, "API_Verifier: 'ShaderSemantic::SEMANTIC_NORMAL == 2' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_COLOR == 3, "API_Verifier: 'ShaderSemantic::SEMANTIC_COLOR == 3' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TANGENT == 4, "API_Verifier: 'ShaderSemantic::SEMANTIC_TANGENT == 4' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_BITANGENT == 5, "API_Verifier: 'ShaderSemantic::SEMANTIC_BITANGENT == 5' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_JOINTS == 6, "API_Verifier: 'ShaderSemantic::SEMANTIC_JOINTS == 6' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_WEIGHTS == 7, "API_Verifier: 'ShaderSemantic::SEMANTIC_WEIGHTS == 7' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_CUSTOM == 8, "API_Verifier: 'ShaderSemantic::SEMANTIC_CUSTOM == 8' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD0 == 9, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD0 == 9' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD1 == 10, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD1 == 10' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD2 == 11, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD2 == 11' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD3 == 12, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD3 == 12' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD4 == 13, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD4 == 13' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD5 == 14, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD5 == 14' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD6 == 15, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD6 == 15' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD7 == 16, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD7 == 16' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD8 == 17, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD8 == 17' evaluated to false.");
static_assert(ShaderSemantic::SEMANTIC_TEXCOORD9 == 18, "API_Verifier: 'ShaderSemantic::SEMANTIC_TEXCOORD9 == 18' evaluated to false.");
static_assert(ShaderSemantic::MAX_SEMANTICS == 19, "API_Verifier: 'ShaderSemantic::MAX_SEMANTICS == 19' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<BlendConstant>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<BlendConstant>,int>' evaluated to false.");
static_assert(BlendConstant::BC_ZERO == 0, "API_Verifier: 'BlendConstant::BC_ZERO == 0' evaluated to false.");
static_assert(BlendConstant::BC_ONE == 1, "API_Verifier: 'BlendConstant::BC_ONE == 1' evaluated to false.");
static_assert(BlendConstant::BC_SRC_COLOR == 2, "API_Verifier: 'BlendConstant::BC_SRC_COLOR == 2' evaluated to false.");
static_assert(BlendConstant::BC_ONE_MINUS_SRC_COLOR == 3, "API_Verifier: 'BlendConstant::BC_ONE_MINUS_SRC_COLOR == 3' evaluated to false.");
static_assert(BlendConstant::BC_DST_COLOR == 4, "API_Verifier: 'BlendConstant::BC_DST_COLOR == 4' evaluated to false.");
static_assert(BlendConstant::BC_ONE_MINUS_DST_COLOR == 5, "API_Verifier: 'BlendConstant::BC_ONE_MINUS_DST_COLOR == 5' evaluated to false.");
static_assert(BlendConstant::BC_SRC_ALPHA == 6, "API_Verifier: 'BlendConstant::BC_SRC_ALPHA == 6' evaluated to false.");
static_assert(BlendConstant::BC_ONE_MINUS_SRC_ALPHA == 7, "API_Verifier: 'BlendConstant::BC_ONE_MINUS_SRC_ALPHA == 7' evaluated to false.");
static_assert(BlendConstant::BC_DST_ALPHA == 8, "API_Verifier: 'BlendConstant::BC_DST_ALPHA == 8' evaluated to false.");
static_assert(BlendConstant::BC_ONE_MINUS_DST_ALPHA == 9, "API_Verifier: 'BlendConstant::BC_ONE_MINUS_DST_ALPHA == 9' evaluated to false.");
static_assert(BlendConstant::BC_SRC_ALPHA_SATURATE == 10, "API_Verifier: 'BlendConstant::BC_SRC_ALPHA_SATURATE == 10' evaluated to false.");
static_assert(BlendConstant::BC_BLEND_FACTOR == 11, "API_Verifier: 'BlendConstant::BC_BLEND_FACTOR == 11' evaluated to false.");
static_assert(BlendConstant::BC_ONE_MINUS_BLEND_FACTOR == 12, "API_Verifier: 'BlendConstant::BC_ONE_MINUS_BLEND_FACTOR == 12' evaluated to false.");
static_assert(BlendConstant::MAX_BLEND_CONSTANTS == 13, "API_Verifier: 'BlendConstant::MAX_BLEND_CONSTANTS == 13' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<BlendMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<BlendMode>,int>' evaluated to false.");
static_assert(BlendMode::BM_ADD == 0, "API_Verifier: 'BlendMode::BM_ADD == 0' evaluated to false.");
static_assert(BlendMode::BM_SUBTRACT == 1, "API_Verifier: 'BlendMode::BM_SUBTRACT == 1' evaluated to false.");
static_assert(BlendMode::BM_REVERSE_SUBTRACT == 2, "API_Verifier: 'BlendMode::BM_REVERSE_SUBTRACT == 2' evaluated to false.");
static_assert(BlendMode::BM_MIN == 3, "API_Verifier: 'BlendMode::BM_MIN == 3' evaluated to false.");
static_assert(BlendMode::BM_MAX == 4, "API_Verifier: 'BlendMode::BM_MAX == 4' evaluated to false.");
static_assert(BlendMode::MAX_BLEND_MODES == 5, "API_Verifier: 'BlendMode::MAX_BLEND_MODES == 5' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<CompareMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<CompareMode>,int>' evaluated to false.");
static_assert(CompareMode::CMP_NEVER == 0, "API_Verifier: 'CompareMode::CMP_NEVER == 0' evaluated to false.");
static_assert(CompareMode::CMP_LESS == 1, "API_Verifier: 'CompareMode::CMP_LESS == 1' evaluated to false.");
static_assert(CompareMode::CMP_EQUAL == 2, "API_Verifier: 'CompareMode::CMP_EQUAL == 2' evaluated to false.");
static_assert(CompareMode::CMP_LEQUAL == 3, "API_Verifier: 'CompareMode::CMP_LEQUAL == 3' evaluated to false.");
static_assert(CompareMode::CMP_GREATER == 4, "API_Verifier: 'CompareMode::CMP_GREATER == 4' evaluated to false.");
static_assert(CompareMode::CMP_NOTEQUAL == 5, "API_Verifier: 'CompareMode::CMP_NOTEQUAL == 5' evaluated to false.");
static_assert(CompareMode::CMP_GEQUAL == 6, "API_Verifier: 'CompareMode::CMP_GEQUAL == 6' evaluated to false.");
static_assert(CompareMode::CMP_ALWAYS == 7, "API_Verifier: 'CompareMode::CMP_ALWAYS == 7' evaluated to false.");
static_assert(CompareMode::MAX_COMPARE_MODES == 8, "API_Verifier: 'CompareMode::MAX_COMPARE_MODES == 8' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<StencilOp>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<StencilOp>,int>' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_KEEP == 0, "API_Verifier: 'StencilOp::STENCIL_OP_KEEP == 0' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_SET_ZERO == 1, "API_Verifier: 'StencilOp::STENCIL_OP_SET_ZERO == 1' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_REPLACE == 2, "API_Verifier: 'StencilOp::STENCIL_OP_REPLACE == 2' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_INVERT == 3, "API_Verifier: 'StencilOp::STENCIL_OP_INVERT == 3' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_INCR == 4, "API_Verifier: 'StencilOp::STENCIL_OP_INCR == 4' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_DECR == 5, "API_Verifier: 'StencilOp::STENCIL_OP_DECR == 5' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_INCR_SAT == 6, "API_Verifier: 'StencilOp::STENCIL_OP_INCR_SAT == 6' evaluated to false.");
static_assert(StencilOp::STENCIL_OP_DECR_SAT == 7, "API_Verifier: 'StencilOp::STENCIL_OP_DECR_SAT == 7' evaluated to false.");
static_assert(StencilOp::MAX_STENCIL_OPS == 8, "API_Verifier: 'StencilOp::MAX_STENCIL_OPS == 8' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ColorMask>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ColorMask>,int>' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_NONE == 0, "API_Verifier: 'ColorMask::COLOR_MASK_NONE == 0' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_RED == 1, "API_Verifier: 'ColorMask::COLOR_MASK_RED == 1' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_GREEN == 2, "API_Verifier: 'ColorMask::COLOR_MASK_GREEN == 2' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_BLUE == 4, "API_Verifier: 'ColorMask::COLOR_MASK_BLUE == 4' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_ALPHA == 8, "API_Verifier: 'ColorMask::COLOR_MASK_ALPHA == 8' evaluated to false.");
static_assert(ColorMask::COLOR_MASK_ALL == 15, "API_Verifier: 'ColorMask::COLOR_MASK_ALL == 15' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<BlendStateTargets>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<BlendStateTargets>,int>' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_0 == 1, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_0 == 1' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_1 == 2, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_1 == 2' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_2 == 4, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_2 == 4' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_3 == 8, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_3 == 8' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_4 == 16, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_4 == 16' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_5 == 32, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_5 == 32' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_6 == 64, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_6 == 64' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_7 == 128, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_7 == 128' evaluated to false.");
static_assert(BlendStateTargets::BLEND_STATE_TARGET_ALL == 255, "API_Verifier: 'BlendStateTargets::BLEND_STATE_TARGET_ALL == 255' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<CullMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<CullMode>,int>' evaluated to false.");
static_assert(CullMode::CULL_MODE_NONE == 0, "API_Verifier: 'CullMode::CULL_MODE_NONE == 0' evaluated to false.");
static_assert(CullMode::CULL_MODE_BACK == 1, "API_Verifier: 'CullMode::CULL_MODE_BACK == 1' evaluated to false.");
static_assert(CullMode::CULL_MODE_FRONT == 2, "API_Verifier: 'CullMode::CULL_MODE_FRONT == 2' evaluated to false.");
static_assert(CullMode::CULL_MODE_BOTH == 3, "API_Verifier: 'CullMode::CULL_MODE_BOTH == 3' evaluated to false.");
static_assert(CullMode::MAX_CULL_MODES == 4, "API_Verifier: 'CullMode::MAX_CULL_MODES == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<FrontFace>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<FrontFace>,int>' evaluated to false.");
static_assert(FrontFace::FRONT_FACE_CCW == 0, "API_Verifier: 'FrontFace::FRONT_FACE_CCW == 0' evaluated to false.");
static_assert(FrontFace::FRONT_FACE_CW == 1, "API_Verifier: 'FrontFace::FRONT_FACE_CW == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<FillMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<FillMode>,int>' evaluated to false.");
static_assert(FillMode::FILL_MODE_SOLID == 0, "API_Verifier: 'FillMode::FILL_MODE_SOLID == 0' evaluated to false.");
static_assert(FillMode::FILL_MODE_WIREFRAME == 1, "API_Verifier: 'FillMode::FILL_MODE_WIREFRAME == 1' evaluated to false.");
static_assert(FillMode::MAX_FILL_MODES == 2, "API_Verifier: 'FillMode::MAX_FILL_MODES == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<PipelineType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<PipelineType>,int>' evaluated to false.");
static_assert(PipelineType::PIPELINE_TYPE_UNDEFINED == 0, "API_Verifier: 'PipelineType::PIPELINE_TYPE_UNDEFINED == 0' evaluated to false.");
static_assert(PipelineType::PIPELINE_TYPE_COMPUTE == 1, "API_Verifier: 'PipelineType::PIPELINE_TYPE_COMPUTE == 1' evaluated to false.");
static_assert(PipelineType::PIPELINE_TYPE_GRAPHICS == 2, "API_Verifier: 'PipelineType::PIPELINE_TYPE_GRAPHICS == 2' evaluated to false.");
static_assert(PipelineType::PIPELINE_TYPE_COUNT == 3, "API_Verifier: 'PipelineType::PIPELINE_TYPE_COUNT == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<FilterType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<FilterType>,int>' evaluated to false.");
static_assert(FilterType::FILTER_NEAREST == 0, "API_Verifier: 'FilterType::FILTER_NEAREST == 0' evaluated to false.");
static_assert(FilterType::FILTER_LINEAR == 1, "API_Verifier: 'FilterType::FILTER_LINEAR == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<AddressMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<AddressMode>,int>' evaluated to false.");
static_assert(AddressMode::ADDRESS_MODE_MIRROR == 0, "API_Verifier: 'AddressMode::ADDRESS_MODE_MIRROR == 0' evaluated to false.");
static_assert(AddressMode::ADDRESS_MODE_REPEAT == 1, "API_Verifier: 'AddressMode::ADDRESS_MODE_REPEAT == 1' evaluated to false.");
static_assert(AddressMode::ADDRESS_MODE_CLAMP_TO_EDGE == 2, "API_Verifier: 'AddressMode::ADDRESS_MODE_CLAMP_TO_EDGE == 2' evaluated to false.");
static_assert(AddressMode::ADDRESS_MODE_CLAMP_TO_BORDER == 3, "API_Verifier: 'AddressMode::ADDRESS_MODE_CLAMP_TO_BORDER == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<MipMapMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<MipMapMode>,int>' evaluated to false.");
static_assert(MipMapMode::MIPMAP_MODE_NEAREST == 0, "API_Verifier: 'MipMapMode::MIPMAP_MODE_NEAREST == 0' evaluated to false.");
static_assert(MipMapMode::MIPMAP_MODE_LINEAR == 1, "API_Verifier: 'MipMapMode::MIPMAP_MODE_LINEAR == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<BufferCreationFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<BufferCreationFlags>,int>' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_NONE == 0, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_NONE == 0' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_OWN_MEMORY_BIT == 1, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_OWN_MEMORY_BIT == 1' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT == 2, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_PERSISTENT_MAP_BIT == 2' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_ESRAM == 4, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_ESRAM == 4' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_NO_DESCRIPTOR_VIEW_CREATION == 8, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_NO_DESCRIPTOR_VIEW_CREATION == 8' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_ACCELERATION_STRUCTURE_BUILD_INPUT == 16, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_ACCELERATION_STRUCTURE_BUILD_INPUT == 16' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_SHADER_DEVICE_ADDRESS == 32, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_SHADER_DEVICE_ADDRESS == 32' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_SHADER_BINDING_TABLE == 64, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_SHADER_BINDING_TABLE == 64' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_MARKER == 128, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_MARKER == 128' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_HOST_COHERENT == 256, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_HOST_COHERENT == 256' evaluated to false.");
static_assert(BufferCreationFlags::BUFFER_CREATION_FLAG_HOST_VISIBLE == 512, "API_Verifier: 'BufferCreationFlags::BUFFER_CREATION_FLAG_HOST_VISIBLE == 512' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<TextureCreationFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<TextureCreationFlags>,int>' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_NONE == 0, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_NONE == 0' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_OWN_MEMORY_BIT == 1, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_OWN_MEMORY_BIT == 1' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_EXPORT_BIT == 2, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_EXPORT_BIT == 2' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_EXPORT_ADAPTER_BIT == 4, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_EXPORT_ADAPTER_BIT == 4' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_IMPORT_BIT == 8, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_IMPORT_BIT == 8' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_ESRAM == 16, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_ESRAM == 16' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_ON_TILE == 32, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_ON_TILE == 32' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_NO_COMPRESSION == 64, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_NO_COMPRESSION == 64' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_FORCE_2D == 128, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_FORCE_2D == 128' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_FORCE_3D == 256, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_FORCE_3D == 256' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_ALLOW_DISPLAY_TARGET == 512, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_ALLOW_DISPLAY_TARGET == 512' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_SRGB == 1024, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_SRGB == 1024' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_NORMAL_MAP == 2048, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_NORMAL_MAP == 2048' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_FAST_CLEAR == 4096, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_FAST_CLEAR == 4096' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_FRAG_MASK == 8192, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_FRAG_MASK == 8192' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_VR_MULTIVIEW == 16384, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_VR_MULTIVIEW == 16384' evaluated to false.");
static_assert(TextureCreationFlags::TEXTURE_CREATION_FLAG_VR_FOVEATED_RENDERING == 32768, "API_Verifier: 'TextureCreationFlags::TEXTURE_CREATION_FLAG_VR_FOVEATED_RENDERING == 32768' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ColorSpace>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ColorSpace>,int>' evaluated to false.");
static_assert(ColorSpace::COLOR_SPACE_SDR_LINEAR == 0, "API_Verifier: 'ColorSpace::COLOR_SPACE_SDR_LINEAR == 0' evaluated to false.");
static_assert(ColorSpace::COLOR_SPACE_SDR_SRGB == 1, "API_Verifier: 'ColorSpace::COLOR_SPACE_SDR_SRGB == 1' evaluated to false.");
static_assert(ColorSpace::COLOR_SPACE_P2020 == 2, "API_Verifier: 'ColorSpace::COLOR_SPACE_P2020 == 2' evaluated to false.");
static_assert(ColorSpace::COLOR_SPACE_EXTENDED_SRGB == 3, "API_Verifier: 'ColorSpace::COLOR_SPACE_EXTENDED_SRGB == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<QueryType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<QueryType>,int>' evaluated to false.");
static_assert(QueryType::QUERY_TYPE_TIMESTAMP == 0, "API_Verifier: 'QueryType::QUERY_TYPE_TIMESTAMP == 0' evaluated to false.");
static_assert(QueryType::QUERY_TYPE_OCCLUSION == 1, "API_Verifier: 'QueryType::QUERY_TYPE_OCCLUSION == 1' evaluated to false.");
static_assert(QueryType::QUERY_TYPE_PIPELINE_STATISTICS == 2, "API_Verifier: 'QueryType::QUERY_TYPE_PIPELINE_STATISTICS == 2' evaluated to false.");
static_assert(QueryType::QUERY_TYPE_COUNT == 3, "API_Verifier: 'QueryType::QUERY_TYPE_COUNT == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<SamplerRange>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<SamplerRange>,int>' evaluated to false.");
static_assert(SamplerRange::SAMPLER_RANGE_FULL == 0, "API_Verifier: 'SamplerRange::SAMPLER_RANGE_FULL == 0' evaluated to false.");
static_assert(SamplerRange::SAMPLER_RANGE_NARROW == 1, "API_Verifier: 'SamplerRange::SAMPLER_RANGE_NARROW == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<SamplerModelConversion>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<SamplerModelConversion>,int>' evaluated to false.");
static_assert(SamplerModelConversion::SAMPLER_MODEL_CONVERSION_RGB_IDENTITY == 0, "API_Verifier: 'SamplerModelConversion::SAMPLER_MODEL_CONVERSION_RGB_IDENTITY == 0' evaluated to false.");
static_assert(SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_IDENTITY == 1, "API_Verifier: 'SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_IDENTITY == 1' evaluated to false.");
static_assert(SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_709 == 2, "API_Verifier: 'SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_709 == 2' evaluated to false.");
static_assert(SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_601 == 3, "API_Verifier: 'SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_601 == 3' evaluated to false.");
static_assert(SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_2020 == 4, "API_Verifier: 'SamplerModelConversion::SAMPLER_MODEL_CONVERSION_YCBCR_2020 == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<SampleLocation>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<SampleLocation>,int>' evaluated to false.");
static_assert(SampleLocation::SAMPLE_LOCATION_COSITED == 0, "API_Verifier: 'SampleLocation::SAMPLE_LOCATION_COSITED == 0' evaluated to false.");
static_assert(SampleLocation::SAMPLE_LOCATION_MIDPOINT == 1, "API_Verifier: 'SampleLocation::SAMPLE_LOCATION_MIDPOINT == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ResourceHeapCreationFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ResourceHeapCreationFlags>,int>' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_NONE == 0, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_NONE == 0' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_SHARED == 1, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_SHARED == 1' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_BUFFERS == 2, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_BUFFERS == 2' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_DISPLAY == 4, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_DISPLAY == 4' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_SHARED_CROSS_ADAPTER == 8, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_SHARED_CROSS_ADAPTER == 8' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_RT_DS_TEXTURES == 16, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_RT_DS_TEXTURES == 16' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES == 32, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES == 32' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_HARDWARE_PROTECTED == 64, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_HARDWARE_PROTECTED == 64' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_WRITE_WATCH == 128, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_WRITE_WATCH == 128' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_SHADER_ATOMICS == 256, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_SHADER_ATOMICS == 256' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES == 512, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES == 512' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_BUFFERS == 48, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_BUFFERS == 48' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES == 18, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES == 18' evaluated to false.");
static_assert(ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES == 34, "API_Verifier: 'ResourceHeapCreationFlags::RESOURCE_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES == 34' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<DescriptorUpdateFrequency>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<DescriptorUpdateFrequency>,int>' evaluated to false.");
static_assert(DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_NONE == 0, "API_Verifier: 'DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_NONE == 0' evaluated to false.");
static_assert(DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_FRAME == 1, "API_Verifier: 'DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_FRAME == 1' evaluated to false.");
static_assert(DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_BATCH == 2, "API_Verifier: 'DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_BATCH == 2' evaluated to false.");
static_assert(DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_DRAW == 3, "API_Verifier: 'DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_PER_DRAW == 3' evaluated to false.");
static_assert(DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_COUNT == 4, "API_Verifier: 'DescriptorUpdateFrequency::DESCRIPTOR_UPDATE_FREQ_COUNT == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<RootSignatureFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<RootSignatureFlags>,int>' evaluated to false.");
static_assert(RootSignatureFlags::ROOT_SIGNATURE_FLAG_NONE == 0, "API_Verifier: 'RootSignatureFlags::ROOT_SIGNATURE_FLAG_NONE == 0' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<MarkerFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<MarkerFlags>,int>' evaluated to false.");
static_assert(MarkerFlags::MARKER_FLAG_NONE == 0, "API_Verifier: 'MarkerFlags::MARKER_FLAG_NONE == 0' evaluated to false.");
static_assert(MarkerFlags::MARKER_FLAG_WAIT_FOR_WRITE == 1, "API_Verifier: 'MarkerFlags::MARKER_FLAG_WAIT_FOR_WRITE == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<FenceStatus>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<FenceStatus>,int>' evaluated to false.");
static_assert(FenceStatus::FENCE_STATUS_COMPLETE == 0, "API_Verifier: 'FenceStatus::FENCE_STATUS_COMPLETE == 0' evaluated to false.");
static_assert(FenceStatus::FENCE_STATUS_INCOMPLETE == 1, "API_Verifier: 'FenceStatus::FENCE_STATUS_INCOMPLETE == 1' evaluated to false.");
static_assert(FenceStatus::FENCE_STATUS_NOTSUBMITTED == 2, "API_Verifier: 'FenceStatus::FENCE_STATUS_NOTSUBMITTED == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<VertexBindingRate>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<VertexBindingRate>,int>' evaluated to false.");
static_assert(VertexBindingRate::VERTEX_BINDING_RATE_VERTEX == 0, "API_Verifier: 'VertexBindingRate::VERTEX_BINDING_RATE_VERTEX == 0' evaluated to false.");
static_assert(VertexBindingRate::VERTEX_BINDING_RATE_INSTANCE == 1, "API_Verifier: 'VertexBindingRate::VERTEX_BINDING_RATE_INSTANCE == 1' evaluated to false.");
static_assert(VertexBindingRate::VERTEX_BINDING_RATE_COUNT == 2, "API_Verifier: 'VertexBindingRate::VERTEX_BINDING_RATE_COUNT == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<PipelineCacheFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<PipelineCacheFlags>,int>' evaluated to false.");
static_assert(PipelineCacheFlags::PIPELINE_CACHE_FLAG_NONE == 0, "API_Verifier: 'PipelineCacheFlags::PIPELINE_CACHE_FLAG_NONE == 0' evaluated to false.");
static_assert(PipelineCacheFlags::PIPELINE_CACHE_FLAG_EXTERNALLY_SYNCHRONIZED == 1, "API_Verifier: 'PipelineCacheFlags::PIPELINE_CACHE_FLAG_EXTERNALLY_SYNCHRONIZED == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<SwapChainCreationFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<SwapChainCreationFlags>,int>' evaluated to false.");
static_assert(SwapChainCreationFlags::SWAP_CHAIN_CREATION_FLAG_NONE == 0, "API_Verifier: 'SwapChainCreationFlags::SWAP_CHAIN_CREATION_FLAG_NONE == 0' evaluated to false.");
static_assert(SwapChainCreationFlags::SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR == 1, "API_Verifier: 'SwapChainCreationFlags::SWAP_CHAIN_CREATION_FLAG_ENABLE_FOVEATED_RENDERING_VR == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ShaderTarget>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ShaderTarget>,int>' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_5_0 == 0, "API_Verifier: 'ShaderTarget::SHADER_TARGET_5_0 == 0' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_5_1 == 1, "API_Verifier: 'ShaderTarget::SHADER_TARGET_5_1 == 1' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_6_0 == 2, "API_Verifier: 'ShaderTarget::SHADER_TARGET_6_0 == 2' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_6_1 == 3, "API_Verifier: 'ShaderTarget::SHADER_TARGET_6_1 == 3' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_6_2 == 4, "API_Verifier: 'ShaderTarget::SHADER_TARGET_6_2 == 4' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_6_3 == 5, "API_Verifier: 'ShaderTarget::SHADER_TARGET_6_3 == 5' evaluated to false.");
static_assert(ShaderTarget::SHADER_TARGET_6_4 == 6, "API_Verifier: 'ShaderTarget::SHADER_TARGET_6_4 == 6' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<GpuMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<GpuMode>,int>' evaluated to false.");
static_assert(GpuMode::GPU_MODE_SINGLE == 0, "API_Verifier: 'GpuMode::GPU_MODE_SINGLE == 0' evaluated to false.");
static_assert(GpuMode::GPU_MODE_LINKED == 1, "API_Verifier: 'GpuMode::GPU_MODE_LINKED == 1' evaluated to false.");
static_assert(GpuMode::GPU_MODE_UNLINKED == 2, "API_Verifier: 'GpuMode::GPU_MODE_UNLINKED == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<FormatCapability>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<FormatCapability>,int>' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_NONE == 0, "API_Verifier: 'FormatCapability::FORMAT_CAP_NONE == 0' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_LINEAR_FILTER == 1, "API_Verifier: 'FormatCapability::FORMAT_CAP_LINEAR_FILTER == 1' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_READ == 2, "API_Verifier: 'FormatCapability::FORMAT_CAP_READ == 2' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_WRITE == 4, "API_Verifier: 'FormatCapability::FORMAT_CAP_WRITE == 4' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_READ_WRITE == 8, "API_Verifier: 'FormatCapability::FORMAT_CAP_READ_WRITE == 8' evaluated to false.");
static_assert(FormatCapability::FORMAT_CAP_RENDER_TARGET == 16, "API_Verifier: 'FormatCapability::FORMAT_CAP_RENDER_TARGET == 16' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<DefaultResourceAlignment>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<DefaultResourceAlignment>,int>' evaluated to false.");
static_assert(DefaultResourceAlignment::RESOURCE_BUFFER_ALIGNMENT == 4, "API_Verifier: 'DefaultResourceAlignment::RESOURCE_BUFFER_ALIGNMENT == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<WaveOpsSupportFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<WaveOpsSupportFlags>,int>' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_NONE == 0, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_NONE == 0' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_BASIC_BIT == 1, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_BASIC_BIT == 1' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_VOTE_BIT == 2, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_VOTE_BIT == 2' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_ARITHMETIC_BIT == 4, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_ARITHMETIC_BIT == 4' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_BALLOT_BIT == 8, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_BALLOT_BIT == 8' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_SHUFFLE_BIT == 16, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_SHUFFLE_BIT == 16' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_SHUFFLE_RELATIVE_BIT == 32, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_SHUFFLE_RELATIVE_BIT == 32' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_CLUSTERED_BIT == 64, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_CLUSTERED_BIT == 64' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_QUAD_BIT == 128, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_QUAD_BIT == 128' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_PARTITIONED_BIT_NV == 256, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_PARTITIONED_BIT_NV == 256' evaluated to false.");
static_assert(WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_ALL == 2147483647, "API_Verifier: 'WaveOpsSupportFlags::WAVE_OPS_SUPPORT_FLAG_ALL == 2147483647' evaluated to false.");

static_assert(alignof(PlatformParameters) == 4, "API_Verifier: 'alignof(PlatformParameters) == 4' evaluated to false.");
static_assert(sizeof(PlatformParameters) == 1056, "API_Verifier: 'sizeof(PlatformParameters) == 1056' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::mSelectedRendererApi)) == 4, "API_Verifier: 'alignof( decltype(PlatformParameters::mSelectedRendererApi)) == 4' evaluated to false.");
static_assert(offsetof( PlatformParameters, mSelectedRendererApi) == 0, "API_Verifier: 'offsetof( PlatformParameters, mSelectedRendererApi) == 0' evaluated to false.");
static_assert(sizeof(PlatformParameters::mSelectedRendererApi) == 4, "API_Verifier: 'sizeof(PlatformParameters::mSelectedRendererApi) == 4' evaluated to false.");
static_assert(std::is_same_v<RendererApi, decltype(PlatformParameters::mSelectedRendererApi)>, "API_Verifier: 'std::is_same_v<RendererApi, decltype(PlatformParameters::mSelectedRendererApi)>' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::ppAvailableGpuNames)) == 1, "API_Verifier: 'alignof( decltype(PlatformParameters::ppAvailableGpuNames)) == 1' evaluated to false.");
static_assert(offsetof( PlatformParameters, ppAvailableGpuNames) == 4, "API_Verifier: 'offsetof( PlatformParameters, ppAvailableGpuNames) == 4' evaluated to false.");
static_assert(sizeof(PlatformParameters::ppAvailableGpuNames) == 1024, "API_Verifier: 'sizeof(PlatformParameters::ppAvailableGpuNames) == 1024' evaluated to false.");
static_assert(std::is_same_v<char[4][256], decltype(PlatformParameters::ppAvailableGpuNames)>, "API_Verifier: 'std::is_same_v<char[4][256], decltype(PlatformParameters::ppAvailableGpuNames)>' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::pAvailableGpuIds)) == 4, "API_Verifier: 'alignof( decltype(PlatformParameters::pAvailableGpuIds)) == 4' evaluated to false.");
static_assert(offsetof( PlatformParameters, pAvailableGpuIds) == 1028, "API_Verifier: 'offsetof( PlatformParameters, pAvailableGpuIds) == 1028' evaluated to false.");
static_assert(sizeof(PlatformParameters::pAvailableGpuIds) == 16, "API_Verifier: 'sizeof(PlatformParameters::pAvailableGpuIds) == 16' evaluated to false.");
static_assert(std::is_same_v<uint32_t[4], decltype(PlatformParameters::pAvailableGpuIds)>, "API_Verifier: 'std::is_same_v<uint32_t[4], decltype(PlatformParameters::pAvailableGpuIds)>' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::mAvailableGpuCount)) == 4, "API_Verifier: 'alignof( decltype(PlatformParameters::mAvailableGpuCount)) == 4' evaluated to false.");
static_assert(offsetof( PlatformParameters, mAvailableGpuCount) == 1044, "API_Verifier: 'offsetof( PlatformParameters, mAvailableGpuCount) == 1044' evaluated to false.");
static_assert(sizeof(PlatformParameters::mAvailableGpuCount) == 4, "API_Verifier: 'sizeof(PlatformParameters::mAvailableGpuCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PlatformParameters::mAvailableGpuCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PlatformParameters::mAvailableGpuCount)>' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::mSelectedGpuIndex)) == 4, "API_Verifier: 'alignof( decltype(PlatformParameters::mSelectedGpuIndex)) == 4' evaluated to false.");
static_assert(offsetof( PlatformParameters, mSelectedGpuIndex) == 1048, "API_Verifier: 'offsetof( PlatformParameters, mSelectedGpuIndex) == 1048' evaluated to false.");
static_assert(sizeof(PlatformParameters::mSelectedGpuIndex) == 4, "API_Verifier: 'sizeof(PlatformParameters::mSelectedGpuIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PlatformParameters::mSelectedGpuIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PlatformParameters::mSelectedGpuIndex)>' evaluated to false.");

static_assert(alignof( decltype(PlatformParameters::mPreferedGpuId)) == 4, "API_Verifier: 'alignof( decltype(PlatformParameters::mPreferedGpuId)) == 4' evaluated to false.");
static_assert(offsetof( PlatformParameters, mPreferedGpuId) == 1052, "API_Verifier: 'offsetof( PlatformParameters, mPreferedGpuId) == 1052' evaluated to false.");
static_assert(sizeof(PlatformParameters::mPreferedGpuId) == 4, "API_Verifier: 'sizeof(PlatformParameters::mPreferedGpuId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PlatformParameters::mPreferedGpuId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PlatformParameters::mPreferedGpuId)>' evaluated to false.");

static_assert(alignof(IndirectDrawArguments) == 4, "API_Verifier: 'alignof(IndirectDrawArguments) == 4' evaluated to false.");
static_assert(sizeof(IndirectDrawArguments) == 16, "API_Verifier: 'sizeof(IndirectDrawArguments) == 16' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawArguments::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawArguments::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawArguments, mVertexCount) == 0, "API_Verifier: 'offsetof( IndirectDrawArguments, mVertexCount) == 0' evaluated to false.");
static_assert(sizeof(IndirectDrawArguments::mVertexCount) == 4, "API_Verifier: 'sizeof(IndirectDrawArguments::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawArguments::mInstanceCount)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawArguments::mInstanceCount)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawArguments, mInstanceCount) == 4, "API_Verifier: 'offsetof( IndirectDrawArguments, mInstanceCount) == 4' evaluated to false.");
static_assert(sizeof(IndirectDrawArguments::mInstanceCount) == 4, "API_Verifier: 'sizeof(IndirectDrawArguments::mInstanceCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mInstanceCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mInstanceCount)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawArguments::mStartVertex)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawArguments::mStartVertex)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawArguments, mStartVertex) == 8, "API_Verifier: 'offsetof( IndirectDrawArguments, mStartVertex) == 8' evaluated to false.");
static_assert(sizeof(IndirectDrawArguments::mStartVertex) == 4, "API_Verifier: 'sizeof(IndirectDrawArguments::mStartVertex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mStartVertex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mStartVertex)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawArguments::mStartInstance)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawArguments::mStartInstance)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawArguments, mStartInstance) == 12, "API_Verifier: 'offsetof( IndirectDrawArguments, mStartInstance) == 12' evaluated to false.");
static_assert(sizeof(IndirectDrawArguments::mStartInstance) == 4, "API_Verifier: 'sizeof(IndirectDrawArguments::mStartInstance) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mStartInstance)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawArguments::mStartInstance)>' evaluated to false.");

static_assert(alignof(IndirectDrawIndexArguments) == 4, "API_Verifier: 'alignof(IndirectDrawIndexArguments) == 4' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments) == 20, "API_Verifier: 'sizeof(IndirectDrawIndexArguments) == 20' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawIndexArguments::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawIndexArguments::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawIndexArguments, mIndexCount) == 0, "API_Verifier: 'offsetof( IndirectDrawIndexArguments, mIndexCount) == 0' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments::mIndexCount) == 4, "API_Verifier: 'sizeof(IndirectDrawIndexArguments::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawIndexArguments::mInstanceCount)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawIndexArguments::mInstanceCount)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawIndexArguments, mInstanceCount) == 4, "API_Verifier: 'offsetof( IndirectDrawIndexArguments, mInstanceCount) == 4' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments::mInstanceCount) == 4, "API_Verifier: 'sizeof(IndirectDrawIndexArguments::mInstanceCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mInstanceCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mInstanceCount)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawIndexArguments::mStartIndex)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawIndexArguments::mStartIndex)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawIndexArguments, mStartIndex) == 8, "API_Verifier: 'offsetof( IndirectDrawIndexArguments, mStartIndex) == 8' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments::mStartIndex) == 4, "API_Verifier: 'sizeof(IndirectDrawIndexArguments::mStartIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mStartIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mStartIndex)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawIndexArguments::mVertexOffset)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawIndexArguments::mVertexOffset)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawIndexArguments, mVertexOffset) == 12, "API_Verifier: 'offsetof( IndirectDrawIndexArguments, mVertexOffset) == 12' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments::mVertexOffset) == 4, "API_Verifier: 'sizeof(IndirectDrawIndexArguments::mVertexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mVertexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mVertexOffset)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDrawIndexArguments::mStartInstance)) == 4, "API_Verifier: 'alignof( decltype(IndirectDrawIndexArguments::mStartInstance)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDrawIndexArguments, mStartInstance) == 16, "API_Verifier: 'offsetof( IndirectDrawIndexArguments, mStartInstance) == 16' evaluated to false.");
static_assert(sizeof(IndirectDrawIndexArguments::mStartInstance) == 4, "API_Verifier: 'sizeof(IndirectDrawIndexArguments::mStartInstance) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mStartInstance)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDrawIndexArguments::mStartInstance)>' evaluated to false.");

static_assert(alignof(IndirectDispatchArguments) == 4, "API_Verifier: 'alignof(IndirectDispatchArguments) == 4' evaluated to false.");
static_assert(sizeof(IndirectDispatchArguments) == 12, "API_Verifier: 'sizeof(IndirectDispatchArguments) == 12' evaluated to false.");

static_assert(alignof( decltype(IndirectDispatchArguments::mGroupCountX)) == 4, "API_Verifier: 'alignof( decltype(IndirectDispatchArguments::mGroupCountX)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDispatchArguments, mGroupCountX) == 0, "API_Verifier: 'offsetof( IndirectDispatchArguments, mGroupCountX) == 0' evaluated to false.");
static_assert(sizeof(IndirectDispatchArguments::mGroupCountX) == 4, "API_Verifier: 'sizeof(IndirectDispatchArguments::mGroupCountX) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountX)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountX)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDispatchArguments::mGroupCountY)) == 4, "API_Verifier: 'alignof( decltype(IndirectDispatchArguments::mGroupCountY)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDispatchArguments, mGroupCountY) == 4, "API_Verifier: 'offsetof( IndirectDispatchArguments, mGroupCountY) == 4' evaluated to false.");
static_assert(sizeof(IndirectDispatchArguments::mGroupCountY) == 4, "API_Verifier: 'sizeof(IndirectDispatchArguments::mGroupCountY) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountY)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountY)>' evaluated to false.");

static_assert(alignof( decltype(IndirectDispatchArguments::mGroupCountZ)) == 4, "API_Verifier: 'alignof( decltype(IndirectDispatchArguments::mGroupCountZ)) == 4' evaluated to false.");
static_assert(offsetof( IndirectDispatchArguments, mGroupCountZ) == 8, "API_Verifier: 'offsetof( IndirectDispatchArguments, mGroupCountZ) == 8' evaluated to false.");
static_assert(sizeof(IndirectDispatchArguments::mGroupCountZ) == 4, "API_Verifier: 'sizeof(IndirectDispatchArguments::mGroupCountZ) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountZ)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectDispatchArguments::mGroupCountZ)>' evaluated to false.");

static_assert(alignof(ClearValue) == 4, "API_Verifier: 'alignof(ClearValue) == 4' evaluated to false.");
static_assert(sizeof(ClearValue) == 16, "API_Verifier: 'sizeof(ClearValue) == 16' evaluated to false.");

static_assert(alignof(BufferBarrier) == 8, "API_Verifier: 'alignof(BufferBarrier) == 8' evaluated to false.");
static_assert(sizeof(BufferBarrier) == 24, "API_Verifier: 'sizeof(BufferBarrier) == 24' evaluated to false.");

static_assert(alignof( decltype(BufferBarrier::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferBarrier::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferBarrier, pBuffer) == 0, "API_Verifier: 'offsetof( BufferBarrier, pBuffer) == 0' evaluated to false.");
static_assert(sizeof(BufferBarrier::pBuffer) == 8, "API_Verifier: 'sizeof(BufferBarrier::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferBarrier::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferBarrier::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferBarrier::mCurrentState)) == 4, "API_Verifier: 'alignof( decltype(BufferBarrier::mCurrentState)) == 4' evaluated to false.");
static_assert(offsetof( BufferBarrier, mCurrentState) == 8, "API_Verifier: 'offsetof( BufferBarrier, mCurrentState) == 8' evaluated to false.");
static_assert(sizeof(BufferBarrier::mCurrentState) == 4, "API_Verifier: 'sizeof(BufferBarrier::mCurrentState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(BufferBarrier::mCurrentState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(BufferBarrier::mCurrentState)>' evaluated to false.");

static_assert(alignof( decltype(BufferBarrier::mNewState)) == 4, "API_Verifier: 'alignof( decltype(BufferBarrier::mNewState)) == 4' evaluated to false.");
static_assert(offsetof( BufferBarrier, mNewState) == 12, "API_Verifier: 'offsetof( BufferBarrier, mNewState) == 12' evaluated to false.");
static_assert(sizeof(BufferBarrier::mNewState) == 4, "API_Verifier: 'sizeof(BufferBarrier::mNewState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(BufferBarrier::mNewState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(BufferBarrier::mNewState)>' evaluated to false.");

static_assert(alignof( decltype(BufferBarrier::mBeginOnly)) == 1, "API_Verifier: 'alignof( decltype(BufferBarrier::mBeginOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(BufferBarrier::mBeginOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(BufferBarrier::mBeginOnly)>' evaluated to false.");

static_assert(alignof( decltype(BufferBarrier::mEndOnly)) == 1, "API_Verifier: 'alignof( decltype(BufferBarrier::mEndOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(BufferBarrier::mEndOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(BufferBarrier::mEndOnly)>' evaluated to false.");

static_assert(alignof(TextureBarrier) == 8, "API_Verifier: 'alignof(TextureBarrier) == 8' evaluated to false.");
static_assert(sizeof(TextureBarrier) == 24, "API_Verifier: 'sizeof(TextureBarrier) == 24' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::pTexture)) == 8, "API_Verifier: 'alignof( decltype(TextureBarrier::pTexture)) == 8' evaluated to false.");
static_assert(offsetof( TextureBarrier, pTexture) == 0, "API_Verifier: 'offsetof( TextureBarrier, pTexture) == 0' evaluated to false.");
static_assert(sizeof(TextureBarrier::pTexture) == 8, "API_Verifier: 'sizeof(TextureBarrier::pTexture) == 8' evaluated to false.");
static_assert(std::is_same_v<Texture*, decltype(TextureBarrier::pTexture)>, "API_Verifier: 'std::is_same_v<Texture*, decltype(TextureBarrier::pTexture)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mCurrentState)) == 4, "API_Verifier: 'alignof( decltype(TextureBarrier::mCurrentState)) == 4' evaluated to false.");
static_assert(offsetof( TextureBarrier, mCurrentState) == 8, "API_Verifier: 'offsetof( TextureBarrier, mCurrentState) == 8' evaluated to false.");
static_assert(sizeof(TextureBarrier::mCurrentState) == 4, "API_Verifier: 'sizeof(TextureBarrier::mCurrentState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(TextureBarrier::mCurrentState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(TextureBarrier::mCurrentState)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mNewState)) == 4, "API_Verifier: 'alignof( decltype(TextureBarrier::mNewState)) == 4' evaluated to false.");
static_assert(offsetof( TextureBarrier, mNewState) == 12, "API_Verifier: 'offsetof( TextureBarrier, mNewState) == 12' evaluated to false.");
static_assert(sizeof(TextureBarrier::mNewState) == 4, "API_Verifier: 'sizeof(TextureBarrier::mNewState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(TextureBarrier::mNewState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(TextureBarrier::mNewState)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mBeginOnly)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mBeginOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mBeginOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mBeginOnly)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mEndOnly)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mEndOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mEndOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mEndOnly)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mAcquire)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mAcquire)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mAcquire)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mAcquire)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mRelease)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mRelease)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mRelease)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mRelease)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mQueueType)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mQueueType)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mQueueType)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mQueueType)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mSubresourceBarrier)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mSubresourceBarrier)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mSubresourceBarrier)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mSubresourceBarrier)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mMipLevel)) == 1, "API_Verifier: 'alignof( decltype(TextureBarrier::mMipLevel)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(TextureBarrier::mMipLevel)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(TextureBarrier::mMipLevel)>' evaluated to false.");

static_assert(alignof( decltype(TextureBarrier::mArrayLayer)) == 2, "API_Verifier: 'alignof( decltype(TextureBarrier::mArrayLayer)) == 2' evaluated to false.");
static_assert(offsetof( TextureBarrier, mArrayLayer) == 20, "API_Verifier: 'offsetof( TextureBarrier, mArrayLayer) == 20' evaluated to false.");
static_assert(sizeof(TextureBarrier::mArrayLayer) == 2, "API_Verifier: 'sizeof(TextureBarrier::mArrayLayer) == 2' evaluated to false.");
static_assert(std::is_same_v<uint16_t, decltype(TextureBarrier::mArrayLayer)>, "API_Verifier: 'std::is_same_v<uint16_t, decltype(TextureBarrier::mArrayLayer)>' evaluated to false.");

static_assert(alignof(RenderTargetBarrier) == 8, "API_Verifier: 'alignof(RenderTargetBarrier) == 8' evaluated to false.");
static_assert(sizeof(RenderTargetBarrier) == 24, "API_Verifier: 'sizeof(RenderTargetBarrier) == 24' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::pRenderTarget)) == 8, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::pRenderTarget)) == 8' evaluated to false.");
static_assert(offsetof( RenderTargetBarrier, pRenderTarget) == 0, "API_Verifier: 'offsetof( RenderTargetBarrier, pRenderTarget) == 0' evaluated to false.");
static_assert(sizeof(RenderTargetBarrier::pRenderTarget) == 8, "API_Verifier: 'sizeof(RenderTargetBarrier::pRenderTarget) == 8' evaluated to false.");
static_assert(std::is_same_v<RenderTarget*, decltype(RenderTargetBarrier::pRenderTarget)>, "API_Verifier: 'std::is_same_v<RenderTarget*, decltype(RenderTargetBarrier::pRenderTarget)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mCurrentState)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mCurrentState)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetBarrier, mCurrentState) == 8, "API_Verifier: 'offsetof( RenderTargetBarrier, mCurrentState) == 8' evaluated to false.");
static_assert(sizeof(RenderTargetBarrier::mCurrentState) == 4, "API_Verifier: 'sizeof(RenderTargetBarrier::mCurrentState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(RenderTargetBarrier::mCurrentState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(RenderTargetBarrier::mCurrentState)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mNewState)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mNewState)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetBarrier, mNewState) == 12, "API_Verifier: 'offsetof( RenderTargetBarrier, mNewState) == 12' evaluated to false.");
static_assert(sizeof(RenderTargetBarrier::mNewState) == 4, "API_Verifier: 'sizeof(RenderTargetBarrier::mNewState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(RenderTargetBarrier::mNewState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(RenderTargetBarrier::mNewState)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mBeginOnly)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mBeginOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mBeginOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mBeginOnly)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mEndOnly)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mEndOnly)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mEndOnly)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mEndOnly)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mAcquire)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mAcquire)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mAcquire)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mAcquire)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mRelease)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mRelease)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mRelease)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mRelease)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mQueueType)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mQueueType)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mQueueType)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mQueueType)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mSubresourceBarrier)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mSubresourceBarrier)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mSubresourceBarrier)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mSubresourceBarrier)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mMipLevel)) == 1, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mMipLevel)) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mMipLevel)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(RenderTargetBarrier::mMipLevel)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetBarrier::mArrayLayer)) == 2, "API_Verifier: 'alignof( decltype(RenderTargetBarrier::mArrayLayer)) == 2' evaluated to false.");
static_assert(offsetof( RenderTargetBarrier, mArrayLayer) == 20, "API_Verifier: 'offsetof( RenderTargetBarrier, mArrayLayer) == 20' evaluated to false.");
static_assert(sizeof(RenderTargetBarrier::mArrayLayer) == 2, "API_Verifier: 'sizeof(RenderTargetBarrier::mArrayLayer) == 2' evaluated to false.");
static_assert(std::is_same_v<uint16_t, decltype(RenderTargetBarrier::mArrayLayer)>, "API_Verifier: 'std::is_same_v<uint16_t, decltype(RenderTargetBarrier::mArrayLayer)>' evaluated to false.");

static_assert(alignof(ReadRange) == 8, "API_Verifier: 'alignof(ReadRange) == 8' evaluated to false.");
static_assert(sizeof(ReadRange) == 16, "API_Verifier: 'sizeof(ReadRange) == 16' evaluated to false.");

static_assert(alignof( decltype(ReadRange::mOffset)) == 8, "API_Verifier: 'alignof( decltype(ReadRange::mOffset)) == 8' evaluated to false.");
static_assert(offsetof( ReadRange, mOffset) == 0, "API_Verifier: 'offsetof( ReadRange, mOffset) == 0' evaluated to false.");
static_assert(sizeof(ReadRange::mOffset) == 8, "API_Verifier: 'sizeof(ReadRange::mOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ReadRange::mOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ReadRange::mOffset)>' evaluated to false.");

static_assert(alignof( decltype(ReadRange::mSize)) == 8, "API_Verifier: 'alignof( decltype(ReadRange::mSize)) == 8' evaluated to false.");
static_assert(offsetof( ReadRange, mSize) == 8, "API_Verifier: 'offsetof( ReadRange, mSize) == 8' evaluated to false.");
static_assert(sizeof(ReadRange::mSize) == 8, "API_Verifier: 'sizeof(ReadRange::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ReadRange::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ReadRange::mSize)>' evaluated to false.");

static_assert(alignof(QueryPoolDesc) == 8, "API_Verifier: 'alignof(QueryPoolDesc) == 8' evaluated to false.");
static_assert(sizeof(QueryPoolDesc) == 24, "API_Verifier: 'sizeof(QueryPoolDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(QueryPoolDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(QueryPoolDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( QueryPoolDesc, pName) == 0, "API_Verifier: 'offsetof( QueryPoolDesc, pName) == 0' evaluated to false.");
static_assert(sizeof(QueryPoolDesc::pName) == 8, "API_Verifier: 'sizeof(QueryPoolDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(QueryPoolDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(QueryPoolDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(QueryPoolDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(QueryPoolDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( QueryPoolDesc, mType) == 8, "API_Verifier: 'offsetof( QueryPoolDesc, mType) == 8' evaluated to false.");
static_assert(sizeof(QueryPoolDesc::mType) == 4, "API_Verifier: 'sizeof(QueryPoolDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<QueryType, decltype(QueryPoolDesc::mType)>, "API_Verifier: 'std::is_same_v<QueryType, decltype(QueryPoolDesc::mType)>' evaluated to false.");

static_assert(alignof( decltype(QueryPoolDesc::mQueryCount)) == 4, "API_Verifier: 'alignof( decltype(QueryPoolDesc::mQueryCount)) == 4' evaluated to false.");
static_assert(offsetof( QueryPoolDesc, mQueryCount) == 12, "API_Verifier: 'offsetof( QueryPoolDesc, mQueryCount) == 12' evaluated to false.");
static_assert(sizeof(QueryPoolDesc::mQueryCount) == 4, "API_Verifier: 'sizeof(QueryPoolDesc::mQueryCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueryPoolDesc::mQueryCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueryPoolDesc::mQueryCount)>' evaluated to false.");

static_assert(alignof( decltype(QueryPoolDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(QueryPoolDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( QueryPoolDesc, mNodeIndex) == 16, "API_Verifier: 'offsetof( QueryPoolDesc, mNodeIndex) == 16' evaluated to false.");
static_assert(sizeof(QueryPoolDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(QueryPoolDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueryPoolDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueryPoolDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof(QueryDesc) == 4, "API_Verifier: 'alignof(QueryDesc) == 4' evaluated to false.");
static_assert(sizeof(QueryDesc) == 4, "API_Verifier: 'sizeof(QueryDesc) == 4' evaluated to false.");

static_assert(alignof( decltype(QueryDesc::mIndex)) == 4, "API_Verifier: 'alignof( decltype(QueryDesc::mIndex)) == 4' evaluated to false.");
static_assert(offsetof( QueryDesc, mIndex) == 0, "API_Verifier: 'offsetof( QueryDesc, mIndex) == 0' evaluated to false.");
static_assert(sizeof(QueryDesc::mIndex) == 4, "API_Verifier: 'sizeof(QueryDesc::mIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueryDesc::mIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueryDesc::mIndex)>' evaluated to false.");

static_assert(alignof(QueryPool) == 8, "API_Verifier: 'alignof(QueryPool) == 8' evaluated to false.");
static_assert(sizeof(QueryPool) == 32, "API_Verifier: 'sizeof(QueryPool) == 32' evaluated to false.");

static_assert(alignof( decltype(QueryPool::mCount)) == 4, "API_Verifier: 'alignof( decltype(QueryPool::mCount)) == 4' evaluated to false.");
static_assert(offsetof( QueryPool, mCount) == 24, "API_Verifier: 'offsetof( QueryPool, mCount) == 24' evaluated to false.");
static_assert(sizeof(QueryPool::mCount) == 4, "API_Verifier: 'sizeof(QueryPool::mCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueryPool::mCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueryPool::mCount)>' evaluated to false.");

static_assert(alignof( decltype(QueryPool::mStride)) == 4, "API_Verifier: 'alignof( decltype(QueryPool::mStride)) == 4' evaluated to false.");
static_assert(offsetof( QueryPool, mStride) == 28, "API_Verifier: 'offsetof( QueryPool, mStride) == 28' evaluated to false.");
static_assert(sizeof(QueryPool::mStride) == 4, "API_Verifier: 'sizeof(QueryPool::mStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueryPool::mStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueryPool::mStride)>' evaluated to false.");

static_assert(alignof(PipelineStatisticsQueryData) == 8, "API_Verifier: 'alignof(PipelineStatisticsQueryData) == 8' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData) == 88, "API_Verifier: 'sizeof(PipelineStatisticsQueryData) == 88' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mIAVertices)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mIAVertices)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mIAVertices) == 0, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mIAVertices) == 0' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mIAVertices) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mIAVertices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mIAVertices)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mIAVertices)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mIAPrimitives)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mIAPrimitives)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mIAPrimitives) == 8, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mIAPrimitives) == 8' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mIAPrimitives) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mIAPrimitives) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mIAPrimitives)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mIAPrimitives)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mVSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mVSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mVSInvocations) == 16, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mVSInvocations) == 16' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mVSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mVSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mVSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mVSInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mGSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mGSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mGSInvocations) == 24, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mGSInvocations) == 24' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mGSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mGSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mGSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mGSInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mGSPrimitives)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mGSPrimitives)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mGSPrimitives) == 32, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mGSPrimitives) == 32' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mGSPrimitives) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mGSPrimitives) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mGSPrimitives)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mGSPrimitives)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mCInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mCInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mCInvocations) == 40, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mCInvocations) == 40' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mCInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mCInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mCPrimitives)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mCPrimitives)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mCPrimitives) == 48, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mCPrimitives) == 48' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mCPrimitives) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mCPrimitives) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCPrimitives)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCPrimitives)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mPSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mPSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mPSInvocations) == 56, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mPSInvocations) == 56' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mPSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mPSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mPSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mPSInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mHSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mHSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mHSInvocations) == 64, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mHSInvocations) == 64' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mHSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mHSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mHSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mHSInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mDSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mDSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mDSInvocations) == 72, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mDSInvocations) == 72' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mDSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mDSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mDSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mDSInvocations)>' evaluated to false.");

static_assert(alignof( decltype(PipelineStatisticsQueryData::mCSInvocations)) == 8, "API_Verifier: 'alignof( decltype(PipelineStatisticsQueryData::mCSInvocations)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStatisticsQueryData, mCSInvocations) == 80, "API_Verifier: 'offsetof( PipelineStatisticsQueryData, mCSInvocations) == 80' evaluated to false.");
static_assert(sizeof(PipelineStatisticsQueryData::mCSInvocations) == 8, "API_Verifier: 'sizeof(PipelineStatisticsQueryData::mCSInvocations) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCSInvocations)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PipelineStatisticsQueryData::mCSInvocations)>' evaluated to false.");

static_assert(alignof(QueryData) == 8, "API_Verifier: 'alignof(QueryData) == 8' evaluated to false.");
static_assert(sizeof(QueryData) == 96, "API_Verifier: 'sizeof(QueryData) == 96' evaluated to false.");

static_assert(alignof( decltype(QueryData::mValid)) == 1, "API_Verifier: 'alignof( decltype(QueryData::mValid)) == 1' evaluated to false.");
static_assert(offsetof( QueryData, mValid) == 88, "API_Verifier: 'offsetof( QueryData, mValid) == 88' evaluated to false.");
static_assert(sizeof(QueryData::mValid) == 1, "API_Verifier: 'sizeof(QueryData::mValid) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(QueryData::mValid)>, "API_Verifier: 'std::is_same_v<bool, decltype(QueryData::mValid)>' evaluated to false.");

static_assert(alignof(ResourceHeapDesc) == 8, "API_Verifier: 'alignof(ResourceHeapDesc) == 8' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc) == 56, "API_Verifier: 'sizeof(ResourceHeapDesc) == 56' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mSize)) == 8, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mSize)) == 8' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mSize) == 0, "API_Verifier: 'offsetof( ResourceHeapDesc, mSize) == 0' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mSize) == 8, "API_Verifier: 'sizeof(ResourceHeapDesc::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourceHeapDesc::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourceHeapDesc::mSize)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mAlignment)) == 8, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mAlignment)) == 8' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mAlignment) == 8, "API_Verifier: 'offsetof( ResourceHeapDesc, mAlignment) == 8' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mAlignment) == 8, "API_Verifier: 'sizeof(ResourceHeapDesc::mAlignment) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourceHeapDesc::mAlignment)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourceHeapDesc::mAlignment)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mMemoryUsage)) == 4, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mMemoryUsage)) == 4' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mMemoryUsage) == 16, "API_Verifier: 'offsetof( ResourceHeapDesc, mMemoryUsage) == 16' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mMemoryUsage) == 4, "API_Verifier: 'sizeof(ResourceHeapDesc::mMemoryUsage) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceMemoryUsage, decltype(ResourceHeapDesc::mMemoryUsage)>, "API_Verifier: 'std::is_same_v<ResourceMemoryUsage, decltype(ResourceHeapDesc::mMemoryUsage)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mDescriptors)) == 4, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mDescriptors)) == 4' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mDescriptors) == 20, "API_Verifier: 'offsetof( ResourceHeapDesc, mDescriptors) == 20' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mDescriptors) == 4, "API_Verifier: 'sizeof(ResourceHeapDesc::mDescriptors) == 4' evaluated to false.");
static_assert(std::is_same_v<DescriptorType, decltype(ResourceHeapDesc::mDescriptors)>, "API_Verifier: 'std::is_same_v<DescriptorType, decltype(ResourceHeapDesc::mDescriptors)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mFlags) == 24, "API_Verifier: 'offsetof( ResourceHeapDesc, mFlags) == 24' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mFlags) == 4, "API_Verifier: 'sizeof(ResourceHeapDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceHeapCreationFlags, decltype(ResourceHeapDesc::mFlags)>, "API_Verifier: 'std::is_same_v<ResourceHeapCreationFlags, decltype(ResourceHeapDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mNodeIndex) == 28, "API_Verifier: 'offsetof( ResourceHeapDesc, mNodeIndex) == 28' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(ResourceHeapDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ResourceHeapDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ResourceHeapDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::mSharedNodeIndexCount)) == 4, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::mSharedNodeIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, mSharedNodeIndexCount) == 32, "API_Verifier: 'offsetof( ResourceHeapDesc, mSharedNodeIndexCount) == 32' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::mSharedNodeIndexCount) == 4, "API_Verifier: 'sizeof(ResourceHeapDesc::mSharedNodeIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ResourceHeapDesc::mSharedNodeIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ResourceHeapDesc::mSharedNodeIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::pSharedNodeIndices)) == 8, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::pSharedNodeIndices)) == 8' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, pSharedNodeIndices) == 40, "API_Verifier: 'offsetof( ResourceHeapDesc, pSharedNodeIndices) == 40' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::pSharedNodeIndices) == 8, "API_Verifier: 'sizeof(ResourceHeapDesc::pSharedNodeIndices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(ResourceHeapDesc::pSharedNodeIndices)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(ResourceHeapDesc::pSharedNodeIndices)>' evaluated to false.");

static_assert(alignof( decltype(ResourceHeapDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(ResourceHeapDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( ResourceHeapDesc, pName) == 48, "API_Verifier: 'offsetof( ResourceHeapDesc, pName) == 48' evaluated to false.");
static_assert(sizeof(ResourceHeapDesc::pName) == 8, "API_Verifier: 'sizeof(ResourceHeapDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(ResourceHeapDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(ResourceHeapDesc::pName)>' evaluated to false.");

static_assert(alignof(ResourceSizeAlign) == 8, "API_Verifier: 'alignof(ResourceSizeAlign) == 8' evaluated to false.");
static_assert(sizeof(ResourceSizeAlign) == 16, "API_Verifier: 'sizeof(ResourceSizeAlign) == 16' evaluated to false.");

static_assert(alignof( decltype(ResourceSizeAlign::mSize)) == 8, "API_Verifier: 'alignof( decltype(ResourceSizeAlign::mSize)) == 8' evaluated to false.");
static_assert(offsetof( ResourceSizeAlign, mSize) == 0, "API_Verifier: 'offsetof( ResourceSizeAlign, mSize) == 0' evaluated to false.");
static_assert(sizeof(ResourceSizeAlign::mSize) == 8, "API_Verifier: 'sizeof(ResourceSizeAlign::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourceSizeAlign::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourceSizeAlign::mSize)>' evaluated to false.");

static_assert(alignof( decltype(ResourceSizeAlign::mAlignment)) == 8, "API_Verifier: 'alignof( decltype(ResourceSizeAlign::mAlignment)) == 8' evaluated to false.");
static_assert(offsetof( ResourceSizeAlign, mAlignment) == 8, "API_Verifier: 'offsetof( ResourceSizeAlign, mAlignment) == 8' evaluated to false.");
static_assert(sizeof(ResourceSizeAlign::mAlignment) == 8, "API_Verifier: 'sizeof(ResourceSizeAlign::mAlignment) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourceSizeAlign::mAlignment)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourceSizeAlign::mAlignment)>' evaluated to false.");

static_assert(alignof(ResourcePlacement) == 8, "API_Verifier: 'alignof(ResourcePlacement) == 8' evaluated to false.");
static_assert(sizeof(ResourcePlacement) == 16, "API_Verifier: 'sizeof(ResourcePlacement) == 16' evaluated to false.");

static_assert(alignof( decltype(ResourcePlacement::pHeap)) == 8, "API_Verifier: 'alignof( decltype(ResourcePlacement::pHeap)) == 8' evaluated to false.");
static_assert(offsetof( ResourcePlacement, pHeap) == 0, "API_Verifier: 'offsetof( ResourcePlacement, pHeap) == 0' evaluated to false.");
static_assert(sizeof(ResourcePlacement::pHeap) == 8, "API_Verifier: 'sizeof(ResourcePlacement::pHeap) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourceHeap*, decltype(ResourcePlacement::pHeap)>, "API_Verifier: 'std::is_same_v<ResourceHeap*, decltype(ResourcePlacement::pHeap)>' evaluated to false.");

static_assert(alignof( decltype(ResourcePlacement::mOffset)) == 8, "API_Verifier: 'alignof( decltype(ResourcePlacement::mOffset)) == 8' evaluated to false.");
static_assert(offsetof( ResourcePlacement, mOffset) == 8, "API_Verifier: 'offsetof( ResourcePlacement, mOffset) == 8' evaluated to false.");
static_assert(sizeof(ResourcePlacement::mOffset) == 8, "API_Verifier: 'sizeof(ResourcePlacement::mOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourcePlacement::mOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourcePlacement::mOffset)>' evaluated to false.");

static_assert(alignof(BufferDesc) == 8, "API_Verifier: 'alignof(BufferDesc) == 8' evaluated to false.");
static_assert(sizeof(BufferDesc) == 96, "API_Verifier: 'sizeof(BufferDesc) == 96' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::pPlacement)) == 8, "API_Verifier: 'alignof( decltype(BufferDesc::pPlacement)) == 8' evaluated to false.");
static_assert(offsetof( BufferDesc, pPlacement) == 0, "API_Verifier: 'offsetof( BufferDesc, pPlacement) == 0' evaluated to false.");
static_assert(sizeof(BufferDesc::pPlacement) == 8, "API_Verifier: 'sizeof(BufferDesc::pPlacement) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement*, decltype(BufferDesc::pPlacement)>, "API_Verifier: 'std::is_same_v<ResourcePlacement*, decltype(BufferDesc::pPlacement)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mSize)) == 8, "API_Verifier: 'alignof( decltype(BufferDesc::mSize)) == 8' evaluated to false.");
static_assert(offsetof( BufferDesc, mSize) == 8, "API_Verifier: 'offsetof( BufferDesc, mSize) == 8' evaluated to false.");
static_assert(sizeof(BufferDesc::mSize) == 8, "API_Verifier: 'sizeof(BufferDesc::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(BufferDesc::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(BufferDesc::mSize)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::pCounterBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferDesc::pCounterBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferDesc, pCounterBuffer) == 16, "API_Verifier: 'offsetof( BufferDesc, pCounterBuffer) == 16' evaluated to false.");
static_assert(sizeof(BufferDesc::pCounterBuffer) == 8, "API_Verifier: 'sizeof(BufferDesc::pCounterBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferDesc::pCounterBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferDesc::pCounterBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mFirstElement)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mFirstElement)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mFirstElement) == 24, "API_Verifier: 'offsetof( BufferDesc, mFirstElement) == 24' evaluated to false.");
static_assert(sizeof(BufferDesc::mFirstElement) == 4, "API_Verifier: 'sizeof(BufferDesc::mFirstElement) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mFirstElement)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mFirstElement)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mElementCount)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mElementCount)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mElementCount) == 28, "API_Verifier: 'offsetof( BufferDesc, mElementCount) == 28' evaluated to false.");
static_assert(sizeof(BufferDesc::mElementCount) == 4, "API_Verifier: 'sizeof(BufferDesc::mElementCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mElementCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mElementCount)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mStructStride)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mStructStride)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mStructStride) == 32, "API_Verifier: 'offsetof( BufferDesc, mStructStride) == 32' evaluated to false.");
static_assert(sizeof(BufferDesc::mStructStride) == 4, "API_Verifier: 'sizeof(BufferDesc::mStructStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mStructStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mStructStride)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mAlignment)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mAlignment)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mAlignment) == 36, "API_Verifier: 'offsetof( BufferDesc, mAlignment) == 36' evaluated to false.");
static_assert(sizeof(BufferDesc::mAlignment) == 4, "API_Verifier: 'sizeof(BufferDesc::mAlignment) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mAlignment)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mAlignment)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(BufferDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( BufferDesc, pName) == 40, "API_Verifier: 'offsetof( BufferDesc, pName) == 40' evaluated to false.");
static_assert(sizeof(BufferDesc::pName) == 8, "API_Verifier: 'sizeof(BufferDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(BufferDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(BufferDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::pSharedNodeIndices)) == 8, "API_Verifier: 'alignof( decltype(BufferDesc::pSharedNodeIndices)) == 8' evaluated to false.");
static_assert(offsetof( BufferDesc, pSharedNodeIndices) == 48, "API_Verifier: 'offsetof( BufferDesc, pSharedNodeIndices) == 48' evaluated to false.");
static_assert(sizeof(BufferDesc::pSharedNodeIndices) == 8, "API_Verifier: 'sizeof(BufferDesc::pSharedNodeIndices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(BufferDesc::pSharedNodeIndices)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(BufferDesc::pSharedNodeIndices)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mMemoryUsage)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mMemoryUsage)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mMemoryUsage) == 56, "API_Verifier: 'offsetof( BufferDesc, mMemoryUsage) == 56' evaluated to false.");
static_assert(sizeof(BufferDesc::mMemoryUsage) == 4, "API_Verifier: 'sizeof(BufferDesc::mMemoryUsage) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceMemoryUsage, decltype(BufferDesc::mMemoryUsage)>, "API_Verifier: 'std::is_same_v<ResourceMemoryUsage, decltype(BufferDesc::mMemoryUsage)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mFlags) == 60, "API_Verifier: 'offsetof( BufferDesc, mFlags) == 60' evaluated to false.");
static_assert(sizeof(BufferDesc::mFlags) == 4, "API_Verifier: 'sizeof(BufferDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<BufferCreationFlags, decltype(BufferDesc::mFlags)>, "API_Verifier: 'std::is_same_v<BufferCreationFlags, decltype(BufferDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mQueueType)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mQueueType)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mQueueType) == 64, "API_Verifier: 'offsetof( BufferDesc, mQueueType) == 64' evaluated to false.");
static_assert(sizeof(BufferDesc::mQueueType) == 4, "API_Verifier: 'sizeof(BufferDesc::mQueueType) == 4' evaluated to false.");
static_assert(std::is_same_v<QueueType, decltype(BufferDesc::mQueueType)>, "API_Verifier: 'std::is_same_v<QueueType, decltype(BufferDesc::mQueueType)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mStartState)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mStartState)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mStartState) == 68, "API_Verifier: 'offsetof( BufferDesc, mStartState) == 68' evaluated to false.");
static_assert(sizeof(BufferDesc::mStartState) == 4, "API_Verifier: 'sizeof(BufferDesc::mStartState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(BufferDesc::mStartState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(BufferDesc::mStartState)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mICBDrawType)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mICBDrawType)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mICBDrawType) == 72, "API_Verifier: 'offsetof( BufferDesc, mICBDrawType) == 72' evaluated to false.");
static_assert(sizeof(BufferDesc::mICBDrawType) == 4, "API_Verifier: 'sizeof(BufferDesc::mICBDrawType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndirectArgumentType, decltype(BufferDesc::mICBDrawType)>, "API_Verifier: 'std::is_same_v<IndirectArgumentType, decltype(BufferDesc::mICBDrawType)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mICBMaxCommandCount)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mICBMaxCommandCount)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mICBMaxCommandCount) == 76, "API_Verifier: 'offsetof( BufferDesc, mICBMaxCommandCount) == 76' evaluated to false.");
static_assert(sizeof(BufferDesc::mICBMaxCommandCount) == 4, "API_Verifier: 'sizeof(BufferDesc::mICBMaxCommandCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mICBMaxCommandCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mICBMaxCommandCount)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mFormat)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mFormat)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mFormat) == 80, "API_Verifier: 'offsetof( BufferDesc, mFormat) == 80' evaluated to false.");
static_assert(sizeof(BufferDesc::mFormat) == 4, "API_Verifier: 'sizeof(BufferDesc::mFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(BufferDesc::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(BufferDesc::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mDescriptors)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mDescriptors)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mDescriptors) == 84, "API_Verifier: 'offsetof( BufferDesc, mDescriptors) == 84' evaluated to false.");
static_assert(sizeof(BufferDesc::mDescriptors) == 4, "API_Verifier: 'sizeof(BufferDesc::mDescriptors) == 4' evaluated to false.");
static_assert(std::is_same_v<DescriptorType, decltype(BufferDesc::mDescriptors)>, "API_Verifier: 'std::is_same_v<DescriptorType, decltype(BufferDesc::mDescriptors)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mNodeIndex) == 88, "API_Verifier: 'offsetof( BufferDesc, mNodeIndex) == 88' evaluated to false.");
static_assert(sizeof(BufferDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(BufferDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(BufferDesc::mSharedNodeIndexCount)) == 4, "API_Verifier: 'alignof( decltype(BufferDesc::mSharedNodeIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( BufferDesc, mSharedNodeIndexCount) == 92, "API_Verifier: 'offsetof( BufferDesc, mSharedNodeIndexCount) == 92' evaluated to false.");
static_assert(sizeof(BufferDesc::mSharedNodeIndexCount) == 4, "API_Verifier: 'sizeof(BufferDesc::mSharedNodeIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferDesc::mSharedNodeIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferDesc::mSharedNodeIndexCount)>' evaluated to false.");

static_assert(alignof(TextureDesc) == 8, "API_Verifier: 'alignof(TextureDesc) == 8' evaluated to false.");
static_assert(sizeof(TextureDesc) == 112, "API_Verifier: 'sizeof(TextureDesc) == 112' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::pPlacement)) == 8, "API_Verifier: 'alignof( decltype(TextureDesc::pPlacement)) == 8' evaluated to false.");
static_assert(offsetof( TextureDesc, pPlacement) == 0, "API_Verifier: 'offsetof( TextureDesc, pPlacement) == 0' evaluated to false.");
static_assert(sizeof(TextureDesc::pPlacement) == 8, "API_Verifier: 'sizeof(TextureDesc::pPlacement) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement*, decltype(TextureDesc::pPlacement)>, "API_Verifier: 'std::is_same_v<ResourcePlacement*, decltype(TextureDesc::pPlacement)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mClearValue)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mClearValue)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mClearValue) == 8, "API_Verifier: 'offsetof( TextureDesc, mClearValue) == 8' evaluated to false.");
static_assert(sizeof(TextureDesc::mClearValue) == 16, "API_Verifier: 'sizeof(TextureDesc::mClearValue) == 16' evaluated to false.");
static_assert(std::is_same_v<ClearValue, decltype(TextureDesc::mClearValue)>, "API_Verifier: 'std::is_same_v<ClearValue, decltype(TextureDesc::mClearValue)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::pNativeHandle)) == 8, "API_Verifier: 'alignof( decltype(TextureDesc::pNativeHandle)) == 8' evaluated to false.");
static_assert(offsetof( TextureDesc, pNativeHandle) == 24, "API_Verifier: 'offsetof( TextureDesc, pNativeHandle) == 24' evaluated to false.");
static_assert(sizeof(TextureDesc::pNativeHandle) == 8, "API_Verifier: 'sizeof(TextureDesc::pNativeHandle) == 8' evaluated to false.");
static_assert(std::is_same_v<const void *, decltype(TextureDesc::pNativeHandle)>, "API_Verifier: 'std::is_same_v<const void *, decltype(TextureDesc::pNativeHandle)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(TextureDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( TextureDesc, pName) == 32, "API_Verifier: 'offsetof( TextureDesc, pName) == 32' evaluated to false.");
static_assert(sizeof(TextureDesc::pName) == 8, "API_Verifier: 'sizeof(TextureDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(TextureDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(TextureDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::pSharedNodeIndices)) == 8, "API_Verifier: 'alignof( decltype(TextureDesc::pSharedNodeIndices)) == 8' evaluated to false.");
static_assert(offsetof( TextureDesc, pSharedNodeIndices) == 40, "API_Verifier: 'offsetof( TextureDesc, pSharedNodeIndices) == 40' evaluated to false.");
static_assert(sizeof(TextureDesc::pSharedNodeIndices) == 8, "API_Verifier: 'sizeof(TextureDesc::pSharedNodeIndices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(TextureDesc::pSharedNodeIndices)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(TextureDesc::pSharedNodeIndices)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::pSamplerYcbcrConversionInfo)) == 8, "API_Verifier: 'alignof( decltype(TextureDesc::pSamplerYcbcrConversionInfo)) == 8' evaluated to false.");
static_assert(offsetof( TextureDesc, pSamplerYcbcrConversionInfo) == 48, "API_Verifier: 'offsetof( TextureDesc, pSamplerYcbcrConversionInfo) == 48' evaluated to false.");
static_assert(sizeof(TextureDesc::pSamplerYcbcrConversionInfo) == 8, "API_Verifier: 'sizeof(TextureDesc::pSamplerYcbcrConversionInfo) == 8' evaluated to false.");
static_assert(std::is_same_v<VkSamplerYcbcrConversionInfo*, decltype(TextureDesc::pSamplerYcbcrConversionInfo)>, "API_Verifier: 'std::is_same_v<VkSamplerYcbcrConversionInfo*, decltype(TextureDesc::pSamplerYcbcrConversionInfo)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mFlags) == 56, "API_Verifier: 'offsetof( TextureDesc, mFlags) == 56' evaluated to false.");
static_assert(sizeof(TextureDesc::mFlags) == 4, "API_Verifier: 'sizeof(TextureDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<TextureCreationFlags, decltype(TextureDesc::mFlags)>, "API_Verifier: 'std::is_same_v<TextureCreationFlags, decltype(TextureDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mWidth)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mWidth) == 60, "API_Verifier: 'offsetof( TextureDesc, mWidth) == 60' evaluated to false.");
static_assert(sizeof(TextureDesc::mWidth) == 4, "API_Verifier: 'sizeof(TextureDesc::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mHeight)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mHeight) == 64, "API_Verifier: 'offsetof( TextureDesc, mHeight) == 64' evaluated to false.");
static_assert(sizeof(TextureDesc::mHeight) == 4, "API_Verifier: 'sizeof(TextureDesc::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mDepth)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mDepth)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mDepth) == 68, "API_Verifier: 'offsetof( TextureDesc, mDepth) == 68' evaluated to false.");
static_assert(sizeof(TextureDesc::mDepth) == 4, "API_Verifier: 'sizeof(TextureDesc::mDepth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mDepth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mDepth)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mArraySize)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mArraySize)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mArraySize) == 72, "API_Verifier: 'offsetof( TextureDesc, mArraySize) == 72' evaluated to false.");
static_assert(sizeof(TextureDesc::mArraySize) == 4, "API_Verifier: 'sizeof(TextureDesc::mArraySize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mArraySize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mArraySize)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mMipLevels)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mMipLevels)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mMipLevels) == 76, "API_Verifier: 'offsetof( TextureDesc, mMipLevels) == 76' evaluated to false.");
static_assert(sizeof(TextureDesc::mMipLevels) == 4, "API_Verifier: 'sizeof(TextureDesc::mMipLevels) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mMipLevels)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mMipLevels)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mSampleCount)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mSampleCount)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mSampleCount) == 80, "API_Verifier: 'offsetof( TextureDesc, mSampleCount) == 80' evaluated to false.");
static_assert(sizeof(TextureDesc::mSampleCount) == 4, "API_Verifier: 'sizeof(TextureDesc::mSampleCount) == 4' evaluated to false.");
static_assert(std::is_same_v<SampleCount, decltype(TextureDesc::mSampleCount)>, "API_Verifier: 'std::is_same_v<SampleCount, decltype(TextureDesc::mSampleCount)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mSampleQuality)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mSampleQuality)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mSampleQuality) == 84, "API_Verifier: 'offsetof( TextureDesc, mSampleQuality) == 84' evaluated to false.");
static_assert(sizeof(TextureDesc::mSampleQuality) == 4, "API_Verifier: 'sizeof(TextureDesc::mSampleQuality) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mSampleQuality)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mSampleQuality)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mFormat)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mFormat)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mFormat) == 88, "API_Verifier: 'offsetof( TextureDesc, mFormat) == 88' evaluated to false.");
static_assert(sizeof(TextureDesc::mFormat) == 4, "API_Verifier: 'sizeof(TextureDesc::mFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(TextureDesc::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(TextureDesc::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mStartState)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mStartState)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mStartState) == 92, "API_Verifier: 'offsetof( TextureDesc, mStartState) == 92' evaluated to false.");
static_assert(sizeof(TextureDesc::mStartState) == 4, "API_Verifier: 'sizeof(TextureDesc::mStartState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(TextureDesc::mStartState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(TextureDesc::mStartState)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mDescriptors)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mDescriptors)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mDescriptors) == 96, "API_Verifier: 'offsetof( TextureDesc, mDescriptors) == 96' evaluated to false.");
static_assert(sizeof(TextureDesc::mDescriptors) == 4, "API_Verifier: 'sizeof(TextureDesc::mDescriptors) == 4' evaluated to false.");
static_assert(std::is_same_v<DescriptorType, decltype(TextureDesc::mDescriptors)>, "API_Verifier: 'std::is_same_v<DescriptorType, decltype(TextureDesc::mDescriptors)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mSharedNodeIndexCount)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mSharedNodeIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mSharedNodeIndexCount) == 100, "API_Verifier: 'offsetof( TextureDesc, mSharedNodeIndexCount) == 100' evaluated to false.");
static_assert(sizeof(TextureDesc::mSharedNodeIndexCount) == 4, "API_Verifier: 'sizeof(TextureDesc::mSharedNodeIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mSharedNodeIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mSharedNodeIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(TextureDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(TextureDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( TextureDesc, mNodeIndex) == 104, "API_Verifier: 'offsetof( TextureDesc, mNodeIndex) == 104' evaluated to false.");
static_assert(sizeof(TextureDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(TextureDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof(RenderTargetDesc) == 8, "API_Verifier: 'alignof(RenderTargetDesc) == 8' evaluated to false.");
static_assert(sizeof(RenderTargetDesc) == 104, "API_Verifier: 'sizeof(RenderTargetDesc) == 104' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::pPlacement)) == 8, "API_Verifier: 'alignof( decltype(RenderTargetDesc::pPlacement)) == 8' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, pPlacement) == 0, "API_Verifier: 'offsetof( RenderTargetDesc, pPlacement) == 0' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::pPlacement) == 8, "API_Verifier: 'sizeof(RenderTargetDesc::pPlacement) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement*, decltype(RenderTargetDesc::pPlacement)>, "API_Verifier: 'std::is_same_v<ResourcePlacement*, decltype(RenderTargetDesc::pPlacement)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mFlags) == 8, "API_Verifier: 'offsetof( RenderTargetDesc, mFlags) == 8' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mFlags) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<TextureCreationFlags, decltype(RenderTargetDesc::mFlags)>, "API_Verifier: 'std::is_same_v<TextureCreationFlags, decltype(RenderTargetDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mWidth)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mWidth) == 12, "API_Verifier: 'offsetof( RenderTargetDesc, mWidth) == 12' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mWidth) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mHeight)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mHeight) == 16, "API_Verifier: 'offsetof( RenderTargetDesc, mHeight) == 16' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mHeight) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mDepth)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mDepth)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mDepth) == 20, "API_Verifier: 'offsetof( RenderTargetDesc, mDepth) == 20' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mDepth) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mDepth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mDepth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mDepth)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mArraySize)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mArraySize)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mArraySize) == 24, "API_Verifier: 'offsetof( RenderTargetDesc, mArraySize) == 24' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mArraySize) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mArraySize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mArraySize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mArraySize)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mMipLevels)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mMipLevels)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mMipLevels) == 28, "API_Verifier: 'offsetof( RenderTargetDesc, mMipLevels) == 28' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mMipLevels) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mMipLevels) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mMipLevels)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mMipLevels)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mSampleCount)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mSampleCount)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mSampleCount) == 32, "API_Verifier: 'offsetof( RenderTargetDesc, mSampleCount) == 32' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mSampleCount) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mSampleCount) == 4' evaluated to false.");
static_assert(std::is_same_v<SampleCount, decltype(RenderTargetDesc::mSampleCount)>, "API_Verifier: 'std::is_same_v<SampleCount, decltype(RenderTargetDesc::mSampleCount)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mFormat)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mFormat)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mFormat) == 36, "API_Verifier: 'offsetof( RenderTargetDesc, mFormat) == 36' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mFormat) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(RenderTargetDesc::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(RenderTargetDesc::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mStartState)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mStartState)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mStartState) == 40, "API_Verifier: 'offsetof( RenderTargetDesc, mStartState) == 40' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mStartState) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mStartState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(RenderTargetDesc::mStartState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(RenderTargetDesc::mStartState)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mClearValue)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mClearValue)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mClearValue) == 44, "API_Verifier: 'offsetof( RenderTargetDesc, mClearValue) == 44' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mClearValue) == 16, "API_Verifier: 'sizeof(RenderTargetDesc::mClearValue) == 16' evaluated to false.");
static_assert(std::is_same_v<ClearValue, decltype(RenderTargetDesc::mClearValue)>, "API_Verifier: 'std::is_same_v<ClearValue, decltype(RenderTargetDesc::mClearValue)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mSampleQuality)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mSampleQuality)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mSampleQuality) == 60, "API_Verifier: 'offsetof( RenderTargetDesc, mSampleQuality) == 60' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mSampleQuality) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mSampleQuality) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mSampleQuality)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mSampleQuality)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mDescriptors)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mDescriptors)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mDescriptors) == 64, "API_Verifier: 'offsetof( RenderTargetDesc, mDescriptors) == 64' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mDescriptors) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mDescriptors) == 4' evaluated to false.");
static_assert(std::is_same_v<DescriptorType, decltype(RenderTargetDesc::mDescriptors)>, "API_Verifier: 'std::is_same_v<DescriptorType, decltype(RenderTargetDesc::mDescriptors)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::pNativeHandle)) == 8, "API_Verifier: 'alignof( decltype(RenderTargetDesc::pNativeHandle)) == 8' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, pNativeHandle) == 72, "API_Verifier: 'offsetof( RenderTargetDesc, pNativeHandle) == 72' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::pNativeHandle) == 8, "API_Verifier: 'sizeof(RenderTargetDesc::pNativeHandle) == 8' evaluated to false.");
static_assert(std::is_same_v<const void *, decltype(RenderTargetDesc::pNativeHandle)>, "API_Verifier: 'std::is_same_v<const void *, decltype(RenderTargetDesc::pNativeHandle)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(RenderTargetDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, pName) == 80, "API_Verifier: 'offsetof( RenderTargetDesc, pName) == 80' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::pName) == 8, "API_Verifier: 'sizeof(RenderTargetDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(RenderTargetDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(RenderTargetDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::pSharedNodeIndices)) == 8, "API_Verifier: 'alignof( decltype(RenderTargetDesc::pSharedNodeIndices)) == 8' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, pSharedNodeIndices) == 88, "API_Verifier: 'offsetof( RenderTargetDesc, pSharedNodeIndices) == 88' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::pSharedNodeIndices) == 8, "API_Verifier: 'sizeof(RenderTargetDesc::pSharedNodeIndices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(RenderTargetDesc::pSharedNodeIndices)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(RenderTargetDesc::pSharedNodeIndices)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mSharedNodeIndexCount)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mSharedNodeIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mSharedNodeIndexCount) == 96, "API_Verifier: 'offsetof( RenderTargetDesc, mSharedNodeIndexCount) == 96' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mSharedNodeIndexCount) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mSharedNodeIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mSharedNodeIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mSharedNodeIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(RenderTargetDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(RenderTargetDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( RenderTargetDesc, mNodeIndex) == 100, "API_Verifier: 'offsetof( RenderTargetDesc, mNodeIndex) == 100' evaluated to false.");
static_assert(sizeof(RenderTargetDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(RenderTargetDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RenderTargetDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RenderTargetDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof(SampleLocations) == 1, "API_Verifier: 'alignof(SampleLocations) == 1' evaluated to false.");
static_assert(sizeof(SampleLocations) == 2, "API_Verifier: 'sizeof(SampleLocations) == 2' evaluated to false.");

static_assert(alignof( decltype(SampleLocations::mX)) == 1, "API_Verifier: 'alignof( decltype(SampleLocations::mX)) == 1' evaluated to false.");
static_assert(offsetof( SampleLocations, mX) == 0, "API_Verifier: 'offsetof( SampleLocations, mX) == 0' evaluated to false.");
static_assert(sizeof(SampleLocations::mX) == 1, "API_Verifier: 'sizeof(SampleLocations::mX) == 1' evaluated to false.");
static_assert(std::is_same_v<int8_t, decltype(SampleLocations::mX)>, "API_Verifier: 'std::is_same_v<int8_t, decltype(SampleLocations::mX)>' evaluated to false.");

static_assert(alignof( decltype(SampleLocations::mY)) == 1, "API_Verifier: 'alignof( decltype(SampleLocations::mY)) == 1' evaluated to false.");
static_assert(offsetof( SampleLocations, mY) == 1, "API_Verifier: 'offsetof( SampleLocations, mY) == 1' evaluated to false.");
static_assert(sizeof(SampleLocations::mY) == 1, "API_Verifier: 'sizeof(SampleLocations::mY) == 1' evaluated to false.");
static_assert(std::is_same_v<int8_t, decltype(SampleLocations::mY)>, "API_Verifier: 'std::is_same_v<int8_t, decltype(SampleLocations::mY)>' evaluated to false.");

static_assert(alignof(SamplerDesc) == 4, "API_Verifier: 'alignof(SamplerDesc) == 4' evaluated to false.");
static_assert(sizeof(SamplerDesc) == 76, "API_Verifier: 'sizeof(SamplerDesc) == 76' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMinFilter)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMinFilter)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMinFilter) == 0, "API_Verifier: 'offsetof( SamplerDesc, mMinFilter) == 0' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMinFilter) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMinFilter) == 4' evaluated to false.");
static_assert(std::is_same_v<FilterType, decltype(SamplerDesc::mMinFilter)>, "API_Verifier: 'std::is_same_v<FilterType, decltype(SamplerDesc::mMinFilter)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMagFilter)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMagFilter)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMagFilter) == 4, "API_Verifier: 'offsetof( SamplerDesc, mMagFilter) == 4' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMagFilter) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMagFilter) == 4' evaluated to false.");
static_assert(std::is_same_v<FilterType, decltype(SamplerDesc::mMagFilter)>, "API_Verifier: 'std::is_same_v<FilterType, decltype(SamplerDesc::mMagFilter)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMipMapMode)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMipMapMode)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMipMapMode) == 8, "API_Verifier: 'offsetof( SamplerDesc, mMipMapMode) == 8' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMipMapMode) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMipMapMode) == 4' evaluated to false.");
static_assert(std::is_same_v<MipMapMode, decltype(SamplerDesc::mMipMapMode)>, "API_Verifier: 'std::is_same_v<MipMapMode, decltype(SamplerDesc::mMipMapMode)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mAddressU)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mAddressU)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mAddressU) == 12, "API_Verifier: 'offsetof( SamplerDesc, mAddressU) == 12' evaluated to false.");
static_assert(sizeof(SamplerDesc::mAddressU) == 4, "API_Verifier: 'sizeof(SamplerDesc::mAddressU) == 4' evaluated to false.");
static_assert(std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressU)>, "API_Verifier: 'std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressU)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mAddressV)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mAddressV)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mAddressV) == 16, "API_Verifier: 'offsetof( SamplerDesc, mAddressV) == 16' evaluated to false.");
static_assert(sizeof(SamplerDesc::mAddressV) == 4, "API_Verifier: 'sizeof(SamplerDesc::mAddressV) == 4' evaluated to false.");
static_assert(std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressV)>, "API_Verifier: 'std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressV)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mAddressW)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mAddressW)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mAddressW) == 20, "API_Verifier: 'offsetof( SamplerDesc, mAddressW) == 20' evaluated to false.");
static_assert(sizeof(SamplerDesc::mAddressW) == 4, "API_Verifier: 'sizeof(SamplerDesc::mAddressW) == 4' evaluated to false.");
static_assert(std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressW)>, "API_Verifier: 'std::is_same_v<AddressMode, decltype(SamplerDesc::mAddressW)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMipLodBias)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMipLodBias)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMipLodBias) == 24, "API_Verifier: 'offsetof( SamplerDesc, mMipLodBias) == 24' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMipLodBias) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMipLodBias) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SamplerDesc::mMipLodBias)>, "API_Verifier: 'std::is_same_v<float, decltype(SamplerDesc::mMipLodBias)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mSetLodRange)) == 1, "API_Verifier: 'alignof( decltype(SamplerDesc::mSetLodRange)) == 1' evaluated to false.");
static_assert(offsetof( SamplerDesc, mSetLodRange) == 28, "API_Verifier: 'offsetof( SamplerDesc, mSetLodRange) == 28' evaluated to false.");
static_assert(sizeof(SamplerDesc::mSetLodRange) == 1, "API_Verifier: 'sizeof(SamplerDesc::mSetLodRange) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(SamplerDesc::mSetLodRange)>, "API_Verifier: 'std::is_same_v<bool, decltype(SamplerDesc::mSetLodRange)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMinLod)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMinLod)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMinLod) == 32, "API_Verifier: 'offsetof( SamplerDesc, mMinLod) == 32' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMinLod) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMinLod) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SamplerDesc::mMinLod)>, "API_Verifier: 'std::is_same_v<float, decltype(SamplerDesc::mMinLod)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMaxLod)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMaxLod)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMaxLod) == 36, "API_Verifier: 'offsetof( SamplerDesc, mMaxLod) == 36' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMaxLod) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMaxLod) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SamplerDesc::mMaxLod)>, "API_Verifier: 'std::is_same_v<float, decltype(SamplerDesc::mMaxLod)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mMaxAnisotropy)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mMaxAnisotropy)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mMaxAnisotropy) == 40, "API_Verifier: 'offsetof( SamplerDesc, mMaxAnisotropy) == 40' evaluated to false.");
static_assert(sizeof(SamplerDesc::mMaxAnisotropy) == 4, "API_Verifier: 'sizeof(SamplerDesc::mMaxAnisotropy) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SamplerDesc::mMaxAnisotropy)>, "API_Verifier: 'std::is_same_v<float, decltype(SamplerDesc::mMaxAnisotropy)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mCompareFunc)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mCompareFunc)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mCompareFunc) == 44, "API_Verifier: 'offsetof( SamplerDesc, mCompareFunc) == 44' evaluated to false.");
static_assert(sizeof(SamplerDesc::mCompareFunc) == 4, "API_Verifier: 'sizeof(SamplerDesc::mCompareFunc) == 4' evaluated to false.");
static_assert(std::is_same_v<CompareMode, decltype(SamplerDesc::mCompareFunc)>, "API_Verifier: 'std::is_same_v<CompareMode, decltype(SamplerDesc::mCompareFunc)>' evaluated to false.");

static_assert(alignof( decltype(SamplerDesc::mSamplerConversionDesc)) == 4, "API_Verifier: 'alignof( decltype(SamplerDesc::mSamplerConversionDesc)) == 4' evaluated to false.");
static_assert(offsetof( SamplerDesc, mSamplerConversionDesc) == 48, "API_Verifier: 'offsetof( SamplerDesc, mSamplerConversionDesc) == 48' evaluated to false.");
static_assert(sizeof(SamplerDesc::mSamplerConversionDesc) == 28, "API_Verifier: 'sizeof(SamplerDesc::mSamplerConversionDesc) == 28' evaluated to false.");

static_assert(alignof(decltype(SamplerDesc::mSamplerConversionDesc)) == 4, "API_Verifier: 'alignof(decltype(SamplerDesc::mSamplerConversionDesc)) == 4' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)) == 28, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)) == 28' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mFormat) == 0, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mFormat) == 0' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mModel)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mModel)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mModel) == 4, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mModel) == 4' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mModel) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mModel) == 4' evaluated to false.");
static_assert(std::is_same_v<SamplerModelConversion, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mModel)>, "API_Verifier: 'std::is_same_v<SamplerModelConversion, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mModel)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mRange)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mRange)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mRange) == 8, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mRange) == 8' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mRange) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mRange) == 4' evaluated to false.");
static_assert(std::is_same_v<SamplerRange, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mRange)>, "API_Verifier: 'std::is_same_v<SamplerRange, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mRange)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaOffsetX) == 12, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaOffsetX) == 12' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX) == 4' evaluated to false.");
static_assert(std::is_same_v<SampleLocation, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX)>, "API_Verifier: 'std::is_same_v<SampleLocation, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetX)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaOffsetY) == 16, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaOffsetY) == 16' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY) == 4' evaluated to false.");
static_assert(std::is_same_v<SampleLocation, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY)>, "API_Verifier: 'std::is_same_v<SampleLocation, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaOffsetY)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter)) == 4, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter)) == 4' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaFilter) == 20, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mChromaFilter) == 20' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter) == 4, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter) == 4' evaluated to false.");
static_assert(std::is_same_v<FilterType, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter)>, "API_Verifier: 'std::is_same_v<FilterType, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mChromaFilter)>' evaluated to false.");

static_assert(alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction)) == 1, "API_Verifier: 'alignof( decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction)) == 1' evaluated to false.");
static_assert(offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mForceExplicitReconstruction) == 24, "API_Verifier: 'offsetof( decltype(SamplerDesc::mSamplerConversionDesc), mForceExplicitReconstruction) == 24' evaluated to false.");
static_assert(sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction) == 1, "API_Verifier: 'sizeof(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction)>, "API_Verifier: 'std::is_same_v<bool, decltype(decltype(SamplerDesc::mSamplerConversionDesc)::mForceExplicitReconstruction)>' evaluated to false.");

static_assert(alignof(RootSignatureDesc) == 8, "API_Verifier: 'alignof(RootSignatureDesc) == 8' evaluated to false.");
static_assert(sizeof(RootSignatureDesc) == 40, "API_Verifier: 'sizeof(RootSignatureDesc) == 40' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::ppShaders)) == 8, "API_Verifier: 'alignof( decltype(RootSignatureDesc::ppShaders)) == 8' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, ppShaders) == 0, "API_Verifier: 'offsetof( RootSignatureDesc, ppShaders) == 0' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::ppShaders) == 8, "API_Verifier: 'sizeof(RootSignatureDesc::ppShaders) == 8' evaluated to false.");
static_assert(std::is_same_v<Shader **, decltype(RootSignatureDesc::ppShaders)>, "API_Verifier: 'std::is_same_v<Shader **, decltype(RootSignatureDesc::ppShaders)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::mShaderCount)) == 4, "API_Verifier: 'alignof( decltype(RootSignatureDesc::mShaderCount)) == 4' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, mShaderCount) == 8, "API_Verifier: 'offsetof( RootSignatureDesc, mShaderCount) == 8' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::mShaderCount) == 4, "API_Verifier: 'sizeof(RootSignatureDesc::mShaderCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RootSignatureDesc::mShaderCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RootSignatureDesc::mShaderCount)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::mMaxBindlessTextures)) == 4, "API_Verifier: 'alignof( decltype(RootSignatureDesc::mMaxBindlessTextures)) == 4' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, mMaxBindlessTextures) == 12, "API_Verifier: 'offsetof( RootSignatureDesc, mMaxBindlessTextures) == 12' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::mMaxBindlessTextures) == 4, "API_Verifier: 'sizeof(RootSignatureDesc::mMaxBindlessTextures) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RootSignatureDesc::mMaxBindlessTextures)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RootSignatureDesc::mMaxBindlessTextures)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::ppStaticSamplerNames)) == 8, "API_Verifier: 'alignof( decltype(RootSignatureDesc::ppStaticSamplerNames)) == 8' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, ppStaticSamplerNames) == 16, "API_Verifier: 'offsetof( RootSignatureDesc, ppStaticSamplerNames) == 16' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::ppStaticSamplerNames) == 8, "API_Verifier: 'sizeof(RootSignatureDesc::ppStaticSamplerNames) == 8' evaluated to false.");
static_assert(std::is_same_v<const char **, decltype(RootSignatureDesc::ppStaticSamplerNames)>, "API_Verifier: 'std::is_same_v<const char **, decltype(RootSignatureDesc::ppStaticSamplerNames)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::ppStaticSamplers)) == 8, "API_Verifier: 'alignof( decltype(RootSignatureDesc::ppStaticSamplers)) == 8' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, ppStaticSamplers) == 24, "API_Verifier: 'offsetof( RootSignatureDesc, ppStaticSamplers) == 24' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::ppStaticSamplers) == 8, "API_Verifier: 'sizeof(RootSignatureDesc::ppStaticSamplers) == 8' evaluated to false.");
static_assert(std::is_same_v<Sampler **, decltype(RootSignatureDesc::ppStaticSamplers)>, "API_Verifier: 'std::is_same_v<Sampler **, decltype(RootSignatureDesc::ppStaticSamplers)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::mStaticSamplerCount)) == 4, "API_Verifier: 'alignof( decltype(RootSignatureDesc::mStaticSamplerCount)) == 4' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, mStaticSamplerCount) == 32, "API_Verifier: 'offsetof( RootSignatureDesc, mStaticSamplerCount) == 32' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::mStaticSamplerCount) == 4, "API_Verifier: 'sizeof(RootSignatureDesc::mStaticSamplerCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RootSignatureDesc::mStaticSamplerCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RootSignatureDesc::mStaticSamplerCount)>' evaluated to false.");

static_assert(alignof( decltype(RootSignatureDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(RootSignatureDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( RootSignatureDesc, mFlags) == 36, "API_Verifier: 'offsetof( RootSignatureDesc, mFlags) == 36' evaluated to false.");
static_assert(sizeof(RootSignatureDesc::mFlags) == 4, "API_Verifier: 'sizeof(RootSignatureDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<RootSignatureFlags, decltype(RootSignatureDesc::mFlags)>, "API_Verifier: 'std::is_same_v<RootSignatureFlags, decltype(RootSignatureDesc::mFlags)>' evaluated to false.");

static_assert(alignof(DescriptorDataRange) == 4, "API_Verifier: 'alignof(DescriptorDataRange) == 4' evaluated to false.");
static_assert(sizeof(DescriptorDataRange) == 12, "API_Verifier: 'sizeof(DescriptorDataRange) == 12' evaluated to false.");

static_assert(alignof( decltype(DescriptorDataRange::mOffset)) == 4, "API_Verifier: 'alignof( decltype(DescriptorDataRange::mOffset)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorDataRange, mOffset) == 0, "API_Verifier: 'offsetof( DescriptorDataRange, mOffset) == 0' evaluated to false.");
static_assert(sizeof(DescriptorDataRange::mOffset) == 4, "API_Verifier: 'sizeof(DescriptorDataRange::mOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorDataRange::mOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorDataRange::mOffset)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorDataRange::mSize)) == 4, "API_Verifier: 'alignof( decltype(DescriptorDataRange::mSize)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorDataRange, mSize) == 4, "API_Verifier: 'offsetof( DescriptorDataRange, mSize) == 4' evaluated to false.");
static_assert(sizeof(DescriptorDataRange::mSize) == 4, "API_Verifier: 'sizeof(DescriptorDataRange::mSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorDataRange::mSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorDataRange::mSize)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorDataRange::mStructStride)) == 4, "API_Verifier: 'alignof( decltype(DescriptorDataRange::mStructStride)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorDataRange, mStructStride) == 8, "API_Verifier: 'offsetof( DescriptorDataRange, mStructStride) == 8' evaluated to false.");
static_assert(sizeof(DescriptorDataRange::mStructStride) == 4, "API_Verifier: 'sizeof(DescriptorDataRange::mStructStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorDataRange::mStructStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorDataRange::mStructStride)>' evaluated to false.");

static_assert(alignof(DescriptorData) == 8, "API_Verifier: 'alignof(DescriptorData) == 8' evaluated to false.");
static_assert(sizeof(DescriptorData) == 56, "API_Verifier: 'sizeof(DescriptorData) == 56' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::pName)) == 8, "API_Verifier: 'alignof( decltype(DescriptorData::pName)) == 8' evaluated to false.");
static_assert(offsetof( DescriptorData, pName) == 0, "API_Verifier: 'offsetof( DescriptorData, pName) == 0' evaluated to false.");
static_assert(sizeof(DescriptorData::pName) == 8, "API_Verifier: 'sizeof(DescriptorData::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(DescriptorData::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(DescriptorData::pName)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::mCount)) == 4, "API_Verifier: 'alignof( decltype(DescriptorData::mCount)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorData::mCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorData::mCount)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::mArrayOffset)) == 4, "API_Verifier: 'alignof( decltype(DescriptorData::mArrayOffset)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorData::mArrayOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorData::mArrayOffset)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::mIndex)) == 4, "API_Verifier: 'alignof( decltype(DescriptorData::mIndex)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorData::mIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorData::mIndex)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::mBindByIndex)) == 4, "API_Verifier: 'alignof( decltype(DescriptorData::mBindByIndex)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorData::mBindByIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorData::mBindByIndex)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::pRanges)) == 8, "API_Verifier: 'alignof( decltype(DescriptorData::pRanges)) == 8' evaluated to false.");
static_assert(offsetof( DescriptorData, pRanges) == 16, "API_Verifier: 'offsetof( DescriptorData, pRanges) == 16' evaluated to false.");
static_assert(sizeof(DescriptorData::pRanges) == 8, "API_Verifier: 'sizeof(DescriptorData::pRanges) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorDataRange*, decltype(DescriptorData::pRanges)>, "API_Verifier: 'std::is_same_v<DescriptorDataRange*, decltype(DescriptorData::pRanges)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorData::mBindStencilResource)) == 1, "API_Verifier: 'alignof( decltype(DescriptorData::mBindStencilResource)) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(DescriptorData::mBindStencilResource)>, "API_Verifier: 'std::is_same_v<bool, decltype(DescriptorData::mBindStencilResource)>' evaluated to false.");

static_assert(alignof(CmdPoolDesc) == 8, "API_Verifier: 'alignof(CmdPoolDesc) == 8' evaluated to false.");
static_assert(sizeof(CmdPoolDesc) == 16, "API_Verifier: 'sizeof(CmdPoolDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(CmdPoolDesc::pQueue)) == 8, "API_Verifier: 'alignof( decltype(CmdPoolDesc::pQueue)) == 8' evaluated to false.");
static_assert(offsetof( CmdPoolDesc, pQueue) == 0, "API_Verifier: 'offsetof( CmdPoolDesc, pQueue) == 0' evaluated to false.");
static_assert(sizeof(CmdPoolDesc::pQueue) == 8, "API_Verifier: 'sizeof(CmdPoolDesc::pQueue) == 8' evaluated to false.");
static_assert(std::is_same_v<Queue*, decltype(CmdPoolDesc::pQueue)>, "API_Verifier: 'std::is_same_v<Queue*, decltype(CmdPoolDesc::pQueue)>' evaluated to false.");

static_assert(alignof( decltype(CmdPoolDesc::mTransient)) == 1, "API_Verifier: 'alignof( decltype(CmdPoolDesc::mTransient)) == 1' evaluated to false.");
static_assert(offsetof( CmdPoolDesc, mTransient) == 8, "API_Verifier: 'offsetof( CmdPoolDesc, mTransient) == 8' evaluated to false.");
static_assert(sizeof(CmdPoolDesc::mTransient) == 1, "API_Verifier: 'sizeof(CmdPoolDesc::mTransient) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CmdPoolDesc::mTransient)>, "API_Verifier: 'std::is_same_v<bool, decltype(CmdPoolDesc::mTransient)>' evaluated to false.");

static_assert(alignof(CmdPool) == 8, "API_Verifier: 'alignof(CmdPool) == 8' evaluated to false.");
static_assert(sizeof(CmdPool) == 16, "API_Verifier: 'sizeof(CmdPool) == 16' evaluated to false.");

static_assert(alignof( decltype(CmdPool::pQueue)) == 8, "API_Verifier: 'alignof( decltype(CmdPool::pQueue)) == 8' evaluated to false.");
static_assert(offsetof( CmdPool, pQueue) == 8, "API_Verifier: 'offsetof( CmdPool, pQueue) == 8' evaluated to false.");
static_assert(sizeof(CmdPool::pQueue) == 8, "API_Verifier: 'sizeof(CmdPool::pQueue) == 8' evaluated to false.");
static_assert(std::is_same_v<Queue*, decltype(CmdPool::pQueue)>, "API_Verifier: 'std::is_same_v<Queue*, decltype(CmdPool::pQueue)>' evaluated to false.");

static_assert(alignof(CmdDesc) == 8, "API_Verifier: 'alignof(CmdDesc) == 8' evaluated to false.");
static_assert(sizeof(CmdDesc) == 24, "API_Verifier: 'sizeof(CmdDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(CmdDesc::pPool)) == 8, "API_Verifier: 'alignof( decltype(CmdDesc::pPool)) == 8' evaluated to false.");
static_assert(offsetof( CmdDesc, pPool) == 0, "API_Verifier: 'offsetof( CmdDesc, pPool) == 0' evaluated to false.");
static_assert(sizeof(CmdDesc::pPool) == 8, "API_Verifier: 'sizeof(CmdDesc::pPool) == 8' evaluated to false.");
static_assert(std::is_same_v<CmdPool*, decltype(CmdDesc::pPool)>, "API_Verifier: 'std::is_same_v<CmdPool*, decltype(CmdDesc::pPool)>' evaluated to false.");

static_assert(alignof( decltype(CmdDesc::mSecondary)) == 1, "API_Verifier: 'alignof( decltype(CmdDesc::mSecondary)) == 1' evaluated to false.");
static_assert(offsetof( CmdDesc, mSecondary) == 8, "API_Verifier: 'offsetof( CmdDesc, mSecondary) == 8' evaluated to false.");
static_assert(sizeof(CmdDesc::mSecondary) == 1, "API_Verifier: 'sizeof(CmdDesc::mSecondary) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CmdDesc::mSecondary)>, "API_Verifier: 'std::is_same_v<bool, decltype(CmdDesc::mSecondary)>' evaluated to false.");

static_assert(alignof( decltype(CmdDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(CmdDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( CmdDesc, pName) == 16, "API_Verifier: 'offsetof( CmdDesc, pName) == 16' evaluated to false.");
static_assert(sizeof(CmdDesc::pName) == 8, "API_Verifier: 'sizeof(CmdDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(CmdDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(CmdDesc::pName)>' evaluated to false.");

static_assert(alignof(MarkerDesc) == 8, "API_Verifier: 'alignof(MarkerDesc) == 8' evaluated to false.");
static_assert(sizeof(MarkerDesc) == 24, "API_Verifier: 'sizeof(MarkerDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(MarkerDesc::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(MarkerDesc::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( MarkerDesc, pBuffer) == 0, "API_Verifier: 'offsetof( MarkerDesc, pBuffer) == 0' evaluated to false.");
static_assert(sizeof(MarkerDesc::pBuffer) == 8, "API_Verifier: 'sizeof(MarkerDesc::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(MarkerDesc::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(MarkerDesc::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(MarkerDesc::mOffset)) == 4, "API_Verifier: 'alignof( decltype(MarkerDesc::mOffset)) == 4' evaluated to false.");
static_assert(offsetof( MarkerDesc, mOffset) == 8, "API_Verifier: 'offsetof( MarkerDesc, mOffset) == 8' evaluated to false.");
static_assert(sizeof(MarkerDesc::mOffset) == 4, "API_Verifier: 'sizeof(MarkerDesc::mOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MarkerDesc::mOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MarkerDesc::mOffset)>' evaluated to false.");

static_assert(alignof( decltype(MarkerDesc::mValue)) == 4, "API_Verifier: 'alignof( decltype(MarkerDesc::mValue)) == 4' evaluated to false.");
static_assert(offsetof( MarkerDesc, mValue) == 12, "API_Verifier: 'offsetof( MarkerDesc, mValue) == 12' evaluated to false.");
static_assert(sizeof(MarkerDesc::mValue) == 4, "API_Verifier: 'sizeof(MarkerDesc::mValue) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MarkerDesc::mValue)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MarkerDesc::mValue)>' evaluated to false.");

static_assert(alignof( decltype(MarkerDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(MarkerDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( MarkerDesc, mFlags) == 16, "API_Verifier: 'offsetof( MarkerDesc, mFlags) == 16' evaluated to false.");
static_assert(sizeof(MarkerDesc::mFlags) == 4, "API_Verifier: 'sizeof(MarkerDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<MarkerFlags, decltype(MarkerDesc::mFlags)>, "API_Verifier: 'std::is_same_v<MarkerFlags, decltype(MarkerDesc::mFlags)>' evaluated to false.");

static_assert(alignof(Fence) == 8, "API_Verifier: 'alignof(Fence) == 8' evaluated to false.");
static_assert(sizeof(Fence) == 24, "API_Verifier: 'sizeof(Fence) == 24' evaluated to false.");

static_assert(alignof(Semaphore) == 8, "API_Verifier: 'alignof(Semaphore) == 8' evaluated to false.");
static_assert(sizeof(Semaphore) == 24, "API_Verifier: 'sizeof(Semaphore) == 24' evaluated to false.");

static_assert(alignof(QueueDesc) == 8, "API_Verifier: 'alignof(QueueDesc) == 8' evaluated to false.");
static_assert(sizeof(QueueDesc) == 24, "API_Verifier: 'sizeof(QueueDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(QueueDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(QueueDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( QueueDesc, mType) == 0, "API_Verifier: 'offsetof( QueueDesc, mType) == 0' evaluated to false.");
static_assert(sizeof(QueueDesc::mType) == 4, "API_Verifier: 'sizeof(QueueDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<QueueType, decltype(QueueDesc::mType)>, "API_Verifier: 'std::is_same_v<QueueType, decltype(QueueDesc::mType)>' evaluated to false.");

static_assert(alignof( decltype(QueueDesc::mFlag)) == 4, "API_Verifier: 'alignof( decltype(QueueDesc::mFlag)) == 4' evaluated to false.");
static_assert(offsetof( QueueDesc, mFlag) == 4, "API_Verifier: 'offsetof( QueueDesc, mFlag) == 4' evaluated to false.");
static_assert(sizeof(QueueDesc::mFlag) == 4, "API_Verifier: 'sizeof(QueueDesc::mFlag) == 4' evaluated to false.");
static_assert(std::is_same_v<QueueFlag, decltype(QueueDesc::mFlag)>, "API_Verifier: 'std::is_same_v<QueueFlag, decltype(QueueDesc::mFlag)>' evaluated to false.");

static_assert(alignof( decltype(QueueDesc::mPriority)) == 4, "API_Verifier: 'alignof( decltype(QueueDesc::mPriority)) == 4' evaluated to false.");
static_assert(offsetof( QueueDesc, mPriority) == 8, "API_Verifier: 'offsetof( QueueDesc, mPriority) == 8' evaluated to false.");
static_assert(sizeof(QueueDesc::mPriority) == 4, "API_Verifier: 'sizeof(QueueDesc::mPriority) == 4' evaluated to false.");
static_assert(std::is_same_v<QueuePriority, decltype(QueueDesc::mPriority)>, "API_Verifier: 'std::is_same_v<QueuePriority, decltype(QueueDesc::mPriority)>' evaluated to false.");

static_assert(alignof( decltype(QueueDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(QueueDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( QueueDesc, mNodeIndex) == 12, "API_Verifier: 'offsetof( QueueDesc, mNodeIndex) == 12' evaluated to false.");
static_assert(sizeof(QueueDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(QueueDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueueDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueueDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(QueueDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(QueueDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( QueueDesc, pName) == 16, "API_Verifier: 'offsetof( QueueDesc, pName) == 16' evaluated to false.");
static_assert(sizeof(QueueDesc::pName) == 8, "API_Verifier: 'sizeof(QueueDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(QueueDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(QueueDesc::pName)>' evaluated to false.");

static_assert(alignof(Queue) == 8, "API_Verifier: 'alignof(Queue) == 8' evaluated to false.");
static_assert(sizeof(Queue) == 40, "API_Verifier: 'sizeof(Queue) == 40' evaluated to false.");

static_assert(alignof( decltype(Queue::mType)) == 4, "API_Verifier: 'alignof( decltype(Queue::mType)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Queue::mType)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Queue::mType)>' evaluated to false.");

static_assert(alignof( decltype(Queue::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(Queue::mNodeIndex)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Queue::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Queue::mNodeIndex)>' evaluated to false.");

static_assert(alignof(ShaderConstant) == 8, "API_Verifier: 'alignof(ShaderConstant) == 8' evaluated to false.");
static_assert(sizeof(ShaderConstant) == 16, "API_Verifier: 'sizeof(ShaderConstant) == 16' evaluated to false.");

static_assert(alignof( decltype(ShaderConstant::pValue)) == 8, "API_Verifier: 'alignof( decltype(ShaderConstant::pValue)) == 8' evaluated to false.");
static_assert(offsetof( ShaderConstant, pValue) == 0, "API_Verifier: 'offsetof( ShaderConstant, pValue) == 0' evaluated to false.");
static_assert(sizeof(ShaderConstant::pValue) == 8, "API_Verifier: 'sizeof(ShaderConstant::pValue) == 8' evaluated to false.");
static_assert(std::is_same_v<const void *, decltype(ShaderConstant::pValue)>, "API_Verifier: 'std::is_same_v<const void *, decltype(ShaderConstant::pValue)>' evaluated to false.");

static_assert(alignof( decltype(ShaderConstant::mIndex)) == 4, "API_Verifier: 'alignof( decltype(ShaderConstant::mIndex)) == 4' evaluated to false.");
static_assert(offsetof( ShaderConstant, mIndex) == 8, "API_Verifier: 'offsetof( ShaderConstant, mIndex) == 8' evaluated to false.");
static_assert(sizeof(ShaderConstant::mIndex) == 4, "API_Verifier: 'sizeof(ShaderConstant::mIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderConstant::mIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderConstant::mIndex)>' evaluated to false.");

static_assert(alignof( decltype(ShaderConstant::mSize)) == 4, "API_Verifier: 'alignof( decltype(ShaderConstant::mSize)) == 4' evaluated to false.");
static_assert(offsetof( ShaderConstant, mSize) == 12, "API_Verifier: 'offsetof( ShaderConstant, mSize) == 12' evaluated to false.");
static_assert(sizeof(ShaderConstant::mSize) == 4, "API_Verifier: 'sizeof(ShaderConstant::mSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderConstant::mSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderConstant::mSize)>' evaluated to false.");

static_assert(alignof(BinaryShaderStageDesc) == 8, "API_Verifier: 'alignof(BinaryShaderStageDesc) == 8' evaluated to false.");
static_assert(sizeof(BinaryShaderStageDesc) == 32, "API_Verifier: 'sizeof(BinaryShaderStageDesc) == 32' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderStageDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderStageDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderStageDesc, pName) == 0, "API_Verifier: 'offsetof( BinaryShaderStageDesc, pName) == 0' evaluated to false.");
static_assert(sizeof(BinaryShaderStageDesc::pName) == 8, "API_Verifier: 'sizeof(BinaryShaderStageDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(BinaryShaderStageDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(BinaryShaderStageDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderStageDesc::pByteCode)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderStageDesc::pByteCode)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderStageDesc, pByteCode) == 8, "API_Verifier: 'offsetof( BinaryShaderStageDesc, pByteCode) == 8' evaluated to false.");
static_assert(sizeof(BinaryShaderStageDesc::pByteCode) == 8, "API_Verifier: 'sizeof(BinaryShaderStageDesc::pByteCode) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(BinaryShaderStageDesc::pByteCode)>, "API_Verifier: 'std::is_same_v<void *, decltype(BinaryShaderStageDesc::pByteCode)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderStageDesc::mByteCodeSize)) == 4, "API_Verifier: 'alignof( decltype(BinaryShaderStageDesc::mByteCodeSize)) == 4' evaluated to false.");
static_assert(offsetof( BinaryShaderStageDesc, mByteCodeSize) == 16, "API_Verifier: 'offsetof( BinaryShaderStageDesc, mByteCodeSize) == 16' evaluated to false.");
static_assert(sizeof(BinaryShaderStageDesc::mByteCodeSize) == 4, "API_Verifier: 'sizeof(BinaryShaderStageDesc::mByteCodeSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BinaryShaderStageDesc::mByteCodeSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BinaryShaderStageDesc::mByteCodeSize)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderStageDesc::pEntryPoint)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderStageDesc::pEntryPoint)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderStageDesc, pEntryPoint) == 24, "API_Verifier: 'offsetof( BinaryShaderStageDesc, pEntryPoint) == 24' evaluated to false.");
static_assert(sizeof(BinaryShaderStageDesc::pEntryPoint) == 8, "API_Verifier: 'sizeof(BinaryShaderStageDesc::pEntryPoint) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(BinaryShaderStageDesc::pEntryPoint)>, "API_Verifier: 'std::is_same_v<const char *, decltype(BinaryShaderStageDesc::pEntryPoint)>' evaluated to false.");

static_assert(alignof(BinaryShaderDesc) == 8, "API_Verifier: 'alignof(BinaryShaderDesc) == 8' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc) == 216, "API_Verifier: 'sizeof(BinaryShaderDesc) == 216' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mStages)) == 4, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mStages)) == 4' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mStages) == 0, "API_Verifier: 'offsetof( BinaryShaderDesc, mStages) == 0' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mStages) == 4, "API_Verifier: 'sizeof(BinaryShaderDesc::mStages) == 4' evaluated to false.");
static_assert(std::is_same_v<ShaderStage, decltype(BinaryShaderDesc::mStages)>, "API_Verifier: 'std::is_same_v<ShaderStage, decltype(BinaryShaderDesc::mStages)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mOwnByteCode)) == 4, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mOwnByteCode)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BinaryShaderDesc::mOwnByteCode)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BinaryShaderDesc::mOwnByteCode)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mVert)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mVert)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mVert) == 8, "API_Verifier: 'offsetof( BinaryShaderDesc, mVert) == 8' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mVert) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mVert) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mVert)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mVert)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mFrag)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mFrag)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mFrag) == 40, "API_Verifier: 'offsetof( BinaryShaderDesc, mFrag) == 40' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mFrag) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mFrag) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mFrag)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mFrag)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mGeom)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mGeom)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mGeom) == 72, "API_Verifier: 'offsetof( BinaryShaderDesc, mGeom) == 72' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mGeom) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mGeom) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mGeom)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mGeom)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mHull)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mHull)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mHull) == 104, "API_Verifier: 'offsetof( BinaryShaderDesc, mHull) == 104' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mHull) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mHull) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mHull)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mHull)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mDomain)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mDomain)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mDomain) == 136, "API_Verifier: 'offsetof( BinaryShaderDesc, mDomain) == 136' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mDomain) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mDomain) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mDomain)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mDomain)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mComp)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mComp)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mComp) == 168, "API_Verifier: 'offsetof( BinaryShaderDesc, mComp) == 168' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mComp) == 32, "API_Verifier: 'sizeof(BinaryShaderDesc::mComp) == 32' evaluated to false.");
static_assert(std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mComp)>, "API_Verifier: 'std::is_same_v<BinaryShaderStageDesc, decltype(BinaryShaderDesc::mComp)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::pConstants)) == 8, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::pConstants)) == 8' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, pConstants) == 200, "API_Verifier: 'offsetof( BinaryShaderDesc, pConstants) == 200' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::pConstants) == 8, "API_Verifier: 'sizeof(BinaryShaderDesc::pConstants) == 8' evaluated to false.");
static_assert(std::is_same_v<const ShaderConstant*, decltype(BinaryShaderDesc::pConstants)>, "API_Verifier: 'std::is_same_v<const ShaderConstant*, decltype(BinaryShaderDesc::pConstants)>' evaluated to false.");

static_assert(alignof( decltype(BinaryShaderDesc::mConstantCount)) == 4, "API_Verifier: 'alignof( decltype(BinaryShaderDesc::mConstantCount)) == 4' evaluated to false.");
static_assert(offsetof( BinaryShaderDesc, mConstantCount) == 208, "API_Verifier: 'offsetof( BinaryShaderDesc, mConstantCount) == 208' evaluated to false.");
static_assert(sizeof(BinaryShaderDesc::mConstantCount) == 4, "API_Verifier: 'sizeof(BinaryShaderDesc::mConstantCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BinaryShaderDesc::mConstantCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BinaryShaderDesc::mConstantCount)>' evaluated to false.");

static_assert(alignof(Shader) == 8, "API_Verifier: 'alignof(Shader) == 8' evaluated to false.");
static_assert(sizeof(Shader) == 80, "API_Verifier: 'sizeof(Shader) == 80' evaluated to false.");

static_assert(alignof( decltype(Shader::mStages)) == 4, "API_Verifier: 'alignof( decltype(Shader::mStages)) == 4' evaluated to false.");
static_assert(std::is_same_v<ShaderStage, decltype(Shader::mStages)>, "API_Verifier: 'std::is_same_v<ShaderStage, decltype(Shader::mStages)>' evaluated to false.");

static_assert(alignof( decltype(Shader::mIsMultiviewVR)) == 1, "API_Verifier: 'alignof( decltype(Shader::mIsMultiviewVR)) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(Shader::mIsMultiviewVR)>, "API_Verifier: 'std::is_same_v<bool, decltype(Shader::mIsMultiviewVR)>' evaluated to false.");

static_assert(alignof( decltype(Shader::mNumThreadsPerGroup)) == 4, "API_Verifier: 'alignof( decltype(Shader::mNumThreadsPerGroup)) == 4' evaluated to false.");
static_assert(offsetof( Shader, mNumThreadsPerGroup) == 8, "API_Verifier: 'offsetof( Shader, mNumThreadsPerGroup) == 8' evaluated to false.");
static_assert(sizeof(Shader::mNumThreadsPerGroup) == 12, "API_Verifier: 'sizeof(Shader::mNumThreadsPerGroup) == 12' evaluated to false.");
static_assert(std::is_same_v<uint32_t[3], decltype(Shader::mNumThreadsPerGroup)>, "API_Verifier: 'std::is_same_v<uint32_t[3], decltype(Shader::mNumThreadsPerGroup)>' evaluated to false.");

static_assert(alignof( decltype(Shader::mOutputRenderTargetTypesMask)) == 4, "API_Verifier: 'alignof( decltype(Shader::mOutputRenderTargetTypesMask)) == 4' evaluated to false.");
static_assert(offsetof( Shader, mOutputRenderTargetTypesMask) == 20, "API_Verifier: 'offsetof( Shader, mOutputRenderTargetTypesMask) == 20' evaluated to false.");
static_assert(sizeof(Shader::mOutputRenderTargetTypesMask) == 4, "API_Verifier: 'sizeof(Shader::mOutputRenderTargetTypesMask) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Shader::mOutputRenderTargetTypesMask)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Shader::mOutputRenderTargetTypesMask)>' evaluated to false.");

static_assert(alignof( decltype(Shader::pReflection)) == 8, "API_Verifier: 'alignof( decltype(Shader::pReflection)) == 8' evaluated to false.");
static_assert(offsetof( Shader, pReflection) == 72, "API_Verifier: 'offsetof( Shader, pReflection) == 72' evaluated to false.");
static_assert(sizeof(Shader::pReflection) == 8, "API_Verifier: 'sizeof(Shader::pReflection) == 8' evaluated to false.");
static_assert(std::is_same_v<PipelineReflection*, decltype(Shader::pReflection)>, "API_Verifier: 'std::is_same_v<PipelineReflection*, decltype(Shader::pReflection)>' evaluated to false.");

static_assert(alignof(BlendStateDesc) == 4, "API_Verifier: 'alignof(BlendStateDesc) == 4' evaluated to false.");
static_assert(sizeof(BlendStateDesc) == 232, "API_Verifier: 'sizeof(BlendStateDesc) == 232' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mSrcFactors)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mSrcFactors)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mSrcFactors) == 0, "API_Verifier: 'offsetof( BlendStateDesc, mSrcFactors) == 0' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mSrcFactors) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mSrcFactors) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mSrcFactors)>, "API_Verifier: 'std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mSrcFactors)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mDstFactors)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mDstFactors)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mDstFactors) == 32, "API_Verifier: 'offsetof( BlendStateDesc, mDstFactors) == 32' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mDstFactors) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mDstFactors) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mDstFactors)>, "API_Verifier: 'std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mDstFactors)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mSrcAlphaFactors)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mSrcAlphaFactors)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mSrcAlphaFactors) == 64, "API_Verifier: 'offsetof( BlendStateDesc, mSrcAlphaFactors) == 64' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mSrcAlphaFactors) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mSrcAlphaFactors) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mSrcAlphaFactors)>, "API_Verifier: 'std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mSrcAlphaFactors)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mDstAlphaFactors)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mDstAlphaFactors)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mDstAlphaFactors) == 96, "API_Verifier: 'offsetof( BlendStateDesc, mDstAlphaFactors) == 96' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mDstAlphaFactors) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mDstAlphaFactors) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mDstAlphaFactors)>, "API_Verifier: 'std::is_same_v<BlendConstant[8], decltype(BlendStateDesc::mDstAlphaFactors)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mBlendModes)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mBlendModes)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mBlendModes) == 128, "API_Verifier: 'offsetof( BlendStateDesc, mBlendModes) == 128' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mBlendModes) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mBlendModes) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendMode[8], decltype(BlendStateDesc::mBlendModes)>, "API_Verifier: 'std::is_same_v<BlendMode[8], decltype(BlendStateDesc::mBlendModes)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mBlendAlphaModes)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mBlendAlphaModes)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mBlendAlphaModes) == 160, "API_Verifier: 'offsetof( BlendStateDesc, mBlendAlphaModes) == 160' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mBlendAlphaModes) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mBlendAlphaModes) == 32' evaluated to false.");
static_assert(std::is_same_v<BlendMode[8], decltype(BlendStateDesc::mBlendAlphaModes)>, "API_Verifier: 'std::is_same_v<BlendMode[8], decltype(BlendStateDesc::mBlendAlphaModes)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mColorWriteMasks)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mColorWriteMasks)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mColorWriteMasks) == 192, "API_Verifier: 'offsetof( BlendStateDesc, mColorWriteMasks) == 192' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mColorWriteMasks) == 32, "API_Verifier: 'sizeof(BlendStateDesc::mColorWriteMasks) == 32' evaluated to false.");
static_assert(std::is_same_v<ColorMask[8], decltype(BlendStateDesc::mColorWriteMasks)>, "API_Verifier: 'std::is_same_v<ColorMask[8], decltype(BlendStateDesc::mColorWriteMasks)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mRenderTargetMask)) == 4, "API_Verifier: 'alignof( decltype(BlendStateDesc::mRenderTargetMask)) == 4' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mRenderTargetMask) == 224, "API_Verifier: 'offsetof( BlendStateDesc, mRenderTargetMask) == 224' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mRenderTargetMask) == 4, "API_Verifier: 'sizeof(BlendStateDesc::mRenderTargetMask) == 4' evaluated to false.");
static_assert(std::is_same_v<BlendStateTargets, decltype(BlendStateDesc::mRenderTargetMask)>, "API_Verifier: 'std::is_same_v<BlendStateTargets, decltype(BlendStateDesc::mRenderTargetMask)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mAlphaToCoverage)) == 1, "API_Verifier: 'alignof( decltype(BlendStateDesc::mAlphaToCoverage)) == 1' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mAlphaToCoverage) == 228, "API_Verifier: 'offsetof( BlendStateDesc, mAlphaToCoverage) == 228' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mAlphaToCoverage) == 1, "API_Verifier: 'sizeof(BlendStateDesc::mAlphaToCoverage) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(BlendStateDesc::mAlphaToCoverage)>, "API_Verifier: 'std::is_same_v<bool, decltype(BlendStateDesc::mAlphaToCoverage)>' evaluated to false.");

static_assert(alignof( decltype(BlendStateDesc::mIndependentBlend)) == 1, "API_Verifier: 'alignof( decltype(BlendStateDesc::mIndependentBlend)) == 1' evaluated to false.");
static_assert(offsetof( BlendStateDesc, mIndependentBlend) == 229, "API_Verifier: 'offsetof( BlendStateDesc, mIndependentBlend) == 229' evaluated to false.");
static_assert(sizeof(BlendStateDesc::mIndependentBlend) == 1, "API_Verifier: 'sizeof(BlendStateDesc::mIndependentBlend) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(BlendStateDesc::mIndependentBlend)>, "API_Verifier: 'std::is_same_v<bool, decltype(BlendStateDesc::mIndependentBlend)>' evaluated to false.");

static_assert(alignof(DepthStateDesc) == 4, "API_Verifier: 'alignof(DepthStateDesc) == 4' evaluated to false.");
static_assert(sizeof(DepthStateDesc) == 44, "API_Verifier: 'sizeof(DepthStateDesc) == 44' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mDepthTest)) == 1, "API_Verifier: 'alignof( decltype(DepthStateDesc::mDepthTest)) == 1' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mDepthTest) == 0, "API_Verifier: 'offsetof( DepthStateDesc, mDepthTest) == 0' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mDepthTest) == 1, "API_Verifier: 'sizeof(DepthStateDesc::mDepthTest) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(DepthStateDesc::mDepthTest)>, "API_Verifier: 'std::is_same_v<bool, decltype(DepthStateDesc::mDepthTest)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mDepthWrite)) == 1, "API_Verifier: 'alignof( decltype(DepthStateDesc::mDepthWrite)) == 1' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mDepthWrite) == 1, "API_Verifier: 'offsetof( DepthStateDesc, mDepthWrite) == 1' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mDepthWrite) == 1, "API_Verifier: 'sizeof(DepthStateDesc::mDepthWrite) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(DepthStateDesc::mDepthWrite)>, "API_Verifier: 'std::is_same_v<bool, decltype(DepthStateDesc::mDepthWrite)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mDepthFunc)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mDepthFunc)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mDepthFunc) == 4, "API_Verifier: 'offsetof( DepthStateDesc, mDepthFunc) == 4' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mDepthFunc) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mDepthFunc) == 4' evaluated to false.");
static_assert(std::is_same_v<CompareMode, decltype(DepthStateDesc::mDepthFunc)>, "API_Verifier: 'std::is_same_v<CompareMode, decltype(DepthStateDesc::mDepthFunc)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilTest)) == 1, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilTest)) == 1' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilTest) == 8, "API_Verifier: 'offsetof( DepthStateDesc, mStencilTest) == 8' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilTest) == 1, "API_Verifier: 'sizeof(DepthStateDesc::mStencilTest) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(DepthStateDesc::mStencilTest)>, "API_Verifier: 'std::is_same_v<bool, decltype(DepthStateDesc::mStencilTest)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilReadMask)) == 1, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilReadMask)) == 1' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilReadMask) == 9, "API_Verifier: 'offsetof( DepthStateDesc, mStencilReadMask) == 9' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilReadMask) == 1, "API_Verifier: 'sizeof(DepthStateDesc::mStencilReadMask) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(DepthStateDesc::mStencilReadMask)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(DepthStateDesc::mStencilReadMask)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilWriteMask)) == 1, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilWriteMask)) == 1' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilWriteMask) == 10, "API_Verifier: 'offsetof( DepthStateDesc, mStencilWriteMask) == 10' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilWriteMask) == 1, "API_Verifier: 'sizeof(DepthStateDesc::mStencilWriteMask) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(DepthStateDesc::mStencilWriteMask)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(DepthStateDesc::mStencilWriteMask)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilFrontFunc)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilFrontFunc)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilFrontFunc) == 12, "API_Verifier: 'offsetof( DepthStateDesc, mStencilFrontFunc) == 12' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilFrontFunc) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilFrontFunc) == 4' evaluated to false.");
static_assert(std::is_same_v<CompareMode, decltype(DepthStateDesc::mStencilFrontFunc)>, "API_Verifier: 'std::is_same_v<CompareMode, decltype(DepthStateDesc::mStencilFrontFunc)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilFrontFail)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilFrontFail)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilFrontFail) == 16, "API_Verifier: 'offsetof( DepthStateDesc, mStencilFrontFail) == 16' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilFrontFail) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilFrontFail) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilFrontFail)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilFrontFail)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mDepthFrontFail)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mDepthFrontFail)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mDepthFrontFail) == 20, "API_Verifier: 'offsetof( DepthStateDesc, mDepthFrontFail) == 20' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mDepthFrontFail) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mDepthFrontFail) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mDepthFrontFail)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mDepthFrontFail)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilFrontPass)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilFrontPass)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilFrontPass) == 24, "API_Verifier: 'offsetof( DepthStateDesc, mStencilFrontPass) == 24' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilFrontPass) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilFrontPass) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilFrontPass)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilFrontPass)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilBackFunc)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilBackFunc)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilBackFunc) == 28, "API_Verifier: 'offsetof( DepthStateDesc, mStencilBackFunc) == 28' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilBackFunc) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilBackFunc) == 4' evaluated to false.");
static_assert(std::is_same_v<CompareMode, decltype(DepthStateDesc::mStencilBackFunc)>, "API_Verifier: 'std::is_same_v<CompareMode, decltype(DepthStateDesc::mStencilBackFunc)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilBackFail)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilBackFail)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilBackFail) == 32, "API_Verifier: 'offsetof( DepthStateDesc, mStencilBackFail) == 32' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilBackFail) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilBackFail) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilBackFail)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilBackFail)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mDepthBackFail)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mDepthBackFail)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mDepthBackFail) == 36, "API_Verifier: 'offsetof( DepthStateDesc, mDepthBackFail) == 36' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mDepthBackFail) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mDepthBackFail) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mDepthBackFail)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mDepthBackFail)>' evaluated to false.");

static_assert(alignof( decltype(DepthStateDesc::mStencilBackPass)) == 4, "API_Verifier: 'alignof( decltype(DepthStateDesc::mStencilBackPass)) == 4' evaluated to false.");
static_assert(offsetof( DepthStateDesc, mStencilBackPass) == 40, "API_Verifier: 'offsetof( DepthStateDesc, mStencilBackPass) == 40' evaluated to false.");
static_assert(sizeof(DepthStateDesc::mStencilBackPass) == 4, "API_Verifier: 'sizeof(DepthStateDesc::mStencilBackPass) == 4' evaluated to false.");
static_assert(std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilBackPass)>, "API_Verifier: 'std::is_same_v<StencilOp, decltype(DepthStateDesc::mStencilBackPass)>' evaluated to false.");

static_assert(alignof(RasterizerStateDesc) == 4, "API_Verifier: 'alignof(RasterizerStateDesc) == 4' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc) == 24, "API_Verifier: 'sizeof(RasterizerStateDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mCullMode)) == 4, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mCullMode)) == 4' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mCullMode) == 0, "API_Verifier: 'offsetof( RasterizerStateDesc, mCullMode) == 0' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mCullMode) == 4, "API_Verifier: 'sizeof(RasterizerStateDesc::mCullMode) == 4' evaluated to false.");
static_assert(std::is_same_v<CullMode, decltype(RasterizerStateDesc::mCullMode)>, "API_Verifier: 'std::is_same_v<CullMode, decltype(RasterizerStateDesc::mCullMode)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mDepthBias)) == 4, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mDepthBias)) == 4' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mDepthBias) == 4, "API_Verifier: 'offsetof( RasterizerStateDesc, mDepthBias) == 4' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mDepthBias) == 4, "API_Verifier: 'sizeof(RasterizerStateDesc::mDepthBias) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RasterizerStateDesc::mDepthBias)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RasterizerStateDesc::mDepthBias)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mSlopeScaledDepthBias)) == 4, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mSlopeScaledDepthBias)) == 4' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mSlopeScaledDepthBias) == 8, "API_Verifier: 'offsetof( RasterizerStateDesc, mSlopeScaledDepthBias) == 8' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mSlopeScaledDepthBias) == 4, "API_Verifier: 'sizeof(RasterizerStateDesc::mSlopeScaledDepthBias) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(RasterizerStateDesc::mSlopeScaledDepthBias)>, "API_Verifier: 'std::is_same_v<float, decltype(RasterizerStateDesc::mSlopeScaledDepthBias)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mFillMode)) == 4, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mFillMode)) == 4' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mFillMode) == 12, "API_Verifier: 'offsetof( RasterizerStateDesc, mFillMode) == 12' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mFillMode) == 4, "API_Verifier: 'sizeof(RasterizerStateDesc::mFillMode) == 4' evaluated to false.");
static_assert(std::is_same_v<FillMode, decltype(RasterizerStateDesc::mFillMode)>, "API_Verifier: 'std::is_same_v<FillMode, decltype(RasterizerStateDesc::mFillMode)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mFrontFace)) == 4, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mFrontFace)) == 4' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mFrontFace) == 16, "API_Verifier: 'offsetof( RasterizerStateDesc, mFrontFace) == 16' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mFrontFace) == 4, "API_Verifier: 'sizeof(RasterizerStateDesc::mFrontFace) == 4' evaluated to false.");
static_assert(std::is_same_v<FrontFace, decltype(RasterizerStateDesc::mFrontFace)>, "API_Verifier: 'std::is_same_v<FrontFace, decltype(RasterizerStateDesc::mFrontFace)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mMultiSample)) == 1, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mMultiSample)) == 1' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mMultiSample) == 20, "API_Verifier: 'offsetof( RasterizerStateDesc, mMultiSample) == 20' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mMultiSample) == 1, "API_Verifier: 'sizeof(RasterizerStateDesc::mMultiSample) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RasterizerStateDesc::mMultiSample)>, "API_Verifier: 'std::is_same_v<bool, decltype(RasterizerStateDesc::mMultiSample)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mScissor)) == 1, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mScissor)) == 1' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mScissor) == 21, "API_Verifier: 'offsetof( RasterizerStateDesc, mScissor) == 21' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mScissor) == 1, "API_Verifier: 'sizeof(RasterizerStateDesc::mScissor) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RasterizerStateDesc::mScissor)>, "API_Verifier: 'std::is_same_v<bool, decltype(RasterizerStateDesc::mScissor)>' evaluated to false.");

static_assert(alignof( decltype(RasterizerStateDesc::mDepthClampEnable)) == 1, "API_Verifier: 'alignof( decltype(RasterizerStateDesc::mDepthClampEnable)) == 1' evaluated to false.");
static_assert(offsetof( RasterizerStateDesc, mDepthClampEnable) == 22, "API_Verifier: 'offsetof( RasterizerStateDesc, mDepthClampEnable) == 22' evaluated to false.");
static_assert(sizeof(RasterizerStateDesc::mDepthClampEnable) == 1, "API_Verifier: 'sizeof(RasterizerStateDesc::mDepthClampEnable) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RasterizerStateDesc::mDepthClampEnable)>, "API_Verifier: 'std::is_same_v<bool, decltype(RasterizerStateDesc::mDepthClampEnable)>' evaluated to false.");

static_assert(alignof(VertexBinding) == 4, "API_Verifier: 'alignof(VertexBinding) == 4' evaluated to false.");
static_assert(sizeof(VertexBinding) == 8, "API_Verifier: 'sizeof(VertexBinding) == 8' evaluated to false.");

static_assert(alignof( decltype(VertexBinding::mStride)) == 4, "API_Verifier: 'alignof( decltype(VertexBinding::mStride)) == 4' evaluated to false.");
static_assert(offsetof( VertexBinding, mStride) == 0, "API_Verifier: 'offsetof( VertexBinding, mStride) == 0' evaluated to false.");
static_assert(sizeof(VertexBinding::mStride) == 4, "API_Verifier: 'sizeof(VertexBinding::mStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexBinding::mStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexBinding::mStride)>' evaluated to false.");

static_assert(alignof( decltype(VertexBinding::mRate)) == 4, "API_Verifier: 'alignof( decltype(VertexBinding::mRate)) == 4' evaluated to false.");
static_assert(offsetof( VertexBinding, mRate) == 4, "API_Verifier: 'offsetof( VertexBinding, mRate) == 4' evaluated to false.");
static_assert(sizeof(VertexBinding::mRate) == 4, "API_Verifier: 'sizeof(VertexBinding::mRate) == 4' evaluated to false.");
static_assert(std::is_same_v<VertexBindingRate, decltype(VertexBinding::mRate)>, "API_Verifier: 'std::is_same_v<VertexBindingRate, decltype(VertexBinding::mRate)>' evaluated to false.");

static_assert(alignof(VertexAttrib) == 4, "API_Verifier: 'alignof(VertexAttrib) == 4' evaluated to false.");
static_assert(sizeof(VertexAttrib) == 152, "API_Verifier: 'sizeof(VertexAttrib) == 152' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mSemantic)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mSemantic)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mSemantic) == 0, "API_Verifier: 'offsetof( VertexAttrib, mSemantic) == 0' evaluated to false.");
static_assert(sizeof(VertexAttrib::mSemantic) == 4, "API_Verifier: 'sizeof(VertexAttrib::mSemantic) == 4' evaluated to false.");
static_assert(std::is_same_v<ShaderSemantic, decltype(VertexAttrib::mSemantic)>, "API_Verifier: 'std::is_same_v<ShaderSemantic, decltype(VertexAttrib::mSemantic)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mSemanticNameLength)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mSemanticNameLength)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mSemanticNameLength) == 4, "API_Verifier: 'offsetof( VertexAttrib, mSemanticNameLength) == 4' evaluated to false.");
static_assert(sizeof(VertexAttrib::mSemanticNameLength) == 4, "API_Verifier: 'sizeof(VertexAttrib::mSemanticNameLength) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexAttrib::mSemanticNameLength)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexAttrib::mSemanticNameLength)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mSemanticName)) == 1, "API_Verifier: 'alignof( decltype(VertexAttrib::mSemanticName)) == 1' evaluated to false.");
static_assert(offsetof( VertexAttrib, mSemanticName) == 8, "API_Verifier: 'offsetof( VertexAttrib, mSemanticName) == 8' evaluated to false.");
static_assert(sizeof(VertexAttrib::mSemanticName) == 128, "API_Verifier: 'sizeof(VertexAttrib::mSemanticName) == 128' evaluated to false.");
static_assert(std::is_same_v<char[128], decltype(VertexAttrib::mSemanticName)>, "API_Verifier: 'std::is_same_v<char[128], decltype(VertexAttrib::mSemanticName)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mFormat)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mFormat)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mFormat) == 136, "API_Verifier: 'offsetof( VertexAttrib, mFormat) == 136' evaluated to false.");
static_assert(sizeof(VertexAttrib::mFormat) == 4, "API_Verifier: 'sizeof(VertexAttrib::mFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(VertexAttrib::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(VertexAttrib::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mBinding)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mBinding)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mBinding) == 140, "API_Verifier: 'offsetof( VertexAttrib, mBinding) == 140' evaluated to false.");
static_assert(sizeof(VertexAttrib::mBinding) == 4, "API_Verifier: 'sizeof(VertexAttrib::mBinding) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexAttrib::mBinding)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexAttrib::mBinding)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mLocation)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mLocation)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mLocation) == 144, "API_Verifier: 'offsetof( VertexAttrib, mLocation) == 144' evaluated to false.");
static_assert(sizeof(VertexAttrib::mLocation) == 4, "API_Verifier: 'sizeof(VertexAttrib::mLocation) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexAttrib::mLocation)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexAttrib::mLocation)>' evaluated to false.");

static_assert(alignof( decltype(VertexAttrib::mOffset)) == 4, "API_Verifier: 'alignof( decltype(VertexAttrib::mOffset)) == 4' evaluated to false.");
static_assert(offsetof( VertexAttrib, mOffset) == 148, "API_Verifier: 'offsetof( VertexAttrib, mOffset) == 148' evaluated to false.");
static_assert(sizeof(VertexAttrib::mOffset) == 4, "API_Verifier: 'sizeof(VertexAttrib::mOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexAttrib::mOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexAttrib::mOffset)>' evaluated to false.");

static_assert(alignof(VertexLayout) == 4, "API_Verifier: 'alignof(VertexLayout) == 4' evaluated to false.");
static_assert(sizeof(VertexLayout) == 2408, "API_Verifier: 'sizeof(VertexLayout) == 2408' evaluated to false.");

static_assert(alignof( decltype(VertexLayout::mBindings)) == 4, "API_Verifier: 'alignof( decltype(VertexLayout::mBindings)) == 4' evaluated to false.");
static_assert(offsetof( VertexLayout, mBindings) == 0, "API_Verifier: 'offsetof( VertexLayout, mBindings) == 0' evaluated to false.");
static_assert(sizeof(VertexLayout::mBindings) == 120, "API_Verifier: 'sizeof(VertexLayout::mBindings) == 120' evaluated to false.");
static_assert(std::is_same_v<VertexBinding[15], decltype(VertexLayout::mBindings)>, "API_Verifier: 'std::is_same_v<VertexBinding[15], decltype(VertexLayout::mBindings)>' evaluated to false.");

static_assert(alignof( decltype(VertexLayout::mAttribs)) == 4, "API_Verifier: 'alignof( decltype(VertexLayout::mAttribs)) == 4' evaluated to false.");
static_assert(offsetof( VertexLayout, mAttribs) == 120, "API_Verifier: 'offsetof( VertexLayout, mAttribs) == 120' evaluated to false.");
static_assert(sizeof(VertexLayout::mAttribs) == 2280, "API_Verifier: 'sizeof(VertexLayout::mAttribs) == 2280' evaluated to false.");
static_assert(std::is_same_v<VertexAttrib[15], decltype(VertexLayout::mAttribs)>, "API_Verifier: 'std::is_same_v<VertexAttrib[15], decltype(VertexLayout::mAttribs)>' evaluated to false.");

static_assert(alignof( decltype(VertexLayout::mBindingCount)) == 4, "API_Verifier: 'alignof( decltype(VertexLayout::mBindingCount)) == 4' evaluated to false.");
static_assert(offsetof( VertexLayout, mBindingCount) == 2400, "API_Verifier: 'offsetof( VertexLayout, mBindingCount) == 2400' evaluated to false.");
static_assert(sizeof(VertexLayout::mBindingCount) == 4, "API_Verifier: 'sizeof(VertexLayout::mBindingCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexLayout::mBindingCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexLayout::mBindingCount)>' evaluated to false.");

static_assert(alignof( decltype(VertexLayout::mAttribCount)) == 4, "API_Verifier: 'alignof( decltype(VertexLayout::mAttribCount)) == 4' evaluated to false.");
static_assert(offsetof( VertexLayout, mAttribCount) == 2404, "API_Verifier: 'offsetof( VertexLayout, mAttribCount) == 2404' evaluated to false.");
static_assert(sizeof(VertexLayout::mAttribCount) == 4, "API_Verifier: 'sizeof(VertexLayout::mAttribCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VertexLayout::mAttribCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VertexLayout::mAttribCount)>' evaluated to false.");

static_assert(alignof(GraphicsPipelineDesc) == 8, "API_Verifier: 'alignof(GraphicsPipelineDesc) == 8' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc) == 80, "API_Verifier: 'sizeof(GraphicsPipelineDesc) == 80' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pShaderProgram)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pShaderProgram)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pShaderProgram) == 0, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pShaderProgram) == 0' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pShaderProgram) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pShaderProgram) == 8' evaluated to false.");
static_assert(std::is_same_v<Shader*, decltype(GraphicsPipelineDesc::pShaderProgram)>, "API_Verifier: 'std::is_same_v<Shader*, decltype(GraphicsPipelineDesc::pShaderProgram)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pRootSignature)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pRootSignature)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pRootSignature) == 8, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pRootSignature) == 8' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pRootSignature) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pRootSignature) == 8' evaluated to false.");
static_assert(std::is_same_v<RootSignature*, decltype(GraphicsPipelineDesc::pRootSignature)>, "API_Verifier: 'std::is_same_v<RootSignature*, decltype(GraphicsPipelineDesc::pRootSignature)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pVertexLayout)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pVertexLayout)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pVertexLayout) == 16, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pVertexLayout) == 16' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pVertexLayout) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pVertexLayout) == 8' evaluated to false.");
static_assert(std::is_same_v<VertexLayout*, decltype(GraphicsPipelineDesc::pVertexLayout)>, "API_Verifier: 'std::is_same_v<VertexLayout*, decltype(GraphicsPipelineDesc::pVertexLayout)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pBlendState)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pBlendState)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pBlendState) == 24, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pBlendState) == 24' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pBlendState) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pBlendState) == 8' evaluated to false.");
static_assert(std::is_same_v<BlendStateDesc*, decltype(GraphicsPipelineDesc::pBlendState)>, "API_Verifier: 'std::is_same_v<BlendStateDesc*, decltype(GraphicsPipelineDesc::pBlendState)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pDepthState)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pDepthState)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pDepthState) == 32, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pDepthState) == 32' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pDepthState) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pDepthState) == 8' evaluated to false.");
static_assert(std::is_same_v<DepthStateDesc*, decltype(GraphicsPipelineDesc::pDepthState)>, "API_Verifier: 'std::is_same_v<DepthStateDesc*, decltype(GraphicsPipelineDesc::pDepthState)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pRasterizerState)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pRasterizerState)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pRasterizerState) == 40, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pRasterizerState) == 40' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pRasterizerState) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pRasterizerState) == 8' evaluated to false.");
static_assert(std::is_same_v<RasterizerStateDesc*, decltype(GraphicsPipelineDesc::pRasterizerState)>, "API_Verifier: 'std::is_same_v<RasterizerStateDesc*, decltype(GraphicsPipelineDesc::pRasterizerState)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::pColorFormats)) == 8, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::pColorFormats)) == 8' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, pColorFormats) == 48, "API_Verifier: 'offsetof( GraphicsPipelineDesc, pColorFormats) == 48' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::pColorFormats) == 8, "API_Verifier: 'sizeof(GraphicsPipelineDesc::pColorFormats) == 8' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat*, decltype(GraphicsPipelineDesc::pColorFormats)>, "API_Verifier: 'std::is_same_v<TinyImageFormat*, decltype(GraphicsPipelineDesc::pColorFormats)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mRenderTargetCount)) == 4, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mRenderTargetCount)) == 4' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mRenderTargetCount) == 56, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mRenderTargetCount) == 56' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mRenderTargetCount) == 4, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mRenderTargetCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GraphicsPipelineDesc::mRenderTargetCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GraphicsPipelineDesc::mRenderTargetCount)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mSampleCount)) == 4, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mSampleCount)) == 4' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mSampleCount) == 60, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mSampleCount) == 60' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mSampleCount) == 4, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mSampleCount) == 4' evaluated to false.");
static_assert(std::is_same_v<SampleCount, decltype(GraphicsPipelineDesc::mSampleCount)>, "API_Verifier: 'std::is_same_v<SampleCount, decltype(GraphicsPipelineDesc::mSampleCount)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mSampleQuality)) == 4, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mSampleQuality)) == 4' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mSampleQuality) == 64, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mSampleQuality) == 64' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mSampleQuality) == 4, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mSampleQuality) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GraphicsPipelineDesc::mSampleQuality)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GraphicsPipelineDesc::mSampleQuality)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mDepthStencilFormat)) == 4, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mDepthStencilFormat)) == 4' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mDepthStencilFormat) == 68, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mDepthStencilFormat) == 68' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mDepthStencilFormat) == 4, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mDepthStencilFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(GraphicsPipelineDesc::mDepthStencilFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(GraphicsPipelineDesc::mDepthStencilFormat)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mPrimitiveTopo)) == 4, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mPrimitiveTopo)) == 4' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mPrimitiveTopo) == 72, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mPrimitiveTopo) == 72' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mPrimitiveTopo) == 4, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mPrimitiveTopo) == 4' evaluated to false.");
static_assert(std::is_same_v<PrimitiveTopology, decltype(GraphicsPipelineDesc::mPrimitiveTopo)>, "API_Verifier: 'std::is_same_v<PrimitiveTopology, decltype(GraphicsPipelineDesc::mPrimitiveTopo)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mSupportIndirectCommandBuffer)) == 1, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mSupportIndirectCommandBuffer)) == 1' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mSupportIndirectCommandBuffer) == 76, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mSupportIndirectCommandBuffer) == 76' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mSupportIndirectCommandBuffer) == 1, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mSupportIndirectCommandBuffer) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(GraphicsPipelineDesc::mSupportIndirectCommandBuffer)>, "API_Verifier: 'std::is_same_v<bool, decltype(GraphicsPipelineDesc::mSupportIndirectCommandBuffer)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mVRFoveatedRendering)) == 1, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mVRFoveatedRendering)) == 1' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mVRFoveatedRendering) == 77, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mVRFoveatedRendering) == 77' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mVRFoveatedRendering) == 1, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mVRFoveatedRendering) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(GraphicsPipelineDesc::mVRFoveatedRendering)>, "API_Verifier: 'std::is_same_v<bool, decltype(GraphicsPipelineDesc::mVRFoveatedRendering)>' evaluated to false.");

static_assert(alignof( decltype(GraphicsPipelineDesc::mUseCustomSampleLocations)) == 1, "API_Verifier: 'alignof( decltype(GraphicsPipelineDesc::mUseCustomSampleLocations)) == 1' evaluated to false.");
static_assert(offsetof( GraphicsPipelineDesc, mUseCustomSampleLocations) == 78, "API_Verifier: 'offsetof( GraphicsPipelineDesc, mUseCustomSampleLocations) == 78' evaluated to false.");
static_assert(sizeof(GraphicsPipelineDesc::mUseCustomSampleLocations) == 1, "API_Verifier: 'sizeof(GraphicsPipelineDesc::mUseCustomSampleLocations) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(GraphicsPipelineDesc::mUseCustomSampleLocations)>, "API_Verifier: 'std::is_same_v<bool, decltype(GraphicsPipelineDesc::mUseCustomSampleLocations)>' evaluated to false.");

static_assert(alignof(ComputePipelineDesc) == 8, "API_Verifier: 'alignof(ComputePipelineDesc) == 8' evaluated to false.");
static_assert(sizeof(ComputePipelineDesc) == 16, "API_Verifier: 'sizeof(ComputePipelineDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(ComputePipelineDesc::pShaderProgram)) == 8, "API_Verifier: 'alignof( decltype(ComputePipelineDesc::pShaderProgram)) == 8' evaluated to false.");
static_assert(offsetof( ComputePipelineDesc, pShaderProgram) == 0, "API_Verifier: 'offsetof( ComputePipelineDesc, pShaderProgram) == 0' evaluated to false.");
static_assert(sizeof(ComputePipelineDesc::pShaderProgram) == 8, "API_Verifier: 'sizeof(ComputePipelineDesc::pShaderProgram) == 8' evaluated to false.");
static_assert(std::is_same_v<Shader*, decltype(ComputePipelineDesc::pShaderProgram)>, "API_Verifier: 'std::is_same_v<Shader*, decltype(ComputePipelineDesc::pShaderProgram)>' evaluated to false.");

static_assert(alignof( decltype(ComputePipelineDesc::pRootSignature)) == 8, "API_Verifier: 'alignof( decltype(ComputePipelineDesc::pRootSignature)) == 8' evaluated to false.");
static_assert(offsetof( ComputePipelineDesc, pRootSignature) == 8, "API_Verifier: 'offsetof( ComputePipelineDesc, pRootSignature) == 8' evaluated to false.");
static_assert(sizeof(ComputePipelineDesc::pRootSignature) == 8, "API_Verifier: 'sizeof(ComputePipelineDesc::pRootSignature) == 8' evaluated to false.");
static_assert(std::is_same_v<RootSignature*, decltype(ComputePipelineDesc::pRootSignature)>, "API_Verifier: 'std::is_same_v<RootSignature*, decltype(ComputePipelineDesc::pRootSignature)>' evaluated to false.");

static_assert(alignof(PipelineDesc) == 8, "API_Verifier: 'alignof(PipelineDesc) == 8' evaluated to false.");
static_assert(sizeof(PipelineDesc) == 112, "API_Verifier: 'sizeof(PipelineDesc) == 112' evaluated to false.");

static_assert(alignof( decltype(PipelineDesc::pCache)) == 8, "API_Verifier: 'alignof( decltype(PipelineDesc::pCache)) == 8' evaluated to false.");
static_assert(offsetof( PipelineDesc, pCache) == 80, "API_Verifier: 'offsetof( PipelineDesc, pCache) == 80' evaluated to false.");
static_assert(sizeof(PipelineDesc::pCache) == 8, "API_Verifier: 'sizeof(PipelineDesc::pCache) == 8' evaluated to false.");
static_assert(std::is_same_v<PipelineCache*, decltype(PipelineDesc::pCache)>, "API_Verifier: 'std::is_same_v<PipelineCache*, decltype(PipelineDesc::pCache)>' evaluated to false.");

static_assert(alignof( decltype(PipelineDesc::pPipelineExtensions)) == 8, "API_Verifier: 'alignof( decltype(PipelineDesc::pPipelineExtensions)) == 8' evaluated to false.");
static_assert(offsetof( PipelineDesc, pPipelineExtensions) == 88, "API_Verifier: 'offsetof( PipelineDesc, pPipelineExtensions) == 88' evaluated to false.");
static_assert(sizeof(PipelineDesc::pPipelineExtensions) == 8, "API_Verifier: 'sizeof(PipelineDesc::pPipelineExtensions) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(PipelineDesc::pPipelineExtensions)>, "API_Verifier: 'std::is_same_v<void *, decltype(PipelineDesc::pPipelineExtensions)>' evaluated to false.");

static_assert(alignof( decltype(PipelineDesc::pName)) == 8, "API_Verifier: 'alignof( decltype(PipelineDesc::pName)) == 8' evaluated to false.");
static_assert(offsetof( PipelineDesc, pName) == 96, "API_Verifier: 'offsetof( PipelineDesc, pName) == 96' evaluated to false.");
static_assert(sizeof(PipelineDesc::pName) == 8, "API_Verifier: 'sizeof(PipelineDesc::pName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(PipelineDesc::pName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(PipelineDesc::pName)>' evaluated to false.");

static_assert(alignof( decltype(PipelineDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(PipelineDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( PipelineDesc, mType) == 104, "API_Verifier: 'offsetof( PipelineDesc, mType) == 104' evaluated to false.");
static_assert(sizeof(PipelineDesc::mType) == 4, "API_Verifier: 'sizeof(PipelineDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<PipelineType, decltype(PipelineDesc::mType)>, "API_Verifier: 'std::is_same_v<PipelineType, decltype(PipelineDesc::mType)>' evaluated to false.");

static_assert(alignof( decltype(PipelineDesc::mExtensionCount)) == 4, "API_Verifier: 'alignof( decltype(PipelineDesc::mExtensionCount)) == 4' evaluated to false.");
static_assert(offsetof( PipelineDesc, mExtensionCount) == 108, "API_Verifier: 'offsetof( PipelineDesc, mExtensionCount) == 108' evaluated to false.");
static_assert(sizeof(PipelineDesc::mExtensionCount) == 4, "API_Verifier: 'sizeof(PipelineDesc::mExtensionCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PipelineDesc::mExtensionCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PipelineDesc::mExtensionCount)>' evaluated to false.");

static_assert(alignof(PipelineCacheDesc) == 8, "API_Verifier: 'alignof(PipelineCacheDesc) == 8' evaluated to false.");
static_assert(sizeof(PipelineCacheDesc) == 24, "API_Verifier: 'sizeof(PipelineCacheDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheDesc::pData)) == 8, "API_Verifier: 'alignof( decltype(PipelineCacheDesc::pData)) == 8' evaluated to false.");
static_assert(offsetof( PipelineCacheDesc, pData) == 0, "API_Verifier: 'offsetof( PipelineCacheDesc, pData) == 0' evaluated to false.");
static_assert(sizeof(PipelineCacheDesc::pData) == 8, "API_Verifier: 'sizeof(PipelineCacheDesc::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(PipelineCacheDesc::pData)>, "API_Verifier: 'std::is_same_v<void *, decltype(PipelineCacheDesc::pData)>' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheDesc::mSize)) == 8, "API_Verifier: 'alignof( decltype(PipelineCacheDesc::mSize)) == 8' evaluated to false.");
static_assert(offsetof( PipelineCacheDesc, mSize) == 8, "API_Verifier: 'offsetof( PipelineCacheDesc, mSize) == 8' evaluated to false.");
static_assert(sizeof(PipelineCacheDesc::mSize) == 8, "API_Verifier: 'sizeof(PipelineCacheDesc::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<size_t, decltype(PipelineCacheDesc::mSize)>, "API_Verifier: 'std::is_same_v<size_t, decltype(PipelineCacheDesc::mSize)>' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(PipelineCacheDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( PipelineCacheDesc, mFlags) == 16, "API_Verifier: 'offsetof( PipelineCacheDesc, mFlags) == 16' evaluated to false.");
static_assert(sizeof(PipelineCacheDesc::mFlags) == 4, "API_Verifier: 'sizeof(PipelineCacheDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<PipelineCacheFlags, decltype(PipelineCacheDesc::mFlags)>, "API_Verifier: 'std::is_same_v<PipelineCacheFlags, decltype(PipelineCacheDesc::mFlags)>' evaluated to false.");

static_assert(alignof(PipelineCache) == 8, "API_Verifier: 'alignof(PipelineCache) == 8' evaluated to false.");
static_assert(sizeof(PipelineCache) == 16, "API_Verifier: 'sizeof(PipelineCache) == 16' evaluated to false.");

static_assert(alignof(ShaderStats) == 8, "API_Verifier: 'alignof(ShaderStats) == 8' evaluated to false.");
static_assert(sizeof(ShaderStats) == 72, "API_Verifier: 'sizeof(ShaderStats) == 72' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mUsedVgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mUsedVgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mUsedVgprs) == 16, "API_Verifier: 'offsetof( ShaderStats, mUsedVgprs) == 16' evaluated to false.");
static_assert(sizeof(ShaderStats::mUsedVgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mUsedVgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mUsedVgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mUsedVgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mUsedSgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mUsedSgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mUsedSgprs) == 20, "API_Verifier: 'offsetof( ShaderStats, mUsedSgprs) == 20' evaluated to false.");
static_assert(sizeof(ShaderStats::mUsedSgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mUsedSgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mUsedSgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mUsedSgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mLdsSizePerLocalWorkGroup)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mLdsSizePerLocalWorkGroup)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mLdsSizePerLocalWorkGroup) == 24, "API_Verifier: 'offsetof( ShaderStats, mLdsSizePerLocalWorkGroup) == 24' evaluated to false.");
static_assert(sizeof(ShaderStats::mLdsSizePerLocalWorkGroup) == 4, "API_Verifier: 'sizeof(ShaderStats::mLdsSizePerLocalWorkGroup) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mLdsSizePerLocalWorkGroup)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mLdsSizePerLocalWorkGroup)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mLdsUsageSizeInBytes)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mLdsUsageSizeInBytes)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mLdsUsageSizeInBytes) == 28, "API_Verifier: 'offsetof( ShaderStats, mLdsUsageSizeInBytes) == 28' evaluated to false.");
static_assert(sizeof(ShaderStats::mLdsUsageSizeInBytes) == 4, "API_Verifier: 'sizeof(ShaderStats::mLdsUsageSizeInBytes) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mLdsUsageSizeInBytes)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mLdsUsageSizeInBytes)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mScratchMemUsageInBytes)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mScratchMemUsageInBytes)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mScratchMemUsageInBytes) == 32, "API_Verifier: 'offsetof( ShaderStats, mScratchMemUsageInBytes) == 32' evaluated to false.");
static_assert(sizeof(ShaderStats::mScratchMemUsageInBytes) == 4, "API_Verifier: 'sizeof(ShaderStats::mScratchMemUsageInBytes) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mScratchMemUsageInBytes)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mScratchMemUsageInBytes)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mPhysicalVgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mPhysicalVgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mPhysicalVgprs) == 36, "API_Verifier: 'offsetof( ShaderStats, mPhysicalVgprs) == 36' evaluated to false.");
static_assert(sizeof(ShaderStats::mPhysicalVgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mPhysicalVgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mPhysicalVgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mPhysicalVgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mPhysicalSgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mPhysicalSgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mPhysicalSgprs) == 40, "API_Verifier: 'offsetof( ShaderStats, mPhysicalSgprs) == 40' evaluated to false.");
static_assert(sizeof(ShaderStats::mPhysicalSgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mPhysicalSgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mPhysicalSgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mPhysicalSgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mAvailableVgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mAvailableVgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mAvailableVgprs) == 44, "API_Verifier: 'offsetof( ShaderStats, mAvailableVgprs) == 44' evaluated to false.");
static_assert(sizeof(ShaderStats::mAvailableVgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mAvailableVgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mAvailableVgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mAvailableVgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mAvailableSgprs)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mAvailableSgprs)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mAvailableSgprs) == 48, "API_Verifier: 'offsetof( ShaderStats, mAvailableSgprs) == 48' evaluated to false.");
static_assert(sizeof(ShaderStats::mAvailableSgprs) == 4, "API_Verifier: 'sizeof(ShaderStats::mAvailableSgprs) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderStats::mAvailableSgprs)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderStats::mAvailableSgprs)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mComputeWorkGroupSize)) == 4, "API_Verifier: 'alignof( decltype(ShaderStats::mComputeWorkGroupSize)) == 4' evaluated to false.");
static_assert(offsetof( ShaderStats, mComputeWorkGroupSize) == 52, "API_Verifier: 'offsetof( ShaderStats, mComputeWorkGroupSize) == 52' evaluated to false.");
static_assert(sizeof(ShaderStats::mComputeWorkGroupSize) == 12, "API_Verifier: 'sizeof(ShaderStats::mComputeWorkGroupSize) == 12' evaluated to false.");
static_assert(std::is_same_v<uint32_t[3], decltype(ShaderStats::mComputeWorkGroupSize)>, "API_Verifier: 'std::is_same_v<uint32_t[3], decltype(ShaderStats::mComputeWorkGroupSize)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStats::mValid)) == 1, "API_Verifier: 'alignof( decltype(ShaderStats::mValid)) == 1' evaluated to false.");
static_assert(offsetof( ShaderStats, mValid) == 64, "API_Verifier: 'offsetof( ShaderStats, mValid) == 64' evaluated to false.");
static_assert(sizeof(ShaderStats::mValid) == 1, "API_Verifier: 'sizeof(ShaderStats::mValid) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(ShaderStats::mValid)>, "API_Verifier: 'std::is_same_v<bool, decltype(ShaderStats::mValid)>' evaluated to false.");

static_assert(alignof(PipelineStats) == 8, "API_Verifier: 'alignof(PipelineStats) == 8' evaluated to false.");
static_assert(sizeof(PipelineStats) == 432, "API_Verifier: 'sizeof(PipelineStats) == 432' evaluated to false.");

static_assert(alignof( decltype(PipelineStats::mStats)) == 8, "API_Verifier: 'alignof( decltype(PipelineStats::mStats)) == 8' evaluated to false.");
static_assert(offsetof( PipelineStats, mStats) == 0, "API_Verifier: 'offsetof( PipelineStats, mStats) == 0' evaluated to false.");
static_assert(sizeof(PipelineStats::mStats) == 432, "API_Verifier: 'sizeof(PipelineStats::mStats) == 432' evaluated to false.");
static_assert(std::is_same_v<ShaderStats[6], decltype(PipelineStats::mStats)>, "API_Verifier: 'std::is_same_v<ShaderStats[6], decltype(PipelineStats::mStats)>' evaluated to false.");

static_assert(alignof(SwapChainDesc) == 8, "API_Verifier: 'alignof(SwapChainDesc) == 8' evaluated to false.");
static_assert(sizeof(SwapChainDesc) == 72, "API_Verifier: 'sizeof(SwapChainDesc) == 72' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mWindowHandle)) == 8, "API_Verifier: 'alignof( decltype(SwapChainDesc::mWindowHandle)) == 8' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mWindowHandle) == 0, "API_Verifier: 'offsetof( SwapChainDesc, mWindowHandle) == 0' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mWindowHandle) == 16, "API_Verifier: 'sizeof(SwapChainDesc::mWindowHandle) == 16' evaluated to false.");
static_assert(std::is_same_v<WindowHandle, decltype(SwapChainDesc::mWindowHandle)>, "API_Verifier: 'std::is_same_v<WindowHandle, decltype(SwapChainDesc::mWindowHandle)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::ppPresentQueues)) == 8, "API_Verifier: 'alignof( decltype(SwapChainDesc::ppPresentQueues)) == 8' evaluated to false.");
static_assert(offsetof( SwapChainDesc, ppPresentQueues) == 16, "API_Verifier: 'offsetof( SwapChainDesc, ppPresentQueues) == 16' evaluated to false.");
static_assert(sizeof(SwapChainDesc::ppPresentQueues) == 8, "API_Verifier: 'sizeof(SwapChainDesc::ppPresentQueues) == 8' evaluated to false.");
static_assert(std::is_same_v<Queue **, decltype(SwapChainDesc::ppPresentQueues)>, "API_Verifier: 'std::is_same_v<Queue **, decltype(SwapChainDesc::ppPresentQueues)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mPresentQueueCount)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mPresentQueueCount)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mPresentQueueCount) == 24, "API_Verifier: 'offsetof( SwapChainDesc, mPresentQueueCount) == 24' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mPresentQueueCount) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mPresentQueueCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChainDesc::mPresentQueueCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChainDesc::mPresentQueueCount)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mImageCount)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mImageCount)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mImageCount) == 28, "API_Verifier: 'offsetof( SwapChainDesc, mImageCount) == 28' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mImageCount) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mImageCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChainDesc::mImageCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChainDesc::mImageCount)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mWidth)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mWidth) == 32, "API_Verifier: 'offsetof( SwapChainDesc, mWidth) == 32' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mWidth) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChainDesc::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChainDesc::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mHeight)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mHeight) == 36, "API_Verifier: 'offsetof( SwapChainDesc, mHeight) == 36' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mHeight) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChainDesc::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChainDesc::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mColorFormat)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mColorFormat)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mColorFormat) == 40, "API_Verifier: 'offsetof( SwapChainDesc, mColorFormat) == 40' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mColorFormat) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mColorFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(SwapChainDesc::mColorFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(SwapChainDesc::mColorFormat)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mColorClearValue)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mColorClearValue)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mColorClearValue) == 44, "API_Verifier: 'offsetof( SwapChainDesc, mColorClearValue) == 44' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mColorClearValue) == 16, "API_Verifier: 'sizeof(SwapChainDesc::mColorClearValue) == 16' evaluated to false.");
static_assert(std::is_same_v<ClearValue, decltype(SwapChainDesc::mColorClearValue)>, "API_Verifier: 'std::is_same_v<ClearValue, decltype(SwapChainDesc::mColorClearValue)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mFlags) == 60, "API_Verifier: 'offsetof( SwapChainDesc, mFlags) == 60' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mFlags) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<SwapChainCreationFlags, decltype(SwapChainDesc::mFlags)>, "API_Verifier: 'std::is_same_v<SwapChainCreationFlags, decltype(SwapChainDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mEnableVsync)) == 1, "API_Verifier: 'alignof( decltype(SwapChainDesc::mEnableVsync)) == 1' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mEnableVsync) == 64, "API_Verifier: 'offsetof( SwapChainDesc, mEnableVsync) == 64' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mEnableVsync) == 1, "API_Verifier: 'sizeof(SwapChainDesc::mEnableVsync) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(SwapChainDesc::mEnableVsync)>, "API_Verifier: 'std::is_same_v<bool, decltype(SwapChainDesc::mEnableVsync)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mUseFlipSwapEffect)) == 1, "API_Verifier: 'alignof( decltype(SwapChainDesc::mUseFlipSwapEffect)) == 1' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mUseFlipSwapEffect) == 65, "API_Verifier: 'offsetof( SwapChainDesc, mUseFlipSwapEffect) == 65' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mUseFlipSwapEffect) == 1, "API_Verifier: 'sizeof(SwapChainDesc::mUseFlipSwapEffect) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(SwapChainDesc::mUseFlipSwapEffect)>, "API_Verifier: 'std::is_same_v<bool, decltype(SwapChainDesc::mUseFlipSwapEffect)>' evaluated to false.");

static_assert(alignof( decltype(SwapChainDesc::mColorSpace)) == 4, "API_Verifier: 'alignof( decltype(SwapChainDesc::mColorSpace)) == 4' evaluated to false.");
static_assert(offsetof( SwapChainDesc, mColorSpace) == 68, "API_Verifier: 'offsetof( SwapChainDesc, mColorSpace) == 68' evaluated to false.");
static_assert(sizeof(SwapChainDesc::mColorSpace) == 4, "API_Verifier: 'sizeof(SwapChainDesc::mColorSpace) == 4' evaluated to false.");
static_assert(std::is_same_v<ColorSpace, decltype(SwapChainDesc::mColorSpace)>, "API_Verifier: 'std::is_same_v<ColorSpace, decltype(SwapChainDesc::mColorSpace)>' evaluated to false.");

static_assert(alignof(SwapChain) == 8, "API_Verifier: 'alignof(SwapChain) == 8' evaluated to false.");
static_assert(sizeof(SwapChain) == 56, "API_Verifier: 'sizeof(SwapChain) == 56' evaluated to false.");

static_assert(alignof( decltype(SwapChain::ppRenderTargets)) == 8, "API_Verifier: 'alignof( decltype(SwapChain::ppRenderTargets)) == 8' evaluated to false.");
static_assert(offsetof( SwapChain, ppRenderTargets) == 0, "API_Verifier: 'offsetof( SwapChain, ppRenderTargets) == 0' evaluated to false.");
static_assert(sizeof(SwapChain::ppRenderTargets) == 8, "API_Verifier: 'sizeof(SwapChain::ppRenderTargets) == 8' evaluated to false.");
static_assert(std::is_same_v<RenderTarget **, decltype(SwapChain::ppRenderTargets)>, "API_Verifier: 'std::is_same_v<RenderTarget **, decltype(SwapChain::ppRenderTargets)>' evaluated to false.");

static_assert(alignof( decltype(SwapChain::mImageCount)) == 4, "API_Verifier: 'alignof( decltype(SwapChain::mImageCount)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChain::mImageCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChain::mImageCount)>' evaluated to false.");

static_assert(alignof( decltype(SwapChain::mEnableVsync)) == 4, "API_Verifier: 'alignof( decltype(SwapChain::mEnableVsync)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SwapChain::mEnableVsync)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SwapChain::mEnableVsync)>' evaluated to false.");

static_assert(alignof( decltype(SwapChain::mColorSpace)) == 4, "API_Verifier: 'alignof( decltype(SwapChain::mColorSpace)) == 4' evaluated to false.");
static_assert(std::is_same_v<ColorSpace, decltype(SwapChain::mColorSpace)>, "API_Verifier: 'std::is_same_v<ColorSpace, decltype(SwapChain::mColorSpace)>' evaluated to false.");

static_assert(alignof( decltype(SwapChain::mFormat)) == 4, "API_Verifier: 'alignof( decltype(SwapChain::mFormat)) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(SwapChain::mFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(SwapChain::mFormat)>' evaluated to false.");

static_assert(alignof(RendererDesc) == 8, "API_Verifier: 'alignof(RendererDesc) == 8' evaluated to false.");
static_assert(sizeof(RendererDesc) == 72, "API_Verifier: 'sizeof(RendererDesc) == 72' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mShaderTarget)) == 4, "API_Verifier: 'alignof( decltype(RendererDesc::mShaderTarget)) == 4' evaluated to false.");
static_assert(offsetof( RendererDesc, mShaderTarget) == 40, "API_Verifier: 'offsetof( RendererDesc, mShaderTarget) == 40' evaluated to false.");
static_assert(sizeof(RendererDesc::mShaderTarget) == 4, "API_Verifier: 'sizeof(RendererDesc::mShaderTarget) == 4' evaluated to false.");
static_assert(std::is_same_v<ShaderTarget, decltype(RendererDesc::mShaderTarget)>, "API_Verifier: 'std::is_same_v<ShaderTarget, decltype(RendererDesc::mShaderTarget)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mGpuMode)) == 4, "API_Verifier: 'alignof( decltype(RendererDesc::mGpuMode)) == 4' evaluated to false.");
static_assert(offsetof( RendererDesc, mGpuMode) == 44, "API_Verifier: 'offsetof( RendererDesc, mGpuMode) == 44' evaluated to false.");
static_assert(sizeof(RendererDesc::mGpuMode) == 4, "API_Verifier: 'sizeof(RendererDesc::mGpuMode) == 4' evaluated to false.");
static_assert(std::is_same_v<GpuMode, decltype(RendererDesc::mGpuMode)>, "API_Verifier: 'std::is_same_v<GpuMode, decltype(RendererDesc::mGpuMode)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::pExtendedSettings)) == 8, "API_Verifier: 'alignof( decltype(RendererDesc::pExtendedSettings)) == 8' evaluated to false.");
static_assert(offsetof( RendererDesc, pExtendedSettings) == 48, "API_Verifier: 'offsetof( RendererDesc, pExtendedSettings) == 48' evaluated to false.");
static_assert(sizeof(RendererDesc::pExtendedSettings) == 8, "API_Verifier: 'sizeof(RendererDesc::pExtendedSettings) == 8' evaluated to false.");
static_assert(std::is_same_v<ExtendedSettings*, decltype(RendererDesc::pExtendedSettings)>, "API_Verifier: 'std::is_same_v<ExtendedSettings*, decltype(RendererDesc::pExtendedSettings)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::pContext)) == 8, "API_Verifier: 'alignof( decltype(RendererDesc::pContext)) == 8' evaluated to false.");
static_assert(offsetof( RendererDesc, pContext) == 56, "API_Verifier: 'offsetof( RendererDesc, pContext) == 56' evaluated to false.");
static_assert(sizeof(RendererDesc::pContext) == 8, "API_Verifier: 'sizeof(RendererDesc::pContext) == 8' evaluated to false.");
static_assert(std::is_same_v<RendererContext*, decltype(RendererDesc::pContext)>, "API_Verifier: 'std::is_same_v<RendererContext*, decltype(RendererDesc::pContext)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mGpuIndex)) == 4, "API_Verifier: 'alignof( decltype(RendererDesc::mGpuIndex)) == 4' evaluated to false.");
static_assert(offsetof( RendererDesc, mGpuIndex) == 64, "API_Verifier: 'offsetof( RendererDesc, mGpuIndex) == 64' evaluated to false.");
static_assert(sizeof(RendererDesc::mGpuIndex) == 4, "API_Verifier: 'sizeof(RendererDesc::mGpuIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RendererDesc::mGpuIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RendererDesc::mGpuIndex)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mEnableGpuBasedValidation)) == 1, "API_Verifier: 'alignof( decltype(RendererDesc::mEnableGpuBasedValidation)) == 1' evaluated to false.");
static_assert(offsetof( RendererDesc, mEnableGpuBasedValidation) == 68, "API_Verifier: 'offsetof( RendererDesc, mEnableGpuBasedValidation) == 68' evaluated to false.");
static_assert(sizeof(RendererDesc::mEnableGpuBasedValidation) == 1, "API_Verifier: 'sizeof(RendererDesc::mEnableGpuBasedValidation) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererDesc::mEnableGpuBasedValidation)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererDesc::mEnableGpuBasedValidation)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mEnableShaderStats)) == 1, "API_Verifier: 'alignof( decltype(RendererDesc::mEnableShaderStats)) == 1' evaluated to false.");
static_assert(offsetof( RendererDesc, mEnableShaderStats) == 69, "API_Verifier: 'offsetof( RendererDesc, mEnableShaderStats) == 69' evaluated to false.");
static_assert(sizeof(RendererDesc::mEnableShaderStats) == 1, "API_Verifier: 'sizeof(RendererDesc::mEnableShaderStats) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererDesc::mEnableShaderStats)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererDesc::mEnableShaderStats)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mD3D11Supported)) == 1, "API_Verifier: 'alignof( decltype(RendererDesc::mD3D11Supported)) == 1' evaluated to false.");
static_assert(offsetof( RendererDesc, mD3D11Supported) == 70, "API_Verifier: 'offsetof( RendererDesc, mD3D11Supported) == 70' evaluated to false.");
static_assert(sizeof(RendererDesc::mD3D11Supported) == 1, "API_Verifier: 'sizeof(RendererDesc::mD3D11Supported) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererDesc::mD3D11Supported)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererDesc::mD3D11Supported)>' evaluated to false.");

static_assert(alignof( decltype(RendererDesc::mGLESSupported)) == 1, "API_Verifier: 'alignof( decltype(RendererDesc::mGLESSupported)) == 1' evaluated to false.");
static_assert(offsetof( RendererDesc, mGLESSupported) == 71, "API_Verifier: 'offsetof( RendererDesc, mGLESSupported) == 71' evaluated to false.");
static_assert(sizeof(RendererDesc::mGLESSupported) == 1, "API_Verifier: 'sizeof(RendererDesc::mGLESSupported) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererDesc::mGLESSupported)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererDesc::mGLESSupported)>' evaluated to false.");

static_assert(alignof(GPUVendorPreset) == 4, "API_Verifier: 'alignof(GPUVendorPreset) == 4' evaluated to false.");
static_assert(sizeof(GPUVendorPreset) == 1044, "API_Verifier: 'sizeof(GPUVendorPreset) == 1044' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mVendorId)) == 4, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mVendorId)) == 4' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mVendorId) == 0, "API_Verifier: 'offsetof( GPUVendorPreset, mVendorId) == 0' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mVendorId) == 4, "API_Verifier: 'sizeof(GPUVendorPreset::mVendorId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUVendorPreset::mVendorId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUVendorPreset::mVendorId)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mModelId)) == 4, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mModelId)) == 4' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mModelId) == 4, "API_Verifier: 'offsetof( GPUVendorPreset, mModelId) == 4' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mModelId) == 4, "API_Verifier: 'sizeof(GPUVendorPreset::mModelId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUVendorPreset::mModelId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUVendorPreset::mModelId)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mRevisionId)) == 4, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mRevisionId)) == 4' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mRevisionId) == 8, "API_Verifier: 'offsetof( GPUVendorPreset, mRevisionId) == 8' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mRevisionId) == 4, "API_Verifier: 'sizeof(GPUVendorPreset::mRevisionId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUVendorPreset::mRevisionId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUVendorPreset::mRevisionId)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mPresetLevel)) == 4, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mPresetLevel)) == 4' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mPresetLevel) == 12, "API_Verifier: 'offsetof( GPUVendorPreset, mPresetLevel) == 12' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mPresetLevel) == 4, "API_Verifier: 'sizeof(GPUVendorPreset::mPresetLevel) == 4' evaluated to false.");
static_assert(std::is_same_v<GPUPresetLevel, decltype(GPUVendorPreset::mPresetLevel)>, "API_Verifier: 'std::is_same_v<GPUPresetLevel, decltype(GPUVendorPreset::mPresetLevel)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mVendorName)) == 1, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mVendorName)) == 1' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mVendorName) == 16, "API_Verifier: 'offsetof( GPUVendorPreset, mVendorName) == 16' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mVendorName) == 256, "API_Verifier: 'sizeof(GPUVendorPreset::mVendorName) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(GPUVendorPreset::mVendorName)>, "API_Verifier: 'std::is_same_v<char[256], decltype(GPUVendorPreset::mVendorName)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mGpuName)) == 1, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mGpuName)) == 1' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mGpuName) == 272, "API_Verifier: 'offsetof( GPUVendorPreset, mGpuName) == 272' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mGpuName) == 256, "API_Verifier: 'sizeof(GPUVendorPreset::mGpuName) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuName)>, "API_Verifier: 'std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuName)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mGpuDriverVersion)) == 1, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mGpuDriverVersion)) == 1' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mGpuDriverVersion) == 528, "API_Verifier: 'offsetof( GPUVendorPreset, mGpuDriverVersion) == 528' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mGpuDriverVersion) == 256, "API_Verifier: 'sizeof(GPUVendorPreset::mGpuDriverVersion) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuDriverVersion)>, "API_Verifier: 'std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuDriverVersion)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mGpuDriverDate)) == 1, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mGpuDriverDate)) == 1' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mGpuDriverDate) == 784, "API_Verifier: 'offsetof( GPUVendorPreset, mGpuDriverDate) == 784' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mGpuDriverDate) == 256, "API_Verifier: 'sizeof(GPUVendorPreset::mGpuDriverDate) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuDriverDate)>, "API_Verifier: 'std::is_same_v<char[256], decltype(GPUVendorPreset::mGpuDriverDate)>' evaluated to false.");

static_assert(alignof( decltype(GPUVendorPreset::mRTCoresCount)) == 4, "API_Verifier: 'alignof( decltype(GPUVendorPreset::mRTCoresCount)) == 4' evaluated to false.");
static_assert(offsetof( GPUVendorPreset, mRTCoresCount) == 1040, "API_Verifier: 'offsetof( GPUVendorPreset, mRTCoresCount) == 1040' evaluated to false.");
static_assert(sizeof(GPUVendorPreset::mRTCoresCount) == 4, "API_Verifier: 'sizeof(GPUVendorPreset::mRTCoresCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUVendorPreset::mRTCoresCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUVendorPreset::mRTCoresCount)>' evaluated to false.");

static_assert(alignof(GPUCapBits) == 4, "API_Verifier: 'alignof(GPUCapBits) == 4' evaluated to false.");
static_assert(sizeof(GPUCapBits) == 956, "API_Verifier: 'sizeof(GPUCapBits) == 956' evaluated to false.");

static_assert(alignof( decltype(GPUCapBits::mFormatCaps)) == 4, "API_Verifier: 'alignof( decltype(GPUCapBits::mFormatCaps)) == 4' evaluated to false.");
static_assert(offsetof( GPUCapBits, mFormatCaps) == 0, "API_Verifier: 'offsetof( GPUCapBits, mFormatCaps) == 0' evaluated to false.");
static_assert(sizeof(GPUCapBits::mFormatCaps) == 956, "API_Verifier: 'sizeof(GPUCapBits::mFormatCaps) == 956' evaluated to false.");
static_assert(std::is_same_v<FormatCapability[239], decltype(GPUCapBits::mFormatCaps)>, "API_Verifier: 'std::is_same_v<FormatCapability[239], decltype(GPUCapBits::mFormatCaps)>' evaluated to false.");

static_assert(alignof(GPUSettings) == 8, "API_Verifier: 'alignof(GPUSettings) == 8' evaluated to false.");
static_assert(sizeof(GPUSettings) == 1128, "API_Verifier: 'sizeof(GPUSettings) == 1128' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mVRAM)) == 8, "API_Verifier: 'alignof( decltype(GPUSettings::mVRAM)) == 8' evaluated to false.");
static_assert(offsetof( GPUSettings, mVRAM) == 0, "API_Verifier: 'offsetof( GPUSettings, mVRAM) == 0' evaluated to false.");
static_assert(sizeof(GPUSettings::mVRAM) == 8, "API_Verifier: 'sizeof(GPUSettings::mVRAM) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(GPUSettings::mVRAM)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(GPUSettings::mVRAM)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mUniformBufferAlignment)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mUniformBufferAlignment)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mUniformBufferAlignment) == 8, "API_Verifier: 'offsetof( GPUSettings, mUniformBufferAlignment) == 8' evaluated to false.");
static_assert(sizeof(GPUSettings::mUniformBufferAlignment) == 4, "API_Verifier: 'sizeof(GPUSettings::mUniformBufferAlignment) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mUniformBufferAlignment)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mUniformBufferAlignment)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mUploadBufferTextureAlignment)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mUploadBufferTextureAlignment)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mUploadBufferTextureAlignment) == 12, "API_Verifier: 'offsetof( GPUSettings, mUploadBufferTextureAlignment) == 12' evaluated to false.");
static_assert(sizeof(GPUSettings::mUploadBufferTextureAlignment) == 4, "API_Verifier: 'sizeof(GPUSettings::mUploadBufferTextureAlignment) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mUploadBufferTextureAlignment)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mUploadBufferTextureAlignment)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mUploadBufferTextureRowAlignment)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mUploadBufferTextureRowAlignment)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mUploadBufferTextureRowAlignment) == 16, "API_Verifier: 'offsetof( GPUSettings, mUploadBufferTextureRowAlignment) == 16' evaluated to false.");
static_assert(sizeof(GPUSettings::mUploadBufferTextureRowAlignment) == 4, "API_Verifier: 'sizeof(GPUSettings::mUploadBufferTextureRowAlignment) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mUploadBufferTextureRowAlignment)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mUploadBufferTextureRowAlignment)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMaxVertexInputBindings)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMaxVertexInputBindings)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mMaxVertexInputBindings) == 20, "API_Verifier: 'offsetof( GPUSettings, mMaxVertexInputBindings) == 20' evaluated to false.");
static_assert(sizeof(GPUSettings::mMaxVertexInputBindings) == 4, "API_Verifier: 'sizeof(GPUSettings::mMaxVertexInputBindings) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mMaxVertexInputBindings)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mMaxVertexInputBindings)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMaxRootSignatureDWORDS)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMaxRootSignatureDWORDS)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mMaxRootSignatureDWORDS) == 24, "API_Verifier: 'offsetof( GPUSettings, mMaxRootSignatureDWORDS) == 24' evaluated to false.");
static_assert(sizeof(GPUSettings::mMaxRootSignatureDWORDS) == 4, "API_Verifier: 'sizeof(GPUSettings::mMaxRootSignatureDWORDS) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mMaxRootSignatureDWORDS)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mMaxRootSignatureDWORDS)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mWaveLaneCount)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mWaveLaneCount)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mWaveLaneCount) == 28, "API_Verifier: 'offsetof( GPUSettings, mWaveLaneCount) == 28' evaluated to false.");
static_assert(sizeof(GPUSettings::mWaveLaneCount) == 4, "API_Verifier: 'sizeof(GPUSettings::mWaveLaneCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mWaveLaneCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mWaveLaneCount)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mWaveOpsSupportFlags)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mWaveOpsSupportFlags)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mWaveOpsSupportFlags) == 32, "API_Verifier: 'offsetof( GPUSettings, mWaveOpsSupportFlags) == 32' evaluated to false.");
static_assert(sizeof(GPUSettings::mWaveOpsSupportFlags) == 4, "API_Verifier: 'sizeof(GPUSettings::mWaveOpsSupportFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<WaveOpsSupportFlags, decltype(GPUSettings::mWaveOpsSupportFlags)>, "API_Verifier: 'std::is_same_v<WaveOpsSupportFlags, decltype(GPUSettings::mWaveOpsSupportFlags)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mGpuVendorPreset)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mGpuVendorPreset)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mGpuVendorPreset) == 36, "API_Verifier: 'offsetof( GPUSettings, mGpuVendorPreset) == 36' evaluated to false.");
static_assert(sizeof(GPUSettings::mGpuVendorPreset) == 1044, "API_Verifier: 'sizeof(GPUSettings::mGpuVendorPreset) == 1044' evaluated to false.");
static_assert(std::is_same_v<GPUVendorPreset, decltype(GPUSettings::mGpuVendorPreset)>, "API_Verifier: 'std::is_same_v<GPUVendorPreset, decltype(GPUSettings::mGpuVendorPreset)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mWaveOpsSupportedStageFlags)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mWaveOpsSupportedStageFlags)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mWaveOpsSupportedStageFlags) == 1080, "API_Verifier: 'offsetof( GPUSettings, mWaveOpsSupportedStageFlags) == 1080' evaluated to false.");
static_assert(sizeof(GPUSettings::mWaveOpsSupportedStageFlags) == 4, "API_Verifier: 'sizeof(GPUSettings::mWaveOpsSupportedStageFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<ShaderStage, decltype(GPUSettings::mWaveOpsSupportedStageFlags)>, "API_Verifier: 'std::is_same_v<ShaderStage, decltype(GPUSettings::mWaveOpsSupportedStageFlags)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMaxTotalComputeThreads)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMaxTotalComputeThreads)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mMaxTotalComputeThreads) == 1084, "API_Verifier: 'offsetof( GPUSettings, mMaxTotalComputeThreads) == 1084' evaluated to false.");
static_assert(sizeof(GPUSettings::mMaxTotalComputeThreads) == 4, "API_Verifier: 'sizeof(GPUSettings::mMaxTotalComputeThreads) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mMaxTotalComputeThreads)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mMaxTotalComputeThreads)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMaxComputeThreads)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMaxComputeThreads)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mMaxComputeThreads) == 1088, "API_Verifier: 'offsetof( GPUSettings, mMaxComputeThreads) == 1088' evaluated to false.");
static_assert(sizeof(GPUSettings::mMaxComputeThreads) == 12, "API_Verifier: 'sizeof(GPUSettings::mMaxComputeThreads) == 12' evaluated to false.");
static_assert(std::is_same_v<uint32_t[3], decltype(GPUSettings::mMaxComputeThreads)>, "API_Verifier: 'std::is_same_v<uint32_t[3], decltype(GPUSettings::mMaxComputeThreads)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMultiDrawIndirect)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMultiDrawIndirect)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mMultiDrawIndirect)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mMultiDrawIndirect)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mIndirectRootConstant)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mIndirectRootConstant)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mIndirectRootConstant)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mIndirectRootConstant)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mBuiltinDrawID)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mBuiltinDrawID)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mBuiltinDrawID)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mBuiltinDrawID)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mIndirectCommandBuffer)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mIndirectCommandBuffer)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mIndirectCommandBuffer)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mIndirectCommandBuffer)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mROVsSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mROVsSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mROVsSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mROVsSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mTessellationSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mTessellationSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mTessellationSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mTessellationSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mGeometryShaderSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mGeometryShaderSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mGeometryShaderSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mGeometryShaderSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mGpuMarkers)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mGpuMarkers)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mGpuMarkers)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mGpuMarkers)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mHDRSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mHDRSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mHDRSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mHDRSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mTimestampQueries)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mTimestampQueries)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mTimestampQueries)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mTimestampQueries)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mOcclusionQueries)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mOcclusionQueries)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mOcclusionQueries)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mOcclusionQueries)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mPipelineStatsQueries)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mPipelineStatsQueries)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mPipelineStatsQueries)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mPipelineStatsQueries)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mAllowBufferTextureInSameHeap)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mAllowBufferTextureInSameHeap)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mAllowBufferTextureInSameHeap)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mAllowBufferTextureInSameHeap)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mRaytracingSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mRaytracingSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mRaytracingSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mRaytracingSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mRayPipelineSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mRayPipelineSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mRayPipelineSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mRayPipelineSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mRayQuerySupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mRayQuerySupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mRayQuerySupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mRayQuerySupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mSoftwareVRSSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mSoftwareVRSSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mSoftwareVRSSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mSoftwareVRSSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mPrimitiveIdSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mPrimitiveIdSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mPrimitiveIdSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mPrimitiveIdSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mFeatureLevel)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mFeatureLevel)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mFeatureLevel) == 1104, "API_Verifier: 'offsetof( GPUSettings, mFeatureLevel) == 1104' evaluated to false.");
static_assert(sizeof(GPUSettings::mFeatureLevel) == 4, "API_Verifier: 'sizeof(GPUSettings::mFeatureLevel) == 4' evaluated to false.");
static_assert(std::is_same_v<D3D_FEATURE_LEVEL, decltype(GPUSettings::mFeatureLevel)>, "API_Verifier: 'std::is_same_v<D3D_FEATURE_LEVEL, decltype(GPUSettings::mFeatureLevel)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mDynamicRenderingSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mDynamicRenderingSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mDynamicRenderingSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mDynamicRenderingSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mXclipseTransferQueueWorkaround)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mXclipseTransferQueueWorkaround)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mXclipseTransferQueueWorkaround)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mXclipseTransferQueueWorkaround)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mMaxBoundTextures)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mMaxBoundTextures)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mMaxBoundTextures) == 1112, "API_Verifier: 'offsetof( GPUSettings, mMaxBoundTextures) == 1112' evaluated to false.");
static_assert(sizeof(GPUSettings::mMaxBoundTextures) == 4, "API_Verifier: 'sizeof(GPUSettings::mMaxBoundTextures) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mMaxBoundTextures)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mMaxBoundTextures)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mSamplerAnisotropySupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mSamplerAnisotropySupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mSamplerAnisotropySupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mSamplerAnisotropySupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mGraphicsQueueSupported)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mGraphicsQueueSupported)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mGraphicsQueueSupported)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mGraphicsQueueSupported)>' evaluated to false.");

static_assert(alignof( decltype(GPUSettings::mAmdAsicFamily)) == 4, "API_Verifier: 'alignof( decltype(GPUSettings::mAmdAsicFamily)) == 4' evaluated to false.");
static_assert(offsetof( GPUSettings, mAmdAsicFamily) == 1120, "API_Verifier: 'offsetof( GPUSettings, mAmdAsicFamily) == 1120' evaluated to false.");
static_assert(sizeof(GPUSettings::mAmdAsicFamily) == 4, "API_Verifier: 'sizeof(GPUSettings::mAmdAsicFamily) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GPUSettings::mAmdAsicFamily)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GPUSettings::mAmdAsicFamily)>' evaluated to false.");

static_assert(alignof(RendererContextDesc) == 8, "API_Verifier: 'alignof(RendererContextDesc) == 8' evaluated to false.");
static_assert(sizeof(RendererContextDesc) == 48, "API_Verifier: 'sizeof(RendererContextDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(RendererContextDesc::mEnableGpuBasedValidation)) == 1, "API_Verifier: 'alignof( decltype(RendererContextDesc::mEnableGpuBasedValidation)) == 1' evaluated to false.");
static_assert(offsetof( RendererContextDesc, mEnableGpuBasedValidation) == 40, "API_Verifier: 'offsetof( RendererContextDesc, mEnableGpuBasedValidation) == 40' evaluated to false.");
static_assert(sizeof(RendererContextDesc::mEnableGpuBasedValidation) == 1, "API_Verifier: 'sizeof(RendererContextDesc::mEnableGpuBasedValidation) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererContextDesc::mEnableGpuBasedValidation)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererContextDesc::mEnableGpuBasedValidation)>' evaluated to false.");

static_assert(alignof( decltype(RendererContextDesc::mEnableShaderStats)) == 1, "API_Verifier: 'alignof( decltype(RendererContextDesc::mEnableShaderStats)) == 1' evaluated to false.");
static_assert(offsetof( RendererContextDesc, mEnableShaderStats) == 41, "API_Verifier: 'offsetof( RendererContextDesc, mEnableShaderStats) == 41' evaluated to false.");
static_assert(sizeof(RendererContextDesc::mEnableShaderStats) == 1, "API_Verifier: 'sizeof(RendererContextDesc::mEnableShaderStats) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererContextDesc::mEnableShaderStats)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererContextDesc::mEnableShaderStats)>' evaluated to false.");

static_assert(alignof( decltype(RendererContextDesc::mD3D11Supported)) == 1, "API_Verifier: 'alignof( decltype(RendererContextDesc::mD3D11Supported)) == 1' evaluated to false.");
static_assert(offsetof( RendererContextDesc, mD3D11Supported) == 42, "API_Verifier: 'offsetof( RendererContextDesc, mD3D11Supported) == 42' evaluated to false.");
static_assert(sizeof(RendererContextDesc::mD3D11Supported) == 1, "API_Verifier: 'sizeof(RendererContextDesc::mD3D11Supported) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererContextDesc::mD3D11Supported)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererContextDesc::mD3D11Supported)>' evaluated to false.");

static_assert(alignof( decltype(RendererContextDesc::mGLESSupported)) == 1, "API_Verifier: 'alignof( decltype(RendererContextDesc::mGLESSupported)) == 1' evaluated to false.");
static_assert(offsetof( RendererContextDesc, mGLESSupported) == 43, "API_Verifier: 'offsetof( RendererContextDesc, mGLESSupported) == 43' evaluated to false.");
static_assert(sizeof(RendererContextDesc::mGLESSupported) == 1, "API_Verifier: 'sizeof(RendererContextDesc::mGLESSupported) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RendererContextDesc::mGLESSupported)>, "API_Verifier: 'std::is_same_v<bool, decltype(RendererContextDesc::mGLESSupported)>' evaluated to false.");

static_assert(alignof(GpuInfo) == 8, "API_Verifier: 'alignof(GpuInfo) == 8' evaluated to false.");
static_assert(sizeof(GpuInfo) == 2944, "API_Verifier: 'sizeof(GpuInfo) == 2944' evaluated to false.");

static_assert(alignof( decltype(GpuInfo::mSettings)) == 8, "API_Verifier: 'alignof( decltype(GpuInfo::mSettings)) == 8' evaluated to false.");
static_assert(offsetof( GpuInfo, mSettings) == 856, "API_Verifier: 'offsetof( GpuInfo, mSettings) == 856' evaluated to false.");
static_assert(sizeof(GpuInfo::mSettings) == 1128, "API_Verifier: 'sizeof(GpuInfo::mSettings) == 1128' evaluated to false.");
static_assert(std::is_same_v<GPUSettings, decltype(GpuInfo::mSettings)>, "API_Verifier: 'std::is_same_v<GPUSettings, decltype(GpuInfo::mSettings)>' evaluated to false.");

static_assert(alignof( decltype(GpuInfo::mCapBits)) == 4, "API_Verifier: 'alignof( decltype(GpuInfo::mCapBits)) == 4' evaluated to false.");
static_assert(offsetof( GpuInfo, mCapBits) == 1984, "API_Verifier: 'offsetof( GpuInfo, mCapBits) == 1984' evaluated to false.");
static_assert(sizeof(GpuInfo::mCapBits) == 956, "API_Verifier: 'sizeof(GpuInfo::mCapBits) == 956' evaluated to false.");
static_assert(std::is_same_v<GPUCapBits, decltype(GpuInfo::mCapBits)>, "API_Verifier: 'std::is_same_v<GPUCapBits, decltype(GpuInfo::mCapBits)>' evaluated to false.");

static_assert(alignof(RendererContext) == 8, "API_Verifier: 'alignof(RendererContext) == 8' evaluated to false.");
static_assert(sizeof(RendererContext) == 11816, "API_Verifier: 'sizeof(RendererContext) == 11816' evaluated to false.");

static_assert(alignof( decltype(RendererContext::mGpus)) == 8, "API_Verifier: 'alignof( decltype(RendererContext::mGpus)) == 8' evaluated to false.");
static_assert(offsetof( RendererContext, mGpus) == 32, "API_Verifier: 'offsetof( RendererContext, mGpus) == 32' evaluated to false.");
static_assert(sizeof(RendererContext::mGpus) == 11776, "API_Verifier: 'sizeof(RendererContext::mGpus) == 11776' evaluated to false.");
static_assert(std::is_same_v<GpuInfo[4], decltype(RendererContext::mGpus)>, "API_Verifier: 'std::is_same_v<GpuInfo[4], decltype(RendererContext::mGpus)>' evaluated to false.");

static_assert(alignof( decltype(RendererContext::mGpuCount)) == 4, "API_Verifier: 'alignof( decltype(RendererContext::mGpuCount)) == 4' evaluated to false.");
static_assert(offsetof( RendererContext, mGpuCount) == 11808, "API_Verifier: 'offsetof( RendererContext, mGpuCount) == 11808' evaluated to false.");
static_assert(sizeof(RendererContext::mGpuCount) == 4, "API_Verifier: 'sizeof(RendererContext::mGpuCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(RendererContext::mGpuCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(RendererContext::mGpuCount)>' evaluated to false.");

static_assert(alignof(IndirectArgument) == 4, "API_Verifier: 'alignof(IndirectArgument) == 4' evaluated to false.");
static_assert(sizeof(IndirectArgument) == 8, "API_Verifier: 'sizeof(IndirectArgument) == 8' evaluated to false.");

static_assert(alignof( decltype(IndirectArgument::mType)) == 4, "API_Verifier: 'alignof( decltype(IndirectArgument::mType)) == 4' evaluated to false.");
static_assert(offsetof( IndirectArgument, mType) == 0, "API_Verifier: 'offsetof( IndirectArgument, mType) == 0' evaluated to false.");
static_assert(sizeof(IndirectArgument::mType) == 4, "API_Verifier: 'sizeof(IndirectArgument::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndirectArgumentType, decltype(IndirectArgument::mType)>, "API_Verifier: 'std::is_same_v<IndirectArgumentType, decltype(IndirectArgument::mType)>' evaluated to false.");

static_assert(alignof( decltype(IndirectArgument::mOffset)) == 4, "API_Verifier: 'alignof( decltype(IndirectArgument::mOffset)) == 4' evaluated to false.");
static_assert(offsetof( IndirectArgument, mOffset) == 4, "API_Verifier: 'offsetof( IndirectArgument, mOffset) == 4' evaluated to false.");
static_assert(sizeof(IndirectArgument::mOffset) == 4, "API_Verifier: 'sizeof(IndirectArgument::mOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectArgument::mOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectArgument::mOffset)>' evaluated to false.");

static_assert(alignof(IndirectArgumentDescriptor) == 4, "API_Verifier: 'alignof(IndirectArgumentDescriptor) == 4' evaluated to false.");
static_assert(sizeof(IndirectArgumentDescriptor) == 12, "API_Verifier: 'sizeof(IndirectArgumentDescriptor) == 12' evaluated to false.");

static_assert(alignof( decltype(IndirectArgumentDescriptor::mType)) == 4, "API_Verifier: 'alignof( decltype(IndirectArgumentDescriptor::mType)) == 4' evaluated to false.");
static_assert(offsetof( IndirectArgumentDescriptor, mType) == 0, "API_Verifier: 'offsetof( IndirectArgumentDescriptor, mType) == 0' evaluated to false.");
static_assert(sizeof(IndirectArgumentDescriptor::mType) == 4, "API_Verifier: 'sizeof(IndirectArgumentDescriptor::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndirectArgumentType, decltype(IndirectArgumentDescriptor::mType)>, "API_Verifier: 'std::is_same_v<IndirectArgumentType, decltype(IndirectArgumentDescriptor::mType)>' evaluated to false.");

static_assert(alignof( decltype(IndirectArgumentDescriptor::mIndex)) == 4, "API_Verifier: 'alignof( decltype(IndirectArgumentDescriptor::mIndex)) == 4' evaluated to false.");
static_assert(offsetof( IndirectArgumentDescriptor, mIndex) == 4, "API_Verifier: 'offsetof( IndirectArgumentDescriptor, mIndex) == 4' evaluated to false.");
static_assert(sizeof(IndirectArgumentDescriptor::mIndex) == 4, "API_Verifier: 'sizeof(IndirectArgumentDescriptor::mIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectArgumentDescriptor::mIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectArgumentDescriptor::mIndex)>' evaluated to false.");

static_assert(alignof( decltype(IndirectArgumentDescriptor::mByteSize)) == 4, "API_Verifier: 'alignof( decltype(IndirectArgumentDescriptor::mByteSize)) == 4' evaluated to false.");
static_assert(offsetof( IndirectArgumentDescriptor, mByteSize) == 8, "API_Verifier: 'offsetof( IndirectArgumentDescriptor, mByteSize) == 8' evaluated to false.");
static_assert(sizeof(IndirectArgumentDescriptor::mByteSize) == 4, "API_Verifier: 'sizeof(IndirectArgumentDescriptor::mByteSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(IndirectArgumentDescriptor::mByteSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(IndirectArgumentDescriptor::mByteSize)>' evaluated to false.");

static_assert(alignof(CommandSignatureDesc) == 8, "API_Verifier: 'alignof(CommandSignatureDesc) == 8' evaluated to false.");
static_assert(sizeof(CommandSignatureDesc) == 24, "API_Verifier: 'sizeof(CommandSignatureDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(CommandSignatureDesc::pRootSignature)) == 8, "API_Verifier: 'alignof( decltype(CommandSignatureDesc::pRootSignature)) == 8' evaluated to false.");
static_assert(offsetof( CommandSignatureDesc, pRootSignature) == 0, "API_Verifier: 'offsetof( CommandSignatureDesc, pRootSignature) == 0' evaluated to false.");
static_assert(sizeof(CommandSignatureDesc::pRootSignature) == 8, "API_Verifier: 'sizeof(CommandSignatureDesc::pRootSignature) == 8' evaluated to false.");
static_assert(std::is_same_v<RootSignature*, decltype(CommandSignatureDesc::pRootSignature)>, "API_Verifier: 'std::is_same_v<RootSignature*, decltype(CommandSignatureDesc::pRootSignature)>' evaluated to false.");

static_assert(alignof( decltype(CommandSignatureDesc::pArgDescs)) == 8, "API_Verifier: 'alignof( decltype(CommandSignatureDesc::pArgDescs)) == 8' evaluated to false.");
static_assert(offsetof( CommandSignatureDesc, pArgDescs) == 8, "API_Verifier: 'offsetof( CommandSignatureDesc, pArgDescs) == 8' evaluated to false.");
static_assert(sizeof(CommandSignatureDesc::pArgDescs) == 8, "API_Verifier: 'sizeof(CommandSignatureDesc::pArgDescs) == 8' evaluated to false.");
static_assert(std::is_same_v<IndirectArgumentDescriptor*, decltype(CommandSignatureDesc::pArgDescs)>, "API_Verifier: 'std::is_same_v<IndirectArgumentDescriptor*, decltype(CommandSignatureDesc::pArgDescs)>' evaluated to false.");

static_assert(alignof( decltype(CommandSignatureDesc::mIndirectArgCount)) == 4, "API_Verifier: 'alignof( decltype(CommandSignatureDesc::mIndirectArgCount)) == 4' evaluated to false.");
static_assert(offsetof( CommandSignatureDesc, mIndirectArgCount) == 16, "API_Verifier: 'offsetof( CommandSignatureDesc, mIndirectArgCount) == 16' evaluated to false.");
static_assert(sizeof(CommandSignatureDesc::mIndirectArgCount) == 4, "API_Verifier: 'sizeof(CommandSignatureDesc::mIndirectArgCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(CommandSignatureDesc::mIndirectArgCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(CommandSignatureDesc::mIndirectArgCount)>' evaluated to false.");

static_assert(alignof( decltype(CommandSignatureDesc::mPacked)) == 1, "API_Verifier: 'alignof( decltype(CommandSignatureDesc::mPacked)) == 1' evaluated to false.");
static_assert(offsetof( CommandSignatureDesc, mPacked) == 20, "API_Verifier: 'offsetof( CommandSignatureDesc, mPacked) == 20' evaluated to false.");
static_assert(sizeof(CommandSignatureDesc::mPacked) == 1, "API_Verifier: 'sizeof(CommandSignatureDesc::mPacked) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CommandSignatureDesc::mPacked)>, "API_Verifier: 'std::is_same_v<bool, decltype(CommandSignatureDesc::mPacked)>' evaluated to false.");

static_assert(alignof(CommandSignature) == 8, "API_Verifier: 'alignof(CommandSignature) == 8' evaluated to false.");
static_assert(sizeof(CommandSignature) == 16, "API_Verifier: 'sizeof(CommandSignature) == 16' evaluated to false.");

static_assert(alignof( decltype(CommandSignature::pHandle)) == 8, "API_Verifier: 'alignof( decltype(CommandSignature::pHandle)) == 8' evaluated to false.");
static_assert(offsetof( CommandSignature, pHandle) == 0, "API_Verifier: 'offsetof( CommandSignature, pHandle) == 0' evaluated to false.");
static_assert(sizeof(CommandSignature::pHandle) == 8, "API_Verifier: 'sizeof(CommandSignature::pHandle) == 8' evaluated to false.");
static_assert(std::is_same_v<ID3D12CommandSignature*, decltype(CommandSignature::pHandle)>, "API_Verifier: 'std::is_same_v<ID3D12CommandSignature*, decltype(CommandSignature::pHandle)>' evaluated to false.");

static_assert(alignof( decltype(CommandSignature::mDrawType)) == 4, "API_Verifier: 'alignof( decltype(CommandSignature::mDrawType)) == 4' evaluated to false.");
static_assert(offsetof( CommandSignature, mDrawType) == 8, "API_Verifier: 'offsetof( CommandSignature, mDrawType) == 8' evaluated to false.");
static_assert(sizeof(CommandSignature::mDrawType) == 4, "API_Verifier: 'sizeof(CommandSignature::mDrawType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndirectArgumentType, decltype(CommandSignature::mDrawType)>, "API_Verifier: 'std::is_same_v<IndirectArgumentType, decltype(CommandSignature::mDrawType)>' evaluated to false.");

static_assert(alignof( decltype(CommandSignature::mStride)) == 4, "API_Verifier: 'alignof( decltype(CommandSignature::mStride)) == 4' evaluated to false.");
static_assert(offsetof( CommandSignature, mStride) == 12, "API_Verifier: 'offsetof( CommandSignature, mStride) == 12' evaluated to false.");
static_assert(sizeof(CommandSignature::mStride) == 4, "API_Verifier: 'sizeof(CommandSignature::mStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(CommandSignature::mStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(CommandSignature::mStride)>' evaluated to false.");

static_assert(alignof(DescriptorSetDesc) == 8, "API_Verifier: 'alignof(DescriptorSetDesc) == 8' evaluated to false.");
static_assert(sizeof(DescriptorSetDesc) == 24, "API_Verifier: 'sizeof(DescriptorSetDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(DescriptorSetDesc::pRootSignature)) == 8, "API_Verifier: 'alignof( decltype(DescriptorSetDesc::pRootSignature)) == 8' evaluated to false.");
static_assert(offsetof( DescriptorSetDesc, pRootSignature) == 0, "API_Verifier: 'offsetof( DescriptorSetDesc, pRootSignature) == 0' evaluated to false.");
static_assert(sizeof(DescriptorSetDesc::pRootSignature) == 8, "API_Verifier: 'sizeof(DescriptorSetDesc::pRootSignature) == 8' evaluated to false.");
static_assert(std::is_same_v<RootSignature*, decltype(DescriptorSetDesc::pRootSignature)>, "API_Verifier: 'std::is_same_v<RootSignature*, decltype(DescriptorSetDesc::pRootSignature)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorSetDesc::mUpdateFrequency)) == 4, "API_Verifier: 'alignof( decltype(DescriptorSetDesc::mUpdateFrequency)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorSetDesc, mUpdateFrequency) == 8, "API_Verifier: 'offsetof( DescriptorSetDesc, mUpdateFrequency) == 8' evaluated to false.");
static_assert(sizeof(DescriptorSetDesc::mUpdateFrequency) == 4, "API_Verifier: 'sizeof(DescriptorSetDesc::mUpdateFrequency) == 4' evaluated to false.");
static_assert(std::is_same_v<DescriptorUpdateFrequency, decltype(DescriptorSetDesc::mUpdateFrequency)>, "API_Verifier: 'std::is_same_v<DescriptorUpdateFrequency, decltype(DescriptorSetDesc::mUpdateFrequency)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorSetDesc::mMaxSets)) == 4, "API_Verifier: 'alignof( decltype(DescriptorSetDesc::mMaxSets)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorSetDesc, mMaxSets) == 12, "API_Verifier: 'offsetof( DescriptorSetDesc, mMaxSets) == 12' evaluated to false.");
static_assert(sizeof(DescriptorSetDesc::mMaxSets) == 4, "API_Verifier: 'sizeof(DescriptorSetDesc::mMaxSets) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorSetDesc::mMaxSets)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorSetDesc::mMaxSets)>' evaluated to false.");

static_assert(alignof( decltype(DescriptorSetDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(DescriptorSetDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( DescriptorSetDesc, mNodeIndex) == 16, "API_Verifier: 'offsetof( DescriptorSetDesc, mNodeIndex) == 16' evaluated to false.");
static_assert(sizeof(DescriptorSetDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(DescriptorSetDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DescriptorSetDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DescriptorSetDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof(QueueSubmitDesc) == 8, "API_Verifier: 'alignof(QueueSubmitDesc) == 8' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc) == 48, "API_Verifier: 'sizeof(QueueSubmitDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::ppCmds)) == 8, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::ppCmds)) == 8' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, ppCmds) == 0, "API_Verifier: 'offsetof( QueueSubmitDesc, ppCmds) == 0' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::ppCmds) == 8, "API_Verifier: 'sizeof(QueueSubmitDesc::ppCmds) == 8' evaluated to false.");
static_assert(std::is_same_v<Cmd **, decltype(QueueSubmitDesc::ppCmds)>, "API_Verifier: 'std::is_same_v<Cmd **, decltype(QueueSubmitDesc::ppCmds)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::pSignalFence)) == 8, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::pSignalFence)) == 8' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, pSignalFence) == 8, "API_Verifier: 'offsetof( QueueSubmitDesc, pSignalFence) == 8' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::pSignalFence) == 8, "API_Verifier: 'sizeof(QueueSubmitDesc::pSignalFence) == 8' evaluated to false.");
static_assert(std::is_same_v<Fence*, decltype(QueueSubmitDesc::pSignalFence)>, "API_Verifier: 'std::is_same_v<Fence*, decltype(QueueSubmitDesc::pSignalFence)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::ppWaitSemaphores)) == 8, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::ppWaitSemaphores)) == 8' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, ppWaitSemaphores) == 16, "API_Verifier: 'offsetof( QueueSubmitDesc, ppWaitSemaphores) == 16' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::ppWaitSemaphores) == 8, "API_Verifier: 'sizeof(QueueSubmitDesc::ppWaitSemaphores) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore **, decltype(QueueSubmitDesc::ppWaitSemaphores)>, "API_Verifier: 'std::is_same_v<Semaphore **, decltype(QueueSubmitDesc::ppWaitSemaphores)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::ppSignalSemaphores)) == 8, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::ppSignalSemaphores)) == 8' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, ppSignalSemaphores) == 24, "API_Verifier: 'offsetof( QueueSubmitDesc, ppSignalSemaphores) == 24' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::ppSignalSemaphores) == 8, "API_Verifier: 'sizeof(QueueSubmitDesc::ppSignalSemaphores) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore **, decltype(QueueSubmitDesc::ppSignalSemaphores)>, "API_Verifier: 'std::is_same_v<Semaphore **, decltype(QueueSubmitDesc::ppSignalSemaphores)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::mCmdCount)) == 4, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::mCmdCount)) == 4' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, mCmdCount) == 32, "API_Verifier: 'offsetof( QueueSubmitDesc, mCmdCount) == 32' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::mCmdCount) == 4, "API_Verifier: 'sizeof(QueueSubmitDesc::mCmdCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mCmdCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mCmdCount)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::mWaitSemaphoreCount)) == 4, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::mWaitSemaphoreCount)) == 4' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, mWaitSemaphoreCount) == 36, "API_Verifier: 'offsetof( QueueSubmitDesc, mWaitSemaphoreCount) == 36' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::mWaitSemaphoreCount) == 4, "API_Verifier: 'sizeof(QueueSubmitDesc::mWaitSemaphoreCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mWaitSemaphoreCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mWaitSemaphoreCount)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::mSignalSemaphoreCount)) == 4, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::mSignalSemaphoreCount)) == 4' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, mSignalSemaphoreCount) == 40, "API_Verifier: 'offsetof( QueueSubmitDesc, mSignalSemaphoreCount) == 40' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::mSignalSemaphoreCount) == 4, "API_Verifier: 'sizeof(QueueSubmitDesc::mSignalSemaphoreCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mSignalSemaphoreCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueueSubmitDesc::mSignalSemaphoreCount)>' evaluated to false.");

static_assert(alignof( decltype(QueueSubmitDesc::mSubmitDone)) == 1, "API_Verifier: 'alignof( decltype(QueueSubmitDesc::mSubmitDone)) == 1' evaluated to false.");
static_assert(offsetof( QueueSubmitDesc, mSubmitDone) == 44, "API_Verifier: 'offsetof( QueueSubmitDesc, mSubmitDone) == 44' evaluated to false.");
static_assert(sizeof(QueueSubmitDesc::mSubmitDone) == 1, "API_Verifier: 'sizeof(QueueSubmitDesc::mSubmitDone) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(QueueSubmitDesc::mSubmitDone)>, "API_Verifier: 'std::is_same_v<bool, decltype(QueueSubmitDesc::mSubmitDone)>' evaluated to false.");

static_assert(alignof(QueuePresentDesc) == 8, "API_Verifier: 'alignof(QueuePresentDesc) == 8' evaluated to false.");
static_assert(sizeof(QueuePresentDesc) == 24, "API_Verifier: 'sizeof(QueuePresentDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(QueuePresentDesc::pSwapChain)) == 8, "API_Verifier: 'alignof( decltype(QueuePresentDesc::pSwapChain)) == 8' evaluated to false.");
static_assert(offsetof( QueuePresentDesc, pSwapChain) == 0, "API_Verifier: 'offsetof( QueuePresentDesc, pSwapChain) == 0' evaluated to false.");
static_assert(sizeof(QueuePresentDesc::pSwapChain) == 8, "API_Verifier: 'sizeof(QueuePresentDesc::pSwapChain) == 8' evaluated to false.");
static_assert(std::is_same_v<SwapChain*, decltype(QueuePresentDesc::pSwapChain)>, "API_Verifier: 'std::is_same_v<SwapChain*, decltype(QueuePresentDesc::pSwapChain)>' evaluated to false.");

static_assert(alignof( decltype(QueuePresentDesc::ppWaitSemaphores)) == 8, "API_Verifier: 'alignof( decltype(QueuePresentDesc::ppWaitSemaphores)) == 8' evaluated to false.");
static_assert(offsetof( QueuePresentDesc, ppWaitSemaphores) == 8, "API_Verifier: 'offsetof( QueuePresentDesc, ppWaitSemaphores) == 8' evaluated to false.");
static_assert(sizeof(QueuePresentDesc::ppWaitSemaphores) == 8, "API_Verifier: 'sizeof(QueuePresentDesc::ppWaitSemaphores) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore **, decltype(QueuePresentDesc::ppWaitSemaphores)>, "API_Verifier: 'std::is_same_v<Semaphore **, decltype(QueuePresentDesc::ppWaitSemaphores)>' evaluated to false.");

static_assert(alignof( decltype(QueuePresentDesc::mWaitSemaphoreCount)) == 4, "API_Verifier: 'alignof( decltype(QueuePresentDesc::mWaitSemaphoreCount)) == 4' evaluated to false.");
static_assert(offsetof( QueuePresentDesc, mWaitSemaphoreCount) == 16, "API_Verifier: 'offsetof( QueuePresentDesc, mWaitSemaphoreCount) == 16' evaluated to false.");
static_assert(sizeof(QueuePresentDesc::mWaitSemaphoreCount) == 4, "API_Verifier: 'sizeof(QueuePresentDesc::mWaitSemaphoreCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(QueuePresentDesc::mWaitSemaphoreCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(QueuePresentDesc::mWaitSemaphoreCount)>' evaluated to false.");

static_assert(alignof( decltype(QueuePresentDesc::mIndex)) == 1, "API_Verifier: 'alignof( decltype(QueuePresentDesc::mIndex)) == 1' evaluated to false.");
static_assert(offsetof( QueuePresentDesc, mIndex) == 20, "API_Verifier: 'offsetof( QueuePresentDesc, mIndex) == 20' evaluated to false.");
static_assert(sizeof(QueuePresentDesc::mIndex) == 1, "API_Verifier: 'sizeof(QueuePresentDesc::mIndex) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(QueuePresentDesc::mIndex)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(QueuePresentDesc::mIndex)>' evaluated to false.");

static_assert(alignof( decltype(QueuePresentDesc::mSubmitDone)) == 1, "API_Verifier: 'alignof( decltype(QueuePresentDesc::mSubmitDone)) == 1' evaluated to false.");
static_assert(offsetof( QueuePresentDesc, mSubmitDone) == 21, "API_Verifier: 'offsetof( QueuePresentDesc, mSubmitDone) == 21' evaluated to false.");
static_assert(sizeof(QueuePresentDesc::mSubmitDone) == 1, "API_Verifier: 'sizeof(QueuePresentDesc::mSubmitDone) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(QueuePresentDesc::mSubmitDone)>, "API_Verifier: 'std::is_same_v<bool, decltype(QueuePresentDesc::mSubmitDone)>' evaluated to false.");

static_assert(alignof(BindRenderTargetDesc) == 8, "API_Verifier: 'alignof(BindRenderTargetDesc) == 8' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc) == 48, "API_Verifier: 'sizeof(BindRenderTargetDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::pRenderTarget)) == 8, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::pRenderTarget)) == 8' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, pRenderTarget) == 0, "API_Verifier: 'offsetof( BindRenderTargetDesc, pRenderTarget) == 0' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::pRenderTarget) == 8, "API_Verifier: 'sizeof(BindRenderTargetDesc::pRenderTarget) == 8' evaluated to false.");
static_assert(std::is_same_v<RenderTarget*, decltype(BindRenderTargetDesc::pRenderTarget)>, "API_Verifier: 'std::is_same_v<RenderTarget*, decltype(BindRenderTargetDesc::pRenderTarget)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mLoadAction)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mLoadAction)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mLoadAction) == 8, "API_Verifier: 'offsetof( BindRenderTargetDesc, mLoadAction) == 8' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mLoadAction) == 4, "API_Verifier: 'sizeof(BindRenderTargetDesc::mLoadAction) == 4' evaluated to false.");
static_assert(std::is_same_v<LoadActionType, decltype(BindRenderTargetDesc::mLoadAction)>, "API_Verifier: 'std::is_same_v<LoadActionType, decltype(BindRenderTargetDesc::mLoadAction)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mStoreAction)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mStoreAction)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mStoreAction) == 12, "API_Verifier: 'offsetof( BindRenderTargetDesc, mStoreAction) == 12' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mStoreAction) == 4, "API_Verifier: 'sizeof(BindRenderTargetDesc::mStoreAction) == 4' evaluated to false.");
static_assert(std::is_same_v<StoreActionType, decltype(BindRenderTargetDesc::mStoreAction)>, "API_Verifier: 'std::is_same_v<StoreActionType, decltype(BindRenderTargetDesc::mStoreAction)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mClearValue)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mClearValue)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mClearValue) == 16, "API_Verifier: 'offsetof( BindRenderTargetDesc, mClearValue) == 16' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mClearValue) == 16, "API_Verifier: 'sizeof(BindRenderTargetDesc::mClearValue) == 16' evaluated to false.");
static_assert(std::is_same_v<ClearValue, decltype(BindRenderTargetDesc::mClearValue)>, "API_Verifier: 'std::is_same_v<ClearValue, decltype(BindRenderTargetDesc::mClearValue)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mLoadActionStencil)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mLoadActionStencil)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mLoadActionStencil) == 32, "API_Verifier: 'offsetof( BindRenderTargetDesc, mLoadActionStencil) == 32' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mLoadActionStencil) == 4, "API_Verifier: 'sizeof(BindRenderTargetDesc::mLoadActionStencil) == 4' evaluated to false.");
static_assert(std::is_same_v<LoadActionType, decltype(BindRenderTargetDesc::mLoadActionStencil)>, "API_Verifier: 'std::is_same_v<LoadActionType, decltype(BindRenderTargetDesc::mLoadActionStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mStoreActionStencil)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mStoreActionStencil)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mStoreActionStencil) == 36, "API_Verifier: 'offsetof( BindRenderTargetDesc, mStoreActionStencil) == 36' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mStoreActionStencil) == 4, "API_Verifier: 'sizeof(BindRenderTargetDesc::mStoreActionStencil) == 4' evaluated to false.");
static_assert(std::is_same_v<StoreActionType, decltype(BindRenderTargetDesc::mStoreActionStencil)>, "API_Verifier: 'std::is_same_v<StoreActionType, decltype(BindRenderTargetDesc::mStoreActionStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mArraySlice)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mArraySlice)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetDesc, mArraySlice) == 40, "API_Verifier: 'offsetof( BindRenderTargetDesc, mArraySlice) == 40' evaluated to false.");
static_assert(sizeof(BindRenderTargetDesc::mArraySlice) == 4, "API_Verifier: 'sizeof(BindRenderTargetDesc::mArraySlice) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mArraySlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mArraySlice)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mMipSlice)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mMipSlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mMipSlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mMipSlice)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mOverrideClearValue)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mOverrideClearValue)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mOverrideClearValue)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mOverrideClearValue)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mUseArraySlice)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mUseArraySlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mUseArraySlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mUseArraySlice)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetDesc::mUseMipSlice)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetDesc::mUseMipSlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mUseMipSlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetDesc::mUseMipSlice)>' evaluated to false.");

static_assert(alignof(BindDepthTargetDesc) == 8, "API_Verifier: 'alignof(BindDepthTargetDesc) == 8' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc) == 48, "API_Verifier: 'sizeof(BindDepthTargetDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::pDepthStencil)) == 8, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::pDepthStencil)) == 8' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, pDepthStencil) == 0, "API_Verifier: 'offsetof( BindDepthTargetDesc, pDepthStencil) == 0' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::pDepthStencil) == 8, "API_Verifier: 'sizeof(BindDepthTargetDesc::pDepthStencil) == 8' evaluated to false.");
static_assert(std::is_same_v<RenderTarget*, decltype(BindDepthTargetDesc::pDepthStencil)>, "API_Verifier: 'std::is_same_v<RenderTarget*, decltype(BindDepthTargetDesc::pDepthStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mLoadAction)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mLoadAction)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mLoadAction) == 8, "API_Verifier: 'offsetof( BindDepthTargetDesc, mLoadAction) == 8' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mLoadAction) == 4, "API_Verifier: 'sizeof(BindDepthTargetDesc::mLoadAction) == 4' evaluated to false.");
static_assert(std::is_same_v<LoadActionType, decltype(BindDepthTargetDesc::mLoadAction)>, "API_Verifier: 'std::is_same_v<LoadActionType, decltype(BindDepthTargetDesc::mLoadAction)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mLoadActionStencil)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mLoadActionStencil)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mLoadActionStencil) == 12, "API_Verifier: 'offsetof( BindDepthTargetDesc, mLoadActionStencil) == 12' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mLoadActionStencil) == 4, "API_Verifier: 'sizeof(BindDepthTargetDesc::mLoadActionStencil) == 4' evaluated to false.");
static_assert(std::is_same_v<LoadActionType, decltype(BindDepthTargetDesc::mLoadActionStencil)>, "API_Verifier: 'std::is_same_v<LoadActionType, decltype(BindDepthTargetDesc::mLoadActionStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mStoreAction)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mStoreAction)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mStoreAction) == 16, "API_Verifier: 'offsetof( BindDepthTargetDesc, mStoreAction) == 16' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mStoreAction) == 4, "API_Verifier: 'sizeof(BindDepthTargetDesc::mStoreAction) == 4' evaluated to false.");
static_assert(std::is_same_v<StoreActionType, decltype(BindDepthTargetDesc::mStoreAction)>, "API_Verifier: 'std::is_same_v<StoreActionType, decltype(BindDepthTargetDesc::mStoreAction)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mStoreActionStencil)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mStoreActionStencil)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mStoreActionStencil) == 20, "API_Verifier: 'offsetof( BindDepthTargetDesc, mStoreActionStencil) == 20' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mStoreActionStencil) == 4, "API_Verifier: 'sizeof(BindDepthTargetDesc::mStoreActionStencil) == 4' evaluated to false.");
static_assert(std::is_same_v<StoreActionType, decltype(BindDepthTargetDesc::mStoreActionStencil)>, "API_Verifier: 'std::is_same_v<StoreActionType, decltype(BindDepthTargetDesc::mStoreActionStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mClearValue)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mClearValue)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mClearValue) == 24, "API_Verifier: 'offsetof( BindDepthTargetDesc, mClearValue) == 24' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mClearValue) == 16, "API_Verifier: 'sizeof(BindDepthTargetDesc::mClearValue) == 16' evaluated to false.");
static_assert(std::is_same_v<ClearValue, decltype(BindDepthTargetDesc::mClearValue)>, "API_Verifier: 'std::is_same_v<ClearValue, decltype(BindDepthTargetDesc::mClearValue)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mArraySlice)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mArraySlice)) == 4' evaluated to false.");
static_assert(offsetof( BindDepthTargetDesc, mArraySlice) == 40, "API_Verifier: 'offsetof( BindDepthTargetDesc, mArraySlice) == 40' evaluated to false.");
static_assert(sizeof(BindDepthTargetDesc::mArraySlice) == 4, "API_Verifier: 'sizeof(BindDepthTargetDesc::mArraySlice) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mArraySlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mArraySlice)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mMipSlice)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mMipSlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mMipSlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mMipSlice)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mOverrideClearValue)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mOverrideClearValue)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mOverrideClearValue)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mOverrideClearValue)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mUseArraySlice)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mUseArraySlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mUseArraySlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mUseArraySlice)>' evaluated to false.");

static_assert(alignof( decltype(BindDepthTargetDesc::mUseMipSlice)) == 4, "API_Verifier: 'alignof( decltype(BindDepthTargetDesc::mUseMipSlice)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mUseMipSlice)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindDepthTargetDesc::mUseMipSlice)>' evaluated to false.");

static_assert(alignof(BindRenderTargetsDesc) == 8, "API_Verifier: 'alignof(BindRenderTargetsDesc) == 8' evaluated to false.");
static_assert(sizeof(BindRenderTargetsDesc) == 448, "API_Verifier: 'sizeof(BindRenderTargetsDesc) == 448' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetsDesc::mRenderTargetCount)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetsDesc::mRenderTargetCount)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetsDesc, mRenderTargetCount) == 0, "API_Verifier: 'offsetof( BindRenderTargetsDesc, mRenderTargetCount) == 0' evaluated to false.");
static_assert(sizeof(BindRenderTargetsDesc::mRenderTargetCount) == 4, "API_Verifier: 'sizeof(BindRenderTargetsDesc::mRenderTargetCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BindRenderTargetsDesc::mRenderTargetCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BindRenderTargetsDesc::mRenderTargetCount)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetsDesc::mRenderTargets)) == 8, "API_Verifier: 'alignof( decltype(BindRenderTargetsDesc::mRenderTargets)) == 8' evaluated to false.");
static_assert(offsetof( BindRenderTargetsDesc, mRenderTargets) == 8, "API_Verifier: 'offsetof( BindRenderTargetsDesc, mRenderTargets) == 8' evaluated to false.");
static_assert(sizeof(BindRenderTargetsDesc::mRenderTargets) == 384, "API_Verifier: 'sizeof(BindRenderTargetsDesc::mRenderTargets) == 384' evaluated to false.");
static_assert(std::is_same_v<BindRenderTargetDesc[8], decltype(BindRenderTargetsDesc::mRenderTargets)>, "API_Verifier: 'std::is_same_v<BindRenderTargetDesc[8], decltype(BindRenderTargetsDesc::mRenderTargets)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetsDesc::mDepthStencil)) == 8, "API_Verifier: 'alignof( decltype(BindRenderTargetsDesc::mDepthStencil)) == 8' evaluated to false.");
static_assert(offsetof( BindRenderTargetsDesc, mDepthStencil) == 392, "API_Verifier: 'offsetof( BindRenderTargetsDesc, mDepthStencil) == 392' evaluated to false.");
static_assert(sizeof(BindRenderTargetsDesc::mDepthStencil) == 48, "API_Verifier: 'sizeof(BindRenderTargetsDesc::mDepthStencil) == 48' evaluated to false.");
static_assert(std::is_same_v<BindDepthTargetDesc, decltype(BindRenderTargetsDesc::mDepthStencil)>, "API_Verifier: 'std::is_same_v<BindDepthTargetDesc, decltype(BindRenderTargetsDesc::mDepthStencil)>' evaluated to false.");

static_assert(alignof( decltype(BindRenderTargetsDesc::mExtent)) == 4, "API_Verifier: 'alignof( decltype(BindRenderTargetsDesc::mExtent)) == 4' evaluated to false.");
static_assert(offsetof( BindRenderTargetsDesc, mExtent) == 440, "API_Verifier: 'offsetof( BindRenderTargetsDesc, mExtent) == 440' evaluated to false.");
static_assert(sizeof(BindRenderTargetsDesc::mExtent) == 8, "API_Verifier: 'sizeof(BindRenderTargetsDesc::mExtent) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t[2], decltype(BindRenderTargetsDesc::mExtent)>, "API_Verifier: 'std::is_same_v<uint32_t[2], decltype(BindRenderTargetsDesc::mExtent)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Graphics\Interfaces\IRay.h"

static_assert(std::is_same_v<std::underlying_type_t<AccelerationStructureType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<AccelerationStructureType>,int>' evaluated to false.");
static_assert(AccelerationStructureType::ACCELERATION_STRUCTURE_TYPE_BOTTOM == 0, "API_Verifier: 'AccelerationStructureType::ACCELERATION_STRUCTURE_TYPE_BOTTOM == 0' evaluated to false.");
static_assert(AccelerationStructureType::ACCELERATION_STRUCTURE_TYPE_TOP == 1, "API_Verifier: 'AccelerationStructureType::ACCELERATION_STRUCTURE_TYPE_TOP == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<AccelerationStructureBuildFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<AccelerationStructureBuildFlags>,int>' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_NONE == 0, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_NONE == 0' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE == 1, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_UPDATE == 1' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION == 2, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_ALLOW_COMPACTION == 2' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE == 4, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE == 4' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD == 8, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_BUILD == 8' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY == 16, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_MINIMIZE_MEMORY == 16' evaluated to false.");
static_assert(AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE == 32, "API_Verifier: 'AccelerationStructureBuildFlags::ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE == 32' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<AccelerationStructureGeometryFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<AccelerationStructureGeometryFlags>,int>' evaluated to false.");
static_assert(AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_NONE == 0, "API_Verifier: 'AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_NONE == 0' evaluated to false.");
static_assert(AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_OPAQUE == 1, "API_Verifier: 'AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_OPAQUE == 1' evaluated to false.");
static_assert(AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION == 2, "API_Verifier: 'AccelerationStructureGeometryFlags::ACCELERATION_STRUCTURE_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<AccelerationStructureInstanceFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<AccelerationStructureInstanceFlags>,int>' evaluated to false.");
static_assert(AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_NONE == 0, "API_Verifier: 'AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_NONE == 0' evaluated to false.");
static_assert(AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE == 1, "API_Verifier: 'AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE == 1' evaluated to false.");
static_assert(AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE == 2, "API_Verifier: 'AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE == 2' evaluated to false.");
static_assert(AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_OPAQUE == 4, "API_Verifier: 'AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_OPAQUE == 4' evaluated to false.");
static_assert(AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_NON_OPAQUE == 8, "API_Verifier: 'AccelerationStructureInstanceFlags::ACCELERATION_STRUCTURE_INSTANCE_FLAG_FORCE_NON_OPAQUE == 8' evaluated to false.");

static_assert(alignof(AccelerationStructureInstanceDesc) == 8, "API_Verifier: 'alignof(AccelerationStructureInstanceDesc) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc) == 72, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc) == 72' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::pBottomAS)) == 8, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::pBottomAS)) == 8' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, pBottomAS) == 0, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, pBottomAS) == 0' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::pBottomAS) == 8, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::pBottomAS) == 8' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructure*, decltype(AccelerationStructureInstanceDesc::pBottomAS)>, "API_Verifier: 'std::is_same_v<AccelerationStructure*, decltype(AccelerationStructureInstanceDesc::pBottomAS)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::mTransform)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::mTransform)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, mTransform) == 8, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, mTransform) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::mTransform) == 48, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::mTransform) == 48' evaluated to false.");
static_assert(std::is_same_v<float[12], decltype(AccelerationStructureInstanceDesc::mTransform)>, "API_Verifier: 'std::is_same_v<float[12], decltype(AccelerationStructureInstanceDesc::mTransform)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::mInstanceID)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::mInstanceID)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, mInstanceID) == 56, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, mInstanceID) == 56' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::mInstanceID) == 4, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::mInstanceID) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceID)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceID)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::mInstanceMask)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::mInstanceMask)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, mInstanceMask) == 60, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, mInstanceMask) == 60' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::mInstanceMask) == 4, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::mInstanceMask) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceMask)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceMask)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, mInstanceContributionToHitGroupIndex) == 64, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, mInstanceContributionToHitGroupIndex) == 64' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex) == 4, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureInstanceDesc::mInstanceContributionToHitGroupIndex)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureInstanceDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureInstanceDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureInstanceDesc, mFlags) == 68, "API_Verifier: 'offsetof( AccelerationStructureInstanceDesc, mFlags) == 68' evaluated to false.");
static_assert(sizeof(AccelerationStructureInstanceDesc::mFlags) == 4, "API_Verifier: 'sizeof(AccelerationStructureInstanceDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureInstanceFlags, decltype(AccelerationStructureInstanceDesc::mFlags)>, "API_Verifier: 'std::is_same_v<AccelerationStructureInstanceFlags, decltype(AccelerationStructureInstanceDesc::mFlags)>' evaluated to false.");

static_assert(alignof(AccelerationStructureGeometryDesc) == 8, "API_Verifier: 'alignof(AccelerationStructureGeometryDesc) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc) == 48, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::pVertexBuffer)) == 8, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::pVertexBuffer)) == 8' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, pVertexBuffer) == 0, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, pVertexBuffer) == 0' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::pVertexBuffer) == 8, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::pVertexBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(AccelerationStructureGeometryDesc::pVertexBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(AccelerationStructureGeometryDesc::pVertexBuffer)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::pIndexBuffer)) == 8, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::pIndexBuffer)) == 8' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, pIndexBuffer) == 8, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, pIndexBuffer) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::pIndexBuffer) == 8, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::pIndexBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(AccelerationStructureGeometryDesc::pIndexBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(AccelerationStructureGeometryDesc::pIndexBuffer)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mVertexOffset)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mVertexOffset)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mVertexOffset) == 16, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mVertexOffset) == 16' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mVertexOffset) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mVertexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexOffset)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mVertexCount) == 20, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mVertexCount) == 20' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mVertexCount) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mVertexStride)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mVertexStride)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mVertexStride) == 24, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mVertexStride) == 24' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mVertexStride) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mVertexStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mVertexStride)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mVertexFormat)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mVertexFormat)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mVertexFormat) == 28, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mVertexFormat) == 28' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mVertexFormat) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mVertexFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<TinyImageFormat, decltype(AccelerationStructureGeometryDesc::mVertexFormat)>, "API_Verifier: 'std::is_same_v<TinyImageFormat, decltype(AccelerationStructureGeometryDesc::mVertexFormat)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mIndexOffset)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mIndexOffset)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mIndexOffset) == 32, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mIndexOffset) == 32' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mIndexOffset) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mIndexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mIndexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mIndexOffset)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mIndexCount) == 36, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mIndexCount) == 36' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mIndexCount) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureGeometryDesc::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mIndexType)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mIndexType)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mIndexType) == 40, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mIndexType) == 40' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mIndexType) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mIndexType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndexType, decltype(AccelerationStructureGeometryDesc::mIndexType)>, "API_Verifier: 'std::is_same_v<IndexType, decltype(AccelerationStructureGeometryDesc::mIndexType)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureGeometryDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureGeometryDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureGeometryDesc, mFlags) == 44, "API_Verifier: 'offsetof( AccelerationStructureGeometryDesc, mFlags) == 44' evaluated to false.");
static_assert(sizeof(AccelerationStructureGeometryDesc::mFlags) == 4, "API_Verifier: 'sizeof(AccelerationStructureGeometryDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureGeometryFlags, decltype(AccelerationStructureGeometryDesc::mFlags)>, "API_Verifier: 'std::is_same_v<AccelerationStructureGeometryFlags, decltype(AccelerationStructureGeometryDesc::mFlags)>' evaluated to false.");

static_assert(alignof(AccelerationStructureDescBottom) == 8, "API_Verifier: 'alignof(AccelerationStructureDescBottom) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescBottom) == 16, "API_Verifier: 'sizeof(AccelerationStructureDescBottom) == 16' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDescBottom::mDescCount)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureDescBottom::mDescCount)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureDescBottom, mDescCount) == 0, "API_Verifier: 'offsetof( AccelerationStructureDescBottom, mDescCount) == 0' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescBottom::mDescCount) == 4, "API_Verifier: 'sizeof(AccelerationStructureDescBottom::mDescCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureDescBottom::mDescCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureDescBottom::mDescCount)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDescBottom::pGeometryDescs)) == 8, "API_Verifier: 'alignof( decltype(AccelerationStructureDescBottom::pGeometryDescs)) == 8' evaluated to false.");
static_assert(offsetof( AccelerationStructureDescBottom, pGeometryDescs) == 8, "API_Verifier: 'offsetof( AccelerationStructureDescBottom, pGeometryDescs) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescBottom::pGeometryDescs) == 8, "API_Verifier: 'sizeof(AccelerationStructureDescBottom::pGeometryDescs) == 8' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureGeometryDesc*, decltype(AccelerationStructureDescBottom::pGeometryDescs)>, "API_Verifier: 'std::is_same_v<AccelerationStructureGeometryDesc*, decltype(AccelerationStructureDescBottom::pGeometryDescs)>' evaluated to false.");

static_assert(alignof(AccelerationStructureDescTop) == 8, "API_Verifier: 'alignof(AccelerationStructureDescTop) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescTop) == 16, "API_Verifier: 'sizeof(AccelerationStructureDescTop) == 16' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDescTop::mDescCount)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureDescTop::mDescCount)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureDescTop, mDescCount) == 0, "API_Verifier: 'offsetof( AccelerationStructureDescTop, mDescCount) == 0' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescTop::mDescCount) == 4, "API_Verifier: 'sizeof(AccelerationStructureDescTop::mDescCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(AccelerationStructureDescTop::mDescCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(AccelerationStructureDescTop::mDescCount)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDescTop::pInstanceDescs)) == 8, "API_Verifier: 'alignof( decltype(AccelerationStructureDescTop::pInstanceDescs)) == 8' evaluated to false.");
static_assert(offsetof( AccelerationStructureDescTop, pInstanceDescs) == 8, "API_Verifier: 'offsetof( AccelerationStructureDescTop, pInstanceDescs) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureDescTop::pInstanceDescs) == 8, "API_Verifier: 'sizeof(AccelerationStructureDescTop::pInstanceDescs) == 8' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureInstanceDesc*, decltype(AccelerationStructureDescTop::pInstanceDescs)>, "API_Verifier: 'std::is_same_v<AccelerationStructureInstanceDesc*, decltype(AccelerationStructureDescTop::pInstanceDescs)>' evaluated to false.");

static_assert(alignof(AccelerationStructureDesc) == 8, "API_Verifier: 'alignof(AccelerationStructureDesc) == 8' evaluated to false.");
static_assert(sizeof(AccelerationStructureDesc) == 24, "API_Verifier: 'sizeof(AccelerationStructureDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureDesc, mType) == 0, "API_Verifier: 'offsetof( AccelerationStructureDesc, mType) == 0' evaluated to false.");
static_assert(sizeof(AccelerationStructureDesc::mType) == 4, "API_Verifier: 'sizeof(AccelerationStructureDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureType, decltype(AccelerationStructureDesc::mType)>, "API_Verifier: 'std::is_same_v<AccelerationStructureType, decltype(AccelerationStructureDesc::mType)>' evaluated to false.");

static_assert(alignof( decltype(AccelerationStructureDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(AccelerationStructureDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( AccelerationStructureDesc, mFlags) == 4, "API_Verifier: 'offsetof( AccelerationStructureDesc, mFlags) == 4' evaluated to false.");
static_assert(sizeof(AccelerationStructureDesc::mFlags) == 4, "API_Verifier: 'sizeof(AccelerationStructureDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructureBuildFlags, decltype(AccelerationStructureDesc::mFlags)>, "API_Verifier: 'std::is_same_v<AccelerationStructureBuildFlags, decltype(AccelerationStructureDesc::mFlags)>' evaluated to false.");

static_assert(alignof(RaytracingBuildASDesc) == 8, "API_Verifier: 'alignof(RaytracingBuildASDesc) == 8' evaluated to false.");
static_assert(sizeof(RaytracingBuildASDesc) == 16, "API_Verifier: 'sizeof(RaytracingBuildASDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(RaytracingBuildASDesc::pAccelerationStructure)) == 8, "API_Verifier: 'alignof( decltype(RaytracingBuildASDesc::pAccelerationStructure)) == 8' evaluated to false.");
static_assert(offsetof( RaytracingBuildASDesc, pAccelerationStructure) == 0, "API_Verifier: 'offsetof( RaytracingBuildASDesc, pAccelerationStructure) == 0' evaluated to false.");
static_assert(sizeof(RaytracingBuildASDesc::pAccelerationStructure) == 8, "API_Verifier: 'sizeof(RaytracingBuildASDesc::pAccelerationStructure) == 8' evaluated to false.");
static_assert(std::is_same_v<AccelerationStructure*, decltype(RaytracingBuildASDesc::pAccelerationStructure)>, "API_Verifier: 'std::is_same_v<AccelerationStructure*, decltype(RaytracingBuildASDesc::pAccelerationStructure)>' evaluated to false.");

static_assert(alignof( decltype(RaytracingBuildASDesc::mIssueRWBarrier)) == 1, "API_Verifier: 'alignof( decltype(RaytracingBuildASDesc::mIssueRWBarrier)) == 1' evaluated to false.");
static_assert(offsetof( RaytracingBuildASDesc, mIssueRWBarrier) == 8, "API_Verifier: 'offsetof( RaytracingBuildASDesc, mIssueRWBarrier) == 8' evaluated to false.");
static_assert(sizeof(RaytracingBuildASDesc::mIssueRWBarrier) == 1, "API_Verifier: 'sizeof(RaytracingBuildASDesc::mIssueRWBarrier) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(RaytracingBuildASDesc::mIssueRWBarrier)>, "API_Verifier: 'std::is_same_v<bool, decltype(RaytracingBuildASDesc::mIssueRWBarrier)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IApp.h"

static_assert(alignof(IApp) == 8, "API_Verifier: 'alignof(IApp) == 8' evaluated to false.");
static_assert(sizeof(IApp) == 80, "API_Verifier: 'sizeof(IApp) == 80' evaluated to false.");

static_assert(alignof( decltype(IApp::mSettings)) == 4, "API_Verifier: 'alignof( decltype(IApp::mSettings)) == 4' evaluated to false.");
static_assert(offsetof( IApp, mSettings) == 8, "API_Verifier: 'offsetof( IApp, mSettings) == 8' evaluated to false.");
static_assert(sizeof(IApp::mSettings) == 36, "API_Verifier: 'sizeof(IApp::mSettings) == 36' evaluated to false.");
static_assert(std::is_same_v<IApp::IApp::Settings, decltype(IApp::mSettings)>, "API_Verifier: 'std::is_same_v<IApp::IApp::Settings, decltype(IApp::mSettings)>' evaluated to false.");

static_assert(alignof( decltype(IApp::pWindow)) == 8, "API_Verifier: 'alignof( decltype(IApp::pWindow)) == 8' evaluated to false.");
static_assert(offsetof( IApp, pWindow) == 48, "API_Verifier: 'offsetof( IApp, pWindow) == 48' evaluated to false.");
static_assert(sizeof(IApp::pWindow) == 8, "API_Verifier: 'sizeof(IApp::pWindow) == 8' evaluated to false.");
static_assert(std::is_same_v<WindowDesc*, decltype(IApp::pWindow)>, "API_Verifier: 'std::is_same_v<WindowDesc*, decltype(IApp::pWindow)>' evaluated to false.");

static_assert(alignof( decltype(IApp::pCommandLine)) == 8, "API_Verifier: 'alignof( decltype(IApp::pCommandLine)) == 8' evaluated to false.");
static_assert(offsetof( IApp, pCommandLine) == 56, "API_Verifier: 'offsetof( IApp, pCommandLine) == 56' evaluated to false.");
static_assert(sizeof(IApp::pCommandLine) == 8, "API_Verifier: 'sizeof(IApp::pCommandLine) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(IApp::pCommandLine)>, "API_Verifier: 'std::is_same_v<const char *, decltype(IApp::pCommandLine)>' evaluated to false.");

static_assert(alignof( decltype(IApp::pUnsupportedReason)) == 8, "API_Verifier: 'alignof( decltype(IApp::pUnsupportedReason)) == 8' evaluated to false.");
static_assert(offsetof( IApp, pUnsupportedReason) == 64, "API_Verifier: 'offsetof( IApp, pUnsupportedReason) == 64' evaluated to false.");
static_assert(sizeof(IApp::pUnsupportedReason) == 8, "API_Verifier: 'sizeof(IApp::pUnsupportedReason) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(IApp::pUnsupportedReason)>, "API_Verifier: 'std::is_same_v<const char *, decltype(IApp::pUnsupportedReason)>' evaluated to false.");

static_assert(alignof( decltype(IApp::mUnsupported)) == 1, "API_Verifier: 'alignof( decltype(IApp::mUnsupported)) == 1' evaluated to false.");
static_assert(offsetof( IApp, mUnsupported) == 72, "API_Verifier: 'offsetof( IApp, mUnsupported) == 72' evaluated to false.");
static_assert(sizeof(IApp::mUnsupported) == 1, "API_Verifier: 'sizeof(IApp::mUnsupported) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::mUnsupported)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::mUnsupported)>' evaluated to false.");

static_assert(alignof(IApp::IApp::Settings) == 4, "API_Verifier: 'alignof(IApp::IApp::Settings) == 4' evaluated to false.");
static_assert(sizeof(IApp::IApp::Settings) == 36, "API_Verifier: 'sizeof(IApp::IApp::Settings) == 36' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWidth)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWidth) == 0, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWidth) == 0' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWidth) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWidth)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mHeight)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mHeight) == 4, "API_Verifier: 'offsetof( IApp::IApp::Settings, mHeight) == 4' evaluated to false.");
static_assert(sizeof(IApp::Settings::mHeight) == 4, "API_Verifier: 'sizeof(IApp::Settings::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mHeight)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mMonitorIndex)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mMonitorIndex)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mMonitorIndex) == 8, "API_Verifier: 'offsetof( IApp::IApp::Settings, mMonitorIndex) == 8' evaluated to false.");
static_assert(sizeof(IApp::Settings::mMonitorIndex) == 4, "API_Verifier: 'sizeof(IApp::Settings::mMonitorIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mMonitorIndex)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mMonitorIndex)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWindowX)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWindowX)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWindowX) == 12, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWindowX) == 12' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWindowX) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWindowX) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWindowX)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWindowX)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWindowY)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWindowY)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWindowY) == 16, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWindowY) == 16' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWindowY) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWindowY) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWindowY)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWindowY)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mFullScreen)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mFullScreen)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mFullScreen) == 20, "API_Verifier: 'offsetof( IApp::IApp::Settings, mFullScreen) == 20' evaluated to false.");
static_assert(sizeof(IApp::Settings::mFullScreen) == 1, "API_Verifier: 'sizeof(IApp::Settings::mFullScreen) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mFullScreen)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mFullScreen)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mExternalWindow)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mExternalWindow)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mExternalWindow) == 21, "API_Verifier: 'offsetof( IApp::IApp::Settings, mExternalWindow) == 21' evaluated to false.");
static_assert(sizeof(IApp::Settings::mExternalWindow) == 1, "API_Verifier: 'sizeof(IApp::Settings::mExternalWindow) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mExternalWindow)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mExternalWindow)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mDragToResize)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mDragToResize)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mDragToResize) == 22, "API_Verifier: 'offsetof( IApp::IApp::Settings, mDragToResize) == 22' evaluated to false.");
static_assert(sizeof(IApp::Settings::mDragToResize) == 1, "API_Verifier: 'sizeof(IApp::Settings::mDragToResize) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mDragToResize)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mDragToResize)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mBorderlessWindow)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mBorderlessWindow)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mBorderlessWindow) == 23, "API_Verifier: 'offsetof( IApp::IApp::Settings, mBorderlessWindow) == 23' evaluated to false.");
static_assert(sizeof(IApp::Settings::mBorderlessWindow) == 1, "API_Verifier: 'sizeof(IApp::Settings::mBorderlessWindow) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mBorderlessWindow)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mBorderlessWindow)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mAllowedOverSizeWindows)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mAllowedOverSizeWindows)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mAllowedOverSizeWindows) == 24, "API_Verifier: 'offsetof( IApp::IApp::Settings, mAllowedOverSizeWindows) == 24' evaluated to false.");
static_assert(sizeof(IApp::Settings::mAllowedOverSizeWindows) == 1, "API_Verifier: 'sizeof(IApp::Settings::mAllowedOverSizeWindows) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mAllowedOverSizeWindows)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mAllowedOverSizeWindows)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mInitialized)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mInitialized)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mInitialized) == 25, "API_Verifier: 'offsetof( IApp::IApp::Settings, mInitialized) == 25' evaluated to false.");
static_assert(sizeof(IApp::Settings::mInitialized) == 1, "API_Verifier: 'sizeof(IApp::Settings::mInitialized) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mInitialized)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mInitialized)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mQuit)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mQuit)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mQuit) == 26, "API_Verifier: 'offsetof( IApp::IApp::Settings, mQuit) == 26' evaluated to false.");
static_assert(sizeof(IApp::Settings::mQuit) == 1, "API_Verifier: 'sizeof(IApp::Settings::mQuit) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mQuit)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mQuit)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mBenchmarking)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mBenchmarking)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mBenchmarking) == 27, "API_Verifier: 'offsetof( IApp::IApp::Settings, mBenchmarking) == 27' evaluated to false.");
static_assert(sizeof(IApp::Settings::mBenchmarking) == 1, "API_Verifier: 'sizeof(IApp::Settings::mBenchmarking) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mBenchmarking)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mBenchmarking)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mCentered)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mCentered)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mCentered) == 28, "API_Verifier: 'offsetof( IApp::IApp::Settings, mCentered) == 28' evaluated to false.");
static_assert(sizeof(IApp::Settings::mCentered) == 1, "API_Verifier: 'sizeof(IApp::Settings::mCentered) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mCentered)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mCentered)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mFocused)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mFocused)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mFocused) == 29, "API_Verifier: 'offsetof( IApp::IApp::Settings, mFocused) == 29' evaluated to false.");
static_assert(sizeof(IApp::Settings::mFocused) == 1, "API_Verifier: 'sizeof(IApp::Settings::mFocused) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mFocused)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mFocused)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mForceLowDPI)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mForceLowDPI)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mForceLowDPI) == 30, "API_Verifier: 'offsetof( IApp::IApp::Settings, mForceLowDPI) == 30' evaluated to false.");
static_assert(sizeof(IApp::Settings::mForceLowDPI) == 1, "API_Verifier: 'sizeof(IApp::Settings::mForceLowDPI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mForceLowDPI)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mForceLowDPI)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mShowPlatformUI)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mShowPlatformUI)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mShowPlatformUI) == 31, "API_Verifier: 'offsetof( IApp::IApp::Settings, mShowPlatformUI) == 31' evaluated to false.");
static_assert(sizeof(IApp::Settings::mShowPlatformUI) == 1, "API_Verifier: 'sizeof(IApp::Settings::mShowPlatformUI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mShowPlatformUI)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mShowPlatformUI)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mVSyncEnabled)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mVSyncEnabled)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mVSyncEnabled) == 32, "API_Verifier: 'offsetof( IApp::IApp::Settings, mVSyncEnabled) == 32' evaluated to false.");
static_assert(sizeof(IApp::Settings::mVSyncEnabled) == 1, "API_Verifier: 'sizeof(IApp::Settings::mVSyncEnabled) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mVSyncEnabled)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mVSyncEnabled)>' evaluated to false.");

static_assert(alignof(IApp::IApp::Settings) == 4, "API_Verifier: 'alignof(IApp::IApp::Settings) == 4' evaluated to false.");
static_assert(sizeof(IApp::IApp::Settings) == 36, "API_Verifier: 'sizeof(IApp::IApp::Settings) == 36' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWidth)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWidth) == 0, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWidth) == 0' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWidth) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWidth)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mHeight)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mHeight) == 4, "API_Verifier: 'offsetof( IApp::IApp::Settings, mHeight) == 4' evaluated to false.");
static_assert(sizeof(IApp::Settings::mHeight) == 4, "API_Verifier: 'sizeof(IApp::Settings::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mHeight)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mMonitorIndex)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mMonitorIndex)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mMonitorIndex) == 8, "API_Verifier: 'offsetof( IApp::IApp::Settings, mMonitorIndex) == 8' evaluated to false.");
static_assert(sizeof(IApp::Settings::mMonitorIndex) == 4, "API_Verifier: 'sizeof(IApp::Settings::mMonitorIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mMonitorIndex)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mMonitorIndex)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWindowX)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWindowX)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWindowX) == 12, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWindowX) == 12' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWindowX) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWindowX) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWindowX)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWindowX)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mWindowY)) == 4, "API_Verifier: 'alignof( decltype(IApp::Settings::mWindowY)) == 4' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mWindowY) == 16, "API_Verifier: 'offsetof( IApp::IApp::Settings, mWindowY) == 16' evaluated to false.");
static_assert(sizeof(IApp::Settings::mWindowY) == 4, "API_Verifier: 'sizeof(IApp::Settings::mWindowY) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(IApp::Settings::mWindowY)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(IApp::Settings::mWindowY)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mFullScreen)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mFullScreen)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mFullScreen) == 20, "API_Verifier: 'offsetof( IApp::IApp::Settings, mFullScreen) == 20' evaluated to false.");
static_assert(sizeof(IApp::Settings::mFullScreen) == 1, "API_Verifier: 'sizeof(IApp::Settings::mFullScreen) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mFullScreen)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mFullScreen)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mExternalWindow)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mExternalWindow)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mExternalWindow) == 21, "API_Verifier: 'offsetof( IApp::IApp::Settings, mExternalWindow) == 21' evaluated to false.");
static_assert(sizeof(IApp::Settings::mExternalWindow) == 1, "API_Verifier: 'sizeof(IApp::Settings::mExternalWindow) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mExternalWindow)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mExternalWindow)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mDragToResize)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mDragToResize)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mDragToResize) == 22, "API_Verifier: 'offsetof( IApp::IApp::Settings, mDragToResize) == 22' evaluated to false.");
static_assert(sizeof(IApp::Settings::mDragToResize) == 1, "API_Verifier: 'sizeof(IApp::Settings::mDragToResize) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mDragToResize)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mDragToResize)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mBorderlessWindow)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mBorderlessWindow)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mBorderlessWindow) == 23, "API_Verifier: 'offsetof( IApp::IApp::Settings, mBorderlessWindow) == 23' evaluated to false.");
static_assert(sizeof(IApp::Settings::mBorderlessWindow) == 1, "API_Verifier: 'sizeof(IApp::Settings::mBorderlessWindow) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mBorderlessWindow)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mBorderlessWindow)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mAllowedOverSizeWindows)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mAllowedOverSizeWindows)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mAllowedOverSizeWindows) == 24, "API_Verifier: 'offsetof( IApp::IApp::Settings, mAllowedOverSizeWindows) == 24' evaluated to false.");
static_assert(sizeof(IApp::Settings::mAllowedOverSizeWindows) == 1, "API_Verifier: 'sizeof(IApp::Settings::mAllowedOverSizeWindows) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mAllowedOverSizeWindows)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mAllowedOverSizeWindows)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mInitialized)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mInitialized)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mInitialized) == 25, "API_Verifier: 'offsetof( IApp::IApp::Settings, mInitialized) == 25' evaluated to false.");
static_assert(sizeof(IApp::Settings::mInitialized) == 1, "API_Verifier: 'sizeof(IApp::Settings::mInitialized) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mInitialized)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mInitialized)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mQuit)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mQuit)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mQuit) == 26, "API_Verifier: 'offsetof( IApp::IApp::Settings, mQuit) == 26' evaluated to false.");
static_assert(sizeof(IApp::Settings::mQuit) == 1, "API_Verifier: 'sizeof(IApp::Settings::mQuit) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mQuit)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mQuit)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mBenchmarking)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mBenchmarking)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mBenchmarking) == 27, "API_Verifier: 'offsetof( IApp::IApp::Settings, mBenchmarking) == 27' evaluated to false.");
static_assert(sizeof(IApp::Settings::mBenchmarking) == 1, "API_Verifier: 'sizeof(IApp::Settings::mBenchmarking) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mBenchmarking)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mBenchmarking)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mCentered)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mCentered)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mCentered) == 28, "API_Verifier: 'offsetof( IApp::IApp::Settings, mCentered) == 28' evaluated to false.");
static_assert(sizeof(IApp::Settings::mCentered) == 1, "API_Verifier: 'sizeof(IApp::Settings::mCentered) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mCentered)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mCentered)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mFocused)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mFocused)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mFocused) == 29, "API_Verifier: 'offsetof( IApp::IApp::Settings, mFocused) == 29' evaluated to false.");
static_assert(sizeof(IApp::Settings::mFocused) == 1, "API_Verifier: 'sizeof(IApp::Settings::mFocused) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mFocused)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mFocused)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mForceLowDPI)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mForceLowDPI)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mForceLowDPI) == 30, "API_Verifier: 'offsetof( IApp::IApp::Settings, mForceLowDPI) == 30' evaluated to false.");
static_assert(sizeof(IApp::Settings::mForceLowDPI) == 1, "API_Verifier: 'sizeof(IApp::Settings::mForceLowDPI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mForceLowDPI)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mForceLowDPI)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mShowPlatformUI)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mShowPlatformUI)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mShowPlatformUI) == 31, "API_Verifier: 'offsetof( IApp::IApp::Settings, mShowPlatformUI) == 31' evaluated to false.");
static_assert(sizeof(IApp::Settings::mShowPlatformUI) == 1, "API_Verifier: 'sizeof(IApp::Settings::mShowPlatformUI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mShowPlatformUI)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mShowPlatformUI)>' evaluated to false.");

static_assert(alignof( decltype(IApp::Settings::mVSyncEnabled)) == 1, "API_Verifier: 'alignof( decltype(IApp::Settings::mVSyncEnabled)) == 1' evaluated to false.");
static_assert(offsetof( IApp::IApp::Settings, mVSyncEnabled) == 32, "API_Verifier: 'offsetof( IApp::IApp::Settings, mVSyncEnabled) == 32' evaluated to false.");
static_assert(sizeof(IApp::Settings::mVSyncEnabled) == 1, "API_Verifier: 'sizeof(IApp::Settings::mVSyncEnabled) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(IApp::Settings::mVSyncEnabled)>, "API_Verifier: 'std::is_same_v<bool, decltype(IApp::Settings::mVSyncEnabled)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\ICameraController.h"

static_assert(alignof(CameraMotionParameters) == 4, "API_Verifier: 'alignof(CameraMotionParameters) == 4' evaluated to false.");
static_assert(sizeof(CameraMotionParameters) == 20, "API_Verifier: 'sizeof(CameraMotionParameters) == 20' evaluated to false.");

static_assert(alignof( decltype(CameraMotionParameters::maxSpeed)) == 4, "API_Verifier: 'alignof( decltype(CameraMotionParameters::maxSpeed)) == 4' evaluated to false.");
static_assert(offsetof( CameraMotionParameters, maxSpeed) == 0, "API_Verifier: 'offsetof( CameraMotionParameters, maxSpeed) == 0' evaluated to false.");
static_assert(sizeof(CameraMotionParameters::maxSpeed) == 4, "API_Verifier: 'sizeof(CameraMotionParameters::maxSpeed) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(CameraMotionParameters::maxSpeed)>, "API_Verifier: 'std::is_same_v<float, decltype(CameraMotionParameters::maxSpeed)>' evaluated to false.");

static_assert(alignof( decltype(CameraMotionParameters::acceleration)) == 4, "API_Verifier: 'alignof( decltype(CameraMotionParameters::acceleration)) == 4' evaluated to false.");
static_assert(offsetof( CameraMotionParameters, acceleration) == 4, "API_Verifier: 'offsetof( CameraMotionParameters, acceleration) == 4' evaluated to false.");
static_assert(sizeof(CameraMotionParameters::acceleration) == 4, "API_Verifier: 'sizeof(CameraMotionParameters::acceleration) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(CameraMotionParameters::acceleration)>, "API_Verifier: 'std::is_same_v<float, decltype(CameraMotionParameters::acceleration)>' evaluated to false.");

static_assert(alignof( decltype(CameraMotionParameters::braking)) == 4, "API_Verifier: 'alignof( decltype(CameraMotionParameters::braking)) == 4' evaluated to false.");
static_assert(offsetof( CameraMotionParameters, braking) == 8, "API_Verifier: 'offsetof( CameraMotionParameters, braking) == 8' evaluated to false.");
static_assert(sizeof(CameraMotionParameters::braking) == 4, "API_Verifier: 'sizeof(CameraMotionParameters::braking) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(CameraMotionParameters::braking)>, "API_Verifier: 'std::is_same_v<float, decltype(CameraMotionParameters::braking)>' evaluated to false.");

static_assert(alignof( decltype(CameraMotionParameters::movementSpeed)) == 4, "API_Verifier: 'alignof( decltype(CameraMotionParameters::movementSpeed)) == 4' evaluated to false.");
static_assert(offsetof( CameraMotionParameters, movementSpeed) == 12, "API_Verifier: 'offsetof( CameraMotionParameters, movementSpeed) == 12' evaluated to false.");
static_assert(sizeof(CameraMotionParameters::movementSpeed) == 4, "API_Verifier: 'sizeof(CameraMotionParameters::movementSpeed) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(CameraMotionParameters::movementSpeed)>, "API_Verifier: 'std::is_same_v<float, decltype(CameraMotionParameters::movementSpeed)>' evaluated to false.");

static_assert(alignof( decltype(CameraMotionParameters::rotationSpeed)) == 4, "API_Verifier: 'alignof( decltype(CameraMotionParameters::rotationSpeed)) == 4' evaluated to false.");
static_assert(offsetof( CameraMotionParameters, rotationSpeed) == 16, "API_Verifier: 'offsetof( CameraMotionParameters, rotationSpeed) == 16' evaluated to false.");
static_assert(sizeof(CameraMotionParameters::rotationSpeed) == 4, "API_Verifier: 'sizeof(CameraMotionParameters::rotationSpeed) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(CameraMotionParameters::rotationSpeed)>, "API_Verifier: 'std::is_same_v<float, decltype(CameraMotionParameters::rotationSpeed)>' evaluated to false.");

static_assert(alignof(ICameraController) == 8, "API_Verifier: 'alignof(ICameraController) == 8' evaluated to false.");
static_assert(sizeof(ICameraController) == 8, "API_Verifier: 'sizeof(ICameraController) == 8' evaluated to false.");

static_assert(alignof(CameraMatrix) == 16, "API_Verifier: 'alignof(CameraMatrix) == 16' evaluated to false.");
static_assert(sizeof(CameraMatrix) == 64, "API_Verifier: 'sizeof(CameraMatrix) == 64' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IFont.h"

static_assert(alignof(FontSystemDesc) == 8, "API_Verifier: 'alignof(FontSystemDesc) == 8' evaluated to false.");
static_assert(sizeof(FontSystemDesc) == 16, "API_Verifier: 'sizeof(FontSystemDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(FontSystemDesc::pRenderer)) == 8, "API_Verifier: 'alignof( decltype(FontSystemDesc::pRenderer)) == 8' evaluated to false.");
static_assert(offsetof( FontSystemDesc, pRenderer) == 0, "API_Verifier: 'offsetof( FontSystemDesc, pRenderer) == 0' evaluated to false.");
static_assert(sizeof(FontSystemDesc::pRenderer) == 8, "API_Verifier: 'sizeof(FontSystemDesc::pRenderer) == 8' evaluated to false.");
static_assert(std::is_same_v<Renderer*, decltype(FontSystemDesc::pRenderer)>, "API_Verifier: 'std::is_same_v<Renderer*, decltype(FontSystemDesc::pRenderer)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemDesc::mFontstashRingSizeBytes)) == 4, "API_Verifier: 'alignof( decltype(FontSystemDesc::mFontstashRingSizeBytes)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemDesc, mFontstashRingSizeBytes) == 8, "API_Verifier: 'offsetof( FontSystemDesc, mFontstashRingSizeBytes) == 8' evaluated to false.");
static_assert(sizeof(FontSystemDesc::mFontstashRingSizeBytes) == 4, "API_Verifier: 'sizeof(FontSystemDesc::mFontstashRingSizeBytes) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemDesc::mFontstashRingSizeBytes)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemDesc::mFontstashRingSizeBytes)>' evaluated to false.");

static_assert(alignof(FontSystemLoadDesc) == 8, "API_Verifier: 'alignof(FontSystemLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc) == 40, "API_Verifier: 'sizeof(FontSystemLoadDesc) == 40' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::pCache)) == 8, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::pCache)) == 8' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, pCache) == 0, "API_Verifier: 'offsetof( FontSystemLoadDesc, pCache) == 0' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::pCache) == 8, "API_Verifier: 'sizeof(FontSystemLoadDesc::pCache) == 8' evaluated to false.");
static_assert(std::is_same_v<PipelineCache*, decltype(FontSystemLoadDesc::pCache)>, "API_Verifier: 'std::is_same_v<PipelineCache*, decltype(FontSystemLoadDesc::pCache)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mLoadType)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mLoadType)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mLoadType) == 8, "API_Verifier: 'offsetof( FontSystemLoadDesc, mLoadType) == 8' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mLoadType) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mLoadType) == 4' evaluated to false.");
static_assert(std::is_same_v<ReloadType, decltype(FontSystemLoadDesc::mLoadType)>, "API_Verifier: 'std::is_same_v<ReloadType, decltype(FontSystemLoadDesc::mLoadType)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mColorFormat)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mColorFormat)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mColorFormat) == 12, "API_Verifier: 'offsetof( FontSystemLoadDesc, mColorFormat) == 12' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mColorFormat) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mColorFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mColorFormat)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mColorFormat)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mDepthFormat)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mDepthFormat)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mDepthFormat) == 16, "API_Verifier: 'offsetof( FontSystemLoadDesc, mDepthFormat) == 16' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mDepthFormat) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mDepthFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mDepthFormat)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mDepthFormat)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mWidth)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mWidth) == 20, "API_Verifier: 'offsetof( FontSystemLoadDesc, mWidth) == 20' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mWidth) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mHeight)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mHeight) == 24, "API_Verifier: 'offsetof( FontSystemLoadDesc, mHeight) == 24' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mHeight) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mCullMode)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mCullMode)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mCullMode) == 28, "API_Verifier: 'offsetof( FontSystemLoadDesc, mCullMode) == 28' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mCullMode) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mCullMode) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mCullMode)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mCullMode)>' evaluated to false.");

static_assert(alignof( decltype(FontSystemLoadDesc::mDepthCompareMode)) == 4, "API_Verifier: 'alignof( decltype(FontSystemLoadDesc::mDepthCompareMode)) == 4' evaluated to false.");
static_assert(offsetof( FontSystemLoadDesc, mDepthCompareMode) == 32, "API_Verifier: 'offsetof( FontSystemLoadDesc, mDepthCompareMode) == 32' evaluated to false.");
static_assert(sizeof(FontSystemLoadDesc::mDepthCompareMode) == 4, "API_Verifier: 'sizeof(FontSystemLoadDesc::mDepthCompareMode) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mDepthCompareMode)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontSystemLoadDesc::mDepthCompareMode)>' evaluated to false.");

static_assert(alignof(FontDesc) == 8, "API_Verifier: 'alignof(FontDesc) == 8' evaluated to false.");
static_assert(sizeof(FontDesc) == 16, "API_Verifier: 'sizeof(FontDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(FontDesc::pFontName)) == 8, "API_Verifier: 'alignof( decltype(FontDesc::pFontName)) == 8' evaluated to false.");
static_assert(offsetof( FontDesc, pFontName) == 0, "API_Verifier: 'offsetof( FontDesc, pFontName) == 0' evaluated to false.");
static_assert(sizeof(FontDesc::pFontName) == 8, "API_Verifier: 'sizeof(FontDesc::pFontName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(FontDesc::pFontName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(FontDesc::pFontName)>' evaluated to false.");

static_assert(alignof( decltype(FontDesc::pFontPath)) == 8, "API_Verifier: 'alignof( decltype(FontDesc::pFontPath)) == 8' evaluated to false.");
static_assert(offsetof( FontDesc, pFontPath) == 8, "API_Verifier: 'offsetof( FontDesc, pFontPath) == 8' evaluated to false.");
static_assert(sizeof(FontDesc::pFontPath) == 8, "API_Verifier: 'sizeof(FontDesc::pFontPath) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(FontDesc::pFontPath)>, "API_Verifier: 'std::is_same_v<const char *, decltype(FontDesc::pFontPath)>' evaluated to false.");

static_assert(alignof(FontDrawDesc) == 8, "API_Verifier: 'alignof(FontDrawDesc) == 8' evaluated to false.");
static_assert(sizeof(FontDrawDesc) == 32, "API_Verifier: 'sizeof(FontDrawDesc) == 32' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::pText)) == 8, "API_Verifier: 'alignof( decltype(FontDrawDesc::pText)) == 8' evaluated to false.");
static_assert(offsetof( FontDrawDesc, pText) == 0, "API_Verifier: 'offsetof( FontDrawDesc, pText) == 0' evaluated to false.");
static_assert(sizeof(FontDrawDesc::pText) == 8, "API_Verifier: 'sizeof(FontDrawDesc::pText) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(FontDrawDesc::pText)>, "API_Verifier: 'std::is_same_v<const char *, decltype(FontDrawDesc::pText)>' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::mFontID)) == 4, "API_Verifier: 'alignof( decltype(FontDrawDesc::mFontID)) == 4' evaluated to false.");
static_assert(offsetof( FontDrawDesc, mFontID) == 8, "API_Verifier: 'offsetof( FontDrawDesc, mFontID) == 8' evaluated to false.");
static_assert(sizeof(FontDrawDesc::mFontID) == 4, "API_Verifier: 'sizeof(FontDrawDesc::mFontID) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontDrawDesc::mFontID)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontDrawDesc::mFontID)>' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::mFontColor)) == 4, "API_Verifier: 'alignof( decltype(FontDrawDesc::mFontColor)) == 4' evaluated to false.");
static_assert(offsetof( FontDrawDesc, mFontColor) == 12, "API_Verifier: 'offsetof( FontDrawDesc, mFontColor) == 12' evaluated to false.");
static_assert(sizeof(FontDrawDesc::mFontColor) == 4, "API_Verifier: 'sizeof(FontDrawDesc::mFontColor) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FontDrawDesc::mFontColor)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FontDrawDesc::mFontColor)>' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::mFontSize)) == 4, "API_Verifier: 'alignof( decltype(FontDrawDesc::mFontSize)) == 4' evaluated to false.");
static_assert(offsetof( FontDrawDesc, mFontSize) == 16, "API_Verifier: 'offsetof( FontDrawDesc, mFontSize) == 16' evaluated to false.");
static_assert(sizeof(FontDrawDesc::mFontSize) == 4, "API_Verifier: 'sizeof(FontDrawDesc::mFontSize) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(FontDrawDesc::mFontSize)>, "API_Verifier: 'std::is_same_v<float, decltype(FontDrawDesc::mFontSize)>' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::mFontSpacing)) == 4, "API_Verifier: 'alignof( decltype(FontDrawDesc::mFontSpacing)) == 4' evaluated to false.");
static_assert(offsetof( FontDrawDesc, mFontSpacing) == 20, "API_Verifier: 'offsetof( FontDrawDesc, mFontSpacing) == 20' evaluated to false.");
static_assert(sizeof(FontDrawDesc::mFontSpacing) == 4, "API_Verifier: 'sizeof(FontDrawDesc::mFontSpacing) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(FontDrawDesc::mFontSpacing)>, "API_Verifier: 'std::is_same_v<float, decltype(FontDrawDesc::mFontSpacing)>' evaluated to false.");

static_assert(alignof( decltype(FontDrawDesc::mFontBlur)) == 4, "API_Verifier: 'alignof( decltype(FontDrawDesc::mFontBlur)) == 4' evaluated to false.");
static_assert(offsetof( FontDrawDesc, mFontBlur) == 24, "API_Verifier: 'offsetof( FontDrawDesc, mFontBlur) == 24' evaluated to false.");
static_assert(sizeof(FontDrawDesc::mFontBlur) == 4, "API_Verifier: 'sizeof(FontDrawDesc::mFontBlur) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(FontDrawDesc::mFontBlur)>, "API_Verifier: 'std::is_same_v<float, decltype(FontDrawDesc::mFontBlur)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IInput.h"

static_assert(std::is_same_v<std::underlying_type_t<GamepadButton>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<GamepadButton>,int>' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_LEFT_STICK_X == 0, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_LEFT_STICK_X == 0' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_LEFT_STICK_Y == 1, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_LEFT_STICK_Y == 1' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_RIGHT_STICK_X == 2, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_RIGHT_STICK_X == 2' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_RIGHT_STICK_Y == 3, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_RIGHT_STICK_Y == 3' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_4 == 4, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_4 == 4' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_5 == 5, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_5 == 5' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_6 == 6, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_6 == 6' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_7 == 7, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_7 == 7' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_8 == 8, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_8 == 8' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_9 == 9, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_9 == 9' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_10 == 10, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_10 == 10' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_11 == 11, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_11 == 11' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_12 == 12, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_12 == 12' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_13 == 13, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_13 == 13' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_14 == 14, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_14 == 14' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_15 == 15, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_15 == 15' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_16 == 16, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_16 == 16' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_17 == 17, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_17 == 17' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_18 == 18, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_18 == 18' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_19 == 19, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_19 == 19' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_20 == 20, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_20 == 20' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_21 == 21, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_21 == 21' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_22 == 22, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_22 == 22' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_23 == 23, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_23 == 23' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_24 == 24, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_24 == 24' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_25 == 25, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_25 == 25' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_26 == 26, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_26 == 26' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_27 == 27, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_27 == 27' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_28 == 28, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_28 == 28' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_29 == 29, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_29 == 29' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_30 == 30, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_30 == 30' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_31 == 31, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_31 == 31' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_ACCELERATION_X == 32, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_ACCELERATION_X == 32' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_ACCELERATION_Y == 33, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_ACCELERATION_Y == 33' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_ACCELERATION_Z == 34, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_ACCELERATION_Z == 34' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GRAVITY_X == 35, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GRAVITY_X == 35' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GRAVITY_Y == 36, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GRAVITY_Y == 36' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GRAVITY_Z == 37, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GRAVITY_Z == 37' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_X == 38, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_X == 38' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_Y == 39, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_Y == 39' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_Z == 40, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_GYROSCOPE_Z == 40' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_X == 41, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_X == 41' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_Y == 42, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_Y == 42' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_Z == 43, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_MAGNETIC_FIELD_Z == 43' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_START == 44, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_START == 44' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_AXIS_COUNT_ == 44, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_AXIS_COUNT_ == 44' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_SELECT == 45, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_SELECT == 45' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_LEFT == 46, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_LEFT == 46' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_RIGHT == 47, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_RIGHT == 47' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_UP == 48, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_UP == 48' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_DOWN == 49, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_DOWN == 49' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_A == 50, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_A == 50' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_B == 51, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_B == 51' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_X == 52, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_X == 52' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_Y == 53, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_Y == 53' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_L1 == 54, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_L1 == 54' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_R1 == 55, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_R1 == 55' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_L2 == 56, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_L2 == 56' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_R2 == 57, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_R2 == 57' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_L3 == 58, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_L3 == 58' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_R3 == 59, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_R3 == 59' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_HOME == 60, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_HOME == 60' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_17 == 61, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_17 == 61' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_18 == 62, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_18 == 62' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_19 == 63, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_19 == 63' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_20 == 64, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_20 == 64' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_21 == 65, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_21 == 65' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_22 == 66, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_22 == 66' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_23 == 67, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_23 == 67' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_24 == 68, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_24 == 68' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_25 == 69, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_25 == 69' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_26 == 70, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_26 == 70' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_27 == 71, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_27 == 71' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_28 == 72, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_28 == 72' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_29 == 73, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_29 == 73' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_30 == 74, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_30 == 74' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_31 == 75, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_31 == 75' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_MAX_ == 76, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_MAX_ == 76' evaluated to false.");
static_assert(GamepadButton::GAMEPAD_BUTTON_COUNT_ == 32, "API_Verifier: 'GamepadButton::GAMEPAD_BUTTON_COUNT_ == 32' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<KeyboardButton>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<KeyboardButton>,int>' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_INVALID == -1, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_INVALID == -1' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ESCAPE == 0, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ESCAPE == 0' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F1 == 1, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F1 == 1' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F2 == 2, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F2 == 2' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F3 == 3, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F3 == 3' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F4 == 4, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F4 == 4' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F5 == 5, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F5 == 5' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F6 == 6, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F6 == 6' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F7 == 7, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F7 == 7' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F8 == 8, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F8 == 8' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F9 == 9, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F9 == 9' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F10 == 10, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F10 == 10' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F11 == 11, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F11 == 11' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F12 == 12, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F12 == 12' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F13 == 13, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F13 == 13' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F14 == 14, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F14 == 14' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F15 == 15, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F15 == 15' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F16 == 16, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F16 == 16' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F17 == 17, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F17 == 17' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F18 == 18, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F18 == 18' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F19 == 19, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F19 == 19' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PRINT == 20, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PRINT == 20' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SCROLL_LOCK == 21, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SCROLL_LOCK == 21' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BREAK == 22, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BREAK == 22' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SPACE == 32, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SPACE == 32' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_APOSTROPHE == 39, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_APOSTROPHE == 39' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_COMMA == 44, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_COMMA == 44' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MINUS == 45, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MINUS == 45' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PERIOD == 46, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PERIOD == 46' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SLASH == 47, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SLASH == 47' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_0 == 48, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_0 == 48' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_1 == 49, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_1 == 49' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_2 == 50, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_2 == 50' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_3 == 51, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_3 == 51' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_4 == 52, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_4 == 52' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_5 == 53, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_5 == 53' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_6 == 54, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_6 == 54' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_7 == 55, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_7 == 55' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_8 == 56, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_8 == 56' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_9 == 57, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_9 == 57' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SEMICOLON == 59, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SEMICOLON == 59' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_LESS == 60, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_LESS == 60' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EQUAL == 61, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EQUAL == 61' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_A == 65, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_A == 65' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_B == 66, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_B == 66' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_C == 67, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_C == 67' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_D == 68, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_D == 68' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_E == 69, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_E == 69' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_F == 70, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_F == 70' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_G == 71, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_G == 71' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_H == 72, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_H == 72' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_I == 73, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_I == 73' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_J == 74, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_J == 74' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_K == 75, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_K == 75' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_L == 76, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_L == 76' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_M == 77, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_M == 77' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_N == 78, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_N == 78' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_O == 79, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_O == 79' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_P == 80, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_P == 80' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_Q == 81, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_Q == 81' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_R == 82, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_R == 82' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_S == 83, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_S == 83' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_T == 84, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_T == 84' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_U == 85, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_U == 85' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_V == 86, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_V == 86' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_W == 87, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_W == 87' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_X == 88, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_X == 88' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_Y == 89, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_Y == 89' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_Z == 90, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_Z == 90' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BRACKET_LEFT == 91, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BRACKET_LEFT == 91' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BACKSLASH == 92, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BACKSLASH == 92' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BRACKET_RIGHT == 93, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BRACKET_RIGHT == 93' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_GRAVE == 96, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_GRAVE == 96' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_LEFT == 97, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_LEFT == 97' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_RIGHT == 98, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_RIGHT == 98' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_UP == 99, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_UP == 99' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_DOWN == 100, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_DOWN == 100' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_INSERT == 101, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_INSERT == 101' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_HOME == 102, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_HOME == 102' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_DELETE == 103, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_DELETE == 103' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_END == 104, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_END == 104' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PAGE_UP == 105, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PAGE_UP == 105' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PAGE_DOWN == 106, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PAGE_DOWN == 106' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_NUM_LOCK == 107, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_NUM_LOCK == 107' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_EQUAL == 108, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_EQUAL == 108' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_DIVIDE == 109, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_DIVIDE == 109' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_MULTIPLY == 110, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_MULTIPLY == 110' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_SUBTRACT == 111, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_SUBTRACT == 111' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_ADD == 112, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_ADD == 112' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_ENTER == 113, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_ENTER == 113' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_INSERT == 114, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_INSERT == 114' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_END == 115, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_END == 115' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_DOWN == 116, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_DOWN == 116' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_PAGE_DOWN == 117, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_PAGE_DOWN == 117' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_LEFT == 118, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_LEFT == 118' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_BEGIN == 119, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_BEGIN == 119' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_RIGHT == 120, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_RIGHT == 120' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_HOME == 121, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_HOME == 121' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_UP == 122, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_UP == 122' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_PAGE_UP == 123, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_PAGE_UP == 123' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_KP_DELETE == 124, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_KP_DELETE == 124' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BACK_SPACE == 125, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BACK_SPACE == 125' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_TAB == 126, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_TAB == 126' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_RETURN == 127, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_RETURN == 127' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CAPS_LOCK == 128, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CAPS_LOCK == 128' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SHIFT_L == 129, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SHIFT_L == 129' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CTRL_L == 130, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CTRL_L == 130' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SUPER_L == 131, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SUPER_L == 131' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ALT_L == 132, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ALT_L == 132' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ALT_R == 133, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ALT_R == 133' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SUPER_R == 134, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SUPER_R == 134' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MENU == 135, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MENU == 135' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CTRL_R == 136, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CTRL_R == 136' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SHIFT_R == 137, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SHIFT_R == 137' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BACK == 138, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BACK == 138' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SOFT_LEFT == 139, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SOFT_LEFT == 139' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SOFT_RIGHT == 140, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SOFT_RIGHT == 140' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CALL == 141, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CALL == 141' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_END_CALL == 142, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_END_CALL == 142' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_START == 143, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_START == 143' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_POUND == 144, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_POUND == 144' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_DPAD_CENTER == 145, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_DPAD_CENTER == 145' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_VOLUME_UP == 146, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_VOLUME_UP == 146' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_VOLUME_DOWN == 147, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_VOLUME_DOWN == 147' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_POWER == 148, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_POWER == 148' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CAMERA == 149, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CAMERA == 149' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CLEAR == 150, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CLEAR == 150' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SYMBOL == 151, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SYMBOL == 151' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXPLORER == 152, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXPLORER == 152' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ENVELOPE == 153, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ENVELOPE == 153' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EQUALS == 154, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EQUALS == 154' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_AT == 155, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_AT == 155' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_HEADSET_HOOK == 156, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_HEADSET_HOOK == 156' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_FOCUS == 157, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_FOCUS == 157' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PLUS == 158, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PLUS == 158' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_NOTIFICATION == 159, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_NOTIFICATION == 159' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SEARCH == 160, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SEARCH == 160' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_PLAY_PAUSE == 161, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_PLAY_PAUSE == 161' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_STOP == 162, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_STOP == 162' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_NEXT == 163, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_NEXT == 163' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_PREVIOUS == 164, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_PREVIOUS == 164' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_REWIND == 165, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_REWIND == 165' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MEDIA_FAST_FORWARD == 166, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MEDIA_FAST_FORWARD == 166' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_MUTE == 167, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_MUTE == 167' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_PICT_SYMBOLS == 168, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_PICT_SYMBOLS == 168' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SWITCH_CHARSET == 169, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SWITCH_CHARSET == 169' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_FORWARD == 170, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_FORWARD == 170' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA1 == 171, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA1 == 171' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA2 == 172, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA2 == 172' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA3 == 173, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA3 == 173' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA4 == 174, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA4 == 174' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA5 == 175, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA5 == 175' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXTRA6 == 176, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXTRA6 == 176' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_FN == 177, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_FN == 177' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_CIRCUM_FLEX == 178, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_CIRCUM_FLEX == 178' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_S_SHARP == 179, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_S_SHARP == 179' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ACUTE == 180, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ACUTE == 180' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ALT_GR == 181, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ALT_GR == 181' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_NUMBER_SIGN == 182, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_NUMBER_SIGN == 182' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_U_DIAERESIS == 183, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_U_DIAERESIS == 183' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_A_DIAERESIS == 184, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_A_DIAERESIS == 184' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_O_DIAERESIS == 185, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_O_DIAERESIS == 185' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SECTION == 186, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SECTION == 186' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_A_RING == 187, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_A_RING == 187' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_DIAERESIS == 188, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_DIAERESIS == 188' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_TWO_SUPERIOR == 189, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_TWO_SUPERIOR == 189' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_RIGHT_PARENTHESIS == 190, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_RIGHT_PARENTHESIS == 190' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_DOLLAR == 191, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_DOLLAR == 191' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_U_GRAVE == 192, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_U_GRAVE == 192' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_ASTERISK == 193, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_ASTERISK == 193' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_COLON == 194, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_COLON == 194' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_EXCLAM == 195, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_EXCLAM == 195' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BRACE_LEFT == 196, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BRACE_LEFT == 196' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_BRACE_RIGHT == 197, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_BRACE_RIGHT == 197' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_SYS_RQ == 198, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_SYS_RQ == 198' evaluated to false.");
static_assert(KeyboardButton::KEYBOARD_BUTTON_COUNT_ == 199, "API_Verifier: 'KeyboardButton::KEYBOARD_BUTTON_COUNT_ == 199' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<MouseButton>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<MouseButton>,int>' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_0 == 0, "API_Verifier: 'MouseButton::MOUSE_BUTTON_0 == 0' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_LEFT == 0, "API_Verifier: 'MouseButton::MOUSE_BUTTON_LEFT == 0' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_1 == 1, "API_Verifier: 'MouseButton::MOUSE_BUTTON_1 == 1' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_MIDDLE == 1, "API_Verifier: 'MouseButton::MOUSE_BUTTON_MIDDLE == 1' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_2 == 2, "API_Verifier: 'MouseButton::MOUSE_BUTTON_2 == 2' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_RIGHT == 2, "API_Verifier: 'MouseButton::MOUSE_BUTTON_RIGHT == 2' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_3 == 3, "API_Verifier: 'MouseButton::MOUSE_BUTTON_3 == 3' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_WHEEL_UP == 3, "API_Verifier: 'MouseButton::MOUSE_BUTTON_WHEEL_UP == 3' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_4 == 4, "API_Verifier: 'MouseButton::MOUSE_BUTTON_4 == 4' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_WHEEL_DOWN == 4, "API_Verifier: 'MouseButton::MOUSE_BUTTON_WHEEL_DOWN == 4' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_5 == 5, "API_Verifier: 'MouseButton::MOUSE_BUTTON_5 == 5' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_6 == 6, "API_Verifier: 'MouseButton::MOUSE_BUTTON_6 == 6' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_7 == 7, "API_Verifier: 'MouseButton::MOUSE_BUTTON_7 == 7' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_8 == 8, "API_Verifier: 'MouseButton::MOUSE_BUTTON_8 == 8' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_9 == 9, "API_Verifier: 'MouseButton::MOUSE_BUTTON_9 == 9' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_10 == 10, "API_Verifier: 'MouseButton::MOUSE_BUTTON_10 == 10' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_11 == 11, "API_Verifier: 'MouseButton::MOUSE_BUTTON_11 == 11' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_12 == 12, "API_Verifier: 'MouseButton::MOUSE_BUTTON_12 == 12' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_13 == 13, "API_Verifier: 'MouseButton::MOUSE_BUTTON_13 == 13' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_14 == 14, "API_Verifier: 'MouseButton::MOUSE_BUTTON_14 == 14' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_15 == 15, "API_Verifier: 'MouseButton::MOUSE_BUTTON_15 == 15' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_16 == 16, "API_Verifier: 'MouseButton::MOUSE_BUTTON_16 == 16' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_17 == 17, "API_Verifier: 'MouseButton::MOUSE_BUTTON_17 == 17' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_18 == 18, "API_Verifier: 'MouseButton::MOUSE_BUTTON_18 == 18' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_19 == 19, "API_Verifier: 'MouseButton::MOUSE_BUTTON_19 == 19' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_20 == 20, "API_Verifier: 'MouseButton::MOUSE_BUTTON_20 == 20' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_MAX == 20, "API_Verifier: 'MouseButton::MOUSE_BUTTON_MAX == 20' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_COUNT == 21, "API_Verifier: 'MouseButton::MOUSE_BUTTON_COUNT == 21' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_AXIS_X == 21, "API_Verifier: 'MouseButton::MOUSE_BUTTON_AXIS_X == 21' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_AXIS_Y == 22, "API_Verifier: 'MouseButton::MOUSE_BUTTON_AXIS_Y == 22' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_COUNT_ == 23, "API_Verifier: 'MouseButton::MOUSE_BUTTON_COUNT_ == 23' evaluated to false.");
static_assert(MouseButton::MOUSE_BUTTON_AXIS_COUNT == 2, "API_Verifier: 'MouseButton::MOUSE_BUTTON_AXIS_COUNT == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<TouchButton>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<TouchButton>,int>' evaluated to false.");
static_assert(TouchButton::TOUCH_BUTTON_NONE == 0, "API_Verifier: 'TouchButton::TOUCH_BUTTON_NONE == 0' evaluated to false.");
static_assert(TouchButton::TOUCH_AXIS_X == 1, "API_Verifier: 'TouchButton::TOUCH_AXIS_X == 1' evaluated to false.");
static_assert(TouchButton::TOUCH_AXIS_Y == 2, "API_Verifier: 'TouchButton::TOUCH_AXIS_Y == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<TouchGesture>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<TouchGesture>,int>' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_TAP == 0, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_TAP == 0' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_PAN == 1, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_PAN == 1' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_DOUBLE_TAP == 2, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_DOUBLE_TAP == 2' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_SWIPE == 3, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_SWIPE == 3' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_PINCH == 4, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_PINCH == 4' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_ROTATE == 5, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_ROTATE == 5' evaluated to false.");
static_assert(TouchGesture::TOUCH_GESTURE_LONG_PRESS == 6, "API_Verifier: 'TouchGesture::TOUCH_GESTURE_LONG_PRESS == 6' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<TouchScreenArea>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<TouchScreenArea>,int>' evaluated to false.");
static_assert(TouchScreenArea::AREA_LEFT == 0, "API_Verifier: 'TouchScreenArea::AREA_LEFT == 0' evaluated to false.");
static_assert(TouchScreenArea::AREA_RIGHT == 1, "API_Verifier: 'TouchScreenArea::AREA_RIGHT == 1' evaluated to false.");
static_assert(TouchScreenArea::AREA_FULL == 2, "API_Verifier: 'TouchScreenArea::AREA_FULL == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<InputActionMappingType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<InputActionMappingType>,int>' evaluated to false.");
static_assert(InputActionMappingType::INPUT_ACTION_MAPPING_NORMAL == 0, "API_Verifier: 'InputActionMappingType::INPUT_ACTION_MAPPING_NORMAL == 0' evaluated to false.");
static_assert(InputActionMappingType::INPUT_ACTION_MAPPING_COMPOSITE == 1, "API_Verifier: 'InputActionMappingType::INPUT_ACTION_MAPPING_COMPOSITE == 1' evaluated to false.");
static_assert(InputActionMappingType::INPUT_ACTION_MAPPING_COMBO == 2, "API_Verifier: 'InputActionMappingType::INPUT_ACTION_MAPPING_COMBO == 2' evaluated to false.");
static_assert(InputActionMappingType::INPUT_ACTION_MAPPING_TOUCH_GESTURE == 3, "API_Verifier: 'InputActionMappingType::INPUT_ACTION_MAPPING_TOUCH_GESTURE == 3' evaluated to false.");
static_assert(InputActionMappingType::INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK == 4, "API_Verifier: 'InputActionMappingType::INPUT_ACTION_MAPPING_TOUCH_VIRTUAL_JOYSTICK == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<InputActionMappingDeviceTarget>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<InputActionMappingDeviceTarget>,int>' evaluated to false.");
static_assert(InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_ALL == 0, "API_Verifier: 'InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_ALL == 0' evaluated to false.");
static_assert(InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_CONTROLLER == 1, "API_Verifier: 'InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_CONTROLLER == 1' evaluated to false.");
static_assert(InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_KEYBOARD == 2, "API_Verifier: 'InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_KEYBOARD == 2' evaluated to false.");
static_assert(InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_MOUSE == 3, "API_Verifier: 'InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_MOUSE == 3' evaluated to false.");
static_assert(InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_TOUCH == 4, "API_Verifier: 'InputActionMappingDeviceTarget::INPUT_ACTION_MAPPING_TARGET_TOUCH == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<UISystemInputActions::UISystemInputActions::UISystemInputAction>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<UISystemInputActions::UISystemInputActions::UISystemInputAction>,int>' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_START_ID_ == 192, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_START_ID_ == 192' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_TAB == 193, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_TAB == 193' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_LEFT_ARROW == 194, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_LEFT_ARROW == 194' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_RIGHT_ARROW == 195, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_RIGHT_ARROW == 195' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_UP_ARROW == 196, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_UP_ARROW == 196' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_DOWN_ARROW == 197, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_DOWN_ARROW == 197' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_PAGE_UP == 198, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_PAGE_UP == 198' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_PAGE_DOWN == 199, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_PAGE_DOWN == 199' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_HOME == 200, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_HOME == 200' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_END == 201, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_END == 201' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_INSERT == 202, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_INSERT == 202' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_DELETE == 203, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_DELETE == 203' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_BACK_SPACE == 204, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_BACK_SPACE == 204' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SPACE == 205, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SPACE == 205' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ENTER == 206, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ENTER == 206' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ESCAPE == 207, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ESCAPE == 207' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_CONTROL_L == 208, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_CONTROL_L == 208' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_CONTROL_R == 209, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_CONTROL_R == 209' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SHIFT_L == 210, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SHIFT_L == 210' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SHIFT_R == 211, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SHIFT_R == 211' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ALT_L == 212, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ALT_L == 212' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ALT_R == 213, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_ALT_R == 213' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SUPER_L == 214, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SUPER_L == 214' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SUPER_R == 215, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_SUPER_R == 215' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_A == 216, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_A == 216' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_C == 217, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_C == 217' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_V == 218, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_V == 218' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_X == 219, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_X == 219' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_Y == 220, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_Y == 220' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_Z == 221, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_Z == 221' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_F2 == 222, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_KEY_F2 == 222' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_LEFT == 223, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_LEFT == 223' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_RIGHT == 224, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_RIGHT == 224' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_MIDDLE == 225, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_MIDDLE == 225' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_SCROLL_UP == 226, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_SCROLL_UP == 226' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_SCROLL_DOWN == 227, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_SCROLL_DOWN == 227' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_MOVE == 228, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_MOUSE_MOVE == 228' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TOGGLE_UI == 229, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TOGGLE_UI == 229' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_ACTIVATE == 230, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_ACTIVATE == 230' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_CANCEL == 231, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_CANCEL == 231' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_INPUT == 232, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_INPUT == 232' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_MENU == 233, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_MENU == 233' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_LEFT == 234, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_LEFT == 234' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_RIGHT == 235, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_RIGHT == 235' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_UP == 236, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_UP == 236' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_DOWN == 237, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_WINDOW_DOWN == 237' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_SCROLL_MOVE_WINDOW == 238, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_SCROLL_MOVE_WINDOW == 238' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_FOCUS_PREV == 239, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_FOCUS_PREV == 239' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_FOCUS_NEXT == 240, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_FOCUS_NEXT == 240' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_SLOW == 241, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_SLOW == 241' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_FAST == 242, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_TWEAK_FAST == 242' evaluated to false.");
static_assert(UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_HIDE_UI_TOGGLE == 243, "API_Verifier: 'UISystemInputActions::UISystemInputActions::UISystemInputAction::UI_ACTION_NAV_HIDE_UI_TOGGLE == 243' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<DefaultInputActions::DefaultInputActions::DefaultInputAction>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<DefaultInputActions::DefaultInputActions::DefaultInputAction>,int>' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::TRANSLATE_CAMERA == 0, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::TRANSLATE_CAMERA == 0' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::TRANSLATE_CAMERA_VERTICAL == 1, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::TRANSLATE_CAMERA_VERTICAL == 1' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::ROTATE_CAMERA == 2, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::ROTATE_CAMERA == 2' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::CAPTURE_INPUT == 3, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::CAPTURE_INPUT == 3' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::RESET_CAMERA == 4, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::RESET_CAMERA == 4' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::DUMP_PROFILE_DATA == 5, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::DUMP_PROFILE_DATA == 5' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::TOGGLE_FULLSCREEN == 6, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::TOGGLE_FULLSCREEN == 6' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::RELOAD_SHADERS == 7, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::RELOAD_SHADERS == 7' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::EXIT == 8, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::EXIT == 8' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_TAB == 193, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_TAB == 193' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_LEFT_ARROW == 194, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_LEFT_ARROW == 194' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_RIGHT_ARROW == 195, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_RIGHT_ARROW == 195' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_UP_ARROW == 196, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_UP_ARROW == 196' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_DOWN_ARROW == 197, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_DOWN_ARROW == 197' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_PAGE_UP == 198, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_PAGE_UP == 198' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_PAGE_DOWN == 199, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_PAGE_DOWN == 199' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_HOME == 200, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_HOME == 200' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_END == 201, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_END == 201' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_INSERT == 202, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_INSERT == 202' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_DELETE == 203, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_DELETE == 203' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_BACK_SPACE == 204, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_BACK_SPACE == 204' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SPACE == 205, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SPACE == 205' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ENTER == 206, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ENTER == 206' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ESCAPE == 207, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ESCAPE == 207' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_CONTROL_L == 208, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_CONTROL_L == 208' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_CONTROL_R == 209, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_CONTROL_R == 209' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SHIFT_L == 210, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SHIFT_L == 210' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SHIFT_R == 211, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SHIFT_R == 211' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ALT_L == 212, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ALT_L == 212' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ALT_R == 213, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_ALT_R == 213' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SUPER_L == 214, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SUPER_L == 214' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SUPER_R == 215, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_SUPER_R == 215' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_A == 216, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_A == 216' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_C == 217, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_C == 217' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_V == 218, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_V == 218' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_X == 219, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_X == 219' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_Y == 220, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_Y == 220' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_Z == 221, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_Z == 221' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_F2 == 222, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_KEY_F2 == 222' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_LEFT == 223, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_LEFT == 223' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_RIGHT == 224, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_RIGHT == 224' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_MIDDLE == 225, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_MIDDLE == 225' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_SCROLL_UP == 226, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_SCROLL_UP == 226' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_SCROLL_DOWN == 227, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_MOUSE_SCROLL_DOWN == 227' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TOGGLE_UI == 229, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TOGGLE_UI == 229' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_ACTIVATE == 230, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_ACTIVATE == 230' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_CANCEL == 231, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_CANCEL == 231' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_INPUT == 232, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_INPUT == 232' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_MENU == 233, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_MENU == 233' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_LEFT == 234, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_LEFT == 234' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_RIGHT == 235, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_RIGHT == 235' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_UP == 236, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_UP == 236' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_DOWN == 237, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_WINDOW_DOWN == 237' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_SCROLL_MOVE_WINDOW == 238, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_SCROLL_MOVE_WINDOW == 238' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_FOCUS_PREV == 239, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_FOCUS_PREV == 239' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_FOCUS_NEXT == 240, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_FOCUS_NEXT == 240' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_SLOW == 241, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_SLOW == 241' evaluated to false.");
static_assert(DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_FAST == 242, "API_Verifier: 'DefaultInputActions::DefaultInputActions::DefaultInputAction::UI_NAV_TWEAK_FAST == 242' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<InputDeviceType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<InputDeviceType>,int>' evaluated to false.");
static_assert(InputDeviceType::INPUT_DEVICE_INVALID == 0, "API_Verifier: 'InputDeviceType::INPUT_DEVICE_INVALID == 0' evaluated to false.");
static_assert(InputDeviceType::INPUT_DEVICE_GAMEPAD == 1, "API_Verifier: 'InputDeviceType::INPUT_DEVICE_GAMEPAD == 1' evaluated to false.");
static_assert(InputDeviceType::INPUT_DEVICE_TOUCH == 2, "API_Verifier: 'InputDeviceType::INPUT_DEVICE_TOUCH == 2' evaluated to false.");
static_assert(InputDeviceType::INPUT_DEVICE_KEYBOARD == 3, "API_Verifier: 'InputDeviceType::INPUT_DEVICE_KEYBOARD == 3' evaluated to false.");
static_assert(InputDeviceType::INPUT_DEVICE_MOUSE == 4, "API_Verifier: 'InputDeviceType::INPUT_DEVICE_MOUSE == 4' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<InputActionPhase>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<InputActionPhase>,int>' evaluated to false.");
static_assert(InputActionPhase::INPUT_ACTION_PHASE_STARTED == 0, "API_Verifier: 'InputActionPhase::INPUT_ACTION_PHASE_STARTED == 0' evaluated to false.");
static_assert(InputActionPhase::INPUT_ACTION_PHASE_UPDATED == 1, "API_Verifier: 'InputActionPhase::INPUT_ACTION_PHASE_UPDATED == 1' evaluated to false.");
static_assert(InputActionPhase::INPUT_ACTION_PHASE_ENDED == 2, "API_Verifier: 'InputActionPhase::INPUT_ACTION_PHASE_ENDED == 2' evaluated to false.");
static_assert(InputActionPhase::INPUT_ACTION_PHASE_CANCELED == 3, "API_Verifier: 'InputActionPhase::INPUT_ACTION_PHASE_CANCELED == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType>,int>' evaluated to false.");
static_assert(GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType::ANY_BUTTON_ACTION == 0, "API_Verifier: 'GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType::ANY_BUTTON_ACTION == 0' evaluated to false.");
static_assert(GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType::TEXT == 1, "API_Verifier: 'GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType::TEXT == 1' evaluated to false.");

static_assert(alignof(ActionMappingDesc) == 4, "API_Verifier: 'alignof(ActionMappingDesc) == 4' evaluated to false.");
static_assert(sizeof(ActionMappingDesc) == 52, "API_Verifier: 'sizeof(ActionMappingDesc) == 52' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mActionMappingType)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mActionMappingType)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mActionMappingType) == 0, "API_Verifier: 'offsetof( ActionMappingDesc, mActionMappingType) == 0' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mActionMappingType) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mActionMappingType) == 4' evaluated to false.");
static_assert(std::is_same_v<InputActionMappingType, decltype(ActionMappingDesc::mActionMappingType)>, "API_Verifier: 'std::is_same_v<InputActionMappingType, decltype(ActionMappingDesc::mActionMappingType)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mActionMappingDeviceTarget)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mActionMappingDeviceTarget)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mActionMappingDeviceTarget) == 4, "API_Verifier: 'offsetof( ActionMappingDesc, mActionMappingDeviceTarget) == 4' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mActionMappingDeviceTarget) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mActionMappingDeviceTarget) == 4' evaluated to false.");
static_assert(std::is_same_v<InputActionMappingDeviceTarget, decltype(ActionMappingDesc::mActionMappingDeviceTarget)>, "API_Verifier: 'std::is_same_v<InputActionMappingDeviceTarget, decltype(ActionMappingDesc::mActionMappingDeviceTarget)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mActionId)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mActionId)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mActionId) == 8, "API_Verifier: 'offsetof( ActionMappingDesc, mActionId) == 8' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mActionId) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mActionId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ActionMappingDesc::mActionId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ActionMappingDesc::mActionId)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mDeviceButtons)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mDeviceButtons)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mDeviceButtons) == 12, "API_Verifier: 'offsetof( ActionMappingDesc, mDeviceButtons) == 12' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mDeviceButtons) == 16, "API_Verifier: 'sizeof(ActionMappingDesc::mDeviceButtons) == 16' evaluated to false.");
static_assert(std::is_same_v<int32_t[4], decltype(ActionMappingDesc::mDeviceButtons)>, "API_Verifier: 'std::is_same_v<int32_t[4], decltype(ActionMappingDesc::mDeviceButtons)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mNumAxis)) == 1, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mNumAxis)) == 1' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mNumAxis) == 28, "API_Verifier: 'offsetof( ActionMappingDesc, mNumAxis) == 28' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mNumAxis) == 1, "API_Verifier: 'sizeof(ActionMappingDesc::mNumAxis) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(ActionMappingDesc::mNumAxis)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(ActionMappingDesc::mNumAxis)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mDelta)) == 1, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mDelta)) == 1' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mDelta) == 29, "API_Verifier: 'offsetof( ActionMappingDesc, mDelta) == 29' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mDelta) == 1, "API_Verifier: 'sizeof(ActionMappingDesc::mDelta) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(ActionMappingDesc::mDelta)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(ActionMappingDesc::mDelta)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mUserId)) == 1, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mUserId)) == 1' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mUserId) == 30, "API_Verifier: 'offsetof( ActionMappingDesc, mUserId) == 30' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mUserId) == 1, "API_Verifier: 'sizeof(ActionMappingDesc::mUserId) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(ActionMappingDesc::mUserId)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(ActionMappingDesc::mUserId)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mDeadzone)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mDeadzone)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mDeadzone) == 32, "API_Verifier: 'offsetof( ActionMappingDesc, mDeadzone) == 32' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mDeadzone) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mDeadzone) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(ActionMappingDesc::mDeadzone)>, "API_Verifier: 'std::is_same_v<float, decltype(ActionMappingDesc::mDeadzone)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mOutsideRadius)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mOutsideRadius)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mOutsideRadius) == 36, "API_Verifier: 'offsetof( ActionMappingDesc, mOutsideRadius) == 36' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mOutsideRadius) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mOutsideRadius) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(ActionMappingDesc::mOutsideRadius)>, "API_Verifier: 'std::is_same_v<float, decltype(ActionMappingDesc::mOutsideRadius)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mScale)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mScale)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mScale) == 40, "API_Verifier: 'offsetof( ActionMappingDesc, mScale) == 40' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mScale) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mScale) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(ActionMappingDesc::mScale)>, "API_Verifier: 'std::is_same_v<float, decltype(ActionMappingDesc::mScale)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mTouchScreenArea)) == 4, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mTouchScreenArea)) == 4' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mTouchScreenArea) == 44, "API_Verifier: 'offsetof( ActionMappingDesc, mTouchScreenArea) == 44' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mTouchScreenArea) == 4, "API_Verifier: 'sizeof(ActionMappingDesc::mTouchScreenArea) == 4' evaluated to false.");
static_assert(std::is_same_v<TouchScreenArea, decltype(ActionMappingDesc::mTouchScreenArea)>, "API_Verifier: 'std::is_same_v<TouchScreenArea, decltype(ActionMappingDesc::mTouchScreenArea)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mScaleByDT)) == 1, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mScaleByDT)) == 1' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mScaleByDT) == 48, "API_Verifier: 'offsetof( ActionMappingDesc, mScaleByDT) == 48' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mScaleByDT) == 1, "API_Verifier: 'sizeof(ActionMappingDesc::mScaleByDT) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(ActionMappingDesc::mScaleByDT)>, "API_Verifier: 'std::is_same_v<bool, decltype(ActionMappingDesc::mScaleByDT)>' evaluated to false.");

static_assert(alignof( decltype(ActionMappingDesc::mCompositeUseSingleAxis)) == 1, "API_Verifier: 'alignof( decltype(ActionMappingDesc::mCompositeUseSingleAxis)) == 1' evaluated to false.");
static_assert(offsetof( ActionMappingDesc, mCompositeUseSingleAxis) == 49, "API_Verifier: 'offsetof( ActionMappingDesc, mCompositeUseSingleAxis) == 49' evaluated to false.");
static_assert(sizeof(ActionMappingDesc::mCompositeUseSingleAxis) == 1, "API_Verifier: 'sizeof(ActionMappingDesc::mCompositeUseSingleAxis) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(ActionMappingDesc::mCompositeUseSingleAxis)>, "API_Verifier: 'std::is_same_v<bool, decltype(ActionMappingDesc::mCompositeUseSingleAxis)>' evaluated to false.");

static_assert(alignof(UISystemInputActions) == 1, "API_Verifier: 'alignof(UISystemInputActions) == 1' evaluated to false.");
static_assert(sizeof(UISystemInputActions) == 1, "API_Verifier: 'sizeof(UISystemInputActions) == 1' evaluated to false.");

static_assert(alignof(DefaultInputActions) == 1, "API_Verifier: 'alignof(DefaultInputActions) == 1' evaluated to false.");
static_assert(sizeof(DefaultInputActions) == 1, "API_Verifier: 'sizeof(DefaultInputActions) == 1' evaluated to false.");

static_assert(alignof(InputActionContext) == 8, "API_Verifier: 'alignof(InputActionContext) == 8' evaluated to false.");
static_assert(sizeof(InputActionContext) == 88, "API_Verifier: 'sizeof(InputActionContext) == 88' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::pUserData)) == 8, "API_Verifier: 'alignof( decltype(InputActionContext::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( InputActionContext, pUserData) == 0, "API_Verifier: 'offsetof( InputActionContext, pUserData) == 0' evaluated to false.");
static_assert(sizeof(InputActionContext::pUserData) == 8, "API_Verifier: 'sizeof(InputActionContext::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(InputActionContext::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(InputActionContext::pUserData)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mFingerIndices)) == 4, "API_Verifier: 'alignof( decltype(InputActionContext::mFingerIndices)) == 4' evaluated to false.");
static_assert(offsetof( InputActionContext, mFingerIndices) == 8, "API_Verifier: 'offsetof( InputActionContext, mFingerIndices) == 8' evaluated to false.");
static_assert(sizeof(InputActionContext::mFingerIndices) == 32, "API_Verifier: 'sizeof(InputActionContext::mFingerIndices) == 32' evaluated to false.");
static_assert(std::is_same_v<int32_t[8], decltype(InputActionContext::mFingerIndices)>, "API_Verifier: 'std::is_same_v<int32_t[8], decltype(InputActionContext::mFingerIndices)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::pPosition)) == 8, "API_Verifier: 'alignof( decltype(InputActionContext::pPosition)) == 8' evaluated to false.");
static_assert(offsetof( InputActionContext, pPosition) == 56, "API_Verifier: 'offsetof( InputActionContext, pPosition) == 56' evaluated to false.");
static_assert(sizeof(InputActionContext::pPosition) == 8, "API_Verifier: 'sizeof(InputActionContext::pPosition) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2*, decltype(InputActionContext::pPosition)>, "API_Verifier: 'std::is_same_v<Vectormath::float2*, decltype(InputActionContext::pPosition)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::pCaptured)) == 8, "API_Verifier: 'alignof( decltype(InputActionContext::pCaptured)) == 8' evaluated to false.");
static_assert(offsetof( InputActionContext, pCaptured) == 64, "API_Verifier: 'offsetof( InputActionContext, pCaptured) == 64' evaluated to false.");
static_assert(sizeof(InputActionContext::pCaptured) == 8, "API_Verifier: 'sizeof(InputActionContext::pCaptured) == 8' evaluated to false.");
static_assert(std::is_same_v<const bool *, decltype(InputActionContext::pCaptured)>, "API_Verifier: 'std::is_same_v<const bool *, decltype(InputActionContext::pCaptured)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mScrollValue)) == 4, "API_Verifier: 'alignof( decltype(InputActionContext::mScrollValue)) == 4' evaluated to false.");
static_assert(offsetof( InputActionContext, mScrollValue) == 72, "API_Verifier: 'offsetof( InputActionContext, mScrollValue) == 72' evaluated to false.");
static_assert(sizeof(InputActionContext::mScrollValue) == 4, "API_Verifier: 'sizeof(InputActionContext::mScrollValue) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(InputActionContext::mScrollValue)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(InputActionContext::mScrollValue)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mActionId)) == 4, "API_Verifier: 'alignof( decltype(InputActionContext::mActionId)) == 4' evaluated to false.");
static_assert(offsetof( InputActionContext, mActionId) == 76, "API_Verifier: 'offsetof( InputActionContext, mActionId) == 76' evaluated to false.");
static_assert(sizeof(InputActionContext::mActionId) == 4, "API_Verifier: 'sizeof(InputActionContext::mActionId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(InputActionContext::mActionId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(InputActionContext::mActionId)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mPhase)) == 1, "API_Verifier: 'alignof( decltype(InputActionContext::mPhase)) == 1' evaluated to false.");
static_assert(offsetof( InputActionContext, mPhase) == 80, "API_Verifier: 'offsetof( InputActionContext, mPhase) == 80' evaluated to false.");
static_assert(sizeof(InputActionContext::mPhase) == 1, "API_Verifier: 'sizeof(InputActionContext::mPhase) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(InputActionContext::mPhase)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(InputActionContext::mPhase)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mDeviceType)) == 1, "API_Verifier: 'alignof( decltype(InputActionContext::mDeviceType)) == 1' evaluated to false.");
static_assert(offsetof( InputActionContext, mDeviceType) == 81, "API_Verifier: 'offsetof( InputActionContext, mDeviceType) == 81' evaluated to false.");
static_assert(sizeof(InputActionContext::mDeviceType) == 1, "API_Verifier: 'sizeof(InputActionContext::mDeviceType) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(InputActionContext::mDeviceType)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(InputActionContext::mDeviceType)>' evaluated to false.");

static_assert(alignof( decltype(InputActionContext::mUserId)) == 1, "API_Verifier: 'alignof( decltype(InputActionContext::mUserId)) == 1' evaluated to false.");
static_assert(offsetof( InputActionContext, mUserId) == 82, "API_Verifier: 'offsetof( InputActionContext, mUserId) == 82' evaluated to false.");
static_assert(sizeof(InputActionContext::mUserId) == 1, "API_Verifier: 'sizeof(InputActionContext::mUserId) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(InputActionContext::mUserId)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(InputActionContext::mUserId)>' evaluated to false.");

static_assert(alignof(InputActionDesc) == 8, "API_Verifier: 'alignof(InputActionDesc) == 8' evaluated to false.");
static_assert(sizeof(InputActionDesc) == 32, "API_Verifier: 'sizeof(InputActionDesc) == 32' evaluated to false.");

static_assert(alignof( decltype(InputActionDesc::mActionId)) == 4, "API_Verifier: 'alignof( decltype(InputActionDesc::mActionId)) == 4' evaluated to false.");
static_assert(offsetof( InputActionDesc, mActionId) == 0, "API_Verifier: 'offsetof( InputActionDesc, mActionId) == 0' evaluated to false.");
static_assert(sizeof(InputActionDesc::mActionId) == 4, "API_Verifier: 'sizeof(InputActionDesc::mActionId) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(InputActionDesc::mActionId)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(InputActionDesc::mActionId)>' evaluated to false.");

static_assert(alignof( decltype(InputActionDesc::pFunction)) == 8, "API_Verifier: 'alignof( decltype(InputActionDesc::pFunction)) == 8' evaluated to false.");
static_assert(offsetof( InputActionDesc, pFunction) == 8, "API_Verifier: 'offsetof( InputActionDesc, pFunction) == 8' evaluated to false.");
static_assert(sizeof(InputActionDesc::pFunction) == 8, "API_Verifier: 'sizeof(InputActionDesc::pFunction) == 8' evaluated to false.");
static_assert(std::is_same_v<InputActionCallback, decltype(InputActionDesc::pFunction)>, "API_Verifier: 'std::is_same_v<InputActionCallback, decltype(InputActionDesc::pFunction)>' evaluated to false.");

static_assert(alignof( decltype(InputActionDesc::pUserData)) == 8, "API_Verifier: 'alignof( decltype(InputActionDesc::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( InputActionDesc, pUserData) == 16, "API_Verifier: 'offsetof( InputActionDesc, pUserData) == 16' evaluated to false.");
static_assert(sizeof(InputActionDesc::pUserData) == 8, "API_Verifier: 'sizeof(InputActionDesc::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(InputActionDesc::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(InputActionDesc::pUserData)>' evaluated to false.");

static_assert(alignof( decltype(InputActionDesc::mUserId)) == 1, "API_Verifier: 'alignof( decltype(InputActionDesc::mUserId)) == 1' evaluated to false.");
static_assert(offsetof( InputActionDesc, mUserId) == 24, "API_Verifier: 'offsetof( InputActionDesc, mUserId) == 24' evaluated to false.");
static_assert(sizeof(InputActionDesc::mUserId) == 1, "API_Verifier: 'sizeof(InputActionDesc::mUserId) == 1' evaluated to false.");
static_assert(std::is_same_v<uint8_t, decltype(InputActionDesc::mUserId)>, "API_Verifier: 'std::is_same_v<uint8_t, decltype(InputActionDesc::mUserId)>' evaluated to false.");

static_assert(alignof(GlobalInputActionDesc) == 8, "API_Verifier: 'alignof(GlobalInputActionDesc) == 8' evaluated to false.");
static_assert(sizeof(GlobalInputActionDesc) == 24, "API_Verifier: 'sizeof(GlobalInputActionDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(GlobalInputActionDesc::mGlobalInputActionType)) == 4, "API_Verifier: 'alignof( decltype(GlobalInputActionDesc::mGlobalInputActionType)) == 4' evaluated to false.");
static_assert(offsetof( GlobalInputActionDesc, mGlobalInputActionType) == 0, "API_Verifier: 'offsetof( GlobalInputActionDesc, mGlobalInputActionType) == 0' evaluated to false.");
static_assert(sizeof(GlobalInputActionDesc::mGlobalInputActionType) == 4, "API_Verifier: 'sizeof(GlobalInputActionDesc::mGlobalInputActionType) == 4' evaluated to false.");
static_assert(std::is_same_v<GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType, decltype(GlobalInputActionDesc::mGlobalInputActionType)>, "API_Verifier: 'std::is_same_v<GlobalInputActionDesc::GlobalInputActionDesc::GlobalInputActionType, decltype(GlobalInputActionDesc::mGlobalInputActionType)>' evaluated to false.");

static_assert(alignof( decltype(GlobalInputActionDesc::pFunction)) == 8, "API_Verifier: 'alignof( decltype(GlobalInputActionDesc::pFunction)) == 8' evaluated to false.");
static_assert(offsetof( GlobalInputActionDesc, pFunction) == 8, "API_Verifier: 'offsetof( GlobalInputActionDesc, pFunction) == 8' evaluated to false.");
static_assert(sizeof(GlobalInputActionDesc::pFunction) == 8, "API_Verifier: 'sizeof(GlobalInputActionDesc::pFunction) == 8' evaluated to false.");
static_assert(std::is_same_v<InputActionCallback, decltype(GlobalInputActionDesc::pFunction)>, "API_Verifier: 'std::is_same_v<InputActionCallback, decltype(GlobalInputActionDesc::pFunction)>' evaluated to false.");

static_assert(alignof( decltype(GlobalInputActionDesc::pUserData)) == 8, "API_Verifier: 'alignof( decltype(GlobalInputActionDesc::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( GlobalInputActionDesc, pUserData) == 16, "API_Verifier: 'offsetof( GlobalInputActionDesc, pUserData) == 16' evaluated to false.");
static_assert(sizeof(GlobalInputActionDesc::pUserData) == 8, "API_Verifier: 'sizeof(GlobalInputActionDesc::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(GlobalInputActionDesc::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(GlobalInputActionDesc::pUserData)>' evaluated to false.");

static_assert(alignof(InputSystemDesc) == 8, "API_Verifier: 'alignof(InputSystemDesc) == 8' evaluated to false.");
static_assert(sizeof(InputSystemDesc) == 24, "API_Verifier: 'sizeof(InputSystemDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(InputSystemDesc::pRenderer)) == 8, "API_Verifier: 'alignof( decltype(InputSystemDesc::pRenderer)) == 8' evaluated to false.");
static_assert(offsetof( InputSystemDesc, pRenderer) == 0, "API_Verifier: 'offsetof( InputSystemDesc, pRenderer) == 0' evaluated to false.");
static_assert(sizeof(InputSystemDesc::pRenderer) == 8, "API_Verifier: 'sizeof(InputSystemDesc::pRenderer) == 8' evaluated to false.");
static_assert(std::is_same_v<Renderer*, decltype(InputSystemDesc::pRenderer)>, "API_Verifier: 'std::is_same_v<Renderer*, decltype(InputSystemDesc::pRenderer)>' evaluated to false.");

static_assert(alignof( decltype(InputSystemDesc::pWindow)) == 8, "API_Verifier: 'alignof( decltype(InputSystemDesc::pWindow)) == 8' evaluated to false.");
static_assert(offsetof( InputSystemDesc, pWindow) == 8, "API_Verifier: 'offsetof( InputSystemDesc, pWindow) == 8' evaluated to false.");
static_assert(sizeof(InputSystemDesc::pWindow) == 8, "API_Verifier: 'sizeof(InputSystemDesc::pWindow) == 8' evaluated to false.");
static_assert(std::is_same_v<WindowDesc*, decltype(InputSystemDesc::pWindow)>, "API_Verifier: 'std::is_same_v<WindowDesc*, decltype(InputSystemDesc::pWindow)>' evaluated to false.");

static_assert(alignof( decltype(InputSystemDesc::pJoystickTexture)) == 8, "API_Verifier: 'alignof( decltype(InputSystemDesc::pJoystickTexture)) == 8' evaluated to false.");
static_assert(offsetof( InputSystemDesc, pJoystickTexture) == 16, "API_Verifier: 'offsetof( InputSystemDesc, pJoystickTexture) == 16' evaluated to false.");
static_assert(sizeof(InputSystemDesc::pJoystickTexture) == 8, "API_Verifier: 'sizeof(InputSystemDesc::pJoystickTexture) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(InputSystemDesc::pJoystickTexture)>, "API_Verifier: 'std::is_same_v<const char *, decltype(InputSystemDesc::pJoystickTexture)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IMiddleware.h"

static_assert(alignof(IMiddleware) == 8, "API_Verifier: 'alignof(IMiddleware) == 8' evaluated to false.");
static_assert(sizeof(IMiddleware) == 8, "API_Verifier: 'sizeof(IMiddleware) == 8' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IProfiler.h"

static_assert(alignof(ProfilerDesc) == 8, "API_Verifier: 'alignof(ProfilerDesc) == 8' evaluated to false.");
static_assert(sizeof(ProfilerDesc) == 48, "API_Verifier: 'sizeof(ProfilerDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::pRenderer)) == 8, "API_Verifier: 'alignof( decltype(ProfilerDesc::pRenderer)) == 8' evaluated to false.");
static_assert(offsetof( ProfilerDesc, pRenderer) == 0, "API_Verifier: 'offsetof( ProfilerDesc, pRenderer) == 0' evaluated to false.");
static_assert(sizeof(ProfilerDesc::pRenderer) == 8, "API_Verifier: 'sizeof(ProfilerDesc::pRenderer) == 8' evaluated to false.");
static_assert(std::is_same_v<Renderer*, decltype(ProfilerDesc::pRenderer)>, "API_Verifier: 'std::is_same_v<Renderer*, decltype(ProfilerDesc::pRenderer)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::ppQueues)) == 8, "API_Verifier: 'alignof( decltype(ProfilerDesc::ppQueues)) == 8' evaluated to false.");
static_assert(offsetof( ProfilerDesc, ppQueues) == 8, "API_Verifier: 'offsetof( ProfilerDesc, ppQueues) == 8' evaluated to false.");
static_assert(sizeof(ProfilerDesc::ppQueues) == 8, "API_Verifier: 'sizeof(ProfilerDesc::ppQueues) == 8' evaluated to false.");
static_assert(std::is_same_v<Queue **, decltype(ProfilerDesc::ppQueues)>, "API_Verifier: 'std::is_same_v<Queue **, decltype(ProfilerDesc::ppQueues)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::ppProfilerNames)) == 8, "API_Verifier: 'alignof( decltype(ProfilerDesc::ppProfilerNames)) == 8' evaluated to false.");
static_assert(offsetof( ProfilerDesc, ppProfilerNames) == 16, "API_Verifier: 'offsetof( ProfilerDesc, ppProfilerNames) == 16' evaluated to false.");
static_assert(sizeof(ProfilerDesc::ppProfilerNames) == 8, "API_Verifier: 'sizeof(ProfilerDesc::ppProfilerNames) == 8' evaluated to false.");
static_assert(std::is_same_v<const char **, decltype(ProfilerDesc::ppProfilerNames)>, "API_Verifier: 'std::is_same_v<const char **, decltype(ProfilerDesc::ppProfilerNames)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::pProfileTokens)) == 8, "API_Verifier: 'alignof( decltype(ProfilerDesc::pProfileTokens)) == 8' evaluated to false.");
static_assert(offsetof( ProfilerDesc, pProfileTokens) == 24, "API_Verifier: 'offsetof( ProfilerDesc, pProfileTokens) == 24' evaluated to false.");
static_assert(sizeof(ProfilerDesc::pProfileTokens) == 8, "API_Verifier: 'sizeof(ProfilerDesc::pProfileTokens) == 8' evaluated to false.");
static_assert(std::is_same_v<ProfileToken*, decltype(ProfilerDesc::pProfileTokens)>, "API_Verifier: 'std::is_same_v<ProfileToken*, decltype(ProfilerDesc::pProfileTokens)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::mGpuProfilerCount)) == 4, "API_Verifier: 'alignof( decltype(ProfilerDesc::mGpuProfilerCount)) == 4' evaluated to false.");
static_assert(offsetof( ProfilerDesc, mGpuProfilerCount) == 32, "API_Verifier: 'offsetof( ProfilerDesc, mGpuProfilerCount) == 32' evaluated to false.");
static_assert(sizeof(ProfilerDesc::mGpuProfilerCount) == 4, "API_Verifier: 'sizeof(ProfilerDesc::mGpuProfilerCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ProfilerDesc::mGpuProfilerCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ProfilerDesc::mGpuProfilerCount)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::mWidthUI)) == 4, "API_Verifier: 'alignof( decltype(ProfilerDesc::mWidthUI)) == 4' evaluated to false.");
static_assert(offsetof( ProfilerDesc, mWidthUI) == 36, "API_Verifier: 'offsetof( ProfilerDesc, mWidthUI) == 36' evaluated to false.");
static_assert(sizeof(ProfilerDesc::mWidthUI) == 4, "API_Verifier: 'sizeof(ProfilerDesc::mWidthUI) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ProfilerDesc::mWidthUI)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ProfilerDesc::mWidthUI)>' evaluated to false.");

static_assert(alignof( decltype(ProfilerDesc::mHeightUI)) == 4, "API_Verifier: 'alignof( decltype(ProfilerDesc::mHeightUI)) == 4' evaluated to false.");
static_assert(offsetof( ProfilerDesc, mHeightUI) == 40, "API_Verifier: 'offsetof( ProfilerDesc, mHeightUI) == 40' evaluated to false.");
static_assert(sizeof(ProfilerDesc::mHeightUI) == 4, "API_Verifier: 'sizeof(ProfilerDesc::mHeightUI) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ProfilerDesc::mHeightUI)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ProfilerDesc::mHeightUI)>' evaluated to false.");

static_assert(alignof(CpuProfileScopeMarker) == 8, "API_Verifier: 'alignof(CpuProfileScopeMarker) == 8' evaluated to false.");
static_assert(sizeof(CpuProfileScopeMarker) == 16, "API_Verifier: 'sizeof(CpuProfileScopeMarker) == 16' evaluated to false.");

static_assert(alignof( decltype(CpuProfileScopeMarker::nToken)) == 8, "API_Verifier: 'alignof( decltype(CpuProfileScopeMarker::nToken)) == 8' evaluated to false.");
static_assert(offsetof( CpuProfileScopeMarker, nToken) == 0, "API_Verifier: 'offsetof( CpuProfileScopeMarker, nToken) == 0' evaluated to false.");
static_assert(sizeof(CpuProfileScopeMarker::nToken) == 8, "API_Verifier: 'sizeof(CpuProfileScopeMarker::nToken) == 8' evaluated to false.");
static_assert(std::is_same_v<ProfileToken, decltype(CpuProfileScopeMarker::nToken)>, "API_Verifier: 'std::is_same_v<ProfileToken, decltype(CpuProfileScopeMarker::nToken)>' evaluated to false.");

static_assert(alignof( decltype(CpuProfileScopeMarker::nTick)) == 8, "API_Verifier: 'alignof( decltype(CpuProfileScopeMarker::nTick)) == 8' evaluated to false.");
static_assert(offsetof( CpuProfileScopeMarker, nTick) == 8, "API_Verifier: 'offsetof( CpuProfileScopeMarker, nTick) == 8' evaluated to false.");
static_assert(sizeof(CpuProfileScopeMarker::nTick) == 8, "API_Verifier: 'sizeof(CpuProfileScopeMarker::nTick) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(CpuProfileScopeMarker::nTick)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(CpuProfileScopeMarker::nTick)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IScreenshot.h"

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Application\Interfaces\IUI.h"

static_assert(std::is_same_v<std::underlying_type_t<WidgetType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<WidgetType>,int>' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLLAPSING_HEADER == 0, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLLAPSING_HEADER == 0' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DEBUG_TEXTURES == 1, "API_Verifier: 'WidgetType::WIDGET_TYPE_DEBUG_TEXTURES == 1' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_LABEL == 2, "API_Verifier: 'WidgetType::WIDGET_TYPE_LABEL == 2' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLOR_LABEL == 3, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLOR_LABEL == 3' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_HORIZONTAL_SPACE == 4, "API_Verifier: 'WidgetType::WIDGET_TYPE_HORIZONTAL_SPACE == 4' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SEPARATOR == 5, "API_Verifier: 'WidgetType::WIDGET_TYPE_SEPARATOR == 5' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_VERTICAL_SEPARATOR == 6, "API_Verifier: 'WidgetType::WIDGET_TYPE_VERTICAL_SEPARATOR == 6' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_BUTTON == 7, "API_Verifier: 'WidgetType::WIDGET_TYPE_BUTTON == 7' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_FLOAT == 8, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_FLOAT == 8' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_FLOAT2 == 9, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_FLOAT2 == 9' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_FLOAT3 == 10, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_FLOAT3 == 10' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_FLOAT4 == 11, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_FLOAT4 == 11' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_INT == 12, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_INT == 12' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_SLIDER_UINT == 13, "API_Verifier: 'WidgetType::WIDGET_TYPE_SLIDER_UINT == 13' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_RADIO_BUTTON == 14, "API_Verifier: 'WidgetType::WIDGET_TYPE_RADIO_BUTTON == 14' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_CHECKBOX == 15, "API_Verifier: 'WidgetType::WIDGET_TYPE_CHECKBOX == 15' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_ONE_LINE_CHECKBOX == 16, "API_Verifier: 'WidgetType::WIDGET_TYPE_ONE_LINE_CHECKBOX == 16' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_CURSOR_LOCATION == 17, "API_Verifier: 'WidgetType::WIDGET_TYPE_CURSOR_LOCATION == 17' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DROPDOWN == 18, "API_Verifier: 'WidgetType::WIDGET_TYPE_DROPDOWN == 18' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLUMN == 19, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLUMN == 19' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_PROGRESS_BAR == 20, "API_Verifier: 'WidgetType::WIDGET_TYPE_PROGRESS_BAR == 20' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLOR_SLIDER == 21, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLOR_SLIDER == 21' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_HISTOGRAM == 22, "API_Verifier: 'WidgetType::WIDGET_TYPE_HISTOGRAM == 22' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_PLOT_LINES == 23, "API_Verifier: 'WidgetType::WIDGET_TYPE_PLOT_LINES == 23' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLOR_PICKER == 24, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLOR_PICKER == 24' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_COLOR3_PICKER == 25, "API_Verifier: 'WidgetType::WIDGET_TYPE_COLOR3_PICKER == 25' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_TEXTBOX == 26, "API_Verifier: 'WidgetType::WIDGET_TYPE_TEXTBOX == 26' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DYNAMIC_TEXT == 27, "API_Verifier: 'WidgetType::WIDGET_TYPE_DYNAMIC_TEXT == 27' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_FILLED_RECT == 28, "API_Verifier: 'WidgetType::WIDGET_TYPE_FILLED_RECT == 28' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DRAW_TEXT == 29, "API_Verifier: 'WidgetType::WIDGET_TYPE_DRAW_TEXT == 29' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DRAW_TOOLTIP == 30, "API_Verifier: 'WidgetType::WIDGET_TYPE_DRAW_TOOLTIP == 30' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DRAW_LINE == 31, "API_Verifier: 'WidgetType::WIDGET_TYPE_DRAW_LINE == 31' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_DRAW_CURVE == 32, "API_Verifier: 'WidgetType::WIDGET_TYPE_DRAW_CURVE == 32' evaluated to false.");
static_assert(WidgetType::WIDGET_TYPE_CUSTOM == 33, "API_Verifier: 'WidgetType::WIDGET_TYPE_CUSTOM == 33' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<UITextFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<UITextFlags>,int>' evaluated to false.");
static_assert(UITextFlags::UI_TEXT_ENABLE_RESIZE == 1, "API_Verifier: 'UITextFlags::UI_TEXT_ENABLE_RESIZE == 1' evaluated to false.");
static_assert(UITextFlags::UI_TEXT_AUTOSELECT_ALL == 2, "API_Verifier: 'UITextFlags::UI_TEXT_AUTOSELECT_ALL == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<GuiComponentFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<GuiComponentFlags>,int>' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NONE == 0, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NONE == 0' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_TITLE_BAR == 1, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_TITLE_BAR == 1' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_RESIZE == 2, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_RESIZE == 2' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_MOVE == 4, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_MOVE == 4' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_SCROLLBAR == 8, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_SCROLLBAR == 8' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_COLLAPSE == 16, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_COLLAPSE == 16' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_AUTO_RESIZE == 32, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_AUTO_RESIZE == 32' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_INPUTS == 64, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_INPUTS == 64' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_MEMU_BAR == 128, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_MEMU_BAR == 128' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_HORIZONTAL_SCROLLBAR == 256, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_HORIZONTAL_SCROLLBAR == 256' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_FOCUS_ON_APPEARING == 512, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_FOCUS_ON_APPEARING == 512' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_BRING_TO_FRONT_ON_FOCUS == 1024, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_BRING_TO_FRONT_ON_FOCUS == 1024' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_VERTICAL_SCROLLBAR == 2048, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_VERTICAL_SCROLLBAR == 2048' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_HORIZONTAL_SCROLLBAR == 4096, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_HORIZONTAL_SCROLLBAR == 4096' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_USE_WINDOW_PADDING == 8192, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_ALWAYS_USE_WINDOW_PADDING == 8192' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_NAV_INPUT == 16384, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_NAV_INPUT == 16384' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_NAV_FOCUS == 32768, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_NAV_FOCUS == 32768' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_START_COLLAPSED == 65536, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_START_COLLAPSED == 65536' evaluated to false.");
static_assert(GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_DOCKING == 131072, "API_Verifier: 'GuiComponentFlags::GUI_COMPONENT_FLAGS_NO_DOCKING == 131072' evaluated to false.");

static_assert(alignof(UIWidget) == 8, "API_Verifier: 'alignof(UIWidget) == 8' evaluated to false.");
static_assert(sizeof(UIWidget) == 256, "API_Verifier: 'sizeof(UIWidget) == 256' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mType)) == 4, "API_Verifier: 'alignof( decltype(UIWidget::mType)) == 4' evaluated to false.");
static_assert(offsetof( UIWidget, mType) == 0, "API_Verifier: 'offsetof( UIWidget, mType) == 0' evaluated to false.");
static_assert(sizeof(UIWidget::mType) == 4, "API_Verifier: 'sizeof(UIWidget::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<WidgetType, decltype(UIWidget::mType)>, "API_Verifier: 'std::is_same_v<WidgetType, decltype(UIWidget::mType)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pWidget)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pWidget)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pWidget) == 8, "API_Verifier: 'offsetof( UIWidget, pWidget) == 8' evaluated to false.");
static_assert(sizeof(UIWidget::pWidget) == 8, "API_Verifier: 'sizeof(UIWidget::pWidget) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pWidget)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pWidget)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnHoverUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnHoverUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnHoverUserData) == 16, "API_Verifier: 'offsetof( UIWidget, pOnHoverUserData) == 16' evaluated to false.");
static_assert(sizeof(UIWidget::pOnHoverUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnHoverUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnHoverUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnHoverUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnHover)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnHover)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnHover) == 24, "API_Verifier: 'offsetof( UIWidget, pOnHover) == 24' evaluated to false.");
static_assert(sizeof(UIWidget::pOnHover) == 8, "API_Verifier: 'sizeof(UIWidget::pOnHover) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnHover)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnHover)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnActiveUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnActiveUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnActiveUserData) == 32, "API_Verifier: 'offsetof( UIWidget, pOnActiveUserData) == 32' evaluated to false.");
static_assert(sizeof(UIWidget::pOnActiveUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnActiveUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnActiveUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnActiveUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnActive)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnActive)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnActive) == 40, "API_Verifier: 'offsetof( UIWidget, pOnActive) == 40' evaluated to false.");
static_assert(sizeof(UIWidget::pOnActive) == 8, "API_Verifier: 'sizeof(UIWidget::pOnActive) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnActive)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnActive)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnFocusUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnFocusUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnFocusUserData) == 48, "API_Verifier: 'offsetof( UIWidget, pOnFocusUserData) == 48' evaluated to false.");
static_assert(sizeof(UIWidget::pOnFocusUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnFocusUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnFocusUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnFocusUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnFocus)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnFocus)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnFocus) == 56, "API_Verifier: 'offsetof( UIWidget, pOnFocus) == 56' evaluated to false.");
static_assert(sizeof(UIWidget::pOnFocus) == 8, "API_Verifier: 'sizeof(UIWidget::pOnFocus) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnFocus)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnFocus)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnEditedUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnEditedUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnEditedUserData) == 64, "API_Verifier: 'offsetof( UIWidget, pOnEditedUserData) == 64' evaluated to false.");
static_assert(sizeof(UIWidget::pOnEditedUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnEditedUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnEditedUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnEditedUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnEdited)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnEdited)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnEdited) == 72, "API_Verifier: 'offsetof( UIWidget, pOnEdited) == 72' evaluated to false.");
static_assert(sizeof(UIWidget::pOnEdited) == 8, "API_Verifier: 'sizeof(UIWidget::pOnEdited) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnEdited)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnEdited)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnDeactivatedUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnDeactivatedUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnDeactivatedUserData) == 80, "API_Verifier: 'offsetof( UIWidget, pOnDeactivatedUserData) == 80' evaluated to false.");
static_assert(sizeof(UIWidget::pOnDeactivatedUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnDeactivatedUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnDeactivatedUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnDeactivatedUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnDeactivated)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnDeactivated)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnDeactivated) == 88, "API_Verifier: 'offsetof( UIWidget, pOnDeactivated) == 88' evaluated to false.");
static_assert(sizeof(UIWidget::pOnDeactivated) == 8, "API_Verifier: 'sizeof(UIWidget::pOnDeactivated) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnDeactivated)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnDeactivated)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnDeactivatedAfterEditUserData)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnDeactivatedAfterEditUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnDeactivatedAfterEditUserData) == 96, "API_Verifier: 'offsetof( UIWidget, pOnDeactivatedAfterEditUserData) == 96' evaluated to false.");
static_assert(sizeof(UIWidget::pOnDeactivatedAfterEditUserData) == 8, "API_Verifier: 'sizeof(UIWidget::pOnDeactivatedAfterEditUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIWidget::pOnDeactivatedAfterEditUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIWidget::pOnDeactivatedAfterEditUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::pOnDeactivatedAfterEdit)) == 8, "API_Verifier: 'alignof( decltype(UIWidget::pOnDeactivatedAfterEdit)) == 8' evaluated to false.");
static_assert(offsetof( UIWidget, pOnDeactivatedAfterEdit) == 104, "API_Verifier: 'offsetof( UIWidget, pOnDeactivatedAfterEdit) == 104' evaluated to false.");
static_assert(sizeof(UIWidget::pOnDeactivatedAfterEdit) == 8, "API_Verifier: 'sizeof(UIWidget::pOnDeactivatedAfterEdit) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(UIWidget::pOnDeactivatedAfterEdit)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(UIWidget::pOnDeactivatedAfterEdit)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mLabel)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mLabel)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mLabel) == 112, "API_Verifier: 'offsetof( UIWidget, mLabel) == 112' evaluated to false.");
static_assert(sizeof(UIWidget::mLabel) == 128, "API_Verifier: 'sizeof(UIWidget::mLabel) == 128' evaluated to false.");
static_assert(std::is_same_v<char[128], decltype(UIWidget::mLabel)>, "API_Verifier: 'std::is_same_v<char[128], decltype(UIWidget::mLabel)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mDeferred)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mDeferred)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mDeferred) == 240, "API_Verifier: 'offsetof( UIWidget, mDeferred) == 240' evaluated to false.");
static_assert(sizeof(UIWidget::mDeferred) == 1, "API_Verifier: 'sizeof(UIWidget::mDeferred) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mDeferred)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mDeferred)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mHovered)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mHovered)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mHovered) == 241, "API_Verifier: 'offsetof( UIWidget, mHovered) == 241' evaluated to false.");
static_assert(sizeof(UIWidget::mHovered) == 1, "API_Verifier: 'sizeof(UIWidget::mHovered) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mHovered)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mHovered)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mActive)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mActive)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mActive) == 242, "API_Verifier: 'offsetof( UIWidget, mActive) == 242' evaluated to false.");
static_assert(sizeof(UIWidget::mActive) == 1, "API_Verifier: 'sizeof(UIWidget::mActive) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mActive)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mActive)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mFocused)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mFocused)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mFocused) == 243, "API_Verifier: 'offsetof( UIWidget, mFocused) == 243' evaluated to false.");
static_assert(sizeof(UIWidget::mFocused) == 1, "API_Verifier: 'sizeof(UIWidget::mFocused) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mFocused)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mFocused)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mEdited)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mEdited)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mEdited) == 244, "API_Verifier: 'offsetof( UIWidget, mEdited) == 244' evaluated to false.");
static_assert(sizeof(UIWidget::mEdited) == 1, "API_Verifier: 'sizeof(UIWidget::mEdited) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mEdited)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mEdited)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mDeactivated)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mDeactivated)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mDeactivated) == 245, "API_Verifier: 'offsetof( UIWidget, mDeactivated) == 245' evaluated to false.");
static_assert(sizeof(UIWidget::mDeactivated) == 1, "API_Verifier: 'sizeof(UIWidget::mDeactivated) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mDeactivated)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mDeactivated)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mDeactivatedAfterEdit)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mDeactivatedAfterEdit)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mDeactivatedAfterEdit) == 246, "API_Verifier: 'offsetof( UIWidget, mDeactivatedAfterEdit) == 246' evaluated to false.");
static_assert(sizeof(UIWidget::mDeactivatedAfterEdit) == 1, "API_Verifier: 'sizeof(UIWidget::mDeactivatedAfterEdit) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mDeactivatedAfterEdit)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mDeactivatedAfterEdit)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mSameLine)) == 1, "API_Verifier: 'alignof( decltype(UIWidget::mSameLine)) == 1' evaluated to false.");
static_assert(offsetof( UIWidget, mSameLine) == 247, "API_Verifier: 'offsetof( UIWidget, mSameLine) == 247' evaluated to false.");
static_assert(sizeof(UIWidget::mSameLine) == 1, "API_Verifier: 'sizeof(UIWidget::mSameLine) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIWidget::mSameLine)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIWidget::mSameLine)>' evaluated to false.");

static_assert(alignof( decltype(UIWidget::mDisplayPosition)) == 4, "API_Verifier: 'alignof( decltype(UIWidget::mDisplayPosition)) == 4' evaluated to false.");
static_assert(offsetof( UIWidget, mDisplayPosition) == 248, "API_Verifier: 'offsetof( UIWidget, mDisplayPosition) == 248' evaluated to false.");
static_assert(sizeof(UIWidget::mDisplayPosition) == 8, "API_Verifier: 'sizeof(UIWidget::mDisplayPosition) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(UIWidget::mDisplayPosition)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(UIWidget::mDisplayPosition)>' evaluated to false.");

static_assert(alignof(CollapsingHeaderWidget) == 8, "API_Verifier: 'alignof(CollapsingHeaderWidget) == 8' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget) == 16, "API_Verifier: 'sizeof(CollapsingHeaderWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::pGroupedWidgets)) == 8, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::pGroupedWidgets)) == 8' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, pGroupedWidgets) == 0, "API_Verifier: 'offsetof( CollapsingHeaderWidget, pGroupedWidgets) == 0' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::pGroupedWidgets) == 8, "API_Verifier: 'sizeof(CollapsingHeaderWidget::pGroupedWidgets) == 8' evaluated to false.");
static_assert(std::is_same_v<UIWidget **, decltype(CollapsingHeaderWidget::pGroupedWidgets)>, "API_Verifier: 'std::is_same_v<UIWidget **, decltype(CollapsingHeaderWidget::pGroupedWidgets)>' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::mWidgetsCount)) == 4, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::mWidgetsCount)) == 4' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, mWidgetsCount) == 8, "API_Verifier: 'offsetof( CollapsingHeaderWidget, mWidgetsCount) == 8' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::mWidgetsCount) == 4, "API_Verifier: 'sizeof(CollapsingHeaderWidget::mWidgetsCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(CollapsingHeaderWidget::mWidgetsCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(CollapsingHeaderWidget::mWidgetsCount)>' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::mCollapsed)) == 1, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::mCollapsed)) == 1' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, mCollapsed) == 12, "API_Verifier: 'offsetof( CollapsingHeaderWidget, mCollapsed) == 12' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::mCollapsed) == 1, "API_Verifier: 'sizeof(CollapsingHeaderWidget::mCollapsed) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CollapsingHeaderWidget::mCollapsed)>, "API_Verifier: 'std::is_same_v<bool, decltype(CollapsingHeaderWidget::mCollapsed)>' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::mPreviousCollapsed)) == 1, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::mPreviousCollapsed)) == 1' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, mPreviousCollapsed) == 13, "API_Verifier: 'offsetof( CollapsingHeaderWidget, mPreviousCollapsed) == 13' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::mPreviousCollapsed) == 1, "API_Verifier: 'sizeof(CollapsingHeaderWidget::mPreviousCollapsed) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CollapsingHeaderWidget::mPreviousCollapsed)>, "API_Verifier: 'std::is_same_v<bool, decltype(CollapsingHeaderWidget::mPreviousCollapsed)>' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::mDefaultOpen)) == 1, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::mDefaultOpen)) == 1' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, mDefaultOpen) == 14, "API_Verifier: 'offsetof( CollapsingHeaderWidget, mDefaultOpen) == 14' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::mDefaultOpen) == 1, "API_Verifier: 'sizeof(CollapsingHeaderWidget::mDefaultOpen) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CollapsingHeaderWidget::mDefaultOpen)>, "API_Verifier: 'std::is_same_v<bool, decltype(CollapsingHeaderWidget::mDefaultOpen)>' evaluated to false.");

static_assert(alignof( decltype(CollapsingHeaderWidget::mHeaderIsVisible)) == 1, "API_Verifier: 'alignof( decltype(CollapsingHeaderWidget::mHeaderIsVisible)) == 1' evaluated to false.");
static_assert(offsetof( CollapsingHeaderWidget, mHeaderIsVisible) == 15, "API_Verifier: 'offsetof( CollapsingHeaderWidget, mHeaderIsVisible) == 15' evaluated to false.");
static_assert(sizeof(CollapsingHeaderWidget::mHeaderIsVisible) == 1, "API_Verifier: 'sizeof(CollapsingHeaderWidget::mHeaderIsVisible) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(CollapsingHeaderWidget::mHeaderIsVisible)>, "API_Verifier: 'std::is_same_v<bool, decltype(CollapsingHeaderWidget::mHeaderIsVisible)>' evaluated to false.");

static_assert(alignof(ColumnWidget) == 8, "API_Verifier: 'alignof(ColumnWidget) == 8' evaluated to false.");
static_assert(sizeof(ColumnWidget) == 16, "API_Verifier: 'sizeof(ColumnWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(ColumnWidget::pPerColumnWidgets)) == 8, "API_Verifier: 'alignof( decltype(ColumnWidget::pPerColumnWidgets)) == 8' evaluated to false.");
static_assert(offsetof( ColumnWidget, pPerColumnWidgets) == 0, "API_Verifier: 'offsetof( ColumnWidget, pPerColumnWidgets) == 0' evaluated to false.");
static_assert(sizeof(ColumnWidget::pPerColumnWidgets) == 8, "API_Verifier: 'sizeof(ColumnWidget::pPerColumnWidgets) == 8' evaluated to false.");
static_assert(std::is_same_v<UIWidget **, decltype(ColumnWidget::pPerColumnWidgets)>, "API_Verifier: 'std::is_same_v<UIWidget **, decltype(ColumnWidget::pPerColumnWidgets)>' evaluated to false.");

static_assert(alignof( decltype(ColumnWidget::mWidgetsCount)) == 4, "API_Verifier: 'alignof( decltype(ColumnWidget::mWidgetsCount)) == 4' evaluated to false.");
static_assert(offsetof( ColumnWidget, mWidgetsCount) == 8, "API_Verifier: 'offsetof( ColumnWidget, mWidgetsCount) == 8' evaluated to false.");
static_assert(sizeof(ColumnWidget::mWidgetsCount) == 4, "API_Verifier: 'sizeof(ColumnWidget::mWidgetsCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ColumnWidget::mWidgetsCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ColumnWidget::mWidgetsCount)>' evaluated to false.");

static_assert(alignof(DebugTexturesWidget) == 8, "API_Verifier: 'alignof(DebugTexturesWidget) == 8' evaluated to false.");
static_assert(sizeof(DebugTexturesWidget) == 24, "API_Verifier: 'sizeof(DebugTexturesWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(DebugTexturesWidget::pTextures)) == 8, "API_Verifier: 'alignof( decltype(DebugTexturesWidget::pTextures)) == 8' evaluated to false.");
static_assert(offsetof( DebugTexturesWidget, pTextures) == 0, "API_Verifier: 'offsetof( DebugTexturesWidget, pTextures) == 0' evaluated to false.");
static_assert(sizeof(DebugTexturesWidget::pTextures) == 8, "API_Verifier: 'sizeof(DebugTexturesWidget::pTextures) == 8' evaluated to false.");
static_assert(std::is_same_v<const struct Texture *const *, decltype(DebugTexturesWidget::pTextures)>, "API_Verifier: 'std::is_same_v<const struct Texture *const *, decltype(DebugTexturesWidget::pTextures)>' evaluated to false.");

static_assert(alignof( decltype(DebugTexturesWidget::mTexturesCount)) == 4, "API_Verifier: 'alignof( decltype(DebugTexturesWidget::mTexturesCount)) == 4' evaluated to false.");
static_assert(offsetof( DebugTexturesWidget, mTexturesCount) == 8, "API_Verifier: 'offsetof( DebugTexturesWidget, mTexturesCount) == 8' evaluated to false.");
static_assert(sizeof(DebugTexturesWidget::mTexturesCount) == 4, "API_Verifier: 'sizeof(DebugTexturesWidget::mTexturesCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DebugTexturesWidget::mTexturesCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DebugTexturesWidget::mTexturesCount)>' evaluated to false.");

static_assert(alignof( decltype(DebugTexturesWidget::mTextureDisplaySize)) == 4, "API_Verifier: 'alignof( decltype(DebugTexturesWidget::mTextureDisplaySize)) == 4' evaluated to false.");
static_assert(offsetof( DebugTexturesWidget, mTextureDisplaySize) == 12, "API_Verifier: 'offsetof( DebugTexturesWidget, mTextureDisplaySize) == 12' evaluated to false.");
static_assert(sizeof(DebugTexturesWidget::mTextureDisplaySize) == 8, "API_Verifier: 'sizeof(DebugTexturesWidget::mTextureDisplaySize) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(DebugTexturesWidget::mTextureDisplaySize)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(DebugTexturesWidget::mTextureDisplaySize)>' evaluated to false.");

static_assert(alignof(LabelWidget) == 1, "API_Verifier: 'alignof(LabelWidget) == 1' evaluated to false.");
static_assert(sizeof(LabelWidget) == 1, "API_Verifier: 'sizeof(LabelWidget) == 1' evaluated to false.");

static_assert(alignof(ColorLabelWidget) == 4, "API_Verifier: 'alignof(ColorLabelWidget) == 4' evaluated to false.");
static_assert(sizeof(ColorLabelWidget) == 16, "API_Verifier: 'sizeof(ColorLabelWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(ColorLabelWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(ColorLabelWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( ColorLabelWidget, mColor) == 0, "API_Verifier: 'offsetof( ColorLabelWidget, mColor) == 0' evaluated to false.");
static_assert(sizeof(ColorLabelWidget::mColor) == 16, "API_Verifier: 'sizeof(ColorLabelWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(ColorLabelWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(ColorLabelWidget::mColor)>' evaluated to false.");

static_assert(alignof(HorizontalSpaceWidget) == 1, "API_Verifier: 'alignof(HorizontalSpaceWidget) == 1' evaluated to false.");
static_assert(sizeof(HorizontalSpaceWidget) == 1, "API_Verifier: 'sizeof(HorizontalSpaceWidget) == 1' evaluated to false.");

static_assert(alignof(SeparatorWidget) == 1, "API_Verifier: 'alignof(SeparatorWidget) == 1' evaluated to false.");
static_assert(sizeof(SeparatorWidget) == 1, "API_Verifier: 'sizeof(SeparatorWidget) == 1' evaluated to false.");

static_assert(alignof(VerticalSeparatorWidget) == 4, "API_Verifier: 'alignof(VerticalSeparatorWidget) == 4' evaluated to false.");
static_assert(sizeof(VerticalSeparatorWidget) == 4, "API_Verifier: 'sizeof(VerticalSeparatorWidget) == 4' evaluated to false.");

static_assert(alignof( decltype(VerticalSeparatorWidget::mLineCount)) == 4, "API_Verifier: 'alignof( decltype(VerticalSeparatorWidget::mLineCount)) == 4' evaluated to false.");
static_assert(offsetof( VerticalSeparatorWidget, mLineCount) == 0, "API_Verifier: 'offsetof( VerticalSeparatorWidget, mLineCount) == 0' evaluated to false.");
static_assert(sizeof(VerticalSeparatorWidget::mLineCount) == 4, "API_Verifier: 'sizeof(VerticalSeparatorWidget::mLineCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VerticalSeparatorWidget::mLineCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VerticalSeparatorWidget::mLineCount)>' evaluated to false.");

static_assert(alignof(ButtonWidget) == 1, "API_Verifier: 'alignof(ButtonWidget) == 1' evaluated to false.");
static_assert(sizeof(ButtonWidget) == 1, "API_Verifier: 'sizeof(ButtonWidget) == 1' evaluated to false.");

static_assert(alignof(SliderFloatWidget) == 8, "API_Verifier: 'alignof(SliderFloatWidget) == 8' evaluated to false.");
static_assert(sizeof(SliderFloatWidget) == 56, "API_Verifier: 'sizeof(SliderFloatWidget) == 56' evaluated to false.");

static_assert(alignof( decltype(SliderFloatWidget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderFloatWidget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderFloatWidget, mFormat) == 0, "API_Verifier: 'offsetof( SliderFloatWidget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderFloatWidget::mFormat) == 30, "API_Verifier: 'sizeof(SliderFloatWidget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderFloatWidget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderFloatWidget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloatWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderFloatWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderFloatWidget, pData) == 32, "API_Verifier: 'offsetof( SliderFloatWidget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderFloatWidget::pData) == 8, "API_Verifier: 'sizeof(SliderFloatWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(SliderFloatWidget::pData)>, "API_Verifier: 'std::is_same_v<float *, decltype(SliderFloatWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloatWidget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderFloatWidget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloatWidget, mMin) == 40, "API_Verifier: 'offsetof( SliderFloatWidget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderFloatWidget::mMin) == 4, "API_Verifier: 'sizeof(SliderFloatWidget::mMin) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SliderFloatWidget::mMin)>, "API_Verifier: 'std::is_same_v<float, decltype(SliderFloatWidget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloatWidget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderFloatWidget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloatWidget, mMax) == 44, "API_Verifier: 'offsetof( SliderFloatWidget, mMax) == 44' evaluated to false.");
static_assert(sizeof(SliderFloatWidget::mMax) == 4, "API_Verifier: 'sizeof(SliderFloatWidget::mMax) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SliderFloatWidget::mMax)>, "API_Verifier: 'std::is_same_v<float, decltype(SliderFloatWidget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloatWidget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderFloatWidget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloatWidget, mStep) == 48, "API_Verifier: 'offsetof( SliderFloatWidget, mStep) == 48' evaluated to false.");
static_assert(sizeof(SliderFloatWidget::mStep) == 4, "API_Verifier: 'sizeof(SliderFloatWidget::mStep) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(SliderFloatWidget::mStep)>, "API_Verifier: 'std::is_same_v<float, decltype(SliderFloatWidget::mStep)>' evaluated to false.");

static_assert(alignof(SliderFloat2Widget) == 8, "API_Verifier: 'alignof(SliderFloat2Widget) == 8' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget) == 64, "API_Verifier: 'sizeof(SliderFloat2Widget) == 64' evaluated to false.");

static_assert(alignof( decltype(SliderFloat2Widget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderFloat2Widget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderFloat2Widget, mFormat) == 0, "API_Verifier: 'offsetof( SliderFloat2Widget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget::mFormat) == 30, "API_Verifier: 'sizeof(SliderFloat2Widget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderFloat2Widget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderFloat2Widget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat2Widget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderFloat2Widget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderFloat2Widget, pData) == 32, "API_Verifier: 'offsetof( SliderFloat2Widget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget::pData) == 8, "API_Verifier: 'sizeof(SliderFloat2Widget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2*, decltype(SliderFloat2Widget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float2*, decltype(SliderFloat2Widget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat2Widget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat2Widget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat2Widget, mMin) == 40, "API_Verifier: 'offsetof( SliderFloat2Widget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget::mMin) == 8, "API_Verifier: 'sizeof(SliderFloat2Widget::mMin) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mMin)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat2Widget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat2Widget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat2Widget, mMax) == 48, "API_Verifier: 'offsetof( SliderFloat2Widget, mMax) == 48' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget::mMax) == 8, "API_Verifier: 'sizeof(SliderFloat2Widget::mMax) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mMax)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat2Widget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat2Widget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat2Widget, mStep) == 56, "API_Verifier: 'offsetof( SliderFloat2Widget, mStep) == 56' evaluated to false.");
static_assert(sizeof(SliderFloat2Widget::mStep) == 8, "API_Verifier: 'sizeof(SliderFloat2Widget::mStep) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mStep)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(SliderFloat2Widget::mStep)>' evaluated to false.");

static_assert(alignof(SliderFloat3Widget) == 8, "API_Verifier: 'alignof(SliderFloat3Widget) == 8' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget) == 80, "API_Verifier: 'sizeof(SliderFloat3Widget) == 80' evaluated to false.");

static_assert(alignof( decltype(SliderFloat3Widget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderFloat3Widget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderFloat3Widget, mFormat) == 0, "API_Verifier: 'offsetof( SliderFloat3Widget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget::mFormat) == 30, "API_Verifier: 'sizeof(SliderFloat3Widget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderFloat3Widget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderFloat3Widget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat3Widget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderFloat3Widget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderFloat3Widget, pData) == 32, "API_Verifier: 'offsetof( SliderFloat3Widget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget::pData) == 8, "API_Verifier: 'sizeof(SliderFloat3Widget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3*, decltype(SliderFloat3Widget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float3*, decltype(SliderFloat3Widget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat3Widget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat3Widget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat3Widget, mMin) == 40, "API_Verifier: 'offsetof( SliderFloat3Widget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget::mMin) == 12, "API_Verifier: 'sizeof(SliderFloat3Widget::mMin) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mMin)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat3Widget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat3Widget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat3Widget, mMax) == 52, "API_Verifier: 'offsetof( SliderFloat3Widget, mMax) == 52' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget::mMax) == 12, "API_Verifier: 'sizeof(SliderFloat3Widget::mMax) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mMax)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat3Widget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat3Widget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat3Widget, mStep) == 64, "API_Verifier: 'offsetof( SliderFloat3Widget, mStep) == 64' evaluated to false.");
static_assert(sizeof(SliderFloat3Widget::mStep) == 12, "API_Verifier: 'sizeof(SliderFloat3Widget::mStep) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mStep)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(SliderFloat3Widget::mStep)>' evaluated to false.");

static_assert(alignof(SliderFloat4Widget) == 8, "API_Verifier: 'alignof(SliderFloat4Widget) == 8' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget) == 88, "API_Verifier: 'sizeof(SliderFloat4Widget) == 88' evaluated to false.");

static_assert(alignof( decltype(SliderFloat4Widget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderFloat4Widget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderFloat4Widget, mFormat) == 0, "API_Verifier: 'offsetof( SliderFloat4Widget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget::mFormat) == 30, "API_Verifier: 'sizeof(SliderFloat4Widget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderFloat4Widget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderFloat4Widget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat4Widget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderFloat4Widget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderFloat4Widget, pData) == 32, "API_Verifier: 'offsetof( SliderFloat4Widget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget::pData) == 8, "API_Verifier: 'sizeof(SliderFloat4Widget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4*, decltype(SliderFloat4Widget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float4*, decltype(SliderFloat4Widget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat4Widget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat4Widget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat4Widget, mMin) == 40, "API_Verifier: 'offsetof( SliderFloat4Widget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget::mMin) == 16, "API_Verifier: 'sizeof(SliderFloat4Widget::mMin) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mMin)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat4Widget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat4Widget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat4Widget, mMax) == 56, "API_Verifier: 'offsetof( SliderFloat4Widget, mMax) == 56' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget::mMax) == 16, "API_Verifier: 'sizeof(SliderFloat4Widget::mMax) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mMax)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderFloat4Widget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderFloat4Widget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderFloat4Widget, mStep) == 72, "API_Verifier: 'offsetof( SliderFloat4Widget, mStep) == 72' evaluated to false.");
static_assert(sizeof(SliderFloat4Widget::mStep) == 16, "API_Verifier: 'sizeof(SliderFloat4Widget::mStep) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mStep)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(SliderFloat4Widget::mStep)>' evaluated to false.");

static_assert(alignof(SliderIntWidget) == 8, "API_Verifier: 'alignof(SliderIntWidget) == 8' evaluated to false.");
static_assert(sizeof(SliderIntWidget) == 56, "API_Verifier: 'sizeof(SliderIntWidget) == 56' evaluated to false.");

static_assert(alignof( decltype(SliderIntWidget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderIntWidget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderIntWidget, mFormat) == 0, "API_Verifier: 'offsetof( SliderIntWidget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderIntWidget::mFormat) == 30, "API_Verifier: 'sizeof(SliderIntWidget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderIntWidget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderIntWidget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderIntWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderIntWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderIntWidget, pData) == 32, "API_Verifier: 'offsetof( SliderIntWidget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderIntWidget::pData) == 8, "API_Verifier: 'sizeof(SliderIntWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<int32_t*, decltype(SliderIntWidget::pData)>, "API_Verifier: 'std::is_same_v<int32_t*, decltype(SliderIntWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderIntWidget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderIntWidget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderIntWidget, mMin) == 40, "API_Verifier: 'offsetof( SliderIntWidget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderIntWidget::mMin) == 4, "API_Verifier: 'sizeof(SliderIntWidget::mMin) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(SliderIntWidget::mMin)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(SliderIntWidget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderIntWidget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderIntWidget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderIntWidget, mMax) == 44, "API_Verifier: 'offsetof( SliderIntWidget, mMax) == 44' evaluated to false.");
static_assert(sizeof(SliderIntWidget::mMax) == 4, "API_Verifier: 'sizeof(SliderIntWidget::mMax) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(SliderIntWidget::mMax)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(SliderIntWidget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderIntWidget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderIntWidget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderIntWidget, mStep) == 48, "API_Verifier: 'offsetof( SliderIntWidget, mStep) == 48' evaluated to false.");
static_assert(sizeof(SliderIntWidget::mStep) == 4, "API_Verifier: 'sizeof(SliderIntWidget::mStep) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(SliderIntWidget::mStep)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(SliderIntWidget::mStep)>' evaluated to false.");

static_assert(alignof(SliderUintWidget) == 8, "API_Verifier: 'alignof(SliderUintWidget) == 8' evaluated to false.");
static_assert(sizeof(SliderUintWidget) == 56, "API_Verifier: 'sizeof(SliderUintWidget) == 56' evaluated to false.");

static_assert(alignof( decltype(SliderUintWidget::mFormat)) == 1, "API_Verifier: 'alignof( decltype(SliderUintWidget::mFormat)) == 1' evaluated to false.");
static_assert(offsetof( SliderUintWidget, mFormat) == 0, "API_Verifier: 'offsetof( SliderUintWidget, mFormat) == 0' evaluated to false.");
static_assert(sizeof(SliderUintWidget::mFormat) == 30, "API_Verifier: 'sizeof(SliderUintWidget::mFormat) == 30' evaluated to false.");
static_assert(std::is_same_v<char[30], decltype(SliderUintWidget::mFormat)>, "API_Verifier: 'std::is_same_v<char[30], decltype(SliderUintWidget::mFormat)>' evaluated to false.");

static_assert(alignof( decltype(SliderUintWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(SliderUintWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( SliderUintWidget, pData) == 32, "API_Verifier: 'offsetof( SliderUintWidget, pData) == 32' evaluated to false.");
static_assert(sizeof(SliderUintWidget::pData) == 8, "API_Verifier: 'sizeof(SliderUintWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(SliderUintWidget::pData)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(SliderUintWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(SliderUintWidget::mMin)) == 4, "API_Verifier: 'alignof( decltype(SliderUintWidget::mMin)) == 4' evaluated to false.");
static_assert(offsetof( SliderUintWidget, mMin) == 40, "API_Verifier: 'offsetof( SliderUintWidget, mMin) == 40' evaluated to false.");
static_assert(sizeof(SliderUintWidget::mMin) == 4, "API_Verifier: 'sizeof(SliderUintWidget::mMin) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SliderUintWidget::mMin)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SliderUintWidget::mMin)>' evaluated to false.");

static_assert(alignof( decltype(SliderUintWidget::mMax)) == 4, "API_Verifier: 'alignof( decltype(SliderUintWidget::mMax)) == 4' evaluated to false.");
static_assert(offsetof( SliderUintWidget, mMax) == 44, "API_Verifier: 'offsetof( SliderUintWidget, mMax) == 44' evaluated to false.");
static_assert(sizeof(SliderUintWidget::mMax) == 4, "API_Verifier: 'sizeof(SliderUintWidget::mMax) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SliderUintWidget::mMax)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SliderUintWidget::mMax)>' evaluated to false.");

static_assert(alignof( decltype(SliderUintWidget::mStep)) == 4, "API_Verifier: 'alignof( decltype(SliderUintWidget::mStep)) == 4' evaluated to false.");
static_assert(offsetof( SliderUintWidget, mStep) == 48, "API_Verifier: 'offsetof( SliderUintWidget, mStep) == 48' evaluated to false.");
static_assert(sizeof(SliderUintWidget::mStep) == 4, "API_Verifier: 'sizeof(SliderUintWidget::mStep) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(SliderUintWidget::mStep)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(SliderUintWidget::mStep)>' evaluated to false.");

static_assert(alignof(RadioButtonWidget) == 8, "API_Verifier: 'alignof(RadioButtonWidget) == 8' evaluated to false.");
static_assert(sizeof(RadioButtonWidget) == 16, "API_Verifier: 'sizeof(RadioButtonWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(RadioButtonWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(RadioButtonWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( RadioButtonWidget, pData) == 0, "API_Verifier: 'offsetof( RadioButtonWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(RadioButtonWidget::pData) == 8, "API_Verifier: 'sizeof(RadioButtonWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<int32_t*, decltype(RadioButtonWidget::pData)>, "API_Verifier: 'std::is_same_v<int32_t*, decltype(RadioButtonWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(RadioButtonWidget::mRadioId)) == 4, "API_Verifier: 'alignof( decltype(RadioButtonWidget::mRadioId)) == 4' evaluated to false.");
static_assert(offsetof( RadioButtonWidget, mRadioId) == 8, "API_Verifier: 'offsetof( RadioButtonWidget, mRadioId) == 8' evaluated to false.");
static_assert(sizeof(RadioButtonWidget::mRadioId) == 4, "API_Verifier: 'sizeof(RadioButtonWidget::mRadioId) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RadioButtonWidget::mRadioId)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RadioButtonWidget::mRadioId)>' evaluated to false.");

static_assert(alignof(CheckboxWidget) == 8, "API_Verifier: 'alignof(CheckboxWidget) == 8' evaluated to false.");
static_assert(sizeof(CheckboxWidget) == 8, "API_Verifier: 'sizeof(CheckboxWidget) == 8' evaluated to false.");

static_assert(alignof( decltype(CheckboxWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(CheckboxWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( CheckboxWidget, pData) == 0, "API_Verifier: 'offsetof( CheckboxWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(CheckboxWidget::pData) == 8, "API_Verifier: 'sizeof(CheckboxWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<bool *, decltype(CheckboxWidget::pData)>, "API_Verifier: 'std::is_same_v<bool *, decltype(CheckboxWidget::pData)>' evaluated to false.");

static_assert(alignof(OneLineCheckboxWidget) == 8, "API_Verifier: 'alignof(OneLineCheckboxWidget) == 8' evaluated to false.");
static_assert(sizeof(OneLineCheckboxWidget) == 24, "API_Verifier: 'sizeof(OneLineCheckboxWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(OneLineCheckboxWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(OneLineCheckboxWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( OneLineCheckboxWidget, pData) == 0, "API_Verifier: 'offsetof( OneLineCheckboxWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(OneLineCheckboxWidget::pData) == 8, "API_Verifier: 'sizeof(OneLineCheckboxWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<bool *, decltype(OneLineCheckboxWidget::pData)>, "API_Verifier: 'std::is_same_v<bool *, decltype(OneLineCheckboxWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(OneLineCheckboxWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(OneLineCheckboxWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( OneLineCheckboxWidget, mColor) == 8, "API_Verifier: 'offsetof( OneLineCheckboxWidget, mColor) == 8' evaluated to false.");
static_assert(sizeof(OneLineCheckboxWidget::mColor) == 16, "API_Verifier: 'sizeof(OneLineCheckboxWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(OneLineCheckboxWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(OneLineCheckboxWidget::mColor)>' evaluated to false.");

static_assert(alignof(CursorLocationWidget) == 4, "API_Verifier: 'alignof(CursorLocationWidget) == 4' evaluated to false.");
static_assert(sizeof(CursorLocationWidget) == 8, "API_Verifier: 'sizeof(CursorLocationWidget) == 8' evaluated to false.");

static_assert(alignof( decltype(CursorLocationWidget::mLocation)) == 4, "API_Verifier: 'alignof( decltype(CursorLocationWidget::mLocation)) == 4' evaluated to false.");
static_assert(offsetof( CursorLocationWidget, mLocation) == 0, "API_Verifier: 'offsetof( CursorLocationWidget, mLocation) == 0' evaluated to false.");
static_assert(sizeof(CursorLocationWidget::mLocation) == 8, "API_Verifier: 'sizeof(CursorLocationWidget::mLocation) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(CursorLocationWidget::mLocation)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(CursorLocationWidget::mLocation)>' evaluated to false.");

static_assert(alignof(DropdownWidget) == 8, "API_Verifier: 'alignof(DropdownWidget) == 8' evaluated to false.");
static_assert(sizeof(DropdownWidget) == 24, "API_Verifier: 'sizeof(DropdownWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(DropdownWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(DropdownWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( DropdownWidget, pData) == 0, "API_Verifier: 'offsetof( DropdownWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(DropdownWidget::pData) == 8, "API_Verifier: 'sizeof(DropdownWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(DropdownWidget::pData)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(DropdownWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(DropdownWidget::pNames)) == 8, "API_Verifier: 'alignof( decltype(DropdownWidget::pNames)) == 8' evaluated to false.");
static_assert(offsetof( DropdownWidget, pNames) == 8, "API_Verifier: 'offsetof( DropdownWidget, pNames) == 8' evaluated to false.");
static_assert(sizeof(DropdownWidget::pNames) == 8, "API_Verifier: 'sizeof(DropdownWidget::pNames) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *const *, decltype(DropdownWidget::pNames)>, "API_Verifier: 'std::is_same_v<const char *const *, decltype(DropdownWidget::pNames)>' evaluated to false.");

static_assert(alignof( decltype(DropdownWidget::mCount)) == 4, "API_Verifier: 'alignof( decltype(DropdownWidget::mCount)) == 4' evaluated to false.");
static_assert(offsetof( DropdownWidget, mCount) == 16, "API_Verifier: 'offsetof( DropdownWidget, mCount) == 16' evaluated to false.");
static_assert(sizeof(DropdownWidget::mCount) == 4, "API_Verifier: 'sizeof(DropdownWidget::mCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DropdownWidget::mCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DropdownWidget::mCount)>' evaluated to false.");

static_assert(alignof(ProgressBarWidget) == 8, "API_Verifier: 'alignof(ProgressBarWidget) == 8' evaluated to false.");
static_assert(sizeof(ProgressBarWidget) == 16, "API_Verifier: 'sizeof(ProgressBarWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(ProgressBarWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(ProgressBarWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( ProgressBarWidget, pData) == 0, "API_Verifier: 'offsetof( ProgressBarWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(ProgressBarWidget::pData) == 8, "API_Verifier: 'sizeof(ProgressBarWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<size_t*, decltype(ProgressBarWidget::pData)>, "API_Verifier: 'std::is_same_v<size_t*, decltype(ProgressBarWidget::pData)>' evaluated to false.");

static_assert(alignof( decltype(ProgressBarWidget::mMaxProgress)) == 8, "API_Verifier: 'alignof( decltype(ProgressBarWidget::mMaxProgress)) == 8' evaluated to false.");
static_assert(offsetof( ProgressBarWidget, mMaxProgress) == 8, "API_Verifier: 'offsetof( ProgressBarWidget, mMaxProgress) == 8' evaluated to false.");
static_assert(sizeof(ProgressBarWidget::mMaxProgress) == 8, "API_Verifier: 'sizeof(ProgressBarWidget::mMaxProgress) == 8' evaluated to false.");
static_assert(std::is_same_v<size_t, decltype(ProgressBarWidget::mMaxProgress)>, "API_Verifier: 'std::is_same_v<size_t, decltype(ProgressBarWidget::mMaxProgress)>' evaluated to false.");

static_assert(alignof(ColorSliderWidget) == 8, "API_Verifier: 'alignof(ColorSliderWidget) == 8' evaluated to false.");
static_assert(sizeof(ColorSliderWidget) == 8, "API_Verifier: 'sizeof(ColorSliderWidget) == 8' evaluated to false.");

static_assert(alignof( decltype(ColorSliderWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(ColorSliderWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( ColorSliderWidget, pData) == 0, "API_Verifier: 'offsetof( ColorSliderWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(ColorSliderWidget::pData) == 8, "API_Verifier: 'sizeof(ColorSliderWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4*, decltype(ColorSliderWidget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float4*, decltype(ColorSliderWidget::pData)>' evaluated to false.");

static_assert(alignof(HistogramWidget) == 8, "API_Verifier: 'alignof(HistogramWidget) == 8' evaluated to false.");
static_assert(sizeof(HistogramWidget) == 48, "API_Verifier: 'sizeof(HistogramWidget) == 48' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::pValues)) == 8, "API_Verifier: 'alignof( decltype(HistogramWidget::pValues)) == 8' evaluated to false.");
static_assert(offsetof( HistogramWidget, pValues) == 0, "API_Verifier: 'offsetof( HistogramWidget, pValues) == 0' evaluated to false.");
static_assert(sizeof(HistogramWidget::pValues) == 8, "API_Verifier: 'sizeof(HistogramWidget::pValues) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(HistogramWidget::pValues)>, "API_Verifier: 'std::is_same_v<float *, decltype(HistogramWidget::pValues)>' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::mCount)) == 4, "API_Verifier: 'alignof( decltype(HistogramWidget::mCount)) == 4' evaluated to false.");
static_assert(offsetof( HistogramWidget, mCount) == 8, "API_Verifier: 'offsetof( HistogramWidget, mCount) == 8' evaluated to false.");
static_assert(sizeof(HistogramWidget::mCount) == 4, "API_Verifier: 'sizeof(HistogramWidget::mCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(HistogramWidget::mCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(HistogramWidget::mCount)>' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::mMinScale)) == 8, "API_Verifier: 'alignof( decltype(HistogramWidget::mMinScale)) == 8' evaluated to false.");
static_assert(offsetof( HistogramWidget, mMinScale) == 16, "API_Verifier: 'offsetof( HistogramWidget, mMinScale) == 16' evaluated to false.");
static_assert(sizeof(HistogramWidget::mMinScale) == 8, "API_Verifier: 'sizeof(HistogramWidget::mMinScale) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(HistogramWidget::mMinScale)>, "API_Verifier: 'std::is_same_v<float *, decltype(HistogramWidget::mMinScale)>' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::mMaxScale)) == 8, "API_Verifier: 'alignof( decltype(HistogramWidget::mMaxScale)) == 8' evaluated to false.");
static_assert(offsetof( HistogramWidget, mMaxScale) == 24, "API_Verifier: 'offsetof( HistogramWidget, mMaxScale) == 24' evaluated to false.");
static_assert(sizeof(HistogramWidget::mMaxScale) == 8, "API_Verifier: 'sizeof(HistogramWidget::mMaxScale) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(HistogramWidget::mMaxScale)>, "API_Verifier: 'std::is_same_v<float *, decltype(HistogramWidget::mMaxScale)>' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::mHistogramSize)) == 4, "API_Verifier: 'alignof( decltype(HistogramWidget::mHistogramSize)) == 4' evaluated to false.");
static_assert(offsetof( HistogramWidget, mHistogramSize) == 32, "API_Verifier: 'offsetof( HistogramWidget, mHistogramSize) == 32' evaluated to false.");
static_assert(sizeof(HistogramWidget::mHistogramSize) == 8, "API_Verifier: 'sizeof(HistogramWidget::mHistogramSize) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(HistogramWidget::mHistogramSize)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(HistogramWidget::mHistogramSize)>' evaluated to false.");

static_assert(alignof( decltype(HistogramWidget::mHistogramTitle)) == 8, "API_Verifier: 'alignof( decltype(HistogramWidget::mHistogramTitle)) == 8' evaluated to false.");
static_assert(offsetof( HistogramWidget, mHistogramTitle) == 40, "API_Verifier: 'offsetof( HistogramWidget, mHistogramTitle) == 40' evaluated to false.");
static_assert(sizeof(HistogramWidget::mHistogramTitle) == 8, "API_Verifier: 'sizeof(HistogramWidget::mHistogramTitle) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(HistogramWidget::mHistogramTitle)>, "API_Verifier: 'std::is_same_v<const char *, decltype(HistogramWidget::mHistogramTitle)>' evaluated to false.");

static_assert(alignof(PlotLinesWidget) == 8, "API_Verifier: 'alignof(PlotLinesWidget) == 8' evaluated to false.");
static_assert(sizeof(PlotLinesWidget) == 48, "API_Verifier: 'sizeof(PlotLinesWidget) == 48' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mValues)) == 8, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mValues)) == 8' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mValues) == 0, "API_Verifier: 'offsetof( PlotLinesWidget, mValues) == 0' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mValues) == 8, "API_Verifier: 'sizeof(PlotLinesWidget::mValues) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(PlotLinesWidget::mValues)>, "API_Verifier: 'std::is_same_v<float *, decltype(PlotLinesWidget::mValues)>' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mNumValues)) == 4, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mNumValues)) == 4' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mNumValues) == 8, "API_Verifier: 'offsetof( PlotLinesWidget, mNumValues) == 8' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mNumValues) == 4, "API_Verifier: 'sizeof(PlotLinesWidget::mNumValues) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PlotLinesWidget::mNumValues)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PlotLinesWidget::mNumValues)>' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mScaleMin)) == 8, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mScaleMin)) == 8' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mScaleMin) == 16, "API_Verifier: 'offsetof( PlotLinesWidget, mScaleMin) == 16' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mScaleMin) == 8, "API_Verifier: 'sizeof(PlotLinesWidget::mScaleMin) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(PlotLinesWidget::mScaleMin)>, "API_Verifier: 'std::is_same_v<float *, decltype(PlotLinesWidget::mScaleMin)>' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mScaleMax)) == 8, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mScaleMax)) == 8' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mScaleMax) == 24, "API_Verifier: 'offsetof( PlotLinesWidget, mScaleMax) == 24' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mScaleMax) == 8, "API_Verifier: 'sizeof(PlotLinesWidget::mScaleMax) == 8' evaluated to false.");
static_assert(std::is_same_v<float *, decltype(PlotLinesWidget::mScaleMax)>, "API_Verifier: 'std::is_same_v<float *, decltype(PlotLinesWidget::mScaleMax)>' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mPlotScale)) == 8, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mPlotScale)) == 8' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mPlotScale) == 32, "API_Verifier: 'offsetof( PlotLinesWidget, mPlotScale) == 32' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mPlotScale) == 8, "API_Verifier: 'sizeof(PlotLinesWidget::mPlotScale) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2*, decltype(PlotLinesWidget::mPlotScale)>, "API_Verifier: 'std::is_same_v<Vectormath::float2*, decltype(PlotLinesWidget::mPlotScale)>' evaluated to false.");

static_assert(alignof( decltype(PlotLinesWidget::mTitle)) == 8, "API_Verifier: 'alignof( decltype(PlotLinesWidget::mTitle)) == 8' evaluated to false.");
static_assert(offsetof( PlotLinesWidget, mTitle) == 40, "API_Verifier: 'offsetof( PlotLinesWidget, mTitle) == 40' evaluated to false.");
static_assert(sizeof(PlotLinesWidget::mTitle) == 8, "API_Verifier: 'sizeof(PlotLinesWidget::mTitle) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(PlotLinesWidget::mTitle)>, "API_Verifier: 'std::is_same_v<const char *, decltype(PlotLinesWidget::mTitle)>' evaluated to false.");

static_assert(alignof(ColorPickerWidget) == 8, "API_Verifier: 'alignof(ColorPickerWidget) == 8' evaluated to false.");
static_assert(sizeof(ColorPickerWidget) == 8, "API_Verifier: 'sizeof(ColorPickerWidget) == 8' evaluated to false.");

static_assert(alignof( decltype(ColorPickerWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(ColorPickerWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( ColorPickerWidget, pData) == 0, "API_Verifier: 'offsetof( ColorPickerWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(ColorPickerWidget::pData) == 8, "API_Verifier: 'sizeof(ColorPickerWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4*, decltype(ColorPickerWidget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float4*, decltype(ColorPickerWidget::pData)>' evaluated to false.");

static_assert(alignof(Color3PickerWidget) == 8, "API_Verifier: 'alignof(Color3PickerWidget) == 8' evaluated to false.");
static_assert(sizeof(Color3PickerWidget) == 8, "API_Verifier: 'sizeof(Color3PickerWidget) == 8' evaluated to false.");

static_assert(alignof( decltype(Color3PickerWidget::pData)) == 8, "API_Verifier: 'alignof( decltype(Color3PickerWidget::pData)) == 8' evaluated to false.");
static_assert(offsetof( Color3PickerWidget, pData) == 0, "API_Verifier: 'offsetof( Color3PickerWidget, pData) == 0' evaluated to false.");
static_assert(sizeof(Color3PickerWidget::pData) == 8, "API_Verifier: 'sizeof(Color3PickerWidget::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3*, decltype(Color3PickerWidget::pData)>, "API_Verifier: 'std::is_same_v<Vectormath::float3*, decltype(Color3PickerWidget::pData)>' evaluated to false.");

static_assert(alignof(TextboxWidget) == 8, "API_Verifier: 'alignof(TextboxWidget) == 8' evaluated to false.");
static_assert(sizeof(TextboxWidget) == 24, "API_Verifier: 'sizeof(TextboxWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(TextboxWidget::pText)) == 8, "API_Verifier: 'alignof( decltype(TextboxWidget::pText)) == 8' evaluated to false.");
static_assert(offsetof( TextboxWidget, pText) == 0, "API_Verifier: 'offsetof( TextboxWidget, pText) == 0' evaluated to false.");
static_assert(sizeof(TextboxWidget::pText) == 8, "API_Verifier: 'sizeof(TextboxWidget::pText) == 8' evaluated to false.");
static_assert(std::is_same_v<bstring*, decltype(TextboxWidget::pText)>, "API_Verifier: 'std::is_same_v<bstring*, decltype(TextboxWidget::pText)>' evaluated to false.");

static_assert(alignof( decltype(TextboxWidget::mFlags)) == 1, "API_Verifier: 'alignof( decltype(TextboxWidget::mFlags)) == 1' evaluated to false.");
static_assert(offsetof( TextboxWidget, mFlags) == 8, "API_Verifier: 'offsetof( TextboxWidget, mFlags) == 8' evaluated to false.");
static_assert(sizeof(TextboxWidget::mFlags) == 1, "API_Verifier: 'sizeof(TextboxWidget::mFlags) == 1' evaluated to false.");
static_assert(std::is_same_v<unsigned char, decltype(TextboxWidget::mFlags)>, "API_Verifier: 'std::is_same_v<unsigned char, decltype(TextboxWidget::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(TextboxWidget::pCallback)) == 8, "API_Verifier: 'alignof( decltype(TextboxWidget::pCallback)) == 8' evaluated to false.");
static_assert(offsetof( TextboxWidget, pCallback) == 16, "API_Verifier: 'offsetof( TextboxWidget, pCallback) == 16' evaluated to false.");
static_assert(sizeof(TextboxWidget::pCallback) == 8, "API_Verifier: 'sizeof(TextboxWidget::pCallback) == 8' evaluated to false.");
static_assert(std::is_same_v<TextboxCallback, decltype(TextboxWidget::pCallback)>, "API_Verifier: 'std::is_same_v<TextboxCallback, decltype(TextboxWidget::pCallback)>' evaluated to false.");

static_assert(alignof(DynamicTextWidget) == 8, "API_Verifier: 'alignof(DynamicTextWidget) == 8' evaluated to false.");
static_assert(sizeof(DynamicTextWidget) == 24, "API_Verifier: 'sizeof(DynamicTextWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(DynamicTextWidget::pText)) == 8, "API_Verifier: 'alignof( decltype(DynamicTextWidget::pText)) == 8' evaluated to false.");
static_assert(offsetof( DynamicTextWidget, pText) == 0, "API_Verifier: 'offsetof( DynamicTextWidget, pText) == 0' evaluated to false.");
static_assert(sizeof(DynamicTextWidget::pText) == 8, "API_Verifier: 'sizeof(DynamicTextWidget::pText) == 8' evaluated to false.");
static_assert(std::is_same_v<bstring*, decltype(DynamicTextWidget::pText)>, "API_Verifier: 'std::is_same_v<bstring*, decltype(DynamicTextWidget::pText)>' evaluated to false.");

static_assert(alignof( decltype(DynamicTextWidget::pColor)) == 8, "API_Verifier: 'alignof( decltype(DynamicTextWidget::pColor)) == 8' evaluated to false.");
static_assert(offsetof( DynamicTextWidget, pColor) == 8, "API_Verifier: 'offsetof( DynamicTextWidget, pColor) == 8' evaluated to false.");
static_assert(sizeof(DynamicTextWidget::pColor) == 8, "API_Verifier: 'sizeof(DynamicTextWidget::pColor) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4*, decltype(DynamicTextWidget::pColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4*, decltype(DynamicTextWidget::pColor)>' evaluated to false.");

static_assert(alignof( decltype(DynamicTextWidget::mFlags)) == 1, "API_Verifier: 'alignof( decltype(DynamicTextWidget::mFlags)) == 1' evaluated to false.");
static_assert(offsetof( DynamicTextWidget, mFlags) == 16, "API_Verifier: 'offsetof( DynamicTextWidget, mFlags) == 16' evaluated to false.");
static_assert(sizeof(DynamicTextWidget::mFlags) == 1, "API_Verifier: 'sizeof(DynamicTextWidget::mFlags) == 1' evaluated to false.");
static_assert(std::is_same_v<unsigned char, decltype(DynamicTextWidget::mFlags)>, "API_Verifier: 'std::is_same_v<unsigned char, decltype(DynamicTextWidget::mFlags)>' evaluated to false.");

static_assert(alignof(FilledRectWidget) == 4, "API_Verifier: 'alignof(FilledRectWidget) == 4' evaluated to false.");
static_assert(sizeof(FilledRectWidget) == 32, "API_Verifier: 'sizeof(FilledRectWidget) == 32' evaluated to false.");

static_assert(alignof( decltype(FilledRectWidget::mPos)) == 4, "API_Verifier: 'alignof( decltype(FilledRectWidget::mPos)) == 4' evaluated to false.");
static_assert(offsetof( FilledRectWidget, mPos) == 0, "API_Verifier: 'offsetof( FilledRectWidget, mPos) == 0' evaluated to false.");
static_assert(sizeof(FilledRectWidget::mPos) == 8, "API_Verifier: 'sizeof(FilledRectWidget::mPos) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(FilledRectWidget::mPos)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(FilledRectWidget::mPos)>' evaluated to false.");

static_assert(alignof( decltype(FilledRectWidget::mScale)) == 4, "API_Verifier: 'alignof( decltype(FilledRectWidget::mScale)) == 4' evaluated to false.");
static_assert(offsetof( FilledRectWidget, mScale) == 8, "API_Verifier: 'offsetof( FilledRectWidget, mScale) == 8' evaluated to false.");
static_assert(sizeof(FilledRectWidget::mScale) == 8, "API_Verifier: 'sizeof(FilledRectWidget::mScale) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(FilledRectWidget::mScale)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(FilledRectWidget::mScale)>' evaluated to false.");

static_assert(alignof( decltype(FilledRectWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(FilledRectWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( FilledRectWidget, mColor) == 16, "API_Verifier: 'offsetof( FilledRectWidget, mColor) == 16' evaluated to false.");
static_assert(sizeof(FilledRectWidget::mColor) == 16, "API_Verifier: 'sizeof(FilledRectWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(FilledRectWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(FilledRectWidget::mColor)>' evaluated to false.");

static_assert(alignof(DrawTextWidget) == 4, "API_Verifier: 'alignof(DrawTextWidget) == 4' evaluated to false.");
static_assert(sizeof(DrawTextWidget) == 24, "API_Verifier: 'sizeof(DrawTextWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(DrawTextWidget::mPos)) == 4, "API_Verifier: 'alignof( decltype(DrawTextWidget::mPos)) == 4' evaluated to false.");
static_assert(offsetof( DrawTextWidget, mPos) == 0, "API_Verifier: 'offsetof( DrawTextWidget, mPos) == 0' evaluated to false.");
static_assert(sizeof(DrawTextWidget::mPos) == 8, "API_Verifier: 'sizeof(DrawTextWidget::mPos) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(DrawTextWidget::mPos)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(DrawTextWidget::mPos)>' evaluated to false.");

static_assert(alignof( decltype(DrawTextWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(DrawTextWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( DrawTextWidget, mColor) == 8, "API_Verifier: 'offsetof( DrawTextWidget, mColor) == 8' evaluated to false.");
static_assert(sizeof(DrawTextWidget::mColor) == 16, "API_Verifier: 'sizeof(DrawTextWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(DrawTextWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(DrawTextWidget::mColor)>' evaluated to false.");

static_assert(alignof(DrawTooltipWidget) == 8, "API_Verifier: 'alignof(DrawTooltipWidget) == 8' evaluated to false.");
static_assert(sizeof(DrawTooltipWidget) == 16, "API_Verifier: 'sizeof(DrawTooltipWidget) == 16' evaluated to false.");

static_assert(alignof( decltype(DrawTooltipWidget::mShowTooltip)) == 8, "API_Verifier: 'alignof( decltype(DrawTooltipWidget::mShowTooltip)) == 8' evaluated to false.");
static_assert(offsetof( DrawTooltipWidget, mShowTooltip) == 0, "API_Verifier: 'offsetof( DrawTooltipWidget, mShowTooltip) == 0' evaluated to false.");
static_assert(sizeof(DrawTooltipWidget::mShowTooltip) == 8, "API_Verifier: 'sizeof(DrawTooltipWidget::mShowTooltip) == 8' evaluated to false.");
static_assert(std::is_same_v<bool *, decltype(DrawTooltipWidget::mShowTooltip)>, "API_Verifier: 'std::is_same_v<bool *, decltype(DrawTooltipWidget::mShowTooltip)>' evaluated to false.");

static_assert(alignof( decltype(DrawTooltipWidget::mText)) == 8, "API_Verifier: 'alignof( decltype(DrawTooltipWidget::mText)) == 8' evaluated to false.");
static_assert(offsetof( DrawTooltipWidget, mText) == 8, "API_Verifier: 'offsetof( DrawTooltipWidget, mText) == 8' evaluated to false.");
static_assert(sizeof(DrawTooltipWidget::mText) == 8, "API_Verifier: 'sizeof(DrawTooltipWidget::mText) == 8' evaluated to false.");
static_assert(std::is_same_v<char *, decltype(DrawTooltipWidget::mText)>, "API_Verifier: 'std::is_same_v<char *, decltype(DrawTooltipWidget::mText)>' evaluated to false.");

static_assert(alignof(DrawLineWidget) == 4, "API_Verifier: 'alignof(DrawLineWidget) == 4' evaluated to false.");
static_assert(sizeof(DrawLineWidget) == 36, "API_Verifier: 'sizeof(DrawLineWidget) == 36' evaluated to false.");

static_assert(alignof( decltype(DrawLineWidget::mPos1)) == 4, "API_Verifier: 'alignof( decltype(DrawLineWidget::mPos1)) == 4' evaluated to false.");
static_assert(offsetof( DrawLineWidget, mPos1) == 0, "API_Verifier: 'offsetof( DrawLineWidget, mPos1) == 0' evaluated to false.");
static_assert(sizeof(DrawLineWidget::mPos1) == 8, "API_Verifier: 'sizeof(DrawLineWidget::mPos1) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(DrawLineWidget::mPos1)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(DrawLineWidget::mPos1)>' evaluated to false.");

static_assert(alignof( decltype(DrawLineWidget::mPos2)) == 4, "API_Verifier: 'alignof( decltype(DrawLineWidget::mPos2)) == 4' evaluated to false.");
static_assert(offsetof( DrawLineWidget, mPos2) == 8, "API_Verifier: 'offsetof( DrawLineWidget, mPos2) == 8' evaluated to false.");
static_assert(sizeof(DrawLineWidget::mPos2) == 8, "API_Verifier: 'sizeof(DrawLineWidget::mPos2) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(DrawLineWidget::mPos2)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(DrawLineWidget::mPos2)>' evaluated to false.");

static_assert(alignof( decltype(DrawLineWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(DrawLineWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( DrawLineWidget, mColor) == 16, "API_Verifier: 'offsetof( DrawLineWidget, mColor) == 16' evaluated to false.");
static_assert(sizeof(DrawLineWidget::mColor) == 16, "API_Verifier: 'sizeof(DrawLineWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(DrawLineWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(DrawLineWidget::mColor)>' evaluated to false.");

static_assert(alignof( decltype(DrawLineWidget::mAddItem)) == 1, "API_Verifier: 'alignof( decltype(DrawLineWidget::mAddItem)) == 1' evaluated to false.");
static_assert(offsetof( DrawLineWidget, mAddItem) == 32, "API_Verifier: 'offsetof( DrawLineWidget, mAddItem) == 32' evaluated to false.");
static_assert(sizeof(DrawLineWidget::mAddItem) == 1, "API_Verifier: 'sizeof(DrawLineWidget::mAddItem) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(DrawLineWidget::mAddItem)>, "API_Verifier: 'std::is_same_v<bool, decltype(DrawLineWidget::mAddItem)>' evaluated to false.");

static_assert(alignof(DrawCurveWidget) == 8, "API_Verifier: 'alignof(DrawCurveWidget) == 8' evaluated to false.");
static_assert(sizeof(DrawCurveWidget) == 32, "API_Verifier: 'sizeof(DrawCurveWidget) == 32' evaluated to false.");

static_assert(alignof( decltype(DrawCurveWidget::mPos)) == 8, "API_Verifier: 'alignof( decltype(DrawCurveWidget::mPos)) == 8' evaluated to false.");
static_assert(offsetof( DrawCurveWidget, mPos) == 0, "API_Verifier: 'offsetof( DrawCurveWidget, mPos) == 0' evaluated to false.");
static_assert(sizeof(DrawCurveWidget::mPos) == 8, "API_Verifier: 'sizeof(DrawCurveWidget::mPos) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2*, decltype(DrawCurveWidget::mPos)>, "API_Verifier: 'std::is_same_v<Vectormath::float2*, decltype(DrawCurveWidget::mPos)>' evaluated to false.");

static_assert(alignof( decltype(DrawCurveWidget::mNumPoints)) == 4, "API_Verifier: 'alignof( decltype(DrawCurveWidget::mNumPoints)) == 4' evaluated to false.");
static_assert(offsetof( DrawCurveWidget, mNumPoints) == 8, "API_Verifier: 'offsetof( DrawCurveWidget, mNumPoints) == 8' evaluated to false.");
static_assert(sizeof(DrawCurveWidget::mNumPoints) == 4, "API_Verifier: 'sizeof(DrawCurveWidget::mNumPoints) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(DrawCurveWidget::mNumPoints)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(DrawCurveWidget::mNumPoints)>' evaluated to false.");

static_assert(alignof( decltype(DrawCurveWidget::mThickness)) == 4, "API_Verifier: 'alignof( decltype(DrawCurveWidget::mThickness)) == 4' evaluated to false.");
static_assert(offsetof( DrawCurveWidget, mThickness) == 12, "API_Verifier: 'offsetof( DrawCurveWidget, mThickness) == 12' evaluated to false.");
static_assert(sizeof(DrawCurveWidget::mThickness) == 4, "API_Verifier: 'sizeof(DrawCurveWidget::mThickness) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(DrawCurveWidget::mThickness)>, "API_Verifier: 'std::is_same_v<float, decltype(DrawCurveWidget::mThickness)>' evaluated to false.");

static_assert(alignof( decltype(DrawCurveWidget::mColor)) == 4, "API_Verifier: 'alignof( decltype(DrawCurveWidget::mColor)) == 4' evaluated to false.");
static_assert(offsetof( DrawCurveWidget, mColor) == 16, "API_Verifier: 'offsetof( DrawCurveWidget, mColor) == 16' evaluated to false.");
static_assert(sizeof(DrawCurveWidget::mColor) == 16, "API_Verifier: 'sizeof(DrawCurveWidget::mColor) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(DrawCurveWidget::mColor)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(DrawCurveWidget::mColor)>' evaluated to false.");

static_assert(alignof(CustomWidget) == 8, "API_Verifier: 'alignof(CustomWidget) == 8' evaluated to false.");
static_assert(sizeof(CustomWidget) == 24, "API_Verifier: 'sizeof(CustomWidget) == 24' evaluated to false.");

static_assert(alignof( decltype(CustomWidget::pUserData)) == 8, "API_Verifier: 'alignof( decltype(CustomWidget::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( CustomWidget, pUserData) == 0, "API_Verifier: 'offsetof( CustomWidget, pUserData) == 0' evaluated to false.");
static_assert(sizeof(CustomWidget::pUserData) == 8, "API_Verifier: 'sizeof(CustomWidget::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(CustomWidget::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(CustomWidget::pUserData)>' evaluated to false.");

static_assert(alignof( decltype(CustomWidget::pCallback)) == 8, "API_Verifier: 'alignof( decltype(CustomWidget::pCallback)) == 8' evaluated to false.");
static_assert(offsetof( CustomWidget, pCallback) == 8, "API_Verifier: 'offsetof( CustomWidget, pCallback) == 8' evaluated to false.");
static_assert(sizeof(CustomWidget::pCallback) == 8, "API_Verifier: 'sizeof(CustomWidget::pCallback) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(CustomWidget::pCallback)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(CustomWidget::pCallback)>' evaluated to false.");

static_assert(alignof( decltype(CustomWidget::pDestroyCallback)) == 8, "API_Verifier: 'alignof( decltype(CustomWidget::pDestroyCallback)) == 8' evaluated to false.");
static_assert(offsetof( CustomWidget, pDestroyCallback) == 16, "API_Verifier: 'offsetof( CustomWidget, pDestroyCallback) == 16' evaluated to false.");
static_assert(sizeof(CustomWidget::pDestroyCallback) == 8, "API_Verifier: 'sizeof(CustomWidget::pDestroyCallback) == 8' evaluated to false.");
static_assert(std::is_same_v<WidgetCallback, decltype(CustomWidget::pDestroyCallback)>, "API_Verifier: 'std::is_same_v<WidgetCallback, decltype(CustomWidget::pDestroyCallback)>' evaluated to false.");

static_assert(alignof(UIComponentDesc) == 4, "API_Verifier: 'alignof(UIComponentDesc) == 4' evaluated to false.");
static_assert(sizeof(UIComponentDesc) == 24, "API_Verifier: 'sizeof(UIComponentDesc) == 24' evaluated to false.");

static_assert(alignof( decltype(UIComponentDesc::mStartPosition)) == 4, "API_Verifier: 'alignof( decltype(UIComponentDesc::mStartPosition)) == 4' evaluated to false.");
static_assert(offsetof( UIComponentDesc, mStartPosition) == 0, "API_Verifier: 'offsetof( UIComponentDesc, mStartPosition) == 0' evaluated to false.");
static_assert(sizeof(UIComponentDesc::mStartPosition) == 8, "API_Verifier: 'sizeof(UIComponentDesc::mStartPosition) == 8' evaluated to false.");
static_assert(std::is_same_v<vec2, decltype(UIComponentDesc::mStartPosition)>, "API_Verifier: 'std::is_same_v<vec2, decltype(UIComponentDesc::mStartPosition)>' evaluated to false.");

static_assert(alignof( decltype(UIComponentDesc::mStartSize)) == 4, "API_Verifier: 'alignof( decltype(UIComponentDesc::mStartSize)) == 4' evaluated to false.");
static_assert(offsetof( UIComponentDesc, mStartSize) == 8, "API_Verifier: 'offsetof( UIComponentDesc, mStartSize) == 8' evaluated to false.");
static_assert(sizeof(UIComponentDesc::mStartSize) == 8, "API_Verifier: 'sizeof(UIComponentDesc::mStartSize) == 8' evaluated to false.");
static_assert(std::is_same_v<vec2, decltype(UIComponentDesc::mStartSize)>, "API_Verifier: 'std::is_same_v<vec2, decltype(UIComponentDesc::mStartSize)>' evaluated to false.");

static_assert(alignof( decltype(UIComponentDesc::mFontID)) == 4, "API_Verifier: 'alignof( decltype(UIComponentDesc::mFontID)) == 4' evaluated to false.");
static_assert(offsetof( UIComponentDesc, mFontID) == 16, "API_Verifier: 'offsetof( UIComponentDesc, mFontID) == 16' evaluated to false.");
static_assert(sizeof(UIComponentDesc::mFontID) == 4, "API_Verifier: 'sizeof(UIComponentDesc::mFontID) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UIComponentDesc::mFontID)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UIComponentDesc::mFontID)>' evaluated to false.");

static_assert(alignof( decltype(UIComponentDesc::mFontSize)) == 4, "API_Verifier: 'alignof( decltype(UIComponentDesc::mFontSize)) == 4' evaluated to false.");
static_assert(offsetof( UIComponentDesc, mFontSize) == 20, "API_Verifier: 'offsetof( UIComponentDesc, mFontSize) == 20' evaluated to false.");
static_assert(sizeof(UIComponentDesc::mFontSize) == 4, "API_Verifier: 'sizeof(UIComponentDesc::mFontSize) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(UIComponentDesc::mFontSize)>, "API_Verifier: 'std::is_same_v<float, decltype(UIComponentDesc::mFontSize)>' evaluated to false.");

static_assert(alignof(UIComponent) == 8, "API_Verifier: 'alignof(UIComponent) == 8' evaluated to false.");
static_assert(sizeof(UIComponent) == 248, "API_Verifier: 'sizeof(UIComponent) == 248' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mWidgets)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::mWidgets)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, mWidgets) == 0, "API_Verifier: 'offsetof( UIComponent, mWidgets) == 0' evaluated to false.");
static_assert(sizeof(UIComponent::mWidgets) == 8, "API_Verifier: 'sizeof(UIComponent::mWidgets) == 8' evaluated to false.");
static_assert(std::is_same_v<UIWidget **, decltype(UIComponent::mWidgets)>, "API_Verifier: 'std::is_same_v<UIWidget **, decltype(UIComponent::mWidgets)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mWidgetsClone)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::mWidgetsClone)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, mWidgetsClone) == 8, "API_Verifier: 'offsetof( UIComponent, mWidgetsClone) == 8' evaluated to false.");
static_assert(sizeof(UIComponent::mWidgetsClone) == 8, "API_Verifier: 'sizeof(UIComponent::mWidgetsClone) == 8' evaluated to false.");
static_assert(std::is_same_v<bool *, decltype(UIComponent::mWidgetsClone)>, "API_Verifier: 'std::is_same_v<bool *, decltype(UIComponent::mWidgetsClone)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::pUserData)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, pUserData) == 16, "API_Verifier: 'offsetof( UIComponent, pUserData) == 16' evaluated to false.");
static_assert(sizeof(UIComponent::pUserData) == 8, "API_Verifier: 'sizeof(UIComponent::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(UIComponent::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(UIComponent::pUserData)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mContextualMenuLabels)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::mContextualMenuLabels)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, mContextualMenuLabels) == 24, "API_Verifier: 'offsetof( UIComponent, mContextualMenuLabels) == 24' evaluated to false.");
static_assert(sizeof(UIComponent::mContextualMenuLabels) == 8, "API_Verifier: 'sizeof(UIComponent::mContextualMenuLabels) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *const *, decltype(UIComponent::mContextualMenuLabels)>, "API_Verifier: 'std::is_same_v<const char *const *, decltype(UIComponent::mContextualMenuLabels)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mContextualMenuCallbacks)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::mContextualMenuCallbacks)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, mContextualMenuCallbacks) == 32, "API_Verifier: 'offsetof( UIComponent, mContextualMenuCallbacks) == 32' evaluated to false.");
static_assert(sizeof(UIComponent::mContextualMenuCallbacks) == 8, "API_Verifier: 'sizeof(UIComponent::mContextualMenuCallbacks) == 8' evaluated to false.");
static_assert(std::is_same_v<const WidgetCallback*, decltype(UIComponent::mContextualMenuCallbacks)>, "API_Verifier: 'std::is_same_v<const WidgetCallback*, decltype(UIComponent::mContextualMenuCallbacks)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mContextualMenuCount)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::mContextualMenuCount)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, mContextualMenuCount) == 40, "API_Verifier: 'offsetof( UIComponent, mContextualMenuCount) == 40' evaluated to false.");
static_assert(sizeof(UIComponent::mContextualMenuCount) == 8, "API_Verifier: 'sizeof(UIComponent::mContextualMenuCount) == 8' evaluated to false.");
static_assert(std::is_same_v<size_t, decltype(UIComponent::mContextualMenuCount)>, "API_Verifier: 'std::is_same_v<size_t, decltype(UIComponent::mContextualMenuCount)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mInitialWindowRect)) == 4, "API_Verifier: 'alignof( decltype(UIComponent::mInitialWindowRect)) == 4' evaluated to false.");
static_assert(offsetof( UIComponent, mInitialWindowRect) == 48, "API_Verifier: 'offsetof( UIComponent, mInitialWindowRect) == 48' evaluated to false.");
static_assert(sizeof(UIComponent::mInitialWindowRect) == 16, "API_Verifier: 'sizeof(UIComponent::mInitialWindowRect) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(UIComponent::mInitialWindowRect)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(UIComponent::mInitialWindowRect)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mCurrentWindowRect)) == 4, "API_Verifier: 'alignof( decltype(UIComponent::mCurrentWindowRect)) == 4' evaluated to false.");
static_assert(offsetof( UIComponent, mCurrentWindowRect) == 64, "API_Verifier: 'offsetof( UIComponent, mCurrentWindowRect) == 64' evaluated to false.");
static_assert(sizeof(UIComponent::mCurrentWindowRect) == 16, "API_Verifier: 'sizeof(UIComponent::mCurrentWindowRect) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(UIComponent::mCurrentWindowRect)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(UIComponent::mCurrentWindowRect)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mTitle)) == 1, "API_Verifier: 'alignof( decltype(UIComponent::mTitle)) == 1' evaluated to false.");
static_assert(offsetof( UIComponent, mTitle) == 80, "API_Verifier: 'offsetof( UIComponent, mTitle) == 80' evaluated to false.");
static_assert(sizeof(UIComponent::mTitle) == 128, "API_Verifier: 'sizeof(UIComponent::mTitle) == 128' evaluated to false.");
static_assert(std::is_same_v<char[128], decltype(UIComponent::mTitle)>, "API_Verifier: 'std::is_same_v<char[128], decltype(UIComponent::mTitle)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::pFont)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::pFont)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, pFont) == 208, "API_Verifier: 'offsetof( UIComponent, pFont) == 208' evaluated to false.");
static_assert(sizeof(UIComponent::pFont) == 8, "API_Verifier: 'sizeof(UIComponent::pFont) == 8' evaluated to false.");
static_assert(std::is_same_v<uintptr_t, decltype(UIComponent::pFont)>, "API_Verifier: 'std::is_same_v<uintptr_t, decltype(UIComponent::pFont)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mFontTextureIndex)) == 4, "API_Verifier: 'alignof( decltype(UIComponent::mFontTextureIndex)) == 4' evaluated to false.");
static_assert(offsetof( UIComponent, mFontTextureIndex) == 216, "API_Verifier: 'offsetof( UIComponent, mFontTextureIndex) == 216' evaluated to false.");
static_assert(sizeof(UIComponent::mFontTextureIndex) == 4, "API_Verifier: 'sizeof(UIComponent::mFontTextureIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UIComponent::mFontTextureIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UIComponent::mFontTextureIndex)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mAlpha)) == 4, "API_Verifier: 'alignof( decltype(UIComponent::mAlpha)) == 4' evaluated to false.");
static_assert(offsetof( UIComponent, mAlpha) == 220, "API_Verifier: 'offsetof( UIComponent, mAlpha) == 220' evaluated to false.");
static_assert(sizeof(UIComponent::mAlpha) == 4, "API_Verifier: 'sizeof(UIComponent::mAlpha) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(UIComponent::mAlpha)>, "API_Verifier: 'std::is_same_v<float, decltype(UIComponent::mAlpha)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mFlags)) == 4, "API_Verifier: 'alignof( decltype(UIComponent::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( UIComponent, mFlags) == 224, "API_Verifier: 'offsetof( UIComponent, mFlags) == 224' evaluated to false.");
static_assert(sizeof(UIComponent::mFlags) == 4, "API_Verifier: 'sizeof(UIComponent::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(UIComponent::mFlags)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(UIComponent::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mActive)) == 1, "API_Verifier: 'alignof( decltype(UIComponent::mActive)) == 1' evaluated to false.");
static_assert(offsetof( UIComponent, mActive) == 228, "API_Verifier: 'offsetof( UIComponent, mActive) == 228' evaluated to false.");
static_assert(sizeof(UIComponent::mActive) == 1, "API_Verifier: 'sizeof(UIComponent::mActive) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIComponent::mActive)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIComponent::mActive)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::mHasCloseButton)) == 1, "API_Verifier: 'alignof( decltype(UIComponent::mHasCloseButton)) == 1' evaluated to false.");
static_assert(offsetof( UIComponent, mHasCloseButton) == 229, "API_Verifier: 'offsetof( UIComponent, mHasCloseButton) == 229' evaluated to false.");
static_assert(sizeof(UIComponent::mHasCloseButton) == 1, "API_Verifier: 'sizeof(UIComponent::mHasCloseButton) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UIComponent::mHasCloseButton)>, "API_Verifier: 'std::is_same_v<bool, decltype(UIComponent::mHasCloseButton)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::pPreProcessCallback)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::pPreProcessCallback)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, pPreProcessCallback) == 232, "API_Verifier: 'offsetof( UIComponent, pPreProcessCallback) == 232' evaluated to false.");
static_assert(sizeof(UIComponent::pPreProcessCallback) == 8, "API_Verifier: 'sizeof(UIComponent::pPreProcessCallback) == 8' evaluated to false.");
static_assert(std::is_same_v<WindowCallback, decltype(UIComponent::pPreProcessCallback)>, "API_Verifier: 'std::is_same_v<WindowCallback, decltype(UIComponent::pPreProcessCallback)>' evaluated to false.");

static_assert(alignof( decltype(UIComponent::pPostProcessCallback)) == 8, "API_Verifier: 'alignof( decltype(UIComponent::pPostProcessCallback)) == 8' evaluated to false.");
static_assert(offsetof( UIComponent, pPostProcessCallback) == 240, "API_Verifier: 'offsetof( UIComponent, pPostProcessCallback) == 240' evaluated to false.");
static_assert(sizeof(UIComponent::pPostProcessCallback) == 8, "API_Verifier: 'sizeof(UIComponent::pPostProcessCallback) == 8' evaluated to false.");
static_assert(std::is_same_v<WindowCallback, decltype(UIComponent::pPostProcessCallback)>, "API_Verifier: 'std::is_same_v<WindowCallback, decltype(UIComponent::pPostProcessCallback)>' evaluated to false.");

static_assert(alignof(DynamicUIWidgets) == 8, "API_Verifier: 'alignof(DynamicUIWidgets) == 8' evaluated to false.");
static_assert(sizeof(DynamicUIWidgets) == 8, "API_Verifier: 'sizeof(DynamicUIWidgets) == 8' evaluated to false.");

static_assert(alignof( decltype(DynamicUIWidgets::mDynamicProperties)) == 8, "API_Verifier: 'alignof( decltype(DynamicUIWidgets::mDynamicProperties)) == 8' evaluated to false.");
static_assert(offsetof( DynamicUIWidgets, mDynamicProperties) == 0, "API_Verifier: 'offsetof( DynamicUIWidgets, mDynamicProperties) == 0' evaluated to false.");
static_assert(sizeof(DynamicUIWidgets::mDynamicProperties) == 8, "API_Verifier: 'sizeof(DynamicUIWidgets::mDynamicProperties) == 8' evaluated to false.");
static_assert(std::is_same_v<UIWidget **, decltype(DynamicUIWidgets::mDynamicProperties)>, "API_Verifier: 'std::is_same_v<UIWidget **, decltype(DynamicUIWidgets::mDynamicProperties)>' evaluated to false.");

static_assert(alignof(UserInterfaceDesc) == 8, "API_Verifier: 'alignof(UserInterfaceDesc) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc) == 40, "API_Verifier: 'sizeof(UserInterfaceDesc) == 40' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::pRenderer)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::pRenderer)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, pRenderer) == 0, "API_Verifier: 'offsetof( UserInterfaceDesc, pRenderer) == 0' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::pRenderer) == 8, "API_Verifier: 'sizeof(UserInterfaceDesc::pRenderer) == 8' evaluated to false.");
static_assert(std::is_same_v<Renderer*, decltype(UserInterfaceDesc::pRenderer)>, "API_Verifier: 'std::is_same_v<Renderer*, decltype(UserInterfaceDesc::pRenderer)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::pCache)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::pCache)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, pCache) == 8, "API_Verifier: 'offsetof( UserInterfaceDesc, pCache) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::pCache) == 8, "API_Verifier: 'sizeof(UserInterfaceDesc::pCache) == 8' evaluated to false.");
static_assert(std::is_same_v<PipelineCache*, decltype(UserInterfaceDesc::pCache)>, "API_Verifier: 'std::is_same_v<PipelineCache*, decltype(UserInterfaceDesc::pCache)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mSettingsFilename)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mSettingsFilename)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mSettingsFilename) == 16, "API_Verifier: 'offsetof( UserInterfaceDesc, mSettingsFilename) == 16' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mSettingsFilename) == 8, "API_Verifier: 'sizeof(UserInterfaceDesc::mSettingsFilename) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(UserInterfaceDesc::mSettingsFilename)>, "API_Verifier: 'std::is_same_v<const char *, decltype(UserInterfaceDesc::mSettingsFilename)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mMaxDynamicUIUpdatesPerBatch) == 24, "API_Verifier: 'offsetof( UserInterfaceDesc, mMaxDynamicUIUpdatesPerBatch) == 24' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch) == 4, "API_Verifier: 'sizeof(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mMaxDynamicUIUpdatesPerBatch)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mMaxUIFonts)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mMaxUIFonts)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mMaxUIFonts) == 28, "API_Verifier: 'offsetof( UserInterfaceDesc, mMaxUIFonts) == 28' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mMaxUIFonts) == 4, "API_Verifier: 'sizeof(UserInterfaceDesc::mMaxUIFonts) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mMaxUIFonts)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mMaxUIFonts)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mFrameCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mFrameCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mFrameCount) == 32, "API_Verifier: 'offsetof( UserInterfaceDesc, mFrameCount) == 32' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mFrameCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDesc::mFrameCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mFrameCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDesc::mFrameCount)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mEnableDocking)) == 1, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mEnableDocking)) == 1' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mEnableDocking) == 36, "API_Verifier: 'offsetof( UserInterfaceDesc, mEnableDocking) == 36' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mEnableDocking) == 1, "API_Verifier: 'sizeof(UserInterfaceDesc::mEnableDocking) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UserInterfaceDesc::mEnableDocking)>, "API_Verifier: 'std::is_same_v<bool, decltype(UserInterfaceDesc::mEnableDocking)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDesc::mEnableRemoteUI)) == 1, "API_Verifier: 'alignof( decltype(UserInterfaceDesc::mEnableRemoteUI)) == 1' evaluated to false.");
static_assert(offsetof( UserInterfaceDesc, mEnableRemoteUI) == 37, "API_Verifier: 'offsetof( UserInterfaceDesc, mEnableRemoteUI) == 37' evaluated to false.");
static_assert(sizeof(UserInterfaceDesc::mEnableRemoteUI) == 1, "API_Verifier: 'sizeof(UserInterfaceDesc::mEnableRemoteUI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(UserInterfaceDesc::mEnableRemoteUI)>, "API_Verifier: 'std::is_same_v<bool, decltype(UserInterfaceDesc::mEnableRemoteUI)>' evaluated to false.");

static_assert(alignof(UserInterfaceLoadDesc) == 8, "API_Verifier: 'alignof(UserInterfaceLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc) == 32, "API_Verifier: 'sizeof(UserInterfaceLoadDesc) == 32' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::pCache)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::pCache)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, pCache) == 0, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, pCache) == 0' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::pCache) == 8, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::pCache) == 8' evaluated to false.");
static_assert(std::is_same_v<PipelineCache*, decltype(UserInterfaceLoadDesc::pCache)>, "API_Verifier: 'std::is_same_v<PipelineCache*, decltype(UserInterfaceLoadDesc::pCache)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mLoadType)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mLoadType)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mLoadType) == 8, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mLoadType) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mLoadType) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mLoadType) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mLoadType)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mLoadType)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mColorFormat)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mColorFormat)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mColorFormat) == 12, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mColorFormat) == 12' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mColorFormat) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mColorFormat) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mColorFormat)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mColorFormat)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mWidth)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mWidth) == 16, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mWidth) == 16' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mWidth) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mHeight)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mHeight) == 20, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mHeight) == 20' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mHeight) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mHeight)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mDisplayWidth)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mDisplayWidth)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mDisplayWidth) == 24, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mDisplayWidth) == 24' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mDisplayWidth) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mDisplayWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mDisplayWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mDisplayWidth)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceLoadDesc::mDisplayHeight)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceLoadDesc::mDisplayHeight)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceLoadDesc, mDisplayHeight) == 28, "API_Verifier: 'offsetof( UserInterfaceLoadDesc, mDisplayHeight) == 28' evaluated to false.");
static_assert(sizeof(UserInterfaceLoadDesc::mDisplayHeight) == 4, "API_Verifier: 'sizeof(UserInterfaceLoadDesc::mDisplayHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mDisplayHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceLoadDesc::mDisplayHeight)>' evaluated to false.");

static_assert(alignof(UserInterfaceDrawCommand) == 8, "API_Verifier: 'alignof(UserInterfaceDrawCommand) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand) == 48, "API_Verifier: 'sizeof(UserInterfaceDrawCommand) == 48' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mClipRect)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mClipRect)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mClipRect) == 0, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mClipRect) == 0' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mClipRect) == 16, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mClipRect) == 16' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float4, decltype(UserInterfaceDrawCommand::mClipRect)>, "API_Verifier: 'std::is_same_v<Vectormath::float4, decltype(UserInterfaceDrawCommand::mClipRect)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mTextureId)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mTextureId)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mTextureId) == 16, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mTextureId) == 16' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mTextureId) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mTextureId) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(UserInterfaceDrawCommand::mTextureId)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(UserInterfaceDrawCommand::mTextureId)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mVertexOffset)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mVertexOffset)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mVertexOffset) == 24, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mVertexOffset) == 24' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mVertexOffset) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mVertexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mVertexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mVertexOffset)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mIndexOffset)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mIndexOffset)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mIndexOffset) == 28, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mIndexOffset) == 28' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mIndexOffset) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mIndexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mIndexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mIndexOffset)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mVertexCount) == 32, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mVertexCount) == 32' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mVertexCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mIndexCount) == 36, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mIndexCount) == 36' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mIndexCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawCommand::mElemCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawCommand::mElemCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawCommand, mElemCount) == 40, "API_Verifier: 'offsetof( UserInterfaceDrawCommand, mElemCount) == 40' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawCommand::mElemCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawCommand::mElemCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mElemCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawCommand::mElemCount)>' evaluated to false.");

static_assert(alignof(UserInterfaceDrawData) == 8, "API_Verifier: 'alignof(UserInterfaceDrawData) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData) == 64, "API_Verifier: 'sizeof(UserInterfaceDrawData) == 64' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mVertexCount) == 0, "API_Verifier: 'offsetof( UserInterfaceDrawData, mVertexCount) == 0' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mVertexCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawData::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mIndexCount) == 4, "API_Verifier: 'offsetof( UserInterfaceDrawData, mIndexCount) == 4' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mIndexCount) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawData::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mVertexSize)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mVertexSize)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mVertexSize) == 8, "API_Verifier: 'offsetof( UserInterfaceDrawData, mVertexSize) == 8' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mVertexSize) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawData::mVertexSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mVertexSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mVertexSize)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mIndexSize)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mIndexSize)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mIndexSize) == 12, "API_Verifier: 'offsetof( UserInterfaceDrawData, mIndexSize) == 12' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mIndexSize) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawData::mIndexSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mIndexSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mIndexSize)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mDisplayPos)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mDisplayPos)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mDisplayPos) == 16, "API_Verifier: 'offsetof( UserInterfaceDrawData, mDisplayPos) == 16' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mDisplayPos) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawData::mDisplayPos) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(UserInterfaceDrawData::mDisplayPos)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(UserInterfaceDrawData::mDisplayPos)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mDisplaySize)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mDisplaySize)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mDisplaySize) == 24, "API_Verifier: 'offsetof( UserInterfaceDrawData, mDisplaySize) == 24' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mDisplaySize) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawData::mDisplaySize) == 8' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float2, decltype(UserInterfaceDrawData::mDisplaySize)>, "API_Verifier: 'std::is_same_v<Vectormath::float2, decltype(UserInterfaceDrawData::mDisplaySize)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mNumDrawCommands)) == 4, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mNumDrawCommands)) == 4' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mNumDrawCommands) == 32, "API_Verifier: 'offsetof( UserInterfaceDrawData, mNumDrawCommands) == 32' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mNumDrawCommands) == 4, "API_Verifier: 'sizeof(UserInterfaceDrawData::mNumDrawCommands) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mNumDrawCommands)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UserInterfaceDrawData::mNumDrawCommands)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mVertexBufferData)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mVertexBufferData)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mVertexBufferData) == 40, "API_Verifier: 'offsetof( UserInterfaceDrawData, mVertexBufferData) == 40' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mVertexBufferData) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawData::mVertexBufferData) == 8' evaluated to false.");
static_assert(std::is_same_v<unsigned char *, decltype(UserInterfaceDrawData::mVertexBufferData)>, "API_Verifier: 'std::is_same_v<unsigned char *, decltype(UserInterfaceDrawData::mVertexBufferData)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mIndexBufferData)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mIndexBufferData)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mIndexBufferData) == 48, "API_Verifier: 'offsetof( UserInterfaceDrawData, mIndexBufferData) == 48' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mIndexBufferData) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawData::mIndexBufferData) == 8' evaluated to false.");
static_assert(std::is_same_v<unsigned char *, decltype(UserInterfaceDrawData::mIndexBufferData)>, "API_Verifier: 'std::is_same_v<unsigned char *, decltype(UserInterfaceDrawData::mIndexBufferData)>' evaluated to false.");

static_assert(alignof( decltype(UserInterfaceDrawData::mDrawCommands)) == 8, "API_Verifier: 'alignof( decltype(UserInterfaceDrawData::mDrawCommands)) == 8' evaluated to false.");
static_assert(offsetof( UserInterfaceDrawData, mDrawCommands) == 56, "API_Verifier: 'offsetof( UserInterfaceDrawData, mDrawCommands) == 56' evaluated to false.");
static_assert(sizeof(UserInterfaceDrawData::mDrawCommands) == 8, "API_Verifier: 'sizeof(UserInterfaceDrawData::mDrawCommands) == 8' evaluated to false.");
static_assert(std::is_same_v<UserInterfaceDrawCommand*, decltype(UserInterfaceDrawData::mDrawCommands)>, "API_Verifier: 'std::is_same_v<UserInterfaceDrawCommand*, decltype(UserInterfaceDrawData::mDrawCommands)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\OS\Interfaces\IOperatingSystem.h"

static_assert(std::is_same_v<std::underlying_type_t<WindowMode>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<WindowMode>,int>' evaluated to false.");
static_assert(WindowMode::WM_WINDOWED == 0, "API_Verifier: 'WindowMode::WM_WINDOWED == 0' evaluated to false.");
static_assert(WindowMode::WM_FULLSCREEN == 1, "API_Verifier: 'WindowMode::WM_FULLSCREEN == 1' evaluated to false.");
static_assert(WindowMode::WM_BORDERLESS == 2, "API_Verifier: 'WindowMode::WM_BORDERLESS == 2' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<WindowHandleType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<WindowHandleType>,int>' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_UNKNOWN == 0, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_UNKNOWN == 0' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_WIN32 == 1, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_WIN32 == 1' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_XLIB == 2, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_XLIB == 2' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_XCB == 3, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_XCB == 3' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_WAYLAND == 4, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_WAYLAND == 4' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_ANDROID == 5, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_ANDROID == 5' evaluated to false.");
static_assert(WindowHandleType::WINDOW_HANDLE_TYPE_VI_NN == 6, "API_Verifier: 'WindowHandleType::WINDOW_HANDLE_TYPE_VI_NN == 6' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ThermalStatus>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ThermalStatus>,int>' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_MIN == -2, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_MIN == -2' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_NOT_SUPPORTED == -2, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_NOT_SUPPORTED == -2' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_ERROR == -1, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_ERROR == -1' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_NONE == 0, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_NONE == 0' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_LIGHT == 1, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_LIGHT == 1' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_MODERATE == 2, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_MODERATE == 2' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_SEVERE == 3, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_SEVERE == 3' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_CRITICAL == 4, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_CRITICAL == 4' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_EMERGENCY == 5, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_EMERGENCY == 5' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_SHUTDOWN == 6, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_SHUTDOWN == 6' evaluated to false.");
static_assert(ThermalStatus::THERMAL_STATUS_MAX == 7, "API_Verifier: 'ThermalStatus::THERMAL_STATUS_MAX == 7' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ResetType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ResetType>,int>' evaluated to false.");
static_assert(ResetType::RESET_TYPE_NONE == 0, "API_Verifier: 'ResetType::RESET_TYPE_NONE == 0' evaluated to false.");
static_assert(ResetType::RESET_TYPE_API_SWITCH == 1, "API_Verifier: 'ResetType::RESET_TYPE_API_SWITCH == 1' evaluated to false.");
static_assert(ResetType::RESET_TYPE_GRAPHIC_CARD_SWITCH == 2, "API_Verifier: 'ResetType::RESET_TYPE_GRAPHIC_CARD_SWITCH == 2' evaluated to false.");
static_assert(ResetType::RESET_TYPE_DEVICE_LOST == 4, "API_Verifier: 'ResetType::RESET_TYPE_DEVICE_LOST == 4' evaluated to false.");
static_assert(ResetType::RESET_TYPE_GPU_MODE_SWITCH == 8, "API_Verifier: 'ResetType::RESET_TYPE_GPU_MODE_SWITCH == 8' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<ReloadType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<ReloadType>,int>' evaluated to false.");
static_assert(ReloadType::RELOAD_TYPE_RESIZE == 1, "API_Verifier: 'ReloadType::RELOAD_TYPE_RESIZE == 1' evaluated to false.");
static_assert(ReloadType::RELOAD_TYPE_SHADER == 2, "API_Verifier: 'ReloadType::RELOAD_TYPE_SHADER == 2' evaluated to false.");
static_assert(ReloadType::RELOAD_TYPE_RENDERTARGET == 4, "API_Verifier: 'ReloadType::RELOAD_TYPE_RENDERTARGET == 4' evaluated to false.");
static_assert(ReloadType::RELOAD_TYPE_ALL == -1, "API_Verifier: 'ReloadType::RELOAD_TYPE_ALL == -1' evaluated to false.");
static_assert(ReloadType::RELOAD_TYPE_COUNT == 3, "API_Verifier: 'ReloadType::RELOAD_TYPE_COUNT == 3' evaluated to false.");

static_assert(alignof(RectDesc) == 4, "API_Verifier: 'alignof(RectDesc) == 4' evaluated to false.");
static_assert(sizeof(RectDesc) == 16, "API_Verifier: 'sizeof(RectDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(RectDesc::left)) == 4, "API_Verifier: 'alignof( decltype(RectDesc::left)) == 4' evaluated to false.");
static_assert(offsetof( RectDesc, left) == 0, "API_Verifier: 'offsetof( RectDesc, left) == 0' evaluated to false.");
static_assert(sizeof(RectDesc::left) == 4, "API_Verifier: 'sizeof(RectDesc::left) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RectDesc::left)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RectDesc::left)>' evaluated to false.");

static_assert(alignof( decltype(RectDesc::top)) == 4, "API_Verifier: 'alignof( decltype(RectDesc::top)) == 4' evaluated to false.");
static_assert(offsetof( RectDesc, top) == 4, "API_Verifier: 'offsetof( RectDesc, top) == 4' evaluated to false.");
static_assert(sizeof(RectDesc::top) == 4, "API_Verifier: 'sizeof(RectDesc::top) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RectDesc::top)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RectDesc::top)>' evaluated to false.");

static_assert(alignof( decltype(RectDesc::right)) == 4, "API_Verifier: 'alignof( decltype(RectDesc::right)) == 4' evaluated to false.");
static_assert(offsetof( RectDesc, right) == 8, "API_Verifier: 'offsetof( RectDesc, right) == 8' evaluated to false.");
static_assert(sizeof(RectDesc::right) == 4, "API_Verifier: 'sizeof(RectDesc::right) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RectDesc::right)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RectDesc::right)>' evaluated to false.");

static_assert(alignof( decltype(RectDesc::bottom)) == 4, "API_Verifier: 'alignof( decltype(RectDesc::bottom)) == 4' evaluated to false.");
static_assert(offsetof( RectDesc, bottom) == 12, "API_Verifier: 'offsetof( RectDesc, bottom) == 12' evaluated to false.");
static_assert(sizeof(RectDesc::bottom) == 4, "API_Verifier: 'sizeof(RectDesc::bottom) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(RectDesc::bottom)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(RectDesc::bottom)>' evaluated to false.");

static_assert(alignof(WindowHandle) == 8, "API_Verifier: 'alignof(WindowHandle) == 8' evaluated to false.");
static_assert(sizeof(WindowHandle) == 16, "API_Verifier: 'sizeof(WindowHandle) == 16' evaluated to false.");

static_assert(alignof( decltype(WindowHandle::type)) == 4, "API_Verifier: 'alignof( decltype(WindowHandle::type)) == 4' evaluated to false.");
static_assert(offsetof( WindowHandle, type) == 0, "API_Verifier: 'offsetof( WindowHandle, type) == 0' evaluated to false.");
static_assert(sizeof(WindowHandle::type) == 4, "API_Verifier: 'sizeof(WindowHandle::type) == 4' evaluated to false.");
static_assert(std::is_same_v<WindowHandleType, decltype(WindowHandle::type)>, "API_Verifier: 'std::is_same_v<WindowHandleType, decltype(WindowHandle::type)>' evaluated to false.");

static_assert(alignof( decltype(WindowHandle::window)) == 8, "API_Verifier: 'alignof( decltype(WindowHandle::window)) == 8' evaluated to false.");
static_assert(offsetof( WindowHandle, window) == 8, "API_Verifier: 'offsetof( WindowHandle, window) == 8' evaluated to false.");
static_assert(sizeof(WindowHandle::window) == 8, "API_Verifier: 'sizeof(WindowHandle::window) == 8' evaluated to false.");
static_assert(std::is_same_v<HWND, decltype(WindowHandle::window)>, "API_Verifier: 'std::is_same_v<HWND, decltype(WindowHandle::window)>' evaluated to false.");

static_assert(alignof(WindowDesc) == 8, "API_Verifier: 'alignof(WindowDesc) == 8' evaluated to false.");
static_assert(sizeof(WindowDesc) == 608, "API_Verifier: 'sizeof(WindowDesc) == 608' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::handle)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::handle)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, handle) == 0, "API_Verifier: 'offsetof( WindowDesc, handle) == 0' evaluated to false.");
static_assert(sizeof(WindowDesc::handle) == 16, "API_Verifier: 'sizeof(WindowDesc::handle) == 16' evaluated to false.");
static_assert(std::is_same_v<WindowHandle, decltype(WindowDesc::handle)>, "API_Verifier: 'std::is_same_v<WindowHandle, decltype(WindowDesc::handle)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::windowedRect)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::windowedRect)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, windowedRect) == 16, "API_Verifier: 'offsetof( WindowDesc, windowedRect) == 16' evaluated to false.");
static_assert(sizeof(WindowDesc::windowedRect) == 16, "API_Verifier: 'sizeof(WindowDesc::windowedRect) == 16' evaluated to false.");
static_assert(std::is_same_v<RectDesc, decltype(WindowDesc::windowedRect)>, "API_Verifier: 'std::is_same_v<RectDesc, decltype(WindowDesc::windowedRect)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::fullscreenRect)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::fullscreenRect)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, fullscreenRect) == 32, "API_Verifier: 'offsetof( WindowDesc, fullscreenRect) == 32' evaluated to false.");
static_assert(sizeof(WindowDesc::fullscreenRect) == 16, "API_Verifier: 'sizeof(WindowDesc::fullscreenRect) == 16' evaluated to false.");
static_assert(std::is_same_v<RectDesc, decltype(WindowDesc::fullscreenRect)>, "API_Verifier: 'std::is_same_v<RectDesc, decltype(WindowDesc::fullscreenRect)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::clientRect)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::clientRect)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, clientRect) == 48, "API_Verifier: 'offsetof( WindowDesc, clientRect) == 48' evaluated to false.");
static_assert(sizeof(WindowDesc::clientRect) == 16, "API_Verifier: 'sizeof(WindowDesc::clientRect) == 16' evaluated to false.");
static_assert(std::is_same_v<RectDesc, decltype(WindowDesc::clientRect)>, "API_Verifier: 'std::is_same_v<RectDesc, decltype(WindowDesc::clientRect)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::windowsFlags)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::windowsFlags)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, windowsFlags) == 64, "API_Verifier: 'offsetof( WindowDesc, windowsFlags) == 64' evaluated to false.");
static_assert(sizeof(WindowDesc::windowsFlags) == 4, "API_Verifier: 'sizeof(WindowDesc::windowsFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(WindowDesc::windowsFlags)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(WindowDesc::windowsFlags)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::fullScreen)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::fullScreen)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, fullScreen) == 68, "API_Verifier: 'offsetof( WindowDesc, fullScreen) == 68' evaluated to false.");
static_assert(sizeof(WindowDesc::fullScreen) == 1, "API_Verifier: 'sizeof(WindowDesc::fullScreen) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::fullScreen)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::fullScreen)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::cursorCaptured)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::cursorCaptured)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, cursorCaptured) == 69, "API_Verifier: 'offsetof( WindowDesc, cursorCaptured) == 69' evaluated to false.");
static_assert(sizeof(WindowDesc::cursorCaptured) == 1, "API_Verifier: 'sizeof(WindowDesc::cursorCaptured) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::cursorCaptured)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::cursorCaptured)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::iconified)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::iconified)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, iconified) == 70, "API_Verifier: 'offsetof( WindowDesc, iconified) == 70' evaluated to false.");
static_assert(sizeof(WindowDesc::iconified) == 1, "API_Verifier: 'sizeof(WindowDesc::iconified) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::iconified)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::iconified)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::maximized)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::maximized)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, maximized) == 71, "API_Verifier: 'offsetof( WindowDesc, maximized) == 71' evaluated to false.");
static_assert(sizeof(WindowDesc::maximized) == 1, "API_Verifier: 'sizeof(WindowDesc::maximized) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::maximized)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::maximized)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::minimized)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::minimized)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, minimized) == 72, "API_Verifier: 'offsetof( WindowDesc, minimized) == 72' evaluated to false.");
static_assert(sizeof(WindowDesc::minimized) == 1, "API_Verifier: 'sizeof(WindowDesc::minimized) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::minimized)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::minimized)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::hide)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::hide)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, hide) == 73, "API_Verifier: 'offsetof( WindowDesc, hide) == 73' evaluated to false.");
static_assert(sizeof(WindowDesc::hide) == 1, "API_Verifier: 'sizeof(WindowDesc::hide) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::hide)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::hide)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::noresizeFrame)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::noresizeFrame)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, noresizeFrame) == 74, "API_Verifier: 'offsetof( WindowDesc, noresizeFrame) == 74' evaluated to false.");
static_assert(sizeof(WindowDesc::noresizeFrame) == 1, "API_Verifier: 'sizeof(WindowDesc::noresizeFrame) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::noresizeFrame)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::noresizeFrame)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::borderlessWindow)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::borderlessWindow)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, borderlessWindow) == 75, "API_Verifier: 'offsetof( WindowDesc, borderlessWindow) == 75' evaluated to false.");
static_assert(sizeof(WindowDesc::borderlessWindow) == 1, "API_Verifier: 'sizeof(WindowDesc::borderlessWindow) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::borderlessWindow)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::borderlessWindow)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::overrideDefaultPosition)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::overrideDefaultPosition)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, overrideDefaultPosition) == 76, "API_Verifier: 'offsetof( WindowDesc, overrideDefaultPosition) == 76' evaluated to false.");
static_assert(sizeof(WindowDesc::overrideDefaultPosition) == 1, "API_Verifier: 'sizeof(WindowDesc::overrideDefaultPosition) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::overrideDefaultPosition)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::overrideDefaultPosition)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::centered)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::centered)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, centered) == 77, "API_Verifier: 'offsetof( WindowDesc, centered) == 77' evaluated to false.");
static_assert(sizeof(WindowDesc::centered) == 1, "API_Verifier: 'sizeof(WindowDesc::centered) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::centered)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::centered)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::forceLowDPI)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::forceLowDPI)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, forceLowDPI) == 78, "API_Verifier: 'offsetof( WindowDesc, forceLowDPI) == 78' evaluated to false.");
static_assert(sizeof(WindowDesc::forceLowDPI) == 1, "API_Verifier: 'sizeof(WindowDesc::forceLowDPI) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::forceLowDPI)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::forceLowDPI)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mWindowMode)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mWindowMode)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mWindowMode) == 80, "API_Verifier: 'offsetof( WindowDesc, mWindowMode) == 80' evaluated to false.");
static_assert(sizeof(WindowDesc::mWindowMode) == 4, "API_Verifier: 'sizeof(WindowDesc::mWindowMode) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mWindowMode)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mWindowMode)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pCurRes)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::pCurRes)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, pCurRes) == 84, "API_Verifier: 'offsetof( WindowDesc, pCurRes) == 84' evaluated to false.");
static_assert(sizeof(WindowDesc::pCurRes) == 128, "API_Verifier: 'sizeof(WindowDesc::pCurRes) == 128' evaluated to false.");
static_assert(std::is_same_v<int32_t[32], decltype(WindowDesc::pCurRes)>, "API_Verifier: 'std::is_same_v<int32_t[32], decltype(WindowDesc::pCurRes)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pLastRes)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::pLastRes)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, pLastRes) == 212, "API_Verifier: 'offsetof( WindowDesc, pLastRes) == 212' evaluated to false.");
static_assert(sizeof(WindowDesc::pLastRes) == 128, "API_Verifier: 'sizeof(WindowDesc::pLastRes) == 128' evaluated to false.");
static_assert(std::is_same_v<int32_t[32], decltype(WindowDesc::pLastRes)>, "API_Verifier: 'std::is_same_v<int32_t[32], decltype(WindowDesc::pLastRes)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mWndX)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mWndX)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mWndX) == 340, "API_Verifier: 'offsetof( WindowDesc, mWndX) == 340' evaluated to false.");
static_assert(sizeof(WindowDesc::mWndX) == 4, "API_Verifier: 'sizeof(WindowDesc::mWndX) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mWndX)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mWndX)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mWndY)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mWndY)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mWndY) == 344, "API_Verifier: 'offsetof( WindowDesc, mWndY) == 344' evaluated to false.");
static_assert(sizeof(WindowDesc::mWndY) == 4, "API_Verifier: 'sizeof(WindowDesc::mWndY) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mWndY)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mWndY)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mWndW)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mWndW)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mWndW) == 348, "API_Verifier: 'offsetof( WindowDesc, mWndW) == 348' evaluated to false.");
static_assert(sizeof(WindowDesc::mWndW) == 4, "API_Verifier: 'sizeof(WindowDesc::mWndW) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mWndW)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mWndW)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mWndH)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mWndH)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mWndH) == 352, "API_Verifier: 'offsetof( WindowDesc, mWndH) == 352' evaluated to false.");
static_assert(sizeof(WindowDesc::mWndH) == 4, "API_Verifier: 'sizeof(WindowDesc::mWndH) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mWndH)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mWndH)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mCursorHidden)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::mCursorHidden)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, mCursorHidden) == 356, "API_Verifier: 'offsetof( WindowDesc, mCursorHidden) == 356' evaluated to false.");
static_assert(sizeof(WindowDesc::mCursorHidden) == 1, "API_Verifier: 'sizeof(WindowDesc::mCursorHidden) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::mCursorHidden)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::mCursorHidden)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mCursorInsideWindow)) == 4, "API_Verifier: 'alignof( decltype(WindowDesc::mCursorInsideWindow)) == 4' evaluated to false.");
static_assert(offsetof( WindowDesc, mCursorInsideWindow) == 360, "API_Verifier: 'offsetof( WindowDesc, mCursorInsideWindow) == 360' evaluated to false.");
static_assert(sizeof(WindowDesc::mCursorInsideWindow) == 4, "API_Verifier: 'sizeof(WindowDesc::mCursorInsideWindow) == 4' evaluated to false.");
static_assert(std::is_same_v<int32_t, decltype(WindowDesc::mCursorInsideWindow)>, "API_Verifier: 'std::is_same_v<int32_t, decltype(WindowDesc::mCursorInsideWindow)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mCursorCaptured)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::mCursorCaptured)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, mCursorCaptured) == 364, "API_Verifier: 'offsetof( WindowDesc, mCursorCaptured) == 364' evaluated to false.");
static_assert(sizeof(WindowDesc::mCursorCaptured) == 1, "API_Verifier: 'sizeof(WindowDesc::mCursorCaptured) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::mCursorCaptured)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::mCursorCaptured)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::mMinimizeRequested)) == 1, "API_Verifier: 'alignof( decltype(WindowDesc::mMinimizeRequested)) == 1' evaluated to false.");
static_assert(offsetof( WindowDesc, mMinimizeRequested) == 365, "API_Verifier: 'offsetof( WindowDesc, mMinimizeRequested) == 365' evaluated to false.");
static_assert(sizeof(WindowDesc::mMinimizeRequested) == 1, "API_Verifier: 'sizeof(WindowDesc::mMinimizeRequested) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(WindowDesc::mMinimizeRequested)>, "API_Verifier: 'std::is_same_v<bool, decltype(WindowDesc::mMinimizeRequested)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pWindowedRectLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pWindowedRectLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pWindowedRectLabel) == 368, "API_Verifier: 'offsetof( WindowDesc, pWindowedRectLabel) == 368' evaluated to false.");
static_assert(sizeof(WindowDesc::pWindowedRectLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pWindowedRectLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pWindowedRectLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pWindowedRectLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pFullscreenRectLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pFullscreenRectLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pFullscreenRectLabel) == 384, "API_Verifier: 'offsetof( WindowDesc, pFullscreenRectLabel) == 384' evaluated to false.");
static_assert(sizeof(WindowDesc::pFullscreenRectLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pFullscreenRectLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pFullscreenRectLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pFullscreenRectLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pClientRectLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pClientRectLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pClientRectLabel) == 400, "API_Verifier: 'offsetof( WindowDesc, pClientRectLabel) == 400' evaluated to false.");
static_assert(sizeof(WindowDesc::pClientRectLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pClientRectLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pClientRectLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pClientRectLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pWndLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pWndLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pWndLabel) == 416, "API_Verifier: 'offsetof( WindowDesc, pWndLabel) == 416' evaluated to false.");
static_assert(sizeof(WindowDesc::pWndLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pWndLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pWndLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pWndLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pFullscreenLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pFullscreenLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pFullscreenLabel) == 432, "API_Verifier: 'offsetof( WindowDesc, pFullscreenLabel) == 432' evaluated to false.");
static_assert(sizeof(WindowDesc::pFullscreenLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pFullscreenLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pFullscreenLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pFullscreenLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pCursorCapturedLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pCursorCapturedLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pCursorCapturedLabel) == 448, "API_Verifier: 'offsetof( WindowDesc, pCursorCapturedLabel) == 448' evaluated to false.");
static_assert(sizeof(WindowDesc::pCursorCapturedLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pCursorCapturedLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pCursorCapturedLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pCursorCapturedLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pIconifiedLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pIconifiedLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pIconifiedLabel) == 464, "API_Verifier: 'offsetof( WindowDesc, pIconifiedLabel) == 464' evaluated to false.");
static_assert(sizeof(WindowDesc::pIconifiedLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pIconifiedLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pIconifiedLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pIconifiedLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pMaximizedLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pMaximizedLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pMaximizedLabel) == 480, "API_Verifier: 'offsetof( WindowDesc, pMaximizedLabel) == 480' evaluated to false.");
static_assert(sizeof(WindowDesc::pMaximizedLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pMaximizedLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pMaximizedLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pMaximizedLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pMinimizedLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pMinimizedLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pMinimizedLabel) == 496, "API_Verifier: 'offsetof( WindowDesc, pMinimizedLabel) == 496' evaluated to false.");
static_assert(sizeof(WindowDesc::pMinimizedLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pMinimizedLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pMinimizedLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pMinimizedLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pNoResizeFrameLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pNoResizeFrameLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pNoResizeFrameLabel) == 512, "API_Verifier: 'offsetof( WindowDesc, pNoResizeFrameLabel) == 512' evaluated to false.");
static_assert(sizeof(WindowDesc::pNoResizeFrameLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pNoResizeFrameLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pNoResizeFrameLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pNoResizeFrameLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pBorderlessWindowLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pBorderlessWindowLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pBorderlessWindowLabel) == 528, "API_Verifier: 'offsetof( WindowDesc, pBorderlessWindowLabel) == 528' evaluated to false.");
static_assert(sizeof(WindowDesc::pBorderlessWindowLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pBorderlessWindowLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pBorderlessWindowLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pBorderlessWindowLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pOverrideDefaultPositionLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pOverrideDefaultPositionLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pOverrideDefaultPositionLabel) == 544, "API_Verifier: 'offsetof( WindowDesc, pOverrideDefaultPositionLabel) == 544' evaluated to false.");
static_assert(sizeof(WindowDesc::pOverrideDefaultPositionLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pOverrideDefaultPositionLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pOverrideDefaultPositionLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pOverrideDefaultPositionLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pCenteredLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pCenteredLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pCenteredLabel) == 560, "API_Verifier: 'offsetof( WindowDesc, pCenteredLabel) == 560' evaluated to false.");
static_assert(sizeof(WindowDesc::pCenteredLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pCenteredLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pCenteredLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pCenteredLabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pForceLowDPILabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pForceLowDPILabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pForceLowDPILabel) == 576, "API_Verifier: 'offsetof( WindowDesc, pForceLowDPILabel) == 576' evaluated to false.");
static_assert(sizeof(WindowDesc::pForceLowDPILabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pForceLowDPILabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pForceLowDPILabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pForceLowDPILabel)>' evaluated to false.");

static_assert(alignof( decltype(WindowDesc::pWindowModeLabel)) == 8, "API_Verifier: 'alignof( decltype(WindowDesc::pWindowModeLabel)) == 8' evaluated to false.");
static_assert(offsetof( WindowDesc, pWindowModeLabel) == 592, "API_Verifier: 'offsetof( WindowDesc, pWindowModeLabel) == 592' evaluated to false.");
static_assert(sizeof(WindowDesc::pWindowModeLabel) == 16, "API_Verifier: 'sizeof(WindowDesc::pWindowModeLabel) == 16' evaluated to false.");
static_assert(std::is_same_v<bstring, decltype(WindowDesc::pWindowModeLabel)>, "API_Verifier: 'std::is_same_v<bstring, decltype(WindowDesc::pWindowModeLabel)>' evaluated to false.");

static_assert(alignof(Resolution) == 4, "API_Verifier: 'alignof(Resolution) == 4' evaluated to false.");
static_assert(sizeof(Resolution) == 8, "API_Verifier: 'sizeof(Resolution) == 8' evaluated to false.");

static_assert(alignof( decltype(Resolution::mWidth)) == 4, "API_Verifier: 'alignof( decltype(Resolution::mWidth)) == 4' evaluated to false.");
static_assert(offsetof( Resolution, mWidth) == 0, "API_Verifier: 'offsetof( Resolution, mWidth) == 0' evaluated to false.");
static_assert(sizeof(Resolution::mWidth) == 4, "API_Verifier: 'sizeof(Resolution::mWidth) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Resolution::mWidth)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Resolution::mWidth)>' evaluated to false.");

static_assert(alignof( decltype(Resolution::mHeight)) == 4, "API_Verifier: 'alignof( decltype(Resolution::mHeight)) == 4' evaluated to false.");
static_assert(offsetof( Resolution, mHeight) == 4, "API_Verifier: 'offsetof( Resolution, mHeight) == 4' evaluated to false.");
static_assert(sizeof(Resolution::mHeight) == 4, "API_Verifier: 'sizeof(Resolution::mHeight) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Resolution::mHeight)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Resolution::mHeight)>' evaluated to false.");

static_assert(alignof(MonitorDesc) == 8, "API_Verifier: 'alignof(MonitorDesc) == 8' evaluated to false.");
static_assert(sizeof(MonitorDesc) == 712, "API_Verifier: 'sizeof(MonitorDesc) == 712' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::monitorRect)) == 4, "API_Verifier: 'alignof( decltype(MonitorDesc::monitorRect)) == 4' evaluated to false.");
static_assert(offsetof( MonitorDesc, monitorRect) == 0, "API_Verifier: 'offsetof( MonitorDesc, monitorRect) == 0' evaluated to false.");
static_assert(sizeof(MonitorDesc::monitorRect) == 16, "API_Verifier: 'sizeof(MonitorDesc::monitorRect) == 16' evaluated to false.");
static_assert(std::is_same_v<RectDesc, decltype(MonitorDesc::monitorRect)>, "API_Verifier: 'std::is_same_v<RectDesc, decltype(MonitorDesc::monitorRect)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::workRect)) == 4, "API_Verifier: 'alignof( decltype(MonitorDesc::workRect)) == 4' evaluated to false.");
static_assert(offsetof( MonitorDesc, workRect) == 16, "API_Verifier: 'offsetof( MonitorDesc, workRect) == 16' evaluated to false.");
static_assert(sizeof(MonitorDesc::workRect) == 16, "API_Verifier: 'sizeof(MonitorDesc::workRect) == 16' evaluated to false.");
static_assert(std::is_same_v<RectDesc, decltype(MonitorDesc::workRect)>, "API_Verifier: 'std::is_same_v<RectDesc, decltype(MonitorDesc::workRect)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::dpi)) == 4, "API_Verifier: 'alignof( decltype(MonitorDesc::dpi)) == 4' evaluated to false.");
static_assert(offsetof( MonitorDesc, dpi) == 32, "API_Verifier: 'offsetof( MonitorDesc, dpi) == 32' evaluated to false.");
static_assert(sizeof(MonitorDesc::dpi) == 8, "API_Verifier: 'sizeof(MonitorDesc::dpi) == 8' evaluated to false.");
static_assert(std::is_same_v<unsigned int[2], decltype(MonitorDesc::dpi)>, "API_Verifier: 'std::is_same_v<unsigned int[2], decltype(MonitorDesc::dpi)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::physicalSize)) == 4, "API_Verifier: 'alignof( decltype(MonitorDesc::physicalSize)) == 4' evaluated to false.");
static_assert(offsetof( MonitorDesc, physicalSize) == 40, "API_Verifier: 'offsetof( MonitorDesc, physicalSize) == 40' evaluated to false.");
static_assert(sizeof(MonitorDesc::physicalSize) == 8, "API_Verifier: 'sizeof(MonitorDesc::physicalSize) == 8' evaluated to false.");
static_assert(std::is_same_v<unsigned int[2], decltype(MonitorDesc::physicalSize)>, "API_Verifier: 'std::is_same_v<unsigned int[2], decltype(MonitorDesc::physicalSize)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::adapterName)) == 2, "API_Verifier: 'alignof( decltype(MonitorDesc::adapterName)) == 2' evaluated to false.");
static_assert(offsetof( MonitorDesc, adapterName) == 48, "API_Verifier: 'offsetof( MonitorDesc, adapterName) == 48' evaluated to false.");
static_assert(sizeof(MonitorDesc::adapterName) == 64, "API_Verifier: 'sizeof(MonitorDesc::adapterName) == 64' evaluated to false.");
static_assert(std::is_same_v<WCHAR[32], decltype(MonitorDesc::adapterName)>, "API_Verifier: 'std::is_same_v<WCHAR[32], decltype(MonitorDesc::adapterName)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::displayName)) == 2, "API_Verifier: 'alignof( decltype(MonitorDesc::displayName)) == 2' evaluated to false.");
static_assert(offsetof( MonitorDesc, displayName) == 112, "API_Verifier: 'offsetof( MonitorDesc, displayName) == 112' evaluated to false.");
static_assert(sizeof(MonitorDesc::displayName) == 64, "API_Verifier: 'sizeof(MonitorDesc::displayName) == 64' evaluated to false.");
static_assert(std::is_same_v<WCHAR[32], decltype(MonitorDesc::displayName)>, "API_Verifier: 'std::is_same_v<WCHAR[32], decltype(MonitorDesc::displayName)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::publicAdapterName)) == 2, "API_Verifier: 'alignof( decltype(MonitorDesc::publicAdapterName)) == 2' evaluated to false.");
static_assert(offsetof( MonitorDesc, publicAdapterName) == 176, "API_Verifier: 'offsetof( MonitorDesc, publicAdapterName) == 176' evaluated to false.");
static_assert(sizeof(MonitorDesc::publicAdapterName) == 256, "API_Verifier: 'sizeof(MonitorDesc::publicAdapterName) == 256' evaluated to false.");
static_assert(std::is_same_v<WCHAR[128], decltype(MonitorDesc::publicAdapterName)>, "API_Verifier: 'std::is_same_v<WCHAR[128], decltype(MonitorDesc::publicAdapterName)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::publicDisplayName)) == 2, "API_Verifier: 'alignof( decltype(MonitorDesc::publicDisplayName)) == 2' evaluated to false.");
static_assert(offsetof( MonitorDesc, publicDisplayName) == 432, "API_Verifier: 'offsetof( MonitorDesc, publicDisplayName) == 432' evaluated to false.");
static_assert(sizeof(MonitorDesc::publicDisplayName) == 256, "API_Verifier: 'sizeof(MonitorDesc::publicDisplayName) == 256' evaluated to false.");
static_assert(std::is_same_v<WCHAR[128], decltype(MonitorDesc::publicDisplayName)>, "API_Verifier: 'std::is_same_v<WCHAR[128], decltype(MonitorDesc::publicDisplayName)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::resolutions)) == 8, "API_Verifier: 'alignof( decltype(MonitorDesc::resolutions)) == 8' evaluated to false.");
static_assert(offsetof( MonitorDesc, resolutions) == 688, "API_Verifier: 'offsetof( MonitorDesc, resolutions) == 688' evaluated to false.");
static_assert(sizeof(MonitorDesc::resolutions) == 8, "API_Verifier: 'sizeof(MonitorDesc::resolutions) == 8' evaluated to false.");
static_assert(std::is_same_v<Resolution*, decltype(MonitorDesc::resolutions)>, "API_Verifier: 'std::is_same_v<Resolution*, decltype(MonitorDesc::resolutions)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::defaultResolution)) == 4, "API_Verifier: 'alignof( decltype(MonitorDesc::defaultResolution)) == 4' evaluated to false.");
static_assert(offsetof( MonitorDesc, defaultResolution) == 696, "API_Verifier: 'offsetof( MonitorDesc, defaultResolution) == 696' evaluated to false.");
static_assert(sizeof(MonitorDesc::defaultResolution) == 8, "API_Verifier: 'sizeof(MonitorDesc::defaultResolution) == 8' evaluated to false.");
static_assert(std::is_same_v<Resolution, decltype(MonitorDesc::defaultResolution)>, "API_Verifier: 'std::is_same_v<Resolution, decltype(MonitorDesc::defaultResolution)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::modesPruned)) == 1, "API_Verifier: 'alignof( decltype(MonitorDesc::modesPruned)) == 1' evaluated to false.");
static_assert(offsetof( MonitorDesc, modesPruned) == 704, "API_Verifier: 'offsetof( MonitorDesc, modesPruned) == 704' evaluated to false.");
static_assert(sizeof(MonitorDesc::modesPruned) == 1, "API_Verifier: 'sizeof(MonitorDesc::modesPruned) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(MonitorDesc::modesPruned)>, "API_Verifier: 'std::is_same_v<bool, decltype(MonitorDesc::modesPruned)>' evaluated to false.");

static_assert(alignof( decltype(MonitorDesc::modeChanged)) == 1, "API_Verifier: 'alignof( decltype(MonitorDesc::modeChanged)) == 1' evaluated to false.");
static_assert(offsetof( MonitorDesc, modeChanged) == 705, "API_Verifier: 'offsetof( MonitorDesc, modeChanged) == 705' evaluated to false.");
static_assert(sizeof(MonitorDesc::modeChanged) == 1, "API_Verifier: 'sizeof(MonitorDesc::modeChanged) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(MonitorDesc::modeChanged)>, "API_Verifier: 'std::is_same_v<bool, decltype(MonitorDesc::modeChanged)>' evaluated to false.");

static_assert(alignof(ResetDesc) == 4, "API_Verifier: 'alignof(ResetDesc) == 4' evaluated to false.");
static_assert(sizeof(ResetDesc) == 4, "API_Verifier: 'sizeof(ResetDesc) == 4' evaluated to false.");

static_assert(alignof( decltype(ResetDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(ResetDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( ResetDesc, mType) == 0, "API_Verifier: 'offsetof( ResetDesc, mType) == 0' evaluated to false.");
static_assert(sizeof(ResetDesc::mType) == 4, "API_Verifier: 'sizeof(ResetDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<ResetType, decltype(ResetDesc::mType)>, "API_Verifier: 'std::is_same_v<ResetType, decltype(ResetDesc::mType)>' evaluated to false.");

static_assert(alignof(ReloadDesc) == 4, "API_Verifier: 'alignof(ReloadDesc) == 4' evaluated to false.");
static_assert(sizeof(ReloadDesc) == 4, "API_Verifier: 'sizeof(ReloadDesc) == 4' evaluated to false.");

static_assert(alignof( decltype(ReloadDesc::mType)) == 4, "API_Verifier: 'alignof( decltype(ReloadDesc::mType)) == 4' evaluated to false.");
static_assert(offsetof( ReloadDesc, mType) == 0, "API_Verifier: 'offsetof( ReloadDesc, mType) == 0' evaluated to false.");
static_assert(sizeof(ReloadDesc::mType) == 4, "API_Verifier: 'sizeof(ReloadDesc::mType) == 4' evaluated to false.");
static_assert(std::is_same_v<ReloadType, decltype(ReloadDesc::mType)>, "API_Verifier: 'std::is_same_v<ReloadType, decltype(ReloadDesc::mType)>' evaluated to false.");

static_assert(alignof(OSInfo) == 1, "API_Verifier: 'alignof(OSInfo) == 1' evaluated to false.");
static_assert(sizeof(OSInfo) == 768, "API_Verifier: 'sizeof(OSInfo) == 768' evaluated to false.");

static_assert(alignof( decltype(OSInfo::osName)) == 1, "API_Verifier: 'alignof( decltype(OSInfo::osName)) == 1' evaluated to false.");
static_assert(offsetof( OSInfo, osName) == 0, "API_Verifier: 'offsetof( OSInfo, osName) == 0' evaluated to false.");
static_assert(sizeof(OSInfo::osName) == 256, "API_Verifier: 'sizeof(OSInfo::osName) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(OSInfo::osName)>, "API_Verifier: 'std::is_same_v<char[256], decltype(OSInfo::osName)>' evaluated to false.");

static_assert(alignof( decltype(OSInfo::osVersion)) == 1, "API_Verifier: 'alignof( decltype(OSInfo::osVersion)) == 1' evaluated to false.");
static_assert(offsetof( OSInfo, osVersion) == 256, "API_Verifier: 'offsetof( OSInfo, osVersion) == 256' evaluated to false.");
static_assert(sizeof(OSInfo::osVersion) == 256, "API_Verifier: 'sizeof(OSInfo::osVersion) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(OSInfo::osVersion)>, "API_Verifier: 'std::is_same_v<char[256], decltype(OSInfo::osVersion)>' evaluated to false.");

static_assert(alignof( decltype(OSInfo::osDeviceName)) == 1, "API_Verifier: 'alignof( decltype(OSInfo::osDeviceName)) == 1' evaluated to false.");
static_assert(offsetof( OSInfo, osDeviceName) == 512, "API_Verifier: 'offsetof( OSInfo, osDeviceName) == 512' evaluated to false.");
static_assert(sizeof(OSInfo::osDeviceName) == 256, "API_Verifier: 'sizeof(OSInfo::osDeviceName) == 256' evaluated to false.");
static_assert(std::is_same_v<char[256], decltype(OSInfo::osDeviceName)>, "API_Verifier: 'std::is_same_v<char[256], decltype(OSInfo::osDeviceName)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Renderer\Interfaces\IVisibilityBuffer.h"

static_assert(alignof(VisibilityBuffer) == 8, "API_Verifier: 'alignof(VisibilityBuffer) == 8' evaluated to false.");
static_assert(sizeof(VisibilityBuffer) == 40, "API_Verifier: 'sizeof(VisibilityBuffer) == 40' evaluated to false.");

static_assert(alignof( decltype(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer)) == 8, "API_Verifier: 'alignof( decltype(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer)) == 8' evaluated to false.");
static_assert(offsetof( VisibilityBuffer, ppUncompactedDrawArgumentsBuffer) == 0, "API_Verifier: 'offsetof( VisibilityBuffer, ppUncompactedDrawArgumentsBuffer) == 0' evaluated to false.");
static_assert(sizeof(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer) == 8, "API_Verifier: 'sizeof(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppUncompactedDrawArgumentsBuffer)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers)) == 8, "API_Verifier: 'alignof( decltype(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers)) == 8' evaluated to false.");
static_assert(offsetof( VisibilityBuffer, ppFilteredIndirectDrawArgumentsBuffers) == 8, "API_Verifier: 'offsetof( VisibilityBuffer, ppFilteredIndirectDrawArgumentsBuffers) == 8' evaluated to false.");
static_assert(sizeof(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers) == 8, "API_Verifier: 'sizeof(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilteredIndirectDrawArgumentsBuffers)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBuffer::ppFilteredIndexBuffer)) == 8, "API_Verifier: 'alignof( decltype(VisibilityBuffer::ppFilteredIndexBuffer)) == 8' evaluated to false.");
static_assert(offsetof( VisibilityBuffer, ppFilteredIndexBuffer) == 16, "API_Verifier: 'offsetof( VisibilityBuffer, ppFilteredIndexBuffer) == 16' evaluated to false.");
static_assert(sizeof(VisibilityBuffer::ppFilteredIndexBuffer) == 8, "API_Verifier: 'sizeof(VisibilityBuffer::ppFilteredIndexBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilteredIndexBuffer)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilteredIndexBuffer)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBuffer::ppFilterDispatchGroupDataBuffer)) == 8, "API_Verifier: 'alignof( decltype(VisibilityBuffer::ppFilterDispatchGroupDataBuffer)) == 8' evaluated to false.");
static_assert(offsetof( VisibilityBuffer, ppFilterDispatchGroupDataBuffer) == 24, "API_Verifier: 'offsetof( VisibilityBuffer, ppFilterDispatchGroupDataBuffer) == 24' evaluated to false.");
static_assert(sizeof(VisibilityBuffer::ppFilterDispatchGroupDataBuffer) == 8, "API_Verifier: 'sizeof(VisibilityBuffer::ppFilterDispatchGroupDataBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilterDispatchGroupDataBuffer)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppFilterDispatchGroupDataBuffer)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBuffer::ppIndirectDataIndexBuffer)) == 8, "API_Verifier: 'alignof( decltype(VisibilityBuffer::ppIndirectDataIndexBuffer)) == 8' evaluated to false.");
static_assert(offsetof( VisibilityBuffer, ppIndirectDataIndexBuffer) == 32, "API_Verifier: 'offsetof( VisibilityBuffer, ppIndirectDataIndexBuffer) == 32' evaluated to false.");
static_assert(sizeof(VisibilityBuffer::ppIndirectDataIndexBuffer) == 8, "API_Verifier: 'sizeof(VisibilityBuffer::ppIndirectDataIndexBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppIndirectDataIndexBuffer)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(VisibilityBuffer::ppIndirectDataIndexBuffer)>' evaluated to false.");

static_assert(alignof(VisibilityBufferDesc) == 4, "API_Verifier: 'alignof(VisibilityBufferDesc) == 4' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc) == 52, "API_Verifier: 'sizeof(VisibilityBufferDesc) == 52' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mNumFrames)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mNumFrames)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mNumFrames) == 0, "API_Verifier: 'offsetof( VisibilityBufferDesc, mNumFrames) == 0' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mNumFrames) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mNumFrames) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumFrames)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumFrames)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mNumBuffers)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mNumBuffers)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mNumBuffers) == 4, "API_Verifier: 'offsetof( VisibilityBufferDesc, mNumBuffers) == 4' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mNumBuffers) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mNumBuffers) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumBuffers)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumBuffers)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mIndirectElementCount)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mIndirectElementCount)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mIndirectElementCount) == 8, "API_Verifier: 'offsetof( VisibilityBufferDesc, mIndirectElementCount) == 8' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mIndirectElementCount) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mIndirectElementCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mIndirectElementCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mIndirectElementCount)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mDrawArgCount)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mDrawArgCount)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mDrawArgCount) == 12, "API_Verifier: 'offsetof( VisibilityBufferDesc, mDrawArgCount) == 12' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mDrawArgCount) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mDrawArgCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mDrawArgCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mDrawArgCount)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mIndexCount) == 16, "API_Verifier: 'offsetof( VisibilityBufferDesc, mIndexCount) == 16' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mIndexCount) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mMaxDrawsIndirect)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mMaxDrawsIndirect)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mMaxDrawsIndirect) == 20, "API_Verifier: 'offsetof( VisibilityBufferDesc, mMaxDrawsIndirect) == 20' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mMaxDrawsIndirect) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mMaxDrawsIndirect) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mMaxDrawsIndirect)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mMaxDrawsIndirect)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mMaxPrimitivesPerDrawIndirect) == 24, "API_Verifier: 'offsetof( VisibilityBufferDesc, mMaxPrimitivesPerDrawIndirect) == 24' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mMaxPrimitivesPerDrawIndirect)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mComputeThreads)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mComputeThreads)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mComputeThreads) == 28, "API_Verifier: 'offsetof( VisibilityBufferDesc, mComputeThreads) == 28' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mComputeThreads) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mComputeThreads) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mComputeThreads)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mComputeThreads)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mNumGeometrySets)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mNumGeometrySets)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mNumGeometrySets) == 32, "API_Verifier: 'offsetof( VisibilityBufferDesc, mNumGeometrySets) == 32' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mNumGeometrySets) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mNumGeometrySets) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumGeometrySets)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumGeometrySets)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mNumViews)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mNumViews)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mNumViews) == 36, "API_Verifier: 'offsetof( VisibilityBufferDesc, mNumViews) == 36' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mNumViews) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mNumViews) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumViews)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mNumViews)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mEnablePreSkinPass)) == 1, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mEnablePreSkinPass)) == 1' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mEnablePreSkinPass) == 40, "API_Verifier: 'offsetof( VisibilityBufferDesc, mEnablePreSkinPass) == 40' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mEnablePreSkinPass) == 1, "API_Verifier: 'sizeof(VisibilityBufferDesc::mEnablePreSkinPass) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(VisibilityBufferDesc::mEnablePreSkinPass)>, "API_Verifier: 'std::is_same_v<bool, decltype(VisibilityBufferDesc::mEnablePreSkinPass)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mPreSkinBatchSize)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mPreSkinBatchSize)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mPreSkinBatchSize) == 44, "API_Verifier: 'offsetof( VisibilityBufferDesc, mPreSkinBatchSize) == 44' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mPreSkinBatchSize) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mPreSkinBatchSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mPreSkinBatchSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mPreSkinBatchSize)>' evaluated to false.");

static_assert(alignof( decltype(VisibilityBufferDesc::mPreSkinBatchCount)) == 4, "API_Verifier: 'alignof( decltype(VisibilityBufferDesc::mPreSkinBatchCount)) == 4' evaluated to false.");
static_assert(offsetof( VisibilityBufferDesc, mPreSkinBatchCount) == 48, "API_Verifier: 'offsetof( VisibilityBufferDesc, mPreSkinBatchCount) == 48' evaluated to false.");
static_assert(sizeof(VisibilityBufferDesc::mPreSkinBatchCount) == 4, "API_Verifier: 'sizeof(VisibilityBufferDesc::mPreSkinBatchCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mPreSkinBatchCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VisibilityBufferDesc::mPreSkinBatchCount)>' evaluated to false.");

static_assert(alignof(VBMeshInstance) == 4, "API_Verifier: 'alignof(VBMeshInstance) == 4' evaluated to false.");
static_assert(sizeof(VBMeshInstance) == 12, "API_Verifier: 'sizeof(VBMeshInstance) == 12' evaluated to false.");

static_assert(alignof( decltype(VBMeshInstance::mGeometrySet)) == 4, "API_Verifier: 'alignof( decltype(VBMeshInstance::mGeometrySet)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBMeshInstance::mGeometrySet)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBMeshInstance::mGeometrySet)>' evaluated to false.");

static_assert(alignof( decltype(VBMeshInstance::mMeshIndex)) == 4, "API_Verifier: 'alignof( decltype(VBMeshInstance::mMeshIndex)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBMeshInstance::mMeshIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBMeshInstance::mMeshIndex)>' evaluated to false.");

static_assert(alignof( decltype(VBMeshInstance::mInstanceIndex)) == 4, "API_Verifier: 'alignof( decltype(VBMeshInstance::mInstanceIndex)) == 4' evaluated to false.");
static_assert(offsetof( VBMeshInstance, mInstanceIndex) == 4, "API_Verifier: 'offsetof( VBMeshInstance, mInstanceIndex) == 4' evaluated to false.");
static_assert(sizeof(VBMeshInstance::mInstanceIndex) == 4, "API_Verifier: 'sizeof(VBMeshInstance::mInstanceIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBMeshInstance::mInstanceIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBMeshInstance::mInstanceIndex)>' evaluated to false.");

static_assert(alignof( decltype(VBMeshInstance::mTriangleCount)) == 4, "API_Verifier: 'alignof( decltype(VBMeshInstance::mTriangleCount)) == 4' evaluated to false.");
static_assert(offsetof( VBMeshInstance, mTriangleCount) == 8, "API_Verifier: 'offsetof( VBMeshInstance, mTriangleCount) == 8' evaluated to false.");
static_assert(sizeof(VBMeshInstance::mTriangleCount) == 4, "API_Verifier: 'sizeof(VBMeshInstance::mTriangleCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBMeshInstance::mTriangleCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBMeshInstance::mTriangleCount)>' evaluated to false.");

static_assert(alignof(VBPreFilterStats) == 4, "API_Verifier: 'alignof(VBPreFilterStats) == 4' evaluated to false.");
static_assert(sizeof(VBPreFilterStats) == 20, "API_Verifier: 'sizeof(VBPreFilterStats) == 20' evaluated to false.");

static_assert(alignof( decltype(VBPreFilterStats::mNumDispatchGroups)) == 4, "API_Verifier: 'alignof( decltype(VBPreFilterStats::mNumDispatchGroups)) == 4' evaluated to false.");
static_assert(offsetof( VBPreFilterStats, mNumDispatchGroups) == 0, "API_Verifier: 'offsetof( VBPreFilterStats, mNumDispatchGroups) == 0' evaluated to false.");
static_assert(sizeof(VBPreFilterStats::mNumDispatchGroups) == 4, "API_Verifier: 'sizeof(VBPreFilterStats::mNumDispatchGroups) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBPreFilterStats::mNumDispatchGroups)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBPreFilterStats::mNumDispatchGroups)>' evaluated to false.");

static_assert(alignof( decltype(VBPreFilterStats::mGeomsetMaxDrawCounts)) == 4, "API_Verifier: 'alignof( decltype(VBPreFilterStats::mGeomsetMaxDrawCounts)) == 4' evaluated to false.");
static_assert(offsetof( VBPreFilterStats, mGeomsetMaxDrawCounts) == 4, "API_Verifier: 'offsetof( VBPreFilterStats, mGeomsetMaxDrawCounts) == 4' evaluated to false.");
static_assert(sizeof(VBPreFilterStats::mGeomsetMaxDrawCounts) == 12, "API_Verifier: 'sizeof(VBPreFilterStats::mGeomsetMaxDrawCounts) == 12' evaluated to false.");
static_assert(std::is_same_v<uint32_t[3], decltype(VBPreFilterStats::mGeomsetMaxDrawCounts)>, "API_Verifier: 'std::is_same_v<uint32_t[3], decltype(VBPreFilterStats::mGeomsetMaxDrawCounts)>' evaluated to false.");

static_assert(alignof( decltype(VBPreFilterStats::mTotalMaxDrawCount)) == 4, "API_Verifier: 'alignof( decltype(VBPreFilterStats::mTotalMaxDrawCount)) == 4' evaluated to false.");
static_assert(offsetof( VBPreFilterStats, mTotalMaxDrawCount) == 16, "API_Verifier: 'offsetof( VBPreFilterStats, mTotalMaxDrawCount) == 16' evaluated to false.");
static_assert(sizeof(VBPreFilterStats::mTotalMaxDrawCount) == 4, "API_Verifier: 'sizeof(VBPreFilterStats::mTotalMaxDrawCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(VBPreFilterStats::mTotalMaxDrawCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(VBPreFilterStats::mTotalMaxDrawCount)>' evaluated to false.");

static_assert(alignof(TriangleFilteringPassDesc) == 8, "API_Verifier: 'alignof(TriangleFilteringPassDesc) == 8' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc) == 96, "API_Verifier: 'sizeof(TriangleFilteringPassDesc) == 96' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pPipelineClearBuffers)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pPipelineClearBuffers)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pPipelineClearBuffers) == 0, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pPipelineClearBuffers) == 0' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pPipelineClearBuffers) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pPipelineClearBuffers) == 8' evaluated to false.");
static_assert(std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineClearBuffers)>, "API_Verifier: 'std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineClearBuffers)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pPipelineTriangleFiltering)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pPipelineTriangleFiltering)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pPipelineTriangleFiltering) == 8, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pPipelineTriangleFiltering) == 8' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pPipelineTriangleFiltering) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pPipelineTriangleFiltering) == 8' evaluated to false.");
static_assert(std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineTriangleFiltering)>, "API_Verifier: 'std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineTriangleFiltering)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pPipelineBatchCompaction)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pPipelineBatchCompaction)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pPipelineBatchCompaction) == 16, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pPipelineBatchCompaction) == 16' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pPipelineBatchCompaction) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pPipelineBatchCompaction) == 8' evaluated to false.");
static_assert(std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineBatchCompaction)>, "API_Verifier: 'std::is_same_v<Pipeline*, decltype(TriangleFilteringPassDesc::pPipelineBatchCompaction)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pDescriptorSetTriangleFiltering) == 24, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pDescriptorSetTriangleFiltering) == 24' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFiltering)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pDescriptorSetTriangleFilteringPerFrame) == 32, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pDescriptorSetTriangleFilteringPerFrame) == 32' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetTriangleFilteringPerFrame)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetClearBuffers)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetClearBuffers)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pDescriptorSetClearBuffers) == 40, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pDescriptorSetClearBuffers) == 40' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pDescriptorSetClearBuffers) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pDescriptorSetClearBuffers) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetClearBuffers)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetClearBuffers)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, pDescriptorSetBatchCompaction) == 48, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, pDescriptorSetBatchCompaction) == 48' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(TriangleFilteringPassDesc::pDescriptorSetBatchCompaction)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::mGpuProfileToken)) == 8, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::mGpuProfileToken)) == 8' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, mGpuProfileToken) == 56, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, mGpuProfileToken) == 56' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::mGpuProfileToken) == 8, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::mGpuProfileToken) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(TriangleFilteringPassDesc::mGpuProfileToken)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(TriangleFilteringPassDesc::mGpuProfileToken)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::mFrameIndex)) == 4, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::mFrameIndex)) == 4' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, mFrameIndex) == 64, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, mFrameIndex) == 64' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::mFrameIndex) == 4, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::mFrameIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TriangleFilteringPassDesc::mFrameIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TriangleFilteringPassDesc::mFrameIndex)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::mBuffersIndex)) == 4, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::mBuffersIndex)) == 4' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, mBuffersIndex) == 68, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, mBuffersIndex) == 68' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::mBuffersIndex) == 4, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::mBuffersIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TriangleFilteringPassDesc::mBuffersIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TriangleFilteringPassDesc::mBuffersIndex)>' evaluated to false.");

static_assert(alignof( decltype(TriangleFilteringPassDesc::mVBPreFilterStats)) == 4, "API_Verifier: 'alignof( decltype(TriangleFilteringPassDesc::mVBPreFilterStats)) == 4' evaluated to false.");
static_assert(offsetof( TriangleFilteringPassDesc, mVBPreFilterStats) == 72, "API_Verifier: 'offsetof( TriangleFilteringPassDesc, mVBPreFilterStats) == 72' evaluated to false.");
static_assert(sizeof(TriangleFilteringPassDesc::mVBPreFilterStats) == 20, "API_Verifier: 'sizeof(TriangleFilteringPassDesc::mVBPreFilterStats) == 20' evaluated to false.");
static_assert(std::is_same_v<VBPreFilterStats, decltype(TriangleFilteringPassDesc::mVBPreFilterStats)>, "API_Verifier: 'std::is_same_v<VBPreFilterStats, decltype(TriangleFilteringPassDesc::mVBPreFilterStats)>' evaluated to false.");

static_assert(alignof(UpdateVBMeshFilterGroupsDesc) == 8, "API_Verifier: 'alignof(UpdateVBMeshFilterGroupsDesc) == 8' evaluated to false.");
static_assert(sizeof(UpdateVBMeshFilterGroupsDesc) == 16, "API_Verifier: 'sizeof(UpdateVBMeshFilterGroupsDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances)) == 8, "API_Verifier: 'alignof( decltype(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances)) == 8' evaluated to false.");
static_assert(offsetof( UpdateVBMeshFilterGroupsDesc, pVBMeshInstances) == 0, "API_Verifier: 'offsetof( UpdateVBMeshFilterGroupsDesc, pVBMeshInstances) == 0' evaluated to false.");
static_assert(sizeof(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances) == 8, "API_Verifier: 'sizeof(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances) == 8' evaluated to false.");
static_assert(std::is_same_v<VBMeshInstance*, decltype(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances)>, "API_Verifier: 'std::is_same_v<VBMeshInstance*, decltype(UpdateVBMeshFilterGroupsDesc::pVBMeshInstances)>' evaluated to false.");

static_assert(alignof( decltype(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance)) == 4, "API_Verifier: 'alignof( decltype(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance)) == 4' evaluated to false.");
static_assert(offsetof( UpdateVBMeshFilterGroupsDesc, mNumMeshInstance) == 8, "API_Verifier: 'offsetof( UpdateVBMeshFilterGroupsDesc, mNumMeshInstance) == 8' evaluated to false.");
static_assert(sizeof(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance) == 4, "API_Verifier: 'sizeof(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UpdateVBMeshFilterGroupsDesc::mNumMeshInstance)>' evaluated to false.");

static_assert(alignof( decltype(UpdateVBMeshFilterGroupsDesc::mFrameIndex)) == 4, "API_Verifier: 'alignof( decltype(UpdateVBMeshFilterGroupsDesc::mFrameIndex)) == 4' evaluated to false.");
static_assert(offsetof( UpdateVBMeshFilterGroupsDesc, mFrameIndex) == 12, "API_Verifier: 'offsetof( UpdateVBMeshFilterGroupsDesc, mFrameIndex) == 12' evaluated to false.");
static_assert(sizeof(UpdateVBMeshFilterGroupsDesc::mFrameIndex) == 4, "API_Verifier: 'sizeof(UpdateVBMeshFilterGroupsDesc::mFrameIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(UpdateVBMeshFilterGroupsDesc::mFrameIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(UpdateVBMeshFilterGroupsDesc::mFrameIndex)>' evaluated to false.");

static_assert(alignof(PreSkinACVertexBuffersDesc) == 4, "API_Verifier: 'alignof(PreSkinACVertexBuffersDesc) == 4' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffersDesc) == 12, "API_Verifier: 'sizeof(PreSkinACVertexBuffersDesc) == 12' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffersDesc::mNumBuffers)) == 4, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffersDesc::mNumBuffers)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffersDesc, mNumBuffers) == 0, "API_Verifier: 'offsetof( PreSkinACVertexBuffersDesc, mNumBuffers) == 0' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffersDesc::mNumBuffers) == 4, "API_Verifier: 'sizeof(PreSkinACVertexBuffersDesc::mNumBuffers) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mNumBuffers)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mNumBuffers)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount)) == 4, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffersDesc, mMaxStaticVertexCount) == 4, "API_Verifier: 'offsetof( PreSkinACVertexBuffersDesc, mMaxStaticVertexCount) == 4' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount) == 4, "API_Verifier: 'sizeof(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mMaxStaticVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame)) == 4, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffersDesc, mMaxPreSkinnedVertexCountPerFrame) == 8, "API_Verifier: 'offsetof( PreSkinACVertexBuffersDesc, mMaxPreSkinnedVertexCountPerFrame) == 8' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame) == 4, "API_Verifier: 'sizeof(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinACVertexBuffersDesc::mMaxPreSkinnedVertexCountPerFrame)>' evaluated to false.");

static_assert(alignof(PreSkinACAliasedBuffer) == 8, "API_Verifier: 'alignof(PreSkinACAliasedBuffer) == 8' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer) == 56, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer) == 56' evaluated to false.");

static_assert(alignof( decltype(PreSkinACAliasedBuffer::mVBSize)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACAliasedBuffer::mVBSize)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACAliasedBuffer, mVBSize) == 0, "API_Verifier: 'offsetof( PreSkinACAliasedBuffer, mVBSize) == 0' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer::mVBSize) == 8, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer::mVBSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mVBSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mVBSize)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACAliasedBuffer::mVBPlacement)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACAliasedBuffer::mVBPlacement)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACAliasedBuffer, mVBPlacement) == 8, "API_Verifier: 'offsetof( PreSkinACAliasedBuffer, mVBPlacement) == 8' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer::mVBPlacement) == 16, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer::mVBPlacement) == 16' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement, decltype(PreSkinACAliasedBuffer::mVBPlacement)>, "API_Verifier: 'std::is_same_v<ResourcePlacement, decltype(PreSkinACAliasedBuffer::mVBPlacement)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACAliasedBuffer::mOutputMemoryStartOffset)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACAliasedBuffer::mOutputMemoryStartOffset)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACAliasedBuffer, mOutputMemoryStartOffset) == 24, "API_Verifier: 'offsetof( PreSkinACAliasedBuffer, mOutputMemoryStartOffset) == 24' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer::mOutputMemoryStartOffset) == 8, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer::mOutputMemoryStartOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mOutputMemoryStartOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mOutputMemoryStartOffset)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACAliasedBuffer::mOutputMemorySize)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACAliasedBuffer::mOutputMemorySize)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACAliasedBuffer, mOutputMemorySize) == 32, "API_Verifier: 'offsetof( PreSkinACAliasedBuffer, mOutputMemorySize) == 32' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer::mOutputMemorySize) == 8, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer::mOutputMemorySize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mOutputMemorySize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PreSkinACAliasedBuffer::mOutputMemorySize)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACAliasedBuffer::pPreSkinBuffers)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACAliasedBuffer::pPreSkinBuffers)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACAliasedBuffer, pPreSkinBuffers) == 40, "API_Verifier: 'offsetof( PreSkinACAliasedBuffer, pPreSkinBuffers) == 40' evaluated to false.");
static_assert(sizeof(PreSkinACAliasedBuffer::pPreSkinBuffers) == 16, "API_Verifier: 'sizeof(PreSkinACAliasedBuffer::pPreSkinBuffers) == 16' evaluated to false.");
static_assert(std::is_same_v<Buffer *[2], decltype(PreSkinACAliasedBuffer::pPreSkinBuffers)>, "API_Verifier: 'std::is_same_v<Buffer *[2], decltype(PreSkinACAliasedBuffer::pPreSkinBuffers)>' evaluated to false.");

static_assert(alignof(PreSkinACVertexBuffers) == 8, "API_Verifier: 'alignof(PreSkinACVertexBuffers) == 8' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffers) == 136, "API_Verifier: 'sizeof(PreSkinACVertexBuffers) == 136' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffers::pHeap)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffers::pHeap)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffers, pHeap) == 0, "API_Verifier: 'offsetof( PreSkinACVertexBuffers, pHeap) == 0' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffers::pHeap) == 8, "API_Verifier: 'sizeof(PreSkinACVertexBuffers::pHeap) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourceHeap*, decltype(PreSkinACVertexBuffers::pHeap)>, "API_Verifier: 'std::is_same_v<ResourceHeap*, decltype(PreSkinACVertexBuffers::pHeap)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffers::mPositions)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffers::mPositions)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffers, mPositions) == 8, "API_Verifier: 'offsetof( PreSkinACVertexBuffers, mPositions) == 8' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffers::mPositions) == 56, "API_Verifier: 'sizeof(PreSkinACVertexBuffers::mPositions) == 56' evaluated to false.");
static_assert(std::is_same_v<PreSkinACAliasedBuffer, decltype(PreSkinACVertexBuffers::mPositions)>, "API_Verifier: 'std::is_same_v<PreSkinACAliasedBuffer, decltype(PreSkinACVertexBuffers::mPositions)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffers::mNormals)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffers::mNormals)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffers, mNormals) == 64, "API_Verifier: 'offsetof( PreSkinACVertexBuffers, mNormals) == 64' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffers::mNormals) == 56, "API_Verifier: 'sizeof(PreSkinACVertexBuffers::mNormals) == 56' evaluated to false.");
static_assert(std::is_same_v<PreSkinACAliasedBuffer, decltype(PreSkinACVertexBuffers::mNormals)>, "API_Verifier: 'std::is_same_v<PreSkinACAliasedBuffer, decltype(PreSkinACVertexBuffers::mNormals)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinACVertexBuffers::pShaderOffsets)) == 8, "API_Verifier: 'alignof( decltype(PreSkinACVertexBuffers::pShaderOffsets)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinACVertexBuffers, pShaderOffsets) == 120, "API_Verifier: 'offsetof( PreSkinACVertexBuffers, pShaderOffsets) == 120' evaluated to false.");
static_assert(sizeof(PreSkinACVertexBuffers::pShaderOffsets) == 16, "API_Verifier: 'sizeof(PreSkinACVertexBuffers::pShaderOffsets) == 16' evaluated to false.");
static_assert(std::is_same_v<Buffer *[2], decltype(PreSkinACVertexBuffers::pShaderOffsets)>, "API_Verifier: 'std::is_same_v<Buffer *[2], decltype(PreSkinACVertexBuffers::pShaderOffsets)>' evaluated to false.");

static_assert(alignof(PreSkinContainer) == 4, "API_Verifier: 'alignof(PreSkinContainer) == 4' evaluated to false.");
static_assert(sizeof(PreSkinContainer) == 20, "API_Verifier: 'sizeof(PreSkinContainer) == 20' evaluated to false.");

static_assert(alignof( decltype(PreSkinContainer::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(PreSkinContainer::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinContainer, mVertexCount) == 0, "API_Verifier: 'offsetof( PreSkinContainer, mVertexCount) == 0' evaluated to false.");
static_assert(sizeof(PreSkinContainer::mVertexCount) == 4, "API_Verifier: 'sizeof(PreSkinContainer::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinContainer::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinContainer::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinContainer::mVertexPositionOffset)) == 4, "API_Verifier: 'alignof( decltype(PreSkinContainer::mVertexPositionOffset)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinContainer, mVertexPositionOffset) == 4, "API_Verifier: 'offsetof( PreSkinContainer, mVertexPositionOffset) == 4' evaluated to false.");
static_assert(sizeof(PreSkinContainer::mVertexPositionOffset) == 4, "API_Verifier: 'sizeof(PreSkinContainer::mVertexPositionOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinContainer::mVertexPositionOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinContainer::mVertexPositionOffset)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinContainer::mJointOffset)) == 4, "API_Verifier: 'alignof( decltype(PreSkinContainer::mJointOffset)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinContainer, mJointOffset) == 8, "API_Verifier: 'offsetof( PreSkinContainer, mJointOffset) == 8' evaluated to false.");
static_assert(sizeof(PreSkinContainer::mJointOffset) == 4, "API_Verifier: 'sizeof(PreSkinContainer::mJointOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinContainer::mJointOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinContainer::mJointOffset)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinContainer::mJointMatrixOffset)) == 4, "API_Verifier: 'alignof( decltype(PreSkinContainer::mJointMatrixOffset)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinContainer, mJointMatrixOffset) == 12, "API_Verifier: 'offsetof( PreSkinContainer, mJointMatrixOffset) == 12' evaluated to false.");
static_assert(sizeof(PreSkinContainer::mJointMatrixOffset) == 4, "API_Verifier: 'sizeof(PreSkinContainer::mJointMatrixOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinContainer::mJointMatrixOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinContainer::mJointMatrixOffset)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinContainer::mOutputVertexOffset)) == 4, "API_Verifier: 'alignof( decltype(PreSkinContainer::mOutputVertexOffset)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinContainer, mOutputVertexOffset) == 16, "API_Verifier: 'offsetof( PreSkinContainer, mOutputVertexOffset) == 16' evaluated to false.");
static_assert(sizeof(PreSkinContainer::mOutputVertexOffset) == 4, "API_Verifier: 'sizeof(PreSkinContainer::mOutputVertexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinContainer::mOutputVertexOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinContainer::mOutputVertexOffset)>' evaluated to false.");

static_assert(alignof(PreSkinVertexesPassDesc) == 8, "API_Verifier: 'alignof(PreSkinVertexesPassDesc) == 8' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc) == 64, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc) == 64' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::mGpuProfileToken)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::mGpuProfileToken)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, mGpuProfileToken) == 0, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, mGpuProfileToken) == 0' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::mGpuProfileToken) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::mGpuProfileToken) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(PreSkinVertexesPassDesc::mGpuProfileToken)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(PreSkinVertexesPassDesc::mGpuProfileToken)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, pPipelinePreSkinVertexes) == 8, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, pPipelinePreSkinVertexes) == 8' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes) == 8' evaluated to false.");
static_assert(std::is_same_v<Pipeline*, decltype(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes)>, "API_Verifier: 'std::is_same_v<Pipeline*, decltype(PreSkinVertexesPassDesc::pPipelinePreSkinVertexes)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, pDescriptorSetPreSkinVertexes) == 16, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, pDescriptorSetPreSkinVertexes) == 16' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexes)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, pDescriptorSetPreSkinVertexesPerFrame) == 24, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, pDescriptorSetPreSkinVertexesPerFrame) == 24' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame) == 8' evaluated to false.");
static_assert(std::is_same_v<DescriptorSet*, decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame)>, "API_Verifier: 'std::is_same_v<DescriptorSet*, decltype(PreSkinVertexesPassDesc::pDescriptorSetPreSkinVertexesPerFrame)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, ppPreSkinOutputVertexBuffers) == 32, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, ppPreSkinOutputVertexBuffers) == 32' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(PreSkinVertexesPassDesc::ppPreSkinOutputVertexBuffers)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::pPreSkinContainers)) == 8, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::pPreSkinContainers)) == 8' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, pPreSkinContainers) == 40, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, pPreSkinContainers) == 40' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::pPreSkinContainers) == 8, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::pPreSkinContainers) == 8' evaluated to false.");
static_assert(std::is_same_v<const PreSkinContainer*, decltype(PreSkinVertexesPassDesc::pPreSkinContainers)>, "API_Verifier: 'std::is_same_v<const PreSkinContainer*, decltype(PreSkinVertexesPassDesc::pPreSkinContainers)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, mPreSkinOutputVertexBufferCount) == 48, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, mPreSkinOutputVertexBufferCount) == 48' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount) == 4, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mPreSkinOutputVertexBufferCount)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::mPreSkinContainerCount)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::mPreSkinContainerCount)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, mPreSkinContainerCount) == 52, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, mPreSkinContainerCount) == 52' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::mPreSkinContainerCount) == 4, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::mPreSkinContainerCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mPreSkinContainerCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mPreSkinContainerCount)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesPassDesc::mFrameIndex)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesPassDesc::mFrameIndex)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesPassDesc, mFrameIndex) == 56, "API_Verifier: 'offsetof( PreSkinVertexesPassDesc, mFrameIndex) == 56' evaluated to false.");
static_assert(sizeof(PreSkinVertexesPassDesc::mFrameIndex) == 4, "API_Verifier: 'sizeof(PreSkinVertexesPassDesc::mFrameIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mFrameIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesPassDesc::mFrameIndex)>' evaluated to false.");

static_assert(alignof(PreSkinVertexesStats) == 4, "API_Verifier: 'alignof(PreSkinVertexesStats) == 4' evaluated to false.");
static_assert(sizeof(PreSkinVertexesStats) == 12, "API_Verifier: 'sizeof(PreSkinVertexesStats) == 12' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesStats::mTotalVertexes)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesStats::mTotalVertexes)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesStats, mTotalVertexes) == 0, "API_Verifier: 'offsetof( PreSkinVertexesStats, mTotalVertexes) == 0' evaluated to false.");
static_assert(sizeof(PreSkinVertexesStats::mTotalVertexes) == 4, "API_Verifier: 'sizeof(PreSkinVertexesStats::mTotalVertexes) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalVertexes)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalVertexes)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesStats::mTotalVertexBatches)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesStats::mTotalVertexBatches)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesStats, mTotalVertexBatches) == 4, "API_Verifier: 'offsetof( PreSkinVertexesStats, mTotalVertexBatches) == 4' evaluated to false.");
static_assert(sizeof(PreSkinVertexesStats::mTotalVertexBatches) == 4, "API_Verifier: 'sizeof(PreSkinVertexesStats::mTotalVertexBatches) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalVertexBatches)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalVertexBatches)>' evaluated to false.");

static_assert(alignof( decltype(PreSkinVertexesStats::mTotalShaderDispatches)) == 4, "API_Verifier: 'alignof( decltype(PreSkinVertexesStats::mTotalShaderDispatches)) == 4' evaluated to false.");
static_assert(offsetof( PreSkinVertexesStats, mTotalShaderDispatches) == 8, "API_Verifier: 'offsetof( PreSkinVertexesStats, mTotalShaderDispatches) == 8' evaluated to false.");
static_assert(sizeof(PreSkinVertexesStats::mTotalShaderDispatches) == 4, "API_Verifier: 'sizeof(PreSkinVertexesStats::mTotalShaderDispatches) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalShaderDispatches)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(PreSkinVertexesStats::mTotalShaderDispatches)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Resources\ResourceLoader\Interfaces\IResourceLoader.h"

static_assert(std::is_same_v<std::underlying_type_t<TextureContainerType>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<TextureContainerType>,int>' evaluated to false.");
static_assert(TextureContainerType::TEXTURE_CONTAINER_DEFAULT == 0, "API_Verifier: 'TextureContainerType::TEXTURE_CONTAINER_DEFAULT == 0' evaluated to false.");
static_assert(TextureContainerType::TEXTURE_CONTAINER_DDS == 1, "API_Verifier: 'TextureContainerType::TEXTURE_CONTAINER_DDS == 1' evaluated to false.");
static_assert(TextureContainerType::TEXTURE_CONTAINER_KTX == 2, "API_Verifier: 'TextureContainerType::TEXTURE_CONTAINER_KTX == 2' evaluated to false.");
static_assert(TextureContainerType::TEXTURE_CONTAINER_GNF == 3, "API_Verifier: 'TextureContainerType::TEXTURE_CONTAINER_GNF == 3' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<RegisterMaterialResult>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<RegisterMaterialResult>,int>' evaluated to false.");
static_assert(RegisterMaterialResult::REGISTER_MATERIAL_SUCCESS == 0, "API_Verifier: 'RegisterMaterialResult::REGISTER_MATERIAL_SUCCESS == 0' evaluated to false.");
static_assert(RegisterMaterialResult::REGISTER_MATERIAL_BADFILE == 1, "API_Verifier: 'RegisterMaterialResult::REGISTER_MATERIAL_BADFILE == 1' evaluated to false.");

static_assert(std::is_same_v<std::underlying_type_t<GeometryLoadFlags>,int>, "API_Verifier: 'std::is_same_v<std::underlying_type_t<GeometryLoadFlags>,int>' evaluated to false.");
static_assert(GeometryLoadFlags::GEOMETRY_LOAD_FLAG_NONE == 0, "API_Verifier: 'GeometryLoadFlags::GEOMETRY_LOAD_FLAG_NONE == 0' evaluated to false.");
static_assert(GeometryLoadFlags::GEOMETRY_LOAD_FLAG_SHADOWED == 1, "API_Verifier: 'GeometryLoadFlags::GEOMETRY_LOAD_FLAG_SHADOWED == 1' evaluated to false.");
static_assert(GeometryLoadFlags::GEOMETRY_LOAD_FLAG_STRUCTURED_BUFFERS == 2, "API_Verifier: 'GeometryLoadFlags::GEOMETRY_LOAD_FLAG_STRUCTURED_BUFFERS == 2' evaluated to false.");
static_assert(GeometryLoadFlags::GEOMETRY_LOAD_FLAG_RAYTRACING_INPUT == 4, "API_Verifier: 'GeometryLoadFlags::GEOMETRY_LOAD_FLAG_RAYTRACING_INPUT == 4' evaluated to false.");

static_assert(alignof(MappedMemoryRange) == 8, "API_Verifier: 'alignof(MappedMemoryRange) == 8' evaluated to false.");
static_assert(sizeof(MappedMemoryRange) == 40, "API_Verifier: 'sizeof(MappedMemoryRange) == 40' evaluated to false.");

static_assert(alignof( decltype(MappedMemoryRange::pData)) == 8, "API_Verifier: 'alignof( decltype(MappedMemoryRange::pData)) == 8' evaluated to false.");
static_assert(offsetof( MappedMemoryRange, pData) == 0, "API_Verifier: 'offsetof( MappedMemoryRange, pData) == 0' evaluated to false.");
static_assert(sizeof(MappedMemoryRange::pData) == 8, "API_Verifier: 'sizeof(MappedMemoryRange::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<uint8_t*, decltype(MappedMemoryRange::pData)>, "API_Verifier: 'std::is_same_v<uint8_t*, decltype(MappedMemoryRange::pData)>' evaluated to false.");

static_assert(alignof( decltype(MappedMemoryRange::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(MappedMemoryRange::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( MappedMemoryRange, pBuffer) == 8, "API_Verifier: 'offsetof( MappedMemoryRange, pBuffer) == 8' evaluated to false.");
static_assert(sizeof(MappedMemoryRange::pBuffer) == 8, "API_Verifier: 'sizeof(MappedMemoryRange::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(MappedMemoryRange::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(MappedMemoryRange::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(MappedMemoryRange::mOffset)) == 8, "API_Verifier: 'alignof( decltype(MappedMemoryRange::mOffset)) == 8' evaluated to false.");
static_assert(offsetof( MappedMemoryRange, mOffset) == 16, "API_Verifier: 'offsetof( MappedMemoryRange, mOffset) == 16' evaluated to false.");
static_assert(sizeof(MappedMemoryRange::mOffset) == 8, "API_Verifier: 'sizeof(MappedMemoryRange::mOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(MappedMemoryRange::mOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(MappedMemoryRange::mOffset)>' evaluated to false.");

static_assert(alignof( decltype(MappedMemoryRange::mSize)) == 8, "API_Verifier: 'alignof( decltype(MappedMemoryRange::mSize)) == 8' evaluated to false.");
static_assert(offsetof( MappedMemoryRange, mSize) == 24, "API_Verifier: 'offsetof( MappedMemoryRange, mSize) == 24' evaluated to false.");
static_assert(sizeof(MappedMemoryRange::mSize) == 8, "API_Verifier: 'sizeof(MappedMemoryRange::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(MappedMemoryRange::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(MappedMemoryRange::mSize)>' evaluated to false.");

static_assert(alignof( decltype(MappedMemoryRange::mFlags)) == 4, "API_Verifier: 'alignof( decltype(MappedMemoryRange::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( MappedMemoryRange, mFlags) == 32, "API_Verifier: 'offsetof( MappedMemoryRange, mFlags) == 32' evaluated to false.");
static_assert(sizeof(MappedMemoryRange::mFlags) == 4, "API_Verifier: 'sizeof(MappedMemoryRange::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MappedMemoryRange::mFlags)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MappedMemoryRange::mFlags)>' evaluated to false.");

static_assert(alignof(BufferLoadDesc) == 8, "API_Verifier: 'alignof(BufferLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(BufferLoadDesc) == 136, "API_Verifier: 'sizeof(BufferLoadDesc) == 136' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::ppBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferLoadDesc::ppBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, ppBuffer) == 0, "API_Verifier: 'offsetof( BufferLoadDesc, ppBuffer) == 0' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::ppBuffer) == 8, "API_Verifier: 'sizeof(BufferLoadDesc::ppBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer **, decltype(BufferLoadDesc::ppBuffer)>, "API_Verifier: 'std::is_same_v<Buffer **, decltype(BufferLoadDesc::ppBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::pData)) == 8, "API_Verifier: 'alignof( decltype(BufferLoadDesc::pData)) == 8' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, pData) == 8, "API_Verifier: 'offsetof( BufferLoadDesc, pData) == 8' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::pData) == 8, "API_Verifier: 'sizeof(BufferLoadDesc::pData) == 8' evaluated to false.");
static_assert(std::is_same_v<const void *, decltype(BufferLoadDesc::pData)>, "API_Verifier: 'std::is_same_v<const void *, decltype(BufferLoadDesc::pData)>' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::mDesc)) == 8, "API_Verifier: 'alignof( decltype(BufferLoadDesc::mDesc)) == 8' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, mDesc) == 16, "API_Verifier: 'offsetof( BufferLoadDesc, mDesc) == 16' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::mDesc) == 96, "API_Verifier: 'sizeof(BufferLoadDesc::mDesc) == 96' evaluated to false.");
static_assert(std::is_same_v<BufferDesc, decltype(BufferLoadDesc::mDesc)>, "API_Verifier: 'std::is_same_v<BufferDesc, decltype(BufferLoadDesc::mDesc)>' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::mForceReset)) == 1, "API_Verifier: 'alignof( decltype(BufferLoadDesc::mForceReset)) == 1' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, mForceReset) == 112, "API_Verifier: 'offsetof( BufferLoadDesc, mForceReset) == 112' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::mForceReset) == 1, "API_Verifier: 'sizeof(BufferLoadDesc::mForceReset) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(BufferLoadDesc::mForceReset)>, "API_Verifier: 'std::is_same_v<bool, decltype(BufferLoadDesc::mForceReset)>' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::pSrcBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferLoadDesc::pSrcBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, pSrcBuffer) == 120, "API_Verifier: 'offsetof( BufferLoadDesc, pSrcBuffer) == 120' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::pSrcBuffer) == 8, "API_Verifier: 'sizeof(BufferLoadDesc::pSrcBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferLoadDesc::pSrcBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferLoadDesc::pSrcBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferLoadDesc::mSrcOffset)) == 8, "API_Verifier: 'alignof( decltype(BufferLoadDesc::mSrcOffset)) == 8' evaluated to false.");
static_assert(offsetof( BufferLoadDesc, mSrcOffset) == 128, "API_Verifier: 'offsetof( BufferLoadDesc, mSrcOffset) == 128' evaluated to false.");
static_assert(sizeof(BufferLoadDesc::mSrcOffset) == 8, "API_Verifier: 'sizeof(BufferLoadDesc::mSrcOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(BufferLoadDesc::mSrcOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(BufferLoadDesc::mSrcOffset)>' evaluated to false.");

static_assert(alignof(TextureLoadDesc) == 8, "API_Verifier: 'alignof(TextureLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(TextureLoadDesc) == 48, "API_Verifier: 'sizeof(TextureLoadDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(TextureLoadDesc::ppTexture)) == 8, "API_Verifier: 'alignof( decltype(TextureLoadDesc::ppTexture)) == 8' evaluated to false.");
static_assert(offsetof( TextureLoadDesc, ppTexture) == 0, "API_Verifier: 'offsetof( TextureLoadDesc, ppTexture) == 0' evaluated to false.");
static_assert(sizeof(TextureLoadDesc::ppTexture) == 8, "API_Verifier: 'sizeof(TextureLoadDesc::ppTexture) == 8' evaluated to false.");
static_assert(std::is_same_v<Texture **, decltype(TextureLoadDesc::ppTexture)>, "API_Verifier: 'std::is_same_v<Texture **, decltype(TextureLoadDesc::ppTexture)>' evaluated to false.");

static_assert(alignof( decltype(TextureLoadDesc::pFileName)) == 8, "API_Verifier: 'alignof( decltype(TextureLoadDesc::pFileName)) == 8' evaluated to false.");
static_assert(offsetof( TextureLoadDesc, pFileName) == 24, "API_Verifier: 'offsetof( TextureLoadDesc, pFileName) == 24' evaluated to false.");
static_assert(sizeof(TextureLoadDesc::pFileName) == 8, "API_Verifier: 'sizeof(TextureLoadDesc::pFileName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(TextureLoadDesc::pFileName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(TextureLoadDesc::pFileName)>' evaluated to false.");

static_assert(alignof( decltype(TextureLoadDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(TextureLoadDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( TextureLoadDesc, mNodeIndex) == 32, "API_Verifier: 'offsetof( TextureLoadDesc, mNodeIndex) == 32' evaluated to false.");
static_assert(sizeof(TextureLoadDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(TextureLoadDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureLoadDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureLoadDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(TextureLoadDesc::mCreationFlag)) == 4, "API_Verifier: 'alignof( decltype(TextureLoadDesc::mCreationFlag)) == 4' evaluated to false.");
static_assert(offsetof( TextureLoadDesc, mCreationFlag) == 36, "API_Verifier: 'offsetof( TextureLoadDesc, mCreationFlag) == 36' evaluated to false.");
static_assert(sizeof(TextureLoadDesc::mCreationFlag) == 4, "API_Verifier: 'sizeof(TextureLoadDesc::mCreationFlag) == 4' evaluated to false.");
static_assert(std::is_same_v<TextureCreationFlags, decltype(TextureLoadDesc::mCreationFlag)>, "API_Verifier: 'std::is_same_v<TextureCreationFlags, decltype(TextureLoadDesc::mCreationFlag)>' evaluated to false.");

static_assert(alignof( decltype(TextureLoadDesc::mContainer)) == 4, "API_Verifier: 'alignof( decltype(TextureLoadDesc::mContainer)) == 4' evaluated to false.");
static_assert(offsetof( TextureLoadDesc, mContainer) == 40, "API_Verifier: 'offsetof( TextureLoadDesc, mContainer) == 40' evaluated to false.");
static_assert(sizeof(TextureLoadDesc::mContainer) == 4, "API_Verifier: 'sizeof(TextureLoadDesc::mContainer) == 4' evaluated to false.");
static_assert(std::is_same_v<TextureContainerType, decltype(TextureLoadDesc::mContainer)>, "API_Verifier: 'std::is_same_v<TextureContainerType, decltype(TextureLoadDesc::mContainer)>' evaluated to false.");

static_assert(alignof(BufferChunk) == 4, "API_Verifier: 'alignof(BufferChunk) == 4' evaluated to false.");
static_assert(sizeof(BufferChunk) == 8, "API_Verifier: 'sizeof(BufferChunk) == 8' evaluated to false.");

static_assert(alignof( decltype(BufferChunk::mOffset)) == 4, "API_Verifier: 'alignof( decltype(BufferChunk::mOffset)) == 4' evaluated to false.");
static_assert(offsetof( BufferChunk, mOffset) == 0, "API_Verifier: 'offsetof( BufferChunk, mOffset) == 0' evaluated to false.");
static_assert(sizeof(BufferChunk::mOffset) == 4, "API_Verifier: 'sizeof(BufferChunk::mOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferChunk::mOffset)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferChunk::mOffset)>' evaluated to false.");

static_assert(alignof( decltype(BufferChunk::mSize)) == 4, "API_Verifier: 'alignof( decltype(BufferChunk::mSize)) == 4' evaluated to false.");
static_assert(offsetof( BufferChunk, mSize) == 4, "API_Verifier: 'offsetof( BufferChunk, mSize) == 4' evaluated to false.");
static_assert(sizeof(BufferChunk::mSize) == 4, "API_Verifier: 'sizeof(BufferChunk::mSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferChunk::mSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferChunk::mSize)>' evaluated to false.");

static_assert(alignof(BufferChunkAllocator) == 8, "API_Verifier: 'alignof(BufferChunkAllocator) == 8' evaluated to false.");
static_assert(sizeof(BufferChunkAllocator) == 24, "API_Verifier: 'sizeof(BufferChunkAllocator) == 24' evaluated to false.");

static_assert(alignof( decltype(BufferChunkAllocator::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferChunkAllocator::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferChunkAllocator, pBuffer) == 0, "API_Verifier: 'offsetof( BufferChunkAllocator, pBuffer) == 0' evaluated to false.");
static_assert(sizeof(BufferChunkAllocator::pBuffer) == 8, "API_Verifier: 'sizeof(BufferChunkAllocator::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferChunkAllocator::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferChunkAllocator::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferChunkAllocator::mUsedChunkCount)) == 4, "API_Verifier: 'alignof( decltype(BufferChunkAllocator::mUsedChunkCount)) == 4' evaluated to false.");
static_assert(offsetof( BufferChunkAllocator, mUsedChunkCount) == 8, "API_Verifier: 'offsetof( BufferChunkAllocator, mUsedChunkCount) == 8' evaluated to false.");
static_assert(sizeof(BufferChunkAllocator::mUsedChunkCount) == 4, "API_Verifier: 'sizeof(BufferChunkAllocator::mUsedChunkCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferChunkAllocator::mUsedChunkCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferChunkAllocator::mUsedChunkCount)>' evaluated to false.");

static_assert(alignof( decltype(BufferChunkAllocator::mSize)) == 4, "API_Verifier: 'alignof( decltype(BufferChunkAllocator::mSize)) == 4' evaluated to false.");
static_assert(offsetof( BufferChunkAllocator, mSize) == 12, "API_Verifier: 'offsetof( BufferChunkAllocator, mSize) == 12' evaluated to false.");
static_assert(sizeof(BufferChunkAllocator::mSize) == 4, "API_Verifier: 'sizeof(BufferChunkAllocator::mSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(BufferChunkAllocator::mSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(BufferChunkAllocator::mSize)>' evaluated to false.");

static_assert(alignof( decltype(BufferChunkAllocator::mUnusedChunks)) == 8, "API_Verifier: 'alignof( decltype(BufferChunkAllocator::mUnusedChunks)) == 8' evaluated to false.");
static_assert(offsetof( BufferChunkAllocator, mUnusedChunks) == 16, "API_Verifier: 'offsetof( BufferChunkAllocator, mUnusedChunks) == 16' evaluated to false.");
static_assert(sizeof(BufferChunkAllocator::mUnusedChunks) == 8, "API_Verifier: 'sizeof(BufferChunkAllocator::mUnusedChunks) == 8' evaluated to false.");
static_assert(std::is_same_v<BufferChunk*, decltype(BufferChunkAllocator::mUnusedChunks)>, "API_Verifier: 'std::is_same_v<BufferChunk*, decltype(BufferChunkAllocator::mUnusedChunks)>' evaluated to false.");

static_assert(alignof(GeometryBuffer) == 8, "API_Verifier: 'alignof(GeometryBuffer) == 8' evaluated to false.");
static_assert(sizeof(GeometryBuffer) == 384, "API_Verifier: 'sizeof(GeometryBuffer) == 384' evaluated to false.");

static_assert(alignof( decltype(GeometryBuffer::mIndex)) == 8, "API_Verifier: 'alignof( decltype(GeometryBuffer::mIndex)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBuffer, mIndex) == 0, "API_Verifier: 'offsetof( GeometryBuffer, mIndex) == 0' evaluated to false.");
static_assert(sizeof(GeometryBuffer::mIndex) == 24, "API_Verifier: 'sizeof(GeometryBuffer::mIndex) == 24' evaluated to false.");
static_assert(std::is_same_v<BufferChunkAllocator, decltype(GeometryBuffer::mIndex)>, "API_Verifier: 'std::is_same_v<BufferChunkAllocator, decltype(GeometryBuffer::mIndex)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBuffer::mVertex)) == 8, "API_Verifier: 'alignof( decltype(GeometryBuffer::mVertex)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBuffer, mVertex) == 24, "API_Verifier: 'offsetof( GeometryBuffer, mVertex) == 24' evaluated to false.");
static_assert(sizeof(GeometryBuffer::mVertex) == 360, "API_Verifier: 'sizeof(GeometryBuffer::mVertex) == 360' evaluated to false.");
static_assert(std::is_same_v<BufferChunkAllocator[15], decltype(GeometryBuffer::mVertex)>, "API_Verifier: 'std::is_same_v<BufferChunkAllocator[15], decltype(GeometryBuffer::mVertex)>' evaluated to false.");

static_assert(alignof(Meshlet) == 4, "API_Verifier: 'alignof(Meshlet) == 4' evaluated to false.");
static_assert(sizeof(Meshlet) == 16, "API_Verifier: 'sizeof(Meshlet) == 16' evaluated to false.");

static_assert(alignof( decltype(Meshlet::vertexOffset)) == 4, "API_Verifier: 'alignof( decltype(Meshlet::vertexOffset)) == 4' evaluated to false.");
static_assert(offsetof( Meshlet, vertexOffset) == 0, "API_Verifier: 'offsetof( Meshlet, vertexOffset) == 0' evaluated to false.");
static_assert(sizeof(Meshlet::vertexOffset) == 4, "API_Verifier: 'sizeof(Meshlet::vertexOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::vertexOffset)>, "API_Verifier: 'std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::vertexOffset)>' evaluated to false.");

static_assert(alignof( decltype(Meshlet::triangleOffset)) == 4, "API_Verifier: 'alignof( decltype(Meshlet::triangleOffset)) == 4' evaluated to false.");
static_assert(offsetof( Meshlet, triangleOffset) == 4, "API_Verifier: 'offsetof( Meshlet, triangleOffset) == 4' evaluated to false.");
static_assert(sizeof(Meshlet::triangleOffset) == 4, "API_Verifier: 'sizeof(Meshlet::triangleOffset) == 4' evaluated to false.");
static_assert(std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::triangleOffset)>, "API_Verifier: 'std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::triangleOffset)>' evaluated to false.");

static_assert(alignof( decltype(Meshlet::vertexCount)) == 4, "API_Verifier: 'alignof( decltype(Meshlet::vertexCount)) == 4' evaluated to false.");
static_assert(offsetof( Meshlet, vertexCount) == 8, "API_Verifier: 'offsetof( Meshlet, vertexCount) == 8' evaluated to false.");
static_assert(sizeof(Meshlet::vertexCount) == 4, "API_Verifier: 'sizeof(Meshlet::vertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::vertexCount)>, "API_Verifier: 'std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::vertexCount)>' evaluated to false.");

static_assert(alignof( decltype(Meshlet::triangleCount)) == 4, "API_Verifier: 'alignof( decltype(Meshlet::triangleCount)) == 4' evaluated to false.");
static_assert(offsetof( Meshlet, triangleCount) == 12, "API_Verifier: 'offsetof( Meshlet, triangleCount) == 12' evaluated to false.");
static_assert(sizeof(Meshlet::triangleCount) == 4, "API_Verifier: 'sizeof(Meshlet::triangleCount) == 4' evaluated to false.");
static_assert(std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::triangleCount)>, "API_Verifier: 'std::is_same_v<Vectormath::SSE::uint, decltype(Meshlet::triangleCount)>' evaluated to false.");

static_assert(alignof(MeshletData) == 4, "API_Verifier: 'alignof(MeshletData) == 4' evaluated to false.");
static_assert(sizeof(MeshletData) == 44, "API_Verifier: 'sizeof(MeshletData) == 44' evaluated to false.");

static_assert(alignof( decltype(MeshletData::center)) == 4, "API_Verifier: 'alignof( decltype(MeshletData::center)) == 4' evaluated to false.");
static_assert(offsetof( MeshletData, center) == 0, "API_Verifier: 'offsetof( MeshletData, center) == 0' evaluated to false.");
static_assert(sizeof(MeshletData::center) == 12, "API_Verifier: 'sizeof(MeshletData::center) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(MeshletData::center)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(MeshletData::center)>' evaluated to false.");

static_assert(alignof( decltype(MeshletData::radius)) == 4, "API_Verifier: 'alignof( decltype(MeshletData::radius)) == 4' evaluated to false.");
static_assert(offsetof( MeshletData, radius) == 12, "API_Verifier: 'offsetof( MeshletData, radius) == 12' evaluated to false.");
static_assert(sizeof(MeshletData::radius) == 4, "API_Verifier: 'sizeof(MeshletData::radius) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(MeshletData::radius)>, "API_Verifier: 'std::is_same_v<float, decltype(MeshletData::radius)>' evaluated to false.");

static_assert(alignof( decltype(MeshletData::coneApex)) == 4, "API_Verifier: 'alignof( decltype(MeshletData::coneApex)) == 4' evaluated to false.");
static_assert(offsetof( MeshletData, coneApex) == 16, "API_Verifier: 'offsetof( MeshletData, coneApex) == 16' evaluated to false.");
static_assert(sizeof(MeshletData::coneApex) == 12, "API_Verifier: 'sizeof(MeshletData::coneApex) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(MeshletData::coneApex)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(MeshletData::coneApex)>' evaluated to false.");

static_assert(alignof( decltype(MeshletData::coneAxis)) == 4, "API_Verifier: 'alignof( decltype(MeshletData::coneAxis)) == 4' evaluated to false.");
static_assert(offsetof( MeshletData, coneAxis) == 28, "API_Verifier: 'offsetof( MeshletData, coneAxis) == 28' evaluated to false.");
static_assert(sizeof(MeshletData::coneAxis) == 12, "API_Verifier: 'sizeof(MeshletData::coneAxis) == 12' evaluated to false.");
static_assert(std::is_same_v<Vectormath::float3, decltype(MeshletData::coneAxis)>, "API_Verifier: 'std::is_same_v<Vectormath::float3, decltype(MeshletData::coneAxis)>' evaluated to false.");

static_assert(alignof( decltype(MeshletData::coneCutoff)) == 4, "API_Verifier: 'alignof( decltype(MeshletData::coneCutoff)) == 4' evaluated to false.");
static_assert(offsetof( MeshletData, coneCutoff) == 40, "API_Verifier: 'offsetof( MeshletData, coneCutoff) == 40' evaluated to false.");
static_assert(sizeof(MeshletData::coneCutoff) == 4, "API_Verifier: 'sizeof(MeshletData::coneCutoff) == 4' evaluated to false.");
static_assert(std::is_same_v<float, decltype(MeshletData::coneCutoff)>, "API_Verifier: 'std::is_same_v<float, decltype(MeshletData::coneCutoff)>' evaluated to false.");

static_assert(alignof(GeometryMeshlets) == 8, "API_Verifier: 'alignof(GeometryMeshlets) == 8' evaluated to false.");
static_assert(sizeof(GeometryMeshlets) == 56, "API_Verifier: 'sizeof(GeometryMeshlets) == 56' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mMeshletCount)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mMeshletCount)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mMeshletCount) == 0, "API_Verifier: 'offsetof( GeometryMeshlets, mMeshletCount) == 0' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mMeshletCount) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mMeshletCount) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(GeometryMeshlets::mMeshletCount)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(GeometryMeshlets::mMeshletCount)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mMeshlets)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mMeshlets)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mMeshlets) == 8, "API_Verifier: 'offsetof( GeometryMeshlets, mMeshlets) == 8' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mMeshlets) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mMeshlets) == 8' evaluated to false.");
static_assert(std::is_same_v<Meshlet*, decltype(GeometryMeshlets::mMeshlets)>, "API_Verifier: 'std::is_same_v<Meshlet*, decltype(GeometryMeshlets::mMeshlets)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mMeshletsData)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mMeshletsData)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mMeshletsData) == 16, "API_Verifier: 'offsetof( GeometryMeshlets, mMeshletsData) == 16' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mMeshletsData) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mMeshletsData) == 8' evaluated to false.");
static_assert(std::is_same_v<MeshletData*, decltype(GeometryMeshlets::mMeshletsData)>, "API_Verifier: 'std::is_same_v<MeshletData*, decltype(GeometryMeshlets::mMeshletsData)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mVertexCount)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mVertexCount)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mVertexCount) == 24, "API_Verifier: 'offsetof( GeometryMeshlets, mVertexCount) == 24' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mVertexCount) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mVertexCount) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(GeometryMeshlets::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(GeometryMeshlets::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mVertices)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mVertices)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mVertices) == 32, "API_Verifier: 'offsetof( GeometryMeshlets, mVertices) == 32' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mVertices) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mVertices) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(GeometryMeshlets::mVertices)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(GeometryMeshlets::mVertices)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mTriangleCount)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mTriangleCount)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mTriangleCount) == 40, "API_Verifier: 'offsetof( GeometryMeshlets, mTriangleCount) == 40' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mTriangleCount) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mTriangleCount) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(GeometryMeshlets::mTriangleCount)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(GeometryMeshlets::mTriangleCount)>' evaluated to false.");

static_assert(alignof( decltype(GeometryMeshlets::mTriangles)) == 8, "API_Verifier: 'alignof( decltype(GeometryMeshlets::mTriangles)) == 8' evaluated to false.");
static_assert(offsetof( GeometryMeshlets, mTriangles) == 48, "API_Verifier: 'offsetof( GeometryMeshlets, mTriangles) == 48' evaluated to false.");
static_assert(sizeof(GeometryMeshlets::mTriangles) == 8, "API_Verifier: 'sizeof(GeometryMeshlets::mTriangles) == 8' evaluated to false.");
static_assert(std::is_same_v<uint8_t*, decltype(GeometryMeshlets::mTriangles)>, "API_Verifier: 'std::is_same_v<uint8_t*, decltype(GeometryMeshlets::mTriangles)>' evaluated to false.");

static_assert(alignof(Geometry) == 8, "API_Verifier: 'alignof(Geometry) == 8' evaluated to false.");
static_assert(sizeof(Geometry) == 352, "API_Verifier: 'sizeof(Geometry) == 352' evaluated to false.");

static_assert(alignof( decltype(Geometry::pDrawArgs)) == 8, "API_Verifier: 'alignof( decltype(Geometry::pDrawArgs)) == 8' evaluated to false.");
static_assert(offsetof( Geometry, pDrawArgs) == 128, "API_Verifier: 'offsetof( Geometry, pDrawArgs) == 128' evaluated to false.");
static_assert(sizeof(Geometry::pDrawArgs) == 8, "API_Verifier: 'sizeof(Geometry::pDrawArgs) == 8' evaluated to false.");
static_assert(std::is_same_v<IndirectDrawIndexArguments*, decltype(Geometry::pDrawArgs)>, "API_Verifier: 'std::is_same_v<IndirectDrawIndexArguments*, decltype(Geometry::pDrawArgs)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mVertexStrides)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mVertexStrides)) == 4' evaluated to false.");
static_assert(offsetof( Geometry, mVertexStrides) == 136, "API_Verifier: 'offsetof( Geometry, mVertexStrides) == 136' evaluated to false.");
static_assert(sizeof(Geometry::mVertexStrides) == 60, "API_Verifier: 'sizeof(Geometry::mVertexStrides) == 60' evaluated to false.");
static_assert(std::is_same_v<uint32_t[15], decltype(Geometry::mVertexStrides)>, "API_Verifier: 'std::is_same_v<uint32_t[15], decltype(Geometry::mVertexStrides)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mVertexBufferCount)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mVertexBufferCount)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Geometry::mVertexBufferCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Geometry::mVertexBufferCount)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mIndexType)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mIndexType)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Geometry::mIndexType)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Geometry::mIndexType)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mDrawArgCount)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mDrawArgCount)) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Geometry::mDrawArgCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Geometry::mDrawArgCount)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mIndexCount)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mIndexCount)) == 4' evaluated to false.");
static_assert(offsetof( Geometry, mIndexCount) == 200, "API_Verifier: 'offsetof( Geometry, mIndexCount) == 200' evaluated to false.");
static_assert(sizeof(Geometry::mIndexCount) == 4, "API_Verifier: 'sizeof(Geometry::mIndexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Geometry::mIndexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Geometry::mIndexCount)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mVertexCount)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mVertexCount)) == 4' evaluated to false.");
static_assert(offsetof( Geometry, mVertexCount) == 204, "API_Verifier: 'offsetof( Geometry, mVertexCount) == 204' evaluated to false.");
static_assert(sizeof(Geometry::mVertexCount) == 4, "API_Verifier: 'sizeof(Geometry::mVertexCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(Geometry::mVertexCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(Geometry::mVertexCount)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::pGeometryBuffer)) == 8, "API_Verifier: 'alignof( decltype(Geometry::pGeometryBuffer)) == 8' evaluated to false.");
static_assert(offsetof( Geometry, pGeometryBuffer) == 208, "API_Verifier: 'offsetof( Geometry, pGeometryBuffer) == 208' evaluated to false.");
static_assert(sizeof(Geometry::pGeometryBuffer) == 8, "API_Verifier: 'sizeof(Geometry::pGeometryBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryBuffer*, decltype(Geometry::pGeometryBuffer)>, "API_Verifier: 'std::is_same_v<GeometryBuffer*, decltype(Geometry::pGeometryBuffer)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::meshlets)) == 8, "API_Verifier: 'alignof( decltype(Geometry::meshlets)) == 8' evaluated to false.");
static_assert(offsetof( Geometry, meshlets) == 216, "API_Verifier: 'offsetof( Geometry, meshlets) == 216' evaluated to false.");
static_assert(sizeof(Geometry::meshlets) == 56, "API_Verifier: 'sizeof(Geometry::meshlets) == 56' evaluated to false.");
static_assert(std::is_same_v<GeometryMeshlets, decltype(Geometry::meshlets)>, "API_Verifier: 'std::is_same_v<GeometryMeshlets, decltype(Geometry::meshlets)>' evaluated to false.");

static_assert(alignof( decltype(Geometry::mPad)) == 4, "API_Verifier: 'alignof( decltype(Geometry::mPad)) == 4' evaluated to false.");
static_assert(offsetof( Geometry, mPad) == 272, "API_Verifier: 'offsetof( Geometry, mPad) == 272' evaluated to false.");
static_assert(sizeof(Geometry::mPad) == 80, "API_Verifier: 'sizeof(Geometry::mPad) == 80' evaluated to false.");
static_assert(std::is_same_v<uint32_t[20], decltype(Geometry::mPad)>, "API_Verifier: 'std::is_same_v<uint32_t[20], decltype(Geometry::mPad)>' evaluated to false.");

static_assert(alignof(GeometryData) == 8, "API_Verifier: 'alignof(GeometryData) == 8' evaluated to false.");
static_assert(sizeof(GeometryData) == 80, "API_Verifier: 'sizeof(GeometryData) == 80' evaluated to false.");

static_assert(alignof( decltype(GeometryData::pShadow)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::pShadow)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData, pShadow) == 0, "API_Verifier: 'offsetof( GeometryData, pShadow) == 0' evaluated to false.");
static_assert(sizeof(GeometryData::pShadow) == 8, "API_Verifier: 'sizeof(GeometryData::pShadow) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryData::GeometryData::ShadowData*, decltype(GeometryData::pShadow)>, "API_Verifier: 'std::is_same_v<GeometryData::GeometryData::ShadowData*, decltype(GeometryData::pShadow)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::pInverseBindPoses)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::pInverseBindPoses)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData, pInverseBindPoses) == 8, "API_Verifier: 'offsetof( GeometryData, pInverseBindPoses) == 8' evaluated to false.");
static_assert(sizeof(GeometryData::pInverseBindPoses) == 8, "API_Verifier: 'sizeof(GeometryData::pInverseBindPoses) == 8' evaluated to false.");
static_assert(std::is_same_v<mat4*, decltype(GeometryData::pInverseBindPoses)>, "API_Verifier: 'std::is_same_v<mat4*, decltype(GeometryData::pInverseBindPoses)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::pJointRemaps)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::pJointRemaps)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData, pJointRemaps) == 16, "API_Verifier: 'offsetof( GeometryData, pJointRemaps) == 16' evaluated to false.");
static_assert(sizeof(GeometryData::pJointRemaps) == 8, "API_Verifier: 'sizeof(GeometryData::pJointRemaps) == 8' evaluated to false.");
static_assert(std::is_same_v<uint32_t*, decltype(GeometryData::pJointRemaps)>, "API_Verifier: 'std::is_same_v<uint32_t*, decltype(GeometryData::pJointRemaps)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::mJointCount)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::mJointCount)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData, mJointCount) == 24, "API_Verifier: 'offsetof( GeometryData, mJointCount) == 24' evaluated to false.");
static_assert(sizeof(GeometryData::mJointCount) == 4, "API_Verifier: 'sizeof(GeometryData::mJointCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryData::mJointCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryData::mJointCount)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::mHair)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::mHair)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData, mHair) == 28, "API_Verifier: 'offsetof( GeometryData, mHair) == 28' evaluated to false.");
static_assert(sizeof(GeometryData::mHair) == 8, "API_Verifier: 'sizeof(GeometryData::mHair) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryData::GeometryData::Hair, decltype(GeometryData::mHair)>, "API_Verifier: 'std::is_same_v<GeometryData::GeometryData::Hair, decltype(GeometryData::mHair)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::mPad0)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::mPad0)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData, mPad0) == 36, "API_Verifier: 'offsetof( GeometryData, mPad0) == 36' evaluated to false.");
static_assert(sizeof(GeometryData::mPad0) == 4, "API_Verifier: 'sizeof(GeometryData::mPad0) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t[1], decltype(GeometryData::mPad0)>, "API_Verifier: 'std::is_same_v<uint32_t[1], decltype(GeometryData::mPad0)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::meshlets)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::meshlets)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData, meshlets) == 40, "API_Verifier: 'offsetof( GeometryData, meshlets) == 40' evaluated to false.");
static_assert(sizeof(GeometryData::meshlets) == 8, "API_Verifier: 'sizeof(GeometryData::meshlets) == 8' evaluated to false.");
static_assert(std::is_same_v<MeshletData*, decltype(GeometryData::meshlets)>, "API_Verifier: 'std::is_same_v<MeshletData*, decltype(GeometryData::meshlets)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::pUserData)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::pUserData)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData, pUserData) == 48, "API_Verifier: 'offsetof( GeometryData, pUserData) == 48' evaluated to false.");
static_assert(sizeof(GeometryData::pUserData) == 8, "API_Verifier: 'sizeof(GeometryData::pUserData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(GeometryData::pUserData)>, "API_Verifier: 'std::is_same_v<void *, decltype(GeometryData::pUserData)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::mUserDataSize)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::mUserDataSize)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData, mUserDataSize) == 56, "API_Verifier: 'offsetof( GeometryData, mUserDataSize) == 56' evaluated to false.");
static_assert(sizeof(GeometryData::mUserDataSize) == 4, "API_Verifier: 'sizeof(GeometryData::mUserDataSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryData::mUserDataSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryData::mUserDataSize)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::mPad1)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::mPad1)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData, mPad1) == 60, "API_Verifier: 'offsetof( GeometryData, mPad1) == 60' evaluated to false.");
static_assert(sizeof(GeometryData::mPad1) == 20, "API_Verifier: 'sizeof(GeometryData::mPad1) == 20' evaluated to false.");
static_assert(std::is_same_v<uint32_t[5], decltype(GeometryData::mPad1)>, "API_Verifier: 'std::is_same_v<uint32_t[5], decltype(GeometryData::mPad1)>' evaluated to false.");

static_assert(alignof(GeometryData::GeometryData::Hair) == 4, "API_Verifier: 'alignof(GeometryData::GeometryData::Hair) == 4' evaluated to false.");
static_assert(sizeof(GeometryData::GeometryData::Hair) == 8, "API_Verifier: 'sizeof(GeometryData::GeometryData::Hair) == 8' evaluated to false.");

static_assert(alignof( decltype(GeometryData::Hair::mVertexCountPerStrand)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::Hair::mVertexCountPerStrand)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::Hair, mVertexCountPerStrand) == 0, "API_Verifier: 'offsetof( GeometryData::GeometryData::Hair, mVertexCountPerStrand) == 0' evaluated to false.");
static_assert(sizeof(GeometryData::Hair::mVertexCountPerStrand) == 4, "API_Verifier: 'sizeof(GeometryData::Hair::mVertexCountPerStrand) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryData::Hair::mVertexCountPerStrand)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryData::Hair::mVertexCountPerStrand)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::Hair::mGuideCountPerStrand)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::Hair::mGuideCountPerStrand)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::Hair, mGuideCountPerStrand) == 4, "API_Verifier: 'offsetof( GeometryData::GeometryData::Hair, mGuideCountPerStrand) == 4' evaluated to false.");
static_assert(sizeof(GeometryData::Hair::mGuideCountPerStrand) == 4, "API_Verifier: 'sizeof(GeometryData::Hair::mGuideCountPerStrand) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryData::Hair::mGuideCountPerStrand)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryData::Hair::mGuideCountPerStrand)>' evaluated to false.");

static_assert(alignof(GeometryData::GeometryData::ShadowData) == 8, "API_Verifier: 'alignof(GeometryData::GeometryData::ShadowData) == 8' evaluated to false.");
static_assert(sizeof(GeometryData::GeometryData::ShadowData) == 312, "API_Verifier: 'sizeof(GeometryData::GeometryData::ShadowData) == 312' evaluated to false.");

static_assert(alignof( decltype(GeometryData::ShadowData::pIndices)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::ShadowData::pIndices)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::ShadowData, pIndices) == 0, "API_Verifier: 'offsetof( GeometryData::GeometryData::ShadowData, pIndices) == 0' evaluated to false.");
static_assert(sizeof(GeometryData::ShadowData::pIndices) == 8, "API_Verifier: 'sizeof(GeometryData::ShadowData::pIndices) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(GeometryData::ShadowData::pIndices)>, "API_Verifier: 'std::is_same_v<void *, decltype(GeometryData::ShadowData::pIndices)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::ShadowData::pAttributes)) == 8, "API_Verifier: 'alignof( decltype(GeometryData::ShadowData::pAttributes)) == 8' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::ShadowData, pAttributes) == 8, "API_Verifier: 'offsetof( GeometryData::GeometryData::ShadowData, pAttributes) == 8' evaluated to false.");
static_assert(sizeof(GeometryData::ShadowData::pAttributes) == 152, "API_Verifier: 'sizeof(GeometryData::ShadowData::pAttributes) == 152' evaluated to false.");
static_assert(std::is_same_v<void *[19], decltype(GeometryData::ShadowData::pAttributes)>, "API_Verifier: 'std::is_same_v<void *[19], decltype(GeometryData::ShadowData::pAttributes)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::ShadowData::mVertexStrides)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::ShadowData::mVertexStrides)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::ShadowData, mVertexStrides) == 160, "API_Verifier: 'offsetof( GeometryData::GeometryData::ShadowData, mVertexStrides) == 160' evaluated to false.");
static_assert(sizeof(GeometryData::ShadowData::mVertexStrides) == 76, "API_Verifier: 'sizeof(GeometryData::ShadowData::mVertexStrides) == 76' evaluated to false.");
static_assert(std::is_same_v<uint32_t[19], decltype(GeometryData::ShadowData::mVertexStrides)>, "API_Verifier: 'std::is_same_v<uint32_t[19], decltype(GeometryData::ShadowData::mVertexStrides)>' evaluated to false.");

static_assert(alignof( decltype(GeometryData::ShadowData::mAttributeCount)) == 4, "API_Verifier: 'alignof( decltype(GeometryData::ShadowData::mAttributeCount)) == 4' evaluated to false.");
static_assert(offsetof( GeometryData::GeometryData::ShadowData, mAttributeCount) == 236, "API_Verifier: 'offsetof( GeometryData::GeometryData::ShadowData, mAttributeCount) == 236' evaluated to false.");
static_assert(sizeof(GeometryData::ShadowData::mAttributeCount) == 76, "API_Verifier: 'sizeof(GeometryData::ShadowData::mAttributeCount) == 76' evaluated to false.");
static_assert(std::is_same_v<uint32_t[19], decltype(GeometryData::ShadowData::mAttributeCount)>, "API_Verifier: 'std::is_same_v<uint32_t[19], decltype(GeometryData::ShadowData::mAttributeCount)>' evaluated to false.");

static_assert(alignof(GeometryBufferLoadDesc) == 8, "API_Verifier: 'alignof(GeometryBufferLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc) == 336, "API_Verifier: 'sizeof(GeometryBufferLoadDesc) == 336' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::mStartState)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::mStartState)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, mStartState) == 0, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, mStartState) == 0' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::mStartState) == 4, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::mStartState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(GeometryBufferLoadDesc::mStartState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(GeometryBufferLoadDesc::mStartState)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::pNameIndexBuffer)) == 8, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::pNameIndexBuffer)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, pNameIndexBuffer) == 8, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, pNameIndexBuffer) == 8' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::pNameIndexBuffer) == 8, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::pNameIndexBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(GeometryBufferLoadDesc::pNameIndexBuffer)>, "API_Verifier: 'std::is_same_v<const char *, decltype(GeometryBufferLoadDesc::pNameIndexBuffer)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::pNamesVertexBuffers)) == 8, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::pNamesVertexBuffers)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, pNamesVertexBuffers) == 16, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, pNamesVertexBuffers) == 16' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::pNamesVertexBuffers) == 120, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::pNamesVertexBuffers) == 120' evaluated to false.");
static_assert(std::is_same_v<const char *[15], decltype(GeometryBufferLoadDesc::pNamesVertexBuffers)>, "API_Verifier: 'std::is_same_v<const char *[15], decltype(GeometryBufferLoadDesc::pNamesVertexBuffers)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::mIndicesSize)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::mIndicesSize)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, mIndicesSize) == 136, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, mIndicesSize) == 136' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::mIndicesSize) == 4, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::mIndicesSize) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryBufferLoadDesc::mIndicesSize)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryBufferLoadDesc::mIndicesSize)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::mVerticesSizes)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::mVerticesSizes)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, mVerticesSizes) == 140, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, mVerticesSizes) == 140' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::mVerticesSizes) == 60, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::mVerticesSizes) == 60' evaluated to false.");
static_assert(std::is_same_v<uint32_t[15], decltype(GeometryBufferLoadDesc::mVerticesSizes)>, "API_Verifier: 'std::is_same_v<uint32_t[15], decltype(GeometryBufferLoadDesc::mVerticesSizes)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::pIndicesPlacement)) == 8, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::pIndicesPlacement)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, pIndicesPlacement) == 200, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, pIndicesPlacement) == 200' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::pIndicesPlacement) == 8, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::pIndicesPlacement) == 8' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement*, decltype(GeometryBufferLoadDesc::pIndicesPlacement)>, "API_Verifier: 'std::is_same_v<ResourcePlacement*, decltype(GeometryBufferLoadDesc::pIndicesPlacement)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::pVerticesPlacements)) == 8, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::pVerticesPlacements)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, pVerticesPlacements) == 208, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, pVerticesPlacements) == 208' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::pVerticesPlacements) == 120, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::pVerticesPlacements) == 120' evaluated to false.");
static_assert(std::is_same_v<ResourcePlacement *[15], decltype(GeometryBufferLoadDesc::pVerticesPlacements)>, "API_Verifier: 'std::is_same_v<ResourcePlacement *[15], decltype(GeometryBufferLoadDesc::pVerticesPlacements)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLoadDesc::pOutGeometryBuffer)) == 8, "API_Verifier: 'alignof( decltype(GeometryBufferLoadDesc::pOutGeometryBuffer)) == 8' evaluated to false.");
static_assert(offsetof( GeometryBufferLoadDesc, pOutGeometryBuffer) == 328, "API_Verifier: 'offsetof( GeometryBufferLoadDesc, pOutGeometryBuffer) == 328' evaluated to false.");
static_assert(sizeof(GeometryBufferLoadDesc::pOutGeometryBuffer) == 8, "API_Verifier: 'sizeof(GeometryBufferLoadDesc::pOutGeometryBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryBuffer **, decltype(GeometryBufferLoadDesc::pOutGeometryBuffer)>, "API_Verifier: 'std::is_same_v<GeometryBuffer **, decltype(GeometryBufferLoadDesc::pOutGeometryBuffer)>' evaluated to false.");

static_assert(alignof(GeometryBufferLayoutDesc) == 4, "API_Verifier: 'alignof(GeometryBufferLayoutDesc) == 4' evaluated to false.");
static_assert(sizeof(GeometryBufferLayoutDesc) == 140, "API_Verifier: 'sizeof(GeometryBufferLayoutDesc) == 140' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLayoutDesc::mIndexType)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLayoutDesc::mIndexType)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLayoutDesc, mIndexType) == 0, "API_Verifier: 'offsetof( GeometryBufferLayoutDesc, mIndexType) == 0' evaluated to false.");
static_assert(sizeof(GeometryBufferLayoutDesc::mIndexType) == 4, "API_Verifier: 'sizeof(GeometryBufferLayoutDesc::mIndexType) == 4' evaluated to false.");
static_assert(std::is_same_v<IndexType, decltype(GeometryBufferLayoutDesc::mIndexType)>, "API_Verifier: 'std::is_same_v<IndexType, decltype(GeometryBufferLayoutDesc::mIndexType)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLayoutDesc::mVerticesStrides)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLayoutDesc::mVerticesStrides)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLayoutDesc, mVerticesStrides) == 4, "API_Verifier: 'offsetof( GeometryBufferLayoutDesc, mVerticesStrides) == 4' evaluated to false.");
static_assert(sizeof(GeometryBufferLayoutDesc::mVerticesStrides) == 60, "API_Verifier: 'sizeof(GeometryBufferLayoutDesc::mVerticesStrides) == 60' evaluated to false.");
static_assert(std::is_same_v<uint32_t[15], decltype(GeometryBufferLayoutDesc::mVerticesStrides)>, "API_Verifier: 'std::is_same_v<uint32_t[15], decltype(GeometryBufferLayoutDesc::mVerticesStrides)>' evaluated to false.");

static_assert(alignof( decltype(GeometryBufferLayoutDesc::mSemanticBindings)) == 4, "API_Verifier: 'alignof( decltype(GeometryBufferLayoutDesc::mSemanticBindings)) == 4' evaluated to false.");
static_assert(offsetof( GeometryBufferLayoutDesc, mSemanticBindings) == 64, "API_Verifier: 'offsetof( GeometryBufferLayoutDesc, mSemanticBindings) == 64' evaluated to false.");
static_assert(sizeof(GeometryBufferLayoutDesc::mSemanticBindings) == 76, "API_Verifier: 'sizeof(GeometryBufferLayoutDesc::mSemanticBindings) == 76' evaluated to false.");
static_assert(std::is_same_v<uint32_t[19], decltype(GeometryBufferLayoutDesc::mSemanticBindings)>, "API_Verifier: 'std::is_same_v<uint32_t[19], decltype(GeometryBufferLayoutDesc::mSemanticBindings)>' evaluated to false.");

static_assert(alignof(GeometryLoadDesc) == 8, "API_Verifier: 'alignof(GeometryLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc) == 56, "API_Verifier: 'sizeof(GeometryLoadDesc) == 56' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::ppGeometry)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::ppGeometry)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, ppGeometry) == 0, "API_Verifier: 'offsetof( GeometryLoadDesc, ppGeometry) == 0' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::ppGeometry) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::ppGeometry) == 8' evaluated to false.");
static_assert(std::is_same_v<Geometry **, decltype(GeometryLoadDesc::ppGeometry)>, "API_Verifier: 'std::is_same_v<Geometry **, decltype(GeometryLoadDesc::ppGeometry)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::ppGeometryData)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::ppGeometryData)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, ppGeometryData) == 8, "API_Verifier: 'offsetof( GeometryLoadDesc, ppGeometryData) == 8' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::ppGeometryData) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::ppGeometryData) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryData **, decltype(GeometryLoadDesc::ppGeometryData)>, "API_Verifier: 'std::is_same_v<GeometryData **, decltype(GeometryLoadDesc::ppGeometryData)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::pFileName)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::pFileName)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, pFileName) == 16, "API_Verifier: 'offsetof( GeometryLoadDesc, pFileName) == 16' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::pFileName) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::pFileName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(GeometryLoadDesc::pFileName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(GeometryLoadDesc::pFileName)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, mFlags) == 24, "API_Verifier: 'offsetof( GeometryLoadDesc, mFlags) == 24' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::mFlags) == 4, "API_Verifier: 'sizeof(GeometryLoadDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<GeometryLoadFlags, decltype(GeometryLoadDesc::mFlags)>, "API_Verifier: 'std::is_same_v<GeometryLoadFlags, decltype(GeometryLoadDesc::mFlags)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, mNodeIndex) == 28, "API_Verifier: 'offsetof( GeometryLoadDesc, mNodeIndex) == 28' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(GeometryLoadDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(GeometryLoadDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(GeometryLoadDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::pVertexLayout)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::pVertexLayout)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, pVertexLayout) == 32, "API_Verifier: 'offsetof( GeometryLoadDesc, pVertexLayout) == 32' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::pVertexLayout) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::pVertexLayout) == 8' evaluated to false.");
static_assert(std::is_same_v<const VertexLayout*, decltype(GeometryLoadDesc::pVertexLayout)>, "API_Verifier: 'std::is_same_v<const VertexLayout*, decltype(GeometryLoadDesc::pVertexLayout)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::pGeometryBuffer)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::pGeometryBuffer)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, pGeometryBuffer) == 40, "API_Verifier: 'offsetof( GeometryLoadDesc, pGeometryBuffer) == 40' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::pGeometryBuffer) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::pGeometryBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryBuffer*, decltype(GeometryLoadDesc::pGeometryBuffer)>, "API_Verifier: 'std::is_same_v<GeometryBuffer*, decltype(GeometryLoadDesc::pGeometryBuffer)>' evaluated to false.");

static_assert(alignof( decltype(GeometryLoadDesc::pGeometryBufferLayoutDesc)) == 8, "API_Verifier: 'alignof( decltype(GeometryLoadDesc::pGeometryBufferLayoutDesc)) == 8' evaluated to false.");
static_assert(offsetof( GeometryLoadDesc, pGeometryBufferLayoutDesc) == 48, "API_Verifier: 'offsetof( GeometryLoadDesc, pGeometryBufferLayoutDesc) == 48' evaluated to false.");
static_assert(sizeof(GeometryLoadDesc::pGeometryBufferLayoutDesc) == 8, "API_Verifier: 'sizeof(GeometryLoadDesc::pGeometryBufferLayoutDesc) == 8' evaluated to false.");
static_assert(std::is_same_v<GeometryBufferLayoutDesc*, decltype(GeometryLoadDesc::pGeometryBufferLayoutDesc)>, "API_Verifier: 'std::is_same_v<GeometryBufferLayoutDesc*, decltype(GeometryLoadDesc::pGeometryBufferLayoutDesc)>' evaluated to false.");

static_assert(alignof(BufferUpdateDesc) == 8, "API_Verifier: 'alignof(BufferUpdateDesc) == 8' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc) == 96, "API_Verifier: 'sizeof(BufferUpdateDesc) == 96' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, pBuffer) == 0, "API_Verifier: 'offsetof( BufferUpdateDesc, pBuffer) == 0' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::pBuffer) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferUpdateDesc::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferUpdateDesc::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::mDstOffset)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::mDstOffset)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, mDstOffset) == 8, "API_Verifier: 'offsetof( BufferUpdateDesc, mDstOffset) == 8' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::mDstOffset) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::mDstOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mDstOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mDstOffset)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::mSize)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::mSize)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, mSize) == 16, "API_Verifier: 'offsetof( BufferUpdateDesc, mSize) == 16' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::mSize) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::mSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mSize)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::pMappedData)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::pMappedData)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, pMappedData) == 24, "API_Verifier: 'offsetof( BufferUpdateDesc, pMappedData) == 24' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::pMappedData) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::pMappedData) == 8' evaluated to false.");
static_assert(std::is_same_v<void *, decltype(BufferUpdateDesc::pMappedData)>, "API_Verifier: 'std::is_same_v<void *, decltype(BufferUpdateDesc::pMappedData)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::pSrcBuffer)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::pSrcBuffer)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, pSrcBuffer) == 32, "API_Verifier: 'offsetof( BufferUpdateDesc, pSrcBuffer) == 32' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::pSrcBuffer) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::pSrcBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(BufferUpdateDesc::pSrcBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(BufferUpdateDesc::pSrcBuffer)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::mSrcOffset)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::mSrcOffset)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, mSrcOffset) == 40, "API_Verifier: 'offsetof( BufferUpdateDesc, mSrcOffset) == 40' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::mSrcOffset) == 8, "API_Verifier: 'sizeof(BufferUpdateDesc::mSrcOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mSrcOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(BufferUpdateDesc::mSrcOffset)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::mCurrentState)) == 4, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::mCurrentState)) == 4' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, mCurrentState) == 48, "API_Verifier: 'offsetof( BufferUpdateDesc, mCurrentState) == 48' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::mCurrentState) == 4, "API_Verifier: 'sizeof(BufferUpdateDesc::mCurrentState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(BufferUpdateDesc::mCurrentState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(BufferUpdateDesc::mCurrentState)>' evaluated to false.");

static_assert(alignof( decltype(BufferUpdateDesc::mInternal)) == 8, "API_Verifier: 'alignof( decltype(BufferUpdateDesc::mInternal)) == 8' evaluated to false.");
static_assert(offsetof( BufferUpdateDesc, mInternal) == 56, "API_Verifier: 'offsetof( BufferUpdateDesc, mInternal) == 56' evaluated to false.");
static_assert(sizeof(BufferUpdateDesc::mInternal) == 40, "API_Verifier: 'sizeof(BufferUpdateDesc::mInternal) == 40' evaluated to false.");

static_assert(alignof(decltype(BufferUpdateDesc::mInternal)) == 8, "API_Verifier: 'alignof(decltype(BufferUpdateDesc::mInternal)) == 8' evaluated to false.");
static_assert(sizeof(decltype(BufferUpdateDesc::mInternal)) == 40, "API_Verifier: 'sizeof(decltype(BufferUpdateDesc::mInternal)) == 40' evaluated to false.");

static_assert(alignof( decltype(decltype(BufferUpdateDesc::mInternal)::mMappedRange)) == 8, "API_Verifier: 'alignof( decltype(decltype(BufferUpdateDesc::mInternal)::mMappedRange)) == 8' evaluated to false.");
static_assert(offsetof( decltype(BufferUpdateDesc::mInternal), mMappedRange) == 0, "API_Verifier: 'offsetof( decltype(BufferUpdateDesc::mInternal), mMappedRange) == 0' evaluated to false.");
static_assert(sizeof(decltype(BufferUpdateDesc::mInternal)::mMappedRange) == 40, "API_Verifier: 'sizeof(decltype(BufferUpdateDesc::mInternal)::mMappedRange) == 40' evaluated to false.");
static_assert(std::is_same_v<MappedMemoryRange, decltype(decltype(BufferUpdateDesc::mInternal)::mMappedRange)>, "API_Verifier: 'std::is_same_v<MappedMemoryRange, decltype(decltype(BufferUpdateDesc::mInternal)::mMappedRange)>' evaluated to false.");

static_assert(alignof(TextureSubresourceUpdate) == 8, "API_Verifier: 'alignof(TextureSubresourceUpdate) == 8' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate) == 32, "API_Verifier: 'sizeof(TextureSubresourceUpdate) == 32' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::mDstRowStride)) == 4, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::mDstRowStride)) == 4' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, mDstRowStride) == 0, "API_Verifier: 'offsetof( TextureSubresourceUpdate, mDstRowStride) == 0' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::mDstRowStride) == 4, "API_Verifier: 'sizeof(TextureSubresourceUpdate::mDstRowStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mDstRowStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mDstRowStride)>' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::mRowCount)) == 4, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::mRowCount)) == 4' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, mRowCount) == 4, "API_Verifier: 'offsetof( TextureSubresourceUpdate, mRowCount) == 4' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::mRowCount) == 4, "API_Verifier: 'sizeof(TextureSubresourceUpdate::mRowCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mRowCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mRowCount)>' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::mSrcRowStride)) == 4, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::mSrcRowStride)) == 4' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, mSrcRowStride) == 8, "API_Verifier: 'offsetof( TextureSubresourceUpdate, mSrcRowStride) == 8' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::mSrcRowStride) == 4, "API_Verifier: 'sizeof(TextureSubresourceUpdate::mSrcRowStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mSrcRowStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mSrcRowStride)>' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::mDstSliceStride)) == 4, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::mDstSliceStride)) == 4' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, mDstSliceStride) == 12, "API_Verifier: 'offsetof( TextureSubresourceUpdate, mDstSliceStride) == 12' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::mDstSliceStride) == 4, "API_Verifier: 'sizeof(TextureSubresourceUpdate::mDstSliceStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mDstSliceStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mDstSliceStride)>' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::mSrcSliceStride)) == 4, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::mSrcSliceStride)) == 4' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, mSrcSliceStride) == 16, "API_Verifier: 'offsetof( TextureSubresourceUpdate, mSrcSliceStride) == 16' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::mSrcSliceStride) == 4, "API_Verifier: 'sizeof(TextureSubresourceUpdate::mSrcSliceStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mSrcSliceStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureSubresourceUpdate::mSrcSliceStride)>' evaluated to false.");

static_assert(alignof( decltype(TextureSubresourceUpdate::pMappedData)) == 8, "API_Verifier: 'alignof( decltype(TextureSubresourceUpdate::pMappedData)) == 8' evaluated to false.");
static_assert(offsetof( TextureSubresourceUpdate, pMappedData) == 24, "API_Verifier: 'offsetof( TextureSubresourceUpdate, pMappedData) == 24' evaluated to false.");
static_assert(sizeof(TextureSubresourceUpdate::pMappedData) == 8, "API_Verifier: 'sizeof(TextureSubresourceUpdate::pMappedData) == 8' evaluated to false.");
static_assert(std::is_same_v<uint8_t*, decltype(TextureSubresourceUpdate::pMappedData)>, "API_Verifier: 'std::is_same_v<uint8_t*, decltype(TextureSubresourceUpdate::pMappedData)>' evaluated to false.");

static_assert(alignof(TextureUpdateDesc) == 8, "API_Verifier: 'alignof(TextureUpdateDesc) == 8' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc) == 88, "API_Verifier: 'sizeof(TextureUpdateDesc) == 88' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::pTexture)) == 8, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::pTexture)) == 8' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, pTexture) == 0, "API_Verifier: 'offsetof( TextureUpdateDesc, pTexture) == 0' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::pTexture) == 8, "API_Verifier: 'sizeof(TextureUpdateDesc::pTexture) == 8' evaluated to false.");
static_assert(std::is_same_v<Texture*, decltype(TextureUpdateDesc::pTexture)>, "API_Verifier: 'std::is_same_v<Texture*, decltype(TextureUpdateDesc::pTexture)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mBaseMipLevel)) == 4, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mBaseMipLevel)) == 4' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mBaseMipLevel) == 8, "API_Verifier: 'offsetof( TextureUpdateDesc, mBaseMipLevel) == 8' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mBaseMipLevel) == 4, "API_Verifier: 'sizeof(TextureUpdateDesc::mBaseMipLevel) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mBaseMipLevel)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mBaseMipLevel)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mMipLevels)) == 4, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mMipLevels)) == 4' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mMipLevels) == 12, "API_Verifier: 'offsetof( TextureUpdateDesc, mMipLevels) == 12' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mMipLevels) == 4, "API_Verifier: 'sizeof(TextureUpdateDesc::mMipLevels) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mMipLevels)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mMipLevels)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mBaseArrayLayer)) == 4, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mBaseArrayLayer)) == 4' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mBaseArrayLayer) == 16, "API_Verifier: 'offsetof( TextureUpdateDesc, mBaseArrayLayer) == 16' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mBaseArrayLayer) == 4, "API_Verifier: 'sizeof(TextureUpdateDesc::mBaseArrayLayer) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mBaseArrayLayer)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mBaseArrayLayer)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mLayerCount)) == 4, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mLayerCount)) == 4' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mLayerCount) == 20, "API_Verifier: 'offsetof( TextureUpdateDesc, mLayerCount) == 20' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mLayerCount) == 4, "API_Verifier: 'sizeof(TextureUpdateDesc::mLayerCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mLayerCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureUpdateDesc::mLayerCount)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mCurrentState)) == 4, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mCurrentState)) == 4' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mCurrentState) == 24, "API_Verifier: 'offsetof( TextureUpdateDesc, mCurrentState) == 24' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mCurrentState) == 4, "API_Verifier: 'sizeof(TextureUpdateDesc::mCurrentState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(TextureUpdateDesc::mCurrentState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(TextureUpdateDesc::mCurrentState)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::pCmd)) == 8, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::pCmd)) == 8' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, pCmd) == 32, "API_Verifier: 'offsetof( TextureUpdateDesc, pCmd) == 32' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::pCmd) == 8, "API_Verifier: 'sizeof(TextureUpdateDesc::pCmd) == 8' evaluated to false.");
static_assert(std::is_same_v<Cmd*, decltype(TextureUpdateDesc::pCmd)>, "API_Verifier: 'std::is_same_v<Cmd*, decltype(TextureUpdateDesc::pCmd)>' evaluated to false.");

static_assert(alignof( decltype(TextureUpdateDesc::mInternal)) == 8, "API_Verifier: 'alignof( decltype(TextureUpdateDesc::mInternal)) == 8' evaluated to false.");
static_assert(offsetof( TextureUpdateDesc, mInternal) == 40, "API_Verifier: 'offsetof( TextureUpdateDesc, mInternal) == 40' evaluated to false.");
static_assert(sizeof(TextureUpdateDesc::mInternal) == 48, "API_Verifier: 'sizeof(TextureUpdateDesc::mInternal) == 48' evaluated to false.");

static_assert(alignof(decltype(TextureUpdateDesc::mInternal)) == 8, "API_Verifier: 'alignof(decltype(TextureUpdateDesc::mInternal)) == 8' evaluated to false.");
static_assert(sizeof(decltype(TextureUpdateDesc::mInternal)) == 48, "API_Verifier: 'sizeof(decltype(TextureUpdateDesc::mInternal)) == 48' evaluated to false.");

static_assert(alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mMappedRange)) == 8, "API_Verifier: 'alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mMappedRange)) == 8' evaluated to false.");
static_assert(offsetof( decltype(TextureUpdateDesc::mInternal), mMappedRange) == 0, "API_Verifier: 'offsetof( decltype(TextureUpdateDesc::mInternal), mMappedRange) == 0' evaluated to false.");
static_assert(sizeof(decltype(TextureUpdateDesc::mInternal)::mMappedRange) == 40, "API_Verifier: 'sizeof(decltype(TextureUpdateDesc::mInternal)::mMappedRange) == 40' evaluated to false.");
static_assert(std::is_same_v<MappedMemoryRange, decltype(decltype(TextureUpdateDesc::mInternal)::mMappedRange)>, "API_Verifier: 'std::is_same_v<MappedMemoryRange, decltype(decltype(TextureUpdateDesc::mInternal)::mMappedRange)>' evaluated to false.");

static_assert(alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride)) == 4, "API_Verifier: 'alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride)) == 4' evaluated to false.");
static_assert(offsetof( decltype(TextureUpdateDesc::mInternal), mDstSliceStride) == 40, "API_Verifier: 'offsetof( decltype(TextureUpdateDesc::mInternal), mDstSliceStride) == 40' evaluated to false.");
static_assert(sizeof(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride) == 4, "API_Verifier: 'sizeof(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(decltype(TextureUpdateDesc::mInternal)::mDstSliceStride)>' evaluated to false.");

static_assert(alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier)) == 1, "API_Verifier: 'alignof( decltype(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier)) == 1' evaluated to false.");
static_assert(offsetof( decltype(TextureUpdateDesc::mInternal), mSkipBarrier) == 44, "API_Verifier: 'offsetof( decltype(TextureUpdateDesc::mInternal), mSkipBarrier) == 44' evaluated to false.");
static_assert(sizeof(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier) == 1, "API_Verifier: 'sizeof(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier)>, "API_Verifier: 'std::is_same_v<bool, decltype(decltype(TextureUpdateDesc::mInternal)::mSkipBarrier)>' evaluated to false.");

static_assert(alignof(TextureCopyDesc) == 8, "API_Verifier: 'alignof(TextureCopyDesc) == 8' evaluated to false.");
static_assert(sizeof(TextureCopyDesc) == 48, "API_Verifier: 'sizeof(TextureCopyDesc) == 48' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::pTexture)) == 8, "API_Verifier: 'alignof( decltype(TextureCopyDesc::pTexture)) == 8' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, pTexture) == 0, "API_Verifier: 'offsetof( TextureCopyDesc, pTexture) == 0' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::pTexture) == 8, "API_Verifier: 'sizeof(TextureCopyDesc::pTexture) == 8' evaluated to false.");
static_assert(std::is_same_v<Texture*, decltype(TextureCopyDesc::pTexture)>, "API_Verifier: 'std::is_same_v<Texture*, decltype(TextureCopyDesc::pTexture)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::pBuffer)) == 8, "API_Verifier: 'alignof( decltype(TextureCopyDesc::pBuffer)) == 8' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, pBuffer) == 8, "API_Verifier: 'offsetof( TextureCopyDesc, pBuffer) == 8' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::pBuffer) == 8, "API_Verifier: 'sizeof(TextureCopyDesc::pBuffer) == 8' evaluated to false.");
static_assert(std::is_same_v<Buffer*, decltype(TextureCopyDesc::pBuffer)>, "API_Verifier: 'std::is_same_v<Buffer*, decltype(TextureCopyDesc::pBuffer)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::pWaitSemaphore)) == 8, "API_Verifier: 'alignof( decltype(TextureCopyDesc::pWaitSemaphore)) == 8' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, pWaitSemaphore) == 16, "API_Verifier: 'offsetof( TextureCopyDesc, pWaitSemaphore) == 16' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::pWaitSemaphore) == 8, "API_Verifier: 'sizeof(TextureCopyDesc::pWaitSemaphore) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore*, decltype(TextureCopyDesc::pWaitSemaphore)>, "API_Verifier: 'std::is_same_v<Semaphore*, decltype(TextureCopyDesc::pWaitSemaphore)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::mTextureMipLevel)) == 4, "API_Verifier: 'alignof( decltype(TextureCopyDesc::mTextureMipLevel)) == 4' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, mTextureMipLevel) == 24, "API_Verifier: 'offsetof( TextureCopyDesc, mTextureMipLevel) == 24' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::mTextureMipLevel) == 4, "API_Verifier: 'sizeof(TextureCopyDesc::mTextureMipLevel) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureCopyDesc::mTextureMipLevel)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureCopyDesc::mTextureMipLevel)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::mTextureArrayLayer)) == 4, "API_Verifier: 'alignof( decltype(TextureCopyDesc::mTextureArrayLayer)) == 4' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, mTextureArrayLayer) == 28, "API_Verifier: 'offsetof( TextureCopyDesc, mTextureArrayLayer) == 28' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::mTextureArrayLayer) == 4, "API_Verifier: 'sizeof(TextureCopyDesc::mTextureArrayLayer) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(TextureCopyDesc::mTextureArrayLayer)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(TextureCopyDesc::mTextureArrayLayer)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::mTextureState)) == 4, "API_Verifier: 'alignof( decltype(TextureCopyDesc::mTextureState)) == 4' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, mTextureState) == 32, "API_Verifier: 'offsetof( TextureCopyDesc, mTextureState) == 32' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::mTextureState) == 4, "API_Verifier: 'sizeof(TextureCopyDesc::mTextureState) == 4' evaluated to false.");
static_assert(std::is_same_v<ResourceState, decltype(TextureCopyDesc::mTextureState)>, "API_Verifier: 'std::is_same_v<ResourceState, decltype(TextureCopyDesc::mTextureState)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::mQueueType)) == 4, "API_Verifier: 'alignof( decltype(TextureCopyDesc::mQueueType)) == 4' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, mQueueType) == 36, "API_Verifier: 'offsetof( TextureCopyDesc, mQueueType) == 36' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::mQueueType) == 4, "API_Verifier: 'sizeof(TextureCopyDesc::mQueueType) == 4' evaluated to false.");
static_assert(std::is_same_v<QueueType, decltype(TextureCopyDesc::mQueueType)>, "API_Verifier: 'std::is_same_v<QueueType, decltype(TextureCopyDesc::mQueueType)>' evaluated to false.");

static_assert(alignof( decltype(TextureCopyDesc::mBufferOffset)) == 8, "API_Verifier: 'alignof( decltype(TextureCopyDesc::mBufferOffset)) == 8' evaluated to false.");
static_assert(offsetof( TextureCopyDesc, mBufferOffset) == 40, "API_Verifier: 'offsetof( TextureCopyDesc, mBufferOffset) == 40' evaluated to false.");
static_assert(sizeof(TextureCopyDesc::mBufferOffset) == 8, "API_Verifier: 'sizeof(TextureCopyDesc::mBufferOffset) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(TextureCopyDesc::mBufferOffset)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(TextureCopyDesc::mBufferOffset)>' evaluated to false.");

static_assert(alignof(ShaderStageLoadDesc) == 8, "API_Verifier: 'alignof(ShaderStageLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(ShaderStageLoadDesc) == 16, "API_Verifier: 'sizeof(ShaderStageLoadDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(ShaderStageLoadDesc::pFileName)) == 8, "API_Verifier: 'alignof( decltype(ShaderStageLoadDesc::pFileName)) == 8' evaluated to false.");
static_assert(offsetof( ShaderStageLoadDesc, pFileName) == 0, "API_Verifier: 'offsetof( ShaderStageLoadDesc, pFileName) == 0' evaluated to false.");
static_assert(sizeof(ShaderStageLoadDesc::pFileName) == 8, "API_Verifier: 'sizeof(ShaderStageLoadDesc::pFileName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(ShaderStageLoadDesc::pFileName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(ShaderStageLoadDesc::pFileName)>' evaluated to false.");

static_assert(alignof( decltype(ShaderStageLoadDesc::pEntryPointName)) == 8, "API_Verifier: 'alignof( decltype(ShaderStageLoadDesc::pEntryPointName)) == 8' evaluated to false.");
static_assert(offsetof( ShaderStageLoadDesc, pEntryPointName) == 8, "API_Verifier: 'offsetof( ShaderStageLoadDesc, pEntryPointName) == 8' evaluated to false.");
static_assert(sizeof(ShaderStageLoadDesc::pEntryPointName) == 8, "API_Verifier: 'sizeof(ShaderStageLoadDesc::pEntryPointName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(ShaderStageLoadDesc::pEntryPointName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(ShaderStageLoadDesc::pEntryPointName)>' evaluated to false.");

static_assert(alignof(ShaderLoadDesc) == 8, "API_Verifier: 'alignof(ShaderLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(ShaderLoadDesc) == 112, "API_Verifier: 'sizeof(ShaderLoadDesc) == 112' evaluated to false.");

static_assert(alignof( decltype(ShaderLoadDesc::mStages)) == 8, "API_Verifier: 'alignof( decltype(ShaderLoadDesc::mStages)) == 8' evaluated to false.");
static_assert(offsetof( ShaderLoadDesc, mStages) == 0, "API_Verifier: 'offsetof( ShaderLoadDesc, mStages) == 0' evaluated to false.");
static_assert(sizeof(ShaderLoadDesc::mStages) == 96, "API_Verifier: 'sizeof(ShaderLoadDesc::mStages) == 96' evaluated to false.");
static_assert(std::is_same_v<ShaderStageLoadDesc[6], decltype(ShaderLoadDesc::mStages)>, "API_Verifier: 'std::is_same_v<ShaderStageLoadDesc[6], decltype(ShaderLoadDesc::mStages)>' evaluated to false.");

static_assert(alignof( decltype(ShaderLoadDesc::pConstants)) == 8, "API_Verifier: 'alignof( decltype(ShaderLoadDesc::pConstants)) == 8' evaluated to false.");
static_assert(offsetof( ShaderLoadDesc, pConstants) == 96, "API_Verifier: 'offsetof( ShaderLoadDesc, pConstants) == 96' evaluated to false.");
static_assert(sizeof(ShaderLoadDesc::pConstants) == 8, "API_Verifier: 'sizeof(ShaderLoadDesc::pConstants) == 8' evaluated to false.");
static_assert(std::is_same_v<const ShaderConstant*, decltype(ShaderLoadDesc::pConstants)>, "API_Verifier: 'std::is_same_v<const ShaderConstant*, decltype(ShaderLoadDesc::pConstants)>' evaluated to false.");

static_assert(alignof( decltype(ShaderLoadDesc::mConstantCount)) == 4, "API_Verifier: 'alignof( decltype(ShaderLoadDesc::mConstantCount)) == 4' evaluated to false.");
static_assert(offsetof( ShaderLoadDesc, mConstantCount) == 104, "API_Verifier: 'offsetof( ShaderLoadDesc, mConstantCount) == 104' evaluated to false.");
static_assert(sizeof(ShaderLoadDesc::mConstantCount) == 4, "API_Verifier: 'sizeof(ShaderLoadDesc::mConstantCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ShaderLoadDesc::mConstantCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ShaderLoadDesc::mConstantCount)>' evaluated to false.");

static_assert(alignof(PipelineCacheLoadDesc) == 8, "API_Verifier: 'alignof(PipelineCacheLoadDesc) == 8' evaluated to false.");
static_assert(sizeof(PipelineCacheLoadDesc) == 16, "API_Verifier: 'sizeof(PipelineCacheLoadDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheLoadDesc::pFileName)) == 8, "API_Verifier: 'alignof( decltype(PipelineCacheLoadDesc::pFileName)) == 8' evaluated to false.");
static_assert(offsetof( PipelineCacheLoadDesc, pFileName) == 0, "API_Verifier: 'offsetof( PipelineCacheLoadDesc, pFileName) == 0' evaluated to false.");
static_assert(sizeof(PipelineCacheLoadDesc::pFileName) == 8, "API_Verifier: 'sizeof(PipelineCacheLoadDesc::pFileName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(PipelineCacheLoadDesc::pFileName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(PipelineCacheLoadDesc::pFileName)>' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheLoadDesc::mFlags)) == 4, "API_Verifier: 'alignof( decltype(PipelineCacheLoadDesc::mFlags)) == 4' evaluated to false.");
static_assert(offsetof( PipelineCacheLoadDesc, mFlags) == 8, "API_Verifier: 'offsetof( PipelineCacheLoadDesc, mFlags) == 8' evaluated to false.");
static_assert(sizeof(PipelineCacheLoadDesc::mFlags) == 4, "API_Verifier: 'sizeof(PipelineCacheLoadDesc::mFlags) == 4' evaluated to false.");
static_assert(std::is_same_v<PipelineCacheFlags, decltype(PipelineCacheLoadDesc::mFlags)>, "API_Verifier: 'std::is_same_v<PipelineCacheFlags, decltype(PipelineCacheLoadDesc::mFlags)>' evaluated to false.");

static_assert(alignof(PipelineCacheSaveDesc) == 8, "API_Verifier: 'alignof(PipelineCacheSaveDesc) == 8' evaluated to false.");
static_assert(sizeof(PipelineCacheSaveDesc) == 8, "API_Verifier: 'sizeof(PipelineCacheSaveDesc) == 8' evaluated to false.");

static_assert(alignof( decltype(PipelineCacheSaveDesc::pFileName)) == 8, "API_Verifier: 'alignof( decltype(PipelineCacheSaveDesc::pFileName)) == 8' evaluated to false.");
static_assert(offsetof( PipelineCacheSaveDesc, pFileName) == 0, "API_Verifier: 'offsetof( PipelineCacheSaveDesc, pFileName) == 0' evaluated to false.");
static_assert(sizeof(PipelineCacheSaveDesc::pFileName) == 8, "API_Verifier: 'sizeof(PipelineCacheSaveDesc::pFileName) == 8' evaluated to false.");
static_assert(std::is_same_v<const char *, decltype(PipelineCacheSaveDesc::pFileName)>, "API_Verifier: 'std::is_same_v<const char *, decltype(PipelineCacheSaveDesc::pFileName)>' evaluated to false.");

static_assert(alignof(ResourceLoaderDesc) == 8, "API_Verifier: 'alignof(ResourceLoaderDesc) == 8' evaluated to false.");
static_assert(sizeof(ResourceLoaderDesc) == 16, "API_Verifier: 'sizeof(ResourceLoaderDesc) == 16' evaluated to false.");

static_assert(alignof( decltype(ResourceLoaderDesc::mBufferSize)) == 8, "API_Verifier: 'alignof( decltype(ResourceLoaderDesc::mBufferSize)) == 8' evaluated to false.");
static_assert(offsetof( ResourceLoaderDesc, mBufferSize) == 0, "API_Verifier: 'offsetof( ResourceLoaderDesc, mBufferSize) == 0' evaluated to false.");
static_assert(sizeof(ResourceLoaderDesc::mBufferSize) == 8, "API_Verifier: 'sizeof(ResourceLoaderDesc::mBufferSize) == 8' evaluated to false.");
static_assert(std::is_same_v<uint64_t, decltype(ResourceLoaderDesc::mBufferSize)>, "API_Verifier: 'std::is_same_v<uint64_t, decltype(ResourceLoaderDesc::mBufferSize)>' evaluated to false.");

static_assert(alignof( decltype(ResourceLoaderDesc::mBufferCount)) == 4, "API_Verifier: 'alignof( decltype(ResourceLoaderDesc::mBufferCount)) == 4' evaluated to false.");
static_assert(offsetof( ResourceLoaderDesc, mBufferCount) == 8, "API_Verifier: 'offsetof( ResourceLoaderDesc, mBufferCount) == 8' evaluated to false.");
static_assert(sizeof(ResourceLoaderDesc::mBufferCount) == 4, "API_Verifier: 'sizeof(ResourceLoaderDesc::mBufferCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(ResourceLoaderDesc::mBufferCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(ResourceLoaderDesc::mBufferCount)>' evaluated to false.");

static_assert(alignof( decltype(ResourceLoaderDesc::mSingleThreaded)) == 1, "API_Verifier: 'alignof( decltype(ResourceLoaderDesc::mSingleThreaded)) == 1' evaluated to false.");
static_assert(offsetof( ResourceLoaderDesc, mSingleThreaded) == 12, "API_Verifier: 'offsetof( ResourceLoaderDesc, mSingleThreaded) == 12' evaluated to false.");
static_assert(sizeof(ResourceLoaderDesc::mSingleThreaded) == 1, "API_Verifier: 'sizeof(ResourceLoaderDesc::mSingleThreaded) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(ResourceLoaderDesc::mSingleThreaded)>, "API_Verifier: 'std::is_same_v<bool, decltype(ResourceLoaderDesc::mSingleThreaded)>' evaluated to false.");

static_assert(alignof( decltype(ResourceLoaderDesc::mUseMaterials)) == 1, "API_Verifier: 'alignof( decltype(ResourceLoaderDesc::mUseMaterials)) == 1' evaluated to false.");
static_assert(offsetof( ResourceLoaderDesc, mUseMaterials) == 13, "API_Verifier: 'offsetof( ResourceLoaderDesc, mUseMaterials) == 13' evaluated to false.");
static_assert(sizeof(ResourceLoaderDesc::mUseMaterials) == 1, "API_Verifier: 'sizeof(ResourceLoaderDesc::mUseMaterials) == 1' evaluated to false.");
static_assert(std::is_same_v<bool, decltype(ResourceLoaderDesc::mUseMaterials)>, "API_Verifier: 'std::is_same_v<bool, decltype(ResourceLoaderDesc::mUseMaterials)>' evaluated to false.");

static_assert(alignof(FlushResourceUpdateDesc) == 8, "API_Verifier: 'alignof(FlushResourceUpdateDesc) == 8' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc) == 32, "API_Verifier: 'sizeof(FlushResourceUpdateDesc) == 32' evaluated to false.");

static_assert(alignof( decltype(FlushResourceUpdateDesc::mNodeIndex)) == 4, "API_Verifier: 'alignof( decltype(FlushResourceUpdateDesc::mNodeIndex)) == 4' evaluated to false.");
static_assert(offsetof( FlushResourceUpdateDesc, mNodeIndex) == 0, "API_Verifier: 'offsetof( FlushResourceUpdateDesc, mNodeIndex) == 0' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc::mNodeIndex) == 4, "API_Verifier: 'sizeof(FlushResourceUpdateDesc::mNodeIndex) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FlushResourceUpdateDesc::mNodeIndex)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FlushResourceUpdateDesc::mNodeIndex)>' evaluated to false.");

static_assert(alignof( decltype(FlushResourceUpdateDesc::mWaitSemaphoreCount)) == 4, "API_Verifier: 'alignof( decltype(FlushResourceUpdateDesc::mWaitSemaphoreCount)) == 4' evaluated to false.");
static_assert(offsetof( FlushResourceUpdateDesc, mWaitSemaphoreCount) == 4, "API_Verifier: 'offsetof( FlushResourceUpdateDesc, mWaitSemaphoreCount) == 4' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc::mWaitSemaphoreCount) == 4, "API_Verifier: 'sizeof(FlushResourceUpdateDesc::mWaitSemaphoreCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(FlushResourceUpdateDesc::mWaitSemaphoreCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(FlushResourceUpdateDesc::mWaitSemaphoreCount)>' evaluated to false.");

static_assert(alignof( decltype(FlushResourceUpdateDesc::ppWaitSemaphores)) == 8, "API_Verifier: 'alignof( decltype(FlushResourceUpdateDesc::ppWaitSemaphores)) == 8' evaluated to false.");
static_assert(offsetof( FlushResourceUpdateDesc, ppWaitSemaphores) == 8, "API_Verifier: 'offsetof( FlushResourceUpdateDesc, ppWaitSemaphores) == 8' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc::ppWaitSemaphores) == 8, "API_Verifier: 'sizeof(FlushResourceUpdateDesc::ppWaitSemaphores) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore **, decltype(FlushResourceUpdateDesc::ppWaitSemaphores)>, "API_Verifier: 'std::is_same_v<Semaphore **, decltype(FlushResourceUpdateDesc::ppWaitSemaphores)>' evaluated to false.");

static_assert(alignof( decltype(FlushResourceUpdateDesc::pOutFence)) == 8, "API_Verifier: 'alignof( decltype(FlushResourceUpdateDesc::pOutFence)) == 8' evaluated to false.");
static_assert(offsetof( FlushResourceUpdateDesc, pOutFence) == 16, "API_Verifier: 'offsetof( FlushResourceUpdateDesc, pOutFence) == 16' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc::pOutFence) == 8, "API_Verifier: 'sizeof(FlushResourceUpdateDesc::pOutFence) == 8' evaluated to false.");
static_assert(std::is_same_v<Fence*, decltype(FlushResourceUpdateDesc::pOutFence)>, "API_Verifier: 'std::is_same_v<Fence*, decltype(FlushResourceUpdateDesc::pOutFence)>' evaluated to false.");

static_assert(alignof( decltype(FlushResourceUpdateDesc::pOutSubmittedSemaphore)) == 8, "API_Verifier: 'alignof( decltype(FlushResourceUpdateDesc::pOutSubmittedSemaphore)) == 8' evaluated to false.");
static_assert(offsetof( FlushResourceUpdateDesc, pOutSubmittedSemaphore) == 24, "API_Verifier: 'offsetof( FlushResourceUpdateDesc, pOutSubmittedSemaphore) == 24' evaluated to false.");
static_assert(sizeof(FlushResourceUpdateDesc::pOutSubmittedSemaphore) == 8, "API_Verifier: 'sizeof(FlushResourceUpdateDesc::pOutSubmittedSemaphore) == 8' evaluated to false.");
static_assert(std::is_same_v<Semaphore*, decltype(FlushResourceUpdateDesc::pOutSubmittedSemaphore)>, "API_Verifier: 'std::is_same_v<Semaphore*, decltype(FlushResourceUpdateDesc::pOutSubmittedSemaphore)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Utilities\Interfaces\ITime.h"

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Utilities\Interfaces\IFileSystem.h"

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Utilities\Interfaces\ILog.h"

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Utilities\Interfaces\IMemory.h"

static_assert(alignof(MemoryStatistics) == 4, "API_Verifier: 'alignof(MemoryStatistics) == 4' evaluated to false.");
static_assert(sizeof(MemoryStatistics) == 36, "API_Verifier: 'sizeof(MemoryStatistics) == 36' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::totalReportedMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::totalReportedMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, totalReportedMemory) == 0, "API_Verifier: 'offsetof( MemoryStatistics, totalReportedMemory) == 0' evaluated to false.");
static_assert(sizeof(MemoryStatistics::totalReportedMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::totalReportedMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::totalReportedMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::totalReportedMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::totalActualMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::totalActualMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, totalActualMemory) == 4, "API_Verifier: 'offsetof( MemoryStatistics, totalActualMemory) == 4' evaluated to false.");
static_assert(sizeof(MemoryStatistics::totalActualMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::totalActualMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::totalActualMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::totalActualMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::peakReportedMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::peakReportedMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, peakReportedMemory) == 8, "API_Verifier: 'offsetof( MemoryStatistics, peakReportedMemory) == 8' evaluated to false.");
static_assert(sizeof(MemoryStatistics::peakReportedMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::peakReportedMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::peakReportedMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::peakReportedMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::peakActualMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::peakActualMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, peakActualMemory) == 12, "API_Verifier: 'offsetof( MemoryStatistics, peakActualMemory) == 12' evaluated to false.");
static_assert(sizeof(MemoryStatistics::peakActualMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::peakActualMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::peakActualMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::peakActualMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::accumulatedReportedMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::accumulatedReportedMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, accumulatedReportedMemory) == 16, "API_Verifier: 'offsetof( MemoryStatistics, accumulatedReportedMemory) == 16' evaluated to false.");
static_assert(sizeof(MemoryStatistics::accumulatedReportedMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::accumulatedReportedMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedReportedMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedReportedMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::accumulatedActualMemory)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::accumulatedActualMemory)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, accumulatedActualMemory) == 20, "API_Verifier: 'offsetof( MemoryStatistics, accumulatedActualMemory) == 20' evaluated to false.");
static_assert(sizeof(MemoryStatistics::accumulatedActualMemory) == 4, "API_Verifier: 'sizeof(MemoryStatistics::accumulatedActualMemory) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedActualMemory)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedActualMemory)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::accumulatedAllocUnitCount)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::accumulatedAllocUnitCount)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, accumulatedAllocUnitCount) == 24, "API_Verifier: 'offsetof( MemoryStatistics, accumulatedAllocUnitCount) == 24' evaluated to false.");
static_assert(sizeof(MemoryStatistics::accumulatedAllocUnitCount) == 4, "API_Verifier: 'sizeof(MemoryStatistics::accumulatedAllocUnitCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedAllocUnitCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::accumulatedAllocUnitCount)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::totalAllocUnitCount)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::totalAllocUnitCount)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, totalAllocUnitCount) == 28, "API_Verifier: 'offsetof( MemoryStatistics, totalAllocUnitCount) == 28' evaluated to false.");
static_assert(sizeof(MemoryStatistics::totalAllocUnitCount) == 4, "API_Verifier: 'sizeof(MemoryStatistics::totalAllocUnitCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::totalAllocUnitCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::totalAllocUnitCount)>' evaluated to false.");

static_assert(alignof( decltype(MemoryStatistics::peakAllocUnitCount)) == 4, "API_Verifier: 'alignof( decltype(MemoryStatistics::peakAllocUnitCount)) == 4' evaluated to false.");
static_assert(offsetof( MemoryStatistics, peakAllocUnitCount) == 32, "API_Verifier: 'offsetof( MemoryStatistics, peakAllocUnitCount) == 32' evaluated to false.");
static_assert(sizeof(MemoryStatistics::peakAllocUnitCount) == 4, "API_Verifier: 'sizeof(MemoryStatistics::peakAllocUnitCount) == 4' evaluated to false.");
static_assert(std::is_same_v<uint32_t, decltype(MemoryStatistics::peakAllocUnitCount)>, "API_Verifier: 'std::is_same_v<uint32_t, decltype(MemoryStatistics::peakAllocUnitCount)>' evaluated to false.");

#include <type_traits>
#include "D:\devspace\Bilunaris\dep\ztf\src\dep\common\tfalias\Common_3\Utilities\Interfaces\IThread.h"

static_assert(alignof(MutexLock) == 8, "API_Verifier: 'alignof(MutexLock) == 8' evaluated to false.");
static_assert(sizeof(MutexLock) == 8, "API_Verifier: 'sizeof(MutexLock) == 8' evaluated to false.");

static_assert(alignof( decltype(MutexLock::mMutex)) == 8, "API_Verifier: 'alignof( decltype(MutexLock::mMutex)) == 8' evaluated to false.");
static_assert(offsetof( MutexLock, mMutex) == 0, "API_Verifier: 'offsetof( MutexLock, mMutex) == 0' evaluated to false.");
static_assert(sizeof(MutexLock::mMutex) == 40, "API_Verifier: 'sizeof(MutexLock::mMutex) == 40' evaluated to false.");
static_assert(std::is_same_v<Mutex &, decltype(MutexLock::mMutex)>, "API_Verifier: 'std::is_same_v<Mutex &, decltype(MutexLock::mMutex)>' evaluated to false.");

