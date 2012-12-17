/* /////////////////////////////////////////////////////////////////////////
 * File:        sys/select.h
 *
 * Purpose:     Declaration of the select() API function.
 *
 * Created:     14th January 2007
 * Updated:     13th August 2010
 *
 * Home:        http://synesis.com.au/software/
 *
 * Copyright (c) 2007-2010, Matthew Wilson and Synesis Software
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


/** \file sys/select.h
 *
 * Declaration of the select() API function.
 */

#ifndef SYNSOFT_UNIXEM_INCL_SYS_H_SELECT
#define SYNSOFT_UNIXEM_INCL_SYS_H_SELECT

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_SYS_H_SELECT_MAJOR    1
# define SYNSOFT_UNIXEM_VER_SYS_H_SELECT_MINOR    0
# define SYNSOFT_UNIXEM_VER_SYS_H_SELECT_REVISION 1
# define SYNSOFT_UNIXEM_VER_SYS_H_SELECT_EDIT     2
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */


#include <sys/time.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_select Resource Usage API
 * \ingroup UNIXem unixem
 * \brief select() functions and types
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if !defined(_WINSOCKAPI_) && \
    !defined(_WINSOCK2API_)

/** Provide synchronous I/O multiplexing.
 *
 * Retrieves select usage information about the given process(es).
 *
 * \param reserved0 Must be 0.
 * \param reserved1 Must be NULL.
 * \param reserved2 Must be NULL.
 * \param reserved3 Must be NULL.
 * \param timeout The timeout value.
 *
 * \note This implementation only supports the timeout functionality.
 */
int select(
    int             reserved0
,   void const*     reserved1
,   void const*     reserved2
,   void const*     reserved3
,   struct timeval* timeout
);

#endif /* !_WINSOCKAPI_ */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_select */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_SYS_H_SELECT */

/* ////////////////////////////////////////////////////////////////////// */
