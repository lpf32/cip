#include "utils.h"
extern int debug;

int run_cmd(char *cmd, ...)
{
    va_list ap;
    char buf[CMDBUFLEN];
    va_start(ap, cmd);
    vsnprintf(buf, CMDBUFLEN, cmd, ap);

    va_end(ap);

    if (debug)
    {
        printf("EXEC: %s\n", buf);
    }

    return system(buf);
}

void print_err(char *format, ...)
{
    va_list ap;
    va_start(ap,format);

    vfprintf(stderr, format, ap);

    va_end(ap);
}