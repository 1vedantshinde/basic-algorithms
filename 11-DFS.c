#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjList;  
    int* visited;
};

struct Stack {
    int top;
    int cap;
    int* arr;
};

struct Stack* createStack(int cap) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (int*)malloc(cap * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->arr[++stack->top] = item;
}

int Empty(struct Stack* stack) {
    return stack->top == -1;
}

int pop(struct Stack* stack) {
    if (!Empty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjList = (struct node**)malloc(vertices * sizeof(struct node*)); 
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;  
        graph->visited[i] = 0;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];  
    graph->adjList[src] = newNode;  

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];  
    graph->adjList[dest] = newNode;  
}

void DFS(struct Graph* graph, int startVertex) {
    struct Stack* stack = createStack(graph->numVertices);
    
    push(stack, startVertex);
    graph->visited[startVertex] = 1;
    
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    
    while (!Empty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        struct node* temp = graph->adjList[currentVertex];  
        
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                push(stack, adjVertex);
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    DFS(graph, 4);
}

