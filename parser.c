#include "whale.h"
#include "memory.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_num(char *val) {
    char *v = get_variable(val);
    char *target = v ? v : val;
    for(int i=0; target[i]; i++) if(target[i] < '0' || target[i] > '9') return 0;
    return 1;
}

void parse_all(Token tokens[], int count) {
    int i = 0;
    while (i < count) {
        if (tokens[i].type == T_IDENTIFIER && i+1 < count && tokens[i+1].type == T_ASSIGN) {
            set_variable(tokens[i].value, tokens[i+2].value);
            i += 3;
        } else if (tokens[i].type == T_SAY) {
            i++;
            while (i < count && tokens[i].type != T_EOF && tokens[i].type != T_SAY) {
                // 1. Cek Matematika DULU (Prioritas tertinggi)
                if (is_num(tokens[i].value) && i+1 < count && (tokens[i+1].type == T_PLUS || tokens[i+1].type == T_MULTIPLY)) {
                    int v1 = atoi(get_variable(tokens[i].value) ? get_variable(tokens[i].value) : tokens[i].value);
                    int op = tokens[i+1].type;
                    int v2 = atoi(get_variable(tokens[i+2].value) ? get_variable(tokens[i+2].value) : tokens[i+2].value);
                    
                    // Cek lookahead untuk perkalian (a + b * c)
                    if (i+3 < count && tokens[i+3].type == T_MULTIPLY) {
                        int v3 = atoi(get_variable(tokens[i+4].value) ? get_variable(tokens[i+4].value) : tokens[i+4].value);
                        printf("%d", v1 + (v2 * v3));
                        i += 4;
                    } else {
                        printf("%d", (op == T_PLUS) ? (v1 + v2) : (v1 * v2));
                        i += 2;
                    }
                } 
                // 2. Cek String/Var (Hanya jika bukan angka/math)
                else if (tokens[i].type == T_STRING || tokens[i].type == T_IDENTIFIER) {
                    char *v = get_variable(tokens[i].value);
                    if (v) printf("%s", v);
                    else if (tokens[i].type != T_PLUS && tokens[i].type != T_MULTIPLY) 
                        printf("%s", tokens[i].value);
                }
                i++;
            }
            printf("\n");
        } else i++;
    }
}

