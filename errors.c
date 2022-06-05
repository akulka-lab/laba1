#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

void errorsPrint(int *errorCode, char *nameFunction)
{
    printf(
            " _______________________________________________________________________  \n"
            "|                                                                       | \n"
            "|                 You have nothing in the string!                       | \n"
            "|____  _________________________________________________________________| \n"
            "     |/                                                                   \n");
 
    *errorCode = -1;
}
