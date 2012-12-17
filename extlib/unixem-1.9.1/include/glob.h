/* /////////////////////////////////////////////////////////////////////////
 * File:    glob.h
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
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file glob.h
 *
 * Contains the declarations for the glob() API.
 */

#ifndef SYNSOFT_UNIXEM_INCL_H_GLOB
#define SYNSOFT_UNIXEM_INCL_H_GLOB

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
#define UNIXEM_DOCUMENTATION_SKIP_SECTION
#define SYNSOFT_UNIXEM_VER_H_GLOB_MAJOR    3
#define SYNSOFT_UNIXEM_VER_H_GLOB_MINOR    0
#define SYNSOFT_UNIXEM_VER_H_GLOB_REVISION 1
#define SYNSOFT_UNIXEM_VER_H_GLOB_EDIT     36
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */
#undef UNIXEM_DOCUMENTATION_SKIP_SECTION

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
#define GLOB_NOSPACE        (UNIXEM_GLOB_NOSPACE)   /*!< (Error result code:) An attempt to allocate memory failed, or if errno was 0 GLOB_LIMIT was specified in the flags and ARG_MAX patterns were matched. */
#define GLOB_ABORTED        (UNIXEM_GLOB_ABORTED)   /*!< (Error result code:) The scan was stopped because an error was encountered and either GLOB_ERR was set or (*errfunc)() returned non-zero. */
#define GLOB_NOMATCH        (UNIXEM_GLOB_NOMATCH)   /*!< (Error result code:) The pattern does not match any existing pathname, and GLOB_NOCHECK was not set int flags. */
#define GLOB_NOSYS          (UNIXEM_GLOB_NOSYS)     /*!< (Error result code:) . */
#define GLOB_ABEND          (UNIXEM_GLOB_ABEND)     /*!< (Error result code:) . */

/* Flags */ 
#define GLOB_ERR            (UNIXEM_GLOB_ERR)       /*!< Return on read errors. */
#define GLOB_MARK           (UNIXEM_GLOB_MARK)      /*!< Append a slash to each name. */
#define GLOB_NOSORT         (UNIXEM_GLOB_NOSORT)    /*!< Don't sort the names. */
#define GLOB_DOOFFS         (UNIXEM_GLOB_DOOFFS)    /*!< Insert PGLOB->gl_offs NULLs. Supported from version 1.6 of UNIXem. */
#define GLOB_NOCHECK        (UNIXEM_GLOB_NOCHECK)   /*!< If nothing matches, return the pattern. Supported from version 1.6 of UNIXem. */
#define GLOB_APPEND         (UNIXEM_GLOB_APPEND)    /*!< Append to results of a previous call. Not currently supported in this implementation. */
#define GLOB_NOESCAPE       (UNIXEM_GLOB_NOESCAPE)  /*!< Backslashes don't quote metacharacters. Has no effect in this implementation, since escaping is not supported. */
                            
#define GLOB_PERIOD         (UNIXEM_GLOB_PERIOD)    /*!< Leading `.' can be matched by metachars. Supported from version 1.6 of UNIXem. */
#define GLOB_MAGCHAR        (UNIXEM_GLOB_MAGCHAR)   /*!< Set in gl_flags if any metachars seen. Supported from version 1.6 of UNIXem. */
//#define GLOB_ALTDIRFUNC     (UNIXEM_GLOB_ALTDIRFUNC)    /*!< Use gl_opendir et al functions. Not currently supported in this implementation. */
//#define GLOB_BRACE          (UNIXEM_GLOB_BRACE)         /*!< Expand "{a,b}" to "a" "b". Not currently supported in this implementation. */
#define GLOB_NOMAGIC        (UNIXEM_GLOB_NOMAGIC)       /*!< If no magic chars, return the pattern. Supported from version 1.6 of UNIXem. */
#define GLOB_TILDE          (UNIXEM_GLOB_TILDE)         /*!< Expand ~user and ~ to home directories. Partially supported from version 1.6 of UNIXem: leading ~ is expanded to %HOMEDRIVE%%HOMEPATH%. */
#define GLOB_ONLYDIR        (UNIXEM_GLOB_ONLYDIR)       /*!< Match only directories. This implementation guarantees to only return directories when this flag is specified. */
#define GLOB_TILDE_CHECK    (UNIXEM_GLOB_TILDE_CHECK)   /*!< Like GLOB_TILDE but return an GLOB_NOMATCH even if GLOB_NOCHECK specified. Supported from version 1.6 of UNIXem. */
#define GLOB_ONLYFILE       (UNIXEM_GLOB_ONLYFILE)      /*!< Match only files. Supported from version 1.6 of UNIXem. */
#define GLOB_NODOTSDIRS     (UNIXEM_GLOB_NODOTSDIRS)    /*!< Elide "." and ".." directories from wildcard searches. Supported from version 1.6 of UNIXem. */
#define GLOB_LIMIT          (UNIXEM_GLOB_LIMIT)         /*!< Limits the search to the number specified by the caller in gl_matchc. Supported from version 1.6 of UNIXem. */
/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Result structure for glob()
 *
 * This structure is used by glob() to return the results of the search.
 */
typedef unixem_glob_t glob_t;

//typedef glob_t glob_t7;
//#define glob_t unixem_glob_t

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
 * \param flags A combination of the <b>GLOB_*</b> flags
 * \param errfunc A function that is called each time part of the search processing fails
 * \param pglob Pointer to a glob_t structure to receive the search results
 * \return 0 on success, otherwise one of the <b>GLOB_*</b> error codes
 *
 * \note This is a macro, which resolves to unixem_glob()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
int glob(
    char const*     pattern
,   int             flags
#if defined(__COMO__)
,   int           (*errfunc)(char const*, int)
#else /* ? compiler */
,   const int     (*errfunc)(char const*, int)
#endif /* compiler */
,   glob_t*         pglob
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define glob       unixem_glob
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

/** Frees the results of a call to glob
 *
 * This function releases any memory allocated in a call to glob. It must
 * always be called for a successful call to glob.
 *
 * \param pglob Pointer to a glob_t structure to receive the search results
 *
 * \note This is a macro, which resolves to unixem_globfree()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
void globfree(glob_t* pglob);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define globfree   unixem_globfree
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION

#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_glob */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_H_GLOB */

/* ///////////////////////////// end of file //////////////////////////// */
