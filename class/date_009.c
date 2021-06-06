#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//定义一个 文件指针
	FILE *fp = NULL;

	//fp = fopen("c:\\test\\test1.txt", "w"); // \ 只对windows可用 
	fp = fopen("c:/test/test1.txt", "w");//   ‘/’  对windosw和linux 都可用
	if (fp == NULL) {
		fprintf(stderr, "open file error\n");
		return 0;
	}
	else {
		printf("open file succ!\n");
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen("c:/test/test2.txt", "r+");
	if (fp == NULL) {
		fprintf(stderr, "open file test2.txt error\n");
		return 0;
	}
	else {
		printf("open text2 succ!\n");
	}
	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}