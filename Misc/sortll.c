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
	listnode *temp = *L;
	listnode* node = create(value);
	if(*L==NULL){
		*L = node;
		return;
	}
	while(temp->link!=NULL)
		temp = temp->link;
	temp->link = node;
}

void display(listnode* L){
	listnode *temp = L;
	if(L==NULL){
		printf("\nThe List is EMPTY!!\n");
		return;
	}
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->link;
	}
	printf("\n\n");
}

void sortll(listnode** L){
	int temp;
	listnode* temp1 = *L;
	listnode* temp2 = *L;

	while(temp1!=NULL){
		temp2 = *L;
		while(temp2->link!=NULL){
			if(temp2->data > temp2->link->data){
				temp = temp2->data;
				temp2->data = temp2->link->data;
				temp2->link->data = temp;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}

}

void main(){
	listnode *L = NULL;

	int choice,ele;
	printf("\n***MENU***\n\n");
	printf("1.Insert at End\n2.Display\n3.Sort Linked List\n4.Exit\n\n");
	repeat:
	printf("Enter the menu choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :	printf("Enter the element to be inserted : ");
				scanf("%d",&ele);
				insert_end(&L,ele);
				break;
		case 2 :	display(L);
				break;
		case 3 :	sortll(&L);
				break;
		case 4 :	return;
	}
	goto repeat;
}



