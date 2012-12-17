/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/dirent.h
 *
 * Purpose: Declaration of the opendir() API functions and types for the
 *          Win32 platform.
 *
 * Created: 19th October 2002
 * Updated: 13th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2002-2010, Matthew Wilson and Synesis Software
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


/** \file unixem/dirent.h
 *
 * Contains the declarations for the opendir()/readdir() API.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_H_DIRENT
#define SYNSOFT_UNIXEM_INCL_UNIXEM_H_DIRENT

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_DIRENT_MAJOR       4
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_DIRENT_MINOR       0
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_DIRENT_REVISION    1
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_DIRENT_EDIT        34
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_dirent opendir()/readdir() API
 * \ingroup UNIXem unixem
 * \brief This API provides facilities for enumerating the contents of directories
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WIN32
# error This file is only currently defined for compilation on Win32 systems
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unixem.h>
#include <stddef.h>

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#ifndef NAME_MAX
# define NAME_MAX   (260)   /*!< The maximum number of characters (including null terminator) in a directory entry name */
#endif /* !NAME_MAX */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

typedef struct dirent_dir   unixem_DIR;     /*!< Handle type for multibyte string directory enumeration. \note dirent_dir is defined internally */
typedef struct wdirent_dir  unixem_wDIR;    /*!< Handle type for wide string directory enumeration. \note dirent_dir is defined internally */

/** Results structure for readdir()
 */
struct unixem_dirent
{
    char    d_name[NAME_MAX + 1];   /*!< file name (null-terminated) */
    int     d_mode;                 /*!< currently unused */    
};

/** Results structure for wreaddir()
 */
struct unixem_wdirent
{
    wchar_t d_name[NAME_MAX + 1];   /*!< file name (null-terminated) */
    int     d_mode;                 /*!< currently unused */    
};

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Returns a pointer to the next directory entry.
 *
 * This function opens the directory named by filename, and returns a
 * directory to be used to in subsequent operations. NULL is returned
 * if name cannot be accessed, or if resources cannot be acquired to
 * process the request.
 *
 * \param name The name of the directory to search
 * \return The directory handle from which the entries are read or NULL
 */
unixem_DIR* unixem_opendir(char const* name);
/** Identical semantics to opendir(), but for wide string searches.
 */
unixem_wDIR* unixem_wopendir(wchar_t const* name);

/** Closes a directory handle
 *
 * This function closes a directory handle that was opened with opendir()
 * and releases any resources associated with that directory handle.
 *
 * \param dir The directory handle from which the entries are read
 * \return 0 on success, or -1 to indicate error.
 */
int unixem_closedir(unixem_DIR* dir);
/** Identical semantics to closedir(), but for wide string searches.
 */
int unixem_wclosedir(unixem_wDIR* dir);

/** Resets a directory search position
 *
 * This function resets the position of the named directory handle to
 * the beginning of the directory.
 *
 * \param dir The directory handle whose position should be reset
 */
void unixem_rewinddir(unixem_DIR* dir);
/** Identical semantics to rewinddir(), but for wide string searches.
 */
void unixem_wrewinddir(unixem_wDIR* dir);

/** Returns a pointer to the next directory entry.
 *
 * This function returns a pointer to the next directory entry, or NULL upon
 * reaching the end of the directory or detecting an invalid seekdir() operation
 *
 * \param dir The directory handle from which the entries are read
 * \return A dirent structure or NULL
 */
struct unixem_dirent*  unixem_readdir(unixem_DIR* dir);
/** Identical semantics to readdir(), but for wide string searches.
 */
struct unixem_wdirent* unixem_wreaddir(unixem_wDIR* dir);


#ifdef __cplusplus
}
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_dirent */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_H_DIRENT */

/* ///////////////////////////// end of file //////////////////////////// */
