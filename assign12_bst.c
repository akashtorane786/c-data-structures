#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        printf("Duplicate key %d ignored.\n", key);
    return root;
}

struct Node *search(struct Node *root, int key)
{
    while (root != NULL && root->key != key)
    {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

struct Node *minimumNode(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node *maximumNode(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct Node *predecessor(struct Node *root, int key)
{
    struct Node *current = search(root, key);
    struct Node *pred = NULL;
    if (current == NULL)
        return NULL;
    if (current->left != NULL)
        return maximumNode(current->left);
    while (root != NULL)
    {
        if (key > root->key)
        {
            pred = root;
            root = root->right;
        }
        else if (key < root->key)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }
    return pred;
}

struct Node *successor(struct Node *root, int key)
{
    struct Node *current = search(root, key);
    struct Node *succ = NULL;
    if (current == NULL)
        return NULL;
    if (current->right != NULL)
        return minimumNode(current->right);
    while (root != NULL)
    {
        if (key < root->key)
        {
            succ = root;
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}

struct Node *deleteNode(struct Node *root, int key)
{
    struct Node *temp;
    if (root == NULL)
        return NULL;
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minimumNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    struct Node *root = NULL;
    struct Node *result;
    int n, key, choice, i;
    printf("Enter number of keys: ");
    if (scanf("%d", &n) != 1 || n < 0)
        return 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter key %d: ", i + 1);
        if (scanf("%d", &key) != 1)
        {
            freeTree(root);
            return 0;
        }
        root = insert(root, key);
    }
    do
    {
        printf("\n\n--- BST OPERATIONS ---\n");
        printf("1. Display In-order Traversal\n");
        printf("2. Minimum Key\n");
        printf("3. Maximum Key\n");
        printf("4. Search for a Key\n");
        printf("5. Find Predecessor\n");
        printf("6. Find Successor\n");
        printf("7. Delete a Key\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        switch (choice)
        {
        case 1:
            printf("In-order traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            result = minimumNode(root);
            if (result != NULL)
                printf("Minimum key = %d\n", result->key);
            else
                printf("Tree is empty.\n");
            break;
        case 3:
            result = maximumNode(root);
            if (result != NULL)
                printf("Maximum key = %d\n", result->key);
            else
                printf("Tree is empty.\n");
            break;
        case 4:
            printf("Enter key to search: ");
            scanf("%d", &key);
            result = search(root, key);
            if (result != NULL)
                printf("Key %d found.\n", key);
            else
                printf("Key %d not found.\n", key);
            break;
        case 5:
            printf("Enter key to find predecessor: ");
            scanf("%d", &key);
            result = predecessor(root, key);
            if (search(root, key) == NULL)
                printf("Key not found in the tree.\n");
            else if (result != NULL)
                printf("Predecessor of %d = %d\n", key, result->key);
            else
                printf("No predecessor exists.\n");
            break;
        case 6:
            printf("Enter key to find successor: ");
            scanf("%d", &key);
            result = successor(root, key);
            if (search(root, key) == NULL)
                printf("Key not found in the tree.\n");
            else if (result != NULL)
                printf("Successor of %d = %d\n", key, result->key);
            else
                printf("No successor exists.\n");
            break;
        case 7:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            if (search(root, key) == NULL)
            {
                printf("Key not found; nothing deleted.\n");
            }
            else
            {
                root = deleteNode(root, key);
                printf("Key deleted successfully.\n");
            }
            break;
        case 0:
            printf("Program terminated.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
    freeTree(root);
    return 0;
}
