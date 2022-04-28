#include<stdio.h>
#include<string.h>

char infix[100];
char prefix[100];

char stack[100];
int top = -1;

void push(char ch){
	stack[++top] = ch;
}

char pop(){
	return stack[top--];
}

void pushPrefix(char ch){
	prefix[strlen(prefix)] = ch;
}

int getPriority(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else 
		return 0;
}

void reverse(char* exp){
	char temp;
	for(int i=0;i<strlen(exp)/2;i++){
		temp = exp[i];
		exp[i] = exp[strlen(exp)-1-i];
		exp[strlen(exp)-1-i] = temp;
	}
}

char peek(){
	return stack[top];
}

void convertPrefix(){
	for(int i=0;i<strlen(infix);i++){
		if(infix[i]==')')
			push(')');
		else if(infix[i]=='('){
			char stackop;
			while(1){
				stackop = pop();
				if(stackop == ')')
					break;
				pushPrefix(stackop);
			}
		}
		else if(getPriority(infix[i])==0)
			pushPrefix(infix[i]);
		else{
			while(getPriority(peek()) >= getPriority(infix[i]))
				pushPrefix(pop());
			push(infix[i]);
		}
	}
	for(int i=top;i>=0;i--)
		pushPrefix(pop());
	reverse(prefix);
}

void main(){
	printf("\nEnter the INFIX expression : ");
	scanf("%s",&infix);
	printf("\nINFIX = %s",infix);
	reverse(infix);
	convertPrefix();
	reverse(infix);
	printf("\n\nThe PREFIX EXPRESSION :\n%s\n\n",prefix);
}



