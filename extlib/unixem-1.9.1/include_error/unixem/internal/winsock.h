/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/internal/winsock.h
 *
 * Purpose: Internal utility header for introducing WinSock (in order to
 *          support timeval and gethostname()).
 *
 * Created: 28th December 2007
 * Updated: 5th February 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2007-2010, Matthew Wilson and Synesis Software
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


/** \file unixem/internal/winsock.h Internal utility header for introducing
 *   WinSock
 */

#ifndef UNIXEM_INCL_UNIXEM_INTERNAL_H_WINSOCK
#define UNIXEM_INCL_UNIXEM_INTERNAL_H_WINSOCK

/* /////////////////////////////////////////////////////////////////////////
 * Version
 */

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_VER_UNIXEM_INTERNAL_H_WINSOCK_MAJOR     1
# define UNIXEM_VER_UNIXEM_INTERNAL_H_WINSOCK_MINOR     0
# define UNIXEM_VER_UNIXEM_INTERNAL_H_WINSOCK_REVISION  1
# define UNIXEM_VER_UNIXEM_INTERNAL_H_WINSOCK_EDIT      4
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unixem.h>

#if !defined(WIN32_LEAN_AND_MEAN)
# if defined(_WINSOCKAPI_) || \
     defined(_WINSOCK_H)
#  define UNIXEM_WINSOCK_IS_INCLUDED
# endif /* winsock.h */
# if defined(_WINSOCK2API_) || \
     defined(_WINSOCK2_H)
#  define UNIXEM_WINSOCK2_IS_INCLUDED
# endif /* winsock2.h */

# if !defined(UNIXEM_WINSOCK_IS_INCLUDED) && \
     !defined(UNIXEM_WINSOCK2_IS_INCLUDED)
#  if _WIN32_WINNT >= 0x0400
#   include <winsock2.h>
#   define UNIXEM_WINSOCK_IS_INCLUDED
#   define UNIXEM_WINSOCK2_IS_INCLUDED
#  else /* _WIN32_WINNT */
#   include <winsock.h>
#   define UNIXEM_WINSOCK_IS_INCLUDED
#  endif /* _WIN32_WINNT >=  0x0400 */
# endif /* winsock ? */
#endif /* !WIN32_LEAN_AND_MEAN */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXEM_INCL_UNIXEM_INTERNAL_H_WINSOCK */

/* ///////////////////////////// end of file //////////////////////////// */
