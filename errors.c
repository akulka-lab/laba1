#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

void errorsPrint(int *errorCode, char *nameFunction)
{
    if(*errorCode == EMPTY_STRING)
    {
         printf(
            " _______________________________________________________________________  \n"
            "|                                                                       | \n"
            "|                 You have nothing in the string!                       | \n"
            "|____  _________________________________________________________________| \n"
            "     |/                                                                   \n");
    }

    if(*errorCode == NULL_DELIM)
    {
         printf(
            " _______________________________________________________________________  \n"
            "|                                                                       | \n"
            "|                       Delim is not defined....                        | \n"
            "|____  _________________________________________________________________| \n"
            "     |/                                                                   \n");
    }

    *errorCode = -1;
}
