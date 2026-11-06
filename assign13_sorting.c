#include <stdio.h>
#include <stdlib.h>

void copyArray(int source[], int destination[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        destination[i] = source[i];
}

void displayArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Insertion Sort */
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

/* Merge Sort */
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int i, j, k;
    if (L == NULL || R == NULL)
    {
        printf("Memory allocation failed.\n");
        free(L);
        free(R);
        exit(1);
    }
    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

/* Quick Sort using last element as pivot */
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;
    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

/* Heap Sort */
void heapify(int a[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int temp;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != root)
    {
        temp = a[root];
        a[root] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main(void)
{
    printf("-----------------------------------\n");
    printf("Name: Akash Dipak Torane\n");
    printf("Branch: CSE\n");
    printf("Roll No: 2165\n");
    printf("-----------------------------------\n");
    int n, i;
    int *original, *ins, *mer, *quick, *heap;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid size.\n");
        return 1;
    }
    if (n == 0)
    {
        printf("Array is empty.\n");
        return 0;
    }
    original = (int *)malloc(n * sizeof(int));
    ins = (int *)malloc(n * sizeof(int));
    mer = (int *)malloc(n * sizeof(int));
    quick = (int *)malloc(n * sizeof(int));
    heap = (int *)malloc(n * sizeof(int));
    if (original == NULL || ins == NULL || mer == NULL ||
        quick == NULL || heap == NULL)
    {
        printf("Memory allocation failed.\n");
        free(original); free(ins); free(mer); free(quick); free(heap);
        return 1;
    }
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &original[i]) != 1)
        {
            printf("Invalid input.\n");
            free(original); free(ins); free(mer); free(quick); free(heap);
            return 1;
        }
    }
    copyArray(original, ins, n);
    copyArray(original, mer, n);
    copyArray(original, quick, n);
    copyArray(original, heap, n);
    insertionSort(ins, n);
    mergeSort(mer, 0, n - 1);
    quickSort(quick, 0, n - 1);
    heapSort(heap, n);
    printf("\nOriginal array: ");
    displayArray(original, n);
    printf("After Insertion Sort: ");
    displayArray(ins, n);
    printf("After Merge Sort: ");
    displayArray(mer, n);
    printf("After Quick Sort: ");
    displayArray(quick, n);
    printf("After Heap Sort: ");
    displayArray(heap, n);

    free(original); free(ins); free(mer); free(quick); free(heap);
    return 0;
}
