#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

int isFull() { return top1 == MAX - 1; }
int isEmpty() { return top1 == -1; }

void push1(int value) { s1[++top1] = value; }
void push2(int value) { s2[++top2] = value; }
int pop1() { return s1[top1--]; }
int pop2() { return s2[top2--]; }

/* s1 always keeps the oldest element on top, so dequeue is a simple pop. */
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    while (top1 != -1)
        push2(pop1());
    push1(value);
    while (top2 != -1)
        push1(pop2());
    printf("%d inserted into queue.\n", value);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d deleted from queue.\n", pop1());
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = top1; i >= 0; i--)
        printf("%d ", s1[i]);
    printf("\n");
}

int main()
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    int choice, value;
    do
    {
        printf("\n--- Queue Using Two Stacks ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 4: printf("Exiting program.\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
