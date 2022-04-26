// Binary Search - Recursive

#include<stdio.h>

int binsearch(int arr[],int low,int high,int data){
	int mid = (low + high)/2;
	
	if(low>high){return -1;}
	
	if(arr[mid]==data){return mid;}
	else if(data<arr[mid]){return binsearch(arr,low,mid-1,data);}
	else{return binsearch(arr,mid+1,high,data);}
}

void main(){
	int size,data;
	char choice;
	printf("Enter the number of elements in the Array : ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the elements in the Array :\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	repeat:
	printf("Enter the element to search for : ");
	scanf("%d",&data);
	int res = binsearch(arr,0,size-1,data);
	if(res==-1){printf("\n%d is not found in the Array !!!\n",data);}
	else{
		printf("\n%d is found at index %d and position %d !!!\n",data,res,res+1);
	}
	printf("Do you want to try again [Y/N] ?");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == 'y' || choice == 'Y'){goto repeat;}
	
}