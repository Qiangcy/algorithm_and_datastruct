#ifndef RJ__Standard_h
#define RJ__Standard_h

#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#include <assert.h>

// Assertion macro
#define RJ_ASSERT(condition) assert(condition)

// Boolean types

// Character types
typedef char        tC8;

typedef int        tB;
// Unsigned integer types
typedef uint8_t     tU8;
typedef uint16_t    tU16;
typedef uint32_t    tU32;
typedef uint64_t    tU64;
 
// Signed integer types
typedef int8_t      tS8;
typedef int16_t     tS16;
typedef int32_t     tS32;
typedef int64_t     tS64;
 
// Floating point types
typedef float       tF32;
typedef double      tF64;

// Size types
typedef size_t		tSize;
typedef ptrdiff_t	tPtrDiff;

#endif
