# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct grades
{
	int Math;
	int Chinese;
	int English;
};

struct Student
{
	int StudentID;
	char name[15];
	char gender[10];
	int age;
	struct grades grade;
};

void line(char c, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}


void input(struct Student* stud, int n)  //n是输入的学生数
{
	int i = 0;
	int count = 0;
	int judge = 0;
	printf("请输入学生的学号、姓名、性别、年龄、数学成绩、语文成绩、英语成绩：\n");
	for (i = 3; i < n; i++)
	{
		scanf("%d %s %s %d %d %d %d", &stud[i].StudentID, stud[i].name, stud[i].gender, &stud[i].age,
			&stud[i].grade.Math, &stud[i].grade.Chinese, &stud[i].grade.English);
		printf("已成功录入！\n");
	}

}

void calculate_stu_grade(struct Student* studs, int* total, float* average)
{
	*total = studs->grade.Math + studs->grade.Chinese + studs->grade.English;
	*average = *total / 3.0;
}


void print(struct Student* stud)
{
	//("-学号-  --姓名--  性别  年龄  数学  语文  英语  -总分-  -均分-");
	int total = 0;
	float average = 0.0;
	calculate_stu_grade(stud, &total, &average);
	/*printf("%d  %s     %s   %d     %d    %d    %d     %d     %.2f",
		stud->StudentID, stud->name, stud->gender, stud->age,
		stud->grade.Math, stud->grade.Chinese, stud->grade.English,
		total, average);*/
	printf("%-8d%-12s%-8s%-6d%6d%6d%6d%8d%9.2f",
		stud->StudentID,
		stud->name,
		stud->gender,
		stud->age,
		stud->grade.Math,
		stud->grade.Chinese,
		stud->grade.English,
		total,
		average);

}


void print_all(struct Student* studs, int n)
{
	printf("                       学生成绩总表                        \n");
	line('=', 79);
	//printf("-学号-  --姓名--  性别  年龄  数学  语文  英语   -总分-   -均分-");
	printf("%-8s%-12s%-8s%-6s%6s%6s%6s%8s%9s",
		"学号", "姓名", "性别", "年龄",
		"数学", "语文", "英语",
		"总分", "均分");
	printf("\n");
	line('-', 79);

	int i = 0;
	float Math_average = 0;
	float Chinese_average = 0;
	float English_average = 0;
	int Math_total = 0;
	int Chinese_total = 0;
	int English_total = 0;
	int total = 0;
	int class_total = 0;
	float class_total_average = 0;
	float average = 0;
	float class_average = 0;

	//单科总分
	for (i = 0; i < n; i++)
	{
		Math_total += studs->grade.Math;
		Chinese_total += studs->grade.Chinese;
		English_total += studs->grade.English;
		studs++;
	}

	Math_average = (float)Math_total / n;
	Chinese_average = (float)Chinese_total / n;
	English_average = (float)English_total / n;
	for (i = 0; i < n; i++)
		studs--;

	//班级总分
	for (i = 0; i < n; i++)
	{
		calculate_stu_grade(studs, &total, &average);
		class_total += total;
		class_average += average;
		studs++;
	}

	class_total_average = (float)class_total / n;

	for (i = 0; i < n; i++)
		studs--;
	for (i = 0; i < n; i++)
	{
		print(studs);
		printf("\n");
		studs++;
	}

	line('-', 79);

	/*printf("班级平均分                   %-4.2f  %-4.2f  %-4.2f  %-4.2f  %2.2f",
		Math_average, Chinese_average, English_average, class_total_average, class_average);*/

	printf("%-34s%6.2f%6.2f%6.2f%8.2f%9.2f",  // 前34字符用于文本对齐
		"班级平均分",
		Math_average,
		Chinese_average,
		English_average,
		class_total_average,
		class_average);
}