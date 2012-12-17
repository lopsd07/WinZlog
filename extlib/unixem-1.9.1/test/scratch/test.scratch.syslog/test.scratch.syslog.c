/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.syslog.c
 *
 * Purpose:     Implementation file for the test.scratch.syslog project.
 *
 * Created:     1st October 2006
 * Updated:     13th May 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////////// */

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL Header Files */
#include <platformstl/platformstl.h>


/* UNIXem Header Files */
#include <unixem/unixem.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

#ifdef true
# undef true
#endif /* true */
#ifdef false
# undef false
#endif /* false */
#define true    (1)
#define false   (0)

/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

#if defined(_DEBUG) || \
    defined(_SYB_DEBUG)
static int  s_bDebugging                =   true;
#else /* ? debug */
static int  s_bDebugging                =   false;
#endif /* debug */
//extern "C" const char FE_SIMPLE_PROCESS_IDENTITY[]    =   "test.scratch.syslog";

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */


/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
    puts("test.scratch.syslog: " STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

#if 0
    { size_t i; for(i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    ((void)argc);
    ((void)argv);
    /* . */
    return EXIT_SUCCESS;
}


/* ////////////////////////////////////////////////////////////////////////// */
