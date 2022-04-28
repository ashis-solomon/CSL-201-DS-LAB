#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int exp;
	int coeff;
	struct node* link;
}polynomial;

void insert(polynomial** p,int co,int ex){
	polynomial* node = (polynomial*)malloc(sizeof(polynomial));
	node->exp = ex;
	node->coeff = co;
	node->link = NULL;
	
	polynomial* temp = *p;
	if(*p==NULL){*p = node; return;}
	while(temp->link!=NULL)
		temp = temp->link;
	temp->link = node;
}

void input(polynomial** p,int num){
	int terms,ex,co;
	printf("\n\nEnter the number of terms of Polynomial %d : ",num);
	scanf("%d",&terms);
	for(int i=0;i<terms;i++){
		printf("\nEnter coeff : ");
		scanf("%d",&co);
		printf("Enter exp : ");
		scanf("%d",&ex);
		insert(p,co,ex);
	}
}

void display(polynomial* p,char ch[]){
	printf("\n\nPOLYNOMIAL %s :\n",ch);
	if(p==NULL){printf("\nEMPTY!!\n"); return;}
	
	polynomial* temp = p;
	while(temp->link!=NULL){
		printf("%dx^%d  +  ",temp->coeff,temp->exp);
		temp = temp->link;
	}
	printf("%dx^%d",temp->coeff,temp->exp);
}

int compare(int a,int b){
	if(a==b){return 0;}
	else if(a>b){return 1;}
	else{return -1;}
}

void polyadd(polynomial* poly1,polynomial* poly2,polynomial** poly3){
	polynomial* p1 = poly1;
	polynomial* p2 = poly2;

	while(p1!=NULL && p2!=NULL){
		switch(compare(p1->exp,p2->exp)){
			case 0  :	insert(poly3,p1->coeff+p2->coeff,p1->exp);
					p1 = p1->link;
					p2 = p2->link;
					break;
			case 1  :	insert(poly3,p1->coeff,p1->exp);
					p1 = p1->link;
					break;
			case -1 :	insert(poly3,p2->coeff,p2->exp);
					p2 = p2->link;
					break;
		}
	}
	while(p1!=NULL){
		insert(poly3,p1->coeff,p1->exp);
		p1 = p1->link;
	}
	while(p2!=NULL){
		insert(poly3,p2->coeff,p2->exp);
		p2 = p2->link;
	}
}

void sortll(polynomial** p){
	int temp;
	polynomial* temp1 = *p;
	polynomial* temp2 = *p;
	
	while(temp1!=NULL){
		temp2 = *p;
		while(temp2->link!=NULL){
			if(temp2->exp < temp2->link->exp){
				temp = temp2->coeff;
				temp2->coeff = temp2->link->coeff;
				temp2->link->coeff = temp;
				
				temp = temp2->exp;
				temp2->exp = temp2->link->exp;
				temp2->link->exp = temp;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	} 
}

void main(){
	polynomial* poly1 = NULL;
	polynomial* poly2 = NULL;
	polynomial* poly3 = NULL;	

	input(&poly1,1);
	input(&poly2,2);
	
	printf("\n");

	sortll(&poly1);
	sortll(&poly2);

	display(poly1,"1");
	display(poly2,"1");

	polyadd(poly1,poly2,&poly3);

	display(poly3,"SUM");
	
}