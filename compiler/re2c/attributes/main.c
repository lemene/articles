/**
 * series表示连续匹配字符串的token
 */
 
#include <stdio.h>

enum {
    STRING,
    INTEGER,
    ERROR,
};

struct Input
{
    const char* str;
    int index;
};

struct Token
{
    int id;
    const char* start;
    int len;
};

#include "attributes.c"

void PrintToken(struct Token* t) {
    printf("%d, ", t->id);
    for (int i=0; i<t->len; ++i) printf("%c", t->start[i]);
    printf("\n");
}


int main(int argc, char **argv)
{
    struct Input input = {"12345 abc +", 0};

    while (input.str[input.index] != '\0')
    {
        struct Token token;
        lex(&input, &token);
        PrintToken(&token);
    }
    return 0;
}
