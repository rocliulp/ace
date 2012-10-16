/*
 * @author Paul Liu
 * @summary Here are the error code definitions
 */
#ifndef _ERROR_CODES_H_
#define _ERROR_CODES_H_

#ifndef NULL
#define NULL 0
#endif

#ifndef BOOL
#define BOOL int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define EC_OK                0
#define EC_NULL_POINTER      1
#define EC_INVALID_PARAMETER 2
#define EC_OUT_OF_MEMORY     3
#define EC_OUT_OF_RANGE      4

#endif
