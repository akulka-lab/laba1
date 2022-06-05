struct StringProInfo
{
  void* (*KeyboardInput)(void*, int*);
  void* (*concatenate)(void*,char *);
  void* (*subString)(void*,int i, int j);
  void* (*SplitIntoWords)(void*, char*, int *);
  void* (*print)(void*);
  void* (*freedom)(void*);
} typedef StringProInfo;

StringProInfo* Create(void* (*KeyboardInput)(void *, int*), void* (*concatenate)(void *,char*), void* (*subString)(void*,int i, int j), void* (*SplitIntoWords)(void *, char*, int *), void* (*print)(void*), void* (*freedom)(void*));

