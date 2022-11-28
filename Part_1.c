#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
}Student;
int main() {
	Student s1;
	s1.tag = 101;
	printf("RollNo = %d\n", s1.tag);

	Student *s2;
	s2 = (Student*)malloc(sizeof(Student));
	s2->tag = 102;
	printf("RollNo = %d", s2->tag);
}