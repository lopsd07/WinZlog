/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/sys/mman.h
 *
 * Purpose: Declaration of the mmap() and munmap() API functions.
 *
 * Created: 18th December 2003
 * Updated: 13th August 2010
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


/** \file unixem/sys/mman.h
 *
 * Contains the declarations for the mmap() API.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_MMAP
#define SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_MMAP

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_MMAP_MAJOR     3
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_MMAP_MINOR     0
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_MMAP_REVISION  1
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_MMAP_EDIT      24
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stddef.h>     /* for size_t */
#include <sys/stat.h>   /* for off_t */
#include <sys/types.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_mmap mmap() API
 * \ingroup UNIXem unixem
 * \brief This API provides facilities for manipulating memory-mapped files
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WIN32
# error This file is only currently defined for compilation on Win32 systems
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#define UNIXEM_PROT_READ        (0x01)          /*!< page can be read */
#define UNIXEM_PROT_WRITE       (0x02)          /*!< page can be written */
#define UNIXEM_PROT_EXEC        (0x04)          /*!< page can be executed */
#define UNIXEM_PROT_NONE        (0x00)          /*!< page can not be accessed */

#define UNIXEM_MAP_PRIVATE      (0x02)          /*!< Changes are private */
#define UNIXEM_MAP_ANONYMOUS    (0x20)          /*!< Ignore fd and offset parameters */
#define UNIXEM_MAP_FIXED        (0x10)          /*!< Interpret addr exactly */

#ifdef _WIN64
# if defined(__GNUC__)
#  define UNIXEM_MAP_FAILED     ((void*)(long long)~0)    /*!< Returned from mmap() when the mapping fails */
# elif defined(_MSC_VER)
#  define UNIXEM_MAP_FAILED     ((void*)(__int64)~0)      /*!< Returned from mmap() when the mapping fails */
# else /* ? compiler */
#  error Currently only GCC and VC++ compilers are recognised for Win64
# endif /* compiler */
#else /* ? _WIN64 */
# define UNIXEM_MAP_FAILED      ((void*)~0)                /*!< Returned from mmap() when the mapping fails */
#endif /* _WIN64 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** Maps a file into memory, and returns a pointer to it
 *
 * \param addr Suggested address for the mapping
 * \param len The number of bytes in the mapped region. The combination of
 *   len and offset must not exceed the length of the mapped file
 * \param prot Either PROT_NONE, or a combination of the other PROT_* flags
 * \param flags One of MAP_PRIVATE, MAP_ANONYMOUS or MAP_FIXED.
 * \param fd The file descriptor of the file to map, or -1 to allocate an anonymous map
 * \param offset The offset within the file to start the mapped region
 *
 * \retval pointer to mapped region if successful
 * \retval MAP_FAILED if failed
 *
 * \note The current implementation supports the following three modes:
 * 1. Read-only file; 2. Read-write file; 3. Anonymous Read-write block of
 * system paging file.
 */

void* unixem_mmap(
    void*   addr
,   size_t  len
,   int     prot
,   int     flags
,   int     fd
,   off_t   offset
);

/** Deletes a mapped region
 *
 * The munmap() system call deletes the mappings for the specified address
 * range, and causes further references to addresses within the range to
 * generate invalid memory references.
 *
 * \param addr The base address of the mapped region to unmap
 * \param len The length of the mapped region. Ignore in the Win32 implementation
 *
 * \retval 0 if successful
 * \retval -1 if failed
 */

int unixem_munmap(
    void*   addr
,   size_t  len
);

/** Writes any dirty pages within the given range to disk
 *
 * \param addr The base address of the mapped region
 * \param len The length of the mapped region to flush to disk. Will be rounded up
 * to next page boundary.
 * \param flags Ignored
 */

int unixem_msync(
    void*   addr
,   size_t  len
,   int     flags
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_mmap */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_MMAP */

/* ///////////////////////////// end of file //////////////////////////// */
