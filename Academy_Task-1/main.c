
#include "dynamically_sized_list.h"


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

	//StringListRemoveDuplicates(&list);
	PrintAllStrings(list);
	printf("\n");

	StringListSort(&list);
	PrintAllStrings(list);
	printf("\n");

	//StringListRemove(&list, tmp1);
	PrintAllStrings(list);
	printf("\n");

	StringListReplaceInStrings(&list, "String-2", "");
	PrintAllStrings(list);
    printf("\n");





	StringListDestroy(&list);

	return 0;
}

