#define MAKE_TOKEN(t, _id, _start, _end) \
    t->id = _id; t->start=_start; t->len = (_end)-(_start)

static int lex(struct Input* input, struct Token* token)
{
    const char *YYCURSOR = input->str + input->index;
    const char *YYMARKER;
    
    for (;;) {
        /*!re2c
            re2c:define:YYCTYPE = char;
            re2c:yyfill:enable = 0;
            

            dec = [1-9][0-9]*;
            str = [a-zA-Z]+;
            ws  = [ \t]+;
            

            ws      { input->index = YYCURSOR-input->str; continue;}
            dec     { 
                        MAKE_TOKEN(token, INTEGER, input->str+input->index, YYCURSOR);
                        input->index = YYCURSOR-input->str;  
                        return 0;
                    }
            str     { 
                        MAKE_TOKEN(token, STRING, input->str+input->index, YYCURSOR);
                        input->index = YYCURSOR-input->str;  
                        return 0;
                    }
            *       { 
                        MAKE_TOKEN(token, ERROR, input->str+input->index, YYCURSOR);
                        input->index = YYCURSOR-input->str;  
                        return -1;
                    }
        */
    }
}
