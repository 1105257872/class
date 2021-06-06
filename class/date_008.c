#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//�ṹ���׶���ָ�� 
typedef struct Teacher
{
	char name[64];
	char *aliasname;
	char **stuname;
	int age;
	int id;
}Teacher;
//��ӡ��ʦ������
void printfTeacher(Teacher *array, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("age:%d \n", array[i].age);
	}
}
//������ʦ�����䣬����ʦ����
void sortTeacher(Teacher *array,int num)
{
	int i, j;
	Teacher tmp;
	for (i=0;i<num;i++)
	{
		for (j=0;j<num;j++)
		{
			if (array[i].age > array[j].age)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}
//������ʦ�Ľṹ�壬�����ڴ�
Teacher * creatTeacher01(int num)
{
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}
//����ʦ�Ľṹ������ڴ�
Teacher * creatTeacher02(Teacher **Pt,int num)
{
	int i = 0,j=0;
	Teacher * tmp = NULL;//ͨ��tmp����ָ�� �����ڴ�
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
	{
		return -1;
	}

	//��ʼ���������
	memset(tmp,0,sizeof(Teacher)*num);

	for (i = 0; i < num; i++)
	{
		//malloc һ��ָ��
		tmp[i].aliasname = (char *)malloc(60);

		//����ָ��ĵ������ڴ�ģ��
			char **p = (char **)malloc(3 * sizeof(char *));//����ָ�루�����ά�ڴ棩
			for (j = 0; j < 3; j++)
			{
				p[j] = (char *)malloc(120);
			}
			tmp[i].stuname = p;//����ָ��
	}

	*Pt = tmp;//ָ�봫��������β�
	return 0;
}
//�ͷŽṹ���ڴ�ռ�
void FreeTeacher(Teacher *p,int num)
{
	int i = 0,j = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		//�ͷ�һ��ָ��
		if (p[i].aliasname != NULL)
		{
			free(p[i].aliasname);
		}
		//�ͷŶ���ָ��
		if (p[i].stuname != NULL)
		{
			char **myp = p[i].stuname;
			for (j = 0; j < 3; j++)
			{
				if (myp[j] != NULL)
				{
					free(myp[j]);
				}
			}
			free(myp);
			p[j].stuname = NULL;//����Ұָ��
		}
	}
	free(p);
}
void main80()
{
	int ret = 0;
	int i = 0,j = 0;
	int num = 3;
	Teacher *pArray = NULL;
	ret = creatTeacher02(&pArray,num);
	if (ret != 0)
	{
		printf("func creatTeacher02()er:%d");
		return;
	}

	for (i = 0; i < num; i++)
	{
		printf("\nplease enter age:");
		scanf("%d",&(pArray[i].age));
		//printf("\nplease enter name:");
		//scanf("%d", pArray[i].name);//��ָ����ָ���ڴ�ռ俽������
		printf("\nplease enter alias:");
		scanf("%d", pArray[i].aliasname);//��ָ����ָ���ڴ�ռ俽������
		for (j = 0; j < 3; j++)
		{
			printf("\nplease enter stuname:");
			scanf("%d", &(pArray[i].stuname[j]));
		}
	}
	//��ӡ���
	printfTeacher(pArray, num);
	//����
	sortTeacher(pArray,num);
	//��ӡ������
	printfTeacher(pArray, num);
	//
	FreeTeacher(pArray, num);
	printf("hello...\n");
	system("pause");
	return;
}
