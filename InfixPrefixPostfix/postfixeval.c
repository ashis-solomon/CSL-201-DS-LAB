#include<stdio.h>
#include<string.h>
#include<math.h>


int stack[100];
int top = -1;

void push(int num){
	stack[++top] = num;
}

int peek(){
	return stack[top];
}

int pop(){
	return stack[top--];
}

int performOperation(char op,int op1,int op2){
	switch(op){
		case '+' : return op2 + op1;
		case '-' : return op2 - op1;
		case '*' : return op2 * op1;
		case '/' : return op2 / op1;
		case '^' : return pow(op2,op1);
		defatult : return -1;
	}
}

int isDigit(char ch){
	if(ch>='0' && ch<='9')
		return 1;
	else 
		return 0;
}

int postfixEval(char exp[]){
	for(int i=0;i<strlen(exp);i++){
		if(exp[i] == ' ')
			continue;
		else if(isDigit(exp[i])){
			int num=0;
			while(isDigit(exp[i])){
				num = num*10 + (int)(exp[i]-'0');
				i++;
			}
			i--;
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
	printf("\nEnter the expression seperated by spaces : ");
	gets(exp); //considers spaces also

	int res = postfixEval(exp);
	printf("\n\nThe result is =  %d\n\n",res);
}



