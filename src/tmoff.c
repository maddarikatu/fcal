#include <time.h>

#include "fcal.h"

int
tmoff(struct tm *ltm)
{
    int offset;
#ifdef __GNU_LIBRARY__
    offset = ltm->tm_gmtoff;
#else
    time_t lt;
    struct tm *gmt;

    lt = time(NULL);
    gmt = gmtime(&lt);

    offset = difftime(mktime(ltm), mktime(gmt));
#endif
    return offset;
}
