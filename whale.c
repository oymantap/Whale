#include <stdio.h>
#include "whale.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: whale <file.w>\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("File error!\n");
        return 1;
    }

    char line[256];
    Token t;

    while (fgets(line, sizeof(line), file)) {
        tokenize(line, &t);
        if (t.type != T_EOF) {
            execute(t);
        }
    }
    fclose(file);
    return 0;
}

