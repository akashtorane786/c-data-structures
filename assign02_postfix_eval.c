#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Invalid postfix expression!\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    char exp[MAX];
    int i, a, b, result;
    printf("Enter postfix expression (single-digit operands): ");
    scanf("%99s", exp);
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();
            switch (exp[i])
            {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0)
                {
                    printf("Division by zero!\n");
                    return 1;
                }
                result = a / b;
                break;
            default:
                printf("Invalid operator!\n");
                return 1;
            }
            push(result);
        }
    }

    if (top != 0)
    {
        printf("Invalid postfix expression!\n");
        return 1;
    }

    printf("Result = %d\n", pop());
    return 0;
}
