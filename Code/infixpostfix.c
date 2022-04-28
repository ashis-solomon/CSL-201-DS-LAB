#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
operator from the stack should be popped if its' priority is >= the priority of the scanned character from the expression.
*/


char stack[100];
int size = -1;

char postexp[100];


// function to display the final postfix expression
void displayPostfix() {
	printf("\nPostfix Expression : \n%s\n", postexp);
	printf("\n");
}


// function to add required specific characters into the postfix expression
void addToPostExp(char ch) {
	postexp[strlen(postexp)] = ch;
	//displayPostfix();
}


// function to pop an operator from the operators stack
char popFromStack() {
	size--;
	return stack[size+1];
}


// function to push operators to the stack
void pushToStack(char ch) {
	size++;
	stack[size] = ch;
}


// function that returns priority of different characters in an expression
int getPriority(char ch) {
	if(ch == '^')
		return 3;
	if((ch == '*') || (ch == '/'))
		return 2;
	if((ch == '+') || (ch == '-'))
		return 1;
	else   // all operands comes under this condition
		return 0;
}


void convertInfixToPostfix(char* exp) {

	for(int i=0; i<strlen(exp); i++) {
		if(exp[i] == '(')   // fist checks if it is opening bracket
			pushToStack(exp[i]);
		else if(exp[i] == ')') {  // then checks if it's the closing bracket
			char stackoperator;
			while(1) {
				stackoperator = popFromStack();
				if( stackoperator == '(')
					break;
				addToPostExp(stackoperator);
			}
		}
		else if(getPriority(exp[i]) == 0)  // if it is operand
			addToPostExp(exp[i]);
		else {  // if operator
			while(getPriority(stack[size]) >= getPriority(exp[i])) 
				addToPostExp(popFromStack());
			pushToStack(exp[i]);
		}
	}
	
	for(int i=size; i>=0; i--)   // adding the remaining operators in stack if any
		addToPostExp(popFromStack());
}


void main() {
	char inexp[100];
	printf("\n");
	printf("Enter the Infix Expression : \n");
	scanf("%[^\n]", inexp);	
	
	convertInfixToPostfix(inexp);
	
	displayPostfix();
}