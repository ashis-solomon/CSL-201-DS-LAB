#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} node;

node* top = NULL;


void displayStack() {
	node* temp = top;
	if (temp == NULL) {
		printf("\nStack is Empty\n");
		return;
	}
	printf("\nStack : \n");
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}


void push() {
	int data;
	printf("\nEnter data : ");
	scanf("%d", &data);
	
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->link = NULL;
	
	if(top == NULL)
		top = n;
	else {
		n->link = top;
		top = n;
	}
}


void pop() {
	if(top == NULL) {
		printf("\nStack Empty\n");
		return;
	}
	else {
		printf("\nPop element : %d\n", top->data);
		top = top->link;
	}
	displayStack();
}


void main() {
	int choice;
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
repeat:	
	printf("Enter your choice : ");
	scanf("%d", &choice);
	switch (choice) {
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: displayStack();
			break;
		case 4: exit(0);
			break;
		default: printf("invalid choice...!!\n");
	}
	goto repeat;
}