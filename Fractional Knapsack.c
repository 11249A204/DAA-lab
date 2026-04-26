AIM:To implement the Fractional Knapsack algorithm in C using a greedy approach to maximize profit based on value-to-weight ratio.

PROGRAM:
#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;
    int value;
    float ratio;  // value/weight
};

// Function to sort items in descending order of ratio
void sort(struct Item items[], int n) {
    struct Item temp;

    // Bubble sort based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                // Swap items
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int capacity;

    // Input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate value-to-weight ratio
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by decreasing ratio
    sort(items, n);

    float totalProfit = 0.0;

    // Apply greedy approach
    for (int i = 0; i < n; i++) {

        // If item can be fully included
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } 
        else {
            // Take fractional part of item
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    // Display maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

OUTPUT:
Enter number of items: 5
Enter weight and value of item 1: 6
3
Enter weight and value of item 2: 4 1
Enter weight and value of item 3: 3 7
Enter weight and value of item 4: 5 8
Enter weight and value of item 5: 2 9
Enter knapsack capacity: 10
Maximum profit = 24.00
