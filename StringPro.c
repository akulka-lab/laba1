#include"StringPro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char my_readline(char* message)
{
    printf("%s", message);
    char buffer[81] = { 0 };
    char* result = NULL;
    int len = 0, n = 0;

    do
    {
        n = scanf("%80[^\n]", buffer);

        if (n > 0)
        {
            int buffer_len = my_strlen(buffer);
            int str_len = len + buffer_len;
            result = realloc(result, str_len + 1);
            my_memcpy(result + len, buffer, buffer_len);
            len = str_len;
        }
        else if (n < 0)
        {
            if (!result)
                return NULL;
        }
        else
        {
            scanf("%*c");
        }
    }while (n > 0);

    if (len > 0) {
        result[len] = '\0';
    }
    else
        result = calloc(1, sizeof(char));

    return result;
}


void my_memcpy(char* newstr, char* str, int len)
{
    char* s1 = newstr;
    char* s2 = str;

    for (int i = 0; i < len; i++)
    {
        *(s1++) = *(s2++);
    }
}


StringPro* initialize()
{
    StringPro* StrPro = malloc(sizeof(StringPro*));
    StrPro->ProInfo = Create(&KeyboardInput,&concatenate,&subString,&SplitIntoWords,&print,&freedom);
    StrPro->len = 0;
    StrPro->ptr = NULL;
}

void enteer()
{
    printf(
        " _______________________________________________________________________  \n"
        "|                                                                       | \n"
        "|                          Enter string:                                | \n"
        "|____  _________________________________________________________________| \n"
        "     |/                                                                   \n");
}

void* KeyboardInput(void* str, int * error)
{
    StringPro* StrPro = (StringPro*) str;
    
    enteer();
    char keyBoardInputStr[100] = {0};
    scanf("%*c");
    scanf("%[^\n]",keyBoardInputStr);
    m = scanf("%d", &n);
    
    if (m == 1)
    {
        scanf("%*c");
    }

    char * keyBoardInputPtr;
    keyBoardInputPtr = malloc(sizeof(char)*strlen(keyBoardInputStr));
    my_memcpy(keyBoardInputPtr, keyBoardInputStr, strlen(keyBoardInputStr)*sizeof(char));
    StrPro->ptr = keyBoardInputPtr;
    StrPro->len = strlen(keyBoardInputPtr);
}

void* concatenate(void* str,char * addStr)
{
    StringPro* StrPro = (StringPro*) str;
    StrPro->ptr = malloc(strlen(addStr));

    my_memcpy(StrPro->ptr + strlen(StrPro->ptr),addStr,strlen(addStr) + 1);
    StrPro->len+=strlen(addStr);
}

void* subString(void* str,int i, int j)
{
    char* pass = malloc(((j - i + 1) + 1)*sizeof(char));
    char* pass_ptr = StrPro->ptr;
    
    StringPro* StrPro =(StringPro*) str;

    if (j > StrPro->len)
        j = StrPro->len;

    if (i < 0) i = 0;

    my_memcpy(pass,pass_ptr+i,(j - i + 1));

    StrPro = initialize(StrPro);
    StrPro->ptr = pass;
    StrPro->len = j - i + 1;
    StrPro->ProInfo->print(StrPro);
    StrPro->ProInfo->freedom(StrPro);
}

void* SplitIntoWords(void*str, char* delim, int * error)
{
    StringPro* StrPro = (StringPro*) str;
    int i = 0;
 
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
    char* word;
    char *pass_ptr;
    char* copy_ptr;
    pass_ptr = (char*) StrPro->ptr;
    copy_ptr = malloc(sizeof(char) * (strlen(pass_ptr) + 1));
    my_memcpy(copy_ptr, pass_ptr, (strlen(pass_ptr) + 1) * sizeof(char));
    word = strtok(copy_ptr, delim );

    StringPro** Word = malloc(sizeof(StringPro*));

    while(word != NULL)
    {
        Word = realloc(Word, (i + 1) * sizeof(StringPro*));
        Word[i] = initialize(str);
        Word[i]->ptr = malloc((strlen(word) + 1) * sizeof(char));
        Word[i]->len = strlen(word);

        my_memcpy(Word[i]->ptr, word, strlen(word));
        Word[i]->ProInfo->print(Word[i]); i++;
        word = strtok(NULL, delim);
    }

}

char permutation(int n, char* str, char* newstr)
{
    int dlina = 0, flag = 0;
    for (int i = 0; i < len; i++)
    {
        dlina++;
        dlina = 0;
    }
    
    my_memcpy(newstr, str, len);
    newstr[len] = '\0';
}

void* freedom( void*str )
{
    StringPro* an = (StringPro*) str;
    
    free(an->ptr);
    free(an->ProInfo);
    free(an);
}
