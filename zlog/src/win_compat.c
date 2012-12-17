#ifdef _MSC_VER
//#include <winsock2.h>
// #ifndef WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// #define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// #include <winsock2.h>
// //#include <windows.h>
// #endif
// #include <winsock2.h>
#include "event.h"

#include <time.h>
#include <stdio.h>

int strcasecmp(char *a,char *b) {
  return(_stricmp(a,b));
}

struct tm *localtime_r(long *clock,struct tm *res)
{
    _localtime32_s(res,clock);
    return(res);
}

int gettimeofday(struct timeval *tp,struct timezone *tz)
{
SYSTEMTIME st;

    if (tp!=NULL) {
	tp->tv_sec = _time32(NULL);
	GetLocalTime(&st);
	tp->tv_usec = 1000L * st.wMilliseconds;
    } /* if */

    return(0);
}

int fsync(FILE *fp) {
  return(fflush(fp));
}

#endif
