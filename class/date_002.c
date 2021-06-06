#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int spitString2(const char *buf1, char c, char **myp, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	p = buf1;
	pTmp = buf1;
	do {
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				strcpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p - pTmp] = '\0';
				tmpcount++;
				pTmp = p = p + 1;

			}
		}
		else break;
	} while (*p != '\0');
	*count = tmpcount;
	return 0;
}

void main20()
{
	int ret = 0, i = 0;
	char *p1 = "aaaaa,bbbbb,ccccc,ddddd,eeeee";
	char cTem = ',';
	int nCount;
	char **p = NULL;
	p = (char **)malloc(10 * sizeof(char *));
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < 10; i++)
	{
		p[i] = (char*)malloc(30 * sizeof(char));
	}
	ret = spitString2(p1, cTem, p, &nCount);
	if (ret != NULL)
	{
		printf("fun spitString() err :%d \n", ret);
		return ret;
	}
	for (i = 0; i < nCount; i++)
	{
		printf("%s \n", p[i]);
	}

	for (i = 0; i < 10; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return;
}
