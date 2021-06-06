#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define DIM(a) (sizeof(a)/sizeof(*a))
//指针的应用
void searchkeytable(const char* table[],const int size,const char*key,int *pos)
{
	int rv = 0;
	int i = 0;
	if (table == NULL || key == NULL || pos == NULL)
	{
		rv = -1;
		printf("func searchkeytable:%d",rv);
		return rv;
	}
	for (i = 1; i < size+1; i++)
	{
		if (strcmp(key, table[i]) == 0)
		{
			*pos = i;
			return rv;
		}
	}
	if (i == size)
	{
		*pos = -1;
	}
	return rv;
}
void main70()
{
	int pos = 0;
	int a[10];
	int i = 0;
	char *keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};/*'\0' 0  NULL都可以作为字符串或数组的结束标识符（指针数组自我结束能力）*/
	for (i = 0; keyword[i] != NULL; i++)
	{
		printf("%s", keyword[i]);
	}
	searchkeytable(keyword,DIM(keyword),"static",&pos);
	printf("pos:%d\n",pos);
	system("pause");
	return;
}
