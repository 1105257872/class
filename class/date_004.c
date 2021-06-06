#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//�ͷ��ڴ�1
void Free_mem1(char **myp,int count)
{
	int i = 0;
	if (myp == NULL)
	{
		return;
	}
	for (i = 0; i < count; i++)
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
		}
	}
	if (myp != NULL)
	{
		free(myp);
	}
}
//�ͷ��ڴ�2
void Free_mem2(char ***p, int count)
{
	int i = 0;
	char **myp = NULL;
	if (p == NULL)
	{
		return;
	}
	myp = *p;
	if (myp == NULL)
	{
		return;
	}

	for (i = 0; i < count; i++)
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
		}
	}
	if (myp != NULL)
	{
		free(myp);
	}
	*p = NULL;
}

int spitString4(const char *buf1, char c, char ***myp3, int *count)
{
	int ret = 0;
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	char **myp = NULL;
	p = buf1;
	pTmp = buf1;

	//��һ�����count
	do {
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				tmpcount++;
				pTmp = p = p + 1;

			}
		}
		else break;
	} while (*p != '\0');
	*count = tmpcount;
	//���ݶ����о�ȷ�ķ����ڴ�
	myp = (char **)malloc(tmpcount * sizeof(char *));
	if (myp == NULL)
	{
		ret = -1;
		printf("func spitString4() err:%d", ret);
		goto END;
	}
	memset(myp, 0, tmpcount * sizeof(char *));
	tmpcount = 0;
	p = buf1;
	pTmp = buf1;
	do {
		//����Ŀ��ֵ ����Ŀ��ĵ�ַ
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - pTmp > 0)
			{
				int len = p - pTmp + 1;
				myp[tmpcount] = (char *)malloc(len * sizeof(char));
				if (myp[tmpcount] == NULL)
				{
					ret = -2;
					printf("func spitString4() err:%d", ret);
					goto END;
				}
				strcpy(myp[tmpcount], pTmp, p - pTmp);
				myp[tmpcount][p - pTmp] = '\0';
				tmpcount++;
				pTmp = p = p + 1;

			}
		}
		else break;
	} while (*p != '\0');
END:
	if (ret != 0)//ʧ��
	{
		/*Free_mem1(myp,*count);
		myp = NULL;*/
		Free_mem2(&myp,*count);
	}
	else
	{
		*myp3 = myp;//�ɹ�
	}
	return ret;
}
//�༶ָ�� ����Ұָ��
void main40()
{
	int ret = 0, i = 0;
	char *p1 = "aaaaa,bbbbb,";
	char cTem = ',';
	int nCount;
	char **p = NULL;

	ret = spitString4(p1, cTem, &p, &nCount);
	if (ret != NULL)
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
