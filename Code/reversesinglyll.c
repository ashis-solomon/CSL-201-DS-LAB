#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* head = NULL;

void displayList() {
	Node* temp = head;
	printf("\n");
	while(temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert(int pos) {
	int data;
	printf("Enter Data : ");
	scanf("%d", &data);
	
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	
	if(head == NULL)
		head = temp;
	else if(pos == 0) {
		temp->next = head;
		head = temp;
	}
	else {
		Node* n = head;
		while(n->next != NULL)
			n = n->next;
		n->next = temp;
	}
}

void reverse() {
	Node* before = NULL;
	Node* current = head;
	Node* after = NULL;
	
	while( current != NULL) {
		after = current->next;
		current->next = before;
		before = current;
		current = after;
		
	}
	head = before;
	
	displayList();
}

void main() {
	int choice;
    printf("\n1.Insert at beginning\n2.Insert at end\n3.Reverse list\n4.Display\n5.Exit\n");
repeat:
	printf("\nEnter Choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: insert(0);
			break;
		case 2: insert(1);
			break;
		case 3: reverse();
			break;
        case 4: displayList();
			break;    
		case 5: exit(0);
			break;
		default: printf("invalid choice\n");
	}
	goto repeat;
}