#include "whale.h"
#include <string.h>

void tokenize(char *line, Token *t) {
    t->type = T_EOF; // Default
    if (strncmp(line, "say ", 4) == 0) {
        t->type = T_SAY;
        char *content = line + 4;
        if (content[0] == '"') content++;
        char *end = strrchr(content, '"');
        if (end) *end = '\0';
        strcpy(t->value, content);
    }
}

