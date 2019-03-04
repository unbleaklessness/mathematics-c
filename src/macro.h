#ifndef MACRO_H_
#define MACRO_H_

#if defined (__cplusplus)
#define MY_LIB_BEGIN_DECLARATIONS extern "C" {
#define MY_LIB_END_DECLARATIONS }
#else
#define MY_LIB_BEGIN_DECLARATIONS
#define MY_LIB_END_DECLARATIONS
#endif

#endif // MACRO_H_

