#ifndef TOKEN_H
#define TOKEN_H

typedef enum { T_SAY, T_STRING, T_EOF } TokenType;
typedef struct { TokenType type; char value[256]; } Token;

#endif

