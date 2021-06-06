#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

char ** spitString3(const char *buf1, char c, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	char **myp = NULL;
	p = buf1;
	pTmp = buf1;
	
	//第一遍求出count
	do {
		//检索出目标值 后移 形成差值 挖字符串
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				//3重新让p和ptmp达到下一次检索的条件
				pTmp = p = p + 1;
			}
		}
		else break;
	} while (*p != '\0');
	*count = tmpcount;
	//根据多少行精确的分配内存
	myp = (char **)malloc(tmpcount * sizeof(char *));
	if (myp == NULL)
	{
		return NULL;
	}
	tmpcount = 0;
	//p 和 ptmp 初始化
	p = buf1;
	pTmp = buf1;
	do {
		//检索符合条件的初值 后移形成差值 挖字符串
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				myp[tmpcount] = (char *)malloc(len * sizeof(char));
				if (myp[tmpcount] == NULL)
				{
					return NULL;
				}
				strcpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p - pTmp] = '\0';//把第一行数据变成C风格字符串
				tmpcount++;
				//重新让p和ptmp达到下一次检索的条件
				pTmp = p = p + 1;

			}
		}
		else break;
	} while (*p != '\0');
	return myp;
}

void main30()
{
	int ret = 0, i = 0;
	char *p1 = "aaaaa,bbbbb,";
	char cTem = ',';
	int nCount;
	char **p = NULL;

	p = spitString3(p1, cTem, &nCount);
	if (p == NULL)
	{
		printf("fun spitString() err :%d \n", ret);
		return ret;
	}
	for (i = 0; i < nCount; i++)
	{
		printf("%s \n", p[i]);
	}

	for (i = 0; i < nCount; i++)
	{
		free(p[i]);
	}
	free(p);
	system("pause");
	return;
}
