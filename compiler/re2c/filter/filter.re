static const char *lex(struct Input* input)
{
    const char *YYCURSOR = input->str + input->index;
    const char *YYMARKER;
    
    for (;;) {
        /*!re2c
            re2c:define:YYCTYPE = char;
            re2c:yyfill:enable = 0;

            dec = [1-9][0-9]*;
            str = [a-zA-Z]+;
            ws  = [ \t\n]+;

            ws      { input->index = YYCURSOR-input->str; continue;}
            *       { input->index = YYCURSOR-input->str;  return "Error"; }
            dec     { input->index = YYCURSOR-input->str;  return "Integer"; }
            str     { input->index = YYCURSOR-input->str;  return "String"; }
        */
    }
}
