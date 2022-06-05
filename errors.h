#include <stdio.h>
#include <stdlib.h>

enum Errors
{
    EMPTY_STRING,
    NULL_DELIM
};

void errorsPrint(int * errorCode,char * nameFunction);
