#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void insertEnd(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    if (last == NULL)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("%d inserted.\n", value);
}

void deleteValue(int value)
{
    struct Node *current, *previous;
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    current = last->next;
    previous = last;
    do
    {
        if (current->data == value)
        {
            if (current == last && current->next == last)
                last = NULL;
            else
            {
                previous->next = current->next;
                if (current == last)
                    last = previous;
            }
            free(current);
            printf("%d deleted.\n", value);
            return;
        }
        previous = current;
        current = current->next;
    } while (current != last->next);
    printf("Value not found.\n");
}

void display(void)
{
    struct Node *temp;
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = last->next;
    printf("Circular linked list: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to first node)\n");
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
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at end\n2. Delete by value\n3. Display\n4. Exit\nEnter choice: ");
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
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);
    while (last != NULL)
    {
        struct Node *first = last->next;
        if (first == last)
        {
            free(last);
            last = NULL;
        }
        else
        {
            last->next = first->next;
            free(first);
        }
    }
    return 0;
}
