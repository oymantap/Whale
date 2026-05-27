#include "whale.h"
#include <string.h>
#include <ctype.h>

void tokenize(char *script, Token tokens[], int *count) {
    *count = 0; char *ptr = script;
    while (*ptr && *count < 1000) {
        if (isspace(*ptr)) { ptr++; continue; }
        if (*ptr == '"') {
            ptr++; tokens[*count].type = T_STRING;
            int i = 0; while (*ptr && *ptr != '"') tokens[*count].value[i++] = *ptr++;
            tokens[*count].value[i] = '\0'; ptr++; (*count)++;
        } else if (*ptr == '+') { tokens[*count].type = T_PLUS; strcpy(tokens[*count].value, "+"); (*count)++; ptr++; }
        else if (*ptr == '-') { tokens[*count].type = T_MINUS; strcpy(tokens[*count].value, "-"); (*count)++; ptr++; }
        else if (*ptr == '*') { tokens[*count].type = T_MULTIPLY; strcpy(tokens[*count].value, "*"); (*count)++; ptr++; }
        else if (*ptr == '/') { tokens[*count].type = T_DIVIDE; strcpy(tokens[*count].value, "/"); (*count)++; ptr++; }
        else if (*ptr == '=') { tokens[*count].type = T_ASSIGN; strcpy(tokens[*count].value, "="); (*count)++; ptr++; }
        else if (isdigit(*ptr)) {
            tokens[*count].type = T_NUMBER;
            int i = 0; while (isdigit(*ptr)) tokens[*count].value[i++] = *ptr++;
            tokens[*count].value[i] = '\0'; (*count)++;
        } else {
            char b[64]; int i = 0;
            while (*ptr && !isspace(*ptr) && *ptr != '=' && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '/') b[i++] = *ptr++;
            b[i] = '\0';
            if (strcmp(b, "say") == 0) tokens[*count].type = T_SAY;
            else { tokens[*count].type = T_IDENTIFIER; strcpy(tokens[*count].value, b); }
            (*count)++;
        }
    }
}

