#include "StringProInfo.h"
#include <stdlib.h>

StringProInfo* Create(void*(*KeyboardInput)(void *, int* ), void* (*concatenate)(void *, char * ), void* (*subString)(void*,int i, int j), void* (*SplitIntoWords)(void *, char*, int * ), void* (*print)(void*), void* (*freedom)(void*))
{
  StringProInfo * strInfo = (StringProInfo*) malloc(sizeof(StringProInfo));
  strInfo->KeyboardInput = KeyboardInput;
  strInfo->concatenate = concatenate;
  strInfo->subString = subString;
  strInfo->SplitIntoWords = SplitIntoWords;
  strInfo->print = print;
  strInfo->freedom = freedom;

  return strInfo;
}
