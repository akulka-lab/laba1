#include "errors.h"

typedef struct StringProInfo
{
  void* (*KeyboardInput)(void*, int*);
  void* (*concatenate)(void*,char *);
  void* (*subString)(void*,int i, int j);
  void* (*SplitIntoWords)(void*, char*, int *);
  void* (*print)(void*);
  void* (*freedom)(void*);
  char* (*my_readline)(char* message);
  void* (*my_memcpy)(char* newstr, char* str, int len);
}  StringProInfo;

StringProInfo* Create(void* (*KeyboardInput)(void *, int*), void* (*concatenate)(void *,char*), void* (*subString)(void*,int i, int j), void* (*SplitIntoWords)(void *, char*, int *), void* (*print)(void*), void* (*freedom)(void*));

