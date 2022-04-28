#include<stdio.h>
#include<string.h>

/*
The infix expression is to be reversed. Then converted to postfix expression 
with a slight change in the algorithm. The so obtained postfix expression is 
reversed to get the prefix expression.
*/

/*
while converting to postfix here, we have to pop all characters from the stack 
which are higher than the scanned operator. But in case of '^', we pop operators 
from stack which are greater or equal to the scanned operator.
*/


char preexp[100];

char stack[100];
int size = -1;


void displayPrefixExp() {
	printf("\nPrefix expression : \n%s\n", preexp);
	printf("\n");
}


void addToPreExp(char ch) {
	preexp[strlen(preexp)] = ch;
	//displayPostfix();
}


void reverseExpression(char* exp) {
	char temp;
	for(int i=0; i<(strlen(exp)/2); i++) {
		temp = exp[i];
		exp[i] = exp[strlen(exp)-1-i];
		exp[strlen(exp)-1-i] = temp;
	}
	
	for(int i=0; i<strlen(exp); i++) {
		if(exp[i] == '(')
			exp[i] = ')';
		else if(exp[i] == ')')
			exp[i] = '(';
	}
	
}


char popFromStack() {
	size--;
	return stack[size+1];
}


void pushToStack(char ch) {
	size++;
	stack[size] = ch;
}


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


void convertToPrefix(char* exp) {
	
	for(int i=0; i<strlen(exp); i++) {
		if(exp[i] == '(')   // fist checks if it is opening bracket
			pushToStack(exp[i]);
		else if(exp[i] == ')') {  // then checks if it's the closing bracket
			char stackoperator;
			while(1) {
				stackoperator = popFromStack();
				if( stackoperator == '(')
					break;
				addToPreExp(stackoperator);
			}
		}
		else if(getPriority(exp[i]) == 0)  // if it is operand
			addToPreExp(exp[i]);
		else if(getPriority(exp[i]) == 3) {
			while(getPriority(stack[size]) >= getPriority(exp[i])) 
				addToPreExp(popFromStack());
			pushToStack(exp[i]);
		}
		else {  // if operator
			while(getPriority(stack[size]) > getPriority(exp[i])) 
				addToPreExp(popFromStack());
			pushToStack(exp[i]);
		}
	}
	
	for(int i=size; i>=0; i--)   // adding the remaining operators in stack if any
		addToPreExp(popFromStack());
	
	reverseExpression(preexp);
	
}


void main() {
	char inexp[100];
	printf("\n");
	printf("Enter the Infix Expression : \n");
	scanf("%[^\n]", inexp);
	
	reverseExpression(inexp);
	
	convertToPrefix(inexp);
	
	displayPrefixExp();	
}