/* /////////////////////////////////////////////////////////////////////////
 * File:    unixem/setenv.h
 *
 * Purpose: Definition of the setenv() and unsetenv() functions.
 *
 * Created: 9th December 2005
 * Updated: 13th August 2010
 *
 * Home:    http://synesis.com.au/software/
 *
 * Copyright (c) 2005-2010, Matthew Wilson and Synesis Software
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


/** \file unixem/setenv.h Definition of the setenv() and unsetenv() functions
 */

#ifndef SYNSOFT_UNIXEM_INCL_UNIXEM_H_SETENV
#define SYNSOFT_UNIXEM_INCL_UNIXEM_H_SETENV

#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define UNIXEM_VER_UNIXEM_H_SETENV_MAJOR       2
# define UNIXEM_VER_UNIXEM_H_SETENV_MINOR       0
# define UNIXEM_VER_UNIXEM_H_SETENV_REVISION    1
# define UNIXEM_VER_UNIXEM_H_SETENV_EDIT        7
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/unixem.h>
#include <stddef.h>     /* for size_t */
#include <sys/types.h>  /* for mode_t */

#if defined(__WATCOMC__)
# error The Watcom RTL provides setenv()
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

/** \weakgroup unixem Synesis Software UNIX Emulation for Win32
 * \brief The UNIX emulation library
 */

/** \weakgroup unixem_setenv setenv.h
 * \ingroup UNIXem unixem
 * \brief setenv() and unsetenv() functions
 * @{
 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

# ifdef __cplusplus
extern "C" {
# endif /* __cplusplus */

/** Inserts or resets the value of an environment variable.
 *
 * This function creates a link from \c originalFile to \c linkName.
 *
 * \param name The name of the environment variable to add / set
 * \param value The value of the environment variable
 * \param bOverwrite Determines whether to overwrite the variable, if it exists,
 *         or to leave its current value intact
 *
 * \return O on success, or -1 if there is an error
 */
int unixem_setenv(
    char const* name
,   char const* value
,   int         bOverwrite
);


/** Deletes the named environment variable, if it exists.
 *
 * \param name The name of the environment to delete
 *
 * \return O on success, or -1 if there is an error
 */
void unixem_unsetenv(char const* name);

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

/** @} // end of group unixem_setenv */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* SYNSOFT_UNIXEM_INCL_UNIXEM_H_SETENV */

/* ///////////////////////////// end of file //////////////////////////// */
