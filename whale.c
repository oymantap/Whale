#include <stdio.h>
#include <stdlib.h>
#include "whale.h"

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    FILE *f = fopen(argv[1], "rb");
    if (!f) return 1;
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    char *buf = malloc(size + 1); fread(buf, 1, size, f); buf[size] = '\0'; fclose(f);
    Token *tokens = malloc(sizeof(Token) * 1000); int count = 0;
    tokenize(buf, tokens, &count);
    parse_all(tokens, count);
    free(buf); free(tokens); return 0;
}

