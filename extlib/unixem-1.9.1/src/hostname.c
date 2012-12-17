/* /////////////////////////////////////////////////////////////////////////
 * File:    hostname.c
 *
 * Purpose: Implementation of the gethostname() function.
 *
 * Created: 20th April 2008
 * Updated: 12th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
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
# define _SYNSOFT_VER_C_HOSTNAME_MAJOR      2
# define _SYNSOFT_VER_C_HOSTNAME_MINOR      0
# define _SYNSOFT_VER_C_HOSTNAME_REVISION   1
# define _SYNSOFT_VER_C_HOSTNAME_EDIT       7
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unistd.h>

#include <unixem/unixem.h>
#include <unixem/internal/safestr.h>
#include <unixem/internal/util.h>

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int __stdcall unixem_gethostname(
    char*   name
,   size_t  cchName
)
{
    DWORD   cchName_;

    assert(0 == cchName || NULL != name);

    cchName_ = (DWORD)cchName;

    if(!GetComputerNameA(name, &cchName_))
    {
        if(ERROR_BUFFER_OVERFLOW != GetLastError())
        {
            errno = unixem_internal_errno_from_Win32(GetLastError());

            return -1;
        }
        else
        {
            errno = ENAMETOOLONG;
        }
    }
#if 0
    else
    {
        errno = 0;
    }
#endif /* 0 */

    return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */
