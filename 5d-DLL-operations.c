#include <stdio.h>
#include <stdlib.h>

struct Node {
    int height;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int height) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->height = height;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d \n", temp->height);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFromMiddle(struct Node** head, int pos) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL)
        return;
        
    if (*head == temp)
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;

    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    
    if (*head == temp)
        *head = NULL;
    else
        temp->prev->next = NULL;

    free(temp);
}

void deleteFromBegininning(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}
int main() {
    struct Node* h1 = createNode(155);  
    struct Node* h2 = createNode(162);  
    struct Node* h3 = createNode(185);  
    struct Node* h4 = createNode(168);  
    struct Node* h5 = createNode(177);  
    struct Node* h6 = createNode(159);  
    struct Node* h7 = createNode(193);  
    struct Node* h8 = createNode(190);  
    struct Node* h9 = createNode(156);  
    struct Node* h10 = createNode(164); 

    
    h1->next = h2;
    h2->prev = h1;

    h2->next = h3;
    h3->prev = h2;

    h3->next = h4;
    h4->prev = h3;

    h4->next = h5;
    h5->prev = h4;

    h5->next = h6;
    h6->prev = h5;

    h6->next = h7;
    h7->prev = h6;

    h7->next = h8;
    h8->prev = h7;

    h8->next = h9;
    h9->prev = h8;

    h9->next = h10;
    h10->prev = h9;

    struct Node* head = h1; 

    printf("Initial list:\n");
    displayList(head);

    
    deleteFromMiddle(&head, 5);
    printf("\nDeleting the middle node:\n");
    displayList(head);

    
    deleteFromBegininning(&head);
    printf("\nDeleting the first node:\n");
    displayList(head);

    
    deleteFromEnd(&head);
    printf("\nDeleting the last node:\n");
    displayList(head);

}
