#include<stdio.h>
#include<string.h>
#include<math.h>

int stack[100];
int top = -1;

void push(int num){
	stack[++top] = num;
}

int pop(){
	return stack[top--];
}

int peek(){
	return stack[top];
}

int isDigit(char ch){
	if(ch>='0' && ch<='9')
		return 1;
	else
		return 0;
}

int performOperation(char op,int op1,int op2){
	switch(op){
		case '+' : return op1 + op2;
		case '-' : return op1 - op2;
		case '*' : return op1 * op2;
		case '/' : return op1 / op2;
		case '^' : return pow(op1,op2);
		default : return -1;
	}
}

int prefixEval(char exp[]){
	for(int i = strlen(exp)-1; i>=0; i--){
		if(exp[i] == ' ')
			continue;
		else if(isDigit(exp[i])){
			int num=0,k=1;
			while(isDigit(exp[i])){
				num = (int)(exp[i]-'0')*k + num;
				k*=10;
				i--;
			}
			i++;
			push(num);
		}
		else{
			int op1 = pop();
			int op2 = pop();
			int res = performOperation(exp[i],op1,op2);
			push(res);
		}
	}
	return peek();
}

void main(){
	char exp[100];
	printf("\nEnter the expression [separated by spaces]  : ");
	gets(exp);
	
	int res = prefixEval(exp);
	printf("\n\nThe RESULT is = %d .\n\n",res);
}