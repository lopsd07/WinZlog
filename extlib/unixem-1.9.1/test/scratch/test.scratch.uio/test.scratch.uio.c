/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.uio.cpp
 *
 * Purpose:     Implementation file for the test.scratch.uio project.
 *
 * Created:     19th September 2005
 * Updated:     9th February 2008
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


/* Standard C++ Header Files */
#include <exception>

#ifdef __WATCOMC__
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */


/* Standard C Header Files */
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/stat.h>
#include <sys/uio.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char **argv)
{
    /* . */
    if(argc < 2)
    {
        fprintf(stderr, "Must specify file\n");
    }
    else
    {
        char const      *fileName   =   argv[1];
        int             fd          =   ::_open(fileName, _O_RDONLY);
        struct iovec    vectors[3];
        char            sz1[10];
        char            sz2[2];
        char            sz3[21];

        vectors[0].iov_base =   &sz1[0];
        vectors[0].iov_len  =   sizeof(sz1);
        vectors[1].iov_base =   &sz2[0];
        vectors[1].iov_len  =   sizeof(sz2);
        vectors[2].iov_base =   &sz3[0];
        vectors[2].iov_len  =   sizeof(sz3);

        size_t          n           =   readv(fd, &vectors[0], 3);
    }

    return 0;
}

int main(int argc, char *argv[])
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
        return main_(argc, argv);
    }
    catch(std::exception &x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");
    }

    return EXIT_FAILURE;
}

/* ////////////////////////////////////////////////////////////////////////// */
