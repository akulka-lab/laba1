#include "StringProInfo.h"
#include "errors.h"

typedef struct StringPro
{
    StringProInfo* ProInfo;
    void* ptr;
    int len;
    
} StringPro;

StringPro* initialize();

void* print(void*str);
char* my_readline(char* message);
void* my_memcpy(char* newstr, char* str, int len);
void* KeyboardInput(void*str, int *error);
void* concatenate(void*str,char * addStr);
void* subString(void*str,int i,int j);
void* SplitIntoWords (void*str, char* delim, int * error);
void* print(void*str);
void* freedom(void*str);
char permutation(int n, char* str, char* newstr);
