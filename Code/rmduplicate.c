#include<stdio.h>
#include<stdlib.h>

struct listnode
{
 int data;
 struct listnode *link;
};

struct listnode *head=NULL;

void Push(int value)
{	
	struct listnode *node;
	node=(struct listnode*)malloc(sizeof(struct listnode));
	node->data=value;
	node->link=NULL;
	struct listnode *temp=head;
	if(head==NULL)
		head=node;
	else
	{	while(temp->link!=NULL)
		{	temp=temp->link;
		}
		temp->link=node;
	}
}

void RemoveDuplicate()
{	
	struct listnode *temp, *ptr;
	ptr = head;
	while(ptr != NULL) {
		temp = ptr;
		while(temp->link != NULL) {
			if(temp->link->data == ptr->data) {
				temp->link = temp->link->link;
				continue;
			}
			temp = temp->link;
		}	
		ptr = ptr->link;
	}
	
}
void Display()
{	struct listnode *temp;
	temp=head;
	printf("List:");
	
	while(temp!=NULL)
		{	printf("%d ",temp->data);
			temp=temp->link;
		}
	printf("\n");
}

void main()
{	int N,value;

	printf("Enter number of numbers: ");
	scanf("%d",&N);
	printf("Enter data : \n");
	while(N--)
	{	
		scanf("%d",&value);
		Push(value);
	}
	printf("Initial List: ");
	Display();
	RemoveDuplicate();
	printf("Final List: ");
	Display();
	printf("\n");
}