//Djikstra Shortest Path Algorithm shows the shortest path betweem two vertices in a graph

#include<stdio.h>
#include<stdlib.h>

#define INFINITY 9999
#define MAX 10

void djikstra(int G[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], distance[MAX], predecessor[MAX]; 
    int visited[MAX], count, minDistance, nextNode;
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cost[i][j] = G[i][j]; 
        }
    }

    
    for(int i = 0; i < n; i++){
        distance[i] = cost[startnode][i]; 
        predecessor[i] = startnode;
        visited[i] = 0; //???
    }

    distance[startnode] = 0;
    visited[startnode] = 1; 
    count = 1;

    while(count < n){
        minDistance = INFINITY;
        nextNode = -1; 

        
        for(i = 0; i < n; i++){
            if(distance[i] < minDistance && !visited[i]){
                minDistance = distance[i];
                nextNode = i;
            }
        }

        if(nextNode == -1) break; 

        
        visited[nextNode] = i;

       
        for(i = 0; i < n; i++){
            if(!visited[i]){
                if(minDistance + cost[nextNode][i] < distance[i]){
                    distance[i] = minDistance + cost[nextNode][i];
                    predecessor[i] = nextNode;

                }
            }
        }
        count++;

    }

    
    for(i = 0; i < n; i++){
        if(i != startnode){
            printf("\nDistance to node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;

            do{
                j = predecessor[j];
                printf("<-%d", j);
            } while(j != startnode);
        }
    }
}


int main(){
    int G[MAX][MAX], numVertices, startnode;

    printf("Enter the number of vertices: \n");
    scanf("%d", &numVertices);
    printf("\n");
    printf("Enter the Adjacency Matrix: \n");
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the starting node: (0 to %d): ", numVertices-1);
    scanf("%d", &startnode);

    djikstra(G, numVertices, startnode);

}
