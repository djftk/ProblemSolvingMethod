#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
	char name[20];
	char paid_fee[4];
	int age;
	struct Student *next;
}Student;

Student *h = NULL, *c = NULL;

void main() {
	h = NULL, c = NULL;
	FILE *fp = fopen("ex.txt", "r");
	Student s1, *node;
	while (fscanf(fp, "%d/%[^/]/%[^/]/%d\n", &s1.tag, s1.paid_fee, s1.name, &s1.age) != EOF) {
		node = (Student*)malloc(sizeof(Student));
		node->tag = s1.tag;
		strcpy(node->paid_fee, s1.paid_fee);
		strcpy(node->name, s1.name);
		node->age = s1.age;
		node->next = NULL;
		if (h == NULL) {
			c = h = node;
		}
		else {
			c = c->next = node;
		}
	}
	fclose(fp);
	for (c = h; c; c = c->next)
		printf("%d %s %s %d\n", c->tag, c->paid_fee, c->name, c->age);


}