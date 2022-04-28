#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int stack[100];
int top = -1;

void stack_push(int el)
{
    stack[++top] = el;
}

int stack_pop()
{
    return stack[top--];
}

int stack_peek()
{
    return stack[top];
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int performOperation(char operator, int op1, int op2)
{
    switch (operator)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    default:
        return -1;
    }
}

int prefixEval(char exp[])
{
    int n = strlen(exp);
    for (int i = n - 1; i >= 0; i--) 
    {
        if (exp[i] == ' ')   
            continue;        
        if (isDigit(exp[i])) 
        {
            int num = 0, k = 1;
            while (isDigit(exp[i])) 
            {
                num = num + (int)(exp[i] - '0') * k; 
                k *= 10;
                i--;
            }
            i++;
            stack_push(num); 
        }
        else 
        {
            int op1 = stack_pop(); 
            int op2 = stack_pop();
            int res = performOperation(exp[i], op1, op2); 
            stack_push(res);                             
        }
    }
    return stack_peek(); 
}

int main()
{
    char exp[100];
    printf("\nEnter prefix expression, each item must be space separated\n");
    printf("\nFor example: - + 8 / 6 3 12\n\n");
    gets(exp);
    int eval = prefixEval(exp);
    printf("\nEvaluated prefix: %d", eval);
    printf("\n");

    return 0;
}