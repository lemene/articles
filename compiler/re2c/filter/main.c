/**
 * series表示连续匹配字符串的token
 */
 
#include <stdio.h>

struct Input
{
    const char* str;
    int index;
};

#include "filter.c"



int main(int argc, char **argv)
{
    struct Input input = {"12345 abc +", 0};

    while (input.str[input.index] != '\0')
    {
        printf("%d\n", input.index);
        printf("%s\n", lex(&input));
    }
    return 0;
}
