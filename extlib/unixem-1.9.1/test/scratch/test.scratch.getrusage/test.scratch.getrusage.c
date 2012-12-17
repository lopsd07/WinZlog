/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.getrusage.c
 *
 * Purpose:     Implementation file for the test.scratch.getrusage project.
 *
 * Created:     9th June 2006
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
#include <sys/resource.h>
#include <unixem/internal/safestr.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
    ((void)argc);
    ((void)argv);

    {
        struct rusage   usage;

        { size_t i; for(i = 0; i < 0xffffff; ++i){} }

        { size_t i; for(i = 0; i < 10; ++i)
        {
#ifdef UNIXEM_USING_SAFE_STR_FUNCTIONS
            FILE    *f;
            errno_t e = fopen_s(&f, "abc", "w");

            if(0 == e)
#else /* ? UNIXEM_USING_SAFE_STR_FUNCTIONS */
            FILE    *f = fopen("abc", "w");

            if(NULL != f)
#endif /* UNIXEM_USING_SAFE_STR_FUNCTIONS */
            {
                char    buf[100]    =   "";
                int     j;

                for(j = 0; j < 100; ++j)
                {
                    fwrite(&buf[0], 100, 1, f);
                }

                fclose(f);
            }
        }}

        getrusage(0, &usage);

        printf("system: %ld - %ld\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("user:   %ld - %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    }

    return EXIT_SUCCESS;
}


/* ////////////////////////////////////////////////////////////////////////// */
