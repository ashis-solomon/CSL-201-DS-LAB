// Linear Search - Recursive

#include<stdio.h>

int linearsearch(int arr[],int size,int data,int i){
	if(arr[i]==data){return i;}
	else if(i==size-1 && arr[i]!=data){return -1;}
	else{
		return linearsearch(arr,size,data,i+1);
	}
}

void main(){
	int size,data;
	printf("Enter the number of elements in the Array : ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter the elements of the Array : \n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	repeat:
	printf("\nEnter the element to be searched for : ");
	scanf("%d",&data);
	int res = linearsearch(arr,size,data,0);
	if(res==-1){printf("\n%d is not found in the Array !!!\n",data);}
	else{
		printf("\n%d is found at index %d and position %d in the Array !!!\n",data,res,res+1);
	}
	char choice;
	printf("Do you want to try again [Y/N] ?\n");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice=='y'||choice=='Y'){goto repeat;}
	return;
}