#include <stdio.h>
#include <stdlib.h>

#define size 10
int dq[size];
int end = -1;

void display() {
	for(int i=0; i<=end; i++)
		printf("%d   ", dq[i]);
	printf("\n");
}

void insert(int where) {
	if( end == size-1)
		printf("OVERFLOW..!!\n");
	else {
		printf("Enter Data : ");
		int data;
		scanf("%d", &data);
		
		end++;
		if(where == 1) {
			dq[end]=data;
		}
		else {
			for(int i=end; i>0; i--)
				dq[i] = dq[i-1];
			dq[0]=data;
		}
	}
}

void delete(int where) {
	if(end == -1) 
		printf("UNDERFLOW..!!");
	else {
		if(where == 0) 
			for(int i=0; i<end; i++)
				dq[i] = dq[i+1];
		end--;
	}
	display();
}

void main() {
	int choice;
	printf("\n1.Insert at front\n2.Insert at back\n3.Delete from front\n4.Delete from back\n5.Display\n6.Exit\n");
repeat:
	printf("\nEnter choice: ");
	scanf("%d", &choice);
	switch(choice) {
		case 1: insert(0);
			break;
		case 2: insert(1);
			break;
		case 3: delete(0);
			break;
		case 4: delete(1);
			break;
		case 5: display();
			break;
		case 6: exit(0);
		default: printf("\nInvalid choice\n");
	}
	
	goto repeat;
}