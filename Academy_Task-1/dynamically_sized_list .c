#include "dynamically_sized_list.h"

enum { value, next };

void StringListInit(char*** list, char* str, _Bool* memoryIsAllocated)
{
	if (*memoryIsAllocated == 1)
	{
		printf("\nError. Init has already done.\n");
		return;
	}

	*list = (char**)malloc(2 * sizeof(char*));
	size_t lengthOfString = strlen(str) + 1;
	*list[value] = (char*)malloc(sizeof(char) * lengthOfString);
	memcpy((*list)[value], str, lengthOfString);
	(*list)[next] = NULL;
}

void StringListAdd(char*** list, char* str)
{
	if (*list == NULL)
		return;

	char** present = *list;
	while (present[next] != NULL)
	{
		present = present[1];
	}

	char** new_chain = (char**)malloc(sizeof(char*) * 2);

	const size_t size = strlen(str) + 1;
	new_chain[value] = (char*)malloc(sizeof(char) * size);

	memcpy(new_chain[value], str, sizeof(char) * size);

	new_chain[next] = NULL;
	present[next] = new_chain;
	present = present[next];
}

void StringListDestroy(char*** list)
{
	if (!list)
	{
		return;
	}

	char** tmp = NULL;

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
		if (!strcmp(present[value], str))
		{
			if (prev)
			{
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

void StringListSort(char*** list) {

	char** str1 = NULL
		, ** str2 = NULL;
	str1 = *list;

	while (str1 != NULL)
	{
		str2 = str1[next];
		/* Compare the picked element with rest of the elements */
		while (str2 != NULL)
		{
			/* If duplicate then delete it */
			if (0 < strcmp(str1[value], str2[value]))
			{
				/* sequence of steps is important here */
				char** temp = str1[value];
				str1[value] = str2[value];
				str2[value] = temp;

			}
			else /* This is tricky */
			{
				str2 = str2[next];
			}
		}
		str1 = str1[next];
	}
}

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

void StringListReplaceInStrings(char*** list, char* before, char* after)
{

	char** curr = (*list);

	while (curr != NULL)
	{
		if (!strcmp(curr[value], before))
		{
			char* tmp = (char*)malloc(sizeof(char) * (strlen(after) + 1));
			strcpy(tmp, after);
			free(curr[value]);
			curr[value] = tmp;
		}
		curr = (char*)curr[next];
	}
}

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


int main()
{
	char** list = NULL;
	char* tmp1 = "String-5";
	char* tmp2 = "String-4";
	char* tmp3 = "String-3";
	char* tmp4 = "String-2";
	char* tmp5 = "String-2";
	_Bool move = 0;

	StringListInit(&list, tmp1, &move);
	StringListAdd(&list, tmp2);
	StringListAdd(&list, tmp3);
	StringListAdd(&list, tmp4);
	StringListAdd(&list, tmp5);
	PrintAllStrings(list);
	printf("\n");

	StringListRemoveDuplicates(&list);
	PrintAllStrings(list);
	printf("\n");

	StringListSort(&list);
	PrintAllStrings(list);
	printf("\n");

	StringListRemove(&list, tmp1);
	PrintAllStrings(list);
	printf("\n");

	StringListReplaceInStrings(&list, "S", "K");
	PrintAllStrings(list);
	printf("\n");

	StringListDestroy(&list);

	return 0;
}



