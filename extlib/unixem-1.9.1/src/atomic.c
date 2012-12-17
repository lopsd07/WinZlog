/* /////////////////////////////////////////////////////////////////////////
 * File:    atomic.c
 *
 * Purpose: Implementation of Linux like atomic functions for the
 *          Win32 platform.
 *
 * Created: 21st November 2003
 * Updated: 12th August 2010
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


#ifndef UNIXEM_DOCUMENTATION_SKIP_SECTION
# define _SYNSOFT_VER_C_ATOMIC_MAJOR    3
# define _SYNSOFT_VER_C_ATOMIC_MINOR    0
# define _SYNSOFT_VER_C_ATOMIC_REVISION 1
# define _SYNSOFT_VER_C_ATOMIC_EDIT     19
#endif /* !UNIXEM_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixem/asm/atomic.h>

#include <unixem/unixem.h>

#include <errno.h>
#include <windows.h>

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WIN32
# error This file is only currently defined for Win32 compilation units
#endif /* WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

void unixem_atomic_set(unixem_atomic_t volatile* v, int i)
{
    (void)InterlockedExchange((LPLONG)v, i);
}

int unixem_atomic_read(unixem_atomic_t volatile* v)
{
    return *v;
}

void unixem_atomic_add(int i, unixem_atomic_t volatile* v)
{
    (void)InterlockedExchangeAdd((LPLONG)v, i);
}

void unixem_atomic_sub(int i, unixem_atomic_t volatile* v)
{
    (void)InterlockedExchangeAdd((LPLONG)v, -i);
}

void unixem_atomic_inc(unixem_atomic_t volatile* v)
{
    (void)InterlockedIncrement((LPLONG)v);
}

void unixem_atomic_dec(unixem_atomic_t volatile* v)
{
    (void)InterlockedDecrement((LPLONG)v);
}

int unixem_atomic_inc_and_test(unixem_atomic_t volatile* v)
{
    return -1 + InterlockedIncrement((LPLONG)v);
}

int unixem_atomic_dec_and_test(unixem_atomic_t volatile* v)
{
    return 1 + InterlockedDecrement((LPLONG)v);
}

int unixem_atomic_add_and_test(int i, unixem_atomic_t volatile* v);

int unixem_atomic_sub_and_test(int i, unixem_atomic_t volatile* v);

/* ///////////////////////////// end of file //////////////////////////// */
