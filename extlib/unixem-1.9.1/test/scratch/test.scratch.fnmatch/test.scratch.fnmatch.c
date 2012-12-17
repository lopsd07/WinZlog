/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.fnmatch.c
 *
 * Purpose:     Implementation file for the test.scratch.fnmatch project.
 *
 * Created:     24th April 2006
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
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software. 
 *
 *              This source code is provided by Synesis Software Pty Ltd "as is"
 *              and any warranties, whether expressed or implied, including, but
 *              not limited to, the implied warranties of merchantability and
 *              fitness for a particular purpose are disclaimed. In no event
 *              shall the Synesis Software Pty Ltd be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of
 *              substitute goods or services; loss of use, data, or profits; or
 *              business interruption) however caused and on any theory of
 *              liability, whether in contract, strict liability, or tort
 *              (including negligence or otherwise) arising in any way out of
 *              the use of this software, even if advised of the possibility of
 *              such damage. 
 *
 *              Neither the name of Synesis Software Pty Ltd nor the names of
 *              any subdivisions, employees or agents of Synesis Software Pty
 *              Ltd, nor the names of any other contributors to this software
 *              may be used to endorse or promote products derived from this
 *              software without specific prior written permission. 
 *
 * ////////////////////////////////////////////////////////////////////////// */

/* UNIXem Header Files */
#include <fnmatch.h>

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

static int  s_bDebugging    =   false;

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */


/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void test_1(void);
static void test_2(void);
static void test_3(void);

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
#if 0
    { size_t i; for(i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    ((void)argc);
    ((void)argv);
    /* . */

    test_1();

    return EXIT_SUCCESS;
}

/* ////////////////////////////////////////////////////////////////////////// */

static void test_1(void)
{
    if(0 != fnmatch("a", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }
    if(0 == fnmatch("a", "b", 0))
    {
        fprintf(stderr, "test failed!\n");
    }

    if(0 != fnmatch("[a-d]", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }

    if(0 == fnmatch("[^A-Zb-z0-9]", "a", 0))
    {
        fprintf(stderr, "test failed!\n");
    }
}

static void test_2(void)
{
//  int fnmatch(char const *pattern, char const *string, int flags);
}

static void test_3(void)
{
//  int fnmatch(char const *pattern, char const *string, int flags);
}

/* ////////////////////////////////////////////////////////////////////////// */
