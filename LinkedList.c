#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student {
	int tag;
	char paid_fee[4];
	char name[21];
	//int age;
	//char info[41];
	//char job[21];
	struct Student *next;
}Student;

Student *head;

void create(Student *h) {
	int tag;
	char paid_fee[4];
	char name[21];
	printf("Enter the tag : ");
	scanf("%d", &tag);

	//fflush(stdin);
	//while (getchar() != '\n');
	printf("Enter paid fee : ");
	scanf("%s", paid_fee);

	while (getchar() != '\n');
	printf("Enter name : ");
	scanf("%[^\n]s", name);

	if (h == NULL) {
		head = (Student*)malloc(sizeof(Student));
		head->tag = tag;
		strcpy(head->paid_fee, paid_fee);
		strcpy(head->name, name);
		head->next = NULL;
	}
	else {
		while (h->next != NULL)
			h = h->next;
		h->next = (Student*)malloc(sizeof(Student));
		h->next->tag = tag;
		strcpy(h->next->paid_fee, paid_fee);
		strcpy(h->next->name, name);
		h->next->next = NULL;
	}
}

void disPlay(Student *h) {
	printLine();
	printf("%-10s%-20s%s\n", "tag", "paid_fee", "name");
	printLine();
	while (h != NULL) {
		printf("%-10d%-20s%-30s\n", h->tag, h->paid_fee, h->name);
		h = h->next;
	}
	printLine();
}

int printLine() {
	int i;
	for (i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}

void insert1(Student *h) {
	int tag;
	char paid_fee[4];
	char name[21];
	printf("Enter the tag : ");
	scanf("%d", &tag);

	//fflush(stdin);
	printf("Enter paid fee : ");
	scanf("%s", paid_fee);

	while (getchar() != '\n');
	printf("Enter name : ");
	scanf("%[^\n]s", name);

	Student *temp = (Student*)malloc(sizeof(Student));
	temp->tag = tag;
	strcpy(temp->paid_fee, paid_fee);
	strcpy(temp->name, name);
	temp->next = h;
	head = temp;
}

int count(Student *h) {
	int cnt = 0;
	while (h != NULL) {
		h = h->next;
		cnt++;
	}
	return cnt;
}

void insert2(Student *h) {
	int pos, n = count(h);
	int i;
	printf("Enter Position : ");
	scanf("%d", &pos);

	if (pos == 1)
		insert1(h);
	else if (pos == n + 1) {
		create(h);
	}
	else if (pos > n) {
		printf("Index out of Bounds...!");
	}
	else if (pos > 0) {
		int tag;
		char paid_fee[4];
		char name[21];
		printf("Enter the tag : ");
		scanf("%d", &tag);

		//fflush(stdin);
		printf("Enter paid fee : ");
		scanf("%s", paid_fee);

		while (getchar() != '\n');
		printf("Enter name : ");
		scanf("%[\n]s", name);

		for (i = 1; i < pos - 1; i++) {
			h = h->next;
		}
		Student *tmp = (Student*)malloc(sizeof(Student));
		tmp->tag = tag;
		strcpy(tmp->paid_fee, paid_fee);
		strcpy(tmp->name, name);
		tmp->next = h->next;
		h->next = tmp;
	}
}

void searchByPos(Student *h) {
	int n = count(h);
	int pos, i;
	printf("Enter Position to Search : ");
	scanf("%d", &pos);

	if (pos > n) {
		printf("\nINDEX OUT OF BOUNDS...!");
	}
	else if (pos > 0) {
		for (i = 1; i < pos; i++)
			h = h->next;
		printLine();
		printf("%-10d%-20s%s\n", h->tag, h->paid_fee, h->name);
		printLine();
	}
}
void updateByPose(Student *h) {
	int n = count(h);
	int pos, i;
	printf("Enter Position to Update : ");
	scanf("%d", &pos);

	if (pos > n) {
		printf("\nINDEX OUT OF BOUNDS...!");
	}
	else if (pos > 0) {
		char name[21];
		for (i = 1; i < pos; i++)
			h = h->next;
		//fflush(stdin);
		while (getchar() != '\n');
		printf("Enter New Name : ");
		scanf("%[\n]s", h->name);

		printf("Record update successfully...!");
	}
}
void deleteByPos(Student *h) {
	Student *tmp;
	int n = count(h);
	int pos, i;
	printf("Enter Position to Delete : ");
	scanf("%d", &pos);

	if (pos > n) {
		printf("\nINDEX OUT OF BOUNDS...!");
	}
	else if (pos == 1) {
		tmp = h;
		head = h->next;
		free(tmp);
		printf("Record Deleted Successfully...!");
	}
	else if (pos > 0) {
		for (i = 1; i < pos - 1; i++) {
			h = h->next;
		}
		tmp = h->next;
		h->next = h->next->next;
		free(tmp);
		printf("Record Deleted Successfully...!");
	}
}

void writeData(Student *h) {
	FILE *fp = fopen("ex.txt", "w");

	while (h != NULL) {
		fwrite(h, sizeof(Student), 1, fp);
		h = h->next;
	}
	fclose(fp);
	printf("Linked List Data is written to the File...!");
}

void readData(Student *h) {
	Student s1;
	FILE *fp = fopen("ex.txt", "r");
	while (fread(&s1, sizeof(Student), 1, fp)) {
		if (h == NULL) {
			h = (Student*)malloc(sizeof(Student));
			h->tag = s1.tag;
			strcpy(h->paid_fee, s1.paid_fee);
			strcpy(h->name, s1.name);
			h->next = NULL;
			head = h;
		}
		else {
			while (h->next != NULL)
				h = h->next;
			h->next = (Student*)malloc(sizeof(Student));
			h->next->tag = s1.tag;
			strcpy(h->next->paid_fee, s1.paid_fee);
			strcpy(h->next->name, s1.name);
			h->next->next = NULL;
		}
	}
	fclose(fp);
}
int main() {
	int ch;
	do {
		system("cls");
		printLine();
		printf("1. CREATE LIST\n");
		printf("2. DISPLAY LIST\n");
		printf("3. INSERT AT FIRST\n");
		printf("4. COUNT\n");
		printf("5. INSERT AT ANY POSITION\n");
		printf("6. SEARCH BY PAID FEE\n");
		printf("7. UPDATE BY POSITION\n");
		printf("8. DELETE FROM ANY POSITION\n");
		printf("9. WRITE THE LINKED LIST INTO THE FILE\n");
		printf("10. READ FROM FILE AND WRITE INTO LINKED LIST\n");
		printf("0. EXIT\n");
		printLine();
		printf("Enter Your choice : ");
		scanf("%d", &ch);
		switch (ch) {
		case 1: create(head);
			break;
		case 2:disPlay(head);
			break;
		case 3:insert1(head);
			break;
		case 4:
			printf("Total No of student = %d", count(head));
			break;
		case 5:insert2(head);
			break;
		case 6: searchByPos(head);
			break;
		case 7:updateByPose(head);
			break;
		case 8:deleteByPos(head);
			break;
		case 9:writeData(head);
			break;
		case 10:readData(head);
			break;
		case 0:printf("Thank you\nBye...");
			break;
		}
		printf("\n\n");
		system("pause");
	} while (ch != 0);
}