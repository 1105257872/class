#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//多维数组的本质  ：步长
void writebuf(int (*buf)[5])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			buf[i][j] = i*j;
		}
	}
}
void readbuf(int (*buf)[5])
{
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", buf[i][j]);
		}
		printf("\n");
	}
}
/*二维数组当一维数组打印，证明是线性存储*/
void printbuf(int *buf,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", buf[i]);
	}
}
void main60()
{
	int a[3][5];
	/*内存模型*
	 0 1 2 3 4
	0▢▢▢▢▢
	1▢▢▢▢▢
	2▢▢▢▢▢
	*内存模型*/
	//a			 代表整个二维数组的地址（整个第0行的地址）,即:a[0]或a[0][0]
	//a+i		 代表整个第i行的地址,即:&a[i]
	//*(a+i)	 代表第i行的首元素的地址,即:a[i]
	//*(a+i)+j	 代表第i行的第j个元素的地址,即:&a[i][j]
	//*(*(a+i)+j)代表第i行，第j个元素的值，即:a[i][j]
	writebuf(a);
	readbuf(a);
	printbuf((int *)a,15);
	printf("hello...\n");
	system("pause");
	return;
}
