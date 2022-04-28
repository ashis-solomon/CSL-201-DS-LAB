#include<stdio.h>
#include<string.h>

char infix[100];
char postfix[100];

char stack[100];
int top = -1;

void push(char ch){
	top++;
	stack[top] = ch;
}

char pop(){
	top--;
	return stack[top+1];
}

int getPriority(char ch){
	if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else
		return 0;
}

void pushPostfix(char ch){
	postfix[strlen(postfix)] = ch;
}

char peek(){
	return stack[top];
}

void main(){
	printf("Enter the INFIX expression : ");
	scanf("%s",&infix);
	for(int i=0;i<strlen(infix);i++){
		if(infix[i] == '(')
			push('(');
		else if(infix[i] == ')'){
			char stackop;
			while(1){
				stackop = pop();
				if(stackop=='(')
					break;
				pushPostfix(stackop);
			}
		}
		else if(getPriority(infix[i]) == 0)
			pushPostfix(infix[i]);
		else{
			while(getPriority(peek()) >= getPriority(infix[i]))
				pushPostfix(pop());
			push(infix[i]);
		}
	}

	for(int i=top;i>=0;i--)
		pushPostfix(pop());

	printf("The POSTFIX expression : \n\n%s\n",postfix);
}





