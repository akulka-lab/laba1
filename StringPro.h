#include "StringProInfo.h"
#include "errors.h"

struct StringPro
{
    StringProInfo* ProInfo;
    int len;
    void* ptr;
} typedef StringPro;

StringPro* initialize();

char *myreadline(const char *prompt);
void* KeyboardInput(void*str, int *error);
void* concatenate(void*str,char * addStr);
void* subString(void*str,int i,int j);
void* SplitIntoWords (void*str, char* delim, int * error);
void* print(void*str);
void* freedom(void*str);
