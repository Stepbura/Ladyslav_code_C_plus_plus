#include "dynamically_sized_list.h"



//Function for initializing list
void StringListInit(char*** list, char* str, _Bool* memoryIsAllocated)
{
	if (*memoryIsAllocated == 1)
	{
		printf("\n Error.Init has already done.\n");
		return;
	}

	//Allocating of memory for first element(head)

	*list = (char**)malloc(2 * sizeof(char*));
	size_t lengthOfString = strlen(str) + 1;
	*list[value] = (char*)malloc(sizeof(char) * lengthOfString);
	memcpy((*list)[value], str, lengthOfString);
	(*list)[next] = NULL;
	(*memoryIsAllocated) = 1;
}

//Adding new element to the end of list
void StringListAdd(char*** list, char* str)
{
	if (*list == NULL)
		return;

	char** present = *list;
	while (present[next] != NULL)
	{
		present = present[1];
	}

	//Creating an new element and uniteing last element in list wiht new element

	char** new_chain = (char**)malloc(sizeof(char*) * 2);

	const size_t size = strlen(str) + 1;
	new_chain[value] = (char*)malloc(sizeof(char) * size);

	memcpy(new_chain[value], str, sizeof(char) * size);

	new_chain[next] = NULL;
	present[next] = new_chain;
	present = present[next];
}

//Destroying of list
void StringListDestroy(char*** list)
{
	if (!list)
	{
		return;
	}

	char** tmp = NULL;

	//Deleting elements from the beginning 

	while ((*list)[next])
	{
		tmp = (*list)[next];
		free((*list)[value]);
		free(*list);
		(*list) = tmp;
	}
	free((*list)[value]);
	free(*list);
	(*list) = NULL;
	puts("List was destroyed\n");
}

//Showing all strings from list
void PrintAllStrings(const char** list)
{
	if (!list)
		return;
	char** tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp[value]);
		tmp = tmp[next];
	}
}

//Deleting of some element in list
void StringListRemove(char*** list, char* str)
{
	if (list == NULL)
		return;
	if (str == NULL || !strcmp(str, ""))
		return;

	char** prev = NULL;
	char** present = *list;

	while (present != NULL)
	{
		//Looking for element that we want to find and delete 
		if (!strcmp(present[value], str))
		{
			if (prev)
			{
				//Deleting of data and keeping pointer between elements 
				prev[next] = present[next];
				free(present[value]);
				free(present);
				return;
			}
			else
			{
				(*list) = present[next];
				return;
			}
		}

		prev = present;
		present = present[next];
	}
}

//Sorting of elements in list
void StringListSort(char*** list) {

	char** first_str = NULL;
	char** second_str = NULL;

	first_str = *list;

	while (first_str != NULL)
	{
		second_str = first_str[next];
		//Whats required, is compare this element with others
		while (second_str != NULL)
		{
			if (0 < strcmp(first_str[value], second_str[value]))
			{
				char** temp = first_str[value];
				first_str[value] = second_str[value];
				second_str[value] = temp;

			}
			else 
			{
				second_str = second_str[next];
			}
		}
		first_str = first_str[next];
	}
}

//Removes duplicate entries from the list
void StringListRemoveDuplicates(char*** list)
{
	if (!list)
		return;
	char** present = (*list);
	char** duplicate = (*list)[next];
	char** prev = NULL;

	while (present != NULL)
	{
		duplicate = present[next];
		while (duplicate != NULL)
		{

			if (!strcmp(present[value], duplicate[value]))
			{

				prev[next] = duplicate[next];
				free(duplicate[value]);
				free(duplicate);
				duplicate = prev[next];
				if (!duplicate)
				{
					break;
				}
			}

			prev = duplicate;
			duplicate = duplicate[next];
		}
		prev = present[next];
		present = present[next];
	}

}

//Replaces every occurrence of the before, in each of the string lists's strings, with after
void StringListReplaceInStrings(char*** list, char* before, char* after)
{

	if (before == NULL || !strcmp(before,""))
		return;

	char** curr = (*list);

	while (curr != NULL)
	{
		char* tmp = strstr(curr[value], before);

		if (tmp != NULL)
		{
			size_t newStrLen = (strlen(curr[value]) - strlen(before) + strlen(after) + 1);
			
			if (newStrLen != strlen(curr[value]) + 1)
			{
				char* newStr = (char*)malloc(sizeof(char) * newStrLen);

				size_t numOfSymbolsBefore = 0;

				for (char* i = curr[value]; i != tmp; ++i, ++numOfSymbolsBefore);

				if (numOfSymbolsBefore != 0)
					strcpy_s(newStr, newStrLen, curr[value], numOfSymbolsBefore);

				strcpy_s(&newStr[numOfSymbolsBefore], newStrLen - numOfSymbolsBefore, after, strlen(after));


				char* lastPartOfStr = curr[value] + numOfSymbolsBefore + strlen(before);
				size_t sizeOfLastPartOfStr = strlen(lastPartOfStr);

				strcpy_s(&newStr[numOfSymbolsBefore + strlen(after)], newStrLen - (numOfSymbolsBefore + strlen(after)), lastPartOfStr, sizeOfLastPartOfStr);
				int lastIndex = numOfSymbolsBefore + strlen(after) + sizeOfLastPartOfStr;
				newStr[lastIndex] = '\0';

				free(curr[value]);
				curr[value] = newStr;
			}
			else
			{
				for (int i = 0; i < strlen(after); ++i)
					tmp[i] = after[i];
			}
		}

		curr = curr[next];
	}

}

//Inserts value at the end of the list
int StringListSize(char** list)
{
	int sizeOfList = 0;
	while (list != NULL)
	{
		list = list[next];
		sizeOfList++;
	}
	return sizeOfList;
}

//Returns the index position of the first occurrence of str in the list
int StringListIndexOf(char*** list, char* str) {
	
	if (*list == NULL)
		return;

	char** curr = (*list);
	int position = 0;

	while (curr != NULL)
	{
		if (!strcmp(curr[value], str))
		{
			return position;
		}
		position++;
		curr = curr[next];
	}
	return -1;
}



// What is _Bool type?
// Line 25: void StringListAdd(char*** list, char* str). It needs to verify if str == NULL, It does not need to add an epmty string.
// Line 47: The 'present' variable is assigned but is not used. I am not sure if list contains just added string.
// Line 172: Dereferencing of the null pointer 'prev' might take place.
// Line 198: Line 130: Line: 248: First verify input parameter 'list' and then assign it.
