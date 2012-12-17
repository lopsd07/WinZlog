/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/glob.h
 *
 * Purpose: Declaration of the glob() API functions and types for the
 *          Win32 platform.
 *
 * Created: 13th November 2002
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


/** \file unixem/glob.h
 *
 * Contains the declarations for the glob() API.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_H_GLOB
#define SYNSOFT_UNIXEM_INCL_UNIXEM_H_GLOB

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNIXEM_GLOB_MAJOR     3
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNIXEM_GLOB_MINOR     0
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNIXEM_GLOB_REVISION  1
# define SYNSOFT_UNIXEM_VER_UNIXEM_H_UNIXEM_GLOB_EDIT      36
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unixem.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_glob glob() API
 * \ingroup UNIXem unixem
 * \brief This API provides facilities for enumerating the file-system contents
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WIN32
# error This file is only currently defined for compilation on Win32 systems
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

/* Error codes */
#define UNIXEM_GLOB_NOSPACE         (1)                 /*!< (Error result code:) An attempt to allocate memory failed, or if errno was 0 UNIXEM_GLOB_LIMIT was specified in the flags and ARG_MAX patterns were matched. */
#define UNIXEM_GLOB_ABORTED         (2)                 /*!< (Error result code:) The scan was stopped because an error was encountered and either UNIXEM_GLOB_ERR was set or (*errfunc)() returned non-zero. */
#define UNIXEM_GLOB_NOMATCH         (3)                 /*!< (Error result code:) The pattern does not match any existing pathname, and UNIXEM_GLOB_NOCHECK was not set int flags. */
#define UNIXEM_GLOB_NOSYS           (4)                 /*!< (Error result code:) . */
#define UNIXEM_GLOB_ABEND           UNIXEM_GLOB_ABORTED /*!< (Error result code:) . */

/* Flags */
#define UNIXEM_GLOB_ERR             0x00000001          /*!< Return on read errors. */
#define UNIXEM_GLOB_MARK            0x00000002          /*!< Append a slash to each name. */
#define UNIXEM_GLOB_NOSORT          0x00000004          /*!< Don't sort the names. */
#define UNIXEM_GLOB_DOOFFS          0x00000008          /*!< Insert PGLOB->gl_offs NULLs. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_NOCHECK         0x00000010          /*!< If nothing matches, return the pattern. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_APPEND          0x00000020          /*!< Append to results of a previous call. Not currently supported in this implementation. */
#define UNIXEM_GLOB_NOESCAPE        0x00000040          /*!< Backslashes don't quote metacharacters. Has no effect in this implementation, since escaping is not supported. */

#define UNIXEM_GLOB_PERIOD          0x00000080          /*!< Leading `.' can be matched by metachars. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_MAGCHAR         0x00000100          /*!< Set in gl_flags if any metachars seen. Supported from version 1.6 of UNIXem. */
/* #define UNIXEM_GLOB_ALTDIRFUNC      0x00000200 */       /*!< Use gl_opendir et al functions. Not currently supported in this implementation. */
/* #define UNIXEM_GLOB_BRACE           0x00000400 */       /*!< Expand "{a,b}" to "a" "b". Not currently supported in this implementation. */
#define UNIXEM_GLOB_NOMAGIC         0x00000800          /*!< If no magic chars, return the pattern. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_TILDE           0x00001000          /*!< Expand ~user and ~ to home directories. Partially supported from version 1.6 of UNIXem: leading ~ is expanded to %HOMEDRIVE%%HOMEPATH%. */
#define UNIXEM_GLOB_ONLYDIR         0x00002000          /*!< Match only directories. This implementation guarantees to only return directories when this flag is specified. */
#define UNIXEM_GLOB_TILDE_CHECK     0x00004000          /*!< Like UNIXEM_GLOB_TILDE but return an UNIXEM_GLOB_NOMATCH even if UNIXEM_GLOB_NOCHECK specified. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_ONLYFILE        0x00008000          /*!< Match only files. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_NODOTSDIRS      0x00010000          /*!< Elide "." and ".." directories from wildcard searches. Supported from version 1.6 of UNIXem. */
#define UNIXEM_GLOB_LIMIT           0x00020000          /*!< Limits the search to the number specified by the caller in gl_matchc. Supported from version 1.6 of UNIXem. */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Result structure for unixem_glob()
 *
 * This structure is used by unixem_glob() to return the results of the
 * search.
 */
typedef struct
{
  int       gl_pathc;   /*!< count of total paths so far */
  int       gl_matchc;  /*!< count of paths matching pattern */
  int       gl_offs;    /*!< reserved at beginning of gl_pathv */
  int       gl_flags;   /*!< returned flags */
  char**    gl_pathv; /*!< list of paths matching pattern */
} unixem_glob_t;

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Generates pathnames matching a pattern
 *
 * This function is a pathname generator that implements the rules for
 * file name pattern matching used by the UNIX shell.
 *
 * \param pattern The pattern controlling the search
 * \param flags A combination of the <b>UNIXEM_GLOB_*</b> flags
 * \param errfunc A function that is called each time part of the search processing fails
 * \param pglob Pointer to a glob_t structure to receive the search results
 * \return 0 on success, otherwise one of the <b>UNIXEM_GLOB_*</b> error codes
 */
int unixem_glob(
    char const*     pattern
,   int             flags
#if defined(__COMO__)
,   int           (*errfunc)(char const*, int)
#else /* ? compiler */
,   const int     (*errfunc)(char const*, int)
#endif /* compiler */
,   unixem_glob_t*  pglob
);

/** Frees the results of a call to unixem_glob()
 *
 * This function releases any memory allocated in a call to unixem_glob().
 * It must always be called for a successful call to unixem_glob().
 *
 * \param pglob Pointer to a glob_t structure to receive the search results
 */
void unixem_globfree(unixem_glob_t* pglob);

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_glob */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_H_GLOB */

/* ///////////////////////////// end of file //////////////////////////// */
