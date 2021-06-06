#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//结构体套二级指针 
typedef struct Teacher
{
	char name[64];
	char *aliasname;
	char **stuname;
	int age;
	int id;
}Teacher;
//打印老师的年龄
void printfTeacher(Teacher *array, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("age:%d \n", array[i].age);
	}
}
//根据老师的年龄，给老师排序
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
//创建老师的结构体，分配内存
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
//给老师的结构体分配内存
Teacher * creatTeacher02(Teacher **Pt,int num)
{
	int i = 0,j=0;
	Teacher * tmp = NULL;//通过tmp辅助指针 申请内存
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);
	if (tmp == NULL)
	{
		return -1;
	}

	//初始化清空数据
	memset(tmp,0,sizeof(Teacher)*num);

	for (i = 0; i < num; i++)
	{
		//malloc 一级指针
		tmp[i].aliasname = (char *)malloc(60);

		//二级指针的第三种内存模型
			char **p = (char **)malloc(3 * sizeof(char *));//辅助指针（打造二维内存）
			for (j = 0; j < 3; j++)
			{
				p[j] = (char *)malloc(120);
			}
			tmp[i].stuname = p;//传递指针
	}

	*Pt = tmp;//指针传递输出给形参
	return 0;
}
//释放结构体内存空间
void FreeTeacher(Teacher *p,int num)
{
	int i = 0,j = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		//释放一级指针
		if (p[i].aliasname != NULL)
		{
			free(p[i].aliasname);
		}
		//释放二级指针
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
			p[j].stuname = NULL;//避免野指针
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
		//scanf("%d", pArray[i].name);//向指针所指的内存空间拷贝数据
		printf("\nplease enter alias:");
		scanf("%d", pArray[i].aliasname);//向指针所指的内存空间拷贝数据
		for (j = 0; j < 3; j++)
		{
			printf("\nplease enter stuname:");
			scanf("%d", &(pArray[i].stuname[j]));
		}
	}
	//打印结果
	printfTeacher(pArray, num);
	//排序
	sortTeacher(pArray,num);
	//打印排序结果
	printfTeacher(pArray, num);
	//
	FreeTeacher(pArray, num);
	printf("hello...\n");
	system("pause");
	return;
}
