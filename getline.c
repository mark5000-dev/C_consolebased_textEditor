#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "mainLib.h"

#if defined(_WIN32)
/*
 * Simple portable getline implementation for Windows.
 * Returns number of characters read (including the newline), or -1 on EOF or error.
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    if (!lineptr || !n || !stream) {
        errno = EINVAL;
        return -1;
    }

    if (!*lineptr || *n == 0) {
        *n = 128;
        *lineptr = malloc(*n);
        if (!*lineptr) {
            errno = ENOMEM;
            return -1;
        }
    }

    size_t pos = 0;
    int ch;
    while ((ch = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {
            size_t new_size = *n * 2;
            char *new_buf = realloc(*lineptr, new_size);
            if (!new_buf) {
                errno = ENOMEM;
                return -1;
            }
            *lineptr = new_buf;
            *n = new_size;
        }

        (*lineptr)[pos++] = (char)ch;
        if (ch == '\n') {
            break;
        }
    }

    if (pos == 0 && ch == EOF) {
        return -1;
    }

    (*lineptr)[pos] = '\0';
    return (ssize_t)pos;
}
#endif
