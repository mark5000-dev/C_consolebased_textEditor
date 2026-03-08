#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainLib.h"

void read_file() {
    char *filename = malloc(BUF_SIZE);
    if (!filename) { perror("malloc"); return; }

    printf("Enter filename to read: ");
    if (!fgets(filename, BUF_SIZE, stdin)) { free(filename); return; }
    filename[strcspn(filename, "\n")] = 0;

    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        free(filename);
        return;
    }
    log_action("Reading '%s'", filename);
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, f)) {
        fputs(buffer, stdout);
    }
    fclose(f);
    free(filename);
}
