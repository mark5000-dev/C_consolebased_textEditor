#ifndef MAINLIB_H
#define MAINLIB_H

#include <stdio.h>
#include <stddef.h>

#define BUF_SIZE 1024

#if defined(_WIN32)
/* ssize_t is not always available on Windows/MSVC */
#if defined(_MSC_VER) && !defined(_SSIZE_T_DEFINED)
typedef long ssize_t;
#define _SSIZE_T_DEFINED
#endif

/* Provide our own getline() on Windows */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

void read_file(void);
void append_file(void);
void create_file(void);

void log_action(const char *fmt, ...);

#endif // MAINLIB_H
