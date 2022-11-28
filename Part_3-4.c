#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Student {
	int tag;
	char name[20];
	char paid_fee[4];
	//char info[40];
	int age;
	struct Student *next;
}Student;

Student *head;
Student *c = NULL;

void create(Student *h) {
	int tag;
	char paid_fee[4];
	char name[20];
	//char info[40];
	int age;
	printf("Enter Tag : ");
	scanf("%d", &tag);

	printf("Enter Paid Fee : ");
	scanf("%s", paid_fee);

	printf("Enter Name : ");
	scanf("%s", name);

	////fflush(stdin);		//visual studio에서 실행 안됨(2015)
	//while (getchar() != '\n');		//대응책
	//printf("Enter organization : ");
	//scanf("%[^\n]s", info);

	printf("Enter Age : ");
	scanf("%d", &age);

	if (h == NULL) {
		head = (Student*)malloc(sizeof(Student));
		head->tag = tag;
		strcpy(head->paid_fee, paid_fee);
		strcpy(head->name, name);
		//strcpy(head->info, info);
		head->age = age;
		head->next = NULL;
	}
	else {
		while (h->next != NULL)
			h = h->next;
		h->next = (Student*)malloc(sizeof(Student));
		h->next->tag = tag;
		strcpy(h->next->paid_fee, paid_fee);
		strcpy(h->next->name, name);
		//strcpy(h->next->info, info);
		h->next->age = age;
		h->next->next = NULL;
	}
}

void display(Student *h) {
	printLine();
	printf("%-10s%-10s%-20s%s\n", "TAG","FEE","NAME","AGE");
	printLine();
	while (h != NULL) {
		printf("%-10d%-10s%-20s%3d\n", h->tag,h->paid_fee,h->name,h->age);
		h = h->next;
	}
}

void readData(Student *h,Student *c) {
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
		printf("%-10d%-10s%-20s%3d\n", c->tag, c->paid_fee, c->name, c->age);
}

//int count(Student *h) {
//	int cnt = 0;
//	while (h != NULL) {
//		h = h->next;
//		cnt++;
//	}
//	return cnt;
//}

void searchYesPaid(Student *h) {
	char SearchYes[4];
	int i;
	printf("Enter yes : ");
	scanf("%s", SearchYes);
	printf("%-10s%-10s%-10s%s\n", "TAG", "FEE", "NAME", "ORGANIZATION");
	printLine();
	while (h != NULL) {
		if (strcmp(h->paid_fee, SearchYes) == 0) {
			printf("%-10d%-10s%-20s%3d\n", h->tag, h->paid_fee, h->name, h->age);
		}
		h = h->next;
	}
}

int printLine() {
	int i;
	for (i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}
int main() {
	int ch;
	do {
		system("cls");
		printLine();
		printf("1. CREATE LIST\n");
		printf("2. DISPLAY LIST\n");
		printf("3.SEARCH YES PAID\n");
		printf("4. READ DATA\n");
		printf("0. EXIT\n");
		printLine();
		printf("Enter Your choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:create(head);
			break;
		case 2:display(head);
			break;
		case 3:searchYesPaid(head);
			break;
		case 4:readData(c,head);
			break;
		case 0:printf("Thank You\nBye...");
			break;
		}
		printf("\n\n");
		system("pause");
	} while (ch != 0);
}