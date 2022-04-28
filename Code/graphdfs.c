#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int ADJ_MAT[MAX_SIZE][MAX_SIZE]={{0}};
int isVisited[MAX_SIZE] = {0};

void addEdge(int v1,int v2){
    ADJ_MAT[v1][v2] = 1;
    ADJ_MAT[v2][v1] = 1;
}

void DFS(int v,int n){
    isVisited[v] = 1;
    printf("%d ",v);
    for (int i =0;i<n;i++){
        
        if (ADJ_MAT[v][i] && !isVisited[i]){
            
            DFS(i,n);
        }
    }
}

void main(){
    int v,e;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&v);
    int v1,v2;
    printf("Enter the number of edges in the graph : ");
    scanf("%d",&e);
    printf("enter v1 v2\n");
    for (int i=0;i<e;i++){
        scanf("%d %d",&v1,&v2);
        addEdge(v1,v2);
        
    }
    for (int i = 0;i<v;i++){
        if (!isVisited[i]){
            printf("\n************\n");
            DFS(i,v);
            printf("\n************\n");
        }
    }
}