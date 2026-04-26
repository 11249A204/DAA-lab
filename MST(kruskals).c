AIM:To implement Kruskal’s Algorithm in C to find the Minimum Spanning Tree (MST) of a weighted graph using the Union-Find (Disjoint Set) method.

PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V  5   // Number of vertices
#define E  6   // Number of edges

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

int parentUF[V];  // Array for Union-Find (Disjoint Set)

// Find function to find root of a set (no path compression)
int find(int i)
{
    if (parentUF[i] == i)
        return i;

    return find(parentUF[i]);
}

// Union function to merge two sets
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    parentUF[rootU] = rootV;
}

// Comparator function for sorting edges by weight
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to implement Kruskal's MST algorithm
void kruskalMST(struct Edge edges[])
{
    printf("\nKruskal's MST:\n");
    printf("Edge \tWeight\n");

    // Sort edges in ascending order of weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parentUF[i] = i;

    int count = 0;  // Number of edges in MST
    int total = 0;  // Total cost of MST

    // Iterate through sorted edges
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        // Check if including this edge forms a cycle
        if (find(u) != find(v))
        {
            // Include edge in MST
            printf("%d - %d \t%d\n", u, v, edges[i].weight);

            total += edges[i].weight;

            unionSet(u, v);  // Merge sets

            count++;
        }
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

int main()
{
    // Edge list: {source, destination, weight}
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    // Call Kruskal's algorithm
    kruskalMST(edges);

    return 0;
}
OUTPUT:
Kruskal's MST:
Edge 	Weight
0 - 1 	2
3 - 4 	2
0 - 2 	3
1 - 3 	3
Total Cost = 10
