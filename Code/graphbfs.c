#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct vertex{
    int data;
    struct vertex *next;
}*vertex;

vertex adjList[MAX_SIZE];
int queue[MAX_SIZE];
int isVisited[MAX_SIZE] = {0};


int front = -1, rear = -1;


vertex createItem(int data){
    vertex newVertex = (vertex)malloc(MAX_SIZE*sizeof(int));
    newVertex->data = data;
    newVertex->next = NULL;
    return newVertex;
}

void addEdge(int v1,int v2){
    if (!adjList[v1]){
        adjList[v1] = createItem(v2);

    } else{
        vertex curr = adjList[v1];
        while (curr->next){
            curr = curr->next;
        }
        curr->next = createItem(v2);
    }
    if (!adjList[v2]){
        adjList[v2] = createItem(v1);
    } else{
        vertex curr = adjList[v2];
        while (curr->next){
            curr = curr->next;
        }
        curr->next = createItem(v1);
    }
}

void enQueue(int element){
	if (rear == (MAX_SIZE-1)){
		printf("Queue is full\n");
		return;
	}
	if (front==-1){
		front++;
	}
	queue[++rear] = element;
}

int deQueue(){
	if (front == -1){
		printf("Queue empty\n");
		return -1;
	}
	int data = queue[front];
	if (front == rear)
	{
		front = -1;rear = -1;
	}
	else{
		if (front == rear){
			front = -1;rear = -1;
		}
		else{
			front++;
		}
	}
    return data;
}

int isEmpty(){
    if (front == -1){
		return 1;
	}
    return 0;
}

void bfs(int v){
    for (int i = 0;i<v;i++){
        if (!isVisited[i]){
            printf("\n");
            enQueue(i);
            isVisited[i] = 1;
            int i;
            while (!isEmpty()){
                i = deQueue();
                printf("%d ",i);
                vertex curr = adjList[i];
                while (curr){
                    if (!isVisited[curr->data]){
                        enQueue(curr->data);
                        isVisited[curr->data] = 1;
                    }
                    curr = curr->next;
                }
            }
            printf("\n");
        }
    }
}

void main()
{
    int v,e;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&v);
    int v1,v2;
    printf("Enter the number of edges in the graph : ");
    scanf("%d",&e);
    printf("enter v1 v2\n");
    for (int i=0;i<e;i++)
    {
        scanf("%d %d",&v1,&v2);
        addEdge(v1,v2);
    }
    bfs(v);
}