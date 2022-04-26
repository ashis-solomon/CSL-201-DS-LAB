#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}listnode;

listnode* create(int data){
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->data = data;
	node->link = NULL;
	return node;
}

void insert_end(listnode** L,int data){
	listnode* node = create(data);
	if(*L == NULL){
		*L = node;
	}
	else{
		listnode* temp = *L;
		while(temp->link!=NULL)
			temp = temp->link;
		temp->link = node;
	}
}

void display(listnode **L){
	listnode* temp = *L;
	if(temp==NULL){printf("The List is Empty !!!\n\n");}
	else{
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}

void middle(listnode* L){
	listnode* temp = L;
	int count = 0;
	if(temp==NULL){display(&temp);}
	else{
		while(temp!=NULL){count++; temp=temp->link;}
	}

	int ct = 2;
	temp = L;
	while(ct<=count/2){
		temp = temp->link;
		ct++;
	}
	if(count%2 != 0){
		printf("Middle Element is %d",temp->link->data);
	}
	else if(count%2 == 0){
		printf("Middle Elements are %d and %d",temp->data,temp->link->data);
	}
	printf("\n");
	
}

void main(){
	listnode *L = NULL;
	listnode *L1 = NULL;
	listnode *L2 = NULL;

	int choice,ele;

	printf("***MENU***\n\n");
	printf("1.Insert at End\n2.Display\n3.Middle Element\n4.Exit\n\n");
	repeat:
		printf("Enter menu choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 	printf("Enter the element to be inserted : ");
					scanf("%d",&ele);
					insert_end(&L,ele);
					break;
			case 2: 	display(&L);
					break;
			case 3:	middle(L);
					break;
			case 4:	return;
			default: 	printf("Enter a valid choice !!!\n");
		}	
	goto repeat;
	
}







