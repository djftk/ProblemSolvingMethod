#define _CRT_SECURE_NO_WARNINGS
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

Student *head;
Student *c = NULL;


void readData(Student *h) {
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
	for (c = h; c; c = c->next) {
		printf("%-10d%-10s%-20s%3d\n", c->tag, c->paid_fee, c->name, c->age);
		
	}

}

void searchYes(Student *h) {
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
	char paidYes[10] = { 0 };
	char* p;
	printf("Type yes : ");
	scanf("%s", paidYes);
	
	for (c = h; c; c = c->next) {
		p = strstr(c->paid_fee, paidYes);
		if (p) {
			printf("%-10d%-10s%-20s%3d\n", c->tag, c->paid_fee, c->name, c->age);
		}
	}
}

int count(Student *h) {
	int cnt = 0;
	while (h != NULL) {
		h = h->next;
		cnt++;
	}
	return cnt;
}


int main() {
	readData(head);
	searchYes(head);
}