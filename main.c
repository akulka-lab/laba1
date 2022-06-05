#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main()
{
    printf(
    " _______________________________________________________________________  \n"
    "|                                                                       | \n"
    "|              Welcome to Lab1! Starting the program....                | \n"
    "|____  _________________________________________________________________| \n"
    "     |/                                                                   \n");

    StringPro* str = initialize();
    menu(str);

    str->ProInfo->freedom(str);
    return 0;
}
