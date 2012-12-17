/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/sys/resource.h
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


/** \file unixem/sys/resource.h
 *
 * Contains usage functions and types.
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_RESOURCE
#define SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_RESOURCE

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_RESOURCE_MAJOR     2
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_RESOURCE_MINOR     0
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_RESOURCE_REVISION  1
# define SYNSOFT_UNIXEM_VER_UNIXEM_SYS_H_RESOURCE_EDIT      8
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <sys/time.h>

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

/** \def UNIXEM_RUSAGE_SELF
 *
 * Requests that rusage() provide information about the calling process.
 */
#define UNIXEM_RUSAGE_SELF      (0)
/** \def UNIXEM_RUSAGE_CHILDREN
 *
 * Requests that rusage() provide information about child processes
 *  of the calling process.
 *
 *  \note This flag is <b>not</b> supported
 */
#define UNIXEM_RUSAGE_CHILDREN  (-1)

/** Resource usage information structure.
 *
 * \remarks This implementation supports only the standard fields
 *  <code>ru_utime</code> and <code>ru_stime</code>.
 */
struct unixem_rusage
{
    struct timeval  ru_utime;       /*!< User time used. */
    struct timeval  ru_stime;       /*!< System time used. */
    char            reserved[56];   /*!< [RESERVED] Reserved for future use. */
};

/** Provide resource usage information.
 *
 * Retrieves resource usage information about the given process(es).
 *
 * \param who The process(es) about which the usage information is to be
 *  retrieved. One of UNIXEM_RUSAGE_SELF or UNIXEM_RUSAGE_CHILDREN.
 * \param r_usage Pointer to a unixem_rusage structure to receive the rusage
 *  information.
 *
 * \note This implementation only supports the RUSAGE_SELF flag for the
 *  <code>who</code> parameter.
 */
extern int unixem_getrusage(
    int                     who
,   struct unixem_rusage*   r_usage
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_resource */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_SYS_H_RESOURCE */

/* ///////////////////////////// end of file //////////////////////////// */
