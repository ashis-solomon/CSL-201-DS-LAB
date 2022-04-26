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

void split(listnode** L, listnode** L1, listnode** L2){
	if(*L==NULL){printf("The List is Empty cannot split !!"); return;}
	listnode *temp = *L;
	while(temp!=NULL){
		if(temp->data%2 != 0){insert_end(L1,temp->data);}
		if(temp->data%2 == 0){insert_end(L2,temp->data);}
		temp = temp->link;
	}
	printf("ODD List : \n");
	display(L1);
	printf("\nEVEN List : \n");
	display(L2);
	printf("\n\n");
}

void main(){
	listnode *L = NULL;
	listnode *L1 = NULL;
	listnode *L2 = NULL;

	int choice,ele;

	printf("***MENU***\n\n");
	printf("1.Insert at End\n2.Display\n3.Split into ODD-EVEN List\n4.Exit\n\n");
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
			case 3:	split(&L,&L1,&L2);
					break;
			case 4:	return;
			default: 	printf("Enter a valid choice !!!\n");
		}	
	goto repeat;
	
}







