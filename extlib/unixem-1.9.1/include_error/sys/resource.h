/* /////////////////////////////////////////////////////////////////////////
 * File:    sys/resource.h
 *
 * Purpose: Declaration of the getrusage() API function and supporting
 *          types for the Win32 platform.
 *
 * Created: 9th June 2006
 * Updated: 13th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
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


/** \file sys/resource.h
 *
 * Contains usage functions and types.
 */

#ifndef SYNSOFT_UNIXEM_INCL_SYS_H_RESOURCE
#define SYNSOFT_UNIXEM_INCL_SYS_H_RESOURCE

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_SYS_H_RESOURCE_MAJOR    2
# define SYNSOFT_UNIXEM_VER_SYS_H_RESOURCE_MINOR    0
# define SYNSOFT_UNIXEM_VER_SYS_H_RESOURCE_REVISION 1
# define SYNSOFT_UNIXEM_VER_SYS_H_RESOURCE_EDIT     8
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/sys/resource.h>

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_resource Resource Usage API
 * \ingroup UNIXem unixem
 * \brief Resource usage functions and types
 * @{
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** \def RUSAGE_SELF
 *
 * Requests that rusage() provide information about the calling process.
 */
#define RUSAGE_SELF         (UNIXEM_RUSAGE_SELF)
/** \def RUSAGE_CHILDREN
 *
 * Requests that rusage() provide information about child processes
 *  of the calling process.
 * 
 *  \note This flag is <b>not</b> supported
 */
#define RUSAGE_CHILDREN     (UNIXEM_RUSAGE_CHILDREN)

/** \def rusage
 *
 * Results structure for getrusage()
 *
 * \see unixem_getrusage
 */
#define rusage              unixem_rusage

/** Provide resource usage information.
 *
 * Retrieves resource usage information about the given process(es).
 *
 * \param who The process(es) about which the usage information is to be
 *  retrieved. One of RUSAGE_SELF or RUSAGE_CHILDREN.
 * \param r_usage Pointer to an rusage structure to receive the rusage
 *  information.
 *
 * \note This implementation only supports the RUSAGE_SELF flag for the
 *  <code>who</code> parameter.
 *
 * \note This is a macro, which resolves to unixem_getrusage()
 */
#ifdef UNIXEM_DOCUMENTATION_SKIP_SECTION
int getrusage(
    int             who
,   struct rusage*  r_usage
);
#else /* ? UNIXEM_DOCUMENTATION_SKIP_SECTION */
# define getrusage          unixem_getrusage
#endif /* UNIXEM_DOCUMENTATION_SKIP_SECTION */


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_resource */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_SYS_H_RESOURCE */

/* ///////////////////////////// end of file //////////////////////////// */
