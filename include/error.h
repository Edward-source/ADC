#ifndef TUT_ERROR_H
#define TUT_ERROR_H

#include "tut_types.h"

/*_______________________________ Error Codes _______________________________*/
typedef enum
{
    TUT_OK = 0,                    // No error
    TUT_ERR_UNKNOWN = -1,          // Generic error
    TUT_ERR_NULL_PTR = -2,         // Null pointer passed
    TUT_ERR_TIMEOUT = -3,          // Timeout waiting for HW/SW event
    TUT_ERR_BUSY = -4,             // Resource busy
    TUT_ERR_INVALID = -5,          // Invalid parameter
    TUT_ERR_NOMEM = -6,            // Out of memory
    TUT_ERR_HW = -7,               // Hardware failure
    TUT_ERR_UNSUPPORTED = -8,      // Feature not supported
    TUT_ERR_INVALID_CHANNEL = -9,  // Channel out of range
    TUT_ERR_NOT_INITIALIZED = -10, // ADC not enabled
} TUT_ErrorCode;

/*____________________________ Helper Macros ______________________________*/

#define TUT_IS_OK(err) ((err) == TUT_OK)
#define TUT_IS_ERR(err) ((err) < 0)

/*_________________________ Error Code to String ___________________________*/
static inline const char *tut_error_to_str(TUT_ErrorCode err)
{
    switch (err)
    {
    case TUT_OK:
        return "OK";
    case TUT_ERR_UNKNOWN:
        return "Unknown Error";
    case TUT_ERR_NULL_PTR:
        return "Null Pointer";
    case TUT_ERR_TIMEOUT:
        return "Timeout";
    case TUT_ERR_BUSY:
        return "Busy";
    case TUT_ERR_INVALID:
        return "Invalid Parameter";
    case TUT_ERR_NOMEM:
        return "Out of Memory";
    case TUT_ERR_HW:
        return "Hardware Error";
    case TUT_ERR_UNSUPPORTED:
        return "Unsupported Feature";
    case TUT_ERR_INVALID_CHANNEL:
        return "Invalid Channel";
    case TUT_ERR_NOT_INITIALIZED:
        return "Not Initialized";
    default:
        return "Unmapped Error";
    }
}

#endif // TUT_ERROR_H
