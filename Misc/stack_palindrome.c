#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE]; 
int top=-1;

void push(char c){
	if(top==MAX_SIZE-1){printf("\nOVERFLOW!!!\n"); return;}
	else{
		stack[++top] = c;
	}
}

char pop(){
	if(top==-1){printf("\nUNDERFLOW!!!\n"); return -1;}
	else{
		return stack[top--];
	}
}

void main(){
	char str[100],revstr[100],val;
	int i=0,len,flag=0;

	printf("Enter the String : ");
	scanf("%s",&str);

	len = strlen(str);
	printf("\nThe length of the string is %d .\n\n",len);
	for(i=0;i<len/2;i++){
		push(str[i]);
	}
	
	for(i=len/2;i<len;i++){
		if(len%2!=0){i++;}
		val = pop();
		if(val!=str[i]){flag=-1; break;}
	}
	if(flag==-1){printf("%s is NOT A PALINDROME !!!",str);}
	else{
		printf("%s is A PALINDROME !!!",str);
	}
}