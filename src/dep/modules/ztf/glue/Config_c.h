#pragma once

#ifndef ZTF_BLOCK_CONFIG_INCLUDE

#include <stdint.h>
#include <stdlib.h> 

#include "ztf_bind_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_MSC_VER)
#if !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#ifndef FORGE_DEBUG
#if defined(DEBUG) || defined(_DEBUG) || defined(AUTOMATED_TESTING)
#define FORGE_DEBUG
#endif
#endif

#define UNREF_PARAM(x) (x)
#define ALIGNAS(x) __declspec( align( x ) ) 
#define DEFINE_ALIGNED(def, a) __declspec(align(a)) def
#define ZTF_FORGE_CALLCONV __cdecl
#define ALIGNOF(x) __alignof(x)
#define THREAD_LOCAL __declspec( thread )

#include <crtdbg.h>
#define COMPILE_ASSERT(exp) _STATIC_ASSERT(exp) 

#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

#if defined(_M_X64)
#define ARCH_X64
#define ARCH_X86_FAMILY
#elif defined(_M_IX86)
#define ARCH_X86
#define ARCH_X86_FAMILY
#else
#error "Unsupported architecture for msvc compiler"
#endif

	// Msvc removes trailing commas
#define OPT_COMMA_VA_ARGS(...) ,__VA_ARGS__

#elif defined(__GNUC__) || defined(__clang__)
#include <sys/types.h>
#include <assert.h>
#include <stdalign.h>

#ifdef __OPTIMIZE__
	// Some platforms define NDEBUG for Release builds
#ifndef NDEBUG
#define NDEBUG
#endif
#else
#ifndef _DEBUG
#define _DEBUG
#endif
#endif

#ifdef __APPLE__
#define NOREFS __unsafe_unretained
#endif

#define UNREF_PARAM(x) ((void)(x))
#define ALIGNAS(x)  __attribute__ ((aligned( x )))
#define DEFINE_ALIGNED(def, a) __attribute__((aligned(a))) def
#define ZTF_FORGE_CALLCONV
#define ALIGNOF(x) __alignof__(x)
#define THREAD_LOCAL __thread

#ifdef __clang__
#define COMPILE_ASSERT(exp) _Static_assert(exp, #exp)
#else
#define COMPILE_ASSERT(exp) static_assert(exp, #exp)
#endif

#if defined(__i386__)
#define ARCH_X86
#define ARCH_X86_FAMILY
#elif defined(__x86_64__)
#define ARCH_X64
#define ARCH_X86_FAMILY
#elif defined(__arm__)
#define ARCH_ARM
#define ARCH_ARM_FAMILY
#elif defined(__aarch64__)
#define ARCH_ARM64
#define ARCH_ARM_FAMILY
#else
#error "Unsupported architecture for gcc compiler"
#endif

#define OPT_COMMA_VA_ARGS(...) ,##__VA_ARGS__

#else
#error Unknown language dialect
#endif

#if !defined(NDEBUG)
#define ZTF_ENABLE_MEMORY_TRACKING
#endif

#if defined(FORGE_DEBUG)
#define ENABLE_GRAPHICS_DEBUG
#endif

//////////////////////////////////////////////
//// General options
//////////////////////////////////////////////
// #define ENABLE_MATH_CHECKS // Enables low level math library debug checks like SIMD variable alignment checks
#define ENABLE_FORGE_SCRIPTING
#define ENABLE_FORGE_RELOAD_SHADER
#define ENABLE_FORGE_UI
#define ENABLE_FORGE_FONTS
#define ENABLE_FORGE_INPUT
#define ENABLE_FORGE_ANIMATION_DEBUG
// #define ENABLE_FORGE_GPU_ANIMATION_DEBUG
#define ENABLE_FORGE_MATERIALS
#define ENABLE_ZIP_FILESYSTEM
#define ENABLE_SCREENSHOT
#define ENABLE_PROFILER
#define ENABLE_MESHOPTIMIZER
#define ENABLE_THREAD_PERFORMANCE_STATS
// #define ENABLE_VMA_LOG // Very verbose, prints for each allocation

// ENABLE_FORGE_ANDROID_SHADERC can be disabled if all shaders are compiled offline.
// This way we also avoid to link to this library
#define ENABLE_FORGE_ANDROID_SHADERC

#ifdef __cplusplus
}
#endif

#endif //ZTF_BLOCK_CONFIG_INCLUDE