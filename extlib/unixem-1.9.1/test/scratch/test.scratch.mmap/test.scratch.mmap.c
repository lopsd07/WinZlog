/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.mmap.cpp
 *
 * Purpose:     Implementation file for the test.scratch.mmap project.
 *
 * Created:     18th December 2003
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
 *              This source code is placed into the public domain 2003
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

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <io.h>
#include <share.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#ifdef WIN32
//# include <windows.h>
#endif /* WIN32 */

//#define   TEST_READONLY
//#define   TEST_READWRITE
//#define   TEST_PAGING

/* ////////////////////////////////////////////////////////////////////////// */

#if (   defined(WIN32) || \
        defined(_WIN32)) && \
    !defined(_INC_WINDOWS)
extern "C" void __stdcall Sleep(unsigned long);
#endif /* WIN32 */

/* ////////////////////////////////////////////////////////////////////////// */

/** \brief Maps a file
 *
 * This function supports three modes:
 *
 * 1. Read-only.
 *
 *      fileName must refer to an existing file
 *      len can be 0, for all the file contents, or any size up to the length 
 *          of the file. It is an error if the length exceeds the length of
 *          the file
 *      prot is PROT_READ
 *      flags is ignored in the current implementation
 *
 * 2. Read-write
 *
 *      fileName must refer to an existing file
 *      len can be 0, for all the file contents, or any size up to the length 
 *          of the file. If it is longer than the current size of the file, the
 *          file is extended.
 *      prot contains PROT_WRITE, and is then assumed to be 
 *          (PROT_READ | PROT_WRITE). All other flags are ignored
 *      flags is ignored in the current implementation
 *
 * 3. System-page file
 *
 *      fileName must be NULL
 *      len must be > 0. It is rounded up to the page-size internally
 *      prot is ignored, It is always assumed to be PROT_READ | PROT_WRITE
 *      flags is ignored in the current implementation
 */

extern "C"
void *mmap_file(char const  *fileName   /* = NULL */
            ,   size_t      len
            ,   size_t      offset
            ,   int         prot
            ,   int         flags
            ,   size_t      *plen);

/* ////////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char ** /*argv*/)
{
#if 0
    ::Sleep(100000);
#endif /* 0 */

    /* . */
#if defined(TEST_READONLY)
    char const  *fileName   =   "h:\\dev\\bin\\mmcmnbas.dll";
    void        *pv         =   mmap_file(fileName, 0, 1000, PROT_READ, 0, NULL);
#elif defined(TEST_READWRITE)
    char const  *fileName   =   "test-file.txt";
    void        *pv         =   mmap_file(fileName, 1000, 0, PROT_WRITE, 0, NULL);
#elif defined(TEST_PAGING)
    char const  *fileName   =   "<page-file>";
    void        *pv         =   mmap_file(NULL, 1000, 0, 0, 0, NULL);
#else
# error Must define one only of TEST_READONLY, TEST_READWRITE or TEST_PAGING
#endif

    if(MAP_FAILED == pv)
    {
        fprintf(stderr, "Failed to load \"%s\": %s\n", fileName, strerror(errno));
    }
    else
    {
        fprintf(stderr, "Loaded \"%s\"", fileName);

#if defined(TEST_READWRITE) || \
    defined(TEST_PAGING)
        memset(pv, 99, 2);

        msync(pv, 0, 0);
#endif /* TEST_READWRITE || TEST_PAGING */

        munmap(pv, 0);
    }

    return 0;
}

/* ////////////////////////////////////////////////////////////////////////// */
