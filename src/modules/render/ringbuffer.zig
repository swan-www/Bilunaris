const std = @import("std");
const fmt = std.fmt;
const ztf = @import("ztf");
const builtin = @import("builtin");
const dbg = (builtin.mode == builtin.Mode.Debug);

const ZtfGfx = ztf.gfx;
const ZtfResourceLoader = ztf.resource_loader;
const GfxRenderer = ZtfGfx.ztf_Renderer;
const GfxBuffer = ZtfGfx.ztf_Buffer;
const GfxBufferDesc = ZtfGfx.ztf_BufferDesc;
const GfxQueue = ZtfGfx.ztf_Queue;
const GfxCmdPoolDesc = ZtfGfx.ztf_CmdPoolDesc;
const GfxCmdPool = ZtfGfx.ztf_CmdPool;
const GfxCmd = ZtfGfx.ztf_Cmd;
const GfxCmdDesc = ZtfGfx.ztf_CmdDesc;
const GfxFence = ZtfGfx.ztf_Fence;
const GfxSemaphore = ZtfGfx.ztf_Semaphore;

const BufferLoadDesc = ZtfResourceLoader.ztf_BufferLoadDesc;

pub const GPURingBuffer = extern struct
{
    pRenderer : ?*GfxRenderer = null,
    pBuffer : ?*GfxBuffer = null,

    mBufferAlignment : u32 = 0,
    mMaxBufferSize : u64 = 0,
    mCurrentBufferOffset : u64 = 0,
};

pub const GPURingBufferOffset = extern struct
{
    pBuffer : ?*GfxBuffer,
    mOffset : u64,
};

pub const MAX_GPU_CMD_POOLS_PER_RING = 64;
pub const MAX_GPU_CMDS_PER_POOL = 4;
pub const ENABLE_GRAPHICS_DEBUG = dbg;

pub const GPUCmdRingDesc = extern struct
{
   // Queue used to create the command pools
    pQueue : ?*GfxQueue,
    // Number of command pools in this ring
    mPoolCount : u32,
    // Number of command buffers to be created per command pool
    mCmdPerPoolCount : u32,
    // Whether to add fence, semaphore for this ring
    mAddSyncPrimitives : bool
};

pub const GpuCmdRingElement = extern struct
{
	pCmdPool : ?*GfxCmdPool,
	pCmds : ?*GfxCmd,
	pFence : ?*GfxFence,
	pSemaphore : ?*GfxSemaphore,
};

// Lightweight wrapper that works as a ring for command pools, command buffers
pub const GpuCmdRing = extern struct
{
    pCmdPools : [MAX_GPU_CMD_POOLS_PER_RING]?*GfxCmdPool,
	pCmds : [MAX_GPU_CMD_POOLS_PER_RING][MAX_GPU_CMDS_PER_POOL]?*GfxCmd,
    pFences : [MAX_GPU_CMD_POOLS_PER_RING][MAX_GPU_CMDS_PER_POOL]?*GfxFence,
    pSemaphores : [MAX_GPU_CMD_POOLS_PER_RING][MAX_GPU_CMDS_PER_POOL]?*GfxSemaphore,
    mPoolIndex : u32,
    mCmdIndex : u32,
    mFenceIndex : u32,
    mPoolCount : u32,
    mCmdPerPoolCount  : u32,
};

pub fn addGpuRingBuffer(renderer : *GfxRenderer, buffer_desc : *const GfxBufferDesc, ringbuffer : *GPURingBuffer) void
{
	ringbuffer.* = GPURingBuffer{
		.pRenderer = renderer,
		.mMaxBufferSize = buffer_desc.*.mSize,
		.mBufferAlignment = @sizeOf([4]f32),
	};

	var loadDesc = BufferLoadDesc{
		.mDesc = buffer_desc.*,
		.ppBuffer = ringbuffer.*.pBuffer,
	};
	loadDesc.mDesc.pName = "GPURingBuffer";

	ZtfResourceLoader.addResource(loadDesc, null);
}

pub fn removeGPURingBuffer(ringbuffer : *GPURingBuffer) void
{
	ZtfResourceLoader.removeResource(ringbuffer.*.pBuffer);
}

pub fn resetGPURingBuffer(ringbuffer : *GPURingBuffer) void
{
	ringbuffer.*.mCurrentBufferOffset = 0;
}

pub const GetGPURingBufferOffsetArgs = struct{
	ringbuffer : *GPURingBuffer,
	memoryRequirement : u32,
	alignment : u32 = 0,
};

pub const GetGPURingBufferOffsetError = error{
	RingBufferTooSmallForMemRequirement
};

pub fn getGPURingBufferOffset(args : *GetGPURingBufferOffsetArgs) GetGPURingBufferOffsetError!GPURingBufferOffset
{
	const alignment = if(args.alignment != 0) args.alignment else args.ringbuffer.*.mBufferAlignment;
	const aligned_size = ((args.memoryRequirement + alignment - 1) / alignment) * alignment;

	if (aligned_size > args.ringbuffer.*.mMaxBufferSize)
    {
		std.debug.panic("{s}: aligned_request{{s}}, ringbuffer_max_size{{s}}", 
			.{
				@errorName(GetGPURingBufferOffsetError.RingBufferTooSmallForMemRequirement),
				aligned_size,
				args.ringbuffer.*.mMaxBufferSize,
			}
		);
        return GetGPURingBufferOffsetError.RingBufferTooSmallForMemRequirement;
    }
}

pub const AddGpuCmdRingError = error{
	PoolCountExceedsMaxPoolsPerRing,
	CmdCountExceedsMaxCmdsPerPool,
} | std.fmt.BufPrintError;


pub fn addGpuCmdRing(renderer : *GfxRenderer, desc : *const GPUCmdRingDesc, out : *GpuCmdRing ) AddGpuCmdRingError!void
{
	if(desc.*.mPoolCount > MAX_GPU_CMD_POOLS_PER_RING)
	{
		std.debug.panic("{s}: pool_count{{s}}, max_pools_per_ring{{s}}", 
			.{
				@errorName(AddGpuCmdRingError.PoolCountExceedsMaxPoolsPerRing),
				desc.*.mPoolCount,
				MAX_GPU_CMD_POOLS_PER_RING,
			}
		);
		return AddGpuCmdRingError.PoolCountExceedsMaxPoolsPerRing;
	}

	if(desc.*.mCmdPerPoolCount > MAX_GPU_CMDS_PER_POOL)
	{
		std.debug.panic("{s}: cmd_per_pool_count{{s}}, max_cmds_per_pool{{s}}", 
			.{
				@errorName(AddGpuCmdRingError.CmdCountExceedsMaxCmdsPerPool),
				desc.*.mCmdPerPoolCount,
				MAX_GPU_CMDS_PER_POOL,
			}
		);
		return AddGpuCmdRingError.CmdCountExceedsMaxCmdsPerPool;
	}

	out.*.mPoolCount = desc.*.mPoolCount;
	out.*.mCmdPerPoolCount = desc.*.mCmdPerPoolCount;

	var pool_desc = GfxCmdPoolDesc{
		.mTransient = false,
		.pQueue = desc.*.pQueue,
	};
	
	for (0..desc.*.mPoolCount) |pool_index|
	{
        ZtfGfx.ztf_addCmdPool(renderer, &pool_desc, &out.*.pCmdPools[pool_index]);
		var cmd_desc = GfxCmdDesc{};
		cmd_desc.pPool = out.*.pCmdPools[pool_index];
		for(0..desc.*.mCmdPerPoolCount) |cmd_index|
		{
			if(ENABLE_GRAPHICS_DEBUG)
			{
				const static_buffer = struct {
					var data: [ZtfGfx.ZTF_MAX_DEBUG_NAME_LENGTH]u8 = std.mem.zeroes([ZtfGfx.ZTF_MAX_DEBUG_NAME_LENGTH]u8);
				};
				try fmt.bufPrint(static_buffer.data, "GpuCmdRing Pool {u} Cmd {u}", .{ pool_index, cmd_index});
				desc.pName = static_buffer.data;
			}

			ZtfGfx.ztf_addCmd(renderer, &cmd_desc, &out.*.pCmds[pool_index][cmd_index]);

			if(desc.*.mAddSyncPrimitives)
			{
				ZtfGfx.ztf_addFence(renderer, &out.*.pFences[pool_index][cmd_index]);
				ZtfGfx.ztf_addSemaphore(renderer, &out.*.pSemaphores[pool_index][cmd_index]);
			}
		}
    }

	out.*.mPoolIndex = std.math.maxInt(u32);
	out.*.mCmdIndex = std.math.maxInt(u32);
	out.*.mFenceIndex = std.math.maxInt(u32);
}

pub fn removeGpuCmdRing(renderer : *GfxRenderer, ring : *GpuCmdRing ) !void
{
	for (0..ring.*.mPoolCount) |pool_index|
	{
		for(0..ring.*.mCmdPerPoolCount) |cmd_index|
		{
			ZtfGfx.ztf_removeCmd(renderer, ring.*.pCmds[pool_index][cmd_index]);
			if (ring.*.pSemaphores[pool_index][cmd_index])
            {
                ZtfGfx.ztf_removeSemaphore(renderer, ring.*.pSemaphores[pool_index][cmd_index]);
            }
            if (ring.*.pFences[pool_index][cmd_index])
            {
                ZtfGfx.ztf_removeFence(renderer, ring.*.pFences[pool_index][cmd_index]);
            }
		}
		ZtfGfx.ztf_removeCmdPool(renderer, ring.*.pCmdPools[pool_index]);
	}

	ring.* = std.mem.zeroInit(GpuCmdRing, .{});
}