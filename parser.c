#include "whale.h"
#include "memory.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Helper to check if variable value is numeric
int is_var_number(char *name) {
    char *val = get_variable(name);
    if (val == NULL) return 0;
    for (int i = 0; val[i] != '\0'; i++) {
        if (!isdigit(val[i])) return 0;
    }
    return 1;
}

// Perform calculation based on operator
int calculate(int a, int b, TokenType op) {
    switch (op) {
        case T_PLUS:     return a + b;
        case T_MINUS:    return a - b;
        case T_MULTIPLY: return a * b;
        case T_DIVIDE:   return (b != 0) ? a / b : 0;
        default:         return 0;
    }
}

void get_val(Token t, char *buffer) {
    if (t.type == T_IDENTIFIER) {
        char *val = get_variable(t.value);
        if (val) strcpy(buffer, val);
        else strcpy(buffer, t.value);
    } 
    else {
        strcpy(buffer, t.value);
    }
}

void parse_and_execute(Token tokens[], int count) {
    if (count >= 3 && tokens[1].type == T_ASSIGN) {
        set_variable(tokens[0].value, tokens[2].value);
    }
    else if (tokens[0].type == T_SAY) {
        int sum = 0;
        int is_math = 0;
        char result[512] = "";

        for (int i = 1; i < count; i += 2) {
            char val[256];
            get_val(tokens[i], val);
            int current_val = atoi(val);

            // Check if it's numeric
            if (tokens[i].type == T_NUMBER || (tokens[i].type == T_IDENTIFIER && is_var_number(tokens[i].value))) {
                if (i == 1) {
                    sum = current_val;
                    is_math = 1;
                } else if (is_math) {
                    sum = calculate(sum, current_val, tokens[i-1].type);
                }
            } else {
                is_math = 0;
                strcat(result, val);
            }

            // Error Handling: Expecting an operator after the value
            if (i + 1 < count && tokens[i+1].type != T_PLUS && tokens[i+1].type != T_MINUS && 
                tokens[i+1].type != T_MULTIPLY && tokens[i+1].type != T_DIVIDE) {
                printf("Parser Error: Expected operator, found '%s'\n", tokens[i+1].value);
                return;
            }
        }

        if (is_math) {
            printf("%d\n", sum);
        } else {
            printf("%s\n", result);
        }
    }
}

