#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct graph{
    int numVertices;
    struct node** adjList;
};

struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
}

struct graph* createGraph(int vertices){
    struct graph* graph = malloc(sizeof(struct graph));
    graph -> numVertices = vertices;
    graph -> adjList = malloc(vertices * sizeof(struct node*));
    for(int i = 0; i < vertices; i++){
        graph -> adjList[i] = NULL;
    }
    return graph;
}


void addEdge(struct graph* graph, int src, int dest){
    //from src to dest
    struct node* newNode = createNode(dest);
    newNode -> next = graph->adjList[src];
    graph -> adjList[src] = newNode;

    //from dest to src
    newNode = createNode(src);
    newNode -> next = graph ->adjList[dest];
    graph -> adjList[dest] = newNode;
}

void printGraph(struct graph* graph){
    for(int i = 0; i < graph->numVertices; i++){
        struct node* temp = graph -> adjList[i];
        printf("\n Vertex %d: ", i);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");

    }   

}

int main(){
    struct graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

}
