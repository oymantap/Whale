// File: whale.h
#ifndef WHALE_H
#define WHALE_H

#include "token.h"

// Ubah baris ini agar sesuai dengan array
void tokenize(char *line, Token tokens[], int *count); 
void parse_and_execute(Token tokens[], int count);

#endif

