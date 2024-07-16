#include "../../../../../dep/ztf/src/dep/common/tfalias/Common_3/Graphics/Interfaces/IGraphics.h"

#define ZTF_BLOCK_CONFIG_INCLUDE
#include "IGraphics_c.h"
#undef ZTF_BLOCK_CONFIG_INCLUDE

#ifdef __cplusplus
extern "C"
{
#endif

//BEGIN IShaderReflection_c definitions

ZTF_C_RENDERER_API void ztf_destroyShaderReflection(ztf_ShaderReflection* pReflection)
{
	destroyShaderReflection((ShaderReflection*)pReflection);
}

ZTF_C_RENDERER_API void ztf_createPipelineReflection(ztf_ShaderReflection* pReflection, uint32_t stageCount, ztf_PipelineReflection* pOutReflection)
{
	createPipelineReflection((ShaderReflection*)pReflection, stageCount, (PipelineReflection*) pOutReflection);
}

ZTF_C_RENDERER_API void ztf_destroyPipelineReflection(ztf_PipelineReflection* pReflection)
{
	destroyPipelineReflection((PipelineReflection*)pReflection);
}


ZTF_C_RENDERER_API bool ztf_isDescriptorRootConstant(const char* resourceName)
{
	return isDescriptorRootConstant(resourceName);
}

ZTF_C_RENDERER_API bool ztf_isDescriptorRootCbv(const char* resourceName)
{
	return isDescriptorRootCbv(resourceName);
}

//END IShaderReflection_c definitions

ZTF_C_RENDERER_API void ztf_setRendererInitializationError(const char* reason)
{
	setRendererInitializationError(reason);
}

ZTF_C_RENDERER_API bool ztf_hasRendererInitializationError(const char** outReason)
{
	return hasRendererInitializationError(outReason);
}

ZTF_C_RENDERER_API void ztf_initRendererContext(const char* appName, const ztf_RendererContextDesc* pSettings, ztf_RendererContext** ppContext)
{
	initRendererContext(appName, (const RendererContextDesc*)pSettings, (RendererContext**)ppContext);
}

ZTF_C_RENDERER_API void ztf_exitRendererContext(ztf_RendererContext* pContext)
{
	exitRendererContext((RendererContext*) pContext);
}


// allocates memory and initializes the renderer -> returns pRenderer
//
ZTF_C_RENDERER_API void ztf_initRenderer(const char* appName, const ztf_RendererDesc* pSettings, ztf_Renderer** ppRenderer)
{
	initRenderer(appName, (const RendererDesc*) pSettings,(Renderer**)ppRenderer);
}

ZTF_C_RENDERER_API void ztf_exitRenderer(ztf_Renderer* pRenderer)
{
	exitRenderer((Renderer*) pRenderer);
}


ZTF_C_RENDERER_API void ztf_addFence(ztf_Renderer* pRenderer, ztf_Fence** ppFence)
{
	addFence((Renderer*)pRenderer, (Fence**)ppFence);
}

ZTF_C_RENDERER_API void ztf_removeFence(ztf_Renderer* pRenderer, ztf_Fence* pFence)
{
	removeFence((Renderer*) pRenderer, (Fence*) pFence);
}

ZTF_C_RENDERER_API void ztf_addSemaphore(ztf_Renderer* pRenderer, ztf_Semaphore** ppSemaphore)
{
	addSemaphore((Renderer*)pRenderer, (Semaphore**)ppSemaphore);
}

ZTF_C_RENDERER_API void ztf_removeSemaphore(ztf_Renderer* pRenderer, ztf_Semaphore* pSemaphore)
{
	removeSemaphore((Renderer*) pRenderer, (Semaphore*)pSemaphore);
}


ZTF_C_RENDERER_API void ztf_addQueue(ztf_Renderer* pRenderer, ztf_QueueDesc* pQDesc, ztf_Queue** ppQueue)
{
	addQueue((Renderer*) pRenderer, (QueueDesc*) pQDesc, (Queue**)ppQueue);
}

ZTF_C_RENDERER_API void ztf_removeQueue(ztf_Renderer* pRenderer, ztf_Queue* pQueue)
{
	removeQueue((Renderer*) pRenderer, (Queue*) pQueue);
}


ZTF_C_RENDERER_API void ztf_addSwapChain(ztf_Renderer* pRenderer, const ztf_SwapChainDesc* pDesc, ztf_SwapChain** ppSwapChain)
{
	addSwapChain((Renderer*) pRenderer, (const SwapChainDesc*)pDesc, (SwapChain**)ppSwapChain);
}

ZTF_C_RENDERER_API void ztf_removeSwapChain(ztf_Renderer* pRenderer, ztf_SwapChain* pSwapChain)
{
	removeSwapChain((Renderer*) pRenderer, (SwapChain*) pSwapChain);
}


// memory function 
ZTF_C_RENDERER_API void ztf_addResourceHeap(ztf_Renderer* pRenderer, const ztf_ResourceHeapDesc* pDesc, ztf_ResourceHeap** ppHeap)
{
	addResourceHeap((Renderer*) pRenderer, (const ResourceHeapDesc*) pDesc, (ResourceHeap**)ppHeap);
}

ZTF_C_RENDERER_API void ztf_removeResourceHeap(ztf_Renderer* pRenderer, ztf_ResourceHeap* pHeap)
{
	removeResourceHeap((Renderer*) pRenderer, (ResourceHeap*) pHeap);
}


// command pool functions
ZTF_C_RENDERER_API void ztf_addCmdPool(ztf_Renderer* pRenderer, const ztf_CmdPoolDesc* pDesc, ztf_CmdPool** ppCmdPool)
{
	addCmdPool((Renderer*) pRenderer, (const CmdPoolDesc*) pDesc, (CmdPool**)ppCmdPool);
}

ZTF_C_RENDERER_API void ztf_removeCmdPool(ztf_Renderer* pRenderer, ztf_CmdPool* pCmdPool)
{
	removeCmdPool((Renderer*) pRenderer, (CmdPool*) pCmdPool);
}

ZTF_C_RENDERER_API void ztf_addCmd(ztf_Renderer* pRenderer, const ztf_CmdDesc* pDesc, ztf_Cmd** ppCmd)
{
	addCmd((Renderer*) pRenderer, (const CmdDesc*) pDesc, (Cmd**) ppCmd);
}

ZTF_C_RENDERER_API void ztf_removeCmd(ztf_Renderer* pRenderer, ztf_Cmd* pCmd)
{
	removeCmd((Renderer*) pRenderer, (Cmd*) pCmd);
}

ZTF_C_RENDERER_API void ztf_addCmd_n(ztf_Renderer* pRenderer, const ztf_CmdDesc* pDesc, uint32_t cmdCount, ztf_Cmd*** pppCmds)
{
	addCmd_n((Renderer*) pRenderer, (const CmdDesc*) pDesc, cmdCount, (Cmd***)pppCmds);
}

ZTF_C_RENDERER_API void ztf_removeCmd_n(ztf_Renderer* pRenderer, uint32_t cmdCount, ztf_Cmd** ppCmds)
{
	removeCmd_n((Renderer*) pRenderer, cmdCount, (Cmd**)ppCmds);
}

//
// All buffer, texture loading handled by resource system -> IResourceLoader.*
//

ZTF_C_RENDERER_API void ztf_addRenderTarget(ztf_Renderer* pRenderer, const ztf_RenderTargetDesc* pDesc, ztf_RenderTarget** ppRenderTarget)
{
	addRenderTarget((Renderer*) pRenderer, (const RenderTargetDesc*) pDesc, (RenderTarget**)ppRenderTarget);
}

ZTF_C_RENDERER_API void ztf_removeRenderTarget(ztf_Renderer* pRenderer, ztf_RenderTarget* pRenderTarget)
{
	removeRenderTarget((Renderer*) pRenderer, (RenderTarget*) pRenderTarget);
}

ZTF_C_RENDERER_API void ztf_addSampler(ztf_Renderer* pRenderer, const ztf_SamplerDesc* pDesc, ztf_Sampler** ppSampler)
{
	addSampler((Renderer*) pRenderer, (const SamplerDesc*) pDesc, (Sampler**)ppSampler);
}

ZTF_C_RENDERER_API void ztf_removeSampler(ztf_Renderer* pRenderer, ztf_Sampler* pSampler)
{
	removeSampler((Renderer*) pRenderer, (Sampler*) pSampler);
}

// shader function                                                                                                                                                                      
ZTF_C_RENDERER_API void ztf_addShaderBinary(ztf_Renderer* pRenderer, const ztf_BinaryShaderDesc* pDesc, ztf_Shader** ppShaderProgram)
{
	addShaderBinary((Renderer*) pRenderer, (const BinaryShaderDesc*) pDesc, (Shader**)ppShaderProgram);
}

ZTF_C_RENDERER_API void ztf_removeShader(ztf_Renderer* pRenderer, ztf_Shader* pShaderProgram)
{
	removeShader((Renderer*) pRenderer, (Shader*) pShaderProgram);
}


ZTF_C_RENDERER_API void ztf_addRootSignature(ztf_Renderer* pRenderer, const ztf_RootSignatureDesc* pDesc, ztf_RootSignature** ppRootSignature)
{
	addRootSignature((Renderer*) pRenderer, (const RootSignatureDesc*) pDesc, (RootSignature**)ppRootSignature);
}

ZTF_C_RENDERER_API void ztf_removeRootSignature(ztf_Renderer* pRenderer, ztf_RootSignature* pRootSignature)
{
	removeRootSignature((Renderer*) pRenderer, (RootSignature*) pRootSignature);
}

ZTF_C_RENDERER_API uint32_t ztf_getDescriptorIndexFromName(const ztf_RootSignature* pRootSignature, const char* pName)
{
	return getDescriptorIndexFromName((const RootSignature*) pRootSignature, pName);
}

// pipeline functions                                                                                                                                                                   
ZTF_C_RENDERER_API void ztf_addPipeline(ztf_Renderer* pRenderer, const ztf_PipelineDesc* pPipelineSettings, ztf_Pipeline** ppPipeline)
{
	addPipeline((Renderer*) pRenderer, (const PipelineDesc*) pPipelineSettings, (Pipeline**)ppPipeline);
}

ZTF_C_RENDERER_API void ztf_removePipeline(ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline)
{
	removePipeline((Renderer*) pRenderer, (Pipeline*) pPipeline);
}

ZTF_C_RENDERER_API void ztf_addPipelineCache(ztf_Renderer* pRenderer, const ztf_PipelineCacheDesc* pDesc, ztf_PipelineCache** ppPipelineCache)
{
	addPipelineCache((Renderer*) pRenderer, (const PipelineCacheDesc*) pDesc, (PipelineCache**)ppPipelineCache);
}

ZTF_C_RENDERER_API void ztf_getPipelineCacheData(ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache, size_t* pSize, void* pData)
{
	getPipelineCacheData((Renderer*) pRenderer, (PipelineCache*) pPipelineCache, pSize, pData);
}

#if defined(SHADER_STATS_AVAILABLE)                                                                                                                                                         
ZTF_C_RENDERER_API void ztf_addPipelineStats(ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline, bool generateDisassembly, ztf_PipelineStats* pOutStats)
{
	addPipelineStats((Renderer*) pRenderer, (Pipeline*) pPipeline, generateDisassembly, (PipelineStats*) pOutStats);
}

ZTF_C_RENDERER_API void ztf_removePipelineStats(ztf_Renderer* pRenderer, ztf_PipelineStats* pStats)
{
	removePipelineStats((Renderer*) pRenderer, (PipelineStats*) pStats);
}
#endif           

ZTF_C_RENDERER_API void ztf_removePipelineCache(ztf_Renderer* pRenderer, ztf_PipelineCache* pPipelineCache)
{
	removePipelineCache((Renderer*) pRenderer, (PipelineCache*) pPipelineCache);
}

// Descriptor Set functions                                                                                                                                                             
ZTF_C_RENDERER_API void ztf_addDescriptorSet(ztf_Renderer* pRenderer, const ztf_DescriptorSetDesc* pDesc, ztf_DescriptorSet** ppDescriptorSet)
{
	addDescriptorSet((Renderer*) pRenderer, (const DescriptorSetDesc*) pDesc, (DescriptorSet**)ppDescriptorSet);
}

ZTF_C_RENDERER_API void ztf_removeDescriptorSet(ztf_Renderer* pRenderer, ztf_DescriptorSet* pDescriptorSet)
{
	removeDescriptorSet((Renderer*) pRenderer, (DescriptorSet*)pDescriptorSet);
}

ZTF_C_RENDERER_API void ztf_updateDescriptorSet(ztf_Renderer* pRenderer, uint32_t index, ztf_DescriptorSet* pDescriptorSet, uint32_t count, const ztf_DescriptorData* pParams)
{
	updateDescriptorSet((Renderer*) pRenderer, index, (DescriptorSet*) pDescriptorSet, count, (const DescriptorData*) pParams);
}


// command buffer functions                                                                                                                                                             
ZTF_C_RENDERER_API void ztf_resetCmdPool(ztf_Renderer* pRenderer, ztf_CmdPool* pCmdPool)
{
	resetCmdPool((Renderer*) pRenderer, (CmdPool*) pCmdPool);
}

ZTF_C_RENDERER_API void ztf_beginCmd(ztf_Cmd* pCmd)
{
	beginCmd((Cmd*) pCmd);
}

ZTF_C_RENDERER_API void ztf_endCmd(ztf_Cmd* pCmd)
{
	endCmd((Cmd*) pCmd);
}

ZTF_C_RENDERER_API void ztf_cmdBindRenderTargets(ztf_Cmd* pCmd, const ztf_BindRenderTargetsDesc* pDesc)
{
	cmdBindRenderTargets((Cmd*) pCmd, (const BindRenderTargetsDesc*) pDesc);
}

ZTF_C_RENDERER_API void ztf_cmdSetSampleLocations(ztf_Cmd* pCmd, ztf_SampleCount samplesCount, uint32_t gridSizeX, uint32_t gridSizeY, ztf_SampleLocations* plocations)
{
	cmdSetSampleLocations((Cmd*) pCmd, (SampleCount) samplesCount, gridSizeX, gridSizeY, (SampleLocations*) plocations);
}

ZTF_C_RENDERER_API void ztf_cmdSetViewport(ztf_Cmd* pCmd, float x, float y, float width, float height, float minDepth, float maxDepth)
{
	cmdSetViewport((Cmd*) pCmd, x, y, width, height, minDepth, maxDepth);
}

ZTF_C_RENDERER_API void ztf_cmdSetScissor(ztf_Cmd* pCmd, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	cmdSetScissor((Cmd*) pCmd, x, y, width, height);
}

ZTF_C_RENDERER_API void ztf_cmdSetStencilReferenceValue(ztf_Cmd* pCmd, uint32_t val)
{
	cmdSetStencilReferenceValue((Cmd*) pCmd, val);
}

ZTF_C_RENDERER_API void ztf_cmdBindPipeline(ztf_Cmd* pCmd, ztf_Pipeline* pPipeline)
{
	cmdBindPipeline((Cmd*) pCmd, (Pipeline*) pPipeline);
}

ZTF_C_RENDERER_API void ztf_cmdBindDescriptorSet(ztf_Cmd* pCmd, uint32_t index, ztf_DescriptorSet* pDescriptorSet)
{
	cmdBindDescriptorSet((Cmd*) pCmd, index, (DescriptorSet*) pDescriptorSet);
}

ZTF_C_RENDERER_API void ztf_cmdBindPushConstants(ztf_Cmd* pCmd, ztf_RootSignature* pRootSignature, uint32_t paramIndex, const void* pConstants)
{
	cmdBindPushConstants((Cmd*) pCmd, (RootSignature*) pRootSignature, paramIndex, pConstants);
}

ZTF_C_RENDERER_API void ztf_cmdBindDescriptorSetWithRootCbvs(ztf_Cmd* pCmd, uint32_t index, ztf_DescriptorSet* pDescriptorSet, uint32_t count, const ztf_DescriptorData* pParams)
{
	cmdBindDescriptorSetWithRootCbvs((Cmd*) pCmd, index, (DescriptorSet*) pDescriptorSet, count, (const DescriptorData*) pParams);
}

ZTF_C_RENDERER_API void ztf_cmdBindIndexBuffer(ztf_Cmd* pCmd, ztf_Buffer* pBuffer, uint32_t indexType, uint64_t offset)
{
	cmdBindIndexBuffer((Cmd*) pCmd, (Buffer*) pBuffer, indexType, offset);
}

ZTF_C_RENDERER_API void ztf_cmdBindVertexBuffer(ztf_Cmd* pCmd, uint32_t bufferCount, ztf_Buffer** ppBuffers, const uint32_t* pStrides, const uint64_t* pOffsets)
{
	cmdBindVertexBuffer((Cmd*) pCmd, bufferCount, (Buffer**)ppBuffers, pStrides, pOffsets);
}

ZTF_C_RENDERER_API void ztf_cmdDraw(ztf_Cmd* pCmd, uint32_t vertexCount, uint32_t firstVertex)
{
	cmdDraw((Cmd*) pCmd, vertexCount, firstVertex);
}

ZTF_C_RENDERER_API void ztf_cmdDrawInstanced(ztf_Cmd* pCmd, uint32_t vertexCount, uint32_t firstVertex, uint32_t instanceCount, uint32_t firstInstance)
{
	cmdDrawInstanced((Cmd*) pCmd, vertexCount, firstVertex, instanceCount, firstInstance);
}

ZTF_C_RENDERER_API void ztf_cmdDrawIndexed(ztf_Cmd* pCmd, uint32_t indexCount, uint32_t firstIndex, uint32_t firstVertex)
{
	cmdDrawIndexed((Cmd*) pCmd, indexCount, firstIndex, firstVertex);
}

ZTF_C_RENDERER_API void ztf_cmdDrawIndexedInstanced(ztf_Cmd* pCmd, uint32_t indexCount, uint32_t firstIndex, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
	cmdDrawIndexedInstanced((Cmd*) pCmd, indexCount, firstIndex, instanceCount, firstVertex, firstInstance);
}

ZTF_C_RENDERER_API void ztf_cmdDispatch(ztf_Cmd* pCmd, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
	cmdDispatch((Cmd*) pCmd, groupCountX, groupCountY, groupCountZ);
}


// Transition Commands
ZTF_C_RENDERER_API void ztf_cmdResourceBarrier(ztf_Cmd* pCmd, uint32_t bufferBarrierCount, ztf_BufferBarrier* pBufferBarriers, uint32_t textureBarrierCount, ztf_TextureBarrier* pTextureBarriers, uint32_t rtBarrierCount, ztf_RenderTargetBarrier* pRtBarriers)
{
	cmdResourceBarrier((Cmd*) pCmd, bufferBarrierCount, (BufferBarrier*) pBufferBarriers, textureBarrierCount, (TextureBarrier*) pTextureBarriers, rtBarrierCount, (RenderTargetBarrier*) pRtBarriers);
}


// queue/fence/swapchain functions
ZTF_C_RENDERER_API void ztf_acquireNextImage(ztf_Renderer* pRenderer, ztf_SwapChain* pSwapChain, ztf_Semaphore* pSignalSemaphore, ztf_Fence* pFence, uint32_t* pImageIndex)
{
	acquireNextImage((Renderer*) pRenderer, (SwapChain*) pSwapChain, (Semaphore*) pSignalSemaphore, (Fence*) pFence, pImageIndex);
}

ZTF_C_RENDERER_API void ztf_queueSubmit(ztf_Queue* pQueue, const ztf_QueueSubmitDesc* pDesc)
{
	queueSubmit((Queue*) pQueue, (const QueueSubmitDesc*) pDesc);
}

ZTF_C_RENDERER_API void ztf_queuePresent(ztf_Queue* pQueue, const ztf_QueuePresentDesc* pDesc)
{
	queuePresent((Queue*) pQueue, (const QueuePresentDesc*) pDesc);
}

ZTF_C_RENDERER_API void ztf_waitQueueIdle(ztf_Queue* pQueue)
{
	waitQueueIdle((Queue*) pQueue);
}

ZTF_C_RENDERER_API void ztf_getFenceStatus(ztf_Renderer* pRenderer, ztf_Fence* pFence, ztf_FenceStatus* pFenceStatus)
{
	getFenceStatus((Renderer*)pRenderer, (Fence*)pFence, (FenceStatus*)pFenceStatus);
}

ZTF_C_RENDERER_API void ztf_waitForFences(ztf_Renderer* pRenderer, uint32_t fenceCount, ztf_Fence** ppFences)
{
	waitForFences((Renderer*) pRenderer, fenceCount, (Fence**)ppFences);
}

ZTF_C_RENDERER_API void ztf_toggleVSync(ztf_Renderer* pRenderer, ztf_SwapChain** ppSwapchain)
{
	toggleVSync((Renderer*) pRenderer, (SwapChain**)ppSwapchain);
}


//Returns the recommended format for the swapchain.                                                                                                                                     
//If true is passed for the hintHDR parameter, it will return an HDR format IF the platform supports it                                                                                 
//If false is passed or the platform does not support HDR a non HDR format is returned.                                                                                                 
//If true is passed for the hintSrgb parameter, it will return format that is will do gamma correction automatically                                                                    
//If false is passed for the hintSrgb parameter the gamma correction should be done as a postprocess step before submitting image to swapchain                                          
ZTF_C_RENDERER_API TinyImageFormat ztf_getSupportedSwapchainFormat(ztf_Renderer* pRenderer, const ztf_SwapChainDesc* pDesc, ztf_ColorSpace colorSpace)
{
	return getSupportedSwapchainFormat((Renderer*) pRenderer, (const SwapChainDesc*) pDesc, (ColorSpace) colorSpace);
}

ZTF_C_RENDERER_API uint32_t ztf_getRecommendedSwapchainImageCount(ztf_Renderer* pRenderer, const ztf_WindowHandle* hwnd)
{
	return getRecommendedSwapchainImageCount((Renderer*) pRenderer, (const WindowHandle*) hwnd);
}


//indirect Draw functions                                                                                                                                                              
ZTF_C_RENDERER_API void ztf_addIndirectCommandSignature(ztf_Renderer* pRenderer, const ztf_CommandSignatureDesc* pDesc, ztf_CommandSignature** ppCommandSignature)
{
	addIndirectCommandSignature((Renderer*) pRenderer, (const CommandSignatureDesc*) pDesc, (CommandSignature**)ppCommandSignature);
}

ZTF_C_RENDERER_API void ztf_removeIndirectCommandSignature(ztf_Renderer* pRenderer, ztf_CommandSignature* pCommandSignature)
{
	removeIndirectCommandSignature((Renderer*) pRenderer, (CommandSignature*) pCommandSignature);
}

ZTF_C_RENDERER_API void ztf_cmdExecuteIndirect(ztf_Cmd* pCmd, ztf_CommandSignature* pCommandSignature, unsigned int maxCommandCount, ztf_Buffer* pIndirectBuffer, uint64_t bufferOffset, ztf_Buffer* pCounterBuffer, uint64_t counterBufferOffset)
{
	cmdExecuteIndirect((Cmd*) pCmd, (CommandSignature*) pCommandSignature, maxCommandCount, (Buffer*) pIndirectBuffer, bufferOffset, (Buffer*) pCounterBuffer, counterBufferOffset);
}


/************************************************************************/
// GPU Query Interface
/************************************************************************/
ZTF_C_RENDERER_API void ztf_getTimestampFrequency(ztf_Queue* pQueue, double* pFrequency)
{
	getTimestampFrequency((Queue*) pQueue, pFrequency);
}

ZTF_C_RENDERER_API void ztf_addQueryPool(ztf_Renderer* pRenderer, const ztf_QueryPoolDesc* pDesc, ztf_QueryPool** ppQueryPool)
{
	addQueryPool((Renderer*) pRenderer, (const QueryPoolDesc*) pDesc, (QueryPool**)ppQueryPool);
}

ZTF_C_RENDERER_API void ztf_removeQueryPool(ztf_Renderer* pRenderer, ztf_QueryPool* pQueryPool)
{
	removeQueryPool((Renderer*) pRenderer, (QueryPool*) pQueryPool);
}

ZTF_C_RENDERER_API void ztf_cmdBeginQuery(ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, ztf_QueryDesc* pQuery)
{
	cmdBeginQuery((Cmd*) pCmd, (QueryPool*) pQueryPool, (QueryDesc*) pQuery);
}

ZTF_C_RENDERER_API void ztf_cmdEndQuery(ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, ztf_QueryDesc* pQuery)
{
	cmdEndQuery((Cmd*) pCmd, (QueryPool*) pQueryPool, (QueryDesc*) pQuery);
}

ZTF_C_RENDERER_API void ztf_cmdResolveQuery(ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, uint32_t startQuery, uint32_t queryCount)
{
	cmdResolveQuery((Cmd*) pCmd, (QueryPool*) pQueryPool, startQuery, queryCount);
}

ZTF_C_RENDERER_API void ztf_cmdResetQuery(ztf_Cmd* pCmd, ztf_QueryPool* pQueryPool, uint32_t startQuery, uint32_t queryCount)
{
	cmdResetQuery((Cmd*) pCmd, (QueryPool*) pQueryPool, startQuery, queryCount);
}

ZTF_C_RENDERER_API void ztf_getQueryData(ztf_Renderer* pRenderer, ztf_QueryPool* pQueryPool, uint32_t queryIndex, ztf_QueryData* pOutData)
{
	getQueryData((Renderer*) pRenderer, (QueryPool*) pQueryPool, queryIndex, (QueryData*) pOutData);
}

/************************************************************************/
// Stats Info Interface                                                                                                                                                                 
/************************************************************************/
ZTF_C_RENDERER_API void ztf_calculateMemoryStats(ztf_Renderer* pRenderer, char** ppStats)
{
	calculateMemoryStats((Renderer*) pRenderer, ppStats);
}

ZTF_C_RENDERER_API void ztf_calculateMemoryUse(ztf_Renderer* pRenderer, uint64_t* usedBytes, uint64_t* totalAllocatedBytes)
{
	calculateMemoryUse((Renderer*) pRenderer, usedBytes, totalAllocatedBytes);
}

ZTF_C_RENDERER_API void ztf_freeMemoryStats(ztf_Renderer* pRenderer, char* pStats)
{
	freeMemoryStats((Renderer*) pRenderer, pStats);
}

/************************************************************************/
// Debug Marker Interface                                                                                                                                                               
/************************************************************************/
ZTF_C_RENDERER_API void ztf_cmdBeginDebugMarker(ztf_Cmd* pCmd, float r, float g, float b, const char* pName)
{
	cmdBeginDebugMarker((Cmd*) pCmd, r, g, b, pName);
}

ZTF_C_RENDERER_API void ztf_cmdEndDebugMarker(ztf_Cmd* pCmd)
{
	cmdEndDebugMarker((Cmd*) pCmd);
}

ZTF_C_RENDERER_API void ztf_cmdAddDebugMarker(ztf_Cmd* pCmd, float r, float g, float b, const char* pName)
{
	cmdAddDebugMarker((Cmd*) pCmd, r, g, b, pName);
}

ZTF_C_RENDERER_API void ztf_cmdWriteMarker(ztf_Cmd* pCmd, const ztf_MarkerDesc* pDesc)
{
	cmdWriteMarker((Cmd*) pCmd, (const MarkerDesc*) pDesc);
}

/************************************************************************/
// Resource Debug Naming Interface                                                                                                                                                      
/************************************************************************/
ZTF_C_RENDERER_API void ztf_setBufferName(ztf_Renderer* pRenderer, ztf_Buffer* pBuffer, const char* pName)
{
	setBufferName((Renderer*) pRenderer, (Buffer*) pBuffer, pName);
}

ZTF_C_RENDERER_API void ztf_setTextureName(ztf_Renderer* pRenderer, ztf_Texture* pTexture, const char* pName)
{
	setTextureName((Renderer*) pRenderer, (Texture*) pTexture, pName);
}

ZTF_C_RENDERER_API void ztf_setRenderTargetName(ztf_Renderer* pRenderer, ztf_RenderTarget* pRenderTarget, const char* pName)
{
	setRenderTargetName((Renderer*) pRenderer, (RenderTarget*) pRenderTarget, pName);
}

ZTF_C_RENDERER_API void ztf_setPipelineName(ztf_Renderer* pRenderer, ztf_Pipeline* pPipeline, const char* pName)
{
	setPipelineName((Renderer*) pRenderer, (Pipeline*) pPipeline, pName);
}

/************************************************************************/
// BITFIELD DEFINES                                                                                                                                                  
/************************************************************************/

	ZTF_BITFIELD_SETGET_DEFINE(BufferBarrier, mBitfield, BeginOnly, uint8_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(BufferBarrier, mBitfield, EndOnly, 	uint8_t, 1, 1);

	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldOne, BeginOnly, 			uint8_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldOne, EndOnly, 				uint8_t, 1, 1);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldOne, Acquire, 				uint8_t, 2, 1);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldOne, Release, 				uint8_t, 3, 1);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldTwo, QueueType, 			uint8_t, 0, 5);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldTwo, SubresourceBarrier, 	uint8_t, 5, 1);
	ZTF_BITFIELD_SETGET_DEFINE(TextureBarrier, mBitfieldThree, MipLevel, 			uint8_t, 0, 7);

	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldOne, BeginOnly, 			uint8_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldOne, EndOnly, 				uint8_t, 1, 1);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldOne, Acquire, 				uint8_t, 2, 1);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldOne, Release, 				uint8_t, 3, 1);

	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldTwo, QueueType, 			uint8_t, 0, 5);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldTwo, SubresourceBarrier, 	uint8_t, 5, 1);

	ZTF_BITFIELD_SETGET_DEFINE(RenderTargetBarrier, mBitfieldThree, MipLevel, 			uint8_t, 0, 7);

	ZTF_BITFIELD_SETGET_DEFINE(Buffer, mBitfield, mSize, 			uint64_t, 0, 32);
	ZTF_BITFIELD_SETGET_DEFINE(Buffer, mBitfield, mDescriptors, 	uint64_t, 32, 20);
	ZTF_BITFIELD_SETGET_DEFINE(Buffer, mBitfield, mMemoryUsage, 	uint64_t, 52, 3);
	ZTF_BITFIELD_SETGET_DEFINE(Buffer, mBitfield, mNodeIndex, 		uint64_t, 55, 4);

	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldOne, mWidth, 				uint32_t, 0, 16);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldOne, mHeight, 				uint32_t, 16, 16);

	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldTwo, mDepth, 				uint32_t, 0, 16);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldTwo, mMipLevels, 			uint32_t, 16, 5);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldTwo, mArraySizeMinusOne, 	uint32_t, 21, 11);

	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mFormat, 			uint32_t, 0, 8);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mAspectMask, 		uint32_t, 8, 4);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mNodeIndex, 		uint32_t, 12, 4);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mSampleCount, 		uint32_t, 16, 5);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mUav, 				uint32_t, 21, 1);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mOwnsImage, 		uint32_t, 22, 1);
	ZTF_BITFIELD_SETGET_DEFINE(Texture, mBitfieldThree, mLazilyAllocated, 	uint32_t, 23, 1);

	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldOne, mArraySize, 		uint32_t, 0, 16);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldOne, mDepth, 			uint32_t, 16, 16);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldTwo, mWidth, 			uint32_t, 0, 16);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldTwo, mHeight, 		uint32_t, 16, 16);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldThree, mDescriptors, 	uint32_t, 0, 20);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldThree, mMipLevels, 	uint32_t, 20, 10);
	ZTF_BITFIELD_SETGET_DEFINE(RenderTarget, mBitfieldFour, mSampleQuality, uint32_t, 0, 5);
#if defined(VULKAN)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorInfo, mBitfieldVk, mVk, mVkReg,	uint32_t, 0, 20);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorInfo, mBitfieldVk, mVk, mStages,	uint32_t, 20, 8);
#endif
#if defined(DIRECT3D11)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorInfo, mBitfieldDx11, mDx11, mUsedStages, uint32_t, 0, 6);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorInfo, mBitfieldDx11, mDx11, mDx11Reg,	uint32_t, 6, 20);
#endif

	ZTF_BITFIELD_SETGET_DEFINE(DescriptorInfo, mBitfield, mDim, 				uint32_t, 0, 4);
	ZTF_BITFIELD_SETGET_DEFINE(DescriptorInfo, mBitfield, mRootDescriptor, 		uint32_t, 4, 1);
	ZTF_BITFIELD_SETGET_DEFINE(DescriptorInfo, mBitfield, mStaticSampler, 		uint32_t, 5, 1);
	ZTF_BITFIELD_SETGET_DEFINE(DescriptorInfo, mBitfield, mUpdateFrequency, 	uint32_t, 6, 3);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Fence, mBitfieldDx11, mDx11, mSubmittedDx11, uint32_t, 0, 1);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Semaphore, mBitfieldVk, mVk, mCurrentNodeIndex, uint32_t, 0, 5);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Semaphore, mBitfieldVk, mVk, mSignaledVk, uint32_t, 5, 1);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Queue, mBitfieldVk, mVk, mQueueFamilyIndex, uint32_t, 0, 5);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Queue, mBitfieldVk, mVk, mQueueIndex, uint32_t, 5, 10);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Queue, mBitfieldVk, mVk, mGpuMode, uint32_t, 10, 3);

	ZTF_BITFIELD_SETGET_DEFINE(Queue, mBitfield, mType, uint32_t, 0, 3);
	ZTF_BITFIELD_SETGET_DEFINE(Queue, mBitfield, mNodeIndex, uint32_t, 3, 4);

	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mMultiDrawIndirect, 				uint32_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mIndirectRootConstant, 			uint32_t, 1, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mBuiltinDrawID, 					uint32_t, 2, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mIndirectCommandBuffer, 			uint32_t, 3, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mROVsSupported, 					uint32_t, 4, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mTessellationSupported, 			uint32_t, 5, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mGeometryShaderSupported, 		uint32_t, 6, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mGpuMarkers, 						uint32_t, 7, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mTimestampQueries, 				uint32_t, 8, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mOcclusionQueries, 				uint32_t, 9, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mPipelineStatsQueries, 			uint32_t, 10, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mAllowBufferTextureInSameHeap, 	uint32_t, 11, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mRaytracingSupported, 			uint32_t, 12, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mRayPipelineSupported, 			uint32_t, 13, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mRayQuerySupported, 				uint32_t, 14, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mSoftwareVRSSupported, 			uint32_t, 15, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldOne, mPrimitiveIdSupported, 			uint32_t, 16, 1);

#if defined(VULKAN)	
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldVk, mDynamicRenderingSupported, 		uint32_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldVk, mXclipseTransferQueueWorkaround, 	uint32_t, 1, 1);
#endif	

	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldTwo, mSamplerAnisotropySupported, 	uint32_t, 0, 1);
	ZTF_BITFIELD_SETGET_DEFINE(GPUSettings, mBitfieldTwo, mGraphicsQueueSupported, 		uint32_t, 1, 1);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxOne, mDx, mMaxSets, uint32_t, 0, 16);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxOne, mDx, mUpdateFrequencyDx, uint32_t, 16, 3);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxOne, mDx, mNodeIndex, uint32_t, 19, 4);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxOne, mDx, mCbvSrvUavRootIndex, uint32_t, 23, 4);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxOne, mDx, mSamplerRootIndex, uint32_t, 27, 4);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDxTwo, mDx, mPipelineType, uint32_t, 0, 3);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(DescriptorSet, mBitfieldDx11, mDx11, mUpdateFrequencyDx11, uint32_t, 0, 3);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Cmd, mBitfieldDx, mDx, mNodeIndexDx, uint32_t, 0, 4);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Cmd, mBitfieldDx, mDx, mTypeDx, uint32_t, 4, 3);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Cmd, mBitfieldVk, mVk, mNodeIndexVk, uint32_t, 0, 4);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Cmd, mBitfieldVk, mVk, mTypeVk, uint32_t, 4, 3);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(Cmd, mBitfieldVk, mVk, mIsRendering, uint32_t, 7, 1);

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mYCbCrExtension, 										uint32_t, 0, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mFillModeNonSolid, 									uint32_t, 1, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mKHRRayQueryExtension, 								uint32_t, 2, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDGCNShaderExtension, 								uint32_t, 3, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDDrawIndirectCountExtension, 						uint32_t, 4, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDShaderInfoExtension, 								uint32_t, 5, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDescriptorIndexingExtension, 						uint32_t, 6, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDynamicRenderingExtension, 							uint32_t, 7, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mShaderSampledImageArrayDynamicIndexingSupported, 	uint32_t, 8, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mBufferDeviceAddressSupported, 						uint32_t, 9, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDrawIndirectCountExtension, 							uint32_t, 10, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDedicatedAllocationExtension, 						uint32_t, 11, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDebugMarkerExtension, 								uint32_t, 12, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mMemoryReq2Extension, 								uint32_t, 13, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mFragmentShaderInterlockExtension, 					uint32_t, 14, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mBufferDeviceAddressExtension, 						uint32_t, 15, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAccelerationStructureExtension, 						uint32_t, 16, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mRayTracingPipelineExtension, 						uint32_t, 17, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mRayQueryExtension, 									uint32_t, 18, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mBufferDeviceAddressFeature, 							uint32_t, 19, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mShaderFloatControlsExtension, 						uint32_t, 20, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mSpirv14Extension, 									uint32_t, 21, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDeferredHostOperationsExtension, 					uint32_t, 22, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDeviceFaultExtension, 								uint32_t, 23, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDeviceFaultSupported, 								uint32_t, 24, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mASTCDecodeModeExtension, 							uint32_t, 25, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mDeviceMemoryReportExtension, 						uint32_t, 26, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDBufferMarkerExtension, 							uint32_t, 27, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDDeviceCoherentMemoryExtension, 					uint32_t, 28, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mAMDDeviceCoherentMemorySupported, 					uint32_t, 29, 1);

#define ZTF_BITFIELD_GpuInfo_Temp_Offset 30
#define ZTF_BITFIELD_GpuInfo_Temp_Suffix One
#if defined(VK_USE_PLATFORM_WIN32_KHR)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mExternalMemoryExtension, 								uint32_t, ZTF_BITFIELD_GpuInfo_Temp_Offset, 	1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVkOne, mVk, mExternalMemoryWin32Extension, 						uint32_t, ZTF_BITFIELD_GpuInfo_Temp_Offset + 1, 1);
	#define ZTF_BITFIELD_GpuInfo_VK_USE_PLATFORM_WIN32_KHR_Offset
	#undef ZTF_BITFIELD_GpuInfo_Temp_Offset
	#define ZTF_BITFIELD_GpuInfo_Temp_Offset (ZTF_BITFIELD_GpuInfo_VK_USE_PLATFORM_WIN32_KHR_Offset + 2)
#endif
#if defined(QUEST_VR)
	#if ZTF_BITFIELD_GpuInfo_Temp_Offset > 31
		#undef ZTF_BITFIELD_GpuInfo_Temp_Suffix
		#define ZTF_BITFIELD_GpuInfo_Temp_Suffix Two
		#define ZTF_BITFIELD_GpuInfo_QUEST_VR_Offset_Overflow ZTF_BITFIELD_GpuInfo_Temp_Offset
		#undef ZTF_BITFIELD_GpuInfo_Temp_Offset
		#define ZTF_BITFIELD_GpuInfo_Temp_Offset (ZTF_BITFIELD_GpuInfo_QUEST_VR_Offset_Overflow & 31)
	#endif

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVk##ZTF_BITFIELD_GpuInfo_Temp_Suffix, mVk, mMultiviewExtension, uint32_t, ZTF_BITFIELD_GpuInfo_Temp_Offset, 1);
	#define ZTF_BITFIELD_GpuInfo_QUEST_VR_Offset ZTF_BITFIELD_GpuInfo_Temp_Offset
	#undef ZTF_BITFIELD_GpuInfo_Temp_Offset
	#define ZTF_BITFIELD_GpuInfo_Temp_Offset (ZTF_BITFIELD_GpuInfo_QUEST_VR_Offset + 1)
#endif
#if defined(ENABLE_NSIGHT_AFTERMATH)
	#if ZTF_BITFIELD_GpuInfo_Temp_Offset > 31
		#undef ZTF_BITFIELD_GpuInfo_Temp_Suffix
		#define ZTF_BITFIELD_GpuInfo_Temp_Suffix Two
		#define ZTF_BITFIELD_GpuInfo_ENABLE_NSIGHT_AFTERMATH_Offset_Overflow ZTF_BITFIELD_GpuInfo_Temp_Offset
		#undef ZTF_BITFIELD_GpuInfo_Temp_Offset
		#define ZTF_BITFIELD_GpuInfo_Temp_Offset (ZTF_BITFIELD_GpuInfo_ENABLE_NSIGHT_AFTERMATH_Offset_Overflow & 31)
	#endif

	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVk##ZTF_BITFIELD_GpuInfo_Temp_Suffix, mVk, mNVDeviceDiagnosticsCheckpointExtension, uint32_t, 	ZTF_BITFIELD_GpuInfo_Temp_Offset, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVk##ZTF_BITFIELD_GpuInfo_Temp_Suffix, mVk, mNVDeviceDiagnosticsConfigExtension, uint32_t, 		ZTF_BITFIELD_GpuInfo_Temp_Offset + 1, 1);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldVk##ZTF_BITFIELD_GpuInfo_Temp_Suffix, mVk, mAftermathSupport, uint32_t, 						ZTF_BITFIELD_GpuInfo_Temp_Offset + 2, 1);

	#define ZTF_BITFIELD_GpuInfo_ENABLE_NSIGHT_AFTERMATH_Offset ZTF_BITFIELD_GpuInfo_Temp_Offset
	#undef ZTF_BITFIELD_GpuInfo_Temp_Offset
	#define ZTF_BITFIELD_GpuInfo_Temp_Offset (ZTF_BITFIELD_GpuInfo_ENABLE_NSIGHT_AFTERMATH_Offset + 3)
#endif
#if defined(DIRECT3D11)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(GpuInfo, mBitfieldDx11, mDx11, mPartialUpdateConstantBufferSupported, uint32_t, 0, 1);	
#endif


ZTF_BITFIELD_SETGET_DEFINE(Renderer, mBitfield, mLinkedNodeCount, 		uint32_t, 0, 4);
ZTF_BITFIELD_SETGET_DEFINE(Renderer, mBitfield, mUnlinkedRendererIndex, 	uint32_t, 4, 4);
ZTF_BITFIELD_SETGET_DEFINE(Renderer, mBitfield, mGpuMode, 				uint32_t, 8, 3);
ZTF_BITFIELD_SETGET_DEFINE(Renderer, mBitfield, mShaderTarget, 			uint32_t, 11, 4);
ZTF_BITFIELD_SETGET_DEFINE(Renderer, mBitfield, mOwnsContext, 			uint32_t, 15, 1);

ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(RendererContext, mVkBitfield, mVk, mDebugUtilsExtension, uint32_t, 0, 1);
ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(RendererContext, mVkBitfield, mVk, mDebugReportExtension, uint32_t, 1, 1);
ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(RendererContext, mVkBitfield, mVk, mDeviceGroupCreationExtension, uint32_t, 2, 1);

ZTF_BITFIELD_SETGET_DEFINE(BindRenderTargetDesc, mBitfield, mMipSlice, uint32_t, 0, 10);
ZTF_BITFIELD_SETGET_DEFINE(BindRenderTargetDesc, mBitfield, mOverrideClearValue, uint32_t, 10, 1);
ZTF_BITFIELD_SETGET_DEFINE(BindRenderTargetDesc, mBitfield, mUseArraySlice, uint32_t, 11, 1);
ZTF_BITFIELD_SETGET_DEFINE(BindRenderTargetDesc, mBitfield, mUseMipSlice, uint32_t, 12, 1);

ZTF_BITFIELD_SETGET_DEFINE(BindDepthTargetDesc, mBitfield, mMipSlice, uint32_t, 0, 10);
ZTF_BITFIELD_SETGET_DEFINE(BindDepthTargetDesc, mBitfield, mOverrideClearValue, uint32_t, 10, 1);
ZTF_BITFIELD_SETGET_DEFINE(BindDepthTargetDesc, mBitfield, mUseArraySlice, uint32_t, 11, 1);
ZTF_BITFIELD_SETGET_DEFINE(BindDepthTargetDesc, mBitfield, mUseMipSlice, uint32_t, 12, 1);

#if defined(DIRECT3D12)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldDx12, mDx, mSyncIntervalDx12, uint32_t, 0, 3);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldDx12, mDx, mFlagsDx12, uint32_t, 3, 10);
#endif
#if defined(VULKAN)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldVk, mVk, mPresentQueueFamilyIndex, uint32_t, 0, 5);
#endif
#if defined(DIRECT3D11)
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldDx11, mDx11, mSyncIntervalDx11, 	uint32_t, 0, 3);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldDx11, mDx11, mFlagsDx11, 		uint32_t, 3, 10);
	ZTF_BITFIELD_SETGET_WITH_PREFIX_DEFINE(SwapChain, mBitfieldDx11, mDx11, mImageIndex, 	uint32_t, 13, 3);
#endif
ZTF_BITFIELD_SETGET_DEFINE(SwapChain, mBitfield, mImageCount, uint32_t, 0, 8);
ZTF_BITFIELD_SETGET_DEFINE(SwapChain, mBitfield, mEnableVsync, uint32_t, 8, 1);
ZTF_BITFIELD_SETGET_DEFINE(SwapChain, mBitfield, mColorSpace, uint32_t, 9, 4);
ZTF_BITFIELD_SETGET_DEFINE(SwapChain, mBitfield, mFormat, uint32_t, 15, 8);



#ifdef __cplusplus
}
#endif