#include "whale.h"
#include <stdio.h>

void execute(Token t) {
    if (t.type == T_SAY) {
        printf("%s\n", t.value);
    }
}

