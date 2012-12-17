/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.dlfcn.c
 *
 * Purpose:     Implementation file for the test.scratch.dlfcn project.
 *
 * Created:     1st January 2004
 * Updated:     9th February 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (C) 1999-2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 *              This source code is placed into the public domain 2004
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

#include <dlfcn.h>

#include <stdio.h>

/* ////////////////////////////////////////////////////////////////////////// */

int main(int argc, char *argv[])
{
#if 0
    ::Sleep(100000);
#endif /* 0 */

    char const  *moduleName =   
//                          "MMCmnBas.dll"
//                          "F:\\WINXP\\system32\\win32k.sys"
//                          "F:\\WINXP\\system32\\ntdos.sys"
                            "H:\\Publishing\\Books\\ImpC++\\Drafting\\Pt5_Resource_Management\\Ch5.4_Arrays.doc"
                            ;

    void    *module =   dlopen(moduleName, RTLD_NOW);

    if(NULL == module)
    {
        printf("Failed to open module: %s\n", dlerror());
    }
    else
    {
        void *symbol = dlsym(module, "DllGetVersion");

        if(NULL == symbol)
        {
            printf("Failed to retrive symbol: %s\n", dlerror());
        }

        dlclose(module);
    }

    ((void)argc);
    ((void)argv);
    /* . */

    return 0;
}

/* ////////////////////////////////////////////////////////////////////////// */
