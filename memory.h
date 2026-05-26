#ifndef MEMORY_H
#define MEMORY_H

typedef struct {
    char name[64];
    char value[256];
    int is_number; // <--- TAMBAHKAN INI (0 = false, 1 = true)
} Variable;

void set_variable(char *name, char *value);
char* get_variable(char *name);

#endif

