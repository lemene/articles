#include <stdlib.h>
#include "arith.h"
#include "arith.c"  // 不需要编译arith.c

int main()
{
    void *pParser = ParseAlloc(malloc);

    // 12 + 4*5
    Parse(pParser, INTEGER, 12);
    Parse(pParser, PLUS, 0);
    Parse(pParser, INTEGER, 4);
    //Parse(pParser, TIMES, 0);
    Parse(pParser, INTEGER, 5);
    Parse(pParser, 0, 0);

    ParseFree(pParser, free);
}
