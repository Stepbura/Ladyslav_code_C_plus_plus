#ifndef dynamically_sized_list
#define dynamically_sized_list

#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

enum { value, next };

void StringListInit(char*** list, char* str, _Bool* memoryIsAllocated);
void StringListAdd(char*** list, char* str);
void StringListDestroy(char*** list);
void PrintAllStrings(const char** list);
void StringListRemove(char*** list, char* str);
void StringListSort(char*** list);
void StringListRemoveDuplicates(char*** list);
void StringListReplaceInStrings(char*** list, char* before, char* after);
int StringListSize(char** list);
int StringListIndexOf(char*** list, char* str);

#endif
