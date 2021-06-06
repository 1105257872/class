#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//数组
void main50()
{
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//编译器编译时确定的值
	memset(c, 0, sizeof(c));//手动重置内存块
	//一维数组的规定：
	//c是数组首元素的地址
	//&c 代表整个数组的地址
	printf("hello...\n");
	system("pause");
	return;
}
//怎样表达数组这个数据数据类型
//数组的数据类型 应该由元素的类型和数组的大小决定的
//类型的本质：固定大小内存块的别名
//定义数组类型
void main51()
{
	int i;
	typedef int(MyArrayType)[5];//定义了一个数据类型  数组数据类型
	MyArrayType myarray;//相当于int nyarray[5];
	for (i = 0; i < 5; i++)
	{
		myarray[i] = i + 1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d", myarray[i]);
	}
	system("pause");
	return;
}
//定义数组指针变量的第二种方法

void main52()
{
	int i;
	typedef int(*MyArrayType)[5];//定义了一个数据类型  数组数据类型
	MyArrayType myarray;//相当于int nyarray[5];
	int c[5];
	myarray = &c;
	for (i = 0; i < 5; i++)
	{
		(*myarray)[i] = i + 1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d", (*myarray)[i]);
	}
	system("pause");
	return;
}
//定义数组指针变量 的第三种方法
void main53()
{
	int i;
	int(*MyArrayType)[5];//定义了一个数据类型  数组数据类型
	int c[5];
	MyArrayType = &c;
	for (i = 0; i < 5; i++)
	{
		(*MyArrayType)[i] = i + 1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d", (*MyArrayType)[i]);
	}
	system("pause");
	return;
}