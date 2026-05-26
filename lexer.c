#include "whale.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void tokenize(char *line, Token tokens[], int *count) {
    *count = 0;
    char *ptr = line;

    while (*ptr) {
        if (isspace(*ptr)) { ptr++; continue; }

        if (*ptr == '"') { // Handle String
            ptr++;
            tokens[*count].type = T_STRING;
            int i = 0;
            while (*ptr && *ptr != '"') tokens[*count].value[i++] = *ptr++;
            tokens[*count].value[i] = '\0';
            if (*ptr == '"') ptr++;
            (*count)++;
        }
        else if (*ptr == '=') { // Handle Assignment
            tokens[*count].type = T_ASSIGN;
            strcpy(tokens[*count].value, "=");
            ptr++;
            (*count)++;
        }
        else if (*ptr == '+') { // Handle Plus
            tokens[*count].type = T_PLUS;
            strcpy(tokens[*count].value, "+");
            ptr++;
            (*count)++;
        }
                 else { // Handle Keywords/Identifiers
            // --- BAGIAN INI UNTUK DETEKSI ERROR ---
            if (!isalnum(*ptr) && *ptr != '_' && *ptr != '=' && *ptr != '+' && *ptr != '"') {
                printf("Lexer Error: Karakter tidak dikenal '%c'\n", *ptr);
                return; // Berhenti total jika ketemu simbol aneh
            }
            // --------------------------------------

            char buffer[64];
            int i = 0;
            // Baca karakter sampai ketemu spasi atau operator
            while (*ptr && !isspace(*ptr) && *ptr != '=' && *ptr != '+') buffer[i++] = *ptr++;
            buffer[i] = '\0';

            if (i > 0) {
                if (strcmp(buffer, "say") == 0) tokens[*count].type = T_SAY;
                else {
                    tokens[*count].type = T_IDENTIFIER;
                    strcpy(tokens[*count].value, buffer);
                }
                (*count)++;
            }
        }

    }
}

