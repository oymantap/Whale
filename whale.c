// File: whale.c
#include <stdio.h>
#include <string.h>
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
    Token tokens[10];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        // BERSIHKAN ARRAY TOKENS
        memset(tokens, 0, sizeof(tokens)); 
        
        count = 0;
        tokenize(line, tokens, &count);

        if (count > 0) {
            parse_and_execute(tokens, count);
        }
    }
    fclose(file);
    return 0;
}
