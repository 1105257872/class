#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
//����
void main50()
{
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//����������ʱȷ����ֵ
	memset(c, 0, sizeof(c));//�ֶ������ڴ��
	//һά����Ĺ涨��
	//c��������Ԫ�صĵ�ַ
	//&c ������������ĵ�ַ
	printf("hello...\n");
	system("pause");
	return;
}
//��������������������������
//������������� Ӧ����Ԫ�ص����ͺ�����Ĵ�С������
//���͵ı��ʣ��̶���С�ڴ��ı���
//������������
void main51()
{
	int i;
	typedef int(MyArrayType)[5];//������һ����������  ������������
	MyArrayType myarray;//�൱��int nyarray[5];
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
//��������ָ������ĵڶ��ַ���

void main52()
{
	int i;
	typedef int(*MyArrayType)[5];//������һ����������  ������������
	MyArrayType myarray;//�൱��int nyarray[5];
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
//��������ָ����� �ĵ����ַ���
void main53()
{
	int i;
	int(*MyArrayType)[5];//������һ����������  ������������
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