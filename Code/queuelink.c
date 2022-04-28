#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} Node;

Node* front = NULL;
Node* rear = NULL;


void display() {
	Node* temp = front;
	printf("\n");
	if(temp==NULL){
		printf("Queue Empty !!");
	}
	while(temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


void add() {
	Node* n = (Node*)malloc(sizeof(Node));
	printf("Enter Data : ");
	scanf("%d", &n->data);
	n->link = NULL;
	
	if(front == NULL) 
		front = rear = n;
	else {
		rear->link = n;
		rear = n;
	}
}


void delete() {
	if(front == NULL) 
		printf("\nUnderflow...!");
	else if(front == rear)
		front = rear = NULL;
	else
		front = front->link;
		
	display();
}


void main() {
	int choice;
	printf("\n1.Add element\n2.Delete element\n3.Display\n4.Exit");
repeat:
	printf("\nEnter your choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: add();
			break;
		case 2: delete();
			break;
		case 3: display();
			break;
		case 4: exit(0);
			break;
		default: printf("Invalid Choice.......!\n");
	}
	goto repeat;
}