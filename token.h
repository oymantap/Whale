#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    T_SAY, T_STRING, T_NUMBER, T_IDENTIFIER, T_ASSIGN, 
    T_PLUS, T_MINUS, T_MULTIPLY, T_DIVIDE, T_EOF
} TokenType;

typedef struct { TokenType type; char value[256]; } Token;

#endif

