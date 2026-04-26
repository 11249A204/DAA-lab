AIM:To implement the Best Fit algorithm in C for the bin packing problem, where each item is placed in the bin that leaves the least leftover space.
  
PROGRAM:
#include <stdio.h>

// Function to implement Best Fit algorithm
void bestFit(int items[], int n, int capacity)
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];          // Array to store remaining capacity of bins
    int binCount = 0;    // Number of bins used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = capacity;

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;          // Stores index of best bin
        int minSpace = capacity + 1; // Minimum leftover space

        // Check all existing bins to find best fit
        for (int j = 0; j < binCount; j++)
        {
            // Check if item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If suitable bin found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];  // Reduce remaining capacity
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create new bin
            bin[binCount] -= items[i];
            printf("Item %d (weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;  // Increase bin count
        }
    }

    // Display total bins used
    printf("Total bins used = %d\n", binCount);
}

int main()
{
    int n, capacity, itemSize;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    int items[n];  // Array to store item sizes

    printf("Enter item sizes:\n");

    // Input item sizes
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate item size
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        }
        else
        {
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--;  // Repeat input for this item
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);
    return 0;
}

OUTPUT:
Enter number of items: 4
Enter bin capacity: 10
Enter item sizes:
Item 1: 8
Item 2: 6
Item 3: 2
Item 4: 1

Best Fit Algorithm
Item 1 (weight: 8) placed in Bin 1
Item 2 (weight: 6) placed in Bin 2
Item 3 (weight: 2) placed in Bin 1
Item 4 (weight: 1) placed in Bin 2
Total bins used = 2
