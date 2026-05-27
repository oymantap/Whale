#ifndef WHALE_H
#define WHALE_H

#include "token.h"

void tokenize(char *script, Token tokens[], int *count);
void parse_all(Token tokens[], int count);

#endif

