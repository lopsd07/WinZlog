/* /////////////////////////////////////////////////////////////////////////
 * File:    sys/uio.h
 *
 * Purpose: Vector file read/write.
 *
 * Created: 19th September 2005
 * Updated: 13th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2005-2010, Matthew Wilson and Synesis Software
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


/** \file sys/uio.h
 *
 * Vector file read/write.
 */

#ifndef SYNSOFT_UNIXEM_INCL_SYS_H_UIO
#define SYNSOFT_UNIXEM_INCL_SYS_H_UIO

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_SYS_H_UIO_MAJOR     2
# define SYNSOFT_UNIXEM_VER_SYS_H_UIO_MINOR     0
# define SYNSOFT_UNIXEM_VER_SYS_H_UIO_REVISION  1
# define SYNSOFT_UNIXEM_VER_SYS_H_UIO_EDIT      12
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/sys/uio.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_uio uio() API
 * \ingroup UNIXem unixem
 * \brief UIO functions and types
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef _SSIZE_T_DEFINED
/** Signed size type */
typedef unixem_ssize_t  ssize_t;
# define _SSIZE_T_DEFINED
#endif /* !_SSIZE_T_DEFINED */

/** \def iovec
 * 
 * Defines a memory vector.
 */
#define iovec       unixem_iovec

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Reads from a file into a set of memory blocks
 *
 * \param fd The file from which to read
 * \param vector pointer to the first element in the vector
 * \param count the number of elements in the vector
 *
 * \note This is a macro, which resolves to unixem_readv()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
ssize_t readv(
    int                 fd
,   struct iovec const* vector
,   int                 count
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define readv      unixem_readv
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

/** Writes to a file from a set of memory blocks
 *
 * \param fd The file to which to write
 * \param vector pointer to the first element in the vector
 * \param count the number of elements in the vector
 *
 * \note This is a macro, which resolves to unixem_writev()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
ssize_t writev(
    int                 fd
,   struct iovec const* vector
,   int                 count
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define writev     unixem_writev
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_time */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_SYS_H_UIO */

/* ///////////////////////////// end of file //////////////////////////// */
