/*
 * This source file is part of the bstring string library.  This code was
 * written by Paul Hsieh in 2002-2015, and is covered by the BSD open source
 * license and the GPL. Refer to the accompanying documentation for details   //-V1042
 * on usage and license.
 */

/*
 * The Forge: Please refer to TFREADME.md for all changes and updated documentation
*/

/*
 * Modified again for Bilunaris to be zig translation compatible.
*/

/*
 * bstrlib.h
 *
 * This file is the interface for the core bstring functions.
 */

#ifndef BSTRLIB_INCLUDE
#define BSTRLIB_INCLUDE

#ifdef __cplusplus
extern "C" {
#endif

#include "ztf_bind_common.h"
#include "Config_c.h"

#if !defined (BSTRLIB_VSNP_OK) && !defined (BSTRLIB_NOVSNP)
# if defined (__TURBOC__) && !defined (__BORLANDC__)
#  define BSTRLIB_NOVSNP
# endif
#endif

// Assert error is only for tests
#define BSTR_ASSERT_ERR (INT_MIN)
#define BSTR_ERR (-1)
#define BSTR_CMP_EXTRA_NULL ((int)UCHAR_MAX + 1)
#define BSTR_OK (0)
#define BSTR_BS_BUFF_LENGTH_GET (0)

/* Version */
#define BSTR_VER_MAJOR  1
#define BSTR_VER_MINOR  0
#define BSTR_VER_UPDATE 0

#define BSTR_DYNAMIC_BIT (~INT_MAX)

#ifdef ZTF_ENABLE_MEMORY_TRACKING
#define BSTR_STRINGIFY(x) #x
#define BSTR_DECLARE_FN(ret, name, ...) ret name##Impl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME OPT_COMMA_VA_ARGS(__VA_ARGS__))
#define BSTR_CALL(fn, ...) fn##Impl(__FILE__, __LINE__, __FUNCTION__, BSTR_STRINGIFY(fn) OPT_COMMA_VA_ARGS(__VA_ARGS__))
#else
#define BSTR_DECLARE_FN(ret, name, ...) ret name##Impl (__VA_ARGS__)
#define BSTR_CALL(fn, ...) fn##Impl(__VA_ARGS__)
#endif

typedef struct bstring {
	int mlen;
	int slen;
	unsigned char * data;
}bstring;

/* Accessor macros */
#define blengthe(b, e)      (((b) == (void *)0 || (b)->slen < 0) ? (int)(e) : ((b)->slen))
#define blength(b)          (blengthe ((b), 0))
#define bownsdata(b)       (((b)->mlen & BSTR_DYNAMIC_BIT) != 0)
/* use bcapacity to ensure that b is not null */
#define bmlen(b)            (((b)->mlen) & ~BSTR_DYNAMIC_BIT)
#define bcapacitye(b, e)    ( ((b) == NULL) ? (int)(e) : bmlen((b)) )
#define bcapacity(b)        (bcapacitye((b),0))
#define bdataofse(b, o, e)  (((b) == (void *)0 || (b)->data == (void*)0) ? (char *)(e) : ((char *)(b)->data) + (o))
#define bdataofs(b, o)      (bdataofse ((b), (o), (void *)0))
#define bdatae(b, e)        (bdataofse ((b), 0, (e)))
#define bdata(b)            (bdataofs ((b), 0))
#define bchare(b, p, e)     ((((unsigned)(p)) < (unsigned)blength((b))) ? ((b)->data[(p)]) : (e))
#define bchar(b, p)         bchare ((b), (p), '\0')

ZTF_C_API extern char gEmptyStringBuffer[1];

#define bconstisvalid(b)    ((b != NULL) && ((b)->slen >= 0) && ((b)->data))
#define bisvalid(b)         ( bconstisvalid((b)) && bmlen((b)) > 0 && bmlen((b)) >= (b)->slen )
#define biscstr(b)			( bconstisvalid((b)) && (b)->data[(b)->slen] == '\0' )


/* Dynamic string initialization functions */

/*
 * Creates string allocated on the heap if provided string is not empty.
 * If provided string is empty underlying buffer will point to 
 * global shared empty string buffer
 */
ZTF_C_API extern bstring bdynfromcstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const char* pCStr);
/*
 * Creates string allocated on the heap if provided string is not empty or minCapacity > 1.
 * If provided string is empty and minCapacity <= 1 underlying buffer will point to
 * global shared empty string buffer
 */
ZTF_C_API extern bstring bdynallocfromcstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const char* str, int minCapacity);
/*
 * Creates string allocated on the heap if len > 0 or minCapacity > 1.
 * If len == 0 and minCapacity <= 1 underlying buffer will point to
 * global shared empty string buffer
 */
ZTF_C_API extern bstring bdynfromblkImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const void* blk, int len, int minCapacity);
/*
 * Creates string allocated on the heap if b1->slen > 0 or minCapacity > 1.
 * If b1->slen == 0 and minCapacity <= 1 underlying buffer will point to
 * global shared empty string buffer
 */
ZTF_C_API extern bstring bdynfromstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const bstring* b1, int minCapacity);


/* Initializes internal buffer to arr */
#define bfromarr(arr) (bstring){sizeof(arr)/sizeof(arr[0]), strlen(arr), (unsigned char*)(arr)}
/* Initializes internal buffer to arr, ignores initial content of arr */
#define bemptyfromarr(arr) (bstring){ sizeof(arr)/sizeof(arr[0]), ((arr)[0] = '\0'), (unsigned char*)(arr)}

/* Initializes internal buffer to shared empty string */
#define bempty() (bstring){1,0,(unsigned char*)(&gEmptyStringBuffer[0])}

/* Ensures that underlying buffer is a c string */
ZTF_C_API extern int bmakecstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b);

ZTF_C_API extern int bassignImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* a, const bstring* b);
ZTF_C_API extern int bassignmidstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* a, const bstring* b, int left, int len);
ZTF_C_API extern int bassigncstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* a, const char* str);
ZTF_C_API extern int bassignblkImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* a, const void* s, int len);

/* Destroy function */
ZTF_C_API extern int bdestroyImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b);

/* Space allocation hinting functions */
ZTF_C_API extern int ballocImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* s, int len);
ZTF_C_API extern int ballocminImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, int len);
/* The Forge additional allocation functions */
/* Makes string dynamic and allocates max(current capacity, len) bytes for buffer*/
ZTF_C_API extern int bmakedynamicImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, int len);
/* Makes string dynamic and allocates minimal possible bytes to hold underlying string */
ZTF_C_API extern int bmakedynamicminImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, int len);


/* Substring extraction */
/* Use bassignmidstr instead
extern bstring bmidstr (const_bstring b, int left, int len);
*/

/* Various standard manipulations */
ZTF_C_API extern int bconcatImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b0, const bstring* b1);
ZTF_C_API extern int bconcharImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b0, char c);
ZTF_C_API extern int bcatcstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const char* s);
ZTF_C_API extern int bcatblkImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const void* s, int len);
ZTF_C_API extern int binsertImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* s1, int pos, const bstring* s2, unsigned char fill);
ZTF_C_API extern int binsertblkImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* s1, int pos, const void* s2, int len, unsigned char fill);
ZTF_C_API extern int binsertchImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* s1, int pos, int len, unsigned char fill);
ZTF_C_API extern int breplaceImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b1, int pos, int len, const bstring* b2, unsigned char fill);
ZTF_C_API extern int bsetstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b0, int pos, const bstring* b1, unsigned char fill);
ZTF_C_API extern int bdelete(bstring* s1, int pos, int len);
ZTF_C_API extern int btruncImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, int n);

/* Scan/search functions */
ZTF_C_API extern int bstricmp (const bstring* b0, const bstring* b1);
ZTF_C_API extern int bstrnicmp (const bstring* b0, const bstring* b1, int n);
ZTF_C_API extern int bstrcmp (const bstring* b0, const bstring* b1);
ZTF_C_API extern int bstrncmp (const bstring* b0, const bstring* b1, int n);

ZTF_C_API extern int biseqcaseless (const bstring* b0, const bstring* b1);
ZTF_C_API extern int biseqcaselessblk (const bstring* b, const void * blk, int len);
ZTF_C_API extern int bisstemeqcaselessblk (const bstring* b0, const void * blk, int len);
ZTF_C_API extern int biseq (const bstring* b0, const bstring* b1);
ZTF_C_API extern int biseqblk (const bstring* b, const void * blk, int len);
ZTF_C_API extern int bisstemeqblk (const bstring* b0, const void * blk, int len);
ZTF_C_API extern int biseqcstr (const bstring* b, const char * s);
ZTF_C_API extern int biseqcstrcaseless (const bstring* b, const char * s);
ZTF_C_API extern int binstr (const bstring* s1, int pos, const bstring* s2);
ZTF_C_API extern int binstrr (const bstring* s1, int pos, const bstring* s2);
ZTF_C_API extern int binstrcaseless (const bstring* s1, int pos, const bstring* s2);
ZTF_C_API extern int binstrrcaseless (const bstring* s1, int pos, const bstring* s2);
ZTF_C_API extern int bstrchrp (const bstring* b, int c, int pos);
ZTF_C_API extern int bstrrchrp (const bstring* b, int c, int pos);
#define bstrchr(b,c) bstrchrp ((b), (c), 0)
#define bstrrchr(b,c) bstrrchrp ((b), (c), blength(b))
ZTF_C_API extern int binchr (const bstring* b0, int pos, const bstring* b1);
ZTF_C_API extern int binchrr (const bstring* b0, int pos, const bstring* b1);
ZTF_C_API extern int bninchr (const bstring* b0, int pos, const bstring* b1);
ZTF_C_API extern int bninchrr (const bstring* b0, int pos, const bstring* b1);
ZTF_C_API extern int bfindreplaceImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const bstring* find, const bstring* repl, int pos);
ZTF_C_API extern int bfindreplacecaselessImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const bstring* find, const bstring* repl, int pos);

/* String split */
ZTF_C_API extern bstring* bsplitImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const bstring* str, unsigned char splitChar);
ZTF_C_API extern bstring* bsplitsImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const bstring* str, const bstring* splitChars);
ZTF_C_API extern bstring* bsplitstrImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, const bstring* str, const bstring* splitStr);

typedef int(*BSplitCallbackFn) (void * parm, int ofs, int len);

ZTF_C_API extern int bsplitcb(const bstring* str, unsigned char splitChar, int pos,
	BSplitCallbackFn cb, void * parm);
ZTF_C_API extern int bsplitscb(const bstring* str, const bstring* splitChars, int pos,
	BSplitCallbackFn cb, void * parm);
ZTF_C_API extern int bsplitstrcb(const bstring* str, const bstring* splitStr, int pos,
	BSplitCallbackFn cb, void * parm);

/* String join */
ZTF_C_API extern int bjoinImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* out, const bstring inputs[], int count, const bstring* sep);
ZTF_C_API extern int bjoinblkImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* out, const bstring inputs[], int count, const void* sep, int sepLen);


/* Miscellaneous functions */
ZTF_C_API extern int bpatternImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, int len);
ZTF_C_API extern int btoupper (bstring* b);
ZTF_C_API extern int btolower (bstring* b);
ZTF_C_API extern int bltrimws (bstring* b);
ZTF_C_API extern int brtrimws (bstring* b);
ZTF_C_API extern int btrimws (bstring* b);

#if !defined (BSTRLIB_NOVSNP)
ZTF_C_API extern int bformatImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const char* fmt, ...);
ZTF_C_API extern int bformataImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const char* fmt, ...);
ZTF_C_API extern int bvformatImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const char* fmt, va_list args);
ZTF_C_API extern int bvformataImpl(const char* FILE_NAME, int FILE_LINE, const char* FUNCTION_NAME, const char* PARENT_FUNCTION_NAME, bstring* b, const char* fmt, va_list args);
#endif


#ifdef __cplusplus
}
#endif

#endif
