#include "memory.h"
#include <string.h>
#include <ctype.h>

// --- WAJIB ADA DI ATAS FUNGSI ---
Variable memory[50];
int var_count = 0;
// --------------------------------

int is_numeric(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

void set_variable(char *name, char *value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(memory[i].name, name) == 0) {
            strcpy(memory[i].value, value);
            memory[i].is_number = is_numeric(value);
            return;
        }
    }
    strcpy(memory[var_count].name, name);
    strcpy(memory[var_count].value, value);
    memory[var_count].is_number = is_numeric(value);
    var_count++;
}

char* get_variable(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(memory[i].name, name) == 0) return memory[i].value;
    }
    return NULL;
}

