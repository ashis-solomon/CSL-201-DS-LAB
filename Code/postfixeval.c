#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


int stack[100];
int top = -1;

void stack_push(int el){
    stack[++top] = el;
}

int stack_pop(){
    return stack[top--];
}

int stack_peek(){
    return stack[top];
}


bool isDigit(char c){
    return (c >= '0' && c <= '9');
}

int performOperation(char operator, int op1, int op2){
    switch (operator){
    case '+':
        return op2 + op1;
    case '-':
        return op2 - op1;
    case '*':
        return op2 * op1;
    case '/':
        return op2 / op1;
    case '^':
        return pow(op2, op1);
    default:
        return -1;
    }
}


int postfixEval(char exp[]){
    int n = strlen(exp);      
    for (int i = 0; i < n; i++){
        if (exp[i] == ' ')  
            continue;        
        if (isDigit(exp[i])){
            int num = 0;
            while (isDigit(exp[i])){
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            stack_push(num); 
        }
        else{
            int op1 = stack_pop(); 
            int op2 = stack_pop();
            int result = performOperation(exp[i], op1, op2); 
            stack_push(result);                             
        }
    }
    return stack_peek(); 
}

int main(){
    char exp[100];
    printf("\nEnter postfix expression, each item must be space separated\n");
    printf("For example: 24 36 + 4 /\n\n");
    gets(exp);
    int EvaluatedValue = postfixEval(exp);
    printf("\nResult Of evaluated postfix:  %d", EvaluatedValue);
    printf("\n\n");
    return 0;
}