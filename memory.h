#ifndef MEMORY_H
#define MEMORY_H

typedef struct {
    char name[50];
    char value[100];
} Variable;

void set_variable(char *name, char *value);
char* get_variable(char *name);

#endif

