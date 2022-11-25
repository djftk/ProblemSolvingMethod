#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct INFO {
	int tag;
	char date[20];
	char feePaid[10];
	char name[20];
	int age;
	char organization[50];
	char job[20];
	struct INFO* next;
}List[SIZE];//1/2022-08-25/yes/Choi/74/Harvard University/engineer

void InsertInfo();
void dataFind(char []);
int main() {
	
	InsertInfo();

	char item[20];
	printf("\nEntere job for find: ");
	scanf("%[^\n]s", &item);

	dataFind(item);
	return 0;
}
void InsertInfo() {
	FILE* fp = fopen("registration_data.txt", "r");

	if (fp == NULL) {
		printf("\nFile Could Not Be Opened");
		exit(1);
	}

	char line[1000], * temp;
	int a, i = 0, idx = 0;

	while (!feof(fp)) {
		fgets(line, 1000, fp);
		printf("\n%s", line);
		temp = strtok(line, "/");
		while (temp != NULL) {
			printf("%s\n", temp);
			if (i == 0)
				List[idx].tag = atoi(temp);
			else if (i == 1)
				strcpy(List[idx].date, temp);
			else if (i == 2)
				strcpy(List[idx].feePaid, temp);
			else if (i == 3)
				strcpy(List[idx].name, temp);
			else if (i == 4)
				List[idx].age = atoi(temp);
			else if (i == 5)
				strcpy(List[idx].organization, temp);
			else if (i == 6)
				strcpy(List[idx].job, temp);
			temp = strtok(NULL, "/");
			i++;
		}
		idx++;
		i = 0;
	}
	fclose(fp);
}
void dataFind(char item[]) {
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(List[i].job, item) == 0) {
			printf("\nFind same data");
			printf("%d %s %s %s %d %s %s", List[i].tag, List[i].date, List[i].feePaid, List[i].name, List[i].age, List[i].organization, List[i].job);
		}
		else if (i == 29)
			printf("\nThere's no data matched");
	}
}