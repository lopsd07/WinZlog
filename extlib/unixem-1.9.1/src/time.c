/* /////////////////////////////////////////////////////////////////////////
 * File:    time.c
 *
 * Purpose: gettimeofday() for the Win32 platform.
 *
 * Created: 1st November 2003
 * Updated: 12th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2003-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define _SYNSOFT_VER_C_TIME_MAJOR      3
# define _SYNSOFT_VER_C_TIME_MINOR      0
# define _SYNSOFT_VER_C_TIME_REVISION   1
# define _SYNSOFT_VER_C_TIME_EDIT       25
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* If we're going to include 'windows.h', then it has to be included first, so
 * as to put off the defintion of timeval in sys/time.h. Regrettably, the
 * WinSock header defines it without any conception of sys/time.h. Thanks MS!
 */
#ifndef __MWERKS__
# include <windows.h>
#endif /* !__MWERKS__ */

#include <unixem/sys/time.h>

struct timezone;

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

/** This function is from the STLSoft libraries */
extern long unixem_internal_FILETIMEToUNIXTime(
    FILETIME const* ft
,   long*           microseconds
)
{
#if defined(__COMO__)
    long long   i;
#else /* ? compiler */
    LONGLONG    i;
#endif /* compiler */

    i = ft->dwHighDateTime;
    i <<= 32;
    i |= ft->dwLowDateTime;

#if (   (   defined(__BORLANDC__) && \
            __BORLANDC__ >= 0x0582) || \
        defined(__DMC__) || \
        defined(__COMO__) || \
        defined(__GNUC__) || \
        defined(__MWERKS__))
    i -= 116444736000000000LL;
#else
    i -= 116444736000000000L;
#endif /* compiler */
    if(NULL != microseconds)
    {
        *microseconds = (long)((i % 10000000) / 10);
    }
    i /= 10000000;

    return (long)i;
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int unixem_gettimeofday(
    struct unixem_timeval*  tv
,   void*                   dummy
)
{
    SYSTEMTIME  st;
    FILETIME    ft;

    ((void)dummy);

    GetSystemTime(&st);
    (void)SystemTimeToFileTime(&st, &ft);

    tv->tv_sec = unixem_internal_FILETIMEToUNIXTime(&ft, &tv->tv_usec);

    return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */
