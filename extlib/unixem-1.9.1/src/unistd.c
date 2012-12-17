/* /////////////////////////////////////////////////////////////////////////
 * File:    unistd.c
 *
 * Purpose: Definition of the chdir() and other API functions for the Win32 platform.
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
# define _SYNSOFT_VER_C_UNISTD_MAJOR      3
# define _SYNSOFT_VER_C_UNISTD_MINOR      0
# define _SYNSOFT_VER_C_UNISTD_REVISION   3
# define _SYNSOFT_VER_C_UNISTD_EDIT       36
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unistd.h>

#include <unixem/unixem.h>
#include <unixem/internal/util.h>

#include <errno.h>
#include <limits.h>
#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Feature support
 */

#if defined(__BORLANDC__)
UNIXEM_STGCLS_IMP long _cdecl _get_osfhandle(int __handle);
#elif defined(__DMC__) || \
      ( defined(__INTEL_COMPILER) && \
        defined(_WIN32)) || \
      ( defined(__MWERKS__) && \
        defined(_WIN32)) || \
      defined(_MSC_VER)
UNIXEM_STGCLS_IMP int __cdecl _close(int);
UNIXEM_STGCLS_IMP long __cdecl _get_osfhandle(int __handle);
#elif defined(__GNUC__)
long __cdecl _get_osfhandle(int __handle);
#elif defined(__WATCOMC__)
_WCRTLINK extern long _get_osfhandle( int __posixhandle );
#else
# error Compiler not discriminated
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#ifndef FILE_ATTRIBUTE_ERROR
# define FILE_ATTRIBUTE_ERROR           (0xFFFFFFFF)
#endif /* FILE_ATTRIBUTE_ERROR */

#ifdef __BORLANDC__
# define CreateHardLinkA    __CreateHardLinkA
#endif /* __BORLANDC__ */

/* /////////////////////////////////////////////////////////////////////////
 * Worker functions
 */

static long unixem__unistd__pathconf_diff(
    char const* s
,   size_t      limit
)
{
    size_t  len = (size_t)lstrlenA(s);

    if(len > limit)
    {
        return -1;
    }
    else
    {
        return (long)(limit - len);
    }
}

#if 0
static long unixem__unistd__get_full_path(
    char const* s
,   char*       buff
,   size_t      cchBuff
,   char**      pFile
)
{
    DWORD   dw  =   GetFullPathNameA(s, cchBuff, buff, pFile);

    if(0 == dw)
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        return -1;
    }
    else
    {
        return (long)dw;
    }
}

static char *unixem__unistd__nextSlash(char *s)
{
    for(; '\0' != *s; ++s)
    {
        switch(*s)
        {
            case    '/':
            case    '\\':
                return s;
        }
    }

    return NULL;
}

static char *unixem__unistd__nextSlashDot(char *s)
{
    char    *slash;

    for(slash = s; NULL != (slash = unixem__unistd__nextSlash(slash + 1)); )
    {
        if('.' == slash[1])
        {
            return slash;
        }
    }

    return NULL;
}
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

int unixem_link(
    const char* originalFile
,   const char* linkName
)
{
#if 0
    char    originalPath[1 + _MAX_PATH];
    char    linkPath[1 + _MAX_PATH];
#endif /* 0 */
    DWORD   srcAttr     =   GetFileAttributesA(originalFile);
    DWORD   linkAttr    =   GetFileAttributesA(linkName);

    if(srcAttr == FILE_ATTRIBUTE_ERROR) /* Source exists? */
    {
        errno = ENOENT;

        return -1;
    }
    else if(FILE_ATTRIBUTE_DIRECTORY & srcAttr) /* Source is a directory? */
    {
        errno = ENOTDIR;

        return -1;
    }
    else if(FILE_ATTRIBUTE_ERROR != linkAttr) /* Link already exists? */
    {
        errno = EEXIST;

        return -1;
    }
    else
    {
        char    originalDrive   =   (':' == originalFile[1]) ? originalFile[0] : unixem_internal_get_current_drive();
        char    linkDrive       =   (':' == linkName[1]) ? linkName[0] : unixem_internal_get_current_drive();

        if(originalDrive != linkDrive)
        {
            errno = EXDEV;

            return -1;
        }
        else
        {
            typedef int (WINAPI *PFnCreateHardLink)(LPCTSTR , LPCTSTR , LPSECURITY_ATTRIBUTES );

            HINSTANCE           hinst           =   LoadLibrary("Kernel32");
            PFnCreateHardLink   CreateHardLinkA =   (PFnCreateHardLink)GetProcAddress(hinst, "CreateHardLinkA");
            int                 result          =   -1;

            SetLastError(ERROR_SUCCESS);

            if( NULL == hinst ||
                NULL == CreateHardLinkA)
            {
                errno = unixem_internal_errno_from_Win32(ERROR_NOT_SUPPORTED);
            }
            else
            {
                if(!CreateHardLinkA(linkName, originalFile, NULL))
                {
                    errno = unixem_internal_errno_from_Win32(GetLastError());
                }
                else
                {
                    result = 0;
                }
            }

            if(NULL != hinst)
            {
                (void)FreeLibrary(hinst);
            }

            return result;
        }
    }
}

int unixem_unlink(const char *path)
{
    DWORD   attr    =   GetFileAttributesA(path);

    if(FILE_ATTRIBUTE_ERROR == attr)
    {
        errno = ENOENT;

        return -1;
    }
    else if(FILE_ATTRIBUTE_DIRECTORY & attr)
    {
        if(RemoveDirectoryA(path))
        {
            return 0;
        }
    }
    else
    {
        if(DeleteFileA(path))
        {
            return 0;
        }
    }

    errno = unixem_internal_errno_from_Win32(GetLastError());

    return -1;
}

int unixem_chdir(char const *dirName)
{
    if(SetCurrentDirectoryA(dirName))
    {
        return 0;
    }
    else
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        return -1;
    }
}

char* unixem_getcwd(
    char*   buffer
,   size_t  max_len
)
{
    if(GetCurrentDirectoryA((DWORD)max_len, buffer))
    {
        return buffer;
    }
    else
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        return NULL;
    }
}

int unixem_mkdir(
    const char* dirName
,   unsigned    mode
)
{
    ((void)mode);

    if(CreateDirectoryA(dirName, NULL))
    {
        return 0;
    }
    else
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        return -1;
    }
}

int unixem_rmdir(const char *dirName)
{
    if(RemoveDirectoryA(dirName))
    {
        return 0;
    }
    else
    {
        errno = unixem_internal_errno_from_Win32(GetLastError());

        return -1;
    }
}


int unixem_close(int handle)
{
#if defined(__DMC__) || \
    (   defined(__INTEL_COMPILER) && \
        defined(_WIN32)) || \
    (   defined(__MWERKS__) && \
        defined(_WIN32)) || \
    defined(_MSC_VER)

    /* Use _close() */
    return _close(handle);

#else /* ? compiler */

    if( 0 == handle || 
        1 == handle ||
        2 == handle)
    {
        return 0;
    }
    else
    {
        HANDLE  h   =   (HANDLE)_get_osfhandle(handle);

        if(CloseHandle(h))
        {
            return 0;
        }
        else
        {
            DWORD   err = GetLastError();

            switch(err)
            {
                default:
                    return EBADF;
            }
        }
    }

#endif /* compiler */
}

int unixem_getpagesize(void)
{
    SYSTEM_INFO sysinfo;

    GetSystemInfo(&sysinfo);

    return (int)sysinfo.dwPageSize;
}


#ifndef _MAX_FNAME
# define _MAX_FNAME (256)
#endif /* !_MAX_FNAME */

#ifndef _MAX_PATH
# define _MAX_PATH  (260)
#endif /* !_MAX_PATH */

long unixem_pathconf(
    char const* path
,   int         name
)
{
    switch(name)
    {
        default:
            return -1;
        case    UNIXEM_PC_LINK_MAX:           return LONG_MAX;
        case    UNIXEM_PC_MAX_CANON:          return LONG_MAX;
        case    UNIXEM_PC_MAX_INPUT:          return LONG_MAX;
        case    UNIXEM_PC_NAME_MAX:           return unixem__unistd__pathconf_diff(path, _MAX_FNAME);
        case    UNIXEM_PC_PATH_MAX:           return unixem__unistd__pathconf_diff(path, _MAX_PATH);
        case    UNIXEM_PC_PIPE_BUF:           return -1;
        case    UNIXEM_PC_CHOWN_RESTRICTED:   return -1;
        case    UNIXEM_PC_NO_TRUNC:           return -1;
        case    UNIXEM_PC_VDISABLE:           return -1;
        case    UNIXEM_PC_AIX_DISK_PARTITION: return -1;
        case    UNIXEM_PC_AIX_DISK_SIZE:      return -1;
        case    UNIXEM_PC_FILESIZEBITS:       return -1;
        case    UNIXEM_PC_SYNC_IO:            return -1;
    }
}

char* unixem_realpath(
    char const* path
,   char        resolvedPath[]
)
{
    /* path is made absolute in three steps:
     *
     * 1. Call GetFullPathNameA()
     * 2. Resolve all /./
     * 3. Resolve all /../
     */
    DWORD   attr    =   GetFileAttributesA(path);

    if(FILE_ATTRIBUTE_ERROR == attr)
    {
        errno = ENOENT;

        return NULL;
    }
    else
    {
        LPSTR   lpFile;
        DWORD   dw  =   GetFullPathNameA(path, 1 + _MAX_PATH, resolvedPath, &lpFile);

        if(0 == dw)
        {
            errno = unixem_internal_errno_from_Win32(GetLastError());

            return NULL;
        }
        else
        {
            return resolvedPath;
        }
    }
}

int unixem_usleep(unsigned long microSeconds)
{
    Sleep(microSeconds / 1000);

    return 0;
}

unixem_pid_t unixem_getpid(void)
{
    return (unixem_pid_t)GetCurrentProcessId();
}

/* ///////////////////////////// end of file //////////////////////////// */
