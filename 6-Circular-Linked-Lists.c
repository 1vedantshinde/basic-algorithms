#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL; 
    return newNode; 
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (position == 1) {
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head; 
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
    } else {
        for (int i = 1; i < position - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deletePosition(struct Node** head, int position) {
    if (*head == NULL) { 
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    if (position == 1) {
        while (current->next != *head) {
            current = current->next;
        }
        if (*head == (*head)->next) { 
            free(*head);
            *head = NULL;
        } else {
            current->next = (*head)->next;
            free(*head);
            *head = current->next;
        }
    } else {
        current = *head;
        for (int i = 1; i < position - 1 && current->next != *head; i++) {
            current = current->next;
        }

        struct Node* temp = current->next;
        if (temp == *head) { 
            current->next = *head; 
        } else {
            current->next = temp->next;
        }
        free(temp);
    }
}

void searchAndDelete(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int found = 0;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->data == data) {
        if ((*head)->next == *head) { 
            free(*head);
            *head = NULL;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            struct Node* delNode = *head;
            temp->next = (*head)->next;
            *head = (*head)->next;
            free(delNode);
        }
        printf("Element %d found and deleted.\n", data);
        return;
    }

    temp = (*head)->next; 
    while (temp != *head) {
        if (temp->data == data) {
            prev->next = temp->next;
            free(temp);
            found = 1;
            printf("Element %d found and deleted.\n", data);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Element %d is not in the list.\n", data);
    }
}

void reverseList(struct Node** head){
    if(*head == NULL){
        printf("Cannot reverse empty list.\n");
        return;
    }
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *last = *head;
    do {
        struct Node *next = current -> next; 
        current -> next = prev;              
        prev = current;         
        current = next;        
    } while (current !=*head);
    (*head)->next = prev;
    *head = prev;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("Data: %d\n", temp->data); 
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    insertAtPosition(&head, 101, 1);
    insertAtPosition(&head, 201, 2);
    insertAtPosition(&head, 301, 3);
    insertAtPosition(&head, 401, 4);
    

    display(head); 

    printf("\nCircular Linked List Operations: \n");
    printf("1. Insert at any position \n");
    printf("2. Delete from any position. \n");
    printf("3. Search the element and delete. \n");
    printf("4. Reversing the list\n");
    printf("Enter choice: \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter data to be inserted: \n");
            scanf("%d", &data);
            printf("Enter position\n");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            display(head); 
            break;

        case 2:
            printf("Enter position to delete: \n");
            scanf("%d", &position);
            deletePosition(&head, position);
            display(head); 
            break;

        case 3:
            printf("Enter element to search and delete: \n");
            scanf("%d", &data);
            searchAndDelete(&head, data);
            display(head); 
            break;
        
        case 4:
            printf("Reversed List: \n");
            reverseList(&head);
            display(head);
            break;

        default:
            printf("Error.\n");
            break;
    }

}
