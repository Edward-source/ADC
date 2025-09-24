#ifndef TUT_TYPES_H
#define TUT_TYPES_H

#include <stdint.h>

// Unsigned types
typedef uint8_t TUT_U8;
typedef uint16_t TUT_U16;
typedef uint32_t TUT_U32;
typedef uint64_t TUT_U64;

// Signed types
typedef int8_t TUT_S8;
typedef int16_t TUT_S16;
typedef int32_t TUT_S32;
typedef int64_t TUT_S64;

// Boolean type
typedef enum
{
    TUT_FALSE = 0,
    TUT_TRUE = 1
} TUT_BOOL;

// Null pointer
#ifndef TUT_NULL
#define TUT_NULL ((void *)0)
#endif

#endif // TUT_TYPES_H
