#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mainLib.h"

void create_file() {
    char *filename = malloc(BUF_SIZE);
    if (!filename) { perror("malloc"); return; }

    printf("Enter new filename: ");
    if (!fgets(filename, BUF_SIZE, stdin)) { free(filename); return; }
    filename[strcspn(filename, "\n")] = 0;

    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("fopen");
        free(filename);
        return;
    }
    log_action("Created file '%s'", filename);
    printf("Enter text (end with a single dot on a line):\n");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) > 0) {
        if (strcmp(line, ".\n") == 0) break;
        fputs(line, f);
    }
    free(line);
    fclose(f);
    free(filename);
}
