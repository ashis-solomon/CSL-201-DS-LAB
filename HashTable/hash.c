#include<stdio.h>

#define MAX_SIZE 11

int inputArr[MAX_SIZE];
int hashTable[MAX_SIZE]={0};

void performHash(int inputArr[],int size){
	int hash;
	for(int i=0;i<size;i++){
		hash = inputArr[i]%MAX_SIZE;
		while(1){
			if(hashTable[hash]==0){
				hashTable[hash] = inputArr[i];
				break;
			}
			hash=(hash+1)%MAX_SIZE;
		}
	}
}


void printHash(){
	printf("\n\n");
	for(int i=0;i<MAX_SIZE;i++){
		if(hashTable[i]==0){
			printf("--\t");
			continue;
		}
		printf("%d\t",hashTable[i]);
	}
	printf("\n\n");
}


void main(){
	int size;
	printf("\nEnter the number of elements in the array : ");
	scanf("%d",&size);
	if(size>MAX_SIZE){
		printf("Max Size exceeded !!\n");
		return;
	}
	printf("\nEnter the elements of the array : \n");
	for(int i=0;i<size;i++){
		scanf("%d",&inputArr[i]);
	}
	performHash(inputArr,size);
	printHash();
	
}