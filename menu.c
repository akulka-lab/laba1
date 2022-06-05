#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int* mini_menu(int *menu_number)
{
    printf(
    " _______________________________________________________________________  \n"
    "|                                                                       | \n"
    "|                          Select menu item:                            | \n"
    "|                                                                       | \n"
    "|   1  -> Input with keyboard                                           | \n"
    "|   2  -> Concatenate                                                   | \n"
    "|   3  -> Get substring from i to j                                     | \n"
    "|   4  -> Split into words                                              | \n"
    "|   5  -> Print out                                                     | \n"
    "|                                                                       | \n"
    "|   0 -> Exit                                                           | \n"
    "|____  _________________________________________________________________| \n"
    "     |/                                                                   \n"
    "                                                                          \n");
    scanf("%d", &menu_number);

    while (menu_number < 0 && menu_number > 5)
    {
        printf("Try again\n");
        scanf("%d",&menu_number);
    }

    return menu_number;
}

void* menu(StringPro* str)
{
    char * delim=" \t";
    int menu_number = 0;
    int error = -1;
    int passScanf;

	do{
		menu_number = mini_menu(menu_number);

		if(menu_number == 0)
        {
            menu_number = -1;
            break;
        }

        else if(menu_number == 1)
        {
            str->ProInfo->KeyboardInput(str, &error); // указатель на структуру
			errorsPrint(&error, "KeyboardInput");

        }

        else if(menu_number == 2)
        {
            char addStr[100];

            printf("Enter string to add\n-> ");
			scanf("%s", addStr);

			str->ProInfo->concatenate(str, addStr);
			errorsPrint(&error, "addStr");

        }

        else if(menu_number == 3)
        {
            int i, j;

            printf("begin id\n->");
            scanf("%d", &i);

    		printf("end id (<=%d)\n->", str->len-1);
    		scanf("%d", &j);

			str->ProInfo->subString(str, i, j);

        }

        else if(menu_number == 4)
        {
            str->ProInfo->SplitIntoWords(str, delim, &error); //delim - разделители
			errorsPrint(&error,"SplitIntoWords");

        }

        else if(menu_number == 5)
            str->ProInfo->print(str);


    } while(menu_number != -1);
}
