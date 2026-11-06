#include <stdio.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
    int count;
} Queue;

Queue q1, q2;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) { return q->count == 0; }
int isFull(Queue *q) { return q->count == MAX; }

void enqueue(Queue *q, int value)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->count++;
}

int dequeue(Queue *q)
{
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return value;
}

void push(int value)
{
    Queue temp;
    if (isFull(&q1))
    {
        printf("Stack Overflow!\n");
        return;
    }
    enqueue(&q2, value);
    while (!isEmpty(&q1))
        enqueue(&q2, dequeue(&q1));
    temp = q1;
    q1 = q2;
    q2 = temp;
    printf("%d pushed into stack.\n", value);
}

void pop()
{
    if (isEmpty(&q1))
    {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", dequeue(&q1));
}

void display()
{
    int i, index;
    if (isEmpty(&q1))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (i = 0; i < q1.count; i++)
    {
        index = (q1.front + i) % MAX;
        printf("%d\n", q1.data[index]);
    }
}

int main()
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    int choice, value;
    initQueue(&q1);
    initQueue(&q2);
    do
    {
        printf("\n--- Stack Using Two Queues ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: printf("Exiting program.\n"); break;
        default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
