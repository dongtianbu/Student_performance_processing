# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"
#define STUDENT_NUM 5 //ѧ������


int main()
{
	struct Student students[STUDENT_NUM] =
	{
		{201701, "����", "��", 25, {89, 84, 84}},
		{201702, "�Ŵ�", "��", 23, {88, 95, 73}},
		{201703, "���ɽ", "��", 24, {75, 85, 95}},
	};

	printf("�����%d��ѧ������Ϣ���ո�ָ���ÿ��һ�ˣ���\n", STUDENT_NUM - 3);
	input(students, STUDENT_NUM);
	print_all(students, STUDENT_NUM);

	return 0;
}