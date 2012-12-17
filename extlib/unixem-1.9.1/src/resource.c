/* /////////////////////////////////////////////////////////////////////////
 * File:    resource.c
 *
 * Purpose: Implementation of the getrusage() API function for the Win32
 *          platform.
 *
 * Created: 9th June 2006
 * Updated: 12th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
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
# define SYNSOFT_UNIXEM_VER_SYS_C_USAGE_MAJOR       2
# define SYNSOFT_UNIXEM_VER_SYS_C_USAGE_MINOR       0
# define SYNSOFT_UNIXEM_VER_SYS_C_USAGE_REVISION    1
# define SYNSOFT_UNIXEM_VER_SYS_C_USAGE_EDIT        7
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* If we're going to include 'windows.h', then it has to be included first,
 * so as to put off the defintion of timeval in sys/time.h. Regrettably, the
 * WinSock header defines it without any conception of sys/time.h. Thanks MS!
 */
#ifndef __MWERKS__
# include <windows.h>
#endif /* !__MWERKS__ */

#include <unixem/sys/resource.h>

#include <unixem/unixem.h>
#include <unixem/internal/util.h>

#include <assert.h>
#include <errno.h>
#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int unixem_getrusage(
    int                     who
,   struct unixem_rusage*   r_usage
)
{
    assert(NULL != r_usage);

    if(UNIXEM_RUSAGE_SELF != who)
    {
        errno = EINVAL;

        return -1;
    }
    else
    {
        ULARGE_INTEGER  kernelTime;
        ULARGE_INTEGER  userTime;
        FILETIME        dummy;

        if(!GetProcessTimes(GetCurrentProcess(), &dummy, &dummy, (LPFILETIME)&kernelTime, (LPFILETIME)&userTime))
        {
            errno = unixem_internal_errno_from_Win32(GetLastError());

            return -1;
        }
        else
        {
            r_usage->ru_stime.tv_sec    =   (long)(0x7fffffff & (unsigned long)kernelTime.QuadPart / 10000000);
            r_usage->ru_utime.tv_sec    =   (long)(0x7fffffff & (unsigned long)userTime.QuadPart / 10000000);

            r_usage->ru_stime.tv_usec   =   (long)(0x7fffffff & (unsigned long)((kernelTime.QuadPart % 10000000) / 10));
            r_usage->ru_utime.tv_usec   =   (long)(0x7fffffff & (unsigned long)((userTime.QuadPart % 10000000) / 10));

            return 0;
        }
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
