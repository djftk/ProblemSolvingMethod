#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
	struct Student *next;
}Student;
int main() {
	Student *s1, *s2, *s3;
	s1 = (Student*)malloc(sizeof(Student));
	s2 = (Student*)malloc(sizeof(Student));
	s3 = (Student*)malloc(sizeof(Student));

	s1->tag = 101;
	s2->tag = 102;
	s3->tag = 103;

	s1->next = s2;
	s2->next = s3;
	s3->next = NULL;

	printf("%d\n", s1->tag);
	printf("%d\n", s1->next->tag);
	printf("%d\n", s1->next->next->tag);

}