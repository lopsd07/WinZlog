/* /////////////////////////////////////////////////////////////////////////
 * File:    uio.c
 *
 * Purpose: Vector file read/write.
 *
 * Created: 19th September 2005
 * Updated: 12th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2005-2010, Matthew Wilson and Synesis Software
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
# define _SYNSOFT_VER_C_UIO_MAJOR       2
# define _SYNSOFT_VER_C_UIO_MINOR       0
# define _SYNSOFT_VER_C_UIO_REVISION    1
# define _SYNSOFT_VER_C_UIO_EDIT        12
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/sys/uio.h>

#include <unixem/unixem.h>
#include <unixem/internal/util.h>

#include <errno.h>
#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

unixem_ssize_t unixem_readv(
    int                         fd
,   struct unixem_iovec const*  vector
,   int                         count
)
{
    int             i;
    size_t          total;
    void*           pv;
    unixem_ssize_t  ret;

    /* Determine the total size. */
    for(i = 0, total = 0; i < count; ++i)
    {
        total += vector[i].iov_len;
    }

    pv = HeapAlloc(GetProcessHeap(), 0, total);

    if(NULL == pv)
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        ret = -1;
    }
    else
    {
        HANDLE  h = (HANDLE)unixem_internal_Windows_HANDLE_from_file_handle(fd);
        DWORD   dw;

        if(!ReadFile(h, pv, (DWORD)total, &dw, NULL))
        {
            errno = unixem_internal_errno_from_Win32(GetLastError());

            ret = -1;
        }
        else
        {
            for(i = 0, ret = 0; i < count && 0 != dw; ++i)
            {
                size_t n = (dw < vector[i].iov_len) ? dw : vector[i].iov_len;

                (void)memcpy(vector[i].iov_base, (char const*)pv + ret, n);

                ret +=  (unixem_ssize_t)n;
                dw  -=  (DWORD)n;
            }
        }

        (void)HeapFree(GetProcessHeap(), 0, pv);
    }

    return ret;
}

unixem_ssize_t unixem_writev(
    int                         fd
,   struct unixem_iovec const*  vector
,   int                         count
)
{
    int             i;
    size_t          total;
    void*           pv;
    unixem_ssize_t  ret;

    /* Determine the total size. */
    for(i = 0, total = 0; i < count; ++i)
    {
        total += vector[i].iov_len;
    }

    pv = HeapAlloc(GetProcessHeap(), 0, total);

    if(NULL == pv)
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        ret = -1;
    }
    else
    {
        HANDLE  h = (HANDLE)unixem_internal_Windows_HANDLE_from_file_handle(fd);
        DWORD   dw;

        for(i = 0, ret = 0; i < count; ++i)
        {
            (void)memcpy((char*)pv + ret, vector[i].iov_base, vector[i].iov_len);

            ret += (unixem_ssize_t)vector[i].iov_len;
        }

        if(!WriteFile(h, pv, (DWORD)total, &dw, NULL))
        {
            errno = unixem_internal_errno_from_Win32(GetLastError());

            ret = -1;
        }
        else
        {
            ret = (int)dw;
        }

        (void)HeapFree(GetProcessHeap(), 0, pv);
    }

    return ret;
}

/* ///////////////////////////// end of file //////////////////////////// */
