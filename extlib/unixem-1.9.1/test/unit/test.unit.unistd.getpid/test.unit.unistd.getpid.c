
#include <xtests/xtests.h>

#include <unistd.h>

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
            XTESTS_TEST_INTEGER_EQUAL((pid_t)GetCurrentProcessId(), getpid());

            XTESTS_CASE_END("Test-1");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */
