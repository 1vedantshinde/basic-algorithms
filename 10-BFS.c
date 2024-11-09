#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 9999

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    struct node** adjList;
};

struct Queue{
    int items[MAX_VERTICES];
    int front, rear;
};

//graph memory allocation
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> numVertices = vertices;
    graph -> adjList = malloc(vertices*sizeof(struct node*));
    for(int i = 0; i < vertices; i++){
        graph -> adjList[i] = NULL;
    }

    return graph;
}

//new adjacency list node
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
}

//function to add an edge to the graph

void addEdge(struct Graph* graph, int src, int dest){
    //from source to destination
    struct node* newNode = createNode(dest);
    newNode -> next = graph -> adjList[src];
    graph -> adjList[src] = newNode;

    //from destination to source
    newNode = createNode(src);
    newNode -> next = graph -> adjList[dest];
    graph -> adjList[dest] = newNode;

}

struct Queue* createQueue(){
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> rear = -1;
    return queue;
}

bool Empty(struct Queue* queue){
    return queue -> rear == -1;

}

void enqueue(struct Queue* queue, int value) { 
    if (queue->rear == MAX_VERTICES - 1){
        return;
    } 
    if (queue->front == -1){
        queue->front = 0;
    } 
    queue->items[++queue->rear] = value; 
}

int dequeue(struct Queue* queue) { 
    if (Empty(queue)){
        return -1;
    }

    int item = queue->items[queue->front++];

    if (queue->front > queue->rear) { 
    queue->front = queue->rear = -1;
    }   

    return item;
}

void BFS(struct Graph* graph, int startVertex){
    bool visited[MAX_VERTICES] = { false };
    struct Queue* queue = createQueue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while(!Empty(queue)){
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);
        struct node* adjList = graph->adjList[currentVertex];
    

        while(adjList != NULL){
            int adjVertex = adjList ->vertex;
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                enqueue(queue, adjVertex);
            }
            adjList = adjList-> next;
        }
    }
}

int main(){
    int v = 0;
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("Breadth First Search starting from vertex %d: \n", v);

    BFS(graph, v);

}
