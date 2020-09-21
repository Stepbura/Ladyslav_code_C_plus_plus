#include "dynamically_sized_list.h"



//Function for initializing list
void StringListInit(char*** list, char* str, _Bool* memoryIsAllocated)
{
	if (*memoryIsAllocated == 1)
	{
		printf("\nError. Init has already done.\n");
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
	if (str == NULL)
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
	char** present = (*list);

	while (present != NULL)
	{
		if (!strcmp(present[value], before))
		{
			char* tmp = (char*)malloc(sizeof(char) * (strlen(after) + 1));
			strcpy(tmp, after);
			free(present[value]);
			present[value] = tmp;
		}
		present = (char*)present[next];
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

	char** curr = (*list);
	int position = 0;

	while (curr != NULL)
	{
		if (!strcmp(curr[value], str))
		{
			return position;
		}
		position++;
		curr = (char*)curr[next];
	}
	return -1;
}



