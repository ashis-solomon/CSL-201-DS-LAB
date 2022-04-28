#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}listnode;

listnode* create(int value){
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->data = value;
	node->link = NULL;
	return node;
}

void insert_end(listnode** L,int value){
	listnode* temp = *L;
	listnode* node = create(value);
	if(*L == NULL){*L = node; return;}

	while(temp->link!=NULL)
		temp = temp->link;
	temp->link = node;
}

void display(listnode* L){
	if(L == NULL){printf("\nEMPTY!!\n"); return;}
	
	listnode* temp = L;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void reverse(listnode** L){
	listnode* prev = NULL;
	listnode* curr = *L;
	listnode* next = NULL;

	while(curr!=NULL){
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
		*L = prev;
}

void main(){
	int choice,ele;

	listnode* L = NULL;

	printf("***MENU***\n\n");
	printf("1.Insert at End\n2.Display\n3.Reverse Linked List\n4.Exit\n\n");
	repeat:
	printf("Enter the menu choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :	printf("\nEnter the element to be inserted : ");
				scanf("%d",&ele);
				insert_end(&L,ele);
				break;
		case 2 :	printf("\nThe LIST :\n");
				display(L);	
				break;
		case 3 :	reverse(&L);
				break;
		case 4 :	return;
	}
	goto repeat;
}






