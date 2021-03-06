/*
 *  core.h
 *  SharedPrefix
 *
 *  Created by Jean-Daniel Dupas.
 *  Copyright © 2004 - 2012 Jean-Daniel Dupas. All rights reserved.
 */

#if defined(SC_INCLUDE_CORE_FOUNDATION_H)
  #include <CoreFoundation/CoreFoundation.h>
#else

/* libc headers */
#include <sys/types.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <fenv.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <pthread.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
/* GCC defines __BYTE_ORDER__ */
#  if defined(__BYTE_ORDER__)
#    if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#      define __LITTLE_ENDIAN__ 1
#    elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#      define __BIG_ENDIAN__ 1
#    endif
#  else
/* Unsupported compiler. try to guess based on architecture */
#    if defined(__i386__) || defined(__x86_64__) || defined(__amd64__)
#      define __LITTLE_ENDIAN__ 1
#    elif defined(__ppc__) || defined(__ppc64__)
#      define __BIG_ENDIAN__ 1
#    endif
#  endif
#endif

typedef double CFTimeInterval;
typedef double CFAbsoluteTime;

#if defined(__cplusplus)
extern "C" {
#endif

static inline void *reallocf(void *ptr, size_t newSize) {
  void *result = realloc(ptr, newSize);
  if (!result)
    free(ptr);
  return result;
}

#if defined(__cplusplus)
}
#endif

#endif
