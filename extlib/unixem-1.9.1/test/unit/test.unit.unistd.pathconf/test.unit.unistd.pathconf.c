
#include <xtests/xtests.h>

#include <unistd.h>

#include <limits.h>
#include <stdlib.h>
#include <windows.h>


int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.unistd.pathconf", verbosity))
    {
        /* Test-1 */
        if(XTESTS_CASE_BEGIN("Test-1", "testing pathconf"))
        {
            XTESTS_TEST_INTEGER_EQUAL(LONG_MAX,       pathconf("",          _PC_LINK_MAX));
            XTESTS_TEST_INTEGER_EQUAL(LONG_MAX,       pathconf("",          _PC_MAX_CANON));
            XTESTS_TEST_INTEGER_EQUAL(LONG_MAX,       pathconf("",          _PC_MAX_INPUT));
            XTESTS_TEST_INTEGER_EQUAL(_MAX_FNAME - 1, pathconf("/",         _PC_NAME_MAX));
            XTESTS_TEST_INTEGER_EQUAL(_MAX_FNAME - 9, pathconf("/01234567", _PC_NAME_MAX));
            XTESTS_TEST_INTEGER_EQUAL(_MAX_PATH - 1,  pathconf("/",         _PC_PATH_MAX));
            XTESTS_TEST_INTEGER_EQUAL(_MAX_PATH - 9,  pathconf("/01234567", _PC_PATH_MAX));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_PIPE_BUF));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_CHOWN_RESTRICTED));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_NO_TRUNC));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_VDISABLE));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_AIX_DISK_PARTITION));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_AIX_DISK_SIZE));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_FILESIZEBITS));
            XTESTS_TEST_INTEGER_EQUAL(-1,             pathconf("",          _PC_SYNC_IO));

            XTESTS_CASE_END("Test-1");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */
