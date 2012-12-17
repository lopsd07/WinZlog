/* /////////////////////////////////////////////////////////////////////////
 * File:    setenv.c
 *
 * Purpose: Implementation of the setenv() and unsetenv() functions.
 *
 * Created: 9th December 2005
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
# define _SYNSOFT_VER_C_SETENV_MAJOR    1
# define _SYNSOFT_VER_C_SETENV_MINOR    0
# define _SYNSOFT_VER_C_SETENV_REVISION 5
# define _SYNSOFT_VER_C_SETENV_EDIT     7
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/setenv.h>

#include <unixem/unixem.h>
#include <unixem/internal/safestr.h>
#include <unixem/internal/util.h>

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Feature support
 */

#if defined(__BORLANDC__) || \
    defined(__WATCOMC__)
# define UNIXEM__putenv     putenv
#else /* ? compiler */
# define UNIXEM__putenv     _putenv
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

static int unixem__setenv__putenv_(
    const char* name
,   const char* value
)
{
    assert(NULL != name);
    assert(NULL != value);

    if(NULL != strchr(name, '='))
    {
        errno = EINVAL;

        return -1;
    }
    else
    {
        size_t  nameLen     =   strlen(name);
        size_t  valueLen    =   strlen(value);
        size_t  required    =   1 + nameLen + 1 + valueLen;
        char    buffer_[101];
        char    *buffer     =   (NUM_ELEMENTS(buffer_) < required)
                                    ? (char*)malloc(required * sizeof(char))
                                    : &buffer_[0];

        if(NULL == buffer)
        {
            errno = ENOMEM;

            return -1;
        }
        else
        {
            int r;

#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
            (void)strncpy_s(&buffer[0], NUM_ELEMENTS(buffer), name, nameLen);
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
            (void)strncpy(&buffer[0], name, nameLen);
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
            buffer[nameLen] = '=';
            buffer[nameLen + 1] = '\0';
#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
            (void)strncpy_s(&buffer[nameLen + 1], NUM_ELEMENTS(buffer) - (nameLen + 1), value, valueLen);
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
            (void)strncpy(&buffer[nameLen + 1], value, valueLen);
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
            buffer[nameLen + 1 + valueLen] = '\0';

            r = UNIXEM__putenv(&buffer[0]);

            if(buffer != &buffer_[0])
            {
                free(buffer);
            }

            return r;
        }
    }
}

static int unixem__setenv__putenv(
    const char* name
,   const char* value
)
{
    assert(NULL != name);
    assert(NULL != value);

    return unixem__setenv__putenv_(name, value);
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int setenv(
    const char* name
,   const char* value
,   int         bOverwrite
)
{
    assert(NULL != name);
    assert(NULL != value);

    if(!bOverwrite)
    {
#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
        size_t  requiredSize;

        getenv_s(&requiredSize, NULL, 0, name);

        if(0 != requiredSize)
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
        if(NULL != getenv(name))
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
        {
           return 0;
        }
    }

    return unixem__setenv__putenv(name, value);
}

void unsetenv(const char *name)
{
    assert(NULL != name);

    (void)unixem__setenv__putenv(name, "");
}

/* ///////////////////////////// end of file //////////////////////////// */
