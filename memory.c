#include "memory.h"
#include <string.h>

Variable memory[50];
int var_count = 0;

void set_variable(char *name, char *value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(memory[i].name, name) == 0) {
            strcpy(memory[i].value, value);
            return;
        }
    }
    strcpy(memory[var_count].name, name);
    strcpy(memory[var_count].value, value);
    var_count++;
}

char* get_variable(char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(memory[i].name, name) == 0) return memory[i].value;
    }
    return NULL;
}

