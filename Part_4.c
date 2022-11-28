#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
	struct Student *next;
}Student;
Student *head;