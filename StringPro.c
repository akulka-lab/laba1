#include"StringPro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



StringPro* initialize()
{
    StringPro* StrPro = malloc(sizeof(StringPro*));
    StrPro->ProInfo = Create(&KeyboardInput,&concatenate,&subString,&SplitIntoWords,&print,&freedom);
    StrPro->len = 0;
    StrPro->ptr = NULL;
}

void* KeyboardInput(void* str, int * error)
{
    StringPro* StrPro = (StringPro*) str;
    printf(
        " _______________________________________________________________________  \n"
        "|                                                                       | \n"
        "|                          Enter string:                                | \n"
        "|____  _________________________________________________________________| \n"
        "     |/                                                                   \n");

    char keyBoardInputStr[100] = {0};
    scanf("%*c");
    scanf("%[^\n]",keyBoardInputStr);

    if (keyBoardInputStr[0] == NULL)
    {
        *error = EMPTY_STRING;
        return NULL;
    }

    char * keyBoardInputPtr = malloc(sizeof(char)*strlen(keyBoardInputStr));
    memcpy(keyBoardInputPtr,keyBoardInputStr,strlen(keyBoardInputStr)*sizeof(char));
    StrPro->ptr = keyBoardInputPtr;
    StrPro->len = strlen(keyBoardInputPtr);
}

void* concatenate(void* str,char * addStr)
{
    StringPro* StrPro = (StringPro*) str;

    if(StrPro->ptr != NULL)
        StrPro->ptr = realloc(StrPro->ptr,(StrPro->len+strlen(addStr))*sizeof(char));

    else
        StrPro->ptr = malloc(strlen(addStr));

    memcpy(StrPro->ptr + strlen(StrPro->ptr),addStr,strlen(addStr) + 1);
    StrPro->len+=strlen(addStr);
}

void* subString(void* str,int i, int j)
{
    StringPro* StrPro =(StringPro*) str;

    if (j > StrPro->len)
        j = StrPro->len;

    if (i < 0) i = 0;

    char* pass = malloc(((j - i + 1) + 1)*sizeof(char));
    char* pass_ptr = StrPro->ptr;

    memcpy(pass,pass_ptr+i,(j - i + 1));

    StrPro = initialize(StrPro);
    StrPro->ptr = pass;
    StrPro->len = j - i + 1;
    StrPro->ProInfo->print(StrPro);
    StrPro->ProInfo->freedom(StrPro);
}

void* SplitIntoWords(void*str, char* delim, int * error)
{
    StringPro* StrPro = (StringPro*) str;
    if (delim == NULL)
    {
        *error = NULL_DELIM;
        return NULL;
    }

    if(!StrPro->len)
    {
        printf(
        " _______________________________________________________________________  \n"
        "|                                                                       | \n"
        "|                 You have nothing in the string!                       | \n"
        "|____  _________________________________________________________________| \n"
        "     |/                                                                   \n");

        return NULL ;
    }
    char *pass_ptr = (char*) StrPro->ptr;
    char* copy_ptr = malloc(sizeof(char) * (strlen(pass_ptr) + 1));
    memcpy(copy_ptr, pass_ptr, (strlen(pass_ptr) + 1) * sizeof(char));
    char* word = strtok(copy_ptr, delim );

    StringPro** Word = malloc(sizeof(StringPro*));

    int i = 0;
    while(word != NULL)
    {
        Word=realloc(Word, (i + 1) * sizeof(StringPro*));
        Word[i] = initialize(str);
        Word[i]->ptr = malloc((strlen(word) + 1) * sizeof(char));
        Word[i]->len = strlen(word);
        memcpy(Word[i]->ptr, word, strlen(word));
        Word[i]->ProInfo->print(Word[i]);
        word = strtok(NULL, delim);
        i++;
    }

}

void* print(void* str) {
    StringPro* StrPro = (StringPro*) str;
    if(!StrPro->ptr)
    {
        printf(
        " _______________________________________________________________________  \n"
        "|                                                                       | \n"
        "|                 You have nothing in the string!                       | \n"
        "|____  _________________________________________________________________| \n"
        "     |/                                                                   \n");

        return NULL;
    }
    printf("\n ->%s \n", StrPro->ptr);
}
void* freedom(void*str)
{
    StringPro* StrPro = (StringPro*) str;

    if(StrPro != NULL)
        free(StrPro->ptr);

    free(StrPro->ProInfo);
    free(StrPro);
}
