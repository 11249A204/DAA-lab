AIM:To implement Quick Sort in C using a randomized pivot to efficiently sort an array.
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot at correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Choose last element as pivot
    int i = (low - 1);       // Index of smaller element

    // Rearrange elements based on pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Place pivot at correct position
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);  // Return pivot index
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select random pivot index
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    srand(time(NULL));  // Seed for random number

    printf("Enter number of elements: ");

    // Validate input
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int numbersToSort[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbersToSort[i]);

    // Call QuickSort
    quickSort(numbersToSort, 0, n - 1);

    // Print sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", numbersToSort[i]);

    return 0;
}
OUTPUT:
Enter number of elements: 5
Enter 5 integers: 2
5
4
7
9

Sorted array: 2 4 5 7 9 
