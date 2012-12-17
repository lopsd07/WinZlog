/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.link.c
 *
 * Purpose:     Implementation file for the test.scratch.link project.
 *
 * Created:     2nd September 2005
 * Updated:     13th May 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 1999-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2005
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
#include <unixem/unixem.h>
#include <unixem/implicit_link.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    if(argc < 3)
    {
        fprintf(stderr, "USAGE: test.scratch.link <originalFile> <linkName>\n");

        return EXIT_FAILURE;
    }
    else
    {
        int res =   link(argv[1], argv[2]);

        if(0 == res)
        {
            fprintf(stdout, "\"%s\" => \"%s\"\n", argv[1], argv[2]);

            return EXIT_SUCCESS;
        }
        else
        {
            fprintf(stderr, "link() failed: %d (%s)\n", errno, strerror(errno));

            return EXIT_FAILURE;
        }
    }
}


/* ////////////////////////////////////////////////////////////////////////// */
