#include "whale.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void tokenize(char *line, Token tokens[], int *count) {
    *count = 0;
    char *ptr = line;

    while (*ptr) {
        if (isspace(*ptr)) { ptr++; continue; }

                if (*ptr == '"') {
            ptr++; // Lewati tanda kutip pembuka
            tokens[*count].type = T_STRING;
            int i = 0;
            // Ambil karakter sampai ketemu tanda kutip penutup
            while (*ptr && *ptr != '"' && i < 255) {
                tokens[*count].value[i++] = *ptr++;
            }
            tokens[*count].value[i] = '\0';
            
            // Jika ketemu tanda kutip penutup, majukan pointer
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
        else if (*ptr == '-') { tokens[*count].type = T_MINUS; strcpy(tokens[*count].value, "-"); ptr++; (*count)++; }
        else if (*ptr == '*') { tokens[*count].type = T_MULTIPLY; strcpy(tokens[*count].value, "*"); ptr++; (*count)++; }
        else if (*ptr == '/') { tokens[*count].type = T_DIVIDE; strcpy(tokens[*count].value, "/"); ptr++; (*count)++; }
        
        else if (isdigit(*ptr)) { // Handle Number
            tokens[*count].type = T_NUMBER;
            int i = 0;
            while (*ptr && isdigit(*ptr)) tokens[*count].value[i++] = *ptr++;
            tokens[*count].value[i] = '\0';
            (*count)++;
        }
        else { // Handle Keywords/Identifiers (PENTING: Harus ada 'else')
            // Cek error di sini
            if (!isalnum(*ptr) && *ptr != '_' && *ptr != '"') {
                printf("Character Error: Unknown character '%c'\n", *ptr);
                return;
            }

            char buffer[64];
            int i = 0;
            // Baca sampai spasi atau operator
            while (*ptr && !isspace(*ptr) && *ptr != '=' && *ptr != '+' && *ptr != '-' && *ptr != '*' && *ptr != '/') {
                buffer[i++] = *ptr++;
            }
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

