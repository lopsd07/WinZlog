/* /////////////////////////////////////////////////////////////////////////
 * File:    dlfcn.c
 *
 * Purpose: Implementation of the dlopen, dlclose(), dlsym() and dlerror()
 *          API functions.
 *
 * Created: 1st January 2004
 * Updated: 12th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2004-2010, Matthew Wilson and Synesis Software
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
# define _SYNSOFT_VER_C_DLFCN_MAJOR     3
# define _SYNSOFT_VER_C_DLFCN_MINOR     0
# define _SYNSOFT_VER_C_DLFCN_REVISION  1
# define _SYNSOFT_VER_C_DLFCN_EDIT      17
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/dlfcn.h>

#include <unixem/unixem.h>

#include <windows.h>

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WIN32
# error This file is only currently defined for Win32 compilation units
#endif /* WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#define RTLD_BINDING_MASK   (0x00003)       /*!< Mask of binding time value. */

/* /////////////////////////////////////////////////////////////////////////
 * Statics
 */

static const char* s_error;

/* /////////////////////////////////////////////////////////////////////////
 * Internal functions
 */

static void unixem_set_error_(DWORD dwErr)
{
    switch(dwErr)
    {
        case    ERROR_SUCCESS:
            s_error = NULL;
            break;
        case    ERROR_MOD_NOT_FOUND:
            s_error = "Module not found";
            break;
        case    ERROR_PROC_NOT_FOUND:
            s_error = "Symbol not found";
            break;
        case    ERROR_BAD_EXE_FORMAT:
            s_error = "Invalid image format";
            break;
        case    ERROR_SHARING_VIOLATION:
            s_error = "Sharing violation";
            break;
        default:
            s_error = "Operation failed";
            break;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

void* unixem_dlopen(
    char const* moduleName
,   int         mode
)
{
    HMODULE hModule;

    if(mode & UNIXEM_RTLD_LAZY)
    {
        OutputDebugStringA("Library does not support RTLD_LAZY; using RTLD_NOW\n");
    }

    hModule = LoadLibraryA(moduleName);

    if(NULL == hModule)
    {
        unixem_set_error_(GetLastError());
    }
    else
    {
        unixem_set_error_(ERROR_SUCCESS);
    }

    return hModule;
}

int unixem_dlclose(void* hModule)
{
    if(!FreeLibrary((HMODULE)hModule))
    {
        unixem_set_error_(GetLastError());

        return 1;
    }

    unixem_set_error_(ERROR_SUCCESS);

    return 0;
}

void* unixem_dlsym(
    void*       hModule
,   char const* symbolName
)
{
    union
    {
        void    (*pfn)(void);
        void    *pv;
    } u;

    u.pfn = (void (*)(void))GetProcAddress((HMODULE)hModule, symbolName);

    if(NULL == u.pfn)
    {
        unixem_set_error_(GetLastError());
    }
    else
    {
        unixem_set_error_(ERROR_SUCCESS);
    }

    return u.pv;
}

char const* unixem_dlerror(void)
{
    char const* err = s_error;

    s_error = NULL;

    return err;
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
