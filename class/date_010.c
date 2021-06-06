#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "c:/test/test3.txt"
/*文件的基本操作
"r"	以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
"w"	以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
"a"	以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
"r+"以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
"w+"以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
"a+"以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
*/
//字符的写操作
int test_write_char()
{
	char *buf = "abcdefghij";
	int i = 0;

	FILE *fp = fopen(FILE_NAME, "w+");
	if (fp == NULL) {
		fprintf(stderr, "open %s error\n", FILE_NAME);
		return -1;
	}



	for (i = 0; i < (int)strlen(buf); i++) {
		if (fputc(buf[i], fp) == EOF) {
			fprintf(stderr, "fput %c error\n", buf[i]);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_read_char()
{
	FILE *fp = NULL;
	char buf[128] = { 0 };
	char ch = 0;
	int i = 0;

	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", FILE_NAME);
		return -1;
	}

	while (((ch = fgetc(fp)) != EOF)) {
		buf[i] = ch;
		i++;
	}

	printf("buf: %s\n", buf);

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_append_char()
{
	FILE *fp = NULL;
	char *buf = "123456";
	int i = 0;


	fp = fopen(FILE_NAME, "a+"); //如果没有文件 也会创建
	if (fp == NULL) {
		fprintf(stderr, "open %s  error\n", FILE_NAME);
		return -1;
	}

	int len = strlen(buf);

	for (i = 0; i < len; i++) {
		if (fputc(buf[i], fp) == EOF)
		{
			fprintf(stderr, "fputc %c error\n", buf[i]);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_write_line()
{
	FILE *fp = fopen(FILE_NAME, "w+");
	char *buf = "abcdefg\n";
	int line_num = 10; //10行
	int i = 0;

	if (fp == NULL) {
		printf("open errorn\n");
		return  -1;
	}

	for (i = 0; i < line_num; i++) {
		// 1 fputs 不会把字符串的'\0'写进去 
		// 2 虽然说fputs 是写一行 实际上s 是 string的意思， 不会在字符串的尾部加一个\n  (把一个字符串写进文件中，不包括\0)
		if (fputs(buf, fp) == EOF) {
			fprintf(stderr, "fputs %s error\n", buf);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_read_line()
{
	FILE *fp = NULL;
	char buf[1024] = { 0 };
	char *p = NULL;
	int i = 0;
	int len = 0;
	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		fprintf(stderr, "open %s error\n", FILE_NAME);
		return -1;
	}

	//一定要事先开辟号 buf 的空间
	while ((fgets(buf, 1024, fp) != NULL)) {
		//1 fgets 不是根据\0来从文件区分一行 而是 通过\n 并且会把\n读进来  //读一行到内存中 \n
		len = strlen(buf);
		buf[len - 1] = '\0';
		printf("第 %d行数据是:%s\n", i, buf);
		i++;
		memset(buf, 0, 1024);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

struct student
{
	int age;
	char name[64];
	int id;
};

struct teacher
{
	int age;
	int id;
	char *name;   //malloc  "zhang3"
	int name_len;
};

int test_bin_write()
{
	struct student s_array[3] = { 0 };
	int i = 0;
	int num = 3;
	FILE *fp = NULL;
	int write_ret = 0;

	for (i = 0; i < num; i++) {
		s_array[i].id = i;
		s_array[i].age = i + 20;
		sprintf(s_array[i].name, "张%d", i + 1);
	}


	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", FILE_NAME);
		return -1;
	}

	int a = 10;

	//fwrite(&a, sizeof(int), 1, fp);

	//write_ret = fwrite(&s_array[0], sizeof(struct student), 3, fp);
	//printf("write_ret = %d\n", write_ret);


	for (i = 0; i < num; i++) {
		write_ret = fwrite(&s_array[i], sizeof(struct student), 1, fp);
		if (write_ret < 0) {
			fprintf(stderr, "write error\n");
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_bin_read()
{
	FILE *fp = NULL;
	struct student *s_array = NULL;
	int num = 3;
	int i = 0;
	int read_ret = 0;

	s_array = (struct student *)malloc(sizeof(struct student) * num);
	if (s_array == NULL) {
		return -1;
	}
	memset(s_array, 0, sizeof(struct student) *num);

	fp = fopen(FILE_NAME, "rb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		return -1;
	}

	for (i = 0; i < num; i++) {
		read_ret = fread(&s_array[i], sizeof(struct student), 1, fp);
		if (read_ret < 0) {
			fprintf(stderr, "read err\n");
			break;
		}
	}

	for (i = 0; i < num; i++) {
		printf("age : %d, name :%s, id :%d\n", s_array[i].age, s_array[i].name, s_array[i].id);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int main(void)
{
	char buf[1024] = { 0 };
	int len = 0;

	//test_write_char();
	//test_read_char();
	//test_append_char();
	//test_write_line();
	//test_read_line();

	/*
	if (fgets(buf, 1024, stdin) != NULL) {
		len = strlen(buf);
		buf[len - 1] = '\0';
		printf("buf: %s\n", buf);
	}
	*/

	//test_bin_write();
	test_bin_read();



	return 0;
}

