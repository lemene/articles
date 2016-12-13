#include "first.c"



int main(int argc, char **argv)
{
    const char * strs [] = {
        "12345",
        "abc",
        "+",
        NULL
    };

    for (int i=0; strs[i] != NULL; i++) 
    {
        printf("%s is %s\n", strs[i], lex(strs[i]));
    }
    return 0;
}
