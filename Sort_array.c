#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define file_name "peopleinfo.txt"

typedef struct people_information {
	char name[21];
	int age;
}people_info;

void find_people_name(people_info* people, int size);
int main(void) {
	people_info people[100];
	FILE* fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("fail to read file");
		return 0;
	}
	char buffer[1001], *token;

	int i = 0;
	int idx = 0;
	while (!feof(fp)) {
		i = 0;
		fgets(buffer, 1001, fp);
		token = strtok(buffer, "/");
		while (token != NULL) {
			if (i == 0) {
				strcpy(people[idx].name, token);
			}
			else if (i == 1) {
				people[idx].age = atoi(token);
			}
			i++;
			token = strtok(NULL, "/");
		}
		idx++;
	}
	for (int i = 0; i < idx; i++) {
		printf("%s %d\n", people[i].name, people[i].age);
	}
	fclose(fp);

	find_people_name(people, idx);
	return 0;
}
void find_people_name(people_info* people, int size) {
	printf("찾고싶은 사람의 이름을 입력하세요: ");
	char find_name[100];
	scanf("%s", find_name);
	char* ptr;
	people_info *
	int line = 0;
	for (p = people; p < people + size; p++, line++) {
		ptr = strstr(p->name, find_name);
		if (ptr != NULL) {
			printf("파일의 [%d]line에 이름 : [%s] 발견 - 이름 : [%s] 나이 : [%d]\n", line, p->name, p->name, p->age);
		}
	}
}