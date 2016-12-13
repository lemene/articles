#include <stdio.h>

static const char *lex(const char *YYCURSOR)
{
    const char *YYMARKER;
    /*!re2c
        re2c:define:YYCTYPE = char;
        re2c:yyfill:enable = 0;

        dec = [1-9][0-9]*;
        str = [a-zA-Z]+;

        *       { return "Error"; }
        dec     { return "Integer"; }
        str     { return "String"; }
    */
}
