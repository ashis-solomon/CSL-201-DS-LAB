#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int q[MAX_SIZE];
int front = -1;
int rear = -1;


void display() {
	printf("Queue : \n");
	if(front > rear) {
		for(int i=front; i<MAX_SIZE; i++)
			printf("%d   ", q[i]);
		for(int i=0; i<=rear; i++)
			printf("%d   ", q[i]);
	}
	else { 
		if(front==-1 && rear==-1){
			printf("Queue Empty!!");
			return;
		}
		for(int i=front; i<=rear; i++)
			printf("%d   ", q[i]);
	}
	printf("\n");
}



void add() {
	int item;
	printf("Enter Element to Add : ");
	scanf("%d", &item);
	
	if( (front == -1) && (rear == -1) ) {
		front = rear = 0;
		q[rear] = item;
	}
	else if( (rear+1)%MAX_SIZE == front) {
		printf("Overflow..!!\n");
	}
	else {
		rear = (rear+1)%MAX_SIZE;
		q[rear] = item;
	}
}



void delete() {
	if(front == -1)
		printf("Underflow..!!\n");
	else if(front == rear) {
		printf("Deleted element %d\n", q[front]);
		front=rear=-1;
	}
	else {
		printf("Deleted element %d\n", q[front]);
		front = (front+1)%MAX_SIZE;
	}
	display();
}



void main() {
	int choice;
	printf("\n1.Add\n2.Delete\n3.Display\n4.Exit\n");
repeat:
	printf("\nEnter Choice : ");
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
		default: printf("Invalid Choice \n");
	}
	goto repeat;
}