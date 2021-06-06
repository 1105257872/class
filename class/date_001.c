#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

void main10()
{
	char *p1 = NULL;
	strcpy(p1,"abc");
	printf("hello...\n");
	system("pause");
	return;
}
void main11()
{
	char *p1 = 0x77;
	strcpy(p1, "abc");
	printf("hello...\n");
	system("pause");
	return;
}
void main12()
{
	int i,j=0;
	char buf[10] = {"9876543210"};
	char*p1 = NULL,*p2 = NULL;

	for (i = 0; i < 10; i++) {
		p1 = &buf[i];
		printf("%c\n", *p1);
	}
	p2 = (char *)malloc(10);
	strcpy(p2,"0123456789");
	for (i = 0; i < 10; i++) {
		p1 = p2 + i;
		printf("%c\n",*p1);
	}
	printf("hello...\n");
	system("pause");
	return;
}
void main13()
{
	char from[128] = {0}, to[128] = {"9876543210"};
	char *p1,*p2;
	p1 = from;
	p2 = to;
	printf("to:%s\n", p2);
	strcpy(from,"0123456789");
	/*while (*p1 != NULL)
	{
		*p2 = *p1;
		p2++;
		p1++;
	}*/
	p2 = p1;
	printf("to:%s\n",p2);
	printf("hello...\n"); 
	system("pause");
	return;
}
//全局区代码测试
char * getstring1()
{
	char *p1 = "12345";
	return p1;
}

char * getstring2()
{
	char *p2 = "abcde";
	return p2;
}


void main14()
{
	//指针指向谁就把谁的地址赋给指针变量。
	char *p1 = getstring1();
	char *p2 = getstring2();
	char a;
	a = 'A';

	//指针变量和它所执行的内存空间变量是两个不同的概念
	strcmp(p1, p2);
	printf("p1:%s\n",p1);
	printf("p1:%c  %c  %c  %c  %c\n", *p1, *p1+1, *p1+2, *p1+3, *p1 + 4);
	printf("p2:%s\n", p2);
	printf("p2:%c  %c  %c  %c  %c\n", *p2, *p2+1, *p2+2, *p2+3, *p2 + 4);
	printf("a:%c\n", a);
	system("pause");
	return;
}
void main15()
{
	int i = 0;
	char *p = NULL;
	char buf[7] = "abcdefg";
	for (i = 0; i < strlen(buf); i++)
	{
		printf("%c \n",buf[i]);
	}
	p = buf;
	for (i = 0; i < strlen(buf); i++)
	{
		printf("%c \n", *p);
		p++;
	}
	for (i = 0; i < strlen(buf); i++)
	{
		printf("%c \n", *(buf + i));
	}
	printf("hello...\n");
	system("pause");
	return;
}
/*字符串复制*/
/*普通方法*/
void str_cpy0(char *from, char *to)
{
	int i;
	for (i = 0; *(from + i) != '\0'; i++)
	{
		*(to + i) = *(from + i);
	}
	to[i] = '\0';
	return;
}
void str_cpy1(char *from,char *to)
{
	while(*from!= '\0')
	{
		*to++ = *from++;
	}
	*to = '\0';
	return;
}
void str_cpy2(char *from, char *to)
{
	while ((*to = *from) != '\0')
	{
		to++;
		from++;
	}
}
void str_cpy3(char *from, char *to)
{
	while ((*to++ = *from++) != '\0');//妙
}
void str_cpy4(char *from, char *to)
{
	while (*to++ = *from++);//妙极了
}
void main16()
{
	/*函数调用*/
	char *from = "I am a student";
	char to[14] = "i am a teacher";
	str_cpy4(from, to);
	printf("to=%s \n",to);
	system("pause");
	return;
}
/**********************************************/
int getmem08(char **myp1,char *mylen1,char **myp2,char *mylen2)
{
	char *tmp1 = NULL, *tmp2 = NULL;
	tmp1 = (char *)malloc(100);
	if (tmp1 == NULL)
	{
		return -1;
	}
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);
	tmp2 = (char *)malloc(100);
	if (tmp2 == NULL)
	{
		return -2;
	}
	strcpy(tmp2, "1234567");
	*mylen2 = strlen(tmp2);
	return 0;
}
int getmem08_free(char **myp1)
{
	if (myp1 == NULL)
	{
		return -1;
	}
	free(*myp1);
	*myp1 = NULL; 
	return 0;
}
void main17()
{
	int i,num;
	char *array[] = { "a","bb","ccc","dddd","eeeee" };
	num = sizeof(array)/sizeof(array[0]);//5
	printf("array=%d \n", sizeof(array));//20
	printf("array[]=%d \n", sizeof(array[0]));//4
	for (i = 0; i < num; i++)
	{
		printf("%s \n",*(array+i));
	}
	printf("hello...\n");
	system("pause");
	return;
}

/******************************************/
void getmem09(char ***p3, int num)
{
	int i = 0;
	char **tmp = NULL;
	if (p3 == NULL)
	{
		return -1;
	}
	tmp = (char **)malloc(4*num);
	if (tmp == NULL)
	{
		return NULL;
	}
	for (i = 0; i < num; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char));
		sprintf(tmp[i], "%d", i);
	}
	*p3 = tmp;
	return 0;
}

void getmem09_free(char ***p3,int num)
{
	int i = 0;
	char **tmp = NULL;
	if (p3 == NULL)
	{
		return;
	}
	tmp = *p3;
	for (i = 0; i < num; i++)
	{
		free(tmp[i]);
	}
	*p3 = NULL;
}
void main18()
{
	int i = 0, j = 0;
	char **p2 = NULL;
	int num = 5;
	char *tmp = NULL;
	char tmpbuf[100];
	getmem09(&p2, num);
	for (i = 0; i < num; i++)
	{
		printf("%s \n", *p2[i]);
	}
	getmem09_free(&p2, num);
	system("pause");
}

void change10_mem(int (*buf)[5])
{
	buf[0][0] = 0;
}
void main19()
{
	int buf[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	printf("before = %d \n", buf[0][0]);
	//buf是数组首元素的地址
	//&buf 代表整个数组的地址
	change10_mem(buf);
	printf("later = %d \n", buf[0][0]);
	printf("hello...\n");
	system("pause");
	return;
}




