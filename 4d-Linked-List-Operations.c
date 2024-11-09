#include<stdio.h>
#include<stdlib.h>

struct Node {
    int height;
    struct Node* next;

};

struct Node* createNode(int height) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> height = height;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int height) {
    struct Node* newNode = createNode(height);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;  
    *head = (*head)->next;      
    free(temp);                 
    printf("Node at the beginning deleted.\n");
}

void delEnd(struct Node** head){
    if((*head) -> next == NULL){//if only one node is present
    *head = NULL;

    }else{
        struct Node* current = *head;
        struct Node* prev = NULL;

        while(current -> next != NULL){ //start the list traversal until it gets last element in the list
            prev = current;
            current = current -> next;
        }

        prev -> next=NULL;
        free(current);
    }
}

void deleteAtSpecificPosition(struct Node** head, int position){
    struct Node* current = *head;
    struct Node* prev = NULL;
    int count = 0;
    while(current != NULL){
        if(count == position){
            prev -> next = current -> next;
        }
        prev = current;
        current = current -> next;
        count++;
        }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d, ", temp->height);
        temp = temp->next;
    }
    
}

int main(){
    struct Node* head = NULL;

    insertEnd(&head, 180);
    insertEnd(&head, 171);
    insertEnd(&head, 165);
    insertEnd(&head, 133);
    insertEnd(&head, 139);
    insertEnd(&head, 142);
    insertEnd(&head, 169);
    insertEnd(&head, 144);
    insertEnd(&head, 190);
    insertEnd(&head, 156);

    printf("\nOriginal List of Student Heights: \n");
    printList(head);

    printf("\nDelete at a specific position: ");
    deleteAtSpecificPosition(&head, 5);
    printList(head);

    printf("\nFirst Value Deleted: \n");
    deleteBeginning(&head);
    printList(head);

    printf("\nLast Value Deleted: \n");
    delEnd(&head);
    printList(head);

    

}
