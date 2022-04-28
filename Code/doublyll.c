#include<stdio.h>
#include<stdlib.h>


struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* beg = NULL;
struct Node* end = NULL;


void displayList() {
	struct Node* temp = beg;
	while(temp != NULL) {
		printf("%d   ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void insertElement(int pos) {
	int data;
	printf("Enter Data : ");
	scanf("%d", &data);
	
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	
	if(pos == 0) {
		printf("Enter Position to Insert Data : ");
		scanf("%d", &pos);
	}
	
	if((beg == NULL) && (end == NULL))
		beg = end = n;
	else if(pos == 1) {
		beg->prev = n;
		n->next = beg;
		beg = n;
	}
	else {
		struct Node* temp = beg;
		int count = 0;
		
		while(temp != NULL) {
			count++;
			if(count == pos)
				break;
			temp = temp->next;
		}
		
		if(temp != NULL) {
			n->prev = temp->prev;
			temp->prev->next = n;
			n->next = temp;
			temp->prev = n;
		}
		else {
			end->next = n;
			n->prev = end;
			end = n;
		}
	}
}


void deleteElement() {

	if( (beg == NULL) && (end == NULL) ) {
		printf("UNDERFLOW !\n");
		return;
	}
	
	int ele;
	printf("Enter Element to Delete : ");
	scanf("%d", &ele);
	
	struct Node* temp = beg;
	
	while(temp != NULL) {
		if(temp->data == ele) {
			if((temp == beg) && (temp == end))
				beg = end = NULL;
			else if(temp == beg) {
				beg = beg->next;
				beg->prev = NULL;
			}
			else if(temp == end) {
				end = end->prev;
				end->next = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			
			free(temp);
			break;
		}
		
		temp = temp->next;
	}
	
	displayList();
}


void main() {
	int choice;
	printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at a position\n4.Delete a node\n5.Display\n6.Exit\n");
repeat:
	printf("\nEnter Choice : ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: insertElement(1);
			break;
		case 2: insertElement(-1);
			break;
		case 3: insertElement(0);
			break;
		case 4: deleteElement();
			break;
		case 5: displayList();
			break;
		case 6: exit(0);
			break;	
		default: printf("Invalid Choice !\n");
	}
	goto repeat;
}