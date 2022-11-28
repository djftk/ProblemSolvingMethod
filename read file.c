#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
	int year, month, day;
	char name[20];
	char paid_fee[4];
	int age;
	char info[40];
	char job[20];
	struct Student *next;
}Student;

Student *h = NULL, *c = NULL;

void main() {
	h = NULL, c = NULL;
	FILE *fp = fopen("ex.txt", "r");
	Student s1, *node;
	while (fscanf(fp, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%[^/]", &s1.tag, s1.year, s1.month, s1.day, s1.paid_fee, s1.name, s1.age, s1.info, s1.job) != EOF) {
		node = (Student*)malloc(sizeof(Student));
		node->tag = s1.tag;
		node->year = s1.year;
		node->month = s1.month;
		node->day = s1.day;
		strcpy(node->paid_fee, s1.paid_fee);
		strcpy(node->name, s1.name);
		node->age = s1.age;
		strcpy(node->info, s1.info);
		strcpy(node->job, s1.job);
		node->next = NULL;
		if (h == NULL) {
			c = h = node;
		}
		else {
			c = c->next = node;
		}
	}
	while (c != NULL) {
		fprintf("%d %d-%d-%d %s %s %d %s %s\n", c->tag, c->year,c->month,c->day,c->paid_fee, c->name, c->age ,c->info, c->job);
		c = c->next;
	}
	fclose(fp);

}
