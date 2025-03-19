# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"
#define STUDENT_NUM 5 //学生总数


int main()
{
	struct Student students[STUDENT_NUM] =
	{
		{201701, "王大川", "男", 25, {89, 84, 84}},
		{201702, "张大江", "男", 23, {88, 95, 73}},
		{201703, "李大山", "男", 24, {75, 85, 95}},
	};

	printf("输入后%d个学生的信息（空格分隔，每行一人）：\n", STUDENT_NUM - 3);
	input(students, STUDENT_NUM);
	print_all(students, STUDENT_NUM);

	return 0;
}