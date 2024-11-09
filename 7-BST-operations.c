#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;  
    struct node *right; 
};

struct node *root = NULL;

struct node *createNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct node *searchAndInsert(struct node *root, struct node *insertionNode) {
    if((insertionNode->data > root->data) && (root->right != NULL)) {
        searchAndInsert(root->right, insertionNode);
    }
    else if((insertionNode->data > root->data) && (root->right == NULL)) {
        root->right = insertionNode;
    }
    else if((insertionNode->data < root->data) && (root->left != NULL)) {
        searchAndInsert(root->left, insertionNode);
    }
    else if((insertionNode->data < root->data) && (root->left == NULL)) {
        root->left = insertionNode;
    }
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node *findMin(struct node *root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root, int value) {
    if(root == NULL) {
        printf("Empty BST\n");
        return root;
    }
    if(value < root->data) {
        root->left = delete(root->left, value);
    }
    else if(value > root->data) {
        root->right = delete(root->right, value);
    }
    else {
        if(root->left == NULL) {
            struct node *insertionNode = root->right;
            free(root);
            return insertionNode;
        } else if(root->right == NULL) {
            struct node *insertionNode = root->left;
            free(root);
            return insertionNode;
        }
        struct node *insertionNode = findMin(root->right);
        root->data = insertionNode->data;
        root->right = delete(root->right, insertionNode->data);
    }
    return root;
}

int main() {
    struct node *n1 = createNode(8);
    struct node *n2 = createNode(10);
    struct node *n3 = createNode(15);
    struct node *n4 = createNode(7);
    struct node *n5 = createNode(9);
    struct node *n6 = createNode(12);
    struct node *n7 = createNode(19);
    struct node *n8 = createNode(3);

    root = n1;

    searchAndInsert(root, n2);
    searchAndInsert(root, n3);
    searchAndInsert(root, n4);
    searchAndInsert(root, n5);
    searchAndInsert(root, n6);
    searchAndInsert(root, n7);
    searchAndInsert(root, n8);

    printf("Menu\n");
    printf("1. Create BST\n");
    printf("2. Traversal\n");
    printf("3. Search and insert a given node\n");
    printf("4. Search the element and delete\n");
    printf("5. Exit\n");

    int option;
    printf("Enter an option (1-5): ");
    scanf("%d", &option);

    while(option != 5) {
        switch(option) {
            case 1: 
                int value;
                printf("Enter node to be created: ");
                scanf("%d", &value);
                createNode(value);
                printf("Node created\n");
                break;
            
            case 2: 
                int choice;
                printf("1. Preorder Traversal\n");
                printf("2. Inorder Traversal\n");
                printf("3. Postorder Traversal\n");
                printf("Enter traversal choice(1-3): ");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("\nPreorder Traversal: ");
                    preorder(root);
                    printf("\n");
                    break;
                } else if(choice == 2) {
                    printf("\nInorder Traversal: ");
                    inorder(root);
                    printf("\n");
                    break;
                } else if(choice == 3) {
                    printf("\nPostorder Traversal: ");
                    postorder(root);
                    printf("\n");
                    break;
                } else {
                    printf("Invalid choice\n");
                    break;
                }
            
            case 3: 
                int data;
                printf("Enter element to insert: ");
                scanf("%d", &data);
                struct node *insertionNode = createNode(data);
                searchAndInsert(root, insertionNode);
 	          printf("Preorder Traversal: \n");
                preorder(root);

                printf("\n");
                break;
            
            case 4: 
                int value1;
                printf("Enter value to be deleted: ");
                scanf("%d", &value1);
                delete(root, value1);
                preorder(root);
                printf("\n");
                break;
            
            default: 
                printf("Invalid choice\n");
                break;
            
        }
        printf("Enter an option (1-5): ");
        scanf("%d", &option);
    }
    return 0;
}

