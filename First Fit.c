AIM:To implement the First Fit algorithm in C for the bin packing problem, where each item is placed in the first bin that has enough space.

PROGRAM:
#include <stdio.h>

// Function to implement First Fit algorithm
void firstFit(int items[], int n, int capacity)
{
    int bin[n];        // Array to store remaining capacity of bins
    int binCount = 0;  // Number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // Initialize all bins as empty (0 used yet)
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        // Check if item exceeds bin capacity
        if(items[i] > capacity) {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue; 
        }
        
        int placed = 0;  // Flag to check if item is placed

        // Try to place item in existing bins
        for (int j = 0; j < binCount; j++)
        {
            // Check if enough space is available
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i];  // Reduce remaining space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;           
            }
        }

        // If item not placed in any bin, create a new bin
        if (!placed)
        {
            bin[binCount] = capacity;      // Assign full capacity
            bin[binCount] -= items[i];     // Place item
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;  // Increase bin count
        }
    }

    // Display total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];  // Array to store item sizes

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);   

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}

OUTPUT:
Enter number of items: 4
Enter item sizes:
Item 1: 5
Item 2: 4
Item 3: 6
Item 4: 1
Enter bin capacity: 8

Executing First Fit Algorithm
Item 5 placed in Bin 1
Item 4 placed in Bin 2
Item 6 placed in Bin 3
Item 1 placed in Bin 1
Total bins used = 3
