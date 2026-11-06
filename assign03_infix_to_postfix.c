#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop(void)
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '%' || ch == '^';
}

int main(void)
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch, op;
    printf("Enter infix expression: ");
    scanf("%99s", infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] == '(')
                pop();
            else
            {
                printf("Invalid expression!\n");
                return 1;
            }
        }
        else if (isOperator(ch))
        {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                    (precedence(stack[top]) == precedence(ch) &&
                     ch != '^')))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        else
        {
            printf("Invalid character in expression!\n");
            return 1;
        }
    }

    while (top != -1)
    {
        op = pop();
        if (op == '(')
        {
            printf("Invalid expression!\n");
            return 1;
        }
        postfix[j++] = op;
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
