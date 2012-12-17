/* /////////////////////////////////////////////////////////////////////////
 * File:    sys/mman.h
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


/** \file sys/mman.h
 *
 * Contains the declarations for the mmap() API.
 */

#ifndef SYNSOFT_UNIXEM_INCL_SYS_H_MMAP
#define SYNSOFT_UNIXEM_INCL_SYS_H_MMAP

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_SYS_H_MMAP_MAJOR    3
# define SYNSOFT_UNIXEM_VER_SYS_H_MMAP_MINOR    0
# define SYNSOFT_UNIXEM_VER_SYS_H_MMAP_REVISION 1
# define SYNSOFT_UNIXEM_VER_SYS_H_MMAP_EDIT     24
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/sys/mman.h>

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

#define PROT_READ       (UNIXEM_PROT_READ)          /*!< page can be read */
#define PROT_WRITE      (UNIXEM_PROT_WRITE)         /*!< page can be written */
#define PROT_EXEC       (UNIXEM_PROT_EXEC)          /*!< page can be executed */
#define PROT_NONE       (UNIXEM_PROT_NONE)          /*!< page can not be accessed */

#define MAP_PRIVATE     (UNIXEM_MAP_PRIVATE)        /*!< Changes are private */
#define MAP_ANONYMOUS   (UNIXEM_MAP_ANONYMOUS)      /*!< Ignore fd and offset parameters */
#define MAP_FIXED       (UNIXEM_MAP_FIXED)          /*!< Interpret addr exactly */

#define MAP_FAILED      (UNIXEM_MAP_FAILED)         /*!< Returned from mmap() when the mapping fails */

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
 * len and offset must not exceed the length of the mapped file
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
 *
 * \note \note This is a macro, which resolves to unixem_mmap()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
void* mmap(
    void*   addr
,   size_t  len
,   int     prot
,   int     flags
,   int     fd
,   off_t   offset
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define mmap       unixem_mmap
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

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
 *
 * \note This is a macro, which resolves to unixem_munmap()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
int munmap(
    void*   addr
,   size_t  len
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define munmap     unixem_munmap
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

/** Writes any dirty pages within the given range to disk
 *
 * \param addr The base address of the mapped region
 * \param len The length of the mapped region to flush to disk. Will be rounded up
 * to next page boundary.
 * \param flags Ignored
 *
 * \note This is a macro, which resolves to unixem_msync()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
int msync(
    void*   addr
,   size_t  len
,   int     flags
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define msync      unixem_msync
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_mmap */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_SYS_H_MMAP */

/* ///////////////////////////// end of file //////////////////////////// */
