#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertEnd(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = NULL;
    if (head == NULL)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    printf("%d inserted.\n", value);
}

void deleteValue(int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;
    free(temp);
    printf("%d deleted.\n", value);
}

void displayForward(void)
{
    struct Node *temp = head;
    if (!head)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Forward: ");
    while (temp)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward(void)
{
    struct Node *temp = tail;
    if (!tail)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Backward: ");
    while (temp)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(void)
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    int choice, value;
    do
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at end\n2. Delete by value\n3. Display forward\n");
        printf("4. Display backward\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1)
            return 0;
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteValue(value);
            break;
        case 3:
            displayForward();
            break;
        case 4:
            displayBackward();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);
    while (head)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
