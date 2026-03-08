#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include "mainLib.h"


static void get_timestamp(char *buf, size_t n) {
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    strftime(buf, n, "[%Y-%m-%d %H:%M:%S]", lt);
}

void log_action(const char *fmt, ...) {
    static FILE *log_fp = NULL;
    if (!log_fp) {
        log_fp = fopen("editor.log", "a");
        if (!log_fp) {
            perror("fopen(editor.log)");
        }
    }

    char timebuf[32];
    get_timestamp(timebuf, sizeof timebuf);

    /* Always print to stdout */
    printf("%s ", timebuf);

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    putchar('\n');

    /* Also append to a log file (if available) */
    if (log_fp) {
        fprintf(log_fp, "%s ", timebuf);
        va_start(args, fmt);
        vfprintf(log_fp, fmt, args);
        va_end(args);
        fputc('\n', log_fp);
        fflush(log_fp);
    }
}
