#pragma once
void line(char c, int n);
void input(struct Student* stud, int n);
void print_all(struct Student* studs, int n);

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