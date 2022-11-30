/*
* File:		exercise1
* Author:	202135486 Jiye Choi
* Date:		20221117
* Course:	Program Solving Method 2022
*
* Summary:	search gachon enginner in struct array and linked list and print all data from the mathced person
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    int tag;
    char date[20];
    char fee_paid[20];
    char name[20];
    int age;
    char organization[50];
    char job[20];
    struct Person* next;
};

int load_data(struct Person*);
struct Person* linked_open();
void sortByAge(struct Person*, int);
void print_linked(struct Person*);
void print_array(struct Person*, int);
void search_fee_paid_in_struct(struct Person persons[]);
void search_gachon_engineer_in_struct(struct Person persons[]);
void search_fee_paid_in_list(struct Person* head);
void search_gachon_engineer_in_list(struct Person* head);

int main()
{
    struct Person persons[50];
    struct Person* head;
    int person_num;
    int age_array;

    person_num = load_data(persons);
    head = linked_open();

    sortByAge(persons, person_num);

    search_fee_paid_in_struct(persons);
    search_fee_paid_in_list(head);
    search_gachon_engineer_in_struct(persons);
    search_gachon_engineer_in_list(head);

    return 0;
}

int load_data(struct  Person* regi_Person)
{
    int i = 0, person_num = 0;
    FILE* regi_file;

    regi_file = fopen("registration_data.txt", "r");
    if (regi_file == NULL)
        printf("file open error\n");
    else
    {
        while (fscanf(regi_file, "%d %*[/] %[^/] %*[/] %[^/] %*[/] %[^/] %*[/] %d %*[/] %[^/] %*[/] %s", &regi_Person[i].tag, regi_Person[i].date, regi_Person[i].fee_paid, regi_Person[i].name, &regi_Person[i].age, regi_Person[i].organization, regi_Person[i].job) == 7)
            i++;
    }
    person_num = i;

    fclose(regi_file);

    return person_num;
}

void print_array(struct Person* regi_person, int person_num)
{
    for (int i = 0; i < person_num; i++)
        printf("%d %s %s %s %d %s %s\n", regi_person[i].tag, regi_person[i].date, regi_person[i].fee_paid, regi_person[i].name, regi_person[i].age, regi_person[i].organization, regi_person[i].job);
}

struct Person* linked_open()
{
    int i = 0;
    FILE* regi_file;
    struct Person* node;
    struct Person* head;
    struct  Person* prev_node;

    head = (struct Person*)malloc(sizeof(struct Person));
    prev_node = head;

    regi_file = fopen("registration_data.txt", "r");
    if (regi_file == NULL)
        printf("file open error\n");
    else
    {
        node = (struct Person*)malloc(sizeof(struct Person));
        while (fscanf(regi_file, "%d %*[/] %[^/] %*[/] %[^/] %*[/] %[^/] %*[/] %d %*[/] %[^/] %*[/] %s", &node->tag, node->date, node->fee_paid, node->name, &node->age, node->organization, node->job) == 7)
        {
            prev_node->next = node;
            prev_node = node;
            node = (struct Person*)malloc(sizeof(struct Person));
        }
        free(node); //free trash node
        prev_node->next = NULL; //last node
    }

    fclose(regi_file);

    return head;
}

void print_linked(struct Person* ptr)
{
    while (ptr != NULL)
    {
        printf("%d %s %s %s %d %s %s\n", ptr->tag, ptr->date, ptr->fee_paid, ptr->name, ptr->age, ptr->organization, ptr->job);
        ptr = ptr->next;
    }
}

void sortByAge(struct Person* array, int person_num)
{
    struct Person temp;

    for (int i = 0; i < person_num; i++)
    {
        for (int j = 0; j < person_num - i; j++)
        {
            if (array[j].age > array[j + 1].age)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < person_num; k++)
    {
        temp = array[k + 1];
        array[k] = temp;
    }

    FILE* age_file;

    age_file = fopen("P1.txt", "w");
    {
        for (int i = 0; i < person_num; i++)
        {
            fprintf(age_file, "%d %s %s %s %d %s %s\n", array[i].tag, array[i].date, array[i].fee_paid, array[i].name, array[i].age, array[i].organization, array[i].job);
        }
    }

    fclose(age_file);

}

void search_gachon_engineer_in_struct(struct Person persons[]) {
    printf("------ Search for Gachon University in struct ------\n");
    for (int i = 0; i < 30; i++) {
        char* univ = persons[i].organization;
        char* job = persons[i].job;
        if (strcmp(univ, "Gachon University") == 0) {
            if (strcmp(job, "engineer") == 0) {
                printf("%d %s %s %s %d %s %s\n", persons[i].tag,
                    persons[i].date,
                    persons[i].fee_paid,
                    persons[i].name,
                    persons[i].age,
                    persons[i].organization,
                    persons[i].job);
            }

        }
    }
    printf("\n");
}

void search_gachon_engineer_in_list(struct Person* head) {
    struct Person* p = head->next;
    printf("------ Search for Gachon University in list ------\n");
    for (int i = 0; i < 30; i++) {
        char* univ = p->organization;
        char* job = p->job;

        if (strcmp(univ, "Gachon University") == 0) {
            if (strcmp(job, "engineer") == 0) {
                printf("%d %s %s %s %d %s %s\n", p->tag,
                    p->date,
                    p->fee_paid,
                    p->name,
                    p->age,
                    p->organization,
                    p->job);
            }

        }
        p = p->next;
    }
    printf("\n");
}

void search_fee_paid_in_struct(struct Person persons[]) {
    printf("------ Search for the fee-paid (yes) persons in struct ------\n");
    for (int i = 0; i < 30; i++) {
        if (strcmp(persons[i].fee_paid, "yes") == 0) {
            printf("%d %s %s %s %d %s %s\n", persons[i].tag,
                persons[i].date,
                persons[i].fee_paid,
                persons[i].name,
                persons[i].age,
                persons[i].organization,
                persons[i].job);
        }
    }
    printf("\n");
}

void search_fee_paid_in_list(struct Person* head)
{
    struct Person* p = head->next;
    printf("------ Search for the fee-paid (yes) persons in list ------\n");
    for (int i = 0; i < 30; i++) {

        if (strcmp(p->fee_paid, "yes") == 0) {
            printf("%d %s %s %s %d %s %s\n", p->tag,
                p->date,
                p->fee_paid,
                p->name,
                p->age,
                p->organization,
                p->job);
        }

        p = p->next;
    }
    printf("\n");
}
