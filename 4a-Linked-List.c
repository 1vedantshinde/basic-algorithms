#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

struct student {
    int roll;
    char name[30];
    int age;
    struct student *link;
} *start;

int main() {
    
    int n = 3;
    
    int rolls[] = {1, 2, 3};
    char names[][30] = {"Student 1", "Student 2", "Student 3"};
    int ages[] = {20, 21, 22};

    struct student *q, *tmp;
    start = NULL;

    for (int i = 0; i < n; i++) {
        
        tmp = (struct student *)malloc(sizeof(struct student));
        tmp->roll = rolls[i];
        strcpy(tmp->name, names[i]);  
        tmp->age = ages[i];
        tmp->link = NULL;

        if (start == NULL) {  
            start = tmp;
        } else {
            q = start;
            
            while (q->link != NULL) {
                q = q->link;
            }
            
            q->link = tmp;
        }
    }

   
    struct student *d;
    if (start == NULL) {
        printf("No data");
    } else {
        d = start;
        printf("List of Students: ");
        while (d != NULL) {
            printf("\nName: %s \nRoll No: %d \nAge: %d", d->name, d->roll, d->age);
            d = d->link;
        }
    }

    
}
