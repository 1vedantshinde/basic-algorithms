#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char name[50];
    int roll;
    int age;
    struct Node *next;
    struct Node *prev;
};

struct Node* createStudent(char* name, int roll, int age) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printStudents(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Roll Number: %d, Age: %d\n", temp->name, temp->roll, temp->age);
        temp = temp->next;
    }
}

int main(){
    struct Node* student1 = createStudent("Jeff", 101, 20);
    struct Node* student2 = createStudent("Pierce", 102, 22);
    struct Node* student3 = createStudent("Annie", 103, 21);

    student1->next = student2;
    student2->prev = student1;
    student2->next = student3;
    student3->prev = student2;

    printStudents(student1);
}
    
