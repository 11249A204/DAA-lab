AIM:To implement the Travelling Salesman Problem (TSP) in C using Dynamic Programming (Bitmasking) to find the minimum travelling cost.
PROGRAM:
#include <stdio.h>
#include <limits.h>

#define MAXN 15        // Maximum number of cities
#define INF INT_MAX    // Infinity value

int n;                 // Number of cities
int d[MAXN][MAXN];    // Cost matrix
int dp[MAXN][1 << MAXN]; // DP table for memoization

// Function to compute minimum cost
int g(int i, int s)
{
    // Base case: if no cities left to visit, return cost to go back to start
    if (s == 0)
        return d[i][0];

    // If already computed, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];

    int mincost = INF;

    // Try visiting all cities in set 's'
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set s
        if (s & (1 << k))
        {
            // Calculate cost: current → k + remaining path
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // Update minimum cost
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }

    // Store result in DP table
    return dp[i][s] = mincost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    // Input cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Create set of cities except starting city (0)
    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    // Start from city 0
    int result = g(0, S);

    // Print cost matrix
    printf("\nGiven Cost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    // Print minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
OUTPUT:
Enter number of cities: 5
Enter cost matrix:
0 12 10 19 8
12 0 8 14 11
10 8 0 15 9
19 14 15 0 7
8 11 9 7 0

Given Cost Matrix:
| 0  12  10  19  8 |
| 12  0  8  14  11 |
| 10  8  0  15  9 |
| 19  14  15  0  7 |
| 8  11  9  7  0 |
Minimum travelling cost: 47
